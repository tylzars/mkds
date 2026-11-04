#include "code_0214d018.h"
#include "code_02152490.h"
#include "code_021526bc.h"
#include "code_02152a7c.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_021529e0.h"

#pragma thumb on

void func_02152490(void *a, void *b) {
    Unk02152500 *p = a;
    Unk02152490 *q = b;

    MemFill(q, 0, 12);
    if (func_021526bc(p) != 0) {
        func_02152a7c(q, p->mUnk_1c);
        func_021529e0(q, 3);
    } else {
        *q = p->mUnk_04;
    }
}

#pragma thumb off
