#include "Main/Unknown/code_0200b200.h"
#include "Main/Unknown/code_0200b6e8.h"
#include "Main/Unknown/code_0200b7e0.h"
#include "code_02142eac.h"

#pragma thumb on

void func_0200b6e8(void) {
    u32 v1;
    v1 = func_021438a8(func_0200b698);
    if (v1 != 2) {
        func_0200b820((u16) 0xb, (u16) (v1 & 0xffff));
    }
}

#pragma thumb off
