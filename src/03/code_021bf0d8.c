#include "03/code_021bf0d8.h"
#include "03/code_021be610.h"
#include "03/code_021d1000.h"
#include "03/code_021d1770.h"
#include "03/code_021d1970.h"
#include "03/code_021d250c.h"
#include "03/code_021d2a34.h"
#include "03/code_021d3544.h"
#include "03/unk_021d5000.h"
#include "03/unk_021da000.h"

void func_ov003_021bf0d8(void) {
    Unk021d299c a;
    s32 n;
    s32 i;
    u32 b;
    u32 c;

    n = data_ov003_021d5ecc[data_ov003_021da108->mUnk_17];
    if (data_ov003_021da108->mUnk_18 == 0) {
        if (data_ov003_021da108->mUnk_16 != -1) {
            return;
        }
        for (i = 0; i < n; i++) {
            func_ov003_021d250c(&data_ov003_021d5ed4[(data_ov003_021d5eec + data_ov003_021da108->mUnk_17 * 2)[i] * 2],
                                data_ov003_021d5ec8, (short *) &a);
            if (func_ov003_021d2a34(&a) != 0) {
                if (data_ov003_021da108->mUnk_10 != 0) {
                    break;
                }
                c = (data_ov003_021d5edc + data_ov003_021da108->mUnk_17 * 2)[i] + 1;
                func_ov003_021d1c3c(0, c, (u8 *) func_ov003_021d1974(data_ov003_021da108->mUnk_00[i], 0));
                b = (data_ov003_021d5eec + data_ov003_021da108->mUnk_17 * 2)[i];
                func_ov003_021d17d4((Unk021d1770 *) data_ov003_021da108->mUnk_00[i], -1, data_ov003_021d5ed4[b * 2],
                                    data_ov003_021d5ed6[b * 2]);
                func_ov003_021d1790((Unk021d1770 *) data_ov003_021da108->mUnk_00[i], -1, 1);
                data_ov003_021da108->mUnk_10 = func_ov003_021d3544(0, func_ov003_021befa4, 0, 0x6e);
                data_ov003_021da108->mUnk_16 = i;
                return;
            }
        }
    }
    data_ov003_021da108->mUnk_16 = -1;
}

void func_ov003_021bf1d8(Unk021d34e0 *param_0) {
    u32 a = 0;

    data_ov003_021da108->mUnk_16 = -1;
    data_ov003_021da108->mUnk_14 = data_ov003_021da108->mUnk_14 + 1;
    if (data_ov003_021da108->mUnk_14 >= 4) {
        data_ov003_021da108->mUnk_14 = a;
        func_ov003_021d34e0(param_0, func_ov003_021bf0d8);
    }
}

void func_ov003_021bf20c(Unk021d34e0 *param_0) {
    u32 a;
    s32 b;

    func_ov003_021d1770((Unk021d1770 *) data_ov003_021da108->mUnk_08, 0, &a, &b);
    b = b - 4;
    func_ov003_021bf258(b);
    if (b <= data_ov003_021d5ec4[1]) {
        func_ov003_021bf258(data_ov003_021d5ec4[1]);
        func_ov003_021d34e0(param_0, func_ov003_021bf1d8);
    }
}

void func_ov003_021bf258(s32 param_0) {
    s32 n;
    s32 i;
    s32 a;

    n = data_ov003_021d5ecc[data_ov003_021da108->mUnk_17];
    a = param_0 + data_ov003_021d5ed4[1] - data_ov003_021d5ec4[1];
    func_ov003_021d17d4((Unk021d1770 *) data_ov003_021da108->mUnk_08, -1, data_ov003_021d5ec4[0], param_0);
    for (i = 0; i < n; i++) {
        func_ov003_021d17d4((Unk021d1770 *) data_ov003_021da108->mUnk_00[i], -1,
                            data_ov003_021d5ed4[(data_ov003_021d5eec + data_ov003_021da108->mUnk_17 * 2)[i] * 2], a);
    }
}
