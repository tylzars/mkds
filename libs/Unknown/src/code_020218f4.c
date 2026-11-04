#include "code_020218f4.h"
#include "code_02020e3c.h"
#include "Main/Unknown/unk_02152000.h"

void *func_02021968(Unk02021968 *a, u32 b) {
    u32 v;
    u8 *p;

    SharedLockWait();
    v = a->mUnk_3c[b];
    if (v != 0) {
        p = (u8 *) v;
        if (v < 0x2000000) {
            p = (u8 *) a + v;
        }
    } else {
        p = 0;
    }
    SharedLockUnlock();
    return p;
}

u16 func_020218f4(s32 a) {
    u8 t;
    s32 k;

    if (a < -0x2d3) {
        a = -0x2d3;
    } else if (a > 0) {
        a = 0;
    }
    t = data_02152de4[a + 0x2d3];
    if (a < -0xf0) {
        k = 3;
    } else if (a < -0x78) {
        k = 2;
    } else if (a < -0x3c) {
        k = 1;
    } else {
        k = 0;
    }
    return t | (k << 8);
}
