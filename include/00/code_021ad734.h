#pragma once

#include "types.h"

typedef struct Unk021a998c Unk021a998c;

extern u32 (*data_ov000_021b6388)(void);

typedef struct Unk021a998c Unk021a998c;

struct Unk021a998c;

typedef struct Unk021a998c Unk021a998c;

typedef struct Unk0200db5c Unk0200db5c;

// Frame start: two addresses and a type word.
typedef struct Unk021ae3a4 {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ u16 mUnk_0c;
} Unk021ae3a4;

typedef struct Unk021ae3f0 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u8 mUnk_04;
    /* 05 */ u8 mUnk_05;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u8 mUnk_08;
    /* 09 */ u8 mUnk_09;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u16 mUnk_12;
} Unk021ae3f0;

typedef struct Unk021ae724 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
} Unk021ae724;

typedef struct Unk021ae87c {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u8 mUnk_0c;
    /* 0d */ u8 mUnk_0d;
    /* 0e */ u16 mUnk_0e;
    /* 10 */ u8 pad_10[4];
} Unk021ae87c;

typedef struct Unk021ae3f0 Unk021ae3f0;
typedef struct Unk021ae87c Unk021ae87c;

typedef struct Unk021af1e4 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
} Unk021af1e4;

typedef struct Unk021af3e8 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u16 mUnk_08[3];
    /* 0e */ u16 mUnk_0e;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u16 mUnk_12[3];
    /* 18 */ u16 mUnk_18;
    /* 1a */ u16 mUnk_1a;
} Unk021af3e8;

typedef struct Unk021a998c Unk021a998c;
typedef struct Unk021b6434 Unk021b6434;

// Frame built by func_ov000_021afc5c.
typedef struct Unk021afc5c {
    /* 00 */ u8 mUnk_00[6];
    /* 06 */ u8 mUnk_06[6];
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u8 mUnk_0e;
    /* 0f */ u8 mUnk_0f;
    /* 10 */ u8 mUnk_10;
    /* 11 */ u8 mUnk_11;
    /* 12 */ u16 mUnk_12;
    /* 14 */ u8 mUnk_14;
    /* 15 */ u8 mUnk_15;
    /* 16 */ u8 mUnk_16[6];
    /* 1c */ u16 mUnk_1c;
    /* 1e */ u16 mUnk_1e;
    /* 20 */ u8 mUnk_20[6];
    /* 26 */ u16 mUnk_26;
    /* 28 */ u16 mUnk_28;
} Unk021afc5c;

typedef struct Unk021b0138 {
    /* 00 */ u8 pad_00[0xc];
    /* 0c */ u8 mUnk_0c[8];
} Unk021b0138;

extern void (*data_ov000_021b6384)(void);

// Thread entry functions (not lifted yet).

#include "code_0200db4c.h"

typedef struct Unk021b69dc Unk021b69dc;
typedef struct Unk021b5fa8 Unk021b5fa8;

// Object linked from Unk0200db5c.mUnk_a4.
typedef struct Unk021b04f8 {
    /* 00 */ Unk0200db5c *mThread;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u8 mState;
} Unk021b04f8;

#include "00/code_021a78a4.h"

extern u32 data_ov000_021b4c24;
extern u32 data_ov000_021b4c28;
extern u8 data_ov000_021b4c2c[6];
extern u8 data_ov000_021b4c40[8];
extern u8 data_ov000_021b6364;
extern u8 data_ov000_021b6368;
extern u16 data_ov000_021b636c;
extern u16 data_ov000_021b6370;
extern u16 data_ov000_021b6374;
extern u16 data_ov000_021b6378;
extern u32 data_ov000_021b637c;
extern u32 data_ov000_021b6380;
extern u32 data_ov000_021b638c;
extern u32 data_ov000_021b6390;
extern u32 data_ov000_021b6394;
extern u32 data_ov000_021b639c;
extern u32 data_ov000_021b63b0;
extern u32 data_ov000_021b63b4;
extern u32 data_ov000_021b63bc;
extern Unk0200db5c *data_ov000_021b63c0;
// Objects whose layout isn't known yet.
extern u8 *data_ov000_021b63c4;
extern u32 data_ov000_021b63c8;
extern u32 data_ov000_021b63cc;
extern u16 data_ov000_021b63d0[3];
// Objects whose layout isn't known yet.
extern u8 data_ov000_021b641a[];
extern Unk021b6434 data_ov000_021b6434[8];
extern Unk021a998c data_ov000_021b64f8;
extern Unk0200db5c data_ov000_021b655c;
extern Unk0200db5c data_ov000_021b661c;
extern Unk021b69dc data_ov000_021b69dc[8];
extern u8 data_ov000_021b73a0[];

u8 *func_ov000_021ad734(u8 a, u32 b, u8 *c, u32 d);
u8 *func_ov000_021ad754(u8 *a, u8 b, u32 *c);
void func_ov000_021ad898(void);
void func_ov000_021adb00(void);
void func_ov000_021adb80(void);
s32 func_ov000_021adbac(void);
s32 func_ov000_021adbf4(const u8 *a, s32 b);
s32 func_ov000_021adc64(const u8 *a, s32 b, const u8 *c, s32 d);
s32 func_ov000_021adcec(const u8 *a, u32 b, const u8 *c, s32 d, void *e);
void func_ov000_021ade40(const u8 *a, s32 b, const u8 *c, s32 d, Unk021a998c *e, s32 f);
s32 func_ov000_021ade6c(const u8 *a, s32 b, Unk021a998c *c, s32 d);
void func_ov000_021adf00(u32 a);
void func_ov000_021adf30(u32 a, Unk021a998c *b);
u8 *func_ov000_021adf78(u32 *a);
u8 *func_ov000_021adfc8(u32 *a, Unk021a998c *b);
u8 *func_ov000_021ae01c(u32 *a, Unk021a998c *b);
void func_ov000_021ae048(void);
void func_ov000_021ae094(void);
void func_ov000_021ae0c4(Unk021a998c *a);
u32 func_ov000_021ae100(u16 *a, u32 *b);
u32 func_ov000_021ae134(void);
u32 func_ov000_021ae16c(Unk021a998c *b);
void func_ov000_021ae1e4(void);
void func_ov000_021ae214(Unk021a78a4Func a);
void func_ov000_021ae228(Unk021a998c *a);
void func_ov000_021ae244(Unk0200db5c *thread);
void func_ov000_021ae258(void);
void func_ov000_021ae270(void);
void func_ov000_021ae290(int a, u16 b, int c);
void func_ov000_021ae2d8(void);
void func_ov000_021ae2f4(void);
void func_ov000_021ae304(void *arg0);
u32 func_ov000_021ae314(void);
u16 func_ov000_021ae340(void);
void func_ov000_021ae3a4(void);
void func_ov000_021ae3f0(Unk021ae3f0 *a, u32 f);
Unk021ae3f0 *func_ov000_021ae51c(Unk021ae3f0 *r, u32 *s);
void func_ov000_021ae724(Unk021ae3f0 *a, Unk021ae724 *b, u32 c);
void func_ov000_021ae87c(Unk021ae3f0 *a, Unk021ae87c *b, u32 c);
void func_ov000_021ae958(const Unk021ae3f0 *a, const Unk021ae87c *b);
void func_ov000_021ae984(Unk021ae3f0 *param_1, Unk021ae87c *param_2, u32 param_3);
void func_ov000_021aea34(Unk021ae3f0 *param_1, Unk021ae87c *param_2, u32 param_3);
void func_ov000_021aec84(Unk021ae3f0 *param_1, Unk021ae87c *param_2, u32 param_3);
void func_ov000_021aed3c(Unk021ae3f0 *param_1, Unk021ae87c *param_2, u32 param_3);
u32 func_ov000_021aedd8(Unk021ae3f0 *param_1, Unk021ae87c *param_2, u32 param_3);
void func_ov000_021aee38(Unk021ae3f0 *param_1, Unk021ae87c *param_2, Unk021a998c *param_3);
void func_ov000_021aeed8(Unk021ae3f0 *param_1, Unk021ae87c *param_2, u32 param_3, u16 param_4);
void func_ov000_021aefa8(void *object, u16 value);
void func_ov000_021aefb4(void *object, u16 value);
void func_ov000_021aefc0(Unk021a998c *a, u32 b, u16 c);
u32 func_ov000_021af010(u32 b);
void func_ov000_021af030(const Unk021ae87c *f, Unk021a998c *g);
Unk021a998c *func_ov000_021af090(const Unk021ae3f0 *c, const Unk021ae87c *d);
u32 func_ov000_021af0dc(const Unk021ae3f0 *e, const Unk021ae87c *f, const Unk021a998c *g);
Unk021a998c *func_ov000_021af15c(const Unk021ae3f0 *c, const Unk021ae87c *d);
void func_ov000_021af1e4(Unk021ae3f0 *a, Unk021af1e4 *b, u32 c);
u32 func_ov000_021af284(int a, int b);
void func_ov000_021af2a0(Unk021ae3f0 *c, Unk021af1e4 *d, u32 e);
void func_ov000_021af348(Unk021ae3f0 *d, Unk021af1e4 *e, u32 f);
void func_ov000_021af3e8(Unk021af3e8 *f, u32 g);
void func_ov000_021af4d4(Unk021af3e8 *a);
void func_ov000_021af550(u8 *a, u32 b, Unk021a998c *c, u32 d, u16 e);
void func_ov000_021af70c(u8 *a, u32 b, Unk021a998c *c);
void func_ov000_021af7e4(u8 *a, u32 b, Unk021a998c *c);
void func_ov000_021af858(u8 *a, u32 b, u8 *c, u32 d, u32 e, u8 f);
void func_ov000_021af9d0(u8 *a, u32 b, void *c, u32 d, u32 e, u32 f);
void func_ov000_021afaac(u8 *a, u32 b, void *c, u32 d, u32 e, u16 f);
void func_ov000_021afb58(u8 *a, u32 b, u32 c);
u8 *func_ov000_021afc20(u32 a);
void func_ov000_021afc5c(u32 a);
u8 *func_ov000_021afd00(u32 a);
void func_ov000_021afd8c(void);
u8 *func_ov000_021afdcc(u32 *a);
void func_ov000_021afe5c(void *a, void *b, void *c, u16 d);
void func_ov000_021afe84(const void *a, const void *b, u8 *c, u32 d, void *e, u32 f);
void func_ov000_021affcc(u8 *a, u32 b, const void *c, u32 d);
BOOL func_ov000_021b0014(const u16 *first, const u16 *second);
BOOL func_ov000_021b003c(u32 address);
BOOL func_ov000_021b0094(u32 address);
s32 func_ov000_021b00b0(u32 address);
u32 func_ov000_021b00e0(u32 address);
BOOL func_ov000_021b00fc(u32 address);
BOOL func_ov000_021b0138(const void *buffer, u32 length, const Unk021b0138 *header, u32 sum);
u16 func_ov000_021b0188(const void *buffer, u32 length);
u16 func_ov000_021b01a0(u16 sum);
u32 func_ov000_021b01b4(const void *buffer, u32 length, u32 sum);
void func_ov000_021b0240(s32 a);
void func_ov000_021b026c(void);
void func_ov000_021b02b0(UnkFunc *arg0);
s32 func_ov000_021b02bc(void);
void func_ov000_021b02fc(Unk021b5fa8 *a);
s32 func_ov000_021b04cc(void);
void func_ov000_021b04d0(void);
void func_ov000_021b04d4(void);
void func_ov000_021b04f8(u32 a);
