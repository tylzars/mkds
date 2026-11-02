#include "Main/Unknown/code_0206f04c.h"
#include "Main/Unknown/code_0206d000.h"
#include "Main/Unknown/code_02070398.h"
#include "Main/Unknown/code_02081374.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_0210ab48.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_020e73a0.h"
#include "Main/Unknown/code_020e7388.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0208c16c.h"
#include "Main/Unknown/code_020b33d8.h"
#include "ITCM/code_01ffb000.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_020d3c94.h"
#include "Main/Unknown/code_0208d978.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_020888b4.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b6b0.h"
#include "Main/Unknown/code_020815a0.h"
#include "Main/Unknown/code_020c4780.h"
#include "Main/Unknown/code_02104a0c.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_02040de0.h"
#include "Main/Unknown/code_020720dc.h"
#include "code_0212df7c.h"
#include "code_0212c6ac.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_027e0000.h"
#include "code_02147cd8.h"

#pragma opt_arithtransformation off

s32 func_0206f04c(Unk0206bcb0 *p, Vec3 *a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    s32 j;
    s32 g;
    s32 h;
    s32 i;
    s32 k;
    s16 l;
    Vec3 m;
    Vec3 o;
    Vec3 n;

    j = 0;
    i = func_02039828(&p->mUnk_05c, a) + 0x1000;
    if (i > 0x1000) {
        i = 0x1000;
    } else if (i < 0x29) {
        i = 0x29;
    }
    g = func_0214848c(a, &p->mUnk_2d8);
    p->mUnk_2d8.x = p->mUnk_2d8.x - (s32) (((s64) a->x * g) >> 12);
    p->mUnk_2d8.y = p->mUnk_2d8.y - (s32) (((s64) a->y * g) >> 12);
    p->mUnk_2d8.z = p->mUnk_2d8.z - (s32) (((s64) a->z * g) >> 12);
    g = func_0214848c(a, &p->mUnk_2e4);
    p->mUnk_2e4.x = p->mUnk_2e4.x - (s32) (((s64) a->x * g) >> 12);
    p->mUnk_2e4.y = p->mUnk_2e4.y - (s32) (((s64) a->y * g) >> 12);
    k = (s32) (((s64) c * i) >> 12);
    p->mUnk_2e4.z = p->mUnk_2e4.z - (s32) (((s64) a->z * g) >> 12);
    p->mUnk_38c = k;
    if (func_02039828(&p->mUnk_1fc, a) < -0x800) {
        p->mUnk_1fc = data_02154f94;
    }
    if (b == 0) {
        h = func_02039828(&p->mUnk_138, a);
        j = 1;
        g = func_0214848c(a, &p->mUnk_a4);
        m.x = (s32) (((s64) a->x * g) >> 12);
        m.y = (s32) (((s64) a->y * g) >> 12);
        m.z = (s32) (((s64) a->z * g) >> 12);
        p->mUnk_2fc = 0;
        p->mUnk_302 = 0;
        p->mUnk_300 = p->mUnk_302;
        p->mUnk_30c = 0;
        p->mUnk_386 = 0;
        if (p->mUnk_2a4 > 0x1800) {
            if (!(p->mUnk_48 & 0x20) && (m.x != 0 || m.y != 0 || m.z != 0) && c != 0x1000) {
                func_020eaa14(&m, a, 0, 0x4cd, 0, &m);
                p->mUnk_2d8.x = m.x;
                p->mUnk_2d8.z = m.z;
                p->mUnk_260 = p->mUnk_260 + m.y;
            }
            if (p->mUnk_4da <= 0) {
                if (d >= 0) {
                    func_0210b234(p, 0, d, e, 0);
                }
                if (f == 2 && e != 5 && p->mUnk_590->mUnk_058 == 0) {
                    k = p->mUnk_7c;
                    g = 0;
                    if (!(k & 1) && (k & 0x402000)) {
                        g = 1;
                    }
                    if (g == 0) {
                        n = p->mUnk_80;
                        g = 0x800;
                        if (p->mUnk_4c & 0x10000) {
                            g = 0x4cd;
                        }
                        func_02147fd8(-p->mUnk_1d0, a, &p->mUnk_80, &n);
                        func_02147fd8((s32) (((s64) p->mUnk_bc.y * (g << 4) + 0x800) >> 12), &p->mUnk_12c, &n, &n);
                        func_0208b748(0x3b, &n, p, func_0206c488);
                    }
                }
                func_02071318(p, 2);
            }
        }
        if (h > 0) {
            p->mUnk_38c = 0x4cd;
            if (p->mUnk_3dc != 0xb && p->mUnk_3dc != 8) {
                p->mUnk_48 &= 0xdfe77fdf;
                p->mUnk_238 = 0;
                p->mUnk_538.mUnk_00 = 0;
                p->mUnk_23c = 0;
                if (p->mUnk_7c & 1) {
                    if (!(p->mUnk_4c & 0x10000000) && !(p->mUnk_48 & 0x4000000)) {
                        func_02074854();
                    }
                    func_02055c5c();
                }
            }
            if (p->mUnk_2a4 > 0x2000 && c != 0x1000) {
                l = (s16) ((p->mUnk_2a4 >> 12) * 100);
                if ((u16) p->mUnk_388 > 0x7fff) {
                    l = (s16) (l * (s16) -1);
                }
                p->mUnk_386 = l;
            }
        } else if (p->mUnk_2a4 > 0x2000 && c != 0x1000) {
            k = 0x1000 - i;
            if (p->mUnk_2a4 > 0x1800 && k > 0x19a) {
                l = (s16) (((s32) (((s64) p->mUnk_2a4 * k) >> 12) >> 12) * 30);
                func_020397a8(&p->mUnk_05c, a, &o);
                if (func_02039828(&o, &p->mUnk_12c) < 0) {
                    l = (s16) (l * (s16) -1);
                }
                p->mUnk_386 = l;
            }
        }
        if ((p->mUnk_7c & 1) && p->mUnk_2a4 > 0x3000 && f == 2) {
            func_0207a6b0()->mUnk_10++;
        }
        p->mUnk_388 = 0;
    } else if (e == 4) {
        func_020813ec(p->mUnk_74, a);
    }
    if (p->mUnk_180 != 0) {
        p->mUnk_386 = 0;
    }
    return j;
}

void func_0206f574(Unk0206bcb0 *p, u32 a, Vec3 *b) {
    s32 c;
    s32 d;
    u32 e;

    if (a & 0x200000) {
        c = 0x1000;
    } else {
        c = 0xccd;
    }
    e = func_020d59f8(0x214300);
    func_0206f04c(p, b, (p->mUnk_44 & 0x80) != 0, c, (s32) (e & 0x1f00) >> 8, ((e & 0xe0) << 11) >> 16, 2);
    p->mUnk_44 |= 0x80;
    p->mUnk_250 = *b;
    if (p->mUnk_180 == 6 && b->y < -0x800 && p->mUnk_260 > 0) {
        p->mUnk_260 = -p->mUnk_260;
    }
    d = b->y;
    if (d <= 0) {
        d = -d;
    }
    if (d > 0x3e8) {
        p->mUnk_44 |= 0x40000000;
    }
    if (!(a & 0x2000000)) {
        return;
    }
    if (data_0217ac10 == 0) {
        return;
    }
    if (a & 0x10000) {
        p->mUnk_44 |= 0x4000000;
    }
}

void func_0206f694(Unk0206bcb0 *p, u32 a, Vec3 *b, s32 c) {
    Vec3 d;
    Vec3 e;

    if (a & 0x40000000) {
        p->mUnk_44 |= 0x40000;
        p->mUnk_236 += c;
    } else if (a & 0x1e34ef) {
        p->mUnk_1fc.y = 0;
    }
    if (b->x | b->y | b->z) {
        func_021484d0(b, &p->mUnk_1fc, &d);
        if ((s64) d.x * d.x + (s64) d.y * d.y + (s64) d.z * d.z < 0x1000000) {
            p->mUnk_1fc = *b;
        } else {
            func_02147fd8(0x199, &d, &p->mUnk_1fc, &p->mUnk_1fc);
        }
        p->mUnk_260 = p->mUnk_260 + p->mUnk_1fc.y;
        p->mUnk_1fc.y = 0;
    } else {
        e = data_usa_02165554;
        p->mUnk_1fc.x = (s32) (((s64) p->mUnk_1fc.x * e.x) >> 12);
        p->mUnk_1fc.y = (s32) (((s64) p->mUnk_1fc.y * e.y) >> 12);
        p->mUnk_1fc.z = (s32) (((s64) p->mUnk_1fc.z * e.z) >> 12);
        if ((s64) p->mUnk_1fc.x * p->mUnk_1fc.x + (s64) p->mUnk_1fc.y * p->mUnk_1fc.y +
                (s64) p->mUnk_1fc.z * p->mUnk_1fc.z <
            0xa429) {
            p->mUnk_1fc = data_02154f94;
        }
    }
}

void func_0206f824(Unk0206bcb0 *p, Vec3 *a, s32 b) {
    Vec3 *c;
    s32 d;
    s32 e;
    Vec3 f;
    Vec3 g;

    c = func_020e73a0((u16) p->mUnk_4d8);
    d = func_020e7388((u16) p->mUnk_4d8) * 150;
    e = 0x333;
    if (p->mUnk_7c & 2) {
        d >>= 1;
        e >>= 1;
    }
    if (b == 0) {
        func_021484d0(c, &p->mUnk_80, &g);
        func_020397a8(a, &g, &f);
        func_020397a8(&f, a, &g);
        if (!((s64) g.x * g.x + (s64) g.y * g.y + (s64) g.z * g.z < 0x10)) {
            func_02039860(&g, &p->mUnk_268);
        }
    }
    p->mUnk_44 |= 0x100000;
    p->mUnk_274 = p->mUnk_274 + e;
    if (p->mUnk_274 > d) {
        p->mUnk_274 = d;
    }
}

void func_0206f914(Unk0206bcb0 *p) {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    u32 w;
    Vec3 e;
    Vec3 f;
    Unk02165608 g;
    Unk02165608 h;

    if (p->mUnk_48 & 2) {
        a = p->mUnk_4d4;
        if (a < 0) {
            b = 0x52;
        } else if (a > 0x1000) {
            b = 8;
        } else {
            b = func_02147f34(0x4a, 0x1000);
            b = 0x52 - (s32) (((s64) b * a) >> 12);
        }
        p->mUnk_4d4 = p->mUnk_4d4 + b;
        if (p->mUnk_4d4 > 0x1000) {
            p->mUnk_4d4 = 0x1000;
        }
    } else {
        p->mUnk_4d4 = (s32) (((s64) p->mUnk_4d4 * 0xf5c) >> 12);
    }
    if (!(p->mUnk_4c & 0x20000000)) {
        if (func_020b33f4() - 0xaf > 0) {
            p->mUnk_44 |= 0x1000000;
        }
    }
    if (func_020b33f4() - 0xaf == 0) {
        if (p->mUnk_7c & 2) {
            if (func_0208c180(p->mUnk_310) != 0) {
                if (!(p->mUnk_4c & 0x20000000)) {
                    p->mUnk_4c |= 0x20000000;
                    p->mUnk_3be = 0x78;
                    func_02068a64(p, 1, 1);
                    g = data_usa_02165608;
                    w = p->mUnk_7c;
                    if ((w & 0x10) && p->mUnk_590->mUnk_058 == 0) {
                        if ((w & 1) || !(w & 0x402000)) {
                            func_02147fd8(g.mUnk_00[p->mUnk_590->mUnk_004] << 4, &p->mUnk_138, &p->mUnk_80, &e);
                            func_0208b748(0x72, &e, p, func_0206c1ac);
                            func_0208b748(0x73, &e, p, func_0206c1ac);
                        }
                    }
                    if (!(p->mUnk_48 & 0x840)) {
                        func_0210af40(p, p->mUnk_3cc, 3);
                    }
                    func_02071318(p, 1);
                    p->mUnk_3fc = 1;
                }
            } else if (func_0208c178(p->mUnk_310) != 0) {
                d = func_0208c16c(p->mUnk_310);
                p->mUnk_3be = data_usa_02154a48[d - 1];
                p->mUnk_44 |= 0x1800000;
                func_0206d020(p, 2, (s16) p->mUnk_3be);
                if (!(p->mUnk_48 & 0x840)) {
                    func_0210af40(p, p->mUnk_3cc, 5);
                }
                p->mUnk_48 |= 0x8000;
                if (p->mUnk_7c & 1) {
                    func_0207a6b0()->mUnk_00 = 1;
                } else {
                    func_021090c4(&p->mUnk_00, 0xa1, 0x7f, 0);
                }
            }
        } else if (p->mUnk_48 & 2) {
            c = p->mUnk_4d4;
            if (c > 0xf34) {
                if (!(p->mUnk_4c & 0x20000000)) {
                    p->mUnk_4c |= 0x20000000;
                    p->mUnk_3be = 0x78;
                    func_02068a64(p, 1, 1);
                    h = data_usa_02165608;
                    w = p->mUnk_7c;
                    if ((w & 0x10) && p->mUnk_590->mUnk_058 == 0) {
                        if ((w & 1) || !(w & 0x402000)) {
                            func_02147fd8(h.mUnk_00[p->mUnk_590->mUnk_004] << 4, &p->mUnk_138, &p->mUnk_80, &f);
                            func_0208b748(0x72, &f, p, func_0206c1ac);
                            func_0208b748(0x73, &f, p, func_0206c1ac);
                        }
                    }
                    if (!(p->mUnk_48 & 0x840)) {
                        func_0210af40(p, p->mUnk_3cc, 3);
                    }
                    func_02071318(p, 1);
                    p->mUnk_3fc = 1;
                }
            } else if (c > 0xd9a) {
                d = 5;
                if (c < 0xe14) {
                    d = 1;
                } else if (c < 0xe7b) {
                    d = 2;
                } else if (c < 0xecd) {
                    d = 3;
                } else if (c < 0xf0a) {
                    d = 4;
                }
                p->mUnk_3be = data_usa_02154a48[d - 1];
                p->mUnk_44 |= 0x1800000;
                func_0206d020(p, 2, (s16) p->mUnk_3be);
                if (!(p->mUnk_48 & 0x840)) {
                    func_0210af40(p, p->mUnk_3cc, 5);
                }
                p->mUnk_48 |= 0x8000;
                if (p->mUnk_7c & 1) {
                    func_0207a6b0()->mUnk_00 = 1;
                } else {
                    func_021090c4(&p->mUnk_00, 0xa1, 0x7f, 0);
                }
            }
        }
        p->mUnk_230 = func_01ffb0cc;
        if (!(p->mUnk_4c & 0x20000000)) {
            p->mUnk_44 |= 0x1000000;
        }
    }
    p->mUnk_4e8 = p->mUnk_4d4 + 0x1000;
}

void func_0206fe08(Unk0206bcb0 *p) {
    s32 b;
    s32 a;
    s32 c;
    Vec3 d;

    a = func_020d3d48(p->mUnk_80.y);
    if (a < 0 && !(p->mUnk_4c & 0x4000000)) {
        b = 0;
        c = (s32) (((s64) p->mUnk_3f4 * p->mUnk_bc.z) >> 12);
        p->mUnk_dc = (s32) (((s64) c * a) >> 12) + 0x1000;
        if (p->mUnk_dc < p->mUnk_2cc->mUnk_68[4]) {
            p->mUnk_dc = p->mUnk_2cc->mUnk_68[4];
        }
        func_0207a6c0(p);
        p->mUnk_500 = -a;
        if (func_020d3d48(p->mUnk_80.y) <= -0xa000 && func_020d3d48(p->mUnk_8c.y) > -0xa000 && p->mUnk_a4.y < -0x2000) {
            d = p->mUnk_80;
            d.y = p->mUnk_80.y - a;
            func_0208d978(&d, (p->mUnk_7c & 1) != 0);
            b = 0;
        }
        if (b != 0) {
            return;
        }
        if (p->mUnk_4c & 0x4000000) {
            return;
        }
        func_02083ec4(p);
    } else {
        p->mUnk_500 = 0;
        func_020838dc(p);
    }
}

// non-matching: the three (func_020d59f8(..) & 0xe0) << 11 >> 16 extractions are scheduled differently (original keeps
// the value in r0 and shifts in place interleaved with the next loads; ours uses another register), 22 words differ,
// same size 0x448
void func_0206ff50(Unk0206bcb0 *p, u32 a) {
    u32 b;
    u32 c;
    Unk0212c400 **d;
    s32 f;
    s32 h;
    u16 k;
    Vec3 g;
    Unk02165560 e;

    if (p->mUnk_7c & 0x400) {
        return;
    }
    if (a & 0x8000) {
        if (p->mUnk_180 == 6) {
            return;
        }
        b = ((u32) (func_020d59f8(0x8000) & 0xe0) << 11) >> 16;
        h = data_021759c0->mUnk_08;
        if (h == 2 || h == 4) {
            func_020705fc(p, b);
            return;
        }
        p->mUnk_48 |= 0x10000;
        func_020710b0(p, 0);
        return;
    }
    if (!(p->mUnk_48 & 0x800)) {
        p->mUnk_48 |= 0x800;
        k = p->mUnk_74;
        if (data_021759c0->mUnk_08 == 2) {
            c = func_02041170(0);
        } else {
            c = func_02041170(data_0217561c->mUnk_000[k].mUnk_46);
        }
        p->mUnk_3c4 = c;
        if ((p->mUnk_7c & 1) && data_021759c0->mUnk_00 == 0x1d && (data_0217c780 & 1)) {
            d = (Unk0212c400 **) func_0210e128((void *) func_02108ea0(0));
            if (data_0217d084.mUnk_0c != 0) {
                if (d[0] != 0) {
                    func_0212c6f0(d, 0);
                }
                if (d[0] != 0) {
                    func_0212c6f0(d, 0);
                }
                func_0212ecc0(d, 0, 0x1b7);
            }
        }
    }
    if (!(a & 0xc00)) {
        return;
    }
    if (p->mUnk_48 & 0x1000) {
        return;
    }
    func_020c4ab8(p->mUnk_74);
    p->mUnk_48 |= 0x41000;
    p->mUnk_48 &= 0xdfe77fdf;
    p->mUnk_238 = 0;
    p->mUnk_538.mUnk_00 = 0;
    p->mUnk_23c = 0;
    if (p->mUnk_7c & 1) {
        if (!(p->mUnk_4c & 0x10000000) && !(p->mUnk_48 & 0x4000000)) {
            func_02074854();
        }
        func_02055c5c();
    }
    if (p->mUnk_4c & 0x10000000) {
        p->mUnk_4c &= ~0x10000000;
        func_0210515c(p->mUnk_74);
        if (p->mUnk_7c & 1) {
            func_02074854();
        }
        p->mUnk_4c8 = 0x1000;
        p->mUnk_3dc = -1;
        f = 0;
        p->mUnk_29c = 0;
        if (p->mUnk_590->mUnk_058 == 0) {
            e = data_usa_02165560;
            for (f = 0; f < 3; f++) {
                func_02081f10(func_0208b7bc(e.mUnk_00[f], &p->mUnk_80), p->mUnk_74, 0x14);
            }
        }
        func_020815dc(p->mUnk_74);
        func_021090c4(&p->mUnk_00, 0xfd, 0x7f, 0);
    }
    func_020f00f0(&(data_027e00c8)[p->mUnk_74]);
    if (a & 0x400) {
        b = ((u32) (func_020d59f8(0x400) & 0xe0) << 11) >> 16;
        p->mUnk_48 |= 0x2000;
        if (b == 4) {
            p->mUnk_48 |= 0x800000;
        }
        return;
    }
    b = ((u32) (func_020d59f8(0x800) & 0xe0) << 11) >> 16;
    p->mUnk_4bc = p->mUnk_3f8;
    p->mUnk_4c |= 0x200000;
    if (p->mUnk_7c & 1) {
        func_02075d08(1);
    }
    if ((u16) (b + 0xffff) <= 1) {
        g = p->mUnk_80;
        if (b == 1) {
            p->mUnk_48 |= 0x800000;
            b = 0xce;
        } else {
            p->mUnk_48 |= 0x1000000;
            b = 0x15d;
        }
        g.y = p->mUnk_80.y - func_020d3d48(p->mUnk_80.y);
        func_0208d978(&g, (p->mUnk_7c & 1) != 0);
        p->mUnk_4c |= 0x4000000;
        func_021090c4(&p->mUnk_00, b, 0x7f, 0);
        p->mUnk_c8 = 0;
    }
    func_0210af40(p, p->mUnk_3cc, 0);
}
