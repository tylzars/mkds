#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0205ee14.h"
#include "Main/Unknown/code_020c5ccc.h"

#include "Main/Unknown/code_020c5ce0.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0205f000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020c5db0.h"
#include "Main/Unknown/code_020c53c4.h"
#include "Main/Unknown/unk_0217b000.h"

u32 func_020c5dc4(void) {
    return ((u32) data_0217b3f0->mUnk_00);
}

u32 func_020c5db0(void) {
    return ((u32) data_0217b3f0->mUnk_04);
}

void func_020c5ce0(void) {
    data_0217b3f0 = func_02036bec(func_020364e0(func_020364e8()), 0x1c);
    data_0217b3f0->mUnk_00 = 1;
    data_0217b3f0->mUnk_04 = 0;
    data_0217b3f0->mUnk_08 = 0;
    data_0217b3f0->mUnk_0c = 0;
    data_0217b3f0->mUnk_10 = 0;
    if (data_021759c0->mUnk_08 == 4) {
        if (func_0205fd78(data_021759c0->mUnk_08 == 4 ? data_021759c0->mUnk_54 : -1,
                          data_021759c0->mUnk_08 == 4 ? data_021759c0->mUnk_55 : -1, &data_0217b3f0->mUnk_14) == 0) {
            data_0217b3f0->mUnk_14 = 9;
        }
    } else {
        data_0217b3f0->mUnk_14 = 9;
    }
    data_0217b3f0->mUnk_18 = 9;
}

u32 func_020c5ccc(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217b3f0;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}
