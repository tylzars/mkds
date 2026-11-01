#include "01/code_02190a20.h"
#include "01/code_02181b54.h"
#include "01/code_02187098.h"
#include "01/code_02188000.h"
#include "01/code_02188218.h"
#include "01/code_02188e88.h"
#include "01/code_021900ac.h"
#include "01/code_02191000.h"
#include "01/code_02191b40.h"
#include "01/code_021924cc.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "01/code_02190000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020a1000.h"

s32 func_ov001_02190d00(Unk02188950 *param_1) {
    Unk02188950 *a;
    Unk02188950 *b;

    a = (data_021759c0->mUnk_08 == 4
             ? func_ov001_02181b68((u16) (data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0))
             : 0);
    b = (data_021759c0->mUnk_08 == 4
             ? func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1))
             : 0);
    if (func_ov001_021871f8(a, 3) && func_ov001_021871f8(b, 3)) {
        func_ov001_02190c08(param_1);
    }
    return 0;
}

void func_ov001_02190c08(Unk02188950 *param_1) {
    Unk02188950 *a;
    Unk02188950 *b;

    if (func_ov001_0218820c(param_1)) {
        func_ov001_02187218(param_1, 3, func_ov001_02190d00);
        func_ov001_02188c90(param_1);
        a = (data_021759c0->mUnk_08 == 4
                 ? func_ov001_02181b68((u16) (data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0))
                 : 0);
        b = (data_021759c0->mUnk_08 == 4
                 ? func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1))
                 : 0);
        func_ov001_021911a8(a);
        func_ov001_021911a8(b);
    } else {
        func_ov001_02187218(param_1, 3, func_ov001_02190d78);
        func_ov001_02188c90(param_1);
        a = (data_021759c0->mUnk_08 == 4
                 ? func_ov001_02181b68((u16) (data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0))
                 : 0);
        b = (data_021759c0->mUnk_08 == 4
                 ? func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1))
                 : 0);
        func_ov001_021918c8(a);
        func_ov001_021918c8(b);
    }
}

s32 func_ov001_02190b58(Unk02188950 *param_1) {
    Unk02188950 *a;
    Unk02188950 *b;

    a = (data_021759c0->mUnk_08 == 4
             ? func_ov001_02181b68((u16) (data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0))
             : 0);
    b = (data_021759c0->mUnk_08 == 4
             ? func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1))
             : 0);
    func_ov001_02188998(param_1, &func_0207a974((u16) data_021759c0->mUnk_62)->mUnk_80);
    func_ov001_021924cc();
    if (func_ov001_021871f8(a, 3) && func_ov001_021871f8(b, 3)) {
        func_ov001_02188218(param_1, (s32) ((u16) param_1->mUnk_0a0->mUnk_1ec));
        func_ov001_02190c08(param_1);
    }
    return 0;
}

void func_ov001_02190acc(Unk02188950 *param_1) {
    Unk02188950 *a;
    Unk02188950 *b;

    func_0207a974((u16) data_021759c0->mUnk_62);
    func_ov001_02187218(param_1, 3, func_ov001_02190b58);
    func_ov001_02188c90(param_1);
    a = (data_021759c0->mUnk_08 == 4
             ? func_ov001_02181b68((u16) (data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0))
             : 0);
    b = (data_021759c0->mUnk_08 == 4
             ? func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1))
             : 0);
    func_ov001_02191bc0(a);
    func_ov001_02191bc0(b);
}

s32 func_ov001_02190a20(Unk02188950 *param_1) {
    Unk02188950 *a;
    Unk02188950 *b;

    a = (data_021759c0->mUnk_08 == 4
             ? func_ov001_02181b68((u16) (data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0))
             : 0);
    b = (data_021759c0->mUnk_08 == 4
             ? func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1))
             : 0);
    func_ov001_02188998(param_1, &func_0207a974((u16) data_021759c0->mUnk_62)->mUnk_80);
    func_ov001_021924cc();
    if (func_ov001_021871f8(a, 3) && func_ov001_021871f8(b, 3)) {
        param_1->mUnk_0a8 = param_1->mUnk_0a8 == 4 ? 5 : 4;
        func_ov001_02190948(param_1);
    }
    return 0;
}
