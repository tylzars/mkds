#include "Main/Unknown/code_020acebc.h"

#include "Main/Unknown/code_020acec4.h"
#include "Main/Unknown/code_020ad230.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_020acef4.h"
#include "Main/Unknown/code_020acefc.h"

#pragma thumb on
u32 func_020acefc(u32 arg0) {
    u32 value0 = arg0;
    u32 value3;
    value3 = (u32) &func_020ad230;
    value0 = func_020ad230(value0);
    return value0;
}
#pragma thumb off

u32 func_020acef4(void) {
    return 0x8u;
}

u16 func_020acee0(Unk02175628 *a, u32 b) {
    return a->mUnk_00 & b;
}

u16 func_020acec4(u32 a, u32 b) {
    return func_020acee0(&data_02175628[a], b);
}

u32 func_020acebc(const void *p0) {
    return (*(const u16 *) ((u8 *) p0 + 4));
}
