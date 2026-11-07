#include "Main/Unknown/code_0202cca0.h"
#include "Main/Unknown/code_02025eb0.h"
#include "Main/Unknown/code_02110720.h"

#pragma thumb on

void func_0202cca4(int characterIndex, int b) {
    u32 tableValue;
    if ((characterIndex != 0xc) || (b != 1)) {
        tableValue = func_02025eb0(characterIndex);
        AddSeqQueueEntry(tableValue, b);
    }
}

u32 func_0202cca0(void) {
    return 0x8u;
}

#pragma thumb off
