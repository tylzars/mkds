#include "Main/Unknown/code_021529e0.h"
#include "Main/Unknown/code_02152a04.h"
#include "Main/Unknown/code_02152a6c.h"

#pragma thumb on
void func_021529e0(Unk02152490 *a, u32 b) {
    u32 c;
    u32 d;
    c = func_02152a6c(a);
    d = 3;
    c = c & ~d;
    d = c;
    d = d | b;
    func_02152a04(a, d);
}
#pragma thumb off
