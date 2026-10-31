#include "00/code_021a38d8.h"

u32 func_ov000_021a38d8(void) {
    int *v1;
    v1 = (int *) (u32) data_ov000_021b5df4;
    if (v1 == (int *) 0x0) {
        return 0;
    }
    if (*v1 != 0) {
        *(u16 *) (v1 + 1) = 3;
        func_ov000_021a3810();
        return 1;
    }
    return 0;
}
