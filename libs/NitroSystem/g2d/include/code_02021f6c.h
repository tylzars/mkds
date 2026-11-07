#pragma once

#include "types.h"

typedef struct NNSG2dCharacterData {
    /* 00 */ u16 mH;
    /* 02 */ u16 mW;
    /* 04 */ u32 mPixelFmt;
    /* 08 */ u32 mMappingType;
    /* 0c */ u32 mCharacterFmt;
    /* 10 */ u32 mSzByte;
    /* 14 */ void *mRawData;
} NNSG2dCharacterData;

typedef struct NNSG2dPaletteData {
    /* 00 */ u32 mFmt;
    /* 04 */ s32 mExtendedPlt;
    /* 08 */ u32 mSzByte;
    /* 0c */ void *mRawData;
} NNSG2dPaletteData;

void NNS_G2dUnpackNCG(NNSG2dCharacterData *pCharData);
void NNS_G2dUnpackBGNCG(NNSG2dCharacterData *pCharData);
void NNS_G2dUnpackNCL(NNSG2dPaletteData *pPlttData);
