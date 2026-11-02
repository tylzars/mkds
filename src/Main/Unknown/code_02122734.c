#include "Main/Unknown/code_02122734.h"

s32 func_02122778(s32 a) {
    return data_0217d384->mUnk_1f4e[a];
}

s32 func_02122734(s32 a) {
    s8 i;
    for (i = 0; i < 4; i++) {
        if (a == data_0217d384->mUnk_1f4e[i]) {
            return i;
        }
    }
    return -1;
}
