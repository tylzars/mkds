#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036820.h"

// The start of MapObjectList; the three creators below fill in mInit, mForEachObject and mBeforeObjects.
typedef struct Unk0209bef0 {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ void *mInit;
    /* 0c */ void *mBeforeObjects;
    /* 10 */ void *mForEachObject;
    /* 14 */ u32 mAfterObjects;
    /* 18 */ u32 mUnk_18;
} Unk0209bef0;

#pragma thumb on
void *CreateMapObjectUpdateList(void *arg0, void *arg1, void *arg2) {
    Unk0209bef0 *p = HeapAlloc(GetHeap(func_020364e8()), 40);
    p->mInit = arg0;
    p->mBeforeObjects = arg2;
    p->mForEachObject = arg1;
    p->mAfterObjects = 0;
    return p;
}
#pragma thumb off

#pragma thumb on
// The 1 in the name is the value stored at +0x18, not a slot of the kind row.
void *CreateMapObjectDrawList1(void *arg0, void *arg1, void *arg2) {
    Unk0209bef0 *p = HeapAlloc(GetHeap(func_020364e8()), 44);
    p->mUnk_18 = 1;
    p->mInit = arg0;
    p->mBeforeObjects = arg2;
    p->mForEachObject = arg1;
    p->mAfterObjects = 0;
    return p;
}
#pragma thumb off

#pragma thumb on
void *CreateMapObjectDrawList2(void *arg0, void *arg1, void *arg2) {
    Unk0209bef0 *p = HeapAlloc(GetHeap(func_020364e8()), 44);
    p->mUnk_18 = 2;
    p->mInit = arg0;
    p->mBeforeObjects = arg2;
    p->mForEachObject = arg1;
    p->mAfterObjects = 0;
    return p;
}
#pragma thumb off
