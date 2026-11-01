#include "Main/Unknown/code_020280dc.h"

u16 *func_02028110(void) {
    return (u16 *) 0x27ffc40;
}

u32 func_020280e8(void) {
    if (*func_02028110() == 2) {
        return 1;
    }
    return 0;
}

u32 func_020280dc(void) {
    return func_020280e8();
}
