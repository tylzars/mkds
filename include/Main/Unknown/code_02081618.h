#pragma once

#include "types.h"

struct Unk0201ca6c;

typedef struct Unk02081e3c {
    /* 00 */ u8 mUnk_00[0x90];
    /* 90 */ void (*mUnk_90)(struct Unk0201ca6c *p, s32 a);
    /* 94 */ u8 mUnk_94[0x5];
    /* 99 */ u8 mUnk_99;
    /* 9a */ u8 mUnk_9a;
    /* 9b */ u8 mUnk_9b;
} Unk02081e3c;

// Two halfwords.
typedef struct Unk02155888_00 {
    /* 00 */ s16 mUnk_00;
    /* 02 */ s16 mUnk_02;
} Unk02155888_00;

// Four pairs; rows of data_02155888 and the value of data_0217aea0.
typedef struct Unk02155888 {
    /* 00 */ Unk02155888_00 mUnk_00[4];
} Unk02155888;

#include "Main/Unknown/code_0206bcb0.h"

// Twelve bytes: a count and two values.
typedef struct Unk02155908_00 {
    /* 00 */ u16 mUnk_00;
    /* 04 */ s32 mUnk_04[2];
} Unk02155908_00;

// 0x20 bytes: two entries, a function and its argument.
typedef struct Unk02155908 {
    /* 00 */ Unk02155908_00 mUnk_00[2];
    /* 18 */ s32 (*mUnk_18)(Unk02155908_00 *a, s32 b, Kart *p);
    /* 1c */ s32 mUnk_1c;
} Unk02155908;

#include "Main/Unknown/unk_0217a000.h"
#include "code_0201c528.h"

extern const Unk02155888 data_02155888[];
extern Unk02155908 data_02155908[];
extern Unk02155908 data_02155928;
extern Unk02155908 data_02155968;
extern Unk02155908 data_02155988;
extern Unk02155908 data_021559a8;
extern Unk02155908 data_021559c8;
extern Unk02155908 data_021559e8;
extern s32 data_02165934;
extern s32 data_02165938;
extern s32 data_02165940;
extern s32 data_02165954;
extern s32 data_02165958;
extern s32 data_0216595c;
extern s32 data_02165960;
extern s32 data_02165964;
extern s32 data_02165968;
extern s32 data_0216596c[];
extern Vec3 data_02165984;
extern Unk0201ca6c *data_0217ae78;
extern Unk0201ca6c *data_0217ae80;
extern Unk0201ca6c *data_0217ae88;
extern s32 data_0217ae9c;
extern Unk02155888 data_0217aea0;

void func_02081618(s32 a, Vec3 *b);
void func_02081724(s32 a);
void func_02081768(s32 a);
void func_020817b8(s32 a);
void func_0208181c(s32 a);
void func_02081a40(s32 a);
void func_02081ab8(Unk0201ca6c *p, s32 a);
void func_02081b30(Unk0201ca6c *p, s32 a);
void func_02081b64(Unk0201ca6c *p, Kart *q, s32 a, s32 b);
void func_02081ca0(Unk0201ca6c *p, Kart *q, void *a);
void func_02081d78(Unk0201ca6c *p, s32 a);
void func_02081e3c(Unk02081e3c *p0, unsigned int p1, unsigned int p2);
void func_02081e5c(Unk0201ca6c *p, s32 a);
void func_02081f10(Unk02081e3c *p0, unsigned int p1, unsigned int p2);
void func_02081f30(void);
void func_02082034(Unk0201ca6c *p, s32 a);
void func_020821cc(Unk0201ca6c *p, s32 a);
void func_02082368(Unk0201ca6c *p, s32 a);
void func_020824d0(Unk0201ca6c *p, s32 a);
void func_0208266c(Unk0201ca6c *p, s32 a);
void func_02082750(Unk0201ca6c *p, s32 a);
void func_02082a10(Unk0201ca6c *p, s32 a);
void func_02082aec(void);
void func_02082d64(Unk0201ca6c *p, s32 a);
void func_02082e4c(s32 a);
void func_02082f94(Unk0201ca6c *p, s32 a);
void func_02082fec(Unk0201ca6c *p, s32 a);
void func_020831bc(Unk0201ca6c *p, s32 a);
void func_0208335c(Unk0201ca6c *p, s32 a);
void func_02083484(Unk0201ca6c *p, s32 a);
void func_02083680(Unk0201ca6c *p, s32 a);
void func_02083834(Kart *p);
void func_020838dc(Kart *p);
void func_02083928(Kart *p, s32 a);
void func_020839d8(Kart *p);
BOOL func_02083a24(Unk02155908_00 *a, s32 b, Kart *p);
s32 func_02083ae0(Unk02155908_00 *a, s32 b, Kart *p);
s32 func_02083c18(Unk02155908_00 *a, s32 b, Kart *p);
BOOL func_02083d4c(Unk02155908_00 *a, s32 b, Kart *p);
void func_02083de8(s32 a, Kart *p);
void func_02083ec4(Kart *p);
void func_02083f6c(s32 a, Kart *p);
void func_02084034(u32 a, Kart *p);
void func_020840c0(Kart *p);
void func_02084114(Kart *p);
void func_0208419c(Kart *p);
void func_02084224(Kart *p);
void func_020842ac(Kart *p);
void func_02084334(Kart *p);
void func_02084384(Kart *p);
void func_020843d8(Kart *p);
void func_0208442c(Kart *p);
// Copies the position source of the Kart into the position of its matrix (Kart.mUnk_174), then computes mSidePositions
// and mSideDirections of the Kart from the model points 2 and 3 and the Kart matrix.
void ComputeKartSidePoints(Kart *p);
// Allocates the KartEffects records for a Karts and clears them.
void InitKartEffects(u32 a);
// Returns the KartEffects record of Kart number n.
KartEffects *GetKartEffects(int arg0);
