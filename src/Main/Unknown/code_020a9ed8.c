#include "Main/Unknown/code_020a9ed8.h"

#include "Main/Unknown/code_020a9f20.h"
#include "Main/Unknown/code_020a9f40.h"
#include "Main/Unknown/code_020a9ff4.h"
#include "Main/Unknown/code_020aa81c.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020ab604.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_02167000.h"
#include "code_0213ecf8.h"
#include "Main/Unknown/code_02133000.h"
#include "Main/Unknown/code_020aa810.h"

#pragma thumb on
u32 func_020aa810(void) {
    u32 value0;
    value0 = (u32) &data_0217b278;
    value0 = (u32) * (const u16 *) ((value0) + 62u);
    return value0;
}
#pragma thumb off

#pragma thumb on

u16 func_020aa790(u16 a) {
    u16 r;
    u16 t;

    if (a == 0 || a == 0x3000) {
        return a;
    }
    if (func_020aa600(a) != 0) {
        r = func_020aa738(a);
        t = func_020aa094(data_0217b24c, r);
        if (t != r) {
            return t;
        }
        return a;
    }
    if (func_020aa5d8(a) != 0) {
        r = func_020aa6e0(a);
        t = func_020aa094(data_0217b24c, r);
        if (t != r) {
            return t;
        }
        return a;
    }
    return func_020aa094(data_0217b24c, a);
}

u16 func_020aa738(u16 a) {
    u16 r;
    u16 t;

    if (a == 0 || a == 0x3000) {
        return a;
    }
    if (func_020aa628(a) != 0) {
        r = func_020aa790(a);
        t = func_020aa094(data_0217b244, r);
        if (t != r) {
            return t;
        }
        return a;
    }
    return func_020aa094(data_0217b244, a);
}

u16 func_020aa6e0(u16 a) {
    u16 r;
    u16 t;

    if (a == 0 || a == 0x3000) {
        return a;
    }
    if (func_020aa628(a) != 0) {
        r = func_020aa790(a);
        t = func_020aa094(data_0217b23c, r);
        if (t != r) {
            return t;
        }
        return a;
    }
    return func_020aa094(data_0217b23c, a);
}

u16 func_020aa650(u16 a) {
    s32 i;
    s32 j;
    s32 n;
    u16 **p;
    u16 *q;
    u16 *s;

    if (a == 0 || a == 0x3000) {
        return a;
    }
    for (i = 0, p = data_02167a04; i < 4; p++, i++) {
        q = wcschr(*p, a);
        if (q != NULL) {
            n = q - data_02167a04[i];
            break;
        }
    }
    if (i < 4) {
        for (j = 1; j < 4; j++) {
            s = data_02167a04[(i + j) % 4];
            if (s[n] != 0x3000) {
                return s[n];
            }
        }
    } else {
        return a;
    }
    return a;
}

u32 func_020aa628(u16 a) {
    if (wcschr(data_0217b24c[1], a) != NULL) {
        return 1;
    }
    return 0;
}

u32 func_020aa600(u16 a) {
    if (wcschr(data_0217b244[1], a) != NULL) {
        return 1;
    }
    return 0;
}

u32 func_020aa5d8(u16 a) {
    if (wcschr(data_0217b23c[1], a) != NULL) {
        return 1;
    }
    return 0;
}

void func_020aa4e8(u32 *a, u32 b, s32 c, s32 d, s32 e, s32 f) {
    u32 v1;
    u32 m;
    u32 *p;
    u32 w;
    s32 i;

    v1 = 0;
    for (i = 0; i < e - c; i++) {
        v1 |= b << (i * 4);
    }
    v1 <<= c * 4;
    if (d < f) {
        p = a + d;
        do {
            m = v1;
            w = *p;
            if ((w & 0xf0000000) == 0) {
                m &= 0xfffffff;
            }
            if ((w & 0xf000000) == 0) {
                m &= 0xf0ffffff;
            }
            if ((w & 0xf00000) == 0) {
                m &= 0xff0fffff;
            }
            if ((w & 0xf0000) == 0) {
                m &= 0xfff0ffff;
            }
            if ((w & 0xf000) == 0) {
                m &= 0xffff0fff;
            }
            if ((w & 0xf00) == 0) {
                m &= 0xfffff0ff;
            }
            if ((w & 0xf0) == 0) {
                m &= ~0xf0;
            }
            if ((w & 0xf) == 0) {
                m &= ~0xf;
            }
            *p += m;
            p++;
            d++;
        } while (d < f);
    }
}

void func_020aa47c(u32 (*a)[8], s32 b, u32 c, s32 d, s32 e, s32 f, s32 g) {
    func_020aa3a0(a, b, c, d, e, f, e + 1);
    func_020aa3a0(a, b, c, d, g - 1, f, g);
    func_020aa3a0(a, b, c, d, e + 1, d + 1, g - 1);
    func_020aa3a0(a, b, c, f - 1, e + 1, f, g - 1);
}

void func_020aa3a0(u32 (*a)[8], s32 b, u32 c, s32 d, s32 e, s32 f, s32 g) {
    s32 y;
    s32 x0;
    s32 x1;
    s32 y1;
    s32 v1;
    s32 v2;
    s32 w;

    if (d < f && e < g) {
        x0 = d >> 3;
        x1 = ((f - 1) >> 3) + 1;
        y1 = ((g - 1) >> 3) + 1;
        y = e >> 3;
        if (y < y1) {
            v1 = y << 3;
            w = b >> 3;
            v2 = y * w;
            do {
                s32 x;
                x = x0;
                for (; x < x1; x++) {
                    s32 s;
                    s32 t;
                    s32 u;
                    s32 v;

                    s = d - (x << 3);
                    if (s < 0) {
                        s = 0;
                    }
                    t = e - v1 < 0 ? 0 : e - v1;
                    u = f - (x << 3);
                    if (u > 8) {
                        u = 8;
                    }
                    v = g - v1 > 8 ? 8 : g - v1;
                    func_020aa4e8(a[x + v2], c, s, t, u, v);
                }
                v1 += 8;
                v2 += w;
                y++;
            } while (y < y1);
        }
    }
}

void func_020aa300(Unk0217b278 *a) {
    Unk0217b278_10 *q;
    Unk0217b278_10 *r;
    s32 x;
    s32 y;

    q = a->mUnk_44;
    if (q == NULL) {
        a->mUnk_44 = a->mUnk_2c->mUnk_00 + a->mUnk_2c->mUnk_0c;
        return;
    }
    if (q->mUnk_06 <= 0xff) {
        x = data_0217b234 + ((q->mUnk_00 << 1) + q->mUnk_02) / 2 + 3;
        y = data_0217b238 + ((q->mUnk_01 << 1) + q->mUnk_03) / 2 - 3;
    } else {
        x = ((q->mUnk_00 << 1) + q->mUnk_02) / 2 + 3;
        y = ((q->mUnk_01 << 1) + q->mUnk_03) / 2 - 3;
    }
    r = func_020aaea0(a, x, y);
    if (r != NULL) {
        a->mUnk_44 = r;
        return;
    }
    a->mUnk_44 = a->mUnk_2c->mUnk_00 + a->mUnk_2c->mUnk_0c;
}

Unk0217b278_10 *func_020aa0ec(u32 a, Unk0217b278_10 *b, Unk0217b278_10 *c) {
    s32 x0;
    s32 x1;
    s32 y0;
    s32 y1;
    s32 v1;
    s32 v2;
    s32 v3;
    s32 v4;
    s32 x;
    s32 x2;
    s32 y2;
    s32 v5;
    s32 v6;
    s32 k;
    s32 m;
    s32 h8;
    s32 w8;
    u16 r;
    Unk0217b278_10 *q;
    Unk0217b278_10 *e;
    Ncgr *g;

    if (data_0217b278.mUnk_4c != NULL) {
        r = data_0217b278.mUnk_4c(func_020ab2a4(b), a);
        if (r != 0) {
            q = func_020ab338(r);
            if (q != NULL) {
                return q;
            }
        }
    }
    if (b->mUnk_06 <= 0xff) {
        v3 = data_0217b234;
        v4 = data_0217b238;
    } else {
        v3 = 0;
        v4 = 0;
    }
    if ((a & 0x40) != 0) {
        v1 = -8;
        v2 = -8;
        x0 = x1 = v3 + (b->mUnk_00 + b->mUnk_00 + b->mUnk_02) / 2;
        x1 -= 0x10;
        y0 = v4 + b->mUnk_01;
        y1 = y0 - 0x120;
    } else if ((a & 0x80) != 0) {
        v1 = 8;
        v2 = 8;
        x0 = x1 = v3 + (b->mUnk_00 + b->mUnk_00 + b->mUnk_02) / 2;
        x1 += 0x10;
        y0 = v4 + (b->mUnk_01 + b->mUnk_03);
        y1 = y0 + 0x120;
    } else if ((a & 0x20) != 0) {
        v1 = -8;
        v2 = 8;
        x0 = v3 + b->mUnk_00;
        x1 = x0 - 0x120;
        y0 = y1 = v4 + (b->mUnk_01 + b->mUnk_01 + b->mUnk_03) / 2;
        y1 += 0x10;
    } else if ((a & 0x10) != 0) {
        v1 = 8;
        v2 = 8;
        x0 = v3 + (b->mUnk_00 + b->mUnk_02);
        x1 = x0 + 0x120;
        y0 = y1 = v4 + (b->mUnk_01 + b->mUnk_01 + b->mUnk_03) / 2;
        y1 += 0x10;
    }
    for (; y0 != y1; y0 += v2) {
        x = x0;
        if (x != x1) {
            v6 = y0 - v4;
            do {
                x2 = x;
                y2 = y0;
                g = data_0217b278.mUnk_2c->mUnk_04;
                h8 = g->mUnk_02 << 3;
                w8 = g->mUnk_00 << 3;
                v5 = x - v3;
                k = data_usa_021679f8;
                m = -k;
                if (v5 < m) {
                    x2 = x + (h8 + k * 2);
                } else if (v5 > h8 + k) {
                    x2 = x - (h8 + k * 2);
                }
                if (v6 < m) {
                    y2 = y2 + (w8 + k * 2);
                } else if (v6 > w8 + k) {
                    y2 = y2 - (w8 + k * 2);
                }
                e = func_020aaea0(&data_0217b278, x2, y2);
                if (e != NULL && e != b) {
                    return e;
                }
                x += v1;
            } while (x != x1);
        }
    }
    return b;
}

u16 func_020aa094(u16 **a, u16 b) {
    s32 i;
    u16 *p;
    u16 r;

    for (i = 0; i < 2; i++) {
        p = wcschr(a[i], b);
        if (p != NULL) {
            r = a[1 - i][p - a[i]];
            if (r != 0x3000) {
                return r;
            }
            return b;
        }
    }
    return b;
}

void func_020aa028(Unk0217b278_10 *a, Ncgr *b, void (*c)(Unk0217b278 *), s32 d, u32 e, u16 *f) {
    u32 x;
    u32 y;

    data_0217b278.mUnk_2c = &data_0217b294;
    data_0217b278.mUnk_2c->mUnk_00 = a;
    data_0217b278.mUnk_2c->mUnk_04 = b;
    data_0217b278.mUnk_2c->mUnk_08 = c;
    data_0217b278.mUnk_2c->mUnk_0c = d - 1;
    data_0217b278.mUnk_2c->mUnk_0e = e;
    data_0217b278.mUnk_30 = f + 1;
    if (data_0217b278.mUnk_10 != NULL) {
        x = func_020ab61c();
        y = func_020ab610();
        data_0217b278.mUnk_10 = func_020aaea0(&data_0217b278, x, y);
    }
    func_020aafa8(&data_0217b278);
    func_020aad9c(&data_0217b278);
    func_020aab70(&data_0217b278);
    func_020aa300(&data_0217b278);
}

void func_020a9ff4(Unk0217b278_10 *a, Ncgr *b, u32 c) {
    data_0217b2b8[0] = 4;
    data_0217b2b8[1] = 0;
    func_020aa028(a, b, func_020ab3ec, 9, c, data_0217b338);
}

#pragma thumb off

#pragma thumb on

void func_020a9fc4(Unk0217b278_10 *a, struct Ncgr *b, u32 c) {
    u16 *v1;
    v1 = (u16 *) &data_0217b2b8;
    *(u16 *) &data_0217b2b8 = 0;
    v1[1] = 0;
    func_020aa028(a, b, func_020ab45c, 6, c, data_0217b318);
}

void func_020a9f98(Unk0217b278_10 *a, struct Ncgr *b, u32 c) {
    u16 *v1;
    v1 = (u16 *) &data_0217b2b8;
    *(u16 *) &data_0217b2b8 = 0;
    v1[1] = 0;
    func_020aa028(a, b, NULL, 4, c, data_0217b328);
}

void func_020a9f6c(Unk0217b278_10 *a, struct Ncgr *b, u32 c) {
    u16 *v1;
    v1 = (u16 *) &data_0217b2b8;
    *(u16 *) &data_0217b2b8 = 0;
    v1[1] = 0;
    func_020aa028(a, b, NULL, 4, c, data_0217b32c);
}

void func_020a9f40(Unk0217b278_10 *a, struct Ncgr *b, u32 c) {
    u16 *v1;
    v1 = (u16 *) &data_0217b2b8;
    *(u16 *) &data_0217b2b8 = 0;
    v1[1] = 0;
    func_020aa028(a, b, NULL, 4, c, data_0217b330);
}

#pragma thumb off

#pragma thumb on

void func_020a9f20(Unk0217b278_10 *p, u32 a, u32 b, u32 c, u32 d) {
    if (p != NULL) {
        p->mUnk_00 = a;
        p->mUnk_01 = b;
        p->mUnk_02 = c - a;
        p->mUnk_03 = d - b;
        p->mUnk_04 = 0;
        p->mUnk_06 = 0xff00;
    }
}

#pragma thumb off

#pragma thumb on

void func_020a9efc(u32 a, u32 b, u32 c, u32 d) {
    func_020a9f20(&data_0217b278.mUnk_00, a, b, c, d);
}

void func_020a9ed8(u32 a, u32 b, u32 c, u32 d) {
    func_020a9f20(&data_0217b278.mUnk_08, a, b, c, d);
}

#pragma thumb off
