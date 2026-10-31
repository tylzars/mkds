#include "00/code_021ae100.h"

u32 func_ov000_021ae100(u16 *param_1, u32 *param_2) {
    int v1;
    v1 = *(int *) (*(int *) (((int) (u32) ((u8 *) &data_0216ff5c)) + 4) + 0xa4);
    if ((v1 != 0) && ((*(u8 *) (v1 + 8) == 4 || (*(u8 *) (v1 + 8) == '\n')))) {
        if (param_1 != (u16 *) 0x0) {
            *param_1 = *(u16 *) (v1 + 0x18);
        }
        if (param_2 != (u32 *) 0x0) {
            *param_2 = *(u32 *) (v1 + 0x14);
        }
        return *(u32 *) (v1 + 0x1c);
    }
    return 0;
}
