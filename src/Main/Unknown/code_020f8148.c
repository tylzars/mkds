#include "Main/Unknown/code_020f8148.h"

#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020f7c90.h"

#pragma thumb on

u8 *func_020f8148(Unk0217bc6c *param_1, u8 *param_2) {
    s32 a;
    s32 b;
    s32 i;
    s32 j;
    u16(*tab)[0x12];

    a = *param_2++;
    b = *param_2++;
    param_1->mUnk_00 = a;
    param_1->mUnk_04 = func_02036bec(func_020364e0(func_020364e8()), (a + 1) * 0x24);
    tab = param_1->mUnk_04;
    for (i = 0; i < b; i++) {
        for (j = 0; j < a; j++) {
            tab[j][i] = *param_2++;
        }
        tab[j][i] = 0xffff;
    }
    return param_2;
}

#pragma thumb off
