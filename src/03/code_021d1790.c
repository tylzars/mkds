#include "03/code_021d1770.h"
#include "03/code_021d1790.h"

void func_ov003_021d1790(Unk021d1770 *param_1, s32 param_2, u32 param_3) {
    Unk021d1770_08 *a = param_1->mUnk_08;
    s32 i;

    if (param_2 >= 0) {
        u32 t = a[param_2].mUnk_04;

        a[param_2].mUnk_04 = (t & 0xfffff3ff) | (param_3 << 10);
    } else {
        for (i = 0; i < param_1->mUnk_0c; i++) {
            a->mUnk_04 = (a->mUnk_04 & 0xfffff3ff) | (param_3 << 10);
            a++;
        }
    }
}

static inline void func_ov003_021d17d4_inline(Unk021d1770_08 *p, u32 *x, u32 *y) {
    *x = (p->mUnk_00 & 0x1ff0000) >> 16;
    *y = p->mUnk_00 & 0xff;
}

void func_ov003_021d17d4(Unk021d1770 *param_1, s32 param_2, u32 param_3, u32 param_4) {
    Unk021d1770_08 *a = param_1->mUnk_08;
    s32 i;
    s32 b;
    s32 c;
    s32 d;
    s32 e;
    s32 f;
    s32 g;

    if (param_2 >= 0) {
        u32 t = a[param_2].mUnk_00;

        a[param_2].mUnk_00 = ((param_3 & 0x1ff) << 16) | ((t & 0xfe00ff00) | (param_4 & 0xff));
    } else {
        func_ov003_021d17d4_inline(a, (u32 *) &b, (u32 *) &c);
        a->mUnk_00 = ((param_3 & 0x1ff) << 16) | ((a->mUnk_00 & 0xfe00ff00) | (param_4 & 0xff));
        d = param_3 - b;
        e = param_4 - c;
        for (i = 1; i < param_1->mUnk_0c; i++) {
            func_ov003_021d17d4_inline(&a[i], (u32 *) &f, (u32 *) &g);
            a[i].mUnk_00 = (((f + d) & 0x1ff) << 16) | ((a[i].mUnk_00 & 0xfe00ff00) | ((g + e) & 0xff));
        }
    }
}

void func_ov003_021d1890(Unk021d1770 *param_1, s32 param_2, u32 param_3, u32 param_4) {
    s32 i;
    Unk021d1770_08 *a = param_1->mUnk_08;

    if (param_2 >= 0) {
        u32 t = a[param_2].mUnk_00;
        u32 u;

        a[param_2].mUnk_00 = (t & 0xfffff3ff) | (param_3 << 10);
        u = a[param_2].mUnk_04;
        a[param_2].mUnk_04 = (u & 0xffff0fff) | (param_4 << 12);
    } else {
        for (i = 0; i < param_1->mUnk_0c; i++) {
            a->mUnk_00 = (a->mUnk_00 & 0xfffff3ff) | (param_3 << 10);
            a->mUnk_04 = (a->mUnk_04 & 0xffff0fff) | (param_4 << 12);
            a++;
        }
    }
}

void func_ov003_021d18f0(Unk021d1770 *param_1, s32 param_2, u32 param_3, u32 param_4) {
    Unk021d1770_08 *a = param_1->mUnk_08;
    s32 i;

    if (param_2 >= 0) {
        if (param_3 != 0x100 && param_3 != 0x300) {
            u32 t = a[param_2].mUnk_00;

            a[param_2].mUnk_00 = (t & 0xc1fffcff) | param_3;
        } else {
            u32 t = a[param_2].mUnk_00;

            a[param_2].mUnk_00 = (param_4 << 25) | ((t & 0xc1fffcff) | param_3);
        }
    } else {
        for (i = 0; i < param_1->mUnk_0c; i++) {
            if (param_3 != 0x100 && param_3 != 0x300) {
                a->mUnk_00 = (a->mUnk_00 & 0xc1fffcff) | param_3;
            } else {
                a->mUnk_00 = (param_4 << 25) | ((a->mUnk_00 & 0xc1fffcff) | param_3);
            }
            a++;
        }
    }
}
