#pragma once

#include "types.h"

typedef struct NNSG3dResMdl NNSG3dResMdl;

typedef struct Unk020109c4 {
    /* 00 */ u8 mUnk_00[0x20];
    /* 20 */ void (*mUnk_20)(void *);
    /* 24 */ u8 mUnk_24;
    /* 25 */ u8 mUnk_25;
} Unk020109c4;

// Linked through mUnk_10; func_02010bc8 keeps the chain ordered by mUnk_18.
typedef struct Unk02010b50 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ u8 *mUnk_08; // first byte tested by func_02010ab4
    /* 0c */ u8 mUnk_0c[4];
    /* 10 */ struct Unk02010b50 *mUnk_10;
    /* 14 */ u8 mUnk_14[4];
    /* 18 */ u8 mUnk_18;
    /* 19 */ u8 mUnk_19;    // number of entries in mUnk_1a
    /* 1a */ u16 mUnk_1a[1]; // bit 8 selects the entry's index in func_02010b50
} Unk02010b50;

// Three chains with a 64-bit set each.
typedef struct Unk02010ab4 {
    /* 00 */ u32 mUnk_00; // bit 4 set by func_020109d8
    /* 04 */ const NNSG3dResMdl *mUnk_04;
    /* 08 */ Unk02010b50 *mUnk_08;
    /* 0c */ u8 mUnk_0c[4];
    /* 10 */ Unk02010b50 *mUnk_10;
    /* 14 */ u8 mUnk_14[4];
    /* 18 */ Unk02010b50 *mUnk_18;
    /* 1c */ u8 mUnk_1c[0x20];
    /* 3c */ u32 mUnk_3c[2];
    /* 44 */ u32 mUnk_44[2];
    /* 4c */ u32 mUnk_4c[2];
    /* 54 */ u8 mUnk_54[4];
    /* 58 */ s32 mUnk_58;
    /* 5c */ u8 mUnk_5c[0xc];
    /* 68 */ u32 mUnk_68;
} Unk02010ab4;

void func_020109c4(Unk020109c4 *a, void (*b)(void *), u32 c, u32 d, u32 e);
void func_020109d8(Unk02010ab4 *a, Unk02010b50 *b);
int func_02010a40(Unk02010b50 **a, Unk02010b50 *b);
void func_02010ab4(Unk02010ab4 *a, Unk02010b50 *b);
void func_02010b50(u32 *a, Unk02010b50 *b);
void func_02010bc8(Unk02010b50 **a, Unk02010b50 *b);
