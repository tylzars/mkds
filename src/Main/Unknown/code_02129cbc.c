#include "Main/Unknown/code_02129cbc.h"

#pragma thumb on

void func_02129e78(void) {
    int v1;
    v1 = *(int *) ((int) data_0217d400 + *(int *) ((int) data_0217d400 + 4) * 4 + 0xb4);
    ((u32) func_02016468((u32) 0x1b, (u32) 0, (void *) (v1 + 0xc), (u32) (*(u32 *) (v1 + 8))));
}

void func_02129cbc(void) {
    u32 v1;
    int v2;
    int v3[1];
    v1 = ((int) func_0204799c((const char *) &data_0216e940));
    *(u32 *) ((int) data_0217d400 + 0xa4) = v1;
    v1 = ((int) func_0204799c((const char *) &data_0216e958));
    *(u32 *) ((int) data_0217d400 + 0x9c) = v1;
    v1 = ((int) func_0204799c((const char *) &data_0216e970));
    *(u32 *) ((int) data_0217d400 + 0xac) = v1;
    v1 = ((int) func_0204799c((const char *) &data_0216e988));
    *(u32 *) ((int) data_0217d400 + 0xa8) = v1;
    v1 = ((int) func_0204799c((const char *) &data_0216e998));
    *(u32 *) ((int) data_0217d400 + 0xa0) = v1;
    v1 = ((int) func_0204799c((const char *) &data_0216e9a8));
    *(u32 *) ((int) data_0217d400 + 0xb0) = v1;
    v1 = ((int) func_0204799c((const char *) &data_0216e9b8));
    func_020b49f4((Unk020b4934 **) ((int *) (u32) ((int) data_0217d400 + 0x94)), (void *) v1);
    v1 = ((int) func_0204799c((const char *) &data_0216e9d0));
    func_020b48ec(&data_0217d400->mUnk_90, (void *) v1);
    v1 = ((int) func_0204799c((const char *) &data_0216e9e8));
    func_020b4a7c((Unk020b4a44 **) ((int *) (u32) ((int) data_0217d400 + 0x98)), (void *) v1);
    func_0200ee74((const void *) (*(u32 *) (*(int *) ((int) data_0217d400 + 0x94) + 0x14)),
                  (int) (*(u32 *) (*(int *) ((int) data_0217d400 + 0x94) + 0x10)));
    func_0214bf04((const void *) (*(u32 *) (*(int *) ((int) data_0217d400 + 0x94) + 0x14)), 0,
                  (u32) (*(u32 *) (*(int *) ((int) data_0217d400 + 0x94) + 0x10)));
    func_0214bea4((const void *) (*(u32 *) (*(int *) ((int) data_0217d400 + 0x94) + 0x14)), 0,
                  (u32) (*(u32 *) (*(int *) ((int) data_0217d400 + 0x94) + 0x10)));
    func_0200ee74((const void *) (*(u32 *) (*(int *) ((int) data_0217d400 + 0x98) + 0xc)),
                  (int) (*(u32 *) (*(int *) ((int) data_0217d400 + 0x98) + 8)));
    func_0214c090((const void *) (*(u32 *) (*(int *) ((int) data_0217d400 + 0x98) + 0xc)), 0,
                  (u32) (((u32) 0x000001a0u)));
    func_0214c090((const void *) (*(int *) (*(int *) ((int) data_0217d400 + 0x98) + 0xc) + 0x1c0),
                  0x1c0, (u32) 0x40);
    func_0214c028((const void *) (*(u32 *) (*(int *) ((int) data_0217d400 + 0x98) + 0xc)), 0,
                  (u32) (*(u32 *) (*(int *) ((int) data_0217d400 + 0x98) + 8)));
    v1 = ((int) func_0204799c((const char *) &data_0216e9fc));
    func_020b496c((Unk020b4934 **) (&v2), (void *) v1);
    func_0200ee74((const void *) (*(u32 *) (v2 + 0x14)), (int) (*(u32 *) (v2 + 0x10)));
    func_0214b824((const void *) (*(u32 *) (v2 + 0x14)), 0, (u32) (*(u32 *) (v2 + 0x10)));
    v1 = ((int) func_0204799c((const char *) &data_0216ea14));
    func_020b4810((Unk020b47d8 **) ((int *) (u32) ((int) data_0217d400 + 0xb4)), (void *) v1);
    v1 = ((int) func_0204799c((const char *) &data_0216ea30));
    func_020b4810((Unk020b47d8 **) ((int *) (u32) ((int) data_0217d400 + 0xb8)), (void *) v1);
    v1 = ((int) func_0204799c((const char *) &data_0216ea4c));
    func_020b4a7c((Unk020b4a44 **) v3, (void *) v1);
    func_0200ee74((const void *) (*(u32 *) (v3[0] + 0xc)), 0x80);
    func_0214c0f8((const void *) (*(u32 *) (v3[0] + 0xc)), 0, (u32) 0x80);
}

#pragma thumb off
