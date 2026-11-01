#include "Main/Unknown/code_020d278c.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02109110.h"
#include "Main/Unknown/code_0210cf9c.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "code_02147cd8.h"

void func_020d29cc(Unk020e71a0 *param_1, Vec3 *param_2) {
    s32 a;
    Unk020e71a0_98 *b;
    s32 c;
    param_1->mUnk_1c.x = param_2->x;
    param_1->mUnk_1c.y = param_2->y;
    param_1->mUnk_1c.z = param_2->z;
    param_1->mUnk_58.x = (s64) param_1->mUnk_98->mUnk_0c * param_1->mUnk_1c.x >> 12;
    if (param_1->mUnk_64 >= 0) {
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
    param_1->mUnk_58.y = (s64) param_1->mUnk_98->mUnk_10 * param_1->mUnk_1c.y >> 12;
    if (param_1->mUnk_64 >= 0) {
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
    param_1->mUnk_58.z = (s64) param_1->mUnk_98->mUnk_14 * param_1->mUnk_1c.z >> 12;
    if (param_1->mUnk_64 >= 0) {
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
    a = param_1->mUnk_1c.x;
    b = param_1->mUnk_98;
    c = b->mUnk_2c;
    if (a < param_1->mUnk_1c.y) {
        a = param_1->mUnk_1c.y;
    }
    if (a < param_1->mUnk_1c.z) {
        a = param_1->mUnk_1c.z;
    }
    param_1->mUnk_68 = (s64) c * a >> 12;
}

void func_020d2950(Unk020e71a0 *param_1, s32 param_2) {
    s32 a;
    param_1->mUnk_58.x = (s64) param_2 * param_1->mUnk_1c.x >> 12;
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

void func_020d28e0(Unk020e71a0 *param_1) {
    param_1->mUnk_94 = func_02036bec(func_020364e0(func_020364e8()), 0x44);
    func_02109110(&param_1->mUnk_94->mUnk_00, 2, &param_1->mUnk_04);
    param_1->mUnk_70 = data_0217ca6c[2].mUnk_20;
    func_0210cf9c(&param_1->mUnk_94->mUnk_00, 0);
    if (param_1->mUnk_94->mUnk_00.mUnk_34 & 1) {
        func_0210cfbc(&param_1->mUnk_94->mUnk_00, 2, 1);
    }
}

Unk0210b7ec *func_020d286c(Unk020e71a0 *param_1) {
    param_1->mUnk_94 = func_02036bec(func_020364e0(func_020364e8()), 0x60);
    func_02109110(&param_1->mUnk_94->mUnk_00, 2, &param_1->mUnk_04);
    param_1->mUnk_70 = data_0217ca6c[2].mUnk_20;
    func_0210cf9c(&param_1->mUnk_94->mUnk_00, 0);
    if (param_1->mUnk_94->mUnk_00.mUnk_34 & 1) {
        func_0210cfbc(&param_1->mUnk_94->mUnk_00, 2, 1);
    }
    return &param_1->mUnk_94->mUnk_44;
}

void func_020d27fc(Unk020e71a0 *param_1) {
    param_1->mUnk_94 = func_02036bec(func_020364e0(func_020364e8()), 0x44);
    func_02109110(&param_1->mUnk_94->mUnk_00, 3, &param_1->mUnk_04);
    param_1->mUnk_70 = data_0217ca6c[3].mUnk_20;
    func_0210cf9c(&param_1->mUnk_94->mUnk_00, 0);
    if (param_1->mUnk_94->mUnk_00.mUnk_34 & 1) {
        func_0210cfbc(&param_1->mUnk_94->mUnk_00, 2, 1);
    }
}

void func_020d278c(Unk020e71a0 *param_1) {
    param_1->mUnk_94 = func_02036bec(func_020364e0(func_020364e8()), 0x44);
    func_02109110(&param_1->mUnk_94->mUnk_00, 4, &param_1->mUnk_04);
    param_1->mUnk_70 = data_0217ca6c[4].mUnk_20;
    func_0210cf9c(&param_1->mUnk_94->mUnk_00, 0);
    if (param_1->mUnk_94->mUnk_00.mUnk_34 & 1) {
        func_0210cfbc(&param_1->mUnk_94->mUnk_00, 2, 1);
    }
}
