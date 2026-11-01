#include "Main/Unknown/code_02028db8.h"

u16 func_02028dd4(void) {
    int v1;
    if (data_0217aa00->mUnk_0000 == 2) {
        v1 = data_0217aa00->mUnk_0432;
    } else {
        v1 = 0;
    }
    return v1;
}

u32 func_02028db8(u32 p0) {
    return ((u32) data_0217aa00->mUnk_1e52[p0].mUnk_00);
}
