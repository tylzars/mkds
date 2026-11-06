#pragma once

#include "types.h"
#include "code_0200e77c.h"

typedef struct FSFile FSFile;
typedef struct FSArchive FSArchive;

typedef s32 (*FS_ARCHIVE_READ_FUNC)(FSArchive *archive, void *dst, u32 src, u32 len);
typedef s32 (*FS_ARCHIVE_WRITE_FUNC)(FSArchive *archive, const void *src, u32 dst, u32 len);
typedef s32 (*FS_ARCHIVE_PROC_FUNC)(FSFile *file, u32 command);

struct Unk02003670;

// An archive and a file number in it, as stored by FS_GetOverlayFileID and FSi_FindPathCommand and read by
// FS_OpenFileFast.
typedef struct FSFileID {
    /* 00 */ FSArchive *mArc;
    /* 04 */ u32 mFileId;
} FSFileID;

// 12 bytes at 0x20 and at 0x30 of FSFile (assigned as a whole by FSi_SeekDirCommand, FSi_FindPath and
// FS_ChangeDir; data_0216f344). Different functions use the region with different types: an FSArchive pointer
// (FSi_SeekDirDirect, FSi_ReadDirCommand, FSi_FindPath), an Unk02003670 pointer (FSi_FindPathCommand,
// FSi_GetPathCommand), three words (FSi_OpenFileFastCommand, FS_OpenFileDirect), an FSFileID (FSi_FindPathCommand,
// FS_OpenFileFast), a u8 pointer with two lengths (FSi_GetPathCommand) and a pointer with two signed words
// (FS_SeekFile, FSi_ReadFileCore, FSi_ReadFileCommand).
typedef union Unk02003024U {
    struct {
        /* 00 */ u32 mUnk_00;
        /* 04 */ u32 mUnk_04;
        /* 08 */ u32 mUnk_08;
    } w;
    struct {
        /* 00 */ FSFileID mUnk_00;
        /* 08 */ u32 mUnk_08;
    } d;
    struct {
        /* 00 */ FSArchive *mUnk_00;
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

typedef struct FSFileLink {
    /* 00 */ FSFile *mPrev;
    /* 04 */ FSFile *mNext;
} FSFileLink;

// 0x48-byte record, set up by FS_InitFile (also used as a local); mArc is the archive it works through.
typedef struct FSFile {
    // FSi_ReleaseCommand links mLink.mPrev and mLink.mNext to each other, then clears both.
    /* 00 */ FSFileLink mLink;
    /* 08 */ FSArchive *mArc;
    /* 0c */ volatile u32 mStat; // bit 2 selects the path in FSi_TranslateCommand; FSi_ReleaseCommand clears 0x4f
    /* 10 */ u32 mCommand; // index passed to FSi_TranslateCommand by FSi_ExecuteSyncCommand and FSi_ExecuteAsyncCommand
    /* 14 */ s32 mError; // set from a return value in FSi_TranslateCommand and FSi_ReleaseCommand
    /* 18 */ OSThreadQueue mQueue;
    /* 20 */ Unk02003024U mProp;
    /* 2c */ u32 mUnk_2c;
    /* 30 */ Unk02003024U mArg;
    /* 3c */ const u8 *mPath;
    /* 40 */ u32 mFindDirectory;
    /* 44 */ Unk02003024U *mResult;
} FSFile;

// 0x5c-byte object (FS_InitArchive clears 0x5c bytes; data_0216f36c) at mArc of FSFile. Links at mNext and mPrev
// (FS_RegisterArchiveName, FS_ReleaseArchiveName), flags at mFlag, the list of FSFile at mList; the addresses of
// mSyncQ and mStatQ go to OS_WakeupThread and OS_SleepThread; mRead to mProc are called from FSi_TranslateCommand,
// FSi_WriteFileCommand, FSi_ReadFileCommand, FSi_ReadTable, FSi_SendCommand and FSi_NextCommand.
typedef struct FSArchive {
    /* 00 */ u32 mName;
    /* 04 */ FSArchive *mNext;
    /* 08 */ FSArchive *mPrev;
    /* 0c */ OSThreadQueue mSyncQ;
    /* 14 */ OSThreadQueue mStatQ;
    /* 1c */ volatile u32 mFlag;
    /* 20 */ FSFileLink mList;
    /* 28 */ u8 *mBase;
    /* 2c */ u32 mFat;
    /* 30 */ u32 mFatSize;
    /* 34 */ u32 mFnt;
    /* 38 */ u32 mFntSize;
    /* 3c */ u32 mFatBak;
    /* 40 */ u32 mFntBak;
    /* 44 */ u32 mLoadMem;
    /* 48 */ FS_ARCHIVE_READ_FUNC mRead;
    /* 4c */ FS_ARCHIVE_WRITE_FUNC mWrite;
    /* 50 */ FS_ARCHIVE_READ_FUNC mTable;
    /* 54 */ FS_ARCHIVE_PROC_FUNC mProc;
    /* 58 */ u32 mProcFlag;
} FSArchive;

// Called by FSi_TranslateCommand with its second argument as the index.
extern s32 (*data_02152b5c[])(FSFile *a);

s32 FSi_TranslateCommand(FSFile *file, u32 command);
void FSi_ReleaseCommand(FSFile *file, s32 result);
s32 FSi_CloseFileCommand(FSFile *file);

// Two words FSi_OpenFileFastCommand reads into FSFile.mArg.
typedef struct Unk02003234 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
} Unk02003234;

// FSi_ReadTable passes mUnk_04 to FSArchive.mTable of mUnk_00 and adds the count to it.
typedef struct Unk02003ad8 {
    /* 00 */ FSArchive *mUnk_00;
    /* 04 */ u32 mUnk_04;
} Unk02003ad8;

// Eight bytes read by FSi_SeekDirCommand.
typedef struct Unk0200399c {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
} Unk0200399c;

// Entry read by FSi_FindPathCommand, FSi_ReadDirCommand and FSi_GetPathCommand: a Unk02003024U, then a flag, a length
// and the bytes.
typedef struct Unk02003670 {
    /* 00 */ Unk02003024U mUnk_00;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u8 mUnk_14[0x80];
} Unk02003670;

s32 FSi_OpenFileFastCommand(FSFile *file);
s32 FSi_GetPathCommand(FSFile *file);
s32 FSi_FindPathCommand(FSFile *dir);
s32 FSi_ReadDirCommand(FSFile *dir);
s32 FSi_SeekDirCommand(FSFile *dir);
s32 FSi_WriteFileCommand(FSFile *file);
s32 FSi_ReadFileCommand(FSFile *file);
s32 FSi_SeekDirDirect(FSFile *dir, u32 id);
void FSi_ReadTable(Unk02003ad8 *param, void *dst, u32 len);
s32 FSi_StrNICmp(const u8 *str1, const u8 *str2, u32 len);
