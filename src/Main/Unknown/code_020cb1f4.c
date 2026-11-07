#include "Main/Unknown/code_020cb1f4.h"
#include "Main/Unknown/unk_02175628.h"

#pragma optimize_for_size on
u16 func_020cb210(InputSlot *a, u32 b) {
    return a->mUnk_00 & b;
}

u16 func_020cb1f4(u32 a, u32 b) {
    return func_020cb210(&data_02175628[a], b);
}
