#include "code_020172d0.h"
#include "code_0201750c.h"

void ListAppend(Unk02017328 *a, void *p) {
    u32 o;

    if (a->mUnk_00 == 0) {
        ListAppendToEmpty((u32) a, (u32) p);
        return;
    }
    o = a->mUnk_0a;
    *(void **) ((u8 *) p + o) = a->mUnk_04;
    *(void **) ((u8 *) p + o + 4) = 0;
    *(void **) ((u8 *) a->mUnk_04 + a->mUnk_0a + 4) = p;
    a->mUnk_04 = p;
    a->mUnk_08++;
}

void ListPrepend(Unk02017328 *a, void *p) {
    u32 o;

    if (a->mUnk_00 == 0) {
        ListAppendToEmpty((u32) a, (u32) p);
        return;
    }
    o = a->mUnk_0a;
    *(void **) ((u8 *) p + o) = 0;
    *(void **) ((u8 *) p + o + 4) = a->mUnk_00;
    *(void **) ((u8 *) a->mUnk_00 + a->mUnk_0a) = p;
    a->mUnk_00 = p;
    a->mUnk_08++;
}

void ListInsertBefore(Unk02017328 *a, void *p, void *q) {
    u32 o;
    u8 *l;
    void *n;

    if (p == 0) {
        ListAppend(a, q);
        return;
    }
    if (p == a->mUnk_00) {
        ListPrepend(a, q);
        return;
    }
    o = a->mUnk_0a;
    l = (u8 *) q + o;
    n = *(void **) ((u8 *) p + o);
    *(void **) l = n;
    *(void **) (l + 4) = p;
    *(void **) ((u8 *) n + o + 4) = q;
    *(void **) ((u8 *) p + a->mUnk_0a) = q;
    a->mUnk_08++;
}

void ListRemove(Unk02017328 *a, void *p) {
    u32 o;
    u8 *l;
    void *x;

    o = a->mUnk_0a;
    x = *(void **) ((u8 *) p + o);
    l = (u8 *) p + o;
    if (x == 0) {
        a->mUnk_00 = *(void **) (l + 4);
    } else {
        *(void **) ((u8 *) x + o + 4) = *(void **) (l + 4);
    }
    x = *(void **) (l + 4);
    if (x == 0) {
        a->mUnk_04 = *(void **) l;
    } else {
        *(void **) ((u8 *) x + a->mUnk_0a) = *(void **) l;
    }
    *(void **) l = 0;
    *(void **) (l + 4) = 0;
    a->mUnk_08--;
}

void *ListGetNext(Unk02017328 *a, void *p) {
    if (p == 0) {
        return a->mUnk_00;
    }
    return *(void **) ((u8 *) p + a->mUnk_0a + 4);
}

void *ListGetPrev(Unk02017328 *a, void *p) {
    if (p == 0) {
        return a->mUnk_04;
    }
    return *(void **) ((u8 *) p + a->mUnk_0a);
}

void *ListGetNth(Unk02017328 *a, s32 b) {
    s32 i;
    void *p;

    i = 0;
    p = ListGetNext(a, 0);
    while (p != 0) {
        if (i == b) {
            return p;
        }
        i++;
        p = ListGetNext(a, p);
    }
    return 0;
}

s32 func_020172d0(s32 a) {
    return a << 4;
}
