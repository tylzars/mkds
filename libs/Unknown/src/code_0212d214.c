#include "code_0212d214.h"

#include "Main/Unknown/unk_0217d000.h"
#include "code_02003be0.h"
#include "code_0212f788.h"
#include "code_02004d80.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0212d968.h"
#include "code_02020eb0.h"
#include "code_0201750c.h"
#include "Main/Unknown/code_02017000.h"
#include "code_020172d0.h"
#include "Main/Unknown/code_02018000.h"
#include "Main/Unknown/code_02021000.h"
#include "code_02017f24.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0212da2c.h"
#include "code_0200eddc.h"
#include "code_0200fc8c.h"
#include "code_020207ec.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_0201ec30.h"
#include "code_020219b0.h"
#include "code_0212df7c.h"
#include "code_020219e8.h"
#include "code_0212bcac.h"
#include "code_0212c7a0.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_020218f4.h"

u8 data_0217dec8[0x3c];

// Calls func_0212c7b8, func_0212c7a0 and func_0212c700 for up to 32 entries of func_0212d38c.
u32 func_0212edac(HeapStack *a) {
    s32 i;
    Unk0212edac *p;
    s32 j;

    func_0212d5d0();
    for (i = 0; i < 32; i++) {
        p = func_0212d38c(i);
        if (p == 0) {
            continue;
        }
        func_0212c7b8(i, p->mUnk_00);
        func_0212c7a0(i, p->mUnk_02);
        if (p->mUnk_04 == 0 || a == 0) {
            continue;
        }
        for (j = 0; j < p->mUnk_00; j++) {
            if (func_0212c700(i, a, p->mUnk_04) == 0) {
                return 0;
            }
        }
    }
    return 1;
}

// Reads the entry func_0212d51c returns for b, then passes its fields on to func_0212eaf8.
s32 func_0212ed58(void *a, s32 b) {
    Unk0212ea28 *p;

    p = func_0212d51c(b);
    if (p == 0) {
        return 0;
    }
    return func_0212eaf8(a, p->mUnk_09, p->mUnk_04, p->mUnk_08, p, b);
}

s32 func_0212ecc0(const void *a, u32 b, u32 c) {
    Unk0212f788 *t;
    Unk0212ea28 *r;
    u32 *p;

    p = func_0212d4b8(b);
    if (p == 0) {
        return 0;
    }
    t = func_0212d254(*p);
    if (t == 0) {
        return 0;
    }
    r = (Unk0212ea28 *) func_0212f788(t, c);
    if (r == 0) {
        return 0;
    }
    return func_0212ea28((Unk0212c400 **) a, r->mUnk_09, r->mUnk_04, r->mUnk_08, r, t, b, c);
}

s32 func_0212ec04(Unk0212c400 **a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    Unk0212f788 *t;
    Unk0212ea28 *r;
    u32 *p;

    p = func_0212d4b8(e);
    if (p == 0) {
        return 0;
    }
    t = func_0212d254(*p);
    if (t == 0) {
        return 0;
    }
    r = (Unk0212ea28 *) func_0212f788(t, f);
    if (r == 0) {
        return 0;
    }
    if (d < 0) {
        d = r->mUnk_08;
    }
    if (c < 0) {
        c = r->mUnk_04;
    }
    if (b < 0) {
        b = r->mUnk_09;
    }
    return func_0212ea28(a, b, c, d, r, t, e, f);
}

s32 func_0212eaf8(Unk0212c400 **a, s32 b, s32 c, s32 d, Unk0212ea28 *e, u32 f) {
    void *p;
    Unk0212f788 *x;
    Unk02021968 *y;
    HeapStack *l;

    p = func_0212c0e0(a, b, d);
    if (p == 0) {
        return 0;
    }
    l = func_0212bfbc(b, p);
    if (func_0212e538(c, 6, l, 0, &y) != 0) {
        func_0212c0d4(p);
        return 0;
    }
    if (func_0212e708(f, 1, l, 0, &x) != 0) {
        func_0212c0d4(p);
        return 0;
    }
    func_0212c078(p, (u8 *) x + x->mUnk_18, 0, y);
    func_0212c668(a, e->mUnk_06);
    func_0212c5c4(a, e->mUnk_07);
    func_0212c478(a, f);
    return 1;
}

s32 func_0212ea28(Unk0212c400 **a, s32 b, s32 c, s32 d, Unk0212ea28 *e, Unk0212f788 *f, u32 g, u32 h) {
    void *p;
    Unk02021968 *x;
    HeapStack *l;

    p = func_0212c0e0(a, b, d);
    if (p == 0) {
        return 0;
    }
    l = func_0212bfbc(b, p);
    if (func_0212e538(c, 6, l, 0, &x) != 0) {
        func_0212c0d4(p);
        return 0;
    }
    func_0212c078(p, (u8 *) f + f->mUnk_18, e->mUnk_00, x);
    func_0212c668(a, e->mUnk_06);
    func_0212c5c4(a, e->mUnk_07);
    func_0212c450(a, g, h);
    return 1;
}

u32 func_0212ea04(s32 a, HeapStack *b) {
    return func_0212e7b4(a, b) == 0;
}

u32 func_0212e9cc(s32 a, HeapStack *b) {
    return func_0212e708(a, 0xff, b, 1, 0) == 0;
}

u32 func_0212e994(s32 a, HeapStack *b) {
    return func_0212e698(a, 0xff, b, 1, 0) == 0;
}

u32 func_0212e95c(s32 a, HeapStack *b) {
    return func_0212e538(a, 0xff, b, 1, 0) == 0;
}

u32 func_0212e924(s32 a, HeapStack *b) {
    return func_0212e490(a, 0xff, b, 1, 0) == 0;
}

u32 func_0212e8f4(s32 a, u32 b, HeapStack *c) {
    return func_0212e538(a, b, c, 1, 0) == 0;
}

u32 func_0212e7b4(s32 a, HeapStack *b) {
    u32 *t;
    u32 i;
    Unk0212e7b4 *e;
    u32 r;

    t = func_0212d328(a);
    if (t == 0) {
        return 1;
    }
    for (i = 0; i < *t; i++) {
        e = (Unk0212e7b4 *) (t + 1) + i;
        switch (e->mUnk_00) {
            case 0:
                r = func_0212e708(e->mUnk_04, e->mUnk_01, b, 1, 0);
                if (r != 0) {
                    return r;
                }
                break;
            case 3:
                r = func_0212e698(e->mUnk_04, e->mUnk_01, b, 1, 0);
                if (r != 0) {
                    return r;
                }
                break;
            case 1:
                r = func_0212e538(e->mUnk_04, e->mUnk_01, b, 1, 0);
                if (r != 0) {
                    return r;
                }
                break;
            case 2:
                r = func_0212e490(e->mUnk_04, e->mUnk_01, b, 1, 0);
                if (r != 0) {
                    return r;
                }
                break;
        }
    }
    return 0;
}

u32 func_0212e708(s32 a, u32 b, HeapStack *c, u32 d, Unk0212f788 **out) {
    Unk0212ea28 *p;
    void *v;
    u32 r;

    p = func_0212d51c(a);
    if (p == 0) {
        return 2;
    }
    r = func_0212e538(p->mUnk_04, b, c, d, 0);
    if (r != 0) {
        return r;
    }
    if (b & 1) {
        v = func_0212e360(p->mUnk_00, c, d);
        if (v == 0) {
            return 6;
        }
    } else {
        v = func_0212d254(p->mUnk_00);
    }
    if (out != 0) {
        *out = v;
    }
    return 0;
}

u32 func_0212e698(s32 a, u32 b, HeapStack *c, u32 d, Unk0212f788 **out) {
    u32 *p;
    void *v;

    p = func_0212d4b8(a);
    if (p == 0) {
        return 3;
    }
    if (b & 8) {
        v = func_0212e2e4(*p, c, d);
        if (v == 0) {
            return 7;
        }
    } else {
        v = func_0212d254(*p);
    }
    if (out != 0) {
        *out = v;
    }
    return 0;
}

u32 func_0212e538(s32 a, u32 b, HeapStack *c, u32 d, Unk02021968 **out) {
    Unk0212e538 *p;
    Unk0212e490 *q;
    Unk02021968 *tmp;
    void *v;
    s32 i;
    u32 f;
    u32 r;

    p = func_0212d454(a);
    if (p == 0) {
        return 4;
    }
    if (b & 2) {
        v = func_0212e268(p->mUnk_00, c, d);
        if (v == 0) {
            return 8;
        }
    } else {
        v = func_0212d254(p->mUnk_00);
    }
    f = b & 4;
    for (i = 0; i < 4; i++) {
        if (p->mUnk_04[i] != 0xffff) {
            q = func_0212d3f0(p->mUnk_04[i]);
            if (q == 0) {
                return 5;
            }
            r = func_0212e490(p->mUnk_04[i], b, c, d, &tmp);
            if (r != 0) {
                return r;
            }
            if ((q->mUnk_03 & 1) && f) {
                if (func_0212dd64(tmp, v, i, q->mUnk_00, c) == 0) {
                    return 9;
                }
            }
            if (v != 0 && tmp != 0) {
                func_02021cd4(v, i, tmp);
            }
        }
    }
    if (out != 0) {
        *out = v;
    }
    return 0;
}

u32 func_0212e490(s32 a, u32 b, HeapStack *c, u32 d, Unk02021968 **out) {
    Unk0212e490 *p;
    Unk02021968 *v;

    p = func_0212d3f0(a);
    if (p == 0) {
        return 5;
    }
    if (b & 4) {
        if (p->mUnk_03 & 1) {
            v = func_0212e0b8(p->mUnk_00, c, d);
        } else {
            v = func_0212e1ec(p->mUnk_00, c, d);
        }
        if (v == 0) {
            return 9;
        }
    } else {
        v = func_0212d254(p->mUnk_00);
    }
    if (out != 0) {
        *out = v;
    }
    return 0;
}

void *func_0212e3dc(u32 a, UnkFunc *f, void *p, u32 d, HeapStack *e) {
    u32 size;
    u8 *b;

    size = func_0212d300(a);
    if (size == 0) {
        return 0;
    }
    if (e == 0) {
        return 0;
    }
    b = HeapStackAlloc(e, size + 0x20, f, p, d);
    if (b == 0) {
        return 0;
    }
    if (func_0212d27c(a, b, size, 0) != size) {
        return 0;
    }
    func_0200ee58(b, size);
    return b;
}

void *func_0212e360(u32 a, HeapStack *b, u32 c) {
    void *p;

    p = func_0212d254(a);
    if (p == 0) {
        p = func_0212e3dc(a, func_0212e018, c ? func_0212d5d0() : 0, a, b);
        if (c != 0 && p != 0) {
            func_0212d238(a, p);
        }
    }
    return p;
}

void *func_0212e2e4(u32 a, HeapStack *b, u32 c) {
    void *p;

    p = func_0212d254(a);
    if (p == 0) {
        p = func_0212e3dc(a, func_0212e018, c ? func_0212d5d0() : 0, a, b);
        if (c != 0 && p != 0) {
            func_0212d238(a, p);
        }
    }
    return p;
}

void *func_0212e268(u32 a, HeapStack *b, u32 c) {
    void *p;

    p = func_0212d254(a);
    if (p == 0) {
        p = func_0212e3dc(a, func_0212dfdc, c ? func_0212d5d0() : 0, a, b);
        if (c != 0 && p != 0) {
            func_0212d238(a, p);
        }
    }
    return p;
}

Unk02021968 *func_0212e1ec(u32 a, HeapStack *b, u32 c) {
    Unk02021968 *p;

    p = func_0212d254(a);
    if (p == 0) {
        p = func_0212e3dc(a, func_0212dfa0, c ? func_0212d5d0() : 0, a, b);
        if (c != 0 && p != 0) {
            func_0212d238(a, p);
        }
    }
    return p;
}

Unk02021968 *func_0212e0b8(u32 a, HeapStack *b, u32 c) {
    Unk02021968 *p;
    u32 size;
    u32 n;
    s32 m;

    p = func_0212d254(a);
    if (p == 0) {
        if (func_0212d27c(a, data_0217dec8, 0x3c, 0) != 0x3c) {
            return 0;
        }
        n = ((Unk02021968 *) data_0217dec8)->mUnk_38 * 4;
        size = n * 2 + 0x3c;
        if (b == 0) {
            return 0;
        }
        p = HeapStackAlloc(b, size + 0x20, func_0212df7c, c ? func_0212d5d0() : 0, a);
        if (p == 0) {
            return 0;
        }
        m = func_0212d27c(a, p, n + 0x3c, 0);
        if (m != n + 0x3c) {
            return 0;
        }
        MemCopy(p->mUnk_3c, p->mUnk_3c + p->mUnk_38, n);
        MemFill(p->mUnk_3c, 0, n);
        func_0200ee58(p, size);
        if (c != 0) {
            func_0212d238(a, p);
        }
    }
    return p;
}

void func_0212e04c(void *a, Unk0212d5f8 *b, u32 c) {
    Unk0212d5f8 *p;
    u32 v;

    if (b == 0) {
        return;
    }
    v = IrqDisable();
    p = func_0212d5e0(b);
    if (a == func_0212d254(c)) {
        func_0212d238(c, 0);
    }
    func_0212d5e0(p);
    IrqRestore(v);
}

void func_0212e018(u8 *a, u32 b, Unk0212d5f8 *c, u32 d) {
    func_0212e04c(a, c, d);
    func_020209e8(a, a + b);
}

void func_0212dfdc(u8 *a, u32 b, Unk0212d5f8 *c, u32 d) {
    func_0212e04c(a, c, d);
    func_020209bc(a, a + b);
    func_02021c34((Unk02021968 *) a);
}

void func_0212dfa0(u8 *a, u32 b, Unk0212d5f8 *c, u32 d) {
    func_0212e04c(a, c, d);
    func_02020990(a, a + b);
    func_02021be8((Unk02021968 *) a);
}

void func_0212df7c(u8 *a, u32 b, Unk0212d5f8 *c, u32 d) {
    func_0212e04c(a, c, d);
    func_02021be8((Unk02021968 *) a);
}

void func_0212df28(void *buf, u32 size, void *p, u32 idx) {
    u8 *q = buf;

    if (q == func_02021968(p, idx)) {
        func_020219b0(p, idx, 0);
    }
    func_02020990(q, q + size);
}

u32 func_0212de34(Unk02021968 *a, u32 b, u32 c, HeapStack *d) {
    u32 *e;
    u32 n;
    u32 end;
    u32 size;
    u32 start;
    void *buf;

    if (func_02021968(a, b) != 0) {
        return 1;
    }
    n = func_020219e8(a);
    e = (u32 *) a + (a->mUnk_38 + b);
    start = e[15];
    end = b < n - 1 ? e[16] : a->mUnk_08;
    size = end - start;
    if (d == 0) {
        return 0;
    }
    buf = HeapStackAlloc(d, size + 32, func_0212df28, a, b);
    if (buf == 0) {
        return 0;
    }
    if (func_0212d27c(c, buf, size, start) != size) {
        return 0;
    }
    func_0200ee58(buf, size);
    func_020219b0(a, b, buf);
    return 1;
}

u32 func_0212dd64(Unk02021968 *a, Unk02021968 *b, u32 c, u32 d, HeapStack *e) {
    Unk02021bc8 it;
    Unk02021bc8 init;
    Unk020219f0 rec;

    func_02021bc8(&init);
    it = init;
    if (b == 0) {
        return 0;
    }
    if (func_020219f0(b, &rec, &it) != 0) {
        do {
            if (rec.mUnk_00 == 1 && c == rec.mUnk_04) {
                if (func_0212de34(a, rec.mUnk_02, d, e) == 0) {
                    return 0;
                }
            }
        } while (func_020219f0(b, &rec, &it) != 0);
    }
    return 1;
}

HeapStack *HeapStackCreate(void *base, u32 size) {
    HeapStack *a;
    void *p;
    u32 end;
    u32 n;

    end = (u32) base + size;
    a = (HeapStack *) (((u32) base + 3) & ~3);
    if ((u32) a > end) {
        return 0;
    }
    n = end - (u32) a;
    if (n < 16) {
        return 0;
    }
    p = FrmHeapCreate(a + 1, n - 16, 0);
    if (p == 0) {
        return 0;
    }
    if (HeapStackInit(a, p) != 0) {
        return a;
    }
    FrmHeapDestroy(p);
    return 0;
}

void HeapStackDestroy(HeapStack *a) {
    HeapStackReset(a);
    FrmHeapDestroy(a->mHeap);
}

void HeapStackReset(HeapStack *a) {
    LinkedList *e;
    void *node;
    u32 flag = 0;

    for (e = ListGetPrev(&a->mLevels, 0); e != 0; e = ListGetPrev(&a->mLevels, 0)) {
        for (node = ListGetPrev(e, 0); node != 0; node = ListGetPrev(e, node)) {
            Unk0212db7c *n = node;

            if (n->mUnk_0c != 0) {
                n->mUnk_0c(n + 1, n->mUnk_08, n->mUnk_10, n->mUnk_14);
                flag = 1;
            }
        }
        ListRemove(&a->mLevels, e);
    }
    FrmHeapFree(a->mHeap, 3);
    if (flag != 0) {
        func_0212d968();
    }
    HeapStackPushLevel(a);
}

void *HeapStackAlloc(HeapStack *a, u32 size, UnkFunc *f, void *p, u32 v) {
    Unk0212db7c *n;
    LinkedList *e;

    n = FrmHeapAlloc(a->mHeap, ((size + 31) & ~31) + 32, 32);
    if (n == 0) {
        return 0;
    }
    e = ListGetPrev(&a->mLevels, 0);
    n->mUnk_08 = size;
    n->mUnk_0c = f;
    n->mUnk_10 = p;
    n->mUnk_14 = v;
    ListAppend(e, n);
    return n + 1;
}

s32 HeapStackSave(HeapStack *a) {
    if (FrmHeapSaveFrontBack(a->mHeap, a->mLevels.mCount) == 0) {
        return -1;
    }
    if (HeapStackPushLevel(a) != 0) {
        return a->mLevels.mCount - 1;
    }
    FrmHeapRestoreFrontBack(a->mHeap, 0);
    return -1;
}

void HeapStackRestore(HeapStack *a, s32 n) {
    LinkedList *e;
    void *node = 0;
    u32 flag = 0;

    if (n == 0) {
        HeapStackReset(a);
        return;
    }
    if (n < a->mLevels.mCount) {
        do {
            e = ListGetPrev(&a->mLevels, 0);
            for (node = ListGetPrev(e, node); node != 0; node = ListGetPrev(e, node)) {
                Unk0212db7c *p = node;

                if (p->mUnk_0c != 0) {
                    p->mUnk_0c(p + 1, p->mUnk_08, p->mUnk_10, p->mUnk_14);
                    flag = 1;
                }
            }
            ListRemove(&a->mLevels, e);
        } while (n < a->mLevels.mCount);
    }
    FrmHeapRestoreFrontBack(a->mHeap, n);
    if (flag != 0) {
        func_0212d968();
    }
    FrmHeapSaveFrontBack(a->mHeap, a->mLevels.mCount);
    HeapStackPushLevel(a);
}

u32 func_0212da2c(HeapStack *arg0) {
    u32 value0 = (u32) arg0;
    value0 = (u32) * (const u16 *) ((value0) + (12));
    value0 = (value0) - (1u);
    return value0;
}

void func_0212da1c(LinkedList *arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value12;
    value12 = (u32) &ListInit;
    value1 = 0u;
    ListInit((LinkedList *) value0, (u16) value1);
}

u32 HeapStackInit(HeapStack *a, void *p) {
    ListInit(&a->mLevels, 12);
    a->mHeap = p;
    return HeapStackPushLevel(a) != 0;
}

u32 HeapStackPushLevel(HeapStack *a) {
    void *p;

    p = FrmHeapAlloc(a->mHeap, 0x14, 4);
    if (p == 0) {
        return 0;
    }
    func_0212da1c(p);
    ListAppend(&a->mLevels, p);
    return 1;
}

void func_0212d968(void) {
    u32 v;

    v = func_02021114();
    PxiCommandSendPending(1);
    PxiCommandWaitForSequence(v);
}

void func_0212d8e0(Unk0212d5f8 *a, const u8 *path, void *p, u32 flag) {
    a->mUnk_8c = 0;
    a->mUnk_84 = 0;
    a->mUnk_88 = 0;
    if (FS_ConvertPathToFileID(&a->mUnk_7c, path) == 0) {
        return;
    }
    FS_InitFile(&a->mUnk_34);
    if (FS_OpenFileFast(&a->mUnk_34, a->mUnk_7c) == 0) {
        return;
    }
    a->mUnk_30 = 1;
    if (func_0212d6c4(a, p, flag) != 0) {
        data_0217dec4 = a;
    }
}

u32 func_0212d6c4(Unk0212d5f8 *a, void *p, u32 flag) {
    s32 n;

    if (FS_SeekFile(&a->mUnk_34, 0, 0) == 0) {
        return 0;
    }
    if (FS_ReadFile(&a->mUnk_34, a, 0x30) != 0x30) {
        return 0;
    }
    if (p != 0) {
        a->mUnk_8c = HeapStackAlloc(p, a->mUnk_1c, func_0212d22c, a, 0);
        if (a->mUnk_8c == 0) {
            return 0;
        }
        if (FS_SeekFile(&a->mUnk_34, a->mUnk_18, 0) == 0) {
            return 0;
        }
        n = FS_ReadFile(&a->mUnk_34, a->mUnk_8c, a->mUnk_1c);
        if (n != a->mUnk_1c) {
            return 0;
        }
        a->mUnk_84 = HeapStackAlloc(p, a->mUnk_24, func_0212d220, a, 0);
        if (a->mUnk_84 == 0) {
            return 0;
        }
        if (FS_SeekFile(&a->mUnk_34, a->mUnk_20, 0) == 0) {
            return 0;
        }
        n = FS_ReadFile(&a->mUnk_34, a->mUnk_84, a->mUnk_24);
        if (n != a->mUnk_24) {
            return 0;
        }
        if (flag != 0 && a->mUnk_14 != 0) {
            a->mUnk_88 = HeapStackAlloc(p, a->mUnk_14, func_0212d214, a, 0);
            if (a->mUnk_88 == 0) {
                return 0;
            }
            if (FS_SeekFile(&a->mUnk_34, a->mUnk_10, 0) == 0) {
                return 0;
            }
            n = FS_ReadFile(&a->mUnk_34, a->mUnk_88, a->mUnk_14);
            if (n != a->mUnk_14) {
                return 0;
            }
        }
    }
    return 1;
}

void func_0212d5f8(Unk0212d5f8 *a, void *buf) {
    u32 i;

    MemCopyWords(buf, a, 0x30);
    a->mUnk_8c = a->mUnk_18 == 0 ? 0 : (Unk0212d38c *) ((u8 *) buf + a->mUnk_18);
    a->mUnk_84 = a->mUnk_20 == 0 ? 0 : (Unk0212d254 *) ((u8 *) buf + a->mUnk_20);
    a->mUnk_88 = a->mUnk_10 == 0 ? 0 : (u8 *) buf + a->mUnk_10;
    for (i = 0; i < a->mUnk_84->mUnk_08; i++) {
        Unk0212d27c *e = &a->mUnk_84->mUnk_0c[i];

        e->mUnk_08 = e->mUnk_00 == 0 ? 0 : (Unk0212f788 *) ((u8 *) buf + e->mUnk_00);
    }
    a->mUnk_30 = 0;
    data_0217dec4 = a;
}

Unk0212d5f8 *func_0212d5e0(Unk0212d5f8 *a) {
    Unk0212d5f8 *old = data_0217dec4;

    data_0217dec4 = a;
    return old;
}

struct Unk0212d5f8 *func_0212d5d0(void) {
    u32 value0;
    value0 = (u32) &data_0217dec4;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    return (struct Unk0212d5f8 *) value0;
}

Unk0212d580 *func_0212d580(s32 a, s32 b) {
    u32 *p;
    Unk0212f788 *q;
    u32 *r;

    p = func_0212d4b8(a);
    if (p == 0) {
        return 0;
    }
    q = func_0212d254(*p);
    if (q == 0) {
        return 0;
    }
    r = func_0212f788(q, b);
    if (r == 0) {
        return 0;
    }
    return (Unk0212d580 *) (r + 1);
}

void *func_0212d51c(s32 a) {
    Unk0212d5f8 *d = data_0217dec4;
    Unk0212d328 *t;
    u32 off;
    u8 *base;

    off = d->mUnk_8c->mUnk_08[0];
    t = off == 0 ? 0 : (Unk0212d328 *) ((u8 *) d->mUnk_8c + off);
    if (t == 0) {
        return 0;
    }
    if (a < 0) {
        return 0;
    }
    if (a >= t->mUnk_00) {
        return 0;
    }
    off = t->mUnk_04[a];
    base = (u8 *) d->mUnk_8c;
    return off == 0 ? 0 : base + off;
}

u32 *func_0212d4b8(s32 a) {
    Unk0212d5f8 *d = data_0217dec4;
    Unk0212d328 *t;
    u32 off;
    u8 *base;

    off = d->mUnk_8c->mUnk_08[1];
    t = off == 0 ? 0 : (Unk0212d328 *) ((u8 *) d->mUnk_8c + off);
    if (t == 0) {
        return 0;
    }
    if (a < 0) {
        return 0;
    }
    if (a >= t->mUnk_00) {
        return 0;
    }
    off = t->mUnk_04[a];
    base = (u8 *) d->mUnk_8c;
    return off == 0 ? 0 : (u32 *) (base + off);
}

void *func_0212d454(s32 a) {
    Unk0212d5f8 *d = data_0217dec4;
    Unk0212d328 *t;
    u32 off;
    u8 *base;

    off = d->mUnk_8c->mUnk_08[2];
    t = off == 0 ? 0 : (Unk0212d328 *) ((u8 *) d->mUnk_8c + off);
    if (t == 0) {
        return 0;
    }
    if (a < 0) {
        return 0;
    }
    if (a >= t->mUnk_00) {
        return 0;
    }
    off = t->mUnk_04[a];
    base = (u8 *) d->mUnk_8c;
    return off == 0 ? 0 : base + off;
}

void *func_0212d3f0(s32 a) {
    Unk0212d5f8 *d = data_0217dec4;
    Unk0212d328 *t;
    u32 off;
    u8 *base;

    off = d->mUnk_8c->mUnk_08[3];
    t = off == 0 ? 0 : (Unk0212d328 *) ((u8 *) d->mUnk_8c + off);
    if (t == 0) {
        return 0;
    }
    if (a < 0) {
        return 0;
    }
    if (a >= t->mUnk_00) {
        return 0;
    }
    off = t->mUnk_04[a];
    base = (u8 *) d->mUnk_8c;
    return off == 0 ? 0 : base + off;
}

void *func_0212d38c(s32 a) {
    Unk0212d5f8 *d = data_0217dec4;
    Unk0212d328 *t;
    u32 off;
    u8 *base;

    off = d->mUnk_8c->mUnk_08[4];
    t = off == 0 ? 0 : (Unk0212d328 *) ((u8 *) d->mUnk_8c + off);
    if (t == 0) {
        return 0;
    }
    if (a < 0) {
        return 0;
    }
    if (a >= t->mUnk_00) {
        return 0;
    }
    off = t->mUnk_04[a];
    base = (u8 *) d->mUnk_8c;
    return off == 0 ? 0 : base + off;
}

void *func_0212d328(s32 a) {
    Unk0212d5f8 *d = data_0217dec4;
    Unk0212d328 *t;
    u32 off;
    u8 *base;

    off = d->mUnk_8c->mUnk_08[5];
    t = off == 0 ? 0 : (Unk0212d328 *) ((u8 *) d->mUnk_8c + off);
    if (t == 0) {
        return 0;
    }
    if (a < 0) {
        return 0;
    }
    if (a >= t->mUnk_00) {
        return 0;
    }
    off = t->mUnk_04[a];
    base = (u8 *) d->mUnk_8c;
    return off == 0 ? 0 : base + off;
}

u32 func_0212d300(u32 a) {
    Unk0212d254 *t = data_0217dec4->mUnk_84;

    if (a >= t->mUnk_08) {
        return 0;
    }
    return t->mUnk_0c[a].mUnk_04;
}

s32 func_0212d27c(u32 a, void *dst, u32 n, u32 off) {
    Unk0212d5f8 *d = data_0217dec4;
    Unk0212d254 *t;
    Unk0212d27c *e;
    u32 left;

    t = d->mUnk_84;
    if (a >= t->mUnk_08) {
        return -1;
    }
    e = &t->mUnk_0c[a];
    left = e->mUnk_04 - off;
    if (n > left) {
        n = left;
    }
    if (FS_SeekFile(&d->mUnk_34, e->mUnk_00 + off, 0) == 0) {
        return -1;
    }
    return FS_ReadFile(&d->mUnk_34, dst, n);
}

void *func_0212d254(u32 a) {
    Unk0212d254 *t = data_0217dec4->mUnk_84;

    if (a >= t->mUnk_08) {
        return 0;
    }
    return t->mUnk_0c[a].mUnk_08;
}

u32 func_0212d238(u32 arg0, void *arg1) {
    u32 value0 = arg0;
    u32 value1 = (u32) arg1;
    u32 value2;
    value2 = (u32) &data_0217dec4;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value2 = (u32) * (const u32 *) ((value2) + (132));
    value0 = (value2) + ((value0 << 4));
    *(u32 *) ((value0) + (20)) = value1;
    return value0;
}

void func_0212d22c(void *arg0, u32 arg1, Unk0212d5f8 *arg2, u32 arg3) {
    u32 value0;
    u32 value2 = (u32) arg2;
    value0 = 0u;
    *(u32 *) ((value2) + (140)) = value0;
}

void func_0212d220(void *arg0, u32 arg1, Unk0212d5f8 *arg2, u32 arg3) {
    u32 value0;
    u32 value2 = (u32) arg2;
    value0 = 0u;
    *(u32 *) ((value2) + (132)) = value0;
}

void func_0212d214(void *arg0, u32 arg1, Unk0212d5f8 *arg2, u32 arg3) {
    u32 value0;
    u32 value2 = (u32) arg2;
    value0 = 0u;
    *(u32 *) ((value2) + (136)) = value0;
}
