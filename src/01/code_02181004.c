#include "01/code_02181004.h"

u32 func_ov001_02181020(u32 param_1, u32 param_2, u32 param_3) {
    u8 *v1;
    u32 v2;
    v2 = 0;
    v1 = func_ov001_02181200(param_1, param_2);
    if ((v1 != (u8 *) 0x0) && (*v1 != param_3)) {
        v2 = 1;
        func_ov001_021811c8();
        *v1 = (u8) param_3;
    }
    return v2;
}

u8 func_ov001_02181004(s32 param_1, s32 param_2) {
    u8 *v1;
    v1 = func_ov001_02181200(param_1, param_2);
    if (v1 != (u8 *) 0x0) {
        return *v1;
    }
    return 0;
}
