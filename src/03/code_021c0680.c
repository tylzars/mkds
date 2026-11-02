#include "03/code_021c0680.h"

void func_ov003_021c06b0(void) {
    u32 v1;
    if (data_ov003_021da15c->mUnk_11d == 2) {
        v1 = 0;
    } else {
        v1 = 2;
    }
    func_ov003_021c00ec(v1);
    func_ov003_021cdc10((u32) 1);
}

void func_ov003_021c0680(void) {
    func_ov003_021c00ec((data_ov003_021da15c->mUnk_11d != 1));
    func_ov003_021cdc10((u32) 1);
}
