#include "00/code_0218af28.h"
#include "00/code_021a3668.h"
#include "00/code_021a3690.h"
#include "00/code_0218afa0.h"
#include "00/code_0218afac.h"
#include "00/code_0218afb8.h"
#include "00/code_0218dddc.h"

Unk0218af28 *func_ov000_0218af28(Unk021b4d24 *a, u32 b, u16 c) {
    Unk0218af28 *p;
    p = func_ov000_021a3690(0x24);
    if (p == 0) {
        return 0;
    }
    p->mUnk_18 =
        func_ov000_0218e004(8, 8, 4, (s32(*)(void *, s32)) func_ov000_0218afac,
                            (s32(*)(void *, void *)) func_ov000_0218afa0, (void (*)(void *)) func_ov000_0218afb8);
    if (p->mUnk_18 == 0) {
        func_ov000_021a3668(p);
        return 0;
    }
    p->mUnk_14 = 0;
    p->mUnk_15 = 0;
    p->mUnk_20 = 0;
    p->mUnk_1c = 0;
    p->mUnk_10 = 0;
    p->mUnk_00 = b;
    p->mUnk_04 = c;
    p->mUnk_08 = 0;
    p->mUnk_0c = 0;
    return p;
}
