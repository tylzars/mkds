#include "Main/Unknown/code_020c8d30.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b4dc4.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020c0000.h"
#include "Main/Unknown/code_020c0b84.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "Main/Unknown/code_020c8254.h"
#include "Main/Unknown/code_020d3c94.h"
#include "Main/Unknown/code_020e0680.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f8e78.h"
#include "Main/Unknown/code_020fd83c.h"
#include "Main/Unknown/code_02100084.h"
#include "Main/Unknown/code_02100094.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_021001a0.h"
#include "Main/Unknown/code_02100de4.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02169000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_027e0000.h"
#include "code_020222ec.h"
#include "code_02148538.h"

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

            c = func_020b83dc(v3[k]);
        }
        for (j = 0; j < v2; j++) {
            p = v1[j];
            if ((p->mUnk_74 & 0x80000) != 0) {
                q = 0;
            } else {
                q = &p->mUnk_50;
            }
            if (k == 9) {
                if (q != 0) {
                    if (func_020b5ae8(q, &data_0217b42c->mUnk_10[n].mUnk_00, a, 1, 1) != 0) {
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
                if (((Unk020fdae8 *) p)->mUnk_1a0 != 0 && q != 0) {
                    if (func_020b5ae8(q, &data_0217b42c->mUnk_10[n].mUnk_00, a, 1, 1) != 0) {
                        if (func_020d3d10(q->y) == 0) {
                            data_0217b42c->mUnk_10[n].mUnk_08 = c;
                            data_0217b42c->mUnk_10[n].mUnk_0c = func_020b4e70(q) != 0 ? 2 : 3;
                            data_0217b42c->mUnk_10[n].mUnk_0e = (p->mUnk_74 & 0x40000) != 0 ? 1 : 0;
                            n++;
                        }
                    }
                }
            } else {
                if (q != 0) {
                    if (func_020b5ae8(q, &data_0217b42c->mUnk_10[n].mUnk_00, a, 1, 1) != 0) {
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

void func_020ca058(Unk020c06c4 *param_1) {
    func_020c092c(param_1, data_0217b42c, 0);
}

s32 func_020c9fb8(void) {
    s32 i;

    data_0217b428 = func_02036bec(func_020364e0(func_020364e8()), 0x194);
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
    data_0217b428 = 0;
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
    for (i = 0; i < (u32) data_021759c0->mUnk_3d0; i++) {
        data_0217b428->mUnk_000[i] = 0;
        data_0217b428->mUnk_130[i] = i;
        v1[i] = func_0203c8dc(i & 0xff);
    }
    switch (func_020b1dbc()) {
        case 0:
            for (i = 0; i < (u32) data_021759c0->mUnk_3d0; i++) {
                func_020b6078(i, &data_0217b428->mUnk_060[i]);
                x = data_0217b428->mUnk_060[i].mUnk_00;
                y = data_0217b428->mUnk_060[i].mUnk_04;
                if (x > -0x10 && x < 0x110 && y > -0x10 && y < 0xd0 && func_0207a84c(i) == 0) {
                    data_0217b428->mUnk_000[i] = 1;
                    if (data_021759c0->mUnk_08 == 1 && data_021759c0->mUnk_68[i].mUnk_08.mUnk_00 == 2) {
                        data_0217b428->mUnk_040[i] = 1;
                    } else {
                        data_0217b428->mUnk_040[i] = 0;
                    }
                    func_0207a8c4(&data_0217b428->mUnk_0a0[i], i);
                    if (func_0207a974(i)->mUnk_180 != 0) {
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
            for (i = 0; i < (u32) data_021759c0->mUnk_3d0; i++) {
                func_0207a948(&v, i & 0xff);
                func_020b5dcc(i, &data_0217b428->mUnk_060[i], a);
                x = data_0217b428->mUnk_060[i].mUnk_00;
                y = data_0217b428->mUnk_060[i].mUnk_04;
                if (x > -0x10 && x < 0x110 && y > -0x10 && y < 0xd0 && func_0207a84c(i) == 0) {
                    data_0217b428->mUnk_000[i] = 1;
                    data_0217b428->mUnk_040[i] = func_020b4dc4(i);
                    func_0207a8c4(&data_0217b428->mUnk_0a0[i], i);
                    if (func_0207a974(i)->mUnk_180 != 0) {
                        data_0217b428->mUnk_110[i]++;
                        data_0217b428->mUnk_100[i] = (data_0217b428->mUnk_110[i] << 12) % 0x10000;
                    } else {
                        data_0217b428->mUnk_100[i] = 0;
                        data_0217b428->mUnk_110[i] = 0;
                    }
                    data_0217b428->mUnk_150[i] = func_020b4e70(&v) != 0 ? 2 : 3;
                    s = &((Unk020ee684 *) data_027e00c8)[i].mUnk_058;
                    v2 = s->mUnk_014;
                    v3 = s->mUnk_020;
                    m = data_0217b428->mUnk_190->mUnk_04;
                    b = func_020c0db0();
                    for (j = 0; j < v3; j++) {
                        o = v2[j];
                        if ((o->mUnk_74 & 0x80000) != 0) {
                            q = 0;
                        } else {
                            q = &o->mUnk_50;
                        }
                        f = func_020f91e0(o);
                        if (q != 0 && f != 0) {
                            func_020b4f64(&t, &v, q);
                            w = t;
                            if (func_020b5ae8(&w, &data_0217b428->mUnk_190->mUnk_10[m].mUnk_00, b, 0, 1) != 0) {
                                switch (o->mUnk_44) {
                                    case 0:
                                        data_0217b428->mUnk_190->mUnk_10[m].mUnk_08 = func_020b83dc(0x4c);
                                        break;
                                    case 1:
                                        data_0217b428->mUnk_190->mUnk_10[m].mUnk_08 = func_020b83dc(0x4d);
                                        break;
                                    case 2:
                                        data_0217b428->mUnk_190->mUnk_10[m].mUnk_08 = func_020b83dc(0x4b);
                                        break;
                                    case 5:
                                        data_0217b428->mUnk_190->mUnk_10[m].mUnk_08 = func_020b83dc(0x56);
                                        break;
                                    case 9:
                                        data_0217b428->mUnk_190->mUnk_10[m].mUnk_08 = func_020b83dc(0x55);
                                        break;
                                    case 7:
                                        data_0217b428->mUnk_190->mUnk_10[m].mUnk_08 = func_020b83dc(0x54);
                                        break;
                                    case 8:
                                        data_0217b428->mUnk_190->mUnk_10[m].mUnk_08 = func_020b83dc(0x4e);
                                        break;
                                    default:
                                        data_0217b428->mUnk_190->mUnk_10[m].mUnk_08 = func_020b83dc(0x4c);
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
    for (i = 0; i < (u32) data_021759c0->mUnk_3d0; i++) {
        if (func_0207a8a4(i) == 1) {
            data_0217b428->mUnk_170[i]++;
        } else {
            data_0217b428->mUnk_170[i] = 0;
        }
        if (i != func_020b4d9c() && (func_0207a974(i)->mUnk_7c & 0x402000) != 0) {
            data_0217b428->mUnk_020[i] = 1;
        } else {
            data_0217b428->mUnk_020[i] = 0;
        }
    }
    for (i = 0; i < (u32) data_021759c0->mUnk_3d0; i++) {
        if (data_0217b428->mUnk_040[i] == 0) {
            v1[i] -= 0x20;
        }
        if (i == func_020b4d9c()) {
            v1[i] -= 0x10;
        }
    }
    if (data_021759c0->mUnk_08 == 1) {
        return;
    }
    func_020ae770(data_0217b428->mUnk_130, v1, data_021759c0->mUnk_3d0);
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
    p->mUnk_400 += func_020224e0((Unk020224e0_o *) &p->mUnk_000.mUnk_00[e], 0x80 - e, c, 0, q, 0, 1);
}

static inline void func_020c8dbc_inline3(Unk020c06c4 *p, s32 i, s32 h) {
    s32 j;
    s32 x;
    s32 v3;
    s32 v4;
    Unk020224e0_c *c;

    for (j = 0; j < 3; j++) {
        x = (u16) (((h + 12 - j * 4) << 16) / 64) >> 4;
        v3 = (s16) data_0215d4b4[x * 2 + 1] * 11 >> 12;
        v4 = (s16) data_0215d4b4[x * 2] * 11 >> 12;
        c = func_020b83dc(h % 12 < 6 ? 93 + j * 2 : 94 + j * 2);
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

    switch (func_020b1dbc()) {
        case 0:
            for (k = 0; k < data_021759c0->mUnk_3d0; k++) {
                i = data_0217b428->mUnk_130[k];
                if (data_0217b428->mUnk_000[i] != 0) {
                    f = data_0217b428->mUnk_040[i];
                    if (data_0217b428->mUnk_020[i] == 0) {
                        if (data_0217b428->mUnk_0a0[i].y != 0x1000 || data_0217b428->mUnk_110[i] != 0) {
                            v1 = func_020ae5c4(p);
                            func_020b4bf8(r0, data_0217b428->mUnk_0a0[i].y, data_0217b428->mUnk_100[i]);
                            if (func_0207a8a4((u16) i) == 3) {
                                c = func_020b83dc(0x10);
                            } else {
                                c = func_020b83dc(i);
                            }
                            func_020c8dbc_inline(p, c, r0, data_0217b428->mUnk_060[i].mUnk_00,
                                                 data_0217b428->mUnk_060[i].mUnk_04, v1, f != 0 ? 1 : -1, -1);
                            p->mUnk_000.mUnk_20[v1].mUnk_06 = r0[0] >> 4;
                            p->mUnk_000.mUnk_20[v1].mUnk_0e = r0[1] >> 4;
                            p->mUnk_000.mUnk_20[v1].mUnk_16 = r0[2] >> 4;
                            p->mUnk_000.mUnk_20[v1].mUnk_1e = r0[3] >> 4;
                        } else {
                            if (func_0207a8a4((u16) i) == 3) {
                                c = func_020b83dc(0x10);
                            } else {
                                c = func_020b83dc(i);
                            }
                            func_020c8dbc_inline(p, c, 0, data_0217b428->mUnk_060[i].mUnk_00,
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
            for (k = 0; k < data_021759c0->mUnk_3d0; k++) {
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
                                c = func_020b83dc(0x10);
                            } else {
                                c = func_020b83dc(i);
                            }
                            func_020c8dbc_inline(p, c, r1, v6, v7, n, b != 0 ? 1 : -1, g);
                            p->mUnk_000.mUnk_20[n].mUnk_06 = r1[0] >> 4;
                            p->mUnk_000.mUnk_20[n].mUnk_0e = r1[1] >> 4;
                            p->mUnk_000.mUnk_20[n].mUnk_16 = r1[2] >> 4;
                            p->mUnk_000.mUnk_20[n].mUnk_1e = r1[3] >> 4;
                        } else {
                            if (func_0207a8a4((u16) i) == 3) {
                                c = func_020b83dc(0x10);
                            } else {
                                c = func_020b83dc(i);
                            }
                            func_020c8dbc_inline(p, c, 0, v6, v7, 0, b != 0 ? 1 : -1, g);
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

s32 func_020c8d30(void) {
    Unk02100094 *a;
    s32 n;

    a = func_021000d0(0xcd);
    if (a == 0) {
        return 0;
    }
    n = func_02100094(a);
    if (n == 0) {
        return 0;
    }
    data_0217b424 = func_02036bec(func_020364e0(func_020364e8()), 0x44);
    data_0217b424->mUnk_00 = (Unk020e1e98 **) func_02100084(a);
    data_0217b424->mUnk_04 = n;
    data_0217b424->mUnk_08 = n;
    return 1;
}
