#include "01/code_02181124.h"

u32 func_ov001_021811bc(void) {
    return ((u32) *(const u32 *) ((u8 *) (u32) (((u32) *(
                                                        const u32 *) ((u8 *) (u32) ((
                                                                                   (u32) (&data_ov001_021a9b88))) +
                                                                               0))) +
                                                    28));
}

u32 func_ov001_021811b8(void) {
    return 0x0u;
}

int func_ov001_02181198(void) {
    int v1;
    v1 = _s32_div_f((u32) data_ov001_021a9b88->mUnk_04, 8);
    return v1 * v1;
}

u32 func_ov001_02181194(void) {
    return 0x0u;
}

u32 func_ov001_02181180(void) {
    return (
        (((((u32) *(const u32 *) ((u8 *) (u32) (((u32) *(
                                                        const u32 *) ((u8 *) (u32) ((
                                                                                   (u32) (&data_ov001_021a9b88))) +
                                                                               0))) +
                                                    0))) *
          (((((u32) *(const u32 *) ((u8 *) (u32) (((u32) *(
                                                          const u32 *) ((u8 *) (u32) ((
                                                                                     (u32) (&data_ov001_021a9b88))) +
                                                                                 0))) +
                                                      0))) +
            (0x0u))))) +
        (0x40u));
}

u32 func_ov001_02181174(void) {
    return ((u32) *(const u32 *) ((u8 *) (u32) (((u32) *(
                                                        const u32 *) ((u8 *) (u32) ((
                                                                                   (u32) (&data_ov001_021a9b88))) +
                                                                               0))) +
                                                    32));
}

u32 func_ov001_02181124(u8 *a) {
    int i;
    u32 ret;

    ret = 0;
    for (i = 0; i < data_ov001_021a9b88->mUnk_00 * data_ov001_021a9b88->mUnk_00; i++) {
        if (data_ov001_021a9b88->mUnk_20[i] != a[i]) {
            ret = 1;
            func_ov001_021811c8();
            data_ov001_021a9b88->mUnk_20[i] = a[i];
        }
    }
    return ret;
}
