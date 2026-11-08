#include "Main/Unknown/code_020d6538.h"
#include "Main/Unknown/code_020ea670.h"

#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020b2ec0.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0216b000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "01/code_0218155c.h"
#include "code_02146cbc.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020d6dc0.h"
#include "Main/Unknown/code_020d7db4.h"
#include "Main/Unknown/code_020d7da8.h"
#include "Main/Unknown/code_020d8000.h"
#include "Main/Unknown/code_020d849c.h"
#include "code_02146d78.h"
#include "code_02148538.h"
#include "registers.h"

#pragma thumb on

void func_020d7d4c(Unk020d84e4 *follower, struct CourseMapRow *courseRow, s32 speed, s32 d) {
    InitGroupFollower(&follower->mUnk_00, courseRow, speed);
    follower->mUnk_24 = speed / 100;
    follower->mUnk_28 = (speed * d) / 100;
    func_020d859c(follower, 0, 1);
}

void func_020d7d18(SegmentProgress *segmentProgress, s32 a, Vec3 **points, s32 rate) {
    func_020d80e4(&segmentProgress->mUnk_00, a, 0, points[0], points[1], points[2], points[3]);
    SetSegmentProgressRate(segmentProgress, rate);
    segmentProgress->mUnk_5c = 0;
}

BOOL func_020d7c84(SegmentProgress *segmentProgress, s32 a, Vec3 **points) {
    s32 v;
    segmentProgress->mUnk_5c = segmentProgress->mUnk_5c - 0x1000000;
    segmentProgress->mUnk_5c = ((s64) segmentProgress->mUnk_5c * (s64) segmentProgress->mUnk_00.mUnk_30) >> 12;
    func_020d80e4(&segmentProgress->mUnk_00, a, 0, points[0], points[1], points[2], points[3]);
    v = segmentProgress->mUnk_00.mUnk_34;
    if (v != 0) {
        segmentProgress->mUnk_5c = ((s64) segmentProgress->mUnk_5c * (s64) v) >> 24;
    }
    if (v != 0) {
        v = ((s64) segmentProgress->mUnk_54 * (s64) v) >> 12;
    } else {
        v = 0x1000000;
    }
    segmentProgress->mUnk_58 = v;
    if (segmentProgress->mUnk_5c >= 0x1000000) {
        return TRUE;
    }
    return FALSE;
}

#pragma thumb off

void SetViewYawQuaternion(MtxFx43 *viewMatrix) {
    s32 angle;
    s32 pairIndex;
    angle = FX_Atan2(viewMatrix->mUnk_00[0].z, viewMatrix->mUnk_00[2].z);
    angle = (((s64) angle * 0x28BE60DB9391LL) + 0x80000000000LL) >> 44;
    pairIndex = (u16) ((u16) angle >> 1) >> 4;
    gViewYawQuaternion.mComponents[0] = 0;
    gViewYawQuaternion.mComponents[1] = gPairsByAngle[pairIndex * 2];
    gViewYawQuaternion.mComponents[2] = 0;
    gViewYawQuaternion.mComponents[3] = gPairsByAngle[pairIndex * 2 + 1];
}

void QuaternionFromYAxisToVec3(Vec3 *direction, void *output) {
    Quaternion *quaternion = output;
    s32 root = FX_Sqrt((direction->y + 0x1000) << 1);
    FX_DivAsync(direction->z, root);
    quaternion->mComponents[1] = 0;
    quaternion->mComponents[0] = FX_GetDivResult();
    FX_DivAsync(-direction->x, root);
    quaternion->mComponents[3] = root >> 1;
    quaternion->mComponents[2] = FX_GetDivResult();
}

void QuaternionFromAngleAroundY(s32 angle, Quaternion *quaternion) {
    s32 pairIndex = (u16) (angle >> 1) >> 4;
    quaternion->mComponents[0] = 0;
    quaternion->mComponents[1] = gPairsByAngle[pairIndex * 2];
    quaternion->mComponents[2] = 0;
    quaternion->mComponents[3] = gPairsByAngle[pairIndex * 2 + 1];
}

void QuaternionFromVec3AndAngleAroundY(void *directionPtr, s32 angle, void *outputPtr) {
    Vec3 *direction = directionPtr;
    Quaternion *quaternion = outputPtr;
    s32 root;
    s32 quotient;
    s32 pairIndex;
    s32 pairFirst;
    s32 pairSecond;
    s64 radicand = (s64) ((direction->y + 0x1000) << 1) << 32;
    reg_CP_SQRTCNT = 1;
    reg_CP_SQRT_PARAM = radicand;
    root = FX_GetSqrtResult();
    FX_DivAsync(direction->z, root);
    pairIndex = (u16) (angle >> 1) >> 4;
    pairFirst = gPairsByAngle[pairIndex * 2];
    pairSecond = gPairsByAngle[pairIndex * 2 + 1];
    quaternion->mComponents[1] = ((root >> 1) * pairFirst) >> 12;
    quaternion->mComponents[3] = ((root >> 1) * pairSecond) >> 12;
    quotient = FX_GetDivResult();
    FX_DivAsync(-direction->x, root);
    quaternion->mComponents[0] = (quotient * pairSecond) >> 12;
    quaternion->mComponents[2] = (quotient * pairFirst) >> 12;
    quotient = FX_GetDivResult();
    quaternion->mComponents[0] = quaternion->mComponents[0] - ((quotient * pairFirst) >> 12);
    quaternion->mComponents[2] = quaternion->mComponents[2] + ((quotient * pairSecond) >> 12);
}

void func_020d79b0(void *quaternionPtr, u32 angle, void *outputPtr) {
    Quaternion *quaternion = quaternionPtr;
    Quaternion *result = outputPtr;
    s32 pairIndex = (u16) (angle >> 1) >> 4;
    s32 pairFirst = gPairsByAngle[pairIndex * 2];
    s32 pairSecond = gPairsByAngle[pairIndex * 2 + 1];
    result->mComponents[0] = (quaternion->mComponents[0] * pairSecond - quaternion->mComponents[2] * pairFirst) >> 12;
    result->mComponents[1] = (quaternion->mComponents[3] * pairFirst) >> 12;
    result->mComponents[2] = (quaternion->mComponents[2] * pairSecond + quaternion->mComponents[0] * pairFirst) >> 12;
    result->mComponents[3] = (quaternion->mComponents[3] * pairSecond) >> 12;
}

void func_020d7938(Quaternion *first, Quaternion *second, Quaternion *result) {
    result->mComponents[0] =
        (first->mComponents[0] * second->mComponents[3] - first->mComponents[2] * second->mComponents[1]) >> 12;
    result->mComponents[1] = (first->mComponents[3] * second->mComponents[1]) >> 12;
    result->mComponents[2] =
        (first->mComponents[2] * second->mComponents[3] + first->mComponents[0] * second->mComponents[1]) >> 12;
    result->mComponents[3] = (first->mComponents[3] * second->mComponents[3]) >> 12;
}

void QuaternionMultiplyAngleAroundX(Quaternion *quaternion, s32 angle, Quaternion *result) {
    Quaternion source = *quaternion;
    s32 pairIndex = (u16) (angle >> 1) >> 4;
    s32 pairFirst = gPairsByAngle[pairIndex * 2];
    s32 pairSecond = gPairsByAngle[pairIndex * 2 + 1];
    result->mComponents[0] = (source.mComponents[3] * pairFirst + source.mComponents[0] * pairSecond) >> 12;
    result->mComponents[1] = (source.mComponents[1] * pairSecond + source.mComponents[2] * pairFirst) >> 12;
    result->mComponents[2] = (source.mComponents[2] * pairSecond - source.mComponents[1] * pairFirst) >> 12;
    result->mComponents[3] = (source.mComponents[3] * pairSecond - source.mComponents[0] * pairFirst) >> 12;
}

void QuaternionMultiplyAngleAroundY(void *quaternionPtr, s32 angle, void *resultPtr) {
    Quaternion *quaternion = quaternionPtr;
    Quaternion *result = resultPtr;
    Quaternion source = *quaternion;
    s32 pairIndex = (u16) (angle >> 1) >> 4;
    s32 pairFirst = gPairsByAngle[pairIndex * 2];
    s32 pairSecond = gPairsByAngle[pairIndex * 2 + 1];
    result->mComponents[0] = (source.mComponents[0] * pairSecond - source.mComponents[2] * pairFirst) >> 12;
    result->mComponents[1] = (source.mComponents[3] * pairFirst + source.mComponents[1] * pairSecond) >> 12;
    result->mComponents[2] = (source.mComponents[2] * pairSecond + source.mComponents[0] * pairFirst) >> 12;
    result->mComponents[3] = (source.mComponents[3] * pairSecond - source.mComponents[1] * pairFirst) >> 12;
}

void QuaternionMultiplyAngleAroundZ(void *quaternionPtr, s32 angle, void *resultPtr) {
    Quaternion *quaternion = quaternionPtr;
    Quaternion *result = resultPtr;
    Quaternion source = *quaternion;
    s32 pairIndex = (u16) (angle >> 1) >> 4;
    s32 pairFirst = gPairsByAngle[pairIndex * 2];
    s32 pairSecond = gPairsByAngle[pairIndex * 2 + 1];
    result->mComponents[0] = (source.mComponents[0] * pairSecond + source.mComponents[1] * pairFirst) >> 12;
    result->mComponents[1] = (source.mComponents[1] * pairSecond - source.mComponents[0] * pairFirst) >> 12;
    result->mComponents[2] = (source.mComponents[3] * pairFirst + source.mComponents[2] * pairSecond) >> 12;
    result->mComponents[3] = (source.mComponents[3] * pairSecond - source.mComponents[2] * pairFirst) >> 12;
}

void func_020d76a8(Quaternion *quaternion, s32 angle, Quaternion *result) {
    Quaternion source = *quaternion;
    s32 pairIndex = (u16) (angle >> 1) >> 4;
    s32 pairFirst = gPairsByAngle[pairIndex * 2];
    s32 pairSecond = gPairsByAngle[pairIndex * 2 + 1];
    result->mComponents[0] = (source.mComponents[3] * pairFirst) >> 12;
    result->mComponents[1] = (source.mComponents[1] * pairSecond) >> 12;
    result->mComponents[2] = (-source.mComponents[1] * pairFirst) >> 12;
    result->mComponents[3] = (source.mComponents[3] * pairSecond) >> 12;
}

void QuaternionBlendTowardNearerSign(void *fromPtr, void *toPtr, void *resultPtr, s32 amount) {
    Quaternion *from = fromPtr;
    Quaternion *to = toPtr;
    Quaternion *result = resultPtr;
    s32 dot = from->mComponents[0] * to->mComponents[0] + from->mComponents[1] * to->mComponents[1] +
              from->mComponents[2] * to->mComponents[2] + from->mComponents[3] * to->mComponents[3];
    if (dot < 0) {
        result->mComponents[0] = from->mComponents[0] + ((amount * -(to->mComponents[0] + from->mComponents[0])) >> 12);
        result->mComponents[1] = from->mComponents[1] + ((amount * -(to->mComponents[1] + from->mComponents[1])) >> 12);
        result->mComponents[2] = from->mComponents[2] + ((amount * -(to->mComponents[2] + from->mComponents[2])) >> 12);
        result->mComponents[3] = from->mComponents[3] + ((amount * -(to->mComponents[3] + from->mComponents[3])) >> 12);
    } else {
        result->mComponents[0] = from->mComponents[0] + ((amount * (to->mComponents[0] - from->mComponents[0])) >> 12);
        result->mComponents[1] = from->mComponents[1] + ((amount * (to->mComponents[1] - from->mComponents[1])) >> 12);
        result->mComponents[2] = from->mComponents[2] + ((amount * (to->mComponents[2] - from->mComponents[2])) >> 12);
        result->mComponents[3] = from->mComponents[3] + ((amount * (to->mComponents[3] - from->mComponents[3])) >> 12);
    }
}

void QuaternionNormalizeUnlessNearOne(Quaternion *input, Quaternion *output) {
    s64 lengthSquared;
    s32 root;
    s64 quotient;
    s64 factor;
    lengthSquared = input->mComponents[0] * input->mComponents[0] + input->mComponents[1] * input->mComponents[1] +
                    input->mComponents[2] * input->mComponents[2] + input->mComponents[3] * input->mComponents[3];
    if (lengthSquared > 0xE66666 && lengthSquared < 0x119999A) {
        *output = *input;
        return;
    }
    reg_CP_DIVCNT = 2;
    reg_CP_DIV_NUMER = 0x1000000000000LL << 8;
    reg_CP_DIV_DENOM = lengthSquared;
    reg_CP_SQRTCNT = 1;
    reg_CP_SQRT_PARAM = lengthSquared << 2;
    while (reg_CP_SQRTCNT & 0x8000) {
    }
    root = reg_CP_SQRT_RESULT;
    while (reg_CP_DIVCNT & 0x8000) {
    }
    quotient = reg_CP_DIV_RESULT;
    factor = quotient * root;
    output->mComponents[0] = (factor * input->mComponents[0] + 0x100000000000LL) >> 45;
    output->mComponents[1] = (factor * input->mComponents[1] + 0x100000000000LL) >> 45;
    output->mComponents[2] = (factor * input->mComponents[2] + 0x100000000000LL) >> 45;
    output->mComponents[3] = (factor * input->mComponents[3] + 0x100000000000LL) >> 45;
}

void QuaternionFromVec3Degrees(Vec3 *degrees, u32 *resultWords) {
    Quaternion *result = (Quaternion *) resultWords;
    Quaternion partial;
    Quaternion afterX;
    Quaternion afterXY;
    s32 pairIndex;
    s32 pairFirst;
    s32 pairSecond;
    s32 angle;
    angle = ((s64) degrees->x * 0xB60B60B60BLL + 0x80000000000LL) >> 44;
    pairIndex = (u16) ((u16) angle >> 1) >> 4;
    partial.mComponents[0] = gPairsByAngle[pairIndex * 2];
    partial.mComponents[3] = gPairsByAngle[pairIndex * 2 + 1];
    partial.mComponents[1] = 0;
    partial.mComponents[2] = 0;
    afterX = partial;
    angle = ((s64) degrees->y * 0xB60B60B60BLL + 0x80000000000LL) >> 44;
    pairIndex = (u16) ((u16) angle >> 1) >> 4;
    pairFirst = gPairsByAngle[pairIndex * 2];
    pairSecond = gPairsByAngle[pairIndex * 2 + 1];
    partial.mComponents[0] = (afterX.mComponents[0] * pairSecond - afterX.mComponents[2] * pairFirst) >> 12;
    partial.mComponents[2] = (afterX.mComponents[2] * pairSecond + afterX.mComponents[0] * pairFirst) >> 12;
    partial.mComponents[1] = (afterX.mComponents[3] * pairFirst + afterX.mComponents[1] * pairSecond) >> 12;
    partial.mComponents[3] = (afterX.mComponents[3] * pairSecond - afterX.mComponents[1] * pairFirst) >> 12;
    afterXY = partial;
    angle = ((s64) degrees->z * 0xB60B60B60BLL + 0x80000000000LL) >> 44;
    pairIndex = (u16) ((u16) angle >> 1) >> 4;
    pairFirst = gPairsByAngle[pairIndex * 2];
    pairSecond = gPairsByAngle[pairIndex * 2 + 1];
    result->mComponents[0] = (afterXY.mComponents[0] * pairSecond + afterXY.mComponents[1] * pairFirst) >> 12;
    result->mComponents[1] = (afterXY.mComponents[1] * pairSecond - afterXY.mComponents[0] * pairFirst) >> 12;
    result->mComponents[2] = (afterXY.mComponents[3] * pairFirst + afterXY.mComponents[2] * pairSecond) >> 12;
    result->mComponents[3] = (afterXY.mComponents[3] * pairSecond - afterXY.mComponents[2] * pairFirst) >> 12;
}

s32 Vec3NormalizeAndGetLengthOrZero(Vec3 *vector, Vec3 *result) {
    s64 lengthSquared;
    s32 root;
    s64 quotient;
    s64 factor;
    lengthSquared = (s64) vector->x * vector->x;
    lengthSquared += (s64) vector->y * vector->y;
    lengthSquared += (s64) vector->z * vector->z;
    if (lengthSquared < 16) {
        return 0;
    }
    reg_CP_DIVCNT = 2;
    reg_CP_DIV_NUMER = 0x1000000000000LL << 8;
    reg_CP_DIV_DENOM = lengthSquared;
    reg_CP_SQRTCNT = 1;
    reg_CP_SQRT_PARAM = lengthSquared << 2;
    while (reg_CP_SQRTCNT & 0x8000) {
    }
    root = reg_CP_SQRT_RESULT;
    while (reg_CP_DIVCNT & 0x8000) {
    }
    quotient = reg_CP_DIV_RESULT;
    factor = quotient * root;
    result->x = (factor * vector->x + 0x100000000000LL) >> 45;
    result->y = (factor * vector->y + 0x100000000000LL) >> 45;
    result->z = (factor * vector->z + 0x100000000000LL) >> 45;
    return (root + 1) >> 1;
}

s32 Vec3NormalizeXZAndGetLengthOrZero(Vec3 *vector, Vec3 *result) {
    s64 lengthSquared;
    s32 root;
    s64 quotient;
    s64 factor;
    s32 x = vector->x;
    s32 z = vector->z;
    lengthSquared = (s64) x * x + (s64) z * z;
    if (lengthSquared < 16) {
        return 0;
    }
    reg_CP_DIVCNT = 2;
    reg_CP_DIV_NUMER = 0x1000000000000LL << 8;
    reg_CP_DIV_DENOM = lengthSquared;
    reg_CP_SQRTCNT = 1;
    reg_CP_SQRT_PARAM = lengthSquared << 2;
    while (reg_CP_SQRTCNT & 0x8000) {
    }
    root = reg_CP_SQRT_RESULT;
    while (reg_CP_DIVCNT & 0x8000) {
    }
    quotient = reg_CP_DIV_RESULT;
    factor = quotient * root;
    result->x = (factor * vector->x + 0x100000000000LL) >> 45;
    result->z = (factor * vector->z + 0x100000000000LL) >> 45;
    return (root + 1) >> 1;
}

void Vec3RotateAroundY(Vec3 *vector, s32 angle, Vec3 *result) {
    s32 matrix[9];
    s32 pairIndex = angle >> 4;
    MTX_RotY33_(matrix, gPairsByAngle[pairIndex * 2], gPairsByAngle[pairIndex * 2 + 1]);
    MTX_MultVec33(vector, matrix, result);
}

void Matrix3x3FromVec3Degrees(Vec3 *degrees, s32 *matrix) {
    s32 rotation[9];
    s32 angleX;
    s32 angleY;
    s32 angleZ;
    angleX = (u16) ((((s64) degrees->x * 0xB60B60B60BLL) + 0x80000000000LL) >> 44);
    angleY = (u16) ((((s64) degrees->y * 0xB60B60B60BLL) + 0x80000000000LL) >> 44);
    angleZ = (u16) ((((s64) degrees->z * 0xB60B60B60BLL) + 0x80000000000LL) >> 44);
    MTX_RotX33_(matrix, gPairsByAngle[(angleX >> 4) * 2], gPairsByAngle[(angleX >> 4) * 2 + 1]);
    MTX_RotY33_(rotation, gPairsByAngle[(angleY >> 4) * 2], gPairsByAngle[(angleY >> 4) * 2 + 1]);
    MTX_Concat33(matrix, rotation, matrix);
    MTX_RotZ33_(rotation, gPairsByAngle[(angleZ >> 4) * 2], gPairsByAngle[(angleZ >> 4) * 2 + 1]);
    MTX_Concat33(matrix, rotation, matrix);
}

u32 GetKartMapObjectResponseByKind(s32 flagBit, s32 itemEffect, s32 kindHundreds, s32 kindRemainder) {
    u32 response = data_0216b96c[kindHundreds][itemEffect][kindRemainder];
    if (response == 1) {
        response = flagBit != 0 ? 2 : 0;
    }
    return response;
}

u32 func_020d6d8c(u32 zeroResultFlag, u32 itemKind, u32 kindHundreds, u32 kindRemainder) {
    u32 value0 = zeroResultFlag;
    u32 value1 = itemKind;
    u32 kindHundredsCopy = kindHundreds;
    u32 kindRemainderCopy = kindRemainder;
    u32 value12;
    u32 tableAddress;
    u32 flagCopy;
    u32 zero;
    tableAddress = (u32) &data_0216bb7c;
    value12 = 0x38u;
    value12 = (kindHundredsCopy) * (value12) + (tableAddress);
    value1 = *(const u32 *) ((value12) + ((value1 << 2)));
    flagCopy = value0;
    zero = 0u;
    value0 = *(const u8 *) ((value1) + (kindRemainderCopy));
    if (flagCopy != zero) {
        value0 = 0u;
    }
    return value0;
}

u32 GetItemObjectResponseByKind(s32 flagBit, s32 itemKind, s32 kindHundreds, s32 kindRemainder, s32 kindDataValue) {
    u32 response = data_0216ba2c[kindHundreds][itemKind][kindRemainder];
    if (flagBit != 0 && response == 1 && kindDataValue != 0) {
        response = 2;
    }
    return response;
}

s32 func_020d6be0(Kart *kart, MapObject *mapObject) {
    s32 kindRemainder = mapObject->mKind;
    s32 kindHundreds = 0;
    s32 flagBit;
    s32 response;
    s32 buf[2];
    flagBit = mapObject->mFlags & 0x800;
    while (kindRemainder >= 100) {
        kindRemainder -= 100;
        kindHundreds++;
    }
    if (mapObject->mKindData->mUnk_00 != NULL) {
        response = data_0216b9cc[kindHundreds][kart->mItemEffect][kindRemainder];
        if (flagBit != 0 && response != 2 && response != 4) {
            response = 0;
        }
        buf[0] = response;
        response = data_0216b96c[kindHundreds][kart->mItemEffect][kindRemainder];
        if (response == 1) {
            response = flagBit != 0 ? 2 : 0;
        }
        buf[1] = response;
        if ((mapObject->mFlags & 0x80) == 0) {
            buf[1] = mapObject->mKindData->mUnk_00(mapObject, kart, &buf[0], &buf[1]);
        }
        if (gRaceSetup->mMode == MODE_MISSION_RUN && buf[0] == 1 && gRaceSetup->mMode == MODE_MISSION_RUN) {
            func_ov001_0218175c(mapObject->mKind);
        }
        return buf[1];
    }
    response = data_0216b96c[kindHundreds][kart->mItemEffect][kindRemainder];
    if (response != 1) {
        return response;
    }
    return flagBit != 0 ? 2 : 0;
}

s32 func_020d6a54(ItemObject *itemObject, MapObject *mapObject, s32 *firstResponseOut) {
    s32 kindRemainder = mapObject->mKind;
    s32 kindHundreds = 0;
    s32 flagBit = mapObject->mFlags & 0x800;
    s32 response;
    s32 buf[2];
    s32 kindDataValue;
    while (kindRemainder >= 100) {
        kindRemainder -= 100;
        kindHundreds++;
    }
    if (mapObject->mKindData->mUnk_04 != NULL) {
        response = data_0216bb7c[kindHundreds][itemObject->mKind][kindRemainder];
        if (flagBit != 0) {
            response = 0;
        }
        buf[0] = response;
        kindDataValue = mapObject->mKindData->mUnk_20;
        response = data_0216ba2c[kindHundreds][itemObject->mKind][kindRemainder];
        if (flagBit != 0 && response == 1 && kindDataValue != 0) {
            response = 2;
        }
        buf[1] = response;
        if ((mapObject->mFlags & 0x80) == 0) {
            buf[1] = mapObject->mKindData->mUnk_04(mapObject, itemObject, &buf[0], &buf[1]);
        }
        if (gRaceSetup->mMode == MODE_MISSION_RUN && buf[0] == 1 && gRaceSetup->mMode == MODE_MISSION_RUN) {
            func_ov001_0218175c(mapObject->mKind);
        }
        if (firstResponseOut != NULL) {
            *firstResponseOut = buf[0];
        }
        return buf[1];
    }
    if (firstResponseOut != NULL) {
        *firstResponseOut = 0;
    }
    kindDataValue = mapObject->mKindData->mUnk_20;
    response = data_0216ba2c[kindHundreds][itemObject->mKind][kindRemainder];
    if (flagBit != 0 && response == 1 && kindDataValue != 0) {
        response = 2;
    }
    return response;
}

s32 DoesKartRespondToMapObject(s32 itemEffect, MapObject *mapObject) {
    s32 kindRemainder = mapObject->mKind;
    s32 kindHundreds = 0;
    s32 response;
    s32 flagBit;
    while (kindRemainder >= 100) {
        kindRemainder -= 100;
        kindHundreds++;
    }
    flagBit = mapObject->mFlags & 0x800;
    response = data_0216b96c[kindHundreds][itemEffect][kindRemainder];
    if (response == 1) {
        response = flagBit != 0 ? 2 : 0;
    }
    return response != 0 ? 1 : 0;
}

s32 DoesItemObjectRespondToMapObject(s32 itemKind, MapObject *mapObject) {
    s32 kindRemainder = mapObject->mKind;
    s32 kindHundreds = 0;
    s32 response;
    s32 flagBit;
    s32 kindDataValue;
    while (kindRemainder >= 100) {
        kindRemainder -= 100;
        kindHundreds++;
    }
    flagBit = mapObject->mFlags & 0x800;
    kindDataValue = mapObject->mKindData->mUnk_20;
    response = data_0216ba2c[kindHundreds][itemKind][kindRemainder];
    if (flagBit != 0 && response == 1 && kindDataValue != 0) {
        response = 2;
    }
    return response != 0 ? 1 : 0;
}

s32 func_020d6910(s32 itemKind, MapObject *mapObject) {
    MapObject *object = mapObject;
    s32 kindRemainder = object->mKind;
    s32 kindHundreds = 0;
    s32 response;
    s32 flagBit;
    while (kindRemainder >= 100) {
        kindRemainder -= 100;
        kindHundreds++;
    }
    flagBit = object->mFlags & 0x800;
    response = data_0216bb7c[kindHundreds][itemKind][kindRemainder];
    if (flagBit != 0) {
        response = 0;
    }
    return response;
}

Unk02156adc *CreateRockKindData(void) {
    Unk02156adc *kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *kindData = data_02156adc;
    kindData->mUnk_38 = 0x3e8000;
    kindData->mUnk_3c = -0x3e8000;
    return kindData;
}

RockDrawList *CreateRockDrawList(void) {
    RockDrawList *drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x5c);
    data_0217b650 = drawList;
    *drawList = data_02156a80;
    func_020d49d8(&data_0217b650);
    return data_0217b650;
}

RockDrawList *CreateRock2DrawList(void) {
    RockDrawList *drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x5c);
    data_0217b650 = drawList;
    *drawList = data_02156a24;
    func_020d49d8(&data_0217b650);
    return data_0217b650;
}

RockUpdateList *CreateRockUpdateList(void) {
    RockUpdateList *updateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    data_0217b654 = updateList;
    *updateList = data_021569fc;
    func_020e6f50(&data_0217b654);
    return data_0217b654;
}

void SetupDrawRock(void) {
    s32 pairIndex = (s32) (GetRaceUpdateFrames() << 25 >> 16) >> 4;
    MTX_RotY33_(data_0217b650->mUnk_2c.mUnk_00, gPairsByAngle[pairIndex * 2], gPairsByAngle[pairIndex * 2 + 1]);
}

void func_020d655c(void *a, Unk020d655c *rock, void *c, s32 alpha) {
    Vec3 tiltAxis;
    Vec3 crossProduct;
    Vec3 xAxis;
    Vec3 yAxis;
    RockShadowMatrix *shadowMatrix;
    s32 dot;
    if (func_020b2ec0() == 0) {
        xAxis = rock->mUnk_00.mMatrix.mUnk_00[0];
        yAxis = rock->mUnk_00.mMatrix.mUnk_00[1];
        tiltAxis.x = ((s64) rock->mUnk_00.mUnk_10.z * (s64) rock->mUnk_118) >> 12;
        tiltAxis.z = -(s32) (((s64) rock->mUnk_00.mUnk_10.x * (s64) rock->mUnk_118) >> 12);
        tiltAxis.y = 0;
        Vec3CrossUnrounded(&tiltAxis, &xAxis, &crossProduct);
        VEC_Add(&xAxis, &crossProduct, &xAxis);
        Vec3NormalizeAndGetLengthUnchecked(&xAxis, &rock->mUnk_00.mMatrix.mUnk_00[0]);
        Vec3CrossUnrounded(&tiltAxis, &yAxis, &crossProduct);
        VEC_Add(&yAxis, &crossProduct, &yAxis);
        dot = VEC_DotProduct(&rock->mUnk_00.mMatrix.mUnk_00[0], &yAxis);
        yAxis.x = yAxis.x - (s32) (((s64) rock->mUnk_00.mMatrix.mUnk_00[0].x * (s64) dot) >> 12);
        yAxis.y = yAxis.y - (s32) (((s64) rock->mUnk_00.mMatrix.mUnk_00[0].y * (s64) dot) >> 12);
        yAxis.z = yAxis.z - (s32) (((s64) rock->mUnk_00.mMatrix.mUnk_00[0].z * (s64) dot) >> 12);
        Vec3NormalizeAndGetLengthUnchecked(&yAxis, &rock->mUnk_00.mMatrix.mUnk_00[1]);
        Vec3CrossUnrounded(&rock->mUnk_00.mMatrix.mUnk_00[0], &rock->mUnk_00.mMatrix.mUnk_00[1],
                           &rock->mUnk_00.mMatrix.mUnk_00[2]);
    }
    rock->mUnk_00.mMatrix.mUnk_00[3].x = rock->mUnk_00.mPos.x >> 4;
    rock->mUnk_00.mMatrix.mUnk_00[3].y = rock->mUnk_00.mPos.y >> 4;
    rock->mUnk_00.mMatrix.mUnk_00[3].z = rock->mUnk_00.mPos.z >> 4;
    DrawNsbmdWithMatrixAndMaxAlpha(gRock, &rock->mUnk_00.mMatrix, &rock->mUnk_00.mScale, alpha);
    shadowMatrix = &data_0217b650->mUnk_2c;
    shadowMatrix->mUnk_24.x = rock->mUnk_00.mPos.x >> 4;
    shadowMatrix->mUnk_24.y = rock->mUnk_00.mPos.y >> 4;
    shadowMatrix->mUnk_24.z = rock->mUnk_00.mPos.z >> 4;
    DrawShadowWithMaxAlpha(gRockShadow, &data_0217b650->mUnk_2c, &rock->mUnk_00.mScale, alpha);
}

void func_020d6538(Unk020d6538_a *emitter, Unk020d634c *params) {
    emitter->mUnk_5c = params->mUnk_00;
    emitter->mUnk_64 = params->mUnk_04;
    emitter->mUnk_68 = params->mUnk_06;
    emitter->mUnk_6c = params->mUnk_08;
}
