#include "Main/Unknown/code_021138e4.h"

#pragma thumb on

void func_02113940(void) {
    int v1;
    int v2;
    v2 = (data_0217d348->mUnk_68 + 1) * 0x10000 >> 0x10;
    v1 = func_02113ef0(v2);
    if ((v1 == 0) || (5 <= v2)) {
        v2 = 0;
    }
    if (data_0217d348->mUnk_68 != v2) {
        func_0212ecc0((const void *) (((u32) ((u8 *) &data_0217d068))), (u32) 0, (u32) 0);
    }
    data_0217d348->mUnk_68 = (short) v2;
}

void func_021138e4(void) {
    int v1;
    u32 v2;
    int v3;
    int v4;
    v4 = (data_0217d348->mUnk_68 + -1) * 0x10000 >> 0x10;
    if (v4 < 0) {
        v4 = 4;
        v1 = func_02113ef0(4);
        if (v1 == 0) {
            v2 = func_021143b4();
            v3 = (int) (v2) % 5;
            v4 = (v3 + -1) * 0x10000 >> 0x10;
        }
    }
    if (data_0217d348->mUnk_68 != v4) {
        func_0212ecc0((const void *) &data_0217d068, (u32) 0, (u32) 0);
    }
    data_0217d348->mUnk_68 = (short) v4;
}

#pragma thumb off
