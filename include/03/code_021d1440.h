#pragma once

#include "types.h"

typedef struct FSFile FSFile;
typedef struct FSArchive FSArchive;

BOOL AreStringEndsEqual(const u8 *first, const char *second, s32 endLength);
void DeleteLoadedFile(void *block, ...);
void *LoadFile(const u8 *path, u32 *outSize, s32 alignment);
s32 DwcArchiveWriteCallback(void);
void DwcArchiveReadEndCallback(FSArchive *archive);
u32 DwcArchiveReadCallback(int archive, u32 dst, int offset, u32 length);
s32 DwcArchiveProc(FSFile *file, u32 command);
void ReleaseDwcArchive(void);
void InitDwcArchive(void);
