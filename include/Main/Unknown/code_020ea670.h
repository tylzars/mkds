#pragma once

#include "types.h"

typedef struct NNSG3dResMdl NNSG3dResMdl;
typedef struct Woodbox1 Woodbox1;

// First argument of func_020ea670, DrawNsbmd1Mat1ShpWithMaxAlpha, DrawNsbmdWithMaxAlpha and
// DrawNsbmdWithMatrixAndMaxAlpha.
typedef struct Unk020ea670 {
    /* 000 */ void *mUnk_000;
    /* 004 */ NNSG3dResMdl *mResMdl;
} Unk020ea670;

extern Unk020ea670 *gWoodbox1;

// First argument of DrawShadowWithMaxAlpha.
typedef struct Unk020ea868 {
    /* 000 */ u8 mUnk_000[0x6e];
    /* 06e */ u16 mUnk_06e;
} Unk020ea868;

// Second argument of InitWoodbox1, CollideItemObjectWithWoodbox1 and CollideKartWithWoodbox1.
typedef struct Unk020eb498 {
    /* 000 */ Vec3 mUnk_000;
    /* 00c */ u8 mUnk_00c[4];
    /* 010 */ s32 mUnk_010;
    /* 014 */ u8 mUnk_014[0x14];
    /* 028 */ s16 mUnk_028;
    /* 02a */ s16 mUnk_02a;
    /* 02c */ u8 mUnk_02c[0x30];
    /* 05c */ Vec3 mUnk_05c;
    /* 068 */ u8 mUnk_068[0xc];
    /* 074 */ u16 mUnk_074;
    /* 076 */ u8 mUnk_076[0x2e];
    /* 0a4 */ Vec3 mUnk_0a4;
    /* 0b0 */ u8 mUnk_0b0[0x1ec];
    /* 29c */ s32 mUnk_29c;
    /* 2a0 */ u8 mUnk_2a0[4];
    /* 2a4 */ s32 mUnk_2a4;
} Unk020eb498;

// Objects read by func_020ea670.
typedef struct Unk020ea670_08 {
    /* 000 */ u8 mUnk_000[8];
    /* 008 */ u32 mUnk_008;
} Unk020ea670_08;

typedef struct Unk020ea670_0a {
    /* 000 */ u8 mUnk_000[10];
    /* 00a */ u16 mUnk_00a;
} Unk020ea670_0a;

typedef struct Unk020ea670_0c {
    /* 000 */ u8 mUnk_000[12];
    /* 00c */ u32 mUnk_00c;
} Unk020ea670_0c;

// Sphere (centre param_1, radius param_7) against the cylinder at param_2 whose axes are the rows of param_3; returns 0
// for no hit, else 2, and writes the move out to param_8 unless it is NULL.
s32 ComputeSphereHitOnRotatedCylinder(Vec3 *param_1, Vec3 *param_2, Vec3 *param_3, s32 param_4, s32 param_5,
                                      s32 param_6, s32 param_7, Vec3 *param_8);
// Sphere (radius param_6) against the box at param_2 whose axes are the rows of param_3 and whose half sizes are
// param_4 and param_5; returns 0 for no hit, 1 when the y axis (positive side) has the least overlap, else 3 (x axis)
// or 4 (z axis), and writes the move out to param_7 unless it is NULL.
s32 ComputeSphereHitOnRotatedBox(Vec3 *param_1, Vec3 *param_2, Vec3 *param_3, Vec3 *param_4, Vec3 *param_5, s32 param_6,
                                 Vec3 *param_7);
void CreateWoodbox1(void);

typedef struct Unk020ebeac {
    /* 00 */ u8 mUnk_00[0x2];
    /* 02 */ u16 mUnk_02;
} Unk020ebeac;

void func_020ea670(Unk020ea670 *param_1, s32 param_2);
// Draws the model with its alpha capped at param_2 (put back afterwards), through NNS_G3dDraw1Mat1Shp.
void DrawNsbmd1Mat1ShpWithMaxAlpha(Unk020ea670 *param_1, s32 param_2);
// Draws the model with its alpha capped at param_2 (put back afterwards).
void DrawNsbmdWithMaxAlpha(Unk020ea670 *param_1, s32 param_2);
void func_020ea84c(void);
// Draws the shadow model with its value at 0x6e capped at param_4 (put back afterwards).
void DrawShadowWithMaxAlpha(Unk020ea868 *param_1, void *param_2, Vec3 *param_3, u32 param_4);
// Draws the model with the matrix param_2 and scale param_3, its alpha capped at param_4 (put back afterwards).
void DrawNsbmdWithMatrixAndMaxAlpha(Unk020ea670 *param_1, void *param_2, void *param_3, s32 param_4);
void func_020ea94c(Vec3 *param_1, Vec3 *param_2, s32 param_3, s32 param_4, s32 param_5, Vec3 *param_6);
// Splits the velocity param_1 along the direction param_2: the rest is scaled by param_3, the part along is reversed
// and scaled by param_4; the result goes to param_6.
void BounceVelocityOffSurface(Vec3 *param_1, Vec3 *param_2, s32 param_3, s32 param_4, s32 param_5, Vec3 *param_6);
void func_020eac20(Vec3 *param_1, s32 param_2);
void func_020eacc0(Vec3 *param_1, s32 param_2, Vec3 *param_3, Vec3 *param_4);
// Writes to param_5 the move that puts point param_1 out of the cylinder at param_2 (radius param_3 in x/z, half height
// param_4 in y); the move has y = 0.
void ComputeCylinderOverlapOffset(Vec3 *param_1, Vec3 *param_2, s32 param_3, s32 param_4, Vec3 *param_5);
// Writes to param_4 the move that puts point param_1 exactly param_3 away from param_2.
void ComputeSphereOverlapOffset(Vec3 *param_1, Vec3 *param_2, s32 param_3, Vec3 *param_4);
void InitWoodbox1(Woodbox1 *param_1, Unk020eb498 *param_2);
void ClearWoodbox1Pointer(void);
u32 CollideItemObjectWithWoodbox1(Woodbox1 *param_1, Unk020eb498 *param_2, u8 *param_3, u8 *param_4);
u32 CollideKartWithWoodbox1(Woodbox1 *param_1, Unk020eb498 *param_2, u8 *param_3, u8 *param_4);
void UpdateWoodbox1State3(Woodbox1 *param_1);
void UpdateWoodbox1State2(Woodbox1 *param_1);
void EnterWoodbox1State2(Woodbox1 *param_1);
// Landing test of the box: when it is below the ground and falling, lifts it, reverses and scales its fall speed and
// returns TRUE.
BOOL BounceWoodbox1OffGround(Woodbox1 *param_1);
void UpdateWoodbox1State1(Woodbox1 *param_1);
void EnterWoodbox1State1(Unk020ebeac *p0);
