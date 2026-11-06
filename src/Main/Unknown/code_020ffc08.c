#include "Main/Unknown/code_020ffc08.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020ea670.h"

#include "Main/Unknown/code_020ffc4c.h"
#include "Main/Unknown/code_020ffcf8.h"
#include "Main/Unknown/code_020ffd04.h"
#include "Main/Unknown/code_020ffd3c.h"
#include "Main/Unknown/code_020ffd40.h"
#include "Main/Unknown/code_020ffd94.h"
#include "Main/Unknown/code_020ffda0.h"
#include "Main/Unknown/code_020ffdc0.h"
#include "Main/Unknown/code_020ffdc4.h"
#include "Main/Unknown/code_020ffdd4.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0215a000.h"
#include "code_02146cbc.h"

Unk02100004 *func_02100004(void) {
    Unk02100004 *p;

    p = HeapAlloc(GetHeap(func_020364e8()), 0x40);
    {
        Unk02100004 v1 = {0};

        *p = v1;
    }
    return p;
}

Unk020fffa8 *func_020fffa8(void) {
    Unk020fffa8 *p;

    p = HeapAlloc(GetHeap(func_020364e8()), 0x28);
    data_0217c624 = p;
    *p = data_0215a12c;
    func_020e6f50(&data_0217c624);
    return data_0217c624;
}

Unk020fff4c *func_020fff4c(void) {
    Unk020fff4c *p;

    p = HeapAlloc(GetHeap(func_020364e8()), 0x2c);
    data_0217c62c = p;
    *p = data_0215a100;
    func_020d49d8(&data_0217c62c);
    return data_0217c62c;
}

void DrawDram(void *a, Dram *e, void *c, s32 d) {
    Unk02012f58 *q;
    s32 v;

    q = &e->mUnk_00.mMatrix;
    v = (u16) (-(s32) e->mUnk_a6) >> 4;
    Matrix3x3FromPairX((s32 *) q, gPairsByAngle[v * 2], gPairsByAngle[v * 2 + 1]);
    q->mUnk_00[3].x = e->mUnk_00.mPos.x >> 4;
    q->mUnk_00[3].y = e->mUnk_00.mPos.y >> 4;
    q->mUnk_00[3].z = e->mUnk_00.mPos.z >> 4;
    func_020ea8a8(gDram, q, &e->mUnk_00.mScale, d);
}

void func_020ffdd4(Unk020e6fd4 *v1) {
    Unk020f41c4_B *q;
    void **arr;
    Dram *e;
    u16 *v2;
    s32 n, i;
    u16 t;

    n = v1->mUnk_04;
    arr = v1->mUnk_00;
    for (i = 0; i < n; i++) {
        e = arr[i];
        if (e->mUnk_00.mStateMachine.mState != 1) {
            return;
        }
    }
    q = func_020d22d0();
    q->mUnk_00 = q->mUnk_08 * q->mUnk_00 + q->mUnk_10;
    t = (u16) (((u64) (u32) (q->mUnk_00 >> 32) * 6) >> 32);
    for (i = 0; i < n; i++) {
        e = arr[i];
        v2 = (u16 *) data_0215a0a8[t];
        e->mUnk_a8 = e->mUnk_b4[v2[i]];
        e->mUnk_00.mStateMachine.mNextState = 0;
        e->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
}

void UpdateDram(u32 arg0, u32 arg1) {
    u32 value0;
    u32 value1 = arg1;
    u32 value12;
    value0 = (value1) + (0x80u);
    func_02046b40((void *) value0);
}

u32 func_020ffdc0(u32 p0) {
    return p0;
}

void UpdateDramState0(Dram *p) {
    if (p->mUnk_00.mStateMachine.mStateFrames > p->mUnk_a4) {
        p->mUnk_00.mStateMachine.mNextState = 2;
        p->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterDramState2(Unk020ffd94 *p0) {
    p0->mUnk_ac = 0x0u;
}

void UpdateDramState2(Dram *p) {
    p->mUnk_ac += p->mUnk_b0;
    p->mUnk_a6 += (s16) ((s32) (((s64) p->mUnk_ac * p->mUnk_a8) >> 12));
    if (p->mUnk_00.mStateMachine.mStateFrames > p->mUnk_a0) {
        p->mUnk_00.mStateMachine.mNextState = 3;
        p->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
}

u32 func_020ffd3c(u32 p0) {
    return p0;
}

void UpdateDramState3(Dram *p) {
    p->mUnk_a6 += p->mUnk_a8;
    if (p->mUnk_a2 == 0) {
        return;
    }
    if (p->mUnk_00.mStateMachine.mStateFrames > p->mUnk_a2) {
        p->mUnk_00.mStateMachine.mNextState = 4;
        p->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterDramState4(Unk020ffcf8 *p0) {
    p0->mUnk_ac = 0x1000u;
}

void UpdateDramState4(Dram *p) {
    s16 d;

    p->mUnk_ac -= p->mUnk_b0;
    d = (s16) ((s32) (((s64) p->mUnk_ac * p->mUnk_a8) >> 12));
    if (d <= 0x96) {
        d = 0x96;
    }
    p->mUnk_a6 += d;
    if (p->mUnk_00.mStateMachine.mStateFrames > p->mUnk_a0) {
        p->mUnk_00.mStateMachine.mNextState = 5;
        p->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterDramState5(Dram *p) {
    s32 n;

    n = p->mUnk_a6;
    p->mUnk_bc = 0x1999 - n % 0x1999;
}

// Raw stores of 1 at +0x90 and +0x92 are mNextState and mNextStateRequested (MapObject +0x80 + 0x10 / 0x12): it asks
// for state 1.
void UpdateDramState5(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value3;
    u32 value12;
    u32 compareLeft0;
    u32 compareRight0;
    value1 = (u32) * (const u16 *) ((value0) + (166));
    value12 = (value0) + (0xa6u);
    value1 = (value1) + (0x96u);
    *(u16 *) ((value0) + (166)) = (u16) value1;
    value1 = (u32) * (const u32 *) ((value0) + (188));
    value1 = (value1) - (0x96u);
    *(u32 *) ((value0) + (188)) = value1;
    value3 = (u32) * (const u32 *) ((value0) + (188));
    compareLeft0 = value3;
    compareRight0 = 0u;
    if ((s32) compareLeft0 >= (s32) compareRight0) {
        return;
    }
    value2 = (u32) * (const u16 *) ((value12) + (0));
    value1 = 1u;
    value2 = (value2) + (value3);
    *(u16 *) ((value12) + (0)) = (u16) value2;
    *(u16 *) ((value0) + (144)) = (u16) value1;
    *(u16 *) ((value0) + (146)) = (u16) value1;
}
