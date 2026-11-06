#pragma once

#include "types.h"

#include "code_02003024.h"

void FS_NotifyArchiveAsyncEnd(FSArchive *archive, u32 result);
void FS_SetArchiveProc(FSArchive *archive, FS_ARCHIVE_PROC_FUNC proc, u32 flags);
u32 FS_ResumeArchive(FSArchive *archive);
u32 FS_SuspendArchive(FSArchive *archive);
u32 FS_UnloadArchiveTables(FSArchive *archive);
u32 FS_LoadArchiveTables(FSArchive *archive, u32 mem, u32 maxSize);
u32 FS_UnloadArchive(FSArchive *archive);
u32 FS_LoadArchive(FSArchive *archive, u8 *base, u32 fat, u32 fatSize, u32 fnt, u32 fntSize,
                   FS_ARCHIVE_READ_FUNC readFunc, FS_ARCHIVE_WRITE_FUNC writeFunc);
void FS_ReleaseArchiveName(FSArchive *archive);
u32 FS_RegisterArchiveName(FSArchive *archive, const u8 *name, s32 nameLen);
FSArchive *FS_FindArchive(const u8 *name, s32 nameLen);

void FS_InitArchive(FSArchive *archive);

u32 FSi_SendCommand(FSFile *file, u32 command);
u32 FSi_ExecuteSyncCommand(FSFile *file);
void FSi_ExecuteAsyncCommand(FSFile *file);
FSFile *FSi_NextCommand(FSArchive *archive);
s32 FSi_ReadMemoryCore(FSArchive *archive, void *dst, u32 pos, u32 size);
s32 FSi_WriteMemCallback(FSArchive *archive, const void *src, u32 pos, u32 size);
s32 FSi_ReadMemCallback(FSArchive *archive, void *dst, u32 pos, u32 size);
u32 FSi_GetPackedName(const u8 *name, s32 nameLen);
u32 FS_ChangeDir(const u8 *path);
u32 FS_SeekFile(FSFile *file, s32 offset, u32 origin);
s32 FS_ReadFile(FSFile *file, void *dst, s32 len);
s32 FS_ReadFileAsync(FSFile *file, void *dst, s32 len);
void FS_CancelFile(FSFile *file);
u32 FS_WaitAsync(FSFile *file);
u32 FS_CloseFile(FSFile *file);
u32 FS_OpenFile(FSFile *file, const u8 *path);
u32 FS_OpenFileFast(FSFile *file, FSFileID fileID);
u32 FS_OpenFileDirect(FSFile *file, FSArchive *archive, u32 imageTop, u32 imageBottom, u32 fileIndex);
u32 FS_ConvertPathToFileID(FSFileID *fileID, const u8 *path);
s32 FSi_ReadFileCore(FSFile *file, void *dst, s32 len, u32 async);
u32 FSi_FindPath(FSFile *dir, const u8 *path, void *fileID, void *dirPos);

// First FSArchive of the list FS_RegisterArchiveName builds through mNext/mPrev (FS_FindArchive searches it).
extern FSArchive *data_0216f340;
// Set by FS_RegisterArchiveName, FS_ReleaseArchiveName and FS_ChangeDir; read by FSi_FindPath.
extern Unk02003024U data_0216f344;
