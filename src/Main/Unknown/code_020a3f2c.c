#include "Main/Unknown/code_020a3f2c.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020a3fa8.h"
#include "Main/Unknown/unk_021759c0.h"

u32 func_020a3f48(void) {
    Unk021759c0 *d;
    s32 k;

    d = data_021759c0;
    k = d->mUnk_08;
    if (k == 2 && d->mUnk_18 == 0) {
        return func_0209bf8c();
    }
    if (k != 4) {
        return 0;
    }
    return func_0209bf8c();
}

u32 func_020a3f2c(void) {
    return func_0209bf48(0, func_020a3fa8, 0);
}
