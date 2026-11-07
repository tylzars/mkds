#include "Main/Unknown/code_02008dbc.h"
#include "Main/Unknown/code_02008934.h"
#include "code_0214cfe4.h"

#pragma thumb on

void ReplaceEntryIfChanged(u8 *newBlock, int entryIndex) {
    if (*(u16 *) (newBlock + 0x48) != data_0216fc40->mUnk_10[entryIndex].mUnk_508) {
        func_0200895c(entryIndex);
        MIi_CpuCopy16(newBlock, data_0216fc40->mUnk_10[entryIndex].mUnk_4c0, 0xc0);
        func_02008a4c(entryIndex);
    }
}

#pragma thumb off
