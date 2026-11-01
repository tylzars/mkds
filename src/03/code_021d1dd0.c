#include "03/code_021d1dd0.h"
#include "03/code_021d1da8.h"
#include "03/code_021d34c8.h"
#include "03/code_021d3544.h"
#include "code_02147cd8.h"
#include "code_0214a348.h"
#include "code_0214a390.h"

u32 func_ov003_021d1ee0(s32 param_1, s32 param_2, u32 param_3, u16 param_4) {
    s8 a[4] = {-0x10, 0x00, 0x10, 0x00};
    Unk021d1da8 *b;

    if (param_2 == 1) {
        b = data_ov003_021da2c0;
    } else {
        b = data_ov003_021da2c0 + 1;
    }
    if (b->mEnabled != 0) {
        return 0;
    }
    if (param_2 == 1) {
        func_0214a3e8((u16 *) 0x4001050, param_3, a[param_1]);
    } else {
        func_0214a3e8((u16 *) 0x4000050, param_3, a[param_1]);
    }
    b->mUnk_00 = func_ov003_021d3544(1, func_ov003_021d1e14, b, 200);
    b->mFrames = 0;
    b->mUnk_08 = param_1;
    b->mFrameCount = param_4;
    b->mEnabled = 1;
    return 1;
}

void func_ov003_021d1e14(u32 param_1, Unk021d1da8 *param_2) {
    u8 a[4] = {0x11, 0x10, 0x01, 0x00};
    s8 b[4] = {0x00, -0x10, 0x00, 0x10};
    s32 c;
    u8 d;

    param_2->mFrames++;
    c = func_02147d30(param_2->mFrames << 4, param_2->mFrameCount);
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
