#include "00/code_02198748.h"
#include "00/code_02198d04.h"
#include "code_02134d30.h"

int func_ov000_0219885c(void *a, Unk02197fe8 **b, int c, u32 d) {
    int r = func_ov000_0219a28c(a, b, c, d);
    if (r != 0) {
        return r;
    }
    (*b)->mUnk_0c = 0;
    (*b)->mUnk_10 = 1;
    return 0;
}

int func_ov000_0219883c(void *a, Unk02197fe8 **b, int c, u32 d) {
    int r = func_ov000_0219a28c(a, b, c, d);
    if (r != 0) {
        return r;
    }
    (*b)->mUnk_0c = 2;
    (*b)->mUnk_10 = 0;
    return 0;
}

int func_ov000_021987c8(Unk02197fe8 *a, void *b, int c, Unk02198778 *d) {
    u8 e[0x24];
    func_ov000_0219a61c((const u8 **) &b, (s32 *) &c);
    if (c > 0) {
        a->mUnk_38.mUnk_00 = func_ov000_021a3690(c);
        if (a->mUnk_38.mUnk_00 == 0) {
            return 1;
        }
        func_02134eb8(a->mUnk_38.mUnk_00, b, c);
        a->mUnk_38.mUnk_04 = c;
    }
    if (d != 0) {
        a->mUnk_28 = *d;
    }
    func_ov000_02197be0((s8 *) e);
    func_ov000_02197b34((s8 *) a->mUnk_68, (s8 *) e);
    func_ov000_02198f24((int) a, (u32) e);
    a->mUnk_0c = 0;
    return 0;
}

int func_ov000_02198778(Unk02197fe8 *a, Unk02198778 *b) {
    if (a->mUnk_14 != 0) {
        a->mUnk_14 = 0;
        return 0;
    }
    a->mUnk_14 = 0;
    if (a->mUnk_0c != 4) {
        return 0;
    }
    func_ov000_02198df8((u32) a);
    a->mUnk_0c = 5;
    if (b != 0) {
        a->mUnk_28 = *b;
    }
    return 1;
}

void func_ov000_02198748(Unk02197fe8 *a, void *b, u32 c, ...) {
    a->mUnk_14 = 0;
    if (a->mUnk_0c == 4) {
        func_ov000_0219a61c((const u8 **) &b, (s32 *) &c);
        func_ov000_02198d9c((int) a, (u32) b, c);
        a->mUnk_0c = 6;
    }
}
