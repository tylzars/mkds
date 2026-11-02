#pragma once

#include "types.h"
#include "code_0200e77c.h"

struct Unk02003024;
struct Unk02003a6c;
struct Unk02003670;

// Pair stored by func_02005814 and FileWalkPath and read by func_02004a80: an Unk02003a6c and a number.
typedef struct Unk02005814 {
    /* 00 */ struct Unk02003a6c *mUnk_00;
    /* 04 */ s32 mUnk_04;
} Unk02005814;

// 12 bytes at 0x20 and at 0x30 of Unk02003024 (assigned as a whole by FileReadDirTableEntry, func_02004c20 and
// func_020047ec; data_0216f344). Different functions use the region with different types: an Unk02003a6c pointer
// (FileEnterDirectoryById, FileReadDirEntry, func_02004c20), an Unk02003670 pointer (FileWalkPath,
// FileBuildPathString), three words (FileOpenFromTableEntry, func_02004afc), an Unk02005814 (FileWalkPath,
// func_02004a80), a u8 pointer with two lengths (FileBuildPathString) and a pointer with two signed words
// (func_02004840, func_02004b98, FileReadViaArchive).
typedef union Unk02003024U {
    struct {
        /* 00 */ u32 mUnk_00;
        /* 04 */ u32 mUnk_04;
        /* 08 */ u32 mUnk_08;
    } w;
    struct {
        /* 00 */ Unk02005814 mUnk_00;
        /* 08 */ u32 mUnk_08;
    } d;
    struct {
        /* 00 */ struct Unk02003a6c *mUnk_00;
        /* 04 */ u16 mUnk_04;
        /* 06 */ u16 mUnk_06;
        /* 08 */ u32 mUnk_08;
    } h;
    struct {
        /* 00 */ struct Unk02003670 *mUnk_00;
        /* 04 */ u32 mUnk_04;
        /* 08 */ u32 mUnk_08;
    } e;
    struct {
        /* 00 */ u8 *mUnk_00;
        /* 04 */ u32 mUnk_04;
        /* 08 */ u16 mUnk_08;
        /* 0a */ u16 mUnk_0a;
    } b;
    struct {
        /* 00 */ void *mUnk_00;
        /* 04 */ s32 mUnk_04;
        /* 08 */ s32 mUnk_08;
    } p;
} Unk02003024U;

// 0x48-byte record, set up by func_02004d80 (also used as a local); mUnk_08 is the Unk02003a6c it works through.
typedef struct Unk02003024 {
    // FileFinishCommand links mUnk_00 and mUnk_04 to each other, then clears both.
    /* 00 */ struct Unk02003024 *mUnk_00;
    /* 04 */ struct Unk02003024 *mUnk_04;
    /* 08 */ struct Unk02003a6c *mUnk_08;
    /* 0c */ volatile u32 mUnk_0c; // bit 2 selects the path in FileDispatchCommand; FileFinishCommand clears 0x4f
    /* 10 */ u32 mUnk_10; // index passed to FileDispatchCommand by func_0200442c and func_02004474
    /* 14 */ s32 mUnk_14; // set from a return value in FileDispatchCommand and FileFinishCommand
    /* 18 */ Unk0200df9c mUnk_18;
    /* 20 */ Unk02003024U mUnk_20;
    /* 2c */ u32 mUnk_2c;
    /* 30 */ Unk02003024U mUnk_30;
    /* 3c */ const u8 *mUnk_3c;
    /* 40 */ u32 mUnk_40;
    /* 44 */ Unk02003024U *mUnk_44;
} Unk02003024;

// 0x5c-byte object (FS_InitArchive clears 0x5c bytes; data_0216f36c) at mUnk_08 of Unk02003024. Links at mUnk_04 and
// mUnk_08 (FS_RegisterArchiveName, FS_ReleaseArchiveName), flags at mUnk_1c, the list of Unk02003024 at mUnk_24; the
// addresses of mUnk_0c and mUnk_14 go to func_0200df9c and func_0200e01c; mUnk_48 to mUnk_54 are called from
// FileDispatchCommand, FileWriteViaArchive, FileReadViaArchive, FileReadTableBytes, func_02004270 and func_02004518.
typedef struct Unk02003a6c {
    /* 00 */ u32 mUnk_00;
    /* 04 */ struct Unk02003a6c *mUnk_04;
    /* 08 */ struct Unk02003a6c *mUnk_08;
    /* 0c */ Unk0200df9c mUnk_0c;
    /* 14 */ Unk0200df9c mUnk_14;
    /* 1c */ volatile u32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ struct Unk02003024 *mUnk_24;
    /* 28 */ u8 *mUnk_28;
    /* 2c */ u32 mUnk_2c;
    /* 30 */ u32 mUnk_30;
    /* 34 */ u32 mUnk_34;
    /* 38 */ u32 mUnk_38;
    /* 3c */ u32 mUnk_3c;
    /* 40 */ u32 mUnk_40;
    /* 44 */ u32 mUnk_44;
    /* 48 */ s32 (*mUnk_48)(struct Unk02003a6c *a, void *b, u32 c, u32 d);
    /* 4c */ s32 (*mUnk_4c)(struct Unk02003a6c *a, void *b, u32 c, u32 d);
    /* 50 */ s32 (*mUnk_50)(struct Unk02003a6c *a, void *b, u32 c, u32 d);
    /* 54 */ s32 (*mUnk_54)(Unk02003024 *a, u32 b);
    /* 58 */ u32 mUnk_58;
} Unk02003a6c;

// Called by FileDispatchCommand with its second argument as the index.
extern s32 (*data_02152b5c[])(Unk02003024 *a);

s32 FileDispatchCommand(Unk02003024 *a, u32 b);
void FileFinishCommand(Unk02003024 *a, s32 b);
s32 FileCloseReturnOk(Unk02003024 *a);
