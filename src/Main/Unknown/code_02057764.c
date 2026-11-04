#include "Main/Unknown/code_0204b418.h"
#include "Main/Unknown/code_0204b6cc.h"
#include "Main/Unknown/code_02057764.h"
#include "Main/Unknown/code_02057cfc.h"
#include "01/code_021956dc.h"
#include "code_0214d018.h"

#pragma thumb on

void func_020577b4(void *a) {
    u32 *v1;
    v1 = data_021759d4->mUnk_60;
    if (data_021759d4->mUnk_0c != 0) {
        MemCopy(a, v1, 0xc00);
        *v1 = 0x4c464b4e;
        func_0204b430(0x1f00, 0x32e00, v1, 0xc00, NULL, 0);
    }
}

void func_02057764(void *a) {
    if (data_021759d4->mUnk_0c != 0) {
        data_021759d4->mUnk_68 = a;
        data_021759d4->mUnk_5c = -1;
        func_0204b6cc(0x1f00, 0x32e00, data_021759d4->mUnk_60, 0xc00, func_02057cfc, 0x4c464b4e, 0);
    }
}

#pragma thumb off
