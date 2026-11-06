#include "Main/Unknown/code_02007478.h"
#include "Main/Unknown/code_0200c0d8.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_0214d018.h"

#pragma thumb on

u32 func_020074d8(void) {
    Unk020074d8_msg v1;
    u8 v2[16];
    u16 v3;
    u32 v4;
    u16 v5;
    u8 v6;
    Unk0216fdac *v7;
    u8 v8;
    u8 *v9;
    v5 = 0;
    v4 = -1;
    MI_CpuFill8(v2, 0, 16);
    v3 = 1;
    v7 = data_0216fdac;
    for (; v3 <= 15; v3++) {
        if (v7->mUnk_14e8[v3 - 1] == 5) {
            v2[v7->mUnk_1526[v3 - 1]]++;
        }
    }
    v6 = data_usa_02161784;
    v8 = 0;
    do {
        v6 = (v6 + 1) % 16;
        if (((Unk0216fdac *) ((u8 *) v7 + v6 * 0x5d4))->mUnk_1d52 != 0 && v2[v6] != 0) {
            v4 = (s8) v6;
            break;
        }
        v8++;
    } while (v8 < 16);
    if (v4 == -1) {
        return 21;
    }
    data_usa_02161784 = v4;
    for (v3 = 1; v3 <= 15; v3++) {
        if (v7->mUnk_14e8[v3 - 1] == 5 && v4 == v7->mUnk_1526[v3 - 1]) {
            v5 |= 1 << v3;
        }
    }
    v1.mUnk_00 = 3;
    v1.mUnk_02 = v4;
    v9 = func_0200c3a4((u8 *) &v1, (u8 *) v7);
    if (v9 != NULL) {
        MI_CpuCopy8(data_0216fdac->mUnk_1788 + v4 * 0x5d4, v9, 0xe4);
    }
    return func_02008908(0xea, v5, *(u32 *) &data_0216fdac);
}

void func_02007478(Unk02007478 *a) {
    Unk0200adfc_30 *v1;
    Unk0200adfc *v2;
    FSFile v3;
    u32 v4;
    v1 = a->mUnk_10;
    v2 = a->mUnk_14;
    FS_InitFile(&v3);
    v4 = v1->mUnk_00;
    if (FS_OpenFileDirect(&v3, FS_FindArchive(v2->mUnk_10, v2->mUnk_14), v4, v4 + v1->mUnk_04, -1) != 0) {
        if (v1->mUnk_04 == FS_ReadFile(&v3, v1->mUnk_08, v1->mUnk_04)) {
            v1->mUnk_0c = 2;
        }
        FS_CloseFile(&v3);
    }
    if (v1->mUnk_0c != 2) {
        OS_Terminate();
    }
}

#pragma thumb off
