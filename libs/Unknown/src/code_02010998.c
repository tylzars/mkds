#include "code_02010998.h"

void func_02010998(u32 arg0, u32 arg1, u32 arg2) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2 = arg2;
    u32 compareLeft0;
    u32 compareRight0;
    u32 compareLeft1;
    u32 compareRight1;
    compareLeft0 = value1;
    compareRight0 = 0u;
    if (compareLeft0 != compareRight0) {
        *(u32 *) ((value0) + (8)) = value1;
    }
    compareLeft1 = value2;
    compareRight1 = 0u;
    if (compareLeft1 != compareRight1) {
        *(u32 *) ((value0) + (24)) = value2;
    }
}
