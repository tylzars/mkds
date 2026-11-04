#include "Main/Unknown/code_020ae0ac.h"

#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020ae0c8.h"
#include "Main/Unknown/code_020ae0e4.h"
#include "Main/Unknown/code_020ae0f8.h"

u32 func_020ae0f8(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &data_021759c0;
    value1 = 0x30u;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = (u32) * (const u32 *) ((value1) + (136));
    return value0;
}

u32 func_020ae0e4(void) {
    return ((u32) data_021759c0->mMode);
}

u32 func_020ae0c8(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &data_021759c0;
    value1 = 0x30u;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = (u32) * (const u32 *) ((value1) + (104));
    return value0;
}

int func_020ae0ac(int arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &data_021759c0;
    value1 = 0x30u;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = (u32) * (const s8 *) ((value1) + (134));
    return value0;
}
