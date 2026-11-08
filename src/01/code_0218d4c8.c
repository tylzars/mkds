#include "01/code_0218d4c8.h"
#include "01/code_02185ef4.h"
#include "01/code_02187eb0.h"
#include "01/code_02188cd8.h"
#include "01/code_0218d520.h"
#include "01/code_0218dce4.h"

void func_ov001_0218d4c8(Unk02188950 *a) {
    u32 v1;
    func_ov001_02187218(a, 1, &func_ov001_0218d520);
    func_ov001_02188dcc(a, 0);
    StartAnimationNoEndCallback(a, a->mPrm->mUnk_088, a->mPrm->mUnk_08c);
    v1 = func_ov001_02187f38(a);
    func_ov001_0218d824(a, v1);
    v1 = func_ov001_02187f38(a);
    func_ov001_0218d87c(a, v1);
    func_ov001_0218dce4(a);
}
