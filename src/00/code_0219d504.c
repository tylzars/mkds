#include "00/code_0219d504.h"
#include "00/code_0218f960.h"
#include "00/code_0219cfc0.h"
#include "00/code_0219d000.h"
#include "00/code_0219daa8.h"
#include "00/code_0219d630.h"
#include "code_0200f5ac.h"

u32 func_ov000_0219d5e4(u32 a) {
    s32 i;
    if (data_ov000_021b5664 == 0 || a == 0) {
        return -1;
    }
    for (i = 0; i < data_ov000_021b5664->mUnk_14; i++) {
        if (a == func_ov000_0219d630(i)) {
            return i;
        }
    }
    return -1;
}

void func_ov000_0219d5bc(void) {
    if (data_ov000_021b5664 != 0) {
        data_ov000_021b5664->mUnk_08 = 0;
        data_ov000_021b5664->mUnk_0c = func_0200f5ac();
    }
}

u32 func_ov000_0219d558(s32 a, void *b, void *c) {
    if (data_ov000_021b5664 == 0 || data_ov000_021b5664->mUnk_04 == 0) {
        return 0;
    }
    if (a == -1) {
        a = data_ov000_021b5664->mUnk_04->mUnk_00->mUnk_214;
    }
    if (b == 0) {
        b = data_ov000_021b5664->mUnk_04->mUnk_00->mUnk_218;
    }
    if (c == 0) {
        c = data_ov000_021b5664->mUnk_04->mUnk_00->mUnk_318;
    }
    return func_ov000_0218e974(data_ov000_021b5664->mUnk_04, a, b, c);
}

void func_ov000_0219d504(s32 a) {
    Unk0218ec44 b;
    if (data_ov000_021b5664->mUnk_44 != 0 && data_ov000_021b5664->mUnk_00 != 1) {
        ((void (*)(s32, void *)) data_ov000_021b5664->mUnk_44)(a, data_ov000_021b5664->mUnk_48);
    }
    if (data_ov000_021b5664->mUnk_34 != 0) {
        Unk021b5664 *c;
        u8 d = func_ov000_0219daa8(&data_ov000_021b5664->mUnk_18[a], (char *) b.mUnk_108);
        c = data_ov000_021b5664;
        c->mUnk_34(a, d, b.mUnk_108, c->mUnk_38);
    }
}
