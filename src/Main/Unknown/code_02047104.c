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
#include "code_0214e308.h"
#include "Main/Unknown/code_02018000.h"
#include "Main/Unknown/code_020483e4.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02048000.h"
#include "Main/Unknown/code_0205e000.h"
#include "code_020176b0.h"
#include "code_02017f24.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_0204f5e4.h"
#include "Main/Unknown/code_0204f240.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/unk_02165000.h"
#include "code_0200d118.h"
#include "code_02003be0.h"
#include "code_0200eddc.h"
#include "code_02139f70.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_02004d80.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "code_0214d464.h"
#include "code_0214d564.h"
#include "00/code_02181f98.h"

#pragma thumb on

void BuildResultArchivePath(char *a) {
    const char *b;

    if (data_0217b488->mUnk_78 == 1) {
        b = data_usa_02165108;
    } else {
        b = data_usa_0216510c;
    }
    OS_SNPrintf(a, 0x80, gResultArchivePathFormat, gSceneNames[10].mName, b, data_usa_02165124);
}

void BuildResultArchivePathWithLanguage(char *a) {
    const char *b;
    u32 c;

    if (data_0217b488->mUnk_78 == 1) {
        b = data_usa_021650e0;
    } else {
        b = data_usa_021650e4;
    }
    c = func_02048474();
    OS_SNPrintf(a, 0x80, gResultLanguageArchivePathFormat, gSceneNames[10].mName, b, c, data_usa_02165100);
}

#pragma thumb off

#pragma thumb on

void BuildStaffRollArchivePath(char *a) {
    u32 v1;
    v1 = func_02048474();
    OS_SNPrintf(a, 0x80, gStaffRollLanguageArchivePathFormat, v1, data_021650d8);
}

void BuildSceneModeArchivePath(char *a, const char *b, int c) {
    if (*b != 0) {
        OS_SNPrintf(a, 0x80, gSceneModeArchivePathFormat, b, gModeArchiveNames[c], data_021650b4);
    }
}

void BuildSceneModeLanguageArchivePath(char *a, const char *b, int c) {
    u32 v1;
    if (*b != 0) {
        v1 = func_02048474();
        OS_SNPrintf(a, 0x80, gSceneModeLanguageArchivePathFormat, b, gModeArchiveNames[c], v1, data_02165098);
    }
}

void BuildArchivePathWithLanguage(const char *a, char *b) {
    u32 v1;
    v1 = func_02048474();
    OS_SNPrintf(b, 0x80, gLanguageArchivePathFormat, a, v1);
}

#pragma thumb off

#pragma thumb on

void LoadArchiveSlotForScene(int a, int b) {
    char c[0x80] = {0};
    u32 *d;
    s32 f;
    s32 e;
    s32 g;
    s32 h;

    d = NULL;
    if (data_021759c8->mUnk_00[a].mLoaded != 0) {
        return;
    }
    e = gArchiveSlotInfos[a].mUnk_0c;
    f = gArchiveSlotInfos[a].mUnk_10;
    g = gArchiveSlotInfos[a].mUnk_14;
    h = gArchiveSlotInfos[a].mBufferIndex;
    if (h != -1) {
        d = data_021759c8->mBuffers[h].mData;
    }
    switch (a) {
        case 3:
        case 13:
            func_02048498(c, gRaceSetup->mCourseId, a != 3);
            break;
        case 5:
            switch (b) {
                case 2:
                    d = data_021759c8->mBuffers[2].mData;
                    break;
                case 1:
                    d = data_021759c8->mBuffers[0].mData;
                    break;
                case 10:
                    d = data_021759c8->mBuffers[14].mData;
                    break;
            }
            switch (b) {
                case 10:
                    BuildResultArchivePath(c);
                    break;
                case 2:
                    if (gRaceSetup->mRaceKind == RACE_KIND_STAFF_ROLL) {
                        OS_SNPrintf(c, 0x80, gStaffRollArchivePath);
                    } else {
                        func_020483e4(c, gSceneNames[b].mName);
                    }
                    break;
                default:
                    func_020483e4(c, gSceneNames[b].mName);
                    break;
            }
            g = gSceneNames[b].mUnk_04;
            break;
        case 9:
            switch (b) {
                case 2:
                    d = data_021759c8->mBuffers[3].mData;
                    break;
                case 1:
                    d = data_021759c8->mBuffers[1].mData;
                    break;
                case 10:
                    d = data_021759c8->mBuffers[15].mData;
                    break;
            }
            switch (b) {
                case 10:
                    BuildResultArchivePathWithLanguage(c);
                    break;
                case 2:
                    if (gRaceSetup->mRaceKind == RACE_KIND_STAFF_ROLL) {
                        BuildStaffRollArchivePath(c);
                    } else {
                        func_0204840c(c, gSceneNames[b].mName);
                    }
                    break;
                default:
                    func_0204840c(c, gSceneNames[b].mName);
                    break;
            }
            break;
        case 11:
            BuildSceneModeArchivePath(c, gSceneNames[b].mName, gRaceSetup->mMode);
            break;
        case 12:
            BuildSceneModeLanguageArchivePath(c, gSceneNames[b].mName, gRaceSetup->mMode);
            break;
        case 2:
        case 15:
        case 17:
            BuildArchivePathWithLanguage(gArchiveSlotInfos[a].mPath, c);
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
            strncpy(c, gArchiveSlotInfos[(s32) a].mPath, 0x80);
            break;
    }
    if (c[0] != 0) {
        LoadArchiveSlot(a, c, d, NULL, f, e, g);
    }
    h = *(s32 *) ((s32) &gArchiveSlotInfos[0].mNextSlot + a * 0x18);
    if (h != -1) {
        LoadArchiveSlotForScene(h, b);
    }
}

void LoadArchiveSlot(s32 a, const char *b, u32 *c, void *d, s32 e, s32 f, s32 g) {
    Unk021759c8_8c8 *p;
    s32 h;

    p = &data_021759c8->mUnk_8c8;
    strncpy((char *) p->mUnk_00, b, 0x80);
    p->mUnk_8c = a;
    p->mUnk_80 = c;
    p->mUnk_84 = d;
    p->mUnk_90 = e;
    p->mUnk_94 = f;
    p->mUnk_9c = g;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        if (p->mUnk_80 != NULL) {
            if (p->mUnk_94 != 0) {
                h = gArchiveSlotInfos[a].mBufferIndex;
                if (h != -1) {
                    data_021759c8->mBuffers[h].mUnk_08_31 = 1;
                }
                UncompressArchiveMemory();
            } else {
                p->mUnk_84 = p->mUnk_80;
            }
            LoadArchiveSlotData();
        }
    } else {
        if (a == 0x13) {
            UncompressArchiveMemory();
        } else {
            UncompressArchiveFile();
        }
        LoadArchiveSlotData();
    }
}

void UncompressArchiveFile(void) {
    Unk021759c8_8c8 *p;
    FSFile f;
    MIUncompContextLZ b;
    u32 n;
    s32 r;

    p = &data_021759c8->mUnk_8c8;
    FS_InitFile(&f);
    if (FS_OpenFile(&f, p->mUnk_00) == 0) {
        return;
    }
    if (FS_ReadFile(&f, p->mUnk_88, 4) < 0) {
        return;
    }
    n = *p->mUnk_88 >> 8;
    if (n > 0x200000) {
        return;
    }
    if (p->mUnk_90 != 0) {
        p->mUnk_84 = HeapAllocAligned(GetHeap(func_020364e8()), n, -0x20);
    } else {
        p->mUnk_84 = HeapAllocAligned(GetHeap(func_020364e8()), n, 0x20);
    }
    MI_InitUncompContextLZ(&b, p->mUnk_84, (const MICompressionHeader *) p->mUnk_88);
    do {
        r = FS_ReadFile(&f, p->mUnk_88, 0x400);
        if (r <= 0) {
            return;
        }
    } while (MI_ReadUncompLZ8(&b, (const u8 *) p->mUnk_88, r) != 0);
    DC_StoreRange(p->mUnk_84, n);
    NNS_FndGetTotalFreeSizeForExpHeap(GetHeap(func_020364e8()));
}

void UncompressArchiveMemory(void) {
    Unk021759c8_8c8 *p;
    u32 n;

    p = &data_021759c8->mUnk_8c8;
    n = *p->mUnk_80 >> 8;
    if (p->mUnk_90 != 0) {
        p->mUnk_84 = HeapAllocAligned(GetHeap(func_020364e8()), n, -0x20);
    } else {
        p->mUnk_84 = HeapAllocAligned(GetHeap(func_020364e8()), n, 0x20);
    }
    MI_UncompressLZ8(p->mUnk_80, p->mUnk_84);
    DC_StoreRange(p->mUnk_84, n);
    NNS_FndGetTotalFreeSizeForExpHeap(GetHeap(func_020364e8()));
}

void LoadArchiveSlotData(void) {
    Unk021759c8_8c8 *p;
    ArchiveSlot *e;

    p = &data_021759c8->mUnk_8c8;
    e = &data_021759c8->mUnk_00[p->mUnk_8c];
    if (p->mUnk_84 != NULL) {
        if (ArchiveLoadFromMemory(&e->mArchive, (const u8 *) gArchiveNames[p->mUnk_8c], p->mUnk_84) != 0) {
            e->mLoaded = 1;
            e->mData = p->mUnk_84;
        }
    }
}

void ReleaseArchiveSlot(int a) {
    BOOL b;
    s32 c;

    b = TRUE;
    if (data_021759c8->mUnk_00[a].mLoaded != 0 && a != 0x13) {
        ArchiveUnload(&data_021759c8->mUnk_00[a].mArchive.mUnk_00);
        if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
            c = gArchiveSlotInfos[a].mBufferIndex;
            if (c != -1 && data_021759c8->mBuffers[c].mUnk_08_29 != 0) {
                b = FALSE;
            } else {
                data_021759c8->mBuffers[c].mUnk_08_31 = 1;
            }
        }
        if (b != FALSE) {
            HeapFree(GetHeap(func_020364e8()), data_021759c8->mUnk_00[a].mData);
        }
        data_021759c8->mUnk_00[a].mLoaded = 0;
        data_021759c8->mUnk_00[a].mData = 0;
        NNS_FndGetTotalFreeSizeForExpHeap(GetHeap(func_020364e8()));
    }
}

void LoadArchiveSlotsForScene(s32 a) {
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2 && a == 6 && data_0217b488->mUnk_74 == 0) {
    } else {
        LoadArchiveSlotForScene(1, a);
    }
    switch (a) {
        case 1:
        case 12:
            LoadArchiveSlotForScene(5, a);
            LoadArchiveSlotForScene(14, a);
            LoadArchiveSlotForScene(16, a);
            break;
        case 10:
            LoadArchiveSlotForScene(0, a);
            LoadArchiveSlotForScene(5, a);
            LoadArchiveSlotForScene(16, a);
            LoadArchiveSlotForScene(18, a);
            break;
        case 2:
            LoadArchiveSlotForScene(18, a);
            LoadArchiveSlotForScene(6, a);
            LoadArchiveSlotForScene(8, a);
            break;
        case 3:
            LoadArchiveSlotForScene(0, a);
            LoadArchiveSlotForScene(5, a);
            LoadArchiveSlotForScene(16, a);
            break;
        case 5:
            LoadArchiveSlotForScene(5, a);
            LoadArchiveSlotForScene(14, a);
            LoadArchiveSlotForScene(16, a);
            break;
        case 0:
        case 7:
        case 8:
        case 9:
        case 11:
        case 13:
        case 14:
        case 15:
            LoadArchiveSlotForScene(5, a);
            LoadArchiveSlotForScene(16, a);
            break;
        case 4:
            if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
                LoadArchiveSlotForScene(5, a);
                LoadArchiveSlotForScene(16, a);
            }
            break;
        case 6:
            if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
                LoadArchiveSlotForScene(5, a);
                LoadArchiveSlotForScene(16, a);
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
void SetHeapGroupId(u32 a) {
    NNS_FndSetGroupIDForExpHeap(GetHeap(func_020364e8()), a);
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
    int v1;
    v1 = GetCurrentSceneNumber();
    if (v1 == 3) {
        return FindKartModelFile(path);
    }
    return LoadKartModelFile(path);
}

void *FindKartModelFile(const char *path) {
    int v1;
    void *file;
    file = NULL;
    v1 = GetCurrentSceneNumber();
    if (((v1 == 1) || (v1 == 3)) || (v1 == 0xc)) {
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
    s32 b;
    char fullPath[0x80];
    u32 archiveName;

    file = NULL;
    b = GetCurrentSceneNumber();
    if (b == 1 || b == 3 || b == 0xc) {
        archiveName = gArchiveNames[10];
        if (path[0] == '/') {
            OS_SNPrintf(fullPath, 0x80, data_usa_02165008, archiveName, path);
        } else {
            OS_SNPrintf(fullPath, 0x80, data_usa_02165010, archiveName, path);
        }
        file = func_02048504(fullPath, 8);
    } else {
        if (data_021759c8->mUnk_00[6].mLoaded != 0) {
            archiveName = gArchiveNames[6];
            if (path[0] == '/') {
                OS_SNPrintf(fullPath, 0x80, data_usa_02165018, archiveName, path);
            } else {
                OS_SNPrintf(fullPath, 0x80, data_usa_02165020, archiveName, path);
            }
            file = func_02048504(fullPath, 8);
        }
        if (file == NULL && data_021759c8->mUnk_00[7].mLoaded != 0) {
            archiveName = gArchiveNames[7];
            if (path[0] == '/') {
                OS_SNPrintf(fullPath, 0x80, data_usa_02165028, archiveName, path);
            } else {
                OS_SNPrintf(fullPath, 0x80, data_usa_02165030, archiveName, path);
            }
            file = func_02048504(fullPath, 8);
        }
        if (file == NULL && data_021759c8->mUnk_00[8].mLoaded != 0) {
            archiveName = gArchiveNames[8];
            if (path[0] == '/') {
                OS_SNPrintf(fullPath, 0x80, data_usa_02165038, archiveName, path);
            } else {
                OS_SNPrintf(fullPath, 0x80, data_usa_02165040, archiveName, path);
            }
            file = func_02048504(fullPath, 8);
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
    int v1;
    ReleaseArchiveSlot(7);
    ReleaseArchiveSlot(8);
    SetHeapGroupId((u16) 0);
    v1 = GetCurrentSceneNumber();
    if (v1 == 2) {
        LoadArchiveSlotForScene(3, 2);
    }
    SetHeapGroupId((u16) 9);
}

void func_020476ec(void) {
    int v1;
    ReleaseArchiveSlot(0xd);
    SetHeapGroupId((u16) 0);
    v1 = GetCurrentSceneNumber();
    if (v1 == 2) {
        LoadArchiveSlotForScene(5, 2);
        LoadArchiveSlotForScene(0xb, 2);
        LoadArchiveSlotForScene(0, 2);
    }
    SetHeapGroupId((u16) 9);
}

void func_020476ac(void) {
    u32 v1;
    v1 = GetCurrentSceneNumber();
    ReleaseArchiveSlot(10);
    SetHeapGroupId((u16) 0);
    LoadArchiveSlotForScene(1, v1);
    LoadArchiveSlotForScene(5, v1);
    LoadArchiveSlotForScene(0xe, v1);
    LoadArchiveSlotForScene(0x10, v1);
    SetHeapGroupId((u16) 9);
}

#pragma thumb off

#pragma thumb on

void InitArchiveBuffer(NNSiFndHeapHead *a, s32 b, s32 c, u32 d, u32 e) {
    ArchiveBuffer *p = &data_021759c8->mBuffers[b];
    p->mHeap = a;
    p->mData = NULL;
    p->mUnk_08_0 = c << 10;
    p->mUnk_08_29 = d;
    p->mUnk_08_30 = e;
    p->mUnk_08_31 = 1;
}

#pragma thumb off

#pragma thumb on

// Sets up 12 archive buffers on three heaps.
void InitArchiveBuffers(NNSiFndHeapHead *a, NNSiFndHeapHead *b, NNSiFndHeapHead *c) {
    InitArchiveBuffer(c, 2, 0x3c, 0, 1);
    InitArchiveBuffer(c, 3, 0x32, 0, 1);
    InitArchiveBuffer(c, 4, 5, 0, 1);
    InitArchiveBuffer(c, 5, 5, 0, 1);
    InitArchiveBuffer(c, 0, 0x14, 0, 1);
    InitArchiveBuffer(c, 1, 0x14, 0, 1);
    InitArchiveBuffer(c, 0xe, 0x46, 0, 1);
    InitArchiveBuffer(c, 0xf, 0x46, 0, 1);
    InitArchiveBuffer(b, 6, 200, 1, 1);
    InitArchiveBuffer(b, 7, 200, 0, 1);
    InitArchiveBuffer(a, 8, 0x46, 1, 0);
    InitArchiveBuffer(a, 0xd, 0x1e, 0, 0);
    data_021759c8->mUnk_a78 = a;
    data_021759c8->mCourseBufferHeap = b;
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

void RequestArchiveLoad(const void *a, s32 b) {
    ArchiveBuffer *p = &data_021759c8->mBuffers[b];
    func_0204f4d0(a, p->mHeap, &p->mData, p->mUnk_08_0, p->mUnk_08_29);
    p->mUnk_08_31 = 1;
}

#pragma thumb off

#pragma thumb on

void RequestArchiveLoadWithLanguage(const void *a, u32 b) {
    u32 v1;
    char v2[128];
    v1 = func_02048440();
    OS_SNPrintf(v2, 0x80, gArchivePrefixFormat, a, v1);
    RequestArchiveLoad(v2, b);
}

void func_020473e4(void) {
    func_0204f5e4();
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
    func_0204f5e4();
    NNS_FndFreeToFrmHeap(data_021759c8->mUnk_a80, 3);
    RequestArchiveLoad(gMenuDLArchivePath, 0);
    RequestArchiveLoadWithLanguage(gMenuDLArchivePrefix, 1);
}

#pragma thumb off

#pragma thumb on

void RequestRaceArchives(void *a, void *b) {
    char c[128];
    func_0204f5e4();
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
    func_02048498(c, (s32) a, 0);
    RequestArchiveLoad(c, 6);
    func_02048498(c, (s32) a, 1);
    RequestArchiveLoad(c, 7);
    data_021759c8->mUnk_a70 = a;
}

#pragma thumb off

#pragma thumb on

void RequestResultDLArchives(void) {
    func_0204f5e4();
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
    u8 *p;

    p = data_021759c8->mUnk_84c;
    NNS_FndResizeForMBlockExpHeap(GetHeap(func_020364e8()), p, b + (a - p));
}

void func_020471b0(void *a) {
    u32 n;
    void *p;

    n = *func_020cade8() >> 8;
    data_021759c8->mUnk_8b8 = 0;
    p = HeapAllocAligned(a, n, 0x20);
    func_020487e0(func_020cade8(), p, n);
    ArchiveLoadFromMemory(&data_021759c8->mUnk_850, (const u8 *) gArchiveNames[19], p);
    data_021759c8->mUnk_8bc = p;
    data_021759c8->mUnk_8b8 = 1;
    CreateSearchIconMBChildAndMultiDownload(a);
}

#pragma thumb off

void InitTouchPanelAndSetCalibration(void) {
    TPCalibrateParam v;

    TP_Init();
    if (TP_GetUserInfo(&v) == 0) {
        return;
    }
    TP_SetCalibrateParam(&v);
}

void InitTouchMicInput(void *a) {
    gTouchMicInput = HeapAlloc(a, 0x40);
    gTouchMicInput->mUnk_30_0 = 0;
    gTouchMicInput->mUnk_30_1 = 0;
    gTouchMicInput->mUnk_30_2 = 0;
    gTouchMicInput->mUnk_30_3 = 0;
    gTouchMicInput->mMicBuffer = NULL;
    func_0210f1d4();
}
