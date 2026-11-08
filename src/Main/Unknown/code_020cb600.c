#include "Main/Unknown/code_020cb600.h"

void func_020cb600(int *counterAddress) {
    u32 counterValue;
    counterValue = *(u32 *) counterAddress;
    if ((s32) counterValue < 0x7fffffff) {
        *counterAddress = counterValue + 1;
    }
}
