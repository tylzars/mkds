#include "Main/Unknown/code_020cb600.h"

void func_020cb600(int *param_1) {
    u32 v1;
    v1 = *(u32 *) param_1;
    if ((int) v1 < 0x7fffffff) {
        *param_1 = v1 + 1;
    }
}
