#include "00/code_021a4b98.h"
#include "00/code_021a4b84.h"
#include "00/code_021a4000.h"
#include "00/code_021a5000.h"
#include "00/code_021a6000.h"
#include "00/unk_021b5000.h"
#include "code_02142eac.h"
#include "00/code_021a574c.h"
#include "00/code_021a669c.h"
#include "00/code_021a6abc.h"
#include "00/code_021a6c68.h"
#include "code_02133048.h"
#include "code_02142c24.h"
#include "code_021453ec.h"
#include "code_0200eddc.h"

// Not compiled code: the 1.2 compiler has no clz instruction.
// clang-format off
#pragma thumb off
asm u32 func_ov000_021a4b98(u32 a) {
    mov r1, r0
    mov r0, #0
    mov r3, #1
count_bits:
    clz r2, r1
    rsbs r2, r2, #31
    bxlo lr
    bic r1, r1, r3, lsl r2
    add r0, r0, #1
    b count_bits
}

asm u32 func_ov000_021a4bbc(u32 a) {
    clz r0, r0
    bx lr
}
#pragma thumb on
// clang-format on

void func_ov000_021a4bc4(Unk021425e8 *v1) {
    u16 a;
    u32 b;
    u32 c;
    s32 e;
    u16 f;

    if (v1->mUnk_02 == 0) {
        data_ov000_021b5f50->mUnk_226b = 0;
        data_ov000_021b5f50->mUnk_2282 = 0;
        switch (data_ov000_021b5f50->mUnk_2260) {
            case 5:
            case 6:
                func_ov000_021a57fc(3);
                func_ov000_021a58a4(1, 0, 0, 0x8e1);
                return;
            case 7:
                func_ov000_021a57fc(3);
                func_ov000_021a58a4(0, 0, 0, 0x8e7);
                return;
            case 8:
                a = data_ov000_021b5f50->mUnk_22f8;
                data_ov000_021b5f50->mUnk_22f8 = 0;
                if (a == 0x12 && (data_ov000_021b5f50->mUnk_2170 & 0x24) != 0x24) {
                    data_ov000_021b5f50->mUnk_2170 |= 0x24;
                    b = 0;
                    if ((data_ov000_021b5f50->mUnk_2264 & 0xc0000) == 0xc0000) {
                        b = 1;
                    }
                    f = b;
                    if ((data_ov000_021b5f50->mUnk_2264 & 0x30000) == 0x30000) {
                        c = 0;
                    } else {
                        c = 1;
                    }
                    e = func_021437d8((Unk021425e8Func) func_ov000_021a5088, (u16 *) data_ov000_021b5f50->mUnk_2140, 0,
                                      c, f);
                    switch (e) {
                        case 2:
                            return;
                        case 8:
                            func_ov000_021a57fc(0xc);
                            func_ov000_021a58a4(1, data_ov000_021b5f50->mUnk_2140, a, 0x905);
                            return;
                        case 3:
                        default:
                            func_ov000_021a57fc(0xb);
                            func_ov000_021a58a4(7, data_ov000_021b5f50->mUnk_2140, a, 0x90c);
                            return;
                    }
                }
                func_ov000_021a57fc(3);
                func_ov000_021a58a4(1, data_ov000_021b5f50->mUnk_2140, a, 0x913);
                return;
            case 9:
            case 12:
                func_ov000_021a57fc(3);
                func_ov000_021a58a4(0, data_ov000_021b5f50->mUnk_2140, 1, 0x91b);
                return;
            case 10:
                func_ov000_021a57fc(3);
                func_ov000_021a58a4(0, data_ov000_021b5f50->mUnk_2140, 0, 0x922);
                return;
            case 13:
                e = func_02143e78((Unk021425e8Func) func_ov000_021a54b0);
                switch (e) {
                    case 2:
                        return;
                    case 8:
                        func_ov000_021a57fc(0xc);
                        func_ov000_021a58a4(1, 0, 0, 0x930);
                        return;
                    case 3:
                    default:
                        func_ov000_021a57fc(0xb);
                        func_ov000_021a58a4(7, 0, 0, 0x939);
                        return;
                }
            default:
                func_ov000_021a57fc(0xb);
                func_ov000_021a58a4(7, 0, data_ov000_021b5f50->mUnk_2260, 0x93f);
                return;
        }
    }
    func_ov000_021a57fc(0xb);
    func_ov000_021a58a4(7, 0, 0, 0x946);
}

void func_ov000_021a4e28(Unk021425e8 *v1) {
    s32 a;

    switch (v1->mUnk_02) {
        case 0:
            if (data_ov000_021b5f50->mUnk_2260 == 0xc) {
                func_ov000_021a57fc(0xa);
                func_ov000_021a574c();
                return;
            }
            a = func_021436d0((Unk021425e8Func) func_ov000_021a4fe0, 0);
            switch (a) {
                case 2:
                    return;
                case 8:
                    func_ov000_021a57fc(0xc);
                    func_ov000_021a58a4(1, data_ov000_021b5f50->mUnk_2140, 0, 0x8a0);
                    return;
                case 3:
                    func_ov000_021a57fc(0xa);
                    func_ov000_021a574c();
                    return;
                default:
                    func_ov000_021a57fc(0xb);
                    func_ov000_021a58a4(7, data_ov000_021b5f50->mUnk_2140, 0, 0x8ac);
                    return;
            }
        case 1:
        case 3:
            func_ov000_021a57fc(0xa);
            func_ov000_021a574c();
            return;
        case 2:
        case 4:
        default:
            func_ov000_021a57fc(0xb);
            func_ov000_021a58a4(7, data_ov000_021b5f50->mUnk_2140, 0, 0x8bf);
            return;
    }
}

void func_ov000_021a4f10(Unk021425e8 *v1) {
    switch (v1->mUnk_02) {
        case 0:
            switch (v1->mUnk_04) {
                case 0xe:
                    if (data_ov000_021b5f50->mUnk_2260 == 0xc) {
                        func_ov000_021a57fc(8);
                        func_ov000_021a574c();
                        return;
                    }
                    func_ov000_021a57fc(9);
                    func_ov000_021a58a4(0, data_ov000_021b5f50->mUnk_2140, 0, 0x85d);
                    return;
                case 0xf:
                    func_ov000_021a6c08(((u16 *) v1->mUnk_08)[7] >> 8);
                    func_0200ee3c(v1->mUnk_08, 0x620);
                    func_ov000_021a6bb4(v1->mUnk_08);
                    return;
                default:
                    func_ov000_021a57fc(0xb);
                    func_ov000_021a58a4(7, data_ov000_021b5f50->mUnk_2140, v1->mUnk_04, 0x86b);
                    return;
            }
        case 4:
        default:
            func_ov000_021a57fc(0xb);
            func_ov000_021a58a4(7, data_ov000_021b5f50->mUnk_2140, 0, 0x877);
            return;
    }
}

void func_ov000_021a4fe0(Unk021425e8 *v1) {
    switch (v1->mUnk_02) {
        case 0:
            if (data_ov000_021b5f50->mUnk_2260 == 0xc) {
                func_ov000_021a57fc(0xa);
                func_ov000_021a574c();
                return;
            }
            data_ov000_021b5f50->mUnk_2282 = 0;
            func_ov000_021a57fc(3);
            func_ov000_021a58a4(0, data_ov000_021b5f50->mUnk_2140, 0, 0x827);
            return;
        case 1:
        case 3:
            func_ov000_021a57fc(0xa);
            func_ov000_021a574c();
            return;
        case 2:
        case 4:
        default:
            func_ov000_021a57fc(0xb);
            func_ov000_021a58a4(7, data_ov000_021b5f50->mUnk_2140, 0, 0x839);
            return;
    }
}

void func_ov000_021a5088(Unk021a5088 *v1) {
    u16 a;
    s32 b;

    switch (v1->mUnk_02) {
        case 0:
            switch (v1->mUnk_08) {
                case 8:
                case 9:
                    switch (data_ov000_021b5f50->mUnk_2260 - 8) {
                        case 2:
                            data_ov000_021b5f50->mUnk_2282 = 0;
                        case 0:
                            func_ov000_021a57fc(0xc);
                            return;
                        case 1:
                            data_ov000_021b5f50->mUnk_2282 = 0;
                            data_ov000_021b5f50->mUnk_2280 = 6;
                        case 4:
                            func_ov000_021a574c();
                            return;
                        default:
                            break;
                    }
                    break;
                case 7:
                    if (data_ov000_021b5f50->mUnk_2260 == 0xc) {
                        func_ov000_021a57fc(8);
                        func_ov000_021a574c();
                        return;
                    }
                    a = v1->mUnk_0a;
                    if (a >= 1 && a <= 0x7d7) {
                        data_ov000_021b5f50->mUnk_2282 = a;
                        b = func_02144514((Unk021425e8Func) func_ov000_021a4f10,
                                          &data_ov000_021b5f50->mUnk_0000[0x1500], 0x620);
                        switch (b) {
                            case 2:
                                return;
                            case 8:
                                func_ov000_021a57fc(0xc);
                                func_ov000_021a58a4(1, data_ov000_021b5f50->mUnk_2140, 0, 0x7d7);
                                return;
                            case 3:
                            default:
                                func_ov000_021a57fc(0xb);
                                func_ov000_021a58a4(7, data_ov000_021b5f50->mUnk_2140, 0, 0x7e0);
                                return;
                        }
                    }
                    func_ov000_021a574c();
                    return;
                case 6:
                    break;
                default:
                    func_ov000_021a57fc(0xb);
                    func_ov000_021a58a4(7, data_ov000_021b5f50->mUnk_2140, v1->mUnk_08, 0x7ee);
                    return;
            }
            break;
        case 1:
            data_ov000_021b5f50->mUnk_22f8 = v1->mUnk_0e;
        case 6:
        case 11:
        case 12:
            func_ov000_021a57fc(8);
            func_ov000_021a574c();
            return;
        case 2:
        case 3:
        case 4:
        case 5:
        case 7:
        case 8:
        case 9:
        case 10:
        default:
            func_ov000_021a57fc(0xb);
            func_ov000_021a58a4(7, data_ov000_021b5f50->mUnk_2140, 0, 0x804);
            return;
    }
}

void func_ov000_021a524c(Unk021425e8 *v1) {
    switch (v1->mUnk_02) {
        case 0:
            func_ov000_021a57fc(3);
            func_ov000_021a58a4(0, 0, 0, 0x774);
            return;
        case 1:
            func_ov000_021a574c();
            return;
        case 2:
        case 3:
        case 4:
        default:
            func_ov000_021a57fc(0xb);
            func_ov000_021a58a4(7, 0, 0, 0x784);
            return;
    }
}

void func_ov000_021a52b0(Unk021a5088 *v1) {
    s32 a;
    s32 b;
    u32 c;
    u32 d;
    u32 e;

    a = 0x14;
    switch (v1->mUnk_02) {
        case 0:
            if (data_ov000_021b5f50->mUnk_2260 == 5) {
                func_ov000_021a57fc(6);
                func_ov000_021a58a4(0, 0, 0, 0x6f6);
            }
            switch (data_ov000_021b5f50->mUnk_2260) {
                case 6:
                    data_ov000_021b5f50->mUnk_2280 = 7;
                    if (v1->mUnk_08 == 5) {
                        func_0200ee3c(data_ov000_021b5f50->mUnk_2288.mUnk_00, data_ov000_021b5f50->mUnk_2288.mUnk_04);
                        for (b = 0; b < v1->mUnk_0e; b++) {
                            func_ov000_021a671c((Unk021a5e84 *) v1->mUnk_10[b], v1->mUnk_50[b]);
                            func_ov000_021a586c(7, 0, v1->mUnk_10[b], (u32) v1, 0x70b);
                        }
                    }
                    c = data_ov000_021b5f50->mUnk_2264;
                    if ((c & 0xc00000) == 0xc00000) {
                        d = func_ov000_021a4b98(c & 0x3ffe);
                        if (d != 0) {
                            e = data_ov000_021b5f50->mUnk_2284;
                            if (e % d == 0) {
                                func_ov000_021a586c(8, 0, (void *) e, 0, 0x718);
                            }
                        }
                    }
                    data_ov000_021b5f50->mUnk_2288.mUnk_06 =
                        (1 << func_ov000_021a58dc(32 - func_ov000_021a4bbc(v1->mUnk_0a))) >> 1;
                    func_0200ee3c(data_ov000_021b5f50->mUnk_2288.mUnk_00, data_ov000_021b5f50->mUnk_2288.mUnk_04);
                    data_ov000_021b5f50->mUnk_2284++;
                    a = func_021438f0((Unk021425e8Func) func_ov000_021a52b0, &data_ov000_021b5f50->mUnk_2288);
                    break;
                case 7:
                    a = func_021438a8((Unk021425e8Func) func_ov000_021a524c);
                    break;
                case 13:
                    func_ov000_021a574c();
                    return;
            }
            switch (a) {
                case 2:
                    return;
                case 8:
                    func_ov000_021a57fc(0xc);
                    func_ov000_021a58a4(1, 0, 0, 0x743);
                    return;
                case 3:
                default:
                    func_ov000_021a57fc(0xb);
                    func_ov000_021a58a4(7, 0, 0, 0x74c);
                    return;
            }
        case 1:
            func_ov000_021a574c();
            return;
        case 2:
        case 3:
        case 4:
        default:
            func_ov000_021a57fc(0xb);
            func_ov000_021a58a4(7, 0, 0, 0x75d);
            return;
    }
}
