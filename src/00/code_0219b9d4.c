#include "00/code_0219b9d4.h"
#include "00/code_0219887c.h"
#include "00/code_0219a000.h"
#include "00/code_0219b958.h"
#include "00/code_021a3264.h"
#include "00/code_02198a84.h"
#include "00/code_021a1ae0.h"

u32 func_ov000_0219b9d4(u32 a) {
    s32 i;
    void **p;
    if (data_ov000_021b54c8 == 0) {
        return 0;
    }
    i = 0;
    p = data_ov000_021b54d0;
    for (; i < 32; p++, i++) {
        if (*p != 0 && a == func_ov000_0219887c(*p)[1]) {
            return (u32) data_ov000_021b54d0[i];
        }
    }
    return 0;
}

s32 func_ov000_0219ba20(void) {
    Unk021b54c8 *p;
    u32 v;
    s32 r;
    if (data_ov000_021b54c8->mUnk_00 != 0) {
        return 0;
    }
    v = (u16) (func_ov000_021a3448(0x4000) + 0xc000);
    p = data_ov000_021b54c8;
    r = func_ov000_02198ac4((Unk02197e8c **) data_ov000_021b54c8, (const u8 *) func_ov000_0219a760(0, v, 0), p->mUnk_14,
                            p->mUnk_18, (u32) func_ov000_0219b240);
    if (func_ov000_0219b704(r) != 0) {
        return r;
    }
    func_ov000_02198a84((u32) data_ov000_021b54c8->mUnk_00, (u32) func_ov000_021a1ca8);
    func_ov000_021988d4((int) data_ov000_021b54c8->mUnk_00, (u32) func_ov000_021a1e40);
    return r;
}
