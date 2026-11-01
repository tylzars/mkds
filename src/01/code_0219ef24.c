#include "01/code_0219ef24.h"
#include "01/code_0219efec.h"
#include "01/code_0219e000.h"
#include "01/code_0219f000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02105000.h"

void func_ov001_0219ef24(void) {
    s32 i;
    s32 j;
    s32 count;
    s16 value;

    func_021059e0();
    count = data_ov001_021ca410->mUnk_04->mUnk_06;
    data_ov001_021ca410->mUnk_24 = data_ov001_021ca410->mUnk_24 + 1;
    value = func_020ae4c0(1, data_ov001_021ca410->mUnk_48, 0, data_ov001_021ca410->mUnk_24, 10);
    data_ov001_021ca410->mUnk_44 = func_020ae4c0(1, -192, 0, data_ov001_021ca410->mUnk_24, 10);
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 11; j++) {
            data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][j]].mUnk_04 = value;
        }
        data_ov001_021ca410->mUnk_10[count + data_ov001_021a6c60[i]].mUnk_04 = value;
    }
    if (data_ov001_021ca410->mUnk_24 >= 10) {
        func_ov001_0219f244();
    }
}
