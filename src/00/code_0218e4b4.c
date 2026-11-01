#include "00/code_0218e4b4.h"
#include "00/code_0218e3c4.h"
#include "00/code_0218e56c.h"
#include "00/code_021a8db8.h"
#include "00/code_021a911c.h"
#include "00/unk_021b5000.h"
#include "00/code_021a916c.h"

s32 func_ov000_0218e4e4(s32 param_1, void *param_2, s32 param_3) {
    Unk0218e3c4 *a = param_2;
    Unk0218e3c4 b;
    if (*(u16 *) a->mUnk_02 == 0) {
        return 0;
    }
    b = *a;
    b.mUnk_00 = param_3;
    return func_ov000_0218e56c(func_ov000_021a916c(param_1, &b), -1);
}

s32 func_ov000_0218e4b4(s32 param_1, void *param_2, s32 param_3) {
    Unk0218e3c4 a = *(Unk0218e3c4 *) param_2;
    a.mUnk_00 = param_3;
    return func_ov000_0218e56c(func_ov000_021a911c((Unk021a6fa8 *) param_1, (Unk021a8e18 *) &a), -1);
}
