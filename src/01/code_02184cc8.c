#include "01/code_02184cc8.h"
#include "01/code_02188218.h"
#include "01/code_0218820c.h"
#include "01/code_02187098.h"
#include "01/code_02188cd8.h"
#include "01/code_02188da4.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_02021000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020e6000.h"

void func_ov001_02184d9c(Unk02188950 *param_1) {
    if (func_ov001_0218820c(param_1) != 0) {
        Vec3 sp = {0, 0, 0};

        sp.y = param_1->mUnk_0a0->mUnk_1f4;
        func_ov001_02187218(param_1, 5, 0);
        func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_1ec, param_1->mUnk_0a0->mUnk_1f0);
        func_ov001_02188950(param_1, &sp);
        func_ov001_02188db8(param_1, (UnkFunc *) func_ov001_02184d9c);
    } else {
        func_ov001_02187218(param_1, 0, 0);
    }
}

void func_ov001_02184d70(Unk02188950 *param_1) {
    func_ov001_02188218(param_1, (s32) ((u16) param_1->mUnk_0a0->mUnk_1f8));
    func_ov001_02188c90(param_1);
    func_ov001_02184d9c(param_1);
}

void func_ov001_02184cf4(Unk02188950 *param_1) {
    if (func_ov001_0218820c(param_1) != 0) {
        Vec3 sp = {0, 0, 0};

        sp.y = param_1->mUnk_0a0->mUnk_124;
        func_ov001_02187218(param_1, 5, 0);
        func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_11c, param_1->mUnk_0a0->mUnk_120);
        func_ov001_02188950(param_1, &sp);
        func_ov001_02188db8(param_1, (UnkFunc *) func_ov001_02184cf4);
    } else {
        func_ov001_02187218(param_1, 0, 0);
    }
}

void func_ov001_02184cc8(Unk02188950 *param_1) {
    func_ov001_02188218(param_1, (s32) ((u16) param_1->mUnk_0a0->mUnk_128));
    func_ov001_02188c90(param_1);
    func_ov001_02184cf4(param_1);
}
