#pragma once

#include "types.h"
#include "00/code_0218eb9c.h"
#include "00/code_0218f960.h"
#include "00/code_02190000.h"
#include "00/code_02193000.h"

extern char data_ov000_021b35b8[];
extern u8 data_ov000_021b35f8[];
extern char data_ov000_021b3628[];
extern char data_ov000_021b38c0[];
extern char data_ov000_021b38e8[];
extern char data_ov000_021b391c[];
extern char data_ov000_021b394c[];
extern char data_ov000_021b396c[];
extern char data_ov000_021b3994[];
extern char data_ov000_021b399c[];
extern char data_ov000_021b39a8[];
extern char data_ov000_021b39ac[];
extern char data_ov000_021b39c4[];
extern char data_ov000_021b39cc[];
extern u8 data_ov000_021b39fc[];

// Block filled by func_ov000_021962d4.
typedef struct Unk021962d4Addr {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u32 mUnk_04;
} Unk021962d4Addr;

BOOL func_ov000_02196240(GpConnection *a, Unk02196240 **b, u32 c);
s32 func_ov000_021962d4(GpConnection *a, Unk021937c0Node *b);
void func_ov000_02196434(GpConnection *a, Unk02193f2cNode *b, s32 c, const char *d, s32 e, s32 f);
s32 func_ov000_02196480(GpConnection *a, s32 *b, Unk02193f2cNode *c, s32 d, const char *e);
s32 func_ov000_021964e4(GpConnection *a, Unk021937c0Node *b, const char *c);
