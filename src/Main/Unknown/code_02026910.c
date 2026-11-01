#include "Main/Unknown/code_02026910.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02025b84.h"
#include "Main/Unknown/code_02025bb4.h"
#include "Main/Unknown/code_02027000.h"
#include "Main/Unknown/code_02029520.h"
#include "Main/Unknown/code_02029930.h"
#include "Main/Unknown/code_0202c000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/code_0204799c.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_02077f0c.h"
#include "Main/Unknown/code_02078000.h"
#include "Main/Unknown/code_02116ec0.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_0211f394.h"
#include "Main/Unknown/code_0211f4b0.h"
#include "Main/Unknown/code_02121e84.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_021281b4.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

void func_02026910(void *a, s32 b, void *c, void *d) {
    void *h;
    Unk02174e14 *p;
    Unk02174e14_00 *s;
    Unk021534bc *t;
    s32 i;
    s32 j;
    s32 k;
    s32 f;
    Unk02174e14_00 v;
    Unk02174e14_00 w;

    h = func_02036948(a);
    data_02174e14 = func_02036bec(h, 0x12c);
    func_0214d05c_inline(data_02174e14, 0x12c);
    data_02174e14->mUnk_05c = h;
    data_02174e14->mUnk_080 = b;
    switch (func_02029930()->mUnk_108) {
        case 0:
            func_02025f80(&data_02174e14->mUnk_0f8, 0, 10, -0x80, 0);
            func_02025f80(&data_02174e14->mUnk_118, 0, 10, 0x60, 0);
            if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
                func_020789e4();
            }
            break;
        case 2:
            func_02025f80(&data_02174e14->mUnk_0f8, 1, 10, -0x80, 0);
            func_02025f80(&data_02174e14->mUnk_118, 1, 10, 0x60, 0);
            switch (data_02174e14->mUnk_080) {
                case 1:
                    if (data_0217aa00->mUnk_0004 == 8) {
                        data_0217aa00->mUnk_15f7 = 0xff;
                    }
                    break;
                case 2:
                    func_02121ee4();
                    break;
            }
            break;
    }
    func_02025f80(&data_02174e14->mUnk_108, 0, 10, -0x40, 0);
    data_02174e14->mUnk_054 = c;
    data_02174e14->mUnk_058 = d;
    if (data_02174e14->mUnk_080 != 0 || func_02029930()->mUnk_c8 == 3 || func_02029930()->mUnk_c8 == 2) {
        f = 1;
    } else {
        f = 0;
    }
    data_02174e14->mUnk_128 = f;
    if (data_02174e14->mUnk_128 != 0) {
        switch (data_02174e14->mUnk_080) {
            case 0:
                k = 0;
                break;
            case 1:
                k = 1;
                break;
            case 2:
                k = 2;
                break;
        }
        func_0202c0d4(k, 0);
    }
    p = data_02174e14;
    switch (p->mUnk_080) {
        case 0:
            p->mUnk_078 = 0;
            break;
        case 1:
            p->mUnk_078 =
                data_0217aa00->mUnk_1e52[(u16) (data_0217aa00->mUnk_0000 == 2 ? data_0217aa00->mUnk_0432 : 0)].mUnk_00;
            break;
        case 2:
            data_02174e14->mUnk_078 = func_020295e4();
            break;
    }
    p = data_02174e14;
    if (p->mUnk_128 == 0) {
        func_02025b20(&p->mUnk_000, data_02161c88, data_02161ca8, data_02161cc8, data_02161ce8, 0, 0, func_02047a28);
        func_02025a50(0, data_02174e14->mUnk_05c, &p->mUnk_000);
        func_02025b20(&v, data_02161d04, data_02161d2c, 0, data_02161d54, 0, 0, func_02047a28);
        func_02124748(0, v.mUnk_08, v.mUnk_00, v.mUnk_0c, 0, 0, p->mUnk_000.mUnk_08, p->mUnk_000.mUnk_0c);
        func_02025b20(&data_02174e14->mUnk_038, data_02161d78, data_02161d9c, 0, data_02161dc0, 0, 0, func_02047a28);
        p->mUnk_000.mUnk_18[9].mUnk_00 = 0;
        p->mUnk_000.mUnk_18[8].mUnk_00 = p->mUnk_000.mUnk_18[9].mUnk_00;
        p->mUnk_000.mUnk_18[7].mUnk_00 = p->mUnk_000.mUnk_18[8].mUnk_00;
        p->mUnk_000.mUnk_18[6].mUnk_00 = p->mUnk_000.mUnk_18[7].mUnk_00;
        p->mUnk_000.mUnk_18[5].mUnk_00 = p->mUnk_000.mUnk_18[6].mUnk_00;
        p->mUnk_000.mUnk_18[4].mUnk_00 = p->mUnk_000.mUnk_18[5].mUnk_00;
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        s = &data_02174e14->mUnk_01c;
        func_02025b20(s, data_02161de0, data_02161dfc, data_02161e18, data_02161e34, 0, data_02161e4c, func_02047a28);
        func_02025a50(1, data_02174e14->mUnk_05c, s);
        s->mUnk_18[24].mUnk_00 = 0;
        for (i = 0; i < 12; i++) {
            s->mUnk_18[data_usa_02153554[i].mUnk_04].mUnk_10 = 1;
            s->mUnk_18[data_usa_02153554[i].mUnk_02].mUnk_10 = s->mUnk_18[data_usa_02153554[i].mUnk_04].mUnk_10;
            s->mUnk_18[data_usa_02153554[i].mUnk_00].mUnk_10 = s->mUnk_18[data_usa_02153554[i].mUnk_02].mUnk_10;
            s->mUnk_18[data_usa_02153554[i].mUnk_04].mUnk_34 = 0;
            s->mUnk_18[data_usa_02153554[i].mUnk_02].mUnk_34 = s->mUnk_18[data_usa_02153554[i].mUnk_04].mUnk_34;
            s->mUnk_18[data_usa_02153554[i].mUnk_00].mUnk_34 = s->mUnk_18[data_usa_02153554[i].mUnk_02].mUnk_34;
        }
        s->mUnk_18[25].mUnk_10 = 1;
        s->mUnk_18[24].mUnk_10 = s->mUnk_18[25].mUnk_10;
        s->mUnk_18[25].mUnk_34 = 0;
        s->mUnk_18[24].mUnk_34 = s->mUnk_18[25].mUnk_34;
    } else if (func_02029930()->mUnk_c8 == 2) {
        func_0211f4b0(data_02174e14->mUnk_05c, data_02174e14->mUnk_058);
        func_0211f394();
    }
    data_02174e14->mUnk_07c = 8;
    for (i = 0; i < 8; i++) {
        data_02174e14->mUnk_090[i] = data_021535b4[i];
    }
    if (func_02056dec(0x15) != 0) {
        data_02174e14->mUnk_090[i] = data_021535b4[8];
        i++;
        data_02174e14->mUnk_07c++;
    }
    if (func_02056dec(0x14) != 0) {
        data_02174e14->mUnk_090[i] = data_021535b4[9];
        i++;
        data_02174e14->mUnk_07c++;
    }
    if (func_02056dec(0x16) != 0) {
        data_02174e14->mUnk_090[i] = data_021535b4[10];
        i++;
        data_02174e14->mUnk_07c++;
    }
    if (func_02056dec(0x17) != 0) {
        data_02174e14->mUnk_090[i] = data_021535b4[11];
        i++;
        data_02174e14->mUnk_07c++;
    }
    for (; i < 12; i++) {
        data_02174e14->mUnk_090[i].mUnk_00 = -1;
    }
    for (j = 0; j < data_02174e14->mUnk_07c; j++) {
        if (data_02174e14->mUnk_090[j].mUnk_00 == func_02029930()->mUnk_00[data_02174e14->mUnk_078].mUnk_00) {
            data_02174e14->mUnk_060 = j;
        }
    }
    data_02174e14->mUnk_064 = data_02174e14->mUnk_060;
    p = data_02174e14;
    p->mUnk_0f0 = func_02029930()->mUnk_00[p->mUnk_078].mUnk_00;
    if (data_02174e14->mUnk_0f0 == -1) {
        data_02174e14->mUnk_0f0 = 0;
    }
    data_02174e14->mUnk_0f4 = func_02025e60(data_02174e14->mUnk_0f0);
    func_02029930()->mUnk_00[data_02174e14->mUnk_078].mUnk_00 = -1;
    func_02029930()->mUnk_00[data_02174e14->mUnk_078].mUnk_04 = -1;
    func_02029930()->mUnk_00[data_02174e14->mUnk_078].mUnk_14 = 0;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        s = &data_02174e14->mUnk_01c;
        func_02025b84(0, &w);
        for (i = 0; i < data_02174e14->mUnk_07c; i++) {
            func_0212481c(data_02174e14->mUnk_090[i].mUnk_00, w.mUnk_08, w.mUnk_00, w.mUnk_04, w.mUnk_0c, 1,
                          data_usa_02153554[i].mUnk_02, s->mUnk_08, s->mUnk_0c);
        }
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        t = 0;
        s = &data_02174e14->mUnk_01c;
        switch (data_02174e14->mUnk_07c) {
            case 8:
                t = data_021534bc;
                func_02027be0();
                break;
            case 9:
                t = data_021534dc;
                func_02027a58();
                break;
            case 10:
                t = data_02153500;
                func_02027850();
                break;
            case 11:
                t = data_02153528;
                func_02027648();
                break;
            case 12:
                func_02027448();
                break;
        }
        if (t != 0) {
            for (i = 0; i < data_02174e14->mUnk_07c; i++) {
                func_02025c94(data_usa_02153554[i].mUnk_00, t[i].mUnk_00, t[i].mUnk_02, s->mUnk_0c);
                func_02025c94(data_usa_02153554[i].mUnk_02, t[i].mUnk_00, t[i].mUnk_02, s->mUnk_0c);
                func_02025bb4(data_usa_02153554[i].mUnk_06, t[i].mUnk_00, t[i].mUnk_02, s->mUnk_10);
                func_02025c94(data_usa_02153554[i].mUnk_04, (s16) (t[i].mUnk_00 + 3), (s16) (t[i].mUnk_02 + 3),
                              s->mUnk_0c);
            }
            for (; i < 12; i++) {
                s->mUnk_18[data_usa_02153554[i].mUnk_00].mUnk_00 = 0;
                s->mUnk_18[data_usa_02153554[i].mUnk_02].mUnk_00 = 0;
                s->mUnk_18[data_usa_02153554[i].mUnk_04].mUnk_00 = 0;
                func_02025bb4(data_usa_02153554[i].mUnk_06, 0x400, 0x400, s->mUnk_10);
            }
        }
        func_020271e8();
        func_0202721c();
    }
    if (data_02174e14->mUnk_080 == 0) {
        func_021170f8();
        func_021281c8(0xe);
        func_02128374();
    }
    if (func_02036c5c() != 0) {
        data_02174e14->mUnk_06c = 1;
    } else {
        func_02037288(10);
        func_0202734c(0);
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        func_02077f48(0);
    }
    func_02036820(data_02174e14->mUnk_05c);
}
