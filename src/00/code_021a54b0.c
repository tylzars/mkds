#include "00/code_021a54b0.h"
#include "code_0214259c.h"
#include "code_021453ec.h"

void func_ov000_021a56e4(Unk021425e8 *v1) {
    if (v1->mUnk_02 == 8 && v1->mUnk_04 == 0x16 && v1->mUnk_06 == 0x25) {
        switch (data_ov000_021b5f50->mUnk_2260) {
            case 8:
                func_ov000_021a57fc(0xc);
                return;
            case 9:
            case 12:
                func_ov000_021a574c();
                return;
            case 10:
                func_ov000_021a57fc(0xc);
                break;
        }
    }
}

void func_ov000_021a54b0(Unk021425e8 *v1) {
    Unk021b5f50 *g;
    s32 r = 0x14;

    switch (v1->mUnk_02) {
        case 0:
            switch (v1->mUnk_00) {
                case 3:
                    r = func_02143ec0(func_ov000_021a54b0);
                    break;
                case 4:
                    switch (func_02142c24()) {
                        case 0:
                            func_ov000_021a57fc(1);
                            func_ov000_021a58a4(0, NULL, 0, 0x663);
                            return;
                        case 4:
                        default:
                            func_ov000_021a57fc(0xb);
                            func_ov000_021a58a4(7, NULL, 0, 0x66a);
                            return;
                    }
                case 5:
                    func_ov000_021a57fc(3);
                    func_ov000_021a58a4(0, NULL, 0, 0x670);
                    return;
                case 6:
                    r = func_02143f08(func_ov000_021a54b0);
                    break;
                case 0x1d:
                    r = func_02145530((Unk021425e8Func) func_ov000_021a54b0, 0);
                    break;
                case 0x19:
                    g = data_ov000_021b5f50;
                    r = func_02145668((u32) func_ov000_021a54b0, g->mUnk_2250, g->mUnk_2251, g->mUnk_2200);
                    break;
                case 0x27: {
                    u32 v;
                    u16 e;
                    u32 d;
                    g = data_ov000_021b5f50;
                    v = g->mUnk_2264;
                    e = (v & 0xc0000) == 0xc0000;
                    d = (v & 0x30000) != 0x30000 ? 1 : 0;
                    r = func_021437d8((Unk021425e8Func) func_ov000_021a5088, (u16 *) g->mUnk_2140, NULL, d, e);
                    break;
                }
            }
            if (r == 2) {
                return;
            }
            switch (r) {
                case 8:
                    func_ov000_021a57fc(0xc);
                    func_ov000_021a58a4(1, data_ov000_021b5f50->mUnk_2280 == 5 ? data_ov000_021b5f50->mUnk_2140 : 0, 0,
                                        0x6a7);
                    return;
                case 3:
                default:
                    func_ov000_021a57fc(0xb);
                    func_ov000_021a58a4(7, data_ov000_021b5f50->mUnk_2280 == 5 ? data_ov000_021b5f50->mUnk_2140 : 0, 0,
                                        0x6b0);
                    return;
            }
            break;
        case 1:
            func_ov000_021a57fc(0xc);
            func_ov000_021a58a4(1, data_ov000_021b5f50->mUnk_2280 == 5 ? data_ov000_021b5f50->mUnk_2140 : 0, 0, 0x6d0);
            return;
        case 2:
        case 3:
        case 4:
        default:
            func_ov000_021a57fc(0xb);
            func_ov000_021a58a4(7, data_ov000_021b5f50->mUnk_2280 == 5 ? data_ov000_021b5f50->mUnk_2140 : 0, 0, 0x6da);
            return;
    }
}
