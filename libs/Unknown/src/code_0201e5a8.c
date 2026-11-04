#include "code_0200cd1c.h"
#include "code_0200fc8c.h"
#include "code_0201e5a8.h"
#include "Main/Unknown/unk_02173000.h"
#include "code_0214d5b8.h"
#include "code_0200fe74.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/code_0200c000.h"

s32 func_0201e7a8(u32 a, UnkFunc *b, u32 c) {
    u32 v;

    PxiInit();
    if (PxiCallbackBitIsSet(0xf, 1) == 0) {
        return 2;
    }
    if (data_02173278 == 0) {
        do {
            s32 n = IdAlloc();

            if (n == -3) {
                return 7;
            }
            data_02173278 = n;
        } while (data_02173278 == 0);
    }
    v = IrqDisable();
    if (data_02173284 != 0) {
        IrqRestore(v);
        return 5;
    }
    if (data_0217327c != 0) {
        IrqRestore(v);
        return 5;
    }
    switch (a) {
        case 4:
            if (func_0200ff04(4, data_02173278) == 0) {
                IrqRestore(v);
                return 6;
            }
            data_0217327c = 4;
            *(vu8 *) 0x4000242 = 0x82;
            break;
        case 8:
            if (func_0200ff04(8, data_02173278) == 0) {
                IrqRestore(v);
                return 6;
            }
            data_0217327c = 8;
            *(vu8 *) 0x4000243 = 0x82;
            break;
        case 12:
            if (func_0200ff04(12, data_02173278) == 0) {
                IrqRestore(v);
                return 6;
            }
            data_0217327c = 12;
            *(vu8 *) 0x4000242 = 0x82;
            *(vu8 *) 0x4000243 = 0x8a;
            break;
        default:
            IrqRestore(v);
            return 3;
    }
    if (PxiCallbackBitIsSet(0xf, 0) == 0) {
        PxiCallbackSet(0xf, func_0201e5ac);
    }
    if (b == 0) {
        data_02173284 = func_0201e5a8;
    } else {
        data_02173284 = b;
    }
    data_02173280 = c;
    if (PxiSendFifoWord(0xf, 0x10000, 0) < 0) {
        func_0200fe7c(data_0217327c, data_02173278);
        data_0217327c = 0;
        data_02173284 = 0;
        IrqRestore(v);
        return 4;
    }
    IrqRestore(v);
    return 1;
}

s32 func_0201e6b8(UnkFunc *a, u32 b) {
    u32 v;

    PxiInit();
    if (PxiCallbackBitIsSet(0xf, 1) == 0) {
        return 2;
    }
    v = IrqDisable();
    if (data_02173284 != 0) {
        IrqRestore(v);
        return 5;
    }
    if (PxiCallbackBitIsSet(0xf, 0) == 0) {
        PxiCallbackSet(0xf, func_0201e5ac);
    }
    if (a == 0) {
        data_02173284 = func_0201e5a8;
    } else {
        data_02173284 = a;
    }
    data_02173280 = b;
    if (PxiSendFifoWord(0xf, 0x20000, 0) < 0) {
        data_02173284 = 0;
        IrqRestore(v);
        return 4;
    }
    IrqRestore(v);
    return 1;
}

void func_0201e5ac(u32 a, u32 b) {
    UnkFunc *f;
    u32 arg;
    u32 t;
    u32 k;

    t = b & 0xffff0000;
    k = b & 0xff;
    f = data_02173284;
    arg = data_02173280;
    switch (t) {
        case 0x10000:
            if (k == 7 && data_0217327c != 0 && data_02173278 != 0) {
                func_0200fe7c(data_0217327c, data_02173278);
                data_0217327c = 0;
            }
            break;
        case 0x20000:
            if (k == 0 && data_0217327c != 0 && data_02173278 != 0) {
                func_0200fe7c(data_0217327c, data_02173278);
                data_0217327c = 0;
            }
            PxiCallbackSet(0xf, 0);
            break;
    }
    if (f != 0) {
        data_02173284 = 0;
        data_02173280 = 0;
        f(arg, k);
    }
}

void func_0201e5a8(void) {}
