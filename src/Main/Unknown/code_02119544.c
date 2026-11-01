#include "Main/Unknown/code_02119544.h"

#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_02119ac4.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/unk_0217d000.h"

#pragma thumb on
void func_02119544(void) {
    s16 v;
    s32 w;
    s32 i;

    data_0217d364->mUnk_3c++;
    if (*(vu16 *) 0x027ffc40 != 2) {
        func_020ae4c0(1, 0x100, 0, data_0217d364->mUnk_3c, 10);
        v = func_020ae4c0(1, -0xc0, 0, data_0217d364->mUnk_3c, 10);
        if (func_020cccb4() != 0x1a) {
            w = data_0217d364->mUnk_04->mUnk_06;
            data_0217d364->mUnk_44 = v;
            data_0217d364->mUnk_1c[0].mUnk_06 = v;
            data_0217d364->mUnk_1c[2].mUnk_06 = v;
            data_0217d364->mUnk_1c[1].mUnk_06 = v;
            data_0217d364->mUnk_1c[4].mUnk_06 = v;
            data_0217d364->mUnk_1c[3].mUnk_06 = v;
            data_0217d364->mUnk_1c[5].mUnk_06 = v;
            data_0217d364->mUnk_1c[w].mUnk_06 = v;
            data_0217d364->mUnk_1c[w + 1].mUnk_06 = v;
            data_0217d364->mUnk_1c[w + 2].mUnk_06 = v;
            data_0217d364->mUnk_1c[w + 3].mUnk_06 = v;
            data_0217d364->mUnk_1c[w + 4].mUnk_06 = v;
            data_0217d364->mUnk_1c[w + 5].mUnk_06 = v;
        }
        if (func_020cccb4() == 0x1a) {
            w = data_0217d364->mUnk_10->mUnk_06;
            data_0217d364->mUnk_48 = v - 0x20;
            data_0217d364->mUnk_20[0x14].mUnk_06 = v - 0x20;
            data_0217d364->mUnk_20[0x13].mUnk_06 = v - 0x20;
            data_0217d364->mUnk_20[2].mUnk_06 = v - 0x20;
            data_0217d364->mUnk_20[1].mUnk_06 = v - 0x20;
            data_0217d364->mUnk_20[0].mUnk_06 = v - 0x20;
            for (i = 0; i < 8; i++) {
                data_0217d364->mUnk_20[data_0215cacc[i]].mUnk_06 = v - 0x20;
            }
            v -= 0x20;
            for (i = 0; i < 4; i++) {
                data_0217d364->mUnk_20[data_0215caa4[i]].mUnk_06 = v;
                data_0217d364->mUnk_20[w + data_0215cab4[i]].mUnk_06 = v;
            }
        }
    }
    if (data_0217d364->mUnk_3c >= 10) {
        func_02119bf0();
    }
}
#pragma thumb off
