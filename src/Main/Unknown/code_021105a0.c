#include "Main/Unknown/code_021105a0.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_021059e0.h"

void func_02110698(void) {
    func_02105ac0(0);
}

s32 func_02110640(Unk0217c7f0 *a, s32 b) {
    s32 c;
    s32 d;
    c = a->mUnk_04 >> 12;
    if (b == c) {
        return -1;
    }
    if (c <= b) {
        d = a->mUnk_04 + a->mUnk_00;
        if ((d >> 12) > b) {
            d = b << 12;
        }
    } else {
        d = a->mUnk_04 - a->mUnk_00;
        if ((d >> 12) < b) {
            d = b << 12;
        }
    }
    a->mUnk_04 = d;
    return a->mUnk_04 >> 12;
}

void func_021105d8(void) {
    s32 i;
    Unk0217d26c *p;
    for (i = 0, p = &data_0217d26c; i < 7; i++, p++) {
        s32 t[7] = {1, 3, 2, 1, 3, 2, 3};
        func_0210e094(p, t[i], data_0217d130);
    }
}

void func_021105a0(void) {
    s32 i;
    Unk0217d26c *p;
    for (i = 0, p = &data_0217d26c; i < 7; i++, p++) {
        func_0210e03c(p);
    }
}
