#include "code_0201750c.h"

void ListInit(LinkedList *arg0, u16 arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2;
    value2 = 0u;
    *(u32 *) ((value0) + (0)) = value2;
    *(u32 *) ((value0) + (4)) = value2;
    arg0->mCount = (u16) value2;
    arg0->mLinkOffset = (u16) value1;
}

void ListAppendToEmpty(LinkedList *arg0, u32 arg1) {
    u32 value1 = arg1;
    u32 value2;
    u32 value3;
    u32 value12;
    value3 = (u32) arg0->mLinkOffset;
    value2 = 0u;
    value12 = (value1) + (value3);
    *(u32 *) ((value12) + (4)) = value2;
    *(u32 *) ((value1) + (value3)) = value2;
    arg0->mHead = (void *) value1;
    arg0->mTail = (void *) value1;
    value1 = (u32) arg0->mCount;
    value1 = (value1) + (1u);
    arg0->mCount = (u16) value1;
}
