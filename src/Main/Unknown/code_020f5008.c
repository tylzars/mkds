#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0208ab98.h"
#include "Main/Unknown/code_020f5008.h"

#include "Main/Unknown/code_020f73fc.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0208a000.h"
#include "Main/Unknown/code_020f5d6c.h"
#include "Main/Unknown/code_020f7000.h"
#include "Main/Unknown/code_020f9000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f2dac.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f4000.h"
#include "Main/Unknown/code_020f6000.h"
#include "Main/Unknown/code_020f9c40.h"
#include "Main/Unknown/code_020fa000.h"
#include "Main/Unknown/code_02109000.h"
#include "code_02147cd8.h"

#pragma thumb off

// Runs func_020ed5c0 with the last two parameters swapped when the 0x134 word is set.
void func_020f5008(Unk020f5008 *a, void *b, void *c) {
    if (a->mUnk_134 == 0) {
        return;
    }
    func_020ed5c0(&a->mUnk_000.mUnk_000, c, b);
}

// Decreases the 0x130 word by one; when it goes below zero func_020f7658 runs first.
void func_020f4fd0(Unk020f5008 *a) {
    a->mUnk_130--;
    if (a->mUnk_130 < 0) {
        func_020f7658(&a->mUnk_000.mUnk_000, 0);
    }
    func_020f68b0(&a->mUnk_000.mUnk_000);
}

// Sets the object up through func_020f2df0 when the 0x74 word allows it.
void func_020f4f44(Unk020f5008 *a) {
    u32 n;

    func_020f2df0(&a->mUnk_000, 0x385, 0xff8, 0x733, &n);
    if ((a->mUnk_000.mUnk_000.mUnk_74 & 8) == 0) {
        return;
    }
    if ((a->mUnk_000.mUnk_000.mUnk_74 & 3) != 0) {
        return;
    }
    func_02109060(&a->mUnk_000.mUnk_000.mUnk_00, 0xda);
    func_020f6a6c(&a->mUnk_000.mUnk_000, &n);
    if ((a->mUnk_000.mUnk_000.mUnk_74 & 0x180000) == 0) {
        a->mUnk_000.mUnk_000.mUnk_120 = (void (*)(Unk020f41c4_A *)) func_020f4fd0;
    }
}

// Returns what func_020fa3d0 gives, with its 0x134 and 0x130 words cleared.
Unk020f5008 *func_020f4ee8(void) {
    Unk020f5008 *p;

    p = func_020fa3d0(3, 8, &data_02159764, &data_02159764);
    if (p == NULL) {
        return NULL;
    }
    if ((p->mUnk_000.mUnk_000.mUnk_74 & 0x180000) == 0) {
        p->mUnk_000.mUnk_000.mUnk_120 = NULL;
    }
    func_020f9c40((s32) p);
    p->mUnk_134 = 0;
    p->mUnk_130 = 0;
    return p;
}

// Stores the two Vec3s in the object and sets the word at 0x80.
void func_020f4e78(Unk020f5008 *a, Vec3 *b, Vec3 *c) {
    a->mUnk_134 = 1;
    func_0208ad74(&a->mUnk_000.mUnk_000.mUnk_7c, 1);
    if (b != NULL) {
        a->mUnk_000.mUnk_000.mUnk_f0 = *b;
        a->mUnk_000.mUnk_000.mUnk_74 |= 0x80;
    }
    if (c == NULL) {
        return;
    }
    a->mUnk_000.mUnk_000.mUnk_50 = *c;
    Vec3Sub(&a->mUnk_000.mUnk_000.mUnk_50, &a->mUnk_000.mUnk_000.mUnk_0e4, &a->mUnk_000.mUnk_000.mUnk_5c);
}

// Runs the object's first word and stores the 0x120 and 0x130 words.
void func_020f4dfc(void **a, Vec3 *b, s32 c) {
    Unk020f5008 *p;

    p = a[0];
    p->mUnk_000.mUnk_000.mUnk_78 |= data_0215969c;
    func_020f9ca8(p);
    func_020f9114(p);
    func_020f30ec(&p->mUnk_000, 0, b);
    if ((p->mUnk_000.mUnk_000.mUnk_74 & 0x180000) == 0) {
        p->mUnk_000.mUnk_000.mUnk_120 = (void (*)(Unk020f41c4_A *)) func_020f4f44;
    }
    p->mUnk_130 = c;
    a[0] = NULL;
}

#pragma thumb on

// Fills a table of eighteen 0x1c-byte objects allocated here.
void func_020f4b8c(void) {
    Unk0217bc48 *p;
    s32 i;

    p = HeapAlloc(GetHeap(func_020364e8()), 0x1f8);
    data_0217bc48 = p;
    p[0] = data_02159918;
    p[1] = data_02159838;
    p[2] = data_02159770;
    p[3] = data_02159f68;
    p[4] = data_021596a0;
    p[5] = data_02159664;
    p[6] = data_02159e54;
    p[7] = data_02159cc0;
    p[8] = data_02159aa0;
    p[9] = data_02159f4c;
    p[10] = data_02159680;
    p[11] = data_021598fc;
    p[12] = data_021599dc;
    p[13] = data_02159d90;
    p[14] = data_0215a588;
    p[15] = data_0215a2ec;
    p[16] = data_0215a174;
    p[17] = data_0215a4c0;
    switch (data_021759c0->mUnk_08) {
        case 2:
            p[17].mUnk_00 = 1;
            break;
        case 5:
            for (i = 0; i < 0x12; i++) {
                if (data_0217bc48[(u32) i].mUnk_00 != 0 && data_0217bc48[(u32) i].mUnk_04 == 0) {
                    data_0217bc48[i].mUnk_00 = 0;
                }
            }
            break;
    }
    if (data_021759c0->mUnk_00c == 1) {
        data_0217bc48[15].mUnk_00 = 0;
    }
}

#pragma thumb off

void func_020f4b20(Unk020f40dc *a, Unk020ee684 *b) {
    s32 i;

    a->mUnk_04 = b;
    a->mUnk_00 = 0x13;
    a->mUnk_08 = 0;
    a->mUnk_20 = 0;
    a->mUnk_0c = 0;
    a->mUnk_10 = 0;
    a->mUnk_12 = 0;
    for (i = 0; i < 3; i++) {
        a->mUnk_14[i] = NULL;
    }
    a->mUnk_24 = data_021759c0->mUnk_68[b->mUnk_1f8].mUnk_08.mUnk_00 == 3;
}

void func_020f49bc(Unk020f40dc *a) {
    Unk020f41c4_A *e;
    Unk0206bcb0 *p;
    Vec3 *q;
    Vec3 *r;
    void (*h)(void *);
    s32 i;
    enum { K0 } k;

    if (a->mUnk_20 <= 0) {
        return;
    }
    a->mUnk_20--;
    if (a->mUnk_20 != 7 && a->mUnk_20 != 5 && a->mUnk_20 != 3) {
        return;
    }
    p = a->mUnk_04->mUnk_1fc;
    a->mUnk_08--;
    e = a->mUnk_14[a->mUnk_08];
    q = &p->mUnk_98;
    r = &p->mUnk_a4;
    func_020f0ea0(data_027e00cc + e->mUnk_44, e);
    func_020efd1c(a->mUnk_04, e);
    Vec3AddScaled(0xb33, r, &e->mUnk_5c, &e->mUnk_5c);
    *(Vec3 *) &e->mUnk_50 = *q;
    func_020f6630(e, 0, q, r, &p->mUnk_244);
    k = e->mUnk_44;
    h = data_0217bc34[k].mUnk_38;
    if (h != NULL) {
        h(e);
    }
    if (a->mUnk_08 != 0) {
        return;
    }
    a->mUnk_00 = 0x13;
    a->mUnk_08 = 0;
    a->mUnk_20 = 0;
    a->mUnk_0c = 0;
    a->mUnk_10 = 0;
    a->mUnk_12 = 0;
    for (i = 0; i < 3; i++) {
        a->mUnk_14[i] = NULL;
    }
}
