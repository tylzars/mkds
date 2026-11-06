#include "01/code_0218a444.h"
#include "01/code_02185ef4.h"
#include "01/code_02188cd8.h"
#include "01/code_02189da4.h"
#include "01/code_0218a568.h"

void func_ov001_0218a52c(Unk02188950 *a) {
    func_ov001_02187218(a, 7, NULL);
    func_ov001_02188d30(a, a->mPrm->mUnk_174, a->mPrm->mUnk_178, NULL);
    func_ov001_021881f4(a, (UnkFunc *) &func_ov001_02189ed8);
}

void func_ov001_0218a4d0(Unk02188950 *a) {
    func_ov001_02187218(a, 7, &func_ov001_0218a568);
    func_ov001_02188d64(a, a->mPrm->mUnk_164, a->mPrm->mUnk_168);
    func_ov001_02188dcc(a, &func_ov001_0218a52c);
    func_ov001_02188cec(a, 0);
    a->mUnk_2bc = TRUE;
    func_ov001_021881f4(a, (UnkFunc *) &func_ov001_02189fe0);
}

void func_ov001_0218a4a0(Unk02188950 *a) {
    func_ov001_02187218(a, 7, NULL);
    func_ov001_02188d30(a, a->mPrm->mUnk_070, a->mPrm->mUnk_074, NULL);
    func_ov001_021881f4(a, (UnkFunc *) &func_ov001_02189ed8);
}

void func_ov001_0218a444(Unk02188950 *a) {
    func_ov001_02187218(a, 7, &func_ov001_0218a568);
    func_ov001_02188d64(a, a->mPrm->mUnk_164, a->mPrm->mUnk_168);
    func_ov001_02188dcc(a, &func_ov001_0218a4a0);
    func_ov001_02188cec(a, 0);
    a->mUnk_2bc = TRUE;
    func_ov001_021881f4(a, (UnkFunc *) &func_ov001_02189fe0);
}
