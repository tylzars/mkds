#include "00/code_0218d238.h"
#include "00/code_0218b220.h"
#include "00/code_0218d000.h"
#include "00/code_0218da04.h"

void func_ov000_0218d278(Unk021b4d24 *p, u32 v1) {
    if (p->mUnk_5d0 == 0) {
        func_ov000_0218b224(v1, 0);
    } else {
        func_ov000_0218b224(v1, p->mUnk_5d0);
    }
    p->mUnk_5d0 = v1;
}

void func_ov000_0218d238(Unk021b4d24 *p, s32 a) {
    u32 v = *(u32 *) func_ov000_0218dbf8(p->mUnk_004, a);
    p->mUnk_488(p, 2, v, p->mUnk_494);
    func_ov000_0218da5c(p->mUnk_004, a);
    func_ov000_0218d278(p, v);
}
