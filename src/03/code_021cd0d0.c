#include "03/code_021cd0d0.h"
#include "03/types_021da26c.h"

int func_ov003_021cd0d0(int *param_1) {
    int v1;
    int v2;
    int v3;
    int v4;
    v2 = 0;
    *param_1 = (int) data_ov003_021da26c->mUnk_1300;
    v1 = 0;
    v3 = *param_1;
    do {
        v4 = func_02134d30((const u8 *) (v3 + 0x20), (const u8 *) data_ov003_021d6638, 6);
        if (v4 != 0) {
            v2 = v2 + 1;
        }
        v3 = v3 + 0x2a;
        v1 = v1 + 1;
    } while (v1 < 0x14);
    return v2;
}
