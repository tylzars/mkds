#include "Main/Unknown/code_0205af90.h"
#include "Main/Unknown/unk_0217a000.h"

u32 func_0205af90(void) {
    u32 object;
    u32 flag;
    object = (u32) &data_0217aa14;
    flag = 1u;
    object = *(const u32 *) ((object) + (0));
    *(u32 *) ((object) + (1836)) = flag;
    return object;
}
