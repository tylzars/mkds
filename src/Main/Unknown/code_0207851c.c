#include "Main/Unknown/code_0207851c.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0200fe7c.h"

#pragma thumb on

void func_0207851c(Unk0217ad08_058 *a) {
    if ((data_0217ad08->mUnk_1e0 != 0) && (a->mUnk_b4 != NULL)) {
        func_02010458((Unk020101e8 *) a->mUnk_14->mUnk_04, data_02155048);
        func_020101e8((Unk020101e8 *) a->mUnk_14->mUnk_04, data_021550a8);
        func_0201050c((Unk020101e8 *) a->mUnk_14->mUnk_04, a->mUnk_b4, data_02155048);
        func_02010294((Unk020101e8 *) a->mUnk_14->mUnk_04, a->mUnk_b4, data_021550a8);
    }
}

#pragma thumb off
