#include "03/code_021d1cd4.h"
#include "03/code_021d2ecc.h"
#include "Main/Unknown/code_0214d000.h"

#include "03/code_021d2fa0.h"
#include "03/code_021d27d8.h"
#include "03/code_021d1000.h"
#include "03/unk_021da000.h"
#include "03/code_021d3488.h"
#include "code_0214d018.h"

void func_ov003_021d2f78(void) {
    func_ov003_021d34c0(1, data_ov003_021da2f0->mUnk_808);
    func_ov003_021d2808(&data_ov003_021da2f0);
}

u8 *func_ov003_021d2f44(int a, u8 *b) {
    u8 *v1;
    v1 = func_ov003_021d1cd4(data_ov003_021da2f0->mUnk_800[a]);
    MemCopyWords(b, v1, 8);
    return v1;
}

void func_ov003_021d2f00(u32 *a) {
    Unk021d2fa0 *b;
    s32 c = 0;

    *a = (*a & 0xc1fffcff) | 0x200;
    b = data_ov003_021da2f0;
    if ((u32) a >= (u32) b + 0x400) {
        c = 1;
    }
    func_ov003_021d1d0c((Unk021d1d88 *) b->mUnk_800[c], a);
}

Unk021d1770_08 *func_ov003_021d2eec(int a, int b) {
    return (Unk021d1770_08 *) (&data_ov003_021da2f0->mUnk_000[a][b * 8]);
}

void *func_ov003_021d2ecc(void) {
    u32 v4 = ((u32) func_ov003_021d285c((u32) 0x10u, (u32) 0x4u));
    u32 v7;
    u32 v8;
    *(u32 *) ((v4) + (0)) = (u32) 0x0u;
    v7 = ((v4) + (0x0u));
    v8 = ((v7) + (0x8u));
    *(u32 *) ((v4) + (4)) = v8;
    *(u32 *) ((v4) + (8)) = v4;
    *(u32 *) ((v4) + (12)) = (u32) 0x0u;
    return (void *) v4;
}
