#include "code_02003be0.h"

#include "code_02003024.h"
#include "code_02004d80.h"
#include "code_0200db4c.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/code_0214d000.h"

Unk02003a6c *data_0216f340;
Unk02003024U data_0216f344;

// Resolves a path, with an optional "name:" archive prefix, against the current directory and sends the command.
u32 FSi_FindPath(Unk02003024 *dir, const u8 *path, void *fileID, void *dirPos) {
    Unk02003024U pos;
    s32 i;
    Unk02003a6c *archive;
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
                if (archive->mUnk_1c & 2) {
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
    dir->mUnk_08 = pos.h.mUnk_00;
    dir->mUnk_3c = path;
    dir->mUnk_30 = pos;
    if (dirPos != 0) {
        dir->mUnk_40 = 1;
        dir->mUnk_44 = dirPos;
    } else {
        dir->mUnk_40 = 0;
        dir->mUnk_44 = fileID;
    }
    return FSi_SendCommand(dir, 4);
}

// Reads up to len bytes from the file position; waits for the result unless async is set.
s32 FSi_ReadFileCore(Unk02003024 *file, void *dst, s32 len, u32 async) {
    s32 start;
    s32 requested;

    start = file->mUnk_2c;
    requested = len;
    if (len > file->mUnk_20.p.mUnk_08 - start) {
        len = file->mUnk_20.p.mUnk_08 - start;
    }
    if (len < 0) {
        len = 0;
    }
    file->mUnk_30.p.mUnk_00 = dst;
    file->mUnk_30.p.mUnk_04 = requested;
    file->mUnk_30.p.mUnk_08 = len;
    if (async == 0) {
        file->mUnk_0c |= 4;
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
u32 FS_ConvertPathToFileID(Unk02005814 *fileID, const u8 *path) {
    Unk02003024 file;

    FS_InitFile(&file);
    return FSi_FindPath(&file, path, fileID, 0) != 0;
}

// Opens a file from an archive by byte range and file index.
u32 FS_OpenFileDirect(Unk02003024 *file, Unk02003a6c *archive, u32 imageTop, u32 imageBottom, u32 fileIndex) {
    file->mUnk_08 = archive;
    file->mUnk_30.w.mUnk_08 = fileIndex;
    file->mUnk_30.w.mUnk_00 = imageTop;
    file->mUnk_30.w.mUnk_04 = imageBottom;
    if (FSi_SendCommand(file, 7) == 0) {
        return 0;
    }
    file->mUnk_0c |= 0x10;
    file->mUnk_0c &= ~0x20;
    return 1;
}

// Opens a file from the archive and index found by FS_ConvertPathToFileID.
u32 FS_OpenFileFast(Unk02003024 *file, Unk02005814 fileID) {
    if (fileID.mUnk_00 == 0) {
        return 0;
    }
    file->mUnk_08 = fileID.mUnk_00;
    file->mUnk_30.d.mUnk_00 = fileID;
    if (FSi_SendCommand(file, 6) == 0) {
        return 0;
    }
    file->mUnk_0c |= 0x10;
    file->mUnk_0c &= ~0x20;
    return 1;
}

// Opens a file by path.
u32 FS_OpenFile(Unk02003024 *file, const u8 *path) {
    Unk02005814 fileID;

    if (FS_ConvertPathToFileID(&fileID, path) != 0) {
        if (FS_OpenFileFast(file, fileID) != 0) {
            return 1;
        }
    }
    return 0;
}

// Closes an open file.
u32 FS_CloseFile(Unk02003024 *file) {
    if (FSi_SendCommand(file, 8) == 0) {
        return 0;
    }
    file->mUnk_08 = 0;
    file->mUnk_10 = 0xe;
    file->mUnk_0c &= ~0x30;
    return 1;
}

// Waits until the file has no command pending; runs the command itself if it has not started.
u32 FS_WaitAsync(Unk02003024 *file) {
    u32 needsRun;
    u32 enabled;

    needsRun = 0;
    enabled = OS_DisableInterrupts();
    if (((file->mUnk_0c & 1) ? 1 : 0) != 0) {
        needsRun = (file->mUnk_0c & 0x44) == 0;
        if (needsRun) {
            file->mUnk_0c |= 4;
            do {
                OS_SleepThread(&file->mUnk_18);
            } while ((file->mUnk_0c & 0x40) == 0);
        } else {
            do {
                OS_SleepThread(&file->mUnk_18);
            } while (((file->mUnk_0c & 1) ? 1 : 0) != 0);
        }
    }
    OS_RestoreInterrupts(enabled);
    if (needsRun) {
        return FSi_ExecuteSyncCommand(file);
    }
    return file->mUnk_14 == 0;
}

// Marks a pending command as cancelled.
void FS_CancelFile(Unk02003024 *file) {
    u32 enabled;

    enabled = OS_DisableInterrupts();
    if (((file->mUnk_0c & 1) ? 1 : 0) != 0) {
        file->mUnk_0c |= 2;
        file->mUnk_08->mUnk_1c |= 0x20;
    }
    OS_RestoreInterrupts(enabled);
}

// Starts a read without waiting for it.
s32 FS_ReadFileAsync(Unk02003024 *file, void *dst, s32 len) {
    return FSi_ReadFileCore(file, dst, len, 1);
}

// Reads and waits; returns the byte count or -1.
s32 FS_ReadFile(Unk02003024 *file, void *dst, s32 len) {
    return FSi_ReadFileCore(file, dst, len, 0);
}

// Moves the file position, clamped to the file range; origin 0 is start, 1 current, 2 end.
u32 FS_SeekFile(Unk02003024 *file, s32 offset, u32 origin) {
    switch (origin) {
        case 0:
            offset += file->mUnk_20.p.mUnk_04;
            break;
        case 1:
            offset += file->mUnk_2c;
            break;
        case 2:
            offset += file->mUnk_20.p.mUnk_08;
            break;
        default:
            return 0;
    }
    if (offset < file->mUnk_20.p.mUnk_04) {
        offset = file->mUnk_20.p.mUnk_04;
    }
    if (offset > file->mUnk_20.p.mUnk_08) {
        offset = file->mUnk_20.p.mUnk_08;
    }
    file->mUnk_2c = offset;
    return 1;
}

// Sets the current directory.
u32 FS_ChangeDir(const u8 *path) {
    Unk02003024U dirPos;
    Unk02003024 dir;

    FS_InitFile(&dir);
    if (FSi_FindPath(&dir, path, 0, &dirPos) == 0) {
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
s32 FSi_ReadMemCallback(Unk02003a6c *archive, void *dst, u32 pos, u32 size) {
    MI_CpuCopy8(archive->mUnk_28 + pos, dst, size);
    return 0;
}

// Archive write callback that copies into the archive memory image.
s32 FSi_WriteMemCallback(Unk02003a6c *archive, void *src, u32 pos, u32 size) {
    MI_CpuCopy8(src, archive->mUnk_28 + pos, size);
    return 0;
}

// Table read callback that copies from an address.
s32 FSi_ReadMemoryCore(Unk02003a6c *archive, void *dst, u32 pos, u32 size) {
    MI_CpuCopy8((const void *) pos, dst, size);
    return 0;
}

// Cancels flagged commands and returns the next command the archive should run, if it is not suspended.
Unk02003024 *FSi_NextCommand(Unk02003a6c *archive) {
    Unk02003024 tmp;
    Unk02003024 *file;
    Unk02003024 *next;
    u32 enabled;
    u32 first;

    enabled = OS_DisableInterrupts();
    if (archive->mUnk_1c & 0x20) {
        archive->mUnk_1c &= ~0x20;
        file = archive->mUnk_24;
        if (file != 0) {
            do {
                next = file->mUnk_04;
                if (((file->mUnk_0c & 2) ? 1 : 0) != 0) {
                    if (archive->mUnk_24 == file) {
                        archive->mUnk_24 = next;
                    }
                    FileFinishCommand(file, 3);
                    if (next == 0) {
                        next = archive->mUnk_24;
                    }
                }
                file = next;
            } while (next != 0);
        }
    }
    if (!(archive->mUnk_1c & 0x40) && ((archive->mUnk_1c & 8) ? 1 : 0) == 0 && (file = archive->mUnk_24) != 0) {
        first = ((archive->mUnk_1c & 0x10) ? 1 : 0) == 0;
        if (first != 0) {
            archive->mUnk_1c |= 0x10;
        }
        OS_RestoreInterrupts(enabled);
        if (first != 0 && (archive->mUnk_58 & 0x200)) {
            archive->mUnk_54(file, 9);
        }
        enabled = OS_DisableInterrupts();
        file->mUnk_0c |= 0x40;
        if (((file->mUnk_0c & 4) ? 1 : 0) != 0) {
            OS_WakeupThread(&file->mUnk_18);
            OS_RestoreInterrupts(enabled);
            return 0;
        }
        OS_RestoreInterrupts(enabled);
        return file;
    }
    if (archive->mUnk_1c & 0x10) {
        archive->mUnk_1c &= ~0x10;
        if (archive->mUnk_58 & 0x400) {
            FS_InitFile(&tmp);
            tmp.mUnk_08 = archive;
            archive->mUnk_54(&tmp, 10);
        }
    }
    if (archive->mUnk_1c & 0x40) {
        archive->mUnk_1c &= ~0x40;
        archive->mUnk_1c |= 8;
        OS_WakeupThread(&archive->mUnk_14);
    }
    OS_RestoreInterrupts(enabled);
    return 0;
}

// Runs the given command and then the following queued ones until one is left pending.
void FSi_ExecuteAsyncCommand(Unk02003024 *file) {
    Unk02003a6c *archive;
    u32 enabled;

    archive = file->mUnk_08;
    if (file == 0) {
        return;
    }
    do {
        enabled = OS_DisableInterrupts();
        file->mUnk_0c |= 0x40;
        if (((file->mUnk_0c & 4) ? 1 : 0) != 0) {
            OS_WakeupThread(&file->mUnk_18);
            OS_RestoreInterrupts(enabled);
            return;
        }
        file->mUnk_0c |= 8;
        OS_RestoreInterrupts(enabled);
        if (FileDispatchCommand(file, file->mUnk_10) == 6) {
            return;
        }
        file = FSi_NextCommand(archive);
    } while (file != 0);
}

// Runs one command to completion, then starts the queue.
u32 FSi_ExecuteSyncCommand(Unk02003024 *file) {
    Unk02003024 *next;

    FileFinishCommand(file, FileDispatchCommand(file, file->mUnk_10));
    next = FSi_NextCommand(file->mUnk_08);
    if (next != 0) {
        FSi_ExecuteAsyncCommand(next);
    }
    return file->mUnk_14 == 0;
}

// Queues a command on its archive and runs it or waits for it.
u32 FSi_SendCommand(Unk02003024 *file, u32 command) {
    Unk02003a6c *archive;
    Unk02003024 *tail;
    Unk02003024 *prev;
    u32 mask;
    Unk02003024 *next;
    u32 enabled;

    archive = file->mUnk_08;
    file->mUnk_10 = command;
    mask = 1 << command;
    file->mUnk_14 = 2;
    file->mUnk_0c |= 1;
    enabled = OS_DisableInterrupts();
    if (archive->mUnk_1c & 0x80) {
        FileFinishCommand(file, 3);
        OS_RestoreInterrupts(enabled);
        return 0;
    }
    if (mask & 0x1fc) {
        file->mUnk_0c |= 4;
    }
    prev = file->mUnk_00;
    tail = (Unk02003024 *) &archive->mUnk_20;
    next = file->mUnk_04;
    if (prev != 0) {
        prev->mUnk_04 = next;
    }
    if (next != 0) {
        next->mUnk_00 = prev;
    }
    while (tail->mUnk_04 != 0) {
        tail = tail->mUnk_04;
    }
    tail->mUnk_04 = file;
    file->mUnk_00 = tail;
    file->mUnk_04 = 0;
    if (((archive->mUnk_1c & 8) ? 1 : 0) == 0 && (archive->mUnk_1c & 0x10) == 0) {
        archive->mUnk_1c |= 0x10;
        OS_RestoreInterrupts(enabled);
        if (archive->mUnk_58 & 0x200) {
            archive->mUnk_54(file, 9);
        }
        enabled = OS_DisableInterrupts();
        file->mUnk_0c |= 0x40;
        if (((file->mUnk_0c & 4) ? 1 : 0) == 0) {
            OS_RestoreInterrupts(enabled);
            FSi_ExecuteAsyncCommand(file);
            return 1;
        }
        OS_RestoreInterrupts(enabled);
    } else {
        if (((file->mUnk_0c & 4) ? 1 : 0) == 0) {
            OS_RestoreInterrupts(enabled);
            return 1;
        }
        do {
            OS_SleepThread(&file->mUnk_18);
        } while ((file->mUnk_0c & 0x40) == 0);
        OS_RestoreInterrupts(enabled);
    }
    return FSi_ExecuteSyncCommand(file);
}

// Clears an archive and its thread queues.
void FS_InitArchive(Unk02003a6c *archive) {
    MI_CpuFill8(archive, 0, 0x5c);
    archive->mUnk_0c.mTail = 0;
    archive->mUnk_0c.mHead = archive->mUnk_0c.mTail;
    archive->mUnk_14.mTail = 0;
    archive->mUnk_14.mHead = archive->mUnk_14.mTail;
}

// Finds a registered archive by name.
Unk02003a6c *FS_FindArchive(const u8 *name, s32 nameLen) {
    u32 packed;
    u32 enabled;
    Unk02003a6c *archive;

    packed = FSi_GetPackedName(name, nameLen);
    enabled = OS_DisableInterrupts();
    archive = data_0216f340;
    while (archive != 0 && archive->mUnk_00 != packed) {
        archive = archive->mUnk_04;
    }
    OS_RestoreInterrupts(enabled);
    return archive;
}

// Adds an archive to the list under the given name.
u32 FS_RegisterArchiveName(Unk02003a6c *archive, const u8 *name, s32 nameLen) {
    u32 result;
    u32 enabled;
    Unk02003a6c *tail;

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
            while (tail->mUnk_04 != 0) {
                tail = tail->mUnk_04;
            }
            tail->mUnk_04 = archive;
            archive->mUnk_08 = tail;
        }
        archive->mUnk_00 = FSi_GetPackedName(name, nameLen);
        result = 1;
        archive->mUnk_1c |= 1;
    }
    OS_RestoreInterrupts(enabled);
    return result;
}

// Removes an archive from the list.
void FS_ReleaseArchiveName(Unk02003a6c *archive) {
    u32 enabled;

    if (archive->mUnk_00 == 0) {
        return;
    }
    enabled = OS_DisableInterrupts();
    if (archive->mUnk_04 != 0) {
        archive->mUnk_04->mUnk_08 = archive->mUnk_08;
    }
    if (archive->mUnk_08 != 0) {
        archive->mUnk_08->mUnk_04 = archive->mUnk_04;
    }
    archive->mUnk_00 = 0;
    archive->mUnk_08 = 0;
    archive->mUnk_04 = archive->mUnk_08;
    archive->mUnk_1c &= ~1;
    if (data_0216f344.h.mUnk_00 == archive) {
        data_0216f344.h.mUnk_08 = 0;
        data_0216f344.h.mUnk_06 = 0;
        data_0216f344.h.mUnk_00 = data_0216f340;
        data_0216f344.h.mUnk_04 = 0;
    }
    OS_RestoreInterrupts(enabled);
}

// Sets the archive memory image, table offsets and read and write callbacks.
u32 FS_LoadArchive(Unk02003a6c *archive, u8 *base, u32 fat, u32 fatSize, u32 fnt, u32 fntSize,
                   s32 (*readFunc)(Unk02003a6c *, void *, u32, u32),
                   s32 (*writeFunc)(Unk02003a6c *, void *, u32, u32)) {
    archive->mUnk_28 = base;
    archive->mUnk_30 = fatSize;
    archive->mUnk_3c = fat;
    archive->mUnk_2c = archive->mUnk_3c;
    archive->mUnk_38 = fntSize;
    archive->mUnk_40 = fnt;
    archive->mUnk_34 = archive->mUnk_40;
    archive->mUnk_48 = (readFunc == 0) ? FSi_ReadMemCallback : readFunc;
    archive->mUnk_4c = (writeFunc == 0) ? FSi_WriteMemCallback : writeFunc;
    archive->mUnk_50 = archive->mUnk_48;
    archive->mUnk_44 = 0;
    archive->mUnk_1c |= 2;
    return 1;
}

// Cancels the queued commands and clears the archive.
u32 FS_UnloadArchive(Unk02003a6c *archive) {
    u32 enabled;
    Unk02003024 *file;
    Unk02003024 *next;
    u32 suspended;

    enabled = OS_DisableInterrupts();
    if (((archive->mUnk_1c & 2) ? 1 : 0) != 0) {
        archive->mUnk_1c;
        suspended = FS_SuspendArchive(archive);
        archive->mUnk_1c |= 0x80;
        file = archive->mUnk_24;
        if (file != 0) {
            do {
                next = file->mUnk_04;
                FileFinishCommand(file, 3);
                file = next;
            } while (next != 0);
        }
        archive->mUnk_24 = 0;
        if (suspended != 0) {
            FS_ResumeArchive(archive);
        }
        archive->mUnk_28 = 0;
        archive->mUnk_2c = 0;
        archive->mUnk_30 = 0;
        archive->mUnk_34 = 0;
        archive->mUnk_38 = 0;
        archive->mUnk_40 = 0;
        archive->mUnk_3c = archive->mUnk_40;
        archive->mUnk_1c &= ~0xa2;
    }
    OS_RestoreInterrupts(enabled);
    return 1;
}

// Copies the two tables into memory; returns the size needed.
u32 FS_LoadArchiveTables(Unk02003a6c *archive, u32 mem, u32 maxSize) {
    Unk02003024 tmp;
    u32 totalSize;

    totalSize = ((s32) (archive->mUnk_30 + archive->mUnk_38 + 32) + 31) & ~31;
    if (totalSize <= maxSize) {
        u8 *cache;

        cache = (u8 *) ((mem + 31) & ~31);
        FS_InitFile(&tmp);
        if (FS_OpenFileDirect(&tmp, archive, archive->mUnk_2c, archive->mUnk_2c + archive->mUnk_30, -1) != 0) {
            if (FS_ReadFile(&tmp, cache, archive->mUnk_30) < 0) {
                MI_CpuFill8(cache, 0, archive->mUnk_30);
            }
            FS_CloseFile(&tmp);
        }
        archive->mUnk_2c = (u32) cache;
        cache += archive->mUnk_30;
        if (FS_OpenFileDirect(&tmp, archive, archive->mUnk_34, archive->mUnk_34 + archive->mUnk_38, -1) != 0) {
            if (FS_ReadFile(&tmp, cache, archive->mUnk_38) < 0) {
                MI_CpuFill8(cache, 0, archive->mUnk_38);
            }
            FS_CloseFile(&tmp);
        }
        archive->mUnk_34 = (u32) cache;
        archive->mUnk_44 = mem;
        archive->mUnk_50 = FSi_ReadMemoryCore;
        archive->mUnk_1c |= 4;
    }
    return totalSize;
}

// Returns the archive to reading its tables from the image; returns the table memory.
u32 FS_UnloadArchiveTables(Unk02003a6c *archive) {
    u32 mem;
    u32 suspended;

    mem = 0;
    if (((archive->mUnk_1c & 2) ? 1 : 0) != 0) {
        suspended = FS_SuspendArchive(archive);
        if (((archive->mUnk_1c & 4) ? 1 : 0) != 0) {
            archive->mUnk_1c &= ~4;
            mem = archive->mUnk_44;
            archive->mUnk_44 = 0;
            archive->mUnk_2c = archive->mUnk_3c;
            archive->mUnk_34 = archive->mUnk_40;
            archive->mUnk_50 = archive->mUnk_48;
        }
        if (suspended != 0) {
            FS_ResumeArchive(archive);
        }
    }
    return mem;
}

// Stops the archive from starting commands; returns whether it was not already suspended.
u32 FS_SuspendArchive(Unk02003a6c *archive) {
    u32 enabled;
    u32 result;

    enabled = OS_DisableInterrupts();
    result = ((archive->mUnk_1c & 8) ? 1 : 0) == 0;
    if (result) {
        if (archive->mUnk_1c & 0x10) {
            archive->mUnk_1c |= 0x40;
            do {
                OS_SleepThread(&archive->mUnk_14);
            } while (archive->mUnk_1c & 0x40);
        } else {
            archive->mUnk_1c |= 8;
        }
    }
    OS_RestoreInterrupts(enabled);
    return result;
}

// Lets a suspended archive start commands again.
u32 FS_ResumeArchive(Unk02003a6c *archive) {
    Unk02003024 *next;
    u32 enabled;
    u32 result;

    next = 0;
    enabled = OS_DisableInterrupts();
    result = ((archive->mUnk_1c & 8) ? 1 : 0) == 0;
    if (!result) {
        archive->mUnk_1c &= ~8;
        next = FSi_NextCommand(archive);
    }
    OS_RestoreInterrupts(enabled);
    if (next != 0) {
        FSi_ExecuteAsyncCommand(next);
    }
    return result;
}

// Sets the archive notification callback and the events it receives.
void FS_SetArchiveProc(Unk02003a6c *archive, s32 (*proc)(Unk02003024 *, u32), u32 flags) {
    if (flags == 0) {
        proc = 0;
    } else if (proc == 0) {
        flags = 0;
    }
    archive->mUnk_54 = proc;
    archive->mUnk_58 = flags;
}

// Ends an asynchronous command with the given result.
void FS_NotifyArchiveAsyncEnd(Unk02003a6c *archive, u32 result) {
    u32 enabled;
    Unk02003024 *file;

    if (archive->mUnk_1c & 0x100) {
        file = archive->mUnk_24;
        archive->mUnk_1c &= ~0x100;
        FileFinishCommand(file, result);
        file = FSi_NextCommand(archive);
        if (file != 0) {
            FSi_ExecuteAsyncCommand(file);
        }
    } else {
        file = archive->mUnk_24;
        enabled = OS_DisableInterrupts();
        file->mUnk_14 = result;
        archive->mUnk_1c &= ~0x200;
        OS_WakeupThread(&archive->mUnk_0c);
        OS_RestoreInterrupts(enabled);
    }
}
