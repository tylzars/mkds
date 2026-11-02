#include "code_02017ea0.h"

void func_02017ef8(Unk02017ef8 *a, Unk02017e70 *b) {
    a->mUnk_00 = (u32) b - (u16) ((b->mUnk_02 >> 8) & 0x7f);
    a->mUnk_04 = b->mUnk_04 + (u32) (b + 1);
}

Unk02017e70 *func_02017ed0(Unk02017ea0 *a, Unk02017e70 *b) {
    Unk02017e70 *p;
    Unk02017e70 *n;

    p = b->mUnk_08;
    n = b->mUnk_0c;
    if (p != 0) {
        p->mUnk_0c = n;
    } else {
        a->mUnk_00 = n;
    }
    if (n != 0) {
        n->mUnk_08 = p;
    } else {
        a->mUnk_04 = p;
    }
    return p;
}

Unk02017e70 *func_02017ea0(Unk02017ea0 *a, Unk02017e70 *b, Unk02017e70 *c) {
    Unk02017e70 *n;

    b->mUnk_08 = c;
    if (c != 0) {
        n = c->mUnk_0c;
        c->mUnk_0c = b;
    } else {
        n = a->mUnk_00;
        a->mUnk_00 = b;
    }
    b->mUnk_0c = n;
    if (n != 0) {
        n->mUnk_08 = b;
    } else {
        a->mUnk_04 = b;
    }
    return b;
}
