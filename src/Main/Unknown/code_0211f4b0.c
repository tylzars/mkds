#include "Main/Unknown/code_0211f4b0.h"
#include "Main/Unknown/code_0211f394.h"
#include "Main/Unknown/code_0211f61c.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0204799c.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_02116dd4.h"
#include "Main/Unknown/code_02148ca0.h"
#include "Main/Unknown/unk_0217d000.h"

#pragma thumb on

void func_0211f5e4(void) {
    u16 a;

    data_0217d380->mUnk_20 = 0;
    data_0217d380->mUnk_24 = 0;
    a = data_0217d380->mUnk_04->mUnk_06;
    data_0217d380->mUnk_10[0x2a].mUnk_06 = 0xc0;
    data_0217d380->mUnk_10[a + 0xe].mUnk_06 = 0xc0;
}

void func_0211f5d0(void) {
    data_0217d380->mUnk_20 = 1;
    data_0217d380->mUnk_24 = 0;
}

void func_0211f598(void) {
    u16 a;

    data_0217d380->mUnk_20 = 2;
    data_0217d380->mUnk_24 = 0;
    a = data_0217d380->mUnk_04->mUnk_06;
    data_0217d380->mUnk_10[0x2a].mUnk_06 = 0;
    data_0217d380->mUnk_10[a + 0xe].mUnk_06 = 0;
}

void func_0211f4b0(void *a, void *b) {
    Unk0217d380 *p;
    s32 i;
    u16 n;
    u32 v;

    data_0217d380 = func_02036bec(a, 0x28);
    data_0217d380->mUnk_1c = 1;
    data_0217d380->mUnk_18 = b;
    func_0211f61c();
    func_02124ed0(a, data_0217d380->mUnk_04, data_0217d380->mUnk_0c, &data_0217d380->mUnk_10);
    data_0217d380->mUnk_14 = func_02047a28("common.bmg");
    v = func_02148ca0();
    func_021243ac(a, 0xe, data_0217d380->mUnk_0c, 0xc8, 0xd, 0, data_0217d380->mUnk_00, data_0217d380->mUnk_04,
                  data_0217d380->mUnk_10, v);
    p = data_0217d380;
    func_0212426c(1, 0xe, data_0217d380->mUnk_0c, func_020b3f7c(p->mUnk_14, 0x79), p->mUnk_04, p->mUnk_10);
    i = 0;
    n = data_0217d380->mUnk_04->mUnk_06;
    for (; i < n; i++) {
        data_0217d380->mUnk_10[i].mUnk_00 = 0;
    }
    data_0217d380->mUnk_10[0x2a].mUnk_00 = 1;
    func_02116dd4(a, data_0217d380->mUnk_00, data_0217d380->mUnk_04, 0x2a, 0xe, 1);
    func_0211f5e4();
    func_0211f5d0();
    func_0211f39c();
}

#pragma thumb off
