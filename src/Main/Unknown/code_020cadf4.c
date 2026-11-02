#include "Main/Unknown/code_020cadf4.h"
#include "Main/Unknown/code_020cae24.h"
#include "Main/Unknown/code_020cae38.h"
#include "Main/Unknown/code_020cae54.h"

#pragma thumb on
#pragma optimize_for_size on
void func_020cadf4(Unk020cadf4 *a) {
    if (a != NULL) {
        if (func_020cae54() != 0 && func_020cae38() != 0) {
            a->mUnk_04 = 6;
            func_020cae24(1);
        } else {
            a->mUnk_04 = 2;
        }
    }
}
#pragma thumb off
