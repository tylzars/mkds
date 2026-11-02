#include "ITCM/code_01fff95c.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_020f9334.h"
#include "Main/Unknown/code_020f73fc.h"
#include "Main/Unknown/code_020f8e78.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_0208ab98.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_0200fc8c.h"

BOOL func_01fff95c(Unk027e00cc *a, Unk020f41c4_A *p, s32 f) {
    s32 i;
    u32 v;
    u32 w;
    s32 r;
    s32 m;
    enum { K0 } k;

    p->mUnk_74 &= -0x1000;
    if (p->mUnk_11c == 1 && (p->mUnk_74 & 0x8000000) && !(p->mUnk_74 & 0x10000000)) {
        func_020f0d04(p);
    }
    if (p->mUnk_114 <= 5) {
        p->mUnk_114 += 1;
    }
    if (p->mUnk_116 <= 5) {
        p->mUnk_116 += 1;
    }
    if (!(p->mUnk_74 & 0x8000)) {
        p->mUnk_fc = 0;
    }
    if (!(p->mUnk_74 & 0x800000)) {
        if (p->mUnk_100 == 0) {
            if (func_020fa0b8(p, a->mUnk_2c, 0x2e1) != 0) {
                func_020fa030(p);
            } else {
                goto L_a20;
            }
        } else {
        L_a20:
            if (p->mUnk_74 & 0xc000) {
                r = func_020fa0b8(p, a->mUnk_30, 0x19a);
                if (func_020f9dc8(p) == 0 && r != 0) {
                    func_020fa030(p);
                }
            } else if (func_020fa0b8(p, a->mUnk_30, a->mUnk_34) != 0) {
                func_020fa030(p);
            }
        }
    }
    if (p->mUnk_120 != NULL) {
        p->mUnk_120(p);
    }
    if (p->mUnk_74 & 4) {
        return TRUE;
    }
    if (!(p->mUnk_74 & 0x8000) && p->mUnk_da != -1) {
        if (f == 0) {
            func_01ffd900(p->mUnk_da, 0x6000);
        }
        for (i = 0; i < data_0217b5a8; i++) {
            w = data_0217b5bc[i];
            if (w & 0x4000) {
                if (p->mUnk_da != data_0217b5cc[i]) {
                    func_020f95d4(p, data_0217b5c4[i]);
                } else {
                    continue;
                }
            } else if (w & 0x2000) {
                func_020f944c(p, data_0217b5c4[i]);
            }
            if (p->mUnk_da == -1) {
                break;
            }
        }
    }
    v = p->mUnk_fc;
    if (p->mUnk_74 & 0x8000) {
        func_0208ab98(&p->mUnk_7c, (v & 0x3c000000) >> 26, 0x800);
    } else {
        func_0208ab98(&p->mUnk_7c, (v & 0x3c000000) >> 26, 0x5000);
    }
    if (v & 0x1e34ef) {
        p->mUnk_114 = 0;
        if (v & 0x1000000) {
            p->mUnk_116 = 0;
        }
        if (v & 0x80400) {
            if (v & 0x400) {
                if (p->mUnk_118 == 0) {
                    if (p->mUnk_74 & 0x8000) {
                        p->mUnk_118 = 0xb4;
                    } else {
                        p->mUnk_118 = 2;
                    }
                }
            }
            if (v & 0x80000) {
                p->mUnk_74 |= 0x40000000;
            } else {
                p->mUnk_74 &= ~0x40000000;
            }
        } else {
            p->mUnk_74 &= ~0x40000000;
        }
    }
    if (p->mUnk_118 != 0 && !(p->mUnk_74 & 0x180000)) {
        p->mUnk_118 -= 1;
        if (p->mUnk_118 == 0) {
            func_020f9b0c(p);
        }
    }
    if (p->mUnk_50.y < 0 && p->mUnk_44 != 0xb && p->mUnk_44 != 0xa) {
        func_020f7658(p, 1);
    }
    if (p->mUnk_114 < 5) {
        p->mUnk_74 &= ~0x20000;
    } else {
        p->mUnk_74 |= 0x20000;
        if (p->mUnk_f0.y < 0xfae && !(p->mUnk_74 & 0x40000080)) {
            func_020eac20(&p->mUnk_f0, 0xcd);
        }
    }
    if (p->mUnk_116 < 5) {
        p->mUnk_74 |= 0x40000;
    } else {
        p->mUnk_74 &= ~0x40000;
    }
    k = p->mUnk_44;
    m = data_0217bc34[k].mUnk_60;
    p->mUnk_d4 = a->mUnk_28(p->mUnk_d0, p->mUnk_e0 * m, a->mUnk_38, a->mUnk_3c, 0x1f);
    if (p->mUnk_d4 & 3) {
        p->mUnk_74 |= 0x10000;
    } else {
        p->mUnk_74 &= ~0x10000;
    }
    if (p->mUnk_74 & 0x400000) {
        func_020f90bc(p);
    }
    p->mUnk_0e4 = p->mUnk_50;
    p->mUnk_11c += 1;
    if (p->mUnk_78 & 0x4000) {
        if (p->mUnk_78 & 0x2000) {
            if (p->mUnk_11c > 4 && !(p->mUnk_74 & 0x20000)) {
                p->mUnk_78 &= ~0x4000;
            }
        } else if (p->mUnk_11c > 0x1e) {
            p->mUnk_78 &= ~0x4000;
        }
    }
    return FALSE;
}

void func_01fffe2c(u32 a, const void *b, void *c, u32 d) {
    vu32 *r = (vu32 *) 0x40000b0;
    vu32 *e;

    *(vu32 *) (0x4000000 + a * 12 + 0xb0) = (u32) b;
    e = (vu32 *) ((u32) 0x40000b0 + a * 12);
    e[1] = (u32) c;
    e[2] = d;
    *r;
    *r;
    if (a == 0) {
        e[0] = 0;
        e[1] = 0;
        e[2] = 0x81400001;
    }
    *r;
    *r;
}

void func_01fffe8c(u32 a, const void *b, void *c, u32 d) {
    u32 o = a * 12;
    vu32 *e = (vu32 *) ((u32) 0x40000b0 + o);

    *(vu32 *) (0x4000000 + o + 0xb0) = (u32) b;
    e[1] = (u32) c;
    e[2] = d;
}

void func_01fffec4(u32 a, const void *b, void *c, u32 d) {
    vu32 *r = (vu32 *) 0x40000b0;
    vu32 *e;
    u32 s = func_0200fca0();

    *(vu32 *) (0x4000000 + a * 12 + 0xb0) = (u32) b;
    e = (vu32 *) ((u32) r + a * 12);
    e[1] = (u32) c;
    e[2] = d;
    *r;
    *r;
    if (a == 0) {
        e[0] = 0;
        e[1] = 0;
        e[2] = 0x81400001;
    }
    func_0200fcb4(s);
}

void func_01ffff38(u32 a, const void *b, void *c, u32 d) {
    vu32 *e;
    u32 s = func_0200fca0();

    *(vu32 *) (0x4000000 + a * 12 + 0xb0) = (u32) b;
    e = (vu32 *) ((u32) 0x40000b0 + a * 12);
    e[1] = (u32) c;
    e[2] = d;
    func_0200fcb4(s);
}
