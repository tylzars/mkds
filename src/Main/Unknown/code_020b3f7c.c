#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_02133000.h"

#pragma thumb on
#pragma optimize_for_size on
void func_020b3fb0(Unk020b3fb0 *a) {
    u32 i;
    u32 p;
    u32 q;
    u32 t;

    p = (u32) &a->mUnk_20;
    for (i = 0; i < a->mUnk_0c; i++) {
        q = p;
        p = p + ((Unk020b3fb0_20 *) p)->mUnk_04;
        t = func_020ae1d0(((Unk020b3fb0_20 *) q)->mUnk_00);
        switch (t) {
            case 0x494e4631:
                data_0217b360 = (Unk0217b340 *) q;
                break;
            case 0x44415431:
                data_0217b364 = (Unk0217b344 *) q;
                break;
        }
    }
}

void *func_020b3f7c(Unk020b3fb0 *a, s32 b) {
    func_020b3fb0(a);
    return &data_0217b364->mUnk_08[data_0217b360->mUnk_10[b % 0x10000]];
}
#pragma thumb off
