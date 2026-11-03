#pragma once

#include "types.h"
#include "code_0200db4c.h"
#include "code_02151868.h"
#include "00/code_02185984.h"
#include "00/unk_021b1000.h"
#include "00/code_02188008.h"
#include "00/code_02186628.h"
#include "00/code_02186a9c.h"
#include "00/code_02187490.h"

// Object behind data_ov000_021b4cac.
typedef struct Unk021b4cac {
    /* 000 */ u8 mUnk_000[0x24];
    /* 024 */ s32 mUnk_024;
    /* 028 */ u8 mUnk_028[0x910];
    /* 938 */ u32 mUnk_938;
    /* 93c */ u8 mUnk_93c[0x2c];
    /* 968 */ u8 mUnk_968[0x6c];
    /* 9d4 */ s32 mUnk_9d4;
} Unk021b4cac;

typedef struct Unk021b4cb4 {
    /* 00 */ u8 *mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ void *(*mUnk_10)();
    /* 14 */ void (*mUnk_14)();
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
} Unk021b4cb4;

typedef struct Unk021b4cd4 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01[0x14];
    /* 15 */ u8 mUnk_15;
    /* 16 */ u8 mUnk_16[0xe];
    /* 24 */ void *(*mUnk_24)();
    /* 28 */ void (*mUnk_28)();
} Unk021b4cd4;

// Object filled by func_ov000_0218635c.
typedef struct Unk0218635c {
    /* 000 */ s32 mUnk_000;
    /* 004 */ u8 mUnk_004[0x46];
    /* 04a */ u8 mUnk_04a[0x12d];
    /* 177 */ u8 mUnk_177[0x4d];
} Unk0218635c;

extern Unk021b4cb4 data_ov000_021b4cb4;
extern Unk021b4cd4 data_ov000_021b4cd4;
extern u8 *data_ov000_021b1384;
extern u8 data_ov000_021b13ac[];
extern u8 data_ov000_021b13c4[];
extern u8 data_ov000_021b13c8[];
extern u8 data_ov000_021b13d0[];
extern u8 data_ov000_021b13d8[];
extern u8 data_ov000_021b13f4[];
extern u8 data_ov000_021b1400[];
extern u8 data_ov000_021b1420[];
extern u8 data_ov000_021b1424[];
extern u8 data_ov000_021b142c[];
extern u8 data_ov000_021b1434[];
extern u8 data_ov000_021b143c[];
extern u8 data_ov000_021b144c[];
extern u8 data_ov000_021b1458[];
extern u8 data_ov000_021b1460[];
extern u8 data_ov000_021b1468[];

s32 func_ov000_021863cc(void);
void func_ov000_02186404(void);
void func_ov000_021874ec(void);
