#include "00/code_021ae134.h"
#include "00/code_021ae214.h"
#include "00/code_021a9228.h"
#include "00/code_021ae0c4.h"
#include "00/code_021ae314.h"
#include "00/code_021af550.h"
#include "00/code_021aefc0.h"
#include "00/unk_021b6000.h"
#include "code_0200f5ac.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/unk_0216f000.h"

void func_ov000_021ae1e4(void) {
    Unk021a998c *a;

    a = *(Unk021a998c **) data_0216ff5c.mUnk_04->mUnk_a4;
    if (a != 0) {
        if (a->mUnk_09 != 0) {
            func_ov000_021a9534(a);
        } else {
            func_ov000_021ae228(a);
        }
    }
}

u32 func_ov000_021ae16c(Unk021a998c *param_1) {
    u32 a;
    u32 i;
    u32 s;

    a = func_ov000_021ae314();
    for (i = 0; i < 3; i++) {
        param_1->mUnk_28 = a;
        param_1->mUnk_08 = 2;
        param_1->mUnk_10 = func_0200f5ac() >> 16;
        func_ov000_021aefc0(param_1, 2, 24);
        s = func_0200fca0();
        if (data_ov000_021b63b4 != 0) {
            param_1->mUnk_04 = 1;
            func_0200e01c(0);
        }
        func_0200fcb4(s);
        if (param_1->mUnk_08 == 4) {
            return 0;
        }
        if (data_ov000_021b63b4 == 0) {
            break;
        }
    }
    return 1;
}

u32 func_ov000_021ae134(void) {
    Unk021a998c *a;

    a = *(Unk021a998c **) data_0216ff5c.mUnk_04->mUnk_a4;
    if (a != 0) {
        if (a->mUnk_09 != 0) {
            return func_ov000_021a943c(a);
        }
        return func_ov000_021ae16c(a);
    }
    return 1;
}
