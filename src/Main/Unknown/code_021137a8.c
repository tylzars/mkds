#include "Main/Unknown/code_021137a8.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/code_02113f1c.h"
#include "Main/Unknown/code_02114158.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "01/code_02195a6c.h"
#include "code_0212df7c.h"

#pragma thumb on

void func_021137f4(void) {
    s32 i;
    u16 a;

    a = func_02113f1c();
    data_0217d348->mUnk_3c[data_0215c3ac[0]].mUnk_04 = -func_020adc64(6 - data_0217d348->mUnk_80[0]);
    data_0217d348->mUnk_3c[data_0215c3ac[1]].mUnk_04 = func_020adc64(6 - data_0217d348->mUnk_80[1]);
    for (i = 0; i < 2; i++) {
        if (data_0217d348->mUnk_80[i] > 0) {
            data_0217d348->mUnk_80[i]--;
            data_0217d348->mUnk_3c[data_0215c3b0[i]].mUnk_00 = 0;
            data_0217d348->mUnk_3c[data_0215c3ac[i]].mUnk_00 = 1;
        } else {
            data_0217d348->mUnk_3c[data_0215c3b0[i]].mUnk_00 = 1;
            data_0217d348->mUnk_3c[data_0215c3ac[i]].mUnk_00 = 0;
        }
    }
    if (a == 0) {
        data_0217d348->mUnk_3c[data_0215c3b0[0]].mUnk_00 = 0;
    }
    if (a + 5 >= func_021143b4()) {
        data_0217d348->mUnk_3c[data_0215c3b0[1]].mUnk_00 = 0;
    }
}

void func_021137a8(s32 a) {
    s32 b;

    b = func_02113f1c();
    b += a;
    if (func_02114398(b)) {
        func_02114260(b);
        func_0212ecc0(&data_0217d068, 0, 0x25);
    } else {
        func_0211427c(b);
        func_0212ecc0(&data_0217d068, 0, 0x24);
    }
}

#pragma thumb off
