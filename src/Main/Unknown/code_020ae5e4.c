#include "Main/Unknown/code_020ae5e4.h"
#include "code_0200eddc.h"
#include "code_0214b824.h"

#pragma thumb on

void func_020ae5f0(void *a, void *b) {
    if (a != NULL) {
        func_0200ee74(a, 0x00000400u);
        GX_LoadOAM(a, 0, (u32) 0x00000400u);
    }
    if (b != NULL) {
        func_0200ee74(b, 0x00000400u);
        GXS_LoadOAM(b, 0, (u32) 0x00000400u);
    }
}

u16 func_020ae5e4(const void *p0) {
    return ((u32) * (const u16 *) ((u8 *) p0 + 0 + (0x402u)));
}

#pragma thumb off
