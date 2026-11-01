#include "Main/Unknown/code_02030688.h"

u16 func_020306a4(Unk02175628 *a, u32 b) {
    return a->mUnk_00 & b;
}

u32 func_02030688(u32 a, u32 b) {
    return func_020306a4(&data_02175628[a], b);
}
