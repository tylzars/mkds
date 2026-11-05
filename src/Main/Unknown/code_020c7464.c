#include "Main/Unknown/code_020c7464.h"

#include "Main/Unknown/code_020c06c4.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020c0000.h"
#include "Main/Unknown/code_020c0b84.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "Main/Unknown/code_020de9f8.h"
#include "Main/Unknown/code_020e0680.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020daf20.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_02100084.h"
#include "Main/Unknown/code_02100094.h"
#include "code_020222ec.h"
#include "code_02148538.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020b4dc4.h"
#include "Main/Unknown/code_020d3c94.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f8e78.h"
#include "Main/Unknown/code_020fd83c.h"
#include "Main/Unknown/code_021001a0.h"
#include "Main/Unknown/code_02100de4.h"
#include "Main/Unknown/unk_02169000.h"
#include "Main/Unknown/unk_027e0000.h"

s32 data_021696c0[10] = {0, 1, 2, 3, 4, 5, 9, 7, 8, 11};

void func_020ca454(void) {
    s32 i;
    s32 n;
    u32 v;

    n = 0;
    v = func_020c0db0();
    for (i = 0; i < data_0217b430->mUnk_08; i++) {
        Unk0217b498_00 *p;

        p = data_0217b430->mUnk_00[i];
        if (!(p->mUnk_02 & 1)) {
            if (func_020b5ae8(&p->mUnk_04, &data_0217b430->mUnk_10[n].mUnk_00, v, 1, 1)) {
                data_0217b430->mUnk_10[n].mUnk_08 = GetRaceSNcerEntry(0x8a);
                data_0217b430->mUnk_10[n].mUnk_0c = 2;
                n++;
            }
        }
    }
    data_0217b430->mUnk_04 = n;
}

void func_020ca438(Unk020c06c4 *a) {
    func_020c092c(a, data_0217b430, 0);
}

s32 func_020ca3e4(void) {
    s32 a;
    s32 i;

    a = 0;
    for (i = 0; i < 10; i++) {
        a += data_0217bc34[data_021696c0[i]].mUnk_0c;
    }
    return func_020c0ba8(&data_0217b42c, a);
}

void func_020ca3d0(void) {
    u32 value0;
    u32 value12;
    value12 = (u32) &func_020c0b84;
    value0 = (u32) &data_0217b42c;
    func_020c0b84((Unk0217b498 **) value0);
}

void func_020ca074(void) {
    enum { K0 } t;
    s32 n;
    s32 a;
    s32 k;
    s32 j;
    Unk027e00cc *e;
    Unk020f41c4_A **v1;
    s32 v2;
    Unk020224e0_c *c;
    Unk020f41c4_A *p;
    Vec3 *q;
    s32 v;

    n = 0;
    a = func_020c0db0();
    for (k = 0; k < 10; k++) {
        t = data_021696c0[k];
        e = &data_027e00cc[t];
        v1 = e->mUnk_04;
        v2 = e->mUnk_14;
        {
            s32 v3[10] = {0x4c, 0x4d, 0x4b, 0x4f, 0x50, 0x56, 0x55, 0x54, 0x4e, 0x57};

            c = GetRaceSNcerEntry(v3[k]);
        }
        for (j = 0; j < v2; j++) {
            p = v1[j];
            if ((p->mUnk_74 & 0x80000) != 0) {
                q = NULL;
            } else {
                q = &p->mUnk_50;
            }
            if (k == 9) {
                if (q != NULL) {
                    if (func_020b5ae8(q, &data_0217b42c->mUnk_10[n].mUnk_00, a, 1, 1) != FALSE) {
                        if (p->mUnk_d8 > 0) {
                            v = ((Unk02101c84 *) p)->mUnk_170;
                            data_0217b42c->mUnk_10[n].mUnk_00.mUnk_04 -= 0x88 * v / (s32) func_021001a0();
                            if (data_0217b42c->mUnk_10[n].mUnk_00.mUnk_04 > 0) {
                                data_0217b42c->mUnk_10[n].mUnk_08 = c;
                                data_0217b42c->mUnk_10[n].mUnk_0c = func_020b4e70(q) != 0 ? 2 : 3;
                                data_0217b42c->mUnk_10[n].mUnk_0e = 0;
                                n++;
                            }
                        }
                    }
                }
            } else if (k == 6) {
                if (((Unk020fdae8 *) p)->mUnk_1a0 != FALSE && q != NULL) {
                    if (func_020b5ae8(q, &data_0217b42c->mUnk_10[n].mUnk_00, a, 1, 1) != FALSE) {
                        if (func_020d3d10(q->y) == 0) {
                            data_0217b42c->mUnk_10[n].mUnk_08 = c;
                            data_0217b42c->mUnk_10[n].mUnk_0c = func_020b4e70(q) != 0 ? 2 : 3;
                            data_0217b42c->mUnk_10[n].mUnk_0e = (p->mUnk_74 & 0x40000) != 0 ? 1 : 0;
                            n++;
                        }
                    }
                }
            } else {
                if (q != NULL) {
                    if (func_020b5ae8(q, &data_0217b42c->mUnk_10[n].mUnk_00, a, 1, 1) != FALSE) {
                        if (func_020d3d10(q->y) == 0) {
                            data_0217b42c->mUnk_10[n].mUnk_08 = c;
                            data_0217b42c->mUnk_10[n].mUnk_0c = func_020b4e70(q) != 0 ? 2 : 3;
                            data_0217b42c->mUnk_10[n].mUnk_0e = (p->mUnk_74 & 0x40000) != 0 ? 1 : 0;
                            n++;
                        }
                    }
                }
            }
        }
    }
    data_0217b42c->mUnk_04 = n;
}

void func_020ca058(Unk020c06c4 *a) {
    func_020c092c(a, data_0217b42c, 0);
}

s32 func_020c9fb8(void) {
    s32 i;

    data_0217b428 = HeapAlloc(GetHeap(func_020364e8()), 0x194);
    func_020c0ba8(&data_0217b428->mUnk_190, 0x18);
    for (i = 0; i < 8; i++) {
        data_0217b428->mUnk_000[i] = 0;
        data_0217b428->mUnk_020[i] = 0;
        data_0217b428->mUnk_060[i].mUnk_00 = 0;
        data_0217b428->mUnk_060[i].mUnk_04 = 0;
        data_0217b428->mUnk_100[i] = 0;
        data_0217b428->mUnk_130[i] = 0;
    }
    return 1;
}

void func_020c9f84(void) {
    func_020c0b84(&data_0217b428->mUnk_190);
    data_0217b428 = NULL;
}

void func_020c97c0(void) {
    s32 v1[8];
    u32 a;
    u16 i;
    Vec3 v;
    Vec3 w;
    Vec3 t;
    Unk020f41c4_A **v2;
    s32 v3;
    s32 m;
    s32 j;
    s32 f;
    Unk020f41c4_A *o;
    Vec3 *q;
    u32 b;
    Unk020eda5c *s;
    s32 x;
    s32 y;

    a = func_020c0db0();
    for (i = 0; i < (u32) data_021759c0->mKartCount; i++) {
        data_0217b428->mUnk_000[i] = 0;
        data_0217b428->mUnk_130[i] = i;
        v1[i] = GetKartRank(i & 0xff);
    }
    switch (GetRaceHudSubScreenState()) {
        case 0:
            for (i = 0; i < (u32) data_021759c0->mKartCount; i++) {
                func_020b6078(i, &data_0217b428->mUnk_060[i]);
                x = data_0217b428->mUnk_060[i].mUnk_00;
                y = data_0217b428->mUnk_060[i].mUnk_04;
                if (x > -0x10 && x < 0x110 && y > -0x10 && y < 0xd0 && func_0207a84c(i) == 0) {
                    data_0217b428->mUnk_000[i] = 1;
                    if (data_021759c0->mMode == 1 && data_021759c0->mCurrentEntries[i].mUnk_08.mKind == 2) {
                        data_0217b428->mUnk_040[i] = 1;
                    } else {
                        data_0217b428->mUnk_040[i] = 0;
                    }
                    func_0207a8c4(&data_0217b428->mUnk_0a0[i], i);
                    if (GetKart(i)->mState != 0) {
                        data_0217b428->mUnk_110[i]++;
                        data_0217b428->mUnk_100[i] = (data_0217b428->mUnk_110[i] << 12) % 0x10000;
                    } else {
                        data_0217b428->mUnk_100[i] = 0;
                        data_0217b428->mUnk_110[i] = 0;
                    }
                }
            }
            break;
        case 1:
        case 2:
        case 3:
            data_0217b428->mUnk_190->mUnk_04 = 0;
            for (i = 0; i < (u32) data_021759c0->mKartCount; i++) {
                func_0207a948(&v, i & 0xff);
                func_020b5dcc(i, &data_0217b428->mUnk_060[i], a);
                x = data_0217b428->mUnk_060[i].mUnk_00;
                y = data_0217b428->mUnk_060[i].mUnk_04;
                if (x > -0x10 && x < 0x110 && y > -0x10 && y < 0xd0 && func_0207a84c(i) == 0) {
                    data_0217b428->mUnk_000[i] = 1;
                    data_0217b428->mUnk_040[i] = func_020b4dc4(i);
                    func_0207a8c4(&data_0217b428->mUnk_0a0[i], i);
                    if (GetKart(i)->mState != 0) {
                        data_0217b428->mUnk_110[i]++;
                        data_0217b428->mUnk_100[i] = (data_0217b428->mUnk_110[i] << 12) % 0x10000;
                    } else {
                        data_0217b428->mUnk_100[i] = 0;
                        data_0217b428->mUnk_110[i] = 0;
                    }
                    data_0217b428->mUnk_150[i] = func_020b4e70(&v) != 0 ? 2 : 3;
                    s = &data_027e00c8[i].mUnk_058;
                    v2 = s->mUnk_014;
                    v3 = s->mUnk_020;
                    m = data_0217b428->mUnk_190->mUnk_04;
                    b = func_020c0db0();
                    for (j = 0; j < v3; j++) {
                        o = v2[j];
                        if ((o->mUnk_74 & 0x80000) != 0) {
                            q = NULL;
                        } else {
                            q = &o->mUnk_50;
                        }
                        f = func_020f91e0(o);
                        if (q != NULL && f != 0) {
                            func_020b4f64(&t, &v, q);
                            w = t;
                            if (func_020b5ae8(&w, &data_0217b428->mUnk_190->mUnk_10[m].mUnk_00, b, 0, 1) != FALSE) {
                                switch (o->mUnk_44) {
                                    case 0:
                                        data_0217b428->mUnk_190->mUnk_10[m].mUnk_08 = GetRaceSNcerEntry(0x4c);
                                        break;
                                    case 1:
                                        data_0217b428->mUnk_190->mUnk_10[m].mUnk_08 = GetRaceSNcerEntry(0x4d);
                                        break;
                                    case 2:
                                        data_0217b428->mUnk_190->mUnk_10[m].mUnk_08 = GetRaceSNcerEntry(0x4b);
                                        break;
                                    case 5:
                                        data_0217b428->mUnk_190->mUnk_10[m].mUnk_08 = GetRaceSNcerEntry(0x56);
                                        break;
                                    case 9:
                                        data_0217b428->mUnk_190->mUnk_10[m].mUnk_08 = GetRaceSNcerEntry(0x55);
                                        break;
                                    case 7:
                                        data_0217b428->mUnk_190->mUnk_10[m].mUnk_08 = GetRaceSNcerEntry(0x54);
                                        break;
                                    case 8:
                                        data_0217b428->mUnk_190->mUnk_10[m].mUnk_08 = GetRaceSNcerEntry(0x4e);
                                        break;
                                    default:
                                        data_0217b428->mUnk_190->mUnk_10[m].mUnk_08 = GetRaceSNcerEntry(0x4c);
                                        break;
                                }
                                data_0217b428->mUnk_190->mUnk_10[m].mUnk_0c = func_020b4e70(&w) != 0 ? 2 : 3;
                                data_0217b428->mUnk_190->mUnk_10[m].mUnk_0e = (o->mUnk_74 & 0x40000) != 0 ? 1 : 0;
                                m++;
                            }
                        }
                    }
                    data_0217b428->mUnk_190->mUnk_04 = m;
                }
            }
            break;
    }
    for (i = 0; i < (u32) data_021759c0->mKartCount; i++) {
        if (func_0207a8a4(i) == 1) {
            data_0217b428->mUnk_170[i]++;
        } else {
            data_0217b428->mUnk_170[i] = 0;
        }
        if (i != func_020b4d9c() && (GetKart(i)->mUnk_7c & 0x402000) != 0) {
            data_0217b428->mUnk_020[i] = 1;
        } else {
            data_0217b428->mUnk_020[i] = 0;
        }
    }
    for (i = 0; i < (u32) data_021759c0->mKartCount; i++) {
        if (data_0217b428->mUnk_040[i] == 0) {
            v1[i] -= 0x20;
        }
        if (i == func_020b4d9c()) {
            v1[i] -= 0x10;
        }
    }
    if (data_021759c0->mMode == 1) {
        return;
    }
    SortIndicesByKey(data_0217b428->mUnk_130, v1, data_021759c0->mKartCount);
}

static inline void func_020c8dbc_inline(Unk020c06c4 *p, Unk020224e0_c *c, s32 *r, s32 x, s32 y, u16 v, s32 s, s32 g) {
    s32 q[2];
    s32 e;
    Unk020c06c4_08 *t;

    e = p->mUnk_400;
    q[0] = x << 12;
    q[1] = y << 12;
    t = &p->mUnk_000.mUnk_00[e];
    p->mUnk_400 += func_020224e0((Unk020224e0_o *) t, 0x80 - e, c, r, q, v, 1);
    for (; e < p->mUnk_400; e++) {
        if (s != -1) {
            t->mUnk_0a = s;
        }
        if (g != -1) {
            t->mUnk_0e = g;
        }
        t++;
    }
}

static inline void func_020c8dbc_inline2(Unk020c06c4 *p, Unk020224e0_c *c, s32 x, s32 y) {
    s32 q[2];
    s32 e;

    q[0] = x << 12;
    q[1] = y << 12;
    e = p->mUnk_400;
    p->mUnk_400 += func_020224e0((Unk020224e0_o *) &p->mUnk_000.mUnk_00[e], 0x80 - e, c, NULL, q, 0, 1);
}

static inline void func_020c8dbc_inline3(Unk020c06c4 *p, s32 i, s32 h) {
    s32 j;
    s32 x;
    s32 v3;
    s32 v4;
    Unk020224e0_c *c;

    for (j = 0; j < 3; j++) {
        x = (u16) (((h + 12 - j * 4) << 16) / 64) >> 4;
        v3 = (s16) gPairsByAngle[x * 2 + 1] * 11 >> 12;
        v4 = (s16) gPairsByAngle[x * 2] * 11 >> 12;
        c = GetRaceSNcerEntry(h % 12 < 6 ? 93 + j * 2 : 94 + j * 2);
        func_020c8dbc_inline2(p, c, data_0217b428->mUnk_060[i].mUnk_00 + v3, data_0217b428->mUnk_060[i].mUnk_04 + v4);
    }
}

void func_020c8dbc(Unk020c06c4 *p) {
    s32 i;
    s32 f;
    Unk020224e0_c *c;
    s32 r0[4];
    s32 r1[4];
    s32 k;
    s32 g;
    s32 b;
    u16 v1;
    u16 v5;
    s32 a;
    u16 n;
    s32 v6;
    s32 v7;

    switch (GetRaceHudSubScreenState()) {
        case 0:
            for (k = 0; k < data_021759c0->mKartCount; k++) {
                i = data_0217b428->mUnk_130[k];
                if (data_0217b428->mUnk_000[i] != 0) {
                    f = data_0217b428->mUnk_040[i];
                    if (data_0217b428->mUnk_020[i] == 0) {
                        if (data_0217b428->mUnk_0a0[i].y != 0x1000 || data_0217b428->mUnk_110[i] != 0) {
                            v1 = func_020ae5c4(p);
                            func_020b4bf8(r0, data_0217b428->mUnk_0a0[i].y, data_0217b428->mUnk_100[i]);
                            if (func_0207a8a4((u16) i) == 3) {
                                c = GetRaceSNcerEntry(0x10);
                            } else {
                                c = GetRaceSNcerEntry(i);
                            }
                            func_020c8dbc_inline(p, c, r0, data_0217b428->mUnk_060[i].mUnk_00,
                                                 data_0217b428->mUnk_060[i].mUnk_04, v1, f != 0 ? 1 : -1, -1);
                            p->mUnk_000.mUnk_20[v1].mUnk_06 = r0[0] >> 4;
                            p->mUnk_000.mUnk_20[v1].mUnk_0e = r0[1] >> 4;
                            p->mUnk_000.mUnk_20[v1].mUnk_16 = r0[2] >> 4;
                            p->mUnk_000.mUnk_20[v1].mUnk_1e = r0[3] >> 4;
                        } else {
                            if (func_0207a8a4((u16) i) == 3) {
                                c = GetRaceSNcerEntry(0x10);
                            } else {
                                c = GetRaceSNcerEntry(i);
                            }
                            func_020c8dbc_inline(p, c, NULL, data_0217b428->mUnk_060[i].mUnk_00,
                                                 data_0217b428->mUnk_060[i].mUnk_04, 0, f != 0 ? 1 : -1, -1);
                        }
                    }
                    if (data_0217b428->mUnk_170[i] != 0) {
                        func_020c8dbc_inline3(p, i, data_0217b428->mUnk_170[i]);
                    }
                }
            }
            break;
        case 1:
        case 2:
        case 3:
            a = func_020c0dc4();
            for (k = 0; k < data_021759c0->mKartCount; k++) {
                i = data_0217b428->mUnk_130[k];
                g = data_0217b428->mUnk_150[i];
                if (data_0217b428->mUnk_000[i] != 0 && a <= g) {
                    if (data_0217b428->mUnk_020[i] == 0) {
                        v6 = data_0217b428->mUnk_060[i].mUnk_00;
                        v7 = data_0217b428->mUnk_060[i].mUnk_04;
                        b = data_0217b428->mUnk_040[i];
                        if (data_0217b428->mUnk_0a0[i].y != 0x1000 || data_0217b428->mUnk_110[i] != 0) {
                            n = func_020ae5c4(p);
                            if (data_0217b428->mUnk_110[i] != 0) {
                                v5 = data_0217b428->mUnk_100[i] + func_020b6368();
                            } else {
                                v5 = 0;
                            }
                            func_020b4bf8(r1, data_0217b428->mUnk_0a0[i].y, v5);
                            if (func_0207a8a4((u16) i) == 3) {
                                c = GetRaceSNcerEntry(0x10);
                            } else {
                                c = GetRaceSNcerEntry(i);
                            }
                            func_020c8dbc_inline(p, c, r1, v6, v7, n, b != 0 ? 1 : -1, g);
                            p->mUnk_000.mUnk_20[n].mUnk_06 = r1[0] >> 4;
                            p->mUnk_000.mUnk_20[n].mUnk_0e = r1[1] >> 4;
                            p->mUnk_000.mUnk_20[n].mUnk_16 = r1[2] >> 4;
                            p->mUnk_000.mUnk_20[n].mUnk_1e = r1[3] >> 4;
                        } else {
                            if (func_0207a8a4((u16) i) == 3) {
                                c = GetRaceSNcerEntry(0x10);
                            } else {
                                c = GetRaceSNcerEntry(i);
                            }
                            func_020c8dbc_inline(p, c, NULL, v6, v7, 0, b != 0 ? 1 : -1, g);
                        }
                    }
                    if (data_0217b428->mUnk_170[i] != 0) {
                        func_020c8dbc_inline3(p, i, data_0217b428->mUnk_170[i]);
                    }
                }
            }
            func_020c092c(p, data_0217b428->mUnk_190, 0);
            break;
    }
}

BOOL func_020c8d30(void) {
    Unk02100094 *a;
    s32 n;

    a = func_021000d0(0xcd);
    if (a == NULL) {
        return FALSE;
    }
    n = func_02100094(a);
    if (n == 0) {
        return FALSE;
    }
    data_0217b424 = HeapAlloc(GetHeap(func_020364e8()), 0x44);
    data_0217b424->mUnk_00 = (Unk020e1e98 **) func_02100084(a);
    data_0217b424->mUnk_04 = n;
    data_0217b424->mUnk_08 = n;
    return TRUE;
}

u32 func_020c8d1c(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217b424;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

void func_020c8bdc(void) {
    s32 i;
    u32 a;
    Unk020e1e98 *p;
    s32 s;
    Vec3 *v;
    s32 x;
    s32 y;
    Vec3 w;

    a = func_020c0db0();
    for (i = 0; i < data_0217b424->mUnk_08; i++) {
        p = data_0217b424->mUnk_00[i];
        s = p->mUnk_000.mUnk_58.z;
        v = &p->mUnk_000.mPos;
        x = (s64) p->mUnk_000.mMatrix.mUnk_00[2].x * s >> 12;
        y = (s64) p->mUnk_000.mMatrix.mUnk_00[2].z * s >> 12;
        if (data_021759c0->mUnk_57 != 0) {
            data_0217b424->mUnk_0c[i] = AngleFromPair(-y, x) + 0x8000;
        } else {
            data_0217b424->mUnk_0c[i] = AngleFromPair(y, x);
        }
        func_020b5ae8(v, &data_0217b424->mUnk_14[i], a, 0, 0);
        w.x = v->x + x;
        w.z = v->z + y;
        func_020b5ae8(&w, &data_0217b424->mUnk_2c[i], a, 0, 0);
    }
}

void func_020c82dc(Unk020c06c4 *p) {
    Unk020224e0_c *c;
    s32 r[4];
    u32 a;
    u16 v1;
    u16 v2;
    u16 v3;
    u16 t;
    s32 x;
    s32 y;
    s32 v4;
    s32 v5;
    s32 v6;
    s32 v7;
    s32 j;
    u16 v8;
    s32 v9;
    s32 v10;
    s32 v11;
    s32 v12;
    s32 v13;
    s32 v14;
    s32 v15;
    u16 v16;
    s32 v17;
    s32 v18;
    s32 v19;
    s32 v20;
    s32 v21;
    s32 v22;
    s32 v23;
    s32 q0[2];
    s32 q1[2];
    s32 q2[2];
    s32 q3[2];
    s32 q4[2];
    s32 q5[2];
    s32 q6[2];
    s32 q7[2];
    s32 q8[2];

    a = func_020c0dc4();
    if (data_0217b424->mUnk_04 <= 0) {
        return;
    }
    if (a == 0) {
        if (data_021759c0->mUnk_57 != 0) {
            t = data_0217b424->mUnk_0c[0] - func_020b6368();
        } else {
            t = data_0217b424->mUnk_0c[0] + func_020b6368();
        }
        v1 = func_020ae5c4(p);
        func_020b4cb0(r, t);
        x = data_0217b424->mUnk_2c[0].mUnk_00;
        y = data_0217b424->mUnk_2c[0].mUnk_04;
        if (x > -32 && x < 288 && y > -32 && y < 224) {
            c = GetRaceSNcerEntry(156);
            q0[0] = x << 12;
            q0[1] = y << 12;
            p->mUnk_400 +=
                func_020224e0((Unk020224e0_o *) &p->mUnk_000.mUnk_00[p->mUnk_400], 0x80 - p->mUnk_400, c, r, q0, v1, 1);
        }
        v4 = data_0217b424->mUnk_14[0].mUnk_00 - data_0217b424->mUnk_2c[0].mUnk_00;
        v5 = data_0217b424->mUnk_14[0].mUnk_04 - data_0217b424->mUnk_2c[0].mUnk_04;
        for (j = 0, v6 = 0, v7 = 0; j < 3; j++) {
            x = data_0217b424->mUnk_2c[0].mUnk_00 + (v6 + v4) / 4;
            y = data_0217b424->mUnk_2c[0].mUnk_04 + (v7 + v5) / 4;
            if (x > -32 && x < 288 && y > -32 && y < 224) {
                c = GetRaceSNcerEntry(155);
                q1[0] = x << 12;
                q1[1] = y << 12;
                p->mUnk_400 += func_020224e0((Unk020224e0_o *) &p->mUnk_000.mUnk_00[p->mUnk_400], 0x80 - p->mUnk_400, c,
                                             r, q1, v1, 1);
            }
            v6 += v4;
            v7 += v5;
        }
        x = data_0217b424->mUnk_14[0].mUnk_00;
        y = data_0217b424->mUnk_14[0].mUnk_04;
        if (x > -32 && x < 288 && y > -32 && y < 224) {
            c = GetRaceSNcerEntry(154);
            q2[0] = x << 12;
            q2[1] = y << 12;
            p->mUnk_400 +=
                func_020224e0((Unk020224e0_o *) &p->mUnk_000.mUnk_00[p->mUnk_400], 0x80 - p->mUnk_400, c, r, q2, v1, 1);
        }
        p->mUnk_000.mUnk_20[v1].mUnk_06 = r[0] >> 4;
        p->mUnk_000.mUnk_20[v1].mUnk_0e = r[1] >> 4;
        p->mUnk_000.mUnk_20[v1].mUnk_16 = r[2] >> 4;
        p->mUnk_000.mUnk_20[v1].mUnk_1e = r[3] >> 4;
    }
    if (data_0217b424->mUnk_08 == 3 && a == 0) {
        if (data_021759c0->mUnk_57 != 0) {
            v8 = data_0217b424->mUnk_0c[2] - func_020b6368();
        } else {
            v8 = data_0217b424->mUnk_0c[2] + func_020b6368();
        }
        v3 = func_020ae5c4(p);
        func_020b4cb0(r, v8);
        v9 = data_0217b424->mUnk_2c[2].mUnk_00;
        v10 = data_0217b424->mUnk_2c[2].mUnk_04;
        if (v9 > -32 && v9 < 288 && v10 > -32 && v10 < 224) {
            c = GetRaceSNcerEntry(156);
            q3[0] = v9 << 12;
            q3[1] = v10 << 12;
            p->mUnk_400 +=
                func_020224e0((Unk020224e0_o *) &p->mUnk_000.mUnk_00[p->mUnk_400], 0x80 - p->mUnk_400, c, r, q3, v3, 1);
        }
        v11 = data_0217b424->mUnk_14[2].mUnk_00 - data_0217b424->mUnk_2c[2].mUnk_00;
        v12 = data_0217b424->mUnk_14[2].mUnk_04 - data_0217b424->mUnk_2c[2].mUnk_04;
        for (v15 = 0, v13 = 0, v14 = 0; v15 < 2; v15++) {
            v9 = data_0217b424->mUnk_2c[2].mUnk_00 + (v13 + v11) / 3;
            v10 = data_0217b424->mUnk_2c[2].mUnk_04 + (v14 + v12) / 3;
            if (v9 > -32 && v9 < 288 && v10 > -32 && v10 < 224) {
                c = GetRaceSNcerEntry(155);
                q4[0] = v9 << 12;
                q4[1] = v10 << 12;
                p->mUnk_400 += func_020224e0((Unk020224e0_o *) &p->mUnk_000.mUnk_00[p->mUnk_400], 0x80 - p->mUnk_400, c,
                                             r, q4, v3, 1);
            }
            v13 += v11;
            v14 += v12;
        }
        v9 = data_0217b424->mUnk_14[2].mUnk_00;
        v10 = data_0217b424->mUnk_14[2].mUnk_04;
        if (v9 > -32 && v9 < 288 && v10 > -32 && v10 < 224) {
            c = GetRaceSNcerEntry(154);
            q5[0] = v9 << 12;
            q5[1] = v10 << 12;
            p->mUnk_400 +=
                func_020224e0((Unk020224e0_o *) &p->mUnk_000.mUnk_00[p->mUnk_400], 0x80 - p->mUnk_400, c, r, q5, v3, 1);
        }
        p->mUnk_000.mUnk_20[v3].mUnk_06 = r[0] >> 4;
        p->mUnk_000.mUnk_20[v3].mUnk_0e = r[1] >> 4;
        p->mUnk_000.mUnk_20[v3].mUnk_16 = r[2] >> 4;
        p->mUnk_000.mUnk_20[v3].mUnk_1e = r[3] >> 4;
    }
    if (data_021759c0->mUnk_57 != 0) {
        v16 = data_0217b424->mUnk_0c[1] - func_020b6368();
    } else {
        v16 = data_0217b424->mUnk_0c[1] + func_020b6368();
    }
    v2 = func_020ae5c4(p);
    func_020b4cb0(r, v16);
    v17 = data_0217b424->mUnk_2c[1].mUnk_00;
    v18 = data_0217b424->mUnk_2c[1].mUnk_04;
    if (v17 > -16 && v17 < 272 && v18 > -16 && v18 < 208) {
        c = GetRaceSNcerEntry(159);
        q6[0] = v17 << 12;
        q6[1] = v18 << 12;
        p->mUnk_400 +=
            func_020224e0((Unk020224e0_o *) &p->mUnk_000.mUnk_00[p->mUnk_400], 0x80 - p->mUnk_400, c, r, q6, v2, 1);
    }
    v19 = data_0217b424->mUnk_14[1].mUnk_00 - data_0217b424->mUnk_2c[1].mUnk_00;
    v20 = data_0217b424->mUnk_14[1].mUnk_04 - data_0217b424->mUnk_2c[1].mUnk_04;
    for (v23 = 0, v21 = 0, v22 = 0; v23 < 3; v23++) {
        v17 = data_0217b424->mUnk_2c[1].mUnk_00 + (v21 + v19) / 4;
        v18 = data_0217b424->mUnk_2c[1].mUnk_04 + (v22 + v20) / 4;
        if (v17 > -16 && v17 < 272 && v18 > -16 && v18 < 208) {
            c = GetRaceSNcerEntry(158);
            q7[0] = v17 << 12;
            q7[1] = v18 << 12;
            p->mUnk_400 +=
                func_020224e0((Unk020224e0_o *) &p->mUnk_000.mUnk_00[p->mUnk_400], 0x80 - p->mUnk_400, c, r, q7, v2, 1);
        }
        v21 += v19;
        v22 += v20;
    }
    v17 = data_0217b424->mUnk_14[1].mUnk_00;
    v18 = data_0217b424->mUnk_14[1].mUnk_04;
    if (v17 > -16 && v17 < 272 && v18 > -16 && v18 < 208) {
        c = GetRaceSNcerEntry(157);
        q8[0] = v17 << 12;
        q8[1] = v18 << 12;
        p->mUnk_400 +=
            func_020224e0((Unk020224e0_o *) &p->mUnk_000.mUnk_00[p->mUnk_400], 0x80 - p->mUnk_400, c, r, q8, v2, 1);
    }
    p->mUnk_000.mUnk_20[v2].mUnk_06 = r[0] >> 4;
    p->mUnk_000.mUnk_20[v2].mUnk_0e = r[1] >> 4;
    p->mUnk_000.mUnk_20[v2].mUnk_16 = r[2] >> 4;
    p->mUnk_000.mUnk_20[v2].mUnk_1e = r[3] >> 4;
}

BOOL func_020c8254(void) {
    u16 a[3] = {0x19a, 0x195, 0x19c};
    u16 i;
    u16 b;

    for (i = 0; i < 3; i++) {
        b = a[i];
        if (func_021000d0(b) != NULL) {
            return func_020c0c2c(&data_0217b420, b);
        }
    }
    return FALSE;
}

void func_020c8240(void) {
    u32 value0;
    u32 value12;
    value12 = (u32) &func_020c0b84;
    value0 = (u32) &data_0217b420;
    func_020c0b84((Unk0217b498 **) value0);
}

void func_020c80cc(void) {
    s32 i;
    s32 n;
    Unk020e1e98 *p;
    Vec3 *v;
    u32 a;
    u16 t;
    u16 w;

    n = 0;
    a = func_020c0db0();
    for (i = 0; i < data_0217b420->mUnk_08; i++) {
        p = (Unk020e1e98 *) data_0217b420->mUnk_00[i];
        v = &p->mUnk_000.mPos;
        if (func_020b5ae8(&p->mUnk_000.mPos, &data_0217b420->mUnk_10[n].mUnk_00, a, 1, 1) != FALSE) {
            t = p->mUnk_000.mKind;
            w = p->mUnk_000.mAngle;
            switch (t) {
                case 0x19a:
                    data_0217b420->mUnk_10[n].mUnk_08 = GetRaceSNcerEntry(p->mUnk_130 + 0x95);
                    break;
                case 0x195:
                    data_0217b420->mUnk_10[n].mUnk_08 = GetRaceSNcerEntry(0x93);
                    break;
                case 0x19c:
                    data_0217b420->mUnk_10[n].mUnk_08 = GetRaceSNcerEntry(0x94);
                    break;
            }
            data_0217b420->mUnk_10[n].mUnk_0c = func_020b4e70((Vec3 *) &v) != 0 ? 2 : 3;
            data_0217b420->mUnk_10[n].mUnk_10 = w;
            n++;
        }
    }
    data_0217b420->mUnk_04 = n;
}

void func_020c80b0(Unk020c06c4 *a) {
    func_020c092c(a, data_0217b420, 1);
}

s32 func_020c8098(void) {
    return func_020c0c2c(&data_0217b41c, 0xca);
}

void func_020c8084(void) {
    u32 value0;
    u32 value12;
    value12 = (u32) &func_020c0b84;
    value0 = (u32) &data_0217b41c;
    func_020c0b84((Unk0217b498 **) value0);
}

void func_020c7fbc(void) {
    s32 i;
    s32 n;
    u32 a;

    n = 0;
    a = func_020c0db0();
    for (i = 0; i < data_0217b41c->mUnk_08; i++) {
        if (func_020b5ae8(&data_0217b41c->mUnk_00[i]->mUnk_04, &data_0217b41c->mUnk_10[n].mUnk_00, a, 1, 0) != FALSE) {
            data_0217b41c->mUnk_10[n].mUnk_08 = GetRaceSNcerEntry(0x25);
            data_0217b41c->mUnk_10[n].mUnk_0c = 2;
            n++;
        }
    }
    data_0217b41c->mUnk_04 = n;
}

void func_020c7fa0(Unk020c06c4 *a) {
    func_020c092c(a, data_0217b41c, 0);
}

s32 func_020c7f84(void) {
    return func_020c0c2c(&data_0217b418, 0x199);
}

void func_020c7f70(void) {
    u32 value0;
    u32 value12;
    value12 = (u32) &func_020c0b84;
    value0 = (u32) &data_0217b418;
    func_020c0b84((Unk0217b498 **) value0);
}

void func_020c7d8c(void) {
    s32 i;
    s32 n;
    Unk0217b498_00 *p;
    u32 a;
    s32 v;
    s32 w;

    n = 0;
    a = func_020c0db0();
    for (i = 0; i < data_0217b418->mUnk_08; i++) {
        if (func_020b5f68(&data_0217b418->mUnk_0c[i]) != FALSE) {
            p = data_0217b418->mUnk_00[i];
            if (func_020b5ae8(&p->mUnk_04, &data_0217b418->mUnk_10[n].mUnk_00, a, 0, 0) != FALSE) {
                v = p->mUnk_04.y - p->mUnk_a8;
                if (v >= -0x9000) {
                    w = v > 0 ? 1 : 0;
                    data_0217b418->mUnk_10[n].mUnk_08 = GetRaceSNcerEntry(w != 0 ? 0xa7 : 0xa8);
                    data_0217b418->mUnk_10[n].mUnk_0c = w != 0 ? 1 : 2;
                    data_0217b418->mUnk_10[n + 1].mUnk_00 = data_0217b418->mUnk_10[n].mUnk_00;
                    data_0217b418->mUnk_10[n + 1].mUnk_08 = GetRaceSNcerEntry(0xa9);
                    data_0217b418->mUnk_10[n + 1].mUnk_0c = 2;
                    n += 2;
                    data_0217b418->mUnk_10[n - 2].mUnk_00.mUnk_04 -= v >> 14;
                } else {
                    data_0217b418->mUnk_10[n].mUnk_08 = GetRaceSNcerEntry(0xa9);
                    data_0217b418->mUnk_10[n].mUnk_0c = 2;
                    n++;
                }
            }
        }
    }
    data_0217b418->mUnk_04 = n;
}

void func_020c7d70(Unk020c06c4 *a) {
    func_020c092c(a, data_0217b418, 0);
}

s32 func_020c7d54(void) {
    return func_020c0c2c(&data_0217b414, 0x19b);
}

void func_020c7d40(void) {
    u32 value0;
    u32 value12;
    value12 = (u32) &func_020c0b84;
    value0 = (u32) &data_0217b414;
    func_020c0b84((Unk0217b498 **) value0);
}

void func_020c7c54(void) {
    s32 i;
    s32 n;
    Unk0217b498_00 *p;
    u32 a;

    n = 0;
    a = func_020c0db0();
    for (i = 0; i < data_0217b414->mUnk_08; i++) {
        if (func_020b5f68(&data_0217b414->mUnk_0c[i]) != FALSE) {
            p = data_0217b414->mUnk_00[i];
            if ((p->mUnk_02 & 2) == 0) {
                if (func_020b5ae8(&p->mUnk_04, &data_0217b414->mUnk_10[n].mUnk_00, a, 0, 0) != FALSE) {
                    data_0217b414->mUnk_10[n].mUnk_08 = GetRaceSNcerEntry(0x89);
                    data_0217b414->mUnk_10[n].mUnk_0c = 2;
                    n++;
                }
            }
        }
    }
    data_0217b414->mUnk_04 = n;
}

void func_020c7c38(Unk020c06c4 *a) {
    func_020c092c(a, data_0217b414, 0);
}

s32 func_020c7c1c(void) {
    return func_020c0c2c(&data_0217b410, 0x1a3);
}

void func_020c7c08(void) {
    u32 value0;
    u32 value12;
    value12 = (u32) &func_020c0b84;
    value0 = (u32) &data_0217b410;
    func_020c0b84((Unk0217b498 **) value0);
}

void func_020c7b44(void) {
    s32 i;
    s32 n;
    u32 a;

    n = 0;
    a = func_020c0db0();
    for (i = 0; i < data_0217b410->mUnk_08; i++) {
        if (func_020b5ae8(&data_0217b410->mUnk_00[i]->mUnk_04, &data_0217b410->mUnk_10[n].mUnk_00, a, 1, 1) != FALSE) {
            data_0217b410->mUnk_10[n].mUnk_08 = GetRaceSNcerEntry(0x8b);
            data_0217b410->mUnk_10[n].mUnk_0c = 2;
            n++;
        }
    }
    data_0217b410->mUnk_04 = n;
}

void func_020c7b28(Unk020c06c4 *a) {
    func_020c092c(a, data_0217b410, 0);
}

s32 func_020c7b0c(void) {
    return func_020c0c2c(&data_0217b40c, 0x19d);
}

void func_020c7af8(void) {
    u32 value0;
    u32 value12;
    value12 = (u32) &func_020c0b84;
    value0 = (u32) &data_0217b40c;
    func_020c0b84((Unk0217b498 **) value0);
}

void func_020c7a0c(void) {
    s32 i;
    s32 n;
    Unk0217b498_00 *p;
    u32 a;

    n = 0;
    a = func_020c0db0();
    for (i = 0; i < data_0217b40c->mUnk_08; i++) {
        if (func_020b5f68(&data_0217b40c->mUnk_0c[i]) != FALSE) {
            p = data_0217b40c->mUnk_00[i];
            if ((p->mUnk_02 & 1) == 0) {
                if (func_020b5ae8(&p->mUnk_04, &data_0217b40c->mUnk_10[n].mUnk_00, a, 0, 0) != FALSE) {
                    data_0217b40c->mUnk_10[n].mUnk_08 = GetRaceSNcerEntry(0x98);
                    data_0217b40c->mUnk_10[n].mUnk_0c = 2;
                    n++;
                }
            }
        }
    }
    data_0217b40c->mUnk_04 = n;
}

void func_020c79f0(Unk020c06c4 *a) {
    func_020c092c(a, data_0217b40c, 0);
}

s32 func_020c79d4(void) {
    return func_020c0c2c(&data_0217b408, 0x193);
}

void func_020c79c0(void) {
    u32 value0;
    u32 value12;
    value12 = (u32) &func_020c0b84;
    value0 = (u32) &data_0217b408;
    func_020c0b84((Unk0217b498 **) value0);
}

void func_020c783c(void) {
    s32 i;
    s32 n;
    Unk0217b498_00 *p;
    u32 a;
    s32 t;

    n = 0;
    a = func_020c0db0();
    for (i = 0; i < data_0217b408->mUnk_08; i++) {
        if (func_020b5f68(&data_0217b408->mUnk_0c[i]) != FALSE) {
            p = data_0217b408->mUnk_00[i];
            if (func_020b5ae8(&p->mUnk_04, &data_0217b408->mUnk_10[n].mUnk_00, a, 0, 0) != FALSE) {
                data_0217b408->mUnk_10[n].mUnk_08 = GetRaceSNcerEntry(0xaf);
                data_0217b408->mUnk_10[n].mUnk_0c = 1;
                data_0217b408->mUnk_10[n + 1].mUnk_00 = data_0217b408->mUnk_10[(u32) n].mUnk_00;
                data_0217b408->mUnk_10[n + 1].mUnk_08 = GetRaceSNcerEntry(0xb0);
                data_0217b408->mUnk_10[n + 1].mUnk_0c = 2;
                n += 2;
                t = func_020db4c4((Dossun *) p) * 16 >> 12;
                data_0217b408->mUnk_10[n - 2].mUnk_00.mUnk_04 -= t;
            }
        }
    }
    data_0217b408->mUnk_04 = n;
}

void func_020c7820(Unk020c06c4 *a) {
    func_020c092c(a, data_0217b408, 0);
}

BOOL func_020c77a0(void) {
    u16 a[2] = {0x196, 0x1a5};
    u16 i;
    u16 b;

    for (i = 0; i < 2; i++) {
        b = a[i];
        if (func_021000d0(b) != NULL) {
            return func_020c0c2c(&data_0217b404, b);
        }
    }
    return FALSE;
}

void func_020c778c(void) {
    u32 value0;
    u32 value12;
    value12 = (u32) &func_020c0b84;
    value0 = (u32) &data_0217b404;
    func_020c0b84((Unk0217b498 **) value0);
}

void func_020c76c8(void) {
    s32 i;
    s32 n;
    u32 a;

    n = 0;
    a = func_020c0db0();
    for (i = 0; i < data_0217b404->mUnk_08; i++) {
        if (func_020b5ae8(&data_0217b404->mUnk_00[i]->mUnk_04, &data_0217b404->mUnk_10[n].mUnk_00, a, 1, 0) != FALSE) {
            data_0217b404->mUnk_10[n].mUnk_08 = GetRaceSNcerEntry(0xac);
            data_0217b404->mUnk_10[n].mUnk_0c = 1;
            n++;
        }
    }
    data_0217b404->mUnk_04 = n;
}

void func_020c76ac(Unk020c06c4 *a) {
    func_020c092c(a, data_0217b404, 0);
}

s32 func_020c7690(void) {
    return func_020c0c2c(&data_0217b400, 0x12f);
}

void func_020c767c(void) {
    u32 value0;
    u32 value12;
    value12 = (u32) &func_020c0b84;
    value0 = (u32) &data_0217b400;
    func_020c0b84((Unk0217b498 **) value0);
}

void func_020c756c(void) {
    s32 i;
    s32 n;
    Unk0217b498_00 *p;
    Vec3 *v;
    u32 a;

    n = 0;
    a = func_020c0db0();
    for (i = 0; i < data_0217b400->mUnk_08; i++) {
        if (func_020b5f68(&data_0217b400->mUnk_0c[i]) != FALSE) {
            p = data_0217b400->mUnk_00[i];
            if ((p->mUnk_02 & 1) == 0) {
                v = &p->mUnk_04;
                if (func_020b5ae8(v, &data_0217b400->mUnk_10[n].mUnk_00, a, 0, 0) != FALSE) {
                    data_0217b400->mUnk_10[n].mUnk_08 = GetRaceSNcerEntry(0x8c);
                    data_0217b400->mUnk_10[n].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
                    n++;
                }
            }
        }
    }
    data_0217b400->mUnk_04 = n;
}

void func_020c7550(Unk020c06c4 *a) {
    func_020c092c(a, data_0217b400, 0);
}

s32 func_020c7464(void) {
    u16 a[2] = {0x65, 0xc9};
    u16 i;
    u16 b;
    s32 n;
    s32 m;
    s32 j;

    for (i = 0; i < 2; i++) {
        b = a[i];
        if (func_021000d0(b) != NULL) {
            n = func_020c0c2c(&data_0217b3fc, b);
            m = 0;
            for (j = 0; j < data_0217b3fc->mUnk_08; j++) {
                s32 v = func_020de9f8((Unk020de6a8 *) data_0217b3fc->mUnk_00[j]);
                if (v > m) {
                    m = v;
                }
            }
            if (m < 0x3e8000) {
                data_0217b3f8 = 1;
            } else {
                data_0217b3f8 = 0;
            }
            return n;
        }
    }
    return 0;
}
