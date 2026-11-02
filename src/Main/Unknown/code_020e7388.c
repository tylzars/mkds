#include "Main/Unknown/code_020e7388.h"

#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020e73a0.h"

Vec3 *func_020e73a0(u32 arg0) {
    return (*(Vec3 ***) data_0217b86c)[arg0];
}

u16 func_020e7388(int arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    value1 = (u32) &data_0217b868;
    value0 = (value0 << 1);
    value1 = (u32) * (const u32 *) ((value1) + (0));
    value0 = (u32) * (const u16 *) ((value1) + (value0));
    return (u16) value0;
}
