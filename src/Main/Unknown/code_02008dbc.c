#include "Main/Unknown/code_02008dbc.h"
#include "Main/Unknown/code_02008934.h"
#include "code_0214cfe4.h"

#pragma thumb on

void func_02008dbc(u8 *a, int b) {
    if (*(u16 *) (a + 0x48) != data_0216fc40->mUnk_10[b].mUnk_508) {
        func_0200895c((u32) b);
        MemCopyHalfwords((const void *) a, (void *) data_0216fc40->mUnk_10[b].mUnk_4c0, (u32) 0xc0);
        func_02008a4c((u32) b);
    }
}

#pragma thumb off
