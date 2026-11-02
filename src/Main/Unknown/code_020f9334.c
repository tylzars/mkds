#include "Main/Unknown/code_020f9334.h"

#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020d6000.h"
#include "Main/Unknown/code_020ff000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_0208a000.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/code_020f504c.h"
#include "Main/Unknown/code_020f5d6c.h"
#include "Main/Unknown/code_020f6be8.h"
#include "Main/Unknown/code_020f73fc.h"
#include "Main/Unknown/code_020f7c90.h"
#include "Main/Unknown/code_02109000.h"
#include "code_02147cd8.h"

BOOL func_020f9c08(Unk020f41c4_A *param_1) {
    if (param_1->mUnk_11c > 0x12c && (param_1->mUnk_74 & 0x8000) != 0 &&
        param_1->mUnk_120 == (void (*)(Unk020f41c4_A *)) func_020f68b0) {
        return TRUE;
    }
    return FALSE;
}

void func_020f9ba8(Unk020f41c4_A *param_1) {
    if (param_1->mUnk_11c <= 0x12c) {
        return;
    }
    if ((param_1->mUnk_74 & 0x8000) == 0) {
        return;
    }
    if (param_1->mUnk_120 != (void (*)(Unk020f41c4_A *)) func_020f68b0) {
        return;
    }
    func_020f7658(param_1, 1);
}

void func_020f9b0c(Unk020f41c4_A *param_1) {
    if ((param_1->mUnk_74 & 0x8000) != 0) {
        func_020f7658(param_1, 1);
        return;
    }
    param_1->mUnk_5c.x = (s32) (((s64) param_1->mUnk_5c.x * 0x99a) >> 12);
    param_1->mUnk_5c.y = (s32) (((s64) param_1->mUnk_5c.y * 0x99a) >> 12);
    param_1->mUnk_5c.z = (s32) (((s64) param_1->mUnk_5c.z * 0x99a) >> 12);
    func_020f6fc4(param_1, 1);
}

void func_020f9a14(Unk020f41c4_A *param_1, s32 param_2) {
    void (*f)(void *);

    f = data_0217bc34[param_2].mUnk_18;
    param_1->mUnk_44 = param_2;
    param_1->mUnk_74 = 0;
    param_1->mUnk_7a = 0;
    param_1->mUnk_68.x = 0;
    param_1->mUnk_68.y = 0;
    param_1->mUnk_68.z = 0;
    param_1->mUnk_100 = 0;
    param_1->mUnk_dc = 0x7b;
    param_1->mUnk_e0 = 0x7b;
    param_1->mUnk_d8 = 0x1f;
    param_1->mUnk_fc = 0;
    param_1->mUnk_118 = 0;
    param_1->mUnk_114 = 5;
    param_1->mUnk_124 = NULL;
    param_1->mUnk_d0 = &param_1->mUnk_50;
    param_1->mUnk_da = -1;
    param_1->mUnk_104->mUnk_00 = NULL;
    if (data_021759c0->mUnk_08 == 5) {
        param_1->mUnk_74 |= 0x8000000;
    }
    param_1->mUnk_78 |= data_02159cac;
    func_0208adc8(param_1->mUnk_7c.mUnk_00, 1);
    param_1->mUnk_90 = NULL;
    if (f != NULL) {
        f(param_1);
    }
    param_1->mUnk_128 = 0;
}

void func_020f99b8(Unk020f41c4_A *param_1, s32 param_2, u16 param_3, Vec3 *param_4) {
    param_1->mUnk_50 = *param_4;
    param_1->mUnk_78 = param_3;
    func_020f9a14(param_1, param_2);
    if ((param_1->mUnk_74 & 0x8000000) == 0) {
        return;
    }
    param_1->mUnk_4e = func_020ff178(param_1);
}

void func_020f992c(Unk020f41c4_A *param_1) {
    enum { K0 } k;

    if (param_1->mUnk_da != -1) {
        param_1->mUnk_da = func_020d5344(param_1->mUnk_da);
    }
    if ((param_1->mUnk_74 & 0x400000) != 0) {
        func_02109054(&param_1->mUnk_00);
        param_1->mUnk_00.mUnk_30 = NULL;
        param_1->mUnk_74 &= ~0x400000;
    }
    param_1->mUnk_74 |= 4;
    k = param_1->mUnk_44;
    if (data_0217bc34[k].mUnk_3c != NULL) {
        data_0217bc34[k].mUnk_3c(param_1);
    }
}

void func_020f98a0(void *param_1, Vec3 *param_2, Vec3 *param_3, u16 *param_4, s32 param_5) {
    Unk020f41c4_A *a = param_1;
    a->mUnk_0e4 = *param_2;
    if (param_4 != NULL) {
        a->mUnk_7c = *(Unk020f41c4_C *) param_4;
    } else {
        func_0208adc8(a->mUnk_7c.mUnk_00, 1);
    }
    a->mUnk_f0 = *param_3;
    a->mUnk_116 = param_5 != 0 ? 0 : 5;
}

s32 func_020f9880(Unk020f41c4_A *param_1) {
    return data_0217bc34[param_1->mUnk_44].mUnk_84;
}

BOOL func_020f97e0(Unk020f41c4_A *param_1, Unk0206bcb0 *param_2) {
    Vec3 d;
    s32 n;

    if (param_1->mUnk_da == -1 ||
        param_2->mUnk_74 == (u16) ((param_1->mUnk_78 & 0x4000) != 0 ? (u16) (param_1->mUnk_78 & ~0xff00) : 8)) {
        return FALSE;
    }
    n = param_2->mUnk_1d0 + param_1->mUnk_e0;
    d.x = param_1->mUnk_50.x - param_2->mUnk_1d8.x;
    d.y = param_1->mUnk_50.y - param_2->mUnk_1d8.y;
    d.z = param_1->mUnk_50.z - param_2->mUnk_1d8.z;
    return (s64) d.x * d.x + (s64) d.y * d.y + (s64) d.z * d.z < (s64) n * n;
}

BOOL func_020f9780(Unk020f41c4_A *param_1, Vec3 *param_2, s32 param_3) {
    Vec3 d;
    s32 n;

    n = param_3 + param_1->mUnk_e0;
    d.x = param_1->mUnk_50.x - param_2->x;
    d.y = param_1->mUnk_50.y - param_2->y;
    d.z = param_1->mUnk_50.z - param_2->z;
    return (s64) d.x * d.x + (s64) d.y * d.y + (s64) d.z * d.z < (s64) n * n;
}

void func_020f95d4(Unk020f41c4_A *param_1, Unk020f41c4_A *param_2) {
    Vec3 v;
    s32 a;
    s32 b;

    if (param_2->mUnk_da == -1) {
        return;
    }
    if ((param_2->mUnk_74 & 0x1000) != 0) {
        return;
    }
    if ((param_2->mUnk_74 & 0x8000) == 0) {
        if (param_1->mUnk_48 > param_2->mUnk_48) {
            return;
        }
    }
    if ((param_1->mUnk_74 & 0x10000000) != 0 && (param_2->mUnk_74 & 0x10000000) != 0) {
        if (func_020f7ea8(param_1, param_2) != 1 && func_020f7ea8(param_2, param_1) != 1) {
            return;
        }
    }
    if (func_020f9780(param_1, &param_2->mUnk_50, param_2->mUnk_e0) == FALSE) {
        if (func_020f9780(param_1, &param_2->mUnk_0e4, param_2->mUnk_e0) == FALSE) {
            return;
        }
        if (func_020f9780(param_2, &param_1->mUnk_0e4, param_1->mUnk_e0) == FALSE) {
            return;
        }
    }
    v = param_1->mUnk_5c;
    a = func_020f7ea8(param_1, param_2);
    b = func_020f7ea8(param_2, param_1);
    func_020f77f8(param_1, a, &param_2->mUnk_50, &param_2->mUnk_5c, NULL);
    func_020f77f8(param_2, b, &param_1->mUnk_50, &v, NULL);
    if (param_1->mUnk_44 == 1) {
        func_020f5614(param_1, a, param_2);
    }
    if (param_2->mUnk_44 != 1) {
        return;
    }
    func_020f5614(param_2, b, param_1);
}

void func_020f944c(void *param_1, void *param_2) {
    Vec3 a;
    Vec3 t;
    s32 b;
    Unk020e71a0 *q;
    Unk020f41c4_A *p = param_1;
    Unk020e71a0 *r = param_2;

    if (func_020d3e34(&p->mUnk_50, p->mUnk_e0, r, &a) == 0) {
        return;
    }
    if ((r->mUnk_02 & 0x40) == 0 && (p->mUnk_74 & 0x80000) == 0 && func_020d6968(p->mUnk_44, r) != 0) {
        func_02148504(&p->mUnk_50, &a, &p->mUnk_50);
    }
    switch (func_020d6a54(p, r, &b)) {
        case 1:
            t.x = r->mUnk_04.x;
            t.y = p->mUnk_50.y;
            t.z = r->mUnk_04.z;
            a = t;
            if (b == 1 || (r->mUnk_78 & 0x80000000) != 0) {
                r->mUnk_78 &= ~0x80000000;
                q = r;
            } else {
                r->mUnk_78 &= ~0x80000000;
                q = NULL;
            }
            func_020f77f8(p, 1, &a, &r->mUnk_10, q);
            p->mUnk_78 &= ~0x4000;
            return;
        case 2:
            if (b == 1 || (r->mUnk_78 & 0x80000000) != 0) {
                r->mUnk_78 &= ~0x80000000;
                q = r;
            } else {
                r->mUnk_78 &= ~0x80000000;
                q = NULL;
            }
            func_020f77f8(p, 2, &r->mUnk_04, &r->mUnk_10, q);
            return;
    }
}

void func_020f9334(void *param_1, Vec3 *param_2, Vec3 *param_3, s32 param_4, Vec3 *param_5) {
    Unk020f41c4_A *p = param_1;
    Vec3 v;
    u32 a;
    s32 x;
    s32 y;
    s32 z;

    a = 0;
    z = param_2->z;
    y = param_2->y - p->mUnk_dc;
    x = param_2->x;
    v.x = x;
    v.y = y;
    v.z = z;

    func_01ffdee4(&v, (u32 *) param_2, 0, p->mUnk_dc >> 1, 0x24, p->mUnk_da, NULL, NULL, NULL, &a, NULL, NULL, NULL, NULL);
    if ((a & 0x1e34ef) != 0 || (p->mUnk_fc & 0x80000) != 0) {
        if ((p->mUnk_74 & 0x4000000) != 0) {
            return;
        }
        p->mUnk_74 |= 8;
        p->mUnk_f0 = *param_5;
        return;
    }
    param_3->z = 0;
    param_3->x = param_3->z;
    if (param_3->y > 0) {
        param_3->y = 0;
        return;
    }
    if (param_3->y > -param_4) {
        param_3->y = -param_4;
    }
}
