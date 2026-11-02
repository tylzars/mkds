#pragma once

#include "types.h"
#include "code_02003024.h"

// First Unk02003a6c of the list FS_RegisterArchiveName builds through mUnk_04/mUnk_08 (FS_FindArchive searches it).
extern Unk02003a6c *data_0216f340;
// Set by FS_RegisterArchiveName, FS_ReleaseArchiveName and FS_ChangeDir; read by FileLookUpPath.
extern Unk02003024U data_0216f344;

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
