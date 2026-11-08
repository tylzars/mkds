#include "Main/Unknown/code_020ec538.h"
#include "Main/Unknown/code_020d6dc0.h"
#include "Main/Unknown/code_020e43a8.h"

#include "Main/Unknown/code_020d6000.h"
#include "code_02147cd8.h"

const Vec3 data_02159588 = {0x1000, 0, 0};
const Vec3 gVec3UnitX = {0x1000, 0, 0};
const Vec3 data_02159594 = {0, 0, 0};

void InitPushedMotion(Unk020e43a8 *object, s32 lowestY, u32 gravity, u16 angleStep, u32 upwardSpeed, s32 pushSpeed) {
    object->mUnk_0a0 = lowestY;
    object->mUnk_0a4 = gravity;
    object->mUnk_0a8 = 1;
    object->mUnk_0ac = 0;
    object->mUnk_0ae = angleStep;
    object->mUnk_0b0 = upwardSpeed;
    object->mUnk_0b4 = pushSpeed;
}

BOOL AdvancePushedMotion(Unk020e43a8 *object) {
    if (object->mUnk_0a8) {
        object->mUnk_0ac = object->mUnk_0ac + object->mUnk_0ae;
    } else {
        object->mUnk_0ac = object->mUnk_0ac - object->mUnk_0ae;
    }
    object->mUnk_00.mUnk_10.y = object->mUnk_00.mUnk_10.y - object->mUnk_0a4;
    VEC_Add(&object->mUnk_00.mPos, &object->mUnk_00.mUnk_10, &object->mUnk_00.mPos);
    return object->mUnk_00.mPos.y < object->mUnk_0a0;
}

void SetPushedMotionFromKart(Unk020e43a8 *object, Unk020ec6e4 *other) {
    Vec3 offset;
    s32 pushSpeed;

    VEC_Subtract(&object->mUnk_00.mPos, &other->mUnk_080, &offset);
    if ((s64) offset.z * other->mUnk_0a4 - (s64) offset.x * other->mUnk_0ac < 0) {
        s32 x = other->mUnk_050.x;
        s32 z = other->mUnk_050.z;
        offset.z = -x;
        offset.x = z;
        offset.y = 0;
        object->mUnk_0a8 = 1;
    } else {
        s32 x = other->mUnk_050.x;
        s32 z = -other->mUnk_050.z;
        offset.z = x;
        offset.x = z;
        offset.y = 0;
        object->mUnk_0a8 = 0;
    }
    pushSpeed = object->mUnk_0b4;
    object->mUnk_00.mUnk_10.x = ((s64) offset.x * pushSpeed) >> 12;
    object->mUnk_00.mUnk_10.y = ((s64) offset.y * pushSpeed) >> 12;
    object->mUnk_00.mUnk_10.z = ((s64) offset.z * pushSpeed) >> 12;
    object->mUnk_00.mUnk_10.x = object->mUnk_00.mUnk_10.x + (other->mUnk_0a4 >> 1);
    object->mUnk_00.mUnk_10.z = object->mUnk_00.mUnk_10.z + (other->mUnk_0ac >> 1);
    object->mUnk_00.mUnk_10.y = object->mUnk_0b0;
}

void SetPushedMotionFromItemObject(Unk020e43a8 *object, const Unk020ec6e4 *other) {
    Vec3 out;
    Vec3 otherPoint;
    Vec3 otherVector;
    s32 pushSpeed;

    otherPoint = other ? other->mUnk_050 : object->mUnk_00.mPos;
    otherVector = other ? other->mUnk_05c : data_02159594;
    VEC_Subtract(&object->mUnk_00.mPos, &otherPoint, &out);
    if ((s64) out.z * otherVector.x - (s64) out.x * otherVector.z < 0) {
        if (Vec3NormalizeXZAndGetLengthOrZero(&otherVector, &out) == 0) {
            out = gVec3UnitX;
        } else {
            s32 x = out.x;
            s32 z = out.z;
            out.z = -x;
            out.x = z;
            out.y = 0;
        }
        object->mUnk_0a8 = 1;
    } else {
        if (Vec3NormalizeXZAndGetLengthOrZero(&otherVector, &out) == 0) {
            out = data_02159588;
        } else {
            s32 x = out.x;
            s32 z = -out.z;
            out.z = x;
            out.x = z;
            out.y = 0;
        }
        object->mUnk_0a8 = 0;
    }
    pushSpeed = object->mUnk_0b4;
    object->mUnk_00.mUnk_10.x = ((s64) out.x * pushSpeed) >> 12;
    object->mUnk_00.mUnk_10.y = ((s64) out.y * pushSpeed) >> 12;
    object->mUnk_00.mUnk_10.z = ((s64) out.z * pushSpeed) >> 12;
    object->mUnk_00.mUnk_10.x = object->mUnk_00.mUnk_10.x + (otherVector.x >> 1);
    object->mUnk_00.mUnk_10.z = object->mUnk_00.mUnk_10.z + (otherVector.z >> 1);
    object->mUnk_00.mUnk_10.y = object->mUnk_0b0;
}
