#include "Main/Unknown/code_020e48b4.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020d4c28.h"

#include "Main/Unknown/code_020e48e0.h"
#include "Main/Unknown/code_020e55b4.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020ec000.h"
#include "Main/Unknown/unk_02158000.h"
#include "Main/Unknown/code_020e4934.h"
#include "Main/Unknown/code_020e4990.h"
#include "Main/Unknown/code_020e49c0.h"
#include "Main/Unknown/code_020e4a18.h"
#include "Main/Unknown/code_020e4a34.h"
#include "Main/Unknown/code_020e4a68.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_020e4ab4.h"
#include "Main/Unknown/code_020e4ad0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_020e337c.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020e4dec.h"
#include "Main/Unknown/code_020e4df8.h"
#include "Main/Unknown/code_020e4e08.h"
#include "Main/Unknown/code_020e5000.h"
#include "Main/Unknown/code_020e5634.h"
#include "Main/Unknown/code_020e4e9c.h"
#include "Main/Unknown/code_020e4ea8.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e6000.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/unk_0217b000.h"

Unk020e50dc *func_020e50dc(void) {
    Unk020e50dc *p;
    p = HeapAlloc(GetHeap(func_020364e8()), 0x40);
    *p = *(Unk020e50dc *) data_02159070;
    return p;
}

Unk020e5080 *func_020e5080(void) {
    Unk020e5080 *p;
    p = HeapAlloc(GetHeap(func_020364e8()), 0x2c);
    data_0217b7f8 = p;
    *p = *(Unk020e5080 *) data_02159044;
    func_020d49d8(&data_0217b7f8);
    return data_0217b7f8;
}

Unk020e5024 *func_020e5024(void) {
    Unk020e5024 *p;
    p = HeapAlloc(GetHeap(func_020364e8()), 0x2c);
    data_0217b7fc = p;
    *p = *(Unk020e5024 *) data_02159018;
    func_020d49d8(&data_0217b7fc);
    return data_0217b7fc;
}

Unk020e4fc8 *func_020e4fc8(void) {
    Unk020e4fc8 *p;
    p = HeapAlloc(GetHeap(func_020364e8()), 0x28);
    data_0217b7f4 = p;
    *p = *(Unk020e4fc8 *) data_02158ff0;
    func_020e6f50(&data_0217b7f4);
    return data_0217b7f4;
}

void SetupDrawPukupuku(void) {
    func_020e6a18(gPukupuku);
}

void DrawPukupuku(u32 a, Unk020e43a8 *p, u32 b, u16 c) {
    Unk020e6488 *q;
    s32 neg;
    u32 v;

    if (p->mUnk_00.mStateMachine.mState == 0) {
        MtxFx43 *r;
        neg = p->mUnk_00.mCollisionSlotIndex & 1;
        r = SetViewTransposeMatrixPos(&p->mUnk_00.mPos);
        q = gPukupuku;
        q->mUnk_14 = q->mUnk_14 | 0xc0;
        data_0217b800 = p->mUnk_00.mScale;
        if (neg) {
            data_0217b800.x = -data_0217b800.x;
        }
        func_020e67c4(q, r, &data_0217b800, 0, c);
    } else {
        MtxFx43 *r;
        neg = p->mUnk_00.mCollisionSlotIndex & 1;
        v = *(u16 *) &p->mUnk_a0.mUnk_0c.x;
        r = SetViewTransposeMatrixPos(&p->mUnk_00.mPos);
        q = gPukupuku;
        q->mUnk_14 = q->mUnk_14 | 0xc0;
        data_0217b800 = p->mUnk_00.mScale;
        if (neg) {
            data_0217b800.x = -data_0217b800.x;
        }
        func_020e66e4(q, r, v, &data_0217b800, 0, c);
    }
}

void func_020e4e9c(void) {
    u32 value12;
    func_020e55b4();
}

void func_020e4e08(u32 a, Unk020e43a8 *p, u32 b, u32 c) {
    Unk020e4e08 s;

    if (p->mUnk_00.mStateMachine.mState != 0 && p->mUnk_00.mStateMachine.mState != 1) {
        return;
    }
    s.mUnk_00 = p->mUnk_00.mPos.y - p->mUnk_a0.mUnk_18.y;
    s.mUnk_00 = 0x1000 - (s.mUnk_00 >> 6);
    s.mUnk_04 = p->mUnk_00.mPos;
    s.mUnk_04.y = p->mUnk_f4.z + p->mUnk_100;
    func_020e5634((Unk020e516c *) &p->mUnk_c8, &s.mUnk_04);
    func_020e54e4((Unk020e516c *) &p->mUnk_c8, &s, 0, c);
}

void func_020e4df8(u32 arg0, u32 arg1) {
    u32 value0;
    u32 value1 = arg1;
    u32 value12;
    value0 = (value1) + (0x80u);
    func_02046b40((void *) value0);
}

void func_020e4dec(Unk020e4dec *p0) {
    p0->mUnk_ac = 0x0u;
}

static inline u32 func_020e4ad0_inline(Unk020f41c4_B *r, u32 c) {
    r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
    if (c == 0) {
        return r->mUnk_00 >> 32;
    } else {
        return ((r->mUnk_00 >> 32) * c) >> 32;
    }
}

void func_020e4ad0(Unk020e43a8 *p) {
    s32 y;

    p->mUnk_00.mUnk_10.y -= 0x385;
    VEC_Add(&p->mUnk_00.mPos, &p->mUnk_00.mUnk_10, &p->mUnk_00.mPos);
    y = 0;
    y += (s32) (((s64) p->mUnk_104 * (p->mUnk_00.mPos.x - p->mUnk_a0.mUnk_18.x)) >> 12);
    y += (s32) (((s64) p->mUnk_108 * (p->mUnk_00.mPos.z - p->mUnk_a0.mUnk_18.z)) >> 12);
    p->mUnk_100 = y;
    y = p->mUnk_a0.mUnk_18.y + p->mUnk_100;
    if (p->mUnk_00.mPos.y >= y) {
        return;
    }
    if (!(p->mUnk_00.mDistanceSquaredAndFlags & 4)) {
        Unk0210b7a8 s;
        u32 k;

        if (p->mUnk_00.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
            k = 2;
        } else if (p->mUnk_00.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
            k = 3;
        } else {
            k = 4;
        }
        s.mUnk_00 = 0x10b;
        s.mUnk_04 = &p->mUnk_00.mPos;
        s.mUnk_08 = k;
        s.mUnk_0c = func_020d4ef4(&p->mUnk_00.mPos);
        func_0210b7a8(&s);
    }
    p->mUnk_00.mPos.y = y;
    p->mUnk_c4 = p->mUnk_c4 - 1;
    if (p->mUnk_c4 == 0) {
        Unk020f41c4_B *r;

        p->mUnk_00.mUnk_10.y = 0x3199;
        r = func_020d22d0();
        p->mUnk_c4 = (u16) func_020e4ad0_inline(r, 3) + 4;
    } else {
        Unk020f41c4_B *r;

        p->mUnk_00.mUnk_10.y = 0x2000;
        r = func_020d22d0();
        p->mUnk_00.mUnk_10.y = p->mUnk_00.mUnk_10.y + func_020e4ad0_inline(r, 0x800);
    }
    if (p->mUnk_00.mPos.x > p->mUnk_a0.mUnk_18.x + 0x14000) {
        p->mUnk_00.mUnk_10.x = -0xccc;
    } else if (p->mUnk_00.mPos.x < p->mUnk_a0.mUnk_18.x - 0x14000) {
        p->mUnk_00.mUnk_10.x = 0xccc;
    } else {
        Unk020f41c4_B *r;

        r = func_020d22d0();
        p->mUnk_00.mUnk_10.x = func_020e4ad0_inline(r, 0x1998) - 0xccc;
    }
    if (p->mUnk_00.mPos.z > p->mUnk_a0.mUnk_18.z + 0x14000) {
        p->mUnk_00.mUnk_10.z = -0xccc;
        return;
    }
    if (p->mUnk_00.mPos.z < p->mUnk_a0.mUnk_18.z - 0x14000) {
        p->mUnk_00.mUnk_10.z = 0xccc;
        return;
    }
    {
        Unk020f41c4_B *r;

        r = func_020d22d0();
        p->mUnk_00.mUnk_10.z = func_020e4ad0_inline(r, 0x1998) - 0xccc;
    }
}

void func_020e4ab4(Unk020e43a8 *p0) {
    p0->mUnk_00.mFlags = (((p0->mUnk_00.mFlags)) | ((data_02158fe4)));
}

void func_020e4a68(Unk020e43a8 *p) {
    if (func_020ec7e8(p) == FALSE) {
        return;
    }
    if (p->mUnk_00.mCourseMapRow->mUnk_28 == 0) {
        p->mUnk_00.mStateMachine.mNextState = 2;
        p->mUnk_00.mStateMachine.mNextStateRequested = 1;
        return;
    }
    ParkMapObject(&p->mUnk_00);
}

void func_020e4a34(Unk020e4a34 *p0) {
    p0->mUnk_02 |= data_02158fe8;
    p0->mUnk_02 |= data_02158fec;
}

void func_020e4a18(Unk020e43a8 *p) {
    if (p->mUnk_00.mStateMachine.mStateFrames > 0x12c) {
        p->mUnk_00.mStateMachine.mNextState = 3;
        p->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
}

void func_020e49c0(Unk020e49c0 *p0) {
    p0->mUnk_04 = p0->mUnk_b8;
    p0->mUnk_0c = p0->mUnk_c0;
    p0->mUnk_10 = 0x0u;
    p0->mUnk_14 = 0x3199u;
    p0->mUnk_18 = 0x0u;
    p0->mUnk_02 = (((p0->mUnk_02)) & ~(0x2u));
    p0->mUnk_02 = (((p0->mUnk_02)) & ~(0x8u));
    p0->mUnk_66 = 0x1fu;
    p0->mUnk_02 = (((p0->mUnk_02)) & ~(0x1u));
}

void func_020e4990(Unk020e43a8 *p) {
    p->mUnk_00.mPos.y = p->mUnk_00.mPos.y + p->mUnk_00.mUnk_10.y;
    if (p->mUnk_00.mPos.y > p->mUnk_a0.mUnk_18.y) {
        p->mUnk_00.mStateMachine.mNextState = 0;
        p->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
}

u8 func_020e4934(Unk020e43a8 *a, Unk020ec6e4 *b, u8 *c, u8 *d) {
    if (*c == 1) {
        func_020ec6e4(a, b);
        a->mUnk_00.mStateMachine.mNextState = 1;
        a->mUnk_00.mStateMachine.mNextStateRequested = 1;
        a->mUnk_00.mFlags = a->mUnk_00.mFlags | (data_02158fe4);
        func_020d26f8((void *) a, (void *) b);
    }
    return *d;
}

s32 func_020e48e0(Unk020e43a8 *p, void *a, u8 *b, u8 *c) {
    if (*b == 1) {
        func_020ec538(p, a);
        p->mUnk_00.mFlags |= data_02158fe4;
        p->mUnk_00.mStateMachine.mNextState = 1;
        p->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
    return *c;
}

#pragma thumb on

void CreatePukupuku(void) {
    void *v1;
    v1 = FindCourseMapObjFile(gPukupukuNsbmdName);
    func_020e6488((Unk020e6488 **) (((u32 *) &gPukupuku)), v1, 0, 0);
    func_020e6ab8(gPukupuku);
}

#pragma thumb off
