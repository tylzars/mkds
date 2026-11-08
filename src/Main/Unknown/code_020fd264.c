#include "Main/Unknown/code_020fd264.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_0208ab98.h"

#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020fa000.h"
#include "Main/Unknown/code_020f9c40.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020fd83c.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0216c000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0208a000.h"
#include "Main/Unknown/code_020f2dac.h"
#include "Main/Unknown/code_020f9000.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020fd7f0.h"
#include "Main/Unknown/code_020fd804.h"
#include "Main/Unknown/code_020f2d98.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_0208d978.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02073000.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020f49bc.h"
#include "Main/Unknown/code_020f7000.h"
#include "Main/Unknown/code_020f8000.h"
#include "Main/Unknown/code_0210e000.h"
#include "Main/Unknown/code_020fe4b4.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/code_020fe168.h"
#include "Main/Unknown/code_020fe16c.h"
#include "Main/Unknown/code_020fe264.h"
#include "Main/Unknown/code_020fe268.h"
#include "Main/Unknown/code_020fe3d8.h"
#include "Main/Unknown/code_02077bc0.h"
#include "code_021471bc.h"
#include "Main/Unknown/code_021000d0.h"

// Reset hook of the bomb kind.
void ResetItemBomb(ItemBomb *a) {
    u32 v1;
    MTX_Identity43_((MtxFx43 *) a->mUnk_13c);
    func_02046be8(a->mUnk_184, (UnkFunc *const *) &gItemBombStateTable, 4, a);
    SetStateMachineState(a->mUnk_184, 0);
    a->mUnk_170 = 300;
    a->mUnk_174 = 0;
    v1 = 0x05f592e1u;
    a->mUnk_178 = 8;
    a->mUnk_17c = v1;
    a->mUnk_180 = 0;
    a->mUnk_16c = FALSE;
    a->mUnk_1a0 = TRUE;
    a->mUnk_198 = NULL;
}

s32 InitItemBomb(ItemInUse *a, ItemBomb *e) {
    func_020f9114(e);
    e->mUnk_000.mItemObject.mUnk_78 |= data_02159f3c;
    e->mUnk_134 = (s32) (((s64) a->mKartVelocityLength * 0x1ec) >> 12) + 0x333;
    if (e->mUnk_134 > 0xccd) {
        e->mUnk_134 = 0xccd;
    }
    if (a->mKartItems->mFlags & 0x20) {
        ThrowBouncingItem(&e->mUnk_000, a, 2, 0, 0x7800, 0x5000, 0x219a);
        e->mUnk_170 = 0x5a;
        e->mUnk_130 = 0;
        return e->mUnk_130;
    }
    if (a->mKartItems->mFlags & KART_ITEMS_THROW_FORWARD) {
        ThrowBouncingItem(&e->mUnk_000, a, 3, 1, 0x9800, 0x5000, 0x59a);
    } else {
        ThrowBouncingItem(&e->mUnk_000, a, 3, 1, 0x6000, 0x5000, 0x59a);
    }
    StartSound(&e->mUnk_000.mItemObject.mSoundSource, 0xda, 0x7f, 0);
    e->mUnk_130 = 1;
    return e->mUnk_130;
}

u32 func_020fe264(u32 p0) {
    return p0;
}

void UpdateItemBombState0(ItemBomb *e) {
    s32 v;

    if (e->mUnk_130 != 0) {
        AdvanceBouncingItem(&e->mUnk_000, 0x385, 0xff8, 0x733, (u32 *) &v);
    } else {
        AdvanceBouncingItem(&e->mUnk_000, 0x47b, 0xf91, e->mUnk_134, (u32 *) &v);
    }
    if (e->mUnk_000.mItemObject.mFlags & KART_ITEMS_THROW_FORWARD) {
        func_020f91fc(e, 0xe5);
    }
    if ((e->mUnk_000.mItemObject.mFlags & 0x8) == 0) {
        return;
    }
    if (e->mUnk_000.mItemObject.mFlags & 0x3) {
        return;
    }
    if (e->mUnk_130 != 0) {
        e->mUnk_000.mItemObject.mVelocity.y *= 2;
    }
    StopSound(&e->mUnk_000.mItemObject.mSoundSource, 0xda);
    StartRestingItemObject(&e->mUnk_000.mItemObject, &v);
    if ((e->mUnk_000.mItemObject.mFlags & 0x180000) == 0) {
        e->mUnk_000.mItemObject.mAdvance = (void (*)(ItemObject *)) AdvanceItemBomb;
    }
    e->mNextState = 1;
    e->mNextStateRequested = 1;
}

u32 func_020fe168(u32 p0) {
    return p0;
}

void UpdateItemBombState1(ItemBomb *e) {
    u32 f;

    f = e->mUnk_000.mItemObject.mFlags;
    if (f & 0x8000) {
        AdvanceRestingItemObject(&e->mUnk_000.mItemObject);
        return;
    }
    if (f & 0x4000) {
        AdvanceFallingItemObject(&e->mUnk_000.mItemObject);
        e->mUnk_170 = 0x5a;
        e->mUnk_174 = 0;
    }
}

void EnterItemBombState2(ItemBomb *e) {
    NNSSndSeqPlayer **p;
    ModelEffect *q;

    e->mUnk_000.mItemObject.mFlags |= 0x800000;
    e->mUnk_000.mItemObject.mUnk_100 = 0;
    e->mUnk_000.mItemObject.mScale = data_02159f30;
    e->mUnk_138 =
        StartModelEffect(0, &e->mUnk_000.mItemObject.mPos, func_020f9160(&e->mUnk_000.mItemObject) == 0 ? 1 : 0);
    q = e->mUnk_138;
    if (q != NULL) {
        s32 *t;

        t = q->mScale;
        t[0] = 0xccd;
        t[1] = 0xccd;
        t[2] = 0xccd;
    }
    func_020f91fc(e, 0xe4);
    if (data_0217c780 & 1) {
        p = func_0210e128(func_02108ea0(0));
        if (data_0217d084.mUnk_0c != 0) {
            if (p[0] != NULL) {
                NNS_SndPlayerStopSeq(p, 0);
            }
            if (p[0] != NULL) {
                NNS_SndPlayerStopSeq(p, 0);
            }
            NNS_SndArcPlayerStartSeqArc(p, 0, 0xe0);
        }
    }
    StartCameraWobbleAtDistance(e->mUnk_000.mItemObject.mDistanceSquaredAndFlags & ~0xc000001f, 0x1000);
}

void UpdateItemBombState2(ItemBomb *e) {
    s32 t;

    t = e->mStateFrames;
    if (GrowItemObjectScale(e, data_0217bd50, data_0217bd54) != 0) {
        func_020f9fa8(&e->mUnk_000.mItemObject);
    }
    if (t < 0x16) {
        return;
    }
    if (t == 0x16) {
        e->mUnk_16c = TRUE;
    } else if (t == 0x2a) {
        FreeItemObjectCollisionSlot((s32) e);
    }
    if (t <= 0x55) {
        return;
    }
    ReleaseItemPoolObject(gItemPools + e->mUnk_000.mItemObject.mKind, &e->mUnk_000.mItemObject);
}

void func_020fde18(ItemBomb *e) {
    u32 v1;
    u16 v2;
    Kart *p;
    Vec3 v;
    s32 d;
    s32 x;
    s32 y;
    s32 z;

    v1 = (u16) GetRaceUpdateFramesMod8();
    if (v1 >= gRaceSetup->mKartCount) {
        return;
    }
    v2 = (e->mUnk_000.mItemObject.mUnk_78 & 0x8000) == 0 ? (u16) (e->mUnk_000.mItemObject.mUnk_78 & ~0xff00) : 8;
    if (v1 == v2) {
        return;
    }
    p = GetKart(v1);
    if (func_0206c0e0(p) != 0) {
        return;
    }
    if (e->mUnk_17c < 8) {
        GetKartPos(&v, e->mUnk_178);
        x = (e->mUnk_000.mItemObject.mPos.x - v.x) >> 12;
        y = (e->mUnk_000.mItemObject.mPos.y - v.y) >> 12;
        z = (e->mUnk_000.mItemObject.mPos.z - v.z) >> 12;
        d = x * x + y * y + z * z;
        e->mUnk_17c = d;
    }
    v = p->mDrawMatrixPos;
    x = (e->mUnk_000.mItemObject.mPos.x - v.x) >> 12;
    y = (e->mUnk_000.mItemObject.mPos.y - v.y) >> 12;
    z = (e->mUnk_000.mItemObject.mPos.z - v.z) >> 12;
    d = x * x + y * y + z * z;
    if (d < e->mUnk_17c) {
        e->mUnk_178 = v1;
        e->mUnk_17c = d;
    }
}

void func_020fdd78(ItemBomb *e) {
    if (e->mUnk_17c > (data_0217bd58 << 6)) {
        return;
    }
    if (e->mUnk_17c > (data_0217bd58 << 4)) {
        if (e->mUnk_170 > data_0217bd4c) {
            e->mUnk_170 = data_0217bd4c;
        }
        return;
    }
    if (e->mUnk_17c > (data_0217bd58 << 2)) {
        if (e->mUnk_170 > (data_0217bd4c >> 1)) {
            e->mUnk_170 = data_0217bd4c >> 1;
        }
        return;
    }
    if (e->mUnk_17c > data_0217bd58) {
        if (e->mUnk_170 > (data_0217bd4c >> 2)) {
            e->mUnk_170 = data_0217bd4c >> 2;
        }
        return;
    }
    if (e->mUnk_170 > 4) {
        e->mUnk_170 = 4;
        e->mUnk_174 = 3;
    }
}

void func_020fdc08(ItemBomb *e, ItemBomb *b, Unk021052fc *c) {
    Unk021052fc *v1;

    b->mUnk_000.mItemObject.mDistanceSquaredAndFlags |= data_02159f2c;
    AdvanceStateMachine(&e->mUnk_184);
    if (c->mUnk_00.mFlags & 0x100) {
        e->mUnk_198 = NULL;
        ReleaseItemPoolObject(gItemPools + e->mUnk_000.mItemObject.mKind, &e->mUnk_000.mItemObject);
        return;
    }
    if ((b->mUnk_000.mItemObject.mFlags & 0x8000) == 0) {
        c->mUnk_00.mPos = b->mUnk_000.mItemObject.mPos;
        c->mUnk_00.mPos.y += e->mUnk_19c - b->mUnk_000.mItemObject.mUnk_dc;
    }
    if (e->mUnk_170 <= 0) {
        if ((b->mUnk_000.mItemObject.mFlags & 0x8000) == 0) {
            return;
        }
        e->mUnk_198 = NULL;
        ReleaseItemPoolObject(gItemPools + e->mUnk_000.mItemObject.mKind, &e->mUnk_000.mItemObject);
        return;
    }
    e->mUnk_170--;
    if (e->mUnk_170 < c->mUnk_00.mAlpha) {
        c->mUnk_00.mAlpha = e->mUnk_170;
    }
    if (e->mUnk_170 < 0x10) {
        c->mUnk_00.mFlags |= data_02159f18;
    }
    if (e->mUnk_170 == 0) {
        v1 = e->mUnk_198;
        v1->mUnk_00.mFlags &= ~1;
        ParkMapObject(&v1->mUnk_00);
        e->mUnk_198 = NULL;
        ReleaseItemPoolObject(gItemPools + e->mUnk_000.mItemObject.mKind, &e->mUnk_000.mItemObject);
    }
}

void AdvanceItemBomb(ItemBomb *e) {
    if (e->mUnk_198 != NULL) {
        func_020fdc08(e, e, e->mUnk_198);
        return;
    }
    AdvanceStateMachine(&e->mUnk_184);
    if ((e->mUnk_000.mItemObject.mFlags & 0x80000) || e->mUnk_170 < 0) {
        func_020f7104(&e->mUnk_000.mItemObject, 1);
    }
    e->mUnk_170--;
    if (e->mUnk_180 > 0) {
        e->mUnk_180--;
        if (e->mUnk_170 == 0) {
            e->mUnk_170 = 0x10;
        }
    }
    if (e->mUnk_000.mBouncesRemaining >= 3) {
        return;
    }
    if (e->mUnk_130 == 0 && e->mUnk_000.mBouncesRemaining >= 2) {
        return;
    }
    if ((e->mUnk_000.mItemObject.mUnk_78 & 0x8000) == 0) {
        func_020fde18(e);
        if (e->mUnk_180 == 0) {
            func_020fdd78(e);
        }
    }
    if (e->mUnk_170 >= 0xd2) {
        return;
    }
    e->mUnk_174--;
    if (e->mUnk_174 > 0) {
        return;
    }
    e->mUnk_174 = e->mUnk_170 >> 2;
    if (e->mUnk_174 < 8) {
        e->mUnk_174 = 8;
    }
}

void *func_020fda50(void *a, ItemBomb *b, void *c) {
    void *r;

    if (b != NULL && c != NULL) {
        func_020ff1b8(b->mUnk_130, &b->mUnk_000.mItemObject.mVelocity.y);
    }
    r = func_020fecdc(a, b, c);
    r = func_020fefe8(r, b != NULL ? &b->mUnk_134 : 0, c);
    if (b != NULL && c == NULL) {
        func_020ff1a0(b->mUnk_000.mItemObject.mVelocity.y, &b->mUnk_130);
    }
    if (b != NULL && c != NULL) {
        return func_020fe8ac(b->mUnk_000.mItemObject.mKind);
    }
    return r;
}

void InitItemBombFromData(ItemBomb *e) {
    func_020f8e78(e);
    StartItemObjectBouncing(&e->mUnk_000, e->mUnk_130 != 0 ? 3 : 2);
    func_02046be8(&e->mUnk_184, (UnkFunc *const *) gItemBombStateTable, 4, e);
    if (!(e->mUnk_000.mItemObject.mFlags & 0x10000000)) {
        return;
    }
    if (e->mUnk_130 == 0) {
        return;
    }
    StartSound(&e->mUnk_000.mItemObject.mSoundSource, 0xda, 0x7f, 0);
}

void DrawItemBomb(ItemBomb *e, Vec3 *a, Unk020e6488 *b) {
    if (e->mUnk_1a0 == FALSE) {
        return;
    }
    if (e->mState != 2) {
        if (e->mUnk_174 != 0 && e->mUnk_174 < 6) {
            b->mFrameIndex = 1;
        } else {
            b->mFrameIndex = 0;
        }
        DrawItemObjectModel(&e->mUnk_000.mItemObject, b, a);
        return;
    }
    if (e->mUnk_138 == NULL) {
        return;
    }
    e->mUnk_138->mVisible = (e->mUnk_000.mItemObject.mFlags & 0x10000) == 0;
}

int RequestItemBombState2(ItemBomb *e) {
    if (e->mState != 2) {
        func_02046be8(&e->mUnk_184, (UnkFunc *const *) gItemBombStateTable, 4, e);
        e->mNextState = 2;
        e->mNextStateRequested = 1;
        if ((e->mUnk_000.mItemObject.mFlags & 0x180000) == 0) {
            e->mUnk_000.mItemObject.mAdvance = (void (*)(ItemObject *)) AdvanceItemBomb;
        }
        e->mUnk_000.mItemObject.mFlags &= ~0x8000;
        e->mUnk_000.mItemObject.mFlags |= 0x80000;
        e->mUnk_000.mItemObject.mUnk_78 &= ~0x4000;
    }
    return 1;
}

void func_020fd83c(ItemBomb *e) {
    if (e->mUnk_000.mItemObject.mFlags & 0x80000) {
        return;
    }
    func_02046be8(&e->mUnk_184, (UnkFunc *const *) gItemBombStateTable, 4, e);
    if ((e->mUnk_000.mItemObject.mFlags & 0x180000) == 0) {
        e->mUnk_000.mItemObject.mAdvance = (void (*)(ItemObject *)) AdvanceItemBomb;
    }
    e->mNextState = 1;
    e->mNextStateRequested = 1;
    e->mUnk_180 = 0x10e;
    e->mUnk_130 = 0;
    e->mUnk_000.mBouncesRemaining = 0;
}

// Release hook of the bomb kind: parks its map object, if it has one.
void ParkItemBombMapObject(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 compareLeft0;
    u32 compareRight0;
    value0 = *(const u32 *) ((value0) + (408));
    compareLeft0 = value0;
    compareRight0 = 0u;
    if (compareLeft0 == compareRight0) {
    }
    if (compareLeft0 == compareRight0) {
    }
    if (compareLeft0 == compareRight0) {
        return;
    }
    value1 = *(const u16 *) ((value0) + (2));
    value1 = (value1) & ~(1u);
    *(u16 *) ((value0) + (2)) = value1;
    ParkMapObject((void *) value0);
}

u32 GetItemBombActiveCount(void) {
    return gItemPools[9].mActiveCount;
}

#pragma thumb off

ItemBomb *func_020fd7a4(int a) {
    ItemBomb *e;
    u32 f;

    e = (ItemBomb *) gItemPools[9].mObjects[a];
    f = e->mUnk_000.mItemObject.mFlags;
    if ((f & 0x8000) && (f & 0x180000) == 0 && e->mState != 3 && e->mUnk_198 == NULL) {
        return e;
    }
    return NULL;
}

void func_020fd754(void *a) {
    ItemBomb *e;

    e = a;
    e->mUnk_000.mItemObject.mFlags &= ~0x8000;
    if ((e->mUnk_000.mItemObject.mFlags & 0x180000) == 0) {
        e->mUnk_000.mItemObject.mAdvance = NULL;
    }
    FreeItemObjectCollisionSlot((s32) e);
    e->mUnk_1a0 = FALSE;
    SetStateMachineState(&e->mUnk_184, 3);
    e->mUnk_174 = 0;
}

void func_020fd684(void *c, Vec3 *d, Vec3 *f) {
    ItemBomb *e;
    Vec3 *a;
    Vec3 *b;
    Unk021052fc *v1;

    e = c;
    a = d;
    b = f;
    if (e->mUnk_198 == NULL) {
        e->mUnk_1a0 = TRUE;
        SetCourseColorBlendColor(e->mUnk_000.mItemObject.mColorBlend.mUnk_00, 1);
    }
    if (a != NULL) {
        e->mUnk_000.mItemObject.mNormal = *a;
        e->mUnk_000.mItemObject.mFlags |= 0x80;
    }
    if (b == NULL) {
        return;
    }
    e->mUnk_000.mItemObject.mPos = *b;
    VEC_Subtract(&e->mUnk_000.mItemObject.mPos, &e->mUnk_000.mItemObject.mPrevPos, &e->mUnk_000.mItemObject.mVelocity);
    if (e->mUnk_198 == NULL) {
        return;
    }
    e->mUnk_198->mUnk_00.mPos = *b;
    e->mUnk_198->mUnk_00.mPos.y += e->mUnk_19c;
    v1 = e->mUnk_198;
    v1->mUnk_00.mFlags &= ~2;
    v1->mUnk_00.mFlags &= ~8;
    v1->mUnk_00.mAlpha = 0x1f;
}

void func_020fd540(void **b, Vec3 *v, s32 a) {
    ItemBomb *e;
    Unk021052fc *v1;

    e = *b;
    v1 = e->mUnk_198;
    e->mUnk_000.mItemObject.mUnk_78 |= data_02159f28;
    if (v1 == NULL) {
        CreateItemObjectCollisionSlot(e);
        e->mUnk_1a0 = TRUE;
    }
    func_020f9114(e);
    func_02046be8(&e->mUnk_184, (UnkFunc *const *) gItemBombStateTable, 4, e);
    SetStateMachineState(&e->mUnk_184, 0);
    e->mUnk_170 = 0x12c;
    e->mUnk_174 = 0;
    e->mUnk_178 = 8;
    e->mUnk_17c = 0x5f592e1;
    e->mUnk_180 = 0;
    e->mUnk_16c = FALSE;
    e->mUnk_134 = 0xccd;
    e->mUnk_170 = a;
    e->mUnk_130 = 1;
    InitBouncingItem(&e->mUnk_000, 3, v);
    if ((e->mUnk_000.mItemObject.mFlags & 0x180000) == 0) {
        e->mUnk_000.mItemObject.mAdvance = (void (*)(ItemObject *)) AdvanceItemBomb;
    }
    if (v1 != NULL) {
        v1->mUnk_00.mFlags &= ~2;
        v1->mUnk_00.mFlags &= ~8;
        v1->mUnk_00.mAlpha = 0x1f;
        v1->mUnk_00.mFlags &= ~4;
        if (v1->mUnk_00.mKind != MAP_OBJECT_KIND_KURIBO) {
            v1->mUnk_00.mFlags &= ~1;
        }
    }
    *b = NULL;
}

BOOL IsItemBombState2(Kart *a) {
    ItemBomb *e;

    e = (ItemBomb *) a;
    return e->mState == 2;
}

void ReleaseItemBomb(void **a) {
    ItemBomb *e;
    Unk021052fc *v1;

    e = *a;
    SetStateMachineState(&e->mUnk_184, 0);
    v1 = e->mUnk_198;
    if (v1 != NULL) {
        v1->mUnk_00.mFlags &= ~1;
        ParkMapObject(&v1->mUnk_00);
        e->mUnk_198 = NULL;
        ReleaseItemPoolObject(gItemPools + e->mUnk_000.mItemObject.mKind, &e->mUnk_000.mItemObject);
    } else {
        ReleaseItemPoolObject(gItemPools + e->mUnk_000.mItemObject.mKind, &e->mUnk_000.mItemObject);
    }
    *a = NULL;
}

void *StartItemBomb(void) {
    ItemBomb *e;

    e = StartItemObjectOrZero(9, 8, data_02159f40, data_02159f40);
    if (e == NULL) {
        return NULL;
    }
    if ((e->mUnk_000.mItemObject.mFlags & 0x180000) == 0) {
        e->mUnk_000.mItemObject.mAdvance = NULL;
    }
    FreeItemObjectCollisionSlot((s32) e);
    e->mUnk_1a0 = FALSE;
    SetStateMachineState(&e->mUnk_184, 3);
    e->mUnk_174 = 0;
    return e;
}

void *StartItemBombWithMapObject(void *b, s32 a) {
    ItemBomb *e;
    Unk021052fc *v1;

    v1 = b;
    e = StartItemObjectOrZero(9, 8, data_02159f40, data_02159f40);
    if (e == NULL) {
        e = NULL;
    } else {
        if ((e->mUnk_000.mItemObject.mFlags & 0x180000) == 0) {
            e->mUnk_000.mItemObject.mAdvance = NULL;
        }
        FreeItemObjectCollisionSlot((s32) e);
        e->mUnk_1a0 = FALSE;
        SetStateMachineState(&e->mUnk_184, 3);
        e->mUnk_174 = 0;
    }
    if (e == NULL) {
        return NULL;
    }
    UnparkMapObject(&v1->mUnk_00);
    v1->mUnk_00.mFlags |= data_02159f18;
    v1->mUnk_00.mFlags |= data_02159f1c;
    v1->mUnk_00.mFlags |= data_02159f20;
    v1->mUnk_00.mFlags |= data_02159f24;
    e->mUnk_198 = v1;
    e->mUnk_19c = a;
    return e;
}

Vec3 *func_020fd308(ItemBomb *e, s32 *a, s32 *b) {
    *a = e->mStateFrames;
    *b = ((s64) e->mUnk_000.mItemObject.mScale.z * data_0217bd48) >> 12;
    return &e->mUnk_000.mItemObject.mPos;
}

#pragma thumb on

void func_020fd264(void) {
    s32 k;

    data_0217bd50 = 0x18006;
    data_0217bd48 = FX_Div(0x1000, 0x18006);
    data_0217bd54 = 0x2148;
    data_0217bd58 = ((s64) data_0217bd50 * gItemKinds[9].mUnk_6c) >> 12;
    data_0217bd58 >>= 12;
    data_0217bd58 *= data_0217bd58;
    k = gRaceSetup->mEngineIndex;
    switch (k) {
        case 0:
            data_0217bd4c = 0xb4;
            break;
        case 1:
            data_0217bd4c = 0x96;
            break;
        default:
            data_0217bd4c = 0x78;
            break;
    }
}

#pragma thumb off
