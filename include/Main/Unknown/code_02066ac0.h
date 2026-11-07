#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // Kart
#include "Main/Unknown/code_020653d0.h" // Unk020653d0

// Node of the list at 0x80 of a Unk0206bcb0_514: a halfword at 0x08 and an Unk020653d0 at 0x0c.
typedef struct Unk02066ac0 {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ s16 mUnk_08;
    /* 0a */ u8 mUnk_0a[2];
    /* 0c */ Unk020653d0 mUnk_0c;
} Unk02066ac0;

// Table of 0x5c-byte entries; the code writes the word at 0x00.
typedef struct Unk02175664 {
    /* 00 */ s32 mSourceKind;
    /* 04 */ u8 mUnk_04[0x58];
} Unk02175664;

typedef struct Unk02165518 {
    /* 00 */ u32 mUnk_00[3];
} Unk02165518;

extern const u32 data_02154a64[];
extern const u32 data_usa_02154a84[];
extern const u32 data_02154aa4[];
extern const u32 data_usa_02154ac4[];
extern const u32 data_usa_02154ae4[];
extern const u32 data_02154b04[];
extern const u32 data_usa_02154b24[];
extern const u32 data_02154b44[];
extern const u32 data_02154bc4[];
extern const u16 data_021654c8;
extern const s32 data_021654cc;
extern const s32 data_021654f8;
extern const s32 data_021654fc;
extern const Unk02165518 data_02165518;
extern const s32 data_0216559c[];
extern const s32 data_021655b0[];
extern Unk02175664 data_02175664[];

void func_02066ac0(Kart *a);
void AdvanceKartWobble(Kart *a);
void func_02066fe0(Kart *a);
void func_02067488(Kart *a);
// 1 when the turn start group, the level 3 group or the level 4 group (not while mLevel4StopRequested is TRUE) exists,
// else 0; the level 2 group is not counted.
u32 IsKartTurnEffectsActive(Kart *a);
// Surface kind 10 (entry 10 of gKartSurfaceFunctions): passes the entry that data_02154b04 gives for mSurfaceVariant to
// ApplyKartSurfaceEffect and returns surface group 0, for which RefreshKartSurface uses the factor 0x1000 instead of an
// entry of mSurfaceSpeedLimitFactors.
s32 ApplyKartSurfaceKind10(Kart *a);
// Surface kind 19 (entry 19 of gKartSurfaceFunctions): unless mSurfaceGroup is already 0xb and bit 0x80000000 of
// mUnk_44 is clear it runs StartKartBoost and, for the selected kart, calls StartSound with 0x1b9; otherwise it sets
// mUnk_238 to 0x3c. Then it sets bits 0x40000001 of mUnk_48, runs StopKartCurrentEffects and returns surface group 0xb.
s32 ApplyKartSurfaceKind19(Kart *a);
// Surface kind 17 (entry 17 of gKartSurfaceFunctions): passes the entry that data_02154aa4 gives for mSurfaceVariant to
// ApplyKartSurfaceEffect and returns surface group 0xa.
s32 ApplyKartSurfaceKind17(Kart *a);
// Surface kind 15 (entry 15 of gKartSurfaceFunctions): runs ApplyKartSurfaceEffect with 0; while bit 0x10000 of mUnk_48
// is clear it then runs PlaceKartAtKeyedPlacement with mSurfaceVariant when RaceSetup.mMode is MODE_BATTLE or
// MODE_MISSION_RUN, and in the other modes sets that bit and runs ResetKartMotionState with 0. Returns surface group 9.
s32 ApplyKartSurfaceKind15(Kart *a);
// Surface kind 18 (entry 18 of gKartSurfaceFunctions): the body of kind 7, followed by setting bit 0x400000 of mUnk_48;
// returns surface group 8.
s32 ApplyKartSurfaceKind18(Kart *a);
// Surface kind 12 (entry 12 of gKartSurfaceFunctions): sets bit 0x10000000 of mUnk_48, sets mVerticalSpeed from
// data_021655b0 and mUnk_4c4 from data_0216559c by mSurfaceVariant, runs StopKartCurrentEffects and returns surface
// group 8; on course 0xc or 0x28, when mSurfaceGroup was not already 8 or bit 0x80000000 of mUnk_44 is set, it first
// calls StartSound with 0x15e.
s32 ApplyKartSurfaceKind12(Kart *a);
// Surface kind 7 (entry 7 of gKartSurfaceFunctions): unless mSurfaceGroup is already 8 and bit 0x80000000 of mUnk_44 is
// clear it runs StartKartBoost and, for the selected kart with mSurfaceVariant above 0, calls StartSound with the id
// that data_02165518 gives for mSurfaceVariant minus 1; otherwise it sets mUnk_238 to 0x3c. Then it runs
// StopKartCurrentEffects and returns surface group 8.
s32 ApplyKartSurfaceKind7(Kart *a);
// Surface kind 6 (entry 6 of gKartSurfaceFunctions): passes the entry that data_02154a64 gives for mSurfaceVariant to
// ApplyKartSurfaceEffect and returns surface group 6.
s32 ApplyKartSurfaceKind6(Kart *a);
// Surface kind 5 (entry 5 of gKartSurfaceFunctions): runs func_0207a6c0, passes the entry that data_02154bc4 gives for
// mSurfaceVariant to ApplyKartSurfaceEffect and returns surface group 4.
s32 ApplyKartSurfaceKind5(Kart *a);
// Surface kind 3 (entry 3 of gKartSurfaceFunctions): runs func_0207a6c0, passes the entry that data_02154b44 gives for
// mSurfaceVariant to ApplyKartSurfaceEffect and returns surface group 3.
s32 ApplyKartSurfaceKind3(Kart *a);
// Surface kind 2 (entry 2 of gKartSurfaceFunctions): runs func_0207a6c0, passes the entry that data_usa_02154b24 gives
// for mSurfaceVariant to ApplyKartSurfaceEffect and returns surface group 2.
s32 ApplyKartSurfaceKind2(Kart *p);
// Surface kind 1 (entry 1 of gKartSurfaceFunctions): passes the entry that data_usa_02154ae4 gives for mSurfaceVariant
// to ApplyKartSurfaceEffect and returns surface group 5.
s32 ApplyKartSurfaceKind1(Kart *p);
// Surface kind 20 (entry 20 of gKartSurfaceFunctions): passes the entry that data_usa_02154ac4 gives for
// mSurfaceVariant to ApplyKartSurfaceEffect and returns surface group 0, for which RefreshKartSurface uses the factor
// 0x1000 instead of an entry of mSurfaceSpeedLimitFactors.
s32 ApplyKartSurfaceKind20(Kart *p);
s32 func_02067ad4(Kart *p);
// Collision response 11 of data_0217ac18 (indexed by the value func_020d6be0 returns for the kart and the map object):
// when func_0206a24c holds for the kart, mUnk_44c of the kart is not the object and the kart is the selected kart,
// increments the counter of the record GetEntryKartCounters returns. Stores 0 through the second parameter and returns
// 0.
s32 CollideKartWithMapObjectResponse11(Kart *a, s32 *b, s32 c);
// Collision response 14 of data_0217ac18 (indexed by the value func_020d6be0 returns for the kart and the map object):
// stores 0xc through the second parameter, clears bits of mUnk_48 with the mask 0xdfe77fdf, zeroes mUnk_238, the
// mUnk_00 member of mUnk_538 and mUnk_23c, for the selected kart calls ResetCameraHalfFovAngleGoal unless bit
// 0x10000000 of mUnk_4c or bit 0x4000000 of mUnk_48 is set and then runs func_02055c5c, then runs func_0206bcb0 with 1
// and, when that succeeds, func_02081224 with the kart index. Returns 5.
s32 CollideKartWithMapObjectResponse14(Kart *a, s32 *b);
// Collision response 13 of data_0217ac18 (indexed by the value func_020d6be0 returns for the kart and the map object):
// stores 0xc through the second parameter, clears bits of mUnk_48 with the mask 0xdfe77fdf, zeroes mUnk_238, the
// mUnk_00 member of mUnk_538 and mUnk_23c, for the selected kart calls ResetCameraHalfFovAngleGoal unless bit
// 0x10000000 of mUnk_4c or bit 0x4000000 of mUnk_48 is set and then runs func_02055c5c, and sets mForwardSpeed to 0.
// Returns 5.
s32 CollideKartWithMapObjectResponse13(Kart *a, s32 *b);
// Declared here until the code that defines them is decompiled.
