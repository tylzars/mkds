#pragma once

#include "types.h"

typedef struct PointerStack PointerStack;

typedef struct ObjCharRange {
    /* 00 */ struct ObjCharRange *mPrev;
    /* 04 */ struct ObjCharRange *mNext;
    /* 08 */ u16 mStart;
    /* 0a */ u16 mLength;
} ObjCharRange;

typedef struct ObjCharRanges {
    /* 000 */ u8 mRanges[0x180];
    /* 180 */ ObjCharRange mListStart;
    /* 18c */ ObjCharRange mListEnd;
    /* 198 */ void *mList;
    /* 19c */ PointerStack *mFreeRanges;
} ObjCharRanges;

typedef struct OamBuffers {
    /* 000 */ u8 mBuffers[2][0x400];
    /* 800 */ PointerStack *mFreeEntries[2];
    /* 808 */ u32 mUploadTask;
} OamBuffers;

void UploadOamBuffers(void);
void InitOamBuffers(void);
void DeleteObjCharRange(u32 range);
ObjCharRange *CreateObjCharRange(u32 screen, s32 charCount, s32 fromFront, u32 *outStart);
void InitObjCharRanges(void);
