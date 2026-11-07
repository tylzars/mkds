#include "Main/Unknown/code_020fcf10.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020ee684.h"

void func_020fcf10(ItemKouraW *p0, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    Vec3 t;
    Vec3 *v;
    Vec3 *v1;
    Vec3 *v2;
    Kart *p;
    s32 s;

    p = p0->mKartItems->mKart;
    p0->mUnk_22c = p->mSignedTurnedForward;
    v1 = &p0->mUnk_000.mPos;
    v2 = &p0->mUnk_000.mVelocity;
    v = &p0->mUnk_238;
    if (p->mUnk_44 & 0x100) {
        p0->mUnk_22c.x = -p0->mUnk_22c.x;
        p0->mUnk_22c.y = -p0->mUnk_22c.y;
        p0->mUnk_22c.z = -p0->mUnk_22c.z;
    }
    Vec3CrossUnrounded(&p0->mUnk_22c, &p->mGroundNormal, &t);
    s = ((s64) c * gPairsByAngle[(b >> 4) * 2 + 1]) >> 12;
    p0->mUnk_250.x = ((s64) t.x * s) >> 12;
    p0->mUnk_250.y = ((s64) t.y * s) >> 12;
    p0->mUnk_250.z = ((s64) t.z * s) >> 12;
    s = ((s64) c * gPairsByAngle[(b >> 4) * 2]) >> 12;
    VEC_MultAdd(s, &p0->mUnk_22c, &p0->mUnk_250, &p0->mUnk_250);
    VEC_MultAdd(0x1e000, &p0->mUnk_22c, &p0->mUnk_250, &t);
    if (func_0206c0b0(p) == FALSE) {
        p0->mUnk_244 = p->mDrawMatrixPos;
    }
    VEC_Add(&t, &p0->mUnk_244, &t);
    VEC_Subtract(&t, v1, v);
    t.x = ((s64) v->x * d) >> 12;
    t.y = ((s64) v->y * d) >> 12;
    t.z = ((s64) v->z * d) >> 12;
    if ((s64) t.x * t.x + (s64) t.y * t.y + (s64) t.z * t.z >= (s64) a * a) {
        if ((s64) t.x * t.x + (s64) t.y * t.y + (s64) t.z * t.z >= 0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&t, &t);
        }
        t.x = ((s64) t.x * a) >> 12;
        t.y = ((s64) t.y * a) >> 12;
        t.z = ((s64) t.z * a) >> 12;
    }
    v2->x = (v2->x * (s32) e + t.x) >> f;
    v2->y = (v2->y * (s32) e + t.y) >> f;
    v2->z = (v2->z * e + t.z) >> f;
    VEC_Add(v2, v1, v1);
    if (func_01ffdee4(v1, &p0->mUnk_000.mPrevPos, 0, p0->mUnk_000.mUnk_dc, 4, p0->mUnk_000.mCollisionSlotIndex, &t,
                      NULL, NULL, NULL, NULL, NULL, NULL, NULL) == 0) {
        return;
    }
    if ((p->mUnk_48 & 1) == 0) {
        v1->y += t.y;
        return;
    }
    VEC_Add(v1, &t, v1);
}
