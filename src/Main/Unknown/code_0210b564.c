#include "Main/Unknown/code_0210b564.h"

void func_0210b564(int param_1, int param_2, u32 param_3, u32 param_4, u32 param_5) {
    int v1;
    if ((*(u16 *) (param_1 + 0x34) & 1) == 0) {
        return;
    }
    if (param_2 == 2) {
        if (((u32) 0x00009c40u) < param_5) {
            func_021090c4((void *) ((void *) param_1), 0x70, 0x7f, 0);
            return;
        }
        if (param_5 != 0) {
            func_021090c4((void *) ((void *) param_1), 0x6f, 0x7f, 0);
            return;
        }
    }
    v1 = func_0210bb74(param_2, (int) param_3, (int) param_4);
    if (v1 != 0xffff) {
        func_021090c4((void *) ((void *) param_1), (int) (v1), 0x7f, 0);
        return;
    }
}
