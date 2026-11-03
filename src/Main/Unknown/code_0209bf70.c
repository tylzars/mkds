#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bc5c.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_0209d5e8.h"
#include "Main/Unknown/code_0209d5ec.h"
#include "Main/Unknown/code_0209d694.h"
#include "Main/Unknown/code_0203c8c0.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b6b0.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_020a1e40.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d2450.h"
#include "Main/Unknown/code_020d26e0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d7da8.h"
#include "Main/Unknown/code_020d8bc0.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_021031f4.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020d8918.h"

static inline u32 func_0209c9fc_inline(Unk020f41c4_B *b) {
    b->mUnk_00 = b->mUnk_08 * b->mUnk_00 + b->mUnk_10;
    return (u32) (b->mUnk_00 >> 32);
}

#pragma thumb on
Unk0209bf70 *func_0209bf70(void *a, void *b, void *c, u32 d, u16 e, u16 f) {
    Unk0209bf70 *o;

    o = func_0209bfa8(a, b, c, d, e);
    o->mUnk_24 = f;
    return o;
}
#pragma thumb off

#pragma thumb on
u32 func_0209bf8c(void) {
    return (u32) func_0209bfa8(NULL, NULL, NULL, 0, 1);
}
#pragma thumb off

#pragma thumb on
void *func_0209bfa8(void *param_1, void *param_2, void *param_3, u32 param_4, u16 param_5) {
    Unk0209bf70 *o;

    func_020364e0(func_020364e8());
    o = func_02036bec(func_020364e0(func_020364e8()), 0x40);
    o->mUnk_00 = (u32) param_1;
    o->mUnk_04 = (u32) param_2;
    o->mUnk_20 = param_4;
    o->mUnk_1c = param_5;
    o->mUnk_18 = (u32) param_3;
    return o;
}
#pragma thumb off

BOOL func_0209bfe0(s32 a) {
    Unk0209c220 *p;
    Unk0210b7a8 s;
    s32 k;

    p = func_0209bc5c(func_02100138(0x1a8), a);
    if (p->mUnk_11c == 0) {
        p->mUnk_0b8 = 0x8000;
        p->mUnk_0c4 = 0x1000;
        p->mUnk_0c8 = 0x400;
        p->mUnk_0cc = -0x29;
        p->mUnk_0d0 = 0x1000;
        p->mUnk_0d4 = 0;
        p->mUnk_0d8 = 0;
        p->mUnk_0e4 = 0x1000;
        p->mUnk_0e8 = 0x400;
        p->mUnk_0ec = -0x29;
        p->mUnk_0f0 = 0x1000;
        p->mUnk_0f4 = 0;
        p->mUnk_11c = 1;
        if ((p->mUnk_000.mUnk_78 & 4) == 0) {
            if (p->mUnk_000.mUnk_70 == data_0217ca6c[2].mUnk_20) {
                k = 2;
            } else if (p->mUnk_000.mUnk_70 == data_0217ca6c[3].mUnk_20) {
                k = 3;
            } else {
                k = 4;
            }
            s.mUnk_00 = 0x1cf;
            s.mUnk_04 = &p->mUnk_000.mUnk_04;
            s.mUnk_08 = k;
            s.mUnk_0c = func_020d4ef4(&p->mUnk_000.mUnk_04);
            func_0210b7a8(&s);
        }
        return TRUE;
    }
    return FALSE;
}

void func_0209c0d4(void) {
    func_0209bf48(func_0209c4f0, func_0209c220, NULL);
}

void func_0209c0f4(void) {
    func_0209bf1c(func_0209c738, func_0209c5b8, NULL);
}

void func_0209c114(void) {
    func_0209bf1c(func_0209c770, func_0209c678, NULL);
}

void func_0209c134(void) {
    func_0209bf1c(CreateBound, func_0209c7a8, NULL);
}

void func_0209c154(void) {
    Unk0209bf70 *o;

    o = func_0209bfa8(func_0209c9fc, func_0209c964, func_0209c8b0, 1, 1);
    o->mUnk_28 = 0x155;
}

void func_0209c198(void) {
    Unk0209bf70 *o;

    o = func_0209bfa8(func_0209c9fc, func_0209c964, func_0209c8b0, 1, 1);
    o->mUnk_28 = 0x156;
}

void func_0209c1dc(void) {
    Unk0209bf70 *o;

    o = func_0209bfa8(func_0209c9fc, func_0209c964, func_0209c8b0, 1, 1);
    o->mUnk_28 = 0x1cf;
}

void func_0209c220(Unk02100094 *a, Unk0209c220 *p) {
    u16 v;
    s32 t;
    s32 i;
    s32 n;

    if (p->mUnk_0f8.mUnk_08 != 0xffff) {
        func_020d8cc8(&p->mUnk_0f8);
        func_020d8bf8(&p->mUnk_0f8, &p->mUnk_000.mUnk_04, &p->mUnk_000.mUnk_10);
        v = func_0209b634(gBound);
        p->mUnk_0a0 += 1;
        if (p->mUnk_0a0 >= v) {
            p->mUnk_0a0 = 1;
        }
    } else {
        p->mUnk_000.mUnk_10.x = 0;
        p->mUnk_000.mUnk_10.y = 0;
        p->mUnk_000.mUnk_10.z = 0;
        p->mUnk_0a0 = 0;
    }
    if (p->mUnk_11c == 1) {
        p->mUnk_0b8 += p->mUnk_0d0;
        t = func_0209c4bc(p->mUnk_0c8, func_0209c4d8(p->mUnk_0b8));
        p->mUnk_0c0 = p->mUnk_0c4 + t - p->mUnk_0bc;
        p->mUnk_0bc += p->mUnk_0c0;
        if (p->mUnk_0c8 > 0) {
            t = p->mUnk_0c8 + p->mUnk_0cc;
            if (t <= 0) {
                t = 0;
            }
            p->mUnk_0c8 = t;
        } else if (p->mUnk_0c8 < 0) {
            t = p->mUnk_0c8 + p->mUnk_0cc;
            if (t >= 0) {
                t = 0;
            }
            p->mUnk_0c8 = t;
        }
        if (p->mUnk_0d0 > 0) {
            t = p->mUnk_0d0 + p->mUnk_0d4;
            if (t <= 0) {
                t = 0;
            }
            p->mUnk_0d0 = t;
        } else if (p->mUnk_0d0 < 0) {
            t = p->mUnk_0d0 + p->mUnk_0d4;
            if (t >= 0) {
                t = 0;
            }
            p->mUnk_0d0 = t;
        }
        p->mUnk_0d8 += p->mUnk_0f0;
        t = func_0209c4bc(p->mUnk_0e8, func_0209c4d8(p->mUnk_0d8));
        p->mUnk_0e0 = p->mUnk_0e4 + t - p->mUnk_0dc;
        p->mUnk_0dc += p->mUnk_0e0;
        if (p->mUnk_0e8 > 0) {
            t = p->mUnk_0e8 + p->mUnk_0ec;
            if (t <= 0) {
                t = 0;
            }
            p->mUnk_0e8 = t;
        } else if (p->mUnk_0e8 < 0) {
            t = p->mUnk_0e8 + p->mUnk_0ec;
            if (t >= 0) {
                t = 0;
            }
            p->mUnk_0e8 = t;
        }
        if (p->mUnk_0f0 > 0) {
            t = p->mUnk_0f0 + p->mUnk_0f4;
            if (t <= 0) {
                t = 0;
            }
            p->mUnk_0f0 = t;
        } else if (p->mUnk_0f0 < 0) {
            t = p->mUnk_0f0 + p->mUnk_0f4;
            if (t >= 0) {
                t = 0;
            }
            p->mUnk_0f0 = t;
        }
        if (p->mUnk_0c8 == 0 && p->mUnk_0e8 == 0) {
            p->mUnk_11c = 0;
            p->mUnk_000.mUnk_1c.x = p->mUnk_0b4;
        } else {
            p->mUnk_000.mUnk_1c.x = ((s64) p->mUnk_0b4 * p->mUnk_0bc) >> 12;
        }
    } else {
        p->mUnk_000.mUnk_1c.x = p->mUnk_0b4;
    }
    n = data_021759c0->mKartCount;
    for (i = 0; i < n; i++) {
        if (p->mUnk_120[i] > 0) {
            p->mUnk_120[i] -= 1;
        }
    }
}

s32 func_0209c4bc(s32 a, s32 b) {
    return ((s64) a * b + 0x800) >> 12;
}

s16 func_0209c4d8(s32 a) {
    return data_0215d4b4[(a >> 4) * 2];
}

void func_0209c4f0(Unk02100094 *a) {
    s32 i;
    Unk0209c220 *p;

    if (a == NULL) {
        return;
    }
    for (i = 0; i < a->mUnk_04 && (p = a->mUnk_00[i]) != NULL; i++) {
        if (p->mUnk_000.mUnk_9c->mUnk_26 >= 0) {
            func_020d7da8(&p->mUnk_0f8, p->mUnk_000.mUnk_9c, 0);
            p->mUnk_0f8.mUnk_04 = 0x3000;
            p->mUnk_0f8.mUnk_10 = ((s64) p->mUnk_0f8.mUnk_00->mUnk_00[p->mUnk_0f8.mUnk_0c].mUnk_34 * 0x3000) >> 12;
        } else {
            p->mUnk_0f8.mUnk_08 = 0xffff;
        }
    }
}

void func_0209c5b8(Unk02100094 *a, Unk0209c220 *p) {
    s32 v[4];
    s32 x;
    s32 y;

    v[0] = 0x1e;
    func_01ff9048(0x14, &v[0], 1);
    p->mUnk_000.mUnk_28.mUnk_00[3].x = p->mUnk_000.mUnk_04.x >> 4;
    p->mUnk_000.mUnk_28.mUnk_00[3].y = p->mUnk_000.mUnk_04.y >> 4;
    p->mUnk_000.mUnk_28.mUnk_00[3].z = p->mUnk_000.mUnk_04.z >> 4;
    func_01ff9048(0x19, &p->mUnk_000.mUnk_28, 0xc);
    if (p->mUnk_11c == 1) {
        x = p->mUnk_0bc;
        y = p->mUnk_0dc;
        v[1] = x;
        v[2] = y;
        v[3] = x;
        func_01ff9048(0x1b, &v[1], 3);
    }
    func_01ff9048(0x1b, &p->mUnk_000.mUnk_1c, 3);
    func_0209bb2c(a, gBerry, p);
}

void func_0209c678(Unk02100094 *a, Unk0209c220 *p) {
    s32 v[4];
    s32 x;
    s32 y;

    v[0] = 0x1e;
    func_01ff9048(0x14, &v[0], 1);
    p->mUnk_000.mUnk_28.mUnk_00[3].x = p->mUnk_000.mUnk_04.x >> 4;
    p->mUnk_000.mUnk_28.mUnk_00[3].y = p->mUnk_000.mUnk_04.y >> 4;
    p->mUnk_000.mUnk_28.mUnk_00[3].z = p->mUnk_000.mUnk_04.z >> 4;
    func_01ff9048(0x19, &p->mUnk_000.mUnk_28, 0xc);
    if (p->mUnk_11c == 1) {
        x = p->mUnk_0bc;
        y = p->mUnk_0dc;
        v[1] = x;
        v[2] = y;
        v[3] = x;
        func_01ff9048(0x1b, &v[1], 3);
    }
    func_01ff9048(0x1b, &p->mUnk_000.mUnk_1c, 3);
    func_0209bb2c(a, gCream, p);
}

void func_0209c738(void *a) {
    gBerry = func_0209be84(a, gBerryNsbmdName);
    func_02103554(gCreamEffectNsbmdName);
}

void func_0209c770(void *a) {
    gCream = func_0209be84(a, gCreamNsbmdName);
    func_02103554(data_usa_02167328);
}

void func_0209c7a8(Unk02100094 *a, Unk0209c220 *p) {
    s32 v[4];
    s32 x;
    s32 y;

    v[0] = 0x1e;
    func_01ff9048(0x14, &v[0], 1);
    p->mUnk_000.mUnk_28.mUnk_00[3].x = p->mUnk_000.mUnk_04.x >> 4;
    p->mUnk_000.mUnk_28.mUnk_00[3].y = p->mUnk_000.mUnk_04.y >> 4;
    p->mUnk_000.mUnk_28.mUnk_00[3].z = p->mUnk_000.mUnk_04.z >> 4;
    func_01ff9048(0x19, &p->mUnk_000.mUnk_28, 0xc);
    if (p->mUnk_11c == 1) {
        x = p->mUnk_0bc;
        y = p->mUnk_0dc;
        v[1] = x;
        v[2] = y;
        v[3] = x;
        func_01ff9048(0x1b, &v[1], 3);
    }
    func_01ff9048(0x1b, &p->mUnk_000.mUnk_1c, 3);
    func_0209b688(gBound, p->mUnk_0a0);
    func_0209bb2c(a, gBound, p);
}

void CreateBound(void *a) {
    gBound = func_0209be84(a, gBoundNsbmdName);
    func_0209bde8(gBound, gBoundNsbtpName);
}

BOOL func_0209c8b0(Unk0209c220 *p, Vec3 *a, s32 b, Vec3 *c) {
    if ((p->mUnk_000.mUnk_02 & 0x800) == 0 && p->mUnk_11c == 1) {
        p->mUnk_0a4 = func_020ead80(a, &p->mUnk_000.mUnk_04, &p->mUnk_000.mUnk_28.mUnk_00[0],
                                    ((s64) p->mUnk_000.mUnk_58.x * p->mUnk_0bc) >> 12, p->mUnk_000.mUnk_58.y, 0, b, c);
    } else {
        p->mUnk_0a4 = func_020ead80(a, &p->mUnk_000.mUnk_04, &p->mUnk_000.mUnk_28.mUnk_00[0], p->mUnk_000.mUnk_58.x,
                                    p->mUnk_000.mUnk_58.y, 0, b, c);
    }
    return p->mUnk_0a4 != 0;
}

u8 func_0209c964(Unk0209c220 *p, void *a, u8 *b, u8 *c) {
    u32 d;

    d = *c;
    if (*b == 2 && p->mUnk_11c == 0) {
        p->mUnk_0b8 = 0x8000;
        p->mUnk_0c4 = 0x1000;
        p->mUnk_0c8 = 0x200;
        p->mUnk_0cc = -0x14;
        p->mUnk_0d0 = 0x1000;
        p->mUnk_0d4 = 0;
        p->mUnk_0d8 = 0;
        p->mUnk_0e4 = 0x1000;
        p->mUnk_0e8 = 0x200;
        p->mUnk_0ec = -0x14;
        p->mUnk_0f0 = 0x1000;
        p->mUnk_0f4 = 0;
        p->mUnk_11c = 1;
        p->mUnk_000.mUnk_78 |= data_usa_021565d0;
    }
    return d;
}

s32 func_0209c9fc(Unk0209c220 *p, Unk0206bcb0 *k, u8 *b, u8 *c) {
    Vec3 v0;
    Vec3 v1;
    Vec3 v2;
    Vec3 v3;
    Vec3 *q;
    u8 d;
    s32 t;
    u32 e;

    e = *b;
    d = *c;
    if (e == 3 || e == 4) {
        if (p->mUnk_120[k->mUnk_74] == 0) {
            func_021484d0(&k->mUnk_80, &p->mUnk_000.mUnk_04, &v2);
            t = func_0214848c(&k->mUnk_b0, &v2);
            v0.x = ((s64) k->mUnk_b0.x * t) >> 12;
            v0.y = ((s64) k->mUnk_b0.y * t) >> 12;
            v0.z = ((s64) k->mUnk_b0.z * t) >> 12;
            v1.x = v2.x - v0.x;
            v1.y = v2.y - v0.y;
            v1.z = v2.z - v0.z;
            t = func_0214848c(&p->mUnk_000.mUnk_28.mUnk_00[1], &v1);
            v0.x = ((s64) p->mUnk_000.mUnk_28.mUnk_00[1].x * t) >> 12;
            v0.y = ((s64) p->mUnk_000.mUnk_28.mUnk_00[1].y * t) >> 12;
            v0.z = ((s64) p->mUnk_000.mUnk_28.mUnk_00[1].z * t) >> 12;
            v1.x -= v0.x;
            v1.y -= v0.y;
            v1.z -= v0.z;
            if ((s64) v1.x * v1.x + (s64) v1.y * v1.y + (s64) v1.z * v1.z < 0x10) {
                q = &k->mUnk_120;
                p->mUnk_000.mUnk_10.x = ((s64) k->mUnk_120.x * 0xc000) >> 12;
                p->mUnk_000.mUnk_10.y = ((s64) q->y * 0xc000) >> 12;
                p->mUnk_000.mUnk_10.z = ((s64) q->z * 0xc000) >> 12;
            } else {
                func_02039860(&v1, &v1);
                p->mUnk_000.mUnk_10.x = ((s64) v1.x * 0xc000) >> 12;
                p->mUnk_000.mUnk_10.y = ((s64) v1.y * 0xc000) >> 12;
                p->mUnk_000.mUnk_10.z = ((s64) v1.z * 0xc000) >> 12;
            }
            func_021484d0(&v0, &p->mUnk_000.mUnk_28.mUnk_00[1], &v0);
            func_02147fd8(0x19a, &v0, &p->mUnk_000.mUnk_10, &p->mUnk_000.mUnk_10);
            p->mUnk_120[k->mUnk_74] = 0x1f;
            if (data_021759c0->mUnk_08 == 2) {
                func_020a21bc(k->mUnk_74, (s32) &p->mUnk_000.mUnk_10);
            }
        } else {
            p->mUnk_000.mUnk_10.x = 0;
            p->mUnk_000.mUnk_10.y = 0;
            p->mUnk_000.mUnk_10.z = 0;
        }
        if (data_021759c0->mUnk_68[k->mUnk_74].mUnk_08.mUnk_00 != 2 && p->mUnk_11c == 0) {
            p->mUnk_0b8 = 0x8000;
            p->mUnk_0c4 = 0x1000;
            p->mUnk_0c8 = 0x400;
            p->mUnk_0cc = -0x29;
            p->mUnk_0d0 = 0x1000;
            p->mUnk_0d4 = 0;
            p->mUnk_0d8 = 0;
            p->mUnk_0e4 = 0x1000;
            p->mUnk_0e8 = 0x400;
            p->mUnk_0ec = -0x29;
            p->mUnk_0f0 = 0x1000;
            p->mUnk_0f4 = 0;
            p->mUnk_11c = 1;
            switch (p->mUnk_000.mUnk_00) {
                case 0x1b4:
                    func_020d26ec(k, 0x156);
                    break;
                case 0x1b5:
                    func_020d26ec(k, 0x155);
                    break;
                case 0x1a8:
                    func_020d26ec(k, 0x1cf);
                    break;
            }
            if ((u16) (p->mUnk_000.mUnk_00 + 0xfe4c) <= 1) {
                func_02103544(k->mUnk_74, (u16) (((u64) func_0209c9fc_inline(&data_0217561c->mUnk_498) * 3) >> 32) + 1);
                func_021484d0(&p->mUnk_000.mUnk_04, &k->mUnk_1b8, &v3);
                if (!((s64) v3.x * v3.x + (s64) v3.y * v3.y + (s64) v3.z * v3.z < 0x10)) {
                    func_02039860(&v3, &v3);
                }
                func_02147fd8(k->mUnk_1d0, &v3, &k->mUnk_1b8, &v3);
                if (k->mUnk_74 == data_021759c0->mUnk_62) {
                    func_0208b7bc(0x74, &v3);
                } else {
                    func_0208b7bc(0x75, &v3);
                }
            }
        }
        return d;
    }
    p->mUnk_000.mUnk_10.x = 0;
    p->mUnk_000.mUnk_10.y = 0;
    p->mUnk_000.mUnk_10.z = 0;
    return 2;
}

void func_0209cebc(Unk0209c220 *p) {
    p->mUnk_000.mUnk_02 |= data_usa_021565d4;
    func_020d2450(p);
    p->mUnk_0b4 = p->mUnk_000.mUnk_1c.x;
}

void func_0209cef0(void) {
    func_0209bf48(func_0209d394, func_0209cf34, NULL);
}

void func_0209cf10(void) {
    func_0209bf1c(CreateSunAndSunLOD, func_0209d3fc, func_0209d5e8);
}

static inline BOOL func_0209cf34_inline(void) {
    s32 i;

    for (i = 0; i < data_021759c0->mKartCount; i++) {
        if ((s32) func_0203c8c0((u16) i) >= 2) {
            return TRUE;
        }
    }
    return FALSE;
}

static inline BOOL func_0209cf34_inline_b(Unk0209cf34 *p) {
    s32 i;
    Unk0206bcb0 *k;
    Vec3 *q;
    s32 x;
    s32 z;

    for (i = 0; i < data_021759c0->mKartCount; i++) {
        k = func_0207a974((u16) i);
        q = &k->mUnk_80;
        x = q->x - p->mUnk_000.mUnk_04.x;
        z = q->z - p->mUnk_000.mUnk_04.z;
        if ((s64) x * x + (s64) z * z < 0x15f900000000LL) {
            return TRUE;
        }
    }
    return FALSE;
}

void func_0209cf34(Unk02100094 *a, Unk0209cf34 *p) {
    Vec3 v;
    Vec3 w;
    s32 t;
    s32 k;

    switch (p->mUnk_0dc) {
        case 0:
            if (p->mUnk_000.mUnk_02 & 0x800) {
                if (p->mUnk_0a8-- <= 0) {
                    p->mUnk_0dc = 1;
                }
            } else if (func_0209cf34_inline()) {
                p->mUnk_0dc = 1;
            }
            break;
        case 1:
            p->mUnk_0b8.mUnk_04 = 0x3c000;
            p->mUnk_0b8.mUnk_10 = ((s64) p->mUnk_0b8.mUnk_00->mUnk_00[p->mUnk_0b8.mUnk_0c].mUnk_34 * 0x3c000) >> 12;
            if (func_020d8cc8(&p->mUnk_0b8) != 0 && (t = p->mUnk_0b8.mUnk_1c->mUnk_0e) != 0) {
                if (p->mUnk_000.mUnk_02 & 0x800) {
                    k = data_021759c0->mUnk_08;
                    if (k == 1) {
                        p->mUnk_0a8 = t;
                    } else if (k == 5) {
                        p->mUnk_0a8 = p->mUnk_0b8.mUnk_1c->mUnk_10;
                    }
                }
                p->mUnk_0dc = 2;
            }
            func_020d8a5c(&p->mUnk_0b8, &p->mUnk_000.mUnk_04);
            break;
        case 2:
            if (p->mUnk_000.mUnk_02 & 0x800) {
                if (p->mUnk_0a8-- <= 0) {
                    p->mUnk_0b0 = 0;
                    p->mUnk_0ac = p->mUnk_0b0;
                    p->mUnk_0a8 = 5;
                    p->mUnk_0dc = 3;
                }
            } else if (func_0209cf34_inline_b(p)) {
                p->mUnk_0b0 = 0;
                p->mUnk_0ac = p->mUnk_0b0;
                p->mUnk_0a8 = 5;
                p->mUnk_0dc = 3;
            }
            break;
        case 3:
            p->mUnk_0b0 += 0xe39;
            if (p->mUnk_0ac < 0x8000) {
                p->mUnk_0ac += 0x222;
            }
            if (p->mUnk_0a8-- > 0) {
                break;
            }
            if (p->mUnk_0a0 == 0) {
                p->mUnk_0a4 = (u16) (((u64) func_0209c9fc_inline(func_020d22d0()) * 0x10000) >> 32);
            } else {
                p->mUnk_0a4 += 0x8000;
            }
            v.x = p->mUnk_000.mUnk_04.x;
            v.y = p->mUnk_000.mUnk_04.y - 0x1e000;
            v.z = p->mUnk_000.mUnk_04.z;
            w.x = data_0215d4b4[(p->mUnk_0a4 >> 4) * 2];
            w.y = 0;
            w.z = data_0215d4b4[(p->mUnk_0a4 >> 4) * 2 + 1];
            func_0209d694(&v, &w);
            p->mUnk_0a0 += 1;
            if (p->mUnk_0a0 >= 2) {
                p->mUnk_0a0 = 0;
                p->mUnk_0dc = 4;
            } else {
                p->mUnk_0a8 = 0x1e;
            }
            break;
        case 4:
            p->mUnk_0b0 += 0xe39;
            p->mUnk_0ac += 0x222;
            if (p->mUnk_0ac > 0x10000) {
                p->mUnk_0a8 = 0x1e;
                p->mUnk_0dc = 0;
            }
            break;
    }
    if ((s32) (p->mUnk_000.mUnk_78 & ~0xc000001f) >= 0x3d0900) {
        return;
    }
    if (p->mUnk_0dc == 3) {
        t = p->mUnk_0b4 + 0x19a;
        if (t >= 0x8000) {
            t = 0x8000;
        }
        p->mUnk_0b4 = t;
    } else {
        t = p->mUnk_0b4 - 0x19a;
        if (t <= 0x1000) {
            t = 0x1000;
        }
        p->mUnk_0b4 = t;
    }
    p->mUnk_0b2 += p->mUnk_0b4 >> 12;
    if (p->mUnk_0b2 >= func_0209b758(gSun)) {
        p->mUnk_0b2 = 0;
    }
}

void func_0209d394(Unk02100094 *a) {
    s32 i;
    Unk0209cf34 *p;

    if (a == NULL) {
        return;
    }
    for (i = 0; i < a->mUnk_04 && (p = a->mUnk_00[i]) != NULL; i++) {
        if (data_021759c0->mUnk_08 == 1) {
            p->mUnk_0a8 = (u16) p->mUnk_000.mUnk_9c->mUnk_28;
        } else if (data_021759c0->mUnk_08 == 5) {
            p->mUnk_0a8 = (u16) p->mUnk_000.mUnk_9c->mUnk_2a;
        }
    }
}
