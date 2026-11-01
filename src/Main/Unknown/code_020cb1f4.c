#include "Main/Unknown/code_020cb1f4.h"

#pragma optimize_for_size on
u16 func_020cb210(Unk02175628 *a, u32 b) {
    return a->mUnk_00 & b;
}

u16 func_020cb1f4(u32 a, u32 b) {
    return func_020cb210(&data_02175628[a], b);
}
