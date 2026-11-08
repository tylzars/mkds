#include "Main/Unknown/code_02047104.h"

#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_020487a0.h"
#include "Main/Unknown/code_020cade8.h"
#include "Main/Unknown/code_020d1640.h"
#include "Main/Unknown/code_0210f130.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_020176c0.h"
#include "code_020182c0.h"
#include "tp.h"
#include "Main/Unknown/code_02018000.h"
#include "Main/Unknown/code_020483e4.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02048000.h"
#include "Main/Unknown/code_0205e000.h"
#include "code_020176b0.h"
#include "frameheap.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_0204f5e4.h"
#include "Main/Unknown/code_0204f240.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/unk_02165000.h"
#include "os_printf.h"
#include "code_02003be0.h"
#include "code_0200eddc.h"
#include "code_02139f70.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0200e000.h"
#include "fs_file.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "code_0214d464.h"
#include "code_0214d564.h"
#include "00/code_02181f98.h"

#pragma thumb on

void BuildResultArchivePath(char *path) {
    const char *suffix;

    if (data_0217b488->mUnk_78 == 1) {
        suffix = data_usa_02165108;
    } else {
        suffix = data_usa_0216510c;
    }
    OS_SNPrintf(path, 0x80, gResultArchivePathFormat, gSceneNames[10].mName, suffix, data_usa_02165124);
}

void BuildResultArchivePathWithLanguage(char *path) {
    const char *suffix;
    u32 languageCode;

    if (data_0217b488->mUnk_78 == 1) {
        suffix = data_usa_021650e0;
    } else {
        suffix = data_usa_021650e4;
    }
    languageCode = GetLanguageCode();
    OS_SNPrintf(path, 0x80, gResultLanguageArchivePathFormat, gSceneNames[10].mName, suffix, languageCode,
                data_usa_02165100);
}

#pragma thumb off

#pragma thumb on

void BuildStaffRollArchivePath(char *path) {
    u32 languageCode;
    languageCode = GetLanguageCode();
    OS_SNPrintf(path, 0x80, gStaffRollLanguageArchivePathFormat, languageCode, data_021650d8);
}

void BuildSceneModeArchivePath(char *path, const char *sceneName, int mode) {
    if (*sceneName != 0) {
        OS_SNPrintf(path, 0x80, gSceneModeArchivePathFormat, sceneName, gModeArchiveNames[mode], data_021650b4);
    }
}

void BuildSceneModeLanguageArchivePath(char *path, const char *sceneName, int mode) {
    u32 languageCode;
    if (*sceneName != 0) {
        languageCode = GetLanguageCode();
        OS_SNPrintf(path, 0x80, gSceneModeLanguageArchivePathFormat, sceneName, gModeArchiveNames[mode], languageCode,
                    data_02165098);
    }
}

void BuildArchivePathWithLanguage(const char *prefix, char *path) {
    u32 languageCode;
    languageCode = GetLanguageCode();
    OS_SNPrintf(path, 0x80, gLanguageArchivePathFormat, prefix, languageCode);
}

#pragma thumb off

#pragma thumb on

void LoadArchiveSlotForScene(int slotIndex, int sceneNumber) {
    char path[0x80] = {0};
    u32 *bufferData;
    s32 f;
    s32 uncompressSource;
    s32 g;
    s32 h;

    bufferData = NULL;
    if (data_021759c8->mUnk_00[slotIndex].mLoaded != 0) {
        return;
    }
    uncompressSource = gArchiveSlotInfos[slotIndex].mUncompressSource;
    f = gArchiveSlotInfos[slotIndex].mUnk_10;
    g = gArchiveSlotInfos[slotIndex].mUnk_14;
    h = gArchiveSlotInfos[slotIndex].mBufferIndex;
    if (h != -1) {
        bufferData = data_021759c8->mBuffers[h].mData;
    }
    switch (slotIndex) {
        case 3:
        case 13:
            BuildCourseArchivePath(path, gRaceSetup->mCourseId, slotIndex != 3);
            break;
        case 5:
            switch (sceneNumber) {
                case 2:
                    bufferData = data_021759c8->mBuffers[2].mData;
                    break;
                case 1:
                    bufferData = data_021759c8->mBuffers[0].mData;
                    break;
                case 10:
                    bufferData = data_021759c8->mBuffers[14].mData;
                    break;
            }
            switch (sceneNumber) {
                case 10:
                    BuildResultArchivePath(path);
                    break;
                case 2:
                    if (gRaceSetup->mRaceKind == RACE_KIND_STAFF_ROLL) {
                        OS_SNPrintf(path, 0x80, gStaffRollArchivePath);
                    } else {
                        BuildSceneArchivePath(path, gSceneNames[sceneNumber].mName);
                    }
                    break;
                default:
                    BuildSceneArchivePath(path, gSceneNames[sceneNumber].mName);
                    break;
            }
            g = gSceneNames[sceneNumber].mUnk_04;
            break;
        case 9:
            switch (sceneNumber) {
                case 2:
                    bufferData = data_021759c8->mBuffers[3].mData;
                    break;
                case 1:
                    bufferData = data_021759c8->mBuffers[1].mData;
                    break;
                case 10:
                    bufferData = data_021759c8->mBuffers[15].mData;
                    break;
            }
            switch (sceneNumber) {
                case 10:
                    BuildResultArchivePathWithLanguage(path);
                    break;
                case 2:
                    if (gRaceSetup->mRaceKind == RACE_KIND_STAFF_ROLL) {
                        BuildStaffRollArchivePath(path);
                    } else {
                        BuildSceneArchivePathWithLanguage(path, gSceneNames[sceneNumber].mName);
                    }
                    break;
                default:
                    BuildSceneArchivePathWithLanguage(path, gSceneNames[sceneNumber].mName);
                    break;
            }
            break;
        case 11:
            BuildSceneModeArchivePath(path, gSceneNames[sceneNumber].mName, gRaceSetup->mMode);
            break;
        case 12:
            BuildSceneModeLanguageArchivePath(path, gSceneNames[sceneNumber].mName, gRaceSetup->mMode);
            break;
        case 2:
        case 15:
        case 17:
            BuildArchivePathWithLanguage(gArchiveSlotInfos[slotIndex].mPath, path);
            break;
        case 0:
        case 1:
        case 6:
        case 7:
        case 8:
        case 10:
        case 14:
        case 16:
        case 18:
            strncpy(path, gArchiveSlotInfos[(s32) slotIndex].mPath, 0x80);
            break;
    }
    if (path[0] != 0) {
        LoadArchiveSlot(slotIndex, path, bufferData, NULL, f, uncompressSource, g);
    }
    h = *(s32 *) ((s32) &gArchiveSlotInfos[0].mNextSlot + slotIndex * 0x18);
    if (h != -1) {
        LoadArchiveSlotForScene(h, sceneNumber);
    }
}

void LoadArchiveSlot(s32 slotIndex, const char *path, u32 *sourceData, void *data, s32 e, s32 uncompressSource, s32 g) {
    ArchiveLoadRequest *request;
    s32 bufferIndex;

    request = &data_021759c8->mUnk_8c8;
    strncpy((char *) request->mPath, path, 0x80);
    request->mSlotIndex = slotIndex;
    request->mSourceData = sourceData;
    request->mData = data;
    request->mUnk_90 = e;
    request->mUncompressSource = uncompressSource;
    request->mUnk_9c = g;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        if (request->mSourceData != NULL) {
            if (request->mUncompressSource != 0) {
                bufferIndex = gArchiveSlotInfos[slotIndex].mBufferIndex;
                if (bufferIndex != -1) {
                    data_021759c8->mBuffers[bufferIndex].mUnk_08_31 = 1;
                }
                UncompressArchiveMemory();
            } else {
                request->mData = request->mSourceData;
            }
            LoadArchiveSlotData();
        }
    } else {
        if (slotIndex == 0x13) {
            UncompressArchiveMemory();
        } else {
            UncompressArchiveFile();
        }
        LoadArchiveSlotData();
    }
}

void UncompressArchiveFile(void) {
    ArchiveLoadRequest *request;
    FSFile file;
    MIUncompContextLZ uncompContext;
    u32 uncompressedSize;
    s32 bytesRead;

    request = &data_021759c8->mUnk_8c8;
    FS_InitFile(&file);
    if (FS_OpenFile(&file, request->mPath) == 0) {
        return;
    }
    if (FS_ReadFile(&file, request->mReadBuffer, 4) < 0) {
        return;
    }
    uncompressedSize = *request->mReadBuffer >> 8;
    if (uncompressedSize > 0x200000) {
        return;
    }
    if (request->mUnk_90 != 0) {
        request->mData = HeapAllocAligned(GetHeap(GetCurrentHeapCall()), uncompressedSize, -0x20);
    } else {
        request->mData = HeapAllocAligned(GetHeap(GetCurrentHeapCall()), uncompressedSize, 0x20);
    }
    MI_InitUncompContextLZ(&uncompContext, request->mData, (const MICompressionHeader *) request->mReadBuffer);
    do {
        bytesRead = FS_ReadFile(&file, request->mReadBuffer, 0x400);
        if (bytesRead <= 0) {
            return;
        }
    } while (MI_ReadUncompLZ8(&uncompContext, (const u8 *) request->mReadBuffer, bytesRead) != 0);
    DC_StoreRange(request->mData, uncompressedSize);
    NNS_FndGetTotalFreeSizeForExpHeap(GetHeap(GetCurrentHeapCall()));
}

void UncompressArchiveMemory(void) {
    ArchiveLoadRequest *request;
    u32 uncompressedSize;

    request = &data_021759c8->mUnk_8c8;
    uncompressedSize = *request->mSourceData >> 8;
    if (request->mUnk_90 != 0) {
        request->mData = HeapAllocAligned(GetHeap(GetCurrentHeapCall()), uncompressedSize, -0x20);
    } else {
        request->mData = HeapAllocAligned(GetHeap(GetCurrentHeapCall()), uncompressedSize, 0x20);
    }
    MI_UncompressLZ8(request->mSourceData, request->mData);
    DC_StoreRange(request->mData, uncompressedSize);
    NNS_FndGetTotalFreeSizeForExpHeap(GetHeap(GetCurrentHeapCall()));
}

void LoadArchiveSlotData(void) {
    ArchiveLoadRequest *request;
    ArchiveSlot *slot;

    request = &data_021759c8->mUnk_8c8;
    slot = &data_021759c8->mUnk_00[request->mSlotIndex];
    if (request->mData != NULL) {
        if (ArchiveLoadFromMemory(&slot->mArchive, (const u8 *) gArchiveNames[request->mSlotIndex], request->mData) !=
            0) {
            slot->mLoaded = 1;
            slot->mData = request->mData;
        }
    }
}

void ReleaseArchiveSlot(int slotIndex) {
    BOOL shouldFree;
    s32 bufferIndex;

    shouldFree = TRUE;
    if (data_021759c8->mUnk_00[slotIndex].mLoaded != 0 && slotIndex != 0x13) {
        ArchiveUnload(&data_021759c8->mUnk_00[slotIndex].mArchive.mUnk_00);
        if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
            bufferIndex = gArchiveSlotInfos[slotIndex].mBufferIndex;
            if (bufferIndex != -1 && data_021759c8->mBuffers[bufferIndex].mUncompress != 0) {
                shouldFree = FALSE;
            } else {
                data_021759c8->mBuffers[bufferIndex].mUnk_08_31 = 1;
            }
        }
        if (shouldFree != FALSE) {
            HeapFree(GetHeap(GetCurrentHeapCall()), data_021759c8->mUnk_00[slotIndex].mData);
        }
        data_021759c8->mUnk_00[slotIndex].mLoaded = 0;
        data_021759c8->mUnk_00[slotIndex].mData = 0;
        NNS_FndGetTotalFreeSizeForExpHeap(GetHeap(GetCurrentHeapCall()));
    }
}

void LoadArchiveSlotsForScene(s32 sceneNumber) {
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2 && sceneNumber == 6 && data_0217b488->mUnk_74 == 0) {
    } else {
        LoadArchiveSlotForScene(1, sceneNumber);
    }
    switch (sceneNumber) {
        case 1:
        case 12:
            LoadArchiveSlotForScene(5, sceneNumber);
            LoadArchiveSlotForScene(14, sceneNumber);
            LoadArchiveSlotForScene(16, sceneNumber);
            break;
        case 10:
            LoadArchiveSlotForScene(0, sceneNumber);
            LoadArchiveSlotForScene(5, sceneNumber);
            LoadArchiveSlotForScene(16, sceneNumber);
            LoadArchiveSlotForScene(18, sceneNumber);
            break;
        case 2:
            LoadArchiveSlotForScene(18, sceneNumber);
            LoadArchiveSlotForScene(6, sceneNumber);
            LoadArchiveSlotForScene(8, sceneNumber);
            break;
        case 3:
            LoadArchiveSlotForScene(0, sceneNumber);
            LoadArchiveSlotForScene(5, sceneNumber);
            LoadArchiveSlotForScene(16, sceneNumber);
            break;
        case 5:
            LoadArchiveSlotForScene(5, sceneNumber);
            LoadArchiveSlotForScene(14, sceneNumber);
            LoadArchiveSlotForScene(16, sceneNumber);
            break;
        case 0:
        case 7:
        case 8:
        case 9:
        case 11:
        case 13:
        case 14:
        case 15:
            LoadArchiveSlotForScene(5, sceneNumber);
            LoadArchiveSlotForScene(16, sceneNumber);
            break;
        case 4:
            if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
                LoadArchiveSlotForScene(5, sceneNumber);
                LoadArchiveSlotForScene(16, sceneNumber);
            }
            break;
        case 6:
            if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
                LoadArchiveSlotForScene(5, sceneNumber);
                LoadArchiveSlotForScene(16, sceneNumber);
            }
            break;
    }
}

void ReleaseArchiveSlots(void) {
    s32 i;

    for (i = 0; i < 20; i++) {
        ReleaseArchiveSlot(i);
    }
}

#pragma thumb off

#pragma thumb on
void SetHeapGroupId(u32 groupId) {
    NNS_FndSetGroupIDForExpHeap(GetHeap(GetCurrentHeapCall()), groupId);
}
#pragma thumb off

#pragma thumb on

void *FindArchiveFile(u32 archiveName, const char *path) {
    char fullPath[0x80];

    if (path[0] == '/') {
        OS_SNPrintf(fullPath, 0x80, gArchiveColonFormat, archiveName, path);
    } else {
        OS_SNPrintf(fullPath, 0x80, gArchiveColonSlashFormat, archiveName, path);
    }
    return ArchiveFileGetAddress((const u8 *) fullPath);
}

#pragma thumb off

#pragma thumb on

void *FindMainRaceOrMainEffectFile(const char *path) {
    void *file;
    file = FindArchiveFile(gArchiveNames[0], path);
    if (file == NULL) {
        file = FindArchiveFile(gArchiveNames[18], path);
    }
    return file;
}

#pragma thumb off

#pragma thumb on

// Searches the archives that are loaded, in a fixed order, and returns the first match.
void *FindFileInLoadedArchives(const char *path) {
    void *file;

    file = NULL;
    if (data_021759c8->mUnk_7d8 != 0) {
        file = FindArchiveFile(gArchiveNames[17], path);
    }
    if (file == NULL && data_021759c8->mUnk_768 != 0) {
        file = FindArchiveFile(gArchiveNames[16], path);
    }
    if (file == NULL && data_021759c8->mUnk_6f8 != 0) {
        file = FindArchiveFile(gArchiveNames[15], path);
    }
    if (file == NULL && data_021759c8->mUnk_688 != 0) {
        file = FindArchiveFile(gArchiveNames[14], path);
    }
    if (file == NULL && data_021759c8->mUnk_8b8 != 0) {
        file = FindArchiveFile(gArchiveNames[19], path);
    }
    if (file == NULL && data_021759c8->mUnk_148 != 0) {
        file = FindArchiveFile(gArchiveNames[2], path);
    }
    if (file == NULL && data_021759c8->mUnk_d8 != 0) {
        file = FindArchiveFile(gArchiveNames[1], path);
    }
    return file;
}

void *FindSceneFile(const char *path) {
    void *file;

    file = FindArchiveFile(gArchiveNames[5], path);
    if (file == NULL && data_021759c8->mUnk_458 != 0) {
        file = FindArchiveFile(gArchiveNames[9], path);
    }
    if (GetCurrentSceneNumber() == 2) {
        if (file == NULL && data_021759c8->mUnk_538 != 0) {
            file = FindArchiveFile(gArchiveNames[11], path);
        }
        if (file == NULL && data_021759c8->mUnk_5a8 != 0) {
            file = FindArchiveFile(gArchiveNames[12], path);
        }
    }
    return file;
}

#pragma thumb off

#pragma thumb on

void *FindCourseFile(const char *path) {
    void *file;
    file = FindArchiveFile(gArchiveNames[3], path);
    if (file == NULL) {
        file = FindArchiveFile(gArchiveNames[13], path);
    }
    return file;
}

void *func_02047950(const char *path) {
    int currentSceneNumber;
    currentSceneNumber = GetCurrentSceneNumber();
    if (currentSceneNumber == 3) {
        return FindKartModelFile(path);
    }
    return LoadKartModelFile(path);
}

void *FindKartModelFile(const char *path) {
    int currentSceneNumber;
    void *file;
    file = NULL;
    currentSceneNumber = GetCurrentSceneNumber();
    if (((currentSceneNumber == 1) || (currentSceneNumber == 3)) || (currentSceneNumber == 0xc)) {
        file = FindArchiveFile(gArchiveNames[10], path);
    } else {
        if (data_021759c8->mUnk_308 != 0) {
            file = FindArchiveFile(gArchiveNames[6], path);
        }
        if ((file == NULL) && (data_021759c8->mUnk_378 != 0)) {
            file = FindArchiveFile(gArchiveNames[7], path);
        }
        if ((file == NULL) && (data_021759c8->mUnk_3e8 != 0)) {
            file = FindArchiveFile(gArchiveNames[8], path);
        }
    }
    return file;
}

#pragma thumb off

#pragma thumb on

void *LoadKartModelFile(const char *path) {
    void *file;
    s32 currentSceneNumber;
    char fullPath[0x80];
    u32 archiveName;

    file = NULL;
    currentSceneNumber = GetCurrentSceneNumber();
    if (currentSceneNumber == 1 || currentSceneNumber == 3 || currentSceneNumber == 0xc) {
        archiveName = gArchiveNames[10];
        if (path[0] == '/') {
            OS_SNPrintf(fullPath, 0x80, data_usa_02165008, archiveName, path);
        } else {
            OS_SNPrintf(fullPath, 0x80, data_usa_02165010, archiveName, path);
        }
        file = LoadFileAligned(fullPath, 8);
    } else {
        if (data_021759c8->mUnk_00[6].mLoaded != 0) {
            archiveName = gArchiveNames[6];
            if (path[0] == '/') {
                OS_SNPrintf(fullPath, 0x80, data_usa_02165018, archiveName, path);
            } else {
                OS_SNPrintf(fullPath, 0x80, data_usa_02165020, archiveName, path);
            }
            file = LoadFileAligned(fullPath, 8);
        }
        if (file == NULL && data_021759c8->mUnk_00[7].mLoaded != 0) {
            archiveName = gArchiveNames[7];
            if (path[0] == '/') {
                OS_SNPrintf(fullPath, 0x80, data_usa_02165028, archiveName, path);
            } else {
                OS_SNPrintf(fullPath, 0x80, data_usa_02165030, archiveName, path);
            }
            file = LoadFileAligned(fullPath, 8);
        }
        if (file == NULL && data_021759c8->mUnk_00[8].mLoaded != 0) {
            archiveName = gArchiveNames[8];
            if (path[0] == '/') {
                OS_SNPrintf(fullPath, 0x80, data_usa_02165038, archiveName, path);
            } else {
                OS_SNPrintf(fullPath, 0x80, data_usa_02165040, archiveName, path);
            }
            file = LoadFileAligned(fullPath, 8);
        }
    }
    return file;
}

#pragma thumb off

#pragma thumb on

void func_0204775c(void) {
    ReleaseArchiveSlot(6);
    SetHeapGroupId((u16) 0);
    LoadArchiveSlotForScene(7, 2);
    SetHeapGroupId((u16) 9);
}

void func_02047728(void) {
    int currentSceneNumber;
    ReleaseArchiveSlot(7);
    ReleaseArchiveSlot(8);
    SetHeapGroupId((u16) 0);
    currentSceneNumber = GetCurrentSceneNumber();
    if (currentSceneNumber == 2) {
        LoadArchiveSlotForScene(3, 2);
    }
    SetHeapGroupId((u16) 9);
}

void func_020476ec(void) {
    int currentSceneNumber;
    ReleaseArchiveSlot(0xd);
    SetHeapGroupId((u16) 0);
    currentSceneNumber = GetCurrentSceneNumber();
    if (currentSceneNumber == 2) {
        LoadArchiveSlotForScene(5, 2);
        LoadArchiveSlotForScene(0xb, 2);
        LoadArchiveSlotForScene(0, 2);
    }
    SetHeapGroupId((u16) 9);
}

void func_020476ac(void) {
    u32 currentSceneNumber;
    currentSceneNumber = GetCurrentSceneNumber();
    ReleaseArchiveSlot(10);
    SetHeapGroupId((u16) 0);
    LoadArchiveSlotForScene(1, currentSceneNumber);
    LoadArchiveSlotForScene(5, currentSceneNumber);
    LoadArchiveSlotForScene(0xe, currentSceneNumber);
    LoadArchiveSlotForScene(0x10, currentSceneNumber);
    SetHeapGroupId((u16) 9);
}

#pragma thumb off

#pragma thumb on

void InitArchiveBuffer(NNSiFndHeapHead *heap, s32 bufferIndex, s32 c, u32 uncompress, u32 e) {
    ArchiveBuffer *buffer = &data_021759c8->mBuffers[bufferIndex];
    buffer->mHeap = heap;
    buffer->mData = NULL;
    buffer->mUnk_08_0 = c << 10;
    buffer->mUncompress = uncompress;
    buffer->mUnk_08_30 = e;
    buffer->mUnk_08_31 = 1;
}

#pragma thumb off

#pragma thumb on

// Sets up 12 archive buffers on three heaps.
void InitArchiveBuffers(NNSiFndHeapHead *a, NNSiFndHeapHead *courseBufferHeap, NNSiFndHeapHead *c) {
    InitArchiveBuffer(c, 2, 0x3c, 0, 1);
    InitArchiveBuffer(c, 3, 0x32, 0, 1);
    InitArchiveBuffer(c, 4, 5, 0, 1);
    InitArchiveBuffer(c, 5, 5, 0, 1);
    InitArchiveBuffer(c, 0, 0x14, 0, 1);
    InitArchiveBuffer(c, 1, 0x14, 0, 1);
    InitArchiveBuffer(c, 0xe, 0x46, 0, 1);
    InitArchiveBuffer(c, 0xf, 0x46, 0, 1);
    InitArchiveBuffer(courseBufferHeap, 6, 200, 1, 1);
    InitArchiveBuffer(courseBufferHeap, 7, 200, 0, 1);
    InitArchiveBuffer(a, 8, 0x46, 1, 0);
    InitArchiveBuffer(a, 0xd, 0x1e, 0, 0);
    data_021759c8->mUnk_a78 = a;
    data_021759c8->mCourseBufferHeap = courseBufferHeap;
    data_021759c8->mUnk_a80 = c;
}

void func_020474e4(void) {
    InitArchiveBuffer(data_0217aa10->mUnk_a0, 0xb, 0xaa, 0, 0);
    InitArchiveBuffer(data_0217aa10->mUnk_a0, 0xc, 0x6e, 0, 0);
    InitArchiveBuffer(data_0217aa10->mUnk_a0, 9, 0x1e, 0, 0);
    InitArchiveBuffer(data_0217aa10->mUnk_a0, 10, 0x1e, 0, 0);
}

#pragma thumb off

#pragma thumb on

void RequestArchiveLoad(const void *path, s32 bufferIndex) {
    ArchiveBuffer *buffer = &data_021759c8->mBuffers[bufferIndex];
    AddPendingFile(path, buffer->mHeap, &buffer->mData, buffer->mUnk_08_0, buffer->mUncompress);
    buffer->mUnk_08_31 = 1;
}

#pragma thumb off

#pragma thumb on

void RequestArchiveLoadWithLanguage(const void *prefix, u32 bufferIndex) {
    u32 languageCode;
    char path[128];
    languageCode = GetMPLanguageCode();
    OS_SNPrintf(path, 0x80, gArchivePrefixFormat, prefix, languageCode);
    RequestArchiveLoad(path, bufferIndex);
}

void func_020473e4(void) {
    ResetPendingFiles();
    NNS_FndFreeToFrmHeap(data_021759c8->mUnk_a80, 3);
    RequestArchiveLoad(gKartModelMainAArchivePath, 0xb);
    RequestArchiveLoad(gKartModelMainBArchivePath, 0xc);
    RequestArchiveLoad(gMenuDLArchivePath2, 0);
    RequestArchiveLoadWithLanguage(gMenuDLArchivePrefix2, 1);
    RequestArchiveLoad(gMainRaceArchivePath, 8);
    RequestArchiveLoad(gMain2DArchivePath, 9);
    RequestArchiveLoadWithLanguage(gMain2DArchivePrefix, 10);
    RequestArchiveLoad(gMainEffectArchivePath, 0xd);
}

void RequestMenuDLArchives(void) {
    ResetPendingFiles();
    NNS_FndFreeToFrmHeap(data_021759c8->mUnk_a80, 3);
    RequestArchiveLoad(gMenuDLArchivePath, 0);
    RequestArchiveLoadWithLanguage(gMenuDLArchivePrefix, 1);
}

#pragma thumb off

#pragma thumb on

void RequestRaceArchives(void *courseId, void *b) {
    char path[128];
    ResetPendingFiles();
    NNS_FndFreeToFrmHeap(data_021759c8->mUnk_a80, 3);
    RequestArchiveLoad(gRaceArchivePath, 2);
    RequestArchiveLoadWithLanguage(gRaceArchivePrefix, 3);
    if (b == (void *) 3) {
        RequestArchiveLoad(gRaceVsArchivePath, 4);
        RequestArchiveLoadWithLanguage(gRaceVsArchivePrefix, 5);
    } else {
        RequestArchiveLoad(gRaceMgArchivePath, 4);
        RequestArchiveLoadWithLanguage(gRaceMgArchivePrefix, 5);
    }
    data_021759c8->mUnk_a74 = b;
    NNS_FndFreeToFrmHeap(data_021759c8->mCourseBufferHeap, 3);
    BuildCourseArchivePath(path, (s32) courseId, 0);
    RequestArchiveLoad(path, 6);
    BuildCourseArchivePath(path, (s32) courseId, 1);
    RequestArchiveLoad(path, 7);
    data_021759c8->mUnk_a70 = courseId;
}

#pragma thumb off

#pragma thumb on

void RequestResultDLArchives(void) {
    ResetPendingFiles();
    NNS_FndFreeToFrmHeap(data_021759c8->mUnk_a80, 3);
    RequestArchiveLoad(gResultDLArchivePath, 0xe);
    RequestArchiveLoadWithLanguage(gResultDLArchivePrefix, 0xf);
}

#pragma thumb off

#pragma thumb on

void func_02047274(void) {
    s32 i;

    for (i = 0; i < 16; i++) {
        *OFFSET_PTR(u32, &data_021759c8->mBuffers[0].mUnk_08, i * 12) &= 0x7fffffff;
    }
}

s32 func_02047250(void) {
    if (*(vu16 *) 0x027ffc40 == 2) {
        return data_021759c8->mBuffers[7].mUnk_08 >> 31;
    }
    return 1;
}

// Resizes the block that holds the MainEffect archive so it ends where the caller says.
void ResizeMainEffectArchiveBlock(u8 *a, u32 b) {
    u8 *block;

    block = data_021759c8->mUnk_84c;
    NNS_FndResizeForMBlockExpHeap(GetHeap(GetCurrentHeapCall()), block, b + (a - block));
}

void func_020471b0(void *heap) {
    u32 uncompressedSize;
    void *data;

    uncompressedSize = *func_020cade8() >> 8;
    data_021759c8->mUnk_8b8 = 0;
    data = HeapAllocAligned(heap, uncompressedSize, 0x20);
    func_020487e0(func_020cade8(), data, uncompressedSize);
    ArchiveLoadFromMemory(&data_021759c8->mUnk_850, (const u8 *) gArchiveNames[19], data);
    data_021759c8->mUnk_8bc = data;
    data_021759c8->mUnk_8b8 = 1;
    CreateSearchIconMBChildAndMultiDownload(heap);
}

#pragma thumb off

void InitTouchPanelAndSetCalibration(void) {
    TPCalibrateParam calibrateParam;

    TP_Init();
    if (TP_GetUserInfo(&calibrateParam) == 0) {
        return;
    }
    TP_SetCalibrateParam(&calibrateParam);
}

void InitTouchMicInput(void *heap) {
    gTouchMicInput = HeapAlloc(heap, 0x40);
    gTouchMicInput->mTouchAutoSampling = 0;
    gTouchMicInput->mMicAutoSampling = 0;
    gTouchMicInput->mUnk_30_2 = 0;
    gTouchMicInput->mMicOverThreshold = 0;
    gTouchMicInput->mMicBuffer = NULL;
    InitMicAndAmp();
}
