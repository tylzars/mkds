#include "01/code_0219dd94.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02037000.h"

void func_ov001_0219dd94(void) {
    s32 i;
    s32 j;
    s16 v;

    data_ov001_021a9bfc->mUnk_14++;
    v = func_020ae4c0(1, 250, 0, data_ov001_021a9bfc->mUnk_14, 10);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < data_ov001_021a6c28[i]; j++) {
            if (i == 1) {
                data_ov001_021a9bfc->mUnk_18[i].mUnk_00 = v;
            } else {
                data_ov001_021a9bfc->mUnk_18[i].mUnk_00 = -v;
            }
        }
    }
    if (data_ov001_021a9bfc->mUnk_14 >= 10) {
        data_ov001_021a9bfc->mUnk_04 = 2;
        data_ov001_021a9bfc->mUnk_14 = 0;
        func_02128374();
    }
}
