#include "Main/Unknown/code_0207f05c.h"
#include "Main/Unknown/code_0207e000.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02043000.h"
#include "Main/Unknown/code_020435d4.h"
#include "Main/Unknown/code_02061f7c.h"
#include "Main/Unknown/code_020738f4.h"
#include "Main/Unknown/code_02080adc.h"
#include "Main/Unknown/code_02080cc0.h"
#include "Main/Unknown/code_02080cd0.h"
#include "Main/Unknown/code_020853dc.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0208537c.h"
#include "Main/Unknown/code_020854c0.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02147cd8.h"
#include "code_02148538.h"

static inline s32 func_0207f600_inline(s32 a) {
    return (func_0207a974(a)->mUnk_7c & 0x402020) == 0;
}

static inline s32 func_0207f554_inline(u32 a, u32 b) {
    s32 r = 0;
    s32 v;
    s32 t;

    if (data_021759c0->mUnk_58 == 0 ||
        data_021759c0->mUnk_68[b].mUnk_08.mUnk_04 != data_021759c0->mUnk_68[a].mUnk_08.mUnk_04) {
        t = 0;
        v = data_021759c0->mUnk_68[b].mUnk_08.mUnk_00;
        if ((u32) v <= 3) {
            if ((1 << v) & 0xd) {
                t = 1;
            }
        }
        if (t != 0 || func_02085824(a) <= 0) {
            if (func_0207f600_inline(b)) {
                r = 1;
            }
        }
    }
    return r;
}

void func_0207f05c(Unk020888b4 *p) {
    Vec3 a;
    Vec3 b;
    Vec3 c;
    Vec3 e;
    Vec3 f;
    Vec3 g;
    Vec3 d;
    Vec3 h;
    s32 i = func_02080cc0(&p->mUnk_08.mUnk_00);
    s32 j;
    s32 k;
    s32 m;
    Unk0217aebc_128 *r;
    s32 v;

    if (p->mUnk_90 == 0 && i >= 1 && i <= 4) {
        j = 0;
        r = func_0208537c();
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        v = (s16) (u16) (r->mUnk_00 >> 52);
        if (v <= p->mUnk_88 && p->mUnk_00->mUnk_2a4 >= p->mUnk_9c) {
            a = *p->mUnk_08.mUnk_00.mUnk_00->mUnk_18;
            d = data_usa_021557c4;
            func_020397a8(&p->mUnk_08.mUnk_00.mUnk_08, &d, &b);
            func_021484d0(&p->mUnk_00->mUnk_80, &a, &c);
            m = func_02039828(&c, &b);
            k = p->mUnk_08.mUnk_00.mUnk_00->mUnk_1c;
            if (func_020738f8(m) < k) {
                j = 1;
            }
        }
        if (j != 0) {
            switch (i) {
                case 1:
                    p->mUnk_90 = 1;
                    p->mUnk_94 = 1;
                    p->mUnk_98 = 0;
                    p->mUnk_a0 = 1;
                    break;
                case 2:
                    p->mUnk_90 = 1;
                    p->mUnk_94 = 1;
                    p->mUnk_98 = 0;
                    p->mUnk_a0 = 0;
                    break;
                case 3:
                    p->mUnk_90 = 1;
                    p->mUnk_94 = 2;
                    p->mUnk_98 = 0;
                    p->mUnk_a0 = 1;
                    break;
                case 4:
                    p->mUnk_90 = 1;
                    p->mUnk_94 = 2;
                    p->mUnk_98 = 0;
                    p->mUnk_a0 = 0;
                    break;
            }
        }
    }
    if (p->mUnk_90 != 2) {
        return;
    }
    if (i != 5) {
        return;
    }
    p->mUnk_90 = 3;
    e = *p->mUnk_08.mUnk_00.mUnk_00->mUnk_18;
    h = data_usa_021557c4;
    func_020397a8(&p->mUnk_08.mUnk_00.mUnk_08, &h, &f);
    func_021484d0(&p->mUnk_00->mUnk_80, &e, &g);
    p->mUnk_74 = func_02147f34(func_02039828(&g, &f), p->mUnk_08.mUnk_00.mUnk_00->mUnk_1c + 0x1000);
    if (func_020738f8(p->mUnk_74) > 0x1000) {
        if (p->mUnk_74 > 0) {
            p->mUnk_74 = 0x1000;
        }
        p->mUnk_74 = -0x1000;
    }
    p->mUnk_74 = p->mUnk_74 >> 1;
}

// non-matching: same size and instruction order, registers differ: the original keeps p in r5, a in r4, b in r7, the
// flag d in r9 and the first inline result in r8 (ours: p r4, a r5, b r9, d r8, result r7), and the compare of the two
// 0x74 words in the inline body is "cmp a, b" with b loaded first
void func_0207f2e4(Unk020888b4 *p) {
    s32 c;
    s32 b;
    s32 d;
    u32 a;

    p->mUnk_b0 = 0;
    p->mUnk_b4 = 0;
    a = p->mUnk_04;
    if (a != func_02061f90()) {
        return;
    }
    if (data_021759c0->mUnk_014 != 3) {
        return;
    }
    a = func_0203c8dc(a);
    if (a <= 1) {
        return;
    }
    b = data_0217561c->mUnk_474[(u8) (a - 1) - 1];
    d = 0;
    if (b >= 0) {
        if (func_0207f554_inline(p->mUnk_04, (u16) b) != 0) {
            p->mUnk_b0 = func_0207a974(b);
            d = 1;
            p->mUnk_b4 = 1;
        }
    }
    if (d != 0) {
        return;
    }
    if (a >= data_021759c0->mUnk_3d0) {
        return;
    }
    c = data_0217561c->mUnk_474[(u8) (a + 1) - 1];
    if (c < 0) {
        return;
    }
    if (func_0207f554_inline(p->mUnk_04, (u16) c) != 0) {
        p->mUnk_b0 = func_0207a974(c);
    }
}

// non-matching: one instruction: the original compares the loaded 0x74 words as "cmp r1, r2" (word of a, word of b,
// with b loaded first), ours compares "cmp r2, r1"
s32 func_0207f554(u32 a, u32 b) {
    s32 r = 0;
    s32 v;
    s32 t;

    if (data_021759c0->mUnk_58 == 0 ||
        data_021759c0->mUnk_68[b].mUnk_08.mUnk_04 != data_021759c0->mUnk_68[a].mUnk_08.mUnk_04) {
        t = 0;
        v = data_021759c0->mUnk_68[b].mUnk_08.mUnk_00;
        if ((u32) v <= 3) {
            if ((1 << v) & 0xd) {
                t = 1;
            }
        }
        if (t != 0 || func_02085824(a) <= 0) {
            if ((func_0207a974(b)->mUnk_7c & 0x402020) == 0) {
                r = 1;
            }
        }
    }
    return r;
}

s32 func_0207f600(s32 a) {
    return (func_0207a974(a)->mUnk_7c & 0x402020) == 0;
}

void func_0207f630(Unk020888b4 *p, Unk0208001c *q, Unk0206bcb0 *r) {
    p->mUnk_44 = *q->mUnk_00->mUnk_18;
    p->mUnk_60 = data_usa_021557d0;
    p->mUnk_74 = 0;
}

void func_0207f668(Unk020888b4 *p, Unk0208001c *q, Unk0206bcb0 *r) {
    p->mUnk_44 = *q->mUnk_00->mUnk_18;
    if (r->mUnk_48 & 0x40000000) {
        return;
    }
    if (func_02061fb8() > 0xb4) {
        if (p->mUnk_90 == 2) {
            p->mUnk_60 = data_usa_021557d0;
            p->mUnk_74 = 0;
        } else {
            func_0207e944(p);
        }
    }
    func_02148504(&p->mUnk_44, &p->mUnk_60, &p->mUnk_44);
}

void func_0207f6f0(Unk020888b4 *p, Unk0208001c *q, Unk0206bcb0 *r, Unk02175620_bc *s, Vec3 *a, Vec3 *b) {
    Vec3 v;
    Vec3 w;
    Vec3 *c;
    s32 d;
    s32 e;
    s32 f;
    s32 g;
    s32 h;

    if (s != 0 && q->mUnk_00 != s) {
        func_0207f05c(p);
        func_02080adc(q, s);
        data_usa_0217ae44(p, q, r);
        return;
    }
    if (func_02061f90() == p->mUnk_04) {
        if (p->mUnk_00->mUnk_44 & 0x2000) {
            func_0207e7f0(p);
        }
        c = &r->mUnk_12c;
        func_021484d0(&p->mUnk_44, &r->mUnk_80, &v);
        d = func_0214848c(c, &v);
        v.x = v.x - (s32) (((s64) r->mUnk_12c.x * d) >> 12);
        v.y = v.y - (s32) (((s64) c->y * d) >> 12);
        v.z = v.z - (s32) (((s64) c->z * d) >> 12);
        func_020397a8(b, &v, &w);
        e = func_021482cc(&w);
        f = func_02148538(e, func_02039828(b, &v));
        g = (s32) (((s64) f * 0x394bb834c8LL + 0x80000000LL) >> 32);
        if (func_02039828(&w, c) < 0) {
            g *= -1;
        }
        p->mUnk_70 = func_020738f8(g);
    }
    h = func_02080bf4((Unk02080b1c *) q, a);
    if (h == 0 && (r->mUnk_48 & 0x40000000) == 0) {
        h = func_02080c64((Unk02080b1c *) q, a);
    }
    if (h == 0) {
        return;
    }
    func_0207f05c(p);
    data_usa_0217ae3c((Unk02080b1c *) q);
    data_usa_0217ae44(p, q, r);
    q->mUnk_14 = 0;
    q->mUnk_18 = 0;
}

void func_0207f8f8(Unk020888b4 *p) {
    Vec3 v;
    Vec3 w;
    Vec3 *t;
    Unk0208001c *q;
    Unk0206bcb0 *a;
    Unk02175620_bc *s;

    func_0207e668(p);
    q = &p->mUnk_08.mUnk_00;
    a = p->mUnk_00;
    if (p->mUnk_90 == 2) {
        t = &a->mUnk_50;
    } else {
        t = &a->mUnk_138;
    }
    s = q->mUnk_14;
    func_0207a948(&v, p->mUnk_04);
    func_0207f6f0(p, q, a, s, &v, t);
    if (a->mUnk_180 == 0) {
        func_0204360c(p->mUnk_00->mUnk_78, 1);
        func_021484d0(&p->mUnk_44, &v, &w);
        func_01ffd224(p, &w, t);
    }
    func_0207ebfc(p);
    func_0207f2e4(p);
}

void func_0207f9a8(Unk020888b4 *p) {
    Unk02175620_bc *a;

    func_02080cd0(&p->mUnk_08.mUnk_00, a);
    func_0207f9cc(p, 1);
}

void func_0207f9cc(Unk020888b4 *p, s32 a) {
    p->mUnk_44 = *p->mUnk_08.mUnk_00.mUnk_00->mUnk_18;
    p->mUnk_60 = data_usa_021557d0;
    p->mUnk_6c = 0;
    p->mUnk_6e = 0;
    p->mUnk_70 = 0;
    p->mUnk_74 = 0;
    p->mUnk_78 = 0;
    p->mUnk_7a = 0;
    p->mUnk_80 = 0;
    p->mUnk_7c = 0;
    p->mUnk_84 = a;
    p->mUnk_a8 = 0;
    p->mUnk_ac = 0;
    p->mUnk_b0 = 0;
    p->mUnk_b4 = 0;
    p->mUnk_b8 = 0;
    p->mUnk_bc = -0x1000;
    p->mUnk_c0 = 0;
    p->mUnk_c2 = 0;
    p->mUnk_c4 = 0;
    p->mUnk_90 = 0;
    p->mUnk_94 = 0;
    p->mUnk_98 = 0;
    p->mUnk_a0 = 0;
    func_0207e7f0(p);
}

void func_0207fa74(Unk020888b4 *p, Unk0206bcb0 *q, s32 a) {
    s32 v;
    Unk0217aebc_128 *r;

    p->mUnk_00 = q;
    p->mUnk_04 = q->mUnk_74;
    p->mUnk_06 = p->mUnk_04 % 4;
    if (a != 0) {
        v = 0;
    } else {
        v = func_020853f0(p->mUnk_04);
    }
    p->mUnk_88 = data_usa_0217ae38[v];
    p->mUnk_8c = data_usa_0217ae48[v];
    p->mUnk_9c = (s32) (((s64) p->mUnk_00->mUnk_2cc->mUnk_10 * 0x99a + 0x800) >> 12);
    func_02080d34(&p->mUnk_08, p->mUnk_04);
    func_0207f9cc(p, 0);
    r = func_0208537c();
    r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
    v = (s16) (u16) (r->mUnk_00 >> 52);
    p->mUnk_cc = v > 0x800 ? 1 : -1;
}

void func_0207fba0(void) {
    data_usa_0217ae40 = data_021759c0->mUnk_08 == 2 ? &data_usa_021557bc : &data_usa_021557c0;
    switch (func_020853dc()) {
        case 0:
            data_usa_0217ae38 = data_usa_0215572c;
            data_usa_0217ae48 = data_usa_02155798;
            break;
        case 1:
            data_usa_0217ae38 = data_usa_02155750;
            data_usa_0217ae48 = data_usa_021556e4;
            break;
        case 2:
            data_usa_0217ae38 = data_usa_02155774;
            data_usa_0217ae48 = data_usa_02155708;
            break;
        default:
            data_usa_0217ae38 = data_usa_02155774;
            data_usa_0217ae48 = data_usa_02155708;
            break;
    }
    if (data_021759c0->mUnk_00c == 5) {
        data_usa_0217ae3c = func_0207fec0;
        data_usa_0217ae44 = func_0207f630;
    } else if (data_021759c0->mUnk_00c == 6) {
        data_usa_0217ae3c = func_0207fd28;
        data_usa_0217ae44 = func_0207f630;
    } else {
        data_usa_0217ae3c = func_02080b1c;
        data_usa_0217ae44 = func_0207f668;
    }
}

void func_0207fd28(Unk02080b1c *p) {
    Unk0206bcb0 *a = func_0207a974(p->mUnk_1c);
    u16 i;
    s32 t;

    if (p->mUnk_00->mUnk_24 > 1 && p->mUnk_1e < 2) {
        if (p->mUnk_1e == 0) {
            i = (u16) (p->mUnk_1c / 3);
        } else {
            i = (u16) (p->mUnk_1c % 3);
        }
        p->mUnk_1e++;
    } else {
        i = 0;
    }
    p->mUnk_04 = p->mUnk_00;
    p->mUnk_00 = p->mUnk_00->mUnk_00[i];
    t = data_usa_021557dc[p->mUnk_00->mUnk_20->mUnk_04];
    if (t != ((Unk0206bcb0_590 *) a->mUnk_590)->mUnk_008->mUnk_1a) {
        func_02068a64(a, t, 1);
    }
    if (p->mUnk_1c != 0) {
        if (p->mUnk_00->mUnk_20->mUnk_06 == 0) {
            a->mUnk_7c &= ~0x40;
        } else {
            a->mUnk_7c |= 0x40;
        }
    }
    func_021484d0(p->mUnk_00->mUnk_18, p->mUnk_04->mUnk_18, &p->mUnk_08);
    func_02039860(&p->mUnk_08, &p->mUnk_08);
}

s32 func_0207fe70(Unk02080b1c *p) {
    s32 a = p->mUnk_00->mUnk_20->mUnk_02 << 12;

    return (s32) (((s64) a * 0x29 + 0x800) >> 12);
}

void func_0207fec0(Unk02080b1c *p) {
    u32 i = 0;
    Unk0206bcb0 *a = func_0207a974(p->mUnk_1c);
    s32 t;

    if (p->mUnk_00->mUnk_24 > 1) {
        i = p->mUnk_1c;
    }
    p->mUnk_04 = p->mUnk_00;
    p->mUnk_00 = p->mUnk_00->mUnk_00[i];
    t = data_usa_021557dc[p->mUnk_00->mUnk_20->mUnk_04];
    if (t != ((Unk0206bcb0_590 *) a->mUnk_590)->mUnk_008->mUnk_1a) {
        func_02068a64(a, t, 1);
    }
    func_021484d0(p->mUnk_00->mUnk_18, p->mUnk_04->mUnk_18, &p->mUnk_08);
    func_02039860(&p->mUnk_08, &p->mUnk_08);
}
