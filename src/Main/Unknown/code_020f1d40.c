#include "Main/Unknown/code_020f1d40.h"
#include "Main/Unknown/code_020f36d8.h"

#pragma thumb on

u32 func_020f1d40(int a) {
    u32 v1;
    UnkWordFunc *v2;
    v2 = (UnkWordFunc *) gItemKinds[a].mUnk_48;
    if (v2 != NULL) {
        v1 = (*v2)(0, 0, 1);
        return v1;
    }
    return 0;
}

#pragma thumb off
