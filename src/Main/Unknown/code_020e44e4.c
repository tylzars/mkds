#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020e44e4.h"

#include "Main/Unknown/code_020ec538.h"
#include "Main/Unknown/unk_02158000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_020e5000.h"
#include "Main/Unknown/code_020ec000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_020d275c.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "code_02146cbc.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"

#pragma thumb on

void func_020e47c8(Unk020e43a8 *p, Vec3 *a) {
    func_02046be8(&p->mUnk_00.mUnk_80, (UnkFunc *const *) data_0216c1ec, 4, p);
    p->mUnk_00.mPos.y = p->mUnk_00.mPos.y + (s32) (((s64) p->mUnk_00.mUnk_1c.y * 0xa000) >> 12);
    p->mUnk_a0.mUnk_18 = p->mUnk_00.mPos;
    p->mUnk_c4 = 4;
    p->mUnk_00.mUnk_10.x = 0;
    p->mUnk_00.mUnk_10.y = 0;
    p->mUnk_00.mUnk_10.z = 0;
    func_020ec854(p, p->mUnk_00.mPos.y - 0x1e000, 0x400, 0x400, 0x4000, 0x1800);
    p->mUnk_00.mUnk_80.mUnk_10 = 0;
    p->mUnk_00.mUnk_80.mUnk_12 = 1;
    func_020e516c((Unk020e516c *) &p->mUnk_c8, a, (s32) (((s64) p->mUnk_00.mUnk_1c.x * 0x12000) >> 12), 0xd);
    p->mUnk_f4.z = a->y;
    {
        s32 *q = &p->mUnk_d4;
        p->mUnk_104 = -DivFixed12(q[0], q[1]);
        p->mUnk_108 = -DivFixed12(q[2], q[1]);
    }
}

#pragma thumb off

Unk020e46c8 *func_020e4768(void) {
    Unk020e46c8 *p;
    p = HeapAlloc(GetHeap(func_020364e8()), 0x40);
    *p = *(Unk020e46c8 *) data_02158f70;
    p->mUnk_38 = 0x2bc000;
    return p;
}

Unk020e46c8 *func_020e4718(void) {
    Unk020e46c8 *p;
    p = HeapAlloc(GetHeap(func_020364e8()), 0x40);
    *p = *(Unk020e46c8 *) data_02158f30;
    return p;
}

Unk020e46c8 *func_020e46c8(void) {
    Unk020e46c8 *p;
    p = HeapAlloc(GetHeap(func_020364e8()), 0x40);
    *p = *(Unk020e46c8 *) data_02158ef0;
    return p;
}

Unk020e466c *func_020e466c(void) {
    Unk020e466c *p;
    p = HeapAlloc(GetHeap(func_020364e8()), 0x2c);
    data_0217b7e4 = p;
    *p = *(Unk020e466c *) data_02158ec4;
    func_020d49d8(&data_0217b7e4);
    return data_0217b7e4;
}

Unk020e4610 *func_020e4610(void) {
    Unk020e4610 *p;
    p = HeapAlloc(GetHeap(func_020364e8()), 0x28);
    data_0217b7dc = p;
    *p = *(Unk020e4610 *) data_02158e9c;
    func_020e6f50(&data_0217b7dc);
    return data_0217b7dc;
}

void func_020e44e4(u32 a, Unk020e43a8 *p) {
    s32 old;
    s32 d;
    old = p->mUnk_00.mUnk_7e;
    func_02046b40(&p->mUnk_00.mUnk_80);
    d = p->mUnk_00.mUnk_7e - old;
    if (d > 0x8000) {
        d -= 0x10000;
    }
    if (d < -0x8000) {
        d += 0x10000;
    }
    p->mUnk_124 = (s32) (((s64) p->mUnk_00.mMatrix.mUnk_00[1].x * d) >> 12);
    p->mUnk_128 = (s32) (((s64) p->mUnk_00.mMatrix.mUnk_00[1].y * d) >> 12);
    p->mUnk_12c = (s32) (((s64) p->mUnk_00.mMatrix.mUnk_00[1].z * d) >> 12);
    p->mUnk_a0 = *(Unk020e43a8_28 *) &p->mUnk_00.mMatrix;
    Matrix3x3FromPairY((s32 *) &p->mUnk_00.mMatrix, gPairsByAngle[(p->mUnk_00.mUnk_7e >> 4) * 2],
                       gPairsByAngle[(p->mUnk_00.mUnk_7e >> 4) * 2 + 1]);
    Matrix3x3Multiply((const s32 *) &p->mUnk_00.mMatrix, (const s32 *) &p->mUnk_c4, (s32 *) &p->mUnk_00.mMatrix);
    Vec3AddScaled(-p->mUnk_104, &p->mUnk_00.mMatrix.mUnk_00[1], &p->mUnk_00.mPos, &p->mUnk_f4);
    if (p->mUnk_00.mUnk_80.mUnk_0e == 3) {
        return;
    }
    if (p->mUnk_15c == -1) {
        return;
    }
    func_020d275c(&p->mUnk_00, p->mUnk_15c);
}
