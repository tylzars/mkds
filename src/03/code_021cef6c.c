#include "03/code_021cef6c.h"

#include "03/unk_021da000.h"

int func_ov003_021cef80(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_ov003_021da284;
    value1 = (u32) * (const u32 *) ((value0) + 0u);
    value0 = 27u;
    value0 = (u32) * (const s8 *) ((value1) + (value0));
    return value0;
}

u32 func_ov003_021cef6c(void) {
    if (data_ov003_021da284 != 0) {
        return 1;
    }
    return 0;
}
