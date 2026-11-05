#include "Main/Unknown/code_0204f644.h"
#include "Main/Unknown/code_02036820.h"
#include "code_02003be0.h"
#include "code_02004d80.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"

#pragma thumb on

void func_0204f770(void) {
    s16 m = data_0217aa00->mUnk_1d08 - 1;
    u32 v1 = *data_0217aa00->mUnk_16a0[m].mUnk_74 >> 8;
    void *v2 = data_0217aa00->mUnk_16a0[m].mUnk_78;
    if (v2 == NULL) {
        v2 = HeapAllocAligned(data_0217aa00->mUnk_16a0[m].mUnk_80, v1, 0x20);
        *data_0217aa00->mUnk_16a0[m].mUnk_7c = v2;
    }
    ExpandCompressed(data_0217aa00->mUnk_16a0[m].mUnk_74, v2);
    data_0217aa00->mUnk_16a0[m].mUnk_84_29 = 0;
}

BOOL func_0204f644(void) {
    u16 n = data_0217aa00->mUnk_1d08;
    s16 m = n - 1;
    Unk02003024 *p = &data_0217aa00->mUnk_1d0c;
    void *q;
    s32 v1;
    u32 *v2;
    if (((p->mUnk_0c & 1) ? 1 : 0) != 0) {
        return FALSE;
    }
    if (m >= 0 && data_0217aa00->mUnk_16a0[m].mUnk_84_29 != 0) {
        if (data_0217aa0c->mUnk_f8 != 0) {
            return FALSE;
        }
        func_02057df0(func_0204f770);
        data_0217aa0c->mUnk_f8 = 1;
        return FALSE;
    }
    if (n >= 12 || data_0217aa00->mUnk_16a0[n].mUnk_34 == 0) {
        return TRUE;
    }
    q = &data_0217aa00->mUnk_16a0[n].mUnk_34;
    if (((p->mUnk_0c & 0x10) ? 1 : 0) != 0) {
        FS_CloseFile(p);
    }
    FS_InitFile(p);
    if (FS_OpenFile(p, q) != 0) {
        q = data_0217aa00;
        v1 = p->mUnk_20.p.mUnk_08 - p->mUnk_20.p.mUnk_04;
        v2 = ((Unk0217aa00 *) q)->mUnk_16a0[n].mUnk_74;
        if (v2 == NULL) {
            v2 = HeapAllocAligned(data_0217aa00->mUnk_16a0[n].mUnk_80, v1, 0x20);
            *data_0217aa00->mUnk_16a0[n].mUnk_7c = v2;
        }
        FS_ReadFileAsync(p, v2, v1);
        data_0217aa00->mUnk_1d08++;
    }
    return FALSE;
}

#pragma thumb off
