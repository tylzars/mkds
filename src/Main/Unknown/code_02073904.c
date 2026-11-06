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
    Unk020f41c4_B *r;
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
        Vec3Sub(&p->mPos, &p->mLookAt, &d);
        l = func_02073904_inline(&d, &d);
        if (l != 0) {
            k = data_usa_021656a8;
            r = &gRaceProgress->mLocalRandom;
            r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
            s = (s32) (((s64) data_usa_021656ac * l) >> 12);
            h = (s16) (u16) (r->mUnk_00 >> 52);
            s = (s32) (((s64) (s + 0x1000) * data_usa_021656c8) >> 12);
            m = (s32) (((s64) s * ((h - 0x800) * 2)) >> 12);
            a.x = (s32) (((s64) p->mSide.x * m) >> 12);
            a.y = (s32) (((s64) p->mSide.y * m) >> 12);
            a.z = (s32) (((s64) p->mSide.z * m) >> 12);
            r = &gRaceProgress->mLocalRandom;
            r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
            h = (s16) (u16) (r->mUnk_00 >> 52);
            m = (s32) (((s64) s * ((h - 0x800) * 2)) >> 12);
            b.x = (s32) (((s64) p->mUp.x * m) >> 12);
            b.y = (s32) (((s64) p->mUp.y * m) >> 12);
            b.z = (s32) (((s64) p->mUp.z * m) >> 12);
            Vec3Add(&a, &b, &p->mShakeLookAtOffsetGoal);
            r = &gRaceProgress->mLocalRandom;
            r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
            h = (s16) (u16) (r->mUnk_00 >> 52);
            m = (s32) (((s64) k * ((h - 0x800) * 2)) >> 12);
            a.x = (s32) (((s64) p->mSide.x * m) >> 12);
            a.y = (s32) (((s64) p->mSide.y * m) >> 12);
            a.z = (s32) (((s64) p->mSide.z * m) >> 12);
            r = &gRaceProgress->mLocalRandom;
            r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
            h = (s16) (u16) (r->mUnk_00 >> 52);
            m = (s32) (((s64) k * ((h - 0x800) * 2)) >> 12);
            b.x = (s32) (((s64) p->mUp.x * m) >> 12);
            b.y = (s32) (((s64) p->mUp.y * m) >> 12);
            b.z = (s32) (((s64) p->mUp.z * m) >> 12);
            Vec3Add(&a, &b, &p->mShakePosOffsetGoal);
        }
    }
    s = data_usa_021656b0;
    Vec3Sub(&p->mShakePosOffsetGoal, &p->mShakePosOffset, &e);
    e.x = (s32) (((s64) e.x * s) >> 12);
    e.y = (s32) (((s64) e.y * s) >> 12);
    e.z = (s32) (((s64) e.z * s) >> 12);
    Vec3Add(&p->mShakePosOffset, &e, &p->mShakePosOffset);
    s = data_usa_021656a4;
    Vec3Sub(&p->mShakeLookAtOffsetGoal, &p->mShakeLookAtOffset, &f);
    f.x = (s32) (((s64) f.x * s) >> 12);
    f.y = (s32) (((s64) f.y * s) >> 12);
    f.z = (s32) (((s64) f.z * s) >> 12);
    Vec3Add(&p->mShakeLookAtOffset, &f, &p->mShakeLookAtOffset);
    i = -data_usa_021656cc[p->mShakeKind - 1];
    g.x = (s32) (((s64) p->mShakeLookAtOffset.x * i) >> 12);
    g.y = (s32) (((s64) p->mShakeLookAtOffset.y * i) >> 12);
    g.z = (s32) (((s64) p->mShakeLookAtOffset.z * i) >> 12);
    Vec3Add(&g, &p->mShakeLookAtCounterOffset, &p->mShakeLookAtCounterOffset);
    s = data_usa_021656bc;
    p->mShakeLookAtCounterOffset.x = (s32) (((s64) p->mShakeLookAtCounterOffset.x * s) >> 12);
    p->mShakeLookAtCounterOffset.y = (s32) (((s64) p->mShakeLookAtCounterOffset.y * s) >> 12);
    p->mShakeLookAtCounterOffset.z = (s32) (((s64) p->mShakeLookAtCounterOffset.z * s) >> 12);
}
