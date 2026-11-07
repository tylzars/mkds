#include "ITCM/code_01ffad14.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/unk_02154000.h"

void func_01ffb0cc(Kart *p) {
    p->mUnk_4fc = p->mUnk_4fc + 1;
    if (p->mUnk_4fc >= 8) {
        p->mUnk_4fc = 0;
    }
    p->mUnk_4f0.x = data_02154b64[p->mUnk_4fc];
    p->mUnk_4f0.y = data_02154b84[p->mUnk_4fc];
    p->mUnk_4f0.z = data_02154ba4[p->mUnk_4fc];
}

s32 LimitKartForwardSpeedAndGetScaled(Kart *p) {
    BOOL v1;
    s32 a = p->mForwardSpeed;
    s32 c;
    s32 g;
    s32 b;
    u32 f = p->mUnk_48;

    v1 = a < 0;

    a = a > 0 ? a : -a;
    b = p->mUnk_274;
    c = p->mSpeedLimit - b;
    if ((f & 4) && (p->mUnk_44 & 0x100)) {
        if (c > 0x3000) {
            c = 0x3000;
        }
    }
    g = p->mMapObjectVectorLength +
        (b + (s32) ((s64) c * (s32) ((s64) p->mSpeedLimitHitFactor * p->mUnk_394 >> 12) >> 12));
    if (a > g) {
        p->mForwardSpeed = g;
    } else {
        if (a <= (s32) (p->mSpeedLimitHitFactor * (s64) 0x19a >> 12) && !(p->mUnk_44 & 0x80000) && !(f & 6)) {
            p->mForwardSpeed = 0;
        } else {
            p->mForwardSpeed = a;
        }
    }
    if (v1) {
        p->mForwardSpeed *= -1;
    }
    g = p->mMapObjectVectorForwardDot;
    if (g != 0) {
        if (g > 0) {
            a = p->mForwardSpeed;
            if (a < 0) {
                p->mForwardSpeed = a + g;
                if (p->mForwardSpeed > p->mMapObjectVectorForwardDot) {
                    p->mForwardSpeed = p->mMapObjectVectorForwardDot;
                }
            } else {
                a = a > 0 ? a : -a;
                c = g > 0 ? g : -g;
                if (c > a) {
                    p->mForwardSpeed = g;
                }
            }
        } else {
            a = p->mForwardSpeed;
            if (a > 0) {
                p->mForwardSpeed = a + g;
                if (p->mForwardSpeed < p->mMapObjectVectorForwardDot) {
                    p->mForwardSpeed = p->mMapObjectVectorForwardDot;
                }
            } else {
                a = a > 0 ? a : -a;
                c = g > 0 ? g : -g;
                if (c > a) {
                    p->mForwardSpeed = g;
                }
            }
        }
    }
    return ((s64) p->mForwardSpeed * (0x1000 - (p->mUnk_274 >> 3)) + 0x800) >> 12;
}

void ScaleKartVelocityAndSetCappedLengthAndDirection(Kart *p, s32 a) {
    s32 r;

    p->mVelocity.x = (s64) p->mVelocity.x * a >> 12;
    r = 0;
    p->mVelocity.y = (s64) p->mVelocity.y * a >> 12;
    p->mVelocity.z = (s64) p->mVelocity.z * a >> 12;
    if ((s64) p->mVelocity.x * p->mVelocity.x + (s64) p->mVelocity.y * p->mVelocity.y +
            (s64) p->mVelocity.z * p->mVelocity.z >=
        0x10) {
        r = Vec3NormalizeAndGetLengthUnchecked(&p->mVelocity, &p->mVelocityDirection);
    }
    p->mVelocityLength = r;
    if (p->mVelocityLength > 0xd000) {
        p->mVelocityLength = 0xd000;
        p->mVelocity.x = (s64) p->mVelocityDirection.x * 0xd000 >> 12;
        p->mVelocity.y = (s64) p->mVelocityDirection.y * 0xd000 >> 12;
        p->mVelocity.z = (s64) p->mVelocityDirection.z * 0xd000 >> 12;
    }
}

void AdvanceKartQuaternionFromVector(Kart *p, Vec3 *a) {
    Vec4 v;
    Vec4 w;
    Vec4 *q = &p->mUnk_100_q;
    s32 r;

    r = TryQuaternionFromVectors(&v, &data_02154f7c, a);
    TryQuaternionFromVectors(&w, &p->mGroundNormal, a);
    QuaternionMultiply(&w, q, q);
    if (r != 0) {
        if ((v.w < 0 && q->w > 0) || (v.w > 0 && q->w < 0)) {
            q->x = -v.x;
            q->y = 0;
            q->z = -v.z;
            q->w = -v.w;
            p->mUnk_48 = p->mUnk_48 | 0x80000000;
        } else {
            q->x = v.x;
            q->y = 0;
            q->z = v.z;
            q->w = v.w;
            p->mUnk_48 = p->mUnk_48 & ~0x80000000;
        }
    }
    QuaternionNormalize(q, q);
}
