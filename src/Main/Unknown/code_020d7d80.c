#include "Main/Unknown/code_020d7d80.h"

#pragma thumb on

void func_020d7d80(Unk020e0144 *a) {
    Unk020e0144_00 *v1;
    int v2;
    int v3;
    int v4;
    Unk020e0144_00_0 *v5;
    v1 = a->mUnk_00;
    v3 = v1->mUnk_04;
    v2 = 0;
    if (0 < v3) {
        v4 = 0;
        do {
            v5 = (Unk020e0144_00_0 *) ((u8 *) v1->mUnk_00 + v4);
            v5->mUnk_30 = v5->mUnk_40;
            v5->mUnk_34 = v5->mUnk_44;
            v4 = v4 + 0x54;
            v2 = v2 + 1;
        } while (v2 < v3);
    }
}

#pragma thumb off
