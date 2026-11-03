#include "Main/Unknown/code_0200aeb4.h"
#include "Main/Unknown/code_0200aeec.h"
#include "Main/Unknown/code_0200b018.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_0200fc8c.h"

#pragma thumb on

void func_0200aeb4(void *a) {
    u32 v1;
    int v2;
    v1 = ((s64) func_0200fca0());
    v2 = func_0200b018();
    if (v2 != 0) {
        func_0200aeec(&data_0216fde0->mUnk_c4, NULL, a, 0);
    }
    func_0200fcb4(v1);
}

#pragma thumb off
