#include "Main/Unknown/code_02086058.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/unk_0217a000.h"

int func_02086080(int arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    value1 = (u32) &data_0217aed0;
    value1 = (u32) * (const u32 *) ((value1) + (0));
    value0 = (value1) + ((value0 << 2));
    value0 = (u32) * (const u32 *) ((value0) + (292));
    return value0;
}

u16 func_0208606c(int a) {
    return data_02155a64[a];
}

u16 *func_02086058(void) {
    return data_0217aed0->mUnk_094;
}
