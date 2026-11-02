#include "Main/Unknown/code_0204a978.h"
#include "Main/Unknown/code_0214d000.h"

void func_0204a978(Unk02175650 *a) {
    if (a->mUnk_00 == NULL) {
        return;
    }
    if (a->mUnk_0c == 0) {
        if (a->mUnk_00 != NULL) {
            func_0214d168(a->mUnk_00, 0, 0xdcc);
        }
        a->mUnk_0c = 1;
    }
    a->mUnk_00->mUnk_00 = 0;
    a->mUnk_0c = 0;
    a->mUnk_04 = 0;
    a->mUnk_06 = 0;
    a->mUnk_08 = 1;
}
