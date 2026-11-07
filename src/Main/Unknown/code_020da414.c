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

void InitKuribo(Kuribo *a, CourseMapRow *b) {
    Unk02042044 *e;
    Vec3 *q;
    Unk020e005c_080 *o;
    a->mUnk_100 = 0x1f;
    if (b != NULL) {
        func_020d7da8(&a->mUnk_cc, b, (b->mUnk_28 << 11) / 100);
        e = GetCourseMapGroupEntry(b->mUnk_26, b->mUnk_2e);
        a->mUnk_a0 = e->mUnk_00.y;
        a->mUnk_f8 = b->mUnk_28 * 0xb4 / 100;
        a->mUnk_fc = b->mUnk_2a == 0;
        func_02046be8(&a->mUnk_00.mStateMachine, data_0216be68, 6, a);
        func_020d90a8(&a->mUnk_cc, a->mUnk_00.mCourseMapRow->mUnk_2e, 1);
        func_020d8b88(&a->mUnk_cc, &a->mUnk_00.mPos);
        a->mUnk_00.mPos.y = a->mUnk_a0;
        q = &a->mUnk_00.mUnk_10;
        q->x = 0;
        q->y = 0;
        q->z = 0;
        {
            Quaternion x = {0, 0, 0, 0x1000};
            a->mUnk_a4 = x;
        }
        {
            Quaternion y = {0, 0, 0, 0x1000};
            a->mUnk_b4 = y;
        }
        a->mUnk_f0 = 0;
        a->mUnk_f4 = 0;
        o = &a->mUnk_00.mStateMachine;
        o->mNextState = 0;
        o->mNextStateRequested = 1;
    } else {
        a->mUnk_cc.mUnk_08 = 0xffff;
        a->mUnk_a0 = 0;
        a->mUnk_fc = 0;
        func_02046be8(&a->mUnk_00.mStateMachine, data_0216be68, 6, a);
        a->mUnk_f8 = 0x1000;
        {
            Quaternion x = {0, 0, 0, 0x1000};
            a->mUnk_a4 = x;
        }
        {
            Quaternion y = {0, 0, 0, 0x1000};
            a->mUnk_b4 = y;
        }
        SetStateMachineState(&a->mUnk_00.mStateMachine, 1);
        a->mUnk_00.mUnk_10.x = 0;
        a->mUnk_00.mUnk_10.y = 0;
        a->mUnk_00.mUnk_10.z = 0;
    }
}

#pragma thumb off

Unk020da414 *func_020da414(void) {
    Unk020da414 *p;
    p = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    {
        Unk020da414 v = {0};
        *p = v;
    }
    return p;
}
