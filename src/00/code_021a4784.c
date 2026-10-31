#include "00/code_021a4784.h"

void func_ov000_021a4784(u32 param_1, int param_2) {
    int v1;
    v1 = *(int *) (param_1 + 0x100);
    if (((v1 < 0xfe) && (1 <= param_2)) && (param_2 <= 254)) {
        *(int *) (param_1 + 0x100) = v1 + 1;
        *(s8 *) (param_1 + v1) = (s8) param_2;
    }
}
