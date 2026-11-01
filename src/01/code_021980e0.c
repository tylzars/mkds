#include "01/code_021980e0.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_0204799c.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "00/code_02182fdc.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a8000.h"
#include "Main/Unknown/code_02060000.h"
#include "Main/Unknown/code_02116000.h"
#include "code_0212df7c.h"

void func_ov001_021984ac(void) {
    Unk020b4934 *a = 0;
    Unk02021dc8 *b = 0;
    Unk020b4a44 *c = 0;
    Unk020b4934 *d = 0;
    Unk020b4a44 *e = 0;
    Unk020b47d8 *f = 0;

    func_020b496c(&d, func_0204799c(data_ov001_021a835c));
    func_020b4a7c(&e, func_0204799c(data_ov001_021a8360));
    func_020b4810(&f, func_0204799c(data_ov001_021a8354));
    func_020b49f4(&a, func_0204799c(data_ov001_021a8350));
    func_020b48ec(&b, func_0204799c(data_ov001_021a834c));
    func_020b4a7c(&c, func_0204799c(data_ov001_021a8364));
}

void func_ov001_02198384(void) {
    Unk020b4934 *a = 0;
    Unk020b4a44 *b = 0;
    Unk020b4934 *c = 0;
    Unk020b4a44 *d = 0;
    Unk020b47d8 *e = 0;

    func_020b4934(&c, func_0204799c(data_ov001_021a835c));
    func_020b4a44(&d, func_0204799c(data_ov001_021a8360));
    func_020b47d8(&e, func_0204799c(data_ov001_021a8354));
    data_ov001_021a9be0->mUnk_10 = func_02036bec(data_ov001_021a9be0->mUnk_14, 0x800);
    data_ov001_021a9be0->mUnk_04 = func_0204799c(data_ov001_021a8358);
    data_ov001_021a9be0->mUnk_08 = func_0204799c(data_ov001_021a8348);
    func_020b49bc(&a, func_0204799c(data_ov001_021a8350));
    func_020b48b4(&data_ov001_021a9be0->mUnk_00, func_0204799c(data_ov001_021a834c));
    func_020b4a44(&b, func_0204799c(data_ov001_021a8364));
    func_02016468(4, 0, c->mUnk_14, c->mUnk_10);
    func_02016468(0xf, 0, d->mUnk_0c, 0x20);
    func_02016468(8, 0, &e->mUnk_0c, e->mUnk_08);
    func_02016468(8, 0x800, data_ov001_021a9be0->mUnk_10, 0x800);
    func_02016468(0x23, 0, a->mUnk_14, a->mUnk_10);
    func_02016468(0x1e, 0, b->mUnk_0c, b->mUnk_08);
}

void func_ov001_02198368(void) {
    data_ov001_021a9be0->mUnk_1c = 0;
    data_ov001_021a9be0->mUnk_20 = 0;
    data_ov001_021a9be0->mUnk_24 = -192;
}

void func_ov001_02198354(void) {
    data_ov001_021a9be0->mUnk_1c = 1;
    data_ov001_021a9be0->mUnk_20 = 0;
}

void func_ov001_02198338(void) {
    data_ov001_021a9be0->mUnk_1c = 2;
    data_ov001_021a9be0->mUnk_20 = 0;
    func_02128374();
}

void func_ov001_02198324(void) {
    data_ov001_021a9be0->mUnk_1c = 3;
    data_ov001_021a9be0->mUnk_20 = 0;
}

void func_ov001_021982e8(void) {
    data_ov001_021a9be0->mUnk_1c = 4;
    data_ov001_021a9be0->mUnk_20 = 0;
    switch (data_ov001_021a9be0->mUnk_28) {
        case 1:
        case 2:
            func_021282c8();
            break;
    }
    func_0212ecc0(&data_0217d068, 0, 5);
}

void func_ov001_021982d4(void) {
    data_ov001_021a9be0->mUnk_1c = 5;
    data_ov001_021a9be0->mUnk_20 = 0;
}

void func_ov001_0219829c(s32 a) {
    data_ov001_021a9be0->mUnk_0c[data_ov001_021a6a00[a]].mUnk_00 = 1;
    func_02124a20(data_ov001_021a6a18[a], 0xe, data_ov001_021a9be0->mUnk_00, data_ov001_021a9be0->mUnk_04);
}

void func_ov001_02198264(s32 a) {
    data_ov001_021a9be0->mUnk_0c[data_ov001_021a6a00[a]].mUnk_00 = 0;
    func_02124a20(data_ov001_021a6a18[a], 0xf, data_ov001_021a9be0->mUnk_00, data_ov001_021a9be0->mUnk_04);
}

void func_ov001_02198100(void *param_1, void *param_2, s32 param_3) {
    void *heap;
    s32 i;

    *(u16 *) 0x4000008 = (*(u16 *) 0x4000008 & 0x43) | 0x9004;
    heap = func_02036948(param_1);
    data_ov001_021a9be0 = func_02036bec(heap, 0x38);
    data_ov001_021a9be0->mUnk_14 = heap;
    data_ov001_021a9be0->mUnk_18 = 0;
    data_ov001_021a9be0->mUnk_2c = param_2;
    data_ov001_021a9be0->mUnk_30 = param_3;
    data_ov001_021a9be0->mUnk_34 = 0;
    func_ov001_02198368();
    if (func_020cccb4() == 0x1f) {
        if (data_0217b488->mUnk_0c == 0) {
            data_ov001_021a9be0->mUnk_28 = 1;
        } else {
            data_ov001_021a9be0->mUnk_28 = 2;
        }
    } else {
        data_ov001_021a9be0->mUnk_28 = 0;
    }
    func_ov001_02198384();
    for (i = 0; i < 3; i++) {
        func_02124a98(data_ov001_021a6a10[i], 1, data_ov001_021a9be0->mUnk_00, data_ov001_021a9be0->mUnk_04);
    }
    func_020ae6d4(data_ov001_021a9be0->mUnk_2c, (void *) data_ov001_021a9be0->mUnk_30);
    func_02124ed0(data_ov001_021a9be0->mUnk_14, data_ov001_021a9be0->mUnk_04, 0, &data_ov001_021a9be0->mUnk_0c);
    for (i = 0; i < 3; i++) {
        data_ov001_021a9be0->mUnk_0c[data_ov001_021a6a08[i]].mUnk_04 = 0xe0;
        data_ov001_021a9be0->mUnk_0c[data_ov001_021a6a10[i]].mUnk_04 = 0xe0;
        data_ov001_021a9be0->mUnk_0c[data_ov001_021a6a00[i]].mUnk_04 = 0xe0;
        data_ov001_021a9be0->mUnk_0c[data_ov001_021a6a18[i]].mUnk_04 = 0xe0;
        func_ov001_02198264(i);
    }
    data_ov001_021a9be0->mUnk_0c[12].mUnk_04 = 0xe0;
    data_ov001_021a9be0->mUnk_0c[13].mUnk_04 = 0xe0;
    func_ov001_0219829c(data_ov001_021a9be0->mUnk_28);
    func_02036820(data_ov001_021a9be0->mUnk_14);
}

void func_ov001_021980e0(void) {
    func_02036ab0(data_ov001_021a9be0->mUnk_14);
    data_ov001_021a9be0 = 0;
}
