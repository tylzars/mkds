#include "03/code_021c04ec.h"

#include "03/code_021c0000.h"
#include "03/unk_021da000.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d2940.h"
#include "03/code_021d250c.h"
#include "03/unk_021d5f00.h"
#include "03/unk_021d6000.h"
#include "03/code_021bf8c0.h"
#include "03/code_021d1770.h"
#include "03/code_021d3488.h"
#include "03/code_021bf000.h"
#include "03/code_021d1790.h"
#include "03/code_021d197c.h"
#include "03/code_021d1fd0.h"
#include "03/code_021d1000.h"
#include "03/code_021d27d8.h"
#include "03/code_021d1c18.h"
#include "03/unk_021d5000.h"

void func_ov003_021c0d2c(void) {
    u16 v[4] = {0};
    u32 w;
    u16 x[2];
    Unk021da15c *p;
    int i;
    int j;
    int k;
    int l;

    v[2] = data_ov003_021d5f7c[0][0];
    v[3] = data_ov003_021d5f7c[0][1];
    p = func_ov003_021d283c(0x128, 4);
    data_ov003_021da15c = p;
    p->mUnk_11c = 0xff;
    data_ov003_021da15c->mUnk_121 = 0;
    data_ov003_021da15c->mUnk_123 = 1;
    data_ov003_021da15c->mUnk_124 = 1;
    for (i = 0; i < 0x2f; i++) {
        data_ov003_021da15c->mUnk_030[i] = func_ov003_021d1c18(0, 0x34);
        data_ov003_021da15c->mUnk_030[i]->mUnk_00 = (data_ov003_021da15c->mUnk_030[i]->mUnk_00 & 0xc1fffcff) | 0x200;
        data_ov003_021da15c->mUnk_030[i]->mUnk_04 = (data_ov003_021da15c->mUnk_030[i]->mUnk_04 & 0xfffff3ff) | 0xc00;
    }
    for (i = 0; i < 4; i++) {
        data_ov003_021da15c->mUnk_0ec[i] = func_ov003_021d1c18(0, data_ov003_021d5f70[i]);
        data_ov003_021da15c->mUnk_0ec[i]->mUnk_00 = (data_ov003_021da15c->mUnk_0ec[i]->mUnk_00 & 0xc1fffcff) | 0x200;
        data_ov003_021da15c->mUnk_0ec[i]->mUnk_04 = (data_ov003_021da15c->mUnk_0ec[i]->mUnk_04 & 0xfffff3ff) | 0xc00;
    }
    for (i = 0; i < 2; i++) {
        data_ov003_021da15c->mUnk_0fc[i] = func_ov003_021d1be4(0, data_ov003_021d5f68[i], 1);
        func_ov003_021d18f0(data_ov003_021da15c->mUnk_0fc[i], -1, 0x200, 0);
        func_ov003_021d1790(data_ov003_021da15c->mUnk_0fc[i], -1, 3);
    }
    x[1] = 0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            data_ov003_021da15c->mUnk_000[i][j] =
                func_ov003_021d23b0(0, data_ov003_021d5f74[0], data_ov003_021d5f74[1], 0, &w, 0);
            l = j * 12;
            for (k = 0, v[0] = 0; k < 12; k++, l++, v[0] += 0x12) {
                x[0] = data_ov003_021d6be8[i][l];
                func_ov003_021d2070(data_ov003_021da15c->mUnk_000[i][j], v[0], v[1], v[2], v[3], 2, 0x480, x);
            }
            if (i == 0) {
                data_ov003_021da15c->mUnk_104[j] = func_ov003_021d19e0(0, w, 1);
            }
        }
    }
    data_ov003_021da15c->mUnk_114 = func_ov003_021d1be4(0, 0x40, 1);
    func_ov003_021d18f0(data_ov003_021da15c->mUnk_114, -1, 0x200, 0);
    func_ov003_021d1790(data_ov003_021da15c->mUnk_114, -1, 2);
    data_ov003_021da15c->mUnk_118 = (void *) func_ov003_021d3544(0, func_ov003_021c0c2c, NULL, 0x78);
    func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 0, 0xc0);
}

void func_ov003_021c0cf8(void) {
    func_ov003_021d197c(data_ov003_021da15c->mUnk_114);
    func_ov003_021d34e0(data_ov003_021da15c->mUnk_118, func_ov003_021bfc80);
}

u8 func_ov003_021c0ce4(void) {
    return data_ov003_021da15c->mUnk_11c;
}

void func_ov003_021c0cd0(u8 a) {
    data_ov003_021da15c->mUnk_123 = a;
}

void func_ov003_021c0cbc(u8 a) {
    data_ov003_021da15c->mUnk_124 = a;
}

u32 func_ov003_021c0ca8(void) {
    if (data_ov003_021da15c != NULL) {
        return 1;
    }
    return 0;
}

static inline void func_ov003_021c0ab0_inline(Unk021bf920 *p, u32 *x, u32 *y) {
    *x = (p->mUnk_00 & 0x1ff0000) >> 16;
    *y = p->mUnk_00 & 0xff;
}

void func_ov003_021c0c2c(Unk021d34e0 *param_1) {
    s32 a;
    s32 y;
    func_ov003_021c0ab0_inline(data_ov003_021da15c->mUnk_030[0], (u32 *) &a, (u32 *) &y);
    y -= 12;
    if (y > data_ov003_021d5fb0[0][1]) {
        func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 0, y);
        return;
    }
    func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 0, data_ov003_021d5fb0[0][1]);
    func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 1, 0xc0);
    func_ov003_021d34e0(param_1, func_ov003_021c0bb0);
}

void func_ov003_021c0bb0(Unk021d34e0 *param_1) {
    s32 a;
    s32 y;
    func_ov003_021c0ab0_inline(data_ov003_021da15c->mUnk_030[12], (u32 *) &a, (u32 *) &y);
    y -= 12;
    if (y > data_ov003_021d5fb0[12][1]) {
        func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 1, y);
        return;
    }
    func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 1, data_ov003_021d5fb0[12][1]);
    func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 2, 0xc0);
    func_ov003_021d34e0(param_1, func_ov003_021c0b30);
}

void func_ov003_021c0b30(Unk021d34e0 *param_1) {
    s32 a;
    s32 y;
    func_ov003_021c0ab0_inline(data_ov003_021da15c->mUnk_030[24], (u32 *) &a, (u32 *) &y);
    y -= 12;
    if (y > data_ov003_021d5ff0[8][1]) {
        func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 2, y);
        return;
    }
    func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 2, data_ov003_021d5ff0[8][1]);
    func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 3, 0xc0);
    func_ov003_021d34e0(param_1, func_ov003_021c0ab0);
}

void func_ov003_021c0ab0(Unk021d34e0 *param_1) {
    s32 a;
    s32 b;
    func_ov003_021c0ab0_inline(data_ov003_021da15c->mUnk_030[36], (u32 *) &a, (u32 *) &b);
    b -= 12;
    if (b > data_ov003_021d6030[4][1]) {
        func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 3, b);
        return;
    }
    func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 3, data_ov003_021d6030[4][1]);
    func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 4, 0xc0);
    func_ov003_021d34e0(param_1, func_ov003_021c0a40);
}

void func_ov003_021c0a40(Unk021d34e0 *param_1) {
    u32 x;
    s32 y;
    func_ov003_021d1770(data_ov003_021da15c->mUnk_0fc[0], 0, &x, &y);
    y -= 12;
    if (y > data_ov003_021d5f88[0][1]) {
        func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 4, y);
        return;
    }
    func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 4, data_ov003_021d5f88[0][1]);
    func_ov003_021bffb0();
    func_ov003_021d34e0(param_1, func_ov003_021c0a24);
}

void func_ov003_021c0a24(void) {
    func_ov003_021c08d0();
    func_ov003_021c06e0();
    func_ov003_021c0528();
    func_ov003_021c0318();
    return;
}

void func_ov003_021c08d0(void) {
    Unk021d299c a;
    s32 i;
    s32 j;
    if (func_ov003_021d2a34(&data_ov003_021d67e8) == 0) {
        return;
    }
    i = 0;
    data_ov003_021da15c->mUnk_11e = -1;
    for (; i < 0x2f; i++) {
        func_ov003_021d250c(data_ov003_021d5fb0[i], data_ov003_021d5f7c[0], &a);
        if (func_ov003_021d2a34(&a) != 0) {
            if (data_ov003_021da15c->mUnk_124 == 0) {
                func_ov003_021cdc10(9);
                return;
            }
            func_ov003_021cdc10(0);
            data_ov003_021da15c->mUnk_11e = i;
            return;
        }
    }
    for (j = 0; j < 4; j++) {
        func_ov003_021d250c(data_ov003_021d5f90[j], data_ov003_021d5fa0[j], &a);
        if (func_ov003_021d2a34(&a) != 0) {
            if ((j == 3 && data_ov003_021da15c->mUnk_123 == 0) || (j == 2 && data_ov003_021da15c->mUnk_124 == 0)) {
                func_ov003_021cdc10(9);
                return;
            }
            func_ov003_021cdc10(data_ov003_021d6bf4[j]);
            data_ov003_021da15c->mUnk_11e = j + 0x2f;
            return;
        }
    }
    for (i = 0; i < 2; i++) {
        func_ov003_021d250c(data_ov003_021d5f88[i], data_ov003_021d5f78[0], &a);
        if (func_ov003_021d2a34(&a) != 0) {
            func_ov003_021cdc10(0);
            data_ov003_021da15c->mUnk_11e = i + 0x33;
            return;
        }
    }
}

void func_ov003_021c06e0(void) {
    Unk021d299c a;
    s32 i;
    u16(*q)[2];
    u16(*p)[2];
    s32 j;
    data_ov003_021da15c->mUnk_11c = 0;
    if (func_ov003_021d299c(&data_ov003_021d67e8) == 0) {
        return;
    }
    for (i = 0; i < 0x2f; i++) {
        func_ov003_021d250c(data_ov003_021d5fb0[i], data_ov003_021d5f7c[0], &a);
        if (func_ov003_021d299c(&a) != 0) {
            if (data_ov003_021da15c->mUnk_11e != i) {
                return;
            }
            data_ov003_021da15c->mUnk_11c = data_ov003_021d6bdc[data_ov003_021da15c->mUnk_11d][i];
            if (data_ov003_021da15c->mUnk_11d == 1) {
                func_ov003_021c00ec(0);
            }
            data_ov003_021da15c->mUnk_121 = i;
            func_ov003_021bffb0();
            return;
        }
    }
    j = 2;
    q = data_ov003_021d5fa8;
    p = data_ov003_021d5f98;
    for (; j < 4; q++, p++, j++) {
        func_ov003_021d250c(*p, *q, &a);
        if (func_ov003_021d299c(&a) != 0) {
            if (data_ov003_021da15c->mUnk_11e != j + 0x2f) {
                return;
            }
            data_ov003_021da15c->mUnk_11c = data_ov003_021d5f80[j];
            if (data_ov003_021da15c->mUnk_11d == 1) {
                func_ov003_021c00ec(0);
            }
            data_ov003_021da15c->mUnk_121 = j + 0x2f;
            func_ov003_021bffb0();
            return;
        }
    }
    for (i = 0; i < 2; i++) {
        func_ov003_021d250c(data_ov003_021d5f88[i], data_ov003_021d5f78[0], &a);
        if (func_ov003_021d299c(&a) != 0) {
            if (data_ov003_021da15c->mUnk_11e != i + 0x33) {
                return;
            }
            data_ov003_021da15c->mUnk_11c = data_ov003_021d5f6c[i];
            data_ov003_021da15c->mUnk_121 = i + 0x33;
            func_ov003_021bffb0();
            return;
        }
    }
    func_ov003_021d250c(data_ov003_021d5f90[0], data_ov003_021d5fa0[0], &a);
    if (func_ov003_021d299c(&a) != 0) {
        if (data_ov003_021da15c->mUnk_11e != 0x2f) {
            return;
        }
        func_ov003_021c06b0();
        data_ov003_021da15c->mUnk_121 = 0x2f;
        func_ov003_021bffb0();
        return;
    }
    func_ov003_021d250c(data_ov003_021d5f94[0], data_ov003_021d5fa4[0], &a);
    if (func_ov003_021d299c(&a) != 0) {
        if (data_ov003_021da15c->mUnk_11e != 0x30) {
            return;
        }
        func_ov003_021c0680();
        data_ov003_021da15c->mUnk_121 = 0x30;
        func_ov003_021bffb0();
    }
}

void func_ov003_021c06b0(void) {
    u32 v1;
    if (data_ov003_021da15c->mUnk_11d == 2) {
        v1 = 0;
    } else {
        v1 = 2;
    }
    func_ov003_021c00ec(v1);
    func_ov003_021cdc10((u32) 1);
}

void func_ov003_021c0680(void) {
    func_ov003_021c00ec((data_ov003_021da15c->mUnk_11d != 1));
    func_ov003_021cdc10((u32) 1);
}

void func_ov003_021c0528(void) {
    Unk021d299c a;
    s32 i;
    s32 j;

    if (func_ov003_021d2a80(&data_ov003_021d67e8) == 0) {
        goto fail;
    }
    for (i = 0; i < 0x2f; i++) {
        func_ov003_021d250c(data_ov003_021d5fb0[i], data_ov003_021d5f7c[0], &a);
        if (func_ov003_021d2a80(&a) != 0) {
            if (data_ov003_021da15c->mUnk_11e != i) {
                goto fail;
            }
            func_ov003_021c04ec(i);
            goto done;
        }
    }
    for (j = 2; j < 4; j++) {
        func_ov003_021d250c(data_ov003_021d5f90[j], data_ov003_021d5fa0[j], &a);
        if (func_ov003_021d2a80(&a) != 0) {
            if (data_ov003_021da15c->mUnk_11e != j + 0x2f) {
                goto fail;
            }
            func_ov003_021c04ec(j + 0x2f);
            if (j == 3) {
                data_ov003_021da15c->mUnk_122++;
                if (data_ov003_021da15c->mUnk_122 >= 0x28) {
                    if (data_ov003_021da15c->mUnk_123 == 0) {
                        func_ov003_021cdc10(9);
                        data_ov003_021da15c->mUnk_11e = -1;
                        return;
                    }
                    data_ov003_021da15c->mUnk_11c = 0x80;
                    data_ov003_021da15c->mUnk_122 -= 7;
                    return;
                }
            }
            return;
        }
    }
    for (i = 0; i < 2; i++) {
        func_ov003_021d250c(data_ov003_021d5f88[i], data_ov003_021d5f78[0], &a);
        if (func_ov003_021d2a80(&a) != 0) {
            if (data_ov003_021da15c->mUnk_11e != i + 0x33) {
                goto fail;
            }
            func_ov003_021c04ec(i + 0x33);
            goto done;
        }
    }
fail:
    func_ov003_021c04ec(-1);
done:
    data_ov003_021da15c->mUnk_122 = 0;
}

void func_ov003_021c04ec(int a) {
    if (a != data_ov003_021da15c->mUnk_11f) {
        func_ov003_021c0050(a, 1);
        func_ov003_021c0050(data_ov003_021da15c->mUnk_11f, 0);
        data_ov003_021da15c->mUnk_11f = (s8) a;
    }
}
