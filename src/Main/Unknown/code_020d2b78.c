#include "Main/Unknown/code_020d2b78.h"

#pragma thumb on

u32 func_020d2c20(void) {
    return ((u32) data_0217b4ec);
}

u32 func_020d2be8(void) {
    int v1;
    if ((int) data_0217b4d8 != 0) {
        return data_0217b4d8->mUnk_04;
    }
    v1 = *(int *) &data_0217b4e4;
    if ((v1 != 0) && (*(int *) (v1 + 0x170) != 0)) {
        return *(u32 *) (v1 + 0x174);
    }
    return 0;
}

u32 func_020d2bb0(void) {
    int v1;
    if ((int) data_0217b4d8 != 0) {
        return data_0217b4d8->mUnk_08;
    }
    v1 = *(int *) &data_0217b4e4;
    if ((v1 != 0) && (*(int *) (v1 + 0x170) != 0)) {
        return *(u32 *) (v1 + 0x178);
    }
    return 0;
}

u32 func_020d2b78(void) {
    int v1;
    if ((int) data_0217b4d8 != 0) {
        return data_0217b4d8->mUnk_0c;
    }
    v1 = *(int *) &data_0217b4e4;
    if ((v1 != 0) && (*(int *) (v1 + 0x170) != 0)) {
        return *(u32 *) (v1 + 0x17c);
    }
    return 0;
}

#pragma thumb off
