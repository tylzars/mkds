#include "03/code_021d1d60.h"
#include "03/code_021d1d88.h"

PointerStack *CreateFilledPointerStack(s32 count, void *buffer, s32 stride) {
    u8 *entry = buffer;
    PointerStack *list = CreatePointerStack(count);
    s32 i;

    for (i = 0; i < count; i++) {
        list->mPointers[i] = entry;
        entry += stride;
    }
    list->mTopIndex = count;
    return list;
}
