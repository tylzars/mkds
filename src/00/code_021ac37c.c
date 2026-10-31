#include "00/code_021ac37c.h"

void func_ov000_021ac37c(u8 *param_1, u32 *param_2, u32 param_3) {
    u32 v1;
    u32 v2;
    u8 *v3;
    v2 = 0;
    if (v2 < param_3 >> 2) {
        do {
            v1 = *param_2;
            param_2 = param_2 + 1;
            *param_1 = (s8) (v1 >> 0x18);
            param_1[1] = (s8) (v1 >> 0x10);
            param_1[2] = (s8) (v1 >> 8);
            v3 = param_1 + 3;
            param_1 = param_1 + 4;
            *v3 = (s8) v1;
            v2 = v2 + 1;
        } while (v2 < param_3 >> 2);
    }
    return;
}
