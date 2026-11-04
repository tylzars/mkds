#include "Main/Unknown/code_02009c34.h"
#include "Main/Unknown/code_02009c90.h"
#include "Main/Unknown/code_0200ad4c.h"
#include "Main/Unknown/code_0200aeb4.h"
#include "Main/Unknown/code_0200b018.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_0200fc8c.h"

#pragma thumb on

// non-matching: 4 words differ; the original keeps the address of data_0216fda8 in r3 and the loaded pointer in r0,
// ours has them the other way round (same instructions, same size)
u32 func_02009c34(void) {
    Unk0216fda8 **p;
    u32 v1;
    u32 v2;
    v1 = 1;
    v2 = IrqDisable();
    p = (Unk0216fda8 **) &data_0216fda8;
    if ((*p)->mUnk_526 == 0) {
        v1 = 0;
        (*p)->mUnk_5e4 = v1;
        (*p)->mUnk_526 = 1;
        if (func_0200b018() != 0) {
            func_0200aeb4(func_02009c90);
        } else {
            v1 = func_02009c98();
        }
    }
    IrqRestore(v2);
    return v1;
}

#pragma thumb off
