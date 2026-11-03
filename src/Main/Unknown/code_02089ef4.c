#include "Main/Unknown/code_02089ef4.h"
#include "Main/Unknown/code_02087d0c.h"
#include "Main/Unknown/code_02089fa0.h"
#include "Main/Unknown/unk_0217b000.h"

void func_02089ef4(s32 a) {
    if (a == 9) {
        data_0217b034->mUnk_73c = a;
        return;
    }
    if (data_0217b034->mUnk_73c != a || a == 2) {
        func_0208a31c(a);
    }
    data_0217b034->mUnk_740 = 0;
    if (data_0217b034->mUnk_73c == 1 || data_0217b034->mUnk_73c == 3) {
        data_0217b034->mUnk_742 = func_02087d0c(data_0217b034->mUnk_000[8]->mUnk_04[0]) >> 12;
    }
}
