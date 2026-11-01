#include "Main/Unknown/code_02126248.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/code_02126700.h"
#include "Main/Unknown/code_021274ec.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217d000.h"

#pragma thumb on

void func_02126248(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f) {
    Unk0217d3f0_2098 *p;

    p = &data_0217d3f0->mUnk_2098[2];
    p->mUnk_18(p, 0xf);
    func_0212583c(&data_0217d3f0->mUnk_2178[2], 0, 0, data_0215d044[2][0] << 3, data_0215d044[2][1] << 3, 1, 0x480, 1,
                  (void *) a);
    func_02127734();
    data_0217d3f0->mUnk_2204[2] = 1;
    func_02126700();
    data_0217d3f0->mUnk_28 = 0;
    data_0217d3f0->mUnk_30 = 0;
    data_0217d3f0->mUnk_20[0] = 0;
    data_0217d3f0->mUnk_20[1] = f;
    data_0217d3f0->mUnk_2074[0] = b;
    data_0217d3f0->mUnk_2074[1] = c;
    data_0217d3f0->mUnk_3c = d;
    data_0217d3f0->mUnk_40 = e;
}

#pragma thumb off
