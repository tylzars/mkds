#include "00/code_0219c954.h"

void func_ov000_0219c954(void) {
    if ((int) data_ov000_021b565c->mUnk_28 != 0) {
        func_ov000_02186474();
        func_ov000_02186430();
        func_ov000_021a3704((u32) 0, (u32) ((u32) data_ov000_021b565c->mUnk_28), (u32) 0);
        *(u32 *) ((int) data_ov000_021b565c + 0x28) = 0;
    }
    *(int *) &data_ov000_021b565c = 0;
}
