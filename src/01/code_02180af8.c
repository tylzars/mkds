#include "01/code_02180af8.h"

#pragma thumb off

void func_ov001_02180af8(u8 *p0, u32 p1) {
    u32 v2 = ((u32) * (u32 *) (((u32) p0) + (24)));
    u32 v3 = ((u32(*)(u32, u32))(v2))((u32) p0, p1);
}

#pragma thumb on
