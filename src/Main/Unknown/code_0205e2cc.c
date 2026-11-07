#include "Main/Unknown/code_0205e2cc.h"
#include "Main/Unknown/code_0202dd9c.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02057764.h"
#include "Main/Unknown/code_0202d000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02042064.h"
#include "Main/Unknown/code_020431cc.h"
#include "Main/Unknown/code_02057304.h"
#include "Main/Unknown/code_020574c8.h"
#include "Main/Unknown/code_02057000.h"
#include "Main/Unknown/code_02057ca4.h"
#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/code_020576b8.h"
#include "Main/Unknown/code_02060c68.h"
#include "Main/Unknown/code_0212030c.h"
#include "Main/Unknown/code_0214d000.h"
#include "00/code_0219b580.h"
#include "code_021458c4.h"
#include "code_02147cd8.h"
#include "code_0214d018.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "00/code_021832d8.h"
#include "01/code_021956dc.h"

#pragma opt_rebuildconditionals off

EmblemBlock *CreateEmblemBlock(void *a) {
    EmblemBlock *p = HeapAlloc(a, 0xb04);
    if (p != NULL) {
        p->mBlockIndex = -1;
    }
    return p;
}

BOOL CopyEmblemFromBlock(EmblemBlock *a, u8 b, EmblemData *c) {
    BuddyRecord e;
    u8 d;
    u8 m;
    d = b / 5;
    m = b % 5;
    if (d != a->mBlockIndex) {
        return FALSE;
    }
    MI_CpuCopy8(&data_0217aa08->mBuddyRecordBlock->mRecords[b], &e, 0x24);
    if (e.mFilled == 0 || e.mUnk_22_2 == 0) {
        return FALSE;
    }
    c->mUnk_200 = (a->mUnk_04.mUnk_004 & (1 << m)) != 0;
    if (c->mUnk_200 != 0) {
        MI_CpuCopy8(a->mUnk_04.mUnk_008[m], c, 0x200);
    }
    return TRUE;
}

void SetupEmblemBlock(EmblemBlock *a, u8 b) {
    u8 c = b / 5;
    if (func_0205743c(c, &data_0217aa08->mUnk_00->mUnk_2c[2], 2) == 0) {
        a->mBlockIndex = -1;
        return;
    }
    if (c == a->mBlockIndex) {
        return;
    }
    func_020576b8(&a->mUnk_04, c);
    a->mBlockIndex = c;
}

void CopyOtherPlayerEmblemsToBlocks(void) {
    u8 i;
    u16 j;
    Unk0217aa00_45c *e;
    u8 c[12];
    s8 d[8];
    Unk0217aa08_24 *r;
    s32 v1;
    s32 v2;
    u16 k;
    s32 m;
    BOOL f = FALSE;
    s32 t;
    u8 x;
    for (i = 0; i < 12; i++) {
        c[i] = 0;
    }
    for (j = 0; j < 8; j++) {
        d[j] = -1;
        if (data_0217aa00->mUnk_0000 == 2) {
            m = data_0217aa00->mUnk_0432;
        } else {
            m = 0;
        }
        if (j != (u16) m) {
            if ((data_0217aa00->mUnk_0457 & (1 << data_0217aa00->mUnk_1e8c[j])) == 0) {
                if ((data_0217aa00->mUnk_15f6 & (1 << j)) != 0) {
                    e = &data_0217aa00->mUnk_045c[j];
                    t = func_02060c68(e, 1);
                    if (t != -1) {
                        if (e->mUnk_214 != 0) {
                            d[j] = t;
                            c[t / 5] = 1;
                        }
                    }
                }
            }
        }
    }
    func_020577b4(data_0217aa08->mBuddyRecordBlock);
    if (data_021759d4->mUnk_0c != 0) {
        CARD_WaitBackupAsync();
    }
    for (i = 0; i < 12; i++) {
        if (c[i] != 0) {
            r = data_0217aa08->mUnk_24;
            if (func_0205743c(i, &data_0217aa08->mUnk_00->mUnk_2c[2], 2) != 0) {
                func_020576b8(r, i);
                if (data_021759d4->mUnk_0c != 0) {
                    CARD_WaitBackupAsync();
                }
            } else {
                MI_CpuFill8(r, 0, 0xb00);
                func_0205746c(i, &data_0217aa08->mUnk_00->mUnk_2c[2], 2);
                f = TRUE;
            }
            v1 = i * 5;
            v2 = (i + 1) * 5;
            for (k = 0; k < 8; k++) {
                t = d[k];
                if (t >= v1 && t < v2) {
                    x = t % 5;
                    r->mUnk_004 |= 1 << x;
                    MI_CpuCopy8((u8 *) &data_0217aa00->mUnk_045c[k] + 0x14, r->mUnk_008[x], 0x200);
                }
            }
            func_02057710(r, i);
            if (data_021759d4->mUnk_0c != 0) {
                CARD_WaitBackupAsync();
            }
        }
    }
    if (f != FALSE) {
        func_02057ca4(data_0217aa08->mUnk_00);
        if (data_021759d4->mUnk_0c != 0) {
            CARD_WaitBackupAsync();
        }
    }
    func_02057504();
}

void CopyWiFiOtherEmblemsToBlocks(void) {
    u8 i;
    u16 j;
    Unk0217aa00_45c *e;
    u8 c[12];
    s8 d[4];
    Unk0217aa08_24 *r;
    s32 v1;
    s32 v2;
    u8 x;
    u16 k;
    u8 *q;
    s32 t;
    for (i = 0; i < 12; i++) {
        c[i] = 0;
    }
    for (j = 0; j < 4; j++) {
        d[j] = -1;
        if (j != func_ov000_0219bb50()) {
            e = GetWiFiSessionPlayerRecordData(j & 0xff);
            if (e != NULL) {
                t = func_02060c68(e, 0);
                if (t != -1) {
                    if (e->mUnk_214 != 0) {
                        d[j] = t;
                        c[t / 5] = 1;
                    }
                }
            }
        }
    }
    func_020577b4(data_0217aa08->mBuddyRecordBlock);
    if (data_021759d4->mUnk_0c != 0) {
        CARD_WaitBackupAsync();
    }
    for (i = 0; i < 12; i++) {
        if (c[i] != 0) {
            r = data_0217aa08->mUnk_24;
            if (func_0205743c(i, &data_0217aa08->mUnk_00->mUnk_2c[2], 2) != 0) {
                func_020576b8(r, i);
                if (data_021759d4->mUnk_0c != 0) {
                    CARD_WaitBackupAsync();
                }
            } else {
                MI_CpuFill8(r, 0, 0xb00);
                func_0205746c(i, &data_0217aa08->mUnk_00->mUnk_2c[2], 2);
            }
            v1 = i * 5;
            v2 = (i + 1) * 5;
            q = (u8 *) r + 4;
            for (k = 0; k < 4; k++) {
                t = d[k];
                if (t >= v1 && t < v2) {
                    x = t % 5;
                    *q = *q | (1 << x);
                    MI_CpuCopy8((u8 *) GetWiFiSessionPlayerRecordData(k & 0xff) + 0x14, r->mUnk_008[x], 0x200);
                }
            }
            func_02057710(r, i);
            if (data_021759d4->mUnk_0c != 0) {
                CARD_WaitBackupAsync();
            }
        }
    }
    func_02057504();
}

static inline s32 func_0205e5c4_inline(void) {
    if (data_0217aa00 == NULL) {
        return 0;
    }
    return data_0217aa00->mUnk_0000;
}

void func_0205e5c4(s32 a) {
    void (*f)(void);
    BOOL c;
    s32 d;
    if (a != 0) {
        c = FALSE;
        d = func_0205e5c4_inline();
        if (d != 0) {
            if (data_0217aa00->mUnk_0004 != 13) {
                c = TRUE;
            }
        }
        if (c == FALSE) {
            return;
        }
        f = CopyOtherPlayerEmblemsToBlocks;
    } else {
        d = 0;
        if (gWiFiSession != NULL) {
            if (gWiFiSession->mHeapCreated != FALSE) {
                d = 1;
            }
        }
        if (d == 0) {
            return;
        }
        f = CopyWiFiOtherEmblemsToBlocks;
    }
    func_02057514();
    func_02057df0(f);
    data_0217aa0c->mUnk_f8 = 1;
}

static inline u8 func_0205e548_inline(void *a) {
    u8 n = 0;
    u8 i = 0;
    do {
        if (a != 0) {
            MI_CpuCopy8(&data_0217aa08->mBuddyRecordBlock->mRecords[i], a, 0x24);
        }
        if (data_0217aa08->mBuddyRecordBlock->mRecords[i].mFilled != 0) {
            n = n + 1;
        }
        i = i + 1;
    } while (i < 60);
    return n;
}

u8 CountEmblemEntries(void) {
    return func_0205e548_inline(0);
}

#pragma thumb on

void func_0205e530(void) {
    func_0202dfd4(GetHeap(GetCurrentHeapCall()));
}

void func_0205e528(void) {
    func_0202defc();
}

void func_0205e520(void) {
    func_0202dec8();
}

void func_0205e518(u32 a) {
    func_0202df34(a);
}

s32 RunGhostScene(SceneNumbers *a) {
    SceneCallbacks b = data_021653c0;

    RunScene(a, &b);
    return 0;
}

#pragma thumb off

static inline s32 func_0205e2cc_inline(s32 a, s32 b) {
    return ((s64) a * b + 0x800) >> 12;
}

void func_0205e2cc(void *a) {
    u16 n;
    u16 i;
    u16 k;
    u16 j;
    u16 m;
    CourseMapShape *p;
    Unk0217aa24_00 *e;
    s32 u;
    s32 v;
    s32 w;
    s32 y;
    n = gCourseMap->mShapeCount;
    m = 0;
    data_0217aa24 = HeapAlloc(a, 8);
    for (i = 0; i < n; i++) {
        if (GetCourseMapShape(i)->mKind == 5) {
            m = m + 1;
        }
    }
    if (m != 0) {
        data_0217aa24->mUnk_00 = HeapAlloc(a, m * 0xc);
    }
    k = 0;
    data_0217aa24->mUnk_04 = m;
    for (j = 0; j < n; j++) {
        p = GetCourseMapShape(j);
        if (p->mKind == 5) {
            e = &data_0217aa24->mUnk_00[k];
            e->mUnk_00 = j;
            u = 0;
            switch (p->mShapeKind) {
                case 0:
                    u = func_0205e2cc_inline(func_020431cc(), p->mUnk_0c.x);
                    v = func_0205e2cc_inline(func_020431d4(), p->mUnk_0c.y) >> 1;
                    y = func_0205e2cc_inline(func_020431cc(), p->mUnk_0c.z);
                    w = func_0205e2cc_inline(u, u) + func_0205e2cc_inline(v, v);
                    y = func_0205e2cc_inline(y, y);
                    u = FX_Sqrt(y + w);
                    break;
                case 1:
                    u = func_0205e2cc_inline(func_020431dc(), p->mUnk_0c.x);
                    break;
            }
            e->mUnk_04 = u;
            e->mUnk_09 = 0;
            e->mUnk_08 = 0;
            k = k + 1;
        }
    }
}
