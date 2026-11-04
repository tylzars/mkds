#include "Main/Unknown/code_0210b760.h"

#include "code_0212d214.h"
#include "Main/Unknown/code_0210bcf4.h"
#include "Main/Unknown/unk_0217c000.h"

void func_0210b7ec(Unk0210b7ec *p, u32 b) {
    s32 a;
    s32 c;

    a = p->mUnk_00;
    if (a == -1) {
        p->mUnk_00 = b;
        p->mUnk_08 = 0;
        return;
    }
    c = p->mUnk_08;
    p->mUnk_04 = a;
    p->mUnk_00 = b;
    p->mUnk_08 = (p->mUnk_04 - p->mUnk_00) >> p->mUnk_0c;
    a = p->mUnk_08;
    if (a > 0x600 || a < -0x600) {
        p->mUnk_08 = c;
    }
}

void func_0210b7a8(Unk0210b7a8 *p) {
    if (data_0217c780 & 1) {
        func_0210bf24(0, p->mUnk_00, (u32) p->mUnk_04, (u32) p);
    }
}

void func_0210b760(Unk0210b7a8 *p, Unk0212c400 **b) {
    if (data_0217c780 & 1) {
        func_0210bee8(0, p->mUnk_00, (u32) p->mUnk_04, (u32) b, (u32) p);
    }
}
