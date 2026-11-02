#include "Main/Unknown/code_02028130.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02025eb0.h"
#include "Main/Unknown/code_02028774.h"
#include "Main/Unknown/code_0202881c.h"
#include "Main/Unknown/code_02028724.h"
#include "Main/Unknown/code_02028000.h"
#include "Main/Unknown/code_02078000.h"
#include "Main/Unknown/code_02028d9c.h"
#include "Main/Unknown/code_02028f20.h"
#include "Main/Unknown/code_02029008.h"
#include "Main/Unknown/code_020291f0.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_0202b604.h"
#include "Main/Unknown/code_0202b000.h"
#include "Main/Unknown/code_02027f68.h"
#include "Main/Unknown/code_02148000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02077eb4.h"
#include "Main/Unknown/code_020adb04.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_021105a0.h"
#include "Main/Unknown/code_021106a8.h"
#include "Main/Unknown/code_02116ec0.h"
#include "Main/Unknown/code_0211f378.h"
#include "Main/Unknown/code_0211f394.h"
#include "Main/Unknown/code_02120610.h"
#include "Main/Unknown/code_02121e84.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/code_0212b5ec.h"
#include "Main/Unknown/code_020b502c.h"

#pragma optimize_for_size on

#pragma thumb on
int AdvanceSelectKart(void) {
    Unk02174e18 *d;
    Unk02174e50_24 *p;
    s32 e;
    s32 r;
    s32 t;
    s32 x;
    Unk02174e50_24 *q;
    u32 v;
    d = gSelectKart;
    e = d->mUnk_0a8;
    x = 0;
    r = 0;
    q = &d->mUnk_048;
    p = &d->mUnk_064;
    t = func_020435bc();
    func_02025edc(&gSelectKart->mUnk_0ac);
    func_02025edc(&gSelectKart->mUnk_0bc);
    func_02025edc(&gSelectKart->mUnk_0cc);
    func_02025edc(&gSelectKart->mUnk_0dc);
    func_02025edc(&gSelectKart->mUnk_0ec);
    func_02029008();
    if (func_020280dc() == 0) {
        func_0212b80c();
    }
    if (func_020280dc() == 0) {
        gSelectKart->mUnk_110 = func_020290fc();
    } else {
        gSelectKart->mUnk_110 = -1;
    }
    d = gSelectKart;
    switch (d->mUnk_094) {
        case 0:
            if (d->mUnk_0ec.mUnk_00 == 1) {
                d->mUnk_090 = 0;
                if (func_020280dc() != 0) {
                    v = 1;
                } else {
                    v = 2;
                }
                gSelectKart->mUnk_094 = v;
            }
            func_02028fac();
            break;
        case 1:
            func_02028824(d->mUnk_0a8 | 0x80);
            gSelectKart->mUnk_100 = 1;
            gSelectKart->mUnk_094 = 5;
            break;
        case 2:
            if (func_02028774(t) != 0) {
                x = func_02128210(func_0202874c(t), func_02028724(t));
            }
            if (func_020286f4(t, 1) != 0 || gSelectKart->mUnk_110 == 2 || func_02028f84() != 0) {
                gSelectKart->mUnk_090 = 0;
                gSelectKart->mUnk_100 = 1;
                gSelectKart->mUnk_094 = 4;
                p->mUnk_18[18].mUnk_00 = 0;
                func_02124100(data_usa_02153834[4], 0, p->mUnk_14, p->mUnk_18, p->mUnk_0c);
                func_021106a8(func_02025eb0(gSelectKart->mUnk_0a4), 1);
                func_02077f48(1);
                func_0212b7e8();
            } else if (func_020286f4(t, 2) != 0 || x != 0) {
                gSelectKart->mUnk_090 = 0;
                gSelectKart->mUnk_100 = 2;
                func_0202941c(0);
                func_02025f14(&gSelectKart->mUnk_0bc, 2);
                func_02025f14(&gSelectKart->mUnk_0dc, 2);
                func_02025f14(&gSelectKart->mUnk_0ec, 2);
                gSelectKart->mUnk_094 = 7;
                if (gSelectKart->mUnk_0fc != 0) {
                    v = 1;
                } else {
                    v = 0;
                }
                func_02128310(v);
            } else if (func_020ae408(t, 0x10) != 0 || func_020290ac(1) != 0) {
                func_020292bc();
                gSelectKart->mUnk_114 = 3;
                p->mUnk_18[1].mUnk_00 = 0;
                p->mUnk_18[3].mUnk_00 = 1;
            } else if (func_020ae408(t, 0x20) != 0 || func_020290ac(0) != 0) {
                func_02029248();
                gSelectKart->mUnk_114 = 2;
                p->mUnk_18[0].mUnk_00 = 0;
                p->mUnk_18[2].mUnk_00 = 1;
            }
            if (e != gSelectKart->mUnk_0a8) {
                func_02110698();
                func_02028f20();
                func_02028e38();
                gSelectKart->mUnk_094 = 3;
                gSelectKart->mUnk_090 = 0;
            }
            break;
        case 3:
            d->mUnk_090 = d->mUnk_090 + 1;
            if (gSelectKart->mUnk_090 > 6) {
                gSelectKart->mUnk_090 = 0;
                gSelectKart->mUnk_094 = 2;
                p->mUnk_18[gSelectKart->mUnk_114].mUnk_04 = 0;
                p->mUnk_18[1].mUnk_00 = 1;
                p->mUnk_18[0].mUnk_00 = 1;
                p->mUnk_18[3].mUnk_00 = 0;
                p->mUnk_18[2].mUnk_00 = 0;
            } else {
                v = func_020adc64(gSelectKart->mUnk_090);
                if (gSelectKart->mUnk_114 == 2) {
                    v = -v;
                }
                p->mUnk_18[gSelectKart->mUnk_114].mUnk_04 = v;
            }
            break;
        case 4:
            d->mUnk_090 = d->mUnk_090 + 1;
            d = gSelectKart;
            if (d->mUnk_090 >= 5) {
                switch (d->mUnk_0fc) {
                    case 0:
                        func_02029930()->mUnk_00[gSelectKart->mUnk_0a0].mUnk_04 = d->mUnk_0a8;
                        func_02029930()->mUnk_00[gSelectKart->mUnk_0a0].mUnk_14 = 1;
                        func_02116ef8();
                        gSelectKart->mUnk_094 = 6;
                        break;
                    case 1:
                        func_021282c8();
                        func_02028824(gSelectKart->mUnk_0a8 | 0x80);
                        gSelectKart->mUnk_094 = 5;
                        break;
                    case 2:
                        func_021282c8();
                        func_02121eb4(gSelectKart->mUnk_0a8);
                        gSelectKart->mUnk_094 = 5;
                        break;
                }
                gSelectKart->mUnk_090 = 0;
                p->mUnk_18[18].mUnk_00 = 1;
                func_02124100(data_usa_02153834[4], 1, p->mUnk_14, p->mUnk_18, p->mUnk_0c);
            }
            break;
        case 5:
            if (d->mUnk_0fc == 1 && func_0202b888() != 0 || gSelectKart->mUnk_0fc == 2 && func_02121d0c() != 0) {
                gSelectKart->mUnk_090 = 0;
                gSelectKart->mUnk_094 = 6;
            }
            break;
        case 6:
            d->mUnk_090 = d->mUnk_090 + 1;
            if (gSelectKart->mUnk_090 > 0x3c) {
                func_02025f14(&gSelectKart->mUnk_0ac, 2);
                func_02025f14(&gSelectKart->mUnk_0bc, 2);
                func_02025f14(&gSelectKart->mUnk_0cc, 2);
                func_02025f14(&gSelectKart->mUnk_0dc, 2);
                func_02025f14(&gSelectKart->mUnk_0ec, 2);
                if (gSelectKart->mUnk_0fc == 2) {
                    func_021219cc();
                    func_0202941c(3);
                } else {
                    func_0202941c(2);
                }
                if (func_020280dc() == 0) {
                    func_020789d4();
                } else {
                    func_0211f378();
                }
                gSelectKart->mUnk_090 = 0;
                gSelectKart->mUnk_094 = 7;
            }
            break;
        case 7:
            if (d->mUnk_0ec.mUnk_00 == 3) {
                func_02029930()->mUnk_00[gSelectKart->mUnk_0a0].mUnk_14 = d->mUnk_100 == 1;
                gSelectKart->mUnk_094 = 8;
            }
            func_02028fac();
            break;
        case 8:
            r = d->mUnk_100;
            break;
    }
    if (func_020280dc() == 0) {
        func_02078a9c(gSelectKart->mUnk_0a4);
        func_02078a34(gSelectKart->mUnk_0a8);
        func_02078420(func_02029930()->mUnk_d8);
        func_020780f4();
    }
    d = gSelectKart;
    if (d->mUnk_104 != FALSE) {
        func_0202bb80();
    } else {
        func_02124c30(q->mUnk_0c, q->mUnk_08, NULL, d->mUnk_080, q->mUnk_18);
    }
    if (func_020280dc() == 0) {
        d = gSelectKart;
        if (d->mUnk_094 != 8) {
            func_02124c30(p->mUnk_0c, p->mUnk_08, p->mUnk_14, d->mUnk_084, p->mUnk_18);
        }
    } else {
        func_0211f39c();
    }
    switch (r) {
        case 1:
            func_02029930()->mUnk_108 = 0;
            break;
        case 2:
            func_02029930()->mUnk_108 = 2;
            break;
    }
    return r;
}
#pragma thumb off

u16 func_020286f4(u32 a, u32 b) {
    return func_02028710(&data_02175628[a], b);
}

u16 func_02028710(Unk02175628 *a, u32 b) {
    return a->mUnk_00 & b;
}
