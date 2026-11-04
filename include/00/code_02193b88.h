#pragma once

#include "types.h"
#include "00/code_0218f960.h"
#include "00/code_021919ac.h"

// Payload at 0x04 of a Unk021937c0Node whose 0x00 is 3.
typedef struct Unk02193858 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ u8 mUnk_0c[0xc];
    /* 18 */ void *mUnk_18;
} Unk02193858;

// Buffers made by func_ov000_02193954, one for each request type; the first word is taken from the request.
typedef struct Unk02193954_0 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u8 mUnk_08[0x18];
} Unk02193954_0;

typedef struct Unk02193954_1 {
    /* 0 */ s32 mUnk_00;
    /* 4 */ u8 mUnk_04[4];
} Unk02193954_1;

typedef struct Unk02193954_3 {
    /* 0 */ s32 mUnk_00;
    /* 4 */ u8 mUnk_04[8];
    /* c */ u32 mUnk_0c;
} Unk02193954_3;

typedef struct Unk02193954_4 {
    /* 0 */ s32 mUnk_00;
} Unk02193954_4;

// Three words printed by func_ov000_02193c20.
typedef struct Unk02193c20 {
    /* 0 */ u32 mUnk_00;
    /* 4 */ u32 mUnk_04;
    /* 8 */ u32 mUnk_08;
} Unk02193c20;

// Output buffer description built by func_ov000_02193c74.
typedef struct Unk02193c74 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
} Unk02193c74;

// Address passed to func_ov000_0218e4b4 by func_ov000_02193d64.
typedef struct Unk02193d64 {
    /* 0 */ u8 mUnk_00;
    /* 1 */ u8 mUnk_01;
    /* 2 */ u16 mUnk_02;
    /* 4 */ u32 mUnk_04;
} Unk02193d64;

u32 func_ov000_021938cc(GpConnection *param_1, int param_2, int param_3, int *param_4, int param_5, int param_6,
                        int param_7);

#include "00/code_02190cd4.h"

#include "00/code_021965a0.h"
#include "00/code_021967b4.h"
#include "00/code_02193634.h"
#include "00/code_0218e2dc.h"

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

extern char data_ov000_021b333c[];
extern u8 data_ov000_021b33a0[];
extern char data_ov000_021b3440[];
extern s8 data_ov000_021b3490[];
extern u8 data_ov000_021b3494[];
extern char data_ov000_021b34a4[];
extern char data_ov000_021b34a8[];
extern char data_ov000_021b34c8[];
extern char data_ov000_021b34d0[];
extern char data_ov000_021b34d8[];
extern char data_ov000_021b34e0[];
extern char data_ov000_021b34e8[];
extern char data_ov000_021b34f0[];
extern char data_ov000_021b34f8[];
extern char data_ov000_021b3500[];
extern u8 data_ov000_021b3508[];
extern u8 data_ov000_021b352c[];

s32 func_ov000_02193b88(GpConnection *param_1, Unk02193f2cNode *param_2, const char *param_3, s32 param_4);
u32 func_ov000_02193c20(GpConnection *param_1, Unk02193f2cNode *param_2, u32 param_3, Unk02193c20 *param_4);
s32 func_ov000_02193c74(GpConnection *param_1, Unk02193f2cNode *param_2, u32 param_3, const char *param_4);
s32 func_ov000_02193d64(GpConnection *param_1, Unk02193f2cNode *param_2);
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
