#include "00/code_0219bac8.h"
#include "00/code_0219b000.h"
#include "00/code_021a1514.h"
#include "00/code_021a158c.h"

s32 func_ov000_0219bb04(u8 **a) {
    if (data_ov000_021b54c8 == 0) {
        return 0;
    }
    *a = data_ov000_021b54c8->mUnk_33c.mUnk_2b8;
    if (data_ov000_021b54c8->mUnk_33c.mUnk_15 == 2 || data_ov000_021b54c8->mUnk_33c.mUnk_15 == 3) {
        return func_ov000_021a1514((void **) a);
    }
    return func_ov000_021a158c((void **) a);
}

s32 func_ov000_0219bac8(u32 a) {
    if (data_ov000_021b54c8 == 0) {
        return 0;
    }
    if ((data_ov000_021b54c8->mUnk_33c.mUnk_2d8 & (1 << a)) != 0) {
        return func_ov000_0219b8bc(a);
    }
    return 0;
}
