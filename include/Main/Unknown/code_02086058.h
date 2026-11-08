#pragma once

#include "types.h"
#include "code_02012b30.h" // MtxFx43

// 0x24-byte entry: the word at 0x00 and the halfword at 0x08 are tested by func_02086098 and UploadTextureAndPalette,
// the words at 0x1c and 0x20 are passed to the function given to func_02086098.
typedef struct TexPlttEntry {
    /* 00 */ u32 mUnk_00;
    /* 04 */ s32 mTexByteCount;
    /* 08 */ u16 mPlttByteCount;
    /* 0a */ u8 mUnk_0a[2];
    /* 0c */ void *mTexData;
    /* 10 */ void *mPlttData;
    /* 14 */ u8 mUnk_14[4];
    /* 18 */ u32 mPlttOffset;
    /* 1c */ s32 mTexWidthFixed;
    /* 20 */ s32 mTexHeightFixed;
} TexPlttEntry;

// Four entries.
typedef struct Unk02086250_1c {
    /* 00 */ TexPlttEntry mUnk_00[4];
} Unk02086250_1c;

// Object in the tables of data_0217aed0.
typedef struct Unk02086250 {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ u16 mKartIndex;
    /* 0e */ u8 mUnk_0e[2];
    /* 10 */ BOOL mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ BOOL mUnk_18;
    /* 1c */ Unk02086250_1c *mUnk_1c;
    /* 20 */ s16 mFadeLevelPerCall;
    /* 22 */ s16 mFadeLevel;
    /* 24 */ s16 mAlpha;
    /* 26 */ u16 mKartPaletteColor;
} Unk02086250;

void func_02086098(TexPlttEntry *texPlttEntry, Unk02086250 *kartObject, MtxFx43 *viewMatrix, s32 scaleX, s32 scaleY,
                   s16 alpha, s32 screenX, s32 screenY, s32 xOffset, s32 yOffset, UnkFunc *drawVertices);

u16 *GetKartIndicesByDistance(void);
u16 func_0208606c(int index);
u32 GetKartCameraDistanceSquared(int kartIndex);
void func_02086250(MtxFx43 *viewMatrix);
void func_020865ec(void);
void func_020866b4(void);
void func_0208677c(void);
void func_02086a04(void);
