#include "Main/Unknown/code_02025da4.h"
#include "Main/Unknown/code_02025e28.h"
#include "Main/Unknown/code_0205ee14.h"

#pragma thumb on
s32 func_02025da4(KartAppear *appear, u32 characterIndex, s32 kartIndex) {
    s32 position = 1;
    s32 tableIndex;
    s32 startIndex;
    u32 tableKartIndex;
    startIndex = FindKartTableIndex(func_02025e60(characterIndex));
    tableIndex = startIndex;
    do {
        tableKartIndex = GetKartIndexAtTableIndex(tableIndex);
        if (IsKartAppearWithinLimit(appear, characterIndex, tableKartIndex) != 0) {
            if (tableKartIndex == kartIndex) {
                break;
            }
            position++;
        }
        tableIndex++;
        if (tableIndex >= 0x24) {
            tableIndex = 0;
        }
    } while (tableIndex != startIndex);
    return position;
}
#pragma thumb off
