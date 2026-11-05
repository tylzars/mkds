#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f49bc.h"
#include "Main/Unknown/code_020f73fc.h"
#include "Main/Unknown/code_020f81c0.h"
#include "Main/Unknown/code_020f813c.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_020fe4b4.h"
#include "Main/Unknown/code_021001ac.h"
#include "Main/Unknown/unk_02159000.h"
#include "ITCM/code_01fff000.h"
#include "ITCM/code_01fff95c.h"
#include "Main/Unknown/code_02071000.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/code_020f4000.h"
#include "Main/Unknown/code_020f5000.h"
#include "Main/Unknown/code_020f6000.h"
#include "Main/Unknown/code_020f7000.h"
#include "Main/Unknown/code_020f8000.h"
#include "Main/Unknown/code_020f9000.h"
#include "Main/Unknown/code_020fa000.h"
#include "Main/Unknown/code_020fc000.h"
#include "Main/Unknown/code_020fe000.h"
#include "Main/Unknown/code_02100000.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_02070398.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020f5cc4.h"
#include "Main/Unknown/code_020f82c4.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_020f8d9c.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02077bc0.h"

void func_020f1048(ItemPool *v1, s32 v2, ItemObject **out, u16 v3, Vec3 *v) {
    s32 i;

    if (v1->mTakenCount + v2 > v1->mObjectCount) {
        while (v1->mTakenCount + v2 > v1->mObjectCount) {
            if (v1->mActiveCount > 0) {
                ReleaseItemPoolObject(v1, v1->mObjects[0]);
            }
        }
    }
    i = 0;
    while (i < v2) {
        out[i] = v1->mObjects[v1->mTakenCount++];
        func_020f99b8(out[i], v1->mKind, v3, v);
        i++;
    }
}

void ReleaseItemPoolObject(ItemPool *v1, ItemObject *v) {
    s32 i;
    ItemObject **p;
    s32 n;

    i = 0;
    p = v1->mObjects;
    while (i < v1->mTakenCount) {
        if (p[i] == v) {
            goto found;
        }
        i++;
    }
    i = v1->mTakenCount;
found:
    if (i < v1->mUnk_18) {
        v1->mUnk_18 = v1->mUnk_18 - 1;
        n = v1->mUnk_18;
        for (; i < n; i++) {
            p[i] = p[i + 1];
        }
    }
    if (i < v1->mActiveCount) {
        v1->mActiveCount = v1->mActiveCount - 1;
        p[i] = p[v1->mActiveCount];
        i = v1->mActiveCount;
    }
    if (i < v1->mTakenCount) {
        v1->mTakenCount = v1->mTakenCount - 1;
        p[i] = p[v1->mTakenCount];
        i = v1->mTakenCount;
    }
    p[i] = v;
    ReleaseItemObject(v);
    v1->mReservedCount = v1->mReservedCount - 1;
}

void StartItemObject(ItemPool *v1, ItemObject *v) {
    s32 i;
    s32 n;
    ItemObject **p;
    s32 c;
    ItemKind *t;
    enum { K0 } k;

    c = v1->mActiveCount;
    n = v1->mTakenCount;
    i = c;
    p = v1->mObjects;
    if (c < n) {
        do {
            if (p[i] == v) {
                goto found;
            }
            i++;
        } while (i < n);
    }
    i = n;
found:
    if (c < i) {
        p[i] = p[c];
        p[v1->mActiveCount] = v;
    }
    v1->mActiveCount = v1->mActiveCount + 1;
    v->mFlags |= 0x2000;
    k = v1->mKind;
    t = gItemKinds + k;
    if (t->mUnk_6c != 0) {
        func_020f9ca8(v);
    }
    v->mAgeFrames = 0;
    k = v->mKind;
    t = gItemKinds + k;
    if (t->mUnk_1c != NULL) {
        t->mUnk_1c(v);
    }
}

void func_020f0e2c(ItemPool *v1, ItemObject *v) {
    s32 i;
    s32 n;
    ItemObject **p;

    n = v1->mActiveCount;
    i = 0;
    p = v1->mObjects;
    while (i < n) {
        if (p[i] == v) {
            goto found;
        }
        i++;
    }
    i = n;
found:
    n = v1->mUnk_18;
    if (i < n) {
        return;
    }
    p[i] = p[n];
    p[v1->mUnk_18] = v;
    v1->mUnk_18 = v1->mUnk_18 + 1;
}

void DrawItemPool(ItemPool *v1, void *a) {
    if (v1->mUnk_24 != NULL) {
        func_020ed718((Unk020ed718 *) v1, a, (void (*)(void *, void *, void *)) v1->mUnk_24);
    } else {
        func_020ed79c((Unk020ed718 *) v1, (Vec3 *) a);
    }
}

void func_020f0d04(ItemObject *p) {
    void *(*f)(void *, void *, s32);
    s32 i;
    void *z;

    z = NULL;
    i = p->mKind;
    if ((p->mUnk_78 & 0xf00) != 0) {
        z = func_020fe4c0(z, p, 1);
        func_020fe4c0(z, p, 0);
        func_020fe4b4(p);
        if (p->mUnk_78 & 0x800) {
            func_020f70f0(p);
        }
        if (p->mUnk_78 & 0x400) {
            func_020f705c(p);
        }
        if (p->mUnk_78 & 0x200) {
            func_020f7600(p);
        }
        if (p->mUnk_78 & 0x100) {
            func_020f73fc(p);
        }
    } else {
        f = gItemKinds[i].mUnk_48;
        z = f(z, p, 1);
        f(z, p, 0);
        gItemKinds[i].mUnk_50(p);
    }
    p->mFlags |= 0x20000000;
}

void func_020f0b00(ItemPool *v1, s32 a, void *b, s32 c) {
    ItemObject *e;
    s32 i;
    s32 m;
    s32 n;
    ItemObject **p;
    s32 k;
    enum { J0 } j;
    void (*g)(void *);

    i = v1->mTakenCount;
    v1->mTakenCount = i + 1;
    e = v1->mObjects[i];
    func_020f9054(e, v1->mKind, b, c);
    v1->mReservedCount = v1->mReservedCount + 1;
    k = v1->mActiveCount;
    n = v1->mTakenCount;
    p = v1->mObjects;
    m = k;
    if (k < n) {
        do {
            if (p[m] == e) {
                goto found;
            }
            m++;
        } while (m < n);
    }
    m = n;
found:
    if (k < m) {
        p[m] = p[k];
        p[v1->mActiveCount] = e;
    }
    v1->mActiveCount = v1->mActiveCount + 1;
    e->mFlags |= 0x2000;
    j = v1->mKind;
    if (gItemKinds[j].mUnk_6c != 0) {
        func_020f9ca8(e);
    }
    e->mAgeFrames = 0;
    j = e->mKind;
    if (gItemKinds[j].mUnk_1c != NULL) {
        gItemKinds[j].mUnk_1c(e);
    }
    if (c != 0) {
        g = func_020fe4b4;
    } else {
        j = e->mKind;
        g = gItemKinds[j].mUnk_50;
    }
    g(e);
    e->mFlags |= 0x20000000;
    if (c != 0) {
        if (e->mUnk_78 & 0x800) {
            func_020f70f0(e);
        }
        if (e->mUnk_78 & 0x400) {
            func_020f705c(e);
        }
        if (e->mUnk_78 & 0x200) {
            func_020f7600(e);
        }
        if (e->mUnk_78 & 0x100) {
            func_020f73fc(e);
        }
    } else if ((e->mUnk_78 & 0x1000) == 0) {
        k = (u16) ((e->mUnk_78 & 0x8000) == 0 ? (u16) (e->mUnk_78 & ~0xff00) : 8);
        if (k != 8) {
            func_02071894(GetKart(k));
        }
    }
    if (a > 0) {
        e->mUnk_7a = a;
        e->mUnk_7a |= data_02159618;
    }
}

s32 func_020f0950(ItemPool *a, s32 b, s32 c) {
    enum { K0 } k;
    s32 i;
    ItemObject *e;
    ItemObject **p;
    s32 n;
    BOOL r;
    BOOL z0;
    BOOL z1;
    BOOL z2;
    BOOL z3;
    BOOL z4;
    BOOL z5;
    u32 h;

    k = b;
    h = ((u32) (k & 0xf0) << 12) >> 16;
    n = a->mActiveCount;
    p = a->mObjects;
    r = FALSE;
    i = 0;
    k &= 0xf;
    z0 = FALSE;
    z1 = FALSE;
    z2 = FALSE;
    z3 = FALSE;
    z4 = FALSE;
    z5 = FALSE;
    for (; i < n; i++) {
        e = p[i];
        if (c != e->mId) {
            continue;
        }
        r = TRUE;
        if (k < 4) {
            e->mVelocity.x = (s32) (((s64) e->mVelocity.x * 0x4cd) >> 12);
            e->mVelocity.y = (s32) (((s64) e->mVelocity.y * 0x4cd) >> 12);
            e->mVelocity.z = (s32) (((s64) e->mVelocity.z * 0x4cd) >> 12);
        }
        switch (k) {
            case 0:
                func_020f7104(e, z0);
                break;
            case 1:
                func_020f7070(e, z1);
                break;
            case 2:
                func_020f6fc4(e, z2);
                break;
            case 3:
                if (a->mKind == 1) {
                    if (func_020f5324(e, h) == 0) {
                        break;
                    }
                }
                func_020f6f10(e, z3, h);
                break;
            case 4:
                func_020f7658(e, z4);
                break;
            case 5:
                func_020f7430(e, z5);
                break;
        }
    }
    return r;
}

s32 func_020f0898(ItemPool *a, u8 *b) {
    s32 k;
    s32 i;
    s32 n;
    ItemObject *e;
    s32 c;
    ItemObject **p;
    BOOL m;

    n = a->mActiveCount;
    i = 0;
    m = FALSE;
    k = b[1];
    p = a->mObjects;
    for (; i < n; i++) {
        e = p[i];
        if (k != e->mId) {
            continue;
        }
        m = TRUE;
        c = b[2];
        if (a->mKind == 1) {
            func_020f5cc4((u32) e, c);
        }
        if (a->mKind == 5) {
            func_020fc8ec((Unk020fc2e8 *) e, c);
        }
        if (a->mKind == 0xb) {
            func_021003e8((Unk02101c84 *) e, c, b[3]);
        }
    }
    return m;
}

void func_020f0758(ItemPool *a, s32 m, s32 b, u8 *c, s32 d) {
    enum { K0 } k;

    switch (m) {
        case 0:
            k = a->mKind;
            if (!gItemKinds[k].mUnk_48) {
                return;
            }
            if (c[1] == 0xff) {
                return;
            }
            func_020f0b00(a, b, c, 0);
            if (a->mKind == 6) {
                func_020f82e8(0);
            }
            if (a->mKind == 0xa) {
                func_020f82a4(0);
            }
            return;
        case 1:
            func_020f0b00(a, b, c, 1);
            return;
        case 2:
            if (func_020f0950(a, c[2], c[1]) != 0) {
                return;
            }
            break;
        case 3:
            if (func_020f0898(a, c) != 0) {
                return;
            }
            break;
        default:
            return;
    }
    func_020fe56c(a->mKind, m, b, c, d);
}

void func_020f0684(ItemObject **p, s32 i, s32 n, s32 v1) {
    ItemObject *v;
    ItemObject *w;
    s32 j;

    if (i >= n) {
        return;
    }
    do {
        v = p[i - 1];
        w = p[i];
        if ((v->mFlags & 0x180000) != 0) {
            goto next;
        }
        if (func_020f9c08(v) != 0) {
            if (func_020f9c08(w) == 0) {
                goto next;
            }
            j = 0;
            do {
                if ((w->mUnk_fc & data_021595e4[j]) != 0) {
                    goto next;
                }
                if ((v->mUnk_fc & data_021595e4[j]) != 0) {
                    p[i - 1] = w;
                    p[i] = v;
                    goto next;
                }
                j++;
            } while (j < 0xd);
        } else if (func_020f9c08(w) != 0) {
            p[i - 1] = w;
            p[i] = v;
        }
    next:
        i += v1;
    } while (i < n);
}

void UpdateItemPool(ItemPool *a) {
    ItemObject **e;
    ItemObject *p;
    Kart *q;
    s32 k;
    s32 min;
    Vec3 *b;
    Vec3 *c;
    s32 n;
    s32 i;
    s32 t;
    s32 v;
    s32 w;
    s32 d;
    s32 z;
    s32 m;
    s32 g;
    s32 h;
    u16 u;

    e = a->mObjects;
    n = a->mActiveCount;
    if (a->mLimit > 1 && a->mLimit - a->mReservedCount < 2) {
        m = a->mUnk_18;
        if ((t = func_02061f90()) == 0) {
            if (a->mLimit - a->mReservedCount < 1 && a->mActiveCount > 0) {
                func_020f9ba8(a->mObjects[0]);
            }
        } else {
            if (a->mKind == 2) {
                m -= 3;
            }
            func_020f0684(e, t, m, 7);
        }
    }
    if (data_021759c0->mMode != 5) {
        for (i = 0; i < n; i++) {
            if (UpdateItemObject(a, e[i], 0) != 0) {
                n = a->mActiveCount, i--;
            }
        }
        return;
    }
    for (i = 0; i < n; i++) {
        p = e[i];
        v = (u16) (p->mUnk_7a & ~0x8000);
        if (v <= 0) {
            if (UpdateItemObject(a, p, 0) != 0) {
                n = a->mActiveCount;
                i--;
            }
        } else {
            w = p->mUnk_7a & 0x8000;
            k = 1;
            if (w != 0) {
                min = 0x5f592e1;
                p->mUnk_7a &= ~0x8000;
                k += v;
            } else {
                k++;
                for (z = v >> 2; z != 0; z >>= 2) {
                    k++;
                }
            }
            func_020d5180(&p->mPos, p->mUnk_e0 + k * 0xa000, 0x6000);
            p->mUnk_7a++;
            do {
                p->mUnk_7a--;
                if (UpdateItemObject(a, p, 1) != 0) {
                    n = a->mActiveCount;
                    i--;
                    break;
                }
                if (w != 0) {
                    b = p->mUnk_d0;
                    u = p->mUnk_78 & ~0xff00;
                    q = GetKart(u);
                    c = &q->mUnk_98;
                    d = ((c->x - b->x) >> 12) * ((c->x - b->x) >> 12);
                    g = (c->y - b->y) >> 12;
                    h = (c->z - b->z) >> 12;
                    d += g * g;
                    d += h * h;
                    if (min <= d) {
                        break;
                    }
                    min = d;
                }
            } while (--k > 0);
        }
    }
}

BOOL TryReleaseFirstItemObject(ItemPool *v1) {
    if (v1->mActiveCount <= 0) {
        return FALSE;
    }
    ReleaseItemPoolObject(v1, v1->mObjects[0]);
    return TRUE;
}

#pragma thumb on
void CreateItemPool(ItemPool *q, s32 a, s32 *b) {
    void *v;
    s32 n;
    s32 s;
    s32 k;
    s32 i;

    v = GetHeap(func_020364e8());
    k = *b;
    n = gItemKinds[a].mObjectCount;
    s = gItemKinds[a].mObjectSize;
    q->mKind = a;
    q->mObjects = n != 0 ? (ItemObject **) HeapAlloc(v, n * 4) : 0;
    q->mObjectCount = n;
    q->mUnk_0c = gItemKinds[a].mUnk_10;
    q->mTakenCount = 0;
    q->mActiveCount = 0;
    q->mUnk_18 = 0;
    q->mReservedCount = 0;
    q->mLimit = gItemKinds[a].mLimit;
    for (i = 0; i < n; i++) {
        q->mObjects[i] = HeapAlloc(v, s);
        InitItemObject(q->mObjects[i], k, a);
        k++;
        q->mObjects[i]->mPoolIndex = i;
    }
    q->mUnk_24 = gItemKinds[a].mUnk_2c;
    q->mUnk_28 = gItemKinds[a].mUnk_30;
    q->mUnk_2c = gItemKinds[a].mUnk_70;
    q->mUnk_30 = gItemKinds[a].mUnk_74;
    q->mUnk_34 = gItemKinds[a].mUnk_78;
    q->mUnk_38 = gItemKinds[a].mUnk_5c;
    q->mUnk_3c = gItemKinds[a].mUnk_a4;
    *b = k;
}

#pragma thumb off
BOOL func_020f0154(KartItems *p) {
    Kart *b;
    u16 v;
    enum { K0 } i;

    b = p->mKart;
    if (func_02061fec() == 0) {
        return FALSE;
    }
    if (b->mState != 0) {
        return FALSE;
    }
    if ((b->mUnk_4c & 0x20000000) != 0) {
        return FALSE;
    }
    if (p->mItemInUse.mUnk_000 != 0xf) {
        p->mFlags |= data_021595b8;
    } else if (p->mHeldItem.mUnk_00 != 0x13) {
        p->mFlags |= data_021595bc;
    } else if (p->mSlotState != 0) {
        p->mFlags |= data_021595c0;
    }
    i = p->mUnk_200;
    v = data_0217562a[i].mBits & 0x40;
    if (v != 0) {
        p->mFlags |= data_021595c4;
    }
    i = p->mUnk_200;
    v = data_0217562a[i].mBits & 0x80;
    if (v != 0) {
        p->mFlags |= data_021595c8;
    }
    return TRUE;
}

void func_020f00f0(KartItems *p) {
    if ((p->mKart->mUnk_7c & 0x400) != 0) {
        return;
    }
    if (data_021759c0->mMode == 5) {
        return;
    }
    if (p->mSlotState == 0) {
        return;
    }
    func_020f81c0(p);
}

void func_020f0044(KartItems *p) {
    if ((p->mKart->mUnk_7c & 0x400) != 0) {
        return;
    }
    if (p->mHeldItem.mUnk_00 != 0x13) {
        func_020f45f0(&p->mHeldItem, 0);
    }
    if (data_021759c0->mMode == 5) {
        return;
    }
    if (p->mSlotState != 0) {
        func_020f81c0(p);
    }
    if (p->mActiveItem != 0x13) {
        p->mActiveItem = 0x13;
    }
    if (data_021759c0->mMode == 5) {
        return;
    }
    if (p->mItemInUse.mUnk_000 == 0xf) {
        return;
    }
    func_020edb00(&p->mItemInUse);
}

void func_020eff40(KartItems *p) {
    BOOL f;

    f = data_021759c0->mMode == 5;
    if ((p->mKart->mUnk_7c & 0x400) != 0) {
        return;
    }
    if ((u32) (p->mKart->mUnk_29c - 2) <= 1) {
        return;
    }
    if (f && p->mActiveItem != 0x13) {
        return;
    }
    if (p->mHeldItem.mUnk_00 != 0x13 && p->mHeldItem.mUnk_20 == 0) {
        func_020f41b0(&p->mHeldItem);
    }
    if (f) {
        return;
    }
    if (p->mSlotState != 0) {
        func_020f81c0(p);
    }
    if (f) {
        return;
    }
    if (p->mItemInUse.mUnk_000 == 0xf) {
        return;
    }
    if (p->mItemInUse.mUnk_024 != 0) {
        return;
    }
    func_020edad8(&p->mItemInUse);
}

void func_020efea4(KartItems *p) {
    if ((u32) (p->mKart->mUnk_29c - 2) <= 1) {
        return;
    }
    if (data_021759c0->mMode == 5) {
        return;
    }
    if (p->mItemInUse.mUnk_000 == 0xf) {
        return;
    }
    if (p->mItemInUse.mUnk_024 != 0) {
        return;
    }
    if (p->mItemInUse.mUnk_008 != 1 && p->mItemInUse.mUnk_008 != 2) {
        return;
    }
    func_020edad8(&p->mItemInUse);
}

BOOL func_020efd84(KartItems *p, s32 a) {
    Unk020f40dc *r;
    ItemPool *q;
    enum { K0 } i;

    r = &p->mHeldItem;
    if (a == 0x13) {
        return TRUE;
    }
    if (p->mActiveItem != 0x13) {
        p->mActiveItem = 0x13;
    }
    if (p->mSlotState != 0) {
        if (p->mSlotState == 1 && p->mSlotFrames < 0x3c) {
            i = gItemInfos[a].mObjectKind;
            q = &gItemPools[i];
            q->mReservedCount--;
            return TRUE;
        }
        StopItemSlot(p);
        func_020f47e4(r, a);
    } else {
        if (r->mUnk_00 == 0x13 && r->mUnk_08 == 0) {
            i = gItemInfos[a].mObjectKind;
            q = &gItemPools[i];
            q->mReservedCount--;
        }
    }
    func_020f4754(r, 1);
    return r->mUnk_00 == 0x13;
}

void func_020efd1c(KartItems *p, ItemObject *a) {
    Kart *b;
    Vec3 *v;

    b = p->mKart;
    if ((b->mUnk_48 & 1) != 0) {
        v = &b->mUnk_15c;
    } else {
        v = &data_021595d8;
    }
    func_020f98a0(a, &b->mUnk_98, v, &b->mKartModelsEntry->mUnk_040, func_0206c0a8(b));
    if ((b->mUnk_48 & 1) != 0) {
        a->mFlags |= 0x40000000;
    }
}

void func_020efc74(KartItems *p, s32 a) {
    Unk020f371c_Ref *r;
    Kart *b;
    Vec3 *v;
    s64 d;
    s32 t;
    if ((t = func_020f4090(a)) != 0) {
        p->mUnk_1f0.mUnk_00 = (Unk020f371c *) t;
        p->mUnk_1f0.mUnk_04 = 1;
    }
    if ((r = &p->mUnk_1f0)->mUnk_00 == NULL) {
        return;
    }
    b = p->mKart;
    v = &b->mUnk_98;
    func_020f3c54(r, r, v);
    d = (s64) (r->mUnk_00->mUnk_18->x - v->x) * (r->mUnk_00->mUnk_18->x - v->x);
    d += (s64) (r->mUnk_00->mUnk_18->z - v->z) * (r->mUnk_00->mUnk_18->z - v->z);
    if (d < ((s64) 0x15f9 << 32)) {
        return;
    }
    func_020f3a58(r, r, v);
}

#pragma thumb on
void InitKartItems(KartItems *a, s32 n) {
    Unk02175620_060 *q;

    a->mKartIndex = n;
    a->mKart = GetKart(n);
    a->mUnk_200 = ((Unk021759c0_000 *) data_021759c0)->mUnk_07c[n].mUnk_00;
    InitItemSlot(a, a);
    func_020f4b20(&a->mHeldItem, a);
    func_020ee684(&a->mItemInUse, a);
    q = (Unk02175620_060 *) gCourseMap;
    a->mUnk_1f0.mUnk_00 = q->mUnk_060 != 0 ? q->mUnk_0b0 : 0;
    a->mUnk_1f0.mUnk_04 = 1;
    a->mUnk_204 = FALSE;
    a->mUnk_208 = FALSE;
    a->mUnk_20c = FALSE;
}

#pragma thumb off
void func_020efb84(Unk020eda5c *p, ItemObject *v) {
    StartItemObject(&gItemPools[v->mKind], v);
    func_020efd1c(p->mUnk_00c, v);
    v->mFlags &= ~0x1000;
}

void func_020efa60(Unk020eda5c *a, s32 f) {
    ItemObject *b;
    s32 (*cb)(void *, void *);
    void (*v)(struct ItemObject *);

    a->mUnk_020--;
    b = a->mUnk_014[a->mUnk_020];
    cb = gItemKinds[b->mKind].mUnk_24;
    func_020efb84(a, b);
    if (cb(a, b) == 0) {
        if (a->mUnk_00c->mUnk_208 != FALSE) {
            b->mUnk_78 |= data_021595ac;
            f = 0;
        }
    }
    b->mUnk_d4 = gItemKinds[b->mKind].mUnk_30(b->mUnk_d0, b->mUnk_e0 << 1, gItemKinds[b->mKind].mUnk_5c,
                                              gItemKinds[b->mKind].mUnk_a4, 0x1f);
    if (b->mFlags & 0x400000) {
        func_020f90bc(b);
    }
    v = gItemKinds[b->mKind].mUnk_28;
    if ((b->mFlags & 0x180000) == 0) {
        b->mUnk_120 = v;
    }
    if (f != 0) {
        func_02071894(a->mUnk_010);
    }
}

void func_020efa48(Unk020eda5c *a, ItemObject *v) {
    a->mUnk_020 = a->mUnk_020 - 1;
    func_020efb84(a, v);
}

void func_020ef9a8(Unk020eda5c *a) {
    Unk020eda5c *p;
    ItemObject *b;
    Vec3 *v;
    s32 d;

    p = a;
    b = a->mUnk_014[0];
    v = &a->mUnk_02c.mUnk_18;
    p->mUnk_090 = *v;
    p->mUnk_09c.x = -v->x;
    p->mUnk_09c.y = -v->y;
    p->mUnk_09c.z = -v->z;
    d = (s32) (((s64) a->mUnk_084.z << 14) >> 12);
    Vec3AddScaled(a->mUnk_078 + d, &p->mUnk_09c, &a->mUnk_050, &p->mUnk_0a8);
    Vec3AddScaled((s32) (((s64) a->mUnk_0e8 * a->mUnk_084.z) >> 12), &a->mUnk_02c.mUnk_0c, &p->mUnk_0a8, &b->mPos);
}

void func_020ef8c4(Unk020eda5c *a) {
    Unk020eda5c *p;
    ItemObject *b;
    Vec3 *v;
    s32 d;

    p = a;
    b = a->mUnk_014[0];
    v = &a->mUnk_02c.mUnk_18;
    p->mUnk_090 = *v;
    p->mUnk_09c.x = -v->x;
    p->mUnk_09c.y = -v->y;
    p->mUnk_09c.z = -v->z;
    d = (s32) (((s64) a->mUnk_084.z << 14) >> 12);
    Vec3AddScaled(a->mUnk_078 + d, &p->mUnk_09c, &a->mUnk_050, &p->mUnk_0a8);
    Vec3AddScaled((s32) (((s64) a->mUnk_0e8 * a->mUnk_084.z) >> 12), &a->mUnk_02c.mUnk_0c, &p->mUnk_0a8, &b->mPos);
    b->mUnk_94.mUnk_00[1] = a->mUnk_02c.mUnk_0c;
    b->mUnk_94.mUnk_00[2].x = -p->mUnk_09c.x;
    b->mUnk_94.mUnk_00[2].y = -p->mUnk_09c.y;
    b->mUnk_94.mUnk_00[2].z = -p->mUnk_09c.z;
    func_020397a8(&b->mUnk_94.mUnk_00[1], &b->mUnk_94.mUnk_00[2], &b->mUnk_94.mUnk_00[0]);
}

void func_020ef65c(Unk020eda5c *a, Vec3 *v, Vec3 *w) {
    Unk020eda5c *p;
    Vec3 *q;
    Vec3 t;
    s32 d;
    s64 sq;

    p = a;
    q = &p->mUnk_090;
    t = a->mUnk_02c.mUnk_18;
    if (a->mUnk_080 != 0) {
        Vec3AddScaled(0x19a, &a->mUnk_06c, &t, &t);
    }
    q->x = (s32) (((s64) q->x * 0xccd) >> 12);
    q->y = (s32) (((s64) q->y * 0xccd) >> 12);
    q->z = (s32) (((s64) q->z * 0xccd) >> 12);
    Vec3AddScaled(0x333, &t, q, q);
    sq = (s64) q->x * q->x + (s64) q->y * q->y + (s64) q->z * q->z;
    if (sq >= 0x10) {
        func_02039860(q, &t);
    }
    p->mUnk_09c.x = -t.x;
    p->mUnk_09c.y = -t.y;
    p->mUnk_09c.z = -t.z;
    d = (s32) (((s64) a->mUnk_084.z << 14) >> 12);
    Vec3AddScaled(a->mUnk_078 + d, &p->mUnk_09c, &a->mUnk_050, w);
    if (a->mUnk_020 > 1) {
        p->mUnk_0e4 += (s32) (((s64) a->mUnk_07c * 0x333) >> 12);
        p->mUnk_0e4 -= (s32) (((s64) p->mUnk_0e4 * 0x266) >> 12);
    } else {
        p->mUnk_0e4 += (s32) (((s64) a->mUnk_07c * 0xd1f) >> 12);
        p->mUnk_0e4 -= (s32) (((s64) p->mUnk_0e4 * 0x68f) >> 12);
    }
    Vec3AddScaled(p->mUnk_0e4 - a->mUnk_07c + (s32) (((s64) a->mUnk_0e8 * a->mUnk_084.z) >> 12), &a->mUnk_02c.mUnk_0c,
                  w, v);
}

void func_020ef4a0(Unk020eda5c *a) {
    ItemObject *b;
    KartItems *c;
    s32 n;
    enum { K0 } k, i;

    b = a->mUnk_014[0];
    c = a->mUnk_00c;
    n = b->mUnk_68.z;
    func_020ef65c(a, &b->mPos, &a->mUnk_0a8);
    if (b->mAgeFrames > 0xc) {
        k = b->mKind;
        if (func_020fa0b8(b, gItemKinds[k].mUnk_70, 0x333) != 0) {
            func_020f9f08(b, a->mUnk_084.x, a->mUnk_084.y);
        }
    }
    if (n < 0xccd && b->mUnk_68.z >= 0xccd && a->mUnk_028 == data_021759c0->mEntryIndex) {
        func_020719bc(&c->mKart->mUnk_00, 0xe7);
    }
    if ((c->mFlags & 0x284) == 0x284 && a->mUnk_000 != 0xf && a->mUnk_024 == 0) {
        func_020efa60(a, 1);
    }
    if (a->mUnk_170 != NULL) {
        c->mActiveItem = 0x13;
        i = c->mUnk_200;
        if ((u16) (data_0217562a[i].mBits & 0x40) != 0) {
            c->mFlags |= data_021595a0;
        }
        i = c->mUnk_200;
        if ((u16) (data_0217562a[i].mBits & 0x80) != 0) {
            c->mFlags |= data_021595a4;
        }
        func_020efa60(a, 1);
    }
    c->mFlags |= data_021595a8;
}

void func_020ef350(Unk020eda5c *a) {
    Unk020eda5c *c;
    ItemObject *b;
    Vec3 v;
    s64 t;
    s64 sq;
    enum { K0 } k;

    c = a;
    b = a->mUnk_014[0];
    func_020ef4a0(a);
    if ((b->mFlags & 0x1000) != 0) {
        v.x = (s32) (((s64) c->mUnk_09c.x << 13) >> 12);
        v.y = (s32) (((s64) c->mUnk_09c.y << 13) >> 12);
        v.z = (s32) (((s64) c->mUnk_09c.z << 13) >> 12);
        Vec3Add(&v, &a->mUnk_02c.mUnk_18, &v);
        sq = (s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z;
        if (sq >= 0x10) {
            func_02039860(&v, &v);
        }
        b->mUnk_94.mUnk_00[2].x = -v.x;
        b->mUnk_94.mUnk_00[2].y = -v.y;
        b->mUnk_94.mUnk_00[2].z = -v.z;
        b->mUnk_94.mUnk_00[1] = a->mUnk_02c.mUnk_0c;
        func_020397a8(&b->mUnk_94.mUnk_00[1], &b->mUnk_94.mUnk_00[2], &b->mUnk_94.mUnk_00[0]);
    }
    k = b->mKind;
    if (gItemKinds[k].mUnk_20 != NULL) {
        gItemKinds[k].mUnk_20(a, b);
    }
}

void func_020ef340(Unk020eda5c *a, ItemObject *b, ItemObject *c) {
    func_020efa48(a, c);
}

void func_020ef1cc(Unk020eda5c *p) {
    ItemObject *b;
    Vec3 *q;
    s32 d;
    s32 i;
    Vec3 *u;
    ItemObject **l;

    l = p->mUnk_014;
    b = l[0];
    q = &b->mPos;
    u = &p->mUnk_02c.mUnk_18;
    p->mUnk_090 = *u;
    p->mUnk_09c.x = -p->mUnk_02c.mUnk_18.x;
    p->mUnk_09c.y = -u->y;
    p->mUnk_09c.z = -u->z;
    d = (s32) (((s64) p->mUnk_084.z << 14) >> 12);
    Vec3AddScaled(p->mUnk_078 + d, &p->mUnk_09c, &p->mUnk_050, &p->mUnk_0a8);
    Vec3AddScaled((s32) (((s64) p->mUnk_0e8 * p->mUnk_084.z) >> 12), &p->mUnk_02c.mUnk_0c, &p->mUnk_0a8, q);
    l[1]->mPos = p->mUnk_014[0]->mPos;
    l[2]->mPos = l[1]->mPos;
    p->mUnk_0b4 = p->mUnk_0a8;
    p->mUnk_0c0 = p->mUnk_0b4;
    p->mUnk_0cc[0] = 0xee1;
    p->mUnk_0cc[1] = p->mUnk_0cc[0];
    p->mUnk_0cc[2] = p->mUnk_0cc[1];
    p->mUnk_0d8 = p->mUnk_02c.mUnk_18;
    p->mUnk_16c = 0;
    for (i = 0; i < 0x10; i++) {
        p->mUnk_0ec[0][i] = 0;
        p->mUnk_0ec[1][i] = 0;
    }
    if (p->mUnk_028 == data_021759c0->mEntryIndex) {
        func_020719bc(&p->mUnk_00c->mKart->mUnk_00, 0xe7);
    }
}

void func_020eecdc(Unk020eda5c *a) {
    KartItems *c;
    ItemObject **q;
    s32 n;
    s32 k;
    Vec3 *v;
    s32 s14;
    s32 k70;
    s32 f;
    s32 d;
    s32 e;
    s32 s;
    Vec3 v40;
    Vec3 v4c;
    Vec3 v58;
    Vec3 *w;
    s32 i;
    s32 x;
    Vec3 *t;
    ItemObject *b;
    Unk020eda5c *p;

    p = a;
    c = a->mUnk_00c;
    b = a->mUnk_014[0];
    n = a->mUnk_020;
    v40 = c->mKart->mUnk_1fc;
    q = a->mUnk_014;
    x = a->mUnk_078 + (s32) (((s64) a->mUnk_084.z << 14) >> 12);
    w = &p->mUnk_0a8;
    f = (s32) (((s64) a->mUnk_084.z * 0x3000) >> 12);
    v = &p->mUnk_09c;
    k70 = gItemKinds[b->mKind].mUnk_70;
    func_020ef65c(a, &b->mPos, w);
    if (func_020fa0b8(b, k70, 0x19a) != 0) {
        func_020f9f08(b, a->mUnk_084.x, a->mUnk_084.y);
    }
    if (n > 1) {
        if (a->mUnk_080 != 0) {
            Vec3Sub(&p->mUnk_0d8, &p->mUnk_09c, &v58);
            s = (s32) (((s64) a->mUnk_068 * a->mUnk_068) >> 12);
            v58.x = (s32) (((s64) v58.x * s) >> 12);
            v58.y = (s32) (((s64) v58.y * s) >> 12);
            v58.z = (s32) (((s64) v58.z * s) >> 12);
        }
        p->mUnk_0d8 = p->mUnk_09c;
        k = p->mUnk_16c & 0xf;
        p->mUnk_16c = p->mUnk_16c + 1;
        p->mUnk_0ec[0][k] = p->mUnk_0e4;
        s14 = (s32) (((s64) a->mUnk_068 << 9) >> 12);
        if (s14 > 0x1000) {
            s14 = 0x1000;
        }
    }
    for (i = 1; i < n; i++) {
        b = q[i];
        t = &(&p->mUnk_0a8)[i];
        Vec3Add(t, &v40, t);
        if (a->mUnk_024 != 0) {
            Vec3Add(&q[i - 1]->mVelocity, &b->mVelocity, &b->mVelocity);
        }
        if (a->mUnk_080 != 0) {
            Vec3AddScaled(i * 0x1800, &v58, t, t);
        }
        if (p->mUnk_0cc[i] > 0) {
            Vec3AddScaled(p->mUnk_0cc[i], &a->mUnk_06c, t, t);
        }
        Vec3Sub(t, &a->mUnk_050, &v4c);
        if (i > 1) {
            x -= (i - 1) << 13;
        }
        d = x - func_02039828(&v4c, v);
        if (d > 0) {
            Vec3AddScaled(d, v, t, t);
        }
        d = (s32) (((s64) (w->y - t->y) * 0x666) >> 12);
        if (d < 0) {
            t->y = t->y + d;
        }
        e = p->mUnk_0ec[i - 1][(k - 6) & 0xf];
        if (i == 1) {
            p->mUnk_0ec[1][k] = e;
        }
        d = e - a->mUnk_07c;
        d = (s32) (((s64) d * s14) >> 12);
        Vec3Sub(t, w, &v4c);
        if ((s64) v4c.x * v4c.x + (s64) v4c.y * v4c.y + (s64) v4c.z * v4c.z >= (s64) f * f) {
            if ((s64) v4c.x * v4c.x + (s64) v4c.y * v4c.y + (s64) v4c.z * v4c.z >= 0x10) {
                func_02039860(&v4c, &v4c);
            }
            Vec3AddScaled(f, &v4c, w, t);
            if (p->mUnk_0cc[i] > 0) {
                p->mUnk_0cc[i] -= 0x3d;
            }
        }
        Vec3AddScaled(d + (s32) (((s64) a->mUnk_084.z * 0x4333) >> 12), &a->mUnk_02c.mUnk_0c, t, &b->mPos);
        w = t;
        if (func_020fa0b8(b, k70, 0x19a + i * 0xcd) != 0) {
            func_020f9f08(b, a->mUnk_084.x, a->mUnk_084.y);
        }
    }
    if ((c->mFlags & 0x244) == 0x244 && a->mUnk_000 != 0xf && a->mUnk_024 == 0) {
        func_020efa60(a, 1);
    }
}

void func_020eec48(Unk020eda5c *a, s32 i, ItemObject *v) {
    s32 k;
    ItemObject *e;
    s32 sum;
    s32 b;
    s32 d;

    k = 0;
    sum = 0;
    d = i;
    d = d + 1;
    if (a->mUnk_020 > (b = d)) {
        s32 f = 0;
        d = f;
        do {
            e = a->mUnk_014[a->mUnk_020 - 1];
            func_020efa60(a, 0);
            f = f + 0x4cd;
            if (k++ > 0) {
                Vec3AddScaled(f, &e->mUnk_f0, &e->mVelocity, &e->mVelocity);
            }
        } while (a->mUnk_020 > (b = i + 1));
        f = d + 1;
    }
    func_020efa48(a, v);
}

void func_020eea6c(Unk020eda5c *a) {
    ItemObject **d;
    s32 n;
    s32 c;
    s32 x;
    s32 k;
    s32 m;
    s32 t;
    s32 u;
    s32 i;
    Vec3 *q;
    Vec3 *p1;
    Vec3 *p0;
    Vec3 *p2;
    s32 y;

    i = a->mUnk_174 >> 4;
    n = a->mUnk_020;
    c = a->mUnk_178;
    y = (s32) (((s64) c * gPairsByAngle[i * 2 + 1]) >> 12);
    x = (s32) (((s64) c * gPairsByAngle[i * 2]) >> 12);
    t = -y >> 1;
    u = -x >> 1;
    d = a->mUnk_014;
    p1 = &a->mUnk_02c.mUnk_18;
    p0 = &a->mUnk_02c.mUnk_00;
    p2 = &a->mUnk_180;
    k = (s32) (((s64) y * 0xddb) >> 12);
    m = (s32) (((s64) x * 0xddb) >> 12);
    for (i = 0; i < n; i++) {
        q = &d[i]->mPos;
        if (a->mUnk_18c[i] == 0) {
            Vec3AddScaled(y, p1, p2, q);
            Vec3AddScaled(x, p0, q, q);
        } else if (a->mUnk_18c[i] == 1) {
            Vec3AddScaled(t - m, p1, p2, q);
            Vec3AddScaled(u + k, p0, q, q);
        } else {
            Vec3AddScaled(t + m, p1, p2, q);
            Vec3AddScaled(u - k, p0, q, q);
        }
    }
}

void func_020ee9b0(Unk020eda5c *a) {
    u16 i;

    a->mUnk_174 = 0;
    a->mUnk_176 = 0x258;
    a->mUnk_178 = 0;
    a->mUnk_17c = 0;
    for (i = 0; i < 3; i++) {
        a->mUnk_18c[i] = i;
    }
    Vec3AddScaled((s32) (((s64) a->mUnk_084.z * 0x4333) >> 12), &a->mUnk_02c.mUnk_0c, &a->mUnk_050, &a->mUnk_180);
    func_020eea6c(a);
    if (a->mUnk_028 == (s32) data_021759c0->mEntryIndex) {
        func_020719bc(&a->mUnk_00c->mKart->mUnk_00, 0xe7);
    }
}

void func_020ee748(Unk020eda5c *a) {
    KartItems *c;
    s32 i;
    s32 n;
    s32 e;
    u32 d;
    ItemObject *q;
    enum { K0 } k;

    c = a->mUnk_00c;
    n = a->mUnk_020;
    d = (u16) (((u32) (a->mUnk_068 * 0x1e)) >> 12);
    if (a->mUnk_010->mState != 0) {
        a->mUnk_176 = 0;
    } else {
        if (a->mUnk_176 < 0x578) {
            a->mUnk_176 = a->mUnk_176 + 0x46;
        }
        a->mUnk_174 = a->mUnk_174 + a->mUnk_176;
        if (d >= 0x12c) {
            d = 0x12c;
        }
        a->mUnk_174 = a->mUnk_174 + (s32) d;
    }
    a->mUnk_17c = a->mUnk_17c + (s32) (((s64) a->mUnk_07c * 0x666) >> 12);
    a->mUnk_17c = a->mUnk_17c - (s32) (((s64) a->mUnk_17c * 0x333) >> 12);
    Vec3AddScaled((a->mUnk_17c - a->mUnk_07c) + (s32) (((s64) a->mUnk_084.z * 0x4333) >> 12), &a->mUnk_02c.mUnk_0c,
                  &a->mUnk_050, &a->mUnk_180);
    a->mUnk_178 =
        a->mUnk_178 +
        (s32) (((s64) ((a->mUnk_078 + (s32) (((s64) a->mUnk_084.z * 0x3000) >> 12)) - a->mUnk_178) * 0x333) >> 12);
    func_020eea6c(a);
    i = 0;
    k = a->mUnk_000;
    e = gItemKinds[k].mUnk_70;
    for (; i < n; i++) {
        q = a->mUnk_014[i];
        if (func_020fa0b8(q, e, 0x19a) != 0) {
            func_020f9f08(q, a->mUnk_084.x, a->mUnk_084.y);
        }
    }
    if (a->mUnk_028 == (s32) data_021759c0->mEntryIndex) {
        func_020719a8((u32) c->mKart, n + 0xe0);
    }
    if ((c->mFlags & 0x244) != 0x244) {
        return;
    }
    if (a->mUnk_000 == 0xf) {
        return;
    }
    if (a->mUnk_024 != 0) {
        return;
    }
    func_020efa60(a, 1);
}

void func_020ee6e8(Unk020eda5c *a, s32 i, ItemObject *v) {
    s32 n;
    u16 h;
    ItemObject *t;

    n = a->mUnk_020 - 1;
    if (i != n) {
        t = a->mUnk_014[n];
        h = a->mUnk_18c[n];
        a->mUnk_014[n] = v;
        a->mUnk_18c[n] = a->mUnk_18c[i];
        a->mUnk_014[i] = t;
        a->mUnk_18c[i] = h;
    }
    func_020efa48(a, v);
}

void func_020ee6a8(Unk020eda5c *a) {
    s32 i;

    a->mUnk_000 = 0xf;
    a->mUnk_008 = 5;
    a->mUnk_004 = 0x13;
    for (i = 0; i < 3; i++) {
        a->mUnk_014[i] = NULL;
    }
    a->mUnk_020 = 0;
    a->mUnk_024 = 0;
}

void func_020ee684(Unk020eda5c *a, KartItems *b) {
    a->mUnk_00c = b;
    a->mUnk_010 = b->mKart;
    a->mUnk_028 = b->mKartIndex;
    func_020ee6a8(a);
}
