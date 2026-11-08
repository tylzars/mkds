#include "Main/Unknown/code_021052f0.h"
#include "Main/Unknown/code_020d22c0.h"

#include "Main/Unknown/code_021052fc.h"
#include "Main/Unknown/code_021053d8.h"

void ParkPooledMapObject(u32 pooledMapObject) {
    u32 parkedObject = pooledMapObject;
    u32 value12;
    ParkMapObject((void *) parkedObject);
}

void SetPooledMapObjectFromItem(Unk021052fc *object, s32 alpha, Vec3 *scale) {
    object->mUnk_00.mPos = *object->mUnk_fc;
    if (alpha < 1) {
        alpha = 1;
    }
    object->mUnk_00.mAlpha = alpha;
    object->mUnk_00.mScale.x = ((s64) scale->x * 0x666) >> 12;
    object->mUnk_00.mScale.y = ((s64) scale->y * 0x666) >> 12;
    object->mUnk_00.mScale.z = ((s64) scale->z * 0x666) >> 12;
}

void AdvancePooledMapObject(Unk021052fc *object) {
    object->mUnk_a0 = object->mUnk_a0 + 1;
    if (object->mUnk_a0 >= 0x12c) {
        object->mUnk_a0 = 0;
    }
    object->mUnk_a2 = object->mUnk_a2 + 1;
    if (object->mUnk_a2 >= 0x82) {
        object->mUnk_a2 = 0;
    }
}

void SetPooledMapObjectCallback(Unk021052fc *object, void *callback, ItemFBox *owner) {
    object->mUnk_100 = callback;
    object->mUnk_104 = owner;
}
