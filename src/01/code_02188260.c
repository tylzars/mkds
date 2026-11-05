#include "01/code_02188260.h"
#include "01/code_0218155c.h"
#include "Main/Unknown/code_020a12b8.h"

u32 func_ov001_02188260(Unk02188950 *p) {
    if (data_021759c0->mMode == MODE_MISSION_RUN) {
        func_ov001_021817e0();
    }
    p->mUnk_0ac++;
    if (p->mUnk_0ac >= p->mPrm->mUnk_000) {
        p->mUnk_0ac = p->mPrm->mUnk_000;
        if (data_021759c0->mMode == MODE_MISSION_RUN) {
            func_020a12b8();
        }
        return 1;
    }
    return 0;
}
