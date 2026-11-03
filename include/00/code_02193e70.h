#pragma once

#include "types.h"
#include "00/code_0218f960.h"

// Entry of the list behind Unk02193f2cNode.mUnk_38.
typedef struct Unk0219405c {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u8 mUnk_04[0xc];
    /* 10 */ s32 mUnk_10;
    /* 14 */ u32 mUnk_14;
} Unk0219405c;

// Message handed to func_ov000_02190ed4 by func_ov000_021941c4.
typedef struct Unk021941c4Msg {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
} Unk021941c4Msg;

// Entry of the list at 0x38 of Unk02193f2cNode.
typedef struct Unk02194370Entry {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
} Unk02194370Entry;

#include "00/code_02193000.h"
#include "00/code_021a3000.h"
#include "00/code_021906e4.h"

extern u8 data_ov000_021b333c[];
extern u8 data_ov000_021b33a0[];
extern u8 data_ov000_021b3440[];
extern s8 data_ov000_021b3490[];
extern u8 data_ov000_021b3494[];
extern u8 data_ov000_021b34a4[];
extern u8 data_ov000_021b34a8[];
extern u8 data_ov000_021b34c8[];
extern u8 data_ov000_021b34d0[];
extern u8 data_ov000_021b34d8[];
extern u8 data_ov000_021b34e0[];
extern u8 data_ov000_021b34e8[];
extern u8 data_ov000_021b34f0[];
extern u8 data_ov000_021b34f8[];
extern u8 data_ov000_021b3500[];
extern u8 data_ov000_021b3508[];
extern u8 data_ov000_021b352c[];

int func_ov000_02193e70(GpConnection *a, Unk02193f2cNode *b);
Unk02193f2cNode *func_ov000_02193eac(GpConnection *c, u32 d, u32 e);
void func_ov000_02193f18(u32 *a);
Unk02193f2cNode *func_ov000_02193f2c(GpConnection *object, u32 key);
s32 func_ov000_02193f50(GpConnection *e);
void func_ov000_02193ff4(s32 a);
void func_ov000_0219405c(GpConnection *f, Unk02193f2cNode *g);
void func_ov000_02194120(GpConnection *a, Unk02193f2cNode *b);
s32 func_ov000_02194160(GpConnection *b, Unk02193f2cNode *c);
s32 func_ov000_021941c4(GpConnection *param_1, Unk02193f2cNode *param_2);
s32 func_ov000_02194370(GpConnection *a, Unk02193f2cNode *b);
s32 func_ov000_021943f0(GpConnection *param_1, Unk02193f2cNode *param_2);
// Declared here until the code that defines them is decompiled.
s32 func_ov000_02194590(GpConnection *param_1, Unk02193f2cNode *param_2);
