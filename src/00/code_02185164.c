#include "00/code_02185164.h"

void func_ov000_021851a0(void) {
    u32 v1;
    v1 = ((int) func_0204799c((const char *) &data_ov000_021b0e70));
    *(u32 *) ((int) data_ov000_021b4c84 + 0x2c) = v1;
    v1 = ((int) func_0204799c((const char *) &data_ov000_021b0e84));
    *(u32 *) ((int) data_ov000_021b4c84 + 0x30) = v1;
    v1 = ((int) func_0204799c((const char *) &data_ov000_021b0e98));
    func_020b49bc(&data_ov000_021b4c84->mUnk_24, (void *) (v1));
    v1 = ((int) func_0204799c((const char *) &data_ov000_021b0eb4));
    func_020b48b4(&data_ov000_021b4c84->mUnk_20, (void *) (v1));
    v1 = ((int) func_0204799c((const char *) &data_ov000_021b0ed0));
    func_020b4a44(&data_ov000_021b4c84->mUnk_28, (void *) (v1));
    func_0214bea4((const void *) (*(u32 *) ((int) data_ov000_021b4c84->mUnk_24 + 0x14)), 0,
                  (u32) (*(u32 *) ((int) data_ov000_021b4c84->mUnk_24 + 0x10)));
    func_0214c028((const void *) (*(u32 *) ((int) data_ov000_021b4c84->mUnk_28 + 0xc)), 0,
                  (u32) (*(u32 *) ((int) data_ov000_021b4c84->mUnk_28 + 8)));
    return;
}

u32 func_ov000_02185184(void) {
    u32 v1;
    v1 = func_0205e548();
    if (60 <= v1) {
        return 1;
    }
    return 0;
}

void func_ov000_02185164(void) {
    int v1;
    v1 = func_02036c5c();
    if (v1 != 0) {
        *(u32 *) ((int) data_ov000_021b4c84 + 4) = 1;
    }
    return;
}
