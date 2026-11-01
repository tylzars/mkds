#include "03/code_021c6f08.h"
#include "03/code_021cef6c.h"

void func_ov003_021c6f3c(void) {
    int v1;
    v1 = func_ov003_021cef80();
    if (v1 == 0) {
        func_ov003_021cdc10(6);
        func_ov003_021cef90();
        func_ov003_021c212c(func_ov003_021c6f08);
    }
    return;
}

void func_ov003_021c6f08(void) {
    int v1;
    v1 = func_ov003_021cef6c();
    if (v1 == 0) {
        **(u32 **) ((int) data_ov003_021da1fc + 4) = **(u32 **) ((int) data_ov003_021da1fc + 4) & ((u32) 0xc1fffcffu);
        func_ov003_021c212c(func_ov003_021c7614);
    }
    return;
}
