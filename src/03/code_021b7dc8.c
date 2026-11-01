#include "03/code_021b7dc8.h"
#include "00/code_021a8c94.h"
#include "00/code_021a8c8c.h"
#include "00/code_021b0014.h"
#include "03/code_021b94b8.h"

s32 func_ov003_021b7df4(u32 a, u32 b, u32 c) {
    data_ov003_021d6810.mUnk_10 = func_ov003_021b7cac(a);
    data_ov003_021d6810.mUnk_14 = func_ov003_021b7cac(b);
    data_ov003_021d6810.mUnk_18 = func_ov003_021b7cac(c);
    if (func_ov000_021a8c94(&data_ov003_021d6810) < 0) {
        return -1;
    }
    while (data_ov000_021b63b4 == 0) {
        func_0200dc3c(100);
    }
    return 0;
}

s32 func_ov003_021b7dc8(void) {
    if (func_ov000_021a8c8c() < 0) {
        return -1;
    }
    return -(func_ov003_021ba524() != 0);
}
