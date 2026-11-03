#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0207a6b0.h"

#include "Main/Unknown/unk_0217a000.h"

void func_0207a70c(s32 a) {
    if (a == data_021759c0->mUnk_62) {
        data_usa_0217acfc->mUnk_08++;
    }
}

void func_0207a6c0(Unk0206bcb0 *a) {
    if (a->mIndex != data_021759c0->mUnk_62) {
        return;
    }
    if (a->mUnk_4c & 0x40) {
        return;
    }
    if (!(a->mUnk_48 & 0x20000000)) {
        data_usa_0217acfc->mUnk_0c++;
    }
}

Unk0206cdd4_B *func_0207a6b0(void) {
    return data_usa_0217acfc;
}
