#include "Main/Unknown/code_020483e4.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02048000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0217a000.h"

#include "code_0200d118.h"
#include "code_02003be0.h"
#include "code_02004dc0.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_02004d80.h"
#include "code_0200eddc.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_020487a0.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/unk_02175000.h"

#pragma thumb on

void func_020486d4(void *a) {
    s32 i;

    data_021759c8 = HeapAlloc(a, 0xa84);
    data_021759c8->mUnk_8c8.mUnk_88 = HeapAllocAligned(a, 0x400, 0x20);
    for (i = 0; i < 20; i++) {
        data_021759c8->mUnk_00[i].mLoaded = 0;
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        data_021759c8->mUnk_8c0 = FS_TryLoadTable(0, 0);
        data_021759c8->mUnk_8c4 = HeapAlloc(a, data_021759c8->mUnk_8c0);
        FS_TryLoadTable((u32) data_021759c8->mUnk_8c4, data_021759c8->mUnk_8c0);
    }
    for (i = 0; i < 16; i++) {
        func_020487a0(i);
    }
    data_021759c8->mUnk_a70 = NULL;
    data_021759c8->mUnk_a78 = NULL;
    data_021759c8->mUnk_a7c = NULL;
    FS_InitFile(&data_021759c8->mUnk_968);
}

int func_02048684(const char *a, void *b, u32 c) {
    Unk02003024 f;
    u32 r;
    u32 n;

    FS_InitFile(&f);
    r = FS_OpenFile(&f, (const u8 *) a);
    if (r != 0) {
        n = f.mUnk_20.p.mUnk_08 - f.mUnk_20.p.mUnk_04;
        if (c != 0 && n > c) {
            r = 0;
        } else {
            if (FS_ReadFile(&f, b, n) < 0) {
                r = 0;
            }
            FS_CloseFile(&f);
        }
    }
    return r;
}

u32 func_0204863c(void *a, void *b, u32 c) {
    Unk02003024 f;
    u32 r;

    FS_InitFile(&f);
    r = FS_OpenFile(&f, a);
    if (r != 0) {
        if (c <= (u32) (f.mUnk_20.p.mUnk_08 - f.mUnk_20.p.mUnk_04)) {
            if (FS_ReadFile(&f, b, c) < 0) {
                r = 0;
            }
            FS_CloseFile(&f);
        }
    }
    return r;
}

u32 func_02048590(char *a, void *b, void **c) {
    u32 s;
    Unk02003024 *p;
    u32 n;
    void *t;

    p = &data_021759c8->mUnk_968;
    if (((p->mUnk_0c & 1) ? 1 : 0) != 0) {
        return 0;
    }
    if (((p->mUnk_0c & 0x10) ? 1 : 0) != 0) {
        FS_CloseFile(p);
    }
    s = FS_OpenFile(p, (const u8 *) a);
    if (s != 0) {
        n = p->mUnk_20.p.mUnk_08 - p->mUnk_20.p.mUnk_04;
        t = HeapAlloc(b, n);
        *c = t;
        if (t == NULL) {
            s = 0;
        }
        if (s != 0) {
            if (FS_ReadFile(p, t, n) < 0) {
                s = 0;
                HeapFree(b, t);
            }
        }
        FS_CloseFile(p);
    }
    if (s == 0) {
        n = -1;
        *c = NULL;
    }
    return n;
}

void *func_02048504(const char *a, s32 b) {
    Unk02003024 f;
    u32 s;
    void *r;
    u32 n;

    r = NULL;
    if (FS_IsAvailable() == 0) {
        return NULL;
    }
    FS_InitFile(&f);
    s = FS_OpenFile(&f, (const u8 *) a);
    if (s != 0) {
        n = f.mUnk_20.p.mUnk_08 - f.mUnk_20.p.mUnk_04;
        r = HeapAllocAligned(GetHeap(func_020364e8()), n, b);
        func_0200ee58(r, n);
        if (r == NULL) {
            s = 0;
        } else {
            if (FS_ReadFile(&f, r, n) < 0) {
                HeapFree(GetHeap(func_020364e8()), r);
                s = 0;
            }
            FS_CloseFile(&f);
        }
    }
    if (s == 0) {
        r = NULL;
    }
    return r;
}

void func_02048498(char *a, s32 b, s32 c) {
    BOOL d;
    const char *e;
    const char *f;

    d = FALSE;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2 && data_usa_02154228[b].mUnk_04 == 1) {
        d = TRUE;
    }
    if (c != 0) {
        e = data_usa_02165164;
    } else {
        e = data_usa_02165168;
    }
    if (d != FALSE) {
        f = data_usa_0216516c;
    } else {
        f = data_usa_02165170;
    }
    StringFormatBounded(a, 0x80, data_usa_02165174, data_usa_02154228[b].mUnk_00, f, e);
}

u32 func_02048474(void) {
    s32 a;

    a = data_021759d0->mUnk_04;
    if (data_021759d0->mUnk_00 == 2 && a == 1) {
        a += 5;
    }
    return ((u32 *) data_02164dc8)[a];
}

#pragma thumb off

#pragma thumb on

u32 func_02048440(void) {
    u32 v1;
    v1 = data_0217aa00->mUnk_043c;
    if ((data_021759d0->mUnk_00 == 2) && (((s32 *) data_021759d0)[1] == 1)) {
        v1 = v1 + 5;
    }
    return ((u32 *) &data_02164dc8)[v1];
}

void func_0204840c(char *a, u8 *b) {
    u32 v1;
    if (*b != 0) {
        v1 = func_02048474();
        StringFormatBounded(a, 0x80, data_02165148, b, v1, (u32) &data_0216515c);
    }
}

void func_020483e4(char *a, u8 *b) {
    if (*b != 0) {
        StringFormatBounded(a, 0x80, data_0216512c, b, (u32) &data_02165140);
    }
}

#pragma thumb off
