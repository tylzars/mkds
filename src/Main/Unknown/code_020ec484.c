#include "Main/Unknown/code_020ec484.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d50ec.h"

#include "Main/Unknown/code_020ec490.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020ec504.h"
#include "Main/Unknown/unk_02159000.h"

void EnterPushedObjectState1(int object) {
    u16 newSlot;
    *(u16 *) (object + 2) = *(u16 *) (object + 2) | (*(u16 *) &data_02159578);
    newSlot = FreeCollisionSlot(*(s16 *) (object + 100));
    *(u16 *) (object + 100) = newSlot;
}

void UpdatePushedObjectState1(Unk020ec490 *object) {
    if (object->mUnk_a8) {
        object->mUnk_ac = object->mUnk_ac + object->mUnk_ae;
    } else {
        object->mUnk_ac = object->mUnk_ac - object->mUnk_ae;
    }
    object->mUnk_10.y -= object->mUnk_a4;
    VEC_Add(&object->mUnk_04, &object->mUnk_10, &object->mUnk_04);
    if (object->mUnk_04.y < object->mUnk_a0) {
        object->mUnk_90 = 2;
        object->mUnk_92 = 1;
    }
}

void EnterPushedObjectState2(u32 objectAddress) {
    u32 object = objectAddress;
    u32 value12;
    ParkMapObject((void *) object);
}
