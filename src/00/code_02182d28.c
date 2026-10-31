#include "00/code_02182d28.h"

void func_ov000_02182d28(void) {
    int v1;
    data_ov000_021b4c70->mUnk_10 = data_ov000_021b4c70->mUnk_10 + 1;
    v1 = func_02125fa4();
    if ((v1 != 0) && (0x78 < data_ov000_021b4c70->mUnk_10)) {
        func_02125fc0();
    }
    v1 = func_02125f88();
    if (v1 != 0) {
        *(u32 *) ((int) data_ov000_021b4c70 + 4) = 2;
        func_ov000_02182de8();
        *(u32 *) ((int) data_ov000_021b4c70 + 0x10) = 0;
    }
    return;
}
