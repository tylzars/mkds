#include "00/code_021a8960.h"

u32 func_ov000_021a8960(int param_1) {
    u32 v1;
    int v2;
    s8 v3;
    v2 = *(int *) (param_1 + 100);
    v1 = 0;
    if (v2 != 0) {
        v3 = *(s8 *) (param_1 + 0x73);
        if (v3 == 1) {
            if (*(int *) (v2 + 0x104) != 0) {
                v1 = (u32) * (u16 *) (*(int *) (v2 + 0x104) + 4);
            }
        } else if ((v3 == 0) || (v3 == 4)) {
            v1 = *(int *) (param_1 + 0x44) - *(int *) (v2 + 0xf8);
        }
    }
    return v1;
}
