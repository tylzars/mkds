#include "Main/Unknown/code_0208eb10.h"

#include "Main/Unknown/code_02017000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_02166000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_020172d0.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0208d978.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020888b4.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_0207c000.h"
#include "Main/Unknown/code_0208537c.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_02047104.h"
#include "code_0201750c.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_0208fd8c.h"
#include "Main/Unknown/code_0208ffd8.h"
#include "Main/Unknown/code_0208ffe4.h"
#include "Main/Unknown/code_02090088.h"
#include "Main/Unknown/code_02090194.h"
#include "Main/Unknown/code_02077bc0.h"
#include "registers.h"

void func_02090194(Unk02090194 *p0) {
    p0->mUnk_10 = 0x1u;
}

void func_02090088(Unk0208fd8c *a, KartAi *b) {
    Unk0217aebc_128 *r;
    s32 v;

    if (DecrementHeldItemTimer(a) != 0) {
        r = GetKartAiRandom();
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        v = (s16) (u16) (r->mUnk_00 >> 52);
        if (v < 0xb33) {
            UseItemForwardAndResetInUseTimer(a, b);
        } else {
            UseItemBehindAndResetInUseTimer(a, b);
        }
    } else {
        if (b->mTargetKart == NULL) {
            return;
        }
        if (b->mTargetDistanceSquared >= 0x15f90) {
            return;
        }
        if (b->mTargetAhead != 0 && b->mTargetForwardDot > 0xb33) {
            UseItemForwardAndResetInUseTimer(a, b);
        } else {
            UseItemBehindAndResetInUseTimer(a, b);
        }
    }
}

void func_0208ffe4(Unk0208fd8c *a, KartAi *b) {
    Unk0217aebc_128 *r;
    s32 v;

    if (DecrementHeldItemTimer(a) == 0) {
        return;
    }
    r = GetKartAiRandom();
    r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
    v = (s16) (u16) (r->mUnk_00 >> 52);
    if (v < 0xb33) {
        UseItemForwardAndResetInUseTimer(a, b);
    } else {
        UseItemBehindAndResetInUseTimer(a, b);
    }
}

void func_0208ffd8(Unk0208ffd8 *p0) {
    p0->mUnk_10 = 0x1u;
}

void func_0208fefc(Unk0208fd8c *a, struct KartAi *b) {
    Unk0217aebc_128 *r;
    s32 v;

    if (DecrementHeldItemTimer(a) != 0) {
        r = GetKartAiRandom();
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        v = (s16) (u16) (r->mUnk_00 >> 52);
        if (v > 0xccd) {
            UseItemBehindAndResetInUseTimer(a, b);
        } else {
            UseItemForwardAndResetInUseTimer(a, b);
        }
    } else {
        if (b->mTargetKart == NULL) {
            return;
        }
        if (b->mTargetDistanceSquared >= 0x15f90) {
            return;
        }
        UseItemBehindAndResetInUseTimer(a, b);
    }
}

void func_0208fe58(Unk0208fd8c *a, struct KartAi *b) {
    Unk0217aebc_128 *r;
    s32 v;

    if (DecrementHeldItemTimer(a) == 0) {
        return;
    }
    r = GetKartAiRandom();
    r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
    v = (s16) (u16) (r->mUnk_00 >> 52);
    if (v > 0xccd) {
        UseItemBehindAndResetInUseTimer(a, b);
    } else {
        UseItemForwardAndResetInUseTimer(a, b);
    }
}

void func_0208fe1c(Unk0208fd8c *a, struct KartAi *b) {
    if (DecrementHeldItemTimer(a) == 0) {
        return;
    }
    UseItemAndResetInUseTimer(a, b);
}

void func_0208fdcc(Unk0208fd8c *a, struct KartAi *b) {
    if (DecrementHeldItemTimer(a) == 0) {
        return;
    }
    if (b->mTurnAngleDegrees >= 0xa000) {
        return;
    }
    UseItemAndResetHeldTimer(a, b);
}

void SetupBattleItemInUseEntry(Unk0208fd8c *a, struct KartAi *b) {
    enum { K0 } k = (gKartItems)[b->mIndex].mItemInUse.mObjectKind;
    Unk0208fd8c_08 *t = &gBattleItemInUseEntries[k];

    a->mItemInUseEntry = t;
    ResetItemInUseTimer(a, t);
}

u32 func_0208fd88(u32 p0) {
    return p0;
}
// Calls one of two handlers, by whether the item in use is the circling kind.

void func_0208fd24(Unk0208fd8c *a, struct KartAi *b) {
    if (gKartItems[b->mIndex].mItemInUse.mUseKind == ITEM_USE_KIND_CIRCLE) {
        data_0217b0a0(a, b);
    } else {
        data_0217b098(a, b);
    }
}

void ThrowItemAtNearTarget(Unk0208fd8c *a, struct KartAi *b) {
    if (b->mTargetKart == NULL) {
        return;
    }
    if (b->mTargetDistanceSquared >= 0x15f90) {
        return;
    }
    if (b->mTargetAhead != 0 && b->mTargetForwardDot > 0xb33) {
        UseItemForwardAndResetInUseTimer(a, b);
    } else {
        UseItemBehindAndResetInUseTimer(a, b);
    }
}

void func_0208fba0(Unk0208fd8c *a, struct KartAi *b) {
    Unk0217aebc_128 *r;
    s32 v;

    if (DecrementItemInUseTimer(a) != 0) {
        r = GetKartAiRandom();
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        v = (s16) (u16) (r->mUnk_00 >> 52);
        if (v < 0xb33) {
            UseItemForwardAndResetInUseTimer(a, b);
        } else {
            UseItemBehindAndResetInUseTimer(a, b);
        }
    } else {
        if (b->mTargetKart == NULL) {
            return;
        }
        if (b->mTargetDistanceSquared >= 0x15f90) {
            return;
        }
        if (b->mTargetAhead != 0 && b->mTargetForwardDot > 0xb33) {
            UseItemForwardAndResetInUseTimer(a, b);
        } else {
            UseItemBehindAndResetInUseTimer(a, b);
        }
    }
}

void func_0208fafc(Unk0208fd8c *a, struct KartAi *b) {
    Unk0217aebc_128 *r;
    s32 v;

    if (DecrementItemInUseTimer(a) == 0) {
        return;
    }
    r = GetKartAiRandom();
    r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
    v = (s16) (u16) (r->mUnk_00 >> 52);
    if (v < 0xb33) {
        UseItemForwardAndResetInUseTimer(a, b);
    } else {
        UseItemBehindAndResetInUseTimer(a, b);
    }
}

void func_0208fa50(Unk0208fd8c *a, struct KartAi *b) {
    a->mItemBitsEveryCall = 1;
    if (DecrementItemInUseTimer(a) == 0) {
        return;
    }
    if (b->mTargetKart == NULL) {
        return;
    }
    if (b->mTargetDistanceSquared >= 0x15f90) {
        return;
    }
    if (b->mTargetAhead != 0 && b->mTargetForwardDot > 0xb33) {
        UseItemForwardAndResetInUseTimer(a, b);
    } else {
        UseItemBehindAndResetInUseTimer(a, b);
    }
}

void func_0208f9ac(Unk0208fd8c *a, struct KartAi *b) {
    Unk0217aebc_128 *r;
    s32 v;

    if (DecrementItemInUseTimer(a) == 0) {
        return;
    }
    r = GetKartAiRandom();
    r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
    v = (s16) (u16) (r->mUnk_00 >> 52);
    if (v < 0xb33) {
        UseItemForwardAndResetInUseTimer(a, b);
    } else {
        UseItemBehindAndResetInUseTimer(a, b);
    }
// Calls one of two handlers, by whether the item in use is the circling kind.
}

void func_0208f948(Unk0208fd8c *a, struct KartAi *b) {
    if (gKartItems[b->mIndex].mItemInUse.mUseKind == ITEM_USE_KIND_CIRCLE) {
        data_0217b090(a, b);
    } else {
        data_0217b094(a, b);
    }
}

void func_0208f8ac(Unk0208fd8c *a, struct KartAi *b) {
    if (DecrementItemInUseTimer(a) == 0) {
        return;
    }
    if (b->mTargetKart == NULL) {
        return;
    }
    if (b->mTargetDistanceSquared >= 0x15f90) {
        return;
    }
    if (b->mTargetAhead == 0) {
        return;
    }
    if (b->mTargetForwardDot <= 0x666) {
        return;
    }
    UseItemAndResetInUseTimer(a, b);
}

void func_0208f810(Unk0208fd8c *a, struct KartAi *b) {
    if (DecrementItemInUseTimer(a) == 0) {
        return;
    }
    if (b->mTargetKart == NULL) {
        return;
    }
    if (b->mTargetDistanceSquared >= 0x15f90) {
        return;
    }
    if (b->mTargetAhead == 0) {
        return;
    }
    if (b->mTargetForwardDot <= 0x666) {
        return;
    }
    UseItemAndResetInUseTimer(a, b);
}

void UseItemAfterInUse(Unk0208fd8c *a, struct KartAi *b) {
    if (DecrementItemInUseTimer(a) == 0) {
        return;
    }
    UseItemAndResetInUseTimer(a, b);
}

void func_0208f754(Unk0208fd8c *a, struct KartAi *b) {
    if (DecrementItemInUseTimer(a) == 0) {
        return;
    }
    if (b->mTargetKart == NULL) {
        return;
    }
    if (b->mTargetDistanceSquared >= 0x15f90) {
        return;
    }
    if (b->mTargetAhead == 0) {
        return;
    }
    UseItemAndResetInUseTimer(a, b);
}

void func_0208f6d4(Unk0208fd8c *a, struct KartAi *b) {
    if (DecrementItemInUseTimer(a) == 0) {
        return;
    }
    if (b->mTargetKart == NULL) {
        return;
    }
    if (b->mTargetDistanceSquared >= 0x15f90) {
        return;
    }
    if (b->mTargetAhead == 0) {
        return;
    }
    UseItemAndResetInUseTimer(a, b);
// Calls one of two handlers, by whether the item in use is use kind 3.
}

void func_0208f670(Unk0208fd8c *a, struct KartAi *b) {
    if (gKartItems[b->mIndex].mItemInUse.mUseKind == ITEM_USE_KIND_3) {
        data_0217b0ac(a, b);
    } else {
        data_0217b0a8(a, b);
    }
}

void func_0208f5c4(Unk0208fd8c *a, struct KartAi *b) {
    if (DecrementItemInUseTimer(a) == 0) {
        return;
    }
    if (b->mTargetKart == NULL) {
        return;
    }
    if (b->mTargetDistanceSquared >= 0x15f90) {
        return;
    }
    if (b->mTargetAhead != 0) {
        if (b->mTargetForwardDot <= 0xb33) {
            return;
        }
        UseItemForwardAndResetInUseTimer(a, b);
    } else {
        UseItemBehindAndResetInUseTimer(a, b);
    }
}

void func_0208f4e8(Unk0208fd8c *a, struct KartAi *b) {
    Unk0217aebc_128 *r;
    s32 v;

    if (DecrementItemInUseTimer(a) != 0) {
        r = GetKartAiRandom();
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        v = (s16) (u16) (r->mUnk_00 >> 52);
        if (v > 0xb33) {
            UseItemBehindAndResetInUseTimer(a, b);
        } else {
            UseItemForwardAndResetInUseTimer(a, b);
        }
    } else {
        if (b->mTargetKart == NULL) {
            return;
        }
        if (b->mTargetDistanceSquared >= 0x15f90) {
            return;
        }
        UseItemBehindAndResetInUseTimer(a, b);
    }
}

void func_0208f434(Unk0208fd8c *a, struct KartAi *b) {
    a->mItemBitsEveryCall = 1;
    if (DecrementItemInUseTimer(a) == 0) {
        return;
    }
    if (b->mTargetKart == NULL) {
        return;
    }
    if (b->mTargetDistanceSquared >= 0x15f90) {
        return;
    }
    if (b->mTargetAhead != 0) {
        if (b->mTargetForwardDot <= 0xb33) {
            return;
        }
        UseItemBehindAndResetInUseTimer(a, b);
    } else {
        UseItemBehindAndResetInUseTimer(a, b);
    }
}

void UseItemBehindAfterInUseOrNearTarget(Unk0208fd8c *a, struct KartAi *b) {
    if (DecrementItemInUseTimer(a) == 0) {
        if (b->mTargetKart == NULL) {
            return;
        }
        if (b->mTargetDistanceSquared >= 0x15f90) {
            return;
        }
    }
    UseItemBehindAndResetInUseTimer(a, b);
}

void func_0208f0f8(void *a) {
    void *s;
    Unk0208ec64 *e;
    Unk0208ec64_08 *f;
    u16 i;
    u16 n;
    u16 m;
    NNSG3dResTex *q;
    s32 t;

    s = FindMainRaceOrMainEffectFile(data_021759c0->mUnk_00c == 5 ? data_02166514 : data_02166530);
    data_021663f0 = 0x4d;
    data_021663e0 = 8;
    data_021663dc = 3;
    data_021663e4 = 0xc;
    data_021663ec = (s32(*)()) func_0208ee40;
    data_021663d8 = 0xe;
    data_021663e8 = 1;
    n = 1;
    if (data_021759c0->mMode == 5) {
        n += 3;
    } else if (data_021759c0->mUnk_00c == 5) {
        data_021663f0 = 0;
        data_021663e0 = 0xe;
        data_021663dc = 2;
        data_021663e4 = 0x1e;
        data_021663ec = (s32(*)()) func_0208ecd8;
        data_021663d8 = 4;
        data_021663e8 = 0;
        n = 6;
    }
    m = data_021663e4 * n;
    if (data_021759c0->mMode == MODE_MISSION_RUN) {
        a = data_0217aa10->mUnk_a4;
    }
    data_0217b08c = HeapAlloc(a, 0x38);
    e = HeapAlloc(a, n * 0x30);
    f = HeapAlloc(a, m * 0x1c);
    NNS_FndInitList(&data_0217b08c->mUnk_00[0], 0);
    NNS_FndInitList(&data_0217b08c->mUnk_00[1], 0);
    NNS_FndInitList(&data_0217b08c->mUnk_00[2], 0);
    for (i = 0; i < n; i++) {
        NNS_FndInitList(&e[i].mUnk_08, 0);
        NNS_FndAppendListObject(&data_0217b08c->mUnk_00[1], &e[i]);
    }
    for (i = 0; i < m; i++) {
        NNS_FndAppendListObject(&data_0217b08c->mUnk_00[2], &f[i]);
    }
    AddResFileEntry(&data_0217b08c->mUnk_24, s, s);
    q = data_0217b08c->mUnk_24.mTexture;
    t = (q->mTexInfo.mVramKey & 0xffff) << 3;
    data_021663f4.mUnk_00 = data_021663f4.mUnk_00 & 0xffff0000;
    data_021663f4.mUnk_00 = data_021663f4.mUnk_00 | (((u32) t >> 3) & 0xffff);
    data_021663f4.mUnk_18 = (q->mPlttInfo.mVramKey & 0xffff) << 3;
    data_021663f4.mUnk_1c = 0x10000;
    data_021663f4.mUnk_20 = 0x8000;
    data_0217b08c->mUnk_34 = data_021759c0->mCourseId == COURSE_ID_RAINBOW ? 0 : 0x8000;
}

void func_0208f0a0(void) {
    void *p;
    p = NNS_FndGetNextListObject(&data_0217b08c->mUnk_00[0], NULL);
    while (p != NULL) {
        func_0208e99c(p);
        p = NNS_FndGetNextListObject(&data_0217b08c->mUnk_00[0], p);
    }
}

void func_0208ee7c(const MtxFx43 *a) {
    Unk0208ec64 *p;
    Unk0208ec64_08 *r;
    Unk0208ec64_08 *q;
    s32 v;
    u8 f;
    BOOL g;

    f = data_021663d8;
    g = FALSE;
    p = NNS_FndGetNextListObject(&data_0217b08c->mUnk_00[0], NULL);
    if (p == NULL) {
        return;
    }
    do {
        if (g == FALSE) {
            reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~0x3000) | 8;
            reg_G3_SPE_EMI = 0x7c004210;
            reg_G3_DIF_AMB = 0x42100000;
            reg_G3_MTX_MODE = 3;
            reg_G3_MTX_IDENTITY = 0;
            reg_G3_MTX_MODE = 2;
            reg_G3_TEXIMAGE_PARAM = data_021663f4.mUnk_00;
            reg_G3_PLTT_BASE = data_021663f4.mUnk_18 >> (4 - ((data_021663f4.mUnk_00 >> 26 & 7) == 2));
            g = TRUE;
        }
        reg_G3_COLOR = 0x7fff;
        q = NNS_FndGetNextListObject(&p->mUnk_08, NULL);
        if (q != NULL && data_021663e8 != 0) {
            r = NNS_FndGetNextListObject(&p->mUnk_08, NULL);
            if (r != NULL) {
                do {
                    v = 0x1f - q->mUnk_0c * data_021663dc;
                    reg_G3_POLYGON_ATTR = f << 24 | (data_0217b08c->mUnk_34 | 0xc0) | v << 16;
                    func_0208e82c(a, q, r, &data_021663f4);
                    q = r;
                    r = NNS_FndGetNextListObject(&p->mUnk_08, r);
                } while (r != NULL);
            }
        }
        f = f + 1;
        p = NNS_FndGetNextListObject(&data_0217b08c->mUnk_00[0], p);
    } while (p != NULL);
}

void func_0208ee40(u32 arg0, u32 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2;
    u32 value3;
    value3 = *(const u32 *) ((value1) + (20));
    value2 = *(const u32 *) ((value1) + (28));
    value1 = 0u;
    *(u32 *) ((value0) + (8)) = value2;
    *(u16 *) ((value0) + (12)) = value1;
    value1 = *(const u32 *) ((value3) + (0));
    value1 = ((s32) value1 >> 4);
    *(u32 *) ((value0) + (16)) = value1;
    value1 = *(const u32 *) ((value3) + (4));
    value1 = ((s32) value1 >> 4);
    *(u32 *) ((value0) + (20)) = value1;
    value1 = *(const u32 *) ((value3) + (8));
    value1 = ((s32) value1 >> 4);
    *(u32 *) ((value0) + (24)) = value1;
}

void func_0208ecd8(Unk0208ec64_08 *a, Unk0208ec64 *b) {
    Kart *o;
    Vec3 v;
    Vec3 x;
    Vec3 y;
    Vec3 z;
    Vec3 *p;
    s32 k;

    o = GetKart(b->mUnk_20);
    v = o->mPos;
    p = &o->mUnk_120;
    k = b->mUnk_24;
    x.x = ((s64) p->x * k) >> 12;
    x.y = ((s64) p->y * k) >> 12;
    x.z = ((s64) p->z * k) >> 12;
    p = &o->mUnk_12c;
    k = b->mUnk_28;
    y.x = ((s64) p->x * k) >> 12;
    y.y = ((s64) p->y * k) >> 12;
    y.z = ((s64) p->z * k) >> 12;
    p = &o->mUnk_138;
    k = b->mUnk_2c;
    z.x = ((s64) p->x * k) >> 12;
    z.y = ((s64) p->y * k) >> 12;
    z.z = ((s64) p->z * k) >> 12;
    VEC_Add(&v, &x, &v);
    VEC_Add(&v, &y, &v);
    VEC_Add(&v, &z, &v);
    a->mUnk_08 = b->mUnk_1c;
    a->mUnk_0c = 0;
    a->mUnk_10.x = v.x >> 4;
    a->mUnk_10.y = v.y >> 4;
    a->mUnk_10.z = v.z >> 4;
}

s32 func_0208ec64(u32 a) {
    Unk0208ec64 *p;
    p = NNS_FndGetNthListObject(&data_0217b08c->mUnk_00[1], 0);
    if (p != NULL) {
        p->mUnk_14 = a;
        p->mUnk_18 = 0;
        p->mUnk_1c = 0x400;
        NNS_FndRemoveListObject(&data_0217b08c->mUnk_00[1], p);
        NNS_FndAppendListObject(&data_0217b08c->mUnk_00[0], p);
    }
    return (s32) p;
}

Unk0208ec64 *func_0208eb1c(s32 a) {
    Unk0208ec64 *p;
    Kart *o;
    Unk0206bcb0_590 *t;
    Vec3 v;
    s32 h;

    if (data_021759c0->mUnk_00c == 5) {
        p = NNS_FndGetNthListObject(&data_0217b08c->mUnk_00[1], 0);
        if (p != NULL) {
            o = GetKart(a);
            t = o->mKartModelsEntry;
            v = ((Vec3 *) &t->mUnk_020->mUnk_44)[t->mUnk_000];
            p->mUnk_14 = (u32) &o->mPos;
            p->mUnk_18 = 0;
            p->mUnk_1c = 0x400;
            p->mUnk_20 = a;
            h = (v.y + (data_02166418[t->mUnk_000][0] >> 4) - data_02166480[t->mUnk_004]) / 2;
            p->mUnk_1c = h;
            p->mUnk_24 = v.x << 4;
            p->mUnk_28 = (data_02166480[t->mUnk_004] + h) << 4;
            p->mUnk_2c = data_0216641c[t->mUnk_000][0] + (v.z << 4);
            NNS_FndRemoveListObject(&data_0217b08c->mUnk_00[1], p);
            NNS_FndAppendListObject(&data_0217b08c->mUnk_00[0], p);
        }
        return p;
    }
    return NULL;
}

void func_0208eb10(u32 p0) {
    *OFFSET_PTR(u32, p0, 24) = 0x1u;
}
