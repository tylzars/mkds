#include "Main/Unknown/code_020acb08.h"
#include "Main/Unknown/code_020acbe8.h"
#include "Main/Unknown/code_020acff4.h"
#include "Main/Unknown/code_020adad0.h"
#include "Main/Unknown/code_020adaf8.h"
#include "Main/Unknown/code_020ae428.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/unk_0217b000.h"

u32 func_020acbc0(void) {
    return data_0217aa08->mUnk_00->mUnk_31_0 != 0;
}

#pragma optimize_for_size on
#pragma thumb on

void func_020acb08(void) {
    u32 w;
    s32 i;
    Unk02124b1c *p;

    p = data_0217b340->mUnk_68;
    w = func_020acbe8((u32) data_0217b340->mUnk_6c);
    if (func_020adaf8() < 10) {
        for (i = 0; i <= 14; i++) {
            p[i].mUnk_04 = func_020ae4c0(1, 0, 0xf8, func_020adaf8(), 10);
        }
        for (i = 0; i <= 1; i++) {
            p[i + w].mUnk_04 = func_020ae4c0(1, 0, 0xf8, func_020adaf8(), 10);
        }
    } else {
        for (i = 0; i <= 14; i++) {
            p[i].mUnk_04 = 0xf8;
        }
        for (i = 0; i <= 1; i++) {
            p[i + w].mUnk_04 = 0xf8;
        }
        if (func_020acbc0() != 0) {
            func_020adad0(data_0217b340->mUnk_10, 8);
        } else {
            func_020adad0(6, 8);
        }
    }
    func_020acff4();
}

#pragma thumb off
