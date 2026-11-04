#!/usr/bin/env python3
"""Adds a `$d` mapping symbol where a data object starts inside a code section of a delinked object.

`dsd delink` writes mapping symbols only for code. objdiff reads a code section without a `$d` as instructions, so
data kept in .text (a table after a function, a build block) is decoded as code and scores about 40% against the
compiled object, which does carry `$d` there. A `$d` is added at each data object that follows code or starts the
section; objects that follow another data object stay inside the same run. (dsd's `-M` adds `$d` for every literal
pool too, which makes the compiled functions score lower.)

Run on the delinked objects after `dsd delink` and on each compiled object. Arguments may also come from a shell-quoted response file (`@path`).
"""
import shlex
import shutil
import subprocess
import sys
from pathlib import Path

from elftools.elf.elffile import ELFFile

SHF_EXECINSTR = 4
OBJCOPY = shutil.which("arm-none-eabi-objcopy") or shutil.which("llvm-objcopy") or "objcopy"

paths = []
for arg in sys.argv[1:]:
    paths.extend(shlex.split(Path(arg[1:]).read_text()) if arg.startswith("@") else [arg])

for path in map(Path, paths):
    with open(path, "rb") as fh:
        elf = ELFFile(fh)
        symtab = elf.get_section_by_name(".symtab")
        if symtab is None:
            continue
        syms = {}  # section name -> [(offset, name, symbol type)]
        marks = set()
        for sym in symtab.iter_symbols():
            idx = sym["st_shndx"]
            if not isinstance(idx, int):
                continue
            sec = elf.get_section(idx)
            if not sec["sh_flags"] & SHF_EXECINSTR:
                continue
            syms.setdefault(sec.name, []).append((sym["st_value"], sym.name, sym["st_info"]["type"]))
        adds = []
        for sec, lst in syms.items():
            lst.sort(key=lambda s: (s[0], s[1] != "$d"))
            have = {off for off, name, _ in lst if name == "$d"}
            prev_data = False
            for off, name, typ in lst:
                if name == "$d":
                    prev_data = True
                    continue
                if name.startswith("$"):
                    prev_data = False
                    continue
                if typ == "STT_OBJECT":
                    if not prev_data and off not in have:
                        adds.append(f"$d={sec}:{off},local")
                    prev_data = True
                elif typ == "STT_FUNC":
                    prev_data = False
    if adds:
        cmd = [OBJCOPY] + [a for x in adds for a in ("--add-symbol", x)] + [str(path)]
        subprocess.run(cmd, check=True)
