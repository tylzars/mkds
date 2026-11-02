#include "Main/Unknown/code_02116084.h"

#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_02114000.h"
#include "Main/Unknown/code_02116870.h"

#pragma thumb on

u16 data_0215c4ac[2] = {0x1e, 0x1f};

void func_02116084(void) {
    s32 v;
    BOOL a;
    BOOL b;
    s32 i;

    v = func_02116870();
    data_0217d350->mUnk_3c[data_0215c4a8[0]].mUnk_04 = -func_020adc64(6 - data_0217d350->mUnk_90[0]);
    data_0217d350->mUnk_3c[data_0215c4a8[1]].mUnk_04 = func_020adc64(6 - data_0217d350->mUnk_90[1]);
    a = FALSE;
    b = FALSE;
    for (i = 0; i < 2; i++) {
        if (data_0217d350->mUnk_90[i] > 0) {
            data_0217d350->mUnk_90[i]--;
            data_0217d350->mUnk_3c[data_0215c4ac[i]].mUnk_00 = a;
            data_0217d350->mUnk_3c[data_0215c4a8[i]].mUnk_00 = 1;
        } else {
            data_0217d350->mUnk_3c[data_0215c4ac[i]].mUnk_00 = 1;
            data_0217d350->mUnk_3c[data_0215c4a8[i]].mUnk_00 = b;
        }
    }
    if (v == 0) {
        data_0217d350->mUnk_3c[data_0215c4ac[0]].mUnk_00 = 0;
    }
    if (v + 5 >= func_021143b4()) {
        data_0217d350->mUnk_3c[data_0215c4ac[1]].mUnk_00 = 0;
    }
}

#pragma thumb off
