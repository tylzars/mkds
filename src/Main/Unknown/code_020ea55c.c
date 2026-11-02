#include "Main/Unknown/code_020ea55c.h"

#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0207a000.h"

#pragma thumb on

void func_020ea55c(void **a, void *b, u32 c) {
    *a = func_02036bec(func_020364e0(func_020364e8()), 0x74);
    func_0207afa8(*a, b, (u8) c);
}

#pragma thumb off
