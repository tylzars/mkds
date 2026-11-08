#pragma once

#include "types.h"

// Object behind member 0x04 of the elements of the tables of RaceNcerNclrNcgrTables: a halfword at 0x04.
typedef struct Unk020b6e00 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mUnk_04;
} Unk020b6e00;

s32 LookupRaceSNcerIndex(s32 a, s32 b);
void func_020b80a8(void);
void func_020b7fd8(s32 a, s32 *b, s32 *c);
void func_020b6e00(u16 *a, void *b);
void CopyRaceTransferMapMrSO(u16 *a, void *b);
void func_020b7ee8(s32 a, s32 *b, s32 *c);
