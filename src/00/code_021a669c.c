#include "00/code_021a669c.h"
#include "ITCM/code_01ff8000.h"
#include "00/code_021a666c.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"
#include "code_02133274.h"
#include "os_thread.h"
#include "Main/Unknown/code_02000800.h"

void func_ov000_021a68dc(OSMutex *a) {
    if (a->mHolder == (struct OSThread *) func_01ff8000) {
        a->mLockCount--;
        if (a->mLockCount == 0) {
            a->mHolder = NULL;
            OS_WakeupThread(&a->mQueue);
        }
    }
}

void func_ov000_021a6894(void) {
    u32 v1;
    Unk021b5f50 *g;

    v1 = OS_DisableInterrupts();
    g = func_ov000_021a5b30();
    if (g == NULL) {
        OS_RestoreInterrupts(v1);
        return;
    }
    if (g->mUnk_2270 != NULL && (s32) g->mUnk_2274 > 0) {
        MI_CpuFill8(g->mUnk_2270, 0, g->mUnk_2274);
    }
    OS_RestoreInterrupts(v1);
}

u32 func_ov000_021a6844(void) {
    u32 v1;
    u32 r;
    Unk021b5f50 *g;

    v1 = OS_DisableInterrupts();
    g = func_ov000_021a5b30();
    r = 0;
    if (g == NULL) {
        OS_RestoreInterrupts(v1);
        return r;
    }
    if (g->mUnk_2270 != NULL && g->mUnk_2274 > 0xc) {
        r = g->mUnk_2270->mUnk_00;
    }
    OS_RestoreInterrupts(v1);
    return r;
}

u32 func_ov000_021a67dc(u32 a) {
    u32 v1;
    Unk021b5f50 *g;

    v1 = OS_DisableInterrupts();
    g = func_ov000_021a5b30();
    if (g == NULL) {
        OS_RestoreInterrupts(v1);
        return 0;
    }
    if (a != 0) {
        a = g->mUnk_226a != 0;
        g->mUnk_226a = 1;
    } else {
        a = g->mUnk_226a != 0;
        g->mUnk_226a = 0;
    }
    OS_RestoreInterrupts(v1);
    return a;
}

u8 *func_ov000_021a6788(u16 a) {
    u32 v1;
    Unk021b5f50_2270_0c *e;

    v1 = OS_DisableInterrupts();
    if (func_ov000_021a5b30() == NULL) {
        OS_RestoreInterrupts(v1);
        return NULL;
    }
    e = func_ov000_021a65d8(a);
    if (e == NULL) {
        OS_RestoreInterrupts(v1);
        return NULL;
    }
    OS_RestoreInterrupts(v1);
    return e->mUnk_10;
}

void func_ov000_021a671c(Unk021a5e84 *a, u16 b) {
    Unk021b5f50 *g;
    Unk021b5f50_2270_0c *e;

    g = func_ov000_021a5b30();
    if (g != NULL && g->mUnk_226a == 0 && a->mUnk_3c == 0) {
        e = func_ov000_021a6614(a->mUnk_04);
        if (e == NULL) {
            e = func_ov000_021a669c();
        }
        if (e == NULL && g->mUnk_2278 == 1) {
            e = func_ov000_021a666c();
        }
        if (e != NULL) {
            e->mUnk_02 = b;
            MIi_CpuCopyFast(a, e->mUnk_10, 0xc0);
            func_ov000_021a6558(e);
        }
    }
}

Unk021b5f50_2270_0c *func_ov000_021a669c(void) {
    Unk021b5f50 *g;
    Unk021b5f50_2270 *l;
    Unk021b5f50_2270_0c *e;
    u32 n;
    s32 i;

    g = func_ov000_021a5b30();
    l = g->mUnk_2270;
    e = NULL;
    if (l != NULL && g->mUnk_2274 > 0xc) {
        n = (g->mUnk_2274 - 0xc) / 0xd0;
        if (n != 0 && n > l->mUnk_00) {
            for (i = 0; i < n; i++) {
                e = &l->mUnk_0c[(u32) i];
                if (e->mUnk_00 == 0) {
                    break;
                }
            }
            if (i < n) {
                e->mUnk_00 = 1;
                e->mUnk_04 = l->mUnk_00;
                e->mUnk_0c = NULL;
                e->mUnk_08 = l->mUnk_08;
                l->mUnk_08 = e;
                if (e->mUnk_08 != NULL) {
                    e->mUnk_08->mUnk_0c = e;
                } else {
                    l->mUnk_04 = e;
                }
                l->mUnk_00++;
            }
        }
    }
    return e;
}
