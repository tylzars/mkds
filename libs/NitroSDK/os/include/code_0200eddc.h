#pragma once

#include "types.h"

typedef enum {
    OS_ARENA_MAIN = 0,
    OS_ARENA_MAIN_SUBPRIV = 1,
    OS_ARENA_MAINEX = 2,
    OS_ARENA_ITCM = 3,
    OS_ARENA_DTCM = 4,
    OS_ARENA_SHARED = 5,
    OS_ARENA_WRAM_MAIN = 6,
    OS_ARENA_WRAM_SUB = 7,
    OS_ARENA_WRAM_SUBPRIV = 8,
    OS_ARENA_MAX = 9
} OSArenaId;

// Lo and Hi bound of every arena, kept at 0x027ffda0.
typedef struct {
    void *lo[OS_ARENA_MAX];
    void *hi[OS_ARENA_MAX];
} OSArenaInfo;

// Writes back every data cache line by set and way (cp15 c7,c10,2) without invalidating.
void DC_StoreAll(void);
// For every set and way: drains the write buffer (c7,c10,4), then writes back and invalidates the line (c7,c14,2).
void DC_FlushAll(void);
// Invalidates the data cache lines of the range at p, length n, without writing back (c7,c6,1, 32-byte lines).
void DC_InvalidateRange(void *p, u32 n);
// Writes back the data cache lines of the range at p, length n, without invalidating (c7,c10,1).
void DC_StoreRange(const void *p, u32 n);
// For each line of the range at p, length n: drains the write buffer (c7,c10,4), then writes back and invalidates it
// (c7,c14,1).
void DC_FlushRange(const void *p, int n);
// Drains the write buffer (c7,c10,4).
void DC_WaitWriteBufferEmpty(void);
// Invalidates the instruction cache lines of the range at p, length n (c7,c5,1).
void IC_InvalidateRange(void *p, u32 n);
// Starts up the OS: arenas, PXI, locks, interrupts, exceptions, memory, threads, reset, cartridge, card and power
// management.
void OS_Init(void);
// Turns the extra main memory arena off; must run before OS_Init.
void OS_DisableMainExArena(void);
// Stores the Lo bound of the arena.
void OS_SetArenaLo(OSArenaId id, void *newLo);
// Stores the Hi bound of the arena.
void OS_SetArenaHi(OSArenaId id, void *newHi);
// Returns the Lo bound an arena starts out with.
void *OS_GetInitArenaLo(OSArenaId id);
// Returns the Hi bound an arena starts out with.
void *OS_GetInitArenaHi(OSArenaId id);
// Returns the Lo bound of the arena.
void *OS_GetArenaLo(OSArenaId id);
// Returns the Hi bound of the arena.
void *OS_GetArenaHi(OSArenaId id);
// Sets up the extra main memory arena, and the memory protection regions when that arena is off.
void OS_InitArenaEx(void);
// Fills in the arena bounds on the first call only; the extra main memory arena starts out empty.
void OS_InitArena(void);
