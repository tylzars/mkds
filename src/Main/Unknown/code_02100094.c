#include "Main/Unknown/code_02100094.h"

s32 func_02100094(Unk02100094 *list) {
    s32 count = list->mUnk_04;

    while (count > 1 && *(u16 *) list->mUnk_00[count - 1] == 0x6f) {
        count--;
    }
    return count;
}
