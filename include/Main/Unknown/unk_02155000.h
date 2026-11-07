#pragma once

#include "types.h"

// Objects whose layout isn't known yet.
extern const u32 data_usa_02155018[];
extern u32 data_02155048[];
extern u32 data_02155098[];
extern u32 data_021550a8[];
extern const u32 data_usa_02155068[];
extern const Vec3 data_usa_02155188;
struct Vec4;
extern const struct Vec4 data_usa_02155194;
extern void (*data_02155a20[])(void *param_1);
extern const u16 data_02155a64[];
extern const u16 data_02155a28[];
extern const u16 data_02155a2c[];
extern const Vec3 data_02155ccc;
extern const u16 data_02155ed0[];
extern const Vec3 data_021557ec;
extern s32 data_02155854[];
struct Unk0201ca6c;
struct Kart;

// An effect id and its step function.
typedef struct OtherKartEffectKind {
    /* 00 */ s32 mEffectId;
    /* 04 */ void (*mAdvance)(struct Unk0201ca6c *p, s32 a);
} OtherKartEffectKind;

extern OtherKartEffectKind gOtherKartEffectKinds[3];
extern Vec3 data_02155a08;
extern u32 gKartBoostCameraEffectIds[];
extern s32 gKartSideOffsetsX[];
extern Vec3 gKartSideDirectionVectors[];
extern void (*gKartSurfaceEffectFunctions[])(struct Kart *p);
extern Vec3 data_02155a14;
extern Vec3 data_02155a48;
extern Vec3 gVec3UnitY;
extern Vec3 data_02155ebc;

// 12-byte entries; BuildEmblemNsbtxPath reads the string pointer at 0x00.
typedef struct Unk02155cf4 {
    /* 00 */ const char *mUnk_00;
    /* 04 */ u8 mUnk_04[8];
} Unk02155cf4;

extern const Unk02155cf4 gCharacterEmblemNames[];
extern const Unk02155cf4 gCharacterPNames[];
extern const Unk02155cf4 gCharacterENames[];

// 8-byte entries; BuildKartShadowNsbmdPath and BuildKartNsbtxPath read the string pointer at 0x00.
typedef struct Unk02155d88 {
    /* 00 */ const char *mUnk_00;
    /* 04 */ u8 mUnk_04[4];
} Unk02155d88;

extern const Unk02155d88 gKartNames[];
extern const Unk02155d88 gKartShadowNames[];

// 12-byte entry: four bytes and two string pointers.
typedef struct Unk02155ee8 {
    /* 00 */ u8 mNsbmdCount;
    /* 01 */ u8 mNsbcaCount;
    /* 02 */ u8 mNsbmaCount;
    // The nsbtp files are loaded only when mNsbmdCount is 1 and this is above 1.
    /* 03 */ u8 mNsbtpCount;
    /* 04 */ const char *mStems[2];
} Unk02155ee8;

extern const Unk02155ee8 gCountStartStems[3];
extern const Unk02155ee8 gGoalStems;
extern const Unk02155ee8 gWinStems;
extern const Unk02155ee8 gLoseStems;
extern const Unk02155ee8 gCompleteStems;
extern const Unk02155ee8 gFailedStems;
extern Vec3 data_02155a3c;
extern const u32 data_02155a54;
extern const u16 data_02155a74[12];
extern const Vec3 data_usa_021557c4;
extern const Vec3 data_usa_021557d0;
extern const s32 data_usa_021556e4[];
extern const s32 data_usa_02155708[];
extern const s32 data_usa_0215572c[];
extern const s32 data_usa_02155750[];
extern const s32 data_usa_02155774[];
extern const s32 data_usa_02155798[];
extern const s32 data_usa_021557bc;
extern const s32 data_usa_021557c0;
extern const s32 data_usa_021557dc[];
extern const s32 data_usa_021551a4[];
// 12-byte entries from data_usa_021551b0 (a string pointer at 0x00); the second table starts at the word at 0x04 of the
// first entry.
typedef struct Unk021551b0 {
    /* 00 */ const char *mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
} Unk021551b0;
typedef struct Unk021551b4 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u8 mUnk_04[8];
} Unk021551b4;
extern const Unk021551b0 data_usa_021551b0[];
extern const Unk021551b4 data_usa_021551b4[];
extern const s32 data_usa_021551dc[];
extern const s32 data_usa_0215560c[];
extern const s32 data_usa_02155630[];
extern const s32 data_usa_02155654[];
extern const s32 data_usa_02155678[];
extern const s32 data_usa_0215569c[];
extern const s32 data_usa_021556c0[];
