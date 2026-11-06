#pragma once

#include "types.h"

// Four bytes: two column bounds, then two row bounds (inclusive).
typedef struct Unk0215d064 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
} Unk0215d064;

extern s16 data_0215d040[];
extern u8 data_0215d044[][2];
extern u16 data_0215d054[];
extern Unk0215d064 data_0215d064[];
extern Unk0215d064 data_0215d080[];
extern u8 gSelectChoisesNscrOrigins[][2];
extern Unk0215d064 gSelectChoisesTileRect;
extern Unk0215d064 gSelectChoisesHitRects[];
extern Unk0215d064 gSelectChoisesPaletteRects[];

// Objects whose layout isn't known yet.
extern const s16 gPairsByAngle[];
extern s16 data_0215d6b4[];

extern u16 data_0215d00c[];
extern u16 data_0215d014[];
extern u8 data_0215d024[];
extern u8 gBackScreenSNclrStarts[];
extern u8 gBackScreenMNclrStarts[];
extern u8 data_0215d038[];
extern u8 gBackScreenKindMIndices[];
extern u8 gBackScreenKindSIndices[];
extern s8 data_0215d0c0[];
extern s8 data_0215d0cc[];
extern u8 data_0215d0d8[];
extern u8 data_0215d0dc[][1];
extern u8 data_0215d0e0[];
extern u8 data_0215d0e4[][2];
extern s8 data_0215d0b4[];
extern u8 data_0215d0e8[];
extern u8 data_0215d0f0[];
extern u8 data_0215d0f8[][4];
extern s16 data_0215d100[2][2];
extern s16 data_0215d108[2][2];
extern u8 data_0215d110[];
extern u8 data_0215d11c[];
extern u8 data_0215d122[];
extern u8 data_0215d128[2][2][3];
extern u8 data_0215d134[][12];
extern u8 data_0215d14c[][12];
extern u8 data_0215d164[];
extern u8 data_0215d168[];
extern u8 data_0215d170[][4];
extern const s16 data_usa_0215d8b4[];
