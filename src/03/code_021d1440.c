#include "03/code_021d1440.h"
#include "03/unk_021da000.h"
#include "03/code_021d1000.h"
#include "Main/Unknown/code_02146000.h"
#include "code_021458c4.h"

#include "03/code_021d1d4c.h"
#include "03/code_021d1cd4.h"
#include "03/code_021d27d8.h"
#include "03/unk_021d7bd4.h"
#include "fs_file.h"
#include "code_02003be0.h"
#include "string.h"
#include "code_02134398.h"
#include "code_02139f70.h"
#include "code_0214d018.h"
#include "code_0200fc8c.h"
#include "03/code_021d1d60.h"
#include "03/unk_021d67d8.h"
#include "code_0200cd1c.h"
#include "os_printf.h"
#include "code_0214578c.h"

void InitDwcArchive(void) {
    FSFile file;
    u32 fntRegion[2];
    u32 fatRegion[2];
    char dirPath[0x80];
    u32 base;
    u32 tablesSize;

    gDwcArchive = AllocZeroedExpHeapBlock(0xe8, 4);
    FS_InitFile(&file);
    if (FS_OpenFile(&file, data_ov003_021d7be0) == 0) {
        OS_Terminate();
    }
    gDwcArchive->mLockId = OS_GetLockID();
    base = file.mProp.w.mUnk_04;
    FS_ReadFile(&file, fntRegion, 8);
    FS_ReadFile(&file, fatRegion, 8);
    FS_CloseFile(&file);
    FS_InitArchive(&gDwcArchive->mArchive);
    if (FS_RegisterArchiveName(&gDwcArchive->mArchive, data_ov003_021d67d8, 3) == 0) {
        OS_Terminate();
    }
    FS_SetArchiveProc(&gDwcArchive->mArchive, DwcArchiveProc, 0x602);
    if (FS_LoadArchive(&gDwcArchive->mArchive, (u8 *) base, fatRegion[0], fatRegion[1], fntRegion[0], fntRegion[1],
                       (FS_ARCHIVE_READ_FUNC) DwcArchiveReadCallback,
                       (FS_ARCHIVE_WRITE_FUNC) DwcArchiveWriteCallback) == 0) {
        OS_Terminate();
    }
    tablesSize = FS_LoadArchiveTables(&gDwcArchive->mArchive, 0, 0);
    gDwcArchive->mTables = AllocExpHeapBlock(tablesSize, 4);
    FS_LoadArchiveTables(&gDwcArchive->mArchive, (u32) gDwcArchive->mTables, tablesSize);
    gDwcArchive->mUnk_84 = CreateFilledPointerStack(0x20, gDwcArchive->mUnk_04, 4);
    OS_SPrintf(dirPath, data_ov003_021d7bf8, data_ov003_021d67d8);
    FS_ChangeDir((u8 *) dirPath);
}

void ReleaseDwcArchive(void) {
    FS_ChangeDir(data_ov003_021d7bd8);
    FS_UnloadArchiveTables(&gDwcArchive->mArchive);
    FS_UnloadArchive(&gDwcArchive->mArchive);
    FS_ReleaseArchiveName(&gDwcArchive->mArchive);
    OS_ReleaseLockID(gDwcArchive->mLockId);
    gDwcArchive->mLockId = 0;
    FreeExpHeapBlockAndClearPointer(gDwcArchive);
    gDwcArchive->mTables = NULL;
    FreeExpHeapBlockAndClearPointer(&gDwcArchive);
}

s32 DwcArchiveProc(FSFile *file, u32 command) {
    switch (command) {
        case 9:
            CARD_LockRom(gDwcArchive->mLockId);
            return 0;
        case 10:
            CARD_UnlockRom(gDwcArchive->mLockId);
            return 0;
        case 1:
            return 4;
        default:
            return 8;
    }
}

u32 DwcArchiveReadCallback(int archive, u32 dst, int offset, u32 length) {
    CARDi_ReadRom(0xffffffff, (offset + *(s32 *) (archive + 0x28)), dst, length,
                  (UnkFunc *) (&DwcArchiveReadEndCallback), archive, 1);
    return 6;
}

void DwcArchiveReadEndCallback(FSArchive *archive) {
    FS_NotifyArchiveAsyncEnd(archive, 0);
}

s32 DwcArchiveWriteCallback(void) {
    return 1;
}

void *LoadFile(const u8 *path, u32 *outSize, s32 alignment) {
    FSFile file;
    void *fileData;
    u32 c;
    s32 readAlignment;

    PopPointerStack(gDwcArchive->mUnk_84);
    FS_InitFile(&file);
    if (FS_OpenFile(&file, path) == 0) {
        OS_Terminate();
    }
    c = file.mProp.w.mUnk_08 - file.mProp.w.mUnk_04;
    if (outSize != NULL) {
        *outSize = c;
    }
    if (AreStringEndsEqual(path, data_ov003_021d7bd4, 2) != 0) {
        readAlignment = -4;
    } else {
        readAlignment = alignment;
    }
    fileData = AllocExpHeapBlock(c, readAlignment);
    FS_ReadFile(&file, fileData, c);
    FS_CloseFile(&file);
    if (readAlignment > 0) {
        return fileData;
    }
    c = *(u32 *) fileData >> 8;
    if (outSize != NULL) {
        *outSize = c;
    }
    {
        void *uncompressed = AllocExpHeapBlock(c, alignment);

        MI_UncompressLZ8(fileData, uncompressed);
        FreeExpHeapBlockAndClearPointer(&fileData);
        return uncompressed;
    }
}

void DeleteLoadedFile(void *block, ...) {
    FreeExpHeapBlockAndClearPointer(&block);
    PushPointerStack(gDwcArchive->mUnk_84, block);
}

BOOL AreStringEndsEqual(const u8 *first, const char *second, s32 endLength) {
    s32 firstLength = strlen((const char *) first);
    s32 secondLength = strlen(second);

    if (firstLength < endLength || secondLength < endLength) {
        return 0;
    }
    if (memcmp(first + (firstLength - endLength), second + (secondLength - endLength), endLength) == 0) {
        return 1;
    }
    return 0;
}
