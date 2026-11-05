#include "Main/Unknown/code_020ea670.h"

#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020d26e0.h"
#include "Main/Unknown/code_020d6000.h"
#include "Main/Unknown/code_020e5000.h"
#include "Main/Unknown/code_020ebef8.h"
#include "Main/Unknown/code_020ea588.h"
#include "Main/Unknown/code_020ec1fc.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02046be8.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02147cd8.h"
#include "code_02012b30.h"
#include "code_02010c84.h"
#include "code_020109c4.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020e5634.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f49bc.h"
#include "Main/Unknown/code_020f6000.h"
#include "Main/Unknown/code_020f8000.h"
#include "Main/Unknown/code_020f813c.h"
#include "Main/Unknown/code_020fa000.h"
#include "Main/Unknown/code_020ec1ec.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_020ec000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_020ec538.h"
#include "01/code_0218155c.h"

const Unk021594e4 data_021594e4 = {
    0, 0, (u32) &func_020eb720, 0, (u32) &func_020ec1ec, 0, 0, 0, 0, 0,
};

const Unk0215950c data_0215950c = {
    0, 0, (u32) &CreateWoodbox1, 0, (u32) &func_020ec1fc, 0, 1, 0, 0, 0, 0,
};

const Unk02159538 data_02159538 = {
    (u32) &func_020eb7e0, (u32) &func_020eb760, 4, 0xa000, 0xa000, 0xa000, 0, 1, 1, 0x168, 0x169, 0, 0, 0, 0, 0,
};

BOOL func_020ec450(Unk020e43a8 *a, void *b, u8 *c) {
    if (*c != 1) {
        return FALSE;
    }
    func_020ec6e4(a, b);
    a->mUnk_00.mUnk_80.mNextState = 1;
    a->mUnk_00.mUnk_80.mNextStateRequested = 1;
    return TRUE;
}

BOOL func_020ec41c(Unk020e43a8 *a, void *b, u8 *c) {
    if (*c != 1) {
        return FALSE;
    }
    func_020ec538(a, b);
    a->mUnk_00.mUnk_80.mNextState = 1;
    a->mUnk_00.mUnk_80.mNextStateRequested = 1;
    return TRUE;
}

Unk02159538 *func_020ec3cc(void) {
    Unk02159538 *p;

    p = HeapAlloc(GetHeap(func_020364e8()), 0x40);
    *p = data_02159538;
    return p;
}

Unk0215950c *func_020ec370(void) {
    Unk0215950c *p;

    p = HeapAlloc(GetHeap(func_020364e8()), 0x2c);
    data_0217bbec = p;
    *p = data_0215950c;
    func_020d49d8(&data_0217bbec);
    return data_0217bbec;
}

Unk021594e4 *func_020ec314(void) {
    Unk021594e4 *p;

    p = HeapAlloc(GetHeap(func_020364e8()), 0x28);
    data_0217bbf4 = p;
    *p = data_021594e4;
    func_020e6f50(&data_0217bbf4);
    return data_0217bbf4;
}

void func_020ec1fc(void *a, Unk020e43a8 *b, void *c, u32 d) {
    u16 h;
    s32 t;
    Vec3 v;

    h = b->mUnk_00.mUnk_80.mState;
    b->mUnk_00.mMatrix.mUnk_00[3].x = b->mUnk_00.mPos.x >> 4;
    b->mUnk_00.mMatrix.mUnk_00[3].y = b->mUnk_00.mPos.y >> 4;
    b->mUnk_00.mMatrix.mUnk_00[3].z = b->mUnk_00.mPos.z >> 4;
    func_020ea8a8(gWoodbox1, &b->mUnk_00.mMatrix, &b->mUnk_00.mScale, d);
    if (h == 0) {
        return;
    }
    t = (s32) (((s64) (0x5a000 - b->mUnk_d0) * 0x2e) >> 12);
    v.x = b->mUnk_00.mPos.x;
    v.z = b->mUnk_00.mPos.z;
    v.y = b->mUnk_0b4 - (s32) (((s64) b->mUnk_0bc * b->mUnk_cc) >> 12) - (s32) (((s64) b->mUnk_0c4 * b->mUnk_d4) >> 12);
    Vec3AddScaled(-b->mUnk_00.mUnk_58.x, (const Vec3 *) &b->mUnk_0bc, &v, &v);
    func_020e5634((Unk020e516c *) &b->mUnk_114, &v);
    func_020e53ac((Unk020e516c *) &b->mUnk_114, &t, 0, d);
}

void func_020ec1ec(u32 arg0, u32 arg1) {
    u32 value0;
    u32 value1 = arg1;
    u32 value12;
    value12 = (u32) &func_02046b40;
    value0 = (value1) + (0x80u);
    func_02046b40((void *) value0);
}

void func_020ec194(Unk020ec194 *a) {
    Vec3 v;
    Vec3 *p;

    p = &a->mUnk_010;
    p->x = 0;
    p->y = 0;
    p->z = 0;
    a->mUnk_004 = a->mUnk_0b0;
    func_020d7a3c(&a->mUnk_0bc, a->mUnk_0c8, &v);
    func_01ffccd0(&a->mUnk_028, &v);
}

void func_020ebef8(Unk020ebef8 *c, Vec3 *d) {
    s32 n;
    Vec3 a;
    Vec3 b;
    Unk020f41c4_B *p;
    ItemObject *q;
    s32 i;

    if (data_021759c0->mMode == 4) {
        func_ov001_0218175c(c->mUnk_000.mKind);
    }
    c->mUnk_000.mFlags |= data_021594d8;
    if (data_021759c0->mMode == 5) {
        return;
    }
    p = func_020d22c0();
    p->mUnk_00 = p->mUnk_08 * p->mUnk_00 + p->mUnk_10;
    if (c->mUnk_110 <= (u16) (((u64) (u32) (p->mUnk_00 >> 32) * 100) >> 32)) {
        return;
    }
    if (c->mUnk_10e == 0) {
        return;
    }
    i = PickItem(0, c->mUnk_10e, 1, 1, 0, 0x12);
    q = StartItemObjectOrZero(gItemInfos[i].mObjectKind, 8, &c->mUnk_000.mPos, &c->mUnk_0bc);
    if (q == NULL) {
        return;
    }
    if ((s64) d->x * d->x + (s64) d->y * d->y + (s64) d->z * d->z >= 16) {
        func_02039860(d, &a);
    }
    func_020397a8(&c->mUnk_0bc, &a, &b);
    p = func_020d22c0();
    p->mUnk_00 = p->mUnk_08 * p->mUnk_00 + p->mUnk_10;
    n = (s32) (((s64) (s32) ((u32) (((u64) (u32) (p->mUnk_00 >> 32) * 0x1800) >> 32) + 0x119a) << 12) >> 12);
    p = func_020d22c0();
    p->mUnk_00 = p->mUnk_08 * p->mUnk_00 + p->mUnk_10;
    q->mVelocity = *d;
    Vec3AddScaled(n, &a, &c->mUnk_000.mPos, &q->mPos);
    Vec3AddScaled(0, &b, &q->mPos, &q->mPos);
    q->mUnk_68.x = 0xcd;
    q->mUnk_68.y = 0xcd;
    q->mUnk_68.z = 0xcd;
    func_020f6630(q, 2, &c->mUnk_000.mPos, d, &c->mUnk_0bc);
}

void func_020ebeac(Unk020ebeac *p0) {
    p0->mUnk_02 |= data_021594d8;
    p0->mUnk_02 |= data_021594dc;
    p0->mUnk_02 |= data_021594e0;
}

#pragma thumb off

void func_020ebe68(Unk020ebef8 *param_1) {
    if (param_1->mUnk_000.mUnk_80.mStateFrames < 900) {
        return;
    }
    if (param_1->mUnk_000.mCourseMapRow->mUnk_2c != 0) {
        return;
    }
    if (data_0217bbf0 == NULL) {
        data_0217bbf0 = param_1;
        param_1->mUnk_000.mUnk_80.mNextState = 2;
        param_1->mUnk_000.mUnk_80.mNextStateRequested = 1;
    }
}

BOOL func_020ebc2c(Unk020ebef8 *param_1) {
    Vec3 v;
    Vec3 *p;
    s32 d;
    s32 s;

    v = param_1->mUnk_000.mPos;
    p = &param_1->mUnk_000.mMatrix.mUnk_00[0];
    s = param_1->mUnk_000.mUnk_58.x;
    d = func_02039828(&param_1->mUnk_0bc, p);
    if (d > 0) {
        Vec3AddScaled(-s, p, &v, &v);
    } else {
        Vec3AddScaled(s, p, &v, &v);
    }
    p = &param_1->mUnk_000.mMatrix.mUnk_00[1];
    s = param_1->mUnk_000.mUnk_58.x;
    d = func_02039828(&param_1->mUnk_0bc, p);
    if (d > 0) {
        Vec3AddScaled(-s, p, &v, &v);
    } else {
        Vec3AddScaled(s, p, &v, &v);
    }
    p = &param_1->mUnk_000.mMatrix.mUnk_00[2];
    s = param_1->mUnk_000.mUnk_58.x;
    d = func_02039828(&param_1->mUnk_0bc, p);
    if (d > 0) {
        Vec3AddScaled(-s, p, &v, &v);
    } else {
        Vec3AddScaled(s, p, &v, &v);
    }
    Vec3Sub(&v, &param_1->mUnk_0b0, &v);
    v.y = v.y + param_1->mUnk_000.mUnk_58.x;
    d = -func_02039828(&v, &param_1->mUnk_0bc);
    if (d > 0 && param_1->mUnk_000.mUnk_10.y < 0) {
        param_1->mUnk_0cc.y = param_1->mUnk_0cc.y + d;
        param_1->mUnk_000.mUnk_10.y = (s32) (((s64) -param_1->mUnk_000.mUnk_10.y * 0x400) >> 12);
        param_1->mUnk_0e4.x = (s32) (((s64) param_1->mUnk_0d8.x * -0x266) >> 12);
        param_1->mUnk_0e4.y = (s32) (((s64) param_1->mUnk_0d8.y * -0x266) >> 12);
        param_1->mUnk_0e4.z = (s32) (((s64) param_1->mUnk_0d8.z * -0x266) >> 12);
        param_1->mUnk_000.mUnk_10.x = (s32) (((s64) param_1->mUnk_0e4.x * 0x9000) >> 12);
        param_1->mUnk_000.mUnk_10.z = (s32) (((s64) param_1->mUnk_0e4.z * 0x9000) >> 12);
        return TRUE;
    }
    return FALSE;
}

void func_020ebb04(Unk020ebef8 *param_1) {
    Vec3 v;
    u32 n;
    u16 h;

    n = GetRaceUpdateFrames();
    param_1->mUnk_000.mFlags &= ~1;
    param_1->mUnk_000.mFlags &= ~2;
    param_1->mUnk_000.mFlags &= ~8;
    param_1->mUnk_000.mUnk_66 = 1;
    param_1->mUnk_0d8 = *((n & 1) ? &param_1->mUnk_0f4 : &param_1->mUnk_100);
    if (n & 2) {
        h = param_1->mUnk_10c;
    } else {
        h = 0x10000 - param_1->mUnk_0f0;
    }
    param_1->mUnk_0f0 = h;
    param_1->mUnk_0e4.x = 0;
    param_1->mUnk_0e4.y = 0;
    param_1->mUnk_0e4.z = 0;
    param_1->mUnk_0cc.x = (s32) (((s64) param_1->mUnk_0d8.x * 0x14000) >> 12);
    param_1->mUnk_0cc.y = 0x3c000;
    param_1->mUnk_0cc.z = (s32) (((s64) param_1->mUnk_0d8.z * 0x14000) >> 12);
    param_1->mUnk_000.mUnk_10.x = 0;
    param_1->mUnk_000.mUnk_10.y = 0;
    param_1->mUnk_000.mUnk_10.z = 0;
    Vec3Add(&param_1->mUnk_0bc, &param_1->mUnk_0d8, &param_1->mUnk_0a0);
    param_1->mUnk_0ac = param_1->mUnk_0c8 + param_1->mUnk_0f0;
    func_020d7a3c(&param_1->mUnk_0a0, param_1->mUnk_0ac, &v);
    func_01ffccd0(&param_1->mUnk_000.mMatrix, &v);
}

void func_020ebab0(Unk020ebef8 *param_1) {
    if (func_020ebc2c(param_1) != FALSE) {
        param_1->mUnk_000.mUnk_80.mNextState = 3;
        param_1->mUnk_000.mUnk_80.mNextStateRequested = 1;
    }
    param_1->mUnk_000.mUnk_10.y -= 0x1ec;
    param_1->mUnk_0cc.y = param_1->mUnk_0cc.y + param_1->mUnk_000.mUnk_10.y;
    Vec3Add(&param_1->mUnk_0b0, &param_1->mUnk_0cc, &param_1->mUnk_000.mPos);
}

void func_020eb8f8(Unk020ebef8 *param_1) {
    Vec3 v;
    s32 d;

    func_020ebc2c(param_1);
    param_1->mUnk_0cc.x -= (s32) (((s64) param_1->mUnk_0cc.x * 164) >> 12);
    param_1->mUnk_0cc.z -= (s32) (((s64) param_1->mUnk_0cc.z * 164) >> 12);
    Vec3Add(&param_1->mUnk_0d8, &param_1->mUnk_0e4, &param_1->mUnk_0d8);
    d = param_1->mUnk_0f0;
    if ((u32) d < 0x8000) {
        param_1->mUnk_0f0 = d - (s32) (((s64) d * 246) >> 12);
    } else {
        param_1->mUnk_0f0 = d + (s32) (((s64) (0x10000 - d) * 246) >> 12);
    }
    param_1->mUnk_000.mUnk_10.y -= 655;
    Vec3Add(&param_1->mUnk_0cc, &param_1->mUnk_000.mUnk_10, &param_1->mUnk_0cc);
    Vec3Add(&param_1->mUnk_0b0, &param_1->mUnk_0cc, &param_1->mUnk_000.mPos);
    Vec3Add(&param_1->mUnk_0bc, &param_1->mUnk_0d8, &param_1->mUnk_0a0);
    if ((s64) param_1->mUnk_0a0.x * param_1->mUnk_0a0.x + (s64) param_1->mUnk_0a0.y * param_1->mUnk_0a0.y +
            (s64) param_1->mUnk_0a0.z * param_1->mUnk_0a0.z >=
        16) {
        func_02039860(&param_1->mUnk_0a0, &param_1->mUnk_0a0);
    }
    param_1->mUnk_0ac = param_1->mUnk_0c8 + param_1->mUnk_0f0;
    func_020d7a3c(&param_1->mUnk_0a0, param_1->mUnk_0ac, &v);
    func_01ffccd0(&param_1->mUnk_000.mMatrix, &v);
    if (param_1->mUnk_000.mUnk_80.mStateFrames >= 90) {
        data_0217bbf0 = NULL;
        param_1->mUnk_000.mUnk_80.mNextState = 0;
        param_1->mUnk_000.mUnk_80.mNextStateRequested = 1;
    }
}

u32 func_020eb7e0(Unk020ebef8 *param_1, Unk020eb498 *param_2, u8 *param_3, u8 *param_4) {
    if (*param_3 == 3) {
        if (data_021759c0->mMode != 1) {
            if (param_2->mUnk_29c == 1 || param_2->mUnk_2a4 > 0x3000) {
                func_020ebef8(param_1, &param_2->mUnk_0a4);
                if (data_0217bbf0 == param_1) {
                    data_0217bbf0 = NULL;
                }
                param_1->mUnk_000.mUnk_80.mNextState = 1;
                param_1->mUnk_000.mUnk_80.mNextStateRequested = 1;
                func_020d26ec(param_2, 0x167);
                param_1->mUnk_000.mUnk_78 |= *(u32 *) data_021594d4;
                func_020d26f8(&param_1->mUnk_000, (Kart *) param_2);
                if ((param_1->mUnk_000.mUnk_78 & 3) == 0) {
                    if (*param_4 == 0) {
                        func_0208b498(0x31, &param_1->mUnk_000.mPos, param_2->mUnk_074, 0x1000);
                        func_0208b498(0x32, &param_1->mUnk_000.mPos, param_2->mUnk_074, 0x1000);
                    } else {
                        func_0208b7bc(0x31, &param_1->mUnk_000.mPos);
                        func_0208b7bc(0x32, &param_1->mUnk_000.mPos);
                    }
                }
            }
        }
    }
    return *param_4;
}

u32 func_020eb760(Unk020ebef8 *param_1, Unk020eb498 *param_2, u8 *param_3, u8 *param_4) {
    u32 v;

    v = (u32) (*param_3 - 1);
    if (v <= 1) {
        func_020ebef8(param_1, &param_2->mUnk_05c);
        if (data_0217bbf0 == param_1) {
            data_0217bbf0 = NULL;
        }
        param_1->mUnk_000.mUnk_80.mNextState = 1;
        param_1->mUnk_000.mUnk_80.mNextStateRequested = 1;
        if ((param_1->mUnk_000.mUnk_78 & 3) == 0) {
            func_0208b7bc(0x31, &param_1->mUnk_000.mPos);
            func_0208b7bc(0x32, &param_1->mUnk_000.mPos);
        }
    }
    return *param_4;
}

#pragma thumb on

void CreateWoodbox1(void) {
    func_020ea588((void **) &gWoodbox1, (void *) FindCourseMapObjFile(gWoodbox1NsbmdName), NULL);
    func_02084968(gWoodbox1, 0x3f, 2, 0x294a);
}

void func_020eb720(void) {
    data_0217bbf0 = NULL;
}

void func_020eb498(Unk020ebef8 *param_1, Unk020eb498 *param_2) {
    Vec3 v;
    s32 d;

    if (func_01ffdee4(&param_1->mUnk_000.mPos, NULL, 0, 0xa000, 8, -2, NULL, &param_1->mUnk_0bc, NULL, NULL, NULL, NULL,
                      NULL, NULL) == 0) {
        param_1->mUnk_0bc = data_0216c3d8;
    }
    param_1->mUnk_000.mPos.y = param_1->mUnk_000.mPos.y + param_1->mUnk_000.mUnk_58.x;
    param_1->mUnk_0b0 = param_1->mUnk_000.mPos;
    param_1->mUnk_000.mUnk_10.x = 0;
    param_1->mUnk_000.mUnk_10.y = 0;
    param_1->mUnk_000.mUnk_10.z = 0;
    param_1->mUnk_0c8 = (u16) ((((s64) param_2->mUnk_010 * 0xB60B60B60BLL) + 0x80000000000LL) >> 44);
    func_020d7a3c(&param_1->mUnk_0bc, param_1->mUnk_0c8, &v);
    func_01ffccd0(&param_1->mUnk_000.mMatrix, &v);
    param_1->mUnk_0f4.x = -param_1->mUnk_0bc.x;
    param_1->mUnk_0f4.y = 0;
    param_1->mUnk_0f4.z = -param_1->mUnk_0bc.z;
    if ((s64) param_1->mUnk_0f4.x * param_1->mUnk_0f4.x + (s64) param_1->mUnk_0f4.y * param_1->mUnk_0f4.y +
            (s64) param_1->mUnk_0f4.z * param_1->mUnk_0f4.z <
        16) {
        d = 0;
    } else {
        d = func_02039860(&param_1->mUnk_0f4, &param_1->mUnk_0f4);
    }
    if (d == 0) {
        param_1->mUnk_0f4.x = -param_1->mUnk_000.mMatrix.mUnk_00[2].x;
        param_1->mUnk_0f4.z = -param_1->mUnk_000.mMatrix.mUnk_00[2].z;
    }
    func_020d6f20(&param_1->mUnk_0f4, 0x0aab, &param_1->mUnk_100);
    func_020d6f20(&param_1->mUnk_0f4, 0xf555, &param_1->mUnk_0f4);
    param_1->mUnk_0f4.x = (s32) (((s64) param_1->mUnk_0f4.x * 0x800) >> 12);
    param_1->mUnk_0f4.y = (s32) (((s64) param_1->mUnk_0f4.y * 0x800) >> 12);
    param_1->mUnk_0f4.z = (s32) (((s64) param_1->mUnk_0f4.z * 0x800) >> 12);
    param_1->mUnk_100.x = (s32) (((s64) param_1->mUnk_100.x * 0x800) >> 12);
    param_1->mUnk_100.y = (s32) (((s64) param_1->mUnk_100.y * 0x800) >> 12);
    param_1->mUnk_100.z = (s32) (((s64) param_1->mUnk_100.z * 0x800) >> 12);
    param_1->mUnk_10c = 0x1555;
    param_1->mUnk_10e = param_2->mUnk_028;
    param_1->mUnk_110 = param_2->mUnk_02a;
    func_02046be8(&param_1->mUnk_000.mUnk_80, (UnkFunc *const *) data_0216c3e4, 4, param_1);
    param_1->mUnk_000.mUnk_80.mNextState = 0;
    param_1->mUnk_000.mUnk_80.mNextStateRequested = 1;
    func_020e516c(&param_1->mUnk_114, &param_2->mUnk_000, (s32) (((s64) param_1->mUnk_000.mScale.x * 0x19000) >> 12),
                  13);
}

#pragma thumb off

void func_020eb3f0(Vec3 *param_1, Vec3 *param_2, s32 param_3, Vec3 *param_4) {
    Vec3 v;

    Vec3Sub(param_1, param_2, param_4);
    if ((s64) param_4->x * param_4->x + (s64) param_4->y * param_4->y + (s64) param_4->z * param_4->z >= 16) {
        func_02039860(param_4, &v);
    }
    v.x = (s32) (((s64) v.x * param_3) >> 12);
    v.y = (s32) (((s64) v.y * param_3) >> 12);
    v.z = (s32) (((s64) v.z * param_3) >> 12);
    Vec3Sub(&v, param_4, param_4);
}

void func_020eb2a0(Vec3 *param_1, Vec3 *param_2, s32 param_3, s32 param_4, Vec3 *param_5) {
    Vec3 v;
    s32 a;

    param_5->x = param_1->x - param_2->x;
    param_5->y = 0;
    param_5->z = param_1->z - param_2->z;
    if ((s64) param_5->x * param_5->x + (s64) param_5->y * param_5->y + (s64) param_5->z * param_5->z >= 16) {
        func_02039860(param_5, &v);
    }
    param_5->x = (s32) (((s64) v.x * param_3) >> 12) - param_5->x;
    param_5->z = (s32) (((s64) v.z * param_3) >> 12) - param_5->z;
    param_5->y = param_1->y - param_2->y;
    if (param_5->y > 0) {
        param_5->y = param_4 - param_5->y;
    } else {
        param_5->y = -(param_4 + param_5->y);
    }
    if ((s64) param_5->x * param_5->x + (s64) param_5->z * param_5->z > (s64) param_5->y * param_5->y) {
        a = param_5->y;
        if (a <= 0) {
            a = -a;
        }
        if (param_5->x > a) {
            param_5->x = a;
        } else if (param_5->x < -a) {
            param_5->x = -a;
        }
        if (param_5->z > a) {
            param_5->z = a;
        } else if (param_5->z < -a) {
            param_5->z = -a;
        }
    }
    param_5->y = 0;
}

s32 func_020eafc4(Vec3 *param_1, Vec3 *param_2, Vec3 *param_3, Vec3 *param_4, Vec3 *param_5, s32 param_6,
                  Vec3 *param_7) {
    Vec3 dv;
    s32 ry;
    Vec3 *b;
    s32 d1;
    s32 d2;
    s32 d3;
    s32 rx;
    s32 rz;
    Vec3 *c;

    b = &param_3[1];
    c = &param_3[2];
    Vec3Sub(param_1, param_2, &dv);
    d1 = func_02039828(&dv, param_3);
    if (d1 >= param_4->x + param_6 || d1 <= -(param_5->x + param_6)) {
        return 0;
    }
    if (d1 > 0) {
        rx = (param_4->x + param_6) - d1;
    } else {
        rx = d1 + (param_5->x + param_6);
    }
    d2 = func_02039828(&dv, b);
    if (d2 >= param_4->y + param_6 || d2 <= -(param_5->y + param_6)) {
        return 0;
    }
    if (d2 > 0) {
        ry = param_4->y + param_6;
        ry -= d2;
    } else {
        ry = d2 + (param_5->y + param_6);
    }
    d3 = func_02039828(&dv, c);
    if (d3 >= param_4->z + param_6 || d3 <= -(param_5->z + param_6)) {
        return 0;
    }
    if (d3 > 0) {
        rz = (param_4->z + param_6) - d3;
    } else {
        rz = d3 + (param_5->z + param_6);
    }
    if (rz < rx) {
        if (ry < rz && d2 > 0) {
            if (param_7 != NULL) {
                param_7->x = (s32) (((s64) b->x * ry) >> 12);
                param_7->y = (s32) (((s64) b->y * ry) >> 12);
                param_7->z = (s32) (((s64) b->z * ry) >> 12);
            }
            return 1;
        }
        if (param_7 != NULL) {
            if (d3 <= 0) {
                rz = -rz;
            }
            param_7->x = (s32) (((s64) c->x * rz) >> 12);
            param_7->y = (s32) (((s64) c->y * rz) >> 12);
            param_7->z = (s32) (((s64) c->z * rz) >> 12);
            param_7->y = 0;
        }
        return 4;
    }
    if (ry < rx && d2 > 0) {
        if (param_7 != NULL) {
            param_7->x = (s32) (((s64) b->x * ry) >> 12);
            param_7->y = (s32) (((s64) b->y * ry) >> 12);
            param_7->z = (s32) (((s64) b->z * ry) >> 12);
        }
        return 1;
    }
    if (param_7 != NULL) {
        if (d1 <= 0) {
            rx = -rx;
        }
        param_7->x = (s32) (((s64) param_3->x * rx) >> 12);
        param_7->y = (s32) (((s64) param_3->y * rx) >> 12);
        param_7->z = (s32) (((s64) param_3->z * rx) >> 12);
        param_7->y = 0;
    }
    return 3;
}

s32 func_020ead80(Vec3 *param_1, Vec3 *param_2, Vec3 *param_3, s32 param_4, s32 param_5, s32 param_6, s32 param_7,
                  Vec3 *param_8) {
    Vec3 dv;
    Vec3 v;
    s32 r;
    s32 m;
    s32 n;
    Vec3 *p;
    Vec3 *q;

    p = &param_3[1];
    q = &param_3[2];

    Vec3Sub(param_1, param_2, &dv);
    v.y = func_02039828(&dv, p);
    if (v.y >= param_5 + param_7 || v.y <= -(param_6 + param_7)) {
        return 0;
    }
    if (v.y > 0) {
        r = (param_5 + param_7) - v.y;
    } else {
        r = v.y + (param_6 + param_7);
    }
    v.x = func_02039828(&dv, param_3);
    v.y = 0;
    v.z = func_02039828(&dv, q);
    m = Vec3Length(&v);
    if (m >= param_4 + param_7) {
        return 0;
    }
    n = (param_4 + param_7) - m;
    if (r < n && v.y > 0) {
        if (param_8 != NULL) {
            param_8->x = (s32) (((s64) p->x * r) >> 12);
            param_8->y = (s32) (((s64) p->y * r) >> 12);
            param_8->z = (s32) (((s64) p->z * r) >> 12);
        }
        return 1;
    }
    if (param_8 != NULL) {
        Vec3 w = {0};

        if ((s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z >= 16) {
            func_02039860(&v, &w);
        }
        w.x = (s32) (((s64) w.x * n) >> 12);
        w.y = 0;
        w.z = (s32) (((s64) w.z * n) >> 12);
        param_8->x = (s32) (((s64) param_3->x * w.x) >> 12) + (s32) (((s64) q->x * w.z) >> 12);
        param_8->y = (s32) (((s64) param_3->y * w.x) >> 12) + (s32) (((s64) q->y * w.z) >> 12);
        param_8->z = (s32) (((s64) param_3->z * w.x) >> 12) + (s32) (((s64) q->z * w.z) >> 12);
    }
    return 2;
}

void func_020eacc0(Vec3 *param_1, s32 param_2, Vec3 *param_3, Vec3 *param_4) {
    Vec3 v;
    s32 n;
    s32 t;
    s32 u;
    s32 w;
    s32 s;
    s32 o;

    n = -func_02039828(param_1, param_3);
    t = (s32) (((s64) (0x1000 - n) * param_2) >> 12);
    if (t > 0x1000) {
        t = 0x1000;
    }
    u = 0x1000 - t;
    w = (s32) (((s64) t * u) >> 12);
    o = (s32) (((s64) (n + 0x1000) * (w >> 1)) >> 12);
    s = u + o;
    v.x = (s32) (((s64) param_1->x * s) >> 12);
    v.y = (s32) (((s64) param_1->y * s) >> 12);
    v.z = (s32) (((s64) param_1->z * s) >> 12);
    Vec3AddScaled(t + o, param_3, &v, param_4);
}

void func_020eac20(Vec3 *param_1, s32 param_2) {
    s32 t;
    s32 n;
    s32 u;
    s32 w;
    s32 v;
    s32 s;

    n = -param_1->y;
    t = (s32) (((s64) (0x1000 - n) * param_2) >> 12);
    if (t > 0x1000) {
        t = 0x1000;
    }
    u = 0x1000 - t;
    w = (s32) (((s64) t * u) >> 12);
    n += 0x1000;
    v = (s32) (((s64) n * (w >> 1)) >> 12);
    s = u + v;
    t = t + v;
    param_1->x = (s32) (((s64) param_1->x * s) >> 12);
    param_1->y = (s32) (((s64) param_1->y * s) >> 12);
    param_1->z = (s32) (((s64) param_1->z * s) >> 12);
    param_1->y += t;
}

void func_020eaa14(Vec3 *param_1, Vec3 *param_2, s32 param_3, s32 param_4, s32 param_5, Vec3 *param_6) {
    Vec3 v;
    Vec3 w;
    s32 s;
    s32 a;
    s32 n;

    v = *param_2;
    if (v.y > 0) {
        v.y = 0;
        n = 0;
        if ((s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z >= 16) {
            n = func_02039860(&v, &v);
        }
        if (n == 0) {
            *param_6 = *param_1;
            return;
        }
    }
    s = Vec3Dot(&v, param_1);
    w.x = (s32) (((s64) v.x * s) >> 12);
    w.y = (s32) (((s64) v.y * s) >> 12);
    w.z = (s32) (((s64) v.z * s) >> 12);
    param_6->x = param_1->x - w.x;
    param_6->y = param_1->y - w.y;
    param_6->z = param_1->z - w.z;
    a = -param_4;
    param_6->x = (s32) (((s64) param_6->x * param_3) >> 12);
    param_6->y = (s32) (((s64) param_6->y * param_3) >> 12);
    param_6->z = (s32) (((s64) param_6->z * param_3) >> 12);
    w.x = (s32) (((s64) w.x * a) >> 12);
    w.y = (s32) (((s64) w.y * a) >> 12);
    w.z = (s32) (((s64) w.z * a) >> 12);
    if ((s64) w.x * w.x + (s64) w.z * w.z < (s64) param_5 * param_5) {
        w.x = (s32) (((s64) v.x * param_5) >> 12);
        w.y = (s32) (((s64) v.y * param_5) >> 12);
        w.z = (s32) (((s64) v.z * param_5) >> 12);
    }
    Vec3Add(&w, param_6, param_6);
}

void func_020ea94c(Vec3 *param_1, Vec3 *param_2, s32 param_3, s32 param_4, s32 param_5, Vec3 *param_6) {
    Vec3 v;
    s32 n;

    if (param_2->y <= 0) {
        v = *param_2;
        n = 0;
        if ((s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z >= 16) {
            n = func_02039860(&v, &v);
        }
        if (n == 0) {
            *param_6 = *param_1;
            return;
        }
        func_020eaa14(param_1, &v, param_3, param_4, param_5, param_6);
    } else {
        func_020eaa14(param_1, param_2, param_3, param_4, param_5, param_6);
    }
}

void func_020ea8a8(Unk020ea670 *param_1, void *param_2, void *param_3, s32 param_4) {
    void *p;
    s32 n;
    s32 v;

    p = param_1->mUnk_004;
    n = func_02013344((Unk0201290c *) p, 0);
    if (param_4 < n) {
        v = func_02013378((Unk0201290c *) p, 0);
        func_020130d4((Unk0201290c *) p, func_020d3c44());
        func_0201308c((Unk0201290c *) p, param_4);
        func_020849f8(param_1, param_2, param_3);
        func_020130d4((Unk0201290c *) p, v);
        func_0201308c((Unk0201290c *) p, n);
    } else {
        func_020849f8(param_1, param_2, param_3);
    }
}

void func_020ea868(Unk020ea868 *param_1, void *param_2, void *param_3, u32 param_4) {
    u16 v;

    v = param_1->mUnk_06e;
    if (param_4 < v) {
        param_1->mUnk_06e = param_4;
        func_0207aec8(param_1, param_2, param_3);
        param_1->mUnk_06e = v;
    } else {
        func_0207aec8(param_1, param_2, param_3);
    }
}

void func_020ea84c(void) {
    func_01ff9048(0x29, &data_0217bbe8, 1);
}

void func_020ea7cc(Unk020ea670 *param_1, s32 param_2) {
    void *p;
    s32 n;
    s32 m;

    p = param_1->mUnk_004;
    n = func_02013344((Unk0201290c *) p, 0);
    data_0216c3d4 = n;
    if (param_2 < n) {
        func_020130d4((Unk0201290c *) p, func_020d3c44());
        func_0201308c((Unk0201290c *) p, param_2);
    }
    func_020849d0(param_1);
    m = data_0216c3d4;
    if (param_2 < m) {
        func_0201308c((Unk0201290c *) p, m);
    }
    data_0216c3d4 = -1;
}

void func_020ea740(Unk020ea670 *param_1, s32 param_2) {
    void *p;
    s32 n;
    s32 m;

    p = param_1->mUnk_004;
    n = func_02013344((Unk0201290c *) p, 0);
    data_0216c3d4 = n;
    if (param_2 < n) {
        func_020130d4((Unk0201290c *) p, func_020d3c44());
        func_0201308c((Unk0201290c *) p, param_2);
    }
    func_0201290c((Unk0201290c *) param_1->mUnk_004, 0, 0, 1);
    m = data_0216c3d4;
    if (param_2 < m) {
        func_0201308c((Unk0201290c *) p, m);
    }
    data_0216c3d4 = -1;
}

void func_020ea670(Unk020ea670 *param_1, s32 param_2) {
    void *p;
    u8 *q;
    s32 n;
    s32 m;

    p = param_1->mUnk_004;
    n = func_02013344((Unk0201290c *) p, 0);
    data_0216c3d4 = n;
    if (param_2 < n) {
        func_020130d4((Unk0201290c *) p, func_020d3c44());
        func_0201308c((Unk0201290c *) p, param_2);
    }
    q = (u8 *) p + ((Unk020ea670_08 *) p)->mUnk_008;
    data_0217bbe8 =
        ((Unk020ea670_0c *) (q + ((Unk020ea670_08 *) (q + ((Unk020ea670_0a *) q)->mUnk_00a))->mUnk_008))->mUnk_00c;
    func_020109c4((Unk020109c4 *) param_1, (void (*)(void *)) func_020ea84c, 0, 4, 3);
    func_020849d0(param_1);
    m = data_0216c3d4;
    if (param_2 < m) {
        func_0201308c((Unk0201290c *) p, m);
    }
    data_0216c3d4 = -1;
}
