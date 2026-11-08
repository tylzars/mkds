#include "Main/Unknown/code_02008dbc.h"
#include "Main/Unknown/code_02008934.h"
#include "code_0214cfe4.h"

#pragma thumb on

void ReplaceEntryIfChanged(u8 *newBlock, int entryIndex) {
    if (*(u16 *) (newBlock + 0x48) != gEntryTable->mEntries[entryIndex].mUnk_508) {
        func_0200895c(entryIndex);
        MIi_CpuCopy16(newBlock, gEntryTable->mEntries[entryIndex].mScanBuffer, 0xc0);
        SetScanBssidFromEntry(entryIndex);
    }
}

#pragma thumb off
