#pragma once

#include "types.h"

// First word of compressed data: the low byte holds the type and parameter, the upper 24 bits the expanded size.
typedef struct MICompressionHeader {
    /* 00 */ u32 mCompParam : 4;
    /* 00 */ u32 mCompType : 4;
    /* 00 */ u32 mDestSize : 24;
} MICompressionHeader;

// State of an LZ expansion done in steps (MI_ReadUncompLZ8).
typedef struct MIUncompContextLZ {
    /* 00 */ u8 *mDestp;
    /* 04 */ s32 mDestCount;
    /* 08 */ u16 mDestTmp;
    /* 0a */ u8 mDestTmpCnt;
    /* 0b */ u8 mFlags;
    /* 0c */ u8 mFlagIndex;
    /* 0d */ u8 mLength;
    /* 0e */ u8 mLengthFlg;
    /* 0f */ u8 mPadding;
} MIUncompContextLZ;

void MI_InitUncompContextLZ(MIUncompContextLZ *context, u8 *dest, const MICompressionHeader *header);
