#include "Main/Unknown/code_02124f4c.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/code_02038000.h"
#include "Main/Unknown/code_020ad000.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0214cfe4.h"
#include "code_02022aa8.h"
#include "Main/Unknown/code_02023000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_02175000.h"
#include "01/code_021804e0.h"
#include "01/code_021a5140.h"
#include "registers.h"

#pragma thumb on

void func_0212586c(Unk021243ac_20 *a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, void *i, s32 j, s8 k, s32 l) {
    s32 v2c;
    s32 v30;
    s32 v34[20];
    u16 buf[500];

    func_021253f8(a, &v2c, v34, &v30, i, buf, j, (s32) k);
    func_021251c4(a, v2c, v34, v30, b, c, d, e, f, g, h, buf, j, k, l);
}

void func_0212583c(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, void *i) {
    func_0212586c(a, b, c, d, e, f, g, h, i, 0, -1, 0);
}

void func_02125808(void *a, s32 b, s32 c, s32 d, s32 e, u32 f, u32 g, u32 h, void *i, s32 j, s8 k) {
    func_0212586c(a, b, c, d, e, f, g, h, i, j, k, 0);
}

void func_021257d8(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, void *i) {
    func_0212586c(a, b, c, d, e, f, g, h, i, 0, -1, 1);
}

void func_021253f8(Unk021243ac_20 *a, s32 *b, s32 *c, s32 *d, void *e, u16 *f, s32 g, s32 h) {
    s32 v0c;
    s32 v10;
    s32 v14;
    s32 v18;
    s32 n1;
    s32 n2;
    s32 v24;
    s32 i2;
    s32 i1;
    u8 *v30;
    u16 buf1[10];
    u16 buf2[10];
    Unk02022aa8 *r5;
    u16 v1;
    s32 t2;
    s32 r7;
    u32 u;
    u16 ch;
    Unk02022c80 *p;
    s32 *w;
    u16 *q;

    v14 = 0;
    v10 = a->mUnk_08;
    r5 = (Unk02022aa8 *) a->mUnk_04;
    v0c = a->mUnk_0c + r5->mUnk_00->mUnk_01;
    v30 = e;
    q = f;
    *b = ~v14;
    *c = v14;
    *d = r5->mUnk_00->mUnk_01;
    v1 = r5->mUnk_04(&v30);
    if (v1 != 0) {
        w = c;
        v24 = h + v10;
        do {
            if (v1 == 0x1a) {
                v18 = ((Unk021253f8 *) v30)->mUnk_00;
                t2 = ((Unk021253f8 *) v30)->mUnk_02;
                switch (((Unk021253f8 *) v30)->mUnk_01) {
                    case 0:
                        break;
                    case 1:
                        switch (t2) {
                            case 0:
                                for (r7 = 0; r7 < 10; r7++) {
                                    ch = ((u16 *) data_0217aa08->mUnk_00->mUnk_0c)[r7];
                                    if (ch == 0) {
                                        r7 = 10;
                                    } else {
                                        *q++ = ch;
                                        if (h == -1 || (g != 0 && !func_021253f8_inline(ch))) {
                                            u = func_02022ce4(r5, ch);
                                            if (u == 0xffff) {
                                                u = r5->mUnk_00->mUnk_02;
                                            }
                                            p = func_02022c80(r5, u);
                                            *w += p->mUnk_02 + v10;
                                        } else {
                                            *w += v24;
                                        }
                                    }
                                }
                                break;
                            case 1:
                                n1 = func_020adc7c((u16 *) data_0217aa08->mUnk_00->mUnk_0c, buf1);
                                for (i1 = 0; i1 < n1; i1++) {
                                    *q++ = buf1[i1];
                                    if (h == -1 || (g != 0 && !func_021253f8_inline(buf1[i1]))) {
                                        u = func_02022ce4(r5, buf1[i1]);
                                        if (u == 0xffff) {
                                            u = r5->mUnk_00->mUnk_02;
                                        }
                                        p = func_02022c80(r5, u);
                                        *w += p->mUnk_02 + v10;
                                    } else {
                                        *w += v24;
                                    }
                                }
                            case 10:
                                for (r7 = 0; r7 < 10; r7++) {
                                    ch = ((u16 *) data_021759d0->mUnk_2a)[r7];
                                    if (ch == 0) {
                                        r7 = 10;
                                    } else {
                                        *q++ = ch;
                                        if (h == -1 || (g != 0 && !func_021253f8_inline(ch))) {
                                            u = func_02022ce4(r5, ch);
                                            if (u == 0xffff) {
                                                u = r5->mUnk_00->mUnk_02;
                                            }
                                            p = func_02022c80(r5, u);
                                            *w += p->mUnk_02 + v10;
                                        } else {
                                            *w += v24;
                                        }
                                    }
                                }
                                break;
                            case 11:
                                n2 = func_020adc7c((u16 *) data_021759d0->mUnk_2a, buf2);
                                for (i2 = 0; i2 < n2; i2++) {
                                    *q++ = buf2[i2];
                                    if (h == -1 || (g != 0 && !func_021253f8_inline(buf2[i2]))) {
                                        u = func_02022ce4(r5, buf2[i2]);
                                        if (u == 0xffff) {
                                            u = r5->mUnk_00->mUnk_02;
                                        }
                                        p = func_02022c80(r5, u);
                                        *w += p->mUnk_02 + v10;
                                    } else {
                                        *w += v24;
                                    }
                                }
                                break;
                        }
                        break;
                    case 0xff:
                        if (t2 == 0) {
                            func_0214d1fc(v30 - 2, q, v18);
                            q += v18 >> 1;
                        }
                        break;
                }
                v30 = v30 + v18 - 2;
            } else {
                *q++ = v1;
                if (v1 == 0xa) {
                    *d += v0c;
                    if (*b < *w) {
                        *b = *w;
                    }
                    w++;
                    v14++;
                    *w = 0;
                } else {
                    r7 = v10;
                    if (*(u16 *) v30 == 0 || *(u16 *) v30 == 0xa) {
                        r7 = 0;
                    }
                    if (h == -1 || (g != 0 && !func_021253f8_inline(v1))) {
                        u = func_02022ce4(r5, v1);
                        if (u == 0xffff) {
                            u = r5->mUnk_00->mUnk_02;
                        }
                        p = func_02022c80(r5, u);
                        *w += p->mUnk_02 + r7;
                    } else {
                        *w += h + r7;
                    }
                }
            }
        } while ((v1 = r5->mUnk_04(&v30)) != 0);
    }
    *q = 0;
    if (*b < c[v14]) {
        *b = c[v14];
    }
}

s32 func_021253ac(u32 a, s32 b, s32 c, s32 d, s32 e) {
    s32 r;

    r = 0;
    if (a & 0x400) {
        r += (c - d) >> 1;
    } else if (a & 0x800) {
        r += c - d;
    }
    if (b == 1) {
        r += (d - e) >> 1;
    } else if (b == 2) {
        r += d - e;
    }
    return r;
}

void func_021251c4(Unk021243ac_20 *a, s32 b, s32 *c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i, u32 j, s32 k, void *l,
                   s32 m, s32 n, s32 o) {
    s32 x;
    s32 y;
    s32 v10;
    s32 v14;
    Unk02022aa8 *v18;
    s32 v1c;
    s32 v20;
    Unk02022c80 *v24;
    u16 ch;
    u8 t0;
    u16 t2;
    u8 t1;
    u8 t4;
    u32 u;
    u8 *v28;

    x = e;
    y = f;
    v14 = a->mUnk_08;
    v18 = (Unk02022aa8 *) a->mUnk_04;
    v10 = a->mUnk_0c + v18->mUnk_00->mUnk_01;
    v28 = l;
    x += func_021253ac(j, k, g, b, *c);
    if (x < 0) {
        return;
    }
    if (j & 0x80) {
        y += (h - d) >> 1;
    } else if (j & 0x100) {
        y += h - d;
    }
    if (y < 0) {
        return;
    }
    ch = v18->mUnk_04(&v28);
    if (ch == 0) {
        return;
    }
    v1c = f + h;
    v20 = e + g;
    do {
        if (ch == 0x1a) {
            t0 = ((Unk021253f8 *) v28)->mUnk_00;
            t2 = ((Unk021253f8 *) v28)->mUnk_02;
            t1 = ((Unk021253f8 *) v28)->mUnk_01;
            if (t1 == 0xff && t2 == 0) {
                t4 = ((Unk021253f8 *) v28)->mUnk_04;
                if (o != 0) {
                    if (t4 == 0) {
                        i = 2;
                    } else {
                        i = t4 * 2 + 1;
                    }
                } else {
                    i = t4 * 2 + 1;
                }
            }
            v28 = v28 + t0 - 2;
        } else if (ch == 0xa) {
            y += v10;
            c++;
            if (y >= v1c) {
                return;
            }
            x = e + func_021253ac(j, k, g, b, *c);
            if (x < 0) {
                return;
            }
        } else {
            if (n == -1 || (m != 0 && !func_021253f8_inline(ch))) {
                x += func_02023450((Unk02023374 *) a->mUnk_00, (Unk02022aa8 *) a->mUnk_04, x, y, i, ch);
            } else {
                u = func_02022ce4(v18, ch);
                if (u == 0xffff) {
                    u = v18->mUnk_00->mUnk_02;
                }
                v24 = func_02022c80(v18, u);
                x += (n - v24->mUnk_02) >> 1;
                func_02023450((Unk02023374 *) a->mUnk_00, (Unk02022aa8 *) a->mUnk_04, x, y, i, ch);
                x += n - ((n - v24->mUnk_02) >> 1);
            }
            if (x > v20) {
                return;
            }
            x += v14;
        }
    } while ((ch = v18->mUnk_04(&v28)) != 0);
}

void func_0212513c(u16 *a, u16 *b, u16 *c, u32 d) {
    s32 n;
    s32 k;
    u16 *q;
    u16 v;

    n = 0;
    while (*b != 0x1a || ((Unk0212513c *) b)->mUnk_03 != 1 || ((Unk0212513c *) b)->mUnk_04 != 0xff) {
        c[n] = *b;
        n++;
        b++;
    }
    b += ((Unk0212513c *) b)->mUnk_02 >> 1;
    if (*a != 0) {
        q = c + n;
        do {
            *q++ = ((Unk0212513c *) a)->mUnk_00;
            n++;
            a++;
        } while (*a != 0);
    }
    while ((v = *b) != 0) {
        if (v == 0x1a) {
            k = ((Unk0212513c *) b)->mUnk_02;
            func_0214cffc(b, c + n, k);
            b += k >> 1;
            n += k >> 1;
        } else {
            c[n] = v;
            n++;
            b++;
        }
    }
    c[n] = 0;
}

void *func_021250b0(void *a) {
    Unk020391d4 t = {1, 0x12, 0x18, 1, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 4, 0x100, 0, 0, 8, 0};
    Unk02180774 *p;

    p = func_02038d88(a, &t);
    func_02038d28(p->mUnk_28, 0, 0, 0, 0, 0x12, 2, 0);
    func_02038cd8(p->mUnk_70, 1, 0, 0, 0, 0x10, 4);
    func_02037abc(p);
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffcfffef) | 0x10;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffcfffef) | 0x10;
    return p;
}

void *func_02125028(void *a) {
    Unk020391d4 t = {1, 0x13, 0x18, 1, 0, 1, 0, 4, 0x60, 0, 0, 3, 0x10, 0, 0x80, 0x100, 0, 0, 8, 0};
    Unk02180774 *p;

    p = func_02038d88(a, &t);
    func_02038d28(p->mUnk_28, 0, 0, 0, 0, 0x12, 2, 0);
    func_02038cd8(p->mUnk_70, 1, 0, 0, 0, 0xf, 0);
    func_02037abc(p);
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffcfffef) | 0x10;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffcfffef) | 0x10;
    return p;
}

s32 func_02125004(u32 a) {
    s32 i;
    s32 n;

    n = 1;
    for (i = 0; i < 10; i++) {
        a = a / 10;
        if (a == 0) {
            break;
        }
        n++;
    }
    return n;
}

s32 func_02124fac(u32 a, u16 *b) {
    s32 n;
    s32 i;
    n = func_02125004(a);
    for (i = 0; i < n; i++) {
        *(b + n - i - 1) = (u16) (a % 10) + 0x30;
        a = a / 10;
    }
    b[n] = 0;
    return n;
}

s32 func_02124f4c(u32 a, u16 *b) {
    s32 n;
    s32 i;
    n = func_02125004(a);
    for (i = 0; i < n; i++) {
        *(b + n - i - 1) = (u16) (a % 10) + 0xff10;
        a = a / 10;
    }
    b[n] = 0;
    return n;
}

#pragma thumb off
