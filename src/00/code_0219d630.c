#include "00/code_0219d630.h"

s32 func_ov000_0219d660(void) {
    if ((int) data_ov000_021b5664 != 0) {
        return *(u32 *) ((int) data_ov000_021b5664 + 0x14);
    }
    return 0;
}

int func_ov000_0219d630(int param_1) {
    Unk02152500 *v1;
    u32 v2;
    v1 = func_ov000_0219c9c4();
    v2 = func_02152520((void *) (v1), (void *) (*(int *) ((int) data_ov000_021b5664 + 0x18) + param_1 * 0xc));
    if ((v2 == 0) || (v2 == -1)) {
        v2 = 0;
    }
    return v2;
}
