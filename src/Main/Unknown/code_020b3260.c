#include "Main/Unknown/code_020b3260.h"

#pragma thumb on

u32 func_020b3260(int a) {
    if (a < 0) {
        return 0;
    }
    if (a < 2) {
        return 0x1000;
    }
    return a << 0xb;
}

#pragma thumb off
