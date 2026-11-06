#pragma once

#include "types.h"
#include "code_02003024.h" // FSArchive

// Record whose first fields ArchiveHeaderMatches checks; mUnk_0c is the offset of the first of mUnk_0e blocks that
// ArchiveLoadFromMemory walks, each starting with a word and its own size.
typedef struct Unk02018344 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u8 mUnk_08[4];
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
} Unk02018344;

// FSArchive followed by the three words ArchiveLoadFromMemory sets.
typedef struct Unk020182c0 {
    /* 00 */ FSArchive mUnk_00;
    /* 5c */ Unk02018344 *mUnk_5c;
    /* 60 */ u8 *mUnk_60;
    /* 64 */ u8 *mUnk_64;
} Unk020182c0;

void *ArchiveFileGetAddress(const u8 *a);
u32 ArchiveUnload(FSArchive *a);
u32 ArchiveLoadFromMemory(Unk020182c0 *a, const u8 *b, Unk02018344 *c);
u32 ArchiveHeaderMatches(Unk02018344 *a);
