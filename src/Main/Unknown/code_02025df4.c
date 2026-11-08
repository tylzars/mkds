#include "Main/Unknown/code_02025df4.h"
#include "Main/Unknown/code_02025e28.h"

#pragma thumb on

int func_02025df4(KartAppear *appear, u32 characterIndex) {
    int count;
    int tableIndex;
    int testResult;
    u32 kartIndex;
    count = 0;
    tableIndex = 0;
    do {
        kartIndex = GetKartIndexAtTableIndex(tableIndex);
        testResult = func_0205fd2c(appear, characterIndex, kartIndex);
        if (testResult != 0) {
            count = count + 1;
        }
        tableIndex = tableIndex + 1;
    } while (tableIndex < 0x24);
    return count;
}

#pragma thumb off
