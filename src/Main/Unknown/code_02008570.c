#include "Main/Unknown/code_02008570.h"
#include "Main/Unknown/code_0200850c.h"
#include "Main/Unknown/code_02008000.h"
#include "Main/Unknown/code_02000a58.h"
#include "Main/Unknown/code_0200ad00.h"
#include "Main/Unknown/code_0200aea8.h"
#include "code_02003024.h"
#include "code_02003be0.h"
#include "code_02004d80.h"
#include "code_0200eddc.h"
#include "code_0214d018.h"

#pragma thumb on

static inline u32 func_02008570_inline(Unk02008570Header *a) {
    u32 b = a->mUnk_80;
    if (b == 0) {
        b = 0x01000000;
    }
    return b;
}

int func_02008570(FSFile *param_1, void *param_2, u32 param_3) {
    FSFile *v1;
    Unk02008570Header *v2;
    u8 *v3;
    FSFile v4;
    BOOL v11;
    BOOL v12;
    u32 v13;
    u32 v7;
    Unk0200adfc *v5;
    u32 *v6;
    s32 v8;
    u32 v9;
    s32 v10;
    u32 v14[4];
    s8 *p;
    v1 = param_1;
    v2 = param_2;
    v11 = FALSE;
    if (param_3 >= 0x164) {
        v12 = FALSE;
        v13 = param_3;
        v3 = (u8 *) v2;
        v5 = NULL;
        v6 = NULL;
        v3 += 0x160;
        v13 -= 0x160;
        if (v1 != NULL) {
            v7 = v1->mUnk_2c - v1->mProp.w.mUnk_04;
            if ((s32) FS_ReadFile(v1, v2, 0x160) < 0x160) {
                v13 = 0;
            }
            v9 = func_02008570_inline(v2);
        } else {
            v9 = func_02008570_inline((Unk02008570Header *) 0x027ffe00);
            v12 = TRUE;
            FS_InitFile(&v4);
            FS_OpenFileDirect(&v4, FS_FindArchive(data_usa_0216178c, 3), 0, v9 + 0x88, -1);
            v1 = &v4;
            v7 = v4.mUnk_2c - v4.mProp.w.mUnk_04;
            MI_CpuCopy8((const void *) 0x027ffe00, v2, 0x160);
            v2->mUnk_60 |= 0x00406000;
        }
        if (v13 >= 0x88) {
            FS_SeekFile(v1, v7 + v9, 0);
            FS_ReadFile(v1, v3, 0x88);
            v3 += 0x88;
            v13 -= 0x88;
        } else {
            v13 = 0;
        }
        if (v13 >= 0x70) {
            v5 = (Unk0200adfc *) v3;
            func_0200aea8((u32) v3);
            v3 += 0x70;
            v13 -= 0x70;
            func_0200ae60(v5, 0, 0x160, (u8 *) v2, 3);
            p = (s8 *) v1->mArc;
            v10 = 0;
            while (v10 < 3 && p[v10] != 0) {
                v10++;
            }
            MI_CpuCopy8(p, v5->mUnk_10, v10);
            v5->mUnk_14 = v10;
        } else {
            v13 = 0;
        }
        if (v13 >= 0x10) {
            v6 = (u32 *) v3;
            v6[0] = 0;
            v6[1] = v2->mUnk_20 + (v7 + v1->mProp.w.mUnk_04);
            v6[2] = v2->mUnk_30 + (v7 + v1->mProp.w.mUnk_04);
            v3 += 0x10;
            v13 -= 0x10;
        } else {
            v13 = 0;
        }
        v8 = v2->mUnk_2c + v2->mUnk_3c;
        if (v13 >= v8) {
            v10 = v1->mProp.w.mUnk_04;
            FS_SeekFile(v1, v6[1] - v10, 0);
            FS_ReadFile(v1, v3, v2->mUnk_2c);
            func_0200ae60(v5, v6[1], v2->mUnk_2c, v3, 3);
            v3 += v2->mUnk_2c;
            FS_SeekFile(v1, v6[2] - v10, 0);
            FS_ReadFile(v1, v3, v2->mUnk_3c);
            func_0200ae60(v5, v6[2], v2->mUnk_3c, v3, 3);
            v11 = TRUE;
        } else if (v13 >= 0xcc00) {
            v10 = v1->mProp.w.mUnk_04;
            v8 = v6[1];
            FS_SeekFile(v1, v8 - v10, 0);
            FS_ReadFile(v1, v3, 0x4400);
            func_0200ae60(v5, v8, 0x4400, v3, 3);
            FS_SeekFile(v1, v8 + 0x4400 - v10, 0);
            FS_ReadFile(v1, v3 + 0x4400, 0x4400);
            func_0200ae60(v5, v8 + 0x4400, 0x4400, (v3 + 0x4400), 2);
            FS_SeekFile(v1, v8 + 0x8800 - v10, 0);
            FS_ReadFile(v1, v3 + 0x8800, 0x4400);
            func_0200ae60(v5, v8 + 0x8800, 0x4400, (v3 + 0x8800), 2);
            v11 = TRUE;
        }
        FS_SeekFile(v1, v7, 0);
        if (v12 != FALSE) {
            FS_CloseFile(&v4);
            if (v11 != FALSE) {
                v6 = data_usa_02161788;
                v14[0] = v2->mUnk_20;
                v14[1] = v2->mUnk_28 - v2->mUnk_20;
                v14[2] = (u32) v5->mUnk_30[1].mUnk_08 - v2->mUnk_20;
                v14[3] = param_3;
                func_0200850c(v14, 0x4000, 0x8000, 1);
                while (((s32 *) v6)[1] != 0) {
                    func_0200850c(v14, v6[0], v6[0] + v6[1], 0);
                    v6 += 2;
                }
                v3 = v5->mUnk_30[1].mUnk_08;
                v3 += (u32) AutoloadCallback - v2->mUnk_28;
                *(u32 *) v3 = 0xe12fff1e;
            }
        }
        if (v11 != FALSE) {
            DC_FlushRange(v2, param_3);
        }
    }
    return v11;
}

#pragma thumb off
