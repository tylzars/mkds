#pragma once

#include "types.h"
#include "code_02003024.h"

// What func_0212d580 points at; its bytes at 4 and 5 are read.
typedef struct Unk0212d580 {
    /* 0 */ u8 mUnk_00[4];
    /* 4 */ u8 mUnk_04;
    /* 5 */ u8 mUnk_05;
} Unk0212d580;

// 12-byte records at 0x20 of Unk0212f788; func_0212f788 returns one unless its first word is -1.
typedef struct Unk0212f788 {
    /* 00 */ u8 mUnk_00[0x18];
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c; // number of records
    /* 20 */ u32 mUnk_20[3];
} Unk0212f788;

// Entry of 0x10 bytes in the table at mUnk_84 of Unk0212d5f8: func_0212d27c reads up to mUnk_04 bytes from offset
// mUnk_00 through mUnk_34 of Unk0212d5f8, and func_0212d5f8 sets mUnk_08 to its buf + mUnk_00.
typedef struct Unk0212d27c {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ Unk0212f788 *mUnk_08;
    /* 0c */ u32 mUnk_0c;
} Unk0212d27c;

// Table at mUnk_84 of Unk0212d5f8: mUnk_08 entries from 0x0c.
typedef struct Unk0212d254 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ Unk0212d27c mUnk_0c[1];
} Unk0212d254;

// Table at an offset (counted from the start of Unk0212d38c) stored in Unk0212d38c: mUnk_00 offsets from 0x04.
typedef struct Unk0212d328 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04[1];
} Unk0212d328;

// Block at mUnk_8c of Unk0212d5f8: offsets of six tables read by func_0212d328 to func_0212d51c.
typedef struct Unk0212d38c {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ u32 mUnk_08[6];
} Unk0212d38c;

// 0x90-byte object: func_0212d5f8 copies its first 0x30 bytes from buf, func_0212d6c4 reads them through
// FS_ReadFile on mUnk_34.
typedef struct Unk0212d5f8 {
    /* 00 */ u8 mUnk_00[0x10];
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ u32 mUnk_24;
    /* 28 */ u8 mUnk_28[8];
    /* 30 */ u32 mUnk_30;
    /* 34 */ Unk02003024 mUnk_34;
    /* 7c */ Unk02005814 mUnk_7c;
    /* 84 */ Unk0212d254 *mUnk_84;
    /* 88 */ void *mUnk_88;
    /* 8c */ Unk0212d38c *mUnk_8c;
} Unk0212d5f8;

void *func_0212d254(u32 a);
s32 func_0212d27c(u32 a, void *dst, u32 n, u32 off);
u32 func_0212d300(u32 a);
void *func_0212d328(s32 a);
void *func_0212d38c(s32 a);
void *func_0212d3f0(s32 a);
void *func_0212d454(s32 a);
u32 *func_0212d4b8(s32 a);
void *func_0212d51c(s32 a);
Unk0212d580 *func_0212d580(s32 a, s32 b);
