#include "code_02010f98.h"

void func_02010f98(u32 arg0, u32 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2;
    value2 = (u32) &data_02170344;
    value1 = (value1) | ((value0 << 30));
    *(u32 *) ((value2) + ((value0 << 2))) = value1;
}
