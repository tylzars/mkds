#include "Main/Unknown/code_020e0058.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_020d8cac.h"

#include "Main/Unknown/code_020e005c.h"
#include "Main/Unknown/code_020d8000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020e01ec.h"
#include "Main/Unknown/code_020e01f0.h"
#include "Main/Unknown/unk_02158000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e337c.h"
#include "Main/Unknown/code_020e3618.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/unk_0217c000.h"

void func_020e0584(Unk020e005c *a, Vec3 *b, Vec3 *c, Unk020e04b0 *d) {
    Vec3 e;
    s32 f;
    s32 g;

    VEC_Subtract(b, &a->mPos, &e);
    f = Vec3DotUnrounded(&e, &a->mUnk_040);
    g = Vec3DotUnrounded(&e, &a->mUnk_034);
    d->mUnk_04.x = Vec3DotUnrounded(&e, &a->mUnk_028);
    d->mUnk_04.y = g;
    d->mUnk_04.z = f;
    if (c != NULL && a->mUnk_130 != FALSE) {
        f = Vec3DotUnrounded(c, &a->mUnk_040);
        g = Vec3DotUnrounded(c, &a->mUnk_034);
        d->mUnk_10.x = Vec3DotUnrounded(c, &a->mUnk_028);
        d->mUnk_10.y = g;
        d->mUnk_10.z = f;
    } else {
        d->mUnk_10.x = 0;
        d->mUnk_10.y = 0;
        d->mUnk_10.z = 0;
    }
    d->mUnk_00 = a;
}

void func_020e0538(Unk020e04b0 *a, Vec3 *b) {
    Unk020e005c *c = a->mUnk_00;

    if (c == NULL) {
        return;
    }
    Vec3MultiplyMatrix3x3(&a->mUnk_04, &c->mUnk_028.x, b);
    VEC_Add(&c->mPos, b, b);
}

BOOL func_020e04b0(Unk020e04b0 *a, Vec3 *b, Vec3 *c) {
    Unk020e005c *d = a->mUnk_00;

    if (d != NULL) {
        Vec3MultiplyMatrix3x3(&a->mUnk_04, &d->mUnk_028.x, b);
        VEC_Add(&d->mPos, b, b);
        if (d->mUnk_130 != FALSE) {
            Vec3MultiplyMatrix3x3(&a->mUnk_10, &d->mUnk_028.x, c);
            if (c->y < d->mUnk_120) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

s32 func_020e0448(Unk020e0448 *a) {
    Unk020e3ef4 *b = a->mUnk_00;
    s64 c;
    s64 d;

    if (b->mUnk_138 != 0 && b->mUnk_000.mKind == 0xcb) {
        c = (s64) a->mUnk_04.x * a->mUnk_04.x + (s64) a->mUnk_04.z * a->mUnk_04.z;
        d = (s64) b->mUnk_154 * b->mUnk_154;
        return c >= d;
    }
    return b->mUnk_138;
}

void *func_020e03f8(void) {
    void *p = HeapAlloc(GetHeap(func_020364e8()), 0x40);

    *(Unk020e03f8 *) p = *(const Unk020e03f8 *) data_021588a8;
    return p;
}

void *func_020e039c(void) {
    void *p = HeapAlloc(GetHeap(func_020364e8()), 0x2c);

    data_0217b784 = p;
    *(Unk020e039c *) p = *(const Unk020e039c *) data_0215887c;
    func_020d49d8(&data_0217b784);
    return data_0217b784;
}

void *func_020e0340(void) {
    void *p = HeapAlloc(GetHeap(func_020364e8()), 0x28);

    data_0217b780 = p;
    *(Unk020e0340 *) p = *(const Unk020e0340 *) data_02158854;
    func_020e6f50(&data_0217b780);
    return data_0217b780;
}

void func_020e01f0(void *a0, Unk020e005c *a1) {
    Unk020e0144 *b = &a1->mUnk_144;

    if (a1->mUnk_16c != 0) {
        Unk0210b7a8 buf;
        s32 k;

        a1->mUnk_16c--;
        a1->mUnk_010.x = 0;
        a1->mUnk_010.y = 0;
        a1->mUnk_010.z = 0;
        if (a1->mUnk_16c != 0) {
            return;
        }
        if ((a1->mDistanceSquaredAndFlags & 4) != 0) {
            return;
        }
        k = a1->mFarDistanceSquared == gSoundFalloffs[2].mUnk_20
                ? 2
                : (a1->mFarDistanceSquared == gSoundFalloffs[3].mUnk_20 ? 3 : 4);
        buf.mUnk_00 = 0x17e;
        buf.mUnk_04 = &a1->mPos;
        buf.mUnk_08 = k;
        buf.mUnk_0c = func_020d4ef4(&a1->mPos);
        func_0210b7a8(&buf);
        return;
    }
    if (func_020d8cc8(b) != FALSE) {
        if (a1->mStateMachine.mState == 2) {
            a1->mStateMachine.mNextState = 0;
            a1->mStateMachine.mNextStateRequested = 1;
        }
        a1->mUnk_16c = b->mUnk_1c->mUnk_0e;
    }
    a1->mUnk_0e8 = a1->mPos;
    func_020d8a5c(b, &a1->mPos);
    func_02046b40(&a1->mStateMachine);
    VEC_Subtract(&a1->mPos, &a1->mUnk_0e8, &a1->mUnk_010);
    VEC_MultAdd(-a1->mUnk_104, &a1->mUnk_034, &a1->mPos, &a1->mUnk_0f4);
}

u32 func_020e01ec(u32 p0) {
    return p0;
}

void func_020e012c(Unk020e005c *a) {
    Unk020e0144 *b = &a->mUnk_144;
    s32 v = func_020d8cac(b);
    s32 w = (u16) (((s64) v << 18) >> 12);
    s16 t = gPairsByAngle[(w >> 4) * 2];
    s32 p = (s32) (((s64) t * a->mUnk_168) >> 12);
    s32 m;

    b->mUnk_04 = p > 0x200 ? p : 0x200;
    m = b->mUnk_00->mUnk_00[b->mUnk_0c].mUnk_34;
    if (p <= 0x200) {
        p = 0x200;
    }
    b->mUnk_10 = (s32) (((s64) p * m) >> 12);
    if (func_020d8cac(b) >= 0x100) {
        a->mStateMachine.mNextState = 1;
        a->mStateMachine.mNextStateRequested = 1;
    }
}

void func_020e00f8(Unk020e005c *a) {
    s32 v = a->mUnk_168;

    a->mUnk_144.mUnk_04 = v;
    a->mUnk_144.mUnk_10 = (s32) (((s64) v * a->mUnk_144.mUnk_00->mUnk_00[a->mUnk_144.mUnk_0c].mUnk_34) >> 12);
}

void func_020e005c(Unk020e005c *a) {
    Unk020e0144 *b = &a->mUnk_144;

    if (b->mUnk_20->mUnk_0e == 0) {
        Unk020e0144_00 *d = b->mUnk_00;
        BOOL c;
        BOOL f = FALSE;

        if (d->mUnk_08 == 0) {
            if (b->mUnk_18 != 0) {
                c = b->mUnk_0c == d->mUnk_04 - 1;
            } else {
                c = b->mUnk_0c == 0;
            }
            if (c) {
                f = TRUE;
            }
        }
        if (f == FALSE) {
            return;
        }
    }
    if (func_020d8cac(b) >= 0xf00) {
        a->mStateMachine.mNextState = 2;
        a->mStateMachine.mNextStateRequested = 1;
    }
}

u32 func_020e0058(u32 p0) {
    return p0;
}
