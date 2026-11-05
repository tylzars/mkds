#include "01/code_02187c60.h"
#include "01/code_02187d14.h"
#include "01/code_0218d520.h"
#include "code_020109c4.h"
#include "01/unk_021a7000.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_02042000.h"
#include "Main/Unknown/code_020ac000.h"
#include "Main/Unknown/code_020da000.h"
#include "Main/Unknown/code_020f4000.h"
#include "Main/Unknown/code_020fd000.h"
#include "Main/Unknown/code_020fd264.h"
#include "Main/Unknown/code_02147000.h"

void func_ov001_02187c88(Unk02188950 *a, s32 b, const Vec3 *c) {
    a->mUnk_2e4 = b;
    a->mUnk_2f4 = *c;
    a->mNsbmd->mAnimatedModel->mUnk_2c = a;
    func_020109c4((void *) a->mNsbmd->mAnimatedModel, (void (*)(void *)) func_ov001_02187d14, (u32) (0), (u8) (6),
                  (u8) (3));
}

void func_ov001_02187c60(Unk02188950 *a, void *b) {
    if (a->mUnk_300 != NULL) {
        func_020fd494(&a->mUnk_300);
    }
    a->mUnk_300 = b;
}
