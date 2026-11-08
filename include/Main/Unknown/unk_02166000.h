#pragma once

#include "types.h"
#include "Main/Unknown/unk_02165000.h" // Unk02165ff0
#include "Main/Unknown/code_020846c0.h" // ResFileEntry
#include "Main/Unknown/code_0210b000.h" // Unk0210b7a8

struct ModelEffect;

// One row of gModelEffectKinds: object count, which animation objects to make, start and update functions, size.
typedef struct ModelEffectKind {
    /* 00 */ u16 mObjectCount;
    /* 04 */ BOOL mUseNsbca;
    /* 08 */ BOOL mUseNsbma;
    /* 0c */ s32 mUseNsbta;
    /* 10 */ void (*mStart)(struct ModelEffect *, s32);
    /* 14 */ void (*mUpdate)(struct ModelEffect *);
    /* 18 */ u32 mObjectSize;
    /* 1c */ ResFileEntry mResFileEntry;
} ModelEffectKind;

extern ModelEffectKind gModelEffectKinds[5];
extern ModelEffectKind data_021661b8;
extern ModelEffectKind data_021661e4;
extern ModelEffectKind data_02166210;
extern ModelEffectKind data_0216623c;
extern const char data_02166268[];
extern const char data_02166280[];
extern const char gBombcoreNsbmdName[];
extern const char gBombcoreNsbcaName[];
extern const char gBombcoreNsbmaName[];
extern const char gBombcoreNsbtaName[];
extern const char gBombcore2NsbmdName[];
extern const char gBombcore2NsbcaName[];
extern const char gBombcore2NsbmaName[];
extern const char gBombcore2NsbtaName[];
extern const char data_021663a8[];
extern const char data_021663c0[];

extern u8 gPosStripFirstPolygonId;
extern u8 data_021663dc;
extern u16 gPosStripMaxAgeFrames;
extern u16 gPosStripPointsPerStrip;
extern s32 gPosStripDrawEnabled;
extern s32 (*gSetPosStripPointFunction)();
extern s32 gPosStripHeightDecreasePerFrame;
// Object at gPosStripTexture.
typedef struct PosStripTexture {
    /* 00 */ u32 mTexImageParam;
    /* 04 */ u8 mUnk_04[0x14];
    /* 18 */ u32 mPlttBase;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
} PosStripTexture;

extern PosStripTexture gPosStripTexture;
extern s32 data_02166418[][2];
extern s32 data_0216641c[][2];
extern s32 data_02166480[];
extern const char data_02166514[];
extern const char data_02166530[];
extern Unk02165ff0 data_0216600c;
extern Unk02165ff0 data_02166028;

extern const char gBasabasaNsbmdName[];
extern const char gBasabasaNsbtpName[];
extern const char gCowNsbmdName[];
extern const char gCowNsbtpName[];
extern const char gTeresaNsbmdName[];
extern const char gTeresaNsbtpName[];
extern const char gKanoke64NsbmdName[];
extern const char gKanoke64NsbcaName[];
extern const char gMkdEfBurnerNsbmdName[];
extern const char gMkdEfBurnerNsbtaName[];
extern const char gNsKiller2NsbmdName[];
extern const char gNsKiller2SNsbmdName[];
extern Unk0210b7a8 data_0216676c;
extern const char gNsKiller1NsbmdName[];
extern const char gBakubakuNsbmdName[];
extern const char gBakuShadowNsbmdName[];
extern const char gMoveTreeNsbmdName[];
extern const char gMoveTreeNsbcaName[];
extern char gStaffGhostTimeBinName[];
extern char gSmanBottomNsbmdName[];
extern char gSmanTopNsbmdName[];
extern char gFlipperNsbmdName[];
extern char gFlipperNsbtpName[];
extern char gFlipperNsbtaName[];
