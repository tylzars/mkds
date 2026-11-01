#include "01/code_02191ecc.h"
#include "01/code_02193000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_0212a000.h"
#include "Main/Unknown/code_0214a000.h"
#include "Main/Unknown/code_0214d000.h"

void func_ov001_021920dc(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 1, 0);
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_254, param_1->mUnk_0a0->mUnk_258);
    func_ov001_02188c0c(param_1, param_1->mUnk_0a0->mUnk_2c8, 0x270f000);
    func_ov001_02188cd8(param_1, param_1->mUnk_0a0->mUnk_2cc, 0x270f000);
    func_ov001_021875c0(param_1, 0, 0x44cd, 0x400, 0x42d, 0);
    func_ov001_021875c0(param_1, 0, 0x44cd, 0x400, 0x42e, 0);
}

void func_ov001_02192080(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 1, 0);
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_28c, param_1->mUnk_0a0->mUnk_290);
    func_ov001_02188c0c(param_1, param_1->mUnk_0a0->mUnk_2c8, 0x270f000);
    func_ov001_02188cd8(param_1, param_1->mUnk_0a0->mUnk_2cc, 0x270f000);
}

void func_ov001_02191fe8(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 1, 0);
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_294, param_1->mUnk_0a0->mUnk_298);
    func_ov001_02188c0c(param_1, param_1->mUnk_0a0->mUnk_2c8, 0x270f000);
    func_ov001_02188cd8(param_1, param_1->mUnk_0a0->mUnk_2cc, 0x270f000);
    func_ov001_021875c0(param_1, 0, 0x44cd, 0x400, 0x42d, 0);
    func_ov001_021875c0(param_1, 0, 0x44cd, 0x400, 0x42e, 0);
}

void func_ov001_02191f70(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 3, 0);
    func_ov001_02188d30(param_1, param_1->mUnk_0a0->mUnk_2ac, param_1->mUnk_0a0->mUnk_2b0, func_ov001_02192080);
    func_ov001_02188c0c(param_1, param_1->mUnk_0a0->mUnk_2c8, 0x270f000);
    func_ov001_02188cd8(param_1, param_1->mUnk_0a0->mUnk_2cc, 0x270f000);
    func_ov001_021922e0((int) param_1);
    func_020d2774(&param_1->mUnk_000, (u32) (0x215));
}

void func_ov001_02191ecc(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 3, 0);
    func_ov001_02188d30(param_1, param_1->mUnk_0a0->mUnk_2b4, param_1->mUnk_0a0->mUnk_2b8, func_ov001_02191fe8);
    func_ov001_02188c0c(param_1, param_1->mUnk_0a0->mUnk_2c8, 0x270f000);
    func_ov001_02188cd8(param_1, param_1->mUnk_0a0->mUnk_2cc, 0x270f000);
    func_ov001_02192358((int) param_1);
    func_ov001_021875c0(param_1, 0, 0x44cd, 0x2000, 0x42d, 0);
    func_ov001_021875c0(param_1, 0, 0x44cd, 0x2000, 0x42e, 0);
}
