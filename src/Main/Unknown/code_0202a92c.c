#include "Main/Unknown/code_0202a92c.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02025bb4.h"
#include "Main/Unknown/code_02025d5c.h"
#include "Main/Unknown/code_02025d8c.h"
#include "Main/Unknown/code_02025edc.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_0202cb2c.h"
#include "Main/Unknown/code_0202db04.h"
#include "Main/Unknown/code_0202e468.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_020ae428.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02120610.h"
#include "Main/Unknown/code_02121e24.h"
#include "Main/Unknown/code_02121e84.h"
#include "Main/Unknown/code_02122734.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02124bf0.h"
#include "code_02148ca0.h"
#include "Main/Unknown/unk_0217d068.h"
#include "00/code_02182fdc.h"
#include "code_0200f5ac.h"
#include "code_0201ea30.h"
#include "code_0201ea58.h"
#include "code_0212df7c.h"
#include "code_0214d018.h"

#pragma thumb on

s32 AdvanceWiFiVSCourseSelect(void) {
    Unk02174e28 *d;
    Unk02174e14_00 *p;
    s32 r = 0;
    s32 i;
    s32 v;

    func_0202e4b0();
    func_0202b100();
    switch (gWiFiVSCourseSelect->mUnk_0ac) {
        case 0:
            if (func_02036c5c() == 0) {
                break;
            }
            if (gWiFiVSCourseSelect->mUnk_0cc[0].mUnk_00 == 1) {
                gWiFiVSCourseSelect->mUnk_0ac = 1;
            }
            func_0202b264();
            break;
        case 1:
            if (func_0202e468() != 0) {
                func_0212ecc0(&data_0217d068, 0, 0x208);
            }
            if (func_0202e47c() == 0 && gWiFiVSCourseSelect->mUnk_140 != 0) {
                break;
            }
            v = func_0202e4a4();
            if (v == 0) {
                v = func_0202af60();
            } else {
                v--;
            }
            func_02121e84(data_usa_02153a4c[v]);
            gWiFiVSCourseSelect->mUnk_0ac = 2;
            gWiFiVSCourseSelect->mUnk_0b0 = 1;
            func_0202e490(0);
            break;
        case 2:
            if (func_02121cd0() != 0) {
                gWiFiVSCourseSelect->mUnk_0ac = 3;
                func_02025f14(&gWiFiVSCourseSelect->mUnk_0cc[2], 2);
            }
            break;
        case 3:
            gWiFiVSCourseSelect->mUnk_13c++;
            if (gWiFiVSCourseSelect->mUnk_13c > 0x3c) {
                func_02036e20(0x3c, 1);
                gWiFiVSCourseSelect->mUnk_0ac = 4;
                gWiFiVSCourseSelect->mUnk_13c = 0;
                func_0212ecc0(&data_0217d068, 0, 0x209);
            }
            break;
        case 4:
            gWiFiVSCourseSelect->mUnk_13c++;
            if (gWiFiVSCourseSelect->mUnk_13c <= 0x3c) {
                func_0202b3f4();
            } else {
                func_02037334(10, 1);
                gWiFiVSCourseSelect->mUnk_0ac = 5;
                gWiFiVSCourseSelect->mUnk_13c = 0;
                func_0202b2bc();
            }
            break;
        case 5:
            gWiFiVSCourseSelect->mUnk_13c++;
            if (gWiFiVSCourseSelect->mUnk_13c > 0x3c) {
                func_02036f10(10);
                gWiFiVSCourseSelect->mUnk_0ac = 6;
                gWiFiVSCourseSelect->mUnk_13c = 0;
            }
            break;
        case 6:
            gWiFiVSCourseSelect->mUnk_13c++;
            if (gWiFiVSCourseSelect->mUnk_13c > 10) {
                gWiFiVSCourseSelect->mUnk_0ac = 7;
                gWiFiVSCourseSelect->mUnk_13c = 0;
            }
            break;
        case 7:
            r = gWiFiVSCourseSelect->mUnk_0b0;
            break;
    }
    func_0202afe4();
    func_02025edc(&gWiFiVSCourseSelect->mUnk_0cc[1]);
    for (i = 0; i < 2; i++) {
        d = gWiFiVSCourseSelect;
        p = &d->mUnk_048;
        func_02124c30(p[i].mUnk_0c, p[i].mUnk_08, p[i].mUnk_14, d->mUnk_080[i], p[i].mUnk_18);
    }
    return r;
}

void InitWiFiVSCourseSelect(u32 param_1, u32 param_2, u32 param_3) {
    void *h;
    Unk02174e14_00 *p;
    Unk02174e14_00 *t;
    Unk020f41c4_B *l;
    u32 a;
    u32 s;
    u32 k;
    s32 i;
    s32 n;
    s32 m;
    s32 j;
    s32 q;
    Unk02124b1c *e;
    u16 w[2];

    h = func_02036948((void *) param_1);
    gWiFiVSCourseSelect = func_02036bec(h, 0x158);
    func_0214d05c_inline(gWiFiVSCourseSelect, 0x158);
    gWiFiVSCourseSelect->mUnk_090 = h;
    gWiFiVSCourseSelect->mUnk_080[0] = (void *) param_2;
    gWiFiVSCourseSelect->mUnk_080[1] = (void *) param_3;
    gWiFiVSCourseSelect->mUnk_088 = func_02047a28(gCommonBmgName3);
    gWiFiVSCourseSelect->mUnk_08c = FindSceneFile(gWiFiBmgName);
    a = func_0200f5ac();
    s = (a << 16) + (u32) func_0200f5ac();
    l = &gWiFiVSCourseSelect->mUnk_094;
    l->mUnk_00 = s;
    l->mUnk_08 = 0x5d588b656c078965;
    l->mUnk_10 = 0x269ec3;
    gWiFiVSCourseSelect->mUnk_0b8 = func_020295d0();
    gWiFiVSCourseSelect->mUnk_0b4 = func_020295e4();
    gWiFiVSCourseSelect->mUnk_140 = 0x4b0;
    gWiFiVSCourseSelect->mUnk_154 = -0xc0;
    for (i = 0; i < 4; i++) {
        gWiFiVSCourseSelect->mUnk_0bc[i] = 0;
        func_02025f80(&gWiFiVSCourseSelect->mUnk_0fc[i], 3, 10, 0xfc, 0);
    }
    func_02025f80(&gWiFiVSCourseSelect->mUnk_0cc[1], 0, 10, -0x40, 0);
    func_02025f80(&gWiFiVSCourseSelect->mUnk_0cc[0], 0, 10, -0xc0, 0);
    func_02025f80(&gWiFiVSCourseSelect->mUnk_0cc[2], 0, 10, 0x40, 0);
    *(vu16 *) 0x4000008 = (*(vu16 *) 0x4000008 & 0x43) | 0xc00;
    func_020258d4(0, gWiFiVSCourseSelect, gWiFiVSCourseSelectMBNcgrName, gWiFiVSCourseSelectMBNclrName, gWiFiVSCourseSelectMNscrName, 0, FindSceneFile);
    p = &gWiFiVSCourseSelect->mUnk_048;
    k = func_02148cb8();
    func_02025b20(p, gWiFiVSCourseSelectMNcgrName, gWiFiVSCourseSelectMNcerName, gWiFiVSCourseSelectMONclrName, gWiFiVSCourseSelectMBnclName, gWiFiVSCourseSelectMBnllName, NULL,
                  FindSceneFile);
    func_02025a50(0, gWiFiVSCourseSelect->mUnk_090, p);
    n = p->mUnk_0c->mUnk_06;
    for (i = 0; i < n; i++) {
        func_021249a8(i, 1, p->mUnk_08, p->mUnk_0c);
    }
    for (i = 0; i < p->mUnk_14->mUnk_06; i++) {
        k -= func_02025a00(0, gWiFiVSCourseSelect->mUnk_090, p, &data_usa_021539f4[i], k);
    }
    for (i = gWiFiVSCourseSelect->mUnk_0b8; i < 4; i++) {
        p->mUnk_18[data_usa_021539d8[i]].mUnk_00 = 0;
        p->mUnk_18[n + data_usa_021539f4[i].mUnk_00].mUnk_00 = 0;
    }
    for (i = 0; i < n; i++) {
        func_021249a8(i, 2, p->mUnk_08, p->mUnk_0c);
    }
    p->mUnk_18[4].mUnk_06 = 0x60 - (((s16 *) func_0201ea30(p->mUnk_0c, 4))[1] << 20 >> 20);
    p->mUnk_18[4].mUnk_00 = 0;
    func_020258d4(1, &gWiFiVSCourseSelect->mUnk_000[1], gWiFiVSCourseSelectSBNcgrName, gWiFiVSCourseSelectSBNclrName, gWiFiVSCourseSelectSNscrName, 3,
                  FindSceneFile);
    t = &gWiFiVSCourseSelect->mUnk_064;
    k = func_02148ca0();
    func_02025b20(t, gWiFiVSCourseSelectSNcgrName, gWiFiVSCourseSelectSNcerName, gWiFiVSCourseSelectSONclrName, gWiFiVSCourseSelectSBnclName, gWiFiVSCourseSelectSBnllName,
                  gWiFiVSCourseSelectSBnblName, FindSceneFile);
    func_02025a50(1, gWiFiVSCourseSelect->mUnk_090, t);
    m = t->mUnk_0c->mUnk_06;
    for (j = 0; j < m; j++) {
        func_021249a8(j, 1, t->mUnk_08, t->mUnk_0c);
    }
    for (j = 0; j < t->mUnk_14->mUnk_06; j++) {
        k -= func_02025a00(1, gWiFiVSCourseSelect->mUnk_090, t, &data_usa_02153a14[j], k);
    }
    for (j = 0; j < m; j++) {
        func_021249a8(j, 2, t->mUnk_08, t->mUnk_0c);
    }
    for (i = 0; i < 7; i++) {
        n = data_usa_02153a14[i].mUnk_06;
        q = data_usa_02153a14[i].mUnk_00;
        e = t->mUnk_18;
        func_02025c1c(n, (int) (e + n), (u32) t->mUnk_0c);
        func_02025bf0(q, (int) (e + q + m), (u32) t->mUnk_14);
    }
    func_02025c1c(7, (int) (t->mUnk_18 + 7), (u32) t->mUnk_0c);
    w[0] = 0;
    w[1] = m;
    func_0202e530(gWiFiVSCourseSelect->mUnk_090, 2, w, 7, 8, 0x7c, t->mUnk_18, t->mUnk_10,
                  (u8 *) gWiFiVSCourseSelect->mUnk_000[1].mUnk_14[3] + 0xc, 5, 6, 0, 0x15, func_0202b4bc);
    func_02036820(gWiFiVSCourseSelect->mUnk_090);
}

s32 func_0202af60(void) {
    Unk02174e28 *o;
    Unk020f41c4_B *r;
    Unk0217b488 *d;
    s32 i;
    s32 v;
    BOOL f;
    u32 t;
    u32 *q;

    o = gWiFiVSCourseSelect;
    r = &o->mUnk_094;
    r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
    v = (u16) (r->mUnk_00 >> 32 >> 20) % 20;
    d = data_0217b488;
    do {
        f = TRUE;
        v = (v + 1) % 20;
        i = 0;
        q = (u32 *) d;
        t = data_usa_02153a4c[v];
        for (; i < 4; i++) {
            if (q[0x17] == t) {
                f = FALSE;
                break;
            }
            q++;
        }
    } while (f == FALSE);
    return v;
}

void func_0202afe4(void) {
    s32 v;
    Unk02174e14_00 *p;
    Unk0201ea30 *b;
    void *a;

    v = 0;
    p = &gWiFiVSCourseSelect->mUnk_048;
    func_02025edc(&gWiFiVSCourseSelect->mUnk_0cc[2]);
    p->mUnk_18[16].mUnk_04 = func_02025ebc(&gWiFiVSCourseSelect->mUnk_0cc[2]);
    p->mUnk_18[15].mUnk_04 = p->mUnk_18[16].mUnk_04;
    switch (gWiFiVSCourseSelect->mUnk_0ac) {
        case 0:
        case 1:
        case 2:
            if (gWiFiVSCourseSelect->mUnk_140 != 0) {
                gWiFiVSCourseSelect->mUnk_140--;
                v = (gWiFiVSCourseSelect->mUnk_140 + 0x3c) / 0x3c;
                p->mUnk_18[15].mUnk_00 = v >= 10 ? 1 : 0;
                if (gWiFiVSCourseSelect->mUnk_140 == 0) {
                    func_0212ecc0(&data_0217d068, 0, 0x51);
                } else if ((gWiFiVSCourseSelect->mUnk_140 + 0x3c) % 0x3c == 0 && v <= 4) {
                    func_0212ecc0(&data_0217d068, 0, 0x50);
                }
            }
            b = p->mUnk_0c;
            a = p->mUnk_08;
            func_02124748(data_usa_021539e0[v / 10 % 10], a, p->mUnk_00, b, 0, 0xf, a, b);
            b = p->mUnk_0c;
            a = p->mUnk_08;
            func_02124748(data_usa_021539e0[v % 10], a, p->mUnk_00, b, 0, 0x10, a, b);
            break;
    }
}

void func_0202b100(void) {
    s32 i;
    Unk02174e14_00 *p;
    s32 n;
    s32 v;
    void *h;

    p = &gWiFiVSCourseSelect->mUnk_048;
    n = p->mUnk_0c->mUnk_06;
    for (i = 0; i < gWiFiVSCourseSelect->mUnk_0b8; i++) {
        func_02025edc(&gWiFiVSCourseSelect->mUnk_0fc[i]);
        if (func_02122734(i) >= 0) {
            v = func_02121e24((u8) func_02122734(i));
        } else {
            v = 0;
        }
        switch (gWiFiVSCourseSelect->mUnk_0ac) {
            case 0:
            case 1:
            case 2:
                if (v != 0 && v != gWiFiVSCourseSelect->mUnk_0bc[i]) {
                    h = GetBmgEntry(gWiFiVSCourseSelect->mUnk_088, func_02025d8c(v));
                    func_0212426c(0, data_usa_021539f4[i].mUnk_00, p->mUnk_14, h, p->mUnk_0c, p->mUnk_18);
                    gWiFiVSCourseSelect->mUnk_0bc[i] = v;
                    func_02025f14(&gWiFiVSCourseSelect->mUnk_0fc[i], 0);
                    if (gWiFiVSCourseSelect->mUnk_0b4 != i) {
                        func_0212ecc0(&data_0217d068, 0, 0x208);
                    }
                }
                break;
        }
        p->mUnk_18[n + data_usa_021539f4[i].mUnk_00].mUnk_04 = func_02025ebc(&gWiFiVSCourseSelect->mUnk_0fc[i]);
        p->mUnk_18[data_usa_021539d8[i]].mUnk_04 = p->mUnk_18[n + data_usa_021539f4[i].mUnk_00].mUnk_04;
    }
}

void func_0202b264(void) {
    Unk02174e14_00 *p;
    s32 n;
    s32 i;

    p = &gWiFiVSCourseSelect->mUnk_064;
    n = p->mUnk_0c->mUnk_06 + p->mUnk_14->mUnk_06;
    func_02025edc(&gWiFiVSCourseSelect->mUnk_0cc[0]);
    gWiFiVSCourseSelect->mUnk_154 = func_02025ebc(&gWiFiVSCourseSelect->mUnk_0cc[0]);
    for (i = 0; i < n; i++) {
        p->mUnk_18[i].mUnk_06 = gWiFiVSCourseSelect->mUnk_154;
    }
}

void func_0202b2bc(void) {
    Unk02174e14_00 *p;
    u16 n;
    s32 i;
    s32 a;
    u16 *h;

    p = &gWiFiVSCourseSelect->mUnk_048;
    n = p->mUnk_0c->mUnk_06;
    a = func_02121d94();
    h = GetBmgEntry(gWiFiVSCourseSelect->mUnk_088, func_02025d8c(a));
    for (i = 0; i < 4; i++) {
        p->mUnk_18[data_usa_021539f4[i].mUnk_06].mUnk_00 = 0;
        p->mUnk_18[n + data_usa_021539f4[i].mUnk_00].mUnk_00 = p->mUnk_18[data_usa_021539f4[i].mUnk_06].mUnk_00;
        p->mUnk_18[data_usa_021539f4[i].mUnk_06].mUnk_04 = 0;
        p->mUnk_18[n + data_usa_021539f4[i].mUnk_00].mUnk_04 = p->mUnk_18[data_usa_021539f4[i].mUnk_06].mUnk_04;
        func_02025f14(&gWiFiVSCourseSelect->mUnk_0fc[i], 1);
    }
    p->mUnk_18[4].mUnk_00 = 1;
    p->mUnk_18[data_usa_021539f4[0].mUnk_00 + n].mUnk_00 = p->mUnk_18[4].mUnk_00;
    p->mUnk_18[data_usa_021539f4[0].mUnk_00 + n].mUnk_06 += 2;
    func_0212426c(0, data_usa_021539f4[0].mUnk_00, p->mUnk_14, h, p->mUnk_0c, p->mUnk_18);
    gWiFiVSCourseSelect->mUnk_144 = a;
    gWiFiVSCourseSelect->mUnk_148 = func_02025d8c(a);
    gWiFiVSCourseSelect->mUnk_14c[0] = h[0];
    gWiFiVSCourseSelect->mUnk_14c[1] = h[1];
    gWiFiVSCourseSelect->mUnk_14c[2] = h[2];
    gWiFiVSCourseSelect->mUnk_14c[3] = h[3];
}

void func_0202b3f4(void) {
    Unk02174e14_00 *p;
    s32 n;
    s32 i;

    p = &gWiFiVSCourseSelect->mUnk_048;
    n = p->mUnk_0c->mUnk_06;
    for (i = 0; i < gWiFiVSCourseSelect->mUnk_0b8; i++) {
        p->mUnk_18[data_usa_021539f4[i].mUnk_06].mUnk_06 = func_020ae4c0(
            1, 0, (s16) (0x60 - (((s16 *) func_0201ea30(p->mUnk_0c, data_usa_021539f4[i].mUnk_06))[1] << 20 >> 20)),
            (*(struct Unk02174e28 **) &gWiFiVSCourseSelect)->mUnk_13c, 0x3c);
        p->mUnk_18[n + data_usa_021539f4[i].mUnk_00].mUnk_06 = func_020ae4c0(
            1, 0, (s16) (0x60 - (((s16 *) func_0201ea58(p->mUnk_14, data_usa_021539f4[i].mUnk_00))[1] << 20 >> 20)),
            (*(struct Unk02174e28 **) &gWiFiVSCourseSelect)->mUnk_13c, 0x3c);
    }
}

void func_0202b4bc(s32 a, s32 b, s32 c, s32 d) {
    Unk02174e14_00 *p;
    void *h;
    s32 i;
    s32 k;

    p = &gWiFiVSCourseSelect->mUnk_064;
    if (a == 1) {
        if (c == 0) {
            h = GetBmgEntry(gWiFiVSCourseSelect->mUnk_08c, 0x1a);
        } else {
            h = GetBmgEntry(gWiFiVSCourseSelect->mUnk_08c, func_02025d5c(data_usa_02153a4c[c - 1]));
        }
        func_0212426c(1, b, p->mUnk_14, h, p->mUnk_0c, p->mUnk_18);
    } else if (a == 0) {
        for (i = 0; i < 7; i++) {
            if (i == d) {
                k = 0xe;
            } else {
                k = 0xf;
            }
            func_02124100(i, (u8) k, p->mUnk_14, p->mUnk_18, p->mUnk_0c);
        }
    }
}

void func_0202b554(s32 a, s32 b) {
    Unk02174e14_00 *p;
    s32 t;
    s32 o;

    t = b / 10 % 10;
    o = b % 10;
    p = &data_02174e3c->mUnk_000;
    p->mUnk_18[0x3c].mUnk_00 = a >= 10 ? 1 : 0;
    func_02025c48(0x3c, a / 10 % 10 + 0x41, p->mUnk_0c);
    func_02025c48(0x3d, a % 10 + 0x41, p->mUnk_0c);
    if (b >= 10) {
        t += 0x4b;
        func_02025c48(0x3f, t, p->mUnk_0c);
        func_02025c48(0x40, o + 0x4b, p->mUnk_0c);
    } else {
        p->mUnk_18[0x40].mUnk_00 = 0;
        func_02025c48(0x3f, o + 0x4b, p->mUnk_0c);
    }
}

#pragma thumb off
