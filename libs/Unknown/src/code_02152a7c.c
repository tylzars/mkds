#include "code_02152a7c.h"
#include "code_02152490.h"
#include "code_02152ac8.h"

#pragma thumb on

void func_02152a8c(Unk02152490 *a, u32 b, u32 c) {
    enum { K0 } d = K0;
    BitFieldInsert(&a->mUnk_00, c, d, 0x7ff);
    a->mUnk_04 = b;
}

void func_02152a88(Unk02152490 *a, u32 b) {
    a->mUnk_08 = b;
}

void func_02152a80(Unk02152490 *a, u32 b, u32 c) {
    a->mUnk_04 = b;
    a->mUnk_08 = c;
}

void func_02152a7c(Unk02152490 *a, u32 b) {
    a->mUnk_04 = b;
}

#pragma thumb off
