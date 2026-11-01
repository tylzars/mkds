#include "00/code_021a6944.h"
#include "00/code_021a5b30.h"
#include "00/code_021a5000.h"
#include "00/unk_021b5000.h"
#include "code_0200dc3c.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"

void func_ov000_021a6944(Unk021425e8 *param_1) {
    if (param_1->mUnk_00 == 0x12) {
        data_ov000_021b5f54.mUnk_24 = param_1->mUnk_02;
        if (param_1->mUnk_02 == 0) {
            func_ov000_021a57a8();
        }
        func_0200df9c(&data_ov000_021b5f54.mUnk_04);
    }
}

s32 func_ov000_021a6974(const void *param_1, const void *param_2, s32 param_3) {
    u32 a;
    Unk021b5f50 *b;
    s32 c;

    a = func_0200fca0();
    if (func_ov000_021a5b30() == 0) {
        func_0200fcb4(a);
        return -1;
    }
    func_0200ed34(&data_ov000_021b5f54.mUnk_0c);
    b = func_ov000_021a5b30();
    if (b == 0) {
        func_0200ecc4(&data_ov000_021b5f54.mUnk_0c);
        func_0200fcb4(a);
        return -1;
    }
    if (b->mUnk_2260 != 9 || b->mUnk_226b == 1) {
        func_0200ecc4(&data_ov000_021b5f54.mUnk_0c);
        func_0200fcb4(a);
        return -4;
    }
    func_0214d1fc(param_2, b->mUnk_0f00, param_3);
    c = func_02144438(func_ov000_021a6944, param_1, b->mUnk_0f00, (u16) param_3);
    switch (c) {
        case 0:
        case 1:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        default:
            func_0200ecc4(&data_ov000_021b5f54.mUnk_0c);
            func_0200fcb4(a);
            return -5;
        case 2:
            func_0200e01c(&data_ov000_021b5f54.mUnk_04);
            switch (data_ov000_021b5f54.mUnk_24) {
                case 1:
                default:
                    func_0200ecc4(&data_ov000_021b5f54.mUnk_0c);
                    func_0200fcb4(a);
                    return -5;
                case 0:
                    func_0200ecc4(&data_ov000_021b5f54.mUnk_0c);
                    func_0200fcb4(a);
                    return param_3;
            }
    }
}
