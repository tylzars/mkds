#include "Main/Unknown/code_020917d0.h"

u8 func_020917d0(int param_1, u32 param_2, u8 *param_3, u8 *param_4) {
    u8 v1;
    v1 = *param_4;
    if (*param_3 == 1) {
        *(u32 *) (param_1 + 0xb8) = ((u32) 0x0000f333u);
        *(u32 *) (param_1 + 0xbc) = 0x8000;
        *(u32 *) (param_1 + 0xb0) = 0;
        *(u32 *) (param_1 + 0xb4) = 0;
        *(u16 *) (param_1 + 2) = *(u16 *) (param_1 + 2) | (*(u16 *) &data_02156458);
        *(u32 *) (param_1 + 200) = 1;
    }
    return v1;
}
