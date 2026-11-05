#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_0210cf20.h"

#include "Main/Unknown/code_0210cf9c.h"
#include "Main/Unknown/code_0210cfe8.h"
#include "Main/Unknown/code_0210d020.h"
#include "Main/Unknown/code_0210d078.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/unk_0216c000.h"
#include "code_0212bcac.h"
#include "Main/Unknown/code_0210d0b4.h"
#include "Main/Unknown/code_0210d120.h"
#include "Main/Unknown/code_0210bafc.h"
#include "code_0212d214.h"
#include "Main/Unknown/code_0210bcf4.h"
#include "Main/Unknown/code_0210c1b0.h"
#include "Main/Unknown/code_0210e000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_020172d0.h"
#include "Main/Unknown/code_0210d4a0.h"
#include "Main/Unknown/code_0210d4a4.h"
#include "Main/Unknown/code_0210e328.h"
#include "Main/Unknown/code_0210bce0.h"
#include "code_0201750c.h"

void func_0210d4a4(Unk0210bf24 *a, s32 b) {
    s32 i;

    func_0210e2c4((Unk0217c7c4 *) data_0217d034, a, b, 0x1c);
    for (i = 0; i < b; i++) {
        func_0210e328(a);
        func_0210bce0(&a->mUnk_08);
        a->mUnk_18 = 0;
        a->mUnk_16 = 0;
        a->mUnk_19 = 0;
        a->mUnk_14 = 0;
        a->mUnk_1a = 0x7f;
        a++;
    }
    ListInit(&data_0217d028, 0);
    for (i = 0; i < 2; i++) {
        ListInit(&data_0217d048[i], 0x1c);
    }
    data_0217d010[0] = 0;
    data_0217d024[0] = 0;
}

u32 func_0210d4a0(u32 p0) {
    return p0;
}

void func_0210d2cc(void) {
    LinkedList *l;
    u32 t;
    Unk0210bf24 *q;
    LinkedList *m;
    Unk0210bfbc *p;

    if (data_0217d084.mUnk_10 == 0) {
        return;
    }
    if (data_0217d020 != 0) {
        for (p = data_0217d028.mHead; p != NULL; p = ListGetNext(&data_0217d028, p)) {
            func_0210cc3c(p);
        }
        data_0217d020 = 0;
    }
    func_0210e280((Unk0217c7c4 *) data_0217d034);
    l = data_0217d048;
    for (p = l->mHead; p != NULL; p = l->mHead) {
        func_0210ca4c(p);
        if (p->mUnk_18 != 3) {
            func_0210bc54(&l[p->mUnk_18], p);
            p->mUnk_18 = 3;
        }
    }
    m = (LinkedList *) data_0217d054;
    p = m->mHead;
    t = data_0217d024[0];
    if (p != NULL) {
        l = data_0217d048;
        do {
            if ((t++ & 3) == data_0217d010[0]) {
                func_0210ca4c(p);
            } else if ((t & 1) == (data_0217d010[0] & 1)) {
                for (q = p->mUnk_0c.mHead; q != NULL; q = ListGetNext(&p->mUnk_0c, q)) {
                    if (q->mUnk_00 != NULL) {
                        p->mUnk_30(p, q, NULL);
                    }
                }
            }
            if (p->mUnk_18 != 3) {
                func_0210bc54(&l[p->mUnk_18], p);
                p->mUnk_18 = 3;
            }
            p = m->mHead;
        } while (p != NULL);
    }
    data_0217d010[0]++;
    if (data_0217d010[0] == 4) {
        data_0217d010[0] = 0;
    }
    data_0217d024[0] = 0;
}

void func_0210d200(u32 a) {
    Unk0210bfbc *p;
    Unk0210bf24 *q;

    p = data_0217d028.mHead;
    if (p == NULL) {
        return;
    }
    do {
        q = p->mUnk_0c.mHead;
        if (q != NULL) {
            do {
                func_0212c6f0(&q->mUnk_00, a);
                q->mUnk_19 &= ~4;
                q->mUnk_19 &= ~8;
                q->mUnk_19 &= ~2;
                func_0210bc54(&p->mUnk_0c, q);
                q = p->mUnk_0c.mHead;
            } while (q != NULL);
        }
        if (p->mUnk_18 != 3) {
            func_0210bc54(&data_0217d048[p->mUnk_18], p);
            p->mUnk_18 = 3;
        }
        p = ListGetNext(&data_0217d028, p);
    } while (p != NULL);
}

void func_0210d1a4(s32 a, s32 b) {
    u8 *p;
    s32 i;

    p = ((Unk0217c7c4 *) data_0217d034)->mUnk_0c;
    for (i = 0; i < ((Unk0217c7c4 *) data_0217d034)->mUnk_00; i++) {
        func_0212c620(&((Unk0210bf24 *) p)->mUnk_00, a, b);
        p += ((Unk0217c7c4 *) data_0217d034)->mUnk_10;
    }
}

void func_0210d120(u32 a) {
    u8 *p;
    s32 i;

    p = ((Unk0217c7c4 *) data_0217d034)->mUnk_0c;
    for (i = 0; i < ((Unk0217c7c4 *) data_0217d034)->mUnk_00; i++) {
        func_0212c6f0(&((Unk0210bf24 *) p)->mUnk_00, a);
        ((Unk0210bf24 *) p)->mUnk_19 &= ~4;
        ((Unk0210bf24 *) p)->mUnk_19 &= ~8;
        ((Unk0210bf24 *) p)->mUnk_19 &= ~2;
        p += ((Unk0217c7c4 *) data_0217d034)->mUnk_10;
    }
}

void func_0210d0ec(void) {
    while (data_0217d028.mHead != NULL) {
        func_0210c3a8(data_0217d028.mHead);
    }
}

void func_0210d0b4(u32 a, Unk0210bf24 *b, u32 c) {
    func_0212ec04(&b->mUnk_00, -1, -1, c, b->mUnk_18, b->mUnk_16);
}

void func_0210d078(u32 a, Unk0210bf24 *b) {
    func_0212c554(&b->mUnk_00, data_0216cb20, b->mUnk_1a);
    func_0212c524(&b->mUnk_00, data_0216cb20, b->mUnk_14);
}

void func_0210d050(u32 a, u32 b, u32 c, u32 d) {
    func_0212ec04((Unk0212c400 **) a, (u32) 0xffffffff, (u32) 0xffffffff, d, b, c);
}

void func_0210d040(s32 (*p0)(Unk0210bcf4 *)) {
    data_0217d01c = p0;
}

void func_0210d030(u32 (*p0)(Unk0210bcf4 *)) {
    data_0217d018 = p0;
}

void func_0210d020(s32 (*p0)(Unk0210bcf4 *)) {
    data_0217d014 = p0;
}

void func_0210cfe8(u32 arg0) {
    u32 value0 = arg0;
    u32 value4;
    value4 = value0;
    func_0210e328((Unk0210bf24 *) value0);
    value0 = (value4) + (8u);
    func_0210bce0((void *) value0);
    value0 = 0u;
    *(u8 *) ((value4) + (24)) = (u8) value0;
    *(u16 *) ((value4) + (22)) = (u16) value0;
    *(u8 *) ((value4) + (25)) = (u8) value0;
    *(u16 *) ((value4) + (20)) = (u16) value0;
    value0 = 0x7fu;
    *(u8 *) ((value4) + (26)) = (u8) value0;
}

void func_0210cfbc(Unk0210bfbc *p, s32 b, s32 c) {
    if (c == 1) {
        p->mUnk_34 |= 1 << b;
    } else {
        p->mUnk_34 &= ~(1 << b);
    }
}

void func_0210cf9c(Unk0210bfbc *p, s32 b) {
    if (b == 1) {
        p->mUnk_34 |= 1;
    } else {
        p->mUnk_34 &= ~1;
    }
}

void func_0210cf20(int a, u32 b) {
    u32 v1;
    u32 v2;
    ListInit((LinkedList *) ((u32 *) (u32) (a + 0xc)), (u16) 8);
    v1 = ((u32) (&func_0210d0b4));
    *(u32 *) (a + 0x38) = 1;
    v2 = ((u32) (&func_0210d078));
    *(u32 *) (a + 0x2c) = v1;
    *(u32 *) (a + 0x30) = v2;
    *(u16 *) (a + 0x34) = 0;
    *(u32 *) (a + 0x28) = b;
    *(u32 *) (a + 0x18) = 3;
    func_0210bce0((u32 *) (u32) (a + 0x1c));
    func_0210bce0((u32 *) (u32) a);
    func_0210bc8c((((u32) (&data_0217d028))), a);
}
