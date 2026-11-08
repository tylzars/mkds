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
    u32 size;
    int v2;
    u32 result;
    result = 0;
    size = func_02008880(NULL);
    if ((0x00010000u) <= size) {
        v2 = func_02008570(NULL, data_0217aa00->mUnk_1658, data_0217aa00->mUnk_168c);
        if ((v2 != 0) && (v2 = func_02008310(data_0215472c, data_0217aa00->mUnk_1658), v2 != 0)) {
            result = 1;
        }
    }
    return result;
}

void func_0204ea14(Bmg *bmg) {
    void **table;
    void *firstEntry;
    void *secondEntry;
    firstEntry = GetBmgEntry(bmg, 0);
    secondEntry = GetBmgEntry(bmg, 1);
    table = data_0215472c;
    data_0215472c[1] = firstEntry;
    table[2] = secondEntry;
}

#pragma thumb off
