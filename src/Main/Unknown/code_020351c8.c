#include "Main/Unknown/code_020351c8.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/code_02126000.h"

#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"

#pragma thumb on

void func_02035378(void) {
    void *v1;
    v1 = GetBmgEntry((void *) data_02174e64->mUnk_088, 1);
    func_0212658c(v1, (u32) 0, (u32) 0, (u32) 0, (u32) 0, (u32) 0, (u32) 0);
}

#pragma thumb off

#pragma thumb on

void func_020352fc(s32 a) {
    BOOL f;
    s32 c;
    s32 i;
    Unk02174e64 *p;

    f = FALSE;
    p = data_02174e64;
    c = p->mUnk_080;
    i = c - 1;
    if (i < 0) {
        if (a == 0) {
            return;
        }
        i = 3;
    }
    if (i != c) {
        do {
            if (p->mUnk_09c[i].mUnk_28 == 1 && p->mUnk_09c[i].mUnk_2c.mUnk_00 == 1) {
                f = TRUE;
                p->mUnk_080 = i;
                break;
            }
            i--;
            if (i < 0) {
                if (a == 0) {
                    return;
                }
                i = 3;
            }
        } while (i != p->mUnk_080);
    }
    if (f != FALSE) {
        func_0212ecc0(&data_0217d068, 0, 0);
    }
}

void func_02035280(s32 a) {
    BOOL f;
    s32 c;
    s32 i;
    Unk02174e64 *p;

    f = FALSE;
    p = data_02174e64;
    c = p->mUnk_080;
    i = c + 1;
    if (i >= 4) {
        if (a == 0) {
            return;
        }
        i = 0;
    }
    if (i != c) {
        do {
            if (p->mUnk_09c[i].mUnk_28 == 1 && p->mUnk_09c[i].mUnk_2c.mUnk_00 == 1) {
                f = TRUE;
                p->mUnk_080 = i;
                break;
            }
            i++;
            if (i >= 4) {
                if (a == 0) {
                    return;
                }
                i = 0;
            }
        } while (i != p->mUnk_080);
    }
    if (f != FALSE) {
        func_0212ecc0(&data_0217d068, 0, 0);
    }
}

void func_02035228(s32 a) {
    Unk02174e14_00 *q;
    s32 m;
    s32 w;
    s32 v;

    q = &data_02174e64->mUnk_02c[1];
    m = data_02174e64->mUnk_080;
    w = m + 4;
    if (a != 0) {
        v = 0xe;
    } else {
        v = 0xf;
    }
    q->mUnk_18[4].mUnk_00 = a;
    func_02124100(w, v, q->mUnk_14, q->mUnk_18, q->mUnk_0c);
    func_02124100(m, v, q->mUnk_14, q->mUnk_18, q->mUnk_0c);
}

#pragma thumb off

#pragma thumb on

void func_020351c8(void) {
    u32 v1;
    u32 v2;
    u32 v3;
    v1 = ((s32) GetBmgEntry(data_02174e64->mUnk_088, 8));
    v2 = ((s32) GetBmgEntry(data_02174e64->mUnk_084, 0));
    v3 = ((s32) GetBmgEntry(data_02174e64->mUnk_084, 1));
    func_02125ed0(0, (u32) 5);
    func_02125fd4(v1, v2, v3, (u32) 0, (u32) 0, (u32) 1, (u32) 1, (u32) 0);
}

#pragma thumb off
