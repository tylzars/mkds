#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020ae730.h"
#include "Main/Unknown/code_020ae754.h"
#include "Main/Unknown/code_02036bec.h"

#pragma optimize_for_size on

#pragma thumb on

void *func_020ae730(s32 a, s32 b) {
    void *p;

    p = NULL;
    if (a > 0) {
        p = func_02036bec((void *) func_020ae754(), b * a);
    }
    return p;
}

#pragma thumb off
