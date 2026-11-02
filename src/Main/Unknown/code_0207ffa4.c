#include "Main/Unknown/code_0207ffa4.h"

#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/code_02039774.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02039860.h"

s32 func_020800a0(Unk0208001c *p) {
    s32 r = 0;
    s16 a = *p->mUnk_00->mUnk_28;

    if (a != 0) {
        r = (s32) (((s64) a * 0x28f5c) >> 12);
    }
    return r;
}

void func_0208001c(Unk0208001c *p, Unk02175620_bc *a) {
    p->mUnk_04 = p->mUnk_00;
    p->mUnk_00 = a;
    p->mUnk_08 = data_021557ec;
    func_021484d0(p->mUnk_00->mUnk_20, p->mUnk_04->mUnk_20, &p->mUnk_08);
    if ((s64) p->mUnk_08.x * p->mUnk_08.x + (s64) p->mUnk_08.y * p->mUnk_08.y + (s64) p->mUnk_08.z * p->mUnk_08.z >=
        0x10) {
        func_02039860(&p->mUnk_08, &p->mUnk_08);
    }
}

void func_0207ffa4(Unk02080b1c *a, u32 b, Unk02080b1c_00 *c) {
    a->mUnk_08 = data_021557ec;
    a->mUnk_04 = c;
    a->mUnk_00 = a->mUnk_04->mUnk_00[0];
    func_021484d0(a->mUnk_00->mUnk_18, a->mUnk_04->mUnk_18, &a->mUnk_08);
    func_02039860(&a->mUnk_08, &a->mUnk_08);
    a->mUnk_14 = 0;
    a->mUnk_18 = 0;
    a->mUnk_1c = b;
}
