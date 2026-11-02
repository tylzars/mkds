#include "Main/Unknown/code_020ec484.h"

#include "Main/Unknown/code_020ec490.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020ec504.h"

void func_020ec504(int param_1) {
    u16 v1;
    *(u16 *) (param_1 + 2) = *(u16 *) (param_1 + 2) | (*(u16 *) &data_02159578);
    v1 = func_020d5344((int) *(short *) (param_1 + 100));
    *(u16 *) (param_1 + 100) = v1;
}

void func_020ec490(Unk020ec490 *param_1) {
    if (param_1->mUnk_a8) {
        param_1->mUnk_ac = param_1->mUnk_ac + param_1->mUnk_ae;
    } else {
        param_1->mUnk_ac = param_1->mUnk_ac - param_1->mUnk_ae;
    }
    param_1->mUnk_10.y -= param_1->mUnk_a4;
    func_02148504(&param_1->mUnk_04, &param_1->mUnk_10, &param_1->mUnk_04);
    if (param_1->mUnk_04.y < param_1->mUnk_a0) {
        param_1->mUnk_90 = 2;
        param_1->mUnk_92 = 1;
    }
}

void func_020ec484(u32 arg0) {
    u32 value0 = arg0;
    u32 value12;
    value12 = (u32) &func_020d2398;
    func_020d2398((void *) value0);
}
