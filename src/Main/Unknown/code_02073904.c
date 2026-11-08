#include "Main/Unknown/code_02073904.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020f36d8.h"
#include "code_02147cd8.h"

static inline s32 func_02073904_inline(Vec3 *v, Vec3 *n) {
    if ((s64) v->x * v->x + (s64) v->y * v->y + (s64) v->z * v->z < 0x10) {
        return 0;
    }
    return Vec3NormalizeAndGetLengthUnchecked(v, n);
}

void UpdateCameraShake(Unk02073904 *p) {
    RandomState64 *r;
    Vec3 a;
    Vec3 b;
    Vec3 d;
    Vec3 g;
    Vec3 e;
    Vec3 f;
    s32 l;
    s32 k;
    s32 h;
    s32 m;
    s32 s;
    s32 i;

    if (GetRaceUpdateFramesMod2() == 0) {
        VEC_Subtract(&p->mPos, &p->mLookAt, &d);
        l = func_02073904_inline(&d, &d);
        if (l != 0) {
            k = data_usa_021656a8;
            r = &gRaceProgress->mLocalRandom;
            r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
            s = ((s64) data_usa_021656ac * l) >> 12;
            h = (s16) (u16) (r->mValue >> 52);
            s = ((s64) (s + 0x1000) * data_usa_021656c8) >> 12;
            m = ((s64) s * ((h - 0x800) * 2)) >> 12;
            a.x = ((s64) p->mSide.x * m) >> 12;
            a.y = ((s64) p->mSide.y * m) >> 12;
            a.z = ((s64) p->mSide.z * m) >> 12;
            r = &gRaceProgress->mLocalRandom;
            r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
            h = (s16) (u16) (r->mValue >> 52);
            m = ((s64) s * ((h - 0x800) * 2)) >> 12;
            b.x = ((s64) p->mUp.x * m) >> 12;
            b.y = ((s64) p->mUp.y * m) >> 12;
            b.z = ((s64) p->mUp.z * m) >> 12;
            VEC_Add(&a, &b, &p->mShakeLookAtOffsetGoal);
            r = &gRaceProgress->mLocalRandom;
            r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
            h = (s16) (u16) (r->mValue >> 52);
            m = ((s64) k * ((h - 0x800) * 2)) >> 12;
            a.x = ((s64) p->mSide.x * m) >> 12;
            a.y = ((s64) p->mSide.y * m) >> 12;
            a.z = ((s64) p->mSide.z * m) >> 12;
            r = &gRaceProgress->mLocalRandom;
            r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
            h = (s16) (u16) (r->mValue >> 52);
            m = ((s64) k * ((h - 0x800) * 2)) >> 12;
            b.x = ((s64) p->mUp.x * m) >> 12;
            b.y = ((s64) p->mUp.y * m) >> 12;
            b.z = ((s64) p->mUp.z * m) >> 12;
            VEC_Add(&a, &b, &p->mShakePosOffsetGoal);
        }
    }
    s = data_usa_021656b0;
    VEC_Subtract(&p->mShakePosOffsetGoal, &p->mShakePosOffset, &e);
    e.x = ((s64) e.x * s) >> 12;
    e.y = ((s64) e.y * s) >> 12;
    e.z = ((s64) e.z * s) >> 12;
    VEC_Add(&p->mShakePosOffset, &e, &p->mShakePosOffset);
    s = data_usa_021656a4;
    VEC_Subtract(&p->mShakeLookAtOffsetGoal, &p->mShakeLookAtOffset, &f);
    f.x = ((s64) f.x * s) >> 12;
    f.y = ((s64) f.y * s) >> 12;
    f.z = ((s64) f.z * s) >> 12;
    VEC_Add(&p->mShakeLookAtOffset, &f, &p->mShakeLookAtOffset);
    i = -data_usa_021656cc[p->mShakeKind - 1];
    g.x = ((s64) p->mShakeLookAtOffset.x * i) >> 12;
    g.y = ((s64) p->mShakeLookAtOffset.y * i) >> 12;
    g.z = ((s64) p->mShakeLookAtOffset.z * i) >> 12;
    VEC_Add(&g, &p->mShakeLookAtCounterOffset, &p->mShakeLookAtCounterOffset);
    s = data_usa_021656bc;
    p->mShakeLookAtCounterOffset.x = ((s64) p->mShakeLookAtCounterOffset.x * s) >> 12;
    p->mShakeLookAtCounterOffset.y = ((s64) p->mShakeLookAtCounterOffset.y * s) >> 12;
    p->mShakeLookAtCounterOffset.z = ((s64) p->mShakeLookAtCounterOffset.z * s) >> 12;
}
