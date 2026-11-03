#include "00/code_021a998c.h"
#include "00/code_021ae0c4.h"
#include "00/code_021aefa8.h"
#include "code_0200db4c.h"

void func_ov000_021ae0c4(Unk021a998c *a) {
    func_0200dd94();
    if (a->mUnk_08 == 3 || a->mUnk_08 == 4) {
        func_ov000_021aefa8(a, 25);
        a->mUnk_08 = 7;
        return;
    }
    if (a->mUnk_08 != 0) {
        func_ov000_021aefb4(a, 26);
    }
}
