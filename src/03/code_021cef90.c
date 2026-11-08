#include "03/code_021cef90.h"
#include "03/code_021bf4dc.h"
#include "03/code_021d1790.h"
#include "03/code_021d197c.h"
#include "03/code_021d1fd0.h"
#include "03/unk_021d5000.h"
#include "03/unk_021da000.h"
#include "03/code_021bf410.h"
#include "03/code_021c250c.h"
#include "03/code_021cea3c.h"
#include "03/code_021d1000.h"
#include "03/code_021d27d8.h"
#include "03/code_021d3488.h"
#include "03/unk_021d6000.h"
#include "03/unk_021d7000.h"
#include "code_0214a390.h"
#include "registers.h"
#include "03/code_021b94b8.h"
#include "Main/Unknown/code_02009000.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/code_02009adc.h"
#include "03/code_021cf260.h"

#pragma opt_dead_assignments off

u16 func_ov003_021cf1e8(u8 *a) {
    u16 i;
    u16 v1;
    Unk021cf260 *s;

    i = 1;
    s = data_ov003_021da288;
    v1 = s->mMask;
    for (; i < 2; i++) {
        if ((v1 & (1 << i)) != 0) {
            u8 *m;
            u8 *p;
            s32 o;

            o = (i - 1) * 0x1e;
            m = s->mRecords[0].mUnk_16;
            p = m + o;
            if (a[0] == m[o] && a[1] == p[1] && a[2] == p[2] && a[3] == p[3] && a[4] == p[4] && a[5] == p[5]) {
                return s->mRecords[i - 1].mUnk_1c;
            }
        }
    }
    return 0;
}

void func_ov003_021cefc0(u32 a, s32 b, s32 c, u32 d, u32 e) {
    Unk021d7864 v1;
    void *v;
    s32 i;
    u32 v2;

    v1 = data_ov003_021d7864;
    v = func_ov003_021c250c(data_ov003_021da19c, a, d, e);
    data_ov003_021da284 = func_ov003_021d283c(0x20, 4);
    data_ov003_021da284->mUnk_1c = b;
    data_ov003_021da284->mUnk_1b = -2;
    data_ov003_021da284->mUnk_1e = c;
    G2x_SetBlendBrightness_(&reg_G2_BLDCNT, 0x1f, 0);
    data_ov003_021da284->mUnk_00 = func_ov003_021d1be4(0, data_ov003_021d6718[b], 0);
    func_ov003_021d17d4(data_ov003_021da284->mUnk_00, -1, 0x100, 0);
    func_ov003_021d1790(data_ov003_021da284->mUnk_00, -1, 0);
    for (i = 0; i < data_ov003_021d6720[b]; i++) {
        data_ov003_021da284->mUnk_08[i] = func_ov003_021d1be4(0, data_ov003_021d6748[b][i], 0);
        func_ov003_021d17d4(data_ov003_021da284->mUnk_08[i], -1, 0x100, 0);
        func_ov003_021d1790(data_ov003_021da284->mUnk_08[i], -1, 0);
    }
    data_ov003_021da284->mUnk_10 = func_ov003_021d23b0(0, 0x20, 0xc, 1, &v2, 0);
    data_ov003_021da284->mUnk_04 = func_ov003_021d19e0(0, v2, 0);
    func_ov003_021d2070(data_ov003_021da284->mUnk_10, 0, 0, data_ov003_021d6768[b][0], data_ov003_021d6768[b][1], 2,
                        GetLanguageTextFlags(), v);
    func_ov003_021d1ffc(data_ov003_021da284->mUnk_10, 0x100, 0, data_ov003_021da284->mUnk_04, 0);
    func_ov003_021d254c(0, 0, 0x1f, 0);
    func_ov003_021d254c(0, 1, 0x1f, v1.mUnk_00[data_ov003_021da284->mUnk_1c]);
    func_ov003_021d254c(0, 3, 0x1f, 1);
    func_ov003_021d2658(0, 1, data_ov003_021d6728);
    func_ov003_021cec50(0xc0);
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffff1fff) | 0x6000;
    if (c != 0) {
        data_ov003_021da284->mUnk_14 = func_ov003_021d3544(1, func_ov003_021cef28, NULL, 0x78);
    } else {
        data_ov003_021da284->mUnk_14 = func_ov003_021d3544(1, func_ov003_021cee98, NULL, 0x78);
    }
}

void func_ov003_021cef90(void) {
    func_ov003_021d34c8(0, data_ov003_021da284->mUnk_14);
    data_ov003_021da284->mUnk_14 = func_ov003_021d3544(1, func_ov003_021ceb54, NULL, 0x78);
}
