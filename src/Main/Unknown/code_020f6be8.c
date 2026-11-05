#include "Main/Unknown/code_020f6be8.h"

#include "Main/Unknown/code_020fe4b4.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/code_020fe000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f6be4.h"
#include "Main/Unknown/code_020f8e78.h"
#include "Main/Unknown/code_020f9c40.h"
#include "code_02147cd8.h"

s32 func_020f7184(ItemObject *a, s32 b, s32 c) {
    Vec3 *v = &a->mVelocity;
    ItemKind *e;
    s32 r;
    enum { K0 } k;

    if (a->mFlags & 0x80000) {
        return 2;
    }
    if (c == 0 && (a->mFlags & 0x8000000) && !(a->mFlags & 0x10000000) && !(a->mFlags & 0x20000000)) {
        if (a->mUnk_78 & 0xf00) {
            return 2;
        }
        if (b == 0) {
            a->mUnk_78 |= data_02159b6c;
        } else {
            a->mUnk_78 |= data_02159b68;
            func_020f9c40((s32) a);
        }
        a->mUnk_120 = NULL;
        return 1;
    }
    if (b == 0) {
        k = a->mKind;
        e = &gItemKinds[k];
        if (e->mUnk_34 != NULL) {
            r = e->mUnk_34(a);
            if (r == 0) {
                return 2;
            }
            if (r == 1) {
                return 0;
            }
        }
    }
    if (b != 0) {
        a->mUnk_108.y = 0x266;
    } else {
        a->mUnk_108.y = 0x333;
        if (!(a->mFlags & 0x8000)) {
            a->mUnk_108.y += (s32) (((s64) Vec3Length(v) * 0x15c) >> 12);
            if (a->mUnk_108.y > 0x5c3) {
                a->mUnk_108.y = 0x5c3;
            }
        }
    }
    k = a->mKind;
    e = &gItemKinds[k];
    if (e->mUnk_40 == 0) {
        a->mUnk_120 = func_020f6e58;
    }
    a->mUnk_124 = (void (*)(ItemObject *, Vec3 *, Vec3 *)) func_020f6be4;
    if (a->mUnk_f0.y != 0) {
        Vec3 *w = &a->mUnk_f0;

        r = func_02039828(v, w);
        if (r < 0x3000) {
            Vec3AddScaled(0x3000 - r, w, v, v);
        }
    }
    a->mFlags |= 0x80001;
    func_020f9c40((s32) a);
    r = func_02039828(v, (Vec3 *) func_020e6b28());
    if (r > 1) {
        a->mUnk_108.x = 1;
    } else {
        a->mUnk_108.x = 0;
    }
    return 0;
}

void func_020f7104(ItemObject *a, s32 b) {
    s32 r;

    if (!(a->mFlags & 0x8000000)) {
        func_020f7184(a, 0, 0);
        return;
    }
    r = func_020f7184(a, 0, 0);
    if (r != 0) {
        return;
    }
    if (b == 0) {
        return;
    }
    func_020fe7a0(a->mKind, 0, 8, a->mId);
}

void func_020f70f0(ItemObject *a) {
    func_020f7184(a, 0, 1);
}

void func_020f7070(void *a, s32 b) {
    ItemObject *p = a;
    s32 r;

    if (!(p->mFlags & 0x8000000)) {
        func_020f7184(p, 1, 0);
        return;
    }
    r = func_020f7184(p, 1, 0);
    if (r != 0) {
        return;
    }
    if (b == 0) {
        return;
    }
    func_020fe7a0(p->mKind, 1, 8, p->mId);
}

void func_020f705c(ItemObject *a) {
    func_020f7184(a, 1, 1);
}

void func_020f6fc4(void *a, s32 b) {
    ItemObject *p = a;
    s32 r;
    enum { K0 } k;

    r = func_020f7184(p, 0, 0);
    if (r <= 1) {
        k = p->mKind;
        func_020f91fc(p, gItemKinds[k].mUnk_94);
    }
    if (r != 0) {
        return;
    }
    if (!(p->mFlags & 0x8000000)) {
        return;
    }
    if (b == 0) {
        return;
    }
    if (p->mKind == 5) {
        return;
    }
    func_020fe7a0(p->mKind, 2, 8, p->mId);
}

void func_020f6f10(ItemObject *a, s32 b, s32 c) {
    s32 r;
    enum { K0 } k;

    r = func_020f7184(a, 0, 0);
    if (r <= 1) {
        k = a->mKind;
        func_020f91fc(a, gItemKinds[k].mUnk_98);
    }
    if (r != 0) {
        return;
    }
    if (!(a->mFlags & 0x8000000)) {
        return;
    }
    if (b == 0) {
        return;
    }
    if (a->mKind == 5) {
        return;
    }
    func_020fe7a0(a->mKind, 3, c, a->mId);
}

void func_020f6e58(ItemObject *a) {
    Vec3 v;

    func_020397a8(&a->mUnk_f0, (Vec3 *) func_020e6b14(), &v);
    Vec3AddScaled(a->mUnk_108.x != 0 ? a->mUnk_108.y : -a->mUnk_108.y, &v, &a->mUnk_f0, &a->mUnk_f0);
    a->mFlags |= 0x80;
    a->mVelocity.y -= 0x400;
    Vec3Add(&a->mPos, &a->mVelocity, &a->mPos);
    a->mUnk_d8--;
    if (a->mUnk_d8 > 0) {
        return;
    }
    ReleaseItemPoolObject(&gItemPools[a->mKind], a);
}

void func_020f6be8(ItemObject *b, Vec3 *c, Vec3 *e, Vec3 *f) {
    Vec3 v;
    Vec3 a;
    Vec3 *q;
    s32 dot;
    s64 d;

    Vec3Sub(e, &b->mVelocity, &a);
    Vec3Sub(&b->mPos, c, &v);
    dot = Vec3Dot(f, &v);
    v.x -= (s32) (((s64) f->x * dot) >> 12);
    v.y -= (s32) (((s64) f->y * dot) >> 12);
    v.z -= (s32) (((s64) f->z * dot) >> 12);
    d = (s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z;
    if (d >= 0x10) {
        func_02039860(&v, &v);
    }
    if (b->mFlags & 0x8000) {
        Vec3AddScaled(0x666, &a, &b->mVelocity, &b->mVelocity);
        q = data_0217bc4c;
        q->x = (s32) (((s64) v.x * 0xccd) >> 12);
        q->y = (s32) (((s64) v.y * 0xccd) >> 12);
        q->z = (s32) (((s64) v.z * 0xccd) >> 12);
        Vec3Add(&b->mVelocity, data_0217bc4c, &b->mVelocity);
    } else {
        b->mVelocity.x = (s32) (((s64) e->x * 0x8cd) >> 12);
        b->mVelocity.y = (s32) (((s64) e->y * 0x8cd) >> 12);
        b->mVelocity.z = (s32) (((s64) e->z * 0x8cd) >> 12);
        q = data_0217bc4c;
        q->x = (s32) (((s64) v.x * 0x1800) >> 12);
        q->y = (s32) (((s64) v.y * 0x1800) >> 12);
        q->z = (s32) (((s64) v.z * 0x1800) >> 12);
        Vec3Add(&b->mVelocity, data_0217bc4c, &b->mVelocity);
    }
}
