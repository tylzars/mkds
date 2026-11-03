#include "01/code_0218155c.h"
#include "01/code_02188260.h"
#include "Main/Unknown/code_020a12b8.h"

u32 func_ov001_02188260(Unk02188950 *p) {
    if (data_021759c0->mUnk_08 == 4) {
        func_ov001_021817e0();
    }
    p->mUnk_0ac++;
    if (p->mUnk_0ac >= p->mPrm->mUnk_000) {
        p->mUnk_0ac = p->mPrm->mUnk_000;
        if (data_021759c0->mUnk_08 == 4) {
            func_020a12b8();
        }
        return 1;
    }
    return 0;
}
