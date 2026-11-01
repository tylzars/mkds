#include "03/code_021d0a88.h"

void func_ov003_021d0ab8(void) {
    data_ov003_021da2ac->mUnk_a90 = 0xc;
}

u32 func_ov003_021d0a88(void) {
    int v1;
    v1 = func_ov003_021d010c();
    if (v1 == 1) {
        func_ov003_021cfa68();
        data_ov003_021da2ac->mUnk_a90 = 1;
        return 1;
    }
    return 0;
}
