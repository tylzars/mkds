#include "Main/Unknown/code_0211f61c.h"

#pragma thumb on

void func_0211f61c(void) {
    u32 v1;
    int v2;
    int v3[1];
    v2 = 0;
    v3[0] = 0;
    v1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216e128))));
    func_020b48b4(&data_0217d380->mUnk_00, (void *) v1);
    v1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216e134))));
    func_020b49bc((Unk020b4934 **) (&v2), (void *) v1);
    v1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216e130))));
    func_020b4a44((Unk020b4a44 **) v3, (void *) v1);
    v1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216e124))));
    *(u32 *) ((int) data_0217d380 + 4) = v1;
    v1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216e12c))));
    *(u32 *) ((int) data_0217d380 + 0xc) = v1;
    ((u32) func_02016468((u32) 0x23, (u32) 0, (void *) (*(u32 *) (v2 + 0x14)), (u32) (*(u32 *) (v2 + 0x10))));
    ((u32) func_02016468((u32) 0x1e, (u32) 0, (void *) (*(u32 *) (v3[0] + 0xc)), (u32) (*(u32 *) (v3[0] + 8))));
}

#pragma thumb off
