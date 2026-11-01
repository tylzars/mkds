#include "Main/Unknown/code_02024fe8.h"
#include "Main/Unknown/code_0210bafc.h"
#include "Main/Unknown/code_02109054.h"

void func_0202506c(Unk0206bcb0 *a, Unk02024eec *b) {
    Unk0210bf24 *p;

    p = func_02109078(&a->mUnk_00, b->mUnk_00, b->mUnk_04, (b->mUnk_08 << 4) >> 16);
    if (p != 0) {
        p->mUnk_19 |= 0x80;
    }
}

void func_02025030(Unk0206bcb0 *a, Unk02024eec *b) {
    Unk0210bf24 *p;

    p = func_02109078(&a->mUnk_00, b->mUnk_58, b->mUnk_04, (b->mUnk_08 << 4) >> 16);
    if (p != 0) {
        p->mUnk_19 |= 0x80;
    }
}

void func_02024fe8(Unk0206bcb0 *a, Unk02024eec *b) {
    u32 v;

    v = func_0210bb74(3, a->mUnk_3e0, a->mUnk_3e4);
    func_02109078(&a->mUnk_00, v, b->mUnk_04, (b->mUnk_08 << 4) >> 16);
}
