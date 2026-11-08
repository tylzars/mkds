#pragma once

#include "types.h"
#include "code_02012b30.h" // MtxFx43

// 0x24-byte entry: the word at 0x00 and the halfword at 0x08 are tested by DrawKartNameTagTexture and
// UploadTextureAndPalette, the words at 0x1c and 0x20 are passed to the function given to DrawKartNameTagTexture.
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
typedef struct KartNameTagTexPlttEntries {
    /* 00 */ TexPlttEntry mEntries[4];
} KartNameTagTexPlttEntries;

// The name tag over a kart in a race: emblem, entry name and a line down to the kart.
typedef struct KartNameTag {
    /* 00 */ Vec3 mPos;
    /* 0c */ u16 mKartIndex;
    /* 0e */ u8 mUnk_0e[2];
    /* 10 */ BOOL mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ BOOL mFadeStopped;
    /* 1c */ KartNameTagTexPlttEntries *mTexPlttEntries;
    /* 20 */ s16 mFadeLevelPerCall;
    /* 22 */ s16 mFadeLevel;
    /* 24 */ s16 mAlpha;
    /* 26 */ u16 mKartPaletteColor;
} KartNameTag;

void DrawKartNameTagTexture(TexPlttEntry *texPlttEntry, KartNameTag *kartObject, MtxFx43 *viewMatrix, s32 scaleX,
                            s32 scaleY, s16 alpha, s32 screenX, s32 screenY, s32 xOffset, s32 yOffset,
                            UnkFunc *drawVertices);

u16 *GetKartIndicesByDistance(void);
u16 func_0208606c(int index);
u32 GetKartCameraDistanceSquared(int kartIndex);
void DrawKartNameTags(MtxFx43 *viewMatrix);
void func_020865ec(void);
void func_020866b4(void);
void func_0208677c(void);
void func_02086a04(void);
