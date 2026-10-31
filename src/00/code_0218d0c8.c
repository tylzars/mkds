#include "00/code_0218d0c8.h"

int func_ov000_0218d0c8(int param_1, int param_2) {
    int v1;
    v1 = 0;
    if (0 < param_2) {
        do {
            if (*(s8 *) (param_1 + v1) == 0) {
                return v1 + 1;
            }
            v1 = v1 + 1;
        } while (v1 < param_2);
    }
    return -1;
}
