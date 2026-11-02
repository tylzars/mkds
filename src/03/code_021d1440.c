#include "03/code_021d1440.h"
#include "03/unk_021da000.h"
#include "03/code_021d1000.h"
#include "Main/Unknown/code_02146000.h"
#include "code_021458c4.h"

#include "03/code_021d1d4c.h"
#include "03/code_021d1cd4.h"
#include "03/code_021d27d8.h"
#include "03/unk_021d7bd4.h"
#include "code_02004d80.h"
#include "code_02004270.h"
#include "code_02134d30.h"
#include "code_02139f70.h"
#include "code_0214d018.h"
#include "code_0200fd1c.h"
#include "code_02003be0.h"
#include "03/code_021d1d60.h"
#include "03/unk_021d67d8.h"
#include "code_02004238.h"
#include "code_0200cd1c.h"
#include "code_0200d118.h"
#include "code_0214578c.h"

void func_ov003_021d1654(void) {
    Unk02003024 a;
    u32 b[2];
    u32 c[2];
    char d[0x80];
    u32 e;
    u32 f;

    data_ov003_021da2b0 = func_ov003_021d283c(0xe8, 4);
    FS_InitFile(&a);
    if (FS_OpenFile(&a, data_ov003_021d7be0) == 0) {
        func_0200fd1c();
    }
    data_ov003_021da2b0->mUnk_e4 = func_0200cd28();
    e = a.mUnk_20.w.mUnk_04;
    FS_ReadFile(&a, b, 8);
    FS_ReadFile(&a, c, 8);
    FS_CloseFile(&a);
    FS_InitArchive(&data_ov003_021da2b0->mUnk_88);
    if (FS_RegisterArchiveName(&data_ov003_021da2b0->mUnk_88, data_ov003_021d67d8, 3) == 0) {
        func_0200fd1c();
    }
    FS_SetArchiveProc(&data_ov003_021da2b0->mUnk_88, func_ov003_021d15a4, 0x602);
    if (FS_LoadArchive(&data_ov003_021da2b0->mUnk_88, (u8 *) e, c[0], c[1], b[0], b[1],
                       (s32(*)(Unk02003a6c *, void *, u32, u32)) func_ov003_021d1574,
                       (s32(*)(Unk02003a6c *, void *, u32, u32)) func_ov003_021d1564) == 0) {
        func_0200fd1c();
    }
    f = FS_LoadArchiveTables(&data_ov003_021da2b0->mUnk_88, 0, 0);
    data_ov003_021da2b0->mUnk_00 = func_ov003_021d285c(f, 4);
    FS_LoadArchiveTables(&data_ov003_021da2b0->mUnk_88, (u32) data_ov003_021da2b0->mUnk_00, f);
    data_ov003_021da2b0->mUnk_84 = func_ov003_021d1d60(0x20, data_ov003_021da2b0->mUnk_04, 4);
    func_0200da28(d, data_ov003_021d7bf8, data_ov003_021d67d8);
    FS_ChangeDir((u8 *) d);
}

void func_ov003_021d15f4(void) {
    FS_ChangeDir(data_ov003_021d7bd8);
    ((u32(*)(Unk02003a6c *)) FS_UnloadArchiveTables)(&data_ov003_021da2b0->mUnk_88);
    FS_UnloadArchive(&data_ov003_021da2b0->mUnk_88);
    FS_ReleaseArchiveName(&data_ov003_021da2b0->mUnk_88);
    func_0200cd80(data_ov003_021da2b0->mUnk_e4);
    data_ov003_021da2b0->mUnk_e4 = 0;
    func_ov003_021d2808(data_ov003_021da2b0);
    data_ov003_021da2b0->mUnk_00 = 0;
    func_ov003_021d2808(&data_ov003_021da2b0);
}

s32 func_ov003_021d15a4(Unk02003024 *param_1, u32 param_2) {
    switch (param_2) {
        case 9:
            func_021457cc(data_ov003_021da2b0->mUnk_e4);
            return 0;
        case 10:
            func_021457ac(data_ov003_021da2b0->mUnk_e4);
            return 0;
        case 1:
            return 4;
        default:
            return 8;
    }
}

u32 func_ov003_021d1574(int param_1, u32 param_2, int param_3, u32 param_4) {
    func_021461d8((u32) (0xffffffff), (int) (param_3 + *(int *) (param_1 + 0x28)), (u32) (param_2), (u32) (param_4),
                  (UnkFunc *) (&func_ov003_021d1568), (u32) (param_1), 1);
    return 6;
}

void func_ov003_021d1568(Unk02003a6c *list) {
    FS_NotifyArchiveAsyncEnd(list, 0);
}

s32 func_ov003_021d1564(void) {
    return 1;
}

void *func_ov003_021d14b8(const u8 *param_1, u32 *param_2, s32 param_3) {
    Unk02003024 a;
    void *b;
    u32 c;
    s32 e;

    func_ov003_021d1cd4(data_ov003_021da2b0->mUnk_84);
    FS_InitFile(&a);
    if (FS_OpenFile(&a, param_1) == 0) {
        func_0200fd1c();
    }
    c = a.mUnk_20.w.mUnk_08 - a.mUnk_20.w.mUnk_04;
    if (param_2 != 0) {
        *param_2 = c;
    }
    if (func_ov003_021d1440(param_1, data_ov003_021d7bd4, 2) != 0) {
        e = -4;
    } else {
        e = param_3;
    }
    b = func_ov003_021d285c(c, e);
    FS_ReadFile(&a, b, c);
    FS_CloseFile(&a);
    if (e > 0) {
        return b;
    }
    c = *(u32 *) b >> 8;
    if (param_2 != 0) {
        *param_2 = c;
    }
    {
        void *d = func_ov003_021d285c(c, param_3);

        func_0214d344(b, d);
        func_ov003_021d2808(&b);
        return d;
    }
}

void func_ov003_021d1490(void *param_1, ...) {
    func_ov003_021d2808(&param_1);
    func_ov003_021d1d0c(data_ov003_021da2b0->mUnk_84, param_1);
}

u32 func_ov003_021d1440(const u8 *param_1, const u8 *param_2, s32 param_3) {
    s32 a = strlen(param_1);
    s32 b = strlen(param_2);

    if (a < param_3 || b < param_3) {
        return 0;
    }
    if (memcmp(param_1 + (a - param_3), param_2 + (b - param_3), param_3) == 0) {
        return 1;
    }
    return 0;
}
