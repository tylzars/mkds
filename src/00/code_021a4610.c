#include "00/code_021a4610.h"

void func_ov000_021a4648(u8 *a, u8 *b) {
    u8 v1;
    v1 = *a;
    *a = *b;
    *b = v1;
}

u8 func_ov000_021a4610(u32 a) {
    if (a < 0x1a) {
        return a + 0x41 & 0xff;
    }
    if (a < 0x34) {
        return a + 0x47 & 0xff;
    }
    if (a < 0x3e) {
        return a - 4 & 0xff;
    }
    if (a == 0x3e) {
        return 0x2b;
    }
    if (a == 0x3f) {
        return 0x2f;
    }
    return 0;
}
