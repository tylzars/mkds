#include "Main/Unknown/code_020f9c6c.h"

#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/code_020fe000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_027e0000.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02079b40.h"
#include "Main/Unknown/code_020ec8bc.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f1a24.h"
#include "Main/Unknown/code_020f2dac.h"
#include "Main/Unknown/code_020f5008.h"
#include "Main/Unknown/code_020f5d6c.h"
#include "Main/Unknown/code_020f73a4.h"
#include "Main/Unknown/code_020f7c90.h"
#include "Main/Unknown/code_020f81c0.h"
#include "Main/Unknown/code_020f82c4.h"
#include "Main/Unknown/code_020f9334.h"
#include "Main/Unknown/code_02102674.h"
#include "Main/Unknown/code_021031f4.h"
#include "Main/Unknown/code_02103890.h"
#include "Main/Unknown/code_020f6be8.h"

#pragma thumb off

void *func_020fa3d0(s32 param_1, u16 param_2, void *param_3, void *param_4) {
    Unk020f41c4_A *p;
    Unk027e00cc *e;

    p = 0;
    if (data_027e00cc[param_1].mUnk_20 - data_027e00cc[param_1].mUnk_1c <= 0) {
        return 0;
    }
    func_020f1048(&data_027e00cc[param_1], 1, (Unk020f41c4_A **) &p, param_2, param_3);
    e = &data_027e00cc[param_1];
    e->mUnk_1c++;
    func_020f0ea0(&data_027e00cc[p->mUnk_44], p);
    func_020f98a0(p, param_3, param_4, 0, 0);
    if (param_2 == 8) {
        p->mUnk_78 |= data_02159cbc;
    }
    return p;
}

#pragma thumb on

static inline Unk020f41c4_A *func_020fa3d0_inline(s32 param_1, u16 param_2, void *param_3, void *param_4) {
    Unk020f41c4_A *p;
    Unk027e00cc *e;

    p = 0;
    if (data_027e00cc[param_1].mUnk_20 - data_027e00cc[param_1].mUnk_1c <= 0) {
        return 0;
    }
    func_020f1048(&data_027e00cc[param_1], 1, (Unk020f41c4_A **) &p, param_2, param_3);
    e = &data_027e00cc[param_1];
    e->mUnk_1c++;
    func_020f0ea0(&data_027e00cc[p->mUnk_44], p);
    func_020f98a0(p, param_3, param_4, 0, 0);
    if (param_2 == 8) {
        p->mUnk_78 |= data_02159cbc;
    }
    return p;
}

void func_020fa294(void) {
    u32 i;
    u32 n;
    u32 v;
    Unk020f41c4_A *p;
    Vec3 m;
    enum { K0 } k;
    Unk020fa294 *e;

    n = gCourseMap->mUnk_04;
    for (i = 0; i < n; i++) {
        e = &gCourseMap->mUnk_00[i];
        if (e->mUnk_24 == 0x6d) {
            k = e->mUnk_28;
            if (func_01ffdee4((int *) e, (u32 *) 0, 0, 0xa000, 8, -2, (int *) 0, (int *) &m, (int *) 0, (u32 *) 0,
                              (u32 *) 0, (int *) 0, (u16 *) 0, &v) == 0) {
                m = data_02159cb0;
            }
            p = func_020fa3d0_inline(k, 8, e, &m);
            if (p != 0) {
                void (*t)(Unk020f41c4_A *);

                k = p->mUnk_44;
                t = data_0217bc34[k].mUnk_28;
                if ((p->mUnk_74 & 0x180000) == 0) {
                    p->mUnk_120 = t;
                }
                func_020f6a6c(p, &v);
            }
        }
    }
}

void func_020fa13c(void) {
    void *b;
    s32 a;
    s32 i;
    enum { K0 } j;
    Unk020f40dc *p;
    u8 v;

    b = func_020364e0(func_020364e8());
    a = 0;
    func_020f7ec8();
    func_020f82e8(1);
    func_020f82c4(1);
    func_020f82a4(1);
    func_020f4b8c();
    func_020f1a24();
    func_020f73a4();
    func_020f357c();
    v = data_021759c0->mUnk_3d0;
    data_027e00c4 = v;
    (void *) data_027e00c8 = func_02036bec(b, v * 0x210);
    for (i = 0; i < data_027e00c4; i++) {
        func_020efbd4(&(data_027e00c8)[i], (u16) i);
    }
    data_027e00cc = func_02036bec(b, 0x3b8);
    for (j = 0; j < 0xe; j++) {
        func_020f02c0(&data_027e00cc[j], j, &a);
    }
    func_020ed2f8();
    if (data_021759c0->mUnk_08 == 5) {
        func_020fe46c();
        func_020fe450();
    }
    if (data_021759c0->mUnk_08 == 1) {
        for (i = 0; i < data_027e00c4; i++) {
            p = &(data_027e00c8)[i].mUnk_030;
            func_020f47e4(p, 5);
            switch (func_02079b40((u16) i)) {
                case 0:
                    func_020f4754(p, 1);
                    break;
                case 1:
                    func_020f4754(p, 2);
                    break;
            }
        }
    }
    data_0217bd30 = func_02036bec(func_020364e0(func_020364e8()), 0x40);
    func_020fa294();
    func_02102674();
    func_02103468();
    func_02104970();
}

s32 func_020fa0e8(s32 param_1, s32 param_2) {
    switch (param_2) {
        case 0:
            return (u8) ((u8) data_0217bc34[param_1].mUnk_4c + 1);
        case 1:
            return 0x12;
        case 2:
            return 3;
        case 3:
            return (u8) ((param_1 == 0xb ? 3 : 2) + 1);
    }
    return 0;
}

#pragma thumb off

s32 func_020fa0b8(void *param_1, s32 param_2, s32 param_3) {
    Unk020f41c4_A *p = param_1;

    if (p->mUnk_68.z < param_2) {
        p->mUnk_68.z += param_3;
        if (p->mUnk_68.z > param_2) {
            p->mUnk_68.z = param_2;
        }
        return 1;
    }
    return 0;
}

void func_020fa030(Unk020f41c4_A *param_1) {
    Unk0217bc34 *e;
    enum { K0 } k;
    s32 m;

    k = param_1->mUnk_44;
    param_1->mUnk_74 |= 0x40;
    param_1->mUnk_68.y = param_1->mUnk_68.z;
    param_1->mUnk_68.x = param_1->mUnk_68.y;
    e = &data_0217bc34[k];
    m = e->mUnk_6c;
    param_1->mUnk_dc = (s32) (((s64) param_1->mUnk_68.y * e->mUnk_64) >> 12);
    param_1->mUnk_e0 = (s32) (((s64) param_1->mUnk_68.y * m) >> 12);
    func_020d5148(param_1->mUnk_da, param_1->mUnk_e0 + 0xa000);
}

void func_020f9fa8(Unk020f41c4_A *param_1) {
    Unk0217bc34 *e;
    enum { K0 } k;
    s32 m;

    k = param_1->mUnk_44;
    param_1->mUnk_74 |= 0x40;
    param_1->mUnk_68.y = param_1->mUnk_68.z;
    param_1->mUnk_68.x = param_1->mUnk_68.y;
    e = &data_0217bc34[k];
    m = e->mUnk_6c;
    param_1->mUnk_dc = (s32) (((s64) param_1->mUnk_68.y * e->mUnk_64) >> 12);
    param_1->mUnk_e0 = (s32) (((s64) param_1->mUnk_68.y * m) >> 12);
    func_020d5148(param_1->mUnk_da, param_1->mUnk_e0);
}

void func_020f9f08(void *param_1, s32 param_2, s32 param_3) {
    Unk020f41c4_A *p = param_1;
    enum { K0 } k;
    s32 m;

    k = p->mUnk_44;
    m = data_0217bc34[k].mUnk_68;
    p->mUnk_68.x = (s32) (((s64) p->mUnk_68.z * param_2) >> 12);
    p->mUnk_68.y = (s32) (((s64) p->mUnk_68.z * param_3) >> 12);
    p->mUnk_dc = (s32) (((s64) p->mUnk_68.y * data_0217bc34[k].mUnk_64) >> 12);
    p->mUnk_e0 = (s32) (((s64) p->mUnk_68.y * m) >> 12);
    func_020d5148(p->mUnk_da, p->mUnk_e0 + 0xa000);
}

s32 func_020f9dc8(Unk020f41c4_A *param_1) {
    Unk0217bc34 *e;
    enum { K0 } k;
    s32 m;

    if (param_1->mUnk_100 <= -0x29 || param_1->mUnk_100 >= 0x29 || param_1->mUnk_68.x - param_1->mUnk_68.y <= -0x29 ||
        param_1->mUnk_68.x - param_1->mUnk_68.y >= 0x29) {
        k = param_1->mUnk_44;
        param_1->mUnk_74 |= 0x40;
        param_1->mUnk_68.y += param_1->mUnk_100;
        param_1->mUnk_100 += (s32) (((s64) (param_1->mUnk_68.z - param_1->mUnk_68.y) * 0x333) >> 12);
        param_1->mUnk_100 = (s32) (((s64) param_1->mUnk_100 * 0xc00) >> 12);
        param_1->mUnk_68.x = param_1->mUnk_68.z * 2 - param_1->mUnk_68.y;
        e = &data_0217bc34[k];
        m = e->mUnk_6c;
        param_1->mUnk_dc = (s32) (((s64) param_1->mUnk_68.y * e->mUnk_64) >> 12);
        param_1->mUnk_e0 = (s32) (((s64) param_1->mUnk_68.y * m) >> 12);
        func_020d5148(param_1->mUnk_da, param_1->mUnk_e0 + 0xa000);
        return 1;
    }
    param_1->mUnk_100 = 0;
    return 0;
}

s32 func_020f9ce8(Unk020f41c4_A *param_1) {
    Unk0217bc34 *e;
    enum { K0 } k;
    s32 m;

    if (param_1->mUnk_100 != 0) {
        k = param_1->mUnk_44;
        param_1->mUnk_74 |= 0x40;
        param_1->mUnk_68.y += (s32) (((s64) (param_1->mUnk_100 - param_1->mUnk_68.y) * 0x333) >> 12);
        param_1->mUnk_68.x = param_1->mUnk_68.z * 2 - param_1->mUnk_68.y;
        e = &data_0217bc34[k];
        m = e->mUnk_6c;
        param_1->mUnk_dc = (s32) (((s64) param_1->mUnk_68.y * e->mUnk_64) >> 12);
        param_1->mUnk_e0 = (s32) (((s64) param_1->mUnk_68.y * m) >> 12);
        func_020d5148(param_1->mUnk_da, param_1->mUnk_e0 + 0xa000);
        return 1;
    }
    return 0;
}

void func_020f9ca8(void *param_1) {
    Unk020f41c4_A *p = param_1;

    if (p->mUnk_da != -1) {
        return;
    }
    p->mUnk_da = func_020d555c(&p->mUnk_50, p->mUnk_e0 + 0xa000, 0x4000, p);
}

void func_020f9c6c(Unk020f41c4_A *param_1) {
    if (param_1->mUnk_da != -1) {
        return;
    }
    param_1->mUnk_da = func_020d555c(&param_1->mUnk_50, param_1->mUnk_e0, 0x4000, param_1);
}

#pragma thumb on
