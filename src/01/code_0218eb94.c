#include "01/code_0218eb94.h"

#include "01/code_02187000.h"
#include "01/code_02187098.h"
#include "01/code_02188000.h"
#include "01/code_02188e24.h"
#include "01/code_0218edb8.h"
#include "01/code_0218f900.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217d000.h"
#include "01/code_0218f000.h"

void func_ov001_0218ec40(Unk02188950 *param_1) {
    func_0207a974((u16) data_021759c0->mUnk_62);
    func_ov001_02187218(param_1, 1, (s32 (*)(Unk02188950 *)) func_ov001_0218edb8);
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_118), (s32) (param_1->mUnk_0a0->mUnk_11c));
    func_ov001_02188d1c(param_1, (s32) (param_1->mUnk_0a0->mUnk_120), (s32) (param_1->mUnk_0a0->mUnk_124));
    if (param_1->mUnk_0a8 == 1) {
        func_ov001_02188cd8(param_1, (s32) (param_1->mUnk_0a0->mUnk_128), (s32) (param_1->mUnk_0a0->mUnk_12c));
        func_ov001_02188c48(param_1, param_1->mUnk_0a0->mUnk_130, param_1->mUnk_0a0->mUnk_134);
    } else if (param_1->mUnk_0a8 == 2) {
        func_ov001_02188cd8(param_1, (s32) (param_1->mUnk_0a0->mUnk_220), (s32) (param_1->mUnk_0a0->mUnk_224));
        func_ov001_02188c48(param_1, param_1->mUnk_0a0->mUnk_228, param_1->mUnk_0a0->mUnk_22c);
    } else if (param_1->mUnk_0a8 == 3) {
        func_ov001_02188cd8(param_1, (s32) (param_1->mUnk_0a0->mUnk_230), (s32) (param_1->mUnk_0a0->mUnk_234));
        func_ov001_02188c48(param_1, param_1->mUnk_0a0->mUnk_238, param_1->mUnk_0a0->mUnk_23c);
    }
    func_ov001_02188998(param_1, ((Vec3 *) func_ov001_02187fc0(param_1)));
    func_ov001_02188de0(param_1, (s32) (param_1->mUnk_0a0->mUnk_138), (s32) (param_1->mUnk_0a0->mUnk_13c), (Vec3 *) (((Vec3 *) func_ov001_02187fc0(param_1))), (UnkFunc *) (0));
    if (data_0217d20c != 5) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 5;
}

void func_ov001_0218eb94(Unk02188950 *param_1) {
    Unk020f41c4_B *rng;
    func_0207a974((u16) data_021759c0->mUnk_62);
    rng = func_020d22d0();
    rng->mUnk_00 = (s64) rng->mUnk_08 * (s64) rng->mUnk_00 + rng->mUnk_10;
    param_1->mUnk_000.mUnk_04.x = ((Vec3 *) func_ov001_02187fc0(param_1))->x;
    param_1->mUnk_000.mUnk_04.y =
        param_1->mUnk_0a0->mUnk_080 + ((Vec3 *) func_ov001_02187fc0(param_1))->y;
    param_1->mUnk_000.mUnk_04.z = ((Vec3 *) func_ov001_02187fc0(param_1))->z;
    func_ov001_02187218(param_1, 5, (s32 (*)(Unk02188950 *)) func_ov001_0218edb8);
    func_ov001_0218f900(param_1);
    func_ov001_02188e24(param_1, param_1->mUnk_0a0->mUnk_1b4, 0);
    if (data_0217d20c != 5) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 5;
}
