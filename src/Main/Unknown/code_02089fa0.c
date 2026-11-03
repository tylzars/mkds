#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02089fa0.h"
#include "ITCM/code_01ff8000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061f7c.h"
#include "Main/Unknown/code_02087d0c.h"
#include "Main/Unknown/code_020846c0.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_02089d70.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_02170000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02010c84.h"
#include "code_02010fac.h"
#include "code_02013740.h"
#include "code_02135014.h"
#include "code_02146cbc.h"
#include "code_0214a4dc.h"
#include "code_0214a748.h"
#include "registers.h"

void func_0208aa30(void *a) {
    Unk0217b034_784 *p;

    data_0217b034 = func_02036bec(a, 0x79c);
    func_0208a460(a);
    data_0217b034->mUnk_73c = 9;
    reg_G3_MTX_MODE = 0;
    func_0214ad4c(0x60000, -0x60000, -0x80000, 0x80000, 0, 0x1000, 0x200, 1, &data_0217b034->mUnk_744);
    p = &data_0217b034->mUnk_784;
    data_0217b034->mUnk_784.mUnk_00 = 0;
    p->mUnk_02 = 0;
    p->mUnk_04 = 0x7fff;
    p->mUnk_08 = 0;
}

void func_0208a69c(void *a, Unk0208a69c *b, const Unk02155ee8 *c, u16 d) {
    char s[0x80];
    void *n;
    u16 i;
    Unk02084b2c *h;
    Unk02084b2c *e;
    Unk02087d0c *g;
    u16 j;
    Unk02084b2c *p;
    Unk02087d0c *q;
    u16 l;
    u16 k;
    BOOL f;

    n = NULL;
    b->mUnk_10 = c->mUnk_00;
    b->mUnk_00 = NULL;
    b->mUnk_04[0] = b->mUnk_04[1] = b->mUnk_04[2] = NULL;
    f = FALSE;
    if (c->mUnk_00 != 0) {
        b->mUnk_00 = func_02036bec(a, c->mUnk_00 * 0x6c);
    }
    if (c->mUnk_01 != 0) {
        b->mUnk_04[0] = func_02036bec(a, c->mUnk_01 * 0x38);
    }
    if (c->mUnk_02 != 0) {
        b->mUnk_04[1] = func_02036bec(a, c->mUnk_02 * 0x38);
    }
    if (c->mUnk_00 == 1 && c->mUnk_03 > 1) {
        b->mUnk_04[2] = func_02036bec(a, 0x38);
        f = TRUE;
    } else if (c->mUnk_03 != 0) {
        b->mUnk_04[2] = func_02036bec(a, c->mUnk_03 * 0x38);
    }
    for (i = 0; i < c->mUnk_00; i++) {
        h = &b->mUnk_00[i];
        snprintf(s, 0x80, "%s.nsbmd", c->mUnk_04[i]);
        n = FindSceneFile(s);
        func_02084c54(h, n);
    }
    for (j = 0; j < c->mUnk_01; j++) {
        e = &b->mUnk_00[j];
        g = &b->mUnk_04[0][j];
        snprintf(s, 0x80, "%s.nsbca", c->mUnk_04[j]);
        func_0208823c(0, g, e, 1, a, NULL);
        func_0208805c(g, FindSceneFile(s), a);
        func_02087f84(g, 0);
    }
    for (l = 0; l < c->mUnk_02; l++) {
        p = &b->mUnk_00[l];
        q = &b->mUnk_04[1][l];
        snprintf(s, 0x80, "%s.nsbma", c->mUnk_04[l]);
        func_0208823c(4, q, p, 1, a, NULL);
        func_0208805c(q, FindSceneFile(s), a);
        func_02087f84(q, 0);
    }
    if (f != FALSE) {
        g = b->mUnk_04[2];
        func_0208823c(2, g, b->mUnk_00, c->mUnk_03, a, n);
        for (k = 0; k < c->mUnk_03; k++) {
            snprintf(s, 0x80, "%s.nsbtp", c->mUnk_04[k]);
            func_020881b0(g, k, func_02013b00(func_02013ae4(FindSceneFile(s)), 0), 0, a);
        }
        func_02087f84(g, 0);
    }
}

void func_0208a460(void *a) {
    s16 i;
    Unk0208a69c *p;
    Unk0208a69c *q;

    for (i = 0; i < 8; i++) {
        data_0217b034->mUnk_000[i] = NULL;
    }
    if (func_02062eb0() != 0) {
        return;
    }
    for (i = 0; i <= 2; i++) {
        if (i == 2) {
            data_0217b034->mUnk_000[i] = func_02036bec(a, 0x14);
            p = data_0217b034->mUnk_000[0];
            q = data_0217b034->mUnk_000[2];
            q->mUnk_00 = p->mUnk_00;
            q->mUnk_04[0] = NULL;
            q->mUnk_04[1] = p->mUnk_04[1];
            q->mUnk_04[2] = p->mUnk_04[2];
            q->mUnk_10 = p->mUnk_10;
        } else {
            data_0217b034->mUnk_000[i] = func_02036bec(a, 0x14);
            func_0208a69c(a, data_0217b034->mUnk_000[i], &data_02155ee8[(u32) i], i);
        }
    }
    if (data_021759c0->mUnk_08 == 2 || data_021759c0->mUnk_1c == 1) {
        data_0217b034->mUnk_000[4] = func_02036bec(a, 0x14);
        func_0208a69c(a, data_0217b034->mUnk_000[4], &data_02155f18, 4);
        data_0217b034->mUnk_000[5] = func_02036bec(a, 0x14);
        func_0208a69c(a, data_0217b034->mUnk_000[5], &data_02155f24, 5);
    } else if (data_021759c0->mUnk_08 == 4) {
        data_0217b034->mUnk_000[6] = func_02036bec(a, 0x14);
        func_0208a69c(a, data_0217b034->mUnk_000[6], &data_02155f30, 6);
        data_0217b034->mUnk_000[7] = func_02036bec(a, 0x14);
        func_0208a69c(a, data_0217b034->mUnk_000[7], &data_02155f3c, 7);
    } else {
        data_0217b034->mUnk_000[3] = func_02036bec(a, 0x14);
        func_0208a69c(a, data_0217b034->mUnk_000[3], &data_02155f0c, 3);
    }
}

void func_0208a31c(s32 a) {
    Unk0208a69c *p;
    Unk02087d0c *e;
    u16 i;
    s32 f;
    s32 v;

    data_0217b034->mUnk_000[8] = data_0217b034->mUnk_000[a];
    p = data_0217b034->mUnk_000[8];
    if (p == NULL) {
        data_0217b034->mUnk_73c = 9;
        return;
    }
    data_0217b034->mUnk_73c = a;
    for (i = 0; i < p->mUnk_10; i++) {
        if (p->mUnk_04[0] != NULL) {
            func_02087f84(&p->mUnk_04[0][i], 0);
        }
        if (p->mUnk_04[1] != NULL) {
            func_02087f84(&p->mUnk_04[1][i], 0);
        }
        if (a == 0 || a == 2) {
            if (a == 2) {
                f = 1;
            } else {
                f = 0;
            }
            if (a == 2) {
                v = 5;
            } else {
                v = 3;
            }
            func_02087f84(p->mUnk_04[2], (u16) f);
            e = p->mUnk_04[0];
            if (e != NULL) {
                e[i].mUnk_00 = 2;
                e[i].mUnk_12 = v;
            }
            e = p->mUnk_04[1];
            if (e != NULL) {
                e[i].mUnk_00 = 2;
                e[i].mUnk_12 = v;
            }
        }
    }
}

void func_0208a218(void) {
    Unk0208a69c *p;
    u16 i;

    if (data_0217b034->mUnk_73c == 1 || data_0217b034->mUnk_73c == 3) {
        data_0217b034->mUnk_740++;
        if (data_0217b034->mUnk_740 > data_0217b034->mUnk_742) {
            data_0217b034->mUnk_73c = 9;
        }
    }
    if (data_0217b034->mUnk_73c != 9) {
        p = data_0217b034->mUnk_000[8];
        for (i = 0; i < p->mUnk_10; i++) {
            if (p->mUnk_04[0] != NULL) {
                func_02087de0(p->mUnk_04[0]);
            }
            if (p->mUnk_04[1] != NULL) {
                func_02087de0(p->mUnk_04[1]);
            }
            if (p->mUnk_04[2] != NULL) {
                func_02087de0(p->mUnk_04[2]);
            }
        }
    }
    if (data_0217b034->mUnk_784.mUnk_08 != 0) {
        data_0217b034->mUnk_798(&data_0217b034->mUnk_784);
    }
}

void func_02089fa0(void) {
    Unk02012f58 a;
    Unk02012f58 b;
    Vec3 d;
    Vec3 *c;
    u16 i;
    Unk02084b2c *e;

    func_021471bc(&a);
    data_0217029c.mUnk_4c = a;
    if (data_021759c0->mUnk_00c != 0) {
        return;
    }
    if (data_0217b034->mUnk_73c != 9) {
        c = &b.mUnk_00[3];
        c->x = 0;
        c->y = 0;
        c->z = 0;
        d = data_0216608c;
        b.mUnk_00[3].y = data_02166048;
        if (data_0217b034->mUnk_73c == 2) {
            b.mUnk_00[3].y = 0x50000;
        }
        func_02146cbc(&b);
        for (i = 0; i < data_0217b034->mUnk_000[8]->mUnk_10; i++) {
            e = &data_0217b034->mUnk_000[8]->mUnk_00[i];
            func_0214ad4c(0x60000, -0x60000, -0x80000, 0x80000, 0, 0x1000, 0x1f6, 0,
                          (Unk0214ad4c *) data_0217029c.mUnk_08);
            data_0217029c.mUnk_fc &= ~0x50;
            func_02010fe4(&d);
            func_0214d0fc(&b, &data_0217029c.mUnk_bc);
            data_0217029c.mUnk_fc &= ~0xa4;
            func_0201100c(&b.mUnk_00[3]);
            func_02011034();
            func_01ff8cf0(e);
        }
    }
    if (data_0217b034->mUnk_784.mUnk_08 != 0) {
        reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~0x3000) | 8;
        reg_G3_SPE_EMI = 0x4210;
        reg_G3_DIF_AMB = 0x42100000;
        reg_G3_MTX_MODE = 0;
        func_0214a530(&data_0217b034->mUnk_744);
        reg_G3_TEXIMAGE_PARAM = 0x20000000;
        reg_G3_MTX_MODE = 2;
        reg_G3_MTX_IDENTITY = 0;
        func_02089d70(&data_0217b034->mUnk_784);
    }
}
