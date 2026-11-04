#pragma once

#include "types.h"

typedef struct Unk020217b4 Unk020217b4;

// 0x18 bytes, linked through mUnk_00. data_021735a0 holds 256 of them; func_020215bc chains them and func_020213ec
// takes one.
typedef struct Unk020207ec {
    /* 00 */ struct Unk020207ec *mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
} Unk020207ec;

// 12 bytes; func_02021734 sets mUnk_00 and mUnk_04 and adds 1 to mUnk_08, func_020216d4 calls mUnk_00 with mUnk_04.
typedef struct Unk02021734 {
    /* 00 */ UnkFunc *mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ u8 mUnk_08;
} Unk02021734;

extern Unk020207ec *data_021732c8;
extern u32 data_021732cc;
extern Unk020207ec *data_021732d0;
extern Unk020207ec *data_021732d4;
extern Unk020207ec *data_021732d8;
extern s32 data_021732dc;
extern s32 data_021732e0;
extern s32 data_021732e4;
extern u32 data_021732e8;
extern Unk020207ec *data_021732ec[13];
extern Unk020217b4 data_02173320;
extern Unk020207ec data_021735a0[256];
extern Unk02021734 data_02174da0[8];

u32 func_02020eb0(void);
Unk020207ec *func_02020ef8(void);
void func_02020f50(void);
void func_02020f84(void);
void func_02020ff0(u32 a, u32 b);
s32 func_02021020(void);
s32 func_02021040(void);
s32 func_02021080(void);
u32 func_020210c0(u32 a);
u32 func_02021114(void);
void func_02021154(u32 a);
u32 func_020211e4(u32 a);
void func_020213a4(Unk020207ec *p);
Unk020207ec *func_020213ec(u32 a);
Unk020207ec *func_02021488(u32 a);
void func_020215bc(void);
void func_020216d4(s32 a);
u8 func_02021734(s32 a, UnkFunc *b, void *c);
