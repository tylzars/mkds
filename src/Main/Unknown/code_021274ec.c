#include "Main/Unknown/code_021274ec.h"
#include "Main/Unknown/code_02126f78.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02023000.h"

#pragma thumb on

void func_02127734(void) {
    s32 i;

    for (i = 0; i < 7; i++) {
        data_0217d3f0->mUnk_2204[i] = 0;
    }
}

static inline void func_021274ec_inline(Unk0217d3f0_2178 *e, Unk0217d3f0_2098 *o, u32 v) {
    e->mUnk_00 = o;
    e->mUnk_04 = v;
    e->mUnk_08 = 1;
    e->mUnk_0c = 1;
}

s32 func_021274ec(void *param_1, Unk021274ec *param_2) {
    s32 a;
    s32 i;
    Unk0217d3f0_2098 *o;

    a = param_2->mUnk_10;
    data_0217d3f0 = func_02036bec(param_1, 0x2278);
    if (param_2->mUnk_04 != 0) {
        data_0217d3f0->mUnk_44 = 1;
    }
    if (param_2->mUnk_08 != 0) {
        data_0217d3f0->mUnk_48 = 1;
    }
    if (param_2->mUnk_0c != 0) {
        data_0217d3f0->mUnk_4c = 1;
    }
    data_0217d3f0->mUnk_50 = 1;
    func_0212745c();
    a = func_0212717c(a);
    for (i = 0; i < 7; i++) {
        if (!((i == 1 && data_0217d3f0->mUnk_44 == 0) || (i == 2 && data_0217d3f0->mUnk_48 == 0) ||
              (i == 3 && data_0217d3f0->mUnk_4c == 0))) {
            data_0217d3f0->mUnk_21e8[i] = func_02036bec(param_1, (data_0215d044[i][0] * data_0215d044[i][1]) << 5);
            func_02023408(&data_0217d3f0->mUnk_2098[i], data_0217d3f0->mUnk_21e8[i], data_0215d044[i][0],
                          data_0215d044[i][1], 4);
            o = &data_0217d3f0->mUnk_2098[i];
            o->mUnk_18(o, 0);
            func_021274ec_inline(&data_0217d3f0->mUnk_2178[i], &data_0217d3f0->mUnk_2098[i], param_2->mUnk_00);
        }
    }
    func_02127734();
    data_0217d3f0->mUnk_00 = 0;
    data_0217d3f0->mUnk_04 = 0;
    data_0217d3f0->mUnk_08 = 0;
    data_0217d3f0->mUnk_0c = 0;
    data_0217d3f0->mUnk_10 = 0;
    data_0217d3f0->mUnk_14 = 0;
    data_0217d3f0->mUnk_18[0] = 0;
    data_0217d3f0->mUnk_18[1] = 0;
    data_0217d3f0->mUnk_20[0] = 0;
    data_0217d3f0->mUnk_20[1] = 0;
    data_0217d3f0->mUnk_206c[0] = 0;
    data_0217d3f0->mUnk_206c[1] = 0;
    data_0217d3f0->mUnk_2074[0] = 0;
    data_0217d3f0->mUnk_2074[1] = 0;
    data_0217d3f0->mUnk_34 = 0;
    data_0217d3f0->mUnk_38 = 0;
    data_0217d3f0->mUnk_30 = 0;
    data_0217d3f0->mUnk_224c = 0;
    data_0217d3f0->mUnk_2250 = 5;
    data_0217d3f0->mUnk_2254 = 0x10;
    data_0217d3f0->mUnk_2258 = 0x23;
    for (i = 0; i < 2; i++) {
        data_0217d3f0->mUnk_2054[i] = -192;
        data_0217d3f0->mUnk_205c[i] = 0;
        data_0217d3f0->mUnk_2064[i] = 0;
    }
    data_0217d3f0->mUnk_2080[0] = 0x19;
    data_0217d3f0->mUnk_2080[1] = 0x1a;
    data_0217d3f0->mUnk_207c = 0;
    for (i = 0; i < 2; i++) {
        data_0217d3f0->mUnk_2088[i] = 6;
        data_0217d3f0->mUnk_2090[i] = 10;
    }
    data_0217d3f0->mUnk_2248 = 0;
    return a;
}
#pragma thumb off
