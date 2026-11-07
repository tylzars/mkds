#include "Main/Unknown/code_020f49bc.h"

#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0208ab98.h"
#include "Main/Unknown/code_020f73fc.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0208a000.h"
#include "Main/Unknown/code_020f7000.h"
#include "Main/Unknown/code_020f9000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f2dac.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02104a0c.h"
#include "Main/Unknown/code_020f4000.h"
#include "Main/Unknown/code_020f6000.h"
#include "Main/Unknown/code_020f9c40.h"
#include "Main/Unknown/code_020fa000.h"
#include "Main/Unknown/code_02109000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_020fe4b4.h"
#include "Main/Unknown/code_0210a598.h"
#include "Main/Unknown/code_0210a67c.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_02069000.h"
#include "Main/Unknown/code_020ff000.h"
#include "Main/Unknown/code_0210a000.h"
#include "Main/Unknown/code_020f1d70.h"
#include "Main/Unknown/code_020f1104.h"
#include "Main/Unknown/code_020f1258.h"
#include "Main/Unknown/code_020f1a14.h"
#include "Main/Unknown/code_020f2d98.h"
#include "Main/Unknown/code_0210b850.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_020ec8bc.h"
#include "Main/Unknown/code_020fe000.h"
#include "Main/Unknown/code_020f8000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020f5978.h"
#include "Main/Unknown/code_020f11f0.h"
#include "Main/Unknown/code_020f1180.h"
#include "Main/Unknown/code_020f5b74.h"
#include "Main/Unknown/code_020f5b84.h"
#include "Main/Unknown/code_020f5cc4.h"
#include "Main/Unknown/code_020f5d00.h"
#include "Main/Unknown/code_020f5d5c.h"
#include "Main/Unknown/code_020d3c94.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020d5000.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/code_0210e000.h"
#include "Main/Unknown/code_020e01f0.h"
#include "Main/Unknown/code_020f1000.h"
#include "Main/Unknown/code_020f82c4.h"
#include "Main/Unknown/code_020f92e8.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_02077bc0.h"

// The object has landed: it stops and is held at its rest point.
void StartRestingItemObject(ItemObject *a, void *b) {
    s32 t;
    enum { K0 } i;
    s32 k;

    VEC_MultAdd(-a->mUnk_dc, &a->mUnk_f0, &a->mPos, &a->mUnk_108);
    func_020d5aa0(b, a->mUnk_fc, a->mUnk_104, &a->mUnk_108, &a->mUnk_f0);
    if (a->mUnk_104->mUnk_00 != NULL && func_020e0448((Unk020e0448 *) a->mUnk_104) != 0) {
        a->mUnk_11a = 0xe10;
    } else {
        a->mUnk_11a = 0;
    }
    a->mFlags |= 0x8000;
    i = *(vs32 *) &a->mKind;
    if (gItemKinds[i].mUnk_44 == 0) {
        if (!(a->mFlags & 0x180000)) {
            a->mAdvance = AdvanceRestingItemObject;
        }
    }
    a->mUnk_124 = func_020f6830;
    i = a->mKind;
    k = gItemKinds[i].mUnk_7c;
    t = a->mVelocity.y;
    if (t <= 0) {
        t = -t;
    }
    a->mUnk_100 = -(s32) (((s64) t * k) >> 12);
    if (a->mUnk_100 < -0x5c3) {
        a->mUnk_100 = -0x5c3;
    }
    a->mVelocity.x = 0;
    a->mVelocity.y = 0;
    a->mVelocity.z = 0;
    func_020f90dc(a);
    func_020f0e2c(&gItemPools[*(vs32 *) &a->mKind], a);
    i = *(vs32 *) &a->mKind;
    func_020f91fc(a, gItemKinds[i].mUnk_9c);
}

void AdvanceRestingItemObject(ItemObject *a) {
    u32 w;

    if (a->mUnk_104->mUnk_00 != NULL) {
        if (func_020e04b0(a->mUnk_104, &a->mUnk_108, &a->mUnk_f0) != FALSE) {
            StartFallingItemObject(a);
        }
        if (a->mUnk_104->mUnk_00->mUnk_130 != FALSE) {
            if (a->mUnk_f0.y < 0xff4) {
                a->mFlags |= 0x80;
            }
        }
        VEC_MultAdd(a->mUnk_dc, &a->mUnk_f0, &a->mUnk_108, &a->mPos);
        if (a->mUnk_11a > 0) {
            a->mUnk_11a -= 1;
            if ((a->mUnk_48 & 7) != GetRaceUpdateFramesMod8()) {
                return;
            }
            if (func_01ffdee4(&a->mPos.x, NULL, 0, a->mUnk_dc, 0x44, a->mCollisionSlotIndex, NULL, NULL, NULL,
                              &a->mUnk_fc, NULL, NULL, NULL, &w) == 0) {
                return;
            }
            if (func_020d5a68(&w, a->mUnk_fc, a->mUnk_104) != FALSE) {
                a->mVelocity.x = 0;
                a->mVelocity.y = 0;
                a->mVelocity.z = 0;
                func_020f6fc4(a, 1);
            }
            if (!(a->mUnk_fc & 0x8000)) {
                return;
            }
            func_020f7070(a, 1);
        } else {
            VEC_Subtract(&a->mPos, &a->mPrevPos, &a->mVelocity);
        }
    } else {
        if (!(a->mFlags & 0x40)) {
            return;
        }
        VEC_MultAdd(a->mUnk_dc, &a->mUnk_f0, &a->mUnk_108, &a->mPos);
    }
}

void func_020f6830(ItemObject *a, Vec3 *b, Vec3 *c) {
    s32 d;
    s32 n;
    u32 i;

    d = a->mScale.z - a->mScale.y;
    if (d * d >= 0x68be1) {
        return;
    }
    n = Vec3DotUnrounded(b, c);
    if (n <= 0) {
        n = -n;
    }
    i = *(vs32 *) &a->mKind;
    a->mUnk_100 = ((s64) n * gItemKinds[i].mUnk_7c) >> 12;
    a->mUnk_100 = a->mUnk_100 >> 1;
}

void func_020f6630(ItemObject *a0, s32 b, Vec3 *c, Vec3 *d, Vec3 *e) {
    ItemObject *a;
    Vec3 v;
    Vec3 *p;
    s32 t;
    s32 n;
    u32 i;

    a = a0;
    p = &a->mVelocity;
    i = *(vs32 *) &a->mKind;
    t = gItemKinds[i].mUnk_80;
    if (gRaceSetup->mMode == MODE_TIME_ATTACK || (a->mFlags & 0x8000000)) {
        t = 0;
    }
    a->mFlags |= 0x4000;
    a->mUnk_78 |= data_02159b64;
    n = VEC_DotProduct(e, p);
    p->x -= (s32) (((s64) e->x * n) >> 12);
    p->y -= (s32) (((s64) e->y * n) >> 12);
    p->z -= (s32) (((s64) e->z * n) >> 12);
    n = Vec3DotUnrounded(d, e);
    if (n < 0) {
        n = 0;
    } else if (n > 0x1333) {
        n = 0x1333;
    }
    VEC_MultAdd(n + (t != 0 ? 0x2800 : 0x3800), e, p, p);
    if (b != 0) {
        VEC_Subtract(&a->mPos, c, &v);
        if ((s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z >= 0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&v, &v);
        }
        VEC_MultAdd(b * 0x14cd, &v, p, p);
    }
    if (t != 0) {
        if (!(a->mFlags & 0x180000)) {
            a->mAdvance = AdvanceFallingItemObject;
        }
        a->mUnk_124 = func_020f6388;
        a->mFlags &= ~0x7000000;
    } else {
        a->mFlags &= ~0x4000;
        func_020f7070(a, 1);
    }
}

void StartFallingItemObject(ItemObject *a) {
    u32 i;

    a->mFlags &= ~0x8000;
    a->mFlags |= 0x4000;
    i = *(vs32 *) &a->mKind;
    if (gItemKinds[i].mUnk_44 == 0) {
        if (!(a->mFlags & 0x180000)) {
            a->mAdvance = AdvanceFallingItemObject;
        }
    }
    a->mUnk_124 = func_020f6388;
    a->mFlags &= ~0x7000000;
}

void AdvanceFallingItemObject(ItemObject *a) {
    u32 w;
    Vec3 v1;
    Vec3 v2;
    Vec3 v3;
    Vec3 *q;
    Vec3 *p;

    q = &a->mPos;
    p = &a->mVelocity;

    VEC_Add(p, q, q);
    a->mVelocity.x = ((s64) a->mVelocity.x * 0xfec) >> 12;
    p->z = ((s64) p->z * 0xfec) >> 12;
    if (func_01ffdee4(q, &a->mPrevPos, 0, a->mUnk_dc, 0x44, a->mCollisionSlotIndex, &v1, &v2, (s32 *) &v3, &a->mUnk_fc,
                      NULL, NULL, NULL, &w) != 0) {
        VEC_Add(&v1, q, q);
        if (a->mUnk_fc & 0x1e34ef) {
            func_020f9334(a, q, p, 0x385, &v2);
        }
        if (a->mUnk_fc & 0x214300) {
            a->mFlags |= 0x20;
            func_020f92e8(p, &v3);
            if (func_020f9290(a, &v3) != FALSE) {
                return;
            }
        }
        if (a->mUnk_fc & 0x8000) {
            func_020f7070(a, 1);
            return;
        }
    }
    a->mFlags &= ~0x4000000;
    if (!(a->mUnk_fc & 0x1e34ef)) {
        p->y -= 0x385;
        if (p->y < -0xa000) {
            p->y = -0xa000;
        }
    }
    if (!(a->mFlags & 8)) {
        return;
    }
    if (a->mFlags & 3) {
        return;
    }
    StartRestingItemObject(a, &w);
}

void func_020f6388(ItemObject *a, Vec3 *b, Vec3 *c) {
    func_020f92e8(&a->mVelocity, c);
    if (a->mFlags & 0x1000000) {
        return;
    }
    a->mFlags |= 0x1000000;
    a->mUnk_108.x = 0;
    a->mUnk_108.y = 0;
    a->mUnk_108.z = 0;
}

void StartItemThunder(ItemInUse *a, HeldItem *b) {
    NNSSndSeqPlayer **p;

    if (data_0217c780 & 1) {
        p = func_0210e128(func_02108ea0(0));
        if (data_0217d084.mUnk_0c != 0) {
            if (*p != NULL) {
                NNS_SndPlayerStopSeq(p, 0);
            }
            if (*p != NULL) {
                NNS_SndPlayerStopSeq(p, 0);
            }
            NNS_SndArcPlayerStartSeqArc(p, 0, 0xde);
        }
    }
    func_02069e10(b->mKartItems->mKart);
    func_020d3cc8();
    func_020f82e8(0);
    RemoveHeldItemObjects(b, 1);
    if (gRaceSetup->mMode != 5) {
        return;
    }
    func_020fe958(6);
}

void StartItemStar(ItemInUse *a, HeldItem *b) {
    StartKartStar(b->mKartItems->mKart);
    RemoveHeldItemObjects(b, 1);
    if (gRaceSetup->mMode != 5) {
        return;
    }
    func_020fe958(4);
}

void StartItemKouraGSound(void *a0, s32 b) {
    ItemKouraG *a;

    a = a0;
    if (!(a->mUnk_000.mUnk_000.mFlags & 0x400000)) {
        return;
    }
    func_0210b7ec(&a->mUnk_16c, a->mUnk_000.mUnk_000.mUnk_d4 & ~0xc000001f);
    StartSoundWhileRequested(&a->mUnk_000.mUnk_000.mSoundSource, 0xd7, 0x7f, 0);
}

BOOL InitItemKouraG(ItemInUse *a, ItemKouraG *b) {
    BOOL v;

    v = gRaceSetup->mMode == MODE_BATTLE;
    func_020f9114(b);
    func_0210b850(&b->mUnk_16c);
    b->mUnk_000.mUnk_000.mSoundSource.mUnk_30 = (void (*)(void *, void *, void *)) func_0210a77c;
    if (a->mKartItems->mFlags & 0x20) {
        func_020f2b94(b, a, v != FALSE ? 2 : 4, 0, 0, 0x5000);
        return FALSE;
    }
    func_020f2b94(b, a, v != FALSE ? 5 : 9, 1, 0, 0x5000);
    return TRUE;
}

void AdvanceItemKouraG(ItemKouraG *a) {
    if (a->mUnk_000.mUnk_000.mAgeFrames > 0x258) {
        a->mUnk_000.mUnk_154 = 0;
    }
    func_020f2228(&a->mUnk_000, 0x84cd);
    if (a->mUnk_000.mUnk_000.mFlags & 1) {
        return;
    }
    func_0210ddf4(&data_0217d294, (a->mUnk_000.mUnk_000.mUnk_d4 & ~0xc000001f) + 0x9c40, StartItemKouraGSound, a, 0);
}

void *func_020f6038(void *a, ItemKouraG *b, void *c) {
    void *p;

    if (b != NULL && c != NULL) {
        func_020ff1b8(Vec3DotUnrounded(&b->mUnk_000.mUnk_000.mVelocity, &b->mUnk_000.mUnk_130) < 0,
                      &b->mUnk_000.mUnk_000.mVelocity.y);
    }
    p = func_020fecdc(a, b, c);
    if (b != NULL && c == NULL) {
        func_020ff1a0(b->mUnk_000.mUnk_000.mVelocity.y, &b->mUnk_168);
    }
    if (b != NULL && c != NULL) {
        return func_020fe8ac(b->mUnk_000.mUnk_000.mKind);
    }
    return p;
}

void InitItemKouraGFromData(ItemKouraG *a) {
    func_020f8e78(a);
    func_0210b850(&a->mUnk_16c);
    a->mUnk_000.mUnk_000.mSoundSource.mUnk_30 = (void (*)(void *, void *, void *)) func_0210a77c;
    func_020f1ea4(a, 9, a->mUnk_168, 0);
}

void StartItemKouraRSound(void *a0, s32 b) {
    ItemKouraR *a;

    a = a0;
    if (!(a->mUnk_000.mUnk_000.mUnk_000.mFlags & 0x400000)) {
        return;
    }
    func_0210b7ec(&a->mUnk_258, a->mUnk_000.mUnk_000.mUnk_000.mUnk_d4 & ~0xc000001f);
    StartSoundWhileRequested(&a->mUnk_000.mUnk_000.mUnk_000.mSoundSource, 0xd8, 0x7f, 0);
}

void func_020f5f7c(ItemKouraR *a, Vec3 *b, Vec3 *c) {
    func_020f29e8(a);
    func_020f1f98(&a->mUnk_000.mUnk_000, b, c);
    a->mStateMachine.mNextState = 1;
    a->mStateMachine.mNextStateRequested = 1;
}

// Called when an object is taken off the kart item list: sets up its state machine and first state.
s32 InitItemKouraR(ItemInUse *a, ItemKouraR *b) {
    u16 x;
    u16 v;
    u16 n;

    func_020f9114(b);
    func_0210b850(&b->mUnk_258);
    b->mUnk_000.mUnk_000.mUnk_000.mSoundSource.mUnk_30 = (void (*)(void *, void *, void *)) func_0210a77c;
    func_02046be8(&b->mStateMachine, (UnkFunc *const *) gItemKouraRStateTable, 7, b);
    if (a->mKartItems->mFlags & 0x20) {
        b->mThrowForward = 0;
        func_020f2b94(b, a, 0, 0, 0, 0x5000);
        b->mStateMachine.mNextState = 1;
        b->mStateMachine.mNextStateRequested = 1;
        b->mUnk_000.mUnk_21c.mLink = NULL;
        b->mUnk_000.mUnk_21c.mNextLinksUsed = 1;
    } else {
        b->mThrowForward = 1;
        if (gRaceSetup->mMode != MODE_BATTLE && a->mKartItems->mUnk_1f0.mLink != NULL) {
            x = !(b->mUnk_000.mUnk_000.mUnk_000.mUnk_78 & 0x8000)
                    ? (u16) (b->mUnk_000.mUnk_000.mUnk_000.mUnk_78 & ~0xff00)
                    : 8;
            if (x >= 8) {
                v = 8;
            } else {
                n = GetKartRank(x) - 1;
                if (n < 1) {
                    n = gRaceSetup->mKartCount;
                }
                v = gRaceProgress->mKartAtRank[(u8) n - 1];
            }
            func_020ed268(&b->mUnk_000, a, 0x2d, 0x5b, 1, 0, 1, 0x5000, v, 0);
            b->mStateMachine.mNextState = 3;
            b->mStateMachine.mNextStateRequested = 1;
        } else {
            func_020f2b94(b, a, 0, 1, 0, 0x5000);
            b->mStateMachine.mNextState = 2;
            b->mStateMachine.mNextStateRequested = 1;
            b->mUnk_000.mUnk_21c.mLink = NULL;
            b->mUnk_000.mUnk_21c.mNextLinksUsed = 1;
        }
        b->mUnk_000.mUnk_000.mUnk_000.mFlags |= 0x200000;
    }
    func_020f1a14(b);
    if (b->mUnk_000.mUnk_000.mUnk_000.mFlags & 0x8000000) {
        b->mStateMachine.mNextState = 0;
        b->mStateMachine.mNextStateRequested = 1;
    }
    return b->mThrowForward;
}

void AdvanceItemKouraR(u32 arg0) {
    u32 value0 = arg0;
    u32 value12;
    value0 = (value0) + (0x23cu);
    AdvanceStateMachine((void *) value0);
}

void UpdateItemKouraRState0And1(ItemKouraR *a) {
    func_020f2228(&a->mUnk_000.mUnk_000, 0x8800);
    if (a->mUnk_000.mUnk_000.mUnk_000.mFlags & 1) {
        return;
    }
    func_0210ddf4(&data_0217d294, a->mUnk_000.mUnk_000.mUnk_000.mUnk_d4 & ~0xc000001f, StartItemKouraRSound, a, 0);
}

void func_020f5cc4(ItemObject *arg0, u32 arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = arg1;
    u32 value2;
    u32 value3;
    u32 value4;
    u32 compareLeft0;
    u32 compareRight0;
    value4 = value0;
    value3 = *(const s16 *) ((value4) + (218));
    value2 = ~(0u);
    compareLeft0 = value3;
    compareRight0 = value2;
    if (compareLeft0 == compareRight0) {
    }
    if (compareLeft0 == compareRight0) {
        return;
    }
    func_020f1150(value0, value1);
    value0 = (value4) + (0x200u);
    value1 = 4u;
    *(u16 *) ((value0) + (76)) = value1;
    value1 = 1u;
    *(u16 *) ((value0) + (78)) = value1;
}

void UpdateItemKouraRState2(ItemKouraR *a) {
    func_020f2228(&a->mUnk_000.mUnk_000, 0x8800);
    if (!(a->mUnk_000.mUnk_000.mUnk_000.mFlags & 1)) {
        func_0210ddf4(&data_0217d294, a->mUnk_000.mUnk_000.mUnk_000.mUnk_d4 & ~0xc000001f, StartItemKouraRSound, a, 0);
    }
    if (a->mUnk_000.mUnk_000.mUnk_000.mFlags & 1) {
        return;
    }
    if (a->mStateMachine.mStateFrames > 0x10) {
        if (func_020f11f0(a, 0) == 0) {
            return;
        }
        a->mStateMachine.mNextState = 4;
        a->mStateMachine.mNextStateRequested = 1;
        if (!(a->mUnk_000.mUnk_000.mUnk_000.mFlags & 0x8000000)) {
            return;
        }
        func_020fe71c(1, a->mKartItems->mKartIndex, a->mUnk_000.mUnk_000.mUnk_000.mId);
        return;
    }
    if (a->mStateMachine.mStateFrames > 4) {
        if (func_020f1180(a, 0) == FALSE) {
            return;
        }
        a->mStateMachine.mNextState = 4;
        a->mStateMachine.mNextStateRequested = 1;
        if (!(a->mUnk_000.mUnk_000.mUnk_000.mFlags & 0x8000000)) {
            return;
        }
        func_020fe71c(1, a->mKartItems->mKartIndex, a->mUnk_000.mUnk_000.mUnk_000.mId);
    }
}

void EnterItemKouraRState3(ItemKouraR *p0) {
    p0->mUnk_000.mUnk_000.mUnk_000.mUnk_124 = (void (*)(ItemObject *, Vec3 *, Vec3 *)) func_020f5f7c;
}

void UpdateItemKouraRState3(ItemKouraR *a) {
    u16 x;
    u16 v;
    u16 n;

    x = !(a->mUnk_000.mUnk_000.mUnk_000.mUnk_78 & 0x8000) ? (u16) (a->mUnk_000.mUnk_000.mUnk_000.mUnk_78 & ~0xff00) : 8;
    if (x >= 8) {
        v = 8;
    } else {
        n = GetKartRank(x) - 1;
        if (n < 1) {
            n = gRaceSetup->mKartCount;
        }
        v = gRaceProgress->mKartAtRank[(u8) n - 1];
    }
    func_020ec918(&a->mUnk_000, 0xd000, 0x29, v, 0);
    if (!(a->mUnk_000.mUnk_000.mUnk_000.mFlags & 1)) {
        func_0210ddf4(&data_0217d294, a->mUnk_000.mUnk_000.mUnk_000.mUnk_d4 & ~0xc000001f, StartItemKouraRSound, a, 0);
    }
    if (a->mUnk_000.mUnk_000.mUnk_000.mFlags & 1) {
        return;
    }
    if (a->mStateMachine.mStateFrames > 0x708) {
        func_020f29e8(a);
        a->mStateMachine.mNextState = 1;
        a->mStateMachine.mNextStateRequested = 1;
        return;
    }
    if (a->mStateMachine.mStateFrames > 0x10) {
        if (func_020f11f0(a, 1) == 0) {
            return;
        }
        a->mStateMachine.mNextState = 4;
        a->mStateMachine.mNextStateRequested = 1;
        if (!(a->mUnk_000.mUnk_000.mUnk_000.mFlags & 0x8000000)) {
            return;
        }
        func_020fe71c(1, a->mKartItems->mKartIndex, a->mUnk_000.mUnk_000.mUnk_000.mId);
        return;
    }
    if (a->mStateMachine.mStateFrames > 4) {
        if (func_020f1180(a, 1) == FALSE) {
            return;
        }
        a->mStateMachine.mNextState = 4;
        a->mStateMachine.mNextStateRequested = 1;
        if (!(a->mUnk_000.mUnk_000.mUnk_000.mFlags & 0x8000000)) {
            return;
        }
        func_020fe71c(1, a->mKartItems->mKartIndex, a->mUnk_000.mUnk_000.mUnk_000.mId);
    }
}

void EnterItemKouraRState4(ItemKouraR *p0) {
    p0->mUnk_000.mUnk_000.mUnk_000.mUnk_124 = (void (*)(ItemObject *, Vec3 *, Vec3 *)) func_020f5f7c;
}

// Runs the two 0x7c/0x4c checks of the object in the 0x1fc word of the 0x1c pointer, then
// one of the four func_020f14a0 calls, and stores the 0x24c/0x24e halfwords it picks.
void UpdateItemKouraRState4(ItemKouraR *a) {
    KartItems *o;
    Kart *b;
    BOOL d;
    u32 c;
    s32 n;

    o = a->mKartItems;
    b = o->mKart;
    c = *(u32 *) &b->mUnk_7c;
    d = TRUE;
    if ((c & 0x402020) == 0) {
        if ((b->mUnk_4c & 0x800) == 0) {
            d = FALSE;
        }
    }
    if (d != FALSE) {
        func_020f1104(a);
        a->mStateMachine.mNextState = 6;
        a->mStateMachine.mNextStateRequested = 1;
    } else {
        n = a->mUnk_000.mUnk_000.mUnk_000.mFlags;
        if (n & 0x10000000) {
            if (c & 1) {
                n = func_020f14a0(a, 0x5333, 0x19a, 1);
            } else {
                n = func_020f14a0(a, 0x4b33, 0x19a, 0);
            }
        } else {
            n = func_020f14a0(a, 0x4800, 0x19a, (n & 0x8000000) == 0);
        }
        if (n != 0) {
            func_020f1104(a);
            a->mStateMachine.mNextState = 2;
            a->mStateMachine.mNextStateRequested = 1;
            a->mUnk_000.mUnk_21c.mLink = NULL;
            a->mUnk_000.mUnk_21c.mNextLinksUsed = 1;
        }
    }
    if (a->mUnk_000.mUnk_000.mUnk_000.mFlags & 1) {
        return;
    }
    func_0210ddf4(&data_0217d294, a->mUnk_000.mUnk_000.mUnk_000.mUnk_d4 & ~0xc000001f, StartItemKouraRSound, a, 0);
}

// Checks func_0206c0e0 of the 0x1fc object, then the 0x240 counter and the sum of the two
// squares of the 0x50/0x54/0x58 differences against the 0x1d0/0x1d4/0x1e0 square.
void UpdateItemKouraRState5(ItemKouraR *a) {
    KartItems *o;
    Kart *k;
    s32 n;
    s32 r;
    s32 t;

    o = a->mKartItems;
    k = o->mKart;
    if (func_0206c0e0(k) != FALSE) {
        func_020f6f10(&a->mUnk_000.mUnk_000.mUnk_000, 0, 8);
    } else {
        func_020f14a0(a, 0x10000, 0x333, 0);
    }
    if ((a->mUnk_000.mUnk_000.mUnk_000.mFlags & 1) == 0) {
        func_0210ddf4(&data_0217d294, a->mUnk_000.mUnk_000.mUnk_000.mUnk_d4 & ~0xc000001f, StartItemKouraRSound, a, 0);
    }
    if (a->mStateMachine.mStateFrames <= 0x14) {
        r = k->mRadius + ((a->mUnk_000.mUnk_000.mUnk_000.mRadius * 3) >> 1);
        n = a->mUnk_000.mUnk_000.mUnk_000.mPos.z - k->mUnk_1d8.z;
        t = a->mUnk_000.mUnk_000.mUnk_000.mPos.x - k->mUnk_1d8.x;
        if ((s64) t * t + (s64) n * n >= (s64) r * r) {
            return;
        }
    }
    func_020f6f10(&a->mUnk_000.mUnk_000.mUnk_000, 0, 8);
}

// Runs func_020f2228 and hands StartItemKouraRSound to func_0210ddf4 when the 0x74 bit 0 is clear.
void UpdateItemKouraRState6(ItemKouraR *a) {
    func_020f2228(&a->mUnk_000.mUnk_000, 0xc000);
    if (a->mUnk_000.mUnk_000.mUnk_000.mFlags & 1) {
        return;
    }
    func_0210ddf4(&data_0217d294, a->mUnk_000.mUnk_000.mUnk_000.mUnk_d4 & ~0xc000001f, StartItemKouraRSound, a, 0);
}

// Runs func_0210a598 with the 0x3bc word of the 0x1fc object when the 0x78 high bits of the
// third parameter match that object's 0x74 halfword and the 0x74/0x78/0xdc tests pass.
void func_020f5614(void *a0, s32 b, ItemObject *c0) {
    ItemKouraR *a;
    ItemObject *c;
    KartItems *o;
    Kart *k;
    u16 n;
    u32 f;

    a = a0;
    c = c0;
    if ((u32) (b - 1) > 1) {
        return;
    }
    o = a->mKartItems;
    n = !(c->mUnk_78 & 0x8000) ? (u16) (c->mUnk_78 & ~0xff00) : 8;
    if (o == NULL) {
        return;
    }
    k = o->mKart;
    if (n != *(u16 *) &k->mIndex) {
        return;
    }
    f = c->mFlags;
    if ((f & 0x1000) == 0) {
        if ((f & 0x2000) == 0) {
            return;
        }
        if ((c->mUnk_78 & 0x1000) == 0) {
            return;
        }
        if (c->mAgeFrames >= 0x78) {
            return;
        }
    }
    func_0210a598(k, k->mUnk_3cc);
}

// Hands the 0x44 word and the 0x5c/0x130/0x250/0x254/0x60/0x54 addresses of b to
// func_020fecdc, func_020ff040, func_020ff1b8, func_020ff1a0 and func_020fe8ac.
void *func_020f5550(void *a, ItemKouraR *b, void *c) {
    s32 dot;
    void *p;

    if (b != NULL && c != NULL) {
        dot = Vec3DotUnrounded(&b->mUnk_000.mUnk_000.mUnk_000.mVelocity, &b->mUnk_000.mUnk_000.mUnk_130);
        func_020ff1b8(dot < 0, &b->mUnk_000.mUnk_000.mUnk_000.mVelocity.y);
        func_020ff1b8(b->mThrowForward, &b->mUnk_000.mUnk_000.mUnk_000.mPos.y);
    }
    p = func_020fecdc(a, b, c);
    p = func_020ff040(p, b != NULL ? &b->mUnk_000.mUnk_21c : 0, c);
    if (b != NULL && c == NULL) {
        func_020ff1a0(b->mUnk_000.mUnk_000.mUnk_000.mVelocity.y, &b->mUnk_250);
        func_020ff1a0(b->mUnk_000.mUnk_000.mUnk_000.mPos.y, &b->mThrowForward);
    }
    if (b != NULL && c != NULL) {
        return func_020fe8ac(b->mUnk_000.mUnk_000.mUnk_000.mKind);
    }
    return p;
}

// Stores func_0210a77c in the 0x30 word, moves the seven words of gItemKouraRStateTable to 0x23c,
// then picks one of three calls from the 0x254/0x21c words.
void InitItemKouraRFromData(ItemKouraR *a) {
    u16 x;
    u32 n;
    u16 v;
    u16 i;

    func_020f8e78(a);
    func_0210b850(&a->mUnk_258);
    a->mUnk_000.mUnk_000.mUnk_000.mSoundSource.mUnk_30 = (void (*)(void *, void *, void *)) func_0210a77c;
    func_02046be8(&a->mStateMachine, (UnkFunc *const *) gItemKouraRStateTable, 7, a);
    if (a->mThrowForward != 0) {
        if (a->mUnk_000.mUnk_21c.mLink != NULL) {
            a->mStateMachine.mNextState = 3;
            a->mStateMachine.mNextStateRequested = 1;
            x = !(a->mUnk_000.mUnk_000.mUnk_000.mUnk_78 & 0x8000)
                    ? (u16) (a->mUnk_000.mUnk_000.mUnk_000.mUnk_78 & ~0xff00)
                    : 8;
            if (x >= 8) {
                v = 8;
            } else {
                n = GetKartRank(x);
                i = n - 1;
                if (i < 1) {
                    i = gRaceSetup->mKartCount;
                }
                v = gRaceProgress->mKartAtRank[(i & 0xff) - 1];
            }
            func_020ec8bc(&a->mUnk_000, 0x2d, 0x5b, 0, 1, a->mUnk_250, v, 0);
        } else {
            a->mStateMachine.mNextState = 2;
            a->mStateMachine.mNextStateRequested = 1;
            func_020f1ea4(a, 0, a->mUnk_250, 0);
        }
        a->mUnk_000.mUnk_000.mUnk_000.mFlags |= 0x200000;
    } else {
        a->mStateMachine.mNextState = 1;
        a->mStateMachine.mNextStateRequested = 1;
        func_020f1ea4(a, 0, a->mUnk_250, 0);
    }
    func_020f1a14(a);
}

// Returns 1 while GetKart(b) is within the 0x1d0/0x1d4 radius of the 0x50/0x54/0x58
// words, or when the 0xda halfword is -1; otherwise sets the 0x24c/0x24e halfwords, returns 0.
BOOL func_020f5324(void *a0, s32 b) {
    ItemKouraR *a;
    Kart *k;
    s32 n;
    s32 r;
    s32 t;

    a = a0;
    k = GetKart(b);
    r = k->mRadius + ((a->mUnk_000.mUnk_000.mUnk_000.mRadius * 3) >> 1);
    n = a->mUnk_000.mUnk_000.mUnk_000.mPos.z - k->mUnk_1d8.z;
    t = a->mUnk_000.mUnk_000.mUnk_000.mPos.x - k->mUnk_1d8.x;
    if ((s64) t * t + (s64) n * n < (s64) r * r) {
        return TRUE;
    }
    if (a->mUnk_000.mUnk_000.mUnk_000.mCollisionSlotIndex == -1) {
        return TRUE;
    }
    func_020f9c40((s32) a);
    a->mStateMachine.mNextState = 5;
    a->mStateMachine.mNextStateRequested = 1;
    func_020f112c(a, b);
    return FALSE;
}

// Runs func_020f9114, ors data_02159834 into the 0x78 halfword, then makes one of two
// ThrowBouncingItem calls depending on the 0x1ec halfword of the 0x0c pointer, and returns the
// 0x130 word it stores.
s32 InitItemBanana(ItemInUse *a, ItemBanana *b) {
    KartItems *o;
    s32 n;

    func_020f9114(b);
    b->mUnk_000.mItemObject.mUnk_78 |= data_02159834;
    o = a->mKartItems;
    if (o->mFlags & KART_ITEMS_THROW_FORWARD) {
        ThrowBouncingItem(&b->mUnk_000, a, 0, 1, 0x4000, 0x3000, 0x59a);
        StartSound(&b->mUnk_000.mItemObject.mSoundSource, 0xda, 0x7f, 0);
        b->mThrowForward = 1;
        return b->mThrowForward;
    }
    ThrowBouncingItem(&b->mUnk_000, a, 0, 0, 0x4000, 0x3000, 0x59a);
    b->mThrowForward = 0;
    return b->mThrowForward;
}

// Calls AdvanceBouncingItem with one of two pairs of numbers, and when the 0x74 bits allow it
// doubles the 0x60 word and runs StopSound and StartRestingItemObject.
void AdvanceItemBanana(ItemBanana *a) {
    u32 v;
    u32 n;

    if (a->mThrowForward != 0) {
        AdvanceBouncingItem(&a->mUnk_000, 0x1ec, 0xfec, 0, &v);
    } else {
        AdvanceBouncingItem(&a->mUnk_000, 0x2e1, 0xf85, 0, &v);
    }
    n = a->mUnk_000.mItemObject.mFlags;
    if ((n & 8) == 0) {
        return;
    }
    if (n & 3) {
        return;
    }
    if (a->mThrowForward != 0) {
        a->mUnk_000.mItemObject.mVelocity.y = a->mUnk_000.mItemObject.mVelocity.y * 2;
    }
    StopSound(&a->mUnk_000.mItemObject.mSoundSource, 0xda);
    StartRestingItemObject(&a->mUnk_000.mItemObject, &v);
}

// Hands the 0x130 word and the 0x60 word to func_020ff1b8/func_020ff1a0 around the
// func_020fecdc call, and returns func_020fe8ac's value when b and c are both set.
void *func_020f5108(void *a, ItemBanana *b, void *c) {
    void *p;

    if (b != NULL && c != NULL) {
        func_020ff1b8(b->mThrowForward, &b->mUnk_000.mItemObject.mVelocity.y);
    }
    p = func_020fecdc(a, b, c);
    if (b != NULL && c == NULL) {
        func_020ff1a0(b->mUnk_000.mItemObject.mVelocity.y, &b->mThrowForward);
    }
    if (b != NULL && c != NULL) {
        return func_020fe8ac(b->mUnk_000.mItemObject.mKind);
    }
    return p;
}

// Runs func_020f8e78 and func_020f2d98, then StartSound when the two 0x74/0x130 tests pass.
void InitItemBananaFromData(ItemBanana *a) {
    func_020f8e78(a);
    func_020f2d98(&a->mUnk_000, 0);
    if ((a->mUnk_000.mItemObject.mFlags & 0x10000000) == 0) {
        return;
    }
    if (a->mThrowForward == 0) {
        return;
    }
    StartSound(&a->mUnk_000.mItemObject.mSoundSource, 0xda, 0x7f, 0);
}

// Item hook of the mushroom: starts the kart boost, uses up one held object, marks the use,
// and makes the event call when the mode is 5.
void StartItemKinokoBoost(ItemInUse *a, HeldItem *b) {
    func_02069db8(b->mKartItems->mKart);
    RemoveHeldItemObjects(b, 1);
    a->mKartItems->mUnk_204 = TRUE;
    if (gRaceSetup->mMode != 5) {
        return;
    }
    func_020fe958(3);
}

void ResetItemKinoko(ItemKinoko *p0) {
    p0->mVisible = TRUE;
}

#pragma thumb off

// Runs func_020ed5c0 with the last two parameters swapped when the 0x134 word is set.
void DrawItemKinoko(ItemKinoko *a, void *b, void *c) {
    if (a->mVisible == FALSE) {
        return;
    }
    func_020ed5c0(&a->mUnk_000.mItemObject, c, b);
}

// Decreases the 0x130 word by one; when it goes below zero func_020f7658 runs first.
void AdvanceRestingItemKinoko(ItemKinoko *a) {
    a->mTimer--;
    if (a->mTimer < 0) {
        func_020f7658(&a->mUnk_000.mItemObject, 0);
    }
    AdvanceRestingItemObject(&a->mUnk_000.mItemObject);
}

// Sets the object up through AdvanceBouncingItem when the 0x74 word allows it.
void AdvanceBouncingItemKinoko(ItemKinoko *a) {
    u32 n;

    AdvanceBouncingItem(&a->mUnk_000, 0x385, 0xff8, 0x733, &n);
    if ((a->mUnk_000.mItemObject.mFlags & 8) == 0) {
        return;
    }
    if ((a->mUnk_000.mItemObject.mFlags & 3) != 0) {
        return;
    }
    StopSound(&a->mUnk_000.mItemObject.mSoundSource, 0xda);
    StartRestingItemObject(&a->mUnk_000.mItemObject, &n);
    if ((a->mUnk_000.mItemObject.mFlags & 0x180000) == 0) {
        a->mUnk_000.mItemObject.mAdvance = (void (*)(ItemObject *)) AdvanceRestingItemKinoko;
    }
}

// Returns what StartItemObjectOrZero gives, with its 0x134 and 0x130 words cleared.
ItemKinoko *StartItemKinokoOrZero(void) {
    ItemKinoko *p;

    p = StartItemObjectOrZero(3, 8, &data_02159764, &data_02159764);
    if (p == NULL) {
        return NULL;
    }
    if ((p->mUnk_000.mItemObject.mFlags & 0x180000) == 0) {
        p->mUnk_000.mItemObject.mAdvance = NULL;
    }
    func_020f9c40((s32) p);
    p->mVisible = FALSE;
    p->mTimer = 0;
    return p;
}

// Stores the two Vec3s in the object and sets the word at 0x80.
void func_020f4e78(ItemKinoko *a, Vec3 *b, Vec3 *c) {
    a->mVisible = TRUE;
    func_0208ad74(&a->mUnk_000.mItemObject.mUnk_7c, 1);
    if (b != NULL) {
        a->mUnk_000.mItemObject.mUnk_f0 = *b;
        a->mUnk_000.mItemObject.mFlags |= 0x80;
    }
    if (c == NULL) {
        return;
    }
    a->mUnk_000.mItemObject.mPos = *c;
    VEC_Subtract(&a->mUnk_000.mItemObject.mPos, &a->mUnk_000.mItemObject.mPrevPos, &a->mUnk_000.mItemObject.mVelocity);
}

// Runs the object's first word and stores the 0x120 and 0x130 words.
void StartBouncingItemKinoko(void **a, Vec3 *b, s32 c) {
    ItemKinoko *p;

    p = a[0];
    p->mUnk_000.mItemObject.mUnk_78 |= data_0215969c;
    CreateItemObjectCollisionSlot(p);
    func_020f9114(p);
    InitBouncingItem(&p->mUnk_000, 0, b);
    if ((p->mUnk_000.mItemObject.mFlags & 0x180000) == 0) {
        p->mUnk_000.mItemObject.mAdvance = (void (*)(ItemObject *)) AdvanceBouncingItemKinoko;
    }
    p->mTimer = c;
    a[0] = NULL;
}

#pragma thumb on

// Fills a table of eighteen 0x1c-byte objects allocated here.
void CreateItemInfos(void) {
    ItemInfo *p;
    s32 i;

    p = HeapAlloc(GetHeap(func_020364e8()), 0x1f8);
    gItemInfos = p;
    p[0] = data_02159918;
    p[1] = data_02159838;
    p[2] = data_02159770;
    p[3] = data_02159f68;
    p[4] = data_021596a0;
    p[5] = data_02159664;
    p[6] = data_02159e54;
    p[7] = data_02159cc0;
    p[8] = data_02159aa0;
    p[9] = data_02159f4c;
    p[10] = data_02159680;
    p[11] = data_021598fc;
    p[12] = data_021599dc;
    p[13] = data_02159d90;
    p[14] = gItemInfoKiller;
    p[15] = data_0215a2ec;
    p[16] = data_0215a174;
    p[17] = data_0215a4c0;
    switch (gRaceSetup->mMode) {
        case MODE_BATTLE:
            p[17].mEnabled = TRUE;
            break;
        case 5:
            for (i = 0; i < 0x12; i++) {
                if (gItemInfos[(u32) i].mEnabled != FALSE && gItemInfos[(u32) i].mUnk_04 == 0) {
                    gItemInfos[i].mEnabled = FALSE;
                }
            }
            break;
    }
    if (gRaceSetup->mRaceKind == RACE_KIND_DEMO) {
        gItemInfos[15].mEnabled = FALSE;
    }
}

#pragma thumb off

void InitHeldItem(HeldItem *a, KartItems *b) {
    s32 i;

    a->mKartItems = b;
    a->mItemInfoIndex = 0x13;
    a->mObjectCount = 0;
    a->mObjectStartFramesLeft = 0;
    a->mUnk_0c = 0;
    a->mTimer = 0;
    a->mUnk_12 = 0;
    for (i = 0; i < 3; i++) {
        a->mObjects[i] = NULL;
    }
    a->mUnk_24 = gRaceSetup->mCurrentEntries[b->mKartIndex].mPlayer.mKind == PLAYER_KIND_PEER;
}

// Starts one held object at counts 7, 5 and 3 of the countdown that StartHeldItemObjects sets.
void StartNextHeldItemObject(HeldItem *a) {
    ItemObject *e;
    Kart *p;
    Vec3 *q;
    Vec3 *r;
    void (*h)(void *);
    s32 i;
    enum { K0 } k;

    if (a->mObjectStartFramesLeft <= 0) {
        return;
    }
    a->mObjectStartFramesLeft--;
    if (a->mObjectStartFramesLeft != 7 && a->mObjectStartFramesLeft != 5 && a->mObjectStartFramesLeft != 3) {
        return;
    }
    p = a->mKartItems->mKart;
    a->mObjectCount--;
    e = a->mObjects[a->mObjectCount];
    q = &p->mUnk_98;
    r = &p->mVelocity;
    StartItemObject(gItemPools + e->mKind, e);
    func_020efd1c(a->mKartItems, e);
    VEC_MultAdd(0xb33, r, &e->mVelocity, &e->mVelocity);
    *(Vec3 *) &e->mPos = *q;
    func_020f6630(e, 0, q, r, &p->mUnk_244);
    k = e->mKind;
    h = gItemKinds[k].mUnk_38;
    if (h != NULL) {
        h(e);
    }
    if (a->mObjectCount != 0) {
        return;
    }
    a->mItemInfoIndex = 0x13;
    a->mObjectCount = 0;
    a->mObjectStartFramesLeft = 0;
    a->mUnk_0c = 0;
    a->mTimer = 0;
    a->mUnk_12 = 0;
    for (i = 0; i < 3; i++) {
        a->mObjects[i] = NULL;
    }
}
