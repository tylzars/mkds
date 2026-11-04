#include "Main/Unknown/code_020483e4.h"
#include "Main/Unknown/code_0207ffa4.h"
#include "Main/Unknown/code_02090354.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0207e000.h"
#include "Main/Unknown/code_0207f000.h"
#include "Main/Unknown/code_0207ff5c.h"
#include "Main/Unknown/code_02080b1c.h"
#include "Main/Unknown/code_0208f0f8.h"
#include "Main/Unknown/code_02048000.h"
#include "Main/Unknown/code_02056d54.h"
#include "Main/Unknown/code_02056d40.h"
#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_02060000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_020d22e0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020ee684.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_02166000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "00/code_02181f98.h"
#include "01/code_021956dc.h"
#include "code_021458c4.h"
#include "code_02146cbc.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/code_020917d0.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_027e0000.h"

void func_02090354(void) {
    switch (data_021759c0->mUnk_014) {
        case 1:
            data_0217b09c = data_021561d0;
            data_0217b0a4 = data_02155fd8;
            data_0217b0a0 = func_0208fafc;
            data_0217b090 = func_0208f7d4;
            data_0217b098 = func_0208f9ac;
            data_0217b094 = func_0208f6d4;
            data_0217b0ac = func_0208f4e8;
            data_0217b0a8 = func_0208f3d0;
            return;
        case 2:
            data_0217b09c = data_021562a8;
            data_0217b0a4 = data_02156128;
            data_0217b0a0 = func_0208fba0;
            data_0217b090 = func_0208f810;
            data_0217b098 = func_0208f9ac;
            data_0217b094 = func_0208f6d4;
            data_0217b0ac = func_0208f4e8;
            data_0217b0a8 = func_0208f3d0;
            return;
        case 3:
            data_0217b09c = data_02156380;
            data_0217b0a4 = data_02156080;
            data_0217b0a0 = func_0208fcac;
            data_0217b090 = func_0208f8ac;
            data_0217b098 = func_0208fa50;
            data_0217b094 = func_0208f754;
            data_0217b0ac = func_0208f5c4;
            data_0217b0a8 = func_0208f434;
            return;
        default:
            data_0217b09c = data_02156380;
            data_0217b0a4 = data_02156080;
            data_0217b0a0 = func_0208fcac;
            data_0217b090 = func_0208f8ac;
            data_0217b098 = func_0208fa50;
            data_0217b094 = func_0208f754;
            data_0217b0ac = func_0208f5c4;
            data_0217b0a8 = func_0208f434;
            return;
    }
}

s32 func_020905a8(Unk020905a8 *a) {
    BOOL r;
    BOOL t;
    Unk0206bcb0 *p;
    r = FALSE;
    t = FALSE;
    a->mUnk_28 = a->mUnk_28 - 1;
    if (a->mUnk_28 <= 0) {
        a->mUnk_28 = 0;
    } else {
        t = TRUE;
    }
    p = func_0207a974(a->mUnk_24);
    if ((p->mUnk_44 & 0xc0) != 0) {
        t = TRUE;
        a->mUnk_28 = 5;
    }
    if (t != FALSE) {
        a->mUnk_26 = a->mUnk_26 + 1;
        if (a->mUnk_26 >= 0x78) {
            a->mUnk_26 = 0;
            r = TRUE;
        }
    } else if (a->mUnk_28 <= 0) {
        a->mUnk_26 = 0;
    }
    return r;
}

void func_02090638(Unk020905a8 *a) {
    Unk0206bcb0 *p;
    s32 v;
    s32 s;
    u16 m;
    u16 w;
    s32 d;
    s32 e;
    s32 b;
    p = func_0207a974(a->mUnk_24);
    v = a->mUnk_20;
    if ((p->mUnk_44 & 0x10) != 0) {
        s = 0x19a;
    } else {
        s = 0x52;
    }
    w = p->mUnk_236 + (s16) (((s64) v * 0xb6 + 0x800) >> 12);
    b = *(volatile s32 *) &p->mUnk_78;
    m = data_0217562a[b].mBits;
    if ((u16) (m & 0x20) != 0) {
        p->mUnk_236 = p->mUnk_236 + 0xa0;
    } else if ((u16) (m & 0x10) != 0) {
        p->mUnk_236 = p->mUnk_236 - 0xa0;
    }
    d = w - p->mUnk_236;
    e = d;
    e = (e < 0) ? -e : e;
    if (e > 0x7fff) {
        if (d > 0) {
            d = -(0xffff - d);
        } else {
            d = d + 0xffff;
        }
    }
    p->mUnk_236 = p->mUnk_236 + (s32) (((s64) d * s) >> 12);
}

void func_02090748(Unk020905a8 *a) {
    Unk0206bcb0 *p;
    Vec3 v;
    s32 r;
    p = func_0207a974(a->mUnk_24);
    v = p->mUnk_80;
    a->mUnk_20 = func_0207eafc(a->mUnk_00.mUnk_00->mUnk_18, &v, &p->mUnk_12c, &p->mUnk_138);
    if ((p->mUnk_48 & 0x40000000) != 0 && p->mUnk_3e4 == 1) {
        r = func_02080bf4(&a->mUnk_00, &v);
    } else {
        r = func_02080bf4(&a->mUnk_00, &v);
        if (r == 0) {
            r = func_02080c64(&a->mUnk_00, &v);
        }
    }
    p->mUnk_2a8 = 0xa800;
    p->mUnk_cc = p->mUnk_2a8;
    p->mUnk_d0 = p->mUnk_cc;
    if (r != 0) {
        func_0207ff5c((u32) a);
    } else {
        func_02090638(a);
    }
}

s32 func_0209081c(Unk020905a8 *a) {
    func_02090748(a);
    return func_020905a8(a);
}

void func_02090838(Unk020905a8 *a, Unk02080b1c_00 *b) {
    if (b == a->mUnk_00.mUnk_04) {
        return;
    }
    func_0207ffa4(&a->mUnk_00, a->mUnk_24, b);
}

void func_0209086c(Unk020905a8 *a, u32 b) {
    Unk0206bcb0 *p;
    p = func_0207a974(b);
    a->mUnk_24 = b;
    func_0207ffa4(&a->mUnk_00, b, (Unk02080b1c_00 *) data_027e00c8[b].mUnk_1f0.mUnk_00);
    a->mUnk_26 = 0;
    a->mUnk_28 = 0;
    p->mUnk_388 = 0;
    func_0206cdd4(p);
}

BOOL func_020908d0(u32 a, void *c) {
    Unk020908d0 *b = (Unk020908d0 *) c;
    return b->mUnk_03 * 1000 + b->mUnk_02 * 60000 + b->mUnk_00 < data_0217b0b0[a - 1];
}

void func_02090920(u32 a) {
    func_02048590(data_02166548, a, (void **) &data_0217b0b0);
}

BOOL func_02090940(void) {
    enum { K0 } i;
    enum { L0 } j;
    BOOL r;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 4; j++) {
            if (func_02060440(i, j) != 0 && func_020603bc(i, j) == 0) {
                r = TRUE;
            } else {
                r = FALSE;
            }
            if (r == FALSE) {
                return FALSE;
            }
        }
    }
    return TRUE;
}

// non-matching: same control flow, but the original also tests the loop counter before both loops and uses other
// registers for the counters and the flag
s32 func_020909cc(void) {
    Unk0217b488 *p;
    s32 r;
    BOOL c;
    s32 m;
    s32 n;
    BOOL f;
    s32 i;
    s32 j;
    c = FALSE;
    r = 0;
    p = data_0217b488;
    m = p->mUnk_88;
    if (p->mUnk_8c != 0) {
        m = 3;
    }
    n = p->mUnk_84;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 4; j++) {
            if (func_02060440(i, j) != 0 && func_020603bc(i, j) == 0) {
                f = TRUE;
            } else {
                f = FALSE;
            }
            if (f == FALSE) {
                goto l2;
            }
        }
    }
    f = TRUE;
l2:
    if (f != FALSE) {
        if (n == 3 || n == 7) {
            if (data_0217b488->mUnk_7c == 0) {
                c = TRUE;
            }
        }
    }
    if (c != FALSE) {
        r = 2;
    } else {
        c = FALSE;
        if (n == 3 || n == 7) {
            if (n == 7) {
                n = 3;
            } else {
                n = 7;
            }
            if (func_02060440(n, m) != 0 && func_020603bc(n, m) <= 2) {
                f = TRUE;
            } else {
                f = FALSE;
            }
            if (f != FALSE) {
                if (data_0217b488->mUnk_7c <= 2) {
                    c = TRUE;
                }
            }
        }
        if (c != FALSE) {
            r = 1;
        }
    }
    return r;
}

u32 func_02090b24(void) {
    u32 r;
    BOOL t;
    r = 0;
    t = FALSE;
    if (func_02056dec(0x14) == 0) {
        if ((func_02060440(3, 0) != 0 && func_020603bc(3, 0) == 0) ? 1 : 0) {
            func_02056e24(0x14);
            t = TRUE;
        }
    }
    if (t != FALSE) {
        r = r | 0x20;
    }
    t = FALSE;
    if (func_02056dec(0x15) == 0) {
        if ((func_02060440(7, t) != 0 && func_020603bc(7, t) == 0) ? 1 : 0) {
            func_02056e24(0x15);
            t = TRUE;
        }
    }
    if (t != FALSE) {
        r = r | 0x40;
    }
    t = FALSE;
    if (func_02056dec(0x16) == 0) {
        if ((func_02060440(7, 1) != 0 && func_020603bc(7, 1) == 0) ? 1 : 0) {
            func_02056e24(0x16);
            t = TRUE;
        }
    }
    if (t != FALSE) {
        r = r | 0x80;
    }
    t = FALSE;
    if (func_02056dec(0x17) == 0) {
        BOOL f;
        if (func_02060440(3, 3) != 0 && func_020603bc(3, 3) == 0) {
            f = TRUE;
        } else {
            f = FALSE;
        }
        if (f != FALSE) {
            goto l1;
        }
        if (func_02060440(7, 3) != 0 && func_020603bc(7, 3) == 0) {
            f = TRUE;
        } else {
            f = FALSE;
        }
        if (f != FALSE) {
        l1:
            func_02056e24(0x17);
            t = TRUE;
        }
    }
    if (t != FALSE) {
        r = r | 0x100;
    }
    return r;
}

static inline BOOL func_02090cf8_inline(s32 a, s32 b) {
    if (func_02060440(a, b) != 0 && func_020603bc(a, b) == 0) {
        return TRUE;
    }
    return FALSE;
}

u32 func_02090cf8(void) {
    enum { K0 } i;
    u32 r;
    u32 q;
    u32 t;
    s32 j4;
    s32 j8;
    s32 j12;
    r = 0;
    for (i = 0; i < 4; i++) {
        t = 0;
        if (func_02056dec(i) == 0) {
            if (func_02090cf8_inline(0, i) != FALSE && func_02090cf8_inline(1, i) != FALSE) {
                func_02056e24(i);
                t = 1;
            }
        }
        r = r | t;
        t = 0;
        j4 = i + 4;
        if (func_02056dec(j4) == 0) {
            if (func_02090cf8_inline(2, i) != FALSE) {
                func_02056e24(j4);
                t = 2;
            }
        }
        r = r | t;
        t = 0;
        j8 = i + 8;
        if (func_02056dec(j8) == 0) {
            if (func_02090cf8_inline(4, i) != FALSE && func_02090cf8_inline(5, i) != FALSE) {
                func_02056e24(j8);
                t = 4;
            }
        }
        r = r | t;
        t = 0;
        j12 = i + 12;
        if (func_02056dec(j12) == 0) {
            if (func_02090cf8_inline(6, i) != FALSE) {
                func_02056e24(j12);
                t = 8;
            }
        }
        r = r | t;
    }
    q = 0;
    if (func_02056dec(0x10) == 0) {
        if (func_02090cf8_inline(3, 2) != FALSE && func_02090cf8_inline(7, 2) != FALSE) {
            func_02056e24(0x10);
            q = 0x10;
        }
    }
    return r | q;
}

u32 func_02090ff4(void) {
    u32 r;
    u32 q;
    BOOL t;
    r = 0;
    r = r | func_02090cf8();
    r = r | func_02090b24();
    q = 0;
    t = FALSE;
    if (func_02056d98() < 2) {
        if ((func_02060440(3, 1) != 0 && func_020603bc(3, 1) == 0) ? 1 : 0) {
            func_02056d54(2);
            t = TRUE;
        }
    }
    if (t != FALSE) {
        q = 0x200;
    }
    t = FALSE;
    if (func_02056d98() < 3) {
        BOOL f;
        if (func_02060440(3, 2) != 0 && func_020603bc(3, 2) == 0) {
            f = TRUE;
        } else {
            f = FALSE;
        }
        if (f != FALSE) {
            goto l1;
        }
        if (func_02060440(7, 2) != 0 && func_020603bc(7, 2) == 0) {
            f = TRUE;
        } else {
            f = FALSE;
        }
        if (f != FALSE) {
        l1:
            func_02056d54(3);
            t = TRUE;
        }
    }
    if (t != FALSE) {
        q = 0x400;
    }
    t = FALSE;
    if (func_02056d98() < 4) {
        if ((func_02060440(3, 3) != 0 && func_020603bc(3, 3) == 0) ? 1 : 0) {
            if ((func_02060440(7, 3) != 0 && func_020603bc(7, 3) == 0) ? 1 : 0) {
                func_02056d54(4);
                t = TRUE;
            }
        }
    }
    if (t != FALSE) {
        q = 0x800;
    }
    return r | q;
}

u32 func_0209119c(void) {
    return func_02090ff4();
}

u32 func_020911a8(void) {
    u32 r;
    r = 0;
    if (func_0205e0a0() == 10) {
        r = func_02090ff4();
        func_02056d40();
        func_02057d9c();
        if (data_021759d4->mUnk_0c != 0) {
            func_02145d38();
        }
    }
    return r;
}

u32 func_020911f4(void) {
    return func_0209bf48(func_0209151c, func_020912a0, NULL);
}

u32 func_02091214(void) {
    return func_0209bef0(CreateSmanBottom, func_020915c0, func_02091654);
}

u32 func_02091238(void) {
    return func_0209bef0(CreateSmanTop, func_020916a0, func_02091784);
}

void func_0209125c(void) {
    func_0209bf70(func_02091828, func_020917d0, NULL, 0, 1, 0x161);
}

void func_020912a0(void *a, Unk020912a0 *b) {
    Unk0210b7a8 s;
    s32 t;
    switch (b->mUnk_c8) {
        case 0:
            b->mUnk_a0 = 1;
            break;
        case 1:
            b->mUnk_b8 = b->mUnk_b8 + b->mUnk_bc;
            b->mUnk_bc = b->mUnk_bc - 0x400;
            if (b->mUnk_bc < -0x6000) {
                b->mUnk_bc = -0x6000;
            }
            if (b->mUnk_00.mCourseMapRow->mUnk_28 > 0) {
                if (b->mUnk_b8 < 0) {
                    func_020d2398(&b->mUnk_00);
                }
            } else if (b->mUnk_b8 < b->mUnk_c4) {
                b->mUnk_b8 = b->mUnk_c4;
                b->mUnk_bc = 0;
                b->mUnk_c8 = 2;
                t = 2;
                if ((b->mUnk_00.mUnk_78 & 4) == 0) {
                    if (b->mUnk_00.mUnk_70 != data_0217ca6c[2].mUnk_20) {
                        if (b->mUnk_00.mUnk_70 == data_0217ca6c[3].mUnk_20) {
                            t = 3;
                        } else {
                            t = 4;
                        }
                    }
                    s.mUnk_00 = 0x162;
                    s.mUnk_04 = &b->mUnk_00.mPos;
                    s.mUnk_08 = t;
                    s.mUnk_0c = func_020d4ef4(&b->mUnk_00.mPos);
                    func_0210b7a8(&s);
                }
            }
            b->mUnk_a0 = 0;
            break;
        case 2:
            b->mUnk_ac = b->mUnk_ac + 1;
            if (b->mUnk_ac >= 0x12b) {
                b->mUnk_ac = 0;
                b->mUnk_bc = ((b->mUnk_c0 - b->mUnk_c4) * 0x40) / 0x1000;
                b->mUnk_c8 = 3;
            }
            b->mUnk_a0 = 0;
            break;
        case 3:
            if (b->mUnk_b0 >= 0x1000) {
                b->mUnk_b0 = 0x1000;
                b->mUnk_b8 = b->mUnk_c0;
            } else {
                b->mUnk_b0 = b->mUnk_b0 + 0x40;
                b->mUnk_b8 = b->mUnk_b8 + b->mUnk_bc;
            }
            b->mUnk_ac = b->mUnk_ac + 1;
            if (b->mUnk_ac > 10) {
                b->mUnk_b4 = b->mUnk_b4 + 0x40;
                if (b->mUnk_b4 >= 0x1000) {
                    b->mUnk_ac = 0;
                    b->mUnk_b4 = 0x1000;
                    b->mUnk_00.mFlags = b->mUnk_00.mFlags & ~1;
                    b->mUnk_c8 = 0;
                }
            }
            b->mUnk_a0 = 1;
            break;
    }
    if (b->mUnk_a0 == 0) {
        return;
    }
    b->mUnk_a4 = b->mUnk_a4 + b->mUnk_a8;
    if (b->mUnk_a4 >= 0) {
        if (b->mUnk_a8 < 0) {
            b->mUnk_a8 = -0xf0;
        } else {
            b->mUnk_a8 = b->mUnk_a8 - 8;
        }
    } else {
        if (b->mUnk_a8 >= 0) {
            b->mUnk_a8 = 0xf0;
        } else {
            b->mUnk_a8 = b->mUnk_a8 + 8;
        }
    }
}

void func_0209151c(Unk0209151c *a) {
    s32 i;
    Unk020912a0 *p;
    if (a == NULL) {
        return;
    }
    i = 0;
    while (i < a->mUnk_04 && (p = a->mUnk_00[i]) != NULL) {
        p->mUnk_b0 = 0x1000;
        p->mUnk_b4 = 0x1000;
        i++;
        p->mUnk_c0 = (s32) (((s64) p->mUnk_00.mUnk_1c.y * 0xf333) >> 12);
        p->mUnk_c4 = (s32) (((s64) p->mUnk_00.mUnk_1c.y * 0x2000) >> 12);
        p->mUnk_b8 = p->mUnk_c0;
    }
}

void func_020915c0(void *a, Unk020912a0 *b) {
    s32 c;
    s32 d[3];
    s32 v;
    c = 0x1e;
    func_01ff9048(0x14, &c, 1);
    func_01ff9048(0x19, func_020e6cbc(&b->mUnk_00.mPos), 0xc);
    func_01ff9048(0x1b, &b->mUnk_00.mUnk_1c, 3);
    v = b->mUnk_b4;
    d[0] = v;
    d[1] = v;
    d[2] = v;
    func_01ff9048(0x1b, d, 3);
    func_0209bb2c(a, gSmanBottom, b);
}

void func_02091654(void *a) {
    func_0209bbd0(a, gSmanBottom);
}

void CreateSmanBottom(void *a) {
    void *p;
    p = func_0209bd08(a, gSmanBottomNsbmdName);
    gSmanBottom = p;
    func_0209b940(p, 0x3f);
}

void func_020916a0(void *a, Unk020912a0 *b) {
    s32 c;
    s32 m[9];
    s32 s[3];
    c = 0x1e;
    func_01ff9048(0x14, &c, 1);
    func_01ff9048(0x19, func_020e6cbc(&b->mUnk_00.mPos), 0xc);
    s[1] = b->mUnk_b8 >> 4;
    s[0] = 0;
    s[2] = 0;
    func_01ff9048(0x1c, s, 3);
    func_01ff9048(0x1b, &b->mUnk_00.mUnk_1c, 3);
    func_02146d60(m, data_0215d4b4[((u16) b->mUnk_a4 >> 4) * 2], data_0215d4b4[((u16) b->mUnk_a4 >> 4) * 2 + 1]);
    func_01ff9048(0x1a, m, 9);
    func_0209bb2c(a, gSmanTop, b);
}

void func_02091784(void *a) {
    func_0209bbd0(a, gSmanTop);
}

void CreateSmanTop(void *a) {
    void *p;
    p = func_0209bd08(a, gSmanTopNsbmdName);
    gSmanTop = p;
    func_0209b940(p, 0x3f);
}
