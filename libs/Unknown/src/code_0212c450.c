#include "code_0212c450.h"

u32 func_0212c450(Unk0212c400 **arg0, u32 arg1, u32 arg2) {
    u32 value0 = (u32) arg0;
    u32 value1 = arg1;
    u32 value2 = arg2;
    u32 value3;
    u32 value12;
    u32 compareLeft0;
    u32 compareRight0;
    value12 = (u32) * (const u32 *) ((value0) + (0));
    compareLeft0 = value12;
    compareRight0 = 0u;
    if (compareLeft0 == compareRight0) {
        return value0;
    }
    value3 = 2u;
    *(u16 *) ((value12) + (52)) = (u16) value3;
    value3 = (u32) * (const u32 *) ((value0) + (0));
    *(u16 *) ((value3) + (56)) = (u16) value1;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    *(u16 *) ((value0) + (58)) = (u16) value2;
    return value0;
}
