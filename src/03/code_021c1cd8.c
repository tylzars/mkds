#include "03/code_021c1cd8.h"
#include "03/code_021d23b0.h"
#include "03/code_021c0d2c.h"
#include "03/code_021c105c.h"
#include "03/code_021c1a60.h"
#include "03/code_021d1000.h"
#include "03/code_021d1c18.h"
#include "03/code_021d27d8.h"
#include "03/code_021d3544.h"
#include "03/unk_021d6000.h"
#include "03/unk_021da000.h"
#include "03/code_021d2070.h"

// non-matching: 90.0: zero constants and loop counters sit at different stack offsets, size 0x22c against 0x248
void func_ov003_021c1cd8(void) {
    Unk021c0d2c s;
    Unk021da160 *p;
    int i;
    int j;
    int k;
    s.mUnk_00[0] = data_ov003_021d6dd8[0];
    s.mUnk_00[1] = data_ov003_021d6dd8[1];
    s.mUnk_00[2] = data_ov003_021d6dd8[2];
    s.mUnk_00[3] = data_ov003_021d6dd8[3];
    s.mUnk_00[2] = data_ov003_021d622c[0];
    s.mUnk_00[3] = data_ov003_021d622c[1];
    p = func_ov003_021d283c(0x6c, 4);
    data_ov003_021da160 = p;
    p->mUnk_60 = 0x1f;
    data_ov003_021da160->mUnk_63 = 0;
    data_ov003_021da160->mUnk_66 = 1;
    data_ov003_021da160->mUnk_67 = 1;
    data_ov003_021da160->mUnk_68 = 1;
    for (i = 0; i < 10; i++) {
        data_ov003_021da160->mUnk_10[i] = (Unk021bf920 *) func_ov003_021d1c18(0, 0x36);
        data_ov003_021da160->mUnk_10[i]->mUnk_00 = (data_ov003_021da160->mUnk_10[i]->mUnk_00 & 0xc1fffcff) | 0x200;
        data_ov003_021da160->mUnk_10[i]->mUnk_04 = (data_ov003_021da160->mUnk_10[i]->mUnk_04 & 0xfffff3ff) | 0xc00;
    }
    for (i = 0; i < 2; i++) {
        data_ov003_021da160->mUnk_38[i] = (Unk021bf920 *) func_ov003_021d1c18(0, data_ov003_021d6218[i]);
        data_ov003_021da160->mUnk_38[i]->mUnk_00 = (data_ov003_021da160->mUnk_38[i]->mUnk_00 & 0xc1fffcff) | 0x200;
        data_ov003_021da160->mUnk_38[i]->mUnk_04 = (data_ov003_021da160->mUnk_38[i]->mUnk_04 & 0xfffff3ff) | 0xc00;
    }
    for (i = 0; i < 2; i++) {
        data_ov003_021da160->mUnk_40[i] = (void *) func_ov003_021d1be4(0, data_ov003_021d621c[i], 1);
        func_ov003_021d18f0(data_ov003_021da160->mUnk_40[i], -1, 0x200, 0);
        func_ov003_021d1790(data_ov003_021da160->mUnk_40[i], -1, 3);
    }
    s.mUnk_0c[1] = 0;
    for (i = 0; i < 4; i++) {
        data_ov003_021da160->mUnk_00[i] =
            func_ov003_021d23b0(0, data_ov003_021d6230[0], data_ov003_021d6230[1], 0, &s.mUnk_08, 0);
        s.mUnk_00[0] = 0;
        for (k = 0; k < 3; k++) {
            s.mUnk_0c[0] = data_ov003_021d6258[i * 3 + k];
            func_ov003_021d2070(data_ov003_021da160->mUnk_00[i], s.mUnk_00[0], s.mUnk_00[1], s.mUnk_00[2], s.mUnk_00[3],
                                2, 0x480, s.mUnk_0c);
            s.mUnk_00[0] = s.mUnk_00[0] + 0x20;
        }
        data_ov003_021da160->mUnk_48[i] = func_ov003_021d19e0(0, s.mUnk_08, 0);
    }
    data_ov003_021da160->mUnk_58 = (void *) func_ov003_021d1be4(0, 0x44, 1);
    func_ov003_021d18f0(data_ov003_021da160->mUnk_58, -1, 0x200, 0);
    func_ov003_021d1790(data_ov003_021da160->mUnk_58, -1, 2);
    data_ov003_021da160->mUnk_5c = (void *) func_ov003_021d3544(0, (u32) func_ov003_021c1bf4, 0, 0x78);
    func_ov003_021c1364(0, 0xc0);
}
