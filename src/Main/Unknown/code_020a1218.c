#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020a1218.h"

u16 func_020a1250(int arg0) {
    return data_0217b1fc->mUnk_000[arg0].mUnk_48;
}

u32 func_020a1238(void) {
    return ((u32) data_0217b1fc->mUnk_3a0);
}

void func_020a1218(short param_1) {
    Unk0217b1fc *v1;
    v1 = data_0217b1fc;
    v1->mUnk_3a0 = v1->mUnk_3a0 + param_1;
}
