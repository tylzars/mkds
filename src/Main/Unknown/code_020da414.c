#include "Main/Unknown/code_020da414.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020d4970.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_02084000.h"
#include "code_02013740.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_020a02c8.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/unk_02158000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0216b000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020d7da8.h"
#include "Main/Unknown/code_020d8b88.h"

// placeholder: an object of the original file that is not known yet; it only sets the order of the tables below
const u8 data_020da414_pad[1] = {1};

#pragma thumb on

void InitKuribo(Kuribo *kuribo, CourseMapRow *row) {
    CourseMapGroupEntry *startEntry;
    Vec3 *zeroedVector;
    Unk020e005c_080 *stateMachine;
    kuribo->mUnk_100 = 0x1f;
    if (row != NULL) {
        InitGroupFollower(&kuribo->mUnk_cc, row, (row->mUnk_28 << 11) / 100);
        startEntry = GetCourseMapGroupEntry(row->mUnk_26, row->mUnk_2e);
        kuribo->mUnk_a0 = startEntry->mPos.y;
        kuribo->mUnk_f8 = row->mUnk_28 * 0xb4 / 100;
        kuribo->mUnk_fc = row->mUnk_2a == 0;
        func_02046be8(&kuribo->mUnk_00.mStateMachine, data_0216be68, 6, kuribo);
        SetupGroupFollowerAtEntry(&kuribo->mUnk_cc, kuribo->mUnk_00.mCourseMapRow->mUnk_2e, 1);
        GetGroupFollowerCurveXz(&kuribo->mUnk_cc, &kuribo->mUnk_00.mPos);
        kuribo->mUnk_00.mPos.y = kuribo->mUnk_a0;
        zeroedVector = &kuribo->mUnk_00.mUnk_10;
        zeroedVector->x = 0;
        zeroedVector->y = 0;
        zeroedVector->z = 0;
        {
            Quaternion identityA = {0, 0, 0, 0x1000};
            kuribo->mUnk_a4 = identityA;
        }
        {
            Quaternion identityB = {0, 0, 0, 0x1000};
            kuribo->mUnk_b4 = identityB;
        }
        kuribo->mUnk_f0 = 0;
        kuribo->mUnk_f4 = 0;
        stateMachine = &kuribo->mUnk_00.mStateMachine;
        stateMachine->mNextState = 0;
        stateMachine->mNextStateRequested = 1;
    } else {
        kuribo->mUnk_cc.mGroupIndex = 0xffff;
        kuribo->mUnk_a0 = 0;
        kuribo->mUnk_fc = 0;
        func_02046be8(&kuribo->mUnk_00.mStateMachine, data_0216be68, 6, kuribo);
        kuribo->mUnk_f8 = 0x1000;
        {
            Quaternion identityA = {0, 0, 0, 0x1000};
            kuribo->mUnk_a4 = identityA;
        }
        {
            Quaternion identityB = {0, 0, 0, 0x1000};
            kuribo->mUnk_b4 = identityB;
        }
        SetStateMachineState(&kuribo->mUnk_00.mStateMachine, 1);
        kuribo->mUnk_00.mUnk_10.x = 0;
        kuribo->mUnk_00.mUnk_10.y = 0;
        kuribo->mUnk_00.mUnk_10.z = 0;
    }
}

#pragma thumb off

Unk020da414 *func_020da414(void) {
    Unk020da414 *object;
    object = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    {
        Unk020da414 zeros = {0};
        *object = zeros;
    }
    return object;
}
