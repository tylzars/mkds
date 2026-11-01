#include "00/code_0219b704.h"
#include "00/code_0219b8a8.h"
#include "00/code_0219c000.h"
#include "00/code_021a01dc.h"

u32 func_ov000_0219b704(u32 a) {
    s32 b;
    s32 c;

    if (a == 0) {
        return 0;
    }
    switch (a) {
        case 1:
            b = 0xb;
            c = -1;
            break;
        case 2:
        case 5:
            b = 0;
            c = 0;
            a = 0;
            break;
        case 3:
            b = 6;
            c = -10;
            break;
        case 4:
            b = 6;
            c = -30;
            break;
        case 6:
            b = 6;
            c = -70;
            break;
        case 7:
            b = 6;
            c = -80;
            break;
    }
    if (b != 0) {
        func_ov000_0219c990(b, c - 0x105b8);
    }
    return a;
}

int func_ov000_0219b77c(int param_1) {
    s32 a;
    s32 b;

    if (param_1 == 0) {
        return 0;
    }
    switch (param_1) {
        case 1:
            a = 0xb;
            b = -1;
            break;
        case 2:
            a = 0xb;
            b = -2;
            break;
        case 3:
            a = 6;
            b = -10;
            break;
        case 4:
            a = 6;
            b = -20;
            break;
    }
    switch (data_ov000_021b54c8->mUnk_24) {
        case 1:
            b -= 0xee48;
            func_ov000_0219c990(a, b);
            break;
        case 2:
            b -= 0xee48;
            func_ov000_0219c990(a, b);
            break;
        case 5:
            b -= 0x13c68;
            func_ov000_021a1a38(a, b);
            break;
        case 4:
            b -= 0x11558;
            break;
        default:
            b -= 0x16378;
            break;
    }
    func_ov000_0219d734(a, b);
    return param_1;
}
