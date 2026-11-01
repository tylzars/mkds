#include "Main/Unknown/code_020a223c.h"
#include "Main/Unknown/unk_0217b000.h"

s32 func_020a2264(u16 a) {
    if (data_0217b1fc->mUnk_3b4 >= 0) {
        return -1;
    }
    return data_0217b1fc->mUnk_000[a].mUnk_64;
}

s32 func_020a223c(u16 a) {
    if (data_0217b1fc->mUnk_3b4 >= 0) {
        return -1;
    }
    return data_0217b1fc->mUnk_000[a].mUnk_68;
}
