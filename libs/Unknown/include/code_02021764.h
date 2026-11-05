#pragma once

#include "types.h"

typedef struct Unk020217b4_20 {
    /* 00 */ s16 mUnk_00[16];
    /* 20 */ u32 mUnk_20;
} Unk020217b4_20;

// 0x280 bytes.
typedef struct Unk020217b4 {
    /* 000 */ u32 mUnk_000;
    /* 004 */ u32 mUnk_004;
    /* 008 */ u16 mUnk_008;
    /* 00a */ u16 mUnk_00a;
    /* 00c */ u8 mUnk_00c[0x14];
    /* 020 */ Unk020217b4_20 mUnk_020[16];
    /* 260 */ s16 mUnk_260[16];
} Unk020217b4;

extern Unk020217b4 *data_02174e00;

u32 func_02021764(u32 arg0);
// Clears the three fields (function, argument, generation byte) of each of the 8 entries of the alarm table
// data_02174da0.
void SND_AlarmInit(void);
void func_020217b4(Unk020217b4 *p);
u32 func_02021834(void);
// Invalidates the cache of the halfword at index b of the player record a of the shared-work area (the records start at
// +0x20 and are 0x24 bytes apart) and returns it as a signed halfword.
s16 SND_GetPlayerLocalVariable(s32 a, s32 b);
// Invalidates the cache line of the word at +4 of the shared-work area (data_02174e00) and returns it. The other
// processor keeps one bit per active player in it.
u32 SND_GetPlayerStatus(void);
