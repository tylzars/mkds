#include "Main/Unknown/code_02046740.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_021759c0.h"

void func_02046740(void) {
    data_021759c0->mUnk_1e8.mUnk_60 = data_021759c0->mUnk_60 + 1;
    if (data_021759c0->mUnk_1e8.mUnk_60 <= 4) {
        data_021759c0->mUnk_1e8.mUnk_00 =
            data_02154128[data_021759c0->mUnk_1e8.mUnk_04][data_021759c0->mUnk_1e8.mUnk_60 - 1];
    }
    data_021759c0->mUnk_1e8.mUnk_0c = 3;
}
