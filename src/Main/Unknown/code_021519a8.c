#include "Main/Unknown/code_021519a8.h"
#include "Main/Unknown/unk_02180000.h"
#include "code_021510a4.h"

#pragma thumb on

u32 ReadNvramFirstThreeEntries(void *buffer) {
    int readResult;
    readResult = readNvram((*(u32 *) &gNvramEntriesOffset), (0x00000300u), buffer);
    if (readResult != 0) {
        return 1;
    }
    return 0;
}

#pragma thumb off
