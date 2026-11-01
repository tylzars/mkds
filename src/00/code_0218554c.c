#include "00/code_0218554c.h"

void func_ov000_0218554c(void) {
    u32 v1;
    v1 = ((int) func_0204799c((const char *) &data_ov000_021b0f28));
    *(u32 *) ((int) data_ov000_021b4c88 + 0x40) = v1;
    v1 = ((int) func_0204799c((const char *) &data_ov000_021b0f44));
    *(u32 *) ((int) data_ov000_021b4c88 + 0x48) = v1;
    v1 = ((int) func_0204799c((const char *) &data_ov000_021b0f60));
    func_020b49bc(&data_ov000_021b4c88->mUnk_38, (void *) v1);
    v1 = ((int) func_0204799c((const char *) &data_ov000_021b0f80));
    func_020b48b4(&data_ov000_021b4c88->mUnk_34, (void *) v1);
    v1 = ((int) func_0204799c((const char *) &data_ov000_021b0fa0));
    func_020b4a44(&data_ov000_021b4c88->mUnk_3c, (void *) v1);
    func_0214bf04((const void *) (*(u32 *) ((int) data_ov000_021b4c88->mUnk_38 + 0x14)), 0,
                  (u32) (*(u32 *) ((int) data_ov000_021b4c88->mUnk_38 + 0x10)));
    func_0214c090((const void *) (*(u32 *) ((int) data_ov000_021b4c88->mUnk_3c + 0xc)), 0, (u32) (((u32) 0x000001a0u)));
    func_0214c090((const void *) (*(int *) ((int) data_ov000_021b4c88->mUnk_3c + 0xc) + 0x1c0), 0x1c0, (u32) 0x40);
}
