#include "03/code_021c4bc4.h"
#include "03/code_021c4b78.h"
#include "03/code_021cef6c.h"

void func_ov003_021c4c08(void) {
    return;
}

void func_ov003_021c4c04(void) {
    return;
}

void func_ov003_021c4bc4(void) {
    int v1;
    v1 = func_ov003_021cef6c();
    if (v1 == 0) {
        if ((*(u8 *) &data_ov003_021da1d4) == 0) {
            func_ov003_021d1ee0(3, 1, (u32) 1, (u16) 8);
        }
        func_ov003_021d1ee0(3, 0, (u32) 0x15, (u16) 8);
        func_ov003_021c212c(func_ov003_021c4b78);
    }
}
