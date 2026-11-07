#include "Main/Unknown/code_020e5684.h"

#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_020ea588.h"
#include "Main/Unknown/code_020e57f4.h"
#include "Main/Unknown/code_020e57fc.h"
#include "Main/Unknown/code_020e5850.h"
#include "Main/Unknown/code_020e5854.h"
#include "Main/Unknown/code_020e58b8.h"
#include "Main/Unknown/code_020e58c4.h"
#include "Main/Unknown/code_020e58fc.h"
#include "Main/Unknown/code_020e5900.h"
#include "Main/Unknown/code_020e5950.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020d6dc0.h"
#include "Main/Unknown/code_020ec538.h"
#include "Main/Unknown/code_020ec000.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_020ec884.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020e5b88.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_020ec1fc.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_020e337c.h"
#include "Main/Unknown/code_020e5c6c.h"

void DrawObPakkunSf(u32 a, Unk020e43a8 *b, u32 c, u16 d) {
    MtxFx43 *v1;
    gObPakkunSf->mUnk_18 = ((*(u16 *) &b->mUnk_a0.mUnk_18.x & 0x10) >> 4);
    if (b->mUnk_00.mStateMachine.mState == 0) {
        v1 = func_020e6cbc(&b->mUnk_00.mPos);
        func_020e67c4(gObPakkunSf, v1, &b->mUnk_00.mScale, 0, d);
        return;
    }
    v1 = func_020e6cbc(&b->mUnk_00.mPos);
    func_020e66e4(gObPakkunSf, v1, *(u16 *) &b->mUnk_a0.mUnk_0c.x, &b->mUnk_00.mScale, 0, d);
}

void UpdateObPakkunSf(u32 a, Unk020e43a8 *p) {
    Unk0210b7a8 s;
    s32 n;

    *(u16 *) &p->mUnk_a0.mUnk_18 = *(u16 *) &p->mUnk_a0.mUnk_18 + 1;
    if ((*(u16 *) &p->mUnk_a0.mUnk_18 & 0x1f) == 0 && (p->mUnk_00.mDistanceSquaredAndFlags & 4) == 0) {
        if (p->mUnk_00.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
            n = 2;
        } else if (p->mUnk_00.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
            n = 3;
        } else {
            n = 4;
        }
        s.mUnk_00 = 0x163;
        s.mUnk_04 = &p->mUnk_00.mPos;
        s.mUnk_08 = n;
        s.mUnk_0c = GetHorizontalCameraDistanceSquared(&p->mUnk_00.mPos);
        func_0210b7a8(&s);
    }
    AdvanceStateMachine(&p->mUnk_00.mStateMachine);
}

u8 CollideKartWithObPakkunSf(Unk020e43a8 *p, void *a, u8 *b, u8 *c) {
    if (func_020ec450(p, a, b) != FALSE) {
        func_020d26f8(&p->mUnk_00, a);
    }
    return *c;
}

u8 CollideItemObjectWithObPakkunSf(Unk020e43a8 *p, void *a, u8 *b, u8 *c) {
    func_020ec41c(p, a, b);
    return *c;
}

#pragma thumb on

void CreateObPakkunSf(void) {
    void *v1;
    void *v2;
    v1 = FindCourseMapObjFile(gObPakkunSfNsbmdName);
    v2 = FindCourseMapObjFile(gObPakkunSfNsbtpName);
    func_020e6488((Unk020e6488 **) (((u32 *) &gObPakkunSf)), v1, v2, 0);
    func_020e6ab8(gObPakkunSf);
}

#pragma thumb off

#pragma thumb on

void InitObPakkunSf(Unk020e43a8 *p) {
    p->mUnk_00.mPos.y = p->mUnk_00.mPos.y + (s32) (((s64) p->mUnk_00.mScale.y * 0xa000) >> 12);
    *(u16 *) &p->mUnk_a0.mUnk_18.x = 0;
    func_020ec854(p, p->mUnk_00.mPos.y - 0x18000, 0x400, 0x800, 0x4000, 0x1800);
    func_020ec884(p);
}

#pragma thumb off

Unk020e5a9c *CreateSecondHandKindData(void) {
    Unk020e5a9c *p;
    p = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *p = *(Unk020e5a9c *) data_02159140;
    return p;
}

Unk020e5a40 *CreateSecondHandDrawList(void) {
    Unk020e5a40 *p;
    p = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    data_0217b824 = p;
    *p = *(Unk020e5a40 *) data_02159114;
    func_020d49d8(&data_0217b824);
    return data_0217b824;
}

Unk020e59e4 *CreateSecondHandUpdateList(void) {
    Unk020e59e4 *p;
    p = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    data_0217b81c = p;
    *p = *(Unk020e59e4 *) data_021590ec;
    func_020e6f50(&data_0217b81c);
    return data_0217b81c;
}

void DrawSecondHand(u32 a, Unk020e43a8 *p, u32 b, u32 c) {
    p->mUnk_00.mMatrix.mUnk_00[3].x = p->mUnk_00.mPos.x >> 4;
    p->mUnk_00.mMatrix.mUnk_00[3].y = p->mUnk_00.mPos.y >> 4;
    p->mUnk_00.mMatrix.mUnk_00[3].z = p->mUnk_00.mPos.z >> 4;
    DrawNsbmdWithMatrixAndMaxAlpha(gSecondHand, &p->mUnk_00.mMatrix, &p->mUnk_00.mScale, c);
}

void UpdateSecondHand(u32 a, Unk020e43a8 *p) {
    AdvanceStateMachine(&p->mUnk_00.mStateMachine);
    QuaternionMultiplyAngleAroundY(&p->mUnk_a0.mUnk_0c.y, p->mUnk_00.mAngle, &p->mUnk_a0);
    Matrix3x3FromQuaternion(&p->mUnk_00.mMatrix, &p->mUnk_a0);
}

void EnterSecondHandState0(Unk020e5950 *p0) {
    p0->mUnk_c8 = 0x0u;
}

void UpdateSecondHandState0(Unk020e43a8 *p) {
    p->mUnk_c8 = p->mUnk_c8 + p->mUnk_cc;
    p->mUnk_00.mAngle = p->mUnk_00.mAngle + (s16) (((s64) p->mUnk_c8 * p->mUnk_c6) >> 12);
    if (p->mUnk_00.mStateMachine.mStateFrames > *(u16 *) &p->mUnk_a0.mUnk_18.z) {
        p->mUnk_00.mStateMachine.mNextState = 1;
        p->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
}

u32 func_020e58fc(u32 p0) {
    return p0;
}

void UpdateSecondHandState1(Unk020e43a8 *p) {
    p->mUnk_00.mAngle = p->mUnk_00.mAngle + p->mUnk_c6;
    if (*((u16 *) &p->mUnk_a0.mUnk_18.z + 1) == 0) {
        return;
    }
    if (p->mUnk_00.mStateMachine.mStateFrames > *((u16 *) &p->mUnk_a0.mUnk_18.z + 1)) {
        p->mUnk_00.mStateMachine.mNextState = 2;
        p->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterSecondHandState2(Unk020e58b8 *p0) {
    p0->mUnk_c8 = 0x4000u;
}

void UpdateSecondHandState2(Unk020e43a8 *p) {
    p->mUnk_c8 = p->mUnk_c8 - p->mUnk_cc;
    p->mUnk_00.mAngle = p->mUnk_00.mAngle + (s16) (((s64) p->mUnk_c8 * p->mUnk_c6) >> 12);
    if (p->mUnk_00.mStateMachine.mStateFrames > *(u16 *) &p->mUnk_a0.mUnk_18.z) {
        p->mUnk_c6 = -p->mUnk_c6;
        p->mUnk_00.mStateMachine.mNextState = 3;
        p->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
}

u32 func_020e5850(u32 p0) {
    return p0;
}

void UpdateSecondHandState3(Unk020e43a8 *p) {
    if (p->mUnk_00.mStateMachine.mStateFrames > p->mUnk_c4) {
        p->mUnk_00.mStateMachine.mNextState = 0;
        p->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
}

s32 CollideKartWithSecondHand(Unk020e43a8 *p, Unk020e57fc *q, s32 a, u8 *b) {
    u32 x;

    x = q->mUnk_29c;
    if (x == 1 || x == 3) {
        p->mUnk_00.mDistanceSquaredAndFlags |= data_021590e8;
    }
    return *b;
}

u32 func_020e57f4(u32 p0, u32 p1, u32 p2, u32 p3) {
    return (*OFFSET_PTR(const u8, p3, 0));
}

void ComputeSphereHitOnSecondHand(Unk020e43a8 *p, Vec3 *a, s32 b, Vec3 *c) {
    Vec3 s;
    s32 y;

    y = p->mUnk_00.mExtent.y;
    s.x = p->mUnk_00.mExtent.x;
    s.y = y;
    s.z = 0;
    ComputeSphereHitOnRotatedBox(a, &p->mUnk_00.mPos, &p->mUnk_00.mMatrix.mUnk_00[0], &p->mUnk_00.mExtent, &s, b, c);
}

#pragma thumb on

void CreateSecondHand(void) {
    func_020ea588(&gSecondHand, FindCourseMapObjFile(gSecondHandNsbmdName), NULL);
    func_02084968(gSecondHand, 0x3f, 2, 0x294a);
}

void InitSecondHand(Unk020e43a8 *p, Unk020e5684 *q) {
    p->mUnk_00.mExtent.y = ((s64) p->mUnk_00.mScale.x * 0x4b000) >> 12;
    func_02046be8(&p->mUnk_00.mStateMachine, (UnkFunc *const *) data_0216c240, 4, p);
    QuaternionFromVec3Degrees(&q->mUnk_0c, (u32 *) &p->mUnk_a0.mUnk_00);
    *(Quaternion *) &p->mUnk_a0.mUnk_0c.y = *(Quaternion *) &p->mUnk_a0.mUnk_00;
    *(s16 *) &p->mUnk_a0.mUnk_18.z = q->mUnk_2c;
    *((s16 *) &p->mUnk_a0.mUnk_18.z + 1) = q->mUnk_2a;
    p->mUnk_c4 = q->mUnk_2e;
    p->mUnk_c6 = (q->mUnk_28 << 7) / 0x64;
    if (q->mUnk_30 != 0) {
        p->mUnk_c6 = -p->mUnk_c6;
    }
    p->mUnk_00.mAngle = 0;
    if (*(u16 *) &p->mUnk_a0.mUnk_18.z != 0) {
        p->mUnk_cc = 0x1000 / *(u16 *) &p->mUnk_a0.mUnk_18.z;
    } else {
        p->mUnk_cc = 0;
    }
    p->mUnk_c8 = 0;
    p->mUnk_00.mStateMachine.mNextState = 0;
    p->mUnk_00.mStateMachine.mNextStateRequested = 1;
    p->mUnk_00.mFlags |= data_021590b0;
}

#pragma thumb off
