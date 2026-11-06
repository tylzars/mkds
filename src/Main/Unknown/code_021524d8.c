#include "Main/Unknown/code_021524d8.h"
#include "Main/Unknown/code_021529e0.h"
#include "code_0214d018.h"
#include "code_02152a7c.h"

#pragma thumb on

void func_021524d8(void *a, u32 b, u32 c) {
    MI_CpuFill8(a, 0, 0xc);
    func_02152a80(a, b, c);
    func_021529e0(a, 2);
}

#pragma thumb off
