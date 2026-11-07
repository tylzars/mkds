#include "Main/Unknown/code_02025df4.h"
#include "Main/Unknown/code_02025e28.h"

#pragma thumb on

int func_02025df4(KartAppear *a, u32 b) {
    int v1;
    int v2;
    int v3;
    u32 v4;
    v1 = 0;
    v2 = 0;
    do {
        v4 = GetKartIndexAtTableIndex(v2);
        v3 = func_0205fd2c(a, b, v4);
        if (v3 != 0) {
            v1 = v1 + 1;
        }
        v2 = v2 + 1;
    } while (v2 < 0x24);
    return v1;
}

#pragma thumb off
