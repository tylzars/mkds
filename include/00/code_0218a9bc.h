#pragma once

#include "types.h"

struct Unk0218a9bc;

// 0x24 bytes allocated by func_ov000_0218af28.
typedef struct SbServer {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u16 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u8 mUnk_14;
    /* 15 */ u8 mUnk_15;
    /* 18 */ struct Hashtable *mKeyValues;
    /* 1c */ u32 mPing;
    /* 20 */ struct SbServer *mUnk_20;
} SbServer;

typedef struct Unk0218ae68 {
    /* 00 */ SbServer *mUnk_00;
    /* 04 */ SbServer *mUnk_04;
    /* 08 */ s32 mUnk_08;
} Unk0218ae68;

typedef struct Unk0218a9bc {
    /* 00 */ u32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ Unk0218ae68 mUnk_08;
    /* 14 */ Unk0218ae68 mUnk_14;
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ u32 mUnk_28;
    /* 2c */ u8 mUnk_2c[0x14];
    /* 40 */ s32 mUnk_40;
    /* 44 */ UnkFunc *mUnk_44;
    /* 48 */ void *mUnk_48;
} Unk0218a9bc;

typedef struct Unk0218aa14 {
    /* 0 */ u8 mUnk_00;
    /* 1 */ u8 mUnk_01;
    /* 2 */ u16 mUnk_02;
    /* 4 */ u32 mUnk_04;
} Unk0218aa14;

void func_ov000_0218a9bc(Unk0218a9bc *p);
void func_ov000_0218aa14(Unk0218a9bc *p, s32 q);
