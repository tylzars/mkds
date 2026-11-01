#include "00/code_021806a0.h"

s32 func_ov000_021806d4(void) {
    return ((u32) *
            (const u32 *) ((u8 *) (u32) (((u32) * (const u32 *) ((u8 *) (u32) (((u32) (&data_ov000_021b4c64))) + 0))) +
                           16));
}

u32 func_ov000_021806c4(void) {
    return ((u32) * (const short *) ((u8 *) (u32) ((
                                         (u32) * (const u32 *) ((u8 *) (u32) (((u32) (&data_ov000_021b4c64))) + 0))) +
                                     0 + (0x18u)));
}

void func_ov000_021806b8(u32 p0) {
    *(u16 *) ((u8 *) (u32) (((u32) * (const u32 *) ((u8 *) (u32) (((u32) (&data_ov000_021b4c64))) + 0))) + 24) =
        (u16) p0;
}

u32 func_ov000_021806a0(void) {
    if (0 <= data_ov000_021b4c64->mUnk_14) {
        return 1;
    }
    return 0;
}
