#include "01/code_0218e38c.h"
#include "01/code_021827f0.h"
#include "01/code_02187098.h"
#include "01/code_02188158.h"
#include "01/code_021882b8.h"
#include "01/code_02188cd8.h"
#include "01/code_02188e24.h"
#include "01/code_0218e690.h"
#include "01/code_0218f900.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"

void func_ov001_0218e58c(void) {
    func_ov001_021882b8();
}

void func_ov001_0218e564(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d30(param_1, param_1->mUnk_0a0->mUnk_058, param_1->mUnk_0a0->mUnk_05c, func_ov001_0218e760);
}

void func_ov001_0218e520(Unk02188950 *param_1) {
    param_1->mUnk_000.mUnk_04.y += param_1->mUnk_0a0->mUnk_080;
    func_ov001_02187218(param_1, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_04c, param_1->mUnk_0a0->mUnk_050);
    func_ov001_02188e24(param_1, param_1->mUnk_0a0->mUnk_054, func_ov001_0218e564);
}

void func_ov001_0218e508(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_0218f900(param_1);
}

void func_ov001_0218e4ac(Unk02188950 *param_1) {
    param_1->mUnk_000.mUnk_04.y += param_1->mUnk_0a0->mUnk_080;
    param_1->mUnk_16c = 0;
    param_1->mUnk_168 = param_1->mUnk_16c;
    param_1->mUnk_168 = 0;
    func_ov001_02187218(param_1, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_034, param_1->mUnk_0a0->mUnk_038);
    func_ov001_02188e24(param_1, param_1->mUnk_0a0->mUnk_03c, func_ov001_0218e508);
}

void func_ov001_0218e474(Unk02188950 *param_1) {
    param_1->mUnk_000.mUnk_94 = func_02036bec((void *) func_020364e0(func_020364e8()), 0x44);
    func_02109110((Unk0210bfbc *) (param_1->mUnk_000.mUnk_94), (u32) (0xe), (Vec3 *) (&param_1->mUnk_000.mUnk_04));
    param_1->mUnk_000.mUnk_70 = data_0217cc6c[6];
}

void func_ov001_0218e38c(Unk02188950 *param_1, Unk0206bcb0 *param_2) {
    param_1->mUnk_000.mUnk_10.x =
        ((s64) -param_1->mUnk_0a0->mUnk_024 * data_0215d4b4[(param_2->mUnk_236 >> 4) * 2]) >> 12;
    param_1->mUnk_000.mUnk_10.y = 0;
    param_1->mUnk_000.mUnk_10.z =
        ((s64) -param_1->mUnk_0a0->mUnk_024 * data_0215d4b4[(param_2->mUnk_236 >> 4) * 2 + 1]) >> 12;
    func_ov001_021829ac(param_1->mUnk_0a0->mUnk_190);
    func_ov001_0218ead0(param_1);
    param_1->mUnk_2d8 = 0;
    func_ov001_02188200(param_1, (UnkFunc *) (func_ov001_0218f9a8));
    func_ov001_0218e860(param_1);
    param_1->mUnk_0a8 = 0;
    func_020d2774(&param_1->mUnk_000, (u32) (0x22c));
    param_1->mUnk_25c = param_1->mUnk_268 = param_1->mUnk_264 = param_1->mUnk_270 = param_1->mUnk_0a0->mUnk_00c;
}
