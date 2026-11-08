#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject
#include "Main/Unknown/code_020e005c.h"
#include "Main/Unknown/code_0206bcb0.h" // Kart
#include "Main/Unknown/code_0210b000.h" // SoundDistanceSquaredChange
#include "code_02012b30.h"

// Block of ten words.
typedef struct Unk020e0340 {
    /* 00 */ u32 mUnk_00[10];
} Unk020e0340;

extern const Unk020e0340 data_02158a54;

// Block of sixteen words.
typedef struct Unk020e03f8 {
    /* 00 */ u32 mUnk_00[16];
} Unk020e03f8;

extern const Unk020e03f8 data_02158a7c;
extern const Unk020e03f8 data_02158abc;
extern const Unk020e03f8 data_02158afc;
extern const Unk020e03f8 data_02158b3c;

// Three vectors of twelve bytes each.
typedef struct Unk020e38a0_28 {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ Vec3 mUnk_0c;
    /* 18 */ Vec3 mUnk_18;
} Unk020e38a0_28;

// Object func_020e0bac and func_020e0764 compare against: seven words and a vector.
typedef struct Unk020e0764 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ Vec3 mUnk_1c;
} Unk020e0764;

// Object with a vector at 0x2c and words at 0x38 and 0x3c.
typedef struct Unk020e20a8 {
    /* 000 */ u8 mUnk_000[0x2c];
    /* 02c */ Vec3 mUnk_02c;
    /* 038 */ BOOL mUnk_038;
    /* 03c */ BOOL mUnk_03c;
} Unk020e20a8;

// Object with vectors at 0x50 and 0x80.
typedef struct Unk020e246c {
    /* 000 */ u8 mUnk_000[0x50];
    /* 050 */ Vec3 mUnk_050;
    /* 05c */ s32 mUnk_05c;
    /* 060 */ u8 mUnk_060[0x4];
    /* 064 */ s32 mUnk_064;
    /* 068 */ u8 mUnk_068[0xc];
    /* 074 */ u16 mUnk_074;
    /* 076 */ u8 mUnk_076[0xa];
    /* 080 */ Vec3 mUnk_080;
    /* 08c */ u8 mUnk_08c[0x18];
    /* 0a4 */ s32 mUnk_0a4;
    /* 0a8 */ u8 mUnk_0a8[0x4];
    /* 0ac */ s32 mUnk_0ac;
} Unk020e246c;

// Object behind gCarA, gTruckA, gBusA and gCarTire.
typedef struct Unk0217b7a0 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ NNSG3dResMdl *mUnk_04;
} Unk0217b7a0;

// Object a pointer at 0x12c of Unk020e1e98 points to (also behind gBridgeNsbca).
typedef struct Unk020e1e98_12c {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ s32 mUnk_0c;
    /* 10 */ u8 mUnk_10[0xa];
    /* 1a */ u16 mUnk_1a;
    /* 1c */ s32 **mUnk_1c;
} Unk020e1e98_12c;

// Object a pointer at 0x154 of Unk020e1e98 points to.
typedef struct Unk020e1e98_154 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ u32 *mUnk_20;
    /* 24 */ u32 *mUnk_24;
    /* 28 */ Unk020e1e98_12c **mUnk_28;
    /* 2c */ s32 mUnk_2c;
    /* 30 */ s32 mUnk_30;
} Unk020e1e98_154;

// Four words at 0xb4 of Unk020e1e98.
typedef struct Unk020e1e98_0b4 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u8 mUnk_06[0x2];
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
} Unk020e1e98_0b4;

// 0x164 bytes.
typedef struct Unk020e1e98 {
    /* 000 */ MapObject mUnk_000;
    /* 0a0 */ s32 mUnk_0a0;
    /* 0a4 */ s32 mUnk_0a4;
    /* 0a8 */ s32 mUnk_0a8;
    /* 0ac */ s32 mUnk_0ac;
    /* 0b0 */ s32 mUnk_0b0;
    /* 0b4 */ Unk020e1e98_0b4 mUnk_0b4;
    /* 0c4 */ s32 mUnk_0c4;
    /* 0c8 */ s32 mUnk_0c8;
    /* 0cc */ s32 mUnk_0cc;
    /* 0d0 */ u8 mUnk_0d0[0x4];
    /* 0d4 */ s32 mUnk_0d4;
    /* 0d8 */ Unk020e0144 mUnk_0d8;
    /* 0fc */ u16 mUnk_0fc;
    /* 0fe */ s16 mUnk_0fe;
    /* 100 */ s32 mUnk_100[3];
    /* 10c */ u16 mUnk_10c;
    /* 10e */ u8 mUnk_10e[0x2];
    /* 110 */ s32 mUnk_110;
    /* 114 */ Vec3 mUnk_114;
    /* 120 */ s32 mUnk_120;
    /* 124 */ u32 mUnk_124;
    /* 128 */ u32 mUnk_128;
    /* 12c */ Unk020e1e98_12c *mUnk_12c;
    /* 130 */ u16 mUnk_130;
    /* 132 */ u16 mUnk_132;
    /* 134 */ u8 mUnk_134[0xc];
    /* 140 */ void *mUnk_140;
    /* 144 */ Vec3 mUnk_144;
    /* 150 */ u16 mUnk_150;
    /* 152 */ u16 mUnk_152;
    /* 154 */ Unk020e1e98_154 *mUnk_154;
    /* 158 */ SoundDistanceSquaredChange *mUnk_158;
    /* 15c */ u32 mUnk_15c;
    /* 160 */ u32 mUnk_160;
} Unk020e1e98;

// Object behind data_0217b79c and the argument of func_020e230c.
typedef struct Unk0217b79c {
    /* 00 */ Unk020e1e98 **mUnk_00;
    /* 04 */ u16 mUnk_04;
} Unk0217b79c;

// Object func_020e3ef4 fills.
typedef struct Unk020e3ef4 {
    /* 000 */ MapObject mUnk_000;
    /* 0a0 */ Unk020e38a0_28 mUnk_0a0;
    /* 0c4 */ Unk020e38a0_28 mUnk_0c4;
    /* 0e8 */ Vec3 mUnk_0e8;
    /* 0f4 */ Vec3 mUnk_0f4;
    /* 100 */ s32 mUnk_100;
    /* 104 */ s32 mUnk_104;
    /* 108 */ u8 mUnk_108[0x8];
    /* 110 */ BOOL mUnk_110;
    /* 114 */ Vec3 mUnk_114;
    /* 120 */ s32 mUnk_120;
    /* 124 */ Vec3 mUnk_124;
    /* 130 */ s32 mUnk_130;
    /* 134 */ s32 mUnk_134;
    /* 138 */ s32 mUnk_138;
    /* 13c */ u8 mUnk_13c[0x4];
    /* 140 */ struct Unk020ea670 *mModel;
    /* 144 */ u16 mUnk_144;
    /* 146 */ u16 mUnk_146;
    /* 148 */ u16 mUnk_148;
    /* 14a */ s16 mUnk_14a;
    /* 14c */ s32 mUnk_14c;
    /* 150 */ s32 mUnk_150;
    /* 154 */ s32 mUnk_154;
    /* 158 */ s32 mUnk_158;
    /* 15c */ s32 mUnk_15c;
} Unk020e3ef4;

// Object behind data_0217b7c4.
typedef struct Unk020e1dc0 {
    /* 00 */ Unk020e3ef4 **mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u8 mUnk_06[0x26];
    /* 2c */ s32 mUnk_2c;
} Unk020e1dc0;

void InitChoropu(Unk020e1e98 *a, struct CourseMapRow *b);
void *CreateCarAKindData(void);
void *CreateTruckAKindData(void);
void *CreateBusAKindData(void);
void *func_020e2db8(void);
void *func_020e2d5c(void);
void func_020e2ccc(Unk020e20a8 *a);
void func_020e2a74(Unk020e20a8 *a, Unk020e1e98 *b, u32 c, u32 d);
void func_020e2630(u32 a, Unk020e1e98 *b);
void func_020e24d0(Unk020e1e98 *a, Vec3 *b);
u8 func_020e2494(Unk020e1e98 *a, Kart *b, u8 *c, u8 *d);
u8 func_020e246c(Unk020e1e98 *a, Unk020e246c *b, u8 *c, u8 *d);
void func_020e2400(Unk020e1e98 *a, Vec3 *b, s32 c, Vec3 *d);
void func_020e230c(Unk0217b79c *a);
void func_020e20a8(Unk020e20a8 *a);
void func_020e1f54(Unk020e1e98 *a, struct CourseMapRow *b, Unk020e1e98_154 *c);
void func_020e1e98(Unk020e1e98 *a);
void func_020e1e38(Unk020e1dc0 *a, void *b, void (*c)(Unk020e3ef4 *, void *, u32));
void func_020e1dec(Unk020e3ef4 *a, void *b, u32 c);
void SetMapObjectsModel(Unk020e1dc0 *a, void *b);
s32 func_020e1d10(Unk020e005c *a, Vec3 *b, s32 c, u16 d, Unk020e0764 *e, Unk020e0764 *f, Vec3 *g, u16 *h, Vec3 *i,
                  u16 *j);
void func_020e1a80(s32 a, s32 b, s32 c, u32 d, u16 e, u16 *f, s32 v, Unk020e005c *w, Vec3 *g, Vec3 *h, Unk020e0764 *i,
                   Unk020e0764 *j, Vec3 *k, Vec3 *l, u16 *m);
BOOL func_020e16dc(s32 a, s32 b, s32 c, u32 d, u16 e, u16 f, u16 *g, u16 h, s32 i, s32 j, Unk020e005c *w, Vec3 *l,
                   Vec3 *m, Vec3 *n, Unk020e0764 *o, Unk020e0764 *p, Vec3 *q, Vec3 *r, u16 *s);
BOOL func_020e0bac(Unk020e005c *a, Vec3 *b, s32 c, u16 d, Unk020e0764 *o, Unk020e0764 *p, Vec3 *q, u16 *g, Vec3 *r,
                   u16 *s);
BOOL func_020e0764(Unk020e005c *a, Vec3 *b, s32 c, u16 d, Unk020e0764 *o, Unk020e0764 *p, Vec3 *q, u16 *g, Vec3 *r,
                   u16 *s);
void func_020e0680(Unk020e005c *a, Vec3 *b, Vec3 *c, Vec3 *d, u16 *e);
