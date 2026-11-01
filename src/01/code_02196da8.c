#include "01/code_02196da8.h"
#include "01/code_02195a6c.h"
#include "Main/Unknown/code_0205f000.h"
#include "Main/Unknown/code_02126000.h"

void func_ov001_02196dbc(void) {
    s32 i;
    s32 n;
    s32 k;
    u8 buf[0x10];
    u16 str[0x100];

    i = 0;
    n = 0;
    k = 0;
    data_ov001_021a9bdc->mUnk_54 = 14;
    data_ov001_021a9bdc->mUnk_58 = i;
    func_0205fdb4(data_ov001_021a6900[data_ov001_021a9bdc->mUnk_6c], buf);
    while (n < 19) {
        k++;
        if (k > 4) {
            k = 0;
            str[n] = ' ';
            n++;
        } else {
            str[n] = buf[i];
            n++;
            i++;
        }
    }
    str[n] = 0;
    func_02126248((u32) str, 0, 1, 0, 0, 0);
}

void func_ov001_02196da8(void) {
    data_ov001_021a9bdc->mUnk_54 = 15;
    data_ov001_021a9bdc->mUnk_58 = 0;
}
