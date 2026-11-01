#include "Main/Unknown/code_0210fa40.h"
#include "Main/Unknown/unk_0217d000.h"

void func_0210fa74(u32 a) {
    if (a == 1) {
        data_0217d244.mUnk_08 |= 2;
    } else {
        data_0217d244.mUnk_08 &= ~2;
    }
    data_0217d244.mUnk_04 = 0;
}

void func_0210fa40(u32 a, u32 b) {
    if (b == 0) {
        return;
    }
    if (a == 1) {
        data_0217d244.mUnk_08 |= 4;
    } else {
        data_0217d244.mUnk_08 &= ~4;
    }
}
