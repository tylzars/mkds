#pragma once

#include "types.h"

// Object behind member 0x04 of the elements of the tables of RaceNcerNclrNcgrTables: a halfword at 0x04.
typedef struct Unk020b6e00 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mUnk_04;
} Unk020b6e00;

s32 LookupRaceSNcerIndex(s32 kartIndex, s32 b);
void RenderKartEntryNames(void);
void GetEntryCharacterAndPalette(s32 entryIndex, s32 *outCharacterIndex, s32 *outPaletteIndex);
void CopyRaceTransferSOAndMapSO(u16 *palette, void *chars);
void CopyRaceTransferMapMrSO(u16 *palette, void *chars);
void GetTimeRecordCharacterAndPalette(s32 recordIndex, s32 *outCharacterIndex, s32 *outPaletteIndex);
