#include "Main/Unknown/code_020901a0.h"
#include "Main/Unknown/code_0207c000.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/unk_0217b000.h"

void func_0209033c(Unk0208fd8c *a, Unk020888b4 *b) {
    func_0207c2ec(a, b);
}

void func_020902fc(Unk0208fd8c *a, Unk020888b4 *b) {
    enum { K0 } i;

    i = *(s32 *) &gKartItems[b->mIndex].mHeldItem;
    a->mUnk_04 = data_0217b09c + i;
    func_0207c0a0(a);
}

void func_020902d0(Unk0208fd8c *a, Unk020888b4 *b) {
    if (b->mUnk_b0 == NULL) {
        return;
    }
    func_0207c614(a, b);
}

void func_02090288(Unk0208fd8c *a, Unk020888b4 *b) {
    if (func_0207c078(a) == 0 && b->mUnk_b0 == NULL) {
        return;
    }
    func_0207c614(a, b);
}

void func_0209024c(Unk0208fd8c *a, Unk020888b4 *b) {
    if (func_0207c078(a) == 0) {
        return;
    }
    func_0207c614(a, b);
}

void func_020901f0(Unk0208fd8c *a, Unk020888b4 *b) {
    if (func_0207c078(a) == 0 && b->mUnk_b0 == NULL) {
        return;
    }
    if (b->mUnk_70 >= 0xa000) {
        return;
    }
    func_0207c614(a, b);
}

void func_020901a0(Unk0208fd8c *a, Unk020888b4 *b) {
    if (func_0207c078(a) == 0) {
        return;
    }
    if (b->mUnk_70 >= 0xa000) {
        return;
    }
    func_0207c614(a, b);
}
