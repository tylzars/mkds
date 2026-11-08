#include "03/code_021d1d88.h"
#include "03/code_021d27d8.h"

Unk021d1d88 *func_ov003_021d1d88(u32 count) {
    Unk021d1d88 *list = AllocExpHeapBlock((count + 1) * 4 + 8, 4);

    list->mUnk_00 = count + 1;
    list->mUnk_02 = 0;
    list->mUnk_03 = 0;
    return list;
}
