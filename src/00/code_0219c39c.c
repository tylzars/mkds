#include "00/code_0219c39c.h"
#include "00/unk_021b5000.h"
#include "00/code_0219c384.h"

s32 func_ov000_0219c3cc(s32 *value) {
    if (value != 0) {
        *value = data_ov000_021b5654;
    }
    return data_ov000_021b5650;
}

void func_ov000_0219c3b0(void) {
    if (data_ov000_021b5650 != 11) {
        data_ov000_021b5650 = 0;
        data_ov000_021b5654 = 0;
    }
}

u32 func_ov000_0219c39c(void) {
    if ((*(int *) &data_ov000_021b5650) != 0) {
        return 1;
    }
    return 0;
}
