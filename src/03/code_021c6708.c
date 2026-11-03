#include "03/code_021c209c.h"
#include "03/code_021c6708.h"
#include "03/code_021c6a18.h"
#include "03/code_021cdbd0.h"
#include "03/code_021cef6c.h"
#include "03/code_021cef90.h"

void func_ov003_021c673c(void) {
    int v1;
    v1 = func_ov003_021cef80();
    if (v1 == 0) {
        func_ov003_021cdc10(6);
        func_ov003_021cef90();
        func_ov003_021c212c(func_ov003_021c6708);
    }
    return;
}

void func_ov003_021c6708(void) {
    int v1;
    v1 = func_ov003_021cef6c();
    if (v1 == 0) {
        data_ov003_021da1f8->mUnk_04->mUnk_00 = data_ov003_021da1f8->mUnk_04->mUnk_00 & ((u32) 0xc1fffcffu);
        func_ov003_021c212c(func_ov003_021c6d0c);
    }
    return;
}
