#include "00/code_021a8c94.h"
#include "00/code_021a8db8.h"
#include "00/code_021a8d98.h"
#include "00/code_021a6d6c.h"

s32 func_ov000_021a8c94(void *param_1) {
    Unk021a8c94 *a = param_1;
    data_ov000_021b6040.mUnk_00 = a->mUnk_0c == 1 ? 1 : 0;
    data_ov000_021b6040.mUnk_04 =
        ((a->mUnk_10 << 24) & 0xff000000) |
        (((a->mUnk_10 << 8) & 0xff0000) | (((a->mUnk_10 >> 24) & 0xff) | ((a->mUnk_10 >> 8) & 0xff00)));
    data_ov000_021b6040.mUnk_08 =
        ((a->mUnk_14 << 24) & 0xff000000) |
        (((a->mUnk_14 << 8) & 0xff0000) | (((a->mUnk_14 >> 24) & 0xff) | ((a->mUnk_14 >> 8) & 0xff00)));
    data_ov000_021b6040.mUnk_0c =
        ((a->mUnk_18 << 24) & 0xff000000) |
        (((a->mUnk_18 << 8) & 0xff0000) | (((a->mUnk_18 >> 24) & 0xff) | ((a->mUnk_18 >> 8) & 0xff00)));
    data_ov000_021b6040.mUnk_10 =
        ((a->mUnk_1c << 24) & 0xff000000) |
        (((a->mUnk_1c << 8) & 0xff0000) | (((a->mUnk_1c >> 24) & 0xff) | ((a->mUnk_1c >> 8) & 0xff00)));
    data_ov000_021b6040.mUnk_14 =
        ((a->mUnk_20 << 24) & 0xff000000) |
        (((a->mUnk_20 << 8) & 0xff0000) | (((a->mUnk_20 >> 24) & 0xff) | ((a->mUnk_20 >> 8) & 0xff00)));
    data_ov000_021b6040.mUnk_18 = func_ov000_021a8db8;
    data_ov000_021b6040.mUnk_1c = (void (*)(void *)) func_ov000_021a8d98;
    data_ov000_021b6014 = a->mUnk_04;
    *(void **) data_ov000_021b6010 = a->mUnk_08;
    data_ov000_021b6040.mUnk_20 = 0x40;
    data_ov000_021b6040.mUnk_30 = a->mUnk_2c;
    data_ov000_021b6040.mUnk_34 = a->mUnk_30;
    return func_ov000_021a6ee4(&data_ov000_021b6040);
}
