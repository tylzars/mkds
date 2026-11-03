#include "Main/Unknown/code_020b2e98.h"
#include "Main/Unknown/code_020b2ec0.h"
#include "Main/Unknown/code_020b1de4.h"

#pragma thumb on
#pragma optimize_for_size on
u32 func_020b2e98(void) {
    if (func_020b2ec0() != 0 || gChoisesS->mUnk_008 != 0) {
        return 1;
    }
    return 0;
}
#pragma thumb off
