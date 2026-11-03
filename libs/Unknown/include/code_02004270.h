#pragma once

#include "types.h"

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
