#include "03/code_021c5944.h"
#include "code_02147cd8.h"
#include "03/code_021c5c68.h"

void func_ov003_021c5944(void) {
    int v1;
    u32 v2;
    if (data_ov003_021da1f4->mUnk_56 != 0) {
        v1 = func_02147cd8((u32) ((*(u16 *) &data_ov003_021da1f0)), (u32) 0x1c);
        v2 = (v1 + -0x32) * 0x10000 & ((u32) 0x01ff0000u);
        *((u32 *) 0x04000010u) = v2;
        *((u32 *) 0x04000018u) = v2;
        data_ov003_021da1f4->mUnk_56 = 0;
    }
}
