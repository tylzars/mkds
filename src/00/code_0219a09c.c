#include "00/code_0219a09c.h"
#include "00/code_0218e8c4.h"

u32 func_ov000_0219a09c(int param_1) {
    int v1;
    u32 v2[2];
    v2[0] = func_ov000_0218e8c4();
    v1 = func_ov000_0218dd8c((int *) ((int *) (u32) (*(u32 *) (param_1 + 0xc))), (int) &func_ov000_0219a0d0,
                             (u32) ((u32) (v2)));
    if (v1 == 0) {
        return 1;
    }
    return 0;
}
