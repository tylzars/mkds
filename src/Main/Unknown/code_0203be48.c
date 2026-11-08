#include "Main/Unknown/code_0203be48.h"
#include "Main/Unknown/code_0203be88.h"

#pragma thumb on

void SetGivenCharacterAndKart(u8 *picks, u32 entryIndex, u32 characterIndex, u32 kartIndex) {
    SetGivenCharacter(picks, entryIndex, characterIndex);
    SetGivenKart(picks, entryIndex, kartIndex);
}

void GetEntryCharacterAndKart(u8 *picks, u8 entryIndex, u32 *outCharacterIndex, u32 *outKartIndex) {
    if (outCharacterIndex != NULL) {
        *outCharacterIndex = *(u32 *) (picks + entryIndex * 4 + 4);
    }
    if (outKartIndex != NULL) {
        *outKartIndex = *(u32 *) (picks + entryIndex * 4 + 0x24);
    }
}

#pragma thumb off
