#include "00/code_0218523c.h"
#include "00/code_02184bec.h"
#include "00/code_021806a0.h"
#include "00/code_021804f4.h"
#include "00/code_ov000_021804e0.h"
#include "00/code_02185164.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0204799c.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_021281b4.h"

void func_ov000_0218523c(void *a) {
    s32 i;
    s32 j;
    u32 b;
    void *c;

    data_ov000_021b4c84 = func_02036bec(a, 0x40);
    data_ov000_021b4c84->mUnk_18 = a;
    data_ov000_021b4c84->mUnk_00 = 0;
    data_ov000_021b4c84->mUnk_04 = 0;
    data_ov000_021b4c84->mUnk_10 = -1;
    b = func_ov000_021806d4();
    switch (b) {
        case 1:
        case 11:
            data_ov000_021b4c84->mUnk_08 = 0;
            break;
        case 9:
            data_ov000_021b4c84->mUnk_08 = 1;
            break;
    }
    data_ov000_021b4c84->mUnk_0c = 0;
    data_ov000_021b4c84->mUnk_14 = 1;
    func_ov000_021851a0();
    for (i = 0; i < 2; i++) {
        func_02124a98(data_ov000_021b06c0[i], 1, data_ov000_021b4c84->mUnk_20, data_ov000_021b4c84->mUnk_2c);
    }
    c = func_ov000_021804f4();
    func_020ae6d4(c, func_ov000_021804e0());
    func_02124ed0(a, data_ov000_021b4c84->mUnk_2c, 0, &data_ov000_021b4c84->mUnk_1c);
    data_ov000_021b4c84->mUnk_38 = func_0204799c(data_ov000_021b0ee8);
    data_ov000_021b4c84->mUnk_3c = func_02047a28(data_ov000_021b0ef4);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < data_ov000_021b06c8[i]; j++) {
            data_ov000_021b4c84->mUnk_1c[data_ov000_021b06d0[i][j]].mUnk_04 = 0xfa;
        }
    }
    func_021281c8(0xe);
}
