#pragma once

#include "types.h"

typedef union Unk02003024U Unk02003024U;
typedef struct Unk02003024 Unk02003024;
typedef struct Unk02003a6c Unk02003a6c;

void FS_NotifyArchiveAsyncEnd(Unk02003a6c *archive, u32 result);
void FS_SetArchiveProc(Unk02003a6c *archive, s32 (*proc)(Unk02003024 *, u32), u32 flags);
u32 FS_ResumeArchive(Unk02003a6c *archive);
u32 FS_SuspendArchive(Unk02003a6c *archive);
u32 FS_UnloadArchiveTables(Unk02003a6c *archive);
u32 FS_LoadArchiveTables(Unk02003a6c *archive, u32 mem, u32 maxSize);
u32 FS_UnloadArchive(Unk02003a6c *archive);
u32 FS_LoadArchive(Unk02003a6c *archive, u8 *base, u32 fat, u32 fatSize, u32 fnt, u32 fntSize,
                   s32 (*readFunc)(Unk02003a6c *, void *, u32, u32), s32 (*writeFunc)(Unk02003a6c *, void *, u32, u32));
void FS_ReleaseArchiveName(Unk02003a6c *archive);
u32 FS_RegisterArchiveName(Unk02003a6c *archive, const u8 *name, s32 nameLen);
Unk02003a6c *FS_FindArchive(const u8 *name, s32 nameLen);

typedef struct Unk02003a6c Unk02003a6c;

void FS_InitArchive(Unk02003a6c *archive);

typedef struct Unk02005814 Unk02005814;
typedef struct Unk02003024 Unk02003024;
typedef struct Unk02003a6c Unk02003a6c;

u32 FSi_SendCommand(Unk02003024 *file, u32 command);
u32 FSi_ExecuteSyncCommand(Unk02003024 *file);
void FSi_ExecuteAsyncCommand(Unk02003024 *file);
Unk02003024 *FSi_NextCommand(Unk02003a6c *archive);
s32 FSi_ReadMemoryCore(Unk02003a6c *archive, void *dst, u32 pos, u32 size);
s32 FSi_WriteMemCallback(Unk02003a6c *archive, void *src, u32 pos, u32 size);
s32 FSi_ReadMemCallback(Unk02003a6c *archive, void *dst, u32 pos, u32 size);
u32 FSi_GetPackedName(const u8 *name, s32 nameLen);
u32 FS_ChangeDir(const u8 *path);
u32 FS_SeekFile(Unk02003024 *file, s32 offset, u32 origin);
s32 FS_ReadFile(Unk02003024 *file, void *dst, s32 len);
s32 FS_ReadFileAsync(Unk02003024 *file, void *dst, s32 len);
void FS_CancelFile(Unk02003024 *file);
u32 FS_WaitAsync(Unk02003024 *file);
u32 FS_CloseFile(Unk02003024 *file);
u32 FS_OpenFile(Unk02003024 *file, const u8 *path);
u32 FS_OpenFileFast(Unk02003024 *file, Unk02005814 fileID);
u32 FS_OpenFileDirect(Unk02003024 *file, Unk02003a6c *archive, u32 imageTop, u32 imageBottom, u32 fileIndex);
u32 FS_ConvertPathToFileID(Unk02005814 *fileID, const u8 *path);
s32 FSi_ReadFileCore(Unk02003024 *file, void *dst, s32 len, u32 async);
u32 FSi_FindPath(Unk02003024 *dir, const u8 *path, void *fileID, void *dirPos);

// First Unk02003a6c of the list FS_RegisterArchiveName builds through mUnk_04/mUnk_08 (FS_FindArchive searches it).
extern Unk02003a6c *data_0216f340;
// Set by FS_RegisterArchiveName, FS_ReleaseArchiveName and FS_ChangeDir; read by FSi_FindPath.
extern Unk02003024U data_0216f344;
