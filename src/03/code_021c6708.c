#include "03/code_021c6708.h"
#include "03/code_021c209c.h"
#include "03/code_021c6764.h"
#include "03/code_021cdbd0.h"
#include "03/code_021cea3c.h"
#include "03/code_021cef90.h"

void func_ov003_021c673c(void) {
    int v1;
    v1 = func_ov003_021cef80();
    if (v1 == 0) {
        StartSoundSeq(6);
        func_ov003_021cef90();
        SetUpdateFunction(func_ov003_021c6708);
    }
}

void func_ov003_021c6708(void) {
    int v1;
    v1 = func_ov003_021cef6c();
    if (v1 == 0) {
        gEdit->mUnk_04->mUnk_00 = gEdit->mUnk_04->mUnk_00 & (0xc1fffcffu);
        SetUpdateFunction(func_ov003_021c6d0c);
    }
}
