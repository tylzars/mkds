#pragma once

#include "types.h"

// Writes back every data cache line by set and way (cp15 c7,c10,2) without invalidating.
void DC_StoreAll(void);
// For every set and way: drains the write buffer (c7,c10,4), then writes back and invalidates the line (c7,c14,2).
void DC_FlushAll(void);
// Invalidates the data cache lines of the range at p, length n, without writing back (c7,c6,1, 32-byte lines).
void DC_InvalidateRange(void *p, u32 n);
// Writes back the data cache lines of the range at p, length n, without invalidating (c7,c10,1).
void DC_StoreRange(void *p, u32 n);
// For each line of the range at a, length b: drains the write buffer (c7,c10,4), then writes back and invalidates it
// (c7,c14,1).
void DC_FlushRange(const void *a, int b);
// Drains the write buffer (c7,c10,4).
void DC_WaitWriteBufferEmpty(void);
// Invalidates the instruction cache lines of the range at p, length n (c7,c5,1).
void IC_InvalidateRange(void *p, u32 n);
// Calls its 15 start-up steps in a fixed order (arena, PXI, ..., card, power management); the boot function calls it
// once, right after OS_DisableMainExArena, and then calls OS_InitTick and OS_InitAlarm itself.
void OS_Init(void);
// Stores 0 in gArena2Enabled.
u32 OS_DisableMainExArena(void);
// Stores v as the Lo bound of arena i (word at 0x027ffda0 + i * 4).
void OS_SetArenaLo(u32 i, u32 v);
// Stores v as the Hi bound of arena i (word at 0x027ffdc4 + i * 4).
void OS_SetArenaHi(u32 i, u32 v);
// Initial Lo bound of arena i: 0x021da300 (0), 0x01ffffa0 (3), 0x027e00e0 (4), 0x027ff000 (5), 0x037f8000 (6); index
// 2 gives 0x02400000 when gArena2Enabled is nonzero and the low two bits of func_0200e884() are not 1, else 0.
u32 OS_GetInitArenaLo(u32 i);
// Initial Hi bound of arena i: 0x023e0000 (0), 0x02000000 (3), 0x027e0b80 (4), 0x027ff680 (5), 0x037f8000 (6); index
// 2 gives 0x02700000 under the same test as OS_GetInitArenaLo, else 0.
u32 OS_GetInitArenaHi(u32 i);
// Returns the Lo bound of arena arg0 (word at 0x027ffda0 + arg0 * 4). The boot code builds the heap from arena 0.
u32 OS_GetArenaLo(int arg0);
// Returns the Hi bound of arena arg0 (word at 0x027ffdc4 + arg0 * 4).
u32 OS_GetArenaHi(int arg0);
// Fills index 2 of both tables from the initial values; unless gArena2Enabled is nonzero and the low two bits of
// func_0200e884() are not 1, then writes protection region 1 (0x0200002b) and region 2 (0x023e0021).
void OS_InitArenaEx(void);
// Runs once: fills the Lo and Hi tables for indices 0 and 3 to 6 from OS_GetInitArenaLo and OS_GetInitArenaHi, sets
// index 2 to 0 and 0, leaves index 1 alone.
void OS_InitArena(void);
