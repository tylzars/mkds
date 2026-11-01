#include "01/code_021842b4.h"

u32 func_ov001_021842b4(int param_1) {
    if (*(int *) (param_1 + 0x1cc) < 0) {
        func_ov001_02188200((Unk02188950 *) (param_1), func_ov001_02184390);
        *(u32 *) (param_1 + 0x150) = 7;
        *(u32 *) (param_1 + 0x158) = 0;
    }
    return 0;
}
