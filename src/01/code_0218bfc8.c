#include "01/code_0218bfc8.h"
#include "01/code_02185ef4.h"
#include "01/code_02187eb0.h"
#include "01/code_02188cd8.h"
#include "Main/Unknown/code_02042044.h"
#include "01/code_0218c0a4.h"
#include "01/code_0218c584.h"
#include "01/code_0219b1c4.h"

void func_ov001_0218bfc8(Unk02188950 *a) {
    CourseMapGroupEntry *v1;
    Unk02188950_a0 *v2;
    func_ov001_02187218(a, 2, &func_ov001_0218c584);
    func_ov001_02188d64(a, a->mPrm->mUnk_15c, a->mPrm->mUnk_160);
    func_ov001_0219b1c4(a->mNsbmd, a->mPrm->mUnk_164, a->mPrm->mUnk_160, 0);
    func_ov001_02188cd8(a, a->mPrm->mUnk_168, a->mPrm->mUnk_16c);
    v2 = a->mPrm;
    func_ov001_021889ec(a, v2->mUnk_178, v2->mUnk_17c, v2->mUnk_170, v2->mUnk_174);
    v1 = func_ov001_02187fc0(a);
    SetAnglePoint(a, &v1->mPos);
    v1 = func_ov001_02187fc0(a);
    SetMoveAnglePoint(a, &v1->mPos);
    func_ov001_02188e24(a, a->mPrm->mUnk_180, &func_ov001_0218c354);
    func_ov001_0218c5fc(a);
}
