#include "Main/Unknown/code_020adddc.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_0212a910.h"

#pragma thumb on

void func_020adddc(u32 a, void *b, u32 c, u32 d) {
    u16 *v1;
    func_020adf00(a);
    v1 = func_0212b090();
    func_020ade08(v1, b, c, d, func_020adec0);
}

#pragma thumb off
