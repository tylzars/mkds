#include "Main/Unknown/code_020ec484.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d50ec.h"

#include "Main/Unknown/code_020ec490.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020ec504.h"
#include "Main/Unknown/unk_02159000.h"

void EnterPushedObjectState1(MapObject *object) {
    u16 newSlot;
    object->mFlags = object->mFlags | (*(u16 *) &data_02159578);
    newSlot = FreeCollisionSlot(object->mCollisionSlotIndex);
    object->mCollisionSlotIndex = newSlot;
}

void UpdatePushedObjectState1(Unk020e43a8 *object) {
    if (object->mUnk_0a8) {
        object->mUnk_0ac = object->mUnk_0ac + object->mUnk_0ae;
    } else {
        object->mUnk_0ac = object->mUnk_0ac - object->mUnk_0ae;
    }
    object->mUnk_00.mUnk_10.y -= object->mUnk_0a4;
    VEC_Add(&object->mUnk_00.mPos, &object->mUnk_00.mUnk_10, &object->mUnk_00.mPos);
    if (object->mUnk_00.mPos.y < object->mUnk_0a0) {
        object->mUnk_00.mStateMachine.mNextState = 2;
        object->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterPushedObjectState2(u32 objectAddress) {
    u32 object = objectAddress;
    u32 value12;
    ParkMapObject((void *) object);
}
