#include "00/code_021a6d6c.h"
#include "03/code_021b94b8.h"
#include "00/code_021a6fb4.h"
#include "00/code_021a6d1c.h"
#include "00/code_021a6d5c.h"
#include "00/code_021a6934.h"
#include "00/code_021a73d8.h"
#include "00/code_021a8424.h"
#include "00/code_021a8878.h"
#include "00/code_021afe5c.h"
#include "00/code_021b0014.h"
#include "code_0200db4c.h"
#include "00/code_021af550.h"
#include "code_0214d018.h"
#include "00/unk_021b6000.h"
#include "00/code_021a91b4.h"
#include "Main/Unknown/unk_0216f000.h"
#include "00/code_021ae314.h"
#include "00/code_021ad754.h"
#include "00/code_021b0240.h"
#include "00/unk_021b4000.h"
#include "Main/Unknown/code_02000b44.h"
#include "code_02133048.h"
#include "code_0200fc8c.h"

s32 func_ov000_021a6f84(Unk021a6fa8 *param_1, Unk021a7064 *param_2) {
    if (param_1->mReceiveBlock != NULL) {
        return func_ov000_021a6fc0(param_1->mReceiveBlock, param_2);
    }
    return func_ov000_021a6fc0(param_1->mSendBlock, param_2);
}

void func_ov000_021a6f18(void *param_1) {
    Unk0200eb90 *a = param_1;
    Unk021a7064 *b;
    s32 c;
    u32 d;

    while (1) {
        func_0200e904(a, (void **) &b, 1);
        if (b == NULL) {
            return;
        }
        c = b->mUnk_00(b);
        d = IrqDisable();
        func_0200db9c();
        func_0200ea3c(a, NULL, 0);
        if (b->mUnk_04 != NULL) {
            b->mUnk_04->mEntryResult = c;
        }
        if (b->mUnk_08 != NULL) {
            func_0200eae8(b->mUnk_08, (void *) c, 0);
        }
        func_ov000_021a7048(b);
        func_0200db64();
        IrqRestore(d);
        func_0200de50();
    }
}

s32 func_ov000_021a6ee4(Unk021b5f94 *param_1) {
    func_02000b44(0x2000bbc);
    if (data_ov000_021b5f94 != NULL) {
        return 0;
    }
    data_ov000_021b5f94 = param_1;
    func_ov000_021a6db0();
    return func_ov000_021a6eb4();
}

s32 func_ov000_021a6eb4(void) {
    s32 a;

    a = func_ov000_021a70ec(data_ov000_021b5f94->mUnk_20);
    if (a >= 0) {
        data_ov000_021b5fa4 = (Unk021a6fa8 *) func_ov000_021a73d8(&data_ov000_021b49d0);
    }
    return a;
}

void func_ov000_021a6db0(void) {
    Unk021b5fa8 *a = &data_ov000_021b5fa8;
    Unk021b5f94 *b = data_ov000_021b5f94;
    s32 c;
    s32 d;

    MemFill(a, 0, 0x30);
    a->mUnk_04 = b->mUnk_18;
    a->mUnk_08 = b->mUnk_1c;
    a->mUnk_10 = func_ov000_021a6d40;
    a->mUnk_14 = 0;
    a->mUnk_18 = 0;
    a->mUnk_2c = *(u32 *) data_ov000_021b5f98;
    if (b->mUnk_24 != 0) {
        a->mUnk_20 = b->mUnk_24;
    } else {
        a->mUnk_20 = 0x4000;
    }
    if (b->mUnk_28 != NULL) {
        a->mUnk_1c = b->mUnk_28;
    } else {
        a->mUnk_1c = data_ov000_021b5f94->mUnk_18(a->mUnk_20);
    }
    c = b->mUnk_30;
    if (c == 0) {
        c = 0x240;
    }
    d = b->mUnk_34;
    if (d == 0) {
        d = 0x10c0;
    }
    a->mUnk_24 = c - 0x28;
    data_ov000_021b49b8.mUnk_02 = d;
    data_ov000_021b49b8.mUnk_04 = d / 2;
    data_ov000_021b63b4 = 0;
    if (b->mUnk_00 != 0) {
        data_ov000_021b5fa0 = 1;
        a->mUnk_00 = 0;
        a->mUnk_0c = func_ov000_021a6d5c;
        a->mUnk_28 = data_ov000_021b5f9c;
    } else {
        data_ov000_021b5fa0 = 0;
        a->mUnk_00 = 1;
        a->mUnk_0c = func_ov000_021a6d6c;
    }
    c = b->mUnk_2c;
    if (c == 0) {
        c = 0xb;
    }
    func_ov000_021b0240(c);
    func_ov000_021a6aa0(func_ov000_021afe5c);
    func_ov000_021b02b0(func_ov000_021a8424);
    func_ov000_021b02fc(a);
}

void func_ov000_021a6d6c(void) {
    Unk021b5f94 *a = data_ov000_021b5f94;

    data_ov000_021b63b4 = a->mUnk_04;
    data_ov000_021b6380 = a->mUnk_08;
    data_ov000_021b639c = a->mUnk_0c;
    data_ov000_021b63d8[0] = a->mUnk_10;
    data_ov000_021b63d8[1] = a->mUnk_14;
    data_ov000_021b5fa0 |= 2;
}
