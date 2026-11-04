#pragma once

#include "00/code_0219b580.h"
#include "00/code_0219c384.h"
#include "00/code_0219c93c.h"
#include "00/code_0219d934.h"
#include "00/code_0219de4c.h"
#include "types.h"
#include "00/code_021a4b98.h"
#include "00/code_021a2ccc.h"
#include "00/code_021a3760.h"
#include "code_02142eac.h" // Unk021438f0
#include "code_0200f7a0.h"  // Unk0200fb08
#include "00/code_021a6fa8.h"
#include "code_0200e77c.h"

// One element of the table at data_ov000_021b5dfc.
typedef struct Unk021b5dfc {
    /* 0 */ u32 mUnk_00;
} Unk021b5dfc;

typedef void (*Unk021b5f54Func)(void *param_1, void *param_2, void *param_3, u16 param_4);

typedef struct Unk021b5f54 {
    /* 00 */ u8 mUnk_00;
    /* 04 */ Unk0200df9c mUnk_04;
    /* 0c */ Unk0200edc0 mUnk_0c;
    /* 24 */ s32 mUnk_24;
    /* 28 */ Unk021b5f54Func mUnk_28;
} Unk021b5f54;

typedef struct Unk021b5f94 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ void *(*mUnk_18)(u32 param_1);
    /* 1c */ void (*mUnk_1c)(void *param_1);
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ void *mUnk_28;
    /* 2c */ s32 mUnk_2c;
    /* 30 */ s32 mUnk_30;
    /* 34 */ s32 mUnk_34;
} Unk021b5f94;

typedef struct Unk021b5fa8 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ void *(*mUnk_04)(u32 param_1);
    /* 08 */ void (*mUnk_08)(void *param_1);
    /* 0c */ void (*mUnk_0c)(void);
    /* 10 */ u32 (*mUnk_10)(void);
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ void *mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ u32 mUnk_28;
    /* 2c */ u32 mUnk_2c;
} Unk021b5fa8;

// Objects whose layout isn't known yet.
extern u8 data_ov000_021b5dec[];
extern u8 data_ov000_021b5df0[];
extern Unk021b5f50 *data_ov000_021b5f50;
extern u8 data_ov000_021b5f98[];

extern u8 data_ov000_021b5678[0x20];

// Four bytes at data_ov000_021b5668.
typedef struct Unk021b5668 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u16 mUnk_02;
} Unk021b5668;

extern Unk021b5668 data_ov000_021b5668;

typedef struct Unk021b5670 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u64 mUnk_10;
    /* 18 */ u64 mUnk_18;
} Unk021b5670;

extern Unk021b5670 *data_ov000_021b5670;
extern void *data_ov000_021b5674;
extern Unk021b5f54 data_ov000_021b5f54;
extern u8 data_ov000_021b5f80;
extern u8 data_ov000_021b5f84[16];
extern Unk021b5f94 *data_ov000_021b5f94;
extern u32 data_ov000_021b5f9c;
extern Unk021a6fa8 *data_ov000_021b5fa4;
extern Unk021b5fa8 data_ov000_021b5fa8;
extern void *data_ov000_021b5fd8;
extern Unk0200eb90 data_ov000_021b5fdc;

extern s32 data_ov000_021b5284;
extern char data_ov000_021b5288[2][0x16];
extern char *data_ov000_021b52b4;
extern char *data_ov000_021b52b8;
extern u32 data_ov000_021b52bc;
extern u32 data_ov000_021b52c0;
extern void *data_ov000_021b52c4;
extern u8 data_ov000_021b52c8[];
extern s32 data_ov000_021b54cc;
extern void *data_ov000_021b5658;
extern void (*data_ov000_021b5660)();
