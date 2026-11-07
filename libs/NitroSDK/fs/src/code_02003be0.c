#include "code_02003be0.h"

#include "code_02003024.h"
#include "fs_file.h"
#include "os_thread.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/code_0214d000.h"

FSArchive *data_0216f340;
Unk02003024U data_0216f344;

// Resolves a path, with an optional "name:" archive prefix, against the current directory and sends the command.
u32 FSi_FindPath(FSFile *dir, const u8 *path, void *fileID, void *dirPos) {
    Unk02003024U pos;
    s32 i;
    FSArchive *archive;
    s32 loaded;

    if (path[0] == '/' || path[0] == '\\') {
        pos.h.mUnk_00 = data_0216f344.h.mUnk_00;
        pos.h.mUnk_04 = 0;
        pos.h.mUnk_08 = 0;
        pos.h.mUnk_06 = 0;
        path++;
    } else {
        pos = data_0216f344;
        for (i = 0; i <= 3; i++) {
            if (path[i] == 0 || path[i] == '/' || path[i] == '\\') {
                break;
            }
            if (path[i] == ':') {
                archive = FS_FindArchive(path, i);
                if (archive == 0) {
                    return 0;
                }
                if (archive->mFlag & 2) {
                    loaded = 1;
                } else {
                    loaded = 0;
                }
                if (loaded == 0) {
                    return 0;
                }
                pos.h.mUnk_00 = archive;
                pos.h.mUnk_08 = 0;
                pos.h.mUnk_06 = 0;
                pos.h.mUnk_04 = 0;
                path += i + 1;
                if (*path == '/' || *path == '\\') {
                    path++;
                }
                break;
            }
        }
    }
    dir->mArc = pos.h.mUnk_00;
    dir->mPath = path;
    dir->mArg = pos;
    if (dirPos != 0) {
        dir->mFindDirectory = 1;
        dir->mResult = dirPos;
    } else {
        dir->mFindDirectory = 0;
        dir->mResult = fileID;
    }
    return FSi_SendCommand(dir, 4);
}

// Reads up to len bytes from the file position; waits for the result unless async is set.
s32 FSi_ReadFileCore(FSFile *file, void *dst, s32 len, u32 async) {
    s32 start;
    s32 requested;

    start = file->mUnk_2c;
    requested = len;
    if (len > file->mProp.p.mUnk_08 - start) {
        len = file->mProp.p.mUnk_08 - start;
    }
    if (len < 0) {
        len = 0;
    }
    file->mArg.p.mUnk_00 = dst;
    file->mArg.p.mUnk_04 = requested;
    file->mArg.p.mUnk_08 = len;
    if (async == 0) {
        file->mStat |= 4;
    }
    FSi_SendCommand(file, 0);
    if (async == 0) {
        if (FS_WaitAsync(file) != 0) {
            len = file->mUnk_2c - start;
        } else {
            len = -1;
        }
    }
    return len;
}

// Looks up a path and stores the archive and file index.
u32 FS_ConvertPathToFileID(FSFileID *fileID, const u8 *path) {
    FSFile file;

    FS_InitFile(&file);
    return FSi_FindPath(&file, path, fileID, 0) != 0;
}

// Opens a file from an archive by byte range and file index.
u32 FS_OpenFileDirect(FSFile *file, FSArchive *archive, u32 imageTop, u32 imageBottom, u32 fileIndex) {
    file->mArc = archive;
    file->mArg.w.mUnk_08 = fileIndex;
    file->mArg.w.mUnk_00 = imageTop;
    file->mArg.w.mUnk_04 = imageBottom;
    if (FSi_SendCommand(file, 7) == 0) {
        return 0;
    }
    file->mStat |= 0x10;
    file->mStat &= ~0x20;
    return 1;
}

// Opens a file from the archive and index found by FS_ConvertPathToFileID.
u32 FS_OpenFileFast(FSFile *file, FSFileID fileID) {
    if (fileID.mArc == 0) {
        return 0;
    }
    file->mArc = fileID.mArc;
    file->mArg.d.mUnk_00 = fileID;
    if (FSi_SendCommand(file, 6) == 0) {
        return 0;
    }
    file->mStat |= 0x10;
    file->mStat &= ~0x20;
    return 1;
}

// Opens a file by path.
u32 FS_OpenFile(FSFile *file, const u8 *path) {
    FSFileID fileID;

    if (FS_ConvertPathToFileID(&fileID, path) != 0) {
        if (FS_OpenFileFast(file, fileID) != 0) {
            return 1;
        }
    }
    return 0;
}

// Closes an open file.
u32 FS_CloseFile(FSFile *file) {
    if (FSi_SendCommand(file, 8) == 0) {
        return 0;
    }
    file->mArc = 0;
    file->mCommand = 0xe;
    file->mStat &= ~0x30;
    return 1;
}

// Waits until the file has no command pending; runs the command itself if it has not started.
u32 FS_WaitAsync(FSFile *file) {
    u32 needsRun;
    u32 enabled;

    needsRun = 0;
    enabled = OS_DisableInterrupts();
    if (((file->mStat & 1) ? 1 : 0) != 0) {
        needsRun = (file->mStat & 0x44) == 0;
        if (needsRun) {
            file->mStat |= 4;
            do {
                OS_SleepThread(&file->mQueue);
            } while ((file->mStat & 0x40) == 0);
        } else {
            do {
                OS_SleepThread(&file->mQueue);
            } while (((file->mStat & 1) ? 1 : 0) != 0);
        }
    }
    OS_RestoreInterrupts(enabled);
    if (needsRun) {
        return FSi_ExecuteSyncCommand(file);
    }
    return file->mError == 0;
}

// Marks a pending command as cancelled.
void FS_CancelFile(FSFile *file) {
    u32 enabled;

    enabled = OS_DisableInterrupts();
    if (((file->mStat & 1) ? 1 : 0) != 0) {
        file->mStat |= 2;
        file->mArc->mFlag |= 0x20;
    }
    OS_RestoreInterrupts(enabled);
}

// Starts a read without waiting for it.
s32 FS_ReadFileAsync(FSFile *file, void *dst, s32 len) {
    return FSi_ReadFileCore(file, dst, len, 1);
}

// Reads and waits; returns the byte count or -1.
s32 FS_ReadFile(FSFile *file, void *dst, s32 len) {
    return FSi_ReadFileCore(file, dst, len, 0);
}

// Moves the file position, clamped to the file range; origin 0 is start, 1 current, 2 end.
u32 FS_SeekFile(FSFile *file, s32 offset, u32 origin) {
    switch (origin) {
        case 0:
            offset += file->mProp.p.mUnk_04;
            break;
        case 1:
            offset += file->mUnk_2c;
            break;
        case 2:
            offset += file->mProp.p.mUnk_08;
            break;
        default:
            return 0;
    }
    if (offset < file->mProp.p.mUnk_04) {
        offset = file->mProp.p.mUnk_04;
    }
    if (offset > file->mProp.p.mUnk_08) {
        offset = file->mProp.p.mUnk_08;
    }
    file->mUnk_2c = offset;
    return 1;
}

// Sets the current directory.
u32 FS_ChangeDir(const u8 *path) {
    Unk02003024U dirPos;
    FSFile searchFile;

    FS_InitFile(&searchFile);
    if (FSi_FindPath(&searchFile, path, 0, &dirPos) == 0) {
        return 0;
    }
    data_0216f344 = dirPos;
    return 1;
}

// Packs up to three characters of an archive name into a word, upper case folded to lower.
u32 FSi_GetPackedName(const u8 *name, s32 nameLen) {
    u32 packed;
    u32 diff;
    int i;

    packed = 0;
    if (nameLen <= 3) {
        for (i = 0; i < nameLen; i++) {
            if (name[i] == 0) {
                break;
            }
            diff = name[i] - 0x41;
            packed |= ((diff <= 0x19) ? diff + 0x61 : diff + 0x41) << (i * 8);
        }
    }
    return packed;
}

// Archive read callback that copies from the archive memory image.
s32 FSi_ReadMemCallback(FSArchive *archive, void *dst, u32 pos, u32 size) {
    MI_CpuCopy8(archive->mBase + pos, dst, size);
    return 0;
}

// Archive write callback that copies into the archive memory image.
s32 FSi_WriteMemCallback(FSArchive *archive, const void *src, u32 pos, u32 size) {
    MI_CpuCopy8(src, archive->mBase + pos, size);
    return 0;
}

// Table read callback that copies from an address.
s32 FSi_ReadMemoryCore(FSArchive *archive, void *dst, u32 pos, u32 size) {
    MI_CpuCopy8((const void *) pos, dst, size);
    return 0;
}

// Cancels flagged commands and returns the next command the archive should run, if it is not suspended.
FSFile *FSi_NextCommand(FSArchive *archive) {
    FSFile tmp;
    FSFile *file;
    FSFile *next;
    u32 enabled;
    u32 first;

    enabled = OS_DisableInterrupts();
    if (archive->mFlag & 0x20) {
        archive->mFlag &= ~0x20;
        file = archive->mList.mNext;
        if (file != 0) {
            do {
                next = file->mLink.mNext;
                if (((file->mStat & 2) ? 1 : 0) != 0) {
                    if (archive->mList.mNext == file) {
                        archive->mList.mNext = next;
                    }
                    FSi_ReleaseCommand(file, 3);
                    if (next == 0) {
                        next = archive->mList.mNext;
                    }
                }
                file = next;
            } while (next != 0);
        }
    }
    if (!(archive->mFlag & 0x40) && ((archive->mFlag & 8) ? 1 : 0) == 0 && (file = archive->mList.mNext) != 0) {
        first = ((archive->mFlag & 0x10) ? 1 : 0) == 0;
        if (first != 0) {
            archive->mFlag |= 0x10;
        }
        OS_RestoreInterrupts(enabled);
        if (first != 0 && (archive->mProcFlag & 0x200)) {
            archive->mProc(file, 9);
        }
        enabled = OS_DisableInterrupts();
        file->mStat |= 0x40;
        if (((file->mStat & 4) ? 1 : 0) != 0) {
            OS_WakeupThread(&file->mQueue);
            OS_RestoreInterrupts(enabled);
            return 0;
        }
        OS_RestoreInterrupts(enabled);
        return file;
    }
    if (archive->mFlag & 0x10) {
        archive->mFlag &= ~0x10;
        if (archive->mProcFlag & 0x400) {
            FS_InitFile(&tmp);
            tmp.mArc = archive;
            archive->mProc(&tmp, 10);
        }
    }
    if (archive->mFlag & 0x40) {
        archive->mFlag &= ~0x40;
        archive->mFlag |= 8;
        OS_WakeupThread(&archive->mStatQ);
    }
    OS_RestoreInterrupts(enabled);
    return 0;
}

// Runs the given command and then the following queued ones until one is left pending.
void FSi_ExecuteAsyncCommand(FSFile *file) {
    FSArchive *archive;
    u32 enabled;

    archive = file->mArc;
    if (file == 0) {
        return;
    }
    do {
        enabled = OS_DisableInterrupts();
        file->mStat |= 0x40;
        if (((file->mStat & 4) ? 1 : 0) != 0) {
            OS_WakeupThread(&file->mQueue);
            OS_RestoreInterrupts(enabled);
            return;
        }
        file->mStat |= 8;
        OS_RestoreInterrupts(enabled);
        if (FSi_TranslateCommand(file, file->mCommand) == 6) {
            return;
        }
        file = FSi_NextCommand(archive);
    } while (file != 0);
}

// Runs one command to completion, then starts the queue.
u32 FSi_ExecuteSyncCommand(FSFile *file) {
    FSFile *next;

    FSi_ReleaseCommand(file, FSi_TranslateCommand(file, file->mCommand));
    next = FSi_NextCommand(file->mArc);
    if (next != 0) {
        FSi_ExecuteAsyncCommand(next);
    }
    return file->mError == 0;
}

// Queues a command on its archive and runs it or waits for it.
u32 FSi_SendCommand(FSFile *file, u32 command) {
    FSArchive *archive;
    FSFile *tail;
    FSFile *prev;
    u32 mask;
    FSFile *next;
    u32 enabled;

    archive = file->mArc;
    file->mCommand = command;
    mask = 1 << command;
    file->mError = 2;
    file->mStat |= 1;
    enabled = OS_DisableInterrupts();
    if (archive->mFlag & 0x80) {
        FSi_ReleaseCommand(file, 3);
        OS_RestoreInterrupts(enabled);
        return 0;
    }
    if (mask & 0x1fc) {
        file->mStat |= 4;
    }
    prev = file->mLink.mPrev;
    tail = (FSFile *) &archive->mList;
    next = file->mLink.mNext;
    if (prev != 0) {
        prev->mLink.mNext = next;
    }
    if (next != 0) {
        next->mLink.mPrev = prev;
    }
    while (tail->mLink.mNext != 0) {
        tail = tail->mLink.mNext;
    }
    tail->mLink.mNext = file;
    file->mLink.mPrev = tail;
    file->mLink.mNext = 0;
    if (((archive->mFlag & 8) ? 1 : 0) == 0 && (archive->mFlag & 0x10) == 0) {
        archive->mFlag |= 0x10;
        OS_RestoreInterrupts(enabled);
        if (archive->mProcFlag & 0x200) {
            archive->mProc(file, 9);
        }
        enabled = OS_DisableInterrupts();
        file->mStat |= 0x40;
        if (((file->mStat & 4) ? 1 : 0) == 0) {
            OS_RestoreInterrupts(enabled);
            FSi_ExecuteAsyncCommand(file);
            return 1;
        }
        OS_RestoreInterrupts(enabled);
    } else {
        if (((file->mStat & 4) ? 1 : 0) == 0) {
            OS_RestoreInterrupts(enabled);
            return 1;
        }
        do {
            OS_SleepThread(&file->mQueue);
        } while ((file->mStat & 0x40) == 0);
        OS_RestoreInterrupts(enabled);
    }
    return FSi_ExecuteSyncCommand(file);
}

// Clears an archive and its thread queues.
void FS_InitArchive(FSArchive *archive) {
    MI_CpuFill8(archive, 0, 0x5c);
    archive->mSyncQ.mTail = 0;
    archive->mSyncQ.mHead = archive->mSyncQ.mTail;
    archive->mStatQ.mTail = 0;
    archive->mStatQ.mHead = archive->mStatQ.mTail;
}

// Finds a registered archive by name.
FSArchive *FS_FindArchive(const u8 *name, s32 nameLen) {
    u32 packed;
    u32 enabled;
    FSArchive *archive;

    packed = FSi_GetPackedName(name, nameLen);
    enabled = OS_DisableInterrupts();
    archive = data_0216f340;
    while (archive != 0 && archive->mName != packed) {
        archive = archive->mNext;
    }
    OS_RestoreInterrupts(enabled);
    return archive;
}

// Adds an archive to the list under the given name.
u32 FS_RegisterArchiveName(FSArchive *archive, const u8 *name, s32 nameLen) {
    u32 result;
    u32 enabled;
    FSArchive *tail;

    result = 0;
    enabled = OS_DisableInterrupts();
    if (FS_FindArchive(name, nameLen) == 0) {
        if (data_0216f340 == 0) {
            data_0216f340 = archive;
            data_0216f344.h.mUnk_00 = archive;
            data_0216f344.h.mUnk_08 = 0;
            data_0216f344.h.mUnk_06 = 0;
            data_0216f344.h.mUnk_04 = 0;
        } else {
            tail = data_0216f340;
            while (tail->mNext != 0) {
                tail = tail->mNext;
            }
            tail->mNext = archive;
            archive->mPrev = tail;
        }
        archive->mName = FSi_GetPackedName(name, nameLen);
        result = 1;
        archive->mFlag |= 1;
    }
    OS_RestoreInterrupts(enabled);
    return result;
}

// Removes an archive from the list.
void FS_ReleaseArchiveName(FSArchive *archive) {
    u32 enabled;

    if (archive->mName == 0) {
        return;
    }
    enabled = OS_DisableInterrupts();
    if (archive->mNext != 0) {
        archive->mNext->mPrev = archive->mPrev;
    }
    if (archive->mPrev != 0) {
        archive->mPrev->mNext = archive->mNext;
    }
    archive->mName = 0;
    archive->mPrev = 0;
    archive->mNext = archive->mPrev;
    archive->mFlag &= ~1;
    if (data_0216f344.h.mUnk_00 == archive) {
        data_0216f344.h.mUnk_08 = 0;
        data_0216f344.h.mUnk_06 = 0;
        data_0216f344.h.mUnk_00 = data_0216f340;
        data_0216f344.h.mUnk_04 = 0;
    }
    OS_RestoreInterrupts(enabled);
}

// Sets the archive memory image, table offsets and read and write callbacks.
u32 FS_LoadArchive(FSArchive *archive, u8 *base, u32 fat, u32 fatSize, u32 fnt, u32 fntSize,
                   FS_ARCHIVE_READ_FUNC readFunc, FS_ARCHIVE_WRITE_FUNC writeFunc) {
    archive->mBase = base;
    archive->mFatSize = fatSize;
    archive->mFatBak = fat;
    archive->mFat = archive->mFatBak;
    archive->mFntSize = fntSize;
    archive->mFntBak = fnt;
    archive->mFnt = archive->mFntBak;
    archive->mRead = (readFunc == 0) ? FSi_ReadMemCallback : readFunc;
    archive->mWrite = (writeFunc == 0) ? FSi_WriteMemCallback : writeFunc;
    archive->mTable = archive->mRead;
    archive->mLoadMem = 0;
    archive->mFlag |= 2;
    return 1;
}

// Cancels the queued commands and clears the archive.
u32 FS_UnloadArchive(FSArchive *archive) {
    u32 enabled;
    FSFile *file;
    FSFile *next;
    u32 suspended;

    enabled = OS_DisableInterrupts();
    if (((archive->mFlag & 2) ? 1 : 0) != 0) {
        archive->mFlag;
        suspended = FS_SuspendArchive(archive);
        archive->mFlag |= 0x80;
        file = archive->mList.mNext;
        if (file != 0) {
            do {
                next = file->mLink.mNext;
                FSi_ReleaseCommand(file, 3);
                file = next;
            } while (next != 0);
        }
        archive->mList.mNext = 0;
        if (suspended != 0) {
            FS_ResumeArchive(archive);
        }
        archive->mBase = 0;
        archive->mFat = 0;
        archive->mFatSize = 0;
        archive->mFnt = 0;
        archive->mFntSize = 0;
        archive->mFntBak = 0;
        archive->mFatBak = archive->mFntBak;
        archive->mFlag &= ~0xa2;
    }
    OS_RestoreInterrupts(enabled);
    return 1;
}

// Copies the two tables into memory; returns the size needed.
u32 FS_LoadArchiveTables(FSArchive *archive, u32 mem, u32 maxSize) {
    FSFile tmp;
    u32 totalSize;

    totalSize = ((s32) (archive->mFatSize + archive->mFntSize + 32) + 31) & ~31;
    if (totalSize <= maxSize) {
        u8 *cache;

        cache = (u8 *) ((mem + 31) & ~31);
        FS_InitFile(&tmp);
        if (FS_OpenFileDirect(&tmp, archive, archive->mFat, archive->mFat + archive->mFatSize, -1) != 0) {
            if (FS_ReadFile(&tmp, cache, archive->mFatSize) < 0) {
                MI_CpuFill8(cache, 0, archive->mFatSize);
            }
            FS_CloseFile(&tmp);
        }
        archive->mFat = (u32) cache;
        cache += archive->mFatSize;
        if (FS_OpenFileDirect(&tmp, archive, archive->mFnt, archive->mFnt + archive->mFntSize, -1) != 0) {
            if (FS_ReadFile(&tmp, cache, archive->mFntSize) < 0) {
                MI_CpuFill8(cache, 0, archive->mFntSize);
            }
            FS_CloseFile(&tmp);
        }
        archive->mFnt = (u32) cache;
        archive->mLoadMem = mem;
        archive->mTable = FSi_ReadMemoryCore;
        archive->mFlag |= 4;
    }
    return totalSize;
}

// Returns the archive to reading its tables from the image; returns the table memory.
u32 FS_UnloadArchiveTables(FSArchive *archive) {
    u32 mem;
    u32 suspended;

    mem = 0;
    if (((archive->mFlag & 2) ? 1 : 0) != 0) {
        suspended = FS_SuspendArchive(archive);
        if (((archive->mFlag & 4) ? 1 : 0) != 0) {
            archive->mFlag &= ~4;
            mem = archive->mLoadMem;
            archive->mLoadMem = 0;
            archive->mFat = archive->mFatBak;
            archive->mFnt = archive->mFntBak;
            archive->mTable = archive->mRead;
        }
        if (suspended != 0) {
            FS_ResumeArchive(archive);
        }
    }
    return mem;
}

// Stops the archive from starting commands; returns whether it was not already suspended.
u32 FS_SuspendArchive(FSArchive *archive) {
    u32 enabled;
    u32 result;

    enabled = OS_DisableInterrupts();
    result = ((archive->mFlag & 8) ? 1 : 0) == 0;
    if (result) {
        if (archive->mFlag & 0x10) {
            archive->mFlag |= 0x40;
            do {
                OS_SleepThread(&archive->mStatQ);
            } while (archive->mFlag & 0x40);
        } else {
            archive->mFlag |= 8;
        }
    }
    OS_RestoreInterrupts(enabled);
    return result;
}

// Lets a suspended archive start commands again.
u32 FS_ResumeArchive(FSArchive *archive) {
    FSFile *next;
    u32 enabled;
    u32 result;

    next = 0;
    enabled = OS_DisableInterrupts();
    result = ((archive->mFlag & 8) ? 1 : 0) == 0;
    if (!result) {
        archive->mFlag &= ~8;
        next = FSi_NextCommand(archive);
    }
    OS_RestoreInterrupts(enabled);
    if (next != 0) {
        FSi_ExecuteAsyncCommand(next);
    }
    return result;
}

// Sets the archive notification callback and the events it receives.
void FS_SetArchiveProc(FSArchive *archive, FS_ARCHIVE_PROC_FUNC proc, u32 flags) {
    if (flags == 0) {
        proc = 0;
    } else if (proc == 0) {
        flags = 0;
    }
    archive->mProc = proc;
    archive->mProcFlag = flags;
}

// Ends an asynchronous command with the given result.
void FS_NotifyArchiveAsyncEnd(FSArchive *archive, u32 result) {
    u32 enabled;
    FSFile *file;

    if (archive->mFlag & 0x100) {
        file = archive->mList.mNext;
        archive->mFlag &= ~0x100;
        FSi_ReleaseCommand(file, result);
        file = FSi_NextCommand(archive);
        if (file != 0) {
            FSi_ExecuteAsyncCommand(file);
        }
    } else {
        file = archive->mList.mNext;
        enabled = OS_DisableInterrupts();
        file->mError = result;
        archive->mFlag &= ~0x200;
        OS_WakeupThread(&archive->mSyncQ);
        OS_RestoreInterrupts(enabled);
    }
}
