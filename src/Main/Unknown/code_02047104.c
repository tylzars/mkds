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

void func_020483a0(char *a) {
    const char *b;

    if (data_0217b488->mUnk_78 == 1) {
        b = data_usa_02165108;
    } else {
        b = data_usa_0216510c;
    }
    StringFormatBounded(a, 0x80, data_usa_02165110, gSceneNames[10].mUnk_00, b, data_usa_02165124);
}

void func_02048350(char *a) {
    const char *b;
    u32 c;

    if (data_0217b488->mUnk_78 == 1) {
        b = data_usa_021650e0;
    } else {
        b = data_usa_021650e4;
    }
    c = func_02048474();
    StringFormatBounded(a, 0x80, data_usa_021650e8, gSceneNames[10].mUnk_00, b, c, data_usa_02165100);
}

#pragma thumb off

#pragma thumb on

void func_02048324(char *a) {
    u32 v1;
    v1 = func_02048474();
    StringFormatBounded(a, 0x80, data_021650bc, v1, (u32) &data_021650d8);
}

void func_020482f0(char *a, const char *b, int c) {
    if (*b != 0) {
        StringFormatBounded(a, 0x80, data_021650a0, b, ((u32 *) &data_02164d28)[c], (u32) &data_021650b4);
    }
}

void func_020482ac(char *a, u8 *b, int c) {
    u32 v1;
    if (*b != 0) {
        v1 = func_02048474();
        StringFormatBounded(a, 0x80, data_02165080, b, ((u32 *) &data_02164d28)[c], v1, (u32) &data_02165098);
    }
}

void func_02048284(u32 a, char *b) {
    u32 v1;
    v1 = func_02048474();
    StringFormatBounded(b, 0x80, data_02165074, a, v1);
}

#pragma thumb off

#pragma thumb on

void func_02048050(int a, int b) {
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
    e = data_usa_021543e0[a].mUnk_0c;
    f = data_usa_021543e0[a].mUnk_10;
    g = data_usa_021543e0[a].mUnk_14;
    h = data_usa_021543e0[a].mUnk_08;
    if (h != -1) {
        d = data_021759c8->mUnk_9b0[h].mUnk_04;
    }
    switch (a) {
        case 3:
        case 13:
            func_02048498(c, data_021759c0->mCourseId, a != 3);
            break;
        case 5:
            switch (b) {
                case 2:
                    d = data_021759c8->mUnk_9b0[2].mUnk_04;
                    break;
                case 1:
                    d = data_021759c8->mUnk_9b0[0].mUnk_04;
                    break;
                case 10:
                    d = data_021759c8->mUnk_9b0[14].mUnk_04;
                    break;
            }
            switch (b) {
                case 10:
                    func_020483a0(c);
                    break;
                case 2:
                    if (data_021759c0->mUnk_00c == 6) {
                        StringFormatBounded(c, 0x80, data_usa_02165058);
                    } else {
                        func_020483e4(c, (u8 *) gSceneNames[b].mUnk_00);
                    }
                    break;
                default:
                    func_020483e4(c, (u8 *) gSceneNames[b].mUnk_00);
                    break;
            }
            g = gSceneNames[b].mUnk_04;
            break;
        case 9:
            switch (b) {
                case 2:
                    d = data_021759c8->mUnk_9b0[3].mUnk_04;
                    break;
                case 1:
                    d = data_021759c8->mUnk_9b0[1].mUnk_04;
                    break;
                case 10:
                    d = data_021759c8->mUnk_9b0[15].mUnk_04;
                    break;
            }
            switch (b) {
                case 10:
                    func_02048350(c);
                    break;
                case 2:
                    if (data_021759c0->mUnk_00c == 6) {
                        func_02048324(c);
                    } else {
                        func_0204840c(c, (u8 *) gSceneNames[b].mUnk_00);
                    }
                    break;
                default:
                    func_0204840c(c, (u8 *) gSceneNames[b].mUnk_00);
                    break;
            }
            break;
        case 11:
            func_020482f0(c, gSceneNames[b].mUnk_00, data_021759c0->mMode);
            break;
        case 12:
            func_020482ac(c, (u8 *) gSceneNames[b].mUnk_00, data_021759c0->mMode);
            break;
        case 2:
        case 15:
        case 17:
            func_02048284((u32) data_usa_021543e0[a].mUnk_00, c);
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
            strncpy(c, data_usa_021543e0[(s32) a].mUnk_00, 0x80);
            break;
    }
    if (c[0] != 0) {
        func_02047f7c(a, c, d, NULL, f, e, g);
    }
    h = *(s32 *) ((s32) &data_usa_021543e0[0].mUnk_04 + a * 0x18);
    if (h != -1) {
        func_02048050(h, b);
    }
}

void func_02047f7c(s32 a, const char *b, u32 *c, void *d, s32 e, s32 f, s32 g) {
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
                h = data_usa_021543e0[a].mUnk_08;
                if (h != -1) {
                    data_021759c8->mUnk_9b0[h].mUnk_08_31 = 1;
                }
                func_02047e0c();
            } else {
                p->mUnk_84 = p->mUnk_80;
            }
            func_02047db8();
        }
    } else {
        if (a == 0x13) {
            func_02047e0c();
        } else {
            func_02047e94();
        }
        func_02047db8();
    }
}

void func_02047e94(void) {
    Unk021759c8_8c8 *p;
    Unk02003024 f;
    u8 b[0x10];
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
    ExpandCompressedStateInit((u32) b, (u32) p->mUnk_84, (u32) p->mUnk_88);
    do {
        r = FS_ReadFile(&f, p->mUnk_88, 0x400);
        if (r <= 0) {
            return;
        }
    } while (ExpandCompressedContinue(b, (const u8 *) p->mUnk_88, r) != 0);
    func_0200ee58(p->mUnk_84, n);
    ExpHeapGetTotalFreeSize(GetHeap(func_020364e8()));
}

void func_02047e0c(void) {
    Unk021759c8_8c8 *p;
    u32 n;

    p = &data_021759c8->mUnk_8c8;
    n = *p->mUnk_80 >> 8;
    if (p->mUnk_90 != 0) {
        p->mUnk_84 = HeapAllocAligned(GetHeap(func_020364e8()), n, -0x20);
    } else {
        p->mUnk_84 = HeapAllocAligned(GetHeap(func_020364e8()), n, 0x20);
    }
    ExpandCompressed(p->mUnk_80, p->mUnk_84);
    func_0200ee58(p->mUnk_84, n);
    ExpHeapGetTotalFreeSize(GetHeap(func_020364e8()));
}

void func_02047db8(void) {
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

void func_02047cf0(int a) {
    BOOL b;
    s32 c;

    b = TRUE;
    if (data_021759c8->mUnk_00[a].mLoaded != 0 && a != 0x13) {
        ArchiveUnload(&data_021759c8->mUnk_00[a].mArchive.mUnk_00);
        if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
            c = data_usa_021543e0[a].mUnk_08;
            if (c != -1 && data_021759c8->mUnk_9b0[c].mUnk_08_29 != 0) {
                b = FALSE;
            } else {
                data_021759c8->mUnk_9b0[c].mUnk_08_31 = 1;
            }
        }
        if (b != FALSE) {
            HeapFree(GetHeap(func_020364e8()), data_021759c8->mUnk_00[a].mData);
        }
        data_021759c8->mUnk_00[a].mLoaded = 0;
        data_021759c8->mUnk_00[a].mData = 0;
        ExpHeapGetTotalFreeSize(GetHeap(func_020364e8()));
    }
}

void func_02047ba0(s32 a) {
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2 && a == 6 && data_0217b488->mUnk_74 == 0) {
    } else {
        func_02048050(1, a);
    }
    switch (a) {
        case 1:
        case 12:
            func_02048050(5, a);
            func_02048050(14, a);
            func_02048050(16, a);
            break;
        case 10:
            func_02048050(0, a);
            func_02048050(5, a);
            func_02048050(16, a);
            func_02048050(18, a);
            break;
        case 2:
            func_02048050(18, a);
            func_02048050(6, a);
            func_02048050(8, a);
            break;
        case 3:
            func_02048050(0, a);
            func_02048050(5, a);
            func_02048050(16, a);
            break;
        case 5:
            func_02048050(5, a);
            func_02048050(14, a);
            func_02048050(16, a);
            break;
        case 0:
        case 7:
        case 8:
        case 9:
        case 11:
        case 13:
        case 14:
        case 15:
            func_02048050(5, a);
            func_02048050(16, a);
            break;
        case 4:
            if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
                func_02048050(5, a);
                func_02048050(16, a);
            }
            break;
        case 6:
            if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
                func_02048050(5, a);
                func_02048050(16, a);
            }
            break;
    }
}

void func_02047b88(void) {
    s32 i;

    for (i = 0; i < 20; i++) {
        func_02047cf0(i);
    }
}

#pragma thumb off

#pragma thumb on
void func_02047b6c(u16 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value4;
    value4 = (value0) + (0u);
    value0 = (u32) func_020364e8();
    value0 = (u32) GetHeap((void *) value0);
    value1 = (value4 << 16);
    value1 = (value1 >> 16);
    value0 = (u32) func_020176b0(value0, value1);
}
#pragma thumb off

#pragma thumb on

u32 FindArchiveFile(u32 archiveName, const char *path) {
    char fullPath[0x80];

    if (path[0] == '/') {
        StringFormatBounded(fullPath, 0x80, gArchiveColonFormat, archiveName, path);
    } else {
        StringFormatBounded(fullPath, 0x80, gArchiveColonSlashFormat, archiveName, path);
    }
    return ArchiveFileGetAddress((const u8 *) fullPath);
}

#pragma thumb off

#pragma thumb on

void *FindMainRaceOrMainEffectFile(const char *path) {
    int file;
    file = FindArchiveFile(gArchiveNames[0], path);
    if (file == 0) {
        file = FindArchiveFile(gArchiveNames[18], path);
    }
    return (void *) file;
}

#pragma thumb off

#pragma thumb on

void *func_02047a28(const char *path) {
    u32 file;

    file = 0;
    if (data_021759c8->mUnk_7d8 != 0) {
        file = FindArchiveFile(gArchiveNames[17], path);
    }
    if (file == 0 && data_021759c8->mUnk_768 != 0) {
        file = FindArchiveFile(gArchiveNames[16], path);
    }
    if (file == 0 && data_021759c8->mUnk_6f8 != 0) {
        file = FindArchiveFile(gArchiveNames[15], path);
    }
    if (file == 0 && data_021759c8->mUnk_688 != 0) {
        file = FindArchiveFile(gArchiveNames[14], path);
    }
    if (file == 0 && data_021759c8->mUnk_8b8 != 0) {
        file = FindArchiveFile(gArchiveNames[19], path);
    }
    if (file == 0 && data_021759c8->mUnk_148 != 0) {
        file = FindArchiveFile(gArchiveNames[2], path);
    }
    if (file == 0 && data_021759c8->mUnk_d8 != 0) {
        file = FindArchiveFile(gArchiveNames[1], path);
    }
    return (void *) file;
}

void *FindSceneFile(const char *path) {
    u32 file;

    file = FindArchiveFile(gArchiveNames[5], path);
    if (file == 0 && data_021759c8->mUnk_458 != 0) {
        file = FindArchiveFile(gArchiveNames[9], path);
    }
    if (GetCurrentSceneNumber() == 2) {
        if (file == 0 && data_021759c8->mUnk_538 != 0) {
            file = FindArchiveFile(gArchiveNames[11], path);
        }
        if (file == 0 && data_021759c8->mUnk_5a8 != 0) {
            file = FindArchiveFile(gArchiveNames[12], path);
        }
    }
    return (void *) file;
}

#pragma thumb off

#pragma thumb on

void *FindCourseFile(const char *path) {
    int file;
    file = FindArchiveFile(gArchiveNames[3], path);
    if (file == 0) {
        file = FindArchiveFile(gArchiveNames[13], path);
    }
    return (void *) file;
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
    int file;
    file = 0;
    v1 = GetCurrentSceneNumber();
    if (((v1 == 1) || (v1 == 3)) || (v1 == 0xc)) {
        file = FindArchiveFile(gArchiveNames[10], path);
    } else {
        if (data_021759c8->mUnk_308 != 0) {
            file = FindArchiveFile(gArchiveNames[6], path);
        }
        if ((file == 0) && (data_021759c8->mUnk_378 != 0)) {
            file = FindArchiveFile(gArchiveNames[7], path);
        }
        if ((file == 0) && (data_021759c8->mUnk_3e8 != 0)) {
            file = FindArchiveFile(gArchiveNames[8], path);
        }
    }
    return (void *) file;
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
            StringFormatBounded(fullPath, 0x80, data_usa_02165008, archiveName, path);
        } else {
            StringFormatBounded(fullPath, 0x80, data_usa_02165010, archiveName, path);
        }
        file = func_02048504(fullPath, 8);
    } else {
        if (data_021759c8->mUnk_00[6].mLoaded != 0) {
            archiveName = gArchiveNames[6];
            if (path[0] == '/') {
                StringFormatBounded(fullPath, 0x80, data_usa_02165018, archiveName, path);
            } else {
                StringFormatBounded(fullPath, 0x80, data_usa_02165020, archiveName, path);
            }
            file = func_02048504(fullPath, 8);
        }
        if (file == NULL && data_021759c8->mUnk_00[7].mLoaded != 0) {
            archiveName = gArchiveNames[7];
            if (path[0] == '/') {
                StringFormatBounded(fullPath, 0x80, data_usa_02165028, archiveName, path);
            } else {
                StringFormatBounded(fullPath, 0x80, data_usa_02165030, archiveName, path);
            }
            file = func_02048504(fullPath, 8);
        }
        if (file == NULL && data_021759c8->mUnk_00[8].mLoaded != 0) {
            archiveName = gArchiveNames[8];
            if (path[0] == '/') {
                StringFormatBounded(fullPath, 0x80, data_usa_02165038, archiveName, path);
            } else {
                StringFormatBounded(fullPath, 0x80, data_usa_02165040, archiveName, path);
            }
            file = func_02048504(fullPath, 8);
        }
    }
    return file;
}

#pragma thumb off

#pragma thumb on

void func_0204775c(void) {
    func_02047cf0(6);
    func_02047b6c((u16) 0);
    func_02048050(7, 2);
    func_02047b6c((u16) 9);
}

void func_02047728(void) {
    int v1;
    func_02047cf0(7);
    func_02047cf0(8);
    func_02047b6c((u16) 0);
    v1 = GetCurrentSceneNumber();
    if (v1 == 2) {
        func_02048050(3, 2);
    }
    func_02047b6c((u16) 9);
}

void func_020476ec(void) {
    int v1;
    func_02047cf0(0xd);
    func_02047b6c((u16) 0);
    v1 = GetCurrentSceneNumber();
    if (v1 == 2) {
        func_02048050(5, 2);
        func_02048050(0xb, 2);
        func_02048050(0, 2);
    }
    func_02047b6c((u16) 9);
}

void func_020476ac(void) {
    u32 v1;
    v1 = GetCurrentSceneNumber();
    func_02047cf0(10);
    func_02047b6c((u16) 0);
    func_02048050(1, v1);
    func_02048050(5, v1);
    func_02048050(0xe, v1);
    func_02048050(0x10, v1);
    func_02047b6c((u16) 9);
}

#pragma thumb off

#pragma thumb on

void func_02047634(void *a, s32 b, s32 c, u32 d, u32 e) {
    Unk021759c8_9b0 *p = &data_021759c8->mUnk_9b0[b];
    p->mUnk_00 = a;
    p->mUnk_04 = NULL;
    p->mUnk_08_0 = c << 10;
    p->mUnk_08_29 = d;
    p->mUnk_08_30 = e;
    p->mUnk_08_31 = 1;
}

#pragma thumb off

#pragma thumb on

void func_02047544(Unk02017f24 *a, Unk02017f24 *b, Unk02017f24 *c) {
    func_02047634(c, 2, 0x3c, (u32) 0, (u32) 1);
    func_02047634(c, 3, 0x32, (u32) 0, (u32) 1);
    func_02047634(c, 4, 5, (u32) 0, (u32) 1);
    func_02047634(c, 5, 5, (u32) 0, (u32) 1);
    func_02047634(c, 0, 0x14, (u32) 0, (u32) 1);
    func_02047634(c, 1, 0x14, (u32) 0, (u32) 1);
    func_02047634(c, 0xe, 0x46, (u32) 0, (u32) 1);
    func_02047634(c, 0xf, 0x46, (u32) 0, (u32) 1);
    func_02047634(b, 6, 200, (u32) 1, (u32) 1);
    func_02047634(b, 7, 200, (u32) 0, (u32) 1);
    func_02047634(a, 8, 0x46, (u32) 1, (u32) 0);
    func_02047634(a, 0xd, 0x1e, (u32) 0, (u32) 0);
    data_021759c8->mUnk_a78 = a;
    data_021759c8->mUnk_a7c = b;
    data_021759c8->mUnk_a80 = c;
}

void func_020474e4(void) {
    func_02047634(data_0217aa10->mUnk_a0, 0xb, 0xaa, (u32) 0, (u32) 0);
    func_02047634(data_0217aa10->mUnk_a0, 0xc, 0x6e, (u32) 0, (u32) 0);
    func_02047634(data_0217aa10->mUnk_a0, 9, 0x1e, (u32) 0, (u32) 0);
    func_02047634(data_0217aa10->mUnk_a0, 10, 0x1e, (u32) 0, (u32) 0);
}

#pragma thumb off

#pragma thumb on

void func_02047498(const void *a, s32 b) {
    Unk021759c8_9b0 *p = &data_021759c8->mUnk_9b0[b];
    func_0204f4d0(a, p->mUnk_00, &p->mUnk_04, p->mUnk_08_0, p->mUnk_08_29);
    p->mUnk_08_31 = 1;
}

#pragma thumb off

#pragma thumb on

void func_02047468(const void *a, u32 b) {
    u32 v1;
    char v2[128];
    v1 = func_02048440();
    StringFormatBounded(v2, 0x80, gArchivePrefixFormat, a, v1);
    func_02047498(v2, b);
}

void func_020473e4(void) {
    func_0204f5e4();
    FrmHeapFree(data_021759c8->mUnk_a80, (u32) 3);
    func_02047498(gKartModelMainAArchivePath, 0xb);
    func_02047498(gKartModelMainBArchivePath, 0xc);
    func_02047498(gMenuDLArchivePath2, 0);
    func_02047468(gMenuDLArchivePrefix2, (u32) 1);
    func_02047498(gMainRaceArchivePath, 8);
    func_02047498(gMain2DArchivePath, 9);
    func_02047468(gMain2DArchivePrefix, (u32) 10);
    func_02047498(gMainEffectArchivePath, 0xd);
}

void func_020473a8(void) {
    func_0204f5e4();
    FrmHeapFree(data_021759c8->mUnk_a80, (u32) 3);
    func_02047498(gMenuDLArchivePath, 0);
    func_02047468(gMenuDLArchivePrefix, (u32) 1);
}

#pragma thumb off

#pragma thumb on

void func_020472e4(void *a, void *b) {
    char c[128];
    func_0204f5e4();
    FrmHeapFree(data_021759c8->mUnk_a80, 3);
    func_02047498(gRaceArchivePath, 2);
    func_02047468(gRaceArchivePrefix, 3);
    if (b == (void *) 3) {
        func_02047498(gRaceVsArchivePath, 4);
        func_02047468(gRaceVsArchivePrefix, 5);
    } else {
        func_02047498(gRaceMgArchivePath, 4);
        func_02047468(gRaceMgArchivePrefix, 5);
    }
    data_021759c8->mUnk_a74 = b;
    FrmHeapFree(data_021759c8->mUnk_a7c, 3);
    func_02048498(c, (s32) a, 0);
    func_02047498(c, 6);
    func_02048498(c, (s32) a, 1);
    func_02047498(c, 7);
    data_021759c8->mUnk_a70 = a;
}

#pragma thumb off

#pragma thumb on

void func_020472a8(void) {
    func_0204f5e4();
    FrmHeapFree((void *) ((u32) data_021759c8->mUnk_a80), (u32) 3);
    func_02047498(gResultDLArchivePath, 0xe);
    func_02047468(gResultDLArchivePrefix, (u32) 0xf);
}

#pragma thumb off

#pragma thumb on

void func_02047274(void) {
    s32 i;

    for (i = 0; i < 16; i++) {
        *(u32 *) ((u8 *) &data_021759c8->mUnk_9b0[0].mUnk_08 + i * 12) &= 0x7fffffff;
    }
}

s32 func_02047250(void) {
    if (*(vu16 *) 0x027ffc40 == 2) {
        return data_021759c8->mUnk_9b0[7].mUnk_08 >> 31;
    }
    return 1;
}

void func_02047220(void *a, u32 b) {
    void *p;

    p = data_021759c8->mUnk_84c;
    ExpHeapResizeBlock(GetHeap(func_020364e8()), p, b + ((u32) a - (u32) p));
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

void func_02047178(void) {
    Unk0214e334 v;

    func_0214eb88();
    if (func_0214eadc(&v) == 0) {
        return;
    }
    func_0214e994(&v);
}

void func_02047104(void *a) {
    data_021759c4 = HeapAlloc(a, 0x40);
    data_021759c4->mUnk_30_0 = 0;
    data_021759c4->mUnk_30_1 = 0;
    data_021759c4->mUnk_30_2 = 0;
    data_021759c4->mUnk_30_3 = 0;
    data_021759c4->mUnk_3c = NULL;
    func_0210f1d4();
}
