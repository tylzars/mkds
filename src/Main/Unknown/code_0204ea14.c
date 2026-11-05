#include "Main/Unknown/code_0204ea14.h"
#include "Main/Unknown/code_02007ec4.h"
#include "Main/Unknown/code_02008000.h"
#include "Main/Unknown/code_02008880.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02008570.h"

#pragma thumb on

u32 func_0204ea3c(void) {
    u32 v1;
    int v2;
    u32 v3;
    v3 = 0;
    v1 = func_02008880(NULL);
    if (((u32) 0x00010000u) <= v1) {
        v2 = func_02008570(NULL, data_0217aa00->mUnk_1658, data_0217aa00->mUnk_168c);
        if ((v2 != 0) && (v2 = func_02008310(data_0215472c, data_0217aa00->mUnk_1658), v2 != 0)) {
            v3 = 1;
        }
    }
    return v3;
}

void func_0204ea14(void *a) {
    void **v1;
    void *v2;
    void *v3;
    v2 = GetBmgEntry(a, 0);
    v3 = GetBmgEntry(a, 1);
    v1 = data_0215472c;
    data_0215472c[1] = v2;
    v1[2] = v3;
}

#pragma thumb off
