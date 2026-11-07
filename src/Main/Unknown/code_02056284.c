#include "Main/Unknown/code_02056284.h"
#include "Main/Unknown/code_020483e4.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

GhostRecord *func_02056284(const char *a) {
    int v1;
    v1 = ReadWholeFile(a, data_0217aa08->mUnk_14[2], (0x00001000u));
    if (v1 != 0) {
        return data_0217aa08->mUnk_14[2];
    }
    return NULL;
}

#pragma thumb off
