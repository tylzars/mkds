#include "Main/Unknown/code_020b32ec.h"
#include "Main/Unknown/code_020b1de4.h"

#pragma thumb on

Unk020b4a44 *func_020b33c4(void) {
    return ((Unk020b4a44 *) data_0217b354->mChoisesSBNclr);
}

Unk020b4934 *func_020b3374(void) {
    int v1;
    v1 = func_020b2d04();
    if (v1 == 1) {
        data_0217b354->mChoisesSBNcgr->mUnk_14 = data_0217b354->mUnk_174;
    } else {
        v1 = func_020b2d04();
        if (v1 == 2) {
            data_0217b354->mChoisesSBNcgr->mUnk_14 = data_0217b354->mUnk_178;
        }
    }
    return data_0217b354->mChoisesSBNcgr;
}

void *func_020b32f8(void) {
    int v1;
    int v2;
    v2 = 0;
    v1 = func_020b2d04();
    if (v1 == 0) {
        if (data_0217b354->mUnk_17c != 0) {
            v2 = (s32) data_0217b354->mUnk_17c->mUnk_0c;
        }
    } else if (v1 == 1) {
        if (data_0217b354->mUnk_180 != 0) {
            v2 = (s32) data_0217b354->mUnk_180->mUnk_0c;
        }
    } else if (v1 == 2) {
        if (data_0217b354->mUnk_184 != 0) {
            v2 = (s32) data_0217b354->mUnk_184->mUnk_0c;
        }
    } else if ((v1 == 3) && (data_0217b354->mUnk_188 != 0)) {
        v2 = (s32) data_0217b354->mUnk_188->mUnk_0c;
    }
    return (void *) v2;
}

u32 func_020b32ec(void) {
    return ((u32) data_0217b354->mUnk_00c);
}

#pragma thumb off
