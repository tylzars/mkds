#include "00/code_021a57a8.h"
#include "code_0200fc8c.h"

void func_ov000_021a586c(s16 a, u32 b, void *c, u32 d, u32 e) {
    Unk021a586c v;

    if (data_ov000_021b5f50->mUnk_227c != 0) {
        v.mUnk_00 = a;
        v.mUnk_02 = b;
        v.mUnk_04 = c;
        v.mUnk_08 = d;
        v.mUnk_0c = e;
        data_ov000_021b5f50->mUnk_227c(&v);
    }
}

void func_ov000_021a57fc(u32 a) {
    u32 b;

    b = func_0200fca0();
    if (data_ov000_021b5f50->mUnk_2260 == 9 && a != 9) {
        func_0200f8b8(&data_ov000_021b5f50->mUnk_22cc);
    }
    if (data_ov000_021b5f50->mUnk_2260 != 0xb) {
        data_ov000_021b5f50->mUnk_2260 = a;
    }
    if (a == 9) {
        func_0200f950(&data_ov000_021b5f50->mUnk_22cc, 0x22f5341, func_ov000_021a5794, 0);
    }
    func_0200fcb4(b);
}

void func_ov000_021a57a8(void) {
    u32 a;

    a = func_0200fca0();
    func_0200f8b8(&data_ov000_021b5f50->mUnk_22cc);
    if (data_ov000_021b5f50->mUnk_2260 == 9) {
        func_0200f950(&data_ov000_021b5f50->mUnk_22cc, 0x22f5341, func_ov000_021a5794, 0);
    }
    func_0200fcb4(a);
}
