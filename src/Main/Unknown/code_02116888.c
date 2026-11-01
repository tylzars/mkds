#include "Main/Unknown/code_02116888.h"

#pragma thumb on

void func_02116888(void) {
    int *v1;
    u32 v2;
    int v3;
    int v4;
    int v5;
    int v6[2];
    v4 = 0;
    v5 = 0;
    v6[0] = 0;
    v2 = ((int) func_0204799c((const char *) data_0216d20c));
    func_020b49bc((Unk020b4934 **) data_0217d350, (void *) v2);
    v2 = ((int) func_0204799c((const char *) data_0216d200));
    func_020b48b4(&data_0217d350->mUnk_04, (void *) v2);
    v2 = ((int) func_0204799c((const char *) data_0216d1f4));
    *(u32 *) ((int) data_0217d350 + 8) = v2;
    v2 = ((int) func_0204799c((const char *) data_0216d22c));
    *(u32 *) ((int) data_0217d350 + 0xc) = v2;
    v2 = ((int) func_0204799c((const char *) data_0216d238));
    *(u32 *) ((int) data_0217d350 + 0x18) = v2;
    v2 = ((int) func_0204799c((const char *) data_0216d1fc));
    *(u32 *) ((int) data_0217d350 + 0x1c) = v2;
    v2 = ((int) func_0204799c((const char *) data_0216d208));
    func_020b49bc(&data_0217d350->mUnk_28, (void *) v2);
    v2 = ((int) func_0204799c((const char *) data_0216d210));
    func_020b48b4(&data_0217d350->mUnk_2c, (void *) v2);
    v2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d3f0))));
    *(u32 *) ((int) data_0217d350 + 0x30) = v2;
    v2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d3fc))));
    *(u32 *) ((int) data_0217d350 + 0x34) = v2;
    v2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d3f8))));
    v1 = (&(*(int *) &data_0217d350));
    *(u32 *) ((int) data_0217d350 + 0x38) = v2;
    v2 = ((u32) func_02036bec((void *) (*(u32 *) (*v1 + 0x50)), (u32) (((u32) 0x00000800u))));
    data_0217d350->mUnk_4c = v2;
    v2 = ((int) func_0204799c((const char *) data_0216d3f4));
    func_020b4934((Unk020b4934 **) (&v4), (void *) v2);
    v2 = ((int) func_0204799c((const char *) data_0216d400));
    func_020b47d8((Unk020b47d8 **) v6, (void *) v2);
    v2 = ((int) func_0204799c((const char *) data_0216d404));
    func_020b4a44((Unk020b4a44 **) (&v5), (void *) v2);
    v2 = ((int) func_0204799c((const char *) data_0216d228));
    func_020b47d8((Unk020b47d8 **) ((int *) (u32) ((int) data_0217d350 + 0x10)), (void *) v2);
    v2 = ((int) func_0204799c((const char *) data_0216d214));
    func_020b47d8((Unk020b47d8 **) ((int *) (u32) ((int) data_0217d350 + 0x20)), (void *) v2);
    v3 = ((u32) func_02077f00());
    ((u32) func_02016468((u32) 0x17, (u32) 0, (void *) (*(u32 *) (v4 + 0x14)), (u32) (*(u32 *) (v4 + 0x10))));
    ((u32) func_02016468((u32) 0x1b, (u32) 0, (void *) (v6[0] + 0xc), (u32) (*(u32 *) (v6[0] + 8))));
    ((u32) func_02016468((u32) 0x1b, (u32) (((u32) 0x00000800u)), (void *) data_0217d350->mUnk_4c,
                         (u32) (((u32) 0x00000800u))));
    ((u32) func_02016468((u32) 0x1f, (u32) 0, (void *) (*(u32 *) (v5 + 0xc)), (u32) 0x40));
    ((u32) func_02016468((u32) 0xe, (u32) 0x40, (void *) (*(u32 *) (v3 + 0xc)), (u32) 0x20));
}

#pragma thumb off
