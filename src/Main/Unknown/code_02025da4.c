#include "Main/Unknown/code_02025da4.h"
#include "Main/Unknown/code_02025e28.h"
#include "Main/Unknown/code_0205ee14.h"

#pragma thumb on
s32 func_02025da4(Unk0205fd2c *a, u32 b, s32 c) {
    s32 n = 1;
    s32 i;
    s32 j;
    u32 d;
    j = func_02025e34(func_02025e60(b));
    i = j;
    do {
        d = func_02025e28(i);
        if (func_0205fd2c(a, b, d) != 0) {
            if (d == c) {
                break;
            }
            n++;
        }
        i++;
        if (i >= 0x24) {
            i = 0;
        }
    } while (i != j);
    return n;
}
#pragma thumb off
