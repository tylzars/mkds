#pragma once

#include "types.h"

typedef struct Unk021a998c_0c Unk021a998c_0c;

// Argument of func_ov000_021a998c.
struct Unk021a998c;
typedef s32 (*Unk021a998cFunc)(void *param_1, u32 param_2, struct Unk021a998c *param_3);

typedef struct Unk021a998c {
    /* 00 */ struct Thread *mThread;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u8 mState;
    /* 09 */ u8 mUnk_09;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ Unk021a998c_0c *mUnk_0c;
    /* 10 */ u32 mStateStartTime;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u16 mUnk_18;
    /* 1a */ u16 mUnk_1a;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ u32 mUnk_24;
    /* 28 */ u32 mUnk_28;
    /* 2c */ u16 mUnk_2c;
    /* 2e */ u16 mUnk_2e;
    /* 30 */ u32 mUnk_30;
    /* 34 */ u32 mUnk_34;
    /* 38 */ Unk021a998cFunc mReceiveCallback;
    /* 3c */ u32 mReceiveBufferSize;
    /* 40 */ u8 *mReceiveBuffer;
    /* 44 */ u32 mReceiveBufferLength;
    /* 48 */ u32 mSendBufferSize;
    /* 4c */ u8 *mSendBuffer;
    /* 50 */ u8 mUnk_50[0xc];
    /* 5c */ u8 *mUnk_5c;
    /* 60 */ u32 mUnk_60;
} Unk021a998c;

#include "00/unk_021b4000.h"
#include "Main/Unknown/unk_0216f000.h"

typedef struct Unk021a998c Unk021a998c;

typedef struct Unk021a998c_0c Unk021a998c_0c;

typedef struct Unk021a998c_0c Unk021a998c_0c;

typedef struct Unk021a998c_0c Unk021a998c_0c;

typedef struct Unk021a998c_0c Unk021a998c_0c;

typedef struct Unk021a998c_0c Unk021a998c_0c;

typedef struct Unk021a998c_0c Unk021a998c_0c;

typedef struct Unk021a998c_0c Unk021a998c_0c;

// Six length and pointer pairs.
typedef struct Unk021aa880 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ const u8 *mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ const u8 *mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ const u8 *mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ const u8 *mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ const u8 *mUnk_24;
    /* 28 */ u32 mUnk_28;
    /* 2c */ const u8 *mUnk_2c;
} Unk021aa880;

typedef struct Unk021a998c_0c Unk021a998c_0c;

typedef struct Unk021aaf38 Unk021aaf38;
typedef struct Unk021a998c_0c Unk021a998c_0c;

typedef struct Unk021a998c_0c Unk021a998c_0c;

typedef struct Unk021ab5e4 Unk021ab5e4;

#include "00/code_021ad734.h"
#include "00/unk_021b6380.h"
#include "00/code_021ac3e4.h"

extern u16 data_ov000_021b4a00[2];
extern u8 data_ov000_021b617c;
extern u32 data_ov000_021b6180;
extern u8 data_ov000_021b6184[0x14];
extern u8 data_ov000_021b6197;

void func_ov000_021a9228(Unk021a998c *a);
s32 func_ov000_021a9280(u8 *a, u32 b, u8 *c, u32 d, Unk021a998c *e);
s32 func_ov000_021a9358(Unk021a998c *a);
void func_ov000_021a9394(u32 a, Unk021a998c *b);
u8 *func_ov000_021a93e0(s32 *a, Unk021a998c *b);
BOOL func_ov000_021a943c(Unk021a998c *a);
BOOL func_ov000_021a9494(Unk021a998c *a);
void func_ov000_021a9534(Unk021a998c *a);
BOOL func_ov000_021a95a0(Unk021a998c *a);
u32 func_ov000_021a9610(Unk021a998c *a);
void func_ov000_021a9640(Unk021a998c *a);
void func_ov000_021a9868(Unk021a998c *a);
void func_ov000_021a998c(Unk021a998c *a);
u8 func_ov000_021a9aa0(Unk021a998c *a);
void func_ov000_021a9c5c(void *a, u32 n);
void func_ov000_021a9ca8(u8 *a, s32 n);
u8 func_ov000_021a9d68(Unk021a998c *a);
u32 func_ov000_021aa004(u8 *a, s32 b, Unk021a998c *c);
s32 func_ov000_021aa054(void *g, u8 *h);
s32 func_ov000_021aa1e0(Unk021a998c_0c *a, u8 *b);
unsigned int func_ov000_021aa380(unsigned int p0, u8 *p1, unsigned int p2);
void func_ov000_021aa398(u8 *bytes, s32 count);
void func_ov000_021aa3b8(Unk021a998c_0c *a, u8 *b);
void func_ov000_021aa468(Unk021a998c_0c *a, u8 *b, u32 c);
void func_ov000_021aa50c(Unk021a998c_0c *a, u8 *b, u32 c);
void func_ov000_021aa5b0(Unk021a998c_0c *a, const u8 *b);
void func_ov000_021aa5e0(Unk021a998c_0c *a);
void func_ov000_021aa7b4(Unk021a998c_0c *a);
void func_ov000_021aa7f8(u8 *a, const u8 *b, Unk021a998c_0c *c);
void func_ov000_021aa880(u8 *a, const u8 *b, Unk021aa880 *c);
void func_ov000_021aa9ec(Unk021a998c_0c *a, const u8 *b);
void func_ov000_021aaa58(Unk021a998c_0c *a, u8 *b);
u32 func_ov000_021aaaec(int a, int b);
u32 func_ov000_021aaaf8(const u8 *a, s32 b, s32 c);
BOOL func_ov000_021aab3c(const u8 *a, s32 b, s32 c, u32 d);
void func_ov000_021aab74(Unk021a998c_0c *a, u8 *b);
void func_ov000_021aabf0(Unk021a998c_0c *a, u8 *b);
BOOL func_ov000_021aadcc(const s8 *a, const s8 *b);
s32 func_ov000_021aae2c(const s8 *text);
u32 func_ov000_021aae44(Unk021a998c_0c *a);
u32 func_ov000_021aaf38(Unk021a998c_0c *a, Unk021aaf38 *b);
BOOL func_ov000_021ab09c(Unk021a998c_0c *a, u8 **b, s32 c, s32 d, s32 e);
u32 func_ov000_021ab448(const u8 *a, u32 b);
void func_ov000_021ab4b0(s8 *a, const s8 *b, s32 c);
s32 func_ov000_021ab4f8(u8 **a);
u32 func_ov000_021ab548(Unk021a998c_0c *a, const s8 *b);
void func_ov000_021ab594(u32 a, u32 b);
u32 func_ov000_021ab5bc(void);
Unk021ab5e4 *func_ov000_021ab5e4(const u8 *a);
Unk021ab5e4 *func_ov000_021ab63c(u32 a, u32 b);
Unk021ab5e4 *func_ov000_021ab684(const u8 *a);
// Declared here until the code that defines them is decompiled.
