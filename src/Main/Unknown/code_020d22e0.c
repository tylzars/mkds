#include "Main/Unknown/code_020d22e0.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/code_020d5000.h"

void func_020d2398(Unk020e71a0 *a) {
    a->mUnk_02 &= ~0xf000;
    a->mUnk_02 |= (a->mUnk_02 & 0xf) << 12;
    a->mUnk_02 |= data_021568b4;
    a->mUnk_02 |= data_021568b8;
    a->mUnk_02 |= data_021568bc;
    a->mUnk_02 |= data_021568c0;
    if (a->mUnk_64 != -1) {
        func_020d5114(a->mUnk_64);
    }
    a->mUnk_02 |= data_021568c4;
}

void func_020d233c(Unk020e71a0 *a) {
    a->mUnk_02 &= ~0xf;
    a->mUnk_02 |= (a->mUnk_02 & 0xf000) >> 12;
    if (!(a->mUnk_02 & 2)) {
        a->mUnk_66 = 0x1f;
    }
    if (a->mUnk_64 != -1) {
        func_020d50ec(a->mUnk_64);
    }
    a->mUnk_02 &= ~0x100;
}

void func_020d22e0(void) {
    data_0217b4bc = data_021759c0->mUnk_08 == 5 ? &data_0217561c->mUnk_4b0 : &data_0217561c->mUnk_47c;
    data_0217b4b8 = &data_0217561c->mUnk_47c;
}
