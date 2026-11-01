#include "01/code_02191c14.h"
#include "01/code_02193000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_0212a000.h"
#include "Main/Unknown/code_0214a000.h"
#include "Main/Unknown/code_0214d000.h"

void func_ov001_02191cf4(Unk02188950 *param_1) {
    Vec3 v = {0, 0, 0};
    v.y = -param_1->mUnk_0a0->mUnk_2a4;
    func_ov001_02187218(param_1, 3, (s32(*)(Unk02188950 *)) func_ov001_02191dc8);
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_29c, param_1->mUnk_0a0->mUnk_2a0);
    func_ov001_02188950(param_1, &v);
    func_ov001_02188c0c(param_1, param_1->mUnk_0a0->mUnk_2c8, 0x270f000);
    func_ov001_02188cd8(param_1, param_1->mUnk_0a0->mUnk_2cc, 0x270f000);
    func_ov001_021875c0(param_1, 0, 0x44cd, 0x400, 0x42d, 0);
    func_ov001_021875c0(param_1, 0, 0x44cd, 0x400, 0x42e, 0);
    func_ov001_02188db8(param_1, func_ov001_02191de0);
    param_1->mUnk_2c0 = 0;
}

void func_ov001_02191c14(Unk02188950 *param_1) {
    Vec3 v = {0, 0, 0};
    v.y = param_1->mUnk_0a0->mUnk_2a4;
    func_ov001_02187218(param_1, 3, (s32(*)(Unk02188950 *)) func_ov001_02191dc8);
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_29c, param_1->mUnk_0a0->mUnk_2a0);
    func_ov001_02188950(param_1, &v);
    func_ov001_02188c0c(param_1, param_1->mUnk_0a0->mUnk_2c8, 0x270f000);
    func_ov001_02188cd8(param_1, param_1->mUnk_0a0->mUnk_2cc, 0x270f000);
    func_ov001_02188e24(param_1, param_1->mUnk_0a0->mUnk_2a8, func_ov001_02191cf4);
    func_ov001_021875c0(param_1, 0, 0x44cd, 0x400, 0x42d, 0);
    func_ov001_021875c0(param_1, 0, 0x44cd, 0x400, 0x42e, 0);
    param_1->mUnk_2c0 = 0;
}
