#include "Main/Unknown/code_020ada7c.h"

void func_020ada7c(int *param_1) {
    u32 v1;
    v1 = *(u32 *) param_1;
    if ((int) v1 < 0x7fffffff) {
        *param_1 = v1 + 1;
    }
}
