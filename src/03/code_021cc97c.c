#include "03/code_021cc97c.h"
#include "03/code_021cca30.h"

void func_ov003_021cc9fc(void) {
    data_ov003_021da25c->mUnk_604 = 1;
}

void func_ov003_021cc9c0(int param_1, int param_2, int param_3, int param_4) {
    int v1;
    int v2;
    v1 = (int) data_ov003_021da25c + 4 + param_2 * 2;
    v2 = 0;
    if (param_4 > 0) {
        do {
            func_0214cffc((const void *) param_1, (void *) v1, (u32) (param_3 << 1));
            v2 = v2 + 1;
            param_1 = param_1 + 0x40;
            v1 = v1 + 0x40;
        } while (v2 < param_4);
    }
}

void func_ov003_021cc97c(void) {
    if (data_ov003_021da25c->mUnk_604 != 0) {
        func_0200ee74((const void *) data_ov003_021da25c->mUnk_004, (int) (((u32) 0x00000600u)));
        func_0214bc9c((const void *) data_ov003_021da25c->mUnk_004, 0, (u32) (((u32) 0x00000600u)));
        data_ov003_021da25c->mUnk_604 = 0;
    }
}
