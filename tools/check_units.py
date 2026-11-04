#!/usr/bin/env python3
"""Checks every source unit's .text range in delinks.txt against the original functions and the compiled object.

For each unit: the range starts at a function and is 4-byte aligned at both ends, no function runs past its end,
bytes after the last function are zero padding, units don't overlap, and the compiled object defines exactly the
original functions in the range (labels excepted). Every module with a delinks.txt (main, ITCM, DTCM, overlays). Run
`ninja report` first so the objects exist. Exit status 1 on any problem.

  check_units.py
"""
import re

from elftools.elf.elffile import ELFFile
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from project import BUILD, module_base, module_paths, modules  # noqa: E402  (tools/project.py)

# C++ constructor/destructor variants (C1/C2, D0/D1/D2): the compiler can emit a variant the original link dropped.
XTOR = re.compile(r"([CD])[0-2](E)")
SYM = re.compile(r"(\S+) kind:function\(\w+,size=(0x[0-9a-f]+)[^)]*\) addr:(0x[0-9a-f]+)")


def check_module(module):
    """Prints one line per unit of the module; returns the number of units with problems."""
    cfg, extracted, _ = module_paths(module)
    if not (cfg / "delinks.txt").is_file():
        return 0
    text = (cfg / "symbols.txt").read_text()
    funcs = sorted((int(m.group(3), 16), int(m.group(2), 16), m.group(1)) for m in SYM.finditer(text))
    labels = set(re.findall(r"^(\S+) kind:label", text, re.M))
    data_starts = {int(m.group(2), 16): m.group(1) for m in re.finditer(r"^(\S+) kind:data\S* addr:(0x[0-9a-f]+)", text, re.M)}
    units = []
    for m in re.finditer(r"^(\S+\.(?:c|cpp|s)):\n((?:    .*\n?)+)", (cfg / "delinks.txt").read_text(), re.M):
        t = re.search(r"\.text\s+start:(0x[0-9a-f]+) end:(0x[0-9a-f]+)", m.group(2))
        if t:
            units.append((int(t.group(1), 16), int(t.group(2), 16), m.group(1), "complete" in m.group(2)))
    units.sort()
    base = module_base(module)
    code = extracted.read_bytes()
    failed = 0
    for i, (start, end, src, done) in enumerate(units):
        probs = []
        orig = [f for f in funcs if start <= f[0] < end]
        data_only = not orig and start in data_starts  # a unit of data only (an assembled table)
        # An assembler unit may open with padding or a table and carry pools and tables after its last routine.
        assembled = src.endswith(".s")
        # A C unit may also open with its initialized data when a section pragma puts that data in .text.
        if (not orig or orig[0][0] != start) and start not in data_starts and not assembled:
            probs.append(f"start {start:#x} is not a function start")
        if start % 4 or end % 4:
            # The linker places every section on a 4-byte boundary: an end at a halfword (after a Thumb function)
            # moves everything after the unit. End the range after the padding.
            probs.append(f"range {start:#x}-{end:#x} is not 4-byte aligned")
        last = max((f[0] + f[1] for f in orig), default=end if data_only else start)
        if last > end:
            probs.append(f"a function runs past the end ({last:#x})")
        elif any(code[last - base:end - base]) and not assembled:
            probs.append(f"non-zero bytes after the last function ({last:#x}-{end:#x})")
        if i + 1 < len(units) and units[i + 1][0] < end:
            probs.append(f"overlaps {units[i + 1][2]}")
        obj = BUILD / re.sub(r"\.(c|cpp|s)$", ".o", src)
        if obj.exists():
            # every defined function symbol, whatever its binding (inline C++ functions get an unusual one)
            with open(obj, "rb") as f:
                elf = ELFFile(f)
                kind = "STT_OBJECT" if data_only else "STT_FUNC"  # a data unit holds objects, a code unit functions
                defined = {sym.name for sym in elf.get_section_by_name(".symtab").iter_symbols()
                           if sym["st_info"]["type"] == kind and sym["st_shndx"] != "SHN_UNDEF"
                           and not sym.name.startswith(("$", "@", "."))}
            # a data-only unit holds every data symbol in its range
            names = {f[2] for f in orig} | ({n for a, n in data_starts.items() if start <= a < end} if data_only else set())
            if missing := sorted(names - defined - labels):
                probs.append("in the range but not in the source: " + ", ".join(missing))
            variants = {XTOR.sub(r"\1?\2", n) for n in names}
            if extra := sorted(n for n in defined - names if XTOR.sub(r"\1?\2", n) not in variants):
                probs.append("in the source but not in the range: " + ", ".join(extra))
        else:
            probs.append("no object (run ninja report)")
        failed += bool(probs)
        state = "linked " if done else "pending"
        print(f"{module:5} {state} {src:44} {start:#x}-{end:#x} " + ("; ".join(probs) or "OK"))
    return failed


def main():
    failed = sum(check_module(m) for m in modules())
    sys.exit(1 if failed else 0)


if __name__ == "__main__":
    main()
