#include "Main/Unknown/code_020f73fc.h"

#include "Main/Unknown/code_020fe4b4.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/code_020fe000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f49bc.h"
#include "Main/Unknown/code_020f6be8.h"
#include "Main/Unknown/code_020f73a4.h"
#include "Main/Unknown/code_020f7c60.h"
#include "Main/Unknown/code_020f7c90.h"
#include "Main/Unknown/code_020f8e78.h"
#include "Main/Unknown/code_020f9c40.h"
#include "code_02147cd8.h"

void func_020f77f8(ItemObject *a, s32 b, Vec3 *c, Vec3 *d, MapObject *e) {
    ItemObject *p = a;
    Vec3 v;
    Vec3 v2;
    Vec3 w;
    s32 i;
    s32 n;
    s32 m;
    void (*cb)(ItemObject *, s32);

    if (p->mFlags & 0x80000) {
        return;
    }
    i = e ? e->mKindData->mUnk_28 : -1;
    switch (b) {
        case 1:
            if (p->mFlags & 0x1000) {
                break;
            }
            VEC_Subtract(&p->mPrevPos, c, &v);
            if (!(p->mFlags & 0x8000) && (p->mFlags & 0x1000000)) {
                func_020f7c90(p, c, &v);
                break;
            }
            p->mFlags |= 0x4000000;
            if (Vec3DotUnrounded(&p->mVelocity, &v) <= 0) {
                if ((s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z >= 0x10) {
                    Vec3NormalizeAndGetLengthUnchecked(&v, &v);
                }
                p->mUnk_124(p, d, &v);
                if (p->mFlags & 0x8000) {
                    break;
                }
                m = p->mUnk_e0;
                if ((s64) (c->x - p->mPos.x) * (c->x - p->mPos.x) + (s64) (c->y - p->mPos.y) * (c->y - p->mPos.y) +
                        (s64) (c->z - p->mPos.z) * (c->z - p->mPos.z) >=
                    (s64) m * m) {
                    break;
                }
                p->mPos.x = c->x + (s32) (((s64) m * v.x) >> 12);
                p->mPos.z = c->z + (s32) (((s64) m * v.z) >> 12);
                break;
            }
            if (p->mFlags & 0x8000) {
                break;
            }
            m = p->mUnk_e0;
            if ((s64) (c->x - p->mPos.x) * (c->x - p->mPos.x) + (s64) (c->y - p->mPos.y) * (c->y - p->mPos.y) +
                    (s64) (c->z - p->mPos.z) * (c->z - p->mPos.z) >=
                (s64) m * m) {
                break;
            }
            if ((s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z >= 0x10) {
                Vec3NormalizeAndGetLengthUnchecked(&v, &v);
            }
            m = p->mUnk_e0;
            p->mPos.x = c->x + (s32) (((s64) m * v.x) >> 12);
            p->mPos.z = c->z + (s32) (((s64) m * v.z) >> 12);
            break;
        case 2:
            if (p->mFlags & 0x1000) {
                func_020eda5c(&(gKartItems)[(u16) (p->mUnk_78 & ~0xff00)].mItemInUse, p);
            }
            n = 0;
            if ((s64) d->x * d->x + (s64) d->y * d->y + (s64) d->z * d->z >= 0x10) {
                n = Vec3NormalizeAndGetLengthUnchecked(d, &v2);
            }
            if (n != 0) {
                func_020f6be8(p, c, d, &v2);
            } else {
                VEC_Subtract(&p->mPos, c, &v2);
                if (v2.y < 0) {
                    v2.y = 0;
                }
                if ((s64) v2.x * v2.x + (s64) v2.y * v2.y + (s64) v2.z * v2.z >= 0x10) {
                    Vec3NormalizeAndGetLengthUnchecked(&v2, &v2);
                }
                w.x = (s32) (((s64) v2.x * 0x1800) >> 12);
                w.y = (s32) (((s64) v2.y * 0x1800) >> 12);
                w.z = (s32) (((s64) v2.z * 0x1800) >> 12);
                func_020f6be8(p, c, &w, &v2);
            }
            if (i == -1 || (p->mFlags & 0x8000000)) {
                func_020f6fc4(p, 1);
            } else {
                n = p->mKind;
                func_020f7104(p, 1);
                if (n == 5 || n == 9) {
                    i = -1;
                }
            }
    }
    if (i == -1) {
        return;
    }
    cb = (p->mFlags & 0x400000) ? (void (*)(ItemObject *, s32)) func_020f7c60
                                : (void (*)(ItemObject *, s32)) func_020f91fc;
    cb(p, i);
}

void func_020f7658(ItemObject *b, s32 c) {
    BOOL a;
    enum { K0 } k;

    if (!(b->mFlags & 0x8000000)) {
        if ((b->mFlags & 0x8000000) && !(b->mFlags & 0x10000000) && !(b->mFlags & 0x20000000)) {
            if (b->mUnk_78 & 0xf00) {
                return;
            }
            b->mUnk_78 |= data_02159b74;
            b->mUnk_120 = NULL;
            return;
        }
        if (b->mFlags & 0x180000) {
            return;
        }
        k = b->mKind;
        if (gItemKinds[k].mUnk_40 == 0 && !(b->mFlags & 0x180000)) {
            b->mUnk_120 = func_020f758c;
        }
        b->mFlags |= 0x100002;
        return;
    }
    if ((b->mFlags & 0x8000000) && !(b->mFlags & 0x10000000) && !(b->mFlags & 0x20000000)) {
        if (b->mUnk_78 & 0xf00) {
            a = FALSE;
        } else {
            b->mUnk_78 |= data_02159b74;
            b->mUnk_120 = NULL;
            a = TRUE;
        }
    } else {
        if (b->mFlags & 0x180000) {
            a = FALSE;
        } else {
            k = b->mKind;
            if (gItemKinds[k].mUnk_40 == 0 && !(b->mFlags & 0x180000)) {
                b->mUnk_120 = func_020f758c;
            }
            b->mFlags |= 0x100002;
            a = TRUE;
        }
    }
    if (a == FALSE) {
        return;
    }
    if (c == 0) {
        return;
    }
    func_020fe7a0(b->mKind, 4, 8, b->mId);
}

void func_020f7600(ItemObject *a) {
    enum { K0 } k;

    if (a->mFlags & 0x180000) {
        return;
    }
    k = a->mKind;
    if (gItemKinds[k].mUnk_40 == 0 && !(a->mFlags & 0x180000)) {
        a->mUnk_120 = func_020f758c;
    }
    a->mFlags |= 0x100002;
}

void func_020f758c(ItemObject *a) {
    if (a->mFlags & 0x8000) {
        func_020f68b0(a);
    }
    a->mUnk_d8--;
    if (a->mUnk_d8 <= 0) {
        ReleaseItemPoolObject(&gItemPools[a->mKind], a);
    } else {
        if (a->mUnk_d8 < 0xa) {
            func_020f9c40((s32) a);
        }
    }
}

void func_020f7430(ItemObject *b, s32 c) {
    BOOL a;

    if (!(b->mFlags & 0x8000000)) {
        if ((b->mFlags & 0x8000000) && !(b->mFlags & 0x10000000) && !(b->mFlags & 0x20000000)) {
            if (b->mUnk_78 & 0xf00) {
                return;
            }
            b->mUnk_78 |= data_02159b70;
            b->mUnk_120 = NULL;
            return;
        }
        if (b->mFlags & 0x180000) {
            return;
        }
        if (!(b->mFlags & 0x180000)) {
            b->mUnk_120 = (void (*)(ItemObject *)) func_020f73d4;
        }
        b->mFlags |= 0x100002;
        return;
    }
    if ((b->mFlags & 0x8000000) && !(b->mFlags & 0x10000000) && !(b->mFlags & 0x20000000)) {
        if (b->mUnk_78 & 0xf00) {
            a = FALSE;
        } else {
            b->mUnk_78 |= data_02159b70;
            b->mUnk_120 = NULL;
            a = TRUE;
        }
    } else {
        if (b->mFlags & 0x180000) {
            a = FALSE;
        } else {
            if (!(b->mFlags & 0x180000)) {
                b->mUnk_120 = (void (*)(ItemObject *)) func_020f73d4;
            }
            b->mFlags |= 0x100002;
            a = TRUE;
        }
    }
    if (a == FALSE) {
        return;
    }
    if (c == 0) {
        return;
    }
    func_020fe7a0(b->mKind, 5, 8, b->mId);
}

void func_020f73fc(ItemObject *a) {
    if (a->mFlags & 0x180000) {
        return;
    }
    if (!(a->mFlags & 0x180000)) {
        a->mUnk_120 = (void (*)(ItemObject *)) func_020f73d4;
    }
    a->mFlags |= 0x100002;
}
