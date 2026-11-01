#include "Main/Unknown/code_020d24d8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_0217c000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02024000.h"

void func_020d2668(Unk020e71a0 *param_1, Unk0210bfbc *param_2, s32 param_3, s32 param_4) {
    s32 a;
    a = param_1->mUnk_98->mUnk_24;
    if (a == -1) {
        return;
    }
    if (param_1->mUnk_78 & 0x40000000) {
        return;
    }
    if (param_1->mUnk_94 != 0) {
        func_02024a28(&param_1->mUnk_94->mUnk_00, a, param_4, param_3);
    } else {
        func_02024a28(param_2, a, param_4, param_3);
    }
}

void func_020d2600(s32 param_1, Vec3 *param_2, s32 param_3) {
    s32 a;
    Unk0210b7a8 b;
    a = func_020d4ef4(param_2);
    if (a >= (param_3 == 2 ? data_0217ca6c[2].mUnk_20 : data_0217ca6c[4].mUnk_20)) {
        return;
    }
    b.mUnk_00 = param_1;
    b.mUnk_04 = param_2;
    b.mUnk_08 = param_3;
    b.mUnk_0c = a;
    func_0210b7a8(&b);
}

void func_020d2584(Unk020e71a0 *param_1, s32 param_2) {
    s32 a;
    param_1->mUnk_58.y = (s64) param_2 * param_1->mUnk_1c.y >> 12;
    if (param_1->mUnk_64 < 0) {
        return;
    }
    switch (param_1->mUnk_98->mUnk_08) {
        case 3:
        case 4:
        case 5:
            a = func_021482cc(&param_1->mUnk_58);
            break;
        case 0:
        case 1:
        case 2:
        default:
            a = param_1->mUnk_58.x;
            break;
    }
    func_020d5148(param_1->mUnk_64, a);
}

s32 func_020d252c(Unk020e71a0 *param_1) {
    switch (param_1->mUnk_98->mUnk_08) {
        case 3:
        case 4:
        case 5:
            return func_021482cc(&param_1->mUnk_58);
        case 0:
        case 1:
        case 2:
        default:
            return param_1->mUnk_58.x;
    }
}

void func_020d24d8(Unk020e71a0 *param_1, s32 param_2) {
    s32 a;
    param_1->mUnk_6c = param_2;
    if (data_021759c0->mUnk_00c == 3) {
        param_1->mUnk_6c = 0x270f000;
        return;
    }
    a = data_02175620->mUnk_018->mUnk_20;
    if (a == 0) {
        return;
    }
    if (param_1->mUnk_6c > a) {
        param_1->mUnk_6c = a;
    }
}
