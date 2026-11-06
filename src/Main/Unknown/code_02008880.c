#include "Main/Unknown/code_02008880.h"
#include "code_02003024.h"
#include "code_02003be0.h"

#pragma thumb on

u16 func_020088dc(const u16 *a, s32 b) {
    u32 v1;
    u32 v2;
    s32 v3;
    v3 = b >> 1;
    v1 = 0;
    while (v3 > 0) {
        v1 += *a++;
        v3--;
    }
    v2 = (v1 >> 16) + (v1 & 0xffff);
    return (v2 + (v2 >> 16)) ^ 0xffff;
}

u32 func_02008880(FSFile *a) {
    Unk02008880 v1;
    Unk02008880 *v2;
    u32 v3;
    s32 v4;
    v2 = NULL;
    v3 = 0;
    if (a != NULL) {
        v4 = a->mUnk_2c - a->mProp.w.mUnk_04;
        if ((u32) FS_ReadFile(a, &v1, 0x60) >= 0x60) {
            v2 = &v1;
        }
        FS_SeekFile(a, v4, 0);
    } else {
        v2 = (Unk02008880 *) 0x027ffe00;
    }
    if (v2 != NULL) {
        v3 = v2->mUnk_2c + 0x268 + v2->mUnk_3c;
        if (v3 < 0x10000) {
            v3 = 0x10000;
        }
    }
    return v3;
}

#pragma thumb off
