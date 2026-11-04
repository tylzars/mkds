#include "00/code_021ae984.h"
#include "00/code_021aefa8.h"
#include "00/code_021a9228.h"
#include "00/code_021ae0c4.h"
#include "00/code_021ae314.h"
#include "00/code_021af550.h"
#include "code_02133048.h"
#include "code_0200db4c.h"
#include "code_0200f5ac.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"

void func_ov000_021ae984(Unk021ae3f0 *param_1, Unk021ae87c *param_2, u32 param_3) {
    Unk021a998c *a;

    a = func_ov000_021af090(param_1, param_2);
    if (a == NULL) {
        return;
    }
    switch (a->mState) {
        case 7:
            a->mUnk_24++;
            func_ov000_021aefb4(a, (u16) ((param_1->mUnk_05 << 8) + 0x13));
            a->mState = 9;
            return;
        case 8:
            a->mUnk_24++;
            func_ov000_021aefb4(a, (u16) ((param_1->mUnk_05 << 8) + 0x14));
            a->mState = 0;
            if (a->mUnk_04 == 2) {
                a->mUnk_04 = 0;
                func_0200df68(a->mThread);
                return;
            }
            return;
        case 4:
            a->mUnk_24++;
            func_ov000_021aefa8(a, (u16) ((param_1->mUnk_05 << 8) + 0x15));
            a->mState = 6;
            return;
        default:
            func_ov000_021aeed8(param_1, param_2, param_3, (param_1->mUnk_05 << 8) + 0x16);
            return;
    }
}

void func_ov000_021aea34(Unk021ae3f0 *param_1, Unk021ae87c *param_2, u32 param_3) {
    Unk021a998c *a;
    u32 b;
    u32 c;
    s32 d;
    s32 e;
    u32 f;
    u32 g;

    a = func_ov000_021af090(param_1, param_2);
    if (a == NULL) {
        func_ov000_021aeed8(param_1, param_2, param_3, (param_1->mUnk_05 << 8) + 9);
        return;
    }
    b = param_2->mUnk_0d;
    d = param_2->mUnk_0a;
    a->mUnk_30 =
        (u32) (((u16) ((param_2->mUnk_08 >> 8) | (param_2->mUnk_08 << 8)) << 16) | (u16) ((d >> 8) | (d << 8)));
    e = param_2->mUnk_06;
    c = (u32) (((u16) ((param_2->mUnk_04 >> 8) | (param_2->mUnk_04 << 8)) << 16) | (u16) ((e >> 8) | (e << 8)));
    if (a->mState == 4 && a->mUnk_24 != c) {
        func_ov000_021aefb4(a, (u16) ((param_1->mUnk_05 << 8) + 0xa));
        return;
    }
    a->mUnk_2c = (u16) ((param_2->mUnk_0e >> 8) | (param_2->mUnk_0e << 8));
    switch (a->mState) {
        case 0:
        case 2:
            func_ov000_021aeed8(param_1, param_2, param_3, (param_1->mUnk_05 << 8) + 0x63);
            break;
        case 3:
            a->mState = 4;
            if (a->mUnk_04 == 1) {
                a->mUnk_04 = 0;
                func_0200df68(a->mThread);
            }
            if (param_3 == 0) {
                break;
            }
        case 4:
            a->mUnk_34++;
            f = a->mReceiveBufferSize - a->mReceiveBufferLength;
            if (param_3 > f) {
                param_3 = f;
                c = 0;
            } else {
                c = 1;
            }
            if (param_3 != 0) {
                g = IrqDisable();
                MemCopy((u8 *) param_2 + (param_2->mUnk_0c & 0xf0) / 4,
                        (u8 *) a->mReceiveBuffer + a->mReceiveBufferLength, param_3);
                a->mReceiveBufferLength += param_3;
                a->mUnk_24 += param_3;
                IrqRestore(g);
                if (a->mUnk_04 == 2) {
                    a->mUnk_04 = 0;
                    func_0200df68(a->mThread);
                }
            }
            if (c != 0 && (b & 1) != 0) {
                a->mState = 6;
                a->mUnk_24++;
                func_ov000_021aefa8(a, (u16) ((param_1->mUnk_05 << 8) + 0xb));
                if (param_3 == 0 && a->mUnk_04 == 2) {
                    a->mUnk_04 = 0;
                    func_0200df68(a->mThread);
                }
                break;
            }
            if (param_3 != 0) {
                func_ov000_021aefb4(a, (u16) ((param_1->mUnk_05 << 8) + 0xc));
            }
            break;
        case 7:
        case 8:
            if ((b & 1) != 0) {
                a->mUnk_24 = a->mUnk_24 + (param_3 + 1);
                func_ov000_021aefb4(a, (u16) ((param_1->mUnk_05 << 8) + 0xd));
                a->mState = 0;
                if (a->mUnk_04 == 2) {
                    a->mUnk_04 = 0;
                    func_0200df68(a->mThread);
                }
                break;
            }
            if (param_3 != 0) {
                a->mUnk_24 += param_3;
                func_ov000_021aefb4(a, (u16) ((param_1->mUnk_05 << 8) + 0xe));
            }
            a->mState = 8;
            break;
        case 6:
        case 9:
            a->mState = 0;
            if (a->mUnk_04 == 2) {
                a->mUnk_04 = 0;
                func_0200df68(a->mThread);
            }
            break;
        default:
            if ((b & 1) != 0) {
                a->mUnk_24++;
            }
            func_ov000_021aefb4(a, (u16) ((param_1->mUnk_05 << 8) + 0x12));
            break;
    }
    func_0200dd94();
}

void func_ov000_021aec84(Unk021ae3f0 *param_1, Unk021ae87c *param_2, u32 param_3) {
    Unk021a998c *a;

    a = func_ov000_021af090(param_1, param_2);
    if (a == NULL || a->mState != 2) {
        func_ov000_021aeed8(param_1, param_2, param_3, (param_1->mUnk_05 << 8) + 5);
        return;
    }
    func_0200dd94();
    a->mUnk_24 = (u32) (((u16) ((param_2->mUnk_04 >> 8) | (param_2->mUnk_04 << 8)) << 16) |
                        (u16) ((param_2->mUnk_06 >> 8) | (param_2->mUnk_06 << 8))) +
                 1;
    a->mUnk_30 = (u32) (((u16) ((param_2->mUnk_08 >> 8) | (param_2->mUnk_08 << 8)) << 16) |
                        (u16) ((param_2->mUnk_0a >> 8) | (param_2->mUnk_0a << 8)));
    a->mUnk_2c = (u16) ((param_2->mUnk_0e >> 8) | (param_2->mUnk_0e << 8));
    func_ov000_021af030(param_2, a);
    func_ov000_021aefb4(a, (u16) ((param_1->mUnk_05 << 8) + 6));
    a->mState = 4;
    if (a->mUnk_04 == 1) {
        a->mUnk_04 = 0;
        func_0200df68(a->mThread);
    }
}

void func_ov000_021aed3c(Unk021ae3f0 *param_1, Unk021ae87c *param_2, u32 param_3) {
    Unk021a998c *a;

    if (func_ov000_021af284((u32) (((u16) ((param_1->mUnk_0c >> 8) | (param_1->mUnk_0c << 8)) << 16) |
                                   (u16) ((param_1->mUnk_0e >> 8) | (param_1->mUnk_0e << 8))),
                            (u32) (((u16) ((param_1->mUnk_10 >> 8) | (param_1->mUnk_10 << 8)) << 16) |
                                   (u16) ((param_1->mUnk_12 >> 8) | (param_1->mUnk_12 << 8)))) != 0) {
        if (func_ov000_021aedd8(param_1, param_2, param_3) == 0) {
            a = func_ov000_021af15c(param_1, param_2);
            if (a != NULL) {
                func_ov000_021aee38(param_1, param_2, a);
                return;
            }
            func_0200dd94();
            a = func_ov000_021af15c(param_1, param_2);
            if (a != NULL) {
                func_ov000_021aee38(param_1, param_2, a);
            }
        }
    }
}

u32 func_ov000_021aedd8(Unk021ae3f0 *param_1, Unk021ae87c *param_2, u32 param_3) {
    Unk021a998c *a;

    a = func_ov000_021af090(param_1, param_2);
    if (a != NULL) {
        if (a->mState == 1) {
            func_ov000_021aee38(param_1, param_2, a);
        } else if (a->mState == 3 || a->mState == 4) {
            a->mUnk_28--;
            func_ov000_021aee38(param_1, param_2, a);
        } else {
            func_ov000_021aeed8(param_1, param_2, param_3, (param_1->mUnk_05 << 8) + 3);
        }
        return 1;
    }
    return 0;
}

void func_ov000_021aee38(Unk021ae3f0 *param_1, Unk021ae87c *param_2, Unk021a998c *param_3) {
    param_3->mState = 3;
    param_3->mStateStartTime = func_0200f5ac() >> 16;
    param_3->mUnk_14 = (u32) (((u16) ((param_1->mUnk_10 >> 8) | (param_1->mUnk_10 << 8)) << 16) |
                              (u16) ((param_1->mUnk_12 >> 8) | (param_1->mUnk_12 << 8)));
    param_3->mUnk_18 = (u16) ((param_2->mUnk_00 >> 8) | (param_2->mUnk_00 << 8));
    param_3->mUnk_1c = (u32) (((u16) ((param_1->mUnk_0c >> 8) | (param_1->mUnk_0c << 8)) << 16) |
                              (u16) ((param_1->mUnk_0e >> 8) | (param_1->mUnk_0e << 8)));
    param_3->mUnk_24 = (u32) (((u16) ((param_2->mUnk_04 >> 8) | (param_2->mUnk_04 << 8)) << 16) |
                              (u16) ((param_2->mUnk_06 >> 8) | (param_2->mUnk_06 << 8))) +
                       1;
    func_ov000_021af030(param_2, param_3);
    func_ov000_021aefc0(param_3, 0x12, (u16) ((param_1->mUnk_05 << 8) + 1));
}

void func_ov000_021aeed8(Unk021ae3f0 *param_1, Unk021ae87c *param_2, u32 param_3, u16 param_4) {
    Unk021a998c *p;

    p = &data_ov000_021b64f8;
    MemFill(p, 0, 0x64);
    p->mUnk_0a = (u16) ((param_2->mUnk_02 >> 8) | (param_2->mUnk_02 << 8));
    p->mUnk_18 = (u16) ((param_2->mUnk_00 >> 8) | (param_2->mUnk_00 << 8));
    p->mUnk_1c = (u32) (((u16) ((param_1->mUnk_0c >> 8) | (param_1->mUnk_0c << 8)) << 16) |
                        (u16) ((param_1->mUnk_0e >> 8) | (param_1->mUnk_0e << 8)));
    if ((param_2->mUnk_0d & 0x10) != 0) {
        p->mUnk_28 = (u32) (((u16) ((param_2->mUnk_08 >> 8) | (param_2->mUnk_08 << 8)) << 16) |
                            (u16) ((param_2->mUnk_0a >> 8) | (param_2->mUnk_0a << 8)));
        func_ov000_021aefc0(p, 4, param_4);
        return;
    }
    p->mUnk_28 = 0;
    p->mUnk_24 = param_3 + (u32) (((u16) ((param_2->mUnk_04 >> 8) | (param_2->mUnk_04 << 8)) << 16) |
                                  (u16) ((param_2->mUnk_06 >> 8) | (param_2->mUnk_06 << 8)));
    if ((param_2->mUnk_0d & 3) != 0) {
        p->mUnk_24++;
    }
    func_ov000_021aefc0(p, 0x14, param_4);
}
