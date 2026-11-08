#include "Main/Unknown/code_02102eb8.h"
#include "Main/Unknown/code_0208ab98.h"
#include "Main/Unknown/code_020f81c0.h"

#include "Main/Unknown/code_0208a000.h"
#include "Main/Unknown/code_020f8000.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02102674.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020f9c40.h"
#include "Main/Unknown/code_020f8e3c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0203c5e4.h"
#include "Main/Unknown/code_02073eb8.h"
#include "03/code_021b7000.h"
#include "03/unk_021d8000.h"
#include "Main/Unknown/code_02133000.h"
#include "03/code_021b7bb4.h"
#include "Main/Unknown/code_02077bc0.h"

void ResetItemGesso(ItemGesso *p) {
    s32 i;

    p->mKart = NULL;
    for (i = 0; i < 8; i++) {
        p->mUnk_130[i] = 0;
    }
    p->mUnk_138 = -1;
    p->mUnk_000.mAlpha = 0x1f;
    p->mUnk_19c = 0;
    p->mUnk_160 = FALSE;
}

BOOL func_0210300c(ItemGesso *p) {
    Unk0215a3b0 *e;
    s32 i;
    BOOL f;

    p->mUnk_138 = p->mUnk_138 + 1;
    if (p->mUnk_138 >= 0x11) {
        goto done;
    }
    e = &data_0215a3b0[p->mUnk_138];
    p->mUnk_154 = e->mUnk_00;
    p->mUnk_158 = e->mUnk_02;
    p->mUnk_164 = e->mUnk_04;
    p->mUnk_168 = e->mUnk_06;
    p->mUnk_16c = e->mUnk_08;
    p->mUnk_170 = e->mUnk_0a;
    i = p->mUnk_138;
    if (i != 0xc && i != 0xd) {
        if (p->mUnk_158 > 0) {
            p->mUnk_174 = 0xe66;
            p->mUnk_178 = 0x1266;
            p->mUnk_184.z = 0x4cd;
        } else if (i == 4) {
            p->mUnk_174 = 0x1000;
            p->mUnk_178 = 0x1000;
            p->mUnk_184.z = 0x1000;
        } else {
            p->mUnk_174 = 0x1333;
            p->mUnk_178 = 0xc29;
            p->mUnk_184.z = 0x28f;
        }
    } else if (i == 0xc) {
        p->mUnk_174 = 0x199a;
        p->mUnk_178 = 0x119a;
        p->mUnk_184.z = 0x800;
    } else {
        p->mUnk_174 = 0x800;
        p->mUnk_178 = 0x800;
        p->mUnk_184.z = 0x99a;
    }
    i = p->mUnk_138;
    f = TRUE;
    if (i != 2 && i != 0x10) {
        f = FALSE;
    }
    p->mUnk_194 = f;
    if (e->mUnk_02 > 0 && p->mUnk_138 != 0 && p->mUnk_138 != 0xe && p->mUnk_198 != FALSE) {
        func_020f8e3c((u32) p->mKart, 0xf1);
    }
    return FALSE;
done:
    return TRUE;
}

u32 func_02102eb8(ItemGesso *p, s32 b) {
    Unk020748a8 *s;
    s32 a;
    s32 b2;

    a = gRaceSetup->mEntryIndex;
    s = GetChaseCamera();
    func_020f82a4(0);
    if (a < 0) {
        b2 = (u16) (p->mUnk_000.mUnk_78 & ~0xff00);
    } else {
        b2 = a;
    }
    p->mKart = GetKart(b2);
    p->mUnk_000.mPos = p->mKart->mDrawMatrixPos;
    VEC_MultAdd(0x5800, &s->mUp, &p->mUnk_000.mPos, &p->mUnk_000.mPos);
    VEC_MultAdd(func_0203c5e4() != 0 ? 0x5800 : 0xa800, &s->mForward, &p->mUnk_000.mPos, &p->mUnk_000.mPos);
    VEC_Subtract(&p->mUnk_000.mPos, &s->mPos, &p->mUnk_13c);
    MTX_MultVec33(&p->mUnk_13c, s->mViewMatrix, &p->mUnk_13c);
    if (b != 0) {
        if (p->mUnk_000.mFlags & 0x10000000) {
            func_0210300c(p);
            p->mUnk_16c = p->mUnk_16c - 1;
        }
    } else {
        func_0210300c(p);
    }
    p->mUnk_148 = p->mUnk_154;
    p->mUnk_14c = p->mUnk_158;
    p->mUnk_180 = p->mUnk_174;
    p->mUnk_184.x = p->mUnk_178;
    if ((p->mUnk_000.mUnk_78 & 0x8000) == 0) {
        b2 = (u16) (p->mUnk_000.mUnk_78 & ~0xff00);
    } else {
        b2 = 8;
    }
    p->mUnk_198 = a == (u16) b2;
    FreeItemObjectCollisionSlot((s32) p);
    return (u32) InitCourseColorBlend(&p->mUnk_000.mColorBlend, 1);
}
