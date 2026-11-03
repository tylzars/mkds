#include "Main/Unknown/code_021000d0.h"

#include "Main/Unknown/code_020d2b78.h"

void *func_02100138(u32 a) {
    s32 n = func_020d2c20();
    s32 i;

    for (i = 0; i < n; i++) {
        if (data_0216b288[i].mUnk_00 == a) {
            return data_0216b288[i].mUnk_04->mUnk_24[3];
        }
    }
    return NULL;
}

void *func_021000d0(u32 a) {
    s32 n = func_020d2c20();
    s32 i;

    for (i = 0; i < n; i++) {
        if (data_0216b288[i].mUnk_00 == a) {
            return data_0216b288[i].mUnk_04->mUnk_24[0];
        }
    }
    return NULL;
}
