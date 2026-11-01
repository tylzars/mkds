#include "03/code_021c70a4.h"

void func_ov003_021c70a4(void) {
    Unk021d7324 a;
    s32 b;
    a = data_ov003_021d7324;
    if (func_ov003_021cef6c() == 0) {
        if (data_ov003_021da1fc->mUnk_15 == 0) {
            data_ov003_021da1fc->mUnk_04->mUnk_00 = data_ov003_021da1fc->mUnk_04->mUnk_00 & 0xc1fffcff;
            func_ov003_021c212c(func_ov003_021c7614);
            return;
        }
        func_ov003_021c20dc(&b, 0);
        a.mUnk_00[b](data_ov003_021da1fc->mUnk_08);
        func_ov003_021c212c(func_ov003_021c722c);
    }
}

void func_ov003_021c7118(void) {
    data_ov003_021da1fc->mUnk_15 = func_ov003_021cef80();
    switch (data_ov003_021da1fc->mUnk_15) {
        case 0:
            func_ov003_021cdc10(7);
            break;
        case 1:
            func_ov003_021cdc10(0xe);
            break;
        default:
            return;
    }
    func_ov003_021cef90();
    func_ov003_021c212c(func_ov003_021c70a4);
}

void func_ov003_021c7160(void) {
    Unk021da1fc *a;
    Unk021da1f8_04 *p;
    u32 t;
    s32 b;
    a = data_ov003_021da1fc;
    b = a->mUnk_14;
    if (b > 3) {
        b = 3;
    }
    p = a->mUnk_04;
    t = (data_ov003_021d63fc[b * 3 + 2] & 0x1ff) << 16;
    p->mUnk_00 = t | ((p->mUnk_00 & 0xfe00ff00) | 0x28);
}

// non-matching: the first argument is reloaded from the stack halfword into r1 and the stack arguments go through r1
// (original keeps r1 from the byte load and uses r2, and holds the constant 2 in r7); size 0x90 against 0x8c
void func_ov003_021c71a0(void) {
    u16 a[6];
    s32 b;
    u8 *c;
    Unk021da1fc *s;
    a[0] = data_ov003_021d7308[0];
    a[1] = data_ov003_021d7308[1];
    a[2] = data_ov003_021d7308[2];
    a[3] = data_ov003_021d7308[3];
    a[2] = data_ov003_021d63f8[0];
    a[3] = data_ov003_021d63f8[1];
    func_ov003_021d2060(data_ov003_021da1fc->mUnk_00, 0);
    b = 0;
    a[5] = 0;
    c = data_ov003_021d63fc;
    do {
        s = data_ov003_021da1fc;
        a[4] = s->mUnk_08[b];
        a[0] = *c;
        func_ov003_021d2070(s->mUnk_00, a[0], a[1], a[2], a[3], 2, 0x480, &a[4]);
        c++;
        b++;
    } while (b < 12);
    func_ov003_021d1fd0(data_ov003_021da1fc->mUnk_00);
}
