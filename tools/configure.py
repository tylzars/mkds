#!/usr/bin/env python3
"""Generates build.ninja for the decomp. Game-specific settings live in tools/project.py.

Pipeline:  baserom --dsd rom extract--> extract/<ver>/
           dsd delink                -> build/<ver>/delinks/*.o   (asm-equivalent objects for not-yet-decompiled code)
           mwccarm src/**.c(pp)      -> build/<ver>/src/**.o      (decompiled code, for TUs marked `complete`)
           mwasmarm libs/**.s        -> build/<ver>/libs/**.o     (data-only or hand-placed regions)
           dsd lcf + mwldarm         -> build/<ver>/arm9.o + module binaries
           dsd rom config/build      -> build/<ver>/<game>_<ver>.nds, checked against <game>_<ver>.sha1

For a game with several versions, pass the version here; the other tools then work on the configured version
(DECOMP_VERSION=<ver> overrides it for one command).
"""
import argparse
import hashlib
import json
import os
import re
import shlex
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from project import (CC_FLAGS, DECOMP_ME_COMPILER, DSD_INIT_FLAGS, GAME, LD_FLAGS, MWASM_VERSION,  # noqa: E402
                     MWCC_VERSION, PATH_COMPILERS, REFERENCE_VERSION, VERSION, VERSIONS, source_flags)

ROOT = Path(__file__).resolve().parent.parent
os.chdir(ROOT)

# tools/build_wibo.sh builds this upstream commit (53-bit x87 precision for the guest, as on Windows).
WIBO_VERSION = "g420a75b"
OBJDIFF_TAG = "v3.8.2"
DSD_TAG = "v0.12.1"

parser = argparse.ArgumentParser()
parser.add_argument("version", nargs="?", default=VERSION, choices=VERSIONS)
parser.add_argument("-w", "--wine", default="tools/bin/wibo", help="wibo or wine binary used to run mwcc/mwld")
parser.add_argument("--compiler", type=Path, help="pre-installed compiler root (contains 1.2/base/...)")
parser.add_argument("--dsd", type=Path, default=Path("tools/bin/dsd"), help="dsd binary (downloaded on the first run)")
parser.add_argument("--arm7-bios", type=Path, default=Path("arm7_bios.bin"))
args = parser.parse_args()

ver = args.version
info = VERSIONS[ver]
os.environ["DECOMP_VERSION"] = ver  # for the tools run below, before build.ninja names the new version
PY = shlex.quote(sys.executable)
DSD = str(args.dsd)
WINE = args.wine
OBJDIFF = "tools/bin/objdiff-cli"
MWCC_ROOT = args.compiler or Path("tools/mwccarm")
CC = str(MWCC_ROOT / MWCC_VERSION / "mwccarm.exe")
ASM = str(MWCC_ROOT / MWASM_VERSION / "mwasmarm.exe")
LD = str(MWCC_ROOT / MWCC_VERSION / "mwldarm.exe")

baserom = Path(info["baserom"])
extract_dir = Path("extract") / ver
extract_cfg = extract_dir / "config.yaml"
config_dir = Path("config") / ver / "arm9"
dsd_config = config_dir / "config.yaml"
build_dir = Path("build") / ver
have_bios = args.arm7_bios.is_file()
bios_flag = f"--arm7-bios {args.arm7_bios}" if have_bios else ""

if not args.dsd.is_file():
    if args.dsd != Path("tools/bin/dsd"):
        sys.exit(f"{args.dsd} not found")
    subprocess.run([sys.executable, "tools/download_tool.py", "dsd", DSD_TAG, "--path", str(args.dsd)], check=True)
if WINE == "tools/bin/wibo":
    version = subprocess.run([WINE, "--version"], capture_output=True, text=True).stdout if Path(WINE).is_file() else ""
    if WIBO_VERSION not in version:
        sys.exit(f"{WINE} missing or not the pinned build ({WIBO_VERSION}); run tools/build_wibo.sh first")
if not baserom.is_file():
    sys.exit(f"{baserom} not found; see extract/README.md")
# Without the ARM7 BIOS, tools/fix_header.py writes the header field at 0x6C; by default it is the base ROM's value.
secure_area_crc = info.get("secure_area_crc")
if secure_area_crc is None:
    with baserom.open("rb") as f:
        f.seek(0x6C)
        secure_area_crc = int.from_bytes(f.read(2), "little")
# The rebuilt ROM must equal the base ROM, so its expected hash is the base ROM's.
sha1_file = f"{GAME}_{ver}.sha1"
if not Path(sha1_file).is_file():
    digest = hashlib.sha1(baserom.read_bytes()).hexdigest()
    Path(sha1_file).write_text(f"{digest}  {build_dir / f'{GAME}_{ver}.nds'}\n")
    print(f"Wrote {sha1_file} from {baserom}: commit it")

# dsd needs an extracted ROM to answer `json delinks`, so extract eagerly the first time.
if not extract_cfg.is_file():
    subprocess.run([DSD, "rom", "extract", "--rom", str(baserom), "--output-path", str(extract_dir)]
                   + (["--arm7-bios", str(args.arm7_bios)] if have_bios else []), check=True)
# A new game has no dsd config yet: generate one (symbols, relocations, one delinks entry per module).
if not dsd_config.is_file():
    print(f"No {dsd_config}: running dsd init")
    init = subprocess.run([DSD, "init", "--rom-config", str(extract_cfg), "--output-path", str(config_dir.parent),
                           "--build-path", str(build_dir)] + DSD_INIT_FLAGS, capture_output=True, text=True)
    if init.returncode:
        errors = [l for l in (init.stdout + init.stderr).splitlines() if "ERROR" in l or l.startswith("Error")]
        sys.exit("dsd init failed:\n  " + "\n  ".join(errors[-3:] or ["(no error text)"])
                 + "\nSee \"Setting up a new game\" in docs/decompiling.md for the usual causes and fixes.")
    if ver != REFERENCE_VERSION:  # this version's own placeholders get its name (tools/tag_placeholders.py)
        subprocess.run([sys.executable, "tools/tag_placeholders.py", ver, "--write"], check=True)
# Linker-script inputs the build depends on (tools/lcf_force_active.py); empty until a unit needs them.
for name, text in (("force_active.txt", "# Data symbols the original link kept although nothing references them.\n"),
                   ("lcf_edits.txt", "# place / alias / inner edits for the linker script, see tools/lcf_force_active.py.\n")):
    if not (config_dir / name).is_file():
        (config_dir / name).write_text(text)
delinks = json.loads(subprocess.run([DSD, "json", "delinks", "-c", str(dsd_config)],
                                    check=True, capture_output=True, text=True).stdout)

dsd_config_files = sorted(str(p) for p in config_dir.rglob("*") if p.suffix in (".txt", ".yaml"))
include_dirs = ["include"] + sorted(str(p) for p in Path("libs").rglob("include") if p.is_dir())
sources = sorted(p for d in ("src", "libs") for p in Path(d).rglob("*") if p.suffix in (".c", ".cpp", ".s"))

lines: list[str] = []
w = lines.append


def build(outputs, rule, inputs=(), implicit=(), order_only=(), variables=None):
    outs = " ".join(outputs) if isinstance(outputs, list) else outputs
    ins = " ".join(inputs) if isinstance(inputs, list) else inputs
    s = f"build {outs}: {rule}"
    if ins:
        s += f" {ins}"
    if implicit:
        s += " | " + " ".join(implicit)
    if order_only:
        s += " || " + " ".join(order_only)
    w(s)
    for k, v in (variables or {}).items():
        w(f"  {k} = {v}")
    w("")


w(f"# Generated by tools/configure.py {ver}; do not edit.")
w("ninja_required_version = 1.10")
w("")

# ---- rules ----
w(f"rule download_tool\n  command = {PY} tools/download_tool.py $tool $tag --path $path --outputs $out\n  description = DOWNLOAD $tool\n")
w(f"rule extract\n  command = {DSD} rom extract --rom $in --output-path $outdir {bios_flag}\n  description = EXTRACT $in\n")
w(f"rule delink\n  command = {DSD} delink -c $config && {PY} tools/mark_data.py @{build_dir}/delink_multidef.rsp && {PY} tools/delink_multidef.py @{build_dir}/delink_multidef.rsp\n"
  f"  rspfile = {build_dir}/delink_multidef.rsp\n  rspfile_content = $out\n  description = DELINK\n")
w(f"rule lcf\n  command = {DSD} lcf -c $config && {PY} tools/lcf_force_active.py $lcf_raw $lcf_final --config-dir {config_dir}\n  description = LCF\n")
w(f"rule mwcc\n  command = {WINE} $cc $base_flags $cc_flags {' '.join('-i ' + d for d in include_dirs)} "
  f"-d version_{ver.upper()} -MD -c $in -o $outdir && {PY} tools/transform_dep.py $basefile.d $basefile.d && {PY} tools/demote_multidef.py $out && {PY} tools/mark_data.py $out\n"
  f"  depfile = $basefile.d\n  deps = gcc\n  description = MWCC $in\n")
# The same compile with -requireprotos, writing the calls that have no declaration in scope (tools/check_protos.py).
# tools/protos_prefix.h declares the compiler intrinsics; -prefix looks it up from the first include directory.
w(f"rule protos\n  command = {PY} tools/check_protos.py --one $out $basefile.d -- {WINE} $cc $base_flags $cc_flags "
  f"{' '.join('-i ' + d for d in include_dirs)} -prefix ../tools/protos_prefix.h -d version_{ver.upper()} -MD -c $in "
  f"-o $outdir\n"
  f"  depfile = $basefile.d\n  deps = gcc\n  description = PROTOS $in\n")
w(f"rule expand_incbin\n  command = {PY} tools/expand_incbin.py $in $out\n  description = EXPAND $in\n")
w(f"rule mwasm\n  command = {WINE} {ASM} -proc arm5TE $in -o $out\n  description = MWASM $in\n")
w(f"rule mwld\n  command = {WINE} {LD} {' '.join(LD_FLAGS)} @$objects $lcf -o $out\n  description = LINK $out\n")
w(f"rule disassemble\n  command = {DSD} dis -c $config -a $outdir --ual && touch $out\n  description = DIS\n")
w(f"rule rom_config\n  command = {DSD} rom config --elf $in --config $config\n  description = ROM CONFIG\n")
w(f"rule rom_build\n  command = {DSD} rom build --config $in --rom $out {bios_flag}\n  description = ROM BUILD $out\n")
w(f"rule fix_header\n  command = {PY} tools/fix_header.py $in $out --secure-area-crc $crc\n  description = FIX HEADER $out\n")
w(f"rule sha1\n  command = sha1sum -c $sha1_file && touch $out\n  description = SHA1 $in\n")
scratch = (f"--scratch --compiler {DECOMP_ME_COMPILER} --c-flags {shlex.quote(' '.join(CC_FLAGS + ['-lang=c++']))} "
           if DECOMP_ME_COMPILER else "")
w(f"rule objdiff_config\n  command = {DSD} objdiff -c $config -o . {scratch}--custom-make ninja "
  f"&& {PY} tools/objdiff_place.py objdiff.json $edits\n  description = OBJDIFF CONFIG\n")
w(f"rule objdiff_report\n  command = {OBJDIFF} report generate -c combineTextSections=false -o $out\n  description = REPORT\n")
w(f"rule check_symbols\n  command = {DSD} check symbols -c $config --elf-path $in --fail --max-lines 20 && touch $out\n  description = CHECK SYMBOLS\n")
w(f"rule configure\n  command = {PY} tools/configure.py {' '.join(shlex.quote(a) for a in sys.argv[1:])}\n  generator = 1\n  description = CONFIGURE\n")

# ---- tools ----
tool_outputs = []
if WINE == "tools/bin/wibo":
    tool_outputs.append(WINE)
if args.compiler is None:
    # One zip holds every version, including the PATH_COMPILERS ones.
    # Every file of it an edge uses must be an output here, or a fresh checkout has no rule for it (the assembler).
    extra = [str(MWCC_ROOT / v / "mwccarm.exe") for v in sorted(set(PATH_COMPILERS.values())) if v != MWCC_VERSION]
    build([CC, LD, ASM] + extra, "download_tool", variables={"tool": "mwccarm", "tag": "latest", "path": "tools"})
build(OBJDIFF, "download_tool", variables={"tool": "objdiff", "tag": OBJDIFF_TAG, "path": OBJDIFF})

# ---- extract / delink / lcf ----
# The extracted ARM9 binary is listed as an output too: assembly units take filler from it (.incbin, see below).
build([str(extract_cfg), str(extract_dir / "arm9" / "arm9.bin")], "extract", [str(baserom)], implicit=[DSD],
      variables={"outdir": str(extract_dir)})

delink_files = [f["delink_file"] for f in delinks["files"]]
build(delink_files, "delink", dsd_config_files + [str(extract_cfg)], implicit=[DSD, "tools/delink_multidef.py"],
      variables={"config": str(dsd_config)})
build("delink", "phony", delink_files)

lcf_edits = str(Path(config_dir) / "lcf_edits.txt")
lcf_raw = delinks["arm9_lcf_file"]
lcf_final = str(Path(lcf_raw).with_name("arm9_final.lcf"))
build([lcf_raw, delinks["arm9_objects_file"], lcf_final], "lcf", dsd_config_files + [str(extract_cfg)],
      implicit=[DSD, "tools/lcf_force_active.py", str(Path(config_dir) / "force_active.txt"),
                lcf_edits],
      variables={"config": str(dsd_config), "lcf_raw": lcf_raw, "lcf_final": lcf_final})

# ---- compile ----
# The ROM links the delinked originals until a unit is complete; the compiled objects feed objdiff (report).
compiled_objects = []
protos = []
for src in sources:
    obj = build_dir / src.with_suffix(".o")
    compiled_objects.append(str(obj))
    if src.suffix == ".s":
        # .incbin data (filler from the extracted ROM) is expanded into a copy under build/ first: the assembler
        # reads .incbin input as text and rewrites lone 0x0a bytes. The included files are dependencies.
        incbins = sorted(set(re.findall(r'^\s*\.incbin\s+"([^"]+)"', src.read_text(), re.M)))
        asm_src = str(src)
        if incbins:
            asm_src = str(build_dir / src)
            build(asm_src, "expand_incbin", [str(src)], implicit=["tools/expand_incbin.py"] + incbins)
        build(str(obj), "mwasm", [asm_src], implicit=[ASM] + tool_outputs)
        continue
    version, flags = source_flags(src)
    cc = str(MWCC_ROOT / version / "mwccarm.exe") if version else CC
    build(str(obj), "mwcc", [str(src)], implicit=[cc, "tools/demote_multidef.py", "tools/mark_data.py"] + tool_outputs, variables={
        "cc": cc,
        "base_flags": " ".join(flags[:-1]),
        "cc_flags": flags[-1],
        "outdir": str(obj.parent),
        "basefile": str(obj.with_suffix("")),
    })
    if src.parts[0] in ("src", "libs"):
        pobj = build_dir / "protos" / src.with_suffix(".o")
        protos.append(str(pobj.with_suffix(".txt")))
        build(protos[-1], "protos", [str(src)], implicit=[cc, "tools/check_protos.py", "tools/protos_prefix.h"] + tool_outputs, variables={
            "cc": cc,
            "base_flags": " ".join(flags[:-1]).replace("-w off", "-w on -requireprotos"),
            "cc_flags": flags[-1],
            "outdir": str(pobj.parent),
            "basefile": str(pobj.with_suffix("")),
        })
build("protos", "phony", protos)

# ---- link / rom ----
arm9_o = str(build_dir / "arm9.o")
objects = [f["object_to_link"] for f in delinks["files"]]
build(arm9_o, "mwld", objects + [lcf_final], implicit=[LD, delinks["arm9_objects_file"]] + tool_outputs,
      variables={"objects": delinks["arm9_objects_file"], "lcf": lcf_final})
build("arm9", "phony", [arm9_o])

rom_cfg = str(build_dir / "build" / "rom_config.yaml")
build(rom_cfg, "rom_config", [arm9_o], implicit=[DSD], variables={"config": str(dsd_config)})

rom = str(build_dir / f"{GAME}_{ver}.nds")
if have_bios:
    build(rom, "rom_build", [rom_cfg], implicit=[DSD])
else:
    raw_rom = str(build_dir / f"{GAME}_{ver}.nobios.nds")
    build(raw_rom, "rom_build", [rom_cfg], implicit=[DSD])
    build(rom, "fix_header", [raw_rom], implicit=["tools/fix_header.py"], variables={"crc": hex(secure_area_crc)})
build("rom", "phony", [rom])

build(str(build_dir / "rom.ok"), "sha1", [rom], implicit=[sha1_file], variables={"sha1_file": sha1_file})
build("sha1", "phony", [str(build_dir / "rom.ok")])

build(str(build_dir / "symbols.ok"), "check_symbols", [arm9_o], implicit=[DSD], variables={"config": str(dsd_config)})
build("check", "phony", [str(build_dir / "rom.ok"), str(build_dir / "symbols.ok")])

# Disassembly for reading (not committed): build/<ver>/asm/
build(str(build_dir / "asm" / ".stamp"), "disassemble", dsd_config_files, implicit=[DSD],
      variables={"config": str(dsd_config), "outdir": str(build_dir / "asm")})
build("dis", "phony", [str(build_dir / "asm" / ".stamp")])

# ---- objdiff ----
build("objdiff.json", "objdiff_config", dsd_config_files, implicit=[DSD, "tools/objdiff_place.py", "tools/project.py",
                                                                   lcf_edits],
      variables={"config": str(dsd_config), "edits": lcf_edits})
build("objdiff", "phony", ["objdiff.json"] + delink_files + compiled_objects)
build(str(build_dir / "report.json"), "objdiff_report", ["objdiff.json"] + delink_files + compiled_objects + [arm9_o],
      implicit=[OBJDIFF])
build("report", "phony", [str(build_dir / "report.json")])

# Re-run configure when the dsd config changes (a unit added to or removed from delinks.txt). A new source file is
# picked up through its delinks entry; without one it isn't built.
build("build.ninja", "configure", implicit=["tools/configure.py", "tools/project.py"] + dsd_config_files)

w("default sha1")
Path("build.ninja").write_text("\n".join(lines) + "\n")
print(f"Wrote build.ninja for '{ver}' ({len(objects)} objects, {len(sources)} sources, "
      f"{'with' if have_bios else 'without'} ARM7 BIOS)")
