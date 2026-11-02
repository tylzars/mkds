#include "Main/Unknown/code_020d1108.h"

#pragma thumb on

void InitCupPicture(void) {
    int v1;
    u32 v2;
    v1 = func_020d1158();
    if (v1 == 0) {
        v2 = func_020d113c();
        v1 = ((u32) func_02036bec((void *) v2, (u32) (((u32) 0x0000185cu))));
        *(int *) &gCupPicture = v1;
        *(u32 *) (v1 + 0xc) = 0;
        func_020d0efc(0x14);
    }
}

#pragma thumb off
