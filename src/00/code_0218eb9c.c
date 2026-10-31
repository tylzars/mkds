#include "00/code_0218eb9c.h"

u32 func_ov000_0218eb9c(int *param_1, u32 param_2) {
    int v1;
    int v2[1];
    if ((param_1 == (int *) 0x0) || (*param_1 == 0)) {
        return 0;
    }
    if (*(int *) (*param_1 + 0x108) != 0) {
        return 0;
    }
    v1 = func_ov000_02194934((Unk0218f960 *) param_1, param_2, (Unk02194934 **) v2);
    if ((v1 != 0) && (*(int *) (v2[0] + 8) != 0)) {
        return 1;
    }
    return 0;
}
