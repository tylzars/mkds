#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020df890.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_020d7da8.h"
#include "Main/Unknown/code_020d8000.h"
#include "Main/Unknown/code_020d9000.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e43a8.h"
#include "Main/Unknown/code_020e0680.h"
#include "Main/Unknown/code_020e516c.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_020ea514.h"
#include "Main/Unknown/code_020ea588.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0216b000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "code_02146cbc.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02146000.h"

#pragma thumb off

void func_020dffac(Unk020e005c *a) {
    Unk020e0144 *p;
    s32 r;
    s32 n;
    u16 i;
    s32 t;

    p = &a->mUnk_144;
    r = func_020d8cac(p);
    i = (s32) (((s64) r * 0x40000) >> 12);
    t = gPairsByAngle[(i >> 4) * 2];
    n = (s32) (((s64) -t * a->mUnk_168) >> 12);
    p->mUnk_04 = n > 0x200 ? n : 0x200;
    if (n <= 0x200) {
        n = 0x200;
    }
    p->mUnk_10 = (s32) (((s64) n * p->mUnk_00->mUnk_00[p->mUnk_0c].mUnk_34) >> 12);
}

void func_020dff88(void *a) {
    func_020e1e38(data_0217b784, a, func_020e1dec);
}

u32 func_020dff70(u32 a) {
    switch (a) {
        case 0xca:
            return 1;
        default:
            return 0;
    }
}

s32 func_020dff4c(Unk020e005c *a) {
    s32 r;
    Unk020e0144 *p;

    p = &a->mUnk_144;
    r = func_020d8cac(p);
    if (p->mUnk_18 == 0) {
        r = 0x1000 - r;
    }
    return r;
}

#pragma thumb on
void func_020dff08(void) {
    void *r;

    r = FindCourseMapObjFile("koopa_block.nsbmd");
    func_020ea588(&gKoopaBlock, r, NULL);
    func_02084968(gKoopaBlock, 0x3f, 2, 0x294a);
    func_020e1dc0(data_0217b784, gKoopaBlock);
}

void func_020dfd64(Unk020e005c *a, Unk020fa294 *b) {
    func_02046be8(&a->mUnk_080, data_0216bff8, 3, a);
    a->mUnk_168 = (b->mUnk_28 << 12) / 100;
    func_020d7da8(&a->mUnk_144, b, a->mUnk_168);
    a->mUnk_16c = 0;
    *(Unk020e43a8_28 *) &a->mUnk_0a0 = *(Unk020e43a8_28 *) &a->mUnk_028;
    a->mUnk_124.x = 0;
    a->mUnk_124.y = 0;
    a->mUnk_124.z = 0;
    a->mUnk_130 = 0;
    a->mUnk_100 = (s32) (((s64) a->mUnk_01c * 0x190000) >> 12);
    a->mUnk_104 = (s32) (((s64) a->mUnk_020 * 0x64000) >> 12) >> 1;
    a->mUnk_108 = (s32) (((s64) a->mUnk_024 * 0xaf000) >> 12);
    a->mUnk_10c = (s32) (((s64) a->mUnk_024 * 0xaf000) >> 12);
    a->mUnk_110 = 0;
    a->mUnk_114.x = 1;
    a->mUnk_114.y = 0;
    a->mUnk_114.z = 0;
    a->mUnk_120 = 0x800;
    func_020d90a8(&a->mUnk_144, 0, 1);
    func_020d8918(&a->mUnk_144, &a->mUnk_004, &a->mUnk_010);
    a->mUnk_0e8 = a->mUnk_004;
    a->mUnk_134 = 0;
    a->mUnk_138 = 0;
    a->mUnk_002 |= data_0215881c;
    a->mUnk_002 &= ~2;
    a->mUnk_002 &= ~8;
    a->mUnk_066 = 0x1f;
    a->mUnk_080.mNextState = 0;
    a->mUnk_080.mNextStateRequested = 1;
    a->mUnk_070 = data_0217caec[3];
}
#pragma thumb off

Unk020de390 *func_020dfd14(void) {
    Unk020de390 *p;

    p = HeapAlloc(GetHeap(func_020364e8()), 0x40);
    *p = data_021587dc;
    return p;
}

Unk020de334 *func_020dfcb8(void) {
    data_0217b774 = HeapAlloc(GetHeap(func_020364e8()), 0x2c);
    *data_0217b774 = data_021587b0;
    func_020d49d8(&data_0217b774);
    return data_0217b774;
}

Unk020dfc44 *func_020dfc44(void) {
    data_0217b76c = HeapAlloc(GetHeap(func_020364e8()), 0x2c);
    *data_0217b76c = data_02158784;
    func_020e6f50(&data_0217b76c);
    data_0217b76c->mUnk_28 = DivFixed12(0x4000000, 0x1333);
    return data_0217b76c;
}

void func_020dfafc(void *a, MkdEfBubbleObject *b, void *c, s32 d) {
    s32 v;
    s32 w;
    s32 m[9];
    s32 n;

    if (b->mUnk_00.mUnk_80.mState != 0) {
        return;
    }
    w = 0x1e;
    func_01ff9048(0x14, &w, 1);
    func_01ff9048(0x19, func_020e6cf8(&b->mUnk_00.mPos), 0xc);
    if (b->mUnk_a8 != 0) {
        n = b->mUnk_a8 >> 4;
        Matrix3x3FromPairZ(m, gPairsByAngle[n * 2], gPairsByAngle[n * 2 + 1]);
        func_01ff9048(0x1a, m, 9);
    }
    func_01ff9048(0x1b, &b->mUnk_00.mScale, 3);
    func_020ea7cc(gMkdEfBubble, d);
    v = b->mUnk_00.mPos.y - b->mUnk_ac;
    if (v > 0x10000) {
        v = 0x1000 - ((v - 0x10000) >> 8);
        b->mUnk_b0.mUnk_030 = 0xd;
    } else {
        n = 0xd - ((0x10000 - v) >> 13);
        v = 0x1000;
        if (n < 1) {
            n = 1;
        }
        b->mUnk_b0.mUnk_030 = n;
    }
    if (v <= 0) {
        return;
    }
    func_020e53ac(&b->mUnk_b0, &v, 0, d);
}

void func_020dfae4(void) {
    func_02087de0(gMkdEfBubbleNsbta);
}

void func_020dfa50(void *a, MkdEfBubbleObject *b) {
    func_02046b40(&b->mUnk_00.mUnk_80);
    if (b->mUnk_f0 != 0) {
        return;
    }
    if ((b->mUnk_00.mFlags & 0x12) != 0) {
        b->mUnk_e8->mUnk_24 |= 8;
        b->mUnk_ec->mUnk_24 |= 8;
        return;
    }
    b->mUnk_e8->mUnk_24 &= ~8;
    b->mUnk_ec->mUnk_24 &= ~8;
    func_0208b5b0(b->mUnk_e8, &b->mUnk_00.mPos);
    func_0208b5b0(b->mUnk_ec, &b->mUnk_00.mPos);
}

void func_020df938(MkdEfBubbleObject *a) {
    Unk0210b7a8 s;
    s32 n;
    BOOL v;

    a->mUnk_a8 = 0;
    a->mUnk_00.mPos.y = a->mUnk_a4;
    a->mUnk_00.mUnk_10.y = 0x4b33;
    a->mUnk_00.mFlags &= ~2;
    a->mUnk_00.mFlags &= ~8;
    a->mUnk_00.mUnk_66 = 0x1f;
    if ((a->mUnk_00.mUnk_78 & 4) == 0) {
        if (a->mUnk_00.mUnk_70 == data_0217ca6c[2].mUnk_20) {
            n = 2;
        } else if (a->mUnk_00.mUnk_70 == data_0217ca6c[3].mUnk_20) {
            n = 3;
        } else {
            n = 4;
        }
        s.mUnk_00 = 0x18c;
        s.mUnk_04 = &a->mUnk_00.mPos;
        s.mUnk_08 = n;
        s.mUnk_0c = func_020d4ef4(&a->mUnk_00.mPos);
        func_0210b7a8(&s);
    }
    a->mUnk_e4 = 0;
    if (a->mUnk_e8 == NULL) {
        a->mUnk_e8 = func_0208b7bc(0x45, &a->mUnk_00.mPos);
    }
    if (a->mUnk_ec == NULL) {
        a->mUnk_ec = func_0208b7bc(0x46, &a->mUnk_00.mPos);
    }
    if (a->mUnk_e8 == NULL || a->mUnk_ec == NULL) {
        v = TRUE;
    } else {
        v = FALSE;
    }
    a->mUnk_f0 = v;
}

void func_020df890(MkdEfBubbleObject *a) {
    if (a->mUnk_00.mUnk_10.y < 0x1333) {
        if (a->mUnk_00.mUnk_10.y <= -0x1333) {
            a->mUnk_a8 = 0x8000;
        } else {
            a->mUnk_a8 = (s32) (((s64) (0x1333 - a->mUnk_00.mUnk_10.y) * data_0217b76c->mUnk_28) >> 12) >> 12;
        }
    }
    a->mUnk_00.mUnk_10.y -= 0x199;
    if (a->mUnk_00.mUnk_10.y < -0x3000) {
        a->mUnk_00.mUnk_10.y = -0x3000;
    }
    a->mUnk_00.mPos.y += a->mUnk_00.mUnk_10.y;
    if (a->mUnk_00.mPos.y < a->mUnk_a4) {
        a->mUnk_00.mUnk_80.mNextState = 1;
        a->mUnk_00.mUnk_80.mNextStateRequested = 1;
    }
}
