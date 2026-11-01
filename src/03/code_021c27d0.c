#include "03/code_021c27d0.h"

void func_ov003_021c2824(void) {
    func_ov003_021d3544((u32) 0, &func_ov003_021c27f8, 0, (u32) 0x78);
}

void func_ov003_021c27f8(u32 param_1) {
    int v1;
    v1 = func_ov003_021d1290();
    if (v1 != 0) {
        data_ov003_021da194->mUnk_1e2a1 = 1;
        func_ov003_021d34c8(0, param_1);
    }
}

u32 func_ov003_021c27e4(void) {
    if (data_ov003_021da194 == 0) {
        return 1;
    }
    return 0;
}

void func_ov003_021c27d0(u32 param_1) {
    *(u32 *) ((int) data_ov003_021da194 + 0x1e298) = param_1;
}
