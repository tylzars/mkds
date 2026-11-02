#include "00/code_021ae0c4.h"
#include "00/code_021aefa8.h"

void func_ov000_021ae0c4(Unk021a998c *param_1) {
    func_0200dd94();
    if (param_1->mUnk_08 == 3 || param_1->mUnk_08 == 4) {
        func_ov000_021aefa8(param_1, 25);
        param_1->mUnk_08 = 7;
        return;
    }
    if (param_1->mUnk_08 != 0) {
        func_ov000_021aefb4(param_1, 26);
    }
}
