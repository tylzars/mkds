#include "Main/Unknown/code_0202edfc.h"

#pragma thumb on

u32 func_0202ee20(u32 p0, u32 p1) {
    return ((((u32) *
              (const short *) ((u8 *) (u32) ((
                                   (((u32) *
                                     (const u32 *) ((u8 *) (u32) ((
                                                        (u32) *
                                                        (const u32 *) ((u8 *) (u32) (((u32) (&data_02174e48))) + 0))) +
                                                    8))) +
                                   (((p1) << 6)))) +
                               0 + (0xeu)))) -
            (((u32) *
              (const short *) ((u8 *) (u32) ((
                                   (((u32) *
                                     (const u32 *) ((u8 *) (u32) ((
                                                        (u32) *
                                                        (const u32 *) ((u8 *) (u32) (((u32) (&data_02174e48))) + 0))) +
                                                    8))) +
                                   (((p0) << 6)))) +
                               0 + (0xeu)))));
}

u32 func_0202edfc(void) {
    u32 v1;
    v1 = (data_02174e48->mUnk_03c + data_02174e48->mUnk_044 + 1) % (7);
    return v1;
}

#pragma thumb off
