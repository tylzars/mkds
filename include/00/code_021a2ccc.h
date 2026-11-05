#pragma once

#include "types.h"

typedef struct Unk021a2d68 Unk021a2d68;
typedef struct Unk0219887c Unk0219887c;

// One element of the table at the start of Unk021b5dd0.
typedef struct Unk021a2d68 {
    /* 00 */ u8 *mUnk_00;
    /* 04 */ u8 *mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ u8 mUnk_1c;
    /* 1d */ u8 mUnk_1d;
    /* 1e */ u8 mUnk_1e;
    /* 1f */ u8 pad_1f[3];
    /* 22 */ u16 mUnk_22;
    /* 24 */ u64 mUnk_24;
    /* 2c */ u32 mUnk_2c;
} Unk021a2d68;

typedef struct Unk021b5dd0 {
    /* 000 */ Unk021a2d68 mUnk_000[32];
    // Called after a send was queued or finished, with (size, index).
    /* 600 */ void (*mSendCallback)(s32 a, u32 b);
    // Called with (index, buffer, size) when a received message is complete.
    /* 604 */ void (*mReceiveCallback)(u32 a, u8 *b, s32 c);
    /* 608 */ void (*mUnk_608)(u32 a);
    /* 60c */ void (*mUnk_60c)(u32 a, u32 b);
    /* 610 */ u16 mUnk_610;
    /* 612 */ u8 pad_612[2];
} Unk021b5dd0;

// Local of func_ov000_021a31e8, filled by a copy of eight bytes.
typedef struct Unk021a31e8 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u8 mUnk_06[2];
} Unk021a31e8;

extern Unk021b5dd0 *data_ov000_021b5dd0;

BOOL func_ov000_021a2ccc(void);
s32 func_ov000_021a2d18(u32 a);
void func_ov000_021a2d38(u32 a, void *b, s32 c);
void func_ov000_021a2d68(int a, void *b, s32 c);
void func_ov000_021a2dfc(int a, void *b, s32 c);
void func_ov000_021a2e7c(Unk0219887c *a, const void *b, int c);
void func_ov000_021a2eec(Unk0219887c *a, void *b, s32 c);
void func_ov000_021a2f98(u32 a, u32 b, u32 c, u32 d);
u8 func_ov000_021a2fb4(int a);
u8 func_ov000_021a2fc8(int a);
Unk021a2d68 *func_ov000_021a2fdc(int a);
void func_ov000_021a2fec(void);
void func_ov000_021a2ff8(int a);
void func_ov000_021a3030(void);
void func_ov000_021a314c(Unk0219887c *a, u32 b);
void func_ov000_021a317c(Unk0219887c *a, void *b, s32 c, u32 d);
void func_ov000_021a31a4(Unk021b5dd0 *state);
s32 func_ov000_021a31d4(s32 value);
u16 func_ov000_021a31e8(const void *a);
void func_ov000_021a321c(Unk021a31e8 *a, u16 b, u32 c);
void func_ov000_021a323c(void (*arg0)(u32, void *, u32));
void func_ov000_021a3250(u32 (*arg0)(void));
