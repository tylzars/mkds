#include "Main/Unknown/code_02028864.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02025df4.h"
#include "Main/Unknown/code_02025e34.h"
#include "Main/Unknown/code_02028d9c.h"
#include "Main/Unknown/code_02028f20.h"
#include "Main/Unknown/code_02027f68.h"
#include "Main/Unknown/code_020291f0.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_0202c000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_02056444.h"
#include "Main/Unknown/code_02148000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02077eb4.h"
#include "Main/Unknown/code_02078000.h"
#include "Main/Unknown/code_0211f394.h"
#include "Main/Unknown/code_0211f4b0.h"
#include "Main/Unknown/code_02116ec0.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_021281dc.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/code_0212b928.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "code_02148ca0.h"
#include "Main/Unknown/unk_02161000.h"

#pragma optimize_for_size on

#pragma thumb on
void func_02028864(void *a, s32 b, void *c, void *d) {
    void *h;
    Unk02174e50_24 *p;
    Unk02174e50_24 e;
    Unk02174e50_24 f;
    Unk02174e18 *g;
    s32 i;
    s32 m;
    s32 n;
    u32 v;
    void *w;
    h = func_02036948(a);
    data_02174e18 = func_02036bec(h, 0x118);
    func_02028e00(data_02174e18, 0x118);
    data_02174e18->mUnk_08c = h;
    data_02174e18->mUnk_0fc = b;
    data_02174e18->mUnk_110 = -1;
    switch (func_02029930()->mUnk_108) {
        case 1:
            func_02025f80(&data_02174e18->mUnk_0ac, 1, 10, -0x80, 0);
            func_02025f80(&data_02174e18->mUnk_0cc, 1, 10, 0x60, 0);
            break;
        case 0:
            func_02025f80(&data_02174e18->mUnk_0ac, 0, 10, -0x80, 0);
            func_02025f80(&data_02174e18->mUnk_0cc, 0, 10, 0x60, 0);
            if (func_020280dc() == 0) {
                func_020789e4();
                func_02077f48(0);
            }
            break;
    }
    func_02025f80(&data_02174e18->mUnk_0bc, 0, 10, -0x40, 0);
    func_02025f80(&data_02174e18->mUnk_0dc, 0, 10, 0x40, 0);
    func_02025f80(&data_02174e18->mUnk_0ec, 0, 10, -0xc0, 0);
    data_02174e18->mUnk_080 = c;
    data_02174e18->mUnk_084 = d;
    if (data_02174e18->mUnk_0fc != 0 || func_02029930()->mUnk_c8 == 3 || func_02029930()->mUnk_c8 == 2) {
        v = 1;
    } else {
        v = 0;
    }
    data_02174e18->mUnk_104 = v;
    if (data_02174e18->mUnk_104 != 0) {
        switch (data_02174e18->mUnk_0fc) {
            case 0:
                m = 0;
                break;
            case 1:
                m = 1;
                break;
            case 2:
                m = 2;
                break;
        }
        func_0202c0d4(m, 1);
    }
    switch (data_02174e18->mUnk_0fc) {
        case 0:
            data_02174e18->mUnk_0a0 = 0;
            break;
        case 1:
            data_02174e18->mUnk_0a0 = func_02028d9c();
            break;
        case 2:
            data_02174e18->mUnk_0a0 = func_020295e4();
            break;
    }
    if (func_020280dc() == 0) {
        data_02174e18->mUnk_088 = func_02047a28(data_usa_02161ef0);
        data_02174e18->mUnk_098 = func_02056444(data_02174e18->mUnk_08c);
    }
    g = data_02174e18;
    g->mUnk_0a4 = func_02029930()->mUnk_00[g->mUnk_0a0].mUnk_00;
    g = data_02174e18;
    g->mUnk_0a8 = func_02029930()->mUnk_00[g->mUnk_0a0].mUnk_04;
    if (data_02174e18->mUnk_0a4 == -1) {
        data_02174e18->mUnk_0a4 = 0;
    }
    if (data_02174e18->mUnk_0a8 == -1) {
        data_02174e18->mUnk_0a8 = 0;
    }
    func_02029930()->mUnk_00[data_02174e18->mUnk_0a0].mUnk_04 = -1;
    func_02029930()->mUnk_00[data_02174e18->mUnk_0a0].mUnk_14 = 0;
    data_02174e18->mUnk_09c = func_02025e34(data_02174e18->mUnk_0a8);
    if (func_020280dc() == 0) {
        g = data_02174e18;
        if (g->mUnk_104 == 0) {
            p = &g->mUnk_048;
            func_02025b20(p, data_usa_02161f00, data_usa_02161f20, data_usa_02161f40, data_usa_02161f60, 0, 0,
                          func_02047a28);
            func_02025a50(0, data_02174e18->mUnk_08c, p);
            func_02025b20(&e, data_usa_02161f7c, data_usa_02161fa4, 0, data_usa_02161fcc, 0, 0, func_02047a28);
            func_02124748(1, e.mUnk_08, (void *) e.mUnk_00, e.mUnk_0c, 0, 0, p->mUnk_08, p->mUnk_0c);
            func_02025b20(&f, data_usa_02161ff0, data_usa_02162014, 0, data_usa_02162038, 0, 0, func_02047a28);
            func_02124748(data_usa_021537dc[data_02174e18->mUnk_0a4], f.mUnk_08, (void *) f.mUnk_00, f.mUnk_0c, 0, 2,
                          p->mUnk_08, p->mUnk_0c);
            func_02124748(data_usa_021537dc[data_02174e18->mUnk_0a4], f.mUnk_08, (void *) f.mUnk_00, f.mUnk_0c, 0, 1,
                          p->mUnk_08, p->mUnk_0c);
        }
    }
    if (func_020280dc() == 0) {
        func_020258d4(1, &data_02174e18->mUnk_024, data_usa_02162058, data_usa_02162070, data_usa_02162088, 3,
                      func_02047a28);
    }
    if (func_020280dc() == 0) {
        n = func_02148ca0();
        p = &data_02174e18->mUnk_064;
        func_02025b20(p, data_usa_0216209c, data_usa_021620b4, data_usa_021620cc, data_usa_021620e4, data_usa_021620f8,
                      data_usa_0216210c, func_02047a28);
        func_02025a50(1, data_02174e18->mUnk_08c, p);
        for (i = 0; i < 9; i++) {
            n -= func_02025a00(1, data_02174e18->mUnk_08c, p, &data_usa_021537f4[i], n);
        }
        for (i = 0; i < 6; i++) {
            w = GetBmgEntry(data_02174e18->mUnk_088, data_usa_021537f4[i].mUnk_08);
            n = data_usa_021537f4[i].mUnk_00;
            func_0212426c(1, n, p->mUnk_14, w, p->mUnk_0c, p->mUnk_18);
            func_02124094(n, 1, p->mUnk_14, p->mUnk_18, p->mUnk_0c);
        }
        w = GetBmgEntry(func_02047a28(data_usa_02162120), data_usa_021537f4[6].mUnk_08);
        i = data_usa_02153834[4];
        func_0212426c(1, i, p->mUnk_14, w, p->mUnk_0c, p->mUnk_18);
        func_02124100(i, 1, p->mUnk_14, p->mUnk_18, p->mUnk_0c);
        func_0212b928(data_02174e18->mUnk_08c, (Unk020b4a44 *) p->mUnk_04, 1);
        p->mUnk_18[2].mUnk_00 = 0;
        p->mUnk_18[3].mUnk_00 = p->mUnk_18[2].mUnk_00;
    } else {
        func_0211f4b0(data_02174e18->mUnk_08c, data_02174e18->mUnk_084);
        func_0211f394();
    }
    func_02028e38();
    func_02029330();
    func_02028f20();
    if (func_020280dc() == 0) {
        func_02128374();
    }
    if (func_0202811c() == 2) {
        func_021281dc();
    }
    if (data_02174e18->mUnk_0fc == 0) {
        func_02117060();
    }
    func_02036820(h);
}
#pragma thumb off
