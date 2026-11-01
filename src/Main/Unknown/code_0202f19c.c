#include "Main/Unknown/code_0202f19c.h"

u16 *func_0202f1d0(void) {
    return (u16 *) 0x027ffc40;
}

u32 func_0202f1a8(void) {
    return *func_0202f1d0() == 2;
}

u32 func_0202f19c(void) {
    return func_0202f1a8();
}
