# Decompiling Notes

Lessons for getting functions to match exactly. This is a byte-matching decompilation of Mario Kart DS, built with
the CodeWarrior mwccarm 1.2 base compiler; flags and evidence are in `compiler.md`. Paths use the default version
`usa`; substitute yours. Building and the ninja targets: `../INSTALL.md`. Naming, headers, commits and rules:
`../CONTRIBUTING.md`.

## Repository Layout

- `src/Main/Unknown/` holds the main binary's code and `src/ITCM/` the code that runs from ITCM, one file per unit,
  named `code_<address>.c`.
  `src/00/`, `src/01/`, `src/03/` hold overlays 0, 1 and 3. `libs/*/src/` holds library code (`libs/msl/` for the C library, `libs/mathlib/` for the arithmetic routines the compiler calls, `libs/Unknown/` for the rest).
  `include/` mirrors `src/` (`include/01/code_0218254c.h` for `src/01/code_0218254c.c`); a library's headers are in
  `libs/<name>/include/`. Hand-written assembly units are `.s` files next to the C ones (`libs/Unknown/src/`).
- `config/usa/arm9/` is the `dsd` configuration of the main module: `symbols.txt`, `relocs.txt`, `delinks.txt` (the
  unit list), `force_active.txt`, `lcf_edits.txt`, `config.yaml`. `itcm/` and `dtcm/` have the same three files for the
  TCM modules, and `overlays/ov0NN/` for each overlay. `config/eur/` has the same shape for the other version.
- `progress/<ver>/` has the recorded history, graph and treemap (`tools/progress.py`). `build/` (the output, with
  `build/<ver>/report.json` and `build/<ver>/asm/`), `extract/` and `tools/bin/` are generated and never committed.
- `tools/project.py` has the game's settings: compiler, flags and per-path flag changes.
- Other notes: `compiler.md` (compiler evidence and `probes/`), `toolchain.md`, `versions.md`.

## Names and Notes

- Anything not understood yet keeps a placeholder name: `func_<addr>` for main-module functions,
  `func_ov0NN_<addr>` for overlay functions, `data_<addr>` and `data_ov0NN_<addr>` for data, `Unk<addr>` for struct
  types (`Unk021d1da8`), `mUnk_<offset>` for members (`mUnk_02`). Names carry no other meaning until the code is
  understood.
- A `static inline` helper that the match needs is named after the function it serves: `func_0202212c_inline`, then
  `func_0202212c_inline2` for a second one (1.10). Helpers and macros that only tidy the code come after everything
  matches.
- Locals and parameters are neutral: single letters (`a`, `b`, `p`, `i`, `j`).
- A function that doesn't match yet keeps a `// non-matching:` comment directly above it with the exact difference
  (size against the original's size, which words or registers differ, the first differing instruction). Remove it
  when the function matches (`tools/clean_notes.py`); a note can be out of date, so start from a fresh diff.
- A form that gives the original's bytes but probably isn't its source is marked `// placeholder: <what it stands in
  for>` (see "Placeholders").
- Version differences go under `#ifdef version_<VER>` (see "Versions").

## Workflow

1. Pick a function or file. `ninja dis` writes disassembly to `build/usa/asm/`.
2. Write the function in a scratch file with a `// PROBE: <symbol> <module> <address>` line and compare it:
   `python3 tools/probe_compilers.py <file> --unit <source path it will live at> --show`. It compiles with the
   build's compiler and flags for that path and prints a side-by-side diff (`*` = differs, relocated bytes masked).
   Without `--unit`, pass `--only` and `--flags` yourself, including `-O` and `-inline`. Probes mask call targets
   and literal addresses, so check those against the original.
3. When only registers or stack slots differ, mark movable declarations with a trailing `//PERM` and run
   `python3 tools/permute.py <file> <function>`. `tools/auto_permute.py`, `tools/mutate.py` and `tools/permuter.py`
   search wider; run long searches in the background.
4. Put the code in its translation unit under `src/` (or `libs/<name>/src/`), functions in address order, with an
   entry in `config/usa/arm9/delinks.txt` (see `CONTRIBUTING.md`): the source path, one line per section it owns,
   and `complete` once it links from source:

       src/Main/Title.c:
           complete
           .text       start:0x02004a20 end:0x02004c48
           .rodata     start:0x0205f010 end:0x0205f0a4

   A unit's `.text` range starts at its first function and ends on a 4-byte boundary after the padding
   (`tools/check_units.py`). Shared types go in `include/`, library declarations in `libs/<name>/include/`. Each
   function has one declaration with the definition's types (`tools/check_signatures.py`), and every call needs a
   declaration in scope: the build's `-w off` hides undeclared calls, so run `tools/check_protos.py`. Header rules:
   `CONTRIBUTING.md`, "Headers".
5. `ninja report`, then rename the original symbols to your names:
   `python3 tools/sync_symbols.py build/usa/<path>.o main --write`. It finds each matching function by its bytes.
   Settle identical candidates with `--assume NAME=ADDR`. With several versions, run it for each
   (`DECOMP_VERSION=<ver>`). Symbols your code references inside a bigger original object are placed by
   `python3 tools/resolve_undefined.py <unit> --write`.
6. Run `python3 tools/check_calls.py`, `tools/check_callees.py` and `tools/check_strings.py`. Matching masks
   relocated words, so a function can match while calling the wrong function or loading the wrong string.
7. A function that doesn't match yet stays in its file with a `// non-matching:` comment saying what differs
   (`tools/unmatched.py` lists them; `tools/clean_notes.py` removes notes once they match). Such files stay
   unlinked until their code is done.
8. To link a unit whose functions all match, run `python3 tools/try_link.py <unit>` (or `--libs`). It runs the steps
   below and restores the config if anything fails.
   - `tools/link_check.py <unit>` checks function order and that every compiled data section has a range. Under 1.2
     a file defines its functions in descending address order; fix with `tools/reorder_functions.py <unit> --write`.
   - `tools/data_ranges.py <unit> --write` finds the data ranges. It refuses when sections disagree, land in the
     wrong kind of section (`.data` in the original's `.rodata` means wrong const-ness), or hold different bytes.
   - `tools/mark_complete.py <unit>`, then `ninja`: the ROM must still match.
   - `tools/sync_linked_symbols.py --write`, then `ninja` and `ninja check`. Never run it after a failed build.
   - Link many units in one build; split the group only when the ROM differs.
   - A file whose ARM functions sit in `#pragma thumb off`/`on` blocks: `reorder_functions.py` breaks it; reorder
     by hand, one block per run of ARM functions.
   - Data that won't range (conflicts, a link-order cycle): wrong file boundaries (1.11).
   - ROM shorter after linking: a function reached only by a pointer into an address range several overlays share
     is stripped by `-dead`; list it in `config/<ver>/arm9/force_active.txt`.
   - Undefined `_ull_mul` or `_fflt`: see 1.00.

When a unit breaks the ROM on linking, `python3 tools/diff_rom.py` shows where the rebuilt module first differs and
which pointers moved. Read the differing pool words (a wrong table or field behind a masked relocation).

## Tools

Run these from the repository root after `python3 tools/configure.py` (the ones that read `report.json` need
`ninja report` first). Each tool's header says more.

- `ninja`: build the ROM and compare its SHA-1. `ninja check` adds `dsd check symbols`. `ninja report` writes
  `build/<ver>/report.json`. `ninja dis` writes disassembly to `build/<ver>/asm/`. `ninja objdiff` writes
  `objdiff.json` for the GUI. `ninja protos` is what `check_protos.py` runs.
- `tools/probe_compilers.py`: compile a scratch function with the build's compiler and flags and diff it against the
  original, before touching `src/`.
- `tools/permute.py`, `auto_permute.py`, `mutate.py`, `permuter.py`: search declaration orders and source forms for a
  near-miss. Use after reading the diff, when only registers or stack slots differ.
- `tools/check_calls.py`: calls and pointer words of matching functions go where the original's go.
- `tools/check_callees.py`: callee lists of every function, matching or not, compared with the original's.
- `tools/check_strings.py`: strings the matching functions load are the original's.
- `tools/check_signatures.py`: each function has one declaration, with the definition's types.
- `tools/check_protos.py`: calls with no declaration in scope.
- `tools/check_units.py`: each unit's `.text` range against the original functions and the compiled object.
- `tools/unmatched.py`: functions that don't match yet. `tools/clean_notes.py`: drops stale `// non-matching:` notes.
- `tools/sync_symbols.py`: renames the original symbols to your names once functions match.
- `tools/resolve_undefined.py`: places symbols your unit references that `symbols.txt` doesn't name.
- `tools/add_relocs.py`: adds relocations a decompiled unit shows but `relocs.txt` lacks.
- `tools/link_check.py`, `data_ranges.py`, `reorder_functions.py`, `mark_complete.py`, `sync_linked_symbols.py`:
  the steps of linking a unit; `tools/try_link.py` runs them together and keeps what leaves the ROM matching.
- `tools/data_order.py`, `layout_search.py`, `fix_layout.py`, `fix_static_order.py`: data layout (1.11).
- `tools/diff_rom.py`: why the rebuilt ROM differs (shifted pointers, first real difference).
- `tools/progress.py update`: record progress for the version you built (`check` is what the pre-push hook runs).
- `tools/flag_effect.py`: whether a compiler flag changes any object. `tools/objdiff_place.py` and
  `lcf_force_active.py` are build steps, not for daily use.

## Size and Thumb Units

- `tools/project.py` sets the flags: `CC_FLAGS` for game code, `PATH_ADD_FLAGS` and `PATH_DROP_FLAGS` per folder or
  file (the longest matching path wins), `PATH_COMPILERS` for another compiler version. The overlays (`src/00/`,
  `src/01/`, `src/03/`) get `-thumb`; `libs/` gets `-char signed` instead of `-char unsigned`.
- The main module's units are ARM by default. A Thumb function there sits after `#pragma thumb on`, an ARM one in a
  Thumb file between `#pragma thumb off` and `#pragma thumb on` (`src/Main/Unknown/code_020ae730.c`).
- `#pragma optimize_for_size on` goes after the includes of a unit compiled for size (1.00, 1.6).
  `#pragma avoid_byte all` is on a few library files (`libs/msl/src/code_0214177c.c`).
- Adding per-file flags to `PATH_ADD_FLAGS` changes the build for that file only; probe with
  `--unit <source path>` so the probe uses the same flags.

## Config Notes

- `DSD_INIT_FLAGS = ["--allow-unknown-function-calls"]` in `tools/project.py` is set: `dsd init` otherwise stops with
  "Local function call from X to Y leads to no function" at one-instruction `bx lr` functions and code reached only
  through a table.
- The generated `func_<addr>_unk` symbols have size 0, so dsd maps everything up to the next known function as ARM
  code. Thumb pointers in that stretch get linker veneers and the ROM no longer matches. Such a symbol gets its real
  size, including its literal pool, and the name `func_<addr>`.
- On a SHA-1 mismatch, `python3 tools/diff_rom.py` shows the size change and which pointers shifted. Thumb pointers
  that now point at veneers mean a stretch mapped as code that isn't: look for a function before it with a wrong or
  zero size.
- The soft-float runtime at 0x02130380-0x02133670 is hand-written: `dsd init` ended each routine at its first
  return and left the code its branches reach outside every function. Each function was extended over the code only
  it branches into, including its literal pool, and an entry stub that falls through into the next function has a
  symbol of its own. Every non-zero byte of `.text` outside a function should be data.
- Hand-written routines inside `.rodata` (a codec's code mixed with its tables) can keep function symbols, but
  Thumb code in the same object that takes the address of data after them gets a veneer and the ROM grows. The
  problem goes away once units split the gap; until then keep such a routine at the end of `.text`.
- "Call goes to middle of function" warnings usually mean merged functions. Some are real second entries (division
  fast paths, long-branch `bl` inside big Thumb functions) and stay labels.
- `ninja dis` stops with "Inline tables must have a known size" when a data symbol of unknown size sits inside a
  function. Give it a size, e.g. `kind:data(word[4])`.
- `tools/lcf_force_active.py` skips an overlay with no code. `config/<ver>/arm9/force_active.txt` and
  `lcf_edits.txt` are described in 1.11.

## Versions

- Version differences go under `#ifdef version_<VER>` (the build passes `-d version_USA` or `-d version_EUR`).
- Keep every version's `delinks.txt` on the same file list; ranges move by that version's offsets (overlay 1: code
  +0x20, data +0x20 or +0x30).

## Source Patterns

Each rule reads "the binary shows X, write Y". This game is built with the 1.2 base compiler (`compiler.md`).

### 1.00 This Compiler (1.2 Base)

Registers:
- A local declared later gets a lower register than one declared earlier. Spilled locals take stack slots in
  declaration order (first declared, lowest slot). Leaf ARM functions open `lr` before `r4`. Thumb code is never
  scheduled.
- A parameter register untouched through the first statements is the first call's argument: fix the callee's
  signature (`()` drops it).
- On a hardware register, `x = x & m` and `x &= m` get different registers.
- A value below the inner row pointer of a nested table loop: a named row pointer declared before it
  (`for (j = 0, p = tab[i]; j < 3; j++, p++)`).
- A counter in a higher slot than a later loop's: one counter reused for both loops.
- An if/else local in the wrong register: declare it in each arm.
- A value that lands after the loop pointers: a repeated expression, not a local.
- Thumb `muls rD, rS` operand order: the difference is a variable (`d = a - b; ... d * t`).
- Load order inside a call argument: a local assigned just before the call, first in the sum.
- `cmp; beq; movs 0; b; movs 1`: enum or pointer constants. Integer 0/1 folds to `bne -> movs 1`.
- `lsrs` first with the result in the high register: high word of a multiply,
  `(u16)(((u64)(u32)(x >> 32) * 0x10000) >> 32)`.
- A reused variable's later value takes its register in order of first use, not declaration. Give an earlier block
  its own variable.
- Redundant casts can move registers.
- A load stays where written only across a real branch point: an `if`, `switch`, `goto`, `return`, label, or a loop
  that runs once. `{}`, `do {} while (0)` and constant conditions don't count. A never-read local assigned in a
  conditional still counts.
- A small struct moved as a whole stays in memory. Its field at offset 0 is reused across calls and stores; a `u8`
  array element never is.

Data:
- A function that copies an initialised table matches whatever the values are. Check them against the ROM.
- A file's objects (data, local initialisers, `.rodata`, `.bss`) are sorted by size, smallest first
  (`tools/data_order.py` models ties). Uninitialised file-scope definitions follow in reverse order, then each
  function's strings by ascending function address. An object after strings, or a smaller one after a bigger one,
  starts a new file. A `.bss` pointer used by one run of consecutive units marks one file.

Other:
- A `for` clause runs after the body: an increment that comes first in the original goes after `i++` in the clause.
- `#pragma optimize_for_size on` covers the whole file. Signs: a Thumb leaf saving r4 and lr without a call, indexed
  loops, loops entered by `b test` without a guard, cases sharing an epilogue. Speed and size code in one range
  means a file boundary.
- An inline's locals go after all the caller's. A `static inline` wrapper with a `volatile` local gives a call its
  own argument slot (`MemFillWordsByBlock_inline`).
- 64-bit products: only `_ll_mul` exists, so use `(s64)` operands (unsigned ones call `_ull_mul`). `u64 /` calls
  `_ll_udiv`. `_fflt` is a label inside the unsigned conversion; name it in `symbols.txt`.
- Functions defined out of address order show their calls to each other as mismatches. Reorder.

### 1.0 General Rules

- Which variables exist, where they are defined and their types move registers and scheduling far more than how an
  expression is spelled. Macro vs inline, ternary vs if/else and index spellings usually compile the same. Try
  variable structure first.
- For a register-only difference, run a declaration-order search first (every single move or swap of the
  function-scope declarations). It fixed 7 of about 30 near-misses (func_0202ed50). Spill-slot-only differences get
  the same search (1.9).
- A 100% match can still call the wrong function, load the wrong string or point at the wrong field (`&banks[9]`
  vs `&banks[6]`). Run the checkers.
- A one-word literal-pool difference is often a wrong constant (a wrong divisor), not layout. It can also look like
  a scheduling difference when the original builds a value from a neighbouring constant (`mov r7,#34; sub
  r7,r7,#47` reveals -13 where the source said 3).
- Before fighting a caller's registers, check the callee's real signature: parameter widths, return type (void vs
  value), ignored parameters. Wrong callee prototypes caused several "unfixable" caller misses.
- Code that is dead only by the program's logic still affects scheduling and registers: a store every reachable
  case overwrites, an unread zero initialiser of a variable read later, an overwritten product. Code the compiler
  removes outright never matters, so don't try it: never-read locals, discarded expressions, empty inlines,
  self-assignments, `if (0)`, `do {} while (0)`, empty `asm`.
- To tell scheduling from register allocation, compile with `-proc generic` instead of `-proc arm946e`. It also
  shows stack-parameter copy order at entry.
- Don't change a shared helper (bit-test or flag setters) to fix one caller. Fix the caller's form.
- A function that really uses an object declared `__attribute__((aligned(N)))` compiles unoptimised (no loop
  rotation, globals reloaded from the pool). Use it as a hint if the original looks unoptimised.
- A `// non-matching:` note can be out of date. Start from a fresh diff, fix one difference at a time and keep a
  step only if the number of differing words drops.

### 1.0a Find the Rule by Symptom

Read the side-by-side diff first (with relocations when they matter), pick the row, try the recipe, probe, and keep
a step only if the number of differing words drops.

| The diff shows | Read | First recipe to try |
|---|---|---|
| Size differs | 1.9 (frame, repeated blocks with own arrays), 1.10 (static inline helpers), 1.2 (pointer locals), 1.6 (shared exit, `optimize_for_size`), 1.5 | Find the first block where sizes diverge. Frame only: sort the stack locals by size (1.9). Repeated blocks with own arrays: static inline helpers (1.10). Predicated epilogues against one shared exit: `#pragma optimize_for_size on` (1.6) |
| Frame or stack offsets differ, code the same | 1.9 (slot order, memory locals by size, struct vs separate locals), 1.1 (reused variable) | Declaration-order search; then a struct that is really separate locals; then a reused local given its own variable |
| Registers only: a swap or a rotation | 1.1, 1.0 (declaration search), 1.2 (a local that holds an address), 1.12 (random scaling) | Declaration-order search. Then decide whether the value is a reused variable (write it with an earlier dead variable) or its own local. Rotation in a loop with an inlined getter or a 0/1 flag: 1.1 inline getter rules |
| One or two instructions in a different place | 1.2 (computed local moved into its use; compound assignment), 1.3 (sum order, discarded volatile read), 1.9 (operand order next to a call result), 1.15 (Thumb statement order), 1.6 (address computed before a branch) | Make the earlier computation its own statement that can't move: a call result in a local, `a -= x;` instead of `i = a - x;`, a local with two assignments. Or write the later one inside its single use |
| Extra or missing instruction | 1.2 (extra copy, pointer local with a cast, two uses), 1.8 (where the narrowing sits), 1.7 (small constant from the pool), 1.12 | Ask what the original had one more or less of: a use, a variable, a cast, an argument. An extra `adds rN, r0, #0` is a plain value used a second time (1.2); an extra `lsl/lsr #16` is a narrowing in the wrong place (1.8) |
| A load repeated, or not repeated | 1.4 (const view, shared address), 1.2 (store forwarding, address loads), 1.3 (volatile reads), 1.9 | Move the access above or below the preceding `if` or call. Reload wanted: `((const T *) p->f)->g` (1.4). Load wanted once: a local read once, or a macro (1.10) |
| Literal pool or constant form | 1.7, 1.11 (anchors, own sections), 1.2 (constants held in registers), 1.9 | A `.word` that is a symbol: write the symbol (1.7). A small constant loaded from the pool: a symbol the compiler can't fold (1.7). Constant kept in a register: enum-typed local or compound assignment (1.2) |
| Branch or switch form | 1.6, 1.15 (Thumb dispatch), 1.00 (`optimize_for_size`) | `switch` vs if chain, early return vs nested ifs, `b = 0; if (a) { b = (x) != 0; }` for a 0/1 flag (1.6). Thumb jump table ending in `add pc, r0`: compiler difference, not source (1.15) |
| 64-bit multiply form | 1.12, 1.8 (64-bit value in a 32-bit sum), 1.3 (sum order), 1.00 (`_ll_mul`) | Signedness of the product (`(s64)` casts), which factor is cast, the order of the terms, `* 0x10000 >> 32` for `>> 48` |
| Call order or argument order | 1.9 (operand order next to a call result), 1.10 (arguments right to left), 1.3 (side effects) | A call result that must be the left operand of a compare or add: put it in a local, or `(v = f(), v == x)`; a repeated block as an inline helper |
| Identical bytes but under 100%, or 1/1 with a wrong callee | 1.14, 1.12 (`_fflt` vs `_ffltu`), 1.7 (`.word SYMBOL`) | Compare with relocations: a `bl` to the function that ends where this one starts is an artefact; a plain number where the original has a relocation costs points; check helper names |

### 1.1 Registers

Declaration and statement order:
- Declaration order picks registers; assignment order picks load order. Declare `a,b,c,d` and assign `b,a,d,c` if
  that is what the binary shows.
- In a crowded function, initialisation order can swap a pair where declaration order can't, and permuting
  declarations may do nothing.
- Types and order interact: search them together (one large update function matched only with `u32 id = (u8) x`
  and a particular order). `permute.py` supports `//PERM T=u8|u32|int`.
- `s16` locals get different registers from `s32`. Declaration order does not affect `double` locals.
- Read components into named locals in the original's order (`z = p->z; y = p->y; x = p->x;`) to fix load order
  before a call.
- Call results (`int a = g();`) and values hoisted out of loops behave as temporaries, not as named locals.

A short-lived value that reuses a long-lived value's register:
- If the original gives a short-lived value the register of a long-lived one once it is dead, the long-lived value
  must not be a named local. Write it as an expression that folds into its later use (`Entry *entries =
  mData->mEntries;` instead of `Data *d = mData; ... d->mEntries`). Making the short-lived value a named local
  fails, because a local in a straight-line block is removed.

By variable shape:
- A variable assigned in both arms of an if/else gets its register late; a short-lived value per arm
  gets one early.
- The same if/else inside an inline helper that returns the value gets the lowest register (`u32 v; if (...) {...}
  else {...} return v;`). An early return changes it.
- A value returned from an inline helper gets a different register from assigning the variable directly. A variable left
  unset on some path is live from entry and gets low registers.
- Locals shared by two blocks: declare `x, y, step` once at function scope and assign in both blocks, not per block.
- A block-local pointer gets a different register from a function-scope one.
- A global read repeated inside a loop is hoisted and gets a higher register; a named local copy gets a low one.
- A field read through an inline accessor is a temporary: `o->Entries()` vs `o->mEntries` moved a pointer r5->r6.
- A load folded into an address is a temporary: `e = &o->mItems[o->mIndex]` gives the index its register before `o`;
  as its own statement (enum-typed copy) it gets it after `o`.
- `*q++ = x` vs `*q = x; q++;` moves `q` to the end of the order. Write post-increments as separate statements
  (`*base = *r; base++; r++;`). Counter-example: `a[n++] = 0;` needed the folded form. Try both.
- Two locals live across the same calls that swap and that no move fixes: declare one last (func_020f14a0).

Operand and pointer shape:
- `p[c]` vs `p += c; *p`: indexing in place loads the other operand first.
- Index in place instead of through a pointer local (`owner->mSlots[i].x`), and index a table with the global field
  directly (`&tbl[g.a]`) rather than through a named copy of the index.
- A pointer local initialised with a cast (`T *p = (T *) &g;`) keeps the base in a callee-saved register across
  calls. `T *p = &g;`, `g.f`, or a cast at each use reload `g` after each call.

Reused variables and own locals:
- A local the original reuses for a second, separate value (a counter reused for the next loop, a pointer reused
  for a second search) takes its register ahead of the other named locals and compiler temporaries. If the original
  gives a value its register ahead of such a temporary, write it with an earlier variable that is dead there:
  second loop `for (j...)` -> `for (i...)` (func_ov000_021854f8), `b = data[0]` -> `j = data[0]` (func_0211ed80).
- The reverse: a 0/1 or index local that gets the first register in a crowded loop, or a spill slot that sits low,
  was its own named local: `u16 l;` with `l = 0; ... l = 1; v2[0] = v4[l];` (func_020800f4), a string pointer in its
  own `const u8 *y` instead of reusing `x` (func_ov000_02186d7c). Try moving its declaration relative to the loop's
  other locals.
- When two later values swap, the variable that first appears earlier in the function wins. Reuse the variable that
  appears first: `for (j = 0, p = T3; ...)` reusing the first loop's `p` (func_ov003_021c1680). If a variable's
  first use is a short unrelated one (`h = i + 1`), give the early use its own variable (`k = i + 1`,
  func_ov000_021866fc).
- A flag the original registers after a shared-expression temporary must be its variable's first or only value:
  write its earlier use with another local (func_02066fe0).
- A table entry loaded once and kept in a callee-saved register across two calls is a reused dead variable:
  `n = tbl[i].f; f1(n); f2(n);` with `n` from an earlier loop (InitSelectKart).
- A value the original forms itself is not a named local: `while (*(vu8 *) &d->mUnk_1b80 != 2) {}` instead of
  `q = &d->mUnk_1b80; while (*q != 2) {}` (func_ov003_021ce848).
- Where the original gives a local its register only after a shared expression, drop the local and write the
  expression at each use (func_0203a3cc). It works only where nothing between the uses can write the memory.
- `sz = x + 32; sz = (sz + 31) & ~31;` and `(x + 32 + 31) & ~31` give different registers, and the one expression
  folds to `+ 63`. A signed cast stops the fold: `((s32) (x + 32) + 31) & ~31` (func_02003e24).
- A narrow value passed to a wider parameter can take the conversion's register whatever its declaration order. Fix
  the callee's parameter type.

Inline getters and helpers:
- An inlined getter `if (p == 0) return 0; return p->f;` used in several loops can rotate the loop's registers
  (func_020487fc). `u32 r = 0; if (p != 0) r = p->f; return r;` fixes the registers but puts `mov rX, #0` above the
  compare; `p == 0 ? 0 : p->f` gave `moveq` before `ldrne` (func_020401ac).
- Statement order inside a small inline can decide a whole loop's registers: `v1 = a->x - b->x; v2 = a->z - b->z;
  return (s64) v1 * v1 + (s64) v2 * v2;` matched func_020919e8; z first did not.
- Reused locals whose later values take registers in the wrong order, where swapping the first statements breaks the
  load order: a dead initializer on the variable that must come first, `s32 *p = 0;` (the only spelling that matched;
  DrawRaceMNumberPairTwoDigit).
- A later loop that reuses an earlier loop's counter or pointer locals can come out with its registers rotated or
  swapped: give each loop its own named local (func_0208552c, func_020b41e8, func_02042a10). The same holds for a reused
  local whose second use takes its register after the loop counter: give that value its own local (func_0203b6ac).
- A value assigned in both arms of an if/else that takes its register too early: give one arm's value its own local,
  declared before the local it swaps with (func_020b5ae8).
- A narrow local converted where it is passed to a call can take its register before the local it swaps with: declare it
  `u32`, put the narrowing cast at its assignment, and declare it first (func_0214f83c).
- An `s32` local passed to a `u32` parameter inside a loop: declare it `u32` (func_02106580).
- A local whose register must stay apart from a pointer's: assign it earlier, before the preceding test (func_02082750).
- Two values that swap registers: declare the one with the lower register in the original later (`q` before `p`, `s`
  before `c`; func_0204a798, func_020d2c2c).
- A product `i * size` that takes a register in place of `i`: keep the byte offset in the index local, `u32 i = f() *
  size;`, and access through `(T *) ((u32) base + i)`; `(u8 *) base + i` sets the product up again (func_020bab54).
- The loop counter kept in a callee-saved register and the running total spilled, where the original has it the other
  way round: fold the increment into the use, `t[3] = m + k++;` (func_020357dc).
- A call result kept in the return-value local where the original only tests it: use a separate local for the result;
  the return local keeps its initial 0 (func_ov000_021a0cac).
- Scale and component in each other's registers across repeated vector blocks: one pointer local, assigned right before
  each block, instead of several set up at the top (func_0208ecd8).
- A pointer local `p = &a[i]` that disappears because `a[i].f` is also written elsewhere: write `p->f` so the pointer
  stays a named local, then order the declarations (LoadKartAndCharacterFiles).
- A spilled value whose slot sits above the loop pointers but below another variable's: give it two assignments of its
  expression before its read (`c = expr; store c;` twice; one is optimised away) and mention it in the text before that
  other variable, which here is the `for (i = 0; ...)` after them (func_0211baec).
- A flag stored into a bit-field without the `u8` truncation its `&` partners get: declare the flag `u8`
  (func_ov003_021d2b3c).
- An index local reloaded or held differently around a table read: an enum-typed index local, `enum { K0 } k; k = a->m;
  e = tbl[k].f;` (func_020681f0).

### 1.2 Locals, Copies and Constants

Locals that disappear or stay:
- A local used only in the block where it is assigned is replaced by its value and gets no register. It stays when a
  use lies after a join, when a call between kills a value read from memory, or when it copies a parameter register.
- A call result kept in a local loses its name the same way. A repeated identical test `a || a` makes a join that
  keeps the local; the duplicate compare is later dropped. A different-looking second test (`n >= 1` after `n > 0`)
  keeps its compare. Mark such a repeated test as a placeholder.
- A local assigned once is substituted into its use when its right side is a plain operand or a direct read, or
  when it is used in one statement. Substituted values are hoisted out of loops where invariant; passed straight to
  a call they are recomputed. A local assigned twice (`s32 left = c; left += b;`) is computed where written.
- To keep a computation as its own statement, give it a second assignment in the same block or use a compound
  assignment: `s32 r = nscrs[1]->mUnk_0c[i]; r %= 0x400;` (InitMap2D); `a -= g->mUnk_80c;` instead of
  `i = a - g->mUnk_80c;` (func_0202dc68).
- `T *p = o->a; p += o->b;` pins the computation where written. A pointer built by `p = base; p += idx;` doesn't
  share its address with identical `base[idx]` accesses elsewhere; `&e[idx]` or `e + idx` does.
- A pointer local can hoist shared index arithmetic over a branch: `T *e = list->mItems[p];` shares `p*4` with a
  later `p*4 + 0x28`, hoisted above the `if`. Index the container inside each arm to stop it.
- Reading a member directly (`mData->x`) rather than through `T *data = mData;` makes the pointer a temporary; it
  is still loaded once when no store or call intervenes.

Repeated reads and stores:
- A repeated field read is shared when no call sits between the uses. Reading a const table at each use is shared
  even across calls, which can give the original order where a named local takes a register too early.
- Re-read instead of caching where the original reloads a table element or global chain in a loop:
  `g.list->mItems[k]->a + g.list->mItems[k]->b` forces fresh loads; a named pointer lets the compiler reuse them.
- Recompute differences instead of naming them: `x0 - x1` at each use matched where `dx/dy` locals did not.
- A leftover `mov rX, rX` means a store followed by a read-back of the same field.
- `if (field)` right after `field = var;` compiles to `tst #255`. Store first and test the field (`f = g; if (f)`).

Constants held in registers:
- A register already holding a needed constant is reused within straight-line code. A join clears that, so
  `i = 0;` after an `if (n > lim) n = lim;` clamp gives `mov r5, r6`, and before it gives `mov r5,#0`.
- A variable updated by compound assignment keeps its start constant in a register (`int r = 0; r += 0xe0;` ->
  `mov r2,#0; add r3,r2,#0xe0`).
- Enum-typed locals are not constant-folded. When the original keeps a known constant in a register and computes
  with it (`mov r2,#0; mov r1,#52; smulbb r4,r2,r1` for `array[0]`), use an enum-typed local. An enum-typed zero
  stays in its register through a loop of byte stores (`enum {ZERO} z = ZERO; p[k] = (unsigned char) z;`).
- Several zero-initialised locals share one `mov rN,#0`, kept in whichever is assigned first. Declare-then-assign
  picks which; `s32 a = 0, b = 0, c = 0;` as one declaration shares one register where separate ones don't.
- A dead store can matter: `n = 30;` before a switch whose reachable cases all overwrite it keeps 30 in n's
  register for later calls with 30.
- Compound assignment keeps constants from folding: `angle += 90;` / `fx *= 2.0f;` differ from `angle = angle + 90`.
  `k *= -1` keeps `mvn; mul`; `k = k * -1` folds to `rsb` (func_020641f0).
- `x = x + y` and `x = y + x` on a member both compile as `x += y`, old value first. For the old value second, read
  it into a local inside the arm right before the add: `c = a->m; a->m = expr + c;` (func_02087b9c).

Pointer locals and addresses:
- A pointer local initialised with an explicit cast stays a variable: its add is made where it is assigned and every
  access goes through it. A byte copy the original does through one register needs the cast on both pointers; put
  it in a static inline helper with `void *` parameters: `u8 *p = (u8 *) a; const u8 *q = (const u8 *) b;
  p[0] = q[0]; ...` (func_ov000_0218ce14). To keep a global's address in a callee-saved register across calls in
  Thumb: `r = (u8 *) &data_ov000_021b6706;` (func_ov000_021ad264; the plain name and `+ 0` don't).
- A pointer local with one use is folded into it; with two uses it stays, and the field at offset 0 is read from the
  base register while the others go through the pointer. Read every field through the local in the ROM's order
  (func_02094e8c), or write the accesses through the existing pointer locals (func_020f14a0).
- An address computed from a pointer already loaded for a store: write the address statement above the store so the
  base isn't loaded again (func_0203e788). An address the ROM computes before a test's branch: assign it in the
  block of that test (func_0206938c).
- A global's address load is reused only along single-predecessor blocks; the block after an `if` loads it again. A
  second address load early in the ROM means the access sits below the preceding `if` (func_0214d9e8). Two
  statements that share global addresses in the ROM have no branch between them: set the flag first (`b = 0;
  if (a == 0) { b = 1; }`, then both statements; func_0205d6d0).
- An extra copy `ldr r0, [..]; adds r5, r0, #0; adds r5, #8` means the plain loaded value is used a second time
  (func_0204b7b8 passed the base to the call instead of the adjusted pointer).
- A kept `add rX, rY, #0` between two summed terms, with the first term never stored: accumulate from zero in a local,
  `v = 0; v += a; v += b; p->m = v;` (func_020e4ad0, like func_020cf310).
- `n = 2` folded where the original adds 2 to a zero slot: `n = 0; x[n++] = ..; x[n++] = ..;` (func_02042a10).
- A table byte read again after stores: no local; write the element at the test and again at the use (func_02042a10).
- `movs #K; movs #size; muls` rebuilt at each table read across calls, where ours keeps `K` on the stack: an enum-typed
  index local assigned right before each read (func_02078158; 6 words were left).
- A spilled value reloaded into a low register for an argument add, with the add before the other argument copies:
  compute that argument in its own statement first (func_02022eb0).

### 1.3 Scheduling and Evaluation Order

Independent instructions follow statement order, so moving a statement within its block (or adding a call before
it) can flip them.

Memory and aliasing:
- A hardware register accessed through an integer constant (`*(vu16*)0x04000300`) is ordered after every earlier
  global store. When the original reads one ahead of an earlier store, declare the register as an extern object
  and pin its address in the linker script (alias line).
- A direct access to a global past the end of its declared type is ordered against every later load and store. When
  a store seems to pin a later load, check the declared size.
- A store through any pointer makes the compiler re-read a global declared with a complete type (`extern T g;`,
  `extern T g[1];`), but not one declared `extern T g[];`. Give globals their real size (pad a struct to the size
  its block has in the binary). Loads through a pointer local die at any global store; loads written `g[i].f`
  don't.
- Loads from `const` data may move above stores, non-const loads may not. Declare read-only externs const (pointer
  tables `const char *const`).
- A function-local static table schedules like const data while staying in `.data` (a file-scope const would move
  it to `.rodata`). Symbols are `name$N`.
- `abs` declared in a header named stdlib.h is treated as pure: calls with the same argument merge, even across
  stores. Declare it in a project header when the original calls it repeatedly.
- Volatile: a field or parameter re-loaded where the compiler would reuse or hoist it is volatile in the original
  (tick counter, file flags). A store followed by a reload is not by itself a sign. In Thumb code `strb; ldrb` is
  normal; in ARM code look for what sits between (a call, an aliasing store) first.
- A register loaded from a volatile global just before a call that doesn't take it is a discarded volatile read
  statement (`data_02175614.mUnk_00;`), not an extra argument (func_02037abc).
- A volatile field read once for two tests (bits 0x10 and 0x20) is one local read: `c = a->mUnk_4c; b = (c & 0x10)
  != 0;` (func_02063cc4).
- Arguments with side effects (volatile read, `x++`) are evaluated before stack-argument stores and other
  arguments; side-effect-free ones are loaded after the stores. An enum-typed copy plus a named reference gives the
  same effect.
- A `u16`/`s16` local or stack parameter takes a full 32-bit slot and its reloads aren't reused. Parameter and local
  widths move both scheduling and copies.

Spilled values:
- When a spilled value's register is still intact at its next use in the same block, the reload becomes a `mov` or
  is dropped. A use directly after the definition reuses the register (`mov r5,#0; str r5,[sp,#n]`); with an
  instruction in between it reloads. How the variable is built (`s16 x = base; x += off;` vs `x = off + base;`)
  and statement order move this.
- A spilled `s32` whose register still holds the value at a predicated early return has its reload dropped; as `s16`
  it keeps `ldrcs r0,[sp]`. A spilled `u8` holding a call result is reloaded before each compare of a switch chain;
  an `int` isn't.

Expression shapes:
- Narrowing changes scheduling, not just instructions: `-(u8)(m/4)` vs `-((u32)m >> 2)` emit the same ops, but the
  `u8` form schedules `rsb` before the next pool load. Equivalent arithmetic inside a long sum (`y%8 << 3` vs
  `y%8 * 8`) schedules differently; term order doesn't.
- Repeated calls with constant arguments schedule in a repeating cycle. Code before the run shifts it: a global
  store, or a call that returns a value. Several "open" cases were a BOOL-returning callee declared void.
- Store order: `Set(mUnk = value)` (chained assignment as argument) differs from two statements. Compute all sums
  before storing (`u16 y = o->mRotY + r[1]; ...; o->mRotX = x;`); `o->mRotY += r[1]` interleaves loads and stores.
- Create the first operand early and add the second late (`u16 rx = p->mRotX; ...; rx += r[0];`) to get the
  reverse register order.
- Product order: `a*b + c*d` evaluates the right-hand product first; reverse the terms to swap. In a sum of
  products `A + B + C` the ROM's first product is the source's second term, so write the natural
  `x*x + y*y + z*z` (func_0209df84 with 64-bit products; func_02039860 as statements `w = x*x; w += y*y; ...`;
  func_0206988c with 32-bit `mul`/`mla` and the differences as locals in x, y, z order). Statements and one
  expression give different registers.
- When one of several identical expansions (six square sums) schedules differently in the ROM, its expression was
  spelled differently: `(s64) s.x * (s64) s.x + (s64) s.y * (s64) s.y + (s64) s.z * (s64) s.z` at one site of
  func_020800f4. The same casts at all six sites made the function longer.
- `x*3+y` vs `x + x + x + y`: only the spelled-out sum matched a set of animation blends (`(s64) x + x + x + y`).
- `a = b = c = k` stores right to left and changes which register holds the constant. `a = b = 0;` can
  reproduce reload-and-truncate (`ldrb`/`and #0xff`) sequences.
- An identical first instruction in both arms of an if/else (same registers) is hoisted above the branch. Source
  can't stop it; the original avoids it only with different registers per arm.
- `mov rX, rY` just before a load through rX with rY live is a second identical load turned into a copy. A
  `const T *` read (a const-parameter inline helper) keeps the second load apart.
- A stack parameter loaded before the other operands of an `mla` statement: an explicit same-type cast `(s32) e` on two
  of its uses (the only spelling that matched; func_020fcf10).
- A mask computed after the load it is tested against and then reused: write `1U << b` at the test only (func_02007698).
- `x == f()` compiled with the compare operands the other way round: put the result in a local and write it on the left,
  `k = f(); if (k == x)` (func_02151b38).
- `cmp t, reg` with the hardware word read before `t`: read the word through a static inline helper and write `t ==
  helper()` (func_0214f83c).
- Stores to one global array in a different order than ours, with two shifted values in each other's registers: write
  the stores in index order (func_02011624).
- A bit-field update that reads the value before the word: put the value in a local first; reuse one local for the
  stores that follow so only the last definition is folded (func_02056750).
- A member address for a call argument formed before a branch instead of in the call's own block: write that update as
  `m = (s32) (m + v);`, not `m += v;`, and keep the cast (func_020ff6d8).
- A row address added before the element offset (`&t[y]` first, then the element): a pointer local, `p = &t[y][f(x)]; v
  = p->m;` (func_0202a360). A reused index, casts and row or element helpers did not help.
- A final add that loads the local first: `p->m = d[0] + (s32) p->m;` with the same-type cast on the member; `+=` and
  plain `d[0] + p->m` did not match (the only spelling that matched; func_02101964).
- Two differences computed before a wait loop and shifted after it: compute them into two locals before the loop
  (func_0214e464).
- A call result stored to a member before the call where the original stores after: put the call result in a local, then
  the stores in order (func_021243ac).
- `(x & mask) | (m << k)` with the shift evaluated first: write `m * (1 << k)` as a constant multiply (func_021243ac).
- The mask or fraction computed before the table loads, with the index, next index and fraction rotated across r1-r3
  (ARM): assign `f = x & 0xfff` before the indices and declare `f` before them (func_02071568).
- Six byte stores where the original computes `(a - 1) * size` before loading the base: `p = tbl->rec[a - 1].arr; p[0] =
  ...; ... p[5] = ...;` with no offset or base locals (Thumb; func_ov003_021cf378).
- An add with the loaded `s16` element first: `x = a[i]; x += p[i].m;` (func_0212f1f8).
- A call's later argument computed before the call in an earlier argument: pass through a static inline wrapper taking
  all the arguments (func_ov003_021c25e0).
- Index scaled (`lsl #2`) before the base pointer is reloaded: compute the entry address inside the statement that uses
  the index, and set the pointer local after it (func_020072c0).
- A field load after an abs branch, with the `-K` constant load filling its delay and taking r0 across the multiply:
  read the field into a local before the `if` (func_020f6a6c).
- A table byte loaded before the loop's offset init in ours, after it in the original: the table is in `.rodata`, so
  declare it `const` and read it inside the loop (func_ov003_021c965c).
- An address or constant from the early-return test shared with a store far below it, where ours reloads: write that
  store before the first if/else join; the scheduler moves it down to the original's place (ThreadSystemInit).
- Two 0/1 flag arguments computed in the other order: put `? 1 : 0` on the later one only, `d = (v & M) != M ? 1 : 0`
  (Thumb; func_ov000_021a54b0).
- A global pointer loaded before an unrelated subtraction with its index add after it: reuse an existing dead local for
  the pointer, `q = g; v1 = a - b; v2 = ((T *) q)->arr[n].m;`; a fresh local of any type is folded away and does not
  move the load (Thumb; func_0204f644).

### 1.4 Hoisting and Addressing

- A value assigned inside a loop is not hoisted: `d2 = delta; shift = d2*d2/8;` inside the loop stays there; a
  pre-loop form is hoisted and schedules differently.
- Loop-invariant expressions are hoisted out of an outer loop only when bound to a local. Write them inline in the
  inner loop condition to keep them in the loop.
- `T *xb;` declared with other locals and assigned just before a loop puts the address computation before the loop
  guard; `((T*)&x)[k]` at each use puts it after; initialising at declaration changes the registers of the whole function. A named
  `char *q = (char*)&x` gives indexed `q[i]` loads; the cast expression form becomes a running pointer.
- `(u8 *) g[0].member` keeps aliasing with `g` where an extern alias for the same bytes doesn't.
- A table offset as its own variable before the bounds check (`u32 pos = id * 0x20; if (pos >= size) ...`) gives
  the separate shift the original has.
- `tbl[k*3 + byte]` gets a hoisted `tbl + byte`; `const u8 *p = tbl; p += k*3; p[byte]` stops it. Indexing through
  a pointer-to-array type (`int (*t)[3][32]`) recomputes `t + k*4` each iteration.
- A declared 2-D member builds `j + row`; a cast to 2-D (`((u8(*)[2]) flat)[i][j]`) builds `row + j`. Use a union
  view with a real 2-D member.
- A dead product still shapes code: scaling all three components before overwriting one matters.
- A big loop where the original rebuilds stack-array addresses (`add rX, sp, #n`) and constants at each use but
  ours holds them in registers (GpiUpdateSearch): look for a cast of a loop-invariant parameter in that loop
  (`(u32) a` as a call argument). Declare the callee's parameter with the pointer type and pass `a` without the cast
  (a header change; probe every user).
- `((const T *) p->f)->g` in a loop condition shares the base pointer and reloads only the field (func_020800f4). A
  const view on one read of a field a store just changed gives a second load and 4 more bytes (func_0210298c).
- When the ROM reuses one address register in two loads from one table, write the address in both and make the
  expressions differ by a cast on one index: `data[(u32) o->mUnk_78].mUnk_02` and `data[o->mUnk_78].mUnk_5a`
  (func_020a08ec).
- A field loaded twice back to back before a min compare, with one copy kept for the arm and later uses: use a named `t
  = v.x` for those uses and read the compare through `((const Vec3 *) &v)->x` (func_020d2c2c).
- `i << 1` computed early and kept live through a long block for a late store, costing a saved register: write `(u32) i
  * 2` at the store so it is not shared with the address (func_0204a798).
- An element address recomputed per word, where the original adds the base and member offset once and then `i * size`: a
  pointer local to the member, `Vec3 *e = &a[i].m; e->x` (func_020980ec).
- `p += 8` recomputed at each later use where the original adds in place: `p = (u8 *) p + 8;` (ArchiveLoadFromMemory).
- `i * 0x20` strength-reduced across the outer loop where the original shifts each pass: write `(u32) i * 0x20` (or
  `0x20U`) in the subscript (func_020362dc).
- An address used twice that is shared as `(base + i * 2) + off`: write one of the two accesses through `(u8 *) base + i
  * 2` (func_02007698).
- Only `i * 12` kept across a call and `a + r7` formed twice: a same-type cast on the base at the first use only, `f((T
  *) a + i)`, and `&a[i]` later (func_ov000_0219d2e8).
- A global's loads hoisted out of a loop with calls and kept in stack slots, ours reloading each pass: declare the
  extern `const`; a const cast at the use does not do it (func_ov003_021c1cd8).
- Pool address plus constant kept in callee-saved registers across a loop, ours reloading: the loop needs a preheader. A
  0/1 flag set by if/else right before the loop jumps into the header from its then arm, so write `d = b == 0;`
  (func_ov000_0219fbec).
- Every field reloaded after a free-room test while ours reuses the loads: declare the pointer locals loaded from the
  tables `volatile`, and only those (hand-picked; the only spelling that matched; func_02015fa0).
- A loop bound reloaded each pass while the guard's load is reused after the loop (signed `ble`): no named copy of the
  bound; write the condition and the after-loop test through the global (func_ov000_0219fbec).

### 1.5 Loops

- No pre-test (`cmp; bls`) before the body: `do { } while (k < count);`, not `for`. An entry test inside the body
  (back edge jumps to a `count != 0` guard): do-while with the guard as an `if` inside.
- `if (n) { i = 0; do ... while (++i < n); }` has one guard; a `for` keeps a second `cmp/bls`.
- One function-scope loop counter (`u8 i`, maybe `j`) reused by every loop is the common original form, even where
  a loop counts down. Per-loop counters get different registers. When two counters step together the order of
  `j++; i++;` matters.
- `u32 k = 0; ... k = (u8)(k + 1);` fixes counter swaps where `u8 k` fails in every order.
- `unsigned long` vs `unsigned int` are different types to the compiler. It mattered once in game code. In C
  middleware `long` locals and parameters matter much more (`long i` turned `mul` into `smulbb`): try `long` early
  there.
- A pointer declared before a loop and assigned inside it (`e = &list->Items()[i];`) fixed a base/element swap.
- A struct copy declared inside a loop block stays an `ldm/stm` copy re-read from the stack; at function scope it is
  split into registers.
- A loop that returns 1 on a hit and 0 at its natural exit is a static inline helper returning 1 / 0, called as
  `if (helper(p, k) != 0) { ... }`. Its index parameter is `s32` (a `u16` parameter hoists a conversion out of the
  loop): func_020919e8.
- Two induction variables stepping by 2 in the ROM (`add r8, #2; add r7, #2` feeding arguments) mean the argument
  depended on the counter: `m < 6 ? 93 + j * 2 : 94 + j * 2`, not `m < 6 ? 93 : 94` (func_020c8dbc).

- A loop counter set to 0 before earlier calls and kept in a callee-saved register across them was initialised at
  its declaration: `u16 i = 0;` with `for (; i < n; i++)` (func_0206c354).
- Two induction pointers for one row address, both set after the guard: an explicit same-type array cast on one access,
  `(s16 (*)[4]) tbl + i` (the only spelling that matched; func_0202d210).
- A struct-member step placed after the counter increments is in the for update, after `k++`; its reset is in the for
  init, after `k = 0` (func_ov003_021c1cd8).
- Thumb: `movs rX, rY` copying a shared zero for a loop's induction variable, or a loop counter's constant stored before
  the pointer loads of the preheader: assign the counter first, `for (i = 0, x = 0; ...)` or `for (j = n, s = ..., q =
  ...; ...)` (func_020e7460).
- Thumb: one `cmp #0; ble` guard with the pointer load after it and no second guard: `j = 0; if (j < N) { t = ..; do {
  .. j++; } while (j < N); }` (func_020357dc).
- A pointer stepped only to pass as a call argument, with its own spill slot: pass `arr[j]`, not a second pointer
  (func_020357dc).
- Thumb: `ldrsh` with a 0 offset held in a stack slot: write `t[0]`; the 0 is the compiler's hoisted offset, not a
  variable (func_020357dc).
- An inner table loop with a dead counter and a byte offset stepped by 2: `l = j * 12; for (k = 0, s.x = 0; k < N; k++,
  l++, s.x += STEP) tbl[i][l]` (func_ov003_021c0d2c, like func_ov003_021c1cd8).
- A pointer to a field incremented in a loop with its address formed early: drop the pointer and write `p->f++`
  (func_02098d4c).
- Loop counter set before two pool-loaded table pointers: `j = 2; q = ..; p = ..; for (; j < 4; q++, p++, j++)`
  (func_ov003_021c06e0).
- A loop counter taking its register before `counter + off` and before the loop's sum, the reverse of the original:
  count with the variable an earlier loop used, and sum into a variable first used in this loop (func_0212f1f8).
- Loop pointer and counter registers swapped: declare the counter right before the pointer local (func_020072c0).
- A hand-rotated do-while guard giving `bcc` (ROM `blt`) and swapped registers at `j++`: a plain `for (j = 1; j <= f();
  j++)` with the increment at the end (func_020b1a34).
- A later loop's counter and its strength-reduced offset swapped: a new named counter and a new named bound for that
  loop (func_020e4184).
- A stack variable's `+1` placed among the pointer steps, where its first use appears in the body, is a derived
  induction variable: no `a++`; pass `a + i` with a `u16` type like its source. An `s32 a` gives a per-pass add (Thumb;
  func_02113d84).
- Two table pointers stepped before the counter's `+1` and loaded after the counter init: indexed access from a table 8
  bytes earlier, `tbl[j]` with `j = 2..`, not named pointers; `tbl[j - 2]` is not reduced (func_ov003_021c0528).
- A pointer to a local defined last in the preheader, after the hoisted zeros and addresses: `while (n >= K) { q = &c;
  ...; if (b) break; }` instead of an `if` with a `do-while` and `q` set before; the optimiser pulls `q = &c` out of a
  `do-while` even when it is written inside (func_ov000_0218bc08).
- A read placed after the stepped pointer's init and read through a copy of it, while the next loop rereads the field:
  read it inside the first loop and spell the second read as a different expression, `*(u16 *) d`, so the two are not
  merged (hand-picked; func_02009098).
- A pointer re-read placed after `i++` in the latch: no `p = global` in the body; read the global directly
  (func_ov000_021a18e0).
- A global pointer kept across the loop header into the body where the original reloads it each pass: no pointer or byte
  local inside the loop; write `global->member` at every use (condition and indices) and assign the local after the loop
  (Thumb; func_ov003_021cec50, like func_ov003_021cedbc).
- A step after the counter's `+1` in the original, with a named for-update variable that gets the order right but adds a
  round of register changes: `for (i = 0, c = b; ...; i++, c += K)` with `c` declared before `i`, and the other `|`
  operand read through a pointer local, `p = base->arr[i]; p->m = X | ((p->m & K) | (c & 0xff));` (func_ov003_021c85a0).

### 1.6 Switches, Branches and Selects

- A switch right at the density where the compiler changes between a jump table and a compare tree depends on the
  machine running the compiler: use the wibo that `tools/build_wibo.sh` builds (not release 1.2.0).
- Gaps in a jump table that lead to a label inside the switch are case labels the source is missing, not `default`.
- `x == 0 || x == 2 || x == 3` folds into a range check; `cmp #0; cmpne #2; cmpne #3` came from `switch (x) { case
  0: case 2: case 3: }`. Write `||` chains in the original's test order.
- `switch` instead of an if chain stops predication of the arms. A two-case `switch` gives a `beq` chain with the
  case-0 block out of line, where if/else-if predicates. Blocks come out in the order the cases are written, so a
  `cmp #2; beq; cmp #4; bne; body 4; body 2` chain is a `switch` with case 4 first (func_020401ac).
- Explicit nested ifs setting a BOOL keep a branch that a ternary or selected `u8` would predicate.
- `else { return x; }` keeps a branch where `if (!c) return x;` predicates. Conditional early returns
  (`bxeq/bxcs`): `if (x != 0) { x = 0; return TRUE; } return FALSE;`. Inverted forms predicate.
- Guards branching to one shared `mov r0,#0` exit are nested ifs with a single `return 0` at the end; early returns
  become predicated `movne/popne`. Two early `return i;` -> `goto found;` to one `found: return i;` after
  `return 0;` gave the original branch shape.
- In an if/else whose predicated arm branches over the other, the predicated arm is the source's else.
- Identical trailing statements in both arms are merged into the join, as are identical setter calls after the
  join; duplicated call tails are not. Write statements in both arms when the original keeps them there.
- 0/1 selects put the 1 first: `x ? 1 : 0`, `x != 0`, `!!x`, if/else assigning 0/1 to a local and inline
  `return x != 0` all give `movCC #1; movNCC #0`. `#0` first comes from a select of two enum constants
  (`a->m = c == 0 ? KIND_0 : KIND_1;`, func_02087c9c), an if/else storing straight to memory in both arms, a
  variable with other definitions, or constants other than {0,1}. `b = 0; if (x) b = 1;` gives `mov #0; movne #1`.
- `x == 0 ? 3 : 2` vs `x ? 2 : 3` swaps `moveq/movne`. `mode == 0 ? a : b` predicates the loads where
  `mode != 0 ? b : a` branches. `f = c != 0 ? tbl[i] : g;` branches; `if (c == 0) f = g; else f = tbl[i];`
  predicates both arms.
- Bool stores: `if (x) { f = 1; } else { f = 0; }` stores before the return-value move; `f = x != 0;`, `?:` and
  `!!` don't. Bool-returning inline getters: `bool r = false; if (cond) r = true; return r;` matches where
  `return cond;` doesn't.
- Predicated `movCC/strCC` right after a `bCC` on the same condition is a dead re-test inside the branch
  (`if (x <= K) { if (x > K) x = 0; }`). Keep it.
- Two loads before two compares: an enum-typed copy of a field read is a real load at its declaration, so
  `Mode a = (Mode) x.mMode; Mode b = ...;` keeps both loads ahead of the tests.
- An enum-typed result stops the return being folded (`return result` kept where a `u32` folded to `mov r0,#0`).
- A 0/1 flag the ROM sets to 0 before the tests and copies the 1 into as the last instruction (ours has a
  `movs rN, #0` block after the tests): `if (A && B) b = 1;`, nested ifs and `b = A && B;` all give the
  shared-false-block form, so write the last term as a comparison assigned inside the if: `b = 0; if (p != 0) { b =
  (p->mUnk_70 & 1) != 0; }` (Thumb: func_ov000_021a7824). Many functions have the plain `b = 0; if (A && B) b = 1;`
  shape and need this: look at the diff first.
- An early test branching to the same `mov rX, #K` block that a later test falls into (ours predicates the early
  arm): `if (x == -1 || helper(x) == 0) { r = 1; }` with `helper` the `f = 0; if (...) f = 1; return f;` flag
  (func_02040bc0).
- A conditional branch to a shared `pop` exit where ours has predicated epilogue copies (`popne {r4, lr}`), 4 to 8
  bytes longer: the unit is compiled for size. `#pragma optimize_for_size on` after the includes matched every
  function of code_02030708.c and code_0203606c.c. Apply it only when all functions of the unit match with it.

- A jump-table bound one higher than ours: the switch has an empty trailing `case N:`. An unused `cmp rN, #K` just
  before the epilogue is an empty `case K: break;` (func_0200a1bc, func_0200a7b0).
- Jump-table entries that go straight to the function's end are `break`s out of the switch (and a `break` in the
  outer case); `return;` gives a nearer shared exit instead (func_0200a7b0).
- `A && f()` whose false path jumps to the compare of f's result is a value: `A ? f() : 0` (func_0206c5e4).
- Only the order inside one arm of an if/else differs: try the arms the other way round with the test negated
  (func_0209cf34; seen once).
- `cmp #K; beq` to a call placed at the end: `if (x != K) { ... } else { call(); }` (func_02106580).
- The else arm placed first, with the last test branching to the then arm: `if (!A || !B || C != D) { else-body } else {
  then-body }` (func_02007698).
- `movcc #0` then `movcs #1` where `c = (b < K) ? 0 : 1` gives `movcs` first: write `if (b < K) { c = 0; } else { c = 1;
  }` (func_0203a0dc).
- Switch case bodies placed in a different order: write the case bodies in the order of the original's branch targets
  (func_0204dd24).
- A compare tree where the original has a jump table, or a table over a different range: add empty case labels. The
  compiler groups sorted case values into a table while (count / value span) is at least 0.4; pick the labels to hit
  that (func_ov003_021c25e0, func_0200b43c).
- Signed `bgt`/`blt` on a switch where ours has `bhi`/`bcc`: the switch operand is signed, an `s32` parameter or an
  `(s32)` cast (func_0200b43c).
- An inner switch value loaded before its guard, with case results set in the same register and stored once after the
  switch: one local, `t = b->m; if (..) { switch (t) { .. t = 9; .. } v = t; }` (func_0200b43c).
- Range compare signed (`blt`/`ble`) where the original is unsigned (`bcc`/`bls`): an unsigned mask constant, `v &
  0xff00u` (func_ov000_021a0cac).
- A sign flag and its source swapped: write abs as `a = a > 0 ? a : -a;`, not `if (a <= 0) a = -a;` (func_01ffaf18).
- `streq` of the zero arm before the other arm's store: negate the `||` chain to `&&` and swap the arms (func_01ffaf18).
- An early `popeq`/`bxeq` return of 0 where ours if-converts the tail: `if (ok != 0) { return expr; } return 0;`
  (func_02015fa0).
- Two failure paths sharing one `flag = 0` block: `goto done` after the success test with a single `flag = 0` below, and
  carry the 0/1 flag in a variable whose first use is elsewhere (func_020162d4).
- A predicated arm that forms its address in `ip` alone where ours goes through r4: write the multi-statement arm first,
  with the `!= 0` test (func_02050080).
- A one-argument call whose other copy of the declaration is unprototyped: pass the missing `0` argument
  (GpiOpenSearchSocket).

### 1.7 Constants and Literal Pools

- `mvn rX,#0` stored to a byte: the field is signed (`s8` = -1).
- A negative constant stored with `strh` built as `mov r0,#0xe000; sub r1,r0,#0x12000` can't come from a `u16`
  field: the lvalue was signed 16-bit (a cast placeholder when the field's type can't change).
- A register-form `and` with a pool-loaded mask comes from division plus `u16` truncation
  (`u16 v = (x & 0x1fff) / 0x200;`); a shift pair would fold.
- Two literal-pool entries for one address: model it with a second extern name for the same address; it usually
  means the statics' layout isn't understood yet.
- Constant offsets into an object in a file's shared data section are addressed from the section base, so two
  tables can share one pool word; taking the address as a value or a variable index keeps the symbol (1.11).
- A cast on the address can swap address and value registers in a read-modify-write of a global. A pointer local
  initialised with a cast (`T *p = (T *) &g;`) changes addressing (1.1). Try both.
- A word the original loads from the pool as `.word SYMBOL` where ours has a plain number: write the symbol, cast
  to the field's type: `(int) func_01ff8000` (func_ov000_021a6908).
- A small value (0, 1, 2, 3, 0x2000000) loaded from a pool word with no relocation is a symbol the compiler can't
  fold: an absolute address defined by the linker. Bytes match with such a symbol in place (func_0205dee0,
  func_020365f0). The link side isn't built and the names are guesses: leave a placeholder.

### 1.8 Types, Casts, Enums, Volatile and Const

- `-char signed`: `ldrsb` on a string walk means plain `char`.
- Return types show in callers: an enum return gives `movlo #0; movhs #1` at the last compare where BOOL gives the
  reverse; a BOOL stored into a `u8` field gives `ands rX, r0, #0xff` before the store; a `u8` return removes the
  caller's `and #0xff`. In a function returning `u8`, `u8 r = c >= x; return r;` has no final `and`; a BOOL local
  does.
- Declare return values. A callee declared void that really returns a value changes callers' registers and
  scheduling. A tail-call function whose callers all ignore the result may need to be void to keep another caller
  matching (mark it as a placeholder).
- If callers load a register (e.g. a pointer into r0) that the callee never reads, the callee still takes that
  parameter; removing it makes callers 8 bytes short.
- Parameter width shows in the caller: passing `u8` to `u32` adds a conversion that shifts registers. `lsl #16; asr
  #16` on an argument means the caller's variable was `s16`. A caller passing an `ldrsb` value with no `and` means
  the parameter is wider than `u8`. `(u8)` casts at call sites often stand in for the callee's real types.
- Implicit narrowing at a short parameter is not shared between calls; an explicit `(s16)` cast passed to `s32` is.
  Get the callee types right and drop the casts. `(s16)(int)(y - 8)` stops sharing (placeholder form).
- A `u16`/`s16` stack parameter is loaded at the top of the entry block; a 32-bit one at its first use. A `u8` stack
  parameter is loaded first in the prologue; BOOL puts it later.
- A stack parameter the callee reads as a narrow load while all callers store a full word: declaring it narrow
  breaks callers (they add an `and`). If the callee reads `*(s16*)&param` it really is `s16`. Otherwise
  `*(u8*)&param` is a placeholder.
- A signed compare (`bgt`) on an `ldrh` value means `int v = field; if (v > K)`; comparing the field gives `bhi`.
  Unsigned bitfield compares are unsigned (`bcc`); `(s32) bf >= 2` gives `blt`.
- An index the original masks with `and #0xff` at each use was not a `u8` local: write the expression at each use.
- `x *= 10; x &= 0xffff;` keeps a call result and its narrowed product in one register; `x = (u16)(x*10)` splits
  them. Narrow read-modify-write toggles: `f++; f &= 1;` on a `u8` field as two statements.
- A byte array that is really an array of small structs: struct indexing stops address sharing across a call. A
  two-byte `{x,y}` struct instead of `u8[2]` keeps a table out of its own section (1.11).
- Separate globals, not a struct: count/head/free/tail bytes matched only as five globals.
- `-enum int` vs `-enum min` shifts struct field offsets after enum members (`compiler.md`).
- Enum-typed copies and locals are a general tool: not folded, not substituted into compares, a real load at the
  declaration, and they change which of an index and its base gets its register first.
- NitroSDK `u32` is `unsigned long`; a project's own `u32` may be `unsigned int`. These differ to the compiler.
- `_ffltu` where the ROM calls `_fflt`: the converted value is signed (`s32 x` instead of `u32 x`, or a `u16` field
  promoted to `int`). The probe masks the call name, so check relocations (func_020a269c).
- A 64-bit call result added to a 32-bit value widens the sum: `s = (a << 16) + func_0200f5ac();` builds a 64-bit add
  too early. Narrow the call: `(a << 16) + (u32) func_0200f5ac()` (InitWiFiVSCourseSelect). The opposite shows as `adds` with
  the high word dropped: the sum is of `u64` locals and the result truncated (func_020401ac).
- Where the narrowing sits shows what was narrowed. `lsl #1` then `lsl #16; lsr #16` (ROM) against one `lsl #17;
  lsr #16`: `v1 = f(...) * 2; g(..., (u16) v1);` (func_02009828). `lsl #4; lsr #16` for a `u16` argument is how
  `x >> 12` is narrowed: pass `p->mUnk_0a4 >> 12`, not `(u32) x << 4 >> 16` (func_02098b68).
- No `lsl/lsr` narrowing after an add and a signed `movge` against a `u16` compare in the ROM: the value is `s32`
  (func_020919e8).
- A by-value struct parameter read through a `volatile T *p = &b;` local keeps an `add r0, sp, #4` in a register;
  the ROM re-reads from the frame. Make the parameter itself volatile (`volatile Unk b`; the header prototype stays
  without it), func_020ab660.
- A nibble store that loads the byte, clears it with `bic`, then ors `(v & 0xf) << 4` is a bit-field member
  (func_02007698).
- A halfword stored through `lsl 8; asr 16; lsl 16; lsr 16` with the x/y chains in crossed registers: `x = m >> 4; ...`
  and `(u16) (s16) (x >> 8)` for the store (func_02011624).
- A `-0x8000` compare constant that takes r0 before the final value: write `(s16) (x >> 7)` instead of `(s32) (x << 9)
  >> 16` (func_0214e464).
- A `u16` argument converted right after its value's `if`, before the next test: assign it to a `u16` local at that
  point and pass the local (Thumb; func_ov000_021a4bc4).
- `lsl/lsr #16` before a call whose callee passes that register on untouched: widen the parameter to `u32` and write
  `(u16)` at the callers that need the narrowing (func_ov000_0219dfe4).
- `(u8) i` converted again at a second identical call, where ours reuses it in a callee-saved register: `(s32) (u8) i`
  on exactly one of the two calls (hand-picked; the only spelling that matched; func_0202b100).
- Stack `u16` arguments reloaded after a call while ours keeps one temporary across it: type the register parameters
  `u16` too; `u32` compares share the conversion across the call (func_0214e464).
- A stack parameter spilled while the original keeps it callee-saved, with callees taking `u32`: make the callee's
  parameter `s32`, so no conversion temporary is made and `f -= n2` writes `f` (func_021243ac).
- A value passed where every other caller passes `&global`: pass the address (a real bug, not only codegen;
  func_02078158).
- A callback kept in a callee-saved register although nothing is live across the call: the call passes one more
  argument, already in r3; add it to the prototype (func_020d3e34).

### 1.9 Calls, Parameters and Frames

- Spilled parameters take the lowest stack slots in parameter order; spilled named locals go above them in
  declaration order (AdvanceSelectKart needed `e` before `x` before `q`); a spilled compiler temporary (e.g. a merged
  repeated global read) sits just above the parameters. A local that won't take its slot may need to be a repeated
  expression or its own variable (1.1).
- Stack-parameter copies are emitted at entry in parameter order (`-proc generic` shows it). A local with two
  definitions sharing the parameter's home slot pulls its copy early; narrow parameter widths put the copy at the
  top.
- `stm` where the original has two `str`s for stack arguments: declare the flag without an initialiser and assign
  only in the arm that needs it, passing literals in the other.
- A parameter moved into r1-r3 at entry and kept until a later call is usually that call's argument in that
  position (a missing `%d` argument looked like a register problem).
- By-value struct parameters: modify fields in place (`spec.prec -= 2`), don't copy to locals (it changes spill
  slots).
- `T a[2] = {0,0};` / `VecFx32 v = {0,0,0};` store through an `add rN, sp, #off` base; separate element stores,
  field stores and setter calls use sp offsets.
- A local array filled from a one-use rodata table is an aggregate initialiser (`u8 buf[3] = {0,1,4};`): it emits
  an anonymous rodata object (often first in the unit's `.rodata`). Element-wise copy doesn't match.
- Struct copies: where the original loads every component before storing (often `ldm/stm`), fill a local temp (z,
  y, x) and assign `*dst = t;`. Three `u16`s assigned as one object (`*(Vec3u16 *)dst = *(Vec3u16 *)p->mRot;`) load
  all three first. A struct copy initialised at its declaration stays `ldm/stm`; assigned later it is split into
  fields. Inline setters compute all values before storing. A scalar argument of an inline setter is loaded before
  the struct copy in its body.
- Float compared with an int: keep the float expression in a helper returning float and cast at the compare
  (`(s32) ToFloat(n) < x`).
- A call result that must be the left operand of a compare or add (`cmp r0, rX`, `add rD, r0, rX` where ours has
  the call on the right): the compiler puts the call on the right whatever the written order, and a local holding
  the call result keeps the written order. Write `r = f(b, c); if (r != d)` or `c = f(p->x); g(..., c + x, ...)`
  (func_ov003_021b8160). Inside an `&&` chain use a comma expression `(c = func_0203c8dc(a->mUnk_74), c == i)`;
  `(c = f()) == i` is still swapped (func_02066fe0).
- The same holds for a heavier left operand: `mUnk_20 == v1` with `mUnk_20` an array element stays `cmp v1,
  mUnk_20`; the element through a pointer local (`q = &d->mUnk_44[v2]; if (q->mUnk_20 == v1)`) stays on the left
  (func_020401ac). In a product, `(s64) X * b` becomes `b * X`; give X a local (`c = (s32) ((s64) *a * data >> 12);`,
  func_01ffb930).
- A call that must come before a comparison: `p->mUnk_14 = d->mUnk_100 == 1;` after `func_02029930()`; `? 1 : 0` or
  a temp is evaluated before the call (AdvanceSelectKart).
- Memory locals (those whose address is used) go in the frame in size groups, smallest first: 1 byte, 2 bytes, 3 to
  8 bytes, 9 to 64 bytes, over 64; within a group in declaration order. A struct the decompiler made from adjacent
  stack bytes that sits wrong against a smaller local is separate locals (`s8 d; s16 g; s16 h; u8 k[8];`,
  func_ov003_021b8498). Two locals in the 9 to 64 group: declaration order decides (`Vec3 v;` before `Unk0210b7a8
  s;`, func_0209d84c).
- A local declared inside a loop body gets a higher slot than any function-scope local: declare it at function
  scope (func_ov003_021ce5b8).
- `v = K; f(cmd, &v, 1);` eight times with a 4-byte frame slot each, and `Vec3` argument buffers with a slot each:
  static inline helpers `func_X_inline(cmd, val) { f(cmd, &val, 1); }` (func_02063cc4, frame 0xa4 -> 0xbc at once).

- A local array zeroed through `add rX, sp, #N` and two stores had `= {0}` at its declaration (func_0206e874).
- A call result stored to a local's stack slot where the original keeps it in r0: that local has its address taken
  elsewhere; use a separate local (GpiOpenSockets).
- Thumb: an 8-byte local zeroed twice mid-function through `add rX, sp, #N; str [rX]; str [rX, #4]` on one slot:
  `__builtin__clear(&s, sizeof(s));`, like `= {0}` without the extra slot (hand-picked; the only spelling that matched;
  GpiOpenSockets).
- A small local array kept in memory and reloaded after stores, where ours is in registers: one store through `((Vec3 *)
  d)->x` at the first assignment. `*(d + 0)`, `*&d[0]`, unions, wrapped arrays and inline pointer helpers did not work
  (func_02101964).
- Thumb: `add rX, sp` before `movs #0` and four `strh`, then the address formed again for the next stores: the array as
  its own local with an initializer, `u16 v[4] = {0};`; a `{0}` on the whole struct gives word stores
  (func_ov003_021c0d2c).
- A struct cleared through `add rN, sp, #off` with the address reused for the next call: `u32 *p = (u32 *) &g; p[0] = 0;
  p[1] = 0;` (CreateSocket).
- A zero vector built through `add rN, sp` then `ldmia` from the same address, using the 0 from another register: `{
  Vec3 z = {0, 0, 0}; m = z; }` blocks (func_020d2c2c, like func_020d41e0).
- Spill slots in the wrong order: the declaration order of the spilled locals sets it (func_021243ac).
- A spill slot just after the named locals and before a temporary, holding a scaled table index: it is a named local,
  `u32 e = tbl[i] << 6;`, added to `(u32) base` at each use; `(u8 *)` adds let the compiler fold `e` away
  (func_ov000_02183858).
- Out-parameter locals of an inline getter kept in stack words with their dead stores, ours in registers: cast the
  addresses at every call, `f(p, (u32 *) &x, (u32 *) &y)` (func_ov003_021c85a0).
- A frame about 0x200 too big with a separate scratch buffer: make the buffer an array member of a local struct
  (`h.mUnk_008`; func_ov000_0219fbec).
- Thumb: values read before a call and kept across it: read them into locals before the call (func_0202d210).
- Thumb: a `movs` copy of `b - 1` right after a call, used for an index and then times `0x16`: `v = b - 1; ... a[v] ...;
  v *= 0x16;` (func_02007698).

### 1.10 Inlines and Macros

- Use a macro where an inline won't do: a bit-test macro lets the compiler reuse the loaded byte for a following
  set, which inline helpers don't.
- Write SDK inlines and macros as inline functions or macros under their API names (FX_Mul, FX_F32_TO_FX32,
  MATH_Rand32, FS_GetLength, OS_SetIrqCheckFlag, G2S_SetBG1Priority): their multiple evaluation and casts show in
  codegen.
- Inlined SDK setters appear as a 36-byte copy followed by calls (NNS_G3dGlbSetBaseRot/Trans/Scale; MI_Copy36B).
- `__clear(ptr, size)` is a CodeWarrior intrinsic: `mov r0,#0; mov r1,r0; mov r2,r0; mov r3,r0` and an
  `stm lr!,{r0-r3}` loop. `__memcpy(dst, src, n)` is one too: inline `ldrb/strb` pairs (source in r3). `memset`,
  `memcpy` and struct copies compile differently (a call, or the stack).
- With `-inline on,noauto`, same-file calls stay `bl`.
- Repeated blocks that each have their own stack array (`q0 ... q5`) were static inline helpers (`func_X_inline`,
  `func_X_inline2`). An inline's arguments are evaluated right to left (the ROM loads `y` before `x`) and an
  argument expression is substituted into each use. Constant arguments fold tests and loops away, so one helper
  serves sites with different constants. A helper called from inside another helper puts its locals after the outer
  level's. Number the helpers in order of use (func_020c8dbc, func_020401ac).
- A value the helper must see once: `if (data->mUnk_170[i] != 0) { helper(p, i, data->mUnk_170[i]); }` with the
  parameter in the helper and no repeated test inside (func_020c8dbc). A distance helper with `(const Vec3 *a, const
  Vec3 *b)` parameters keeps the reload of the fields for the next call, and a fill helper `(Vec3 *, x, y, z)` loads
  before the first random call and spills (func_020919e8).
- A pointer passed through a helper with `Vec3 *dst, const Vec3 *src` loads `a->mUnk_508` once across the three
  stores (func_02063cc4).

- Thumb: a byte copy that forms the destination address before the source, with the value always in r0, is
  `__memcpy(dst, src, n)` with a constant n (func_ov000_021923b4). A struct store whose nearby address is loaded early
  can be `__memcpy(dst, src, sizeof(T))`; use it only at the store that needs it (func_020a29cc).
- The same block written out twice can split a value in two: use one static inline helper taking the value
  (func_020b5ae8).
- An inline's local whose stack slot comes after the slots of later expansions was a shared expression: read the
  expression twice instead of keeping it in an inline local (func_02126a00).
- `add rD, inv, mod` where `inv + k % 4` gives the operands swapped: pass the invariant as a parameter of a static
  inline that writes `r + k % 4` (func_020b41e8).
- `adds r0, r0, #0` / `#4` kept before a byte load after a table-index call: a static inline returning
  `&tbl[idx()].mUnk_00[j]`, used as `helper(j)->member` (func_0202a360; may also fit func_020c0dd8 and func_020c13e8).
- Inline arguments moved into place in the wrong order (they are passed right to left) while the registers are right:
  the inline assigns its parameters to its own locals in the original's order, `i = size; p = a; q = b;`, declared
  `p, q, t, i` (func_021382a8).
- An inline helper's loop counter taking its register before a named pointer (inline locals come after every named
  local): write the loop out in the caller with the counter and result declared before the pointer, and a `goto` for the
  early return (the only spelling that matched; func_020a1790).

### 1.11 Data Layout, Sections and Link Order

Placement:
- A constant member offset into an object the file defines is addressed from the section base plus an anchor
  offset; taking the address or a variable index uses the object's own symbol. A pool word that names no object
  start is an anchor: find the object it belongs to before declaring it.
- Shared `.bss` order: ascending size; on a tie, definition order except that the first-defined object goes last.
  A smaller object after a bigger one starts a new file. Objects of 64 bytes or more get their own sections,
  smallest first.

Ordering objects within a file:
- `.bss`, `.data` and `.rodata` objects are ordered as one list, smallest first. Ties depend on the whole list.
- File-level statics enter where defined, after the string literals of their initialiser. Strings used inside
  functions don't join. Function-local static tables and a local array initialiser's rodata object enter at their
  function's position.
- Header include order and static definition order (including statics placed between includes) decide all three
  sections. `tools/layout_search.py <unit>` searches static order and where statics sit among the headers; `tools/fix_layout.py` tries header orders; `tools/fix_static_order.py` applies a static order;
  `tools/data_order.py` works out a declaration order for one section. `.clang-format` must keep include order
  (`SortIncludes: Never`).
- Define every table in the range: `.rodata` tables take part in the same ordering as `.data` ones.
- Merging tables into one struct changes what the ordering can reach (a 60-byte struct of position+order tables; a
  struct of two tables to put a 10-byte table before an 8-byte one). Byte tables indexed by a variable stay
  separate.
- Identical string literals in a table initialiser: their order follows from the whole list (`-str noreuse` keeps
  them as separate copies).

Objects that get their own section (addressed through their own symbol):
- Objects the file never references (inline accessors in included headers count as references); byte-aligned const
  tables whose size is a multiple of 4; function-local mutable statics; every string literal; arrays of
  `char`/`u8`/`s8` (1-D always; 2-D char arrays and same-size structs stay shared); `extern` objects; weak objects
  (statics of inline functions); objects under `#pragma section npdata begin/end`. Nothing else (size,
  alignment, order, static vs global, opt level) changes this.
- `const` always wins: a const object goes to `.rodata`. Wrong const-ness shows as a section landing in the other
  kind.
- To give a table its own pool word or `.data` section, make it a function-local static of an inline accessor
  (`inline Rec *Items() { static Rec s[4] = {...}; return s; }`). This also places writable tables after a file's
  strings.
- Big globals the code must address by their own symbol: `#pragma section npdata begin/end`; other units naming
  fields inside them by address get linker-script aliases (base + offset).
- A zero-initialised table the original has in `.data`: `#pragma explicit_zero_data on` around it (`= {0}` alone
  goes to `.bss`).
- A const table read only with constant indices is folded into immediates yet is still referenced and joins the
  shared section: look for a gap's values among a function's immediates before calling it dead data.
- Byte-identical code addressing the wrong `.bss` offset means wrong static definition order.

Unit boundaries:
- A smaller object between two larger ones means a boundary. Another unit's data on both sides means a shared file.
  An object in a neighbour's block means the code using it belongs to that file.
- When no include order works, look for a boundary problem first.

Link order and linking:
- Function order is definition order. A function defined before its caller is emitted first: use a prototype and
  define after.
- `-dead` strips unreferenced data once a unit links from source, though the original link kept it: list
  such objects in `config/<ver>/arm9/force_active.txt` (the `-force_active` flag segfaults under wibo).
  Unreferenced statics are dropped by the compiler; unreferenced globals still take part in the ordering.
- Linker-script aliases (`alias` lines in `config/<ver>/arm9/lcf_edits.txt`, see
  `tools/lcf_force_active.py`) must go after the sections; before them they silently resolve to 0.
- A function placed apart from its unit (e.g. `main` right after start-up code): a stub unit holds its slot and a
  linker-script edit puts `OBJECT(main, Game.o)` there.
- dsd reads any address-looking word as a pointer: a data blob (font bitmap) word recorded as a relocation
  into an overlay becomes 0 when the target is renamed away. Delete such lines from relocs; check relocations into
  a newly linked range when the ROM differs by one word.
- The `.text/.rodata` boundary may be set too late (70 KB of tables counted as code). Fixing it lets units own
  their tables and corrects progress numbers.
- `dsd delink` refuses a relocation from one unit to a local symbol of another: never make a symbol local
  while an outside relocation targets it.

### 1.12 Soft Float and 64-bit Math

- `float` arithmetic calls runtime helpers (`_fadd _fsub _fmul _fdiv _fflt _ffltu _ffix _ffixu`, compares `_fgeq
  _fgr _fleq _fls _feq _fneq`). A source compare must use the same operator as the original (`a < b` -> `_fls`;
  `!(a >= b)` -> `_fgeq`).
- `s->x = 8;` on a float folds to a constant; `u32 left = 8; s->x = left;` keeps `mov r0,#8; bl _ffltu`.
- `/` and `%` on ints call a combined division helper (`_s32_div_f`: quotient r0, remainder r1). Write the
  operator, never call the helper by name. The divisor in r1 often already holds a value used elsewhere (keep it in
  a local). Compound-assigned locals (`s32 q = a; q /= b;`) fix the order of division calls. `_s32_div_f` vs
  `_u32_div_f` follows the signedness of the operand (`(u32) b`, func_ov000_021882f8).
- 64-bit fixed point (NitroSDK-style matrix concat): a product of two locals gives `umull+mla` with sign words on
  the stack; a local times a fresh load gives `smull/smlal`. `(fx32)((e64 >> 12) + t)` gives `adds`. Matrix concat
  reuses the last column loaded in a row for the next row's first element (load columns into locals, alternate
  column order row by row).
- The 64-bit random step: `x * a + c` on unsigned words calls `_ull_mul`; `(s64) x[1] * (s64) x[0] + x[2]` calls
  `_ll_mul`, the name the delinked original has (func_ov000_021acef8). The ROM has one routine for both;
  func_020de6a8 matches only with the unsigned product.
- Random scaling `((x >> 32) * m) >> 32`: the product's signedness decides which register the zero high word and
  the loaded word get. When they swap, flip it: unsigned in func_020983c4, signed in func_ov001_0218c0a4. A `u16 n`
  converted to `s64` is sign-extended (`asrs rX, n, #31`), `(u32) n` zero-extended (func_020427d4).
- The random helper joins one `u32` and narrows once: `u32 t; if (n == 0) { t = 0; } else { step; if (n == 0) { t =
  x >> 32; } else { t = ((s64) (x >> 32) * (u32) n) >> 32; } } return t;` in a helper returning `u16`
  (func_020427d4). Helpers called only with constant ranges fold the tests away.
- `x >> 48` of the state against a `mov #0; lsr; lsl #16; orr` sequence in the ROM: write
  `((x >> 32) * 0x10000) >> 32` (func_0209219c). `x >> 32 >> 29` as `lsl #3; orr ... lsr #29` is
  `((s64) (x >> 32) * 8) >> 32` (func_020401ac).
- Name runtime helpers (`_fmul`, `_ll_ufrom_d`) in `symbols.txt`, or the callee check skips every caller. The
  soft-float and division runtime itself is hand-written assembly (1.13).
- `smull` with the sum as the second operand, where `(s64) t * (a + b)` gives `t` second: put the sum in a local and
  cast both, `s = a + b; (s64) s * (s64) t`; keep `(s64) t` explicit if it is shared with another product
  (func_02082750).
- A 64-bit sum of products whose right term comes first in the original: write that term on the left (func_020ff6d8).
  For `smull`/`smlal` operands in a sum of products, write the products in the original's order: `(s64) w[0] * d[0] +
  (s64) w[2] * d[2]` (func_02101964).
- A random draw computed after the call that follows it, with the 64-bit shift halves in the other order: `(u64) (u32)
  (x >> 32) * 4 >> 32`, no `u64` local (func_0203b6ac).
- A zero high word set before the add in a `u64` store of a sum with a call: `(u32) (sum + call())` (Thumb;
  func_0203b6ac).
- The sign word of a constant product computed early and shared with an earlier product of the same value: put the
  `(s64)` cast on the constant, `x * (s64) 0x19a` (func_01ffaf18).
- A first `smull` taking the second term of the source sum: write the first two terms swapped, `x * x + y * y + z * z`
  for an `smull` of `y * y` first (func_0209297c).
- Projected components kept in registers and stored to the vector after the sum of squares, ours storing then reloading
  a pointer field: compute into locals, sum from the locals, then `u.x = x; u.z = z;` (func_0209297c).
- `smull` with a call result as the second operand where ours has the scalar: put the call result in a local first, `f =
  g(); (s64) f * s`; a call moves right whatever the source order (func_020980ec).
- A 64-bit multiply's operand taking its register after the result registers: accumulate into the already-loaded local
  and put the difference in its own statement, `a += x; a = a + y - z; t += (s32) (((s64) a * K) >> 12);`
  (func_020fc654).

### 1.13 Asm Bodies

- Hand-written routines (start-up, soft-float and division, SHA-1 block, cache/protection/irq/context, ITCM
  copy/fill, divider save/restore, an LZ streaming step, codec DSP kernels) are written as commented `asm` function
  bodies in C files, clean room.
- Each compiled function gets its own 4-byte-aligned section, so Thumb BIOS thunks at halfword addresses can't come
  from C: use an assembler file (mwasmarm), which can place global labels anywhere in one section.
- Labels inside one asm function aren't visible to another: a branch into the middle of a neighbouring routine is a
  raw instruction word (`dcd`) with a comment. objdiff then reads it as data and scores below 100%.
- mwasmarm reads `.incbin` input as text (a lone 0x0a becomes 0x0d): expand `.incbin` lines into `.byte`
  lines in a build-dir copy.
- Opaque filler bytes (secure area) are read from the user's ROM at build time, never committed.

### 1.14 objdiff and Checker Quirks (Identical Code Below 100%)

- A `bl` to the function that starts right where the caller ends stays a mismatch (99.7x%) because of the
  relocation addend. No source change helps; linking is the proof (func_01ffc6c0, func_0200c2e0).
- A `bl` to another function of the same unit counts as a mismatch while that callee doesn't match.
- Calls between functions of one file show as mismatches when the file defines its functions out of address order.
  Reordering fixes the score.
- Data inside asm bodies (no `$d` mapping symbol) and a data block whose delinked target has no mapping symbol give
  under 100% with identical bytes. A hand-written `.s` unit sat at 99.84% because two trailing constant words
  reached only from routines entered by a branch were read as instructions. Declaring those routines as functions
  (in `symbols.txt` and the `.s`) fixed it (func_02131694).
- Literal-pool relocation names in not-yet-linked units differ.
- `tools/objdiff_place.py` gives each objdiff scratch its own compiler and flags.
- `dsd check symbols` keeps a few unfixable mismatches (labels inside asm bodies that emit no symbol). Document them.
- Probes mask call targets and string addresses, so a wrong file name or wrong callee "matches". They also miss a
  wrong runtime helper (`_ull_mul` for `_ll_mul`, `_ffltu` for `_fflt`): compare relocations after any 64-bit or
  float change. A relocation name that differs doesn't cost points; a plain number on our side where the original
  has a relocation does (1.7).
- A Thumb `bl` from a function into its own body (a far branch to a shared exit block) gets a relocation from
  `dsd init`, but the compiler resolves it without one (99.99%). Remove such relocations from `relocs.txt`.

### 1.15 Thumb Code

- `#pragma thumb off` ... `#pragma thumb on` around a function in a `-thumb` file gives exactly the code of
  compiling it in an ARM file, so an ARM function can sit in a Thumb file.
- A Thumb `bl` is two halfwords and can straddle a word boundary: mask relocations per byte.
- Thumb functions end on a halfword, but a unit's range ends after the padding on a 4-byte boundary (a halfword end
  shifts everything after the unit).
- Thumb has no `umull`/`smull`; 64-bit products call a runtime helper. It has no conditional execution except
  branches: where ARM code would predicate an arm, Thumb code branches.
- Thumb code is not scheduled: instruction order follows statement order after single-use locals move into their
  use. So `e = load; i = 0; if (e != -1)` puts the load after `i = 0`; write the plain form
  `if (p->m != -1) return; for (i = 0; ...)` (func_ov003_021bf0d8). A cast of a loop-invariant value in a loop test
  (`(u32) j < q`) is computed after `j = 0`: drop it (`q = n - b - a; for (; j < q; j++)`, func_02085ad8). A call
  result or a value used in two blocks stays where written.
- A Thumb jump table ending in `add pc, r0` where ours ends `add r0, pc; bx r0` (2 bytes longer) is a compiler
  difference, not source: the 1.2 base always emits the `bx` form. Four functions in ov000 use the other form
  (func_ov000_021a9d68, 021ab09c, 021ad898, 021aea34).
- Thumb `ldrsb` and `ldrsh` have only the register-offset form, so `*(p + 11 - i)` differs from `p[11 - i]`
  (func_021528bc).
- A byte loaded, moved to a second register for `muls` and used again after, with the two registers swapped: read the
  field inside the index expression and write the update as `x--` or `x -= 1`, not a local or `x = x - 1`
  (func_ov003_021c73cc).
- Two byte stores whose address is shared with the halfword read that follows: `__memcpy(t.m, v, 2)`
  (func_ov000_0218b010).

## Placeholders

Forms that reproduce the original's bytes but are probably not its source. Use one only when the bytes match and the
code behaves the same, mark it in place (`// placeholder: <what it stands in for>`), and replace it when a real form
matches. Kinds that have worked:
- Layout: a dummy static of the right size taking part in the data ordering; named copies of identical initialisers
  to set their order; a 2-D shape that keeps a byte table in the shared `.rodata`; a stub unit that holds the slot
  of a function placed apart from its unit.
- Index and register: a pointer local for a hardware register read; a second extern name for part of a table; unread
  zero initialisers; volatile reads that keep two reloads apart; an enum-typed index; a narrow read of a stack
  parameter (`*(u8 *)&param`) when callers store a full word; a repeated test `a || a`; `(s16)(int)(y - 8)`; a
  two-arm value whose arms read the same thing (`idx = c ? list->x : g.list->x;`).
- Expressions: `- -v`, a cast through a byte pointer, a zero base, a constant stored through `*(s16 *)&field`. The
  type or variable structure that does the same is the real form.
- Judgement calls: a tail-call function declared `void` because every caller ignores the result and `void` keeps
  another caller matching.

These looked like they needed placeholders but were solved by rules: two loads before two compares (enum-typed
copies), scheduling cycles and enum-zero workarounds (a BOOL-returning callee declared void), literal-order problems
(wrong strings behind masked addresses).

## objdiff Below 100% With Identical Code

See 1.14 for the known causes. The ROM check is the proof; record each such function and its cause here.
