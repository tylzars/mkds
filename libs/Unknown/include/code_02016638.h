#pragma once

#include "types.h"

// 16 bytes: an index into data_02152c54 and three words passed to the function it selects.
typedef struct CallQueueEntry {
    /* 00 */ u32 mFuncIndex;
    /* 04 */ const void *mSource;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mSize;
} CallQueueEntry;

typedef struct CallQueueEntry CallQueueEntry;

// Object at data_02173220: a pointer to an array of CallQueueEntry, its length at 04, two indices at 08 and 0a that
// CallQueueNextIndex advances modulo the length, and a count at 0c (CallQueueIsFull compares it with the length,
// CallQueueIsEmpty tests it for zero).
typedef struct CallQueue {
    /* 00 */ CallQueueEntry *mEntries;
    /* 04 */ u32 mCapacity;
    /* 08 */ u16 mHeadIndex;
    /* 0a */ u16 mTailIndex;
    /* 0c */ u16 mCount;
    /* 10 */ u32 mQueuedSize;
} CallQueue;

void CallQueueRunEntry(CallQueueEntry *p);
void DoTransfer2dObjCharSub(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dObjOamSub(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBGExtPlttSub(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dObjExtPlttSub(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBGPlttSub(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dObjPlttSub(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBG3BmpSub(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBG2BmpSub(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBG3ScrSub(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBG2ScrSub(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBG1ScrSub(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBG0ScrSub(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBG3CharSub(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBG2CharSub(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBG1CharSub(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBG0CharSub(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dObjCharMain(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dObjOamMain(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBGExtPlttMain(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dObjExtPlttMain(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBGPlttMain(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dObjPlttMain(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBG3BmpMain(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBG2BmpMain(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBG3ScrMain(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBG2ScrMain(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBG1ScrMain(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBG0ScrMain(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBG3CharMain(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBG2CharMain(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBG1CharMain(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBG0CharMain(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer3dClearImageDepth(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer3dClearImageColor(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer3dTexPltt(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer3dTex(const void *pSrc, u32 offset, u32 szByte);
s32 CallQueueIsEmpty(CallQueue *p);
s32 CallQueueIsFull(CallQueue *p);
u16 CallQueueNextIndex(CallQueue *p, u32 v);
