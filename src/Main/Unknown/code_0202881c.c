#include "Main/Unknown/code_0202881c.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217a000.h"

u32 func_02028850(void) {
    return (data_0217aa00->mUnk_0004);
}

void func_02028824(u8 a) {
    if (func_02028850() == 8) {
        data_0217aa00->mUnk_15f7 = a;
    }
}

u32 func_0202881c(Unk02175628_48 *a) {
    return a->mHasPair;
}
