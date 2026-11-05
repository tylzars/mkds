#include "Main/Unknown/code_02056284.h"
#include "Main/Unknown/code_020483e4.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

Unk0217aa08_14 *func_02056284(u32 a) {
    int v1;
    v1 = func_02048684((const char *) a, (void *) data_0217aa08->mUnk_14[2], (u32) (((u32) 0x00001000u)));
    if (v1 != 0) {
        return data_0217aa08->mUnk_14[2];
    }
    return NULL;
}

#pragma thumb off
