#include "Main/Unknown/code_0211f394.h"
#include "Main/Unknown/code_0211f4b0.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_02116a4c.h"
#include "00/code_02182fdc.h"
#include "Main/Unknown/unk_0217d000.h"

#pragma thumb on

void func_0211f440(void) {
    u16 a;
    s16 v;

    a = data_0217d380->mUnk_04->mUnk_06;
    data_0217d380->mUnk_24++;
    v = func_020ae4c0(1, 0xc0, 0, data_0217d380->mUnk_24, 10);
    data_0217d380->mUnk_10[0x2a].mUnk_06 = v;
    data_0217d380->mUnk_10[a + 0xe].mUnk_06 = v;
    if (data_0217d380->mUnk_24 >= 10) {
        func_0211f5d0();
    }
}

void func_0211f3e8(void) {
    u16 a;
    s16 v;

    a = data_0217d380->mUnk_04->mUnk_06;
    data_0217d380->mUnk_24++;
    v = func_020ae4c0(1, 0, 0xc0, data_0217d380->mUnk_24, 10);
    data_0217d380->mUnk_10[0x2a].mUnk_06 = v;
    data_0217d380->mUnk_10[a + 0xe].mUnk_06 = v;
    if (data_0217d380->mUnk_24 >= 10) {
        func_0211f5d0();
    }
}

void func_0211f39c(void) {
    data_0217d380->mUnk_1c = data_0217d380->mUnk_20;
    switch (data_0217d380->mUnk_1c) {
        case 0:
            func_0211f440();
            break;
        case 1:
            break;
        case 2:
            func_0211f3e8();
            break;
    }
    func_02116d24();
    func_02124c30(data_0217d380->mUnk_04, data_0217d380->mUnk_00, data_0217d380->mUnk_0c, data_0217d380->mUnk_18,
                  data_0217d380->mUnk_10);
}

void func_0211f394(void) {
    func_0211f5e4();
}

#pragma thumb off
