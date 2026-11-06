#pragma once

#include "types.h"
#include "code_02012b30.h" // MtxFx43
#include "code_0201c528.h" // Unk0201ca6c
#include "01/code_0219b250.h"

// The 0x20 bytes at 0x08 of the object behind data_0217b200.
typedef struct Unk0217b200_08 {
    /* 00 */ u16 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
} Unk0217b200_08;

// Object behind data_0217b200 (a 0x124-byte allocation).
typedef struct Unk0217b200 {
    /* 000 */ u16 mUnk_000;
    /* 002 */ u16 mUnk_002;
    /* 004 */ u16 mUnk_004;
    /* 008 */ Unk0217b200_08 mUnk_008;
    /* 028 */ u8 mUnk_028[0x6c];
    /* 094 */ Unk0219b250_Item mUnk_094;
    /* 0b4 */ u8 mUnk_0b4[0x18];
    /* 0cc */ MtxFx43 mUnk_0cc;
    /* 0fc */ s16 mUnk_0fc;
    /* 0fe */ s16 mUnk_0fe;
    /* 100 */ s16 mUnk_100;
    /* 102 */ s16 mUnk_102;
    /* 104 */ s16 mUnk_104;
    /* 106 */ s16 mUnk_106;
    /* 108 */ Vec3 mUnk_108;
    /* 114 */ s32 mUnk_114;
    /* 118 */ Unk0201ca6c *mUnk_118;
    /* 11c */ Unk0201ca6c *mUnk_11c;
    /* 120 */ Unk0201ca6c *mUnk_120;
} Unk0217b200;

extern Unk0217b200 *data_0217b200;
