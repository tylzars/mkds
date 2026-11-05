#include "Main/Unknown/code_020ad028.h"
#include "Main/Unknown/code_020acbe8.h"
#include "Main/Unknown/code_020adaf8.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma optimize_for_size on
#pragma thumb on

void func_020ad028(void) {
    Unk02124b1c *p;
    u32 w;
    s32 i;

    p = data_0217b340->mUnk_68;
    w = func_020acbe8(data_0217b340->mUnk_6c);
    for (i = 0; i <= 9; i++) {
        p[i].mUnk_00 = 1;
    }
    for (i = 10; i <= 14; i++) {
        p[i].mUnk_00 = 0;
    }
    for (i = 0; i <= 1; i++) {
        p[w + i].mUnk_00 = 1;
    }
    func_02124100(0, 15, data_0217b340->mUnk_74, p, data_0217b340->mUnk_6c);
    func_02124100(1, 15, data_0217b340->mUnk_74, p, data_0217b340->mUnk_6c);
    switch (data_0217b340->mUnk_54) {
        case 0:
            if (data_0217b340->mUnk_0c == 4) {
                p[0].mUnk_04 = data_0217b340->mUnk_60;
                p[5].mUnk_04 = data_0217b340->mUnk_60;
                p[10].mUnk_04 = data_0217b340->mUnk_60;
            }
            if (data_0217b340->mUnk_0c != 4 || data_0217b340->mUnk_58 == FALSE || func_020adaf8() >= 5) {
                p[5].mUnk_00 = 0;
                p[10].mUnk_00 = 1;
            }
            break;
        case 1:
            if (data_0217b340->mUnk_0c == 4) {
                p[1].mUnk_04 = data_0217b340->mUnk_60;
                p[6].mUnk_04 = data_0217b340->mUnk_60;
                p[11].mUnk_04 = data_0217b340->mUnk_60;
            }
            if (data_0217b340->mUnk_0c != 4 || data_0217b340->mUnk_58 == FALSE || func_020adaf8() >= 5) {
                p[6].mUnk_00 = 0;
                p[11].mUnk_00 = 1;
            }
            break;
        case 2:
            if (data_0217b340->mUnk_0c == 4) {
                p[2].mUnk_04 = data_0217b340->mUnk_60;
                p[7].mUnk_04 = data_0217b340->mUnk_60;
                p[12].mUnk_04 = data_0217b340->mUnk_60;
            }
            if (data_0217b340->mUnk_0c != 4 || data_0217b340->mUnk_58 == FALSE || func_020adaf8() >= 5) {
                p[7].mUnk_00 = 0;
                p[12].mUnk_00 = 1;
            }
            break;
        case 3:
            if (data_0217b340->mUnk_0c != 4 || data_0217b340->mUnk_58 == FALSE || func_020adaf8() >= 5) {
                p[8].mUnk_00 = 0;
                p[13].mUnk_00 = 1;
                func_02124100(0, 14, data_0217b340->mUnk_74, p, data_0217b340->mUnk_6c);
            }
            break;
        case 4:
            if (data_0217b340->mUnk_0c != 4 || data_0217b340->mUnk_58 == FALSE || func_020adaf8() >= 5) {
                p[9].mUnk_00 = 0;
                p[14].mUnk_00 = 1;
                func_02124100(1, 14, data_0217b340->mUnk_74, p, data_0217b340->mUnk_6c);
            }
            break;
    }
}

#pragma thumb off
