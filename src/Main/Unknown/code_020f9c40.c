#include "Main/Unknown/code_020f9c40.h"
#include "Main/Unknown/code_020d50ec.h"

void func_020f9c40(int arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value4;
    u32 compareLeft0;
    u32 compareRight0;
    value4 = value0;
    value0 = *(const s16 *) ((value4) + (218));
    value1 = ~(0u);
    compareLeft0 = value0;
    compareRight0 = value1;
    if (compareLeft0 == compareRight0) {
    }
    if (compareLeft0 == compareRight0) {
        return;
    }
    value0 = FreeCollisionSlot(value0);
    *(u16 *) ((value4) + (218)) = value0;
}
