#include "Main/Unknown/code_020cb600.h"

void func_020cb600(int *counterAddress) {
    u32 value;
    value = *(u32 *) counterAddress;
    if ((s32) value < 0x7fffffff) {
        *counterAddress = value + 1;
    }
}
