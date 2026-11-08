#include "Main/Unknown/code_020483e4.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02048000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0217a000.h"

#include "os_printf.h"
#include "code_02003be0.h"
#include "code_02004dc0.h"
#include "Main/Unknown/code_0200e000.h"
#include "fs_file.h"
#include "code_0200eddc.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_020487a0.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/unk_02175000.h"

#pragma thumb on

void InitArchiveSlots(void *heap) {
    s32 index;

    data_021759c8 = HeapAlloc(heap, 0xa84);
    data_021759c8->mUnk_8c8.mReadBuffer = HeapAllocAligned(heap, 0x400, 0x20);
    for (index = 0; index < 20; index++) {
        data_021759c8->mUnk_00[index].mLoaded = 0;
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        data_021759c8->mFileTableSize = FS_TryLoadTable(0, 0);
        data_021759c8->mFileTable = HeapAlloc(heap, data_021759c8->mFileTableSize);
        FS_TryLoadTable((u32) data_021759c8->mFileTable, data_021759c8->mFileTableSize);
    }
    for (index = 0; index < 16; index++) {
        ResetArchiveBuffer(index);
    }
    data_021759c8->mUnk_a70 = NULL;
    data_021759c8->mUnk_a78 = NULL;
    data_021759c8->mCourseBufferHeap = NULL;
    FS_InitFile(&data_021759c8->mFile);
}

int ReadWholeFile(const char *path, void *buffer, u32 maxSize) {
    FSFile file;
    u32 opened;
    u32 size;

    FS_InitFile(&file);
    opened = FS_OpenFile(&file, (const u8 *) path);
    if (opened != 0) {
        size = file.mProp.p.mUnk_08 - file.mProp.p.mUnk_04;
        if (maxSize != 0 && size > maxSize) {
            opened = 0;
        } else {
            if (FS_ReadFile(&file, buffer, size) < 0) {
                opened = 0;
            }
            FS_CloseFile(&file);
        }
    }
    return opened;
}

u32 ReadFileBytes(void *path, void *buffer, u32 size) {
    FSFile file;
    u32 opened;

    FS_InitFile(&file);
    opened = FS_OpenFile(&file, path);
    if (opened != 0) {
        if (size <= (file.mProp.p.mUnk_08 - file.mProp.p.mUnk_04)) {
            if (FS_ReadFile(&file, buffer, size) < 0) {
                opened = 0;
            }
            FS_CloseFile(&file);
        }
    }
    return opened;
}

u32 LoadFileIntoHeap(char *path, NNSiFndHeapHead *heap, void **outData) {
    u32 opened;
    FSFile *file;
    u32 size;
    void *data;

    file = &data_021759c8->mFile;
    if (((file->mStat & 1) ? 1 : 0) != 0) {
        return 0;
    }
    if (((file->mStat & 0x10) ? 1 : 0) != 0) {
        FS_CloseFile(file);
    }
    opened = FS_OpenFile(file, (const u8 *) path);
    if (opened != 0) {
        size = file->mProp.p.mUnk_08 - file->mProp.p.mUnk_04;
        data = HeapAlloc(heap, size);
        *outData = data;
        if (data == NULL) {
            opened = 0;
        }
        if (opened != 0) {
            if (FS_ReadFile(file, data, size) < 0) {
                opened = 0;
                HeapFree(heap, data);
            }
        }
        FS_CloseFile(file);
    }
    if (opened == 0) {
        size = -1;
        *outData = NULL;
    }
    return size;
}

void *LoadFileAligned(const char *path, s32 alignment) {
    FSFile file;
    u32 opened;
    void *data;
    u32 size;

    data = NULL;
    if (FS_IsAvailable() == 0) {
        return NULL;
    }
    FS_InitFile(&file);
    opened = FS_OpenFile(&file, (const u8 *) path);
    if (opened != 0) {
        size = file.mProp.p.mUnk_08 - file.mProp.p.mUnk_04;
        data = HeapAllocAligned(GetHeap(GetCurrentHeapCall()), size, alignment);
        DC_StoreRange(data, size);
        if (data == NULL) {
            opened = 0;
        } else {
            if (FS_ReadFile(&file, data, size) < 0) {
                HeapFree(GetHeap(GetCurrentHeapCall()), data);
                opened = 0;
            }
            FS_CloseFile(&file);
        }
    }
    if (opened == 0) {
        data = NULL;
    }
    return data;
}

void BuildCourseArchivePath(char *path, s32 courseId, s32 useTexture) {
    BOOL d;
    const char *textureSuffix;
    const char *dSuffix;

    d = FALSE;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2 && data_usa_02154228[courseId].mUnk_04 == 1) {
        d = TRUE;
    }
    if (useTexture != 0) {
        textureSuffix = data_usa_02165164;
    } else {
        textureSuffix = data_usa_02165168;
    }
    if (d != FALSE) {
        dSuffix = data_usa_0216516c;
    } else {
        dSuffix = data_usa_02165170;
    }
    OS_SNPrintf(path, 0x80, data_usa_02165174, data_usa_02154228[courseId].mUnk_00, dSuffix, textureSuffix);
}

u32 GetLanguageCode(void) {
    s32 languageIndex;

    languageIndex = data_021759d0->mUnk_04;
    if (data_021759d0->mUnk_00 == 2 && languageIndex == 1) {
        languageIndex += 5;
    }
    return ((u32 *) data_02164dc8)[languageIndex];
}

#pragma thumb off

#pragma thumb on

u32 GetMPLanguageCode(void) {
    u32 languageIndex;
    languageIndex = data_0217aa00->mUnk_043c;
    if ((data_021759d0->mUnk_00 == 2) && (((s32 *) data_021759d0)[1] == 1)) {
        languageIndex = languageIndex + 5;
    }
    return ((u32 *) &data_02164dc8)[languageIndex];
}

void BuildSceneArchivePathWithLanguage(char *path, const char *sceneName) {
    u32 languageCode;
    if (*sceneName != 0) {
        languageCode = GetLanguageCode();
        OS_SNPrintf(path, 0x80, data_02165148, sceneName, languageCode, data_0216515c);
    }
}

void BuildSceneArchivePath(char *path, const char *sceneName) {
    if (*sceneName != 0) {
        OS_SNPrintf(path, 0x80, data_0216512c, sceneName, data_02165140);
    }
}

#pragma thumb off
