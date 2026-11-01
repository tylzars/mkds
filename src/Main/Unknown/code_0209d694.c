#include "Main/Unknown/code_0209d694.h"
#include "Main/Unknown/code_0208b498.h"
#include "Main/Unknown/code_0208b6b0.h"
#include "Main/Unknown/code_0208b748.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_0209dd40.h"
#include "Main/Unknown/code_0209dd44.h"
#include "ITCM/code_01ffdee4.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d22e0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_0215d000.h"
#include "code_02147cd8.h"

static inline u32 func_0209d84c_inline(Unk020f41c4_B *b) {
    b->mUnk_00 = b->mUnk_08 * b->mUnk_00 + b->mUnk_10;
    return (u32) (b->mUnk_00 >> 32);
}

void func_0209d694(Vec3 *a, Vec3 *b) {
    Unk0209d694 *p;

    p = func_0209bbfc(func_02100138(0x1ae));
    if (p == 0) {
        return;
    }
    p->mUnk_a0 = 0x1c2;
    p->mUnk_a8 = *a;
    p->mUnk_00.mUnk_04 = p->mUnk_a8;
    p->mUnk_00.mUnk_28.mUnk_18 = *b;
    p->mUnk_00.mUnk_10.x = ((s64) b->x * 0x2000) >> 12;
    p->mUnk_00.mUnk_10.y = ((s64) b->y * 0x2000) >> 12;
    p->mUnk_00.mUnk_10.z = ((s64) b->z * 0x2000) >> 12;
    p->mUnk_a4 = 0;
    p->mUnk_b8 = 0;
    p->mUnk_bc = func_0208b7bc(0x35, &p->mUnk_00.mUnk_04);
    p->mUnk_c0 = func_0208b7bc(0x34, &p->mUnk_00.mUnk_04);
    p->mUnk_bc->mUnk_70 = 0x15;
    p->mUnk_c0->mUnk_70 = 0x15;
    p->mUnk_bc->mUnk_80 = 3;
    p->mUnk_c0->mUnk_80 = 3;
    p->mUnk_00.mUnk_02 &= ~1;
    p->mUnk_00.mUnk_02 &= ~8;
    p->mUnk_00.mUnk_02 &= ~2;
    p->mUnk_00.mUnk_02 &= ~8;
    p->mUnk_00.mUnk_66 = 0x1f;
}

void func_0209d7e0(void) {
    func_0209bf48(&func_0209dd40, &func_0209d84c, 0);
}

void func_0209d800(void) {
    Unk0209bf70 *o;

    o = func_0209bf70(&func_0209ddec, &func_0209dd44, 0, 1, 0, 0x18d);
    o->mUnk_28 = 0x196;
}

void func_0209d84c(void *a, Unk0209d694 *p) {
    Vec3 v;
    Unk0210b7a8 s;
    u32 f;
    s32 t;
    s32 k;
    s32 r;

    switch (p->mUnk_b8) {
        case 0:
            if (p->mUnk_a4-- <= 0) {
                p->mUnk_b8 = 1;
                s.mUnk_00 = 0x195;
                s.mUnk_04 = &p->mUnk_00.mUnk_04;
                s.mUnk_08 = 2;
                s.mUnk_0c = func_020d4ef4(&p->mUnk_00.mUnk_04);
                func_0210b7a8(&s);
            }
            break;
        case 1:
            if (p->mUnk_a0-- != 0) {
                t = p->mUnk_00.mUnk_10.y - 0x19a;
                if (t <= -0x8000) {
                    t = -0x8000;
                }
                p->mUnk_00.mUnk_10.y = t;
                func_02148504(&p->mUnk_00.mUnk_04, &p->mUnk_00.mUnk_10, &p->mUnk_00.mUnk_04);
                if (p->mUnk_a0 > 0x78 && p->mUnk_00.mUnk_10.y < 0) {
                    if (func_01ffdee4(&p->mUnk_00.mUnk_04, 0, 0, p->mUnk_00.mUnk_58.x, 8, -2, &v, 0, 0, &f, 0, 0, 0,
                                      0) != 0 &&
                        (f & 0x3f77ef) != 0) {
                        func_02148504(&p->mUnk_00.mUnk_04, &v, &p->mUnk_00.mUnk_04);
                        t = p->mUnk_00.mUnk_04.x - p->mUnk_a8.x;
                        k = p->mUnk_00.mUnk_04.z - p->mUnk_a8.z;
                        if ((s64) t * t + (s64) k * k < 0x2710000000LL) {
                            r = (u16) (((u64) func_0209d84c_inline(func_020d22d0()) * 0x10000) >> 32);
                            k = (r >> 4) * 2;
                            p->mUnk_00.mUnk_10.x = ((s64) data_0215d4b4[k] * 0x1800) >> 12;
                            p->mUnk_00.mUnk_10.z = ((s64) data_0215d4b4[k + 1] * 0x1800) >> 12;
                        } else {
                            p->mUnk_00.mUnk_10.x = -p->mUnk_00.mUnk_10.x;
                            p->mUnk_00.mUnk_10.z = -p->mUnk_00.mUnk_10.z;
                        }
                        p->mUnk_00.mUnk_10.y = 0x2c00;
                        p->mUnk_a4 += 0x3c;
                        p->mUnk_b8 = 0;
                        p->mUnk_bc->mUnk_70 = 0x2a;
                        p->mUnk_c0->mUnk_70 = 0x2a;
                        p->mUnk_bc->mUnk_80 = 6;
                        p->mUnk_c0->mUnk_80 = 6;
                    }
                }
            } else {
                func_020d2398(&p->mUnk_00);
                if (p->mUnk_bc != 0) {
                    func_0208b6b0((void **) &p->mUnk_bc);
                }
                if (p->mUnk_c0 != 0) {
                    func_0208b6b0((void **) &p->mUnk_c0);
                }
            }
            break;
        case 2:
            t = p->mUnk_00.mUnk_10.y - 0xcd;
            if (t <= -0x2000) {
                t = -0x2000;
            }
            p->mUnk_00.mUnk_10.y = t;
            p->mUnk_00.mUnk_04.y = p->mUnk_00.mUnk_04.y + p->mUnk_00.mUnk_10.y;
            if (p->mUnk_00.mUnk_10.y < 0) {
                p->mUnk_b4 = (u16) (((u64) func_0209d84c_inline(func_020d22d0()) * 0x10000) >> 32);
                p->mUnk_b8 = 3;
            }
            break;
        case 3:
            if (p->mUnk_a0-- != 0) {
                t = p->mUnk_00.mUnk_10.y - 0xcd;
                if (t <= -0x2000) {
                    t = -0x2000;
                }
                p->mUnk_00.mUnk_10.y = t;
                p->mUnk_b4 += 0xe39;
                p->mUnk_00.mUnk_04.x =
                    p->mUnk_00.mUnk_04.x + (s32) (((s64) data_0215d4b4[(p->mUnk_b4 >> 4) * 2] * 0x2000) >> 12);
                p->mUnk_00.mUnk_04.z =
                    p->mUnk_00.mUnk_04.z + (s32) (((s64) data_0215d4b4[(p->mUnk_b4 >> 4) * 2 + 1] * 0x2000) >> 12);
                p->mUnk_00.mUnk_04.y = p->mUnk_00.mUnk_04.y + p->mUnk_00.mUnk_10.y;
            } else {
                func_020d2398(&p->mUnk_00);
                if (p->mUnk_bc != 0) {
                    func_0208b6b0((void **) &p->mUnk_bc);
                }
                if (p->mUnk_c0 != 0) {
                    func_0208b6b0((void **) &p->mUnk_c0);
                }
            }
            break;
    }
    if ((p->mUnk_00.mUnk_02 & 0x12) == 0) {
        if (p->mUnk_bc != 0) {
            func_0208b5b0(p->mUnk_bc, &p->mUnk_00.mUnk_04);
            p->mUnk_bc->mUnk_24 &= ~2;
        }
        if (p->mUnk_c0 != 0) {
            func_0208b5b0(p->mUnk_c0, &p->mUnk_00.mUnk_04);
            p->mUnk_c0->mUnk_24 &= ~2;
        }
    } else {
        if (p->mUnk_bc != 0) {
            p->mUnk_bc->mUnk_24 |= 2;
        }
        if (p->mUnk_c0 != 0) {
            p->mUnk_c0->mUnk_24 |= 2;
        }
    }
}
