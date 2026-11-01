#include "Main/Unknown/code_020ab8d4.h"

#pragma thumb on

void func_020ab910(u32 param_1, u32 param_2, u32 param_3, u32 param_4) {
    Unk0217b334 **v1;
    Unk0217b334 *v2;
    v1 = &data_0217b334;
    data_0217b334->mUnk_58 = param_1;
    (*v1)->mUnk_5c = param_2;
    (*v1)->mUnk_60 = param_3;
    (*v1)->mUnk_64 = param_4;
    v2 = *v1;
    func_020a9efc((u32) (v2->mUnk_50 + v2->mUnk_58), (u32) (v2->mUnk_54 + v2->mUnk_5c),
                  (u32) (v2->mUnk_50 + v2->mUnk_60), (u32) (v2->mUnk_54 + v2->mUnk_64));
}

void func_020ab8d4(u32 param_1, u32 param_2, u32 param_3, u32 param_4) {
    Unk0217b334 **v1;
    Unk0217b334 *v2;
    v1 = &data_0217b334;
    data_0217b334->mUnk_68 = param_1;
    (*v1)->mUnk_6c = param_2;
    (*v1)->mUnk_70 = param_3;
    (*v1)->mUnk_74 = param_4;
    v2 = *v1;
    func_020a9ed8((u32) (v2->mUnk_50 + v2->mUnk_68), (u32) (v2->mUnk_54 + v2->mUnk_6c),
                  (u32) (v2->mUnk_50 + v2->mUnk_70), (u32) (v2->mUnk_54 + v2->mUnk_74));
}

#pragma thumb off
