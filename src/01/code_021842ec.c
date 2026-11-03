#include "01/code_021842ec.h"
#include "01/unk_021a6000.h"

void func_ov001_021842ec(Unk02188950 *a) {
    func_ov001_02187218(a, 7, NULL);
    func_ov001_02188d30(a, a->mUnk_0a0->mUnk_23c, a->mUnk_0a0->mUnk_240, NULL);
    func_ov001_02188c90(a);
    func_ov001_02188cec(a, 0);
    func_ov001_02187518(a, 0, 0, 0, 0x411, 0);
    func_ov001_02187518(a, 0, 0, 0, 0x412, 0);
    func_020d2774(&a->mUnk_000, (u32) (0x242));
    func_02073fb0(a->mUnk_000.mUnk_78 & 0x3fffffe0, 0x1000);
    func_ov001_02188200(a, func_ov001_02184874);
    a->mUnk_000.mFlags &= ~0x20;
}
