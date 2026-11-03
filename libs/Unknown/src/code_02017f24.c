#include "code_02017f24.h"
#include "code_02134420.h"
#include "Main/Unknown/code_0214d000.h"
#include "00/code_02188720.h"

Unk02017f24 *func_02018270(Unk02017f24 *a, u32 b, u16 c) {
    Unk02018174 *p;

    p = &a->mUnk_24;
    func_02017584(&a->mUnk_00, 0x46524d48, (u32) (p + 1), b, c);
    a->mUnk_24.mUnk_00 = a->mUnk_00.mUnk_18;
    p->mUnk_04 = a->mUnk_00.mUnk_1c;
    p->mUnk_08 = 0;
    return a;
}

void *func_020181f0(Unk02018174 *a, u32 b, u32 c) {
    u32 m;
    u32 s;
    u32 e;
    u32 lo;
    u32 n;

    lo = a->mUnk_00;
    m = c - 1;
    s = (m + lo) & ~m;
    e = b + s;
    if (e > a->mUnk_04) {
        return 0;
    }
    n = e - lo;
    {
        volatile u32 z;

        if ((u16) (*(u32 *) ((u8 *) a - 4) & 0xff) & 1) {
            z = 0;
            func_0214d018(z, (void *) lo, n);
        }
    }
    a->mUnk_00 = e;
    return (void *) s;
}

u32 func_02018174(Unk02018174 *a, u32 b, u32 c) {
    u32 m;
    u32 hi;
    u32 s;
    u32 n;

    hi = a->mUnk_04;
    m = c - 1;
    s = (hi - b) & ~m;
    if (s < a->mUnk_00) {
        return 0;
    }
    n = hi - s;
    {
        volatile u32 z;

        if ((u16) (*(u32 *) ((u8 *) a - 4) & 0xff) & 1) {
            z = 0;
            func_0214d018(z, (void *) s, n);
        }
    }
    a->mUnk_04 = s;
    return s;
}

void func_0201815c(Unk02017f24 *a) {
    Unk02018174 *p;

    p = &a->mUnk_24;
    p->mUnk_00 = a->mUnk_00.mUnk_18;
    p->mUnk_08 = 0;
}

void func_0201812c(Unk02017f24 *a) {
    Unk02017f58 *n;
    Unk02018174 *p;

    p = &a->mUnk_24;
    n = p->mUnk_08;
    if (n != 0) {
        do {
            n->mUnk_08 = a->mUnk_00.mUnk_1c;
            n = n->mUnk_0c;
        } while (n != 0);
    }
    p->mUnk_04 = a->mUnk_00.mUnk_1c;
}

Unk02017f24 *func_020180e0(void *a, u32 b, u16 c) {
    u32 e;

    e = (b + (u32) a) & ~3;
    a = (void *) (((u32) a + 3) & ~3);
    if ((u32) a > e || e - (u32) a < 0x30) {
        return 0;
    }
    return func_02018270(a, e, c);
}

void func_020180d4(Unk02017584 *a) {
    func_02017568(a);
}

void *func_0201808c(Unk02017f24 *a, u32 b, s32 c) {
    Unk02018174 *p;

    p = &a->mUnk_24;
    if (b == 0) {
        b = 1;
    }
    b = (b + 3) & ~3;
    if (c >= 0) {
        return func_020181f0(p, b, c);
    }
    return (void *) func_02018174(p, b, -c);
}

void func_0201804c(Unk02017f24 *a, u32 b) {
    if (b & 1) {
        func_0201815c(a);
    }
    if (b & 2) {
        func_0201812c(a);
    }
}

u32 func_0201800c(Unk02017f24 *a, u32 b) {
    u32 n;
    u32 s;
    u32 t;
    Unk02018174 *p;

    n = func_02134420(b);
    p = &a->mUnk_24;
    t = p->mUnk_04;
    s = ((n - 1) + p->mUnk_00) & ~(n - 1);
    if (s > t) {
        return 0;
    }
    return t - s;
}

u32 func_02017fb4(Unk02017f24 *a, u32 b) {
    u32 lo;
    Unk02017f58 *n;
    Unk02018174 *p;

    p = &a->mUnk_24;
    lo = a->mUnk_24.mUnk_00;
    n = func_020181f0(p, 0x10, 4);
    if (n == 0) {
        return 0;
    }
    n->mUnk_00 = b;
    n->mUnk_04 = lo;
    n->mUnk_08 = p->mUnk_04;
    n->mUnk_0c = p->mUnk_08;
    p->mUnk_08 = n;
    return 1;
}

u32 func_02017f58(Unk02017f24 *a, u32 b) {
    Unk02017f58 *n;
    Unk02018174 *p;

    p = &a->mUnk_24;
    n = p->mUnk_08;
    if (b != 0 && n != 0) {
        do {
            if (n->mUnk_00 == b) {
                break;
            }
            n = n->mUnk_0c;
        } while (n != 0);
    }
    if (n == 0) {
        return 0;
    }
    p->mUnk_00 = n->mUnk_04;
    p->mUnk_04 = n->mUnk_08;
    p->mUnk_08 = n->mUnk_0c;
    return 1;
}

u32 func_02017f24(Unk02017f24 *a) {
    Unk02018174 *p;

    p = &a->mUnk_24;
    if (a->mUnk_00.mUnk_1c - p->mUnk_04 != 0) {
        return 0;
    }
    a->mUnk_00.mUnk_1c = p->mUnk_00;
    p->mUnk_04 = a->mUnk_00.mUnk_1c;
    return a->mUnk_00.mUnk_1c - (u32) a;
}
