#include "00/code_0219922c.h"
#include "00/code_0218e8c4.h"

u32 func_ov000_0219922c(int param_1, u32 param_2, u32 param_3) {
    int v1;
    int v2;
    v1 = (int) func_ov000_0219a5b0((Unk02197e8c *) param_1, param_2, param_3);
    if (*(int *) (param_1 + 0x2c) != 0) {
        v2 = func_ov000_02197f28((int) (param_1), (int) (v1), (u32) (param_2), (u32) (param_3), 1,
                                    0, 0, 0);
        if (v2 == 0) {
            return 0;
        }
    }
    if (v1 == 0) {
        return 1;
    }
    if (*(int *) (v1 + 0xc) == 0) {
        if ((*(int *) (v1 + 0x20) == 0) ||
            (v2 = func_ov000_0218e8c4(), (u32) (v2 - *(int *) (v1 + 0x1c)) < *(u32 *) (v1 + 0x20))) {
            return 1;
        }
        v1 = func_ov000_02199fb0((int) (v1), 6, 1);
        if (v1 == 0) {
            return 0;
        }
    } else {
        v1 = func_ov000_02199fb0((int) (v1), 2, 1);
        if (v1 == 0) {
            return 0;
        }
    }
    return 1;
}
