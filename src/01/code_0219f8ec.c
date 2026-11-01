#include "01/code_0219f8ec.h"

#include "code_0201ea58.h"
#include "types.h"
#include "01/unk_021ca000.h"
#include "01/unk_021a6000.h"
#include "01/code_021a6430.h"
#include "Main/Unknown/code_02105000.h"
#include "Main/Unknown/code_02105550.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02127000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "01/code_021a0000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_0203b000.h"
#include "Main/Unknown/code_02116000.h"
#include "Main/Unknown/code_0203b680.h"
#include "code_0212df7c.h"
#include "code_02148ca0.h"
#include "registers.h"
#include "Main/Unknown/code_0205f000.h"
#include "01/code_021a1000.h"
#include "01/code_021a11a4.h"
#include "01/code_021a2034.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020472a8.h"

void func_ov001_021a10b8(void) {
    Unk020b4934 *a = 0;
    Unk02021dc8 *b = 0;
    Unk020b4a44 *c = 0;
    Unk020b4934 *d = 0;
    Unk02021dc8 *e = 0;
    Unk020b4a44 *f = 0;
    Unk020b4934 *g = 0;
    Unk020b47d8 *h = 0;
    Unk020b47d8 *i = 0;
    Unk020b4a44 *j = 0;

    func_020b496c(&g, func_0204799c(data_ov001_021a92bc));
    func_020b4a7c(&j, func_0204799c(data_ov001_021a92a8));
    func_020b4810(&h, func_0204799c(data_ov001_021a928c));
    func_020b4810(&i, func_0204799c(data_ov001_021a92c0));
    func_020b49f4(&a, func_0204799c(data_ov001_021a9278));
    func_020b48ec(&b, func_0204799c(data_ov001_021a92c4));
    func_020b4a7c(&c, func_0204799c(data_ov001_021a9298));
    func_020b49f4(&d, func_0204799c(data_ov001_021a92b0));
    func_020b48ec(&e, func_0204799c(data_ov001_021a9284));
    func_020b4a7c(&f, func_0204799c(data_ov001_021a927c));
    func_ov001_021a651c();
}

void func_ov001_021a0e7c(void) {
    Unk020b4934 *a = 0;
    Unk020b4a44 *b = 0;
    Unk020b4934 *c = 0;
    Unk020b4934 *d = 0;
    Unk020b47d8 *e = 0;
    Unk020b47d8 *f = 0;
    Unk020b4a44 *g = 0;
    u16 *p;

    func_020b4934(&d, func_0204799c(data_ov001_021a92bc));
    func_020b4a44(&g, func_0204799c(data_ov001_021a92a8));
    func_020b47d8(&e, func_0204799c(data_ov001_021a928c));
    func_020b47d8(&f, func_0204799c(data_ov001_021a92c0));
    data_ov001_021ca414->mUnk_48 = func_02036bec(data_ov001_021ca414->mUnk_5c, 0x800);
    data_ov001_021ca414->mUnk_04 = func_0204799c(data_ov001_021a929c);
    data_ov001_021ca414->mUnk_08 = func_0204799c(data_ov001_021a92ac);
    func_020b49bc(&a, func_0204799c(data_ov001_021a9278));
    func_020b48b4(&data_ov001_021ca414->mUnk_00, func_0204799c(data_ov001_021a92c4));
    func_020b4a44(&b, func_0204799c(data_ov001_021a9298));
    data_ov001_021ca414->mUnk_10 = func_0204799c(data_ov001_021a92a4);
    data_ov001_021ca414->mUnk_14 = func_0204799c(data_ov001_021a92a0);
    data_ov001_021ca414->mUnk_18 = func_0204799c(data_ov001_021a9280);
    func_020b49bc(&c, func_0204799c(data_ov001_021a92b0));
    func_020b48b4(&data_ov001_021ca414->mUnk_0c, func_0204799c(data_ov001_021a9284));
    func_020b4a44((Unk020b4a44 **) &data_ov001_021ca414->mUnk_1c, func_0204799c(data_ov001_021a927c));
    p = b->mUnk_0c;
    func_02016468(4, 0, d->mUnk_14, d->mUnk_10);
    func_02016468(0xf, 0, g->mUnk_0c, 0x40);
    func_02016468(8, 0, e->mUnk_0c, e->mUnk_08);
    func_02016468(8, 0x800, data_ov001_021ca414->mUnk_48, 0x800);
    func_02016468(8, 0x1000, data_ov001_021ca414->mUnk_48, 0x800);
    func_02016468(8, 0x1800, data_ov001_021ca414->mUnk_48, 0x800);
    func_02016468(9, 0, f->mUnk_0c, f->mUnk_08);
    func_02016468(9, 0x800, data_ov001_021ca414->mUnk_48, 0x800);
    func_02016468(0x13, 0, a->mUnk_14, a->mUnk_10);
    func_02016468(0xe, 0, b->mUnk_0c, 0x1a0);
    func_02016468(0xe, 0x1c0, p + 0xe0, 0x40);
    func_02016468(0x23, 0, c->mUnk_14, c->mUnk_10);
    func_02016468(0x1e, 0, data_ov001_021ca414->mUnk_1c->mUnk_0c, data_ov001_021ca414->mUnk_1c->mUnk_08);
}

void func_ov001_021a0e34(void) {
    s32 out;
    s32 i;

    data_ov001_021ca414->mUnk_a0 = 1;
    for (i = 0; i < 8; i++) {
        data_ov001_021ca414->mUnk_a0 &= func_0205fd78((u8) func_02029608(), (u8) (i + 1), &out);
    }
}

void func_ov001_021a0e08(s32 param_1, u16 *param_2) {
    func_02124fac(func_02029608(), param_2);
    param_2[1] = 0x2d;
    func_02124fac(param_1 + 1, param_2 + 2);
    param_2[3] = 0;
}

void func_ov001_021a0b3c(void) {
    u16 cnt10;
    s32 i;
    u16 cnt04;
    s32 j;
    s32 out;
    u16 buf[18];
    cnt04 = data_ov001_021ca414->mUnk_04->mUnk_06;
    cnt10 = data_ov001_021ca414->mUnk_10->mUnk_06;
    for (i = 0; i < 9; i++) {
        data_ov001_021ca414->mUnk_40[data_ov001_021a6dd4[i]].mUnk_00 = 0;
        for (j = 0; j < 9; j++) {
            data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][j]].mUnk_00 = 0;
        }
        for (j = 0; j < 2; j++) {
            data_ov001_021ca414->mUnk_44[cnt10 + data_ov001_021a6e10[i][j]].mUnk_00 = 0;
        }
    }
    for (j = 0; j < 7; j++) {
        data_ov001_021ca414->mUnk_40[data_ov001_021a6d88[j]].mUnk_00 = 0;
    }
    data_ov001_021ca414->mUnk_40[cnt04].mUnk_00 = 1;
    for (i = 0; i < 9; i++) {
        if (i == 8) {
            if (data_ov001_021ca414->mUnk_a0 != 0) {
                data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][1]].mUnk_00 = 1;
                func_ov001_021a6430((s32) ((s16) (func_02029608() - 1)), 1, (void *) data_ov001_021ca414->mUnk_0c,
                                    (void *) data_ov001_021ca414->mUnk_10, (u32) (0x2d), (u16) (8), 1);
            } else {
                data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][4]].mUnk_00 = 1;
                func_ov001_021a6430((s32) ((s16) (func_02029608() - 1)), 0, (void *) data_ov001_021ca414->mUnk_0c,
                                    (void *) data_ov001_021ca414->mUnk_10, (u32) (0x2d), (u16) (8), 1);
            }
        } else {
            data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][1]].mUnk_00 = 1;
        }
        data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][0]].mUnk_00 = 1;
        data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][2]].mUnk_00 = 0;
        data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][3]].mUnk_00 = 0;
        if (func_0205fd78((u8) func_02029608(), (u8) (i + 1), &out)) {
            if (out <= 4) {
                data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][5]].mUnk_00 = 1;
                data_ov001_021ca414->mUnk_44[cnt10 + data_ov001_021a6e10[i][0]].mUnk_00 = 1;
                func_0212426c(1, data_ov001_021a6e10[i][0], data_ov001_021ca414->mUnk_18, data_ov001_021a92c8[out],
                              data_ov001_021ca414->mUnk_10, data_ov001_021ca414->mUnk_44);
            } else if (out <= 7) {
                data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][out + 1]].mUnk_00 = 1;
            }
            if (i == 8) {
                data_ov001_021ca414->mUnk_a4 = 1;
            }
        }
        func_021057f0(0, func_02029608());
        if (i == 8) {
            func_02124a20(data_ov001_021a6e7c[i][2], 2, data_ov001_021ca414->mUnk_0c, data_ov001_021ca414->mUnk_10);
            func_02124a20(data_ov001_021a6e7c[i][1], 5, data_ov001_021ca414->mUnk_0c, data_ov001_021ca414->mUnk_10);
            if (data_ov001_021ca414->mUnk_a0 != 0) {
                if (func_020cccb4() == 0x12) {
                    data_ov001_021ca414->mUnk_9e = 8;
                }
                if (data_ov001_021ca414->mUnk_a4 == 0) {
                    data_ov001_021ca414->mUnk_9e = 8;
                    func_02124a20(data_ov001_021a6e7c[i][2], 0xb, data_ov001_021ca414->mUnk_0c,
                                  data_ov001_021ca414->mUnk_10);
                    func_02124a20(data_ov001_021a6e7c[i][1], 0xe, data_ov001_021ca414->mUnk_0c,
                                  data_ov001_021ca414->mUnk_10);
                    func_021057f0(3, func_02029608());
                }
            }
        }
        data_ov001_021ca414->mUnk_44[cnt10 + data_ov001_021a6e10[i][1]].mUnk_00 = 1;
        func_ov001_021a0e08((s32) ((s16) i), (u16 *) buf);
        func_0212426c(1, data_ov001_021a6e10[i][1], data_ov001_021ca414->mUnk_18, buf, data_ov001_021ca414->mUnk_10,
                      data_ov001_021ca414->mUnk_44);
        func_02124a98(data_ov001_021a6e7c[i][0], 1, data_ov001_021ca414->mUnk_0c, data_ov001_021ca414->mUnk_10);
    }
    data_ov001_021ca414->mUnk_44[45].mUnk_00 = 1;
}

void func_ov001_021a09a4(void) {
    s32 k;
    s32 ra;
    s32 ga;
    s32 ba;
    s32 rb;
    s32 gb;
    s32 bb;
    s32 c0;
    s32 c1;
    s32 c2;
    volatile u16 zero;
    u8 *pal;
    s32 col0;
    s32 col1;
    s32 cnt;
    s32 t;
    s32 d;
    s32 r;
    s32 g;
    s32 bl;

    if (data_ov001_021ca414->mUnk_a0 != 0) {
        if (data_ov001_021ca414->mUnk_a4 == 0) {
            data_ov001_021ca414->mUnk_a8 = data_ov001_021ca414->mUnk_a8 + 1;
            if (data_ov001_021ca414->mUnk_a8 >= 100) {
                data_ov001_021ca414->mUnk_a8 = 0;
            }
            if (data_ov001_021ca414->mUnk_9e == 8) {
                c0 = 9;
                c1 = 10;
                c2 = 11;
            } else {
                c0 = 12;
                c1 = 13;
                c2 = 14;
            }
            zero = 0;
            func_0214cfe4(zero, data_ov001_021ca414->mUnk_20, 0x20);
            pal = data_ov001_021ca414->mUnk_1c->mUnk_0c;
            for (k = 0; k < 16; k++) {
                col0 = ((u16 *) (pal + c0 * 32))[k];
                col1 = ((u16 *) (pal + c1 * 32))[k];
                ra = col0 & 0x1f;
                ga = (col0 & 0x3e0) >> 5;
                ba = (col0 & 0x7c00) >> 10;
                rb = col1 & 0x1f;
                gb = (col1 & 0x3e0) >> 5;
                bb = (col1 & 0x7c00) >> 10;
                cnt = data_ov001_021ca414->mUnk_a8;
                if (cnt < 50) {
                    r = ra + cnt * (rb - ra) * 2 / 100;
                    g = ga + cnt * (gb - ga) * 2 / 100;
                    bl = ba + cnt * (bb - ba) * 2 / 100;
                } else {
                    t = cnt - 50;
                    d = ra - rb;
                    r = rb + d * t * 2 / 100;
                    d = ga - gb;
                    g = gb + d * t * 2 / 100;
                    d = ba - bb;
                    bl = bb + d * t * 2 / 100;
                }
                data_ov001_021ca414->mUnk_20[k] = r | ((bl << 10) | (g << 5));
            }
            func_0200ee74(data_ov001_021ca414->mUnk_20, 0x20);
            func_02016468(0x1e, c2 << 5, data_ov001_021ca414->mUnk_20, 0x20);
        }
    }
}

void func_ov001_021a08d8(void) {
    s32 i;
    s32 cnt;
    s16 n;
    for (i = 0; i < 9; i++) {
        data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][1]].mUnk_00 = 0;
        data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][2]].mUnk_00 = 0;
        data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][3]].mUnk_00 = 0;
        data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][4]].mUnk_00 = 0;
        cnt = data_ov001_021ca414->mUnk_6c[i];
        if (cnt > 0) {
            data_ov001_021ca414->mUnk_6c[i] = cnt - 1;
            data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][3]].mUnk_00 = 1;
            n = data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][2]].mUnk_06 + 1;
            data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][3]].mUnk_06 = n;
        } else if (data_ov001_021ca414->mUnk_9e == i) {
            data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][2]].mUnk_00 = 1;
        } else if (i == 8) {
            if (data_ov001_021ca414->mUnk_a0) {
                data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][1]].mUnk_00 = 1;
            } else {
                data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][4]].mUnk_00 = 1;
            }
        } else {
            data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][1]].mUnk_00 = 1;
        }
    }
}

void func_ov001_021a0774(void) {
    Unk021ca414 *d;
    s32 i;
    s32 out;
    s32 ret;
    data_ov001_021ca414->mUnk_40[data_ov001_021a6d88[func_02029608() - 1]].mUnk_00 = 0;
    data_ov001_021ca414->mUnk_40[9].mUnk_00 = 0;
    for (i = 0; i < 9; i++) {
        data_ov001_021ca414->mUnk_40[data_ov001_021a6dd4[i]].mUnk_00 = 0;
    }
    if (data_ov001_021ca414->mUnk_9e == 8) {
        data_ov001_021ca414->mUnk_40[0].mUnk_00 = 0;
        data_ov001_021ca414->mUnk_40[1].mUnk_00 = 1;
    } else {
        data_ov001_021ca414->mUnk_40[0].mUnk_00 = 1;
        data_ov001_021ca414->mUnk_40[1].mUnk_00 = 0;
        data_ov001_021ca414->mUnk_40[data_ov001_021a6d88[func_02029608() - 1]].mUnk_00 = 1;
        data_ov001_021ca414->mUnk_40[9].mUnk_00 = 1;
        data_ov001_021ca414->mUnk_40[data_ov001_021a6dd4[data_ov001_021ca414->mUnk_9e]].mUnk_00 = 1;
    }
    ret = func_0205fd78((u8) func_02029608(), (u8) (data_ov001_021ca414->mUnk_9e + 1), &out);
    data_ov001_021ca414->mUnk_40[18].mUnk_00 = 0;
    for (i = 0; i < 6; i++) {
        data_ov001_021ca414->mUnk_40[data_ov001_021a6d7c[i]].mUnk_00 = 0;
    }
    if (ret != 0 && out <= 7) {
        if (out <= 4) {
            data_ov001_021ca414->mUnk_40[18].mUnk_00 = 1;
        }
        data_ov001_021ca414->mUnk_40[data_ov001_021a6d7c[out - 2]].mUnk_00 = 1;
    }
    d = data_ov001_021ca414;
    func_0212426c(0, 0, data_ov001_021ca414->mUnk_08,
                  func_020b3f7c(d->mUnk_58, d->mUnk_50[func_0203b680((u32) (data_ov001_021ca414->mUnk_4c),
                                                                     (u32) (func_02029608()), (u32) (d->mUnk_9e + 1)) -
                                                       1]
                                                .mUnk_0c),
                  d->mUnk_04, d->mUnk_40);
}

void func_ov001_021a0734(void) {
    u32 v0;
    u32 v1;

    func_0202947c((s8) (data_ov001_021ca414->mUnk_9e + 1));
    v0 = func_02029608();
    v1 = func_020295f8();
    func_02029468((u32) ((u16) (func_0203b680((u32) (data_ov001_021ca414->mUnk_4c), v0, v1) - 1)));
}

s32 func_ov001_021a071c(void) {
    if (data_ov001_021ca414->mUnk_ac != 0) {
        return 1;
    }
    return 0;
}

void func_ov001_021a0620(void) {
    u16 b;
    s16 v;
    s32 i;

    if (func_ov001_021a071c() != 0) {
        if (data_ov001_021ca414->mUnk_ac == 7) {
            data_ov001_021ca414->mUnk_b0 = data_ov001_021ca414->mUnk_9e;
            func_ov001_021a0774();
        } else {
            b = data_ov001_021ca414->mUnk_04->mUnk_06;
            v = func_02116d10(7 - data_ov001_021ca414->mUnk_ac, 1);
            data_ov001_021ca414->mUnk_94 = v;
            data_ov001_021ca414->mUnk_40[0].mUnk_06 = v;
            data_ov001_021ca414->mUnk_40[1].mUnk_06 = v;
            data_ov001_021ca414->mUnk_40[9].mUnk_06 = v;
            data_ov001_021ca414->mUnk_40[18].mUnk_06 = v;
            for (i = 0; i < 7; i++) {
                data_ov001_021ca414->mUnk_40[data_ov001_021a6d88[i]].mUnk_06 = v;
            }
            for (i = 0; i < 6; i++) {
                data_ov001_021ca414->mUnk_40[data_ov001_021a6d7c[i]].mUnk_06 = v;
            }
            data_ov001_021ca414->mUnk_40[b].mUnk_06 = v;
            for (i = 0; i < 9; i++) {
                data_ov001_021ca414->mUnk_40[data_ov001_021a6dd4[i]].mUnk_06 = v;
            }
        }
        data_ov001_021ca414->mUnk_ac = data_ov001_021ca414->mUnk_ac - 1;
    } else if (data_ov001_021ca414->mUnk_9e != data_ov001_021ca414->mUnk_b0) {
        data_ov001_021ca414->mUnk_ac = 7;
    }
}

void func_ov001_021a04f0(void) {
    s32 i;
    s32 j;
    u16 a;
    u16 b;

    a = data_ov001_021ca414->mUnk_04->mUnk_06;
    b = data_ov001_021ca414->mUnk_10->mUnk_06;
    data_ov001_021ca414->mUnk_64 = 0;
    data_ov001_021ca414->mUnk_68 = 0;
    data_ov001_021ca414->mUnk_90 = 0x100;
    data_ov001_021ca414->mUnk_94 = 0;
    data_ov001_021ca414->mUnk_98 = -192;
    data_ov001_021ca414->mUnk_40[0].mUnk_04 = 0x100;
    data_ov001_021ca414->mUnk_40[1].mUnk_04 = 0x100;
    data_ov001_021ca414->mUnk_40[9].mUnk_04 = 0x100;
    data_ov001_021ca414->mUnk_40[18].mUnk_04 = 0x100;
    for (i = 0; i < 7; i++) {
        data_ov001_021ca414->mUnk_40[data_ov001_021a6d88[i]].mUnk_04 = 0x100;
    }
    data_ov001_021ca414->mUnk_44[45].mUnk_04 = 0x100;
    for (i = 0; i < 6; i++) {
        data_ov001_021ca414->mUnk_40[data_ov001_021a6d7c[i]].mUnk_04 = 0x100;
    }
    data_ov001_021ca414->mUnk_40[a].mUnk_04 = 0x100;
    for (i = 0; i < 9; i++) {
        data_ov001_021ca414->mUnk_40[data_ov001_021a6dd4[i]].mUnk_04 = 0x100;
        for (j = 0; j < 9; j++) {
            data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][j]].mUnk_04 = 0x100;
        }
        for (j = 0; j < 2; j++) {
            data_ov001_021ca414->mUnk_44[b + data_ov001_021a6e10[i][j]].mUnk_04 = 0x100;
        }
    }
}

void func_ov001_021a04dc(void) {
    data_ov001_021ca414->mUnk_64 = 1;
    data_ov001_021ca414->mUnk_68 = 0;
}

void func_ov001_021a04c0(void) {
    data_ov001_021ca414->mUnk_64 = 2;
    data_ov001_021ca414->mUnk_68 = 0;
    func_02128374();
}

void func_ov001_021a04ac(void) {
    data_ov001_021ca414->mUnk_64 = 3;
    data_ov001_021ca414->mUnk_68 = 0;
}

s32 func_ov001_021a0488(void) {
    data_ov001_021ca414->mUnk_64 = 4;
    data_ov001_021ca414->mUnk_68 = 0;
    return func_0212ecc0(&data_0217d068, 0, 5);
}

void func_ov001_021a0428(void) {
    s32 i;
    void *v0;

    data_ov001_021ca414->mUnk_64 = 5;
    data_ov001_021ca414->mUnk_68 = 0;
    v0 = func_020b3f7c(data_ov001_021ca414->mUnk_54, 4);
    func_021277f8(v0, func_020b3f7c(data_ov001_021ca414->mUnk_54, 2), 0);
    for (i = 0; i < 9; i++) {
        data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][0]].mUnk_00 = 0;
    }
}

void func_ov001_021a0414(void) {
    data_ov001_021ca414->mUnk_64 = 6;
    data_ov001_021ca414->mUnk_68 = 0;
}

void func_ov001_021a03f8(void) {
    data_ov001_021ca414->mUnk_64 = 7;
    data_ov001_021ca414->mUnk_68 = 0;
    func_021277e4();
}

void func_ov001_021a03a0(void) {
    data_ov001_021ca414->mUnk_64 = 8;
    data_ov001_021ca414->mUnk_68 = 0;
    func_021282c8();
    switch (data_ov001_021ca414->mUnk_bc) {
        case 1:
            func_02105584(4, 10, func_02029608());
            break;
        case 2:
            func_02105584(0, 10, func_02029608());
            break;
    }
}

void func_ov001_021a0190(s32 param_1, s32 param_2, s32 param_3) {
    s32 i;
    void *heap;
    s32 rem;
    u16 base;

    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 1;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~3) | 1;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & 0x43) | 0xd204;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & 0x43) | 0x9004;
    heap = func_02036948((void *) param_1);
    data_ov001_021ca414 = func_02036bec(heap, 0xc0);
    data_ov001_021ca414->mUnk_5c = heap;
    data_ov001_021ca414->mUnk_60 = 0;
    data_ov001_021ca414->mUnk_9e = func_020295f8() - 1;
    data_ov001_021ca414->mUnk_9c = 0;
    data_ov001_021ca414->mUnk_ac = 0;
    data_ov001_021ca414->mUnk_a4 = 0;
    data_ov001_021ca414->mUnk_b4 = (void *) param_2;
    data_ov001_021ca414->mUnk_b8 = (void *) param_3;
    data_ov001_021ca414->mUnk_bc = 0;
    for (i = 0; i < 9; i++) {
        data_ov001_021ca414->mUnk_6c[i] = 0;
    }
    func_ov001_021a0e34();
    func_ov001_021a0e7c();
    func_020ae6d4(data_ov001_021ca414->mUnk_b4, data_ov001_021ca414->mUnk_b8);
    func_02124ed0(data_ov001_021ca414->mUnk_5c, data_ov001_021ca414->mUnk_04, data_ov001_021ca414->mUnk_08,
                  &data_ov001_021ca414->mUnk_40);
    func_02124ed0(data_ov001_021ca414->mUnk_5c, data_ov001_021ca414->mUnk_10, data_ov001_021ca414->mUnk_18,
                  &data_ov001_021ca414->mUnk_44);
    data_ov001_021ca414->mUnk_54 = func_02047a28(data_ov001_021a94a4);
    data_ov001_021ca414->mUnk_58 = func_0204799c(data_ov001_021a94b0);
    data_ov001_021ca414->mUnk_4c = func_02047a28(data_ov001_021a94bc);
    data_ov001_021ca414->mUnk_50 = (Unk021ca414_50 *) ((u8 *) func_0204799c(data_ov001_021a94d0) + 8);
    func_021243ac(data_ov001_021ca414->mUnk_5c, 0, data_ov001_021ca414->mUnk_08, 0xd2, 0x46, 0,
                  data_ov001_021ca414->mUnk_00, data_ov001_021ca414->mUnk_04, data_ov001_021ca414->mUnk_40, 0x8000);
    rem = func_02148ca0();
    for (i = 0; i < 9; i++) {
        rem -= func_021243ac(data_ov001_021ca414->mUnk_5c, data_ov001_021a6e10[i][0], data_ov001_021ca414->mUnk_18,
                             data_ov001_021a6e34[i][0], data_ov001_021a6e58[i][0], data_ov001_021a6e7c[i][5],
                             data_ov001_021ca414->mUnk_0c, data_ov001_021ca414->mUnk_10, data_ov001_021ca414->mUnk_44,
                             rem);
        base = data_ov001_021a6e10[i][0];
        rem -= func_021243ac(data_ov001_021ca414->mUnk_5c, data_ov001_021a6e10[i][1], data_ov001_021ca414->mUnk_18,
                             data_ov001_021a6e34[i][1], data_ov001_021a6e58[i][1],
                             base + data_ov001_021ca414->mUnk_10->mUnk_06, data_ov001_021ca414->mUnk_0c,
                             data_ov001_021ca414->mUnk_10, data_ov001_021ca414->mUnk_44, rem);
    }
    func_ov001_021a64ac(data_ov001_021ca414->mUnk_5c);
    func_ov001_021a0b3c();
    data_ov001_021ca414->mUnk_b0 = data_ov001_021ca414->mUnk_9e;
    func_ov001_021a0774();
    func_ov001_021a04f0();
    func_02036820(data_ov001_021ca414->mUnk_5c);
}

void func_ov001_021a0140(void) {
    switch (data_ov001_021ca414->mUnk_bc) {
        case 1:
            func_02105550(4, func_02029608());
            break;
        case 2:
            func_02105550(0, func_02029608());
            break;
    }
    func_ov001_021a64a0();
    func_02036ab0(data_ov001_021ca414->mUnk_5c);
    data_ov001_021ca414 = 0;
}

void func_ov001_021a0118(void) {
    func_021055b0(data_ov001_021ca414->mUnk_a8);
    if (func_02036c5c() != 0) {
        func_ov001_021a04dc();
    }
}

void func_ov001_0219ffb4(void) {
    s32 i;
    s32 j;
    u16 a;
    s16 v0;
    u16 b;
    s16 v1;

    func_021055b0(data_ov001_021ca414->mUnk_a8);
    a = data_ov001_021ca414->mUnk_04->mUnk_06;
    b = data_ov001_021ca414->mUnk_10->mUnk_06;
    data_ov001_021ca414->mUnk_68 = data_ov001_021ca414->mUnk_68 + 1;
    v0 = func_020ae4c0(1, 0x100, 0, data_ov001_021ca414->mUnk_68, 10);
    v1 = func_020ae4c0(1, -192, 0, data_ov001_021ca414->mUnk_68, 10);
    data_ov001_021ca414->mUnk_90 = v0;
    data_ov001_021ca414->mUnk_98 = v1;
    data_ov001_021ca414->mUnk_40[0].mUnk_04 = v0;
    data_ov001_021ca414->mUnk_40[1].mUnk_04 = v0;
    data_ov001_021ca414->mUnk_40[9].mUnk_04 = v0;
    data_ov001_021ca414->mUnk_40[18].mUnk_04 = v0;
    for (i = 0; i < 7; i++) {
        data_ov001_021ca414->mUnk_40[data_ov001_021a6d88[i]].mUnk_04 = v0;
    }
    data_ov001_021ca414->mUnk_44[45].mUnk_04 = v0;
    for (i = 0; i < 6; i++) {
        data_ov001_021ca414->mUnk_40[data_ov001_021a6d7c[i]].mUnk_04 = v0;
    }
    data_ov001_021ca414->mUnk_40[a].mUnk_04 = v0;
    for (i = 0; i < 9; i++) {
        data_ov001_021ca414->mUnk_40[data_ov001_021a6dd4[i]].mUnk_04 = v0;
        for (j = 0; j < 9; j++) {
            data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][j]].mUnk_04 = v0;
        }
        for (j = 0; j < 2; j++) {
            data_ov001_021ca414->mUnk_44[b + data_ov001_021a6e10[i][j]].mUnk_04 = v0;
        }
    }
    if (data_ov001_021ca414->mUnk_68 >= 10) {
        func_ov001_021a04c0();
    }
}

void func_ov001_0219ff8c(void) {
    func_021055b0(data_ov001_021ca414->mUnk_a8);
    if (func_02128294()) {
        func_ov001_021a04ac();
    }
}

void func_ov001_0219fc70(void) {
    u32 result = -1;
    Unk02175628Index slot = UNK_02175628_INDEX_8;
    s32 flag_b;
    s32 flag_a;
    u16 value;
    s16 current;
    s16 delta;
    s16 target;

    func_021055b0(data_ov001_021ca414->mUnk_a8);
    func_ov001_021a0620();
    flag_b = 0;
    flag_a = 0;
    value = data_02175628[slot].mUnk_4c;
    if (value == 0 && data_02175628[slot].mUnk_58 < 5) {
        flag_a = 1;
    }
    if (flag_a == 0 && data_02175628[slot].mUnk_54 == 0 && value != 0) {
        flag_b = 1;
    }
    if (flag_b) {
        result = func_0201ea84(data_ov001_021ca414->mUnk_14, data_02175628[slot].mUnk_48, data_02175628[slot].mUnk_4a);
    }
    if ((u16) (data_02175628[slot].mUnk_00 & 2) == 0) {
        flag_b = 0;
        flag_a = 0;
        value = data_02175628[slot].mUnk_4c;
        if (value == 0 && data_02175628[slot].mUnk_58 < 5) {
            flag_a = 1;
        }
        if (flag_a == 0 && data_02175628[slot].mUnk_54 == 0 && value != 0) {
            flag_b = 1;
        }
        if (!flag_b || func_02128210(data_02175628[slot].mUnk_48, data_02175628[slot].mUnk_4a) == 0) {
            goto skip;
        }
    }
    if (func_ov001_021a071c() != 0) {
        return;
    }
    func_021281c8(0xe);
    data_ov001_021ca414->mUnk_9c = 0x100;
    data_ov001_021ca414->mUnk_bc = 2;
    func_ov001_021a03a0();
    func_02128310(0);
    return;
skip:
    if (result <= 8) {
        target = data_ov001_021a6d98[result];
        if (target == 8 && data_ov001_021ca414->mUnk_a0 == 0) {
            func_0212ecc0(&data_0217d068, 0, 0x16);
            return;
        }
        data_ov001_021ca414->mUnk_9e = target;
        data_ov001_021ca414->mUnk_6c[data_ov001_021ca414->mUnk_9e] = 5;
        func_ov001_021a0488();
        return;
    }
    if ((u16) (data_02175628[slot].mUnk_00 & 1) != 0) {
        data_ov001_021ca414->mUnk_6c[data_ov001_021ca414->mUnk_9e] = 5;
        func_ov001_021a0488();
        return;
    }
    if (func_020ae408(8, 0x40)) {
        current = data_ov001_021ca414->mUnk_9e;
        delta = data_ov001_021a6de8[current];
        if (delta == 0) {
            return;
        }
        target = current + delta;
        if (target == 8 && data_ov001_021ca414->mUnk_a0 == 0) {
            target = target + data_ov001_021a6de8[target];
        }
        data_ov001_021ca414->mUnk_9e = target;
        data_ov001_021ca414->mUnk_6c[data_ov001_021ca414->mUnk_9e] = 5;
        func_0212ecc0(&data_0217d068, 0, 0);
        return;
    }
    if (func_020ae408(8, 0x80)) {
        current = data_ov001_021ca414->mUnk_9e;
        delta = data_ov001_021a6dac[current];
        if (delta == 0) {
            return;
        }
        target = current + delta;
        if (target == 8 && data_ov001_021ca414->mUnk_a0 == 0) {
            target = target + data_ov001_021a6dac[target];
        }
        data_ov001_021ca414->mUnk_9e = target;
        data_ov001_021ca414->mUnk_6c[data_ov001_021ca414->mUnk_9e] = 5;
        func_0212ecc0(&data_0217d068, 0, 0);
        return;
    }
    if (func_020ae408(8, 0x20)) {
        current = data_ov001_021ca414->mUnk_9e;
        delta = data_ov001_021a6dc0[current];
        if (delta == 0) {
            return;
        }
        target = current + delta;
        if (target == 8 && data_ov001_021ca414->mUnk_a0 == 0) {
            target = target + data_ov001_021a6dc0[target];
        }
        data_ov001_021ca414->mUnk_9e = target;
        data_ov001_021ca414->mUnk_6c[data_ov001_021ca414->mUnk_9e] = 5;
        func_0212ecc0(&data_0217d068, 0, 0);
        return;
    }
    if (func_020ae408(8, 0x10)) {
        current = data_ov001_021ca414->mUnk_9e;
        delta = data_ov001_021a6dfc[current];
        if (delta == 0) {
            return;
        }
        target = current + delta;
        if (target == 8 && data_ov001_021ca414->mUnk_a0 == 0) {
            target = target + data_ov001_021a6dfc[target];
        }
        data_ov001_021ca414->mUnk_9e = target;
        data_ov001_021ca414->mUnk_6c[data_ov001_021ca414->mUnk_9e] = 5;
        func_0212ecc0(&data_0217d068, 0, 0);
    }
}

void func_ov001_0219fc34(void) {
    func_021055b0(data_ov001_021ca414->mUnk_a8);
    func_ov001_021a0620();
    data_ov001_021ca414->mUnk_68 = data_ov001_021ca414->mUnk_68 + 1;
    if (data_ov001_021ca414->mUnk_68 >= 5) {
        if (func_ov001_021a071c() == 0) {
            func_ov001_021a0428();
        }
    }
}

void func_ov001_0219fc08(void) {
    func_021055b0(data_ov001_021ca414->mUnk_a8);
    func_ov001_021a0620();
    if (func_021277c8()) {
        func_ov001_021a0414();
    }
}

void func_ov001_0219fbdc(void) {
    func_021055b0(data_ov001_021ca414->mUnk_a8);
    func_ov001_021a0620();
    if (func_02127788()) {
        func_ov001_021a03f8();
    }
}

void func_ov001_0219fb5c(void) {
    s32 i;
    s32 r;

    func_021055b0(data_ov001_021ca414->mUnk_a8);
    func_ov001_021a0620();
    if (func_021277ac()) {
        r = func_02127794();
        switch (r) {
            case 0:
                func_ov001_021a0734();
                data_ov001_021ca414->mUnk_bc = 1;
                data_ov001_021ca414->mUnk_9c = -0x100;
                func_ov001_021a03a0();
                break;
            case -1:
            case 1:
                func_ov001_021a04ac();
                break;
        }
        for (i = 0; i < 9; i++) {
            data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][0]].mUnk_00 = 1;
        }
    }
}

void func_ov001_0219f9f8(void) {
    s32 i;
    s32 j;
    s16 first;
    s16 second;
    u16 a;
    u16 b;

    a = data_ov001_021ca414->mUnk_04->mUnk_06;
    b = data_ov001_021ca414->mUnk_10->mUnk_06;
    data_ov001_021ca414->mUnk_68 = data_ov001_021ca414->mUnk_68 + 1;
    first = func_020ae4c0(1, 0, data_ov001_021ca414->mUnk_9c, data_ov001_021ca414->mUnk_68, 10);
    second = func_020ae4c0(1, 0, -0xc0, data_ov001_021ca414->mUnk_68, 10);
    data_ov001_021ca414->mUnk_90 = first;
    data_ov001_021ca414->mUnk_98 = second;
    data_ov001_021ca414->mUnk_40[0].mUnk_04 = first;
    data_ov001_021ca414->mUnk_40[1].mUnk_04 = first;
    data_ov001_021ca414->mUnk_40[9].mUnk_04 = first;
    data_ov001_021ca414->mUnk_40[18].mUnk_04 = first;
    for (i = 0; i < 7; i++) {
        data_ov001_021ca414->mUnk_40[data_ov001_021a6d88[i]].mUnk_04 = first;
    }
    data_ov001_021ca414->mUnk_44[45].mUnk_04 = first;
    for (i = 0; i < 6; i++) {
        data_ov001_021ca414->mUnk_40[data_ov001_021a6d7c[i]].mUnk_04 = first;
    }
    data_ov001_021ca414->mUnk_40[a].mUnk_04 = first;
    for (i = 0; i < 9; i++) {
        data_ov001_021ca414->mUnk_40[data_ov001_021a6dd4[i]].mUnk_04 = first;
        for (j = 0; j < 9; j++) {
            data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][j]].mUnk_04 = first;
        }
        for (j = 0; j < 2; j++) {
            data_ov001_021ca414->mUnk_44[b + data_ov001_021a6e10[i][j]].mUnk_04 = first;
        }
    }
    if (data_ov001_021ca414->mUnk_68 == 5) {
        func_02016468(9, 0, data_ov001_021ca414->mUnk_48, 0x800);
    }
}

s32 func_ov001_0219f934(void) {
    data_ov001_021ca414->mUnk_60 = data_ov001_021ca414->mUnk_64;
    switch (data_ov001_021ca414->mUnk_60) {
        case 0:
            func_ov001_021a0118();
            break;
        case 1:
            func_ov001_0219ffb4();
            break;
        case 2:
            func_ov001_0219ff8c();
            break;
        case 3:
            func_ov001_0219fc70();
            break;
        case 4:
            func_ov001_0219fc34();
            break;
        case 5:
            func_ov001_0219fc08();
            break;
        case 6:
            func_ov001_0219fbdc();
            break;
        case 7:
            func_ov001_0219fb5c();
            break;
        case 8:
            func_ov001_0219f9f8();
            break;
    }
    func_ov001_021a08d8();
    func_ov001_021a09a4();
    func_02124c30(data_ov001_021ca414->mUnk_04, data_ov001_021ca414->mUnk_00, data_ov001_021ca414->mUnk_08,
                  data_ov001_021ca414->mUnk_b4, data_ov001_021ca414->mUnk_40);
    func_02124c30(data_ov001_021ca414->mUnk_10, data_ov001_021ca414->mUnk_0c, data_ov001_021ca414->mUnk_18,
                  data_ov001_021ca414->mUnk_b8, data_ov001_021ca414->mUnk_44);
    if (data_ov001_021ca414->mUnk_60 == 8 && data_ov001_021ca414->mUnk_68 >= 10) {
        return data_ov001_021ca414->mUnk_bc;
    }
    return 0;
}

void func_ov001_0219f8ec(void) {
    *(vu32 *) 0x4000010 = (-data_ov001_021ca414->mUnk_90 & 0x1ff) | ((-data_ov001_021ca414->mUnk_94 << 16) & 0x1ff0000);
    *(vu32 *) 0x4000014 = (-data_ov001_021ca414->mUnk_98 << 16) & 0x1ff0000;
}
