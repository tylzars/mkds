#include "Main/Unknown/code_020cb600.h"

void func_020cb600(int *a) {
    u32 v1;
    v1 = *(u32 *) a;
    if ((s32) v1 < 0x7fffffff) {
        *a = v1 + 1;
    }
}
