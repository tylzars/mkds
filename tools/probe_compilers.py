#!/usr/bin/env python3
"""Compiles a probe source with every installed mwccarm version and reports which
ones reproduce the original bytes of the functions it defines.

Each function to check is declared in the source with a marker comment:
    // PROBE: <symbol> <module> <address>
e.g. // PROBE: func_02012345 main 0x02012345

Bytes covered by relocations in the compiled object are masked (branch targets,
literal pool entries), so only instruction encoding and layout are compared. The masked pool words are then
checked separately, as tools/check_calls.py does for the full build: for each pointer word (R_ARM_ABS32) in the
object, in pool order, the original's word at the same offset must be the address of the symbol (plus addend)
the object points to, so two globals loaded in swapped order are a mismatch. Targets with no address in
symbols.txt (file-local data, strings) are skipped. A Thumb
bl is two halfwords and may straddle a word boundary, so masking is per byte.
When every probed function is Thumb in symbols.txt and no flag set names -thumb,
-thumb is added to each flag set.

The base flags are the project's CC_FLAGS without -O, -inline and -ipa, which each --flags set supplies: write them
out in full (`--flags="-O4,p -inline on,noauto"`; add `-ipa file` only for 2.0 builds, 1.2 rejects it), or pass
`--unit <source path>` to probe with exactly the compiler and flags the build uses for that path (library code, game
code, per-path additions).

  probe_compilers.py probe.c --unit src/Main/Foo.c --show
  probe_compilers.py probe.c --only 1.2/base --flags="-O4,p -inline on,noauto" --flags="-O4,s -inline on,noauto"
"""
import argparse
import os
import re
import shlex
import struct
import subprocess
import sys
from pathlib import Path
from project import CC_FLAGS, MWCC_VERSION, VERSION, lang_flag, module_base, source_flags  # noqa: E402  (tools/project.py)

ROOT = Path(__file__).resolve().parent.parent
WIBO = ROOT / "tools/bin/wibo"
MWCC_ROOT = ROOT / "tools/mwccarm"
EXTRACT = ROOT / f"extract/{VERSION}"
# PROBE_INCLUDE (colon-separated) puts extra header directories ahead of the repo's, for trying header variants.
EXTRA_INCLUDES = "".join(f"-i {shlex.quote(d)} " for d in os.environ.get("PROBE_INCLUDE", "").split(":") if d)
# The project's flags minus the ones each probe varies (optimization, inlining) and the C++-only ones (added per file).
_VARIED = ("-O", "-inline", "-ipa", "-Cpp_exceptions", "-RTTI", "-sym", "-msgstyle")
INCLUDES = ["include"] + sorted(str(p.relative_to(ROOT)) for p in (ROOT / "libs").rglob("include") if p.is_dir())
COMMON_FLAGS = f"-d version_{VERSION.upper()} " + EXTRA_INCLUDES + " ".join(f"-i {d}" for d in INCLUDES)
BASE_FLAGS = " ".join(f for f in CC_FLAGS if not f.startswith(_VARIED)) + " " + COMMON_FLAGS
# The default sweep varies the optimization level and keeps the project's -ipa / -inline settings.
DEFAULT_FLAG_SETS = [" ".join([o] + [f for f in CC_FLAGS if f.startswith(("-ipa", "-inline"))])
                     for o in ("-O4,p", "-O4,s", "-O3,p", "-O2")]


def unit_flags(path) -> tuple[str, list[str]]:
    """(compiler build, complete flags) the build uses for a source path: its compiler from PATH_COMPILERS (or
    MWCC_VERSION) and CC_FLAGS with that path's drops and additions (-thumb included), without -lang. A path outside
    src/ and libs/ (a scratch probe) gets the game's settings; give library probes the unit's path instead."""
    version, flags = source_flags(str(path))
    return version or MWCC_VERSION, [f for f in flags if not f.startswith("-lang")]

PROBE = re.compile(r"//\s*PROBE:\s*(\S+)\s+(\S+)\s+(0x[0-9a-fA-F]+)")


def score_output(out: str, func: str) -> int | None:
    """Differing instructions of one probed function in this tool's output (run it with `--show -v` and one compiler):
    0 = match, None = compile error or the function isn't there; a size difference adds 1000. Used by the search
    tools, so a file with several `// PROBE:` lines is scored on the target alone."""
    if "COMPILE ERROR" in out:
        return None
    lines = out.splitlines()
    summary = next((l for l in lines if re.match(r"\s+\S+\s+\d+/\d+", l)), None)
    if summary is None:
        return None
    results = dict(r.split(": ", 1) for r in re.split(r";\s+", summary.split(None, 2)[2]) if ": " in r) \
        if len(summary.split(None, 2)) > 2 else {}
    name = next((n for n in results if func in n), None)
    if name is None:
        return None
    if results[name].startswith("match"):
        return 0
    count, inside = 0, False
    for l in lines:
        if l.startswith("  ["):
            inside = func in l
        elif inside and re.match(r"\s+[0-9a-f]+ \* ", l):
            count += 1
    return max(count, 1) + (1000 if results[name].startswith("size") else 0)


def thumb_branch_target(blob: bytes, at: int, pc: int) -> int:
    """Target of the Thumb bl/blx pair at blob offset `at` (instruction address pc); blx lands on a word boundary."""
    hi, lo = struct.unpack_from("<HH", blob, at)
    off = ((hi & 0x7FF) << 12) | ((lo & 0x7FF) << 1)
    if off & 0x400000:
        off -= 1 << 23
    target = pc + 4 + off
    return target & ~3 if not lo & 0x1000 else target


def module_bytes(module: str) -> tuple[int, bytes]:
    if module == "main":
        return module_base("main"), (EXTRACT / "arm9/arm9.bin").read_bytes()
    if module == "itcm":
        return module_base("itcm"), (EXTRACT / "arm9/itcm.bin").read_bytes()
    if module.startswith("ov"):
        return module_base(module), (EXTRACT / f"arm9_overlays/{module}.bin").read_bytes()
    raise SystemExit(f"unknown module {module}")


def orig_function(module: str, addr: int) -> tuple[int, bool]:
    """(size, Thumb?) of the original function at addr, from symbols.txt."""
    cfg = ROOT / f"config/{VERSION}/arm9"
    path = cfg / "symbols.txt" if module == "main" else cfg / module / "symbols.txt" if module == "itcm" \
        else cfg / "overlays" / module / "symbols.txt"
    for line in path.read_text().splitlines():
        if f"addr:{addr:#010x}" in line and (m := re.search(r"function\((\w+),size=(0x[0-9a-f]+)", line)):
            return int(m.group(2), 16), m.group(1) == "thumb"
    raise SystemExit(f"no function at {addr:#010x} in {path}")


def orig_size(module: str, addr: int) -> int:
    return orig_function(module, addr)[0]


def elf_functions(obj: Path) -> dict[str, tuple[bytes, set[int], bool]]:
    """Returns {symbol: (code bytes, byte offsets covered by that section's relocations, Thumb?)}.

    mwcc emits one .text section per function, so relocations are keyed by the
    section index they apply to (sh_info), never by section name."""
    from elftools.elf.elffile import ELFFile
    from elftools.elf.relocation import RelocationSection

    with open(obj, "rb") as fh:
        elf = ELFFile(fh)
        masked: dict[int, set[int]] = {}
        for sec in elf.iter_sections():
            if isinstance(sec, RelocationSection):
                masked.setdefault(sec["sh_info"], set()).update(
                    r["r_offset"] + i for r in sec.iter_relocations() for i in range(4))
        funcs = {}
        symtab = elf.get_section_by_name(".symtab")
        # mwcc marks Thumb code with $t mapping symbols (function symbols keep bit 0 clear).
        maps: dict[int, list[tuple[int, bool]]] = {}
        for sym in symtab.iter_symbols():
            if sym.name in ("$a", "$t") and isinstance(sym["st_shndx"], int):
                maps.setdefault(sym["st_shndx"], []).append((sym["st_value"], sym.name == "$t"))
        for sym in symtab.iter_symbols():
            if sym["st_info"]["type"] != "STT_FUNC" or not isinstance(sym["st_shndx"], int):
                continue
            data = elf.get_section(sym["st_shndx"]).data()
            value, size = sym["st_value"] & ~1, sym["st_size"]
            code = data[value: value + size]
            mask = {r - value for r in masked.get(sym["st_shndx"], ()) if value <= r < value + size}
            marks = [t for v, t in sorted(maps.get(sym["st_shndx"], [])) if v <= value]
            funcs[sym.name] = (code, mask, bool(sym["st_value"] & 1) or (marks[-1] if marks else False))
        return funcs


_TABLES: dict | None = None


def pool_entries(obj: Path) -> dict[str, list[tuple[int, str, int]]]:
    """{function symbol: [(offset in function, target symbol, addend)]} for every pointer word (R_ARM_ABS32) the
    object has inside that function, in offset order. Section symbols and `@`/`$` names are file-local data."""
    from elftools.elf.elffile import ELFFile
    from elftools.elf.relocation import RelocationSection

    with open(obj, "rb") as fh:
        elf = ELFFile(fh)
        symtab = elf.get_section_by_name(".symtab")
        syms = list(symtab.iter_symbols())
        out: dict[str, list[tuple[int, str, int]]] = {}
        for sec in elf.iter_sections():
            if not isinstance(sec, RelocationSection):
                continue
            data = elf.get_section(sec["sh_info"]).data()
            funcs = [s for s in syms if s["st_info"]["type"] == "STT_FUNC" and s["st_shndx"] == sec["sh_info"]]
            for r in sec.iter_relocations():
                if r["r_info_type"] != 2:
                    continue
                off = r["r_offset"]
                fn = next((f for f in funcs if (f["st_value"] & ~1) <= off < (f["st_value"] & ~1) + f["st_size"]), None)
                target = syms[r["r_info_sym"]]
                if fn is None:
                    continue
                # mwcc writes RELA (the addend is in the entry); a REL object keeps it in the word itself
                addend = r["r_addend"] if r.is_RELA() else struct.unpack_from("<I", data, off)[0]
                name = "" if target["st_info"]["type"] == "STT_SECTION" else target.name
                out.setdefault(fn.name, []).append((off - (fn["st_value"] & ~1), name, addend))
        for v in out.values():
            v.sort()
        return out


def compare_pool(entries: list[tuple[int, str, int]], module: str, orig: bytes) -> list[str]:
    """Differing pool entries of one function, as printable lines (empty = all match or nothing resolvable)."""
    global _TABLES
    if _TABLES is None:
        from check_calls import load_symbols  # tools/check_calls.py: the same symbol tables the full build uses
        _TABLES = load_symbols()
    local = _TABLES.get(module, {})
    bad = []
    for off, name, addend in entries:
        if not name or name[0] in "@$":
            continue  # file-local data: no address before linking
        want = local.get(name, _TABLES["main"].get(name))
        if want is None or off + 4 > len(orig):
            continue
        actual = struct.unpack_from("<I", orig, off)[0]
        if (actual | 1) != ((want + addend) | 1):  # a Thumb function pointer carries the Thumb bit
            names = [n for t in _TABLES.values() for n, a in t.items() if a == actual & ~1]
            bad.append(f"pool +{off:#x}: {name}{f'+{addend:#x}' if addend else ''} ({want + addend:#010x}) | "
                       f"original {actual:#010x} {names[:1]}")
    return bad


def compare(code: bytes, mask: set[int], orig: bytes) -> tuple[bool, str]:
    if len(code) != len(orig):
        return False, f"size {len(code):#x} vs {len(orig):#x}"
    bad = sorted({i & ~3 for i in range(len(code)) if i not in mask and code[i] != orig[i]})
    return (not bad), (f"{len(bad)} words differ (first +{bad[0]:#x})" if bad else "match")


def disasm(code: bytes, thumb: bool = False) -> list[tuple[int, int, str]]:
    """(offset, size, text) per instruction. In Thumb a `bl` is one 4-byte line, everything else 2 bytes."""
    tmp = ROOT / f"build/probe/_dis_{os.getpid()}.bin"
    tmp.parent.mkdir(parents=True, exist_ok=True)
    tmp.write_bytes(code)
    out = subprocess.run(["arm-none-eabi-objdump", "-z", "-D", "-b", "binary", "-m", "arm"]
                         + (["-M", "force-thumb"] if thumb else []) + [str(tmp)],
                         capture_output=True, text=True).stdout
    tmp.unlink(missing_ok=True)
    lines = []
    for l in out.splitlines():
        if m := re.match(r"\s+([0-9a-f]+):\t([0-9a-f ]+?)\s*\t(.*)", l):
            size = sum(len(w) // 2 for w in m.group(2).split())
            lines.append((int(m.group(1), 16), size, re.sub(r"\s+", " ", m.group(3)).strip()))
    return lines


def show_diff(code: bytes, mask: set[int], orig: bytes, thumb: bool = False) -> None:
    """Side-by-side listing; `*` marks an instruction that differs and has no relocated byte in it."""
    a, b = disasm(code, thumb), disasm(orig, thumb)
    for i in range(max(len(a), len(b))):
        xo, xs, x = a[i] if i < len(a) else (None, 0, "")
        yo, _, y = b[i] if i < len(b) else (None, 0, "")
        masked = xo is not None and any(o in mask for o in range(xo, xo + xs))
        mark = " " if masked or x == y else "*"
        print(f"    {xo if xo is not None else yo:4x} {mark} {x:40} | {y}")


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("source", type=Path)
    ap.add_argument("--flags", action="append", default=None,
                    help="optimization flag set(s) to try (default: several)")
    ap.add_argument("--only", help="substring filter on compiler dirs")
    ap.add_argument("--unit", help="probe with the build's compiler and complete flags for this source path "
                                   "(e.g. src/Main/Some/Unit.c); with --flags, only -O/-inline/-ipa are replaced")
    ap.add_argument("-v", "--verbose", action="store_true")
    ap.add_argument("--show", action="store_true", help="print a side-by-side disassembly of mismatches")
    a = ap.parse_args()

    probes = [(s, mod, int(addr, 16)) for s, mod, addr in PROBE.findall(a.source.read_text())]
    if not probes:
        raise SystemExit("no // PROBE: lines in source")
    lang = "-lang=c++ -Cpp_exceptions off -RTTI off" if a.source.suffix == ".cpp" else "-lang=c"
    if a.unit:  # the unit's own language and dialect; its flags already say whether exceptions are on
        lang = lang_flag(a.unit)
    base_flags = BASE_FLAGS
    if a.unit:
        version, flags = unit_flags(a.unit)
        a.only = a.only or version
        kept = flags if not a.flags else [f for f in flags if not f.startswith(_VARIED[:3])]
        base_flags = " ".join(kept) + " " + COMMON_FLAGS
        a.flags = a.flags or [""]
    flag_sets = a.flags or DEFAULT_FLAG_SETS
    # Thumb targets get -thumb unless the flags or the file already choose the mode: a file with `#pragma thumb`
    # lines sets each function's mode itself (ARM files wrap their Thumb functions in `#pragma thumb on` / `off`),
    # so only a file of Thumb targets with no such pragma is compiled as a Thumb file.
    thumb = [orig_function(mod, addr)[1] for _, mod, addr in probes]
    thumb_file = all(thumb) and "#pragma thumb" not in a.source.read_text()
    if thumb_file and "-thumb" not in base_flags.split() and not any("-thumb" in f for f in flag_sets):
        flag_sets = [f"{f} -thumb".strip() for f in flag_sets]
    compilers = sorted(p.parent for p in MWCC_ROOT.glob("*/*/mwccarm.exe"))
    if a.only:
        compilers = [c for c in compilers if a.only in str(c)]

    out_dir = ROOT / "build/probe"
    out_dir.mkdir(parents=True, exist_ok=True)
    obj = out_dir / f"{a.source.stem}_{os.getpid()}.o"

    for flags in flag_sets:
        on_unit = f" (on the build flags for {a.unit})" if a.unit and flags else ""
        print(f"== {flags or 'build flags for ' + a.unit}{on_unit}")
        for cdir in compilers:
            obj.unlink(missing_ok=True)
            q = shlex.quote
            cmd = (f"{q(str(WIBO))} {q(f'{cdir}/mwccarm.exe')} {base_flags} {lang} {flags} -c {q(str(a.source))} "
                   f"-o {q(str(obj))}")
            r = subprocess.run(cmd, shell=True, capture_output=True, text=True, cwd=ROOT)
            label = str(cdir.relative_to(MWCC_ROOT))
            if r.returncode or not obj.exists():
                print(f"  {label:12} COMPILE ERROR {r.stdout.strip()[:200]}{r.stderr.strip()[:200]}")
                continue
            funcs = elf_functions(obj)
            pools = pool_entries(obj)
            results = []
            for sym, mod, addr in probes:
                if sym not in funcs:  # allow a bare or mis-mangled name: match on the identifier
                    ident = re.sub(r"^_Z\d+|^_ZN\d+", "", sym).split("E")[0]
                    cands = [f for f in funcs if ident and ident in f]
                    if len(cands) == 1:
                        sym = cands[0]
                if sym not in funcs:
                    results.append((False, f"{sym} missing (have {', '.join(funcs)})"))
                    continue
                base, blob = module_bytes(mod)
                code, mask, thumb = funcs[sym]
                orig = blob[addr - base: addr - base + orig_size(mod, addr)]
                results.append(compare(code, mask, orig))
                pool_bad = compare_pool(pools.get(sym, []), mod, orig) if len(code) == len(orig) else []
                if pool_bad and results[-1][0]:
                    results[-1] = (False, f"{len(pool_bad)} pool words point elsewhere (first {pool_bad[0].split(':')[0][5:]})")
                if a.show and not results[-1][0]:
                    print(f"  [{cdir.relative_to(MWCC_ROOT)}] {sym}  (compiled | original)")
                    show_diff(code, mask, orig, thumb)
                    for line in pool_bad:
                        print(f"    {line}")
            ok = sum(r[0] for r in results)
            detail = "" if ok == len(results) and not a.verbose else "  " + "; ".join(
                f"{p[0]}: {r[1]}" for p, r in zip(probes, results) if a.verbose or not r[0])
            print(f"  {label:12} {ok}/{len(results)}{detail}")
    obj.unlink(missing_ok=True)


if __name__ == "__main__":
    sys.exit(main())
