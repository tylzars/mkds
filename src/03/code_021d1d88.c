#include "03/code_021d1d88.h"
#include "03/code_021d27d8.h"

PointerStack *CreatePointerStack(u32 count) {
    PointerStack *list = AllocExpHeapBlock((count + 1) * 4 + 8, 4);

    list->mSlotCount = count + 1;
    list->mBottomIndex = 0;
    list->mTopIndex = 0;
    return list;
}
