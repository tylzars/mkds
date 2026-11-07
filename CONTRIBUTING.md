# Contributing

## Layout
| Path | Contents |
| --- | --- |
| `config/<ver>/` | `dsd` configuration: symbols, relocations and file boundaries (`delinks.txt`) |
| `src/Main/` | Game code from the main ARM9 binary, by subsystem; `Unknown/` for files whose purpose isn't known yet |
| `src/ITCM/` | Game code that runs from ITCM |
| `src/NN/` | Game code from overlay `NN` (`00`, `01` and `03` so far); the folder gets a name (`NN_Name`) once the overlay's purpose is known |
| `include/` | Game headers, by subsystem |
| `libs/<name>/` | Library code, each with `src/` and `include/` (an SDK has one folder per module: `libs/NitroSDK/os/`). The C runtime is in `libs/msl/` (the C library) and `libs/mathlib/` (the arithmetic routines the compiler calls: soft float and division); the rest is in `libs/Unknown/` until each library is identified, then NitroSDK goes in `libs/nds/` and NitroSystem in `libs/nns/`. A library can use a different compiler (`PATH_COMPILERS` in `tools/project.py`) |
| `tools/` | Build scripts and analysis tools; `tools/project.py` has the game's settings |
| `docs/` | Notes on the compiler, decompiling and the game |
| `extract/`, `build/` | Your ROM, its extracted files and the build output (never committed) |

## Naming
- Types and functions: `PascalCase`. Struct members: `m` prefix (`mState`). File-scope statics: `s` prefix
  (`sFrameCount`). Globals used by several files: `g` prefix (`gGameData`). Locals and parameters: `camelCase`, with
  `i`, `j`, `k` for loop counters; until a function is understood they stay neutral single letters.
- Library functions use the library's own names (`OS_GetLockID`, `NNS_G3dDraw`), and only once it's certain which
  function it is. For library functions without a known name, pick one pattern per library and keep to it (for
  example `FileOpen`, `HeapAlloc`).
- Constants are `#define`s in `UPPER_SNAKE` with the literal's exact value and type, suffix included (`0x8000u`).
  Don't change a variable or member to an enum type to name its values: the compiler treats enums differently and
  the code changes.
- Name values only when they form a set: the values one member, parameter or return value takes. Names in a set
  share a prefix (`SCENE_`, `UPLOAD_KIND_`) and go in the header that declares what uses them, or at the top of the
  one `.c` file that uses them. Use the names everywhere the set appears. Sentinels, counts, coordinates, sizes and
  one-off waits stay as numbers, with a comment where it helps.
- A word means the same thing in every name. So far: `m...Timer` counts down, `m...Frames` counts up,
  `m...FrameCount` is a fixed length, `m...Handle` holds index + 1 (0 = none), `m...Visible` / `m...Enabled` are 1
  when drawn / active, `Update<X>` runs every frame, `Load<X>` reads a file, `Init<X>` runs once, `Setup<X>` can run
  again. Add to the list as new words come up.
- Every name comes from this repository: what the code does, the game's strings and file paths, the SDK headers, and
  names already given. Never from memory of other code. Names don't include addresses; `symbols.txt` has those.
- Anything not understood yet keeps a placeholder: `func_<addr>` / `func_ov0NN_<addr>` for functions, `data_<addr>` /
  `data_ov0NN_<addr>` for data, `mUnk_<offset>` for members, `Unk<addr>` for structs.
- Placeholder addresses come from the reference version (`REFERENCE_VERSION` in `tools/project.py`). Placeholders
  that exist only in another version include its name (`func_usa_<addr>`), so a name in the source never points at
  a different object in another version. `tools/sync_symbols.py` copies the source names into each version's config.

## Writing code
- While matching, write every function out plainly: no macros such as `MIN`, `CLAMP` or `ASSERT`, and no new helper
  functions, except a `static inline` that the match needs (named `<function>_inline`, see
  [docs/decompiling.md](docs/decompiling.md)). The rest can come once everything matches.
- Hardware registers use the SDK headers' names (`reg_G3X_*`), or the address cast in place where there is none.
- Write each struct member with its offset: `/* 2c */ u8 mState;`.
- Data is written as typed source (structs and arrays with their values), not as byte dumps. Bytes that aren't
  meaningful data are read from your ROM at build time (`.incbin`, expanded by `tools/expand_incbin.py`).
- Comments say what the code or the compiler does, never where the code came from. Comment hand-written `asm`
  functions.
- Format with `clang-format` (the repository's `.clang-format`). It squashes `asm` functions onto one line, so put
  `// clang-format off` and `// clang-format on` around them.

## Headers
- Headers go in `include/` (library headers in `libs/<name>/include/`), never next to a source file. Include them by
  that path: `#include "01/code_0218254c.h"`. There is one copy of every header.
- Each source file has a header with the same path and name: `src/01/code_0218254c.c` →
  `include/01/code_0218254c.h`. It declares every function and global the file defines (not its statics), and the
  structs they use.
- A header that uses a struct only through a pointer declares it (`typedef struct Unk0206bcb0 Unk0206bcb0;`) instead of
  including the struct's header. A file that reads a struct's members includes that struct's header itself.
- Give parameters and return values the types the code shows:
  - a pointer whose fields the code reads or writes: a pointer to a struct (`Unk<addr>` until it has a name);
  - a pointer the code only passes on: `void *`;
  - a number: `s32`/`u32`, or `s16`/`u16`/`s8`/`u8` when the code narrows it (`lsl`/`lsr`, `strh`, `ldrsb` ...);
  - no return value: `void`.

  Never `u32` for a pointer.
- If a call needs a cast, fix the callee's declaration instead. Changing a declaration can change the code of every
  caller (narrowing a `u32` to a `u16` adds instructions), so rebuild and compare the whole report afterwards: no
  function may get worse.
- A `.c` file includes its own header first, then the header of each file it calls into or reads data from. No
  `extern` declarations in `.c` files, and no copies of another file's declarations in your header. A header itself
  includes only what its declarations need: `types.h` and the headers that define the structs it names.
- A struct used by one file goes in that file's header. A struct used by several files goes in the header of the
  file with most of the functions that use it, or in a shared `types_<area>.h`. Never define the same struct twice
  under two names; add the missing members to the existing one.

For example, `include/01/code_0218254c.h`:
```c
#pragma once

#include "types.h"
#include "01/code_02181c3c.h" // Unk02181c3c

// Object with a flags word at 0x48.
typedef struct Unk0218274c {
    /* 00 */ u8 mUnk_00[0x48];
    /* 48 */ u32 mUnk_48;
} Unk0218274c;

void func_ov001_0218263c(void *param_1, Unk02181c3c *param_2);
u8 func_ov001_0218274c(Unk02181c3c *param_1, Unk0218274c *param_2, u8 *param_3, u8 *param_4);
```
and `src/01/code_0218254c.c` starts with `#include "01/code_0218254c.h"`, then the headers of the files it calls.

## Adding a source file
1. Add the file and its section ranges to the right `delinks.txt`; `dsd` splits the original object there. A `.text`
   range starts at the file's first function and ends on a 4-byte boundary after its padding. Put `// provisional`
   above an entry whose boundaries are a guess. The format is in [docs/decompiling.md](docs/decompiling.md),
   "Workflow" step 4.
2. Write the functions in address order until each one matches. One that doesn't match yet gets a
   `// non-matching:` comment with the exact difference. A file can be committed like that, unlinked.
3. Once every function matches, link the file with `tools/try_link.py <unit>`. The ROM must still match.

The full steps and tools are in [docs/decompiling.md](docs/decompiling.md), "Workflow".

## Commits
- One area per commit (a file, a library, a tool). Keep messages short, about 50 characters, and say only what the
  change does.
- Commit source, headers, config, docs, the build and its tools. Scratch files, probes (except the compiler evidence
  in `docs/probes/`), search output and one-off scripts stay out, and nothing loose goes in the root.

## Before committing
- `ninja` ends with `mkds_usa.nds: OK`, and `ninja check` passes.
- After `ninja report`: `tools/check_calls.py`, `tools/check_callees.py` and `tools/check_strings.py` report 0,
  `tools/check_signatures.py` and `tools/check_protos.py` list nothing, and `tools/check_units.py` prints OK for
  every unit. Each exits non-zero when something is wrong.
- No function scores worse in `build/<ver>/report.json` than before.
- Before pushing, run `tools/progress.py update` for the version you built.
- Docs state only what has been checked, and say so where something hasn't.

## Rules
- Never commit anything from the game: ROMs, assets, extracted files or disassembly. Strings and file paths the code
  uses belong in source like any other constant.
- Every function is decompiled from this ROM. Code, headers and text from other decompilations (other versions or
  related games included) aren't accepted. Write SDK headers yourself from the API names and the code.
- This repository stands on its own: no "same as project X", "sister project" or names "taken from" another
  repository in sources, docs, config or commits. Give evidence from this ROM instead ("matches at 1.2 base with
  `-O4,s`, not at `-O4,p`").
