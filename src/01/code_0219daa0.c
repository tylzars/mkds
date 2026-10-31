#include "01/code_0219daa0.h"

void func_ov001_0219daa0(void) {
    int *v1;
    int v2;
    v1 = (int *) &data_ov001_021a9bfc;
    data_ov001_021a9bfc->mUnk_14 = data_ov001_021a9bfc->mUnk_14 + 1;
    v2 = *v1;
    if (10 <= *(int *) (v2 + 0x14)) {
        *(u32 *) (v2 + 4) = 5;
        *(u32 *) (*v1 + 0x14) = 0;
        func_021282c8();
        return;
    }
    if (5 <= *(int *) (v2 + 0x14)) {
        *(u32 *) (v2 + 0x24) = 1;
    }
    return;
}
