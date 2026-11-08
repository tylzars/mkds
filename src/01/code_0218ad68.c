#include "01/code_0218ad68.h"
#include "01/code_02185ef4.h"
#include "01/code_02188cd8.h"
#include "01/code_0218add0.h"

void func_ov001_0218ad68(Unk02188950 *a) {
    func_ov001_0218aef4(a);
    func_ov001_02187218(a, 3, (s32(*)(Unk02188950 *))(0));
    StartAnimationNoEndCallback(a, a->mPrm->mUnk_1dc, a->mPrm->mUnk_1e0);
    func_ov001_02188c90(a);
    SetSpeedAndClearTarget(a, 0);
    StartStateFrameCountCallback(a, a->mPrm->mUnk_1f0, &func_ov001_0218add0);
    a->mGravityEnabled = FALSE;
}
