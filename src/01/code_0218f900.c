#include "01/code_0218f900.h"

#include "01/code_02185ef4.h"
#include "01/code_02188000.h"
#include "01/code_02188158.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020d2000.h"
#include "01/code_0218f000.h"
#include "Main/Unknown/code_0209bef0.h"

u16 func_ov001_0218f9c0(Unk02188950 *a) {
    return a->mUnk_0a8 == 2;
}

void func_ov001_0218f9a8(Unk02188950 *a) {
    a->mUnk_2d8 = 0;
    func_ov001_02188200(a, func_ov001_0218f9a8);
}

void func_ov001_0218f900(Unk02188950 *a) {
    func_ov001_02188d64(a, (s32) (a->mUnk_0a0->mUnk_198), (s32) (a->mUnk_0a0->mUnk_19c));
    func_ov001_02188d1c(a, (s32) (a->mUnk_0a0->mUnk_1ac), (s32) (a->mUnk_0a0->mUnk_1b0));
    func_ov001_02188cec(a, 0);
    func_ov001_02188c90(a);
    func_ov001_021875c0(a, 0, 0, 0, 0x41b, 0);
    func_ov001_021875c0(a, 0, 0, 0, 0x41c, 0);
    func_ov001_021875c0(a, 0, 0, 0, 0x41d, 0);
    func_020d2774(&a->mUnk_000, (u32) (0x22e));
    a->mUnk_000.mUnk_02 &= ~1;
}
