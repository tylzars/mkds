#include "00/code_021a72c4.h"
#include "00/code_021a88a8.h"
#include "00/code_021a6fb4.h"
#include "00/unk_021b6000.h"
#include "00/code_021a8aa8.h"
#include "00/code_021a78a4.h"
#include "00/code_021ae134.h"
#include "00/code_021ae214.h"
#include "00/code_021ae244.h"
#include "00/code_021ae258.h"
#include "00/code_021ae304.h"
#include "00/unk_021b5000.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"

s32 func_ov000_021a72c4(Unk021b49b8 *param_1) {
    s32 a = 0x80;

    if (param_1->mUnk_02 != 0) {
        a += 0x114;
        a += func_ov000_021a8a54(param_1->mUnk_02);
        a += func_ov000_021a8a54(param_1->mUnk_08);
        a += func_ov000_021a72a4(&param_1->mUnk_10);
    }
    if (param_1->mUnk_06 != 0) {
        a += 0x110;
        a += func_ov000_021a8a54(param_1->mUnk_06);
        a += func_ov000_021a8a54(param_1->mUnk_0a);
        a += func_ov000_021a8a54(param_1->mUnk_0c);
        a += func_ov000_021a72a4(&param_1->mUnk_14);
    }
    return a;
}

Unk021a6fa8 *func_ov000_021a732c(Unk021b49b8 *param_1) {
    s32 a;
    u32 b;
    Unk021a6fa8 *c;

    a = func_ov000_021a72c4(param_1);
    b = func_0200fca0();
    c = data_ov000_021b5f94->mUnk_18(a);
    if (c != NULL) {
        func_0214d168(c, 0, a);
        func_ov000_021a71c0(c, param_1);
        func_ov000_021a8b10(c);
    }
    func_0200fcb4(b);
    return c;
}

s32 func_ov000_021a7378(Unk021a7064 *param_1) {
    Unk021a6fa8 *a;
    Unk021a7154 *b;

    a = param_1->mUnk_04;
    func_ov000_021ae304(a);
    b = a->mSendBlock;
    switch (a->mUnk_73) {
        case 0:
        case 4:
            func_ov000_021ae244(&b->mUnk_20);
            func_ov000_021ae270();
            break;
        case 1:
            func_ov000_021ae270();
            func_ov000_021ae2d8();
            func_ov000_021ae214(func_ov000_021a78a4);
            break;
        case 2:
            func_ov000_021ae2d8();
            break;
        case 3:
            break;
    }
    a->mUnk_70 = 1;
    return 0;
}
