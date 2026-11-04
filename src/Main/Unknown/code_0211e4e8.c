#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020ae428.h"
#include "Main/Unknown/code_020d0e3c.h"
#include "Main/Unknown/code_020d0efc.h"
#include "Main/Unknown/code_0211e4e8.h"
#include "registers.h"

#include "Main/Unknown/code_0211f394.h"
#include "Main/Unknown/code_0211f4b0.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/unk_0216d000.h"
#include "Main/Unknown/unk_0216e000.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_0211d000.h"
#include "Main/Unknown/code_0211f000.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_020d0000.h"
#include "Main/Unknown/code_0211de34.h"
#include "Main/Unknown/code_0211de40.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_0211de00.h"
#include "Main/Unknown/code_0211f380.h"
#include "Main/Unknown/code_0211f498.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_0212426c.h"
#include "code_02148950.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_02016468.h"

#pragma thumb on

void func_0211efec(void) {
    Ncgr *a;
    Nclr *b;
    Ncgr *c;
    Nclr *d;
    Ncgr *e;
    Nscr *f;
    Nclr *g;
    Ncgr *h;
    Nscr *i;
    Nclr *j;
    u16 *v;

    a = NULL;
    b = NULL;
    c = NULL;
    d = NULL;
    e = NULL;
    f = NULL;
    g = NULL;
    h = NULL;
    i = NULL;
    j = NULL;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        return;
    }
    LocateNcgr(&e, FindSceneFile(data_0216dfb0));
    LocateNclr(&g, FindSceneFile(data_0216dfac));
    LocateNscr(&f, FindSceneFile(data_0216df98));
    LocateNcgr(&h, FindSceneFile(data_0216dfb0));
    LocateNclr(&j, FindSceneFile(data_0216dfac));
    LocateNscr(&i, FindSceneFile(data_0216df98));
    data_0217d378->mUnk_20 = HeapAlloc(data_0217d378->mHeap, 0x800);
    data_0217d378->mUnk_04 = FindSceneFile(data_0216df94);
    data_0217d378->mUnk_08 = FindSceneFile(data_0216dfa4);
    LocateNcgr2(&a, FindSceneFile(data_0216df9c));
    LocateNcer(&data_0217d378->mUnk_00, FindSceneFile(data_0216dfa0));
    LocateNclr(&b, FindSceneFile(data_0216dfa8));
    data_0217d378->mUnk_10 = FindSceneFile(data_0216df94);
    data_0217d378->mUnk_14 = FindSceneFile(data_0216dfa4);
    LocateNcgr2(&c, FindSceneFile(data_0216df9c));
    LocateNcer(&data_0217d378->mUnk_0c, FindSceneFile(data_0216dfa0));
    LocateNclr(&d, FindSceneFile(data_0216dfa8));
    v = b->mData;
    if (!(func_020cccb4() == 0x17 || func_020cccb4() == 0xb)) {
        func_02016468(4, 0, e->mData, e->mDataSize);
        func_02016468(0xf, 0, g->mData, 0x140);
        func_02016468(8, 0, f->mData, f->mDataSize);
        func_02016468(8, 0x800, data_0217d378->mUnk_20, 0x800);
    }
    if (!(func_020cccb4() == 0x19 || func_020cccb4() == 0xd)) {
        func_02016468(0x17, 0, h->mData, h->mDataSize);
        func_02016468(0x1f, 0, j->mData, 0x140);
        func_02016468(0x1b, 0, i->mData, i->mDataSize);
        func_02016468(0x1b, 0x800, data_0217d378->mUnk_20, 0x800);
    }
    func_02016468(0x13, 0, a->mData, a->mDataSize);
    func_02016468(0xe, 0, b->mData, 0x1a0);
    func_02016468(0xe, 0x1c0, v + 0xe0, 0x40);
    func_02016468(0x23, 0, c->mData, c->mDataSize);
    func_02016468(0x1e, 0, d->mData, d->mDataSize);
}

void func_0211ed80(void) {
    s32 i;
    u16 c;
    u16 d;
    s32 j;
    BOOL n;
    BOOL v;
    s32 m;
    s32 a;

    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        return;
    }
    c = data_0217d378->mUnk_04->mUnk_06;
    d = data_0217d378->mUnk_10->mUnk_06;
    v = FALSE;
    for (i = 0; i < 8; i++) {
        data_0217d378->mUnk_18[data_0215cf1c[i]].mUnk_00 = v;
        data_0217d378->mUnk_1c[data_0215cf1c[i]].mUnk_00 = v;
    }
    for (i = 0; i < 4; i++) {
        data_0217d378->mUnk_18[data_0215cefc[i]].mUnk_00 = 0;
        data_0217d378->mUnk_1c[data_0215cefc[i]].mUnk_00 = 0;
    }
    for (i = 0; i < 4; i++) {
        data_0217d378->mUnk_18[data_0215cf04[i]].mUnk_00 = 0;
        data_0217d378->mUnk_18[c + data_0215cf0c[i]].mUnk_00 = 1;
        data_0217d378->mUnk_1c[data_0215cf04[i]].mUnk_00 = 0;
        data_0217d378->mUnk_1c[d + data_0215cf0c[i]].mUnk_00 = 1;
    }
    data_0217d378->mUnk_18[20].mUnk_00 = 0;
    data_0217d378->mUnk_18[19].mUnk_00 = 1;
    data_0217d378->mUnk_1c[20].mUnk_00 = 0;
    data_0217d378->mUnk_1c[19].mUnk_00 = 1;
    func_0211de00(data_0215cf2c[func_0202968c()], data_0217d378->mUnk_00, data_0217d378->mUnk_04, 0x13, 0);
    func_0211de00(data_0215cf2c[func_0202968c()], data_0217d378->mUnk_0c, data_0217d378->mUnk_10, 0x13, 1);
    n = FALSE;
    for (j = 0; j < 4; j++) {
        func_0212426c(n, data_0215cf0c[j], data_0217d378->mUnk_08,
                      GetBmgEntry(data_0217d378->mUnk_24, data_0215cf4c[data_0215cf2c[func_0202968c()]][j]),
                      data_0217d378->mUnk_04, data_0217d378->mUnk_18);
        func_0212426c(1, data_0215cf0c[j], data_0217d378->mUnk_14,
                      GetBmgEntry(data_0217d378->mUnk_24, data_0215cf4c[data_0215cf2c[func_0202968c()]][j]),
                      data_0217d378->mUnk_10, data_0217d378->mUnk_1c);
    }
    a = data_0215cf04[0];
    data_0217d378->mUnk_18[a].mUnk_00 = 1;
    j = data_0215cf0c[0];
    func_02124100(j, 0xe, data_0217d378->mUnk_08, data_0217d378->mUnk_18, data_0217d378->mUnk_04);
    data_0217d378->mUnk_1c[a].mUnk_00 = 1;
    func_02124100(j, 0xe, data_0217d378->mUnk_14, data_0217d378->mUnk_1c, data_0217d378->mUnk_10);
    for (m = 1; m < 4; m++) {
        data_0217d378->mUnk_18[data_0215cf04[m]].mUnk_00 = 0;
        func_02124100(data_0215cf0c[m], 0xf, data_0217d378->mUnk_08, data_0217d378->mUnk_18, data_0217d378->mUnk_04);
        data_0217d378->mUnk_1c[data_0215cf04[m]].mUnk_00 = 0;
        func_02124100(data_0215cf0c[m], 0xf, data_0217d378->mUnk_14, data_0217d378->mUnk_1c, data_0217d378->mUnk_10);
    }
    func_020d0efc(data_0215cf8c[data_0215cf2c[func_0202968c()]][0]);
    data_0217d378->mUnk_38 = 1;
}

void func_0211ec54(void) {
    s32 i;
    u16 c;
    u16 d;

    data_0217d378->mUnk_30 = 0;
    data_0217d378->mUnk_34 = 0;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        return;
    }
    c = data_0217d378->mUnk_04->mUnk_06;
    d = data_0217d378->mUnk_10->mUnk_06;
    data_0217d378->mUnk_3c = 0;
    data_0217d378->mUnk_18[20].mUnk_06 = 0;
    data_0217d378->mUnk_18[19].mUnk_06 = 0;
    data_0217d378->mUnk_18[2].mUnk_06 = 0;
    data_0217d378->mUnk_18[1].mUnk_06 = 0;
    data_0217d378->mUnk_18[0].mUnk_06 = 0;
    for (i = 0; i < 8; i++) {
        data_0217d378->mUnk_18[data_0215cf1c[i]].mUnk_06 = 0;
    }
    for (i = 0; i < 4; i++) {
        data_0217d378->mUnk_18[data_0215cf04[i]].mUnk_06 = 0;
        data_0217d378->mUnk_18[c + data_0215cf0c[i]].mUnk_06 = 0;
    }
    data_0217d378->mUnk_40 = ~0xbf;
    data_0217d378->mUnk_1c[20].mUnk_06 = ~0xbf;
    data_0217d378->mUnk_1c[19].mUnk_06 = ~0xbf;
    data_0217d378->mUnk_1c[2].mUnk_06 = ~0xbf;
    data_0217d378->mUnk_1c[1].mUnk_06 = ~0xbf;
    data_0217d378->mUnk_1c[0].mUnk_06 = ~0xbf;
    for (i = 0; i < 8; i++) {
        data_0217d378->mUnk_1c[data_0215cf1c[i]].mUnk_06 = ~0xbf;
    }
    for (i = 0; i < 4; i++) {
        data_0217d378->mUnk_1c[data_0215cf04[i]].mUnk_06 = ~0xbf;
        data_0217d378->mUnk_1c[d + data_0215cf0c[i]].mUnk_06 = ~0xbf;
    }
}

void func_0211eb28(void) {
    s32 i;
    u16 c;
    u16 d;

    data_0217d378->mUnk_30 = 1;
    data_0217d378->mUnk_34 = 0;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        return;
    }
    c = data_0217d378->mUnk_04->mUnk_06;
    d = data_0217d378->mUnk_10->mUnk_06;
    data_0217d378->mUnk_3c = 0xc0;
    data_0217d378->mUnk_18[20].mUnk_06 = 0xc0;
    data_0217d378->mUnk_18[19].mUnk_06 = 0xc0;
    data_0217d378->mUnk_18[2].mUnk_06 = 0xc0;
    data_0217d378->mUnk_18[1].mUnk_06 = 0xc0;
    data_0217d378->mUnk_18[0].mUnk_06 = 0xc0;
    for (i = 0; i < 8; i++) {
        data_0217d378->mUnk_18[data_0215cf1c[i]].mUnk_06 = 0xc0;
    }
    for (i = 0; i < 4; i++) {
        data_0217d378->mUnk_18[data_0215cf04[i]].mUnk_06 = 0xc0;
        data_0217d378->mUnk_18[c + data_0215cf0c[i]].mUnk_06 = 0xc0;
    }
    data_0217d378->mUnk_40 = ~0x1f;
    data_0217d378->mUnk_1c[20].mUnk_06 = ~0x1f;
    data_0217d378->mUnk_1c[19].mUnk_06 = ~0x1f;
    data_0217d378->mUnk_1c[2].mUnk_06 = ~0x1f;
    data_0217d378->mUnk_1c[1].mUnk_06 = ~0x1f;
    data_0217d378->mUnk_1c[0].mUnk_06 = ~0x1f;
    for (i = 0; i < 8; i++) {
        data_0217d378->mUnk_1c[data_0215cf1c[i]].mUnk_06 = ~0x1f;
    }
    for (i = 0; i < 4; i++) {
        data_0217d378->mUnk_1c[data_0215cf04[i]].mUnk_06 = ~0x1f;
        data_0217d378->mUnk_1c[d + data_0215cf0c[i]].mUnk_06 = ~0x1f;
    }
}

void func_0211e958(void *a, void *b, void *c) {
    void *p;
    s32 i;
    s32 m;

    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 1;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~3) | 1;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & 0x43) | 0x9004;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x8300;
    p = CreateFrmHeapFromMaxFree(a);
    data_0217d378 = HeapAlloc(p, 0x54);
    data_0217d378->mHeap = p;
    data_0217d378->mUnk_38 = 0;
    data_0217d378->mUnk_48 = b;
    data_0217d378->mUnk_4c = c;
    data_0217d378->mUnk_50 = 0;
    if (func_020cccb4() == 0x19 || func_020cccb4() == 0xd) {
        data_0217d378->mUnk_2c = 1;
    } else {
        data_0217d378->mUnk_2c = 0;
    }
    func_0211efec();
    data_0217d378->mUnk_24 = func_02047a28(data_0216e09c);
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        func_02124ed0(data_0217d378->mHeap, data_0217d378->mUnk_04, data_0217d378->mUnk_08, &data_0217d378->mUnk_18);
        func_02124ed0(data_0217d378->mHeap, data_0217d378->mUnk_10, data_0217d378->mUnk_14, &data_0217d378->mUnk_1c);
        m = 0x8000;
        for (i = 0; i < 4; i++) {
            m -= func_021243ac(data_0217d378->mHeap, data_0215cf0c[i], data_0217d378->mUnk_08, data_0215cef4[i],
                               data_0215cf14[i], data_0215cf04[i], data_0217d378->mUnk_00, data_0217d378->mUnk_04,
                               data_0217d378->mUnk_18, m);
        }
        i = func_02148ca0();
        for (m = 0; m < 4; m++) {
            i -= func_021243ac(data_0217d378->mHeap, data_0215cf0c[m], data_0217d378->mUnk_14, data_0215cef4[m],
                               data_0215cf14[m], data_0215cf04[m], data_0217d378->mUnk_0c, data_0217d378->mUnk_10,
                               data_0217d378->mUnk_1c, i);
        }
        func_0211de40(data_0217d378->mHeap);
    } else {
        func_0211f4b0(data_0217d378->mHeap, data_0217d378->mUnk_4c);
        func_0211f380();
    }
    func_0211ed80();
    if (func_020cccb4() == 0x19 || func_020cccb4() == 0xd) {
        func_0211eb28();
    } else {
        func_0211ec54();
    }
    FrmHeapShrinkInParent(data_0217d378->mHeap);
}

void func_0211e924(void) {
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        func_0211de34();
    } else {
        func_0211f498();
    }
    HeapDestroy(data_0217d378->mHeap);
    data_0217d378 = NULL;
}

void func_0211e7c0(void) {
    s32 i;
    s16 a;
    s16 b;
    u16 c;
    u16 d;

    data_0217d378->mUnk_34++;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        return;
    }
    a = func_020ae4c0(1, 0, 0xc0, data_0217d378->mUnk_34, 0xa);
    b = func_020ae4c0(1, ~0xbf, ~0x1f, data_0217d378->mUnk_34, 0xa);
    c = data_0217d378->mUnk_04->mUnk_06;
    data_0217d378->mUnk_3c = a;
    data_0217d378->mUnk_18[20].mUnk_06 = a;
    data_0217d378->mUnk_18[19].mUnk_06 = a;
    data_0217d378->mUnk_18[2].mUnk_06 = a;
    data_0217d378->mUnk_18[1].mUnk_06 = a;
    data_0217d378->mUnk_18[0].mUnk_06 = a;
    for (i = 0; i < 8; i++) {
        data_0217d378->mUnk_18[data_0215cf1c[i]].mUnk_06 = a;
    }
    for (i = 0; i < 4; i++) {
        data_0217d378->mUnk_18[data_0215cf04[i]].mUnk_06 = a;
        data_0217d378->mUnk_18[c + data_0215cf0c[i]].mUnk_06 = a;
    }
    d = data_0217d378->mUnk_10->mUnk_06;
    data_0217d378->mUnk_40 = b;
    data_0217d378->mUnk_1c[20].mUnk_06 = b;
    data_0217d378->mUnk_1c[19].mUnk_06 = b;
    data_0217d378->mUnk_1c[2].mUnk_06 = b;
    data_0217d378->mUnk_1c[1].mUnk_06 = b;
    data_0217d378->mUnk_1c[0].mUnk_06 = b;
    for (i = 0; i < 8; i++) {
        data_0217d378->mUnk_1c[data_0215cf1c[i]].mUnk_06 = b;
    }
    for (i = 0; i < 4; i++) {
        data_0217d378->mUnk_1c[data_0215cf04[i]].mUnk_06 = b;
        data_0217d378->mUnk_1c[d + data_0215cf0c[i]].mUnk_06 = b;
    }
}

void func_0211e65c(void) {
    s32 i;
    s16 a;
    s16 b;
    u16 c;
    u16 d;

    data_0217d378->mUnk_34++;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        return;
    }
    a = func_020ae4c0(1, 0xc0, 0, data_0217d378->mUnk_34, 0xa);
    b = func_020ae4c0(1, ~0x1f, ~0xbf, data_0217d378->mUnk_34, 0xa);
    c = data_0217d378->mUnk_04->mUnk_06;
    data_0217d378->mUnk_3c = a;
    data_0217d378->mUnk_18[20].mUnk_06 = a;
    data_0217d378->mUnk_18[19].mUnk_06 = a;
    data_0217d378->mUnk_18[2].mUnk_06 = a;
    data_0217d378->mUnk_18[1].mUnk_06 = a;
    data_0217d378->mUnk_18[0].mUnk_06 = a;
    for (i = 0; i < 8; i++) {
        data_0217d378->mUnk_18[data_0215cf1c[i]].mUnk_06 = a;
    }
    for (i = 0; i < 4; i++) {
        data_0217d378->mUnk_18[data_0215cf04[i]].mUnk_06 = a;
        data_0217d378->mUnk_18[c + data_0215cf0c[i]].mUnk_06 = a;
    }
    d = data_0217d378->mUnk_10->mUnk_06;
    data_0217d378->mUnk_40 = b;
    data_0217d378->mUnk_1c[20].mUnk_06 = b;
    data_0217d378->mUnk_1c[19].mUnk_06 = b;
    data_0217d378->mUnk_1c[2].mUnk_06 = b;
    data_0217d378->mUnk_1c[1].mUnk_06 = b;
    data_0217d378->mUnk_1c[0].mUnk_06 = b;
    for (i = 0; i < 8; i++) {
        data_0217d378->mUnk_1c[data_0215cf1c[i]].mUnk_06 = b;
    }
    for (i = 0; i < 4; i++) {
        data_0217d378->mUnk_1c[data_0215cf04[i]].mUnk_06 = b;
        data_0217d378->mUnk_1c[d + data_0215cf0c[i]].mUnk_06 = b;
    }
}

s32 func_0211e51c(void) {
    s32 i;
    u16 *p;
    s32 n;
    s32 a;
    s32 b;

    data_0217d378->mUnk_2c = data_0217d378->mUnk_30;
    switch (data_0217d378->mUnk_2c) {
        case 0:
            func_0211e7c0();
            break;
        case 1:
            func_0211e65c();
            break;
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        if (data_0217d378->mUnk_38 != 0 && func_020d0ec4() != 0) {
            p = func_020d0e58();
            func_02016468(0xf, 0, func_020d0ea0(), 0xe0);
            func_02016468(4, 0x20, func_020d0e7c(), 0xdc0);
            a = 8;
            b = 0x14;
            for (i = 0; i < 0xb; i++) {
                n = ((i + 8) << 5) + 0x16;
                func_02016468(a, n << 1, p + n, b);
            }
            func_02016468(0x1f, 0, func_020d0ea0(), 0xe0);
            func_02016468(0x17, 0x20, func_020d0e7c(), 0xdc0);
            a = 0x1b;
            for (i = 0; i < 0xb; i++) {
                n = ((i + 8) << 5) + 0x16;
                func_02016468(a, n << 1, p + n, b);
            }
            data_0217d378->mUnk_38 = 0;
        }
        func_02124c30(data_0217d378->mUnk_04, data_0217d378->mUnk_00, data_0217d378->mUnk_08, data_0217d378->mUnk_48,
                      data_0217d378->mUnk_18);
        func_02124c30(data_0217d378->mUnk_10, data_0217d378->mUnk_0c, data_0217d378->mUnk_14, data_0217d378->mUnk_4c,
                      data_0217d378->mUnk_1c);
    } else {
        func_0211f39c();
    }
    if (data_0217d378->mUnk_2c == 0 && data_0217d378->mUnk_34 > 0xa) {
        return 1;
    }
    if (data_0217d378->mUnk_2c == 1 && data_0217d378->mUnk_34 > 0xa) {
        return 2;
    }
    return 0;
}

void func_0211e4e8(void) {
    reg_G2_BG0OFS = (-data_0217d378->mUnk_3c << 16) & 0x1ff0000;
    reg_G2S_DB_BG3OFS = (-data_0217d378->mUnk_40 << 16) & 0x1ff0000;
}

#pragma thumb off
