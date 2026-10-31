#include "01/code_0219baf4.h"
#include "Main/Unknown/code_02117218.h"
#include "registers.h"

void func_ov001_0219baf4(void) {
    if (data_ov001_021a9bf4->mUnk_6c == 1) {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1f00) | 0x1800;
    }
    func_0212b91c();
    func_0211de34();
    func_0211df38();
    func_02117218();
    func_02036ab0(data_ov001_021a9bf4->mUnk_44);
    data_ov001_021a9bf4 = 0;
}
