#include "Main/Unknown/code_020d26f8.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_02070398.h"
#include "Main/Unknown/code_02109054.h"

u32 func_020d26f8(Unk020e71a0 *param_1, Unk0206bcb0 *param_2) {
    if (param_2->mUnk_29c != 1 && param_2->mUnk_29c != 3) {
        return 0;
    }
    if (param_1->mUnk_94 != 0) {
        func_021090c4(&param_1->mUnk_94->mUnk_00, 0xe8, 0x7f, 0);
    } else {
        func_020719bc(&param_2->mUnk_00, 0xe8);
    }
    return 1;
}
