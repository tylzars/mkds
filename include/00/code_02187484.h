#pragma once

#include "types.h"
#include "00/code_02186628.h"

typedef struct Unk0200db5c Unk0200db5c;

// Three words: a function called with (name, size) that returns a block, a function called with (name, block, 0) that
// releases it, and a word.
typedef struct Unk02188114 {
    /* 00 */ void *(*mUnk_00)();
    /* 04 */ void (*mUnk_04)();
    /* 08 */ u32 mUnk_08;
} Unk02188114;

// Object behind data_ov000_021b4cb0.
typedef struct Unk02187490 {
    /* 000 */ u32 mUnk_00;
    /* 004 */ s32 mUnk_04;
    /* 008 */ Unk021868a4Entry mUnk_08[0x20];
    /* 108 */ Unk02188114 mUnk_108;
    /* 114 */ void *mUnk_114;
    /* 118 */ void *mUnk_118;
    /* 11c */ Unk0200db5c mUnk_11c;
    /* 1d4 */ u8 pad_1d4[8];
    /* 1dc */ Unk0200edc0 mUnk_1dc;
    /* 1f4 */ u8 pad_1f4[0x100c];
    /* 1200 */ u8 mUnk_1200[0x1000];
} Unk02187490;

// Object behind gHttp.
typedef struct Unk021b4cac {
    /* 000 */ u8 mUnk_000[0x24];
    /* 024 */ s32 mResult;
    /* 028 */ u8 mUnk_028[0x910];
    /* 938 */ u32 mUnk_938;
    /* 93c */ u8 mUnk_93c[0x2c];
    /* 968 */ u8 mThread[0x6c];
    /* 9d4 */ s32 mUnk_9d4;
} Unk021b4cac;

typedef struct Unk021b4cb4 {
    /* 00 */ char *mUnk_00;
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
    /* 04a */ char mUnk_04a[0x12d];
    /* 177 */ char mUnk_177[0x4d];
} Unk0218635c;

#include "code_0200db4c.h"
#include "code_02151868.h"
#include "00/code_02185954.h"
#include "00/unk_021b1000.h"
#include "00/code_02188008.h"
#include "00/code_02186a9c.h"

extern char *data_ov000_021b1384;
extern char data_ov000_021b13ac[];
extern char data_ov000_021b13c4[];
extern char data_ov000_021b13c8[];
extern char data_ov000_021b13d0[];
extern char data_ov000_021b13d8[];
extern char data_ov000_021b13f4[];
extern char data_ov000_021b1400[];
extern char data_ov000_021b1420[];
extern char data_ov000_021b1424[];
extern char data_ov000_021b142c[];
extern char data_ov000_021b1434[];
extern char data_ov000_021b143c[];
extern char data_ov000_021b144c[];
extern char data_ov000_021b1458[];
extern char data_ov000_021b1460[];
extern char data_ov000_021b1468[];
extern Unk021b4cb4 data_ov000_021b4cb4;
extern Unk021b4cd4 data_ov000_021b4cd4;

s32 func_ov000_021863cc(void);
void func_ov000_02186404(void);
u32 func_ov000_02187484(void);
void func_ov000_02187490(u32 a);
u32 func_ov000_021874c0(void);
void func_ov000_021874ec(void);
void func_ov000_02187fb8(void);
