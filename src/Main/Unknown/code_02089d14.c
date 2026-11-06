#include "Main/Unknown/code_02089d14.h"

#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_02089d70.h"
#include "Main/Unknown/code_02089e10.h"
#include "registers.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/code_02089ecc.h"
#include "Main/Unknown/code_02089ef4.h"
#include "Main/Unknown/code_02087d0c.h"
#include "Main/Unknown/code_02089fa0.h"
#include "Main/Unknown/code_02089f9c.h"
#include "Main/Unknown/code_02036820.h"
#include "ITCM/code_01ff8000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020846c0.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_02170000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02010c84.h"
#include "code_02013740.h"
#include "code_02134398.h"
#include "code_02146cbc.h"
#include "code_0214a4dc.h"
#include "code_0214a748.h"
#include "code_021471bc.h"

void func_0208aa30(void *a) {
    Unk0217b034_784 *p;

    data_0217b034 = HeapAlloc(a, 0x79c);
    func_0208a460(a);
    data_0217b034->mUnk_73c = 9;
    reg_G3_MTX_MODE = 0;
    ComputeOrthoMatrix(0x60000, -0x60000, -0x80000, 0x80000, 0, 0x1000, 0x200, 1, &data_0217b034->mUnk_744);
    p = &data_0217b034->mUnk_784;
    data_0217b034->mUnk_784.mUnk_00 = 0;
    p->mUnk_02 = 0;
    p->mUnk_04 = 0x7fff;
    p->mUnk_08 = FALSE;
}

void InitNsbmdNsbcaNsbmaNsbtp(void *a, Unk0208a69c *b, const Unk02155ee8 *c, u16 d) {
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
    b->mNsbmdCount = c->mNsbmdCount;
    b->mNsbmds = NULL;
    b->mNsbcaNsbmaNsbtp[0] = b->mNsbcaNsbmaNsbtp[1] = b->mNsbcaNsbmaNsbtp[2] = NULL;
    f = FALSE;
    if (c->mNsbmdCount != 0) {
        b->mNsbmds = HeapAlloc(a, c->mNsbmdCount * 0x6c);
    }
    if (c->mNsbcaCount != 0) {
        b->mNsbcaNsbmaNsbtp[0] = HeapAlloc(a, c->mNsbcaCount * 0x38);
    }
    if (c->mNsbmaCount != 0) {
        b->mNsbcaNsbmaNsbtp[1] = HeapAlloc(a, c->mNsbmaCount * 0x38);
    }
    if (c->mNsbmdCount == 1 && c->mNsbtpCount > 1) {
        b->mNsbcaNsbmaNsbtp[2] = HeapAlloc(a, 0x38);
        f = TRUE;
    } else if (c->mNsbtpCount != 0) {
        b->mNsbcaNsbmaNsbtp[2] = HeapAlloc(a, c->mNsbtpCount * 0x38);
    }
    for (i = 0; i < c->mNsbmdCount; i++) {
        h = &b->mNsbmds[i];
        snprintf(s, 0x80, "%s.nsbmd", c->mStems[i]);
        n = FindSceneFile(s);
        func_02084c54(h, n);
    }
    for (j = 0; j < c->mNsbcaCount; j++) {
        e = &b->mNsbmds[j];
        g = &b->mNsbcaNsbmaNsbtp[0][j];
        snprintf(s, 0x80, "%s.nsbca", c->mStems[j]);
        func_0208823c(0, g, e, 1, a, NULL);
        func_0208805c(g, FindSceneFile(s), a);
        func_02087f84(g, 0);
    }
    for (l = 0; l < c->mNsbmaCount; l++) {
        p = &b->mNsbmds[l];
        q = &b->mNsbcaNsbmaNsbtp[1][l];
        snprintf(s, 0x80, "%s.nsbma", c->mStems[l]);
        func_0208823c(4, q, p, 1, a, NULL);
        func_0208805c(q, FindSceneFile(s), a);
        func_02087f84(q, 0);
    }
    if (f != FALSE) {
        g = b->mNsbcaNsbmaNsbtp[2];
        func_0208823c(2, g, b->mNsbmds, c->mNsbtpCount, a, n);
        for (k = 0; k < c->mNsbtpCount; k++) {
            snprintf(s, 0x80, "%s.nsbtp", c->mStems[k]);
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
            data_0217b034->mUnk_000[i] = HeapAlloc(a, 0x14);
            p = data_0217b034->mUnk_000[0];
            q = data_0217b034->mUnk_000[2];
            q->mNsbmds = p->mNsbmds;
            q->mNsbcaNsbmaNsbtp[0] = NULL;
            q->mNsbcaNsbmaNsbtp[1] = p->mNsbcaNsbmaNsbtp[1];
            q->mNsbcaNsbmaNsbtp[2] = p->mNsbcaNsbmaNsbtp[2];
            q->mNsbmdCount = p->mNsbmdCount;
        } else {
            data_0217b034->mUnk_000[i] = HeapAlloc(a, 0x14);
            InitNsbmdNsbcaNsbmaNsbtp(a, data_0217b034->mUnk_000[i], &gCountStartStems[(u32) i], i);
        }
    }
    if (data_021759c0->mMode == MODE_BATTLE || data_021759c0->mUnk_1c == 1) {
        data_0217b034->mUnk_000[4] = HeapAlloc(a, 0x14);
        InitNsbmdNsbcaNsbmaNsbtp(a, data_0217b034->mUnk_000[4], &gWinStems, 4);
        data_0217b034->mUnk_000[5] = HeapAlloc(a, 0x14);
        InitNsbmdNsbcaNsbmaNsbtp(a, data_0217b034->mUnk_000[5], &gLoseStems, 5);
    } else if (data_021759c0->mMode == MODE_MISSION_RUN) {
        data_0217b034->mUnk_000[6] = HeapAlloc(a, 0x14);
        InitNsbmdNsbcaNsbmaNsbtp(a, data_0217b034->mUnk_000[6], &gCompleteStems, 6);
        data_0217b034->mUnk_000[7] = HeapAlloc(a, 0x14);
        InitNsbmdNsbcaNsbmaNsbtp(a, data_0217b034->mUnk_000[7], &gFailedStems, 7);
    } else {
        data_0217b034->mUnk_000[3] = HeapAlloc(a, 0x14);
        InitNsbmdNsbcaNsbmaNsbtp(a, data_0217b034->mUnk_000[3], &gGoalStems, 3);
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
    for (i = 0; i < p->mNsbmdCount; i++) {
        if (p->mNsbcaNsbmaNsbtp[0] != NULL) {
            func_02087f84(&p->mNsbcaNsbmaNsbtp[0][i], 0);
        }
        if (p->mNsbcaNsbmaNsbtp[1] != NULL) {
            func_02087f84(&p->mNsbcaNsbmaNsbtp[1][i], 0);
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
            func_02087f84(p->mNsbcaNsbmaNsbtp[2], (u16) f);
            e = p->mNsbcaNsbmaNsbtp[0];
            if (e != NULL) {
                e[i].mUnk_00 = 2;
                e[i].mUnk_12 = v;
            }
            e = p->mNsbcaNsbmaNsbtp[1];
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
        for (i = 0; i < p->mNsbmdCount; i++) {
            if (p->mNsbcaNsbmaNsbtp[0] != NULL) {
                func_02087de0(p->mNsbcaNsbmaNsbtp[0]);
            }
            if (p->mNsbcaNsbmaNsbtp[1] != NULL) {
                func_02087de0(p->mNsbcaNsbmaNsbtp[1]);
            }
            if (p->mNsbcaNsbmaNsbtp[2] != NULL) {
                func_02087de0(p->mNsbcaNsbmaNsbtp[2]);
            }
        }
    }
    if (data_0217b034->mUnk_784.mUnk_08 != FALSE) {
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

    Matrix4x3Identity(&a);
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
        Matrix3x3Identity(&b);
        for (i = 0; i < data_0217b034->mUnk_000[8]->mNsbmdCount; i++) {
            e = &data_0217b034->mUnk_000[8]->mNsbmds[i];
            ComputeOrthoMatrix(0x60000, -0x60000, -0x80000, 0x80000, 0, 0x1000, 0x1f6, 0,
                               (Unk0214ad4c *) data_0217029c.mUnk_08);
            data_0217029c.mUnk_fc &= ~0x50;
            func_02010fe4(&d);
            MI_Copy36B(&b, &data_0217029c.mUnk_bc);
            data_0217029c.mUnk_fc &= ~0xa4;
            func_0201100c(&b.mUnk_00[3]);
            func_02011034();
            func_01ff8cf0(e);
        }
    }
    if (data_0217b034->mUnk_784.mUnk_08 != FALSE) {
        reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~0x3000) | 8;
        reg_G3_SPE_EMI = 0x4210;
        reg_G3_DIF_AMB = 0x42100000;
        reg_G3_MTX_MODE = 0;
        GxFifoWrite0x16Then16Words(&data_0217b034->mUnk_744);
        reg_G3_TEXIMAGE_PARAM = 0x20000000;
        reg_G3_MTX_MODE = 2;
        reg_G3_MTX_IDENTITY = 0;
        func_02089d70(&data_0217b034->mUnk_784);
    }
}

u32 func_02089f9c(u32 p0) {
    return p0;
}

void func_02089ef4(s32 a) {
    if (a == 9) {
        data_0217b034->mUnk_73c = a;
        return;
    }
    if (data_0217b034->mUnk_73c != a || a == 2) {
        func_0208a31c(a);
    }
    data_0217b034->mUnk_740 = 0;
    if (data_0217b034->mUnk_73c == 1 || data_0217b034->mUnk_73c == 3) {
        data_0217b034->mUnk_742 = func_02087d0c(data_0217b034->mUnk_000[8]->mNsbcaNsbmaNsbtp[0]) >> 12;
    }
}

void func_02089ecc(Unk02089ecc *p0) {
    p0->mUnk_00 = (u16) 0xau;
    p0->mUnk_02 = (u16) 0xcu;
    p0->mUnk_04 = (u16) 0x7fffu;
    p0->mUnk_08 = (u32) 0x1u;
}

void func_02089e68(Unk02089e68 *a) {
    a->mUnk_02 = (s32) (((s64) ((s32) a->mUnk_00 << 12) * 0x1333 + 0x800) >> 12) >> 12;
    a->mUnk_00 = a->mUnk_00 - 1;
    if (a->mUnk_00 <= 0) {
        a->mUnk_08 = 0;
    }
}

void func_02089e10(int a) {
    *(u32 *) 0x400048c = data_02155ed0[a * 3] | data_02155ed0[a * 3 + 1] << 16;
    *(u32 *) 0x400048c = data_02155ed0[a * 3 + 2];
}

void func_02089d70(Unk0217b034_784 *a) {
    u32 *v1;
    u32 *v2;
    v1 = ((u32 *) 0x0400046cu);
    reg_G3_POLYGON_ATTR = (0x090000c0u) | a->mUnk_02 << 0x10;
    *v1 = 0x8c000;
    *v1 = 0x6e000;
    v2 = ((u32 *) 0x04000500u);
    *v1 = 0xa000;
    *v2 = 1;
    reg_G3_COLOR = (u32) a->mUnk_04;
    func_02089e10(0);
    func_02089e10(1);
    func_02089e10(2);
    func_02089e10(3);
    reg_G3_END_VTXS = 0;
}

void func_02089d14(u32 a) {
    data_0217b034->mUnk_794 = data_02155ec8[a];
    data_0217b034->mUnk_798 = data_02155ecc[a];
    data_0217b034->mUnk_794(&data_0217b034->mUnk_784);
}
