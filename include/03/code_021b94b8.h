#pragma once

#include "03/code_021b7ba0.h"
#include "03/code_021b7ba8.h"

#include "types.h"
#include "code_0214cfe4.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200f790.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0200db4c.h"
#include "code_0200e77c.h"

typedef struct Unk021b94c4 {
    /* 000 */ u16 mUnk_000;
    /* 002 */ u8 mUnk_002;
    /* 003 */ u8 pad_003;
    /* 004 */ u16 mUnk_004;
    /* 006 */ u8 mUnk_006[0x100];
    /* 106 */ s16 mUnk_106;
    /* 108 */ s16 mUnk_108;
    /* 10a */ s16 mUnk_10a;
    /* 10c */ s16 mUnk_10c;
    /* 10e */ s16 mUnk_10e;
    /* 110 */ u8 mUnk_110[6];
    /* 116 */ u8 mUnk_116;
    /* 117 */ u8 mUnk_117;
} Unk021b94c4;

typedef struct Unk021d7c6c {
    /* 00 */ u8 *mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ s8 mUnk_18;
    /* 19 */ s8 mUnk_19;
    /* 1a */ u8 pad_1a[2];
} Unk021d7c6c;

typedef struct Unk021ba778Src {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u8 mUnk_04[6];
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u8 mUnk_0c[0x20];
    /* 2c */ u16 mUnk_2c;
    /* 2e */ u16 mUnk_2e;
    /* 30 */ u16 mUnk_30;
    /* 32 */ u16 mUnk_32;
    /* 34 */ u16 mUnk_34;
    /* 36 */ u16 mUnk_36;
    /* 38 */ u8 pad_38[0x88];
} Unk021ba778Src;

typedef struct Unk021ba778Dst {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u8 mUnk_04[0x20];
    /* 24 */ u32 mUnk_24;
    /* 28 */ u8 pad_28[8];
    /* 30 */ u8 mUnk_30[6];
    /* 36 */ u8 pad_36[2];
    /* 38 */ u32 mUnk_38;
    /* 3c */ u8 mUnk_3c[0x10];
    /* 4c */ u32 mUnk_4c;
    /* 50 */ u32 mUnk_50;
} Unk021ba778Dst;

typedef struct Unk021ba734 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ Unk021ba778Dst mUnk_04[1];
} Unk021ba734;

/* Search request handed to func_ov003_021ba1b0. */
typedef struct Unk021ba1b0 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u8 mUnk_04[0x20];
    /* 24 */ BOOL mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ u8 mUnk_2c[0x10];
} Unk021ba1b0;

typedef struct Unk021d687c {
    u16 mUnk_00;
    u8 mUnk_02;
    u8 pad_3;
} Unk021d687c;

typedef struct Unk021d8a4c {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 mUnk_02[0x5e];
} Unk021d8a4c;

typedef struct Unk021d6808 {
    /* 0 */ s16 mUnk_00;
    /* 2 */ s16 mUnk_02;
} Unk021d6808;

typedef struct Unk021b7d1c {
    /* 0 */ s32 mUnk_00;
    /* 4 */ s32 mUnk_04;
} Unk021b7d1c;

typedef struct Unk021b7cec {
    /* 0 */ u8 mUnk_00;
    /* 1 */ u8 mUnk_01;
    /* 2 */ u16 mUnk_02;
    /* 4 */ u32 mUnk_04;
} Unk021b7cec;

typedef struct Unk021b916c {
    /* 0 */ u8 mUnk_00[6];
    /* 6 */ u16 mUnk_06;
} Unk021b916c;

typedef struct Unk021b86e4 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u8 pad_04[0xc];
    /* 10 */ u32 mUnk_10;
} Unk021b86e4;

typedef struct Unk021d7c54 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u8 pad_08[4];
    /* 0c */ u8 mUnk_0c[0x5ec];
} Unk021d7c54;

extern s32 data_ov003_021d6804;
extern Unk021d6808 data_ov003_021d6808;
extern Unk021ba734 *data_ov003_021d7c44;
extern Unk021ba734 *data_ov003_021d7c4c;
extern s32 data_ov003_021d7c50;
extern Unk021d7c54 *data_ov003_021d7c54;
extern u8 data_ov003_021d7c58[8];
extern Unk021d7c6c data_ov003_021d7c6c;
extern void *(*data_ov003_021d8a0c)(u32);
extern void (*data_ov003_021d8a10)(s32);
extern void *data_ov003_021d8a14;
extern void (*data_ov003_021d8a18)(void *);
extern void *data_ov003_021d8a1c[4];
extern RingQueue data_ov003_021d8a2c;
extern Unk021d8a4c data_ov003_021d8a4c;
extern Unk021ba778Src data_ov003_021d8ac0;

s32 func_ov003_021b7cec(s32 id, Unk021b7cec *addr, u32 length);
s32 func_ov003_021b7d1c(s32 count, Unk021b7ba0 *set, void *arg2, void *arg3, Unk021b7d1c *arg4);
s32 func_ov003_021b7d68(s32 id, void *buffer, s32 length, s32 flags, Unk021b7cec *out, s32 *outLength);
s32 func_ov003_021b7dc8(void);
s32 func_ov003_021b7df4(u32 arg0, u32 mask, u32 arg2);
s32 func_ov003_021b86e4(s32 mode, Unk021b86e4 *buf, Unk021b916c *list, s32 id);

void func_ov003_021b94b8(s32 code);
void func_ov003_021b94c4(Unk021b94c4 *req);
void func_ov003_021b9518(void);
u32 func_ov003_021b9550(u32 addr, u32 mask);
s32 func_ov003_021b9570(Unk021b94c4 *req);
s32 func_ov003_021ba05c(Unk021b94c4 *req);
void func_ov003_021ba164(void *ptr);
void *func_ov003_021ba178(u32 size);
s32 func_ov003_021ba18c(s32 state);
void func_ov003_021ba1a8(u32 ms);
s32 func_ov003_021ba1b0(Unk021ba1b0 *request, Unk021ba734 *out);
s32 func_ov003_021ba394(Unk021ba734 **out);
s32 func_ov003_021ba524(void);
s32 func_ov003_021ba560(void);
s32 func_ov003_021ba61c(void *(*alloc)(u32), void (*release)(void *));
s32 func_ov003_021ba70c(void *msg);
s32 func_ov003_021ba720(void *msg);
void func_ov003_021ba734(Unk021ba734 *list, Unk021ba778Src *src, s32 count);
void func_ov003_021ba744(Unk021ba1b0 *request, Unk021ba778Src *rec);
void func_ov003_021ba778(Unk021ba778Src *src, Unk021ba778Dst *dst);

#include "03/code_021b7000.h"
#include "03/unk_021d8000.h"
#include "Main/Unknown/code_02133000.h"
#include "03/code_021b7bb4.h"
#include "03/code_021ba818.h"
