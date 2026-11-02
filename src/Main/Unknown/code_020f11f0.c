#include "Main/Unknown/code_020f11f0.h"

u32 func_020f11f0(u32 a, u32 b) {
    u16 v1;
    int v2;
    v1 = func_02061f90();
    if (((u32) v1 < data_021759c0->mUnk_3d0) && (v2 = func_020f1258((int) a, (int) v1, 0, (int) b), v2 != 0)) {
        return 1;
    }
    return 0;
}
