#include "code_02003024.h"

#include "fs_file.h"
#include "os_thread.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0214d018.h"

// Compares two names for len characters, ignoring case; returns the difference of the first pair that differs.
s32 FSi_StrNICmp(const u8 *str1, const u8 *str2, u32 len) {
    u32 i;
    u32 c;
    u32 d;

    for (i = 0; i < len; i++) {
        c = str1[i] - 0x41;
        d = str2[i] - 0x41;
        if (c <= 0x19) {
            c += 0x20;
        }
        if (d <= 0x19) {
            d += 0x20;
        }
        if (c != d) {
            return c - d;
        }
    }
    return 0;
}

// Reads len bytes of the archive tables through FSArchive.mTable, waiting if it runs in the background; advances
// the position.
void FSi_ReadTable(Unk02003ad8 *param, void *dst, u32 len) {
    FSArchive *archive;
    s32 result;
    u32 enabled;

    archive = param->mUnk_00;
    archive->mFlag |= 0x200;
    result = archive->mTable(archive, dst, param->mUnk_04, len);
    switch (result) {
        case 0:
        case 1:
            archive->mFlag &= ~0x200;
            break;
        case 6:
            enabled = OS_DisableInterrupts();
            if (archive->mFlag & 0x200) {
                do {
                    OS_SleepThread(&archive->mSyncQ);
                } while (archive->mFlag & 0x200);
            }
            OS_RestoreInterrupts(enabled);
            break;
    }
    param->mUnk_04 += len;
}

// Moves a directory file to the directory with the given number.
s32 FSi_SeekDirDirect(FSFile *dir, u32 id) {
    dir->mStat |= 4;
    dir->mArg.h.mUnk_00 = dir->mArc;
    dir->mArg.w.mUnk_08 = 0;
    dir->mArg.h.mUnk_06 = 0;
    dir->mArg.h.mUnk_04 = id;
    return FSi_TranslateCommand(dir, 2);
}

// File read command: advances FSFile position and calls FSArchive.mRead.
s32 FSi_ReadFileCommand(FSFile *file) {
    FSArchive *archive;
    void *dst;
    u32 pos;
    u32 len;

    pos = file->mUnk_2c;
    len = file->mArg.p.mUnk_08;
    archive = file->mArc;
    dst = file->mArg.p.mUnk_00;
    file->mUnk_2c = pos + len;
    return archive->mRead(archive, dst, pos, len);
}

// File write command: advances FSFile position and calls FSArchive.mWrite.
s32 FSi_WriteFileCommand(FSFile *file) {
    FSArchive *archive;
    void *src;
    u32 pos;
    u32 len;

    pos = file->mUnk_2c;
    len = file->mArg.p.mUnk_08;
    archive = file->mArc;
    src = file->mArg.p.mUnk_00;
    file->mUnk_2c = pos + len;
    return archive->mWrite(archive, src, pos, len);
}

// Directory seek command: reads the directory table entry for the directory in FSFile.mArg.
s32 FSi_SeekDirCommand(FSFile *dir) {
    FSArchive *archive;
    Unk02003024U *arg;
    Unk0200399c tableEntry;
    Unk02003ad8 readParam;

    archive = dir->mArc;
    arg = &dir->mArg;
    readParam.mUnk_00 = archive;
    readParam.mUnk_04 = archive->mFnt + arg->h.mUnk_04 * 8;
    FSi_ReadTable(&readParam, &tableEntry, 8);
    dir->mProp = *arg;
    if (arg->h.mUnk_06 == 0 && arg->h.mUnk_08 == 0) {
        dir->mProp.h.mUnk_06 = tableEntry.mUnk_04;
        dir->mProp.h.mUnk_08 = archive->mFnt + tableEntry.mUnk_00;
    }
    dir->mUnk_2c = tableEntry.mUnk_06 & 0xfff;
    return 0;
}

// Directory read command: reads the next entry of the directory into the Unk02003670 in FSFile.mArg.
s32 FSi_ReadDirCommand(FSFile *dir) {
    Unk02003670 *entry;
    u8 header;
    u16 parent;
    Unk02003ad8 readParam;

    entry = dir->mArg.e.mUnk_00;
    readParam.mUnk_00 = dir->mArc;
    readParam.mUnk_04 = dir->mProp.w.mUnk_08;
    FSi_ReadTable(&readParam, &header, 1);
    entry->mUnk_10 = header & 0x7f;
    entry->mUnk_0c = (header >> 7) & 1;
    if (entry->mUnk_10 == 0) {
        return 1;
    }
    if (dir->mArg.w.mUnk_04 != 0) {
        readParam.mUnk_04 += entry->mUnk_10;
    } else {
        FSi_ReadTable(&readParam, entry->mUnk_14, entry->mUnk_10);
        entry->mUnk_14[entry->mUnk_10] = 0;
    }
    if (entry->mUnk_0c != 0) {
        FSi_ReadTable(&readParam, &parent, 2);
        entry->mUnk_00.h.mUnk_00 = dir->mArc;
        entry->mUnk_00.h.mUnk_04 = parent & 0xfff;
        entry->mUnk_00.h.mUnk_06 = 0;
        entry->mUnk_00.w.mUnk_08 = 0;
    } else {
        entry->mUnk_00.h.mUnk_00 = dir->mArc;
        entry->mUnk_00.w.mUnk_04 = dir->mProp.h.mUnk_06;
        dir->mProp.h.mUnk_06++;
    }
    dir->mProp.w.mUnk_08 = readParam.mUnk_04;
    return 0;
}

static inline int func_02003670_inline(u32 c) {
    int r;

    r = 0;
    if (c != 0 && c != 0x2f && c != 0x5c) {
        r = 1;
    }
    return r;
}

// Path search command: walks the path through the directory entries and stores the file or directory found.
s32 FSi_FindPathCommand(FSFile *dir) {
    u32 wantsDir;
    Unk02003670 entry;
    const u8 *path;
    u32 isDirName;
    s32 nameLen;
    u32 ch;
    Unk02003024U *result;

    wantsDir = dir->mFindDirectory;
    path = dir->mPath;
    FSi_TranslateCommand(dir, 2);
    ch = *path;
    if (ch != 0) {
        do {
            for (nameLen = 0; isDirName = path[nameLen], func_02003670_inline(isDirName); nameLen++) {
            }
            if (isDirName != 0 || wantsDir != 0) {
                isDirName = 1;
            }
            if (nameLen == 0) {
                return 1;
            }
            if (ch == 0x2e) {
                if (nameLen == 1) {
                    path += 1;
                    goto next;
                }
                if ((nameLen == 2) & (path[1] == 0x2e)) {
                    if (dir->mProp.h.mUnk_04 != 0) {
                        FSi_SeekDirDirect(dir, dir->mUnk_2c);
                    }
                    path += 2;
                    goto next;
                }
            }
            if (nameLen > 0x7f) {
                return 1;
            }
            dir->mArg.e.mUnk_00 = &entry;
            dir->mArg.w.mUnk_04 = 0;
            do {
                if (FSi_TranslateCommand(dir, 3) != 0) {
                    return 1;
                }
            } while (isDirName != entry.mUnk_0c || nameLen != entry.mUnk_10 ||
                     FSi_StrNICmp(path, entry.mUnk_14, nameLen) != 0);
            if (isDirName != 0) {
                dir->mArg = entry.mUnk_00;
                path += nameLen;
                FSi_TranslateCommand(dir, 2);
            } else {
                if (wantsDir != 0) {
                    return 1;
                }
                result = dir->mResult;
                result->d.mUnk_00 = entry.mUnk_00.d.mUnk_00;
                return 0;
            }
        next:
            path += (*path != 0) ? 1 : 0;
            ch = *path;
        } while (ch != 0);
    }
    if (wantsDir == 0) {
        return 1;
    }
    *dir->mResult = dir->mProp;
    return 0;
}

// Path query command: sizes and writes the full path of a file or directory, starting with the archive name.
s32 FSi_GetPathCommand(FSFile *file) {
    FSArchive *archive;
    Unk02003670 entry;
    FSFile tmp;
    Unk02003024U *arg;
    u32 dirId;
    u32 fileId;
    u32 i;
    u32 dirCount;
    u32 parent;
    u32 totalLen;
    u8 *buf;
    u32 len;
    u32 off;
    u32 n;

    archive = file->mArc;
    arg = &file->mArg;
    FS_InitFile(&tmp);
    tmp.mArc = file->mArc;
    if (((file->mStat & 0x20) ? 1 : 0) != 0) {
        dirId = file->mProp.h.mUnk_04;
        fileId = 0x10000;
    } else {
        fileId = file->mProp.w.mUnk_00;
        if (arg->b.mUnk_08 != 0) {
            dirId = arg->b.mUnk_0a;
        } else {
            i = 0;
            dirCount = 0;
            dirId = 0x10000;
            do {
                FSi_SeekDirDirect(&tmp, i);
                if (i == 0) {
                    dirCount = tmp.mUnk_2c;
                }
                tmp.mArg.e.mUnk_00 = &entry;
                tmp.mArg.w.mUnk_04 = 1;
                if (FSi_TranslateCommand(&tmp, 3) == 0) {
                    do {
                        if (entry.mUnk_0c == 0 && entry.mUnk_00.w.mUnk_04 == fileId) {
                            dirId = tmp.mProp.h.mUnk_04;
                            break;
                        }
                    } while (FSi_TranslateCommand(&tmp, 3) == 0);
                }
                if (dirId != 0x10000) {
                    break;
                }
                i++;
            } while (i < dirCount);
        }
    }
    if (dirId == 0x10000) {
        arg->b.mUnk_08 = 0;
        return 1;
    }
    if (arg->b.mUnk_08 == 0) {
        totalLen = 0;
        if (archive->mName <= 0xff) {
            totalLen += 1;
        } else if (archive->mName <= 0xff00) {
            totalLen += 2;
        } else {
            totalLen += 3;
        }
        totalLen += 2;
        if (fileId != 0x10000) {
            totalLen += entry.mUnk_10;
        }
        parent = dirId;
        if (parent != 0) {
            FSi_SeekDirDirect(&tmp, parent);
            do {
                FSi_SeekDirDirect(&tmp, tmp.mUnk_2c);
                tmp.mArg.e.mUnk_00 = &entry;
                tmp.mArg.w.mUnk_04 = 1;
                if (FSi_TranslateCommand(&tmp, 3) == 0) {
                    do {
                        if (entry.mUnk_0c != 0 && entry.mUnk_00.h.mUnk_04 == parent) {
                            totalLen += entry.mUnk_10 + 1;
                            break;
                        }
                    } while (FSi_TranslateCommand(&tmp, 3) == 0);
                }
                parent = tmp.mProp.h.mUnk_04;
            } while (parent != 0);
        }
        arg->b.mUnk_08 = totalLen + 1;
        arg->b.mUnk_0a = dirId;
    }
    buf = arg->b.mUnk_00;
    if (buf == 0) {
        return 0;
    }
    len = arg->b.mUnk_08;
    if (arg->b.mUnk_04 < len) {
        return 1;
    }
    off = 0;
    if (archive->mName <= 0xff) {
        n = 1;
    } else if (archive->mName <= 0xff00) {
        n = 2;
    } else {
        n = 3;
    }
    MI_CpuCopy8(archive, buf, n);
    off += n;
    MI_CpuCopy8(":/", buf + off, 2);
    FSi_SeekDirDirect(&tmp, dirId);
    if (fileId != 0x10000) {
        tmp.mArg.e.mUnk_00 = &entry;
        tmp.mArg.w.mUnk_04 = 0;
        if (FSi_TranslateCommand(&tmp, 3) == 0) {
            do {
                if (entry.mUnk_0c == 0 && entry.mUnk_00.w.mUnk_04 == fileId) {
                    break;
                }
            } while (FSi_TranslateCommand(&tmp, 3) == 0);
        }
        n = entry.mUnk_10 + 1;
        MI_CpuCopy8(entry.mUnk_14, buf + len - n, n);
        len -= n;
    } else {
        *(buf + len - 1) = 0;
        len--;
    }
    if (dirId != 0) {
        do {
            FSi_SeekDirDirect(&tmp, tmp.mUnk_2c);
            tmp.mArg.e.mUnk_00 = &entry;
            tmp.mArg.w.mUnk_04 = 0;
            *(buf + len - 1) = 0x2f;
            len--;
            if (FSi_TranslateCommand(&tmp, 3) == 0) {
                do {
                    if (entry.mUnk_0c != 0 && entry.mUnk_00.h.mUnk_04 == dirId) {
                        n = entry.mUnk_10;
                        MI_CpuCopy8(entry.mUnk_14, buf + len - n, n);
                        len -= n;
                        break;
                    }
                } while (FSi_TranslateCommand(&tmp, 3) == 0);
            }
            dirId = tmp.mProp.h.mUnk_04;
        } while (dirId != 0);
    }
    return 0;
}

// Open command by file number: reads the file range from the file table and opens it.
s32 FSi_OpenFileFastCommand(FSFile *file) {
    FSArchive *archive;
    u32 index;
    u32 offset;
    Unk02003234 range;
    Unk02003ad8 readParam;

    archive = file->mArc;
    index = file->mArg.w.mUnk_04;
    offset = index << 3;
    if (offset >= archive->mFatSize) {
        return 1;
    }
    readParam.mUnk_00 = archive;
    readParam.mUnk_04 = archive->mFat + offset;
    FSi_ReadTable(&readParam, &range, 8);
    file->mArg.w.mUnk_00 = range.mUnk_00;
    file->mArg.w.mUnk_04 = range.mUnk_04;
    file->mArg.w.mUnk_08 = index;
    return FSi_TranslateCommand(file, 7);
}

// Open command by byte range: sets the file range and position.
s32 FSi_OpenFileDirectCommand(FSFile *file) {
    file->mProp.w.mUnk_04 = file->mArg.w.mUnk_00;
    file->mUnk_2c = file->mArg.w.mUnk_00;
    file->mProp.w.mUnk_08 = file->mArg.w.mUnk_04;
    file->mProp.w.mUnk_00 = file->mArg.w.mUnk_08;
    return 0;
}

// Close command: nothing to do.
s32 FSi_CloseFileCommand(FSFile *file) {
    return 0;
}

// Unlinks a finished command from its archive list, stores the result and wakes the waiting threads.
void FSi_ReleaseCommand(FSFile *file, s32 result) {
    u32 enabled;
    FSFile *prev;
    FSFile *next;

    enabled = OS_DisableInterrupts();
    prev = file->mLink.mPrev;
    next = file->mLink.mNext;
    if (prev != 0) {
        prev->mLink.mNext = next;
    }
    if (next != 0) {
        next->mLink.mPrev = prev;
    }
    file->mLink.mPrev = 0;
    file->mLink.mNext = file->mLink.mPrev;
    file->mStat &= ~0x4f;
    file->mError = result;
    OS_WakeupThread(&file->mQueue);
    OS_RestoreInterrupts(enabled);
}

// Runs a command through FSArchive.mProc when it handles it, else through the default command table.
s32 FSi_TranslateCommand(FSFile *file, u32 command) {
    s32 result;
    FSArchive *archive;
    u32 mask;
    u32 enabled;

    archive = file->mArc;
    mask = 1 << command;
    if (((file->mStat & 4) ? 1 : 0) != 0) {
        archive->mFlag |= 0x200;
    } else {
        archive->mFlag |= 0x100;
    }
    if (archive->mProcFlag & mask) {
        result = archive->mProc(file, command);
        switch (result) {
            case 0:
            case 1:
            case 4:
                file->mError = result;
                break;
            case 8:
                archive->mProcFlag = archive->mProcFlag & ~mask;
                result = 7;
                break;
        }
    } else {
        result = 7;
    }
    if (result == 7) {
        result = data_02152b5c[command](file);
    }
    if (result == 6) {
        if (((file->mStat & 4) ? 1 : 0) != 0) {
            enabled = OS_DisableInterrupts();
            if (archive->mFlag & 0x200) {
                do {
                    OS_SleepThread(&archive->mSyncQ);
                } while (archive->mFlag & 0x200);
            }
            result = file->mError;
            OS_RestoreInterrupts(enabled);
        }
    } else if (((file->mStat & 4) ? 1 : 0) != 0) {
        archive->mFlag &= ~0x200;
        file->mError = result;
    } else {
        archive->mFlag &= ~0x100;
        FSi_ReleaseCommand(file, result);
    }
    return result;
}
