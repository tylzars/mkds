#include "01/code_02184cc8.h"
#include "01/code_02188218.h"
#include "01/code_0218820c.h"
#include "01/code_02185ef4.h"
#include "01/code_02188cd8.h"
#include "01/code_02188da4.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_02021000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020e6000.h"

void func_ov001_02184d9c(Unk02188950 *a) {
    if (func_ov001_0218820c(a) != 0) {
        Vec3 sp = {0, 0, 0};

        sp.y = a->mUnk_0a0->mUnk_1f4;
        func_ov001_02187218(a, 5, 0);
        func_ov001_02188d64(a, a->mUnk_0a0->mUnk_1ec, a->mUnk_0a0->mUnk_1f0);
        func_ov001_02188950(a, &sp);
        func_ov001_02188db8(a, (UnkFunc *) func_ov001_02184d9c);
    } else {
        func_ov001_02187218(a, 0, 0);
    }
}

void func_ov001_02184d70(Unk02188950 *a) {
    func_ov001_02188218(a, (s32) ((u16) a->mUnk_0a0->mUnk_1f8));
    func_ov001_02188c90(a);
    func_ov001_02184d9c(a);
}

void func_ov001_02184cf4(Unk02188950 *a) {
    if (func_ov001_0218820c(a) != 0) {
        Vec3 sp = {0, 0, 0};

        sp.y = a->mUnk_0a0->mUnk_124;
        func_ov001_02187218(a, 5, 0);
        func_ov001_02188d64(a, a->mUnk_0a0->mUnk_11c, a->mUnk_0a0->mUnk_120);
        func_ov001_02188950(a, &sp);
        func_ov001_02188db8(a, (UnkFunc *) func_ov001_02184cf4);
    } else {
        func_ov001_02187218(a, 0, 0);
    }
}

void func_ov001_02184cc8(Unk02188950 *a) {
    func_ov001_02188218(a, (s32) ((u16) a->mUnk_0a0->mUnk_128));
    func_ov001_02188c90(a);
    func_ov001_02184cf4(a);
}
