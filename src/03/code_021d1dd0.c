#include "03/code_021d1dd0.h"
#include "03/code_021d1da8.h"
#include "03/code_021d3488.h"
#include "code_02147cd8.h"
#include "code_0214a348.h"
#include "code_0214a390.h"

// placeholder: two objects of the original file that are not known yet; they only set the order of the tables below
u8 data_ov003_021d1e14_pad1[1];
u8 data_ov003_021d1e14_pad2[8];

void func_ov003_021d1e14(u32 param_1, Unk021d1da8 *param_2) {
    u8 a[4] = {0x11, 0x10, 0x01, 0x00};
    s8 b[4] = {0x00, -0x10, 0x00, 0x10};
    s32 c;
    u8 d;

    param_2->mFrames++;
    c = FX_DivS32(param_2->mFrames << 4, param_2->mFrameCount);
    d = a[param_2->mUnk_08];
    if (d & 1) {
        c = 0x10 - c;
    }
    if (d & 0x10) {
        c = -c;
    }
    if (param_2 == data_ov003_021da2c0) {
        func_0214a348((u16 *) 0x4001050, c);
    } else {
        func_0214a348((u16 *) 0x4000050, c);
    }
    if (param_2->mFrames >= param_2->mFrameCount) {
        if (param_2 == data_ov003_021da2c0) {
            func_0214a348((u16 *) 0x4001050, b[param_2->mUnk_08]);
        } else {
            func_0214a348((u16 *) 0x4000050, b[param_2->mUnk_08]);
        }
        param_2->mEnabled = 0;
        func_ov003_021d34c8(1, param_1);
    }
}

u32 func_ov003_021d1dd0(u16 param_1) {
    Unk021d1da8 *a = data_ov003_021da2c0;

    if (a->mEnabled != 0) {
        return 0;
    }
    a->mUnk_00 = func_ov003_021d3544(1, func_ov003_021d1da8, a, 200);
    a->mFrames = 0;
    a->mFrameCount = param_1;
    a->mEnabled = 1;
    return 1;
}
