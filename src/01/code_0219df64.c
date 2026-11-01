#include "01/code_0219df64.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02037000.h"

void func_ov001_0219df70(void *param_1) {
    s32 i;
    Unk021a9bfc *p;
    void *ptr;

    data_ov001_021a9bfc = func_02036bec(param_1, 0x58);
    data_ov001_021a9bfc->mUnk_30 = param_1;
    data_ov001_021a9bfc->mUnk_00 = 0;
    data_ov001_021a9bfc->mUnk_04 = 0;
    data_ov001_021a9bfc->mUnk_08 = 0;
    data_ov001_021a9bfc->mUnk_14 = 0;
    data_ov001_021a9bfc->mUnk_24 = 1;
    func_ov001_0219de58();
    for (i = 0; i < 2; i++) {
        func_02124a98(data_ov001_021a6c38[i][0], 1, data_ov001_021a9bfc->mUnk_38, data_ov001_021a9bfc->mUnk_44);
    }
    func_020ae6d4(func_ov001_0219e920(), func_ov001_0219e90c());
    func_02124ed0(param_1, data_ov001_021a9bfc->mUnk_44, data_ov001_021a9bfc->mUnk_4c, &data_ov001_021a9bfc->mUnk_34);
    data_ov001_021a9bfc->mUnk_50 = func_0204799c("option.bmg");
    data_ov001_021a9bfc->mUnk_54 = func_02047a28("common.bmg");
    func_021243ac(param_1, 0, data_ov001_021a9bfc->mUnk_4c, 0xa0, 0xe, 9, data_ov001_021a9bfc->mUnk_38,
                  data_ov001_021a9bfc->mUnk_44, data_ov001_021a9bfc->mUnk_34, 0x4000);
    p = data_ov001_021a9bfc;
    ptr = func_020b3f7c(p->mUnk_50, 8);
    func_0212426c(1, 0, data_ov001_021a9bfc->mUnk_4c, ptr, p->mUnk_44, p->mUnk_34);
    for (i = 0; i < 2; i++) {
        data_ov001_021a9bfc->mUnk_18[i].mUnk_00 = 250;
        data_ov001_021a9bfc->mUnk_18[i].mUnk_02 = 0;
    }
    data_ov001_021a9bfc->mUnk_0c = func_ov001_0219de38();
    data_ov001_021a9bfc->mUnk_10 = data_ov001_021a9bfc->mUnk_0c;
    func_ov001_0219d858();
    func_ov001_0219d810();
    data_ov001_021a9bfc->mUnk_28[0] = 0;
    data_ov001_021a9bfc->mUnk_28[1] = 0;
    func_021281c8(0xe);
}

void func_ov001_0219df64(void) {
    data_ov001_021a9bfc = 0;
}
