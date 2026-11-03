#pragma once

#include "types.h"

typedef union Unk02003024U Unk02003024U;
typedef struct Unk02003024 Unk02003024;
typedef struct Unk02003a6c Unk02003a6c;

void FS_NotifyArchiveAsyncEnd(Unk02003a6c *p0, u32 p1);
void FS_SetArchiveProc(Unk02003a6c *p0, s32 (*p1)(Unk02003024 *, u32), u32 p2);
u32 FS_ResumeArchive(Unk02003a6c *p0);
u32 FS_SuspendArchive(Unk02003a6c *p0);
u32 FS_UnloadArchiveTables(Unk02003a6c *p0);
u32 FS_LoadArchiveTables(Unk02003a6c *p0, u32 p1, u32 p2);
u32 FS_UnloadArchive(Unk02003a6c *p0);
u32 FS_LoadArchive(Unk02003a6c *p0, u8 *p1, u32 p2, u32 p3, u32 p4, u32 p5, s32 (*p6)(Unk02003a6c *, void *, u32, u32),
                   s32 (*p7)(Unk02003a6c *, void *, u32, u32));
void FS_ReleaseArchiveName(Unk02003a6c *p0);
u32 FS_RegisterArchiveName(Unk02003a6c *p0, const u8 *p1, s32 p2);
Unk02003a6c *FS_FindArchive(const u8 *p0, s32 p1);

typedef struct Unk02003a6c Unk02003a6c;

void FS_InitArchive(Unk02003a6c *arg0);

typedef struct Unk02005814 Unk02005814;
typedef struct Unk02003024 Unk02003024;
typedef struct Unk02003a6c Unk02003a6c;

u32 FileQueueCommand(Unk02003024 *p0, u32 p1);
u32 FileRunCommandBlocking(Unk02003024 *p0);
void FileRunQueueAsync(Unk02003024 *p0);
Unk02003024 *FilePickNextCommand(Unk02003a6c *p0);
s32 FileCopyFromAddress(Unk02003a6c *p0, void *p1, u32 p2, u32 p3);
s32 FileCopyToArchiveMemory(Unk02003a6c *p0, void *p1, u32 p2, u32 p3);
s32 FileCopyFromArchiveMemory(Unk02003a6c *p0, void *p1, u32 p2, u32 p3);
u32 FilePackLowercaseName(const u8 *p0, s32 p1);
u32 FS_ChangeDir(const u8 *p0);
u32 FS_SeekFile(Unk02003024 *p0, s32 p1, u32 p2);
s32 FS_ReadFile(Unk02003024 *p0, void *p1, s32 p2);
s32 FS_ReadFileAsync(Unk02003024 *p0, void *p1, s32 p2);
void FS_CancelFile(Unk02003024 *p0);
u32 FS_WaitAsync(Unk02003024 *p0);
u32 FS_CloseFile(Unk02003024 *p);
u32 FS_OpenFile(Unk02003024 *p, const u8 *path);
u32 FS_OpenFileFast(Unk02003024 *p, Unk02005814 s);
u32 FS_OpenFileDirect(Unk02003024 *p, Unk02003a6c *owner, u32 a, u32 b, u32 c);
u32 FS_ConvertPathToFileID(Unk02005814 *out, const u8 *path);
s32 FileReadClamped(Unk02003024 *p, void *buf, s32 n, u32 flag);
u32 FileLookUpPath(Unk02003024 *p, const u8 *path, void *out, void *flag);

// First Unk02003a6c of the list FS_RegisterArchiveName builds through mUnk_04/mUnk_08 (FS_FindArchive searches it).
extern Unk02003a6c *data_0216f340;
// Set by FS_RegisterArchiveName, FS_ReleaseArchiveName and FS_ChangeDir; read by FileLookUpPath.
extern Unk02003024U data_0216f344;
