#include "Main/Unknown/code_02074854.h"
#include "Main/Unknown/unk_02165000.h"

void *func_020748a8(void) {
    return data_0217ac94;
}

Unk02061808 *func_02074898(void) {
    return data_0217acbc;
}

Unk02061808 *func_02074888(void) {
    return data_0217acb4;
}

void func_02074874(u32 p0) {
    data_0217ac94->mUnk_064 = p0;
}

void func_02074854(void) {
    u32 value0;
    u32 value1;
    value1 = (u32) &data_0216569c;
    value0 = (u32) &data_0217ac94;
    value1 = (u32) * (const u16 *) ((value1) + (0));
    value0 = (u32) * (const u32 *) ((value0) + (0));
    *(u32 *) ((value0) + (100)) = value1;
}
