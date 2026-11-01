#include "01/code_02192ee4.h"
#include "01/code_02193000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_0212a000.h"
#include "Main/Unknown/code_0214a000.h"
#include "Main/Unknown/code_0214d000.h"

void func_ov001_02192ee4(void) {
    if (data_ov001_021a9bd0->mUnk_18.mUnk_08 != 0) {
        data_ov001_021a9bd0->mUnk_18.mUnk_08();
    }
    if (data_ov001_021a9bd0->mUnk_0c != -1) {
        data_ov001_021a9bd0->mUnk_18.mUnk_04();
        func_ov001_021932c8();
        func_02036ab0((void *) data_ov001_021a9bd0->mUnk_04);
        data_ov001_021a9bd0->mUnk_04 = func_020369fc(data_ov001_021a9bd0->mUnk_00);
        switch (data_ov001_021a9bd0->mUnk_0c) {
            case 0:
                func_ov001_021932e4();
                break;
            case 1:
                func_ov001_02198854();
                break;
            case 2:
                func_ov001_02199964();
                break;
            case 3:
                func_ov001_0219d5dc();
                break;
        }
        data_ov001_021a9bd0->mUnk_10 = data_ov001_021a9bd0->mUnk_08;
        data_ov001_021a9bd0->mUnk_08 = data_ov001_021a9bd0->mUnk_0c;
        data_ov001_021a9bd0->mUnk_0c = -1;
        if (data_ov001_021a9bd0->mUnk_18.mUnk_00 != 0) {
            data_ov001_021a9bd0->mUnk_18.mUnk_00(data_ov001_021a9bd0->mUnk_04);
        }
    }
    func_02125928();
    func_0212a920();
}
