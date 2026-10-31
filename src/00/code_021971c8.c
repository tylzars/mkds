#include "00/code_021971c8.h"

int func_ov000_021971c8(int param_1, int param_2) {
    int v1;
    int v2;
    v2 = 0;
    v1 = 0;
    if (0 < param_2) {
        do {
            v2 = ((int) 0x9ccf9319u) * v2 + (int) *(s8 *) (param_1 + v1);
            v1 = v1 + 1;
        } while (v1 < param_2);
    }
    return v2;
}
