#include "Main/Unknown/code_0212658c.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/code_02126700.h"
#include "Main/Unknown/code_021274ec.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217d000.h"

#pragma thumb on

void func_02126638(void *param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6, s32 param_7) {
    Unk0217d3f0_2098 *p;

    p = &data_0217d3f0->mUnk_2098[0];
    p->mUnk_18(p, 0xf);
    func_0212583c(&data_0217d3f0->mUnk_2178[0], 0, 0, data_0215d044[0][0] << 3, data_0215d044[0][1] << 3, 1, 0x480, 1,
                  param_1);
    func_02127734();
    data_0217d3f0->mUnk_2204[0] = 1;
    func_02126700();
    data_0217d3f0->mUnk_28 = 0;
    data_0217d3f0->mUnk_30 = 0;
    data_0217d3f0->mUnk_20[0] = param_6;
    data_0217d3f0->mUnk_20[1] = param_7;
    data_0217d3f0->mUnk_2074[0] = param_2;
    data_0217d3f0->mUnk_2074[1] = param_3;
    data_0217d3f0->mUnk_3c = param_4;
    data_0217d3f0->mUnk_40 = param_5;
}

void func_0212658c(void *param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7) {
    Unk0217d3f0_2098 *p;

    p = &data_0217d3f0->mUnk_2098[1];
    p->mUnk_18(p, 0xf);
    func_0212583c(&data_0217d3f0->mUnk_2178[1], 0, 0, data_0215d044[1][0] << 3, data_0215d044[1][1] << 3, 1, 0x480, 1,
                  param_1);
    func_02127734();
    data_0217d3f0->mUnk_2204[1] = 1;
    func_02126700();
    data_0217d3f0->mUnk_28 = 0;
    data_0217d3f0->mUnk_30 = 0;
    data_0217d3f0->mUnk_20[0] = param_6;
    data_0217d3f0->mUnk_20[1] = param_7;
    data_0217d3f0->mUnk_2074[0] = param_2;
    data_0217d3f0->mUnk_2074[1] = param_3;
    data_0217d3f0->mUnk_3c = param_4;
    data_0217d3f0->mUnk_40 = param_5;
}
#pragma thumb off
