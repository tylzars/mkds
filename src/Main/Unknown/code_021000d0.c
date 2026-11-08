#include "Main/Unknown/code_021000d0.h"

#include "Main/Unknown/code_020d2b78.h"

void *FindMapObjectKindUpdateList(u32 a) {
    s32 n = GetMapObjectKindCount();
    s32 i;

    for (i = 0; i < n; i++) {
        if (data_0216b288[i].mKind == a) {
            return data_0216b288[i].mUnk_04->mLists[3];
        }
    }
    return NULL;
}

void *FindMapObjectKindDrawList0(u32 a) {
    s32 n = GetMapObjectKindCount();
    s32 i;

    for (i = 0; i < n; i++) {
        if (data_0216b288[i].mKind == a) {
            return data_0216b288[i].mUnk_04->mLists[0];
        }
    }
    return NULL;
}
