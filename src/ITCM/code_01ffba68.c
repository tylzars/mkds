#include "ITCM/code_01ff9598.h"
#include "ITCM/code_01ffa4b4.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffb000.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0207a780.h"
#include "Main/Unknown/code_02070398.h"
#include "Main/Unknown/code_0207a790.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061f7c.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0210ab48.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/code_02024974.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_020720dc.h"
#include "Main/Unknown/code_02066ac0.h"
#include "ITCM/code_01ffb130.h"
#include "code_02147cd8.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_02175628.h"

void func_01ffba68(Unk0206bcb0 *p) {
    s32 v;
    s32 a;
    s32 b;
    s32 c;
    BOOL d;
    s32 e;
    s32 f;
    u32 g;

    d = (p->mUnk_44 & 8) == 0;
    if (d) {
        v = p->mUnk_2cc->mUnk_14;
        a = p->mUnk_2cc->mUnk_18;
        b = p->mUnk_2cc->mUnk_1c;
    } else {
        v = p->mUnk_2cc->mUnk_20;
        a = p->mUnk_2cc->mUnk_24;
        b = p->mUnk_2cc->mUnk_28;
    }
    c = v;
    f = p->mUnk_48;
    if (f & 0x20) {
        func_0206ceb4(&v, p);
    } else if (f & 4) {
        v = -0x19a;
        if (p->mUnk_4c & 0x40) {
            v = -0x4cd;
        }
    } else if (d) {
        if (p->mUnk_4c & 0x10000040) {
            v = 0x4cd;
        } else {
            e = p->mUnk_2a8;
            f = p->mUnk_2a0;
            if (e < 0) {
                v = c + (s32) (((s64) -e * 0x52 + 0x800) >> 12);
            } else if (f < 0x800) {
                v = c;
            } else if (f > b) {
                v = a;
            } else {
                e = func_02147f34(c - a, b - 0x800);
                f = f - 0x800;
                v = c - (s32) (((s64) e * f) >> 12);
            }
        }
    }
    if (p->mUnk_4c & 0x20000000) {
        func_020713a0(p);
    }
    f = p->mUnk_48;
    if (f & 0x10000000) {
        p->mUnk_2a8 += 0x1000;
    } else if (p->mUnk_44 & 0x10) {
        g = p->mUnk_4c;
        if (!(g & 0x20000000)) {
            if (f & 0x80) {
                p->mUnk_2a8 = (s32) (((s64) p->mUnk_2a8 * 0xfae) >> 12);
            } else if (f & 0x26) {
                p->mUnk_2a8 += v;
            } else if (!(g & 0x10000000)) {
                p->mUnk_44 |= 0x400;
            }
        }
    }
    g = p->mUnk_44;
    if ((g & 0x8000) && (g & 0x10)) {
        p->mUnk_44 &= ~0x8000;
    }
    if (p->mUnk_386 != 0) {
        p->mUnk_386 = (s32) (((s64) p->mUnk_386 * 0xe66) >> 12);
        if ((p->mUnk_386 <= 0 ? -p->mUnk_386 : p->mUnk_386) < 0x14) {
            p->mUnk_386 = 0;
        }
        p->mUnk_236 += (u16) p->mUnk_386;
    }
    g = p->mUnk_44;
    if (!(g & 0x10) || !d || (g & 0x8008002)) {
        return;
    }
    if (p->mUnk_388 > 0) {
        p->mUnk_388 = p->mUnk_388 - p->mUnk_2cc->mUnk_34;
        if (p->mUnk_388 < 0) {
            p->mUnk_388 = 0;
        }
    } else if (p->mUnk_388 < 0) {
        p->mUnk_388 = p->mUnk_388 + p->mUnk_2cc->mUnk_34;
        if (p->mUnk_388 > 0) {
            p->mUnk_388 = 0;
        }
    }
}

void func_01ffbd9c(Unk0206bcb0 *p) {
    func_02147d88(p->mUnk_2a4, p->mUnk_d0);
    if (p->mUnk_44 & 0x10) {
        func_020397a8(&p->mUnk_120, &p->mUnk_244, &p->mUnk_278);
    } else {
        func_02063b10(p, &p->mUnk_278);
    }
    p->mUnk_2a0 = func_02147e28();
    if (p->mUnk_2a0 > 0x1000) {
        p->mUnk_2a0 = 0x1000;
        p->mUnk_2a4 = p->mUnk_d0;
    }
}

void func_01ffbe04(Unk0206bcb0 *p) {
    if (p->mUnk_d0 > p->mUnk_cc) {
        p->mUnk_d0 = (s32) (((s64) p->mUnk_d0 * 0xf37) >> 12);
        if (p->mUnk_d0 < p->mUnk_cc) {
            p->mUnk_d0 = p->mUnk_cc;
        }
    } else {
        p->mUnk_d0 = p->mUnk_cc;
    }
}

void func_01ffbe70(Unk0206bcb0 *p) {
    s32 *q;
    u32 f;

    p->mUnk_cc = (s32) (((s64) (s32) (((s64) p->mUnk_2cc->mUnk_10 * p->mUnk_dc) >> 12) *
                         (s32) (((s64) (s32) p->mUnk_d4 * p->mUnk_d8) >> 12)) >>
                        12);
    q = &p->mUnk_cc;
    if (p->mUnk_7c & 0x402000) {
        *q = p->mUnk_2cc->mUnk_10;
        p->mUnk_dc = 0x1000;
    }
    if (p->mUnk_48 & 0x10000000) {
        *q = p->mUnk_4c4;
        p->mUnk_dc = 0x1000;
    }
    f = p->mUnk_48;
    if (f & 0x20) {
        if ((p->mUnk_4c & 0x10000040) || (f & 0x20000000)) {
            *q = p->mUnk_2cc->mUnk_10;
            p->mUnk_dc = 0x1000;
        }
        *q = (s32) (((s64) *q * 0x14cd) >> 12);
        if (p->mUnk_48 & 0x400001) {
            if (*q < 0x8800) {
                *q = 0x8800;
                p->mUnk_dc = 0x1000;
            }
        }
    } else if (p->mUnk_4c & 0x10000040) {
        *q = (s32) (((s64) p->mUnk_2cc->mUnk_10 * 0x1333) >> 12);
        p->mUnk_dc = 0x1000;
    }
}

void func_01ffbfe4(Unk0206bcb0 *p) {
    func_02147fd8(p->mUnk_1d0 + 0x400, &p->mUnk_15c, &p->mUnk_98, &p->mUnk_1c4);
}

void func_01ffc008(Vec3 *a, const Vec3 *b, s32 c, Unk0206bcb0 *p) {
    Vec3 d;
    Vec3 e;

    func_021484d0(&p->mUnk_80, &p->mUnk_8c, &d);
    func_02148504(&d, b, &e);
    func_02147fd8(p->mUnk_1d0 + c, &p->mUnk_15c, &e, a);
}

void func_01ffc064(Vec3 *a, const Vec3 *b, s32 c, Unk0206bcb0 *p) {
    func_02147fd8(p->mUnk_1d0 + c, &p->mUnk_12c, b, a);
}

static inline const s32 func_01ffc090_inline(void) {
    return data_usa_02165500;
}

void func_01ffc090(Unk0206bcb0 *p, s32 a) {
    if (a == 0) {
        if (p->mUnk_44 & 8) {
            p->mUnk_3ec = -p->mUnk_2c4 * ((p->mUnk_2cc->mUnk_32 + p->mUnk_38a) >> 1);
        }
        func_01ffc500(&p->mUnk_2d4);
    }
    if (p->mUnk_3ec == 0 && (p->mUnk_3f0 <= 0 ? -p->mUnk_3f0 : p->mUnk_3f0) < 5) {
        p->mUnk_3f0 = 0;
    } else {
        p->mUnk_3f0 = p->mUnk_3f0 + (s32) (((s64) (p->mUnk_3ec - p->mUnk_3f0) * func_01ffc090_inline() + 0x800) >> 12);
    }
    p->mUnk_236 += (u16) p->mUnk_3f0;
}

s32 func_01ffc158(Unk0206bcb0 *p, s16 a, s16 b, s32 c, s32 d, u32 e) {
    s16 k;
    s16 x;
    u32 f;
    s32 m;

    k = p->mUnk_38a;
    p->mUnk_48 |= e;
    if (d != 0) {
        if (!(p->mUnk_44 & 8)) {
            p->mUnk_3ec = 0x32 * c;
        }
        return 1;
    }
    f = p->mUnk_44;
    if (f & 8) {
        m = p->mUnk_2c4 * c;
        x = p->mUnk_2cc->mUnk_32;
        if (m > 0) {
            x = -k;
        } else {
            x = x + k;
        }
    } else {
        m = data_usa_021654c0 * b;
        x = a - (s32) (((s64) m * p->mUnk_2a0) >> 12);
    }
    if (f & 0x10) {
        p->mUnk_2d4 += c * 0x666;
        if (p->mUnk_2d4 > 0x1000) {
            p->mUnk_2d4 = 0x1000;
        } else if (p->mUnk_2d4 < -0x1000) {
            p->mUnk_2d4 = -0x1000;
        }
    }
    if (p->mUnk_2a4 != 0 && !(p->mUnk_44 & 0x8000000)) {
        p->mUnk_3ec = x * c;
    }
    return 1;
}

s32 func_01ffc27c(Unk0206bcb0 *p, s32 a) {
    s32 x = p->mUnk_2cc->mUnk_30;
    BOOL d = FALSE;
    s32 r = 0;
    enum { K1 } b = 1;
    s32 t;
    s32 v;
    u32 f;
    u16 w;
    enum { K0 } k;
    u32 c;

    if (p->mUnk_4c & 0x30000000) {
        return 0;
    }
    v = p->mUnk_2a8;
    t = v > 0 ? v : -v;
    if (t < 0x2000) {
        t = v <= 0 ? -v : v;
        x = ((x + (s16) (s32) (((s64) x * (t >> 1)) >> 12)) << 15) >> 16;
    }
    f = p->mUnk_44;
    if ((f & 0x800) && (f & 2)) {
        t = p->mUnk_2c4 * 0x168;
        if (a == 0) {
            t = t * ((f & 0x100) ? -1 : 1);
        }
        if (p->mUnk_7c & 2) {
            t = t << 1;
        }
        p->mUnk_236 = p->mUnk_236 - t;
        k = p->mUnk_78;
        w = data_02175628[k].mUnk_02;
        if ((u16) (w & 0x20)) {
            p->mUnk_48 |= 8;
        } else if ((u16) (w & 0x10)) {
            p->mUnk_48 |= 0x10;
        }
        return 1;
    }
    if (!(f & 0x10)) {
        k = p->mUnk_78;
        w = data_02175628[k].mUnk_02;
        if ((u16) (w & 0x40)) {
            p->mUnk_234 += 0x96;
            if (p->mUnk_234 > 0x157c) {
                p->mUnk_234 = 0x157c;
            }
        } else if ((u16) (w & 0x80)) {
            p->mUnk_234 -= 0x12c;
            if (p->mUnk_234 < -0x157c) {
                p->mUnk_234 = -0x157c;
            }
        }
        d = TRUE;
    }
    c = p->mUnk_44;
    f = c;
    if (((f & 0x100) && (u16) (data_02175628[k = p->mUnk_78].mUnk_02 & 2)) || ((f & 0x100) && !(f & 0xa))) {
        b = -1;
        x = (s16) ((s16) x * (s16) b);
    }
    k = p->mUnk_78;
    w = data_02175628[k].mUnk_02;
    if ((u16) (w & 0x20)) {
        r = ((s32(*)(Unk0206bcb0 *, s32, s32, s32, s32, u32)) func_01ffc158)(p, x, b, 1, d, 8);
    } else if ((u16) (w & 0x10)) {
        r = ((s32(*)(Unk0206bcb0 *, s32, s32, s32, s32, u32)) func_01ffc158)(p, x, b, -1, d, 0x10);
    }
    return r;
}

void func_01ffc500(s32 *p) {
    *p = (s32) (((s64) *p * 0xe6a) >> 12);
    if ((*p <= 0 ? -*p : *p) < 0x7b) {
        *p = 0;
    }
}

void func_01ffc558(Unk0206bcb0 *p) {
    Unk021759c0 *d;
    enum { K0 } k;

    d = data_021759c0;
    if (d->mUnk_08 != 4) {
        return;
    }
    if (!(d->mUnk_044 & 1)) {
        return;
    }
    k = p->mUnk_78;
    data_02175628[k].mUnk_42 = 0xff6;
}

void func_01ffc5a0(Unk0206bcb0 *p) {
    u32 *r;
    u32 *q;
    u32 f;
    enum { K0 } k;

    p->mUnk_48 &= ~0x186;
    p->mUnk_44 &= ~0x40500;
    q = (u32 *) &p->mUnk_48;
    k = p->mUnk_78;
    if ((u16) (data_02175628[k].mUnk_02 & 1)) {
        *q |= 2;
    }
    k = p->mUnk_78;
    if ((u16) (data_02175628[k].mUnk_02 & 2)) {
        r = (u32 *) &p->mUnk_48;
        p->mUnk_48 |= 4;
        f = p->mUnk_48;
        if ((f & 2) && !(f & 0x8020)) {
            *r &= ~6;
            *r |= 0x80;
        }
    }
    if (p->mUnk_2a8 < 0) {
        p->mUnk_44 |= 0x100;
    }
}

BOOL func_01ffc67c(Unk0206bcb0 *p) {
    if (p->mUnk_180 != 0 || (p->mUnk_48 & 0x6052840) || (p->mUnk_7c & 0x200000a8)) {
        return TRUE;
    }
    return FALSE;
}

void func_01ffc6c0(Unk0206bcb0 *p) {
    s32 a;
    s32 b;
    enum { K0 } k;

    if (p->mUnk_48 & 0x4000) {
        p->mUnk_23a = p->mUnk_23a - 1;
        if (p->mUnk_23a <= 0) {
            p->mUnk_23a = 0;
            p->mUnk_48 &= ~0x44000;
        }
    }
    if (func_02061fec() == 1) {
        a = 0;
        if (func_01ffc67c(p) != FALSE) {
            k = p->mUnk_78;
            data_02175628[k].mUnk_42 = 0xe04;
            if (p->mUnk_4c & 0x10000000) {
                k = p->mUnk_78;
                data_02175628[k].mUnk_42 = 0xe34;
            }
            if (p->mUnk_48 & 0x2000000) {
                k = p->mUnk_78;
                data_02175628[k].mUnk_42 = 0xe05;
            }
        } else {
            k = p->mUnk_78;
            data_02175628[k].mUnk_42 = 0xff7;
            func_01ffc558(p);
        }
        func_01ffc5a0(p);
        if (p->mUnk_180 == 0) {
            b = 0;
            if (!(p->mUnk_44 & 8)) {
                b = func_0206c494(p);
            }
            a = func_01ffc27c(p, b);
            func_0206c5e4(p);
            func_01ffba68(p);
        }
        func_01ffc090(p, a);
        if (func_01ffc92c(p) == 0) {
            return;
        }
        if (p->mUnk_48 & 0x840) {
            return;
        }
        func_0210af40(p, p->mUnk_3cc, 8);
        return;
    }
    func_01ffc92c(p);
    func_01ffc558(p);
    func_01ffc5a0(p);
    k = p->mUnk_78;
    a = data_02175628[k].mUnk_02;
    if ((u16) (a & 0x20)) {
        p->mUnk_48 |= 8;
    } else if ((u16) (a & 0x10)) {
        p->mUnk_48 |= 0x10;
    }
    p->mUnk_44 |= 0x10;
}

void func_01ffc8cc(Unk0206bcb0 *p) {
    if (p->mUnk_3d2 <= 0) {
        return;
    }
    p->mUnk_3d2 = p->mUnk_3d2 - 1;
    if (p->mUnk_3d2 > 0) {
        return;
    }
    func_0210b12c(p, p->mUnk_3cc, p->mUnk_3d0);
    p->mUnk_3d2 = 0;
}

void func_01ffc920(Unk0206bcb0 *p) {
    func_02024a88(p);
}

s32 func_01ffc92c(Unk0206bcb0 *p) {
    BOOL b;
    s32 a;
    s32 c;
    Unk0206bcb0 *o;

    b = FALSE;
    a = func_0203c8dc(p->mUnk_74);
    if (a != p->mUnk_3d8) {
        if (p->mUnk_7c & 1) {
            func_0210689c((u8) (a - 1));
        }
        if (a < p->mUnk_3d8 && a < data_021759c0->mKartCount) {
            c = data_0217561c->mUnk_474[(u8) (a + 1) - 1];
            if (c >= 0) {
                o = func_0207a974((u16) c);
                if (!(o->mUnk_7c & 0x402004)) {
                    b = TRUE;
                }
            }
        }
    }
    p->mUnk_3d8 = a;
    return b;
}

void func_01ffc9e8(Unk0206bcb0 *p, s32 a) {
    s32 b;
    s32 c;
    s32 d;

    c = (p->mUnk_7c & 1) ? 3 : 2;
    b = data_usa_0216ca38[a];
    d = func_02086080(p->mUnk_74);
    func_0210ddf4(&(&data_0217d26c)[c], d + b, func_02071980, p, a);
}

void func_01ffca50(Unk0206bcb0 *p) {
    p->mUnk_48 &= ~0x18;
    p->mUnk_1d0 = (s32) (((s64) p->mUnk_4c8 * (s32) (((s64) p->mUnk_2cc->mUnk_00 * p->mUnk_394) >> 12)) >> 12);
    p->mUnk_1d4 = (s32) (((s64) p->mUnk_2cc->mUnk_04 * p->mUnk_bc.z) >> 12);
    p->mUnk_3ec = 0;
}

void func_01ffcac0(Unk0206bcb0 *p) {
    p->mUnk_2b0 = 0;
    p->mUnk_44 &= 0x57ffffdf;
    p->mUnk_4c &= 0xffeb7efd;
    p->mUnk_2b4 = p->mUnk_2b2;
    p->mUnk_2b2 = 0;
    p->mUnk_8c = p->mUnk_80;
    p->mUnk_1e4 = p->mUnk_1d8;
    p->mUnk_2f0 = p->mUnk_2e4;
    p->mUnk_2e4 = p->mUnk_2d8;
    p->mUnk_220(p);
}

void func_01ffcb58(Unk0206bcb0 *p) {
    Vec3 v;

    if (p->mUnk_7c & 0x20) {
        return;
    }
    if (p->mUnk_44 & 0x20) {
        p->mUnk_44 |= 0x80000;
    } else {
        p->mUnk_44 &= ~0x80000;
    }
    func_01ffc008(&p->mUnk_1b8, &p->mUnk_98, 0x400, p);
    func_01ffa4b4(p, &v);
    func_01ff9f60(p, &v);
    p->mUnk_244 = v;
    p->mUnk_4d0 = p->mUnk_4d0 + 1;
    if (p->mUnk_4c & 0x8000) {
        func_02084478(p);
    }
    if ((p->mUnk_7c & 1) && func_02061fec() == 1) {
        func_0207a790(p->mUnk_74);
    }
    func_01ffc920(p);
    func_01ffc8cc(p);
    if (p->mUnk_4c & 8) {
        func_02071788(p);
    }
    p->mUnk_230(p);
}

void func_01ffcc50(Unk0206bcb0 *p) {
    if (p->mUnk_7c & 0xa0) {
        func_020732d8(p);
        return;
    }
    func_01ffca50(p);
    func_01ffbe70(p);
    func_02067488(p);
    func_01ffbe04(p);
    func_01ffbd9c(p);
    func_01ffc6c0(p);
    func_01ff9d18(p);
    if (p->mUnk_48 & 0x10000) {
        func_020708a4(p);
    } else {
        func_01ffb130(p);
    }
}

// non-matching: same products, but ours needs one more saved register (r10) and no stack word, 0xac bytes against 0xb4;
// the original forms the three diagonal sums before the z products
void func_01ffccd0(void *a, void *b) {
    s32 *o = a;
    const Vec4 *q = b;
    s32 w;
    s32 x;
    s32 y;
    s32 z;

    w = q->x;
    x = q->y;
    y = q->z;
    z = q->w;
    o[0] = 0x1000 - ((x * x >> 11) + (y * y >> 11));
    o[1] = (w * x >> 11) + (z * y >> 11);
    o[2] = (w * y >> 11) - (z * x >> 11);
    o[3] = (w * x >> 11) - (z * y >> 11);
    o[4] = 0x1000 - ((y * y >> 11) + (w * w >> 11));
    o[5] = (x * y >> 11) + (z * w >> 11);
    o[6] = (w * y >> 11) + (z * x >> 11);
    o[7] = (x * y >> 11) - (z * w >> 11);
    o[8] = 0x1000 - ((w * w >> 11) + (x * x >> 11));
}

// non-matching: same as func_01ffccd0 (one more saved register, 0xbc bytes against 0xc4)
void func_01ffcd84(void *a, const Vec4 *b) {
    s32 *o = a;
    s32 w;
    s32 x;
    s32 y;
    s32 z;

    w = b->x;
    x = b->y;
    y = b->z;
    z = b->w;
    o[0] = 0x1000 - ((x * x >> 11) + (y * y >> 11));
    o[1] = (w * x >> 11) + (z * y >> 11);
    o[2] = (w * y >> 11) - (z * x >> 11);
    o[3] = (w * x >> 11) - (z * y >> 11);
    o[4] = 0x1000 - ((y * y >> 11) + (w * w >> 11));
    o[5] = (x * y >> 11) + (z * w >> 11);
    o[6] = (w * y >> 11) + (z * x >> 11);
    o[7] = (x * y >> 11) - (z * w >> 11);
    o[8] = 0x1000 - ((w * w >> 11) + (x * x >> 11));
    o[9] = 0;
    o[10] = 0;
    o[11] = 0;
}

void func_01ffce48(Vec4 *a, const Vec4 *b, Vec4 *c, s32 d) {
    c->x = a->x + ((d * (b->x - a->x)) >> 12);
    c->y = a->y + ((d * (b->y - a->y)) >> 12);
    c->z = a->z + ((d * (b->z - a->z)) >> 12);
    c->w = a->w + ((d * (b->w - a->w)) >> 12);
}

// non-matching: same products and stack word, but the load, multiply and register order differ throughout (37 words
// differ)
void func_01ffcebc(const Vec4 *a, const Vec4 *b, Vec4 *c) {
    Vec4 t;
    s32 b1 = b->y;
    s32 a1 = a->y;
    s32 b3 = b->w;
    s32 a0 = a->x;
    s32 b0 = b->x;
    s32 b2 = b->z;
    s32 a3 = a->w;
    s32 a2 = a->z;
    s32 p = a0 * b0 + a1 * b1 + a2 * b2;

    t.x = (a3 * b0 + a0 * b3 + (a1 * b2 - a2 * b1)) >> 12;
    t.y = (a1 * b3 + a3 * b1 + (a2 * b0 - a0 * b2)) >> 12;
    t.z = (a2 * b3 + a3 * b2 + (a0 * b1 - a1 * b0)) >> 12;
    t.w = (a3 * b3 - p) >> 12;
    *c = t;
}
