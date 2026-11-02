#pragma once

#include "types.h"
#include "code_02003024.h"

// Two words FileOpenFromTableEntry reads into mUnk_30 of Unk02003024.
typedef struct Unk02003234 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
} Unk02003234;

// FileReadTableBytes passes mUnk_04 to the callback at mUnk_50 of mUnk_00 and adds the count to it.
typedef struct Unk02003ad8 {
    /* 00 */ Unk02003a6c *mUnk_00;
    /* 04 */ u32 mUnk_04;
} Unk02003ad8;

// Eight bytes read by FileReadDirTableEntry.
typedef struct Unk0200399c {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
} Unk0200399c;

// Entry read by FileWalkPath, FileReadDirEntry and FileBuildPathString: a Unk02003024U, then a flag, a length and the
// bytes.
typedef struct Unk02003670 {
    /* 00 */ Unk02003024U mUnk_00;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u8 mUnk_14[0x80];
} Unk02003670;

s32 FileOpenFromTableEntry(Unk02003024 *a);
s32 FileBuildPathString(Unk02003024 *a);
s32 FileWalkPath(Unk02003024 *a);
s32 FileReadDirEntry(Unk02003024 *a);
s32 FileReadDirTableEntry(Unk02003024 *a);
s32 FileWriteViaArchive(Unk02003024 *a);
s32 FileReadViaArchive(Unk02003024 *a);
s32 FileEnterDirectoryById(Unk02003024 *a, u32 b);
void FileReadTableBytes(Unk02003ad8 *a, void *b, u32 c);
s32 FileCompareNamesNoCase(const u8 *a, const u8 *b, u32 c);
