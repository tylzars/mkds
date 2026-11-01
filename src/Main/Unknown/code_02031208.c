#include "Main/Unknown/code_02031208.h"
#include "Main/Unknown/code_02030a20.h"

#pragma thumb on

u32 func_02031268(void) {
    if (data_02174e58->mUnk_c0.mUnk_00 == 1) {
        return 1;
    }
    return 0;
}

u32 func_02031250(void) {
    if (data_02174e58->mUnk_c0.mUnk_00 == 3) {
        return 1;
    }
    return 0;
}

void func_02031208(void) {
    int v1;
    Unk02174e58_24 *v2;
    if (data_02174e58->mUnk_94 != 6) {
        v1 = 0;
        do {
            v2 = &data_02174e58->mUnk_24[v1];
            func_02124c30(v2->mUnk_0c, v2->mUnk_08, v2->mUnk_14, (&data_02174e58->mUnk_5c)[v1], v2->mUnk_18);
            v1++;
        } while (v1 < 2);
    }
}

#pragma thumb off
