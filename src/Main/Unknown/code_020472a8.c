#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_02018000.h"
#include "Main/Unknown/code_020483e4.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02048000.h"
#include "Main/Unknown/code_0205e000.h"
#include "code_020176b0.h"
#include "Main/Unknown/code_020364e0.h"

#include "code_02017f24.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_0204f5e4.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/code_0204f240.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/unk_02165000.h"
#include "code_0200d118.h"
#include "code_020182c0.h"

#pragma thumb on
void func_02047b6c(u16 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value4;
    value4 = (value0) + (0u);
    value0 = (u32) func_020364e8();
    value0 = (u32) func_020364e0((void *) value0);
    value1 = (value4 << 16);
    value1 = (value1 >> 16);
    value0 = (u32) func_020176b0(value0, value1);
}
#pragma thumb off

#pragma thumb on

u32 FindArchiveFile(u32 archiveName, const char *path) {
    char fullPath[0x80];

    if (path[0] == '/') {
        func_0200d9e0(fullPath, 0x80, data_02165048, archiveName, path);
    } else {
        func_0200d9e0(fullPath, 0x80, data_02165050, archiveName, path);
    }
    return func_020182c0((const u8 *) fullPath);
}

#pragma thumb off

#pragma thumb on

void *func_02047b08(const char *path) {
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

void *func_0204799c(const char *path) {
    u32 file;

    file = FindArchiveFile(gArchiveNames[5], path);
    if (file == 0 && data_021759c8->mUnk_458 != 0) {
        file = FindArchiveFile(gArchiveNames[9], path);
    }
    if (func_0205e0a0() == 2) {
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
    v1 = func_0205e0a0();
    if (v1 == 3) {
        return FindKartModelFile(path);
    }
    return LoadKartModelFile(path);
}

void *FindKartModelFile(const char *path) {
    int v1;
    int file;
    file = 0;
    v1 = func_0205e0a0();
    if (((v1 == 1) || (v1 == 3)) || (v1 == 0xc)) {
        file = FindArchiveFile(gArchiveNames[10], path);
    } else {
        if (*(int *) ((*(int *) &data_021759c8) + 0x308) != 0) {
            file = FindArchiveFile(gArchiveNames[6], path);
        }
        if ((file == 0) && (*(int *) ((*(int *) &data_021759c8) + 0x378) != 0)) {
            file = FindArchiveFile(gArchiveNames[7], path);
        }
        if ((file == 0) && (*(int *) ((*(int *) &data_021759c8) + 0x3e8) != 0)) {
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
    b = func_0205e0a0();
    if (b == 1 || b == 3 || b == 0xc) {
        archiveName = gArchiveNames[10];
        if (path[0] == '/') {
            func_0200d9e0(fullPath, 0x80, data_usa_02165008, archiveName, path);
        } else {
            func_0200d9e0(fullPath, 0x80, data_usa_02165010, archiveName, path);
        }
        file = func_02048504(fullPath, 8);
    } else {
        if (data_021759c8->mUnk_00[6].mUnk_68 != 0) {
            archiveName = gArchiveNames[6];
            if (path[0] == '/') {
                func_0200d9e0(fullPath, 0x80, data_usa_02165018, archiveName, path);
            } else {
                func_0200d9e0(fullPath, 0x80, data_usa_02165020, archiveName, path);
            }
            file = func_02048504(fullPath, 8);
        }
        if (file == NULL && data_021759c8->mUnk_00[7].mUnk_68 != 0) {
            archiveName = gArchiveNames[7];
            if (path[0] == '/') {
                func_0200d9e0(fullPath, 0x80, data_usa_02165028, archiveName, path);
            } else {
                func_0200d9e0(fullPath, 0x80, data_usa_02165030, archiveName, path);
            }
            file = func_02048504(fullPath, 8);
        }
        if (file == NULL && data_021759c8->mUnk_00[8].mUnk_68 != 0) {
            archiveName = gArchiveNames[8];
            if (path[0] == '/') {
                func_0200d9e0(fullPath, 0x80, data_usa_02165038, archiveName, path);
            } else {
                func_0200d9e0(fullPath, 0x80, data_usa_02165040, archiveName, path);
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
    v1 = func_0205e0a0();
    if (v1 == 2) {
        func_02048050(3, 2);
    }
    func_02047b6c((u16) 9);
}

void func_020476ec(void) {
    int v1;
    func_02047cf0(0xd);
    func_02047b6c((u16) 0);
    v1 = func_0205e0a0();
    if (v1 == 2) {
        func_02048050(5, 2);
        func_02048050(0xb, 2);
        func_02048050(0, 2);
    }
    func_02047b6c((u16) 9);
}

void func_020476ac(void) {
    u32 v1;
    v1 = func_0205e0a0();
    func_02047cf0(10);
    func_02047b6c((u16) 0);
    func_02048050(1, (int) v1);
    func_02048050(5, (int) v1);
    func_02048050(0xe, (int) v1);
    func_02048050(0x10, (int) v1);
    func_02047b6c((u16) 9);
}

#pragma thumb off

#pragma thumb on

void func_02047634(void *a, s32 b, s32 c, u32 d, u32 e) {
    Unk021759c8_9b0 *p = &data_021759c8->mUnk_9b0[b];
    p->mUnk_00 = a;
    p->mUnk_04 = 0;
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
    u8 v2[128];
    v1 = func_02048440();
    func_0200d9e0((char *) v2, 0x80, (const char *) data_02164ffc, a, v1);
    func_02047498(v2, b);
}

void func_020473e4(void) {
    func_0204f5e4();
    func_0201804c((void *) data_021759c8->mUnk_a80, (u32) 3);
    func_02047498(data_02164f48, 0xb);
    func_02047498(data_02164f64, 0xc);
    func_02047498(data_02164f80, 0);
    func_02047468(data_02164f98, (u32) 1);
    func_02047498(data_02164fac, 8);
    func_02047498(data_02164fc0, 9);
    func_02047468(data_02164fd4, (u32) 10);
    func_02047498(data_02164fe4, 0xd);
}

void func_020473a8(void) {
    func_0204f5e4();
    func_0201804c((void *) data_021759c8->mUnk_a80, (u32) 3);
    func_02047498(data_02164f1c, 0);
    func_02047468(data_02164f34, (u32) 1);
}

#pragma thumb off

#pragma thumb on

void func_020472e4(void *a, void *b) {
    char c[128];
    func_0204f5e4();
    func_0201804c(data_021759c8->mUnk_a80, 3);
    func_02047498(data_02164e88, 2);
    func_02047468(data_02164ea0, 3);
    if (b == (void *) 3) {
        func_02047498(data_02164eb4, 4);
        func_02047468(data_02164ed0, 5);
    } else {
        func_02047498(data_02164ee8, 4);
        func_02047468(data_02164f04, 5);
    }
    data_021759c8->mUnk_a74 = b;
    func_0201804c(data_021759c8->mUnk_a7c, 3);
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
    func_0201804c((void *) ((u32) data_021759c8->mUnk_a80), (u32) 3);
    func_02047498(data_02164e54, 0xe);
    func_02047468(data_02164e70, (u32) 0xf);
}

#pragma thumb off
