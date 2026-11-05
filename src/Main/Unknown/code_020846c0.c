#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020846c0.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0205e090.h"
#include "code_020109ac.h"
#include "code_02010878.h"
#include "code_02010998.h"
#include "code_02013730.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0200fe74.h"
#include "code_020108bc.h"
#include "code_02010804.h"
#include "code_02010c84.h"
#include "code_020172d0.h"

void func_0208526c(Unk0208526c *a, Unk020136f0 *b, Unk020136f0 *c) {
    u32 v1;
    Unk020850c4 *v2;

    v1 = func_02013730((u32) b);
    v2 = func_020136f0(c);
    a->mUnk_0c = NULL;
    a->mUnk_08 = NULL;
    ListAppend(&data_0217aeb0, a);
    a->mUnk_08 = b;
    if (v2 == NULL) {
        return;
    }
    v2->mUnk_10 &= ~1;
    v2->mUnk_20 &= ~1;
    v2->mUnk_08 = 0;
    v2->mUnk_18 = 0;
    v2->mUnk_32 &= ~1;
    v2->mUnk_2c = 0;
    func_020850c4(v2);
    a->mUnk_0c = v2;
    if (((Unk020136f0 *) v1)->mUnk_00 == 0x304c444d) {
        func_02010168((Unk02010168 *) v1, (Unk02010294 *) v2);
    }
}

u32 func_020850c4(Unk020850c4 *a) {
    u32 v1;
    u32 v0;
    u32 v2;
    u32 v3 = 1;
    u32 f0 = 1;
    u32 f1 = 1;
    u32 f2 = 1;

    if ((a->mUnk_10 & 1) != 0 || (a->mUnk_20 & 1) != 0 || (a->mUnk_32 & 1) != 0) {
        v3 = 0;
    } else {
        v0 = func_020109b8((u32) a);
        v1 = func_020109ac((u32) a);
        v2 = func_02010878((u32) a);
        if (v0 != 0) {
            v0 = data_021619ec(v0, 0, 0);
            if (v0 == 0) {
                f0 = 0;
            }
        } else {
            v0 = 0;
        }
        if (v1 != 0) {
            v1 = data_021619ec(v1, 1, 0);
            if (v1 == 0) {
                f1 = 0;
            }
        } else {
            v1 = 0;
        }
        if (v2 != 0) {
            v2 = data_021619f4(v2, a->mUnk_20 & 0x8000, 0);
            if (v2 == 0) {
                f2 = 0;
            }
        } else {
            v2 = 0;
        }
        if (f0 == 0 || f1 == 0 || f2 == 0) {
            data_021619f8((void *) v2);
            data_021619f0((void *) v1);
            data_021619f0((void *) v0);
            return 0;
        }
        func_02010998((u32) a, v0, v1);
        func_02010870((Unk02010804 *) a, v2);
        func_020108bc((Unk020108bc *) a, 1);
        func_02010804((Unk02010804 *) a, 1);
    }
    return v3;
}

void func_02084fb0(Unk02084b2c *a, Unk0201290c *b, u32 c) {
    u32 i;
    Unk0201290c *p;

    if (c != 0 && GetCurrentSceneNumber() == 2) {
        a->mUnk_54 = data_021759c0->mUnk_57;
    } else {
        a->mUnk_54 = 0;
    }
    if (b->mEntryCount == 1 && b->mUnk_19[0] == 1) {
        a->mUnk_58 = 1;
    } else {
        a->mUnk_58 = 0;
    }
    func_02010c84((Unk02010c84 *) a, (u32) b);
    if (a->mUnk_54 != 0) {
        p = a->mUnk_04;
        for (i = 0; i < p->mEntryCount; i++) {
            if (func_020133ac(p, i) == 1) {
                func_020134f8(p, i, 2);
            } else if (func_020133ac(p, i) == 2) {
                func_020134f8(p, i, 1);
            }
        }
    }
}

void func_02084f68(Unk02084b2c *a) {
    u32 i;
    Unk0201290c *p;

    p = a->mUnk_04;
    for (i = 0; i < p->mEntryCount; i++) {
        func_020134f8(p, i, 1);
    }
}

void func_02084f20(Unk02084b2c *a) {
    u32 i;
    Unk0201290c *p;

    p = a->mUnk_04;
    for (i = 0; i < p->mEntryCount; i++) {
        func_020134f8(p, i, 2);
    }
}

void func_02084f10(Unk02084b2c *a, Unk0201290c *b) {
    func_02084fb0(a, b, 1);
}

Unk0201290c *func_02084e28(void *a, Unk020136f0 *b) {
    Unk02084b2c *o = a;

    u32 v1;
    Unk020850c4 *v2;
    u32 v3;

    v1 = func_02013730((u32) b);
    v2 = func_020136f0(b);
    o->mUnk_5c.mUnk_0c = NULL;
    o->mUnk_5c.mUnk_08 = NULL;
    ListAppend(&data_0217aeb0, &o->mUnk_5c);
    o->mUnk_5c.mUnk_08 = b;
    if (v2 != NULL) {
        v2->mUnk_10 &= ~1;
        v2->mUnk_20 &= ~1;
        v2->mUnk_08 = 0;
        v2->mUnk_18 = 0;
        v2->mUnk_32 &= ~1;
        v2->mUnk_2c = 0;
        func_020850c4(v2);
        o->mUnk_5c.mUnk_0c = v2;
        if (((Unk020136f0 *) v1)->mUnk_00 == 0x304c444d) {
            func_02010168((Unk02010168 *) v1, (Unk02010294 *) v2);
        }
    }
    v3 = func_02013730((u32) b);
    func_02084fb0(o, (Unk0201290c *) (v3 + *(u32 *) (v3 + *(u16 *) (v3 + 14) + 12)), 1);
    return o->mUnk_04;
}

Unk0201290c *func_02084d3c(void *a, Unk020136f0 *b, Unk020136f0 *c) {
    Unk02084b2c *o = a;

    u32 v1;
    Unk020850c4 *v2;
    u32 v3;

    v1 = func_02013730((u32) b);
    v2 = func_020136f0(c);
    o->mUnk_5c.mUnk_0c = NULL;
    o->mUnk_5c.mUnk_08 = NULL;
    ListAppend(&data_0217aeb0, &o->mUnk_5c);
    o->mUnk_5c.mUnk_08 = b;
    if (v2 != NULL) {
        v2->mUnk_10 &= ~1;
        v2->mUnk_20 &= ~1;
        v2->mUnk_08 = 0;
        v2->mUnk_18 = 0;
        v2->mUnk_32 &= ~1;
        v2->mUnk_2c = 0;
        func_020850c4(v2);
        o->mUnk_5c.mUnk_0c = v2;
        if (((Unk020136f0 *) v1)->mUnk_00 == 0x304c444d) {
            func_02010168((Unk02010168 *) v1, (Unk02010294 *) v2);
        }
    }
    v3 = func_02013730((u32) b);
    func_02084fb0(o, (Unk0201290c *) (v3 + *(u32 *) (v3 + *(u16 *) (v3 + 14) + 12)), 1);
    return o->mUnk_04;
}

Unk0201290c *func_02084c54(Unk02084b2c *a, Unk020136f0 *b) {
    u32 v1;
    Unk020850c4 *v2;
    u32 v3;

    v1 = func_02013730((u32) b);
    v2 = func_020136f0(b);
    a->mUnk_5c.mUnk_0c = NULL;
    a->mUnk_5c.mUnk_08 = NULL;
    ListAppend(&data_0217aeb0, &a->mUnk_5c);
    a->mUnk_5c.mUnk_08 = b;
    if (v2 != NULL) {
        v2->mUnk_10 &= ~1;
        v2->mUnk_20 &= ~1;
        v2->mUnk_08 = 0;
        v2->mUnk_18 = 0;
        v2->mUnk_32 &= ~1;
        v2->mUnk_2c = 0;
        func_020850c4(v2);
        a->mUnk_5c.mUnk_0c = v2;
        if (((Unk020136f0 *) v1)->mUnk_00 == 0x304c444d) {
            func_02010168((Unk02010168 *) v1, (Unk02010294 *) v2);
        }
    }
    v3 = func_02013730((u32) b);
    func_02084fb0(a, (Unk0201290c *) (v3 + *(u32 *) (v3 + *(u16 *) (v3 + 14) + 12)), 0);
    return a->mUnk_04;
}

Unk0201290c *func_02084b2c(void *a, Unk02084b2c *b, Unk020136f0 *c, Unk020136f0 *d) {
    u32 v1;
    Unk020850c4 *v2;
    u32 v3;
    Unk020850c4 *m;
    u32 v4;
    Unk0208526c *e;
    Unk0201290c *q;

    v1 = func_02013730((u32) c);
    v2 = func_020136f0(d);
    b->mUnk_5c.mUnk_0c = NULL;
    b->mUnk_5c.mUnk_08 = NULL;
    ListAppend(&data_0217aeb0, &b->mUnk_5c);
    b->mUnk_5c.mUnk_08 = c;
    if (v2 != NULL) {
        v2->mUnk_10 &= ~1;
        v2->mUnk_20 &= ~1;
        v2->mUnk_08 = 0;
        v2->mUnk_18 = 0;
        v2->mUnk_32 &= ~1;
        v2->mUnk_2c = 0;
        func_020850c4(v2);
        b->mUnk_5c.mUnk_0c = v2;
        if (((Unk020136f0 *) v1)->mUnk_00 == 0x304c444d) {
            func_02010168((Unk02010168 *) v1, (Unk02010294 *) v2);
        }
    }
    v3 = func_02013730((u32) c);
    func_02084fb0(b, (Unk0201290c *) (v3 + *(u32 *) (v3 + *(u16 *) (v3 + 14) + 12)), 1);
    e = &b->mUnk_5c;
    m = e->mUnk_0c;
    q = b->mUnk_04;
    if (m != NULL) {
        v4 = m->mUnk_14;
        e->mUnk_0c = HeapAlloc(a, v4);
        MemCopy(m, e->mUnk_0c, v4);
    }
    return q;
}

void func_02084ad8(void *a, u8 b) {
    Unk02084b2c *o = a;

    Unk0201290c *p = o->mUnk_04;
    u32 n;

    if (o->mUnk_54 != 0) {
        n = 2;
    } else {
        n = 1;
    }
    func_020134b0(p, 0, 0);
    func_020134f8(p, 0, n);
    func_02013468(p, 0, b);
}

void func_02084a88(void *a, u8 b, u8 c) {
    Unk02084b2c *o = a;

    Unk0201290c *p = o->mUnk_04;
    u32 n;

    if (o->mUnk_54 != 0) {
        n = 1;
    } else {
        n = 2;
    }
    func_020134b0(p, 0, c);
    func_020134f8(p, 0, n);
    func_02013468(p, 0, b);
}

void func_020849f8(void *a, void *b, u32 *c) {
    s32 v0 = 30;
    u32 v[3];

    func_01ff9048(20, &v0, 1);
    func_01ff9048(25, b, 12);
    if (c != NULL) {
        u32 z = c[2];
        u32 y = c[1];
        u32 x = c[0];
        v[0] = x;
        v[1] = y;
        v[2] = z;
        func_01ff9048(27, &v, 3);
    }
    data_02155a20[((Unk02084b2c *) a)->mUnk_58](a);
}

void func_020849d0(void *a) {
    Unk02084b2c *o = a;

    data_02155a20[o->mUnk_58](o);
}

void func_020849c0(void *a, u32 b) {
    Unk02084b2c *o = a;

    func_020130d4(o->mUnk_04, b);
}

void func_020849b0(void *a, u32 b) {
    Unk02084b2c *o = a;

    func_020131ac(o->mUnk_04, b);
}

void func_020849a0(void *a, u32 b) {
    Unk02084b2c *o = a;

    func_020131f4(o->mUnk_04, b);
}

void func_02084968(void *a, u32 b, u32 c, u32 d) {
    Unk02084b2c *o = a;

    func_020130d4(o->mUnk_04, b);
    func_020131ac(o->mUnk_04, c);
    func_020131f4(o->mUnk_04, d);
}

void func_02084958(void *a, u32 b) {
    Unk02084b2c *o = a;

    func_0201311c(o->mUnk_04, b);
}

void func_020848fc(void) {
    Unk0208526c *p;

    for (p = ListGetNext(&data_0217aeb0, NULL); p != NULL; p = ListGetNext(&data_0217aeb0, p)) {
        if (p->mUnk_08 != NULL) {
            func_02012b30(p->mUnk_08);
        }
    }
}

void func_020846c0(void *a) {
    u32 n;
    u16 i;
    u16 j;

    n = data_021759c0->mKartCount;
    data_0217ae8c = HeapAlloc(a, n * 2);
    data_0217ae7c = HeapAlloc(a, n * 12);
    data_0217ae94 = HeapAlloc(a, n * 4);
    data_0217ae74 = HeapAlloc(a, n * 4);
    for (i = 0; i < n; i++) {
        for (j = 0; j < 3; j++) {
            data_0217ae7c[i].mUnk_00[j] = NULL;
        }
        data_0217ae94[i] = NULL;
        data_0217ae74[i] = NULL;
        if (i == data_021759c0->mEntryIndex) {
            data_0217ae8c[i] = 0;
        } else {
            data_0217ae8c[i] = 1;
        }
    }
    data_0217ae6c = 0x7fff;
    switch (data_021759c0->mCourseId) {
        case 0x12:
        case 0x20:
            data_0217ae6c = 0x1667;
            break;
        case 0x1c:
            data_0217ae6c = 0x2ff;
            break;
        case 0x1a:
            data_0217ae6c = 0x3e67;
            break;
    }
    data_0217ae98 = (data_021759c0->mKartCount - 1) / 2;
    data_0217ae90 = (data_021759c0->mKartCount - 1) % 2;
    data_02165948 = 0x1000;
    switch (data_021759c0->mUnk_010) {
        case 0:
            data_02165948 = 0xb33;
            break;
        case 1:
            data_02165948 = 0xd9a;
            break;
    }
}
