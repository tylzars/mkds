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
    func_020ea588(&gMkdEfBubble, nsbmd, NULL);
    func_02084968(gMkdEfBubble, 0x3f, 2, 0x294a);
    gMkdEfBubbleNsbta = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x38);
    func_020ea514(1, gMkdEfBubble, gMkdEfBubbleNsbta, nsbmd, FindCourseMapObjFile("mkd_ef_bubble.nsbta"));
    func_02087cfc(gMkdEfBubbleNsbta, 0, 1);
}

void InitMkdEfBubble(MkdEfBubbleObject *a, CourseMapRow *b) {
    func_02046be8(&a->mUnk_00.mStateMachine, data_0216bfc0, 2, a);
    a->mUnk_a0 = b->mUnk_28;
    a->mUnk_ac = a->mUnk_00.mPos.y;
    a->mUnk_a4 = a->mUnk_00.mPos.y - 0x10000;
    a->mUnk_00.mUnk_10.x = 0;
    a->mUnk_00.mUnk_10.y = 0;
    a->mUnk_00.mUnk_10.z = 0;
    a->mUnk_a8 = 0;
    a->mUnk_00.mStateMachine.mNextState = 0;
    a->mUnk_00.mStateMachine.mNextStateRequested = 1;
    func_020e516c(&a->mUnk_b0, &a->mUnk_00.mPos, ((s64) a->mUnk_00.mScale.x * 0x18000) >> 12, 0xd);
    a->mUnk_00.mFlags |= data_02158740;
}
#pragma thumb off

Unk020de390 *func_020df678(void) {
    Unk020de390 *p;

    p = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *p = data_02158700;
    return p;
}

Unk020de2d8 *func_020df61c(void) {
    data_0217b758 = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    *data_0217b758 = data_021586d8;
    func_020e6f50(&data_0217b758);
    return data_0217b758;
}

void func_020df58c(void) {
    s32 x;

    x = gPairsByAngle[(data_0217b750 >> 4) * 2];
    data_0217b754 = ((s64) x * 0x4000) >> 12;
    data_0217b750 += 0x2d8;
    data_0217b75c = 0xf00 - (x >> 4);
    data_0217b760.x = 0x1666;
    data_0217b760.y = 0x1666;
    data_0217b760.z = 0x1666;
}

void func_020df48c(void *a, Unk020de6a8 *b) {
    if (b->mUnk_108.mUnk_00.mUnk_08 != 0xffff) {
        if (func_020d84e4(&b->mUnk_108) != 0) {
            if (b->mUnk_108.mUnk_00.mUnk_1c->mUnk_10 != 0) {
                func_020d859c(&b->mUnk_108, 0, 1);
            }
        }
        func_020d8c74(&b->mUnk_108.mUnk_00, &b->mUnk_000.mPos);
        if (b->mUnk_108.mUnk_00.mUnk_1c->mUnk_0d != 0 && b->mUnk_108.mUnk_00.mUnk_20->mUnk_0d != 0) {
            b->mUnk_000.mFlags |= data_021586d4;
        } else {
            b->mUnk_000.mFlags &= ~0x20;
        }
        b->mUnk_000.mPos.y += data_0217b754;
        b->mUnk_000.mPos.y += 0x10000;
    }
    if (b->mUnk_0b0 == 0) {
        func_020e5668(&b->mUnk_0b4, &b->mUnk_000.mPos);
    }
    UpdateItemBox(a, b);
}
