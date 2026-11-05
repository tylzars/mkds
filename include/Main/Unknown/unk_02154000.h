#pragma once

#include "types.h"

typedef struct Kart Kart;

// Objects whose layout isn't known yet.
extern const u8 data_usa_0215470c[];
extern void *data_0215472c[];
extern u8 data_02154768[];
extern const u8 data_usa_02154064[];
extern const u8 data_02154788[];
extern const u32 data_usa_02154ff8[];
extern const u32 data_usa_021540c0[];
extern const u32 data_usa_021540c8[];
extern const u32 data_usa_021540d4[];
extern const u32 data_usa_02154108[];
extern const u16 data_02154970[8];
extern const u16 data_02154980[8];
extern u8 data_usa_021547c8[];
extern u8 data_usa_02154868[];
extern u8 data_021547f0[];
extern u8 data_02154818[];
extern const Vec3 data_02154f70;
extern u8 data_02154904[];
// The 16 scene functions, indexed by scene number; the names are in gSceneNames
// (data_usa_021541a8).
extern u32 gSceneFuncs[];
extern const Vec3 data_02154f94;
extern const s16 data_usa_02154a48[];
extern const s32 data_02154b64[8];
extern const s32 data_02154b84[8];
extern const s32 data_02154ba4[8];
extern const s32 data_02154be4[15];
extern const s32 data_02154c20[15];
extern const s32 data_02154c5c[15];
extern const s32 data_02154c98[15];
extern const s32 data_02154cd4[15];
extern const s32 data_02154d10[15];
extern const Vec3 data_02154f7c;
extern const Vec3 data_02154f88;
extern u32 data_02154128[][4];
extern u32 data_usa_021545d8[];
extern u32 data_usa_02154604[];
extern u32 data_usa_02154648[];
extern u32 data_usa_02154694[];
extern u16 data_usa_02154708;
extern const s32 data_usa_02154de4[25];
extern const s32 data_usa_02154e48[25];
extern const s32 data_usa_02154eac[25];
extern Vec3 data_usa_02154fc4;
extern Vec3 data_usa_02154fdc;
extern const s32 data_usa_02154fa0[][3];
extern const s32 data_usa_02154fa4[][3];
extern const s32 data_usa_02154fa8[][3];
extern const Vec3 data_usa_02154fb8;
extern const Vec3 data_usa_02154fd0;

extern u16 data_021540ec[];
extern const Vec4 data_usa_02154f14;
extern const Vec4 data_usa_02154f24;
extern const Vec4 data_usa_02154f34;
extern const Vec4 data_usa_02154f44;
extern const Vec4 data_usa_02154f54;
extern const Vec3 data_usa_02154f64;
extern const s32 data_usa_02154d4c[][2];
extern const s32 data_usa_02154d50[][2];
extern int (*const data_usa_02154d8c[])(Kart *);
