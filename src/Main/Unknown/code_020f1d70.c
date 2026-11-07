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

void func_020f2b94(void *objectParam, ItemInUse *inUseParam, s32 hitLimit, s32 d, s32 e, s32 f) {
    Unk020f1d70 *object;
    ItemInUse *inUse;
    s32 dot;
    s32 negatedZ;
    s32 directionX;

    object = objectParam;
    inUse = inUseParam;
    if (d != 0) {
        object->mUnk_12c = func_020edc9c(inUse, f, 0x1000, 0x3800, &object->mUnk_130);
    } else {
        Vec3 *direction = &object->mUnk_130;
        object->mUnk_12c = func_020edb8c(inUse, 0x3000, 0x1000, 0x4000, direction);
    }
    object->mUnk_13c = object->mUnk_130;
    negatedZ = -object->mUnk_130.z;
    directionX = object->mUnk_130.x;
    object->mUnk_148.z = directionX;
    object->mUnk_148.x = negatedZ;
    object->mUnk_148.y = 0;
    object->mUnk_000.mVelocity.x = ((s64) object->mUnk_130.x * object->mUnk_12c) >> 12;
    object->mUnk_000.mVelocity.z = ((s64) object->mUnk_130.z * object->mUnk_12c) >> 12;
    if (d == 0) {
        VEC_Add(&object->mUnk_000.mVelocity, &inUse->mKart->mUnk_1fc, &object->mUnk_000.mVelocity);
    }
    if (inUse->mKart->mUnk_48 & 1) {
        dot = VEC_DotProduct(&inUse->mUnk_02c.mUnk_0c, &object->mUnk_000.mVelocity);
        {
            s32 x, y, z;

            x = ((s64) inUse->mUnk_02c.mUnk_0c.x * dot) >> 12;
            y = ((s64) inUse->mUnk_02c.mUnk_0c.y * dot) >> 12;
            z = ((s64) inUse->mUnk_02c.mUnk_0c.z * dot) >> 12;
            object->mUnk_000.mVelocity.x = (s32) (object->mUnk_000.mVelocity.x - x);
            object->mUnk_000.mVelocity.y -= y;
            object->mUnk_000.mVelocity.z -= z;
        }
        VEC_MultAdd(-0x1000, &inUse->mUnk_02c.mUnk_0c, &object->mUnk_000.mVelocity, &object->mUnk_000.mVelocity);
    }
    if (object->mUnk_000.mScale.z < 0xccd) {
        object->mUnk_000.mScale.x = 0xccd;
        object->mUnk_000.mScale.y = 0xccd;
        object->mUnk_000.mScale.z = 0xccd;
        if (d != 0) {
            object->mUnk_000.mPos = inUse->mKart->mCollisionCenter;
            VEC_MultAdd(object->mUnk_000.mScale.z * 10, &inUse->mUnk_02c.mUnk_18, &object->mUnk_000.mPos,
                        &object->mUnk_000.mPos);
        }
    }
    if (hitLimit < 0) {
        object->mUnk_154 = 0;
        object->mUnk_15c = FALSE;
    } else {
        object->mUnk_154 = hitLimit;
        object->mUnk_15c = TRUE;
    }
    object->mUnk_000.mUnk_124 = (void (*)(ItemObject *, Vec3 *, Vec3 *)) func_020f1f98;
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
    Unk020f1d70 *object;
    Vec3 *normal;
    s32 speed;

    object = (Unk020f1d70 *) item;
    speed = 0;
    normal = &object->mUnk_000.mUnk_f0;
    if ((s64) object->mUnk_000.mVelocity.x * object->mUnk_000.mVelocity.x +
            (s64) object->mUnk_000.mVelocity.y * object->mUnk_000.mVelocity.y +
            (s64) object->mUnk_000.mVelocity.z * object->mUnk_000.mVelocity.z >=
        0x10) {
        speed = Vec3NormalizeAndGetLengthUnchecked(&object->mUnk_000.mVelocity, &object->mUnk_130);
    }
    object->mUnk_12c = speed;
    func_020f2a6c(&object->mUnk_130, normal, &object->mUnk_13c);
    Vec3CrossUnrounded(&object->mUnk_13c, normal, &object->mUnk_148);
    object->mUnk_000.mUnk_124 = (void (*)(ItemObject *, Vec3 *, Vec3 *)) func_020f1f98;
}

void func_020f288c(Unk020f1d70 *object, Vec3 *hitNormal) {
    Vec3 along;
    Vec3 *velocityDirection;
    Vec3 *flatDirection;
    s32 n;

    velocityDirection = &object->mUnk_13c;
    flatDirection = &object->mUnk_130;
    n = VEC_DotProduct(hitNormal, velocityDirection);
    along.x = ((s64) hitNormal->x * n) >> 12;
    along.y = ((s64) hitNormal->y * n) >> 12;
    along.z = ((s64) hitNormal->z * n) >> 12;
    object->mUnk_13c.x -= along.x;
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
    Vec3CrossUnrounded(flatDirection, &object->mUnk_000.mUnk_f0, &object->mUnk_148);
    StartSound(&object->mUnk_000.mSoundSource, 0xd5, 0x7f, 0);
}

void func_020f2768(Unk020f1d70 *object, Vec3 *hitNormal, Vec3 *c) {
    Vec3 along;
    Vec3 *direction;
    s32 n;

    direction = &object->mUnk_130;
    n = VEC_DotProduct(hitNormal, direction);
    along.x = ((s64) hitNormal->x * n) >> 12;
    along.y = ((s64) hitNormal->y * n) >> 12;
    along.z = ((s64) hitNormal->z * n) >> 12;
    object->mUnk_130.x -= along.x;
    direction->y -= along.y;
    direction->z -= along.z;
    if (object->mUnk_160 != FALSE) {
        VEC_Subtract(direction, &along, direction);
    }
    if ((s64) direction->x * direction->x + (s64) direction->y * direction->y + (s64) direction->z * direction->z >=
        0x10) {
        Vec3NormalizeAndGetLengthUnchecked(direction, direction);
    }
    object->mUnk_13c = *direction;
    Vec3CrossUnrounded(direction, &object->mUnk_000.mUnk_f0, &object->mUnk_148);
    object->mUnk_000.mUnk_f0.y += 1;
    StartSound(&object->mUnk_000.mSoundSource, 0xd5, 0x7f, 0);
}

void func_020f2228(Unk020f1d70 *object, s32 targetSpeed) {
    Vec3 v1;
    Vec3 hitNormal;
    Vec3 v3;
    Vec3 normalPart;
    Vec3 *pos;
    Vec3 *velocity;
    Vec3 *r;
    s32 flag80000;
    s32 n;
    BOOL sameNormal;
    Vec3 *velocityAlias;

    pos = &object->mUnk_000.mPos;
    velocity = &object->mUnk_000.mVelocity;
    r = &object->mUnk_130;
    VEC_Add(velocity, pos, pos);
    n = func_01ffdee4(pos, &object->mUnk_000.mPrevPos, 0, object->mUnk_000.mUnk_dc, object->mUnk_164,
                      object->mUnk_000.mCollisionSlotIndex, &v1, &hitNormal, (s32 *) &v3, &object->mUnk_000.mUnk_fc,
                      NULL, NULL, NULL, NULL);
    if (n != 0) {
        flag80000 = object->mUnk_000.mUnk_fc & 0x80000;
        if (object->mUnk_158 != 0) {
            if (v1.y > 0) {
                pos->y += v1.y;
            }
        } else {
            VEC_Add(&v1, pos, pos);
        }
        if (object->mUnk_000.mUnk_fc & 0x1e34ef) {
            sameNormal = hitNormal.x == object->mUnk_000.mUnk_f0.x && hitNormal.y == object->mUnk_000.mUnk_f0.y &&
                         hitNormal.z == object->mUnk_000.mUnk_f0.z;
            if (sameNormal == FALSE) {
                object->mUnk_000.mUnk_f0 = hitNormal;
                object->mUnk_000.mFlags |= 0x100;
                if (flag80000 != 0) {
                    n = VEC_DotProduct(&hitNormal, &object->mUnk_13c);
                    object->mUnk_13c.x = (s32) (object->mUnk_13c.x - (s32) (((s64) hitNormal.x * n) >> 12));
                    object->mUnk_13c.y -= (s32) (((s64) hitNormal.y * n) >> 12);
                    object->mUnk_13c.z -= (s32) (((s64) hitNormal.z * n) >> 12);
                    if ((s64) object->mUnk_13c.x * object->mUnk_13c.x + (s64) object->mUnk_13c.y * object->mUnk_13c.y +
                            (s64) object->mUnk_13c.z * object->mUnk_13c.z >=
                        0x10) {
                        Vec3NormalizeAndGetLengthUnchecked(&object->mUnk_13c, &object->mUnk_13c);
                    }
                    *r = object->mUnk_13c;
                } else {
                    func_020f2a6c(r, &hitNormal, &object->mUnk_13c);
                }
                Vec3CrossUnrounded(&object->mUnk_13c, &hitNormal, &object->mUnk_148);
            }
        }
        if (object->mUnk_000.mUnk_fc & 0x214300) {
            if (object->mUnk_158 != 0) {
                pos->x += v1.x;
                pos->z += v1.z;
            }
            if (flag80000 != 0) {
                VEC_Subtract(&v3, &object->mUnk_000.mUnk_f0, &v3);
                func_020f288c(object, &v3);
            } else {
                v3.y = 0;
                func_020f2768(object, &v3, NULL);
            }
            object->mUnk_000.mUnk_78 &= ~0x4000;
            if (object->mUnk_15c != FALSE) {
                object->mUnk_000.mFlags |= 0x20;
                object->mUnk_154 -= 1;
            }
        }
        n = object->mUnk_12c;
        velocity->x = ((s64) object->mUnk_13c.x * n) >> 12;
        velocity->y = ((s64) object->mUnk_13c.y * n) >> 12;
        velocity->z = ((s64) object->mUnk_13c.z * n) >> 12;
        if (object->mUnk_000.mUnk_fc & 0x1e34ef) {
            v1.y = pos->y - object->mUnk_000.mPrevPos.y;
            if (v1.y > 0x5000 && flag80000 == 0) {
                v1.y = 0x5000;
            }
            if (v1.y > velocity->y) {
                velocity->y = v1.y;
            }
        }
        if (object->mUnk_154 < 0) {
            velocity->x = ((s64) velocity->x * 0x23d) >> 12;
            velocity->y = ((s64) velocity->y * 0x23d) >> 12;
            velocity->z = ((s64) velocity->z * 0x23d) >> 12;
            func_020f6fc4(object, 1);
            return;
        }
        if ((object->mUnk_000.mUnk_fc & 0x8000) && object->mUnk_000.mKind != 5) {
            func_020f7070(object, 1);
            return;
        }
    }
    object->mUnk_12c += (s32) (((s64) (targetSpeed - object->mUnk_12c) * 0x29) >> 12);
    velocityAlias = &object->mUnk_000.mVelocity;
    if (object->mUnk_000.mUnk_fc & 0x1e34ef) {
        normalPart.x = object->mUnk_000.mUnk_f0.x >> 2;
        normalPart.y = object->mUnk_000.mUnk_f0.y >> 2;
        normalPart.z = object->mUnk_000.mUnk_f0.z >> 2;
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
    if (object->mUnk_fc & 0x1e34ef) {
        normalPart.x = object->mUnk_f0.x >> 2;
        normalPart.y = object->mUnk_f0.y >> 2;
        normalPart.z = object->mUnk_f0.z >> 2;
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

void func_020f1f98(Unk020f1d70 *object, Vec3 *otherVelocity, Vec3 *awayDirection) {
    Vec3 flatDirection;
    s32 speed;

    if (awayDirection->y > 0) {
        func_020f2768(object, awayDirection, awayDirection);
    } else {
        flatDirection = *awayDirection;
        flatDirection.y = 0;
        func_020f2768(object, &flatDirection, NULL);
    }
    speed = object->mUnk_12c;
    object->mUnk_000.mVelocity.x = ((s64) object->mUnk_13c.x * speed) >> 12;
    object->mUnk_000.mVelocity.y = ((s64) object->mUnk_13c.y * speed) >> 12;
    object->mUnk_000.mVelocity.z = ((s64) object->mUnk_13c.z * speed) >> 12;
}

void func_020f1ea4(void *objectParam, s32 hitLimit, s32 reverse, s32 d) {
    Unk020f1d70 *object;
    s32 speed;
    s32 negatedZ;
    s32 directionX;

    object = objectParam;
    speed = 0;
    if ((s64) object->mUnk_000.mVelocity.x * object->mUnk_000.mVelocity.x +
            (s64) object->mUnk_000.mVelocity.y * object->mUnk_000.mVelocity.y +
            (s64) object->mUnk_000.mVelocity.z * object->mUnk_000.mVelocity.z >=
        0x10) {
        speed = Vec3NormalizeAndGetLengthUnchecked(&object->mUnk_000.mVelocity, &object->mUnk_130);
    }
    object->mUnk_12c = speed;
    if (reverse != 0) {
        object->mUnk_12c = -object->mUnk_12c;
        object->mUnk_130.x = -object->mUnk_130.x;
        object->mUnk_130.y = -object->mUnk_130.y;
        object->mUnk_130.z = -object->mUnk_130.z;
    }
    object->mUnk_13c = object->mUnk_130;
    negatedZ = -object->mUnk_130.z;
    directionX = object->mUnk_130.x;
    object->mUnk_148.z = directionX;
    object->mUnk_148.x = negatedZ;
    object->mUnk_148.y = 0;
    if (hitLimit < 0) {
        object->mUnk_154 = 0;
        object->mUnk_15c = FALSE;
    } else {
        object->mUnk_154 = hitLimit;
        object->mUnk_15c = TRUE;
    }
    object->mUnk_000.mUnk_124 = (void (*)(ItemObject *, Vec3 *, Vec3 *)) func_020f1f98;
    object->mUnk_160 = TRUE;
    object->mUnk_158 = d;
}

void func_020f1d70(void *objectParam, const Vec3 *direction) {
    Unk020f1d70 *object;
    Vec3 *normal;
    Vec3 projected;
    s32 dot;
    s32 speed;

    object = objectParam;
    object->mUnk_130.x = direction->x;
    object->mUnk_130.z = direction->z;
    normal = &object->mUnk_000.mUnk_f0;
    dot = VEC_DotProduct(normal, direction);
    projected.x = direction->x - (s32) (((s64) normal->x * dot) >> 12);
    projected.y = direction->y - (s32) (((s64) normal->y * dot) >> 12);
    projected.z = direction->z - (s32) (((s64) normal->z * dot) >> 12);
    object->mUnk_13c.x = normal->x >> 2;
    object->mUnk_13c.y = normal->y >> 2;
    object->mUnk_13c.z = normal->z >> 2;
    VEC_Subtract(&projected, &object->mUnk_13c, &object->mUnk_13c);
    if ((s64) object->mUnk_13c.x * object->mUnk_13c.x + (s64) object->mUnk_13c.y * object->mUnk_13c.y +
            (s64) object->mUnk_13c.z * object->mUnk_13c.z >=
        0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&object->mUnk_13c, &object->mUnk_13c);
    }
    speed = object->mUnk_12c;
    object->mUnk_000.mVelocity.x = ((s64) object->mUnk_13c.x * speed) >> 12;
    object->mUnk_000.mVelocity.z = ((s64) object->mUnk_13c.z * speed) >> 12;
    Vec3CrossUnrounded(direction, normal, &object->mUnk_148);
}
