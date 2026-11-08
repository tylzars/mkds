#pragma once

#include "types.h"

typedef struct Kart Kart;

// Objects whose layout isn't known yet.
extern const u8 data_usa_0215470c[];
extern void *data_0215472c[];
extern u8 gGhostBlockInfo[];
extern const u8 gCupRankTable[];
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
extern const s32 gKartModelScaleYKind0Table[15];
extern const s32 gKartModelOffsetYKind0And2Table[15];
extern const s32 gKartModelScaleYKind1Table[15];
extern const s32 gKartModelOffsetYKind1Table[15];
extern const s32 gKartModelScaleXKind2Table[15];
extern const s32 gKartModelScaleZKind2Table[15];
extern const Vec3 data_02154f7c;
extern const Vec3 data_02154f88;
extern u32 gCupCourseIdTable[][4];
extern u32 data_usa_021545d8[];
extern u32 data_usa_02154604[];
extern u32 data_usa_02154648[];
extern u32 data_usa_02154694[];
extern u16 gCrcXorValue;
extern const s32 gKartScaleFactorXTable[25];
extern const s32 gKartScaleFactorYTable[25];
extern const s32 gKartScaleFactorZTable[25];
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
// 22 handlers indexed by mSurfaceKind: each plays the effect picked by mSurfaceVariant and returns the surface group
// (0, 2..6, 8..0xb). Bits 8..12 can reach 31 but the table ends at 21.
extern int (*const gKartSurfaceFunctions[])(Kart *);
