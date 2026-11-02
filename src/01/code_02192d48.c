#include "01/code_02192d48.h"

#include "01/code_02192000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "01/code_02193000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_0212a000.h"
#include "Main/Unknown/code_0214a000.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020f9c6c.h"

void func_ov001_02192e10(Unk02188950 *a) {
    s32 m[9];
    func_020d2450(a);
    a->mUnk_000.mUnk_7e = (u16) (((s64) a->mUnk_000.mUnk_9c->mUnk_0c.y * 0xb60b60b60bLL + 0x80000000000LL) >> 44);
    func_02146d44(m, data_0215d4b4[(a->mUnk_000.mUnk_7e >> 4) * 2], data_0215d4b4[(a->mUnk_000.mUnk_7e >> 4) * 2 + 1]);
    func_02146dfc(m, &a->mUnk_000.mUnk_28.mUnk_00.x, &a->mUnk_000.mUnk_28.mUnk_00.x);
}

void LoadStopSign(Unk0219b478 *a) {
    gStopSign = func_ov001_0219b478(a, "StopSign.nsbmd");
    func_0209b940(gStopSign, 0x3f);
    func_0209ba08(gStopSign, 2);
    func_020849a0(gStopSign->mUnk_10, 0x294a);
}

void func_ov001_02192d7c(void *a, Unk02192d7c *b) {
    s32 v = 0x1e;
    func_01ff9048(0x14, &v, 1);
    b->mUnk_4c = b->mUnk_04 >> 4;
    b->mUnk_50 = b->mUnk_08 >> 4;
    b->mUnk_54 = b->mUnk_0c >> 4;
    func_01ff9048(0x19, b->mUnk_28, 0xc);
    func_01ff9048(0x1b, b->mUnk_1c, 3);
    func_0209bb2c(a, gStopSign, b);
}

void func_ov001_02192d60(void) {
    func_0209bfa8(NULL, NULL, NULL, (u32) (0), (u16) (1));
    return;
}

void *func_ov001_02192d48(void) {
    return (void *) func_0209bf1c(LoadStopSign, func_ov001_02192d7c, NULL);
}
