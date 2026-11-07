#pragma once

#include "types.h"

// The characters and karts of eight entries; a set bit in the given bits means the caller already set that entry's
// value.
typedef struct CharacterKartPicks {
    /* 00 */ u8 mKartGivenBits;
    /* 01 */ u8 mCharacterGivenBits;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ s32 mCharacterIndices[8];
    /* 24 */ s32 mKartIndices[8];
    /* 44 */ struct Unk0205fd2c *mUnk_44;
} CharacterKartPicks;

void PickRandomCharacters(u8 *rawPicks);
void PickRandomKarts(u8 *rawPicks);
