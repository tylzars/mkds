#include "Main/Unknown/code_020acf04.h"
#include "Main/Unknown/code_020acbe8.h"
#include "Main/Unknown/code_020acff4.h"
#include "Main/Unknown/code_020adad0.h"
#include "Main/Unknown/code_020adaf8.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020acb08.h"

#pragma optimize_for_size on
#pragma thumb on

void func_020acf44(void) {
    u32 w;
    s32 i;
    Unk02124b1c *p;

    p = data_0217b340->mUnk_68;
    w = func_020acbe8((u32) data_0217b340->mUnk_6c);
    if (func_020adaf8() < 10) {
        for (i = 0; i <= 14; i++) {
            p[i].mUnk_04 = func_020ae4c0(1, 0xf8, 0, func_020adaf8(), 10);
        }
        for (i = 0; i <= 1; i++) {
            p[i + w].mUnk_04 = func_020ae4c0(1, 0xe4, 0, func_020adaf8(), 10);
        }
    } else {
        for (i = 0; i <= 14; i++) {
            p[i].mUnk_04 = 0;
        }
        for (i = 0; i <= 1; i++) {
            p[i + w].mUnk_04 = 0;
        }
        func_020adad0(2, 8);
        data_0217b340->mUnk_58 = 0;
    }
    func_020acff4();
}

void func_020acf04(void) {
    switch (data_0217b340->mUnk_54) {
        case 0:
        case 1:
        case 2:
            func_02105ac0(9);
            break;
        case 3:
        case 4:
            func_02105ac0(8);
            break;
        default:
            break;
    }
}

#pragma thumb off
