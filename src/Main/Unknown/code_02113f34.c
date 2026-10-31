#include "Main/Unknown/code_02113f34.h"

#pragma thumb on

void func_02113f34(void) {
    u32 v1;
    int v2;
    int v3;
    int v4;
    int v5;
    int v6;
    int v7;
    int v8;
    v4 = 0;
    v5 = 0;
    v6 = 0;
    v7 = 0;
    v8 = 0;
    v1 = ((int) func_0204799c((const char *) data_0216d20c));
    func_020b49bc((Unk020b4934 **) ((int *) (u32) data_0217d348), (void *) v1);
    v1 = ((int) func_0204799c((const char *) data_0216d200));
    func_020b48b4(&data_0217d348->mUnk_04, (void *) v1);
    v1 = ((int) func_0204799c((const char *) data_0216d1f8));
    func_020b4a44((Unk020b4a44 **) (&v4), (void *) v1);
    v1 = ((int) func_0204799c((const char *) data_0216d1f4));
    *(u32 *) ((int) data_0217d348 + 8) = v1;
    v1 = ((int) func_0204799c((const char *) data_0216d22c));
    *(u32 *) ((int) data_0217d348 + 0xc) = v1;
    v1 = ((int) func_0204799c((const char *) data_0216d238));
    *(u32 *) ((int) data_0217d348 + 0x18) = v1;
    v1 = ((int) func_0204799c((const char *) data_0216d1fc));
    *(u32 *) ((int) data_0217d348 + 0x1c) = v1;
    v1 = ((int) func_0204799c((const char *) data_0216d208));
    func_020b49bc((Unk020b4934 **) ((int *) (u32) ((int) data_0217d348 + 0x28)), (void *) v1);
    v1 = ((int) func_0204799c((const char *) data_0216d210));
    func_020b48b4(&data_0217d348->mUnk_2c, (void *) v1);
    v1 = ((int) func_0204799c((const char *) data_0216d218));
    func_020b4a44((Unk020b4a44 **) (&v8), (void *) v1);
    v1 = ((int) func_0204799c((const char *) data_0216d204));
    *(u32 *) ((int) data_0217d348 + 0x30) = v1;
    v1 = ((int) func_0204799c((const char *) data_0216d234));
    *(u32 *) ((int) data_0217d348 + 0x34) = v1;
    v1 = ((int) func_0204799c((const char *) data_0216d21c));
    *(u32 *) ((int) data_0217d348 + 0x38) = v1;
    v2 = ((u32) func_02077f00());
    v1 = ((int) func_0204799c((const char *) data_0216d220));
    func_020b4934((Unk020b4934 **) (&v5), (void *) v1);
    v1 = ((int) func_0204799c((const char *) data_0216d230));
    func_020b47d8((Unk020b47d8 **) (&v6), (void *) v1);
    v1 = ((int) func_0204799c((const char *) data_0216d228));
    func_020b47d8((Unk020b47d8 **) ((int *) (u32) ((int) data_0217d348 + 0x10)), (void *) v1);
    v1 = ((int) func_0204799c((const char *) data_0216d214));
    func_020b47d8((Unk020b47d8 **) ((int *) (u32) ((int) data_0217d348 + 0x20)), (void *) v1);
    v1 = ((int) func_0204799c((const char *) data_0216d224));
    func_020b4a44((Unk020b4a44 **) (&v7), (void *) v1);
    v3 = *(int *) (v4 + 0xc);
    ((u32) func_02016468((u32) 0x13, (u32) 0, (void *) (*(u32 *) ((int) data_0217d348->mUnk_00 + 0x14)),
                         (u32) (*(u32 *) ((int) data_0217d348->mUnk_00 + 0x10))));
    ((u32) func_02016468((u32) 0xe, (u32) 0, (void *) (*(u32 *) (v4 + 0xc)), (u32) (((u32) 0x000001a0u))));
    ((u32) func_02016468((u32) 0xe, (u32) 0x1c0, (void *) (v3 + 0x1c0),
                         (u32) 0x40));
    ((u32) func_02016468((u32) 0x23, (u32) 0,
                         (void *) (*(u32 *) ((int) data_0217d348->mUnk_28 + 0x14)),
                         (u32) (*(u32 *) ((int) data_0217d348->mUnk_28 + 0x10))));
    ((u32) func_02016468((u32) 0x1e, (u32) 0, (void *) (*(u32 *) (v8 + 0xc)),
                         (u32) (*(u32 *) (v8 + 8))));
    ((u32) func_02016468((u32) 4, (u32) 0, (void *) (*(u32 *) (v5 + 0x14)),
                         (u32) (*(u32 *) (v5 + 0x10))));
    ((u32) func_02016468((u32) 8, (u32) 0, (void *) (v6 + 0xc), (u32) (*(u32 *) (v6 + 8))));
    ((u32) func_02016468((u32) 0xf, (u32) 0, (void *) (*(u32 *) (v7 + 0xc)), (u32) 0x40));
    ((u32) func_02016468((u32) 0xe, (u32) 0x40, (void *) (*(u32 *) (v2 + 0xc)), (u32) 0x20));
}

#pragma thumb off
