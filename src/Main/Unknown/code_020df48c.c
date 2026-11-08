#include "Main/Unknown/code_020df48c.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020debec.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_02087cfc.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d8000.h"
#include "Main/Unknown/code_020d8c74.h"
#include "Main/Unknown/code_020e516c.h"
#include "Main/Unknown/code_020e5668.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_020ea514.h"
#include "Main/Unknown/code_020ea588.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0216b000.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on
void CreateMkdEfBubble(void) {
    void *nsbmd;

    nsbmd = FindCourseMapObjFile("mkd_ef_bubble.nsbmd");
    CreateNsbmd(&gMkdEfBubble, nsbmd, NULL);
    func_02084968(gMkdEfBubble, 0x3f, 2, 0x294a);
    gMkdEfBubbleNsbta = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x38);
    InitModelAnimationWithEntries(1, gMkdEfBubble, gMkdEfBubbleNsbta, nsbmd,
                                  FindCourseMapObjFile("mkd_ef_bubble.nsbta"));
    func_02087cfc(gMkdEfBubbleNsbta, 0, 1);
}

void InitMkdEfBubble(MkdEfBubbleObject *bubble, CourseMapRow *row) {
    InitStateMachine(&bubble->mUnk_00.mStateMachine, data_0216bfc0, 2, bubble);
    bubble->mUnk_a0 = row->mUnk_28;
    bubble->mUnk_ac = bubble->mUnk_00.mPos.y;
    bubble->mUnk_a4 = bubble->mUnk_00.mPos.y - 0x10000;
    bubble->mUnk_00.mUnk_10.x = 0;
    bubble->mUnk_00.mUnk_10.y = 0;
    bubble->mUnk_00.mUnk_10.z = 0;
    bubble->mUnk_a8 = 0;
    bubble->mUnk_00.mStateMachine.mNextState = 0;
    bubble->mUnk_00.mStateMachine.mNextStateRequested = 1;
    RefreshShadowMatrix(&bubble->mUnk_b0, &bubble->mUnk_00.mPos, ((s64) bubble->mUnk_00.mScale.x * 0x18000) >> 12, 0xd);
    bubble->mUnk_00.mFlags |= data_02158740;
}
#pragma thumb off

Unk020de390 *CreateGroupItemBoxKindData(void) {
    Unk020de390 *kindData;

    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *kindData = data_02158700;
    return kindData;
}

Unk020de2d8 *CreateGroupItemBoxUpdateList(void) {
    gGroupItemBoxUpdateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    *gGroupItemBoxUpdateList = data_021586d8;
    SetUpdateListSlot(&gGroupItemBoxUpdateList);
    return gGroupItemBoxUpdateList;
}

void func_020df58c(void) {
    s32 sine;

    sine = gPairsByAngle[(data_0217b750 >> 4) * 2];
    data_0217b754 = ((s64) sine * 0x4000) >> 12;
    data_0217b750 += 0x2d8;
    data_0217b75c = 0xf00 - (sine >> 4);
    data_0217b760.x = 0x1666;
    data_0217b760.y = 0x1666;
    data_0217b760.z = 0x1666;
}

void UpdateGroupItemBox(void *unused, ItemBox *itemBox) {
    if (itemBox->mFollower.mUnk_00.mGroupIndex != 0xffff) {
        if (AdvanceGroupFollowerWithSpeeds(&itemBox->mFollower) != 0) {
            if (itemBox->mFollower.mUnk_00.mFromEntry->mUnk_10 != 0) {
                SetupGroupFollowerWithSpeeds(&itemBox->mFollower, 0, 1);
            }
        }
        GetGroupFollowerCurvePosition(&itemBox->mFollower.mUnk_00, &itemBox->mUnk_000.mPos);
        if (itemBox->mFollower.mUnk_00.mFromEntry->mUnk_0d != 0 && itemBox->mFollower.mUnk_00.mToEntry->mUnk_0d != 0) {
            itemBox->mUnk_000.mFlags |= data_021586d4;
        } else {
            itemBox->mUnk_000.mFlags &= ~0x20;
        }
        itemBox->mUnk_000.mPos.y += data_0217b754;
        itemBox->mUnk_000.mPos.y += 0x10000;
    }
    if (itemBox->mUnk_0b0 == 0) {
        SetShadowPositionXZ(&itemBox->mUnk_0b4, &itemBox->mUnk_000.mPos);
    }
    UpdateItemBox(unused, itemBox);
}
