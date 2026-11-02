#include "03/code_021ce024.h"
#include "03/unk_021da000.h"
#include "03/code_021cdcb8.h"
#include "03/code_021ce0f0.h"
#include "03/code_021cdd28.h"
#include "03/code_021d1000.h"
#include "03/code_021d1970.h"
#include "03/code_021d3000.h"
#include "03/code_021d3488.h"

void func_ov003_021ce024(u32 a) {
    s32 i;
    for (i = 0; i < 5; i += 2) {
        func_ov003_021d1c3c(1, data_ov003_021d6688[a][i],
                            func_ov003_021d1974((s32) data_ov003_021da27c->mUnk_00[i], 0));
        func_ov003_021d1790(data_ov003_021da27c->mUnk_00[i], -1, 0);
        func_ov003_021d17d4(data_ov003_021da27c->mUnk_00[i], -1, data_ov003_021d66a8[i].mUnk_00,
                            data_ov003_021d66a8[i].mUnk_02);
        func_ov003_021d1890(data_ov003_021da27c->mUnk_00[i], -1, 0, data_ov003_021d6698[a][i]);
    }
    func_ov003_021cdcf0(a);
}

void func_ov003_021ce0c4(void) {
    data_ov003_021da27c->mUnk_18 = 1;
    data_ov003_021da27c->mTask = func_ov003_021d3544(0, func_ov003_021cdf98, NULL, 0x78);
}
