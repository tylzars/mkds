#include "Main/Unknown/code_020ae5e4.h"

#pragma thumb on

void func_020ae5f0(void *a, void *b) {
    if (a != 0) {
        func_0200ee74((a), (int) 0x00000400u);
        func_0214bfcc((const void *) a, 0, (u32) 0x00000400u);
    }
    if (b != 0) {
        func_0200ee74((b), (int) 0x00000400u);
        func_0214bf64((const void *) b, 0, (u32) 0x00000400u);
    }
}

u16 func_020ae5e4(u32 p0) {
    return ((u32) * (const u16 *) ((u8 *) p0 + 0 + (0x402u)));
}

#pragma thumb off
