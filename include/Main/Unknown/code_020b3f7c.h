#pragma once

#include "types.h"

// Section header: two words; LocateBmgSections adds the second to the section address to move on.
typedef struct Unk020b3fb0_20 {
    /* 00 */ u32 mTag;
    /* 04 */ u32 mNextOffset;
} Unk020b3fb0_20;

// Object LocateBmgSections walks: the number of sections at 0x0c, the first section at 0x20.
typedef struct Unk020b3fb0 {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ u32 mSectionCount;
    /* 10 */ u8 mUnk_10[0x10];
    /* 20 */ Unk020b3fb0_20 mFirstSection;
} Unk020b3fb0;

// Section of LocateBmgSections whose first word is 0x494e4631 (data_0217b360): words from 0x10.
typedef struct Unk0217b340 {
    /* 00 */ u32 mTag;
    /* 04 */ u32 mNextOffset;
    /* 08 */ u8 mUnk_08[8];
    /* 10 */ u32 mEntryOffsets[1];
} Unk0217b340;

// Section of LocateBmgSections whose first word is 0x44415431 (data_0217b364): bytes from 8.
typedef struct Unk0217b344 {
    /* 00 */ u32 mTag;
    /* 04 */ u32 mNextOffset;
    /* 08 */ u8 mBody[1];
} Unk0217b344;

void LocateBmgSections(Unk020b3fb0 *bmg);
void *GetBmgEntry(Unk020b3fb0 *bmg, s32 index);
