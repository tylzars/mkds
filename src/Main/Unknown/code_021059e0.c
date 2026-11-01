#include "Main/Unknown/code_021059e0.h"

#include "Main/Unknown/unk_0215a000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/code_0210d960.h"
#include "Main/Unknown/code_0210d000.h"
#include "Main/Unknown/code_0212da2c.h"
#include "code_0212c478.h"
#include "code_0212c6ac.h"
#include "code_0212da38.h"
#include "code_0212df7c.h"

void func_02105d70(void) {
    u32 x;
    s32 y;
    s32 j;
    u8 *v;
    s32 i;
    Unk0212c400 **p;
    Unk0217c7c4 *q;

    x = func_0210d960();
    data_0217c814.mUnk_20 = 1;
    func_0210d970(0xa);
    if (data_0217c7ac != 0) {
        func_0212c6f0(&data_0217c7ac, 0);
    }
    func_0212ecc0(&data_0217c7ac, 0, 0x11);
    if (data_0217c814.mUnk_0c == 2) {
        return;
    }
    func_0210d9a0(&data_0217d084, 5);
    if (data_0217c814.mUnk_16 == 1) {
        data_0217c814.mUnk_16 = 3;
    }
    p = data_0217c838;
    for (i = 0; i < 0xc; i++) {
        func_0212c620(p, 0, func_0210d960());
        p++;
    }
    y = func_0210d960();
    q = (Unk0217c7c4 *) data_0217c7c4;
    for (j = 0, v = q->mUnk_0c; j < q->mUnk_00; j++) {
        func_0212c620((Unk0212c400 **) v, 0, y);
        v += q->mUnk_10;
    }
    func_0210d970(x);
}

void func_02105c4c(void) {
    u32 x;
    s32 y;
    s32 j;
    u8 *v;
    s32 i;
    Unk0212c400 **p;
    Unk0217c7c4 *q;

    x = func_0210d960();
    data_0217c814.mUnk_20 = 0;
    func_0210d970(0xa);
    if (data_0217c7ac != 0) {
        func_0212c6f0(&data_0217c7ac, 0);
    }
    func_0212ecc0(&data_0217c7ac, 0, 0x12);
    if (data_0217c814.mUnk_0c == 2) {
        return;
    }
    func_0210dc50(&data_0217d084);
    if (data_0217c814.mUnk_16 == 3) {
        data_0217c814.mUnk_16 = 1;
    }
    p = data_0217c838;
    for (i = 0; i < 0xc; i++) {
        func_0212c620(p, 0x7f, func_0210d960());
        p++;
    }
    y = func_0210d960();
    q = (Unk0217c7c4 *) data_0217c7c4;
    for (j = 0, v = q->mUnk_0c; j < q->mUnk_00; j++) {
        func_0212c620((Unk0212c400 **) v, 0x7f, y);
        v += q->mUnk_10;
    }
    func_0210d970(x);
}

void func_02105b64(s32 a) {
    u32 x;
    s32 j;
    u8 *v;
    s32 i;
    Unk0212c400 **p;
    Unk0217c7c4 *q;
    u32 h;

    h = data_0215a6d8[a];
    if (data_0217c7ac != 0) {
        func_0212c6f0(&data_0217c7ac, 0);
    }
    func_0212ecc0(&data_0217c7ac, 0, h);
    if (a == 4) {
        return;
    }
    p = data_0217c838;
    for (i = 0; i < 0xc; i++) {
        func_0212c6f0(p, func_0210d960());
        p++;
    }
    x = func_0210d960();
    q = (Unk0217c7c4 *) data_0217c7c4;
    for (j = 0, v = q->mUnk_0c; j < q->mUnk_00; j++) {
        func_0212c6f0((Unk0212c400 **) v, x);
        v += q->mUnk_10;
    }
    func_0210d9a0(&data_0217d084, 4);
}

void func_02105b48(void) {
    func_0212c6ac(func_0210d960());
}

void func_02105b28(Unk0212c400 **a, u32 b) {
    func_0212c554(a, data_0216cb20, (u8) b);
}

void func_02105b0c(Unk0212c400 **a, u32 b) {
    func_0212c524(a, data_0216cb20, b);
}

void func_02105ac0(s32 a) {
    if (data_0217c794 != 0) {
        return;
    }
    data_0217c794 = 1;
    func_0212ecc0(&data_0217d068, 0, a);
}

void func_02105a30(u32 a) {
    s32 r;

    *(s32 *) data_0217c784 = a;
    if (a - 1 > 1) {
        return;
    }
    r = (a == 1) ? 0x47 : 0x48;
    func_0212da38(data_0217d130, data_0217c798[0]);
    func_0212da2c(data_0217d130);
    func_0212e9cc(r, data_0217d130);
    func_0212c6f0(&data_0217d07c, 2);
    func_0210d7dc(r, 0x7f, (Unk0212c400 **) data_0217c83c);
}

void func_021059e0(void) {
    if (data_0217d070.mUnk_0c != 0) {
        return;
    }
    if (data_0217c838[1] != 0) {
        return;
    }
    func_0210d5c0(&data_0217d070);
}
