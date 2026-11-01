#include "03/code_021c0d2c.h"
#include "03/unk_021d5f00.h"
#include "03/code_021d23b0.h"
#include "03/code_021bf8c0.h"
#include "03/code_021c0000.h"
#include "03/code_021d1000.h"
#include "03/code_021d27d8.h"
#include "03/code_021d1c18.h"
#include "03/code_021d3544.h"
#include "03/unk_021d5000.h"
#include "03/unk_021d6000.h"
#include "03/unk_021da000.h"
#include "03/code_021d2070.h"

// non-matching: 91.1: zero constants and loop counters sit at different stack offsets (frame 0x54 against 0x64, s at
// sp+0x40 against sp+0x50), size 0x298 against 0x2ac
void func_ov003_021c0d2c(void) {
    Unk021c0d2c s;
    Unk021da15c *p;
    int i;
    int j;
    int k;

    s.mUnk_00[0] = 0;
    s.mUnk_00[1] = 0;
    s.mUnk_00[2] = 0;
    s.mUnk_00[3] = 0;
    s.mUnk_00[2] = data_ov003_021d5f7c[0][0];
    s.mUnk_00[3] = data_ov003_021d5f7c[0][1];
    p = func_ov003_021d283c(0x128, 4);
    data_ov003_021da15c = p;
    p->mUnk_11c = 0xff;
    data_ov003_021da15c->mUnk_121 = 0;
    data_ov003_021da15c->mUnk_123 = 1;
    data_ov003_021da15c->mUnk_124 = 1;
    for (i = 0; i < 0x2f; i++) {
        data_ov003_021da15c->mUnk_030[i] = (Unk021bf920 *) func_ov003_021d1c18(0, 0x34);
        data_ov003_021da15c->mUnk_030[i]->mUnk_00 = (data_ov003_021da15c->mUnk_030[i]->mUnk_00 & 0xc1fffcff) | 0x200;
        data_ov003_021da15c->mUnk_030[i]->mUnk_04 = (data_ov003_021da15c->mUnk_030[i]->mUnk_04 & 0xfffff3ff) | 0xc00;
    }
    for (i = 0; i < 4; i++) {
        data_ov003_021da15c->mUnk_0ec[i] = (Unk021bf920 *) func_ov003_021d1c18(0, data_ov003_021d5f70[i]);
        data_ov003_021da15c->mUnk_0ec[i]->mUnk_00 = (data_ov003_021da15c->mUnk_0ec[i]->mUnk_00 & 0xc1fffcff) | 0x200;
        data_ov003_021da15c->mUnk_0ec[i]->mUnk_04 = (data_ov003_021da15c->mUnk_0ec[i]->mUnk_04 & 0xfffff3ff) | 0xc00;
    }
    for (i = 0; i < 2; i++) {
        data_ov003_021da15c->mUnk_0fc[i] = (void *) func_ov003_021d1be4(0, data_ov003_021d5f68[i], 1);
        func_ov003_021d18f0(data_ov003_021da15c->mUnk_0fc[i], -1, 0x200, 0);
        func_ov003_021d1790(data_ov003_021da15c->mUnk_0fc[i], -1, 3);
    }
    s.mUnk_0c[1] = 0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            data_ov003_021da15c->mUnk_000[i][j] =
                func_ov003_021d23b0(0, data_ov003_021d5f74[0], data_ov003_021d5f74[1], 0, &s.mUnk_08, 0);
            s.mUnk_00[0] = 0;
            for (k = 0; k < 12; k++) {
                s.mUnk_0c[0] = data_ov003_021d6be8[i][j * 12 + k];
                func_ov003_021d2070(data_ov003_021da15c->mUnk_000[i][j], s.mUnk_00[0], s.mUnk_00[1], s.mUnk_00[2],
                                    s.mUnk_00[3], 2, 0x480, s.mUnk_0c);
                s.mUnk_00[0] = s.mUnk_00[0] + 0x12;
            }
            if (i == 0) {
                data_ov003_021da15c->mUnk_104[j] = func_ov003_021d19e0(0, s.mUnk_08, 1);
            }
        }
    }
    data_ov003_021da15c->mUnk_114 = (void *) func_ov003_021d1be4(0, 0x40, 1);
    func_ov003_021d18f0(data_ov003_021da15c->mUnk_114, -1, 0x200, 0);
    func_ov003_021d1790(data_ov003_021da15c->mUnk_114, -1, 2);
    data_ov003_021da15c->mUnk_118 = (void *) func_ov003_021d3544(0, (u32) func_ov003_021c0c2c, 0, 0x78);
    func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 0, 0xc0);
}
