#include "Main/Unknown/code_0202808c.h"

#pragma thumb on

void func_0202808c(void) {
    int v1;
    if ((data_02174e18->mUnk_100 == 1) &&
        (v1 = ((u32) func_0202811c()), v1 == 2)) {
        func_021281fc();
    }
    v1 = func_020280dc();
    if (v1 == 0) {
        func_0212b91c();
    } else {
        func_0211f498();
    }
    func_02036ab0((void *) data_02174e18->mUnk_08c);
    *(int *) &data_02174e18 = 0;
}

#pragma thumb off
