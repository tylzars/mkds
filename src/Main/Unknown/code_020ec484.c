#include "Main/Unknown/code_020ec484.h"

#include "Main/Unknown/code_020ec490.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020ec504.h"

void func_020ec504(int a) {
    u16 v1;
    *(u16 *) (a + 2) = *(u16 *) (a + 2) | (*(u16 *) &data_02159578);
    v1 = func_020d5344((int) *(short *) (a + 100));
    *(u16 *) (a + 100) = v1;
}

void func_020ec490(Unk020ec490 *a) {
    if (a->mUnk_a8) {
        a->mUnk_ac = a->mUnk_ac + a->mUnk_ae;
    } else {
        a->mUnk_ac = a->mUnk_ac - a->mUnk_ae;
    }
    a->mUnk_10.y -= a->mUnk_a4;
    func_02148504(&a->mUnk_04, &a->mUnk_10, &a->mUnk_04);
    if (a->mUnk_04.y < a->mUnk_a0) {
        a->mUnk_90 = 2;
        a->mUnk_92 = 1;
    }
}

void func_020ec484(u32 arg0) {
    u32 value0 = arg0;
    u32 value12;
    value12 = (u32) &func_020d2398;
    func_020d2398((void *) value0);
}
