#pragma once

#include "types.h"
#include "code_0212d214.h"

// Object with an LinkedList at 0x0c, initialised with link offset 4; mRangeStart and mRangeEnd bound the range
// HeapFindInnermostInList tests an address against.
typedef struct Unk02017584 {
    /* 00 */ u32 mTag;
    /* 04 */ u8 mUnk_04[8];
    /* 0c */ LinkedList mUnk_0c;
    /* 18 */ u32 mRangeStart;
    /* 1c */ u32 mRangeEnd;
    /* 20 */ u32 mUnk_20;
} Unk02017584;

extern u32 gHeapListInitialized;
extern LinkedList gHeapList;

void *HeapFindInnermost(void *a);
void HeapUnlink(Unk02017584 *a);
void HeapInitAndLink(Unk02017584 *a, u32 b, u32 c, u32 d, u16 e);
LinkedList *HeapFindList(u32 a);
Unk02017584 *HeapFindInnermostInList(LinkedList *a, u32 b);
