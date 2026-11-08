#include "Main/Unknown/code_020f1d70.h"

#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_020f6000.h"
#include "Main/Unknown/code_020f6be8.h"
#include "Main/Unknown/code_020f7000.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_02109054.h"
#include "code_02147cd8.h"

void InitItemObjectThrow(void *objectParam, ItemInUse *inUseParam, s32 hitLimit, s32 throwForward, s32 e,
                         s32 baseSpeed) {
    DirectedItemObject *object;
    ItemInUse *inUse;
    s32 dot;
    s32 negatedZ;
    s32 directionX;

    object = objectParam;
    inUse = inUseParam;
    if (throwForward != 0) {
        object->mSpeed = ComputeItemThrowForward(inUse, baseSpeed, 0x1000, 0x3800, &object->mDirection);
    } else {
        Vec3 *direction = &object->mDirection;
        object->mSpeed = ComputeItemThrowBackward(inUse, 0x3000, 0x1000, 0x4000, direction);
    }
    object->mSurfaceDirection = object->mDirection;
    negatedZ = -object->mDirection.z;
    directionX = object->mDirection.x;
    object->mSideDirection.z = directionX;
    object->mSideDirection.x = negatedZ;
    object->mSideDirection.y = 0;
    object->mUnk_000.mVelocity.x = ((s64) object->mDirection.x * object->mSpeed) >> 12;
    object->mUnk_000.mVelocity.z = ((s64) object->mDirection.z * object->mSpeed) >> 12;
    if (throwForward == 0) {
        VEC_Add(&object->mUnk_000.mVelocity, &inUse->mKart->mUnk_1fc, &object->mUnk_000.mVelocity);
    }
    if (inUse->mKart->mUnk_48 & 1) {
        dot = VEC_DotProduct(&inUse->mKartOrientation.mUnk_0c, &object->mUnk_000.mVelocity);
        {
            s32 alongX, alongY, alongZ;

            alongX = ((s64) inUse->mKartOrientation.mUnk_0c.x * dot) >> 12;
            alongY = ((s64) inUse->mKartOrientation.mUnk_0c.y * dot) >> 12;
            alongZ = ((s64) inUse->mKartOrientation.mUnk_0c.z * dot) >> 12;
            object->mUnk_000.mVelocity.x = (s32) (object->mUnk_000.mVelocity.x - alongX);
            object->mUnk_000.mVelocity.y -= alongY;
            object->mUnk_000.mVelocity.z -= alongZ;
        }
        VEC_MultAdd(-0x1000, &inUse->mKartOrientation.mUnk_0c, &object->mUnk_000.mVelocity,
                    &object->mUnk_000.mVelocity);
    }
    if (object->mUnk_000.mScale.z < 0xccd) {
        object->mUnk_000.mScale.x = 0xccd;
        object->mUnk_000.mScale.y = 0xccd;
        object->mUnk_000.mScale.z = 0xccd;
        if (throwForward != 0) {
            object->mUnk_000.mPos = inUse->mKart->mCollisionCenter;
            VEC_MultAdd(object->mUnk_000.mScale.z * 10, &inUse->mKartOrientation.mUnk_18, &object->mUnk_000.mPos,
                        &object->mUnk_000.mPos);
        }
    }
    if (hitLimit < 0) {
        object->mHitsRemaining = 0;
        object->mHasHitLimit = FALSE;
    } else {
        object->mHitsRemaining = hitLimit;
        object->mHasHitLimit = TRUE;
    }
    object->mUnk_000.mBounce = (void (*)(ItemObject *, Vec3 *, Vec3 *)) DeflectItemObjectOnHit;
    object->mUnk_160 = TRUE;
    object->mUnk_158 = e;
    object->mUnk_164 = 4;
}

void func_020f2a6c(Vec3 *direction, Vec3 *normal, Vec3 *result) {
    s32 n;

    n = normal->y * normal->y;
    if (n < 0x10) {
        result->x = -direction->x;
        result->y = -direction->y;
        result->z = -direction->z;
        return;
    }
    result->x = normal->x >> 2;
    result->y = normal->y >> 2;
    result->z = normal->z >> 2;
    result->x = direction->x - result->x;
    result->z = direction->z - result->z;
    n = (s32) (((s64) direction->x * normal->x) >> 12) + (s32) (((s64) direction->z * normal->z) >> 12);
    result->y = -(n + result->y);
    result->y = FX_Div(result->y, normal->y);
    if ((s64) result->x * result->x + (s64) result->y * result->y + (s64) result->z * result->z >= 0x10) {
        Vec3NormalizeAndGetLengthUnchecked(result, result);
    }
}

void func_020f29e8(ItemKouraR *item) {
    DirectedItemObject *object;
    Vec3 *normal;
    s32 speed;

    object = (DirectedItemObject *) item;
    speed = 0;
    normal = &object->mUnk_000.mNormal;
    if ((s64) object->mUnk_000.mVelocity.x * object->mUnk_000.mVelocity.x +
            (s64) object->mUnk_000.mVelocity.y * object->mUnk_000.mVelocity.y +
            (s64) object->mUnk_000.mVelocity.z * object->mUnk_000.mVelocity.z >=
        0x10) {
        speed = Vec3NormalizeAndGetLengthUnchecked(&object->mUnk_000.mVelocity, &object->mDirection);
    }
    object->mSpeed = speed;
    func_020f2a6c(&object->mDirection, normal, &object->mSurfaceDirection);
    Vec3CrossUnrounded(&object->mSurfaceDirection, normal, &object->mSideDirection);
    object->mUnk_000.mBounce = (void (*)(ItemObject *, Vec3 *, Vec3 *)) DeflectItemObjectOnHit;
}

void func_020f288c(DirectedItemObject *object, Vec3 *hitNormal) {
    Vec3 along;
    Vec3 *velocityDirection;
    Vec3 *flatDirection;
    s32 n;

    velocityDirection = &object->mSurfaceDirection;
    flatDirection = &object->mDirection;
    n = VEC_DotProduct(hitNormal, velocityDirection);
    along.x = ((s64) hitNormal->x * n) >> 12;
    along.y = ((s64) hitNormal->y * n) >> 12;
    along.z = ((s64) hitNormal->z * n) >> 12;
    object->mSurfaceDirection.x -= along.x;
    velocityDirection->y -= along.y;
    velocityDirection->z -= along.z;
    if (object->mUnk_160 != FALSE) {
        VEC_Subtract(velocityDirection, &along, velocityDirection);
    }
    if ((s64) velocityDirection->x * velocityDirection->x + (s64) velocityDirection->y * velocityDirection->y +
            (s64) velocityDirection->z * velocityDirection->z >=
        0x10) {
        Vec3NormalizeAndGetLengthUnchecked(velocityDirection, velocityDirection);
    }
    n = velocityDirection->z;
    flatDirection->x = velocityDirection->x;
    flatDirection->y = 0;
    flatDirection->z = n;
    if ((s64) flatDirection->x * flatDirection->x + (s64) flatDirection->y * flatDirection->y +
            (s64) flatDirection->z * flatDirection->z >=
        0x10) {
        Vec3NormalizeAndGetLengthUnchecked(flatDirection, flatDirection);
    }
    Vec3CrossUnrounded(flatDirection, &object->mUnk_000.mNormal, &object->mSideDirection);
    StartSound(&object->mUnk_000.mSoundSource, 0xd5, 0x7f, 0);
}

void DeflectItemObjectAndStartSound(DirectedItemObject *object, Vec3 *hitNormal, Vec3 *c) {
    Vec3 along;
    Vec3 *direction;
    s32 n;

    direction = &object->mDirection;
    n = VEC_DotProduct(hitNormal, direction);
    along.x = ((s64) hitNormal->x * n) >> 12;
    along.y = ((s64) hitNormal->y * n) >> 12;
    along.z = ((s64) hitNormal->z * n) >> 12;
    object->mDirection.x -= along.x;
    direction->y -= along.y;
    direction->z -= along.z;
    if (object->mUnk_160 != FALSE) {
        VEC_Subtract(direction, &along, direction);
    }
    if ((s64) direction->x * direction->x + (s64) direction->y * direction->y + (s64) direction->z * direction->z >=
        0x10) {
        Vec3NormalizeAndGetLengthUnchecked(direction, direction);
    }
    object->mSurfaceDirection = *direction;
    Vec3CrossUnrounded(direction, &object->mUnk_000.mNormal, &object->mSideDirection);
    object->mUnk_000.mNormal.y += 1;
    StartSound(&object->mUnk_000.mSoundSource, 0xd5, 0x7f, 0);
}

void AdvanceItemObjectMotion(DirectedItemObject *object, s32 targetSpeed) {
    Vec3 v1;
    Vec3 hitNormal;
    Vec3 v3;
    Vec3 normalPart;
    Vec3 *pos;
    Vec3 *velocity;
    Vec3 *direction;
    s32 flag80000;
    s32 n;
    BOOL sameNormal;
    Vec3 *velocityAlias;

    pos = &object->mUnk_000.mPos;
    velocity = &object->mUnk_000.mVelocity;
    direction = &object->mDirection;
    VEC_Add(velocity, pos, pos);
    n = func_01ffdee4(pos, &object->mUnk_000.mPrevPos, 0, object->mUnk_000.mUnk_dc, object->mUnk_164,
                      object->mUnk_000.mCollisionSlotIndex, &v1, &hitNormal, (s32 *) &v3,
                      &object->mUnk_000.mCollisionBits, NULL, NULL, NULL, NULL);
    if (n != 0) {
        flag80000 = object->mUnk_000.mCollisionBits & 0x80000;
        if (object->mUnk_158 != 0) {
            if (v1.y > 0) {
                pos->y += v1.y;
            }
        } else {
            VEC_Add(&v1, pos, pos);
        }
        if (object->mUnk_000.mCollisionBits & 0x1e34ef) {
            sameNormal = hitNormal.x == object->mUnk_000.mNormal.x && hitNormal.y == object->mUnk_000.mNormal.y &&
                         hitNormal.z == object->mUnk_000.mNormal.z;
            if (sameNormal == FALSE) {
                object->mUnk_000.mNormal = hitNormal;
                object->mUnk_000.mFlags |= 0x100;
                if (flag80000 != 0) {
                    n = VEC_DotProduct(&hitNormal, &object->mSurfaceDirection);
                    object->mSurfaceDirection.x =
                        (s32) (object->mSurfaceDirection.x - (s32) (((s64) hitNormal.x * n) >> 12));
                    object->mSurfaceDirection.y -= (s32) (((s64) hitNormal.y * n) >> 12);
                    object->mSurfaceDirection.z -= (s32) (((s64) hitNormal.z * n) >> 12);
                    if ((s64) object->mSurfaceDirection.x * object->mSurfaceDirection.x +
                            (s64) object->mSurfaceDirection.y * object->mSurfaceDirection.y +
                            (s64) object->mSurfaceDirection.z * object->mSurfaceDirection.z >=
                        0x10) {
                        Vec3NormalizeAndGetLengthUnchecked(&object->mSurfaceDirection, &object->mSurfaceDirection);
                    }
                    *direction = object->mSurfaceDirection;
                } else {
                    func_020f2a6c(direction, &hitNormal, &object->mSurfaceDirection);
                }
                Vec3CrossUnrounded(&object->mSurfaceDirection, &hitNormal, &object->mSideDirection);
            }
        }
        if (object->mUnk_000.mCollisionBits & 0x214300) {
            if (object->mUnk_158 != 0) {
                pos->x += v1.x;
                pos->z += v1.z;
            }
            if (flag80000 != 0) {
                VEC_Subtract(&v3, &object->mUnk_000.mNormal, &v3);
                func_020f288c(object, &v3);
            } else {
                v3.y = 0;
                DeflectItemObjectAndStartSound(object, &v3, NULL);
            }
            object->mUnk_000.mUnk_78 &= ~0x4000;
            if (object->mHasHitLimit != FALSE) {
                object->mUnk_000.mFlags |= 0x20;
                object->mHitsRemaining -= 1;
            }
        }
        n = object->mSpeed;
        velocity->x = ((s64) object->mSurfaceDirection.x * n) >> 12;
        velocity->y = ((s64) object->mSurfaceDirection.y * n) >> 12;
        velocity->z = ((s64) object->mSurfaceDirection.z * n) >> 12;
        if (object->mUnk_000.mCollisionBits & 0x1e34ef) {
            v1.y = pos->y - object->mUnk_000.mPrevPos.y;
            if (v1.y > 0x5000 && flag80000 == 0) {
                v1.y = 0x5000;
            }
            if (v1.y > velocity->y) {
                velocity->y = v1.y;
            }
        }
        if (object->mHitsRemaining < 0) {
            velocity->x = ((s64) velocity->x * 0x23d) >> 12;
            velocity->y = ((s64) velocity->y * 0x23d) >> 12;
            velocity->z = ((s64) velocity->z * 0x23d) >> 12;
            func_020f6fc4(object, 1);
            return;
        }
        if ((object->mUnk_000.mCollisionBits & 0x8000) && object->mUnk_000.mKind != 5) {
            func_020f7070(object, 1);
            return;
        }
    }
    object->mSpeed += (s32) (((s64) (targetSpeed - object->mSpeed) * 0x29) >> 12);
    velocityAlias = &object->mUnk_000.mVelocity;
    if (object->mUnk_000.mCollisionBits & 0x1e34ef) {
        normalPart.x = object->mUnk_000.mNormal.x >> 2;
        normalPart.y = object->mUnk_000.mNormal.y >> 2;
        normalPart.z = object->mUnk_000.mNormal.z >> 2;
        VEC_Subtract(velocityAlias, &normalPart, velocityAlias);
        return;
    }
    n = velocityAlias->y;
    if (n > 0) {
        velocityAlias->y -= 0x6b8;
        if (!(object->mUnk_000.mFlags & 0x20000)) {
            return;
        }
        n = velocityAlias->y;
        if (n > 0xa000) {
            velocityAlias->y = velocityAlias->y >> 3;
            return;
        }
        velocityAlias->y = ((s64) n * 0xe66) >> 12;
    } else {
        velocityAlias->y -= 0x333;
        if (velocityAlias->y >= -0xa000) {
            return;
        }
        if (object->mUnk_000.mFlags & 0x20000) {
            velocityAlias->y = -0xa000;
        }
    }
}

void ApplyItemObjectGravity(void *objectParam) {
    ItemObject *object;
    Vec3 *velocity;
    s32 verticalSpeed;

    object = objectParam;
    velocity = &object->mVelocity;
    verticalSpeed = velocity->y;
    if (verticalSpeed > 0) {
        velocity->y -= 0x6b8;
        if (!(object->mFlags & 0x20000)) {
            return;
        }
        verticalSpeed = velocity->y;
        if (verticalSpeed > 0xa000) {
            velocity->y = velocity->y >> 3;
            return;
        }
        velocity->y = ((s64) verticalSpeed * 0xe66) >> 12;
    } else {
        velocity->y -= 0x333;
        if (velocity->y >= -0xa000) {
            return;
        }
        if (object->mFlags & 0x20000) {
            velocity->y = -0xa000;
        }
    }
}

void func_020f2028(ItemObject *object) {
    Vec3 *velocity;
    Vec3 normalPart;
    s32 verticalSpeed;

    velocity = &object->mVelocity;
    if (object->mCollisionBits & 0x1e34ef) {
        normalPart.x = object->mNormal.x >> 2;
        normalPart.y = object->mNormal.y >> 2;
        normalPart.z = object->mNormal.z >> 2;
        VEC_Subtract(velocity, &normalPart, velocity);
        return;
    }
    verticalSpeed = velocity->y;
    if (verticalSpeed > 0) {
        velocity->y -= 0x6b8;
        if (!(object->mFlags & 0x20000)) {
            return;
        }
        verticalSpeed = velocity->y;
        if (verticalSpeed > 0xa000) {
            velocity->y = velocity->y >> 3;
            return;
        }
        velocity->y = ((s64) verticalSpeed * 0xe66) >> 12;
    } else {
        velocity->y -= 0x333;
        if (velocity->y >= -0xa000) {
            return;
        }
        if (object->mFlags & 0x20000) {
            velocity->y = -0xa000;
        }
    }
}

void DeflectItemObjectOnHit(DirectedItemObject *object, Vec3 *otherVelocity, Vec3 *awayDirection) {
    Vec3 flatDirection;
    s32 speed;

    if (awayDirection->y > 0) {
        DeflectItemObjectAndStartSound(object, awayDirection, awayDirection);
    } else {
        flatDirection = *awayDirection;
        flatDirection.y = 0;
        DeflectItemObjectAndStartSound(object, &flatDirection, NULL);
    }
    speed = object->mSpeed;
    object->mUnk_000.mVelocity.x = ((s64) object->mSurfaceDirection.x * speed) >> 12;
    object->mUnk_000.mVelocity.y = ((s64) object->mSurfaceDirection.y * speed) >> 12;
    object->mUnk_000.mVelocity.z = ((s64) object->mSurfaceDirection.z * speed) >> 12;
}

void InitItemObjectMotion(void *objectParam, s32 hitLimit, s32 reverse, s32 d) {
    DirectedItemObject *object;
    s32 speed;
    s32 negatedZ;
    s32 directionX;

    object = objectParam;
    speed = 0;
    if ((s64) object->mUnk_000.mVelocity.x * object->mUnk_000.mVelocity.x +
            (s64) object->mUnk_000.mVelocity.y * object->mUnk_000.mVelocity.y +
            (s64) object->mUnk_000.mVelocity.z * object->mUnk_000.mVelocity.z >=
        0x10) {
        speed = Vec3NormalizeAndGetLengthUnchecked(&object->mUnk_000.mVelocity, &object->mDirection);
    }
    object->mSpeed = speed;
    if (reverse != 0) {
        object->mSpeed = -object->mSpeed;
        object->mDirection.x = -object->mDirection.x;
        object->mDirection.y = -object->mDirection.y;
        object->mDirection.z = -object->mDirection.z;
    }
    object->mSurfaceDirection = object->mDirection;
    negatedZ = -object->mDirection.z;
    directionX = object->mDirection.x;
    object->mSideDirection.z = directionX;
    object->mSideDirection.x = negatedZ;
    object->mSideDirection.y = 0;
    if (hitLimit < 0) {
        object->mHitsRemaining = 0;
        object->mHasHitLimit = FALSE;
    } else {
        object->mHitsRemaining = hitLimit;
        object->mHasHitLimit = TRUE;
    }
    object->mUnk_000.mBounce = (void (*)(ItemObject *, Vec3 *, Vec3 *)) DeflectItemObjectOnHit;
    object->mUnk_160 = TRUE;
    object->mUnk_158 = d;
}

void SetItemObjectDirection(void *objectParam, const Vec3 *direction) {
    DirectedItemObject *object;
    Vec3 *normal;
    Vec3 projected;
    s32 dot;
    s32 speed;

    object = objectParam;
    object->mDirection.x = direction->x;
    object->mDirection.z = direction->z;
    normal = &object->mUnk_000.mNormal;
    dot = VEC_DotProduct(normal, direction);
    projected.x = direction->x - (s32) (((s64) normal->x * dot) >> 12);
    projected.y = direction->y - (s32) (((s64) normal->y * dot) >> 12);
    projected.z = direction->z - (s32) (((s64) normal->z * dot) >> 12);
    object->mSurfaceDirection.x = normal->x >> 2;
    object->mSurfaceDirection.y = normal->y >> 2;
    object->mSurfaceDirection.z = normal->z >> 2;
    VEC_Subtract(&projected, &object->mSurfaceDirection, &object->mSurfaceDirection);
    if ((s64) object->mSurfaceDirection.x * object->mSurfaceDirection.x +
            (s64) object->mSurfaceDirection.y * object->mSurfaceDirection.y +
            (s64) object->mSurfaceDirection.z * object->mSurfaceDirection.z >=
        0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&object->mSurfaceDirection, &object->mSurfaceDirection);
    }
    speed = object->mSpeed;
    object->mUnk_000.mVelocity.x = ((s64) object->mSurfaceDirection.x * speed) >> 12;
    object->mUnk_000.mVelocity.z = ((s64) object->mSurfaceDirection.z * speed) >> 12;
    Vec3CrossUnrounded(direction, normal, &object->mSideDirection);
}
