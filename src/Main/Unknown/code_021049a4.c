#include "Main/Unknown/code_021049a4.h"

#pragma thumb on

void func_021049a4(void) {
    int v1;
    int v2;
    Unk020f41c4_A *v3;
    Unk020f41c4_A **v4;
    Unk027e00cc *v6;
    u32 v5;
    if (data_0217bc48[17].mUnk_00 != 0) {
        v6 = &data_027e00cc[8];
        v4 = v6->mUnk_04;
        v1 = v6->mUnk_08;
        v2 = 0;
        if (0 < v1) {
            do {
                v3 = *v4;
                v5 = func_0210543c();
                *(u32 *) ((s32) v3 + 0x134) = v5;
                *(s32 *) (*(s32 *) ((s32) v3 + 0x134) + 0xfc) = (s32) v3 + 0x13c;
                v4 = v4 + 1;
                v2 = v2 + 1;
            } while (v2 < v1);
        }
        v6->mUnk_40 = 1;
    }
}

#pragma thumb off
