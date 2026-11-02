#include "Main/Unknown/code_020d26f8.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_02070398.h"
#include "Main/Unknown/code_02109054.h"

u32 func_020d26f8(Unk020e71a0 *a, Unk0206bcb0 *b) {
    if (b->mUnk_29c != 1 && b->mUnk_29c != 3) {
        return 0;
    }
    if (a->mUnk_94 != 0) {
        func_021090c4(&a->mUnk_94->mUnk_00, 0xe8, 0x7f, 0);
    } else {
        func_020719bc(&b->mUnk_00, 0xe8);
    }
    return 1;
}
