#include "code_0200eddc.h"

#include "code_0200c4a4.h"
#include "code_0200c914.h"
#include "code_0200cd04.h"
#include "code_0200ce60.h"
#include "code_0200db4c.h"
#include "code_0214d594.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200f3f4.h"
#include "code_0200f790.h"
#include "code_0200fc8c.h"
#include "code_0200fe74.h"
#include "Main/Unknown/code_02146000.h"
#include "code_021458c4.h"
#include "code_0214d5b8.h"
#include "code_0214f4a4.h"
#include "Main/Unknown/code_02150000.h"
#include "Main/Unknown/unk_02170000.h"
#include "code_0200e77c.h"
#include "Main/Unknown/unk_00000000.h"
#include "Main/Unknown/unk_00002000.h"
#include "Main/Unknown/unk_02400000.h"
#include "code_0200f328.h"
#include "Main/Unknown/code_0200e000.h"

u32 gArena2Enabled;

// Fills in the arena bounds on the first call only; the extra main memory arena starts out empty.
void OS_InitArena(void) {
    if (data_021701b4 != 0) {
        return;
    }
    data_021701b4 = 1;
    OS_SetArenaHi(OS_ARENA_MAIN, OS_GetInitArenaHi(OS_ARENA_MAIN));
    OS_SetArenaLo(OS_ARENA_MAIN, OS_GetInitArenaLo(OS_ARENA_MAIN));
    OS_SetArenaLo(OS_ARENA_MAINEX, NULL);
    OS_SetArenaHi(OS_ARENA_MAINEX, NULL);
    OS_SetArenaHi(OS_ARENA_ITCM, OS_GetInitArenaHi(OS_ARENA_ITCM));
    OS_SetArenaLo(OS_ARENA_ITCM, OS_GetInitArenaLo(OS_ARENA_ITCM));
    OS_SetArenaHi(OS_ARENA_DTCM, OS_GetInitArenaHi(OS_ARENA_DTCM));
    OS_SetArenaLo(OS_ARENA_DTCM, OS_GetInitArenaLo(OS_ARENA_DTCM));
    OS_SetArenaHi(OS_ARENA_SHARED, OS_GetInitArenaHi(OS_ARENA_SHARED));
    OS_SetArenaLo(OS_ARENA_SHARED, OS_GetInitArenaLo(OS_ARENA_SHARED));
    OS_SetArenaHi(OS_ARENA_WRAM_MAIN, OS_GetInitArenaHi(OS_ARENA_WRAM_MAIN));
    OS_SetArenaLo(OS_ARENA_WRAM_MAIN, OS_GetInitArenaLo(OS_ARENA_WRAM_MAIN));
}

// Sets up the extra main memory arena, and the memory protection regions when that arena is off.
void OS_InitArenaEx(void) {
    OS_SetArenaHi(OS_ARENA_MAINEX, OS_GetInitArenaHi(OS_ARENA_MAINEX));
    OS_SetArenaLo(OS_ARENA_MAINEX, OS_GetInitArenaLo(OS_ARENA_MAINEX));
    if (gArena2Enabled != 0 && (OS_GetConsoleType() & 3) != 1) {
        return;
    }
    OS_SetProtectionRegion1(0x200002b);
    OS_SetProtectionRegion2(0x23e0021);
}

// Returns the Hi bound of the arena.
void *OS_GetArenaHi(OSArenaId id) {
    return ((OSArenaInfo *) 0x027ffda0)->hi[id];
}

// Returns the Lo bound of the arena.
void *OS_GetArenaLo(OSArenaId id) {
    return ((OSArenaInfo *) 0x027ffda0)->lo[id];
}

// Returns the Hi bound an arena starts out with.
void *OS_GetInitArenaHi(OSArenaId id) {
    u32 dtcmStart;
    s32 sysStackSize;
    u32 irqStackBottom;

    switch (id) {
        case OS_ARENA_MAIN:
            return (void *) 0x23e0000;
        case OS_ARENA_MAINEX:
            if (gArena2Enabled == 0 || (OS_GetConsoleType() & 3) == 1) {
                return NULL;
            }
            return (void *) 0x2700000;
        case OS_ARENA_ITCM:
            return (void *) 0x2000000;
        case OS_ARENA_DTCM:
            dtcmStart = (u32) &data_027e0000;
            irqStackBottom = dtcmStart + 0x3f80 - (u32) data_00000c00;
            sysStackSize = (s32) data_00002800;
            if (sysStackSize == 0) {
                return (void *) (dtcmStart < 0x27e00e0 ? 0x27e00e0 : dtcmStart);
            }
            if (sysStackSize < 0) {
                return (void *) (0x27e00e0 - sysStackSize);
            }
            return (void *) (irqStackBottom - sysStackSize);
        case OS_ARENA_SHARED:
            return (void *) 0x27ff680;
        case OS_ARENA_WRAM_MAIN:
            return (void *) 0x37f8000;
    }
    return NULL;
}

// Returns the Lo bound an arena starts out with.
void *OS_GetInitArenaLo(OSArenaId id) {
    switch (id) {
        case OS_ARENA_MAIN:
            return (void *) 0x21da300;
        case OS_ARENA_MAINEX:
            if (gArena2Enabled == 0 || (OS_GetConsoleType() & 3) == 1) {
                return NULL;
            }
            return data_02400000;
        case OS_ARENA_ITCM:
            return (void *) 0x1ffffa0;
        case OS_ARENA_DTCM:
            return (void *) 0x27e00e0;
        case OS_ARENA_SHARED:
            return (void *) 0x27ff000;
        case OS_ARENA_WRAM_MAIN:
            return (void *) 0x37f8000;
    }
    return NULL;
}

// Stores the Hi bound of the arena.
void OS_SetArenaHi(OSArenaId id, void *newHi) {
    ((OSArenaInfo *) 0x027ffda0)->hi[id] = newHi;
}

// Stores the Lo bound of the arena.
void OS_SetArenaLo(OSArenaId id, void *newLo) {
    ((OSArenaInfo *) 0x027ffda0)->lo[id] = newLo;
}

// Turns the extra main memory arena off; must run before OS_Init.
void OS_DisableMainExArena(void) {
    gArena2Enabled = 0;
}

// Starts up the OS: arenas, PXI, locks, interrupts, exceptions, memory, threads, reset, cartridge, card and power
// management.
void OS_Init(void) {
    OS_InitArena();
    PXI_Init();
    OS_InitLock();
    OS_InitArenaEx();
    OS_InitIrqTable();
    OS_SetIrqStackChecker();
    OS_InitException();
    MI_Init();
    OS_InitVAlarm();
    OSi_InitVramExclusive();
    OS_InitThread();
    OS_InitReset();
    CTRDG_Init();
    CARD_Init();
    PM_Init();
}

// clang-format off
// Not compiled code: C has no way to write a coprocessor 15 register (mcr).
asm void DC_StoreAll(void) {
    mov r1, #0x0
loop_outer:
    mov r0, #0x0
loop_inner:
    orr r2, r1, r0
    mcr p15, 0, r2, c7, c10, 2
    add r0, r0, #0x20
    cmp r0, #0x400
    blt loop_inner
    add r1, r1, #0x40000000
    cmp r1, #0x0
    bne loop_outer
    bx lr
}

// Not compiled code: C has no way to write a coprocessor 15 register (mcr).
asm void DC_FlushAll(void) {
    mov ip, #0x0
    mov r1, #0x0
loop_outer:
    mov r0, #0x0
loop_inner:
    orr r2, r1, r0
    mcr p15, 0, ip, c7, c10, 4
    mcr p15, 0, r2, c7, c14, 2
    add r0, r0, #0x20
    cmp r0, #0x400
    blt loop_inner
    add r1, r1, #0x40000000
    cmp r1, #0x0
    bne loop_outer
    bx lr
}

// Not compiled code: C has no way to write a coprocessor 15 register (mcr).
asm void DC_InvalidateRange(void *p, u32 n) {
    add r1, r1, r0
    bic r0, r0, #0x1f
loop:
    mcr p15, 0, r0, c7, c6, 1
    add r0, r0, #0x20
    cmp r0, r1
    blt loop
    bx lr
}

// Not compiled code: C has no way to write a coprocessor 15 register (mcr).
asm void DC_StoreRange(const void *p, u32 n) {
    add r1, r1, r0
    bic r0, r0, #0x1f
loop:
    mcr p15, 0, r0, c7, c10, 1
    add r0, r0, #0x20
    cmp r0, r1
    blt loop
    bx lr
}

// Not compiled code: C has no way to write a coprocessor 15 register (mcr).
asm void DC_FlushRange(const void *p, int n) {
    mov ip, #0x0
    add r1, r1, r0
    bic r0, r0, #0x1f
loop:
    mcr p15, 0, ip, c7, c10, 4
    mcr p15, 0, r0, c7, c14, 1
    add r0, r0, #0x20
    cmp r0, r1
    blt loop
    bx lr
}

// Not compiled code: C has no way to write a coprocessor 15 register (mcr).
asm void DC_WaitWriteBufferEmpty(void) {
    mov r0, #0x0
    mcr p15, 0, r0, c7, c10, 4
    bx lr
}

// Not compiled code: C has no way to write a coprocessor 15 register (mcr).
asm void IC_InvalidateRange(void *p, u32 n) {
    add r1, r1, r0
    bic r0, r0, #0x1f
loop:
    mcr p15, 0, r0, c7, c5, 1
    add r0, r0, #0x20
    cmp r0, r1
    blt loop
    bx lr
}
// clang-format on
