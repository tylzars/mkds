#include "Main/Unknown/code_02087d0c.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02087934.h"
#include "code_020109c4.h"
#include "code_02010c84.h"

#include "Main/Unknown/code_02087cd0.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_02036bec.h"
#include "code_02013740.h"
#include "code_02013bdc.h"

u32 func_0208832c(Unk020882fc *p0) {
    return p0->mUnk_08->mUnk_04;
}

u32 func_02088320(Unk020882fc *p0) {
    return p0->mUnk_08->mUnk_04;
}

u32 func_02088314(Unk020882fc *p0) {
    return p0->mUnk_08->mUnk_04;
}

u32 func_02088308(Unk020882fc *p0) {
    return p0->mUnk_08->mUnk_04;
}

u32 func_020882fc(Unk020882fc *p0) {
    return p0->mUnk_08->mUnk_04;
}

void func_0208823c(u32 a, void *b, void *c, u32 d, void *e, void *f) {
    Unk02087d0c *p = b;
    NNSG3dRenderObj *q = c;
    u16 i;

    if (d != 0) {
        i = 0;
        if (e != NULL) {
            p->mUnk_1c = HeapAlloc(e, d * 4);
            p->mUnk_20 = HeapAlloc(e, d * 4);
            for (; i < d; i++) {
                p->mUnk_1c[i] = NULL;
                p->mUnk_20[i] = 0;
            }
        }
    }
    func_02087cd0(p, 0);
    q->mUnk_58 = 0;
    p->mUnk_14 = q;
    p->mUnk_18 = d;
    p->mUnk_1a = 0;
    p->mUnk_28 = a;
    p->mUnk_2c = FALSE;
    p->mUnk_30 = 0x19a;
    p->mUnk_34 = NULL;
}

void func_020881b0(void *a, s32 b, void *c, u32 d, void *e) {
    Unk02087d0c *p = a;
    NNSG3dAnmObj *x;

    if (e == NULL) {
        x = p->mUnk_1c[b];
        p->mUnk_20[b] = d;
    } else {
        data_0217af20 = NNS_G3dAnmObjCalcSizeRequired(c, p->mUnk_14->mResMdl);
        x = HeapAlloc(e, data_0217af20);
        p->mUnk_1c[b] = x;
        p->mUnk_20[b] = d;
    }
    NNS_G3dAnmObjInit((NNSG3dAnmObj *) x, c, p->mUnk_14->mResMdl, (void *) p->mUnk_14->mUnk_68);
}

void func_0208805c(void *a, void *b, void *c) {
    Unk02087d0c *p = a;
    void *v = NULL;
    u8 i = 0;
    NNSG3dAnmObj *x;

    for (i = 0; i < p->mUnk_18; i++) {
        switch (p->mUnk_28) {
            case 0:
                v = NNS_G3dGetJntAnmByIdx(NNS_G3dGetJntAnmSet(b), i);
                break;
            case 2:
                v = NNS_G3dGetTexPatAnmByIdx(NNS_G3dGetTexPatAnmSet(b), i);
                break;
            case 1:
                v = NNS_G3dGetTexSRTAnmByIdx(NNS_G3dGetTexSRTAnmSet(b), i);
                break;
            case 3:
                v = NNS_G3dGetVisAnmByIdx(NNS_G3dGetVisAnmSet(b), i);
                break;
            case 4:
                v = NNS_G3dGetMatCAnmByIdx(NNS_G3dGetMatCAnmSet(b), i);
                break;
        }
        if (c != NULL) {
            data_0217af20 = NNS_G3dAnmObjCalcSizeRequired(v, p->mUnk_14->mResMdl);
            x = HeapAlloc(c, data_0217af20);
            p->mUnk_1c[i] = x;
            p->mUnk_20[i] = 0;
        } else {
            x = p->mUnk_1c[i];
            p->mUnk_20[i] = 0;
        }
        NNS_G3dAnmObjInit((NNSG3dAnmObj *) x, v, p->mUnk_14->mResMdl, (void *) p->mUnk_14->mUnk_68);
    }
}

void func_02087f84(void *b, s32 a) {
    Unk02087d0c *p = b;
    s32 v;

    if (p->mUnk_1c[a] == NULL) {
        return;
    }
    p->mUnk_2c = FALSE;
    if (p->mUnk_34 != NULL) {
        NNS_G3dRenderObjRemoveAnmObj(p->mUnk_14, p->mUnk_34);
        p->mUnk_34 = NULL;
    }
    NNS_G3dRenderObjRemoveAnmObj(p->mUnk_14, p->mUnk_1c[p->mUnk_1a]);
    p->mUnk_1a = a;
    NNS_G3dRenderObjAddAnmObj(p->mUnk_14, p->mUnk_1c[p->mUnk_1a]);
    p->mUnk_1c[p->mUnk_1a]->mRatio = 0x1000;
    v = data_02155cd8[p->mUnk_28](p->mUnk_1c[p->mUnk_1a]) << 12;
    func_02087c9c(p, v, (u16) p->mUnk_20[p->mUnk_1a]);
}

void func_02087e90(void *b, u16 a) {
    Unk02087d0c *p = b;
    s32 v;

    if (p->mUnk_1c[a] == NULL) {
        return;
    }
    if (p->mUnk_1a == a) {
        return;
    }
    p->mUnk_2c = TRUE;
    if (p->mUnk_34 != NULL) {
        NNS_G3dRenderObjRemoveAnmObj(p->mUnk_14, p->mUnk_34);
        p->mUnk_34 = NULL;
    }
    p->mUnk_34 = p->mUnk_1c[p->mUnk_1a];
    p->mUnk_34->mRatio = 0x1000;
    p->mUnk_1a = a;
    NNS_G3dRenderObjAddAnmObj(p->mUnk_14, p->mUnk_1c[p->mUnk_1a]);
    p->mUnk_1c[p->mUnk_1a]->mRatio = 0;
    v = data_02155cd8[p->mUnk_28](p->mUnk_1c[p->mUnk_1a]) << 12;
    func_02087c9c(p, v, (u16) p->mUnk_20[p->mUnk_1a]);
}

void func_02087de0(void *a) {
    Unk02087d0c *p = a;

    if (p->mUnk_2c != FALSE) {
        p->mUnk_1c[p->mUnk_1a]->mRatio += p->mUnk_30;
        p->mUnk_34->mRatio -= p->mUnk_30;
        if (p->mUnk_1c[p->mUnk_1a]->mRatio >= 0x1000) {
            p->mUnk_2c = FALSE;
            p->mUnk_1c[p->mUnk_1a]->mRatio = 0x1000;
            NNS_G3dRenderObjRemoveAnmObj(p->mUnk_14, p->mUnk_34);
            p->mUnk_34 = NULL;
        }
    }
    func_02087b78(p);
    p->mUnk_1c[p->mUnk_1a]->mFrame = p->mUnk_0c;
}

void func_02087d44(Unk02087d0c *p) {
    if (p->mUnk_2c == FALSE) {
        return;
    }
    p->mUnk_1c[p->mUnk_1a]->mRatio += p->mUnk_30;
    p->mUnk_34->mRatio -= p->mUnk_30;
    if (p->mUnk_1c[p->mUnk_1a]->mRatio >= 0x1000) {
        p->mUnk_2c = FALSE;
        p->mUnk_1c[p->mUnk_1a]->mRatio = 0x1000;
        NNS_G3dRenderObjRemoveAnmObj(p->mUnk_14, p->mUnk_34);
        p->mUnk_34 = NULL;
    }
}

s32 func_02087d0c(void *a) {
    Unk02087d0c *p = a;
    enum { K0 } k = p->mUnk_28;

    return data_02155cd8[k](p->mUnk_1c[p->mUnk_1a]) << 12;
}
