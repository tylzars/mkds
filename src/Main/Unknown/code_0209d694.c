#include "Main/Unknown/code_0209d694.h"
#include "Main/Unknown/code_0209b634.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"

#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_0209dd40.h"
#include "Main/Unknown/code_0209dd44.h"
#include "ITCM/code_01ffdee4.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d278c.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_0215d000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020d26f8.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/code_0209decc.h"

void func_0209decc(u32 p0) {
    u32 v1 = ((u32) (&data_021565e4));
    u32 v3 = (*(u16 *) ((p0) + (2)));
    u32 v4 = (*(u16 *) ((v1) + (0)));
    u32 v5 = ((v3) | (v4));
    u32 v7;
    u32 v9;
    *(u16 *) ((p0) + (2)) = v5;
    ParkMapObject((void *) p0);
    CreateMapObjectSoundSourceFalloff2((MapObject *) p0);
}

u8 func_0209ddec(Unk0209d694 *a, Kart *b, u8 *c, u8 *d) {
    u8 x;
    u32 v;

    x = *c;
    v = *d;
    if (x == 1 && a->mUnk_b8 <= 1) {
        a->mUnk_00.mFlags |= data_usa_021565d8;
        a->mUnk_00.mFlags |= data_usa_021565dc;
        a->mUnk_b8 = 2;
        a->mUnk_a0 = 0x168;
        a->mUnk_00.mUnk_10.x = 0;
        a->mUnk_00.mUnk_10.y = 0x3000;
        a->mUnk_00.mUnk_10.z = 0;
        a->mUnk_bc->mUnk_70 = 0x23;
        a->mUnk_c0->mUnk_70 = 0x23;
        a->mUnk_bc->mUnk_80 = 5;
        a->mUnk_c0->mUnk_80 = 5;
        if (b->mItemEffect == 1 || b->mItemEffect == 3) {
            a->mUnk_00.mDistanceSquaredAndFlags |= data_usa_021565e0;
        }
        func_020d26f8(&a->mUnk_00, b);
    }
    return v;
}

u8 func_0209dd44(Unk0209d694 *a, Kart *b, u8 *c, u8 *d) {
    u8 x;
    u32 v;

    x = *c;
    v = *d;
    if (x == 1 && a->mUnk_b8 <= 1) {
        a->mUnk_00.mFlags |= data_usa_021565d8;
        a->mUnk_00.mFlags |= data_usa_021565dc;
        a->mUnk_b8 = 2;
        a->mUnk_a0 = 0x168;
        a->mUnk_00.mUnk_10.x = 0;
        a->mUnk_00.mUnk_10.y = 0x3000;
        a->mUnk_00.mUnk_10.z = 0;
        a->mUnk_bc->mUnk_70 = 0x23;
        a->mUnk_c0->mUnk_70 = 0x23;
        a->mUnk_bc->mUnk_80 = 5;
        a->mUnk_c0->mUnk_80 = 5;
    }
    return v;
}

u32 func_0209dd40(u32 p0) {
    return p0;
}

static inline u32 func_0209d84c_inline(Unk020f41c4_B *b) {
    b->mUnk_00 = b->mUnk_08 * b->mUnk_00 + b->mUnk_10;
    return b->mUnk_00 >> 32;
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
                s.mUnk_04 = &p->mUnk_00.mPos;
                s.mUnk_08 = 2;
                s.mUnk_0c = func_020d4ef4(&p->mUnk_00.mPos);
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
                VEC_Add(&p->mUnk_00.mPos, &p->mUnk_00.mUnk_10, &p->mUnk_00.mPos);
                if (p->mUnk_a0 > 0x78 && p->mUnk_00.mUnk_10.y < 0) {
                    if (func_01ffdee4(&p->mUnk_00.mPos, NULL, 0, p->mUnk_00.mExtent.x, 8, -2, &v, NULL, NULL, &f, NULL,
                                      NULL, NULL, NULL) != 0 &&
                        (f & 0x3f77ef) != 0) {
                        VEC_Add(&p->mUnk_00.mPos, &v, &p->mUnk_00.mPos);
                        t = p->mUnk_00.mPos.x - p->mUnk_a8.x;
                        k = p->mUnk_00.mPos.z - p->mUnk_a8.z;
                        if ((s64) t * t + (s64) k * k < 0x2710000000LL) {
                            r = (u16) (((u64) func_0209d84c_inline(func_020d22d0()) * 0x10000) >> 32);
                            k = (r >> 4) * 2;
                            p->mUnk_00.mUnk_10.x = ((s64) gPairsByAngle[k] * 0x1800) >> 12;
                            p->mUnk_00.mUnk_10.z = ((s64) gPairsByAngle[k + 1] * 0x1800) >> 12;
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
                ParkMapObject(&p->mUnk_00);
                if (p->mUnk_bc != NULL) {
                    func_0208b6b0((void **) &p->mUnk_bc);
                }
                if (p->mUnk_c0 != NULL) {
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
            p->mUnk_00.mPos.y = p->mUnk_00.mPos.y + p->mUnk_00.mUnk_10.y;
            if (p->mUnk_00.mUnk_10.y < 0) {
                p->mUnk_b4 = ((u64) func_0209d84c_inline(func_020d22d0()) * 0x10000) >> 32;
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
                p->mUnk_00.mPos.x =
                    p->mUnk_00.mPos.x + (s32) (((s64) gPairsByAngle[(p->mUnk_b4 >> 4) * 2] * 0x2000) >> 12);
                p->mUnk_00.mPos.z =
                    p->mUnk_00.mPos.z + (s32) (((s64) gPairsByAngle[(p->mUnk_b4 >> 4) * 2 + 1] * 0x2000) >> 12);
                p->mUnk_00.mPos.y = p->mUnk_00.mPos.y + p->mUnk_00.mUnk_10.y;
            } else {
                ParkMapObject(&p->mUnk_00);
                if (p->mUnk_bc != NULL) {
                    func_0208b6b0((void **) &p->mUnk_bc);
                }
                if (p->mUnk_c0 != NULL) {
                    func_0208b6b0((void **) &p->mUnk_c0);
                }
            }
            break;
    }
    if ((p->mUnk_00.mFlags & 0x12) == 0) {
        if (p->mUnk_bc != NULL) {
            func_0208b5b0(p->mUnk_bc, &p->mUnk_00.mPos);
            p->mUnk_bc->mUnk_24 &= ~2;
        }
        if (p->mUnk_c0 != NULL) {
            func_0208b5b0(p->mUnk_c0, &p->mUnk_00.mPos);
            p->mUnk_c0->mUnk_24 &= ~2;
        }
    } else {
        if (p->mUnk_bc != NULL) {
            p->mUnk_bc->mUnk_24 |= 2;
        }
        if (p->mUnk_c0 != NULL) {
            p->mUnk_c0->mUnk_24 |= 2;
        }
    }
}

void func_0209d800(void) {
    Unk0209bf70 *o;

    o = func_0209bf70(&func_0209ddec, &func_0209dd44, NULL, 1, 0, 0x18d);
    o->mUnk_28 = 0x196;
}

void func_0209d7e0(void) {
    CreateMapObjectUpdateList(&func_0209dd40, &func_0209d84c, NULL);
}

void func_0209d694(Vec3 *a, Vec3 *b) {
    Unk0209d694 *p;

    p = UnparkFirstParkedMapObject(func_02100138(0x1ae));
    if (p == NULL) {
        return;
    }
    p->mUnk_a0 = 0x1c2;
    p->mUnk_a8 = *a;
    p->mUnk_00.mPos = p->mUnk_a8;
    p->mUnk_00.mMatrix.mUnk_00[2] = *b;
    p->mUnk_00.mUnk_10.x = ((s64) b->x * 0x2000) >> 12;
    p->mUnk_00.mUnk_10.y = ((s64) b->y * 0x2000) >> 12;
    p->mUnk_00.mUnk_10.z = ((s64) b->z * 0x2000) >> 12;
    p->mUnk_a4 = 0;
    p->mUnk_b8 = 0;
    p->mUnk_bc = StartEffect(0x35, &p->mUnk_00.mPos);
    p->mUnk_c0 = StartEffect(0x34, &p->mUnk_00.mPos);
    p->mUnk_bc->mUnk_70 = 0x15;
    p->mUnk_c0->mUnk_70 = 0x15;
    p->mUnk_bc->mUnk_80 = 3;
    p->mUnk_c0->mUnk_80 = 3;
    p->mUnk_00.mFlags &= ~1;
    p->mUnk_00.mFlags &= ~8;
    p->mUnk_00.mFlags &= ~2;
    p->mUnk_00.mFlags &= ~8;
    p->mUnk_00.mAlpha = 0x1f;
}
