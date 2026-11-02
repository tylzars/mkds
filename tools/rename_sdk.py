#!/usr/bin/env python3
"""Renames library functions that game code knows by placeholder names to their real (C) names.

Input: lines `<address> <Name>` (e.g. `0x02012345 GX_SetGraphicsMode`), for functions of the main module now
written in C. For each one whose symbols.txt entry is a placeholder (`func_<addr>`, or its mangled form in C++ code):
  - every declaration of `func_<addr>` in src/, include/ and libs/ takes the real name, keeping that file's own parameter
    and return types (so callers compile exactly as before); in C++ files it becomes `extern "C"`;
  - every other use of `func_<addr>` is renamed;
  - the symbols.txt entry is renamed.
Check afterwards that `ninja report` shows no function getting worse. Run it on the reference version
(REFERENCE_VERSION in tools/project.py); sync_symbols.py then carries the names into the other versions' config.

  rename_sdk.py names.txt [--write]
"""
import argparse
import re
from pathlib import Path
from project import VERSION  # noqa: E402  (tools/project.py)

ROOT = Path(__file__).resolve().parent.parent
SYMS = ROOT / f"config/{VERSION}/arm9/symbols.txt"
DECL = re.compile(r"^(?P<indent>[ \t]*)(?P<ext>(?:extern[ \t]+(?:\"C\"[ \t]+)?)?)"
                  r"(?P<rest>(?!return\b|else\b|case\b|do\b|delete\b|new\b)(?:(?:const|unsigned|signed|struct|volatile)"
                  r"[ \t]+)*[A-Za-z_]\w*(?:[ \t]*\*+[ \t]*|[ \t]+))(?P<name>func_[0-9a-f]{8})"
                  r"(?P<args>[ \t]*\([^;{}]*\)[ \t]*;)", re.M)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("names")
    ap.add_argument("--write", action="store_true")
    ap.add_argument("--symbols", default=str(SYMS), help="symbols.txt of the module (default: main)")
    ap.add_argument("--sources-only", action="store_true",
                    help="input lines are `<address> <old symbol> <new name>`; only src/, include/ and libs/ change")
    a = ap.parse_args()
    pairs = [ln.split() for ln in Path(a.names).read_text().splitlines() if ln.strip()]
    symfile = Path(a.symbols)
    syms = symfile.read_text().splitlines()
    by_addr = {}
    for i, ln in enumerate(syms):
        m = re.match(r"(\S+) kind:function\S* addr:(0x[0-9a-f]+)", ln)
        if m:
            by_addr.setdefault(int(m.group(2), 16), i)
    renames = {}
    if a.sources_only:
        # lines: <address> <old symbol> <new name>; symbols.txt already renamed (e.g. by sync_symbols.py)
        for addr, old, name in (p[:3] for p in pairs):
            m = re.search(r"func_[0-9a-f]{8}", old)
            if m:
                renames[m.group(0)] = name
        pairs = []
    for addr, name in pairs:
        i = by_addr.get(int(addr, 16))
        if i is None:
            print("no symbol at", addr)
            continue
        old = syms[i].split()[0]
        m = re.search(r"func_[0-9a-f]{8}", old)
        if not m or m.group(0) != f"func_{int(addr, 16):08x}":
            if old != name:
                print(f"{addr}: symbol is '{old}', not a placeholder; left alone")
            continue
        renames[m.group(0)] = name
        syms[i] = name + syms[i][len(old):]
    files = [p for d in ("src", "include", "libs") for p in (ROOT / d).rglob("*") if p.suffix in (".cpp", ".hpp", ".h", ".c")]
    changed = 0
    for p in files:
        text = p.read_text()
        if not any(old in text for old in renames):
            continue

        def decl(m):
            if m.group("name") not in renames:
                return m.group(0)
            ext = 'extern "C" ' if p.suffix in (".cpp", ".hpp") else ("extern " if m.group("ext") else "")
            return f'{m.group("indent")}{ext}{m.group("rest")}{renames[m.group("name")]}{m.group("args")}'

        new = DECL.sub(decl, text)
        for old, name in renames.items():
            new = re.sub(r"\b" + old + r"\b", name, new)
        if new != text:
            changed += 1
            print("edit", p.relative_to(ROOT))
            if a.write:
                p.write_text(new)
    print(f"{len(renames)} functions renamed, {changed} files")
    if a.write and not a.sources_only:
        symfile.write_text("\n".join(syms) + "\n")


if __name__ == "__main__":
    main()
