#include "00/code_02198a8c.h"
#include "00/code_02198714.h"
#include "00/code_02198ba8.h"
#include "00/code_02198d04.h"
#include "00/code_0219a000.h"
#include "00/code_0219a01c.h"
#include "00/code_0219a09c.h"
#include "00/code_0219a3f4.h"
#include "00/code_021988e8.h"

void func_ov000_02198a8c(Unk02197e8c *a) {
    if (func_ov000_0219914c(a) != 0) {
        if (func_ov000_0219a09c((s32) a) != 0) {
            func_ov000_0219a06c(a);
        }
    }
}

void func_ov000_02198ab0(Unk02197e8c *a) {
    func_ov000_021988e8(a);
    func_ov000_0219a3f8((u32 *) a);
}

u32 func_ov000_02198ac4(Unk02197e8c **a, const u8 *b, u32 c, u32 d, u32 e) {
    return func_ov000_0219a430(a, b, c, d, e);
}

int func_ov000_02198ad8(Unk02197fe8 *a, u8 *b, int c, int d) {
    if (d != 0) {
        return func_ov000_02198f80((s32) a, (u32) b, c);
    }
    return func_ov000_02198c58(a, b, c);
}

BOOL func_ov000_02198af4(Unk02197fe8 *a, Unk02198af4 *b) {
    func_ov000_0219a01c(a->mUnk_50.mUnk_00, b->mUnk_00 + 5, a->mUnk_66);
    if (func_ov000_02198714((u32 *) a, (u32) (a->mUnk_50.mUnk_00 + b->mUnk_00), b->mUnk_04) == 0) {
        return FALSE;
    }
    b->mUnk_0c = a->mUnk_88;
    if (a->mUnk_50.mUnk_00[b->mUnk_00 + 2] == 2) {
        a->mUnk_8c = a->mUnk_88;
    }
    return TRUE;
}

BOOL func_ov000_02198b50(Unk02197e8c *a, u32 b, int c) {
    u8 d[3];

    __memcpy(d, data_ov000_021b3fa4, 2);
    d[2] = 0x68;
    if (func_ov000_0219a110((u32 *) a, b, c, (u32) d, 3) != 0) {
        return TRUE;
    }
    return FALSE;
}

int func_ov000_02198b8c(Unk02197fe8 *a) {
    return func_ov000_02198b50(a->mUnk_08, a->mUnk_00, a->mUnk_04);
}
