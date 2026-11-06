#include "Main/Unknown/code_020f813c.h"

#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020f7c90.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f81c0.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020bb5cc.h"
#include "Main/Unknown/code_020f82c4.h"
#include "Main/Unknown/code_02059bc0.h"
#include "Main/Unknown/code_0205a548.h"
#include "Main/Unknown/code_0205a000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02079b40.h"
#include "Main/Unknown/code_020be930.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_020f9c6c.h"

static inline u32 func_020f8a04_inline(Unk020f41c4_B *b, u32 c) {
    b->mUnk_00 = b->mUnk_08 * b->mUnk_00 + b->mUnk_10;
    if (c == 0) {
        return b->mUnk_00 >> 32;
    } else {
        return ((b->mUnk_00 >> 32) * c) >> 32;
    }
}

s32 PickItem(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6) {
    ItemSlotTable *q;
    Unk020f41c4_B *b;
    u16 *row;
    s32 m;
    s32 i;
    u16 acc;
    s32 j;
    s32 x;
    s32 sel;
    s32 t;
    u16 k;
    s32 n;
    enum { K0 } u;

    sel = 0x13;
    if (param_2 != 0) {
        param_3 = (u16) (param_2 - 1);
        m = 0;
        q = &data_0217bc74;
    } else {
        q = param_4 != 0 ? &data_0217bc6c : &data_0217bc64;
        param_3 = (u16) (param_3 - 1);
        m = param_1;
    }
    row = q->mRows[param_3];
    acc = 0;
    t = 0;
    if (data_021759c0->mMode != MODE_MISSION_RUN) {
        for (i = 0; i < 0xe; i++) {
            t += (u16) (gItemKinds[(s32) i].mUnk_90 *
                        (gItemPools[(s32) i].mReservedCount - gItemPools[(s32) i].mUnk_18));
        }
    }
    for (j = 0; j < param_6; j++) {
        n = gItemInfos[(s32) j].mObjectKind;
        if (!((j == 8 && data_0217bc60 > 0) || (j == 7 && data_0217bc5c > 0) || (j == 0xf && data_0217bc58 > 0))) {
            if (gItemPools[n].mLimit - gItemPools[n].mReservedCount > 0 && gItemInfos[(s32) j].mEnabled != FALSE) {
                x = gItemKinds[n].mUnk_90 * gItemInfos[(s32) j].mObjectCount;
                if (x == 0 || x + t <= 0x28) {
                    if (j >= 9 && m != 0) {
                        if (m == 1) {
                            acc = acc + (row[j] >> 2);
                        } else {
                            acc = 3 * row[j] + acc;
                        }
                    } else {
                        acc = acc + row[j];
                    }
                }
            }
        }
        data_0217bc7c[j] = acc;
    }
    b = &gRaceProgress->mRandom;
    if (acc == 0) {
        x = 0;
    } else {
        x = func_020f8a04_inline(b, acc);
    }
    k = x;
    for (j = 0; j < param_6; j++) {
        if (k < data_0217bc7c[j]) {
            sel = j;
            break;
        }
    }
    if (func_020fab34(&sel) != FALSE) {
        func_020faa78(sel);
    }
    if (param_5 != 0) {
        if (param_2 != 0) {
            gItemSlotSpinItemCount = 0;
            for (u = 0; u < param_6; u++) {
                if (u == sel || row[u] != 0) {
                    gItemSlotSpinItems[gItemSlotSpinItemCount++] = u;
                }
            }
        } else {
            gItemSlotSpinItemCount = 0;
        }
    }
    return sel;
}

void InitItemSlot(KartItems *param_1, KartItems *param_2) {
    param_1->mSelf = param_2;
    param_1->mSlotState = 0;
    param_1->mSlotFrames = 0;
    param_1->mSlotShownItem = 0x13;
    param_1->mSlotResult = 0x13;
    param_1->mActiveItem = 0x13;
    param_1->mUnk_020 = FALSE;
    param_1->mUnk_024 = data_021759c0->mCurrentEntries[param_2->mKartIndex].mPlayer.mKind == 3;
}

void StartItemSlot(KartItems *param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5) {
    KartItems *p;
    ItemInfo *e;
    ItemPool *v;
    enum { K0 } k, j;
    BOOL a;
    BOOL b;

    p = param_1->mSelf;
    a = data_021759c0->mMode == 5;
    if (param_1->mSlotState != 0) {
        return;
    }
    if (param_1->mActiveItem != 0x13) {
        return;
    }
    param_1->mSlotState = 1;
    param_1->mSlotShownItem = 0x13;
    if (!a) {
        func_020be930(param_1->mSelf->mKartIndex);
    }
    if (a) {
        param_1->mUnk_01c = FALSE;
        param_1->mSlotFrames = 0;
        param_1->mSlotFrameCount = 0x85;
        param_1->mUnk_028 = 0x10;
        param_1->mUnk_02c = 4;
    } else if (param_5 != 0) {
        param_1->mUnk_01c = TRUE;
        param_1->mSlotFrames = 0x4d;
        param_1->mSlotFrameCount = 0x65;
        param_1->mUnk_028 = 8;
        param_1->mUnk_02c = 3;
    } else {
        param_1->mUnk_01c = FALSE;
        param_1->mSlotFrames = 0;
        param_1->mSlotFrameCount = 0xd5;
        param_1->mUnk_028 = 0x10;
        param_1->mUnk_02c = 4;
    }
    b = p->mKartIndex == data_021759c0->mEntryIndex;
    if (p->mItemInUse.mUnk_000 != 0xf && p->mItemInUse.mUnk_004 >= 9) {
        param_1->mSlotResult = PickItem(0, param_2, param_3, param_4, b, 9);
    } else {
        param_1->mSlotResult = PickItem(func_02079b40(p->mKartIndex), param_2, param_3, param_4, b, 0x12);
    }
    if (a) {
        func_0205a750(param_1->mSlotResult);
        param_1->mUnk_020 = TRUE;
        return;
    }
    k = param_1->mSlotResult;
    e = &gItemInfos[k];
    j = e->mObjectKind;
    v = &gItemPools[j];
    v->mReservedCount += e->mObjectCount;
}

void func_020f86c4(KartItems *param_1) {
    KartItems *p;
    ItemInfo *e;
    ItemPool *v;
    enum { K0 } k, j;

    p = param_1->mSelf;
    if (p->mActiveItem != 0x13) {
        p->mActiveItem = 0x13;
    }
    if (param_1->mSlotState != 0) {
        if (p->mUnk_020 == FALSE) {
            k = p->mSlotResult;
            e = &gItemInfos[k];
            j = e->mObjectKind;
            v = &gItemPools[j];
            v->mReservedCount -= e->mObjectCount;
        }
        p->mSlotState = 0;
        p->mSlotFrames = 0;
        p->mSlotShownItem = 0x13;
        p->mSlotResult = 0x13;
        p->mActiveItem = 0x13;
        p->mUnk_020 = FALSE;
    } else {
        if (p->mHeldItem.mUnk_00 != 0x13) {
            func_020f45f0(&p->mHeldItem, 1);
        }
    }
    param_1->mSlotState = 1;
    param_1->mSlotFrames = 0;
    param_1->mSlotFrameCount = 0x85;
    param_1->mSlotShownItem = 0x13;
    param_1->mActiveItem = 0x13;
    param_1->mSlotResult = 0x13;
    param_1->mUnk_020 = TRUE;
}

BOOL UpdateItemSlot(KartItems *param_1, KartItems *param_2) {
    ItemInfo *e;
    ItemPool *v;
    enum { K0 } j;
    s32 a;
    u32 b;

    switch (param_1->mSlotState) {
        case 1:
            param_1->mSlotFrames++;
            a = data_021759c0->mMode;
            if (a == 5 && param_1->mUnk_020 != FALSE) {
                b = param_2->mKartIndex & 0xff;
                if (func_0205a310(((u8 *) data_0217aa18)[b]) == 0) {
                    b = func_0205a2ac(((u8 *) data_0217aa18)[b]);
                    if (func_020faca4(b) != FALSE) {
                        func_020faa78(b);
                    }
                    e = &gItemInfos[b];
                    j = e->mObjectKind;
                    v = &gItemPools[j];
                    v->mReservedCount += e->mObjectCount;
                    param_1->mSlotResult = b;
                    param_1->mUnk_020 = FALSE;
                    param_1->mSlotFrameCount += param_1->mSlotFrames - 0x6f;
                } else if (param_1->mSlotFrames > 0x6e) {
                    param_1->mSlotFrames = 0x67;
                }
                return FALSE;
            }
            if (param_1->mSlotFrames > 0x3c &&
                (((param_2->mFlags & 0x241) == 0x241 && a != 5 && param_1->mUnk_01c == FALSE) ||
                 param_1->mSlotFrames > param_1->mSlotFrameCount)) {
                param_1->mSlotFrames = 0;
                param_1->mSlotState = 2;
            }
            break;
        case 2:
            param_1->mSlotFrames++;
            if (param_1->mSlotFrames > param_1->mUnk_028 * 2) {
                return TRUE;
            }
            break;
    }
    return FALSE;
}

void FinishItemSlot(KartItems *param_1) {
    ItemInfo *e;
    ItemPool *v;
    enum { K0 } k, j;

    k = param_1->mSlotResult;
    e = &gItemInfos[k];
    j = e->mObjectKind;
    v = &gItemPools[j];
    v->mReservedCount -= e->mObjectCount;
    param_1->mSlotState = 0;
    param_1->mSlotFrames = 0;
    param_1->mSlotShownItem = 0x13;
    param_1->mSlotResult = 0x13;
    param_1->mActiveItem = 0x13;
    param_1->mUnk_020 = FALSE;
}

void StopItemSlot(KartItems *param_1) {
    ItemInfo *e;
    ItemPool *v;
    enum { K0 } k, j;

    if (param_1->mUnk_020 == FALSE) {
        k = param_1->mSlotResult;
        e = &gItemInfos[k];
        j = e->mObjectKind;
        v = &gItemPools[j];
        v->mReservedCount -= e->mObjectCount;
    }
    param_1->mSlotState = 0;
    param_1->mSlotFrames = 0;
    param_1->mSlotShownItem = 0x13;
    param_1->mSlotResult = 0x13;
    param_1->mActiveItem = 0x13;
    param_1->mUnk_020 = FALSE;
}

static inline u16 func_020f830c_inline(Unk020f41c4_B *b, u32 n) {
    u32 t;
    if (n == 0) {
        t = 0;
    } else {
        b->mUnk_00 = b->mUnk_08 * b->mUnk_00 + b->mUnk_10;
        if (n == 0) {
            t = b->mUnk_00 >> 32;
        } else {
            t = ((b->mUnk_00 >> 32) * n) >> 32;
        }
    }
    return t;
}

void PickItemSlotShownItem(KartItems *param_1) {
    Unk020f41c4_B *b;
    s32 *q;
    u16 n;
    u32 i;

    switch (param_1->mSlotState) {
        case 0:
            return;
        case 1:
            if (gItemSlotSpinItemCount != 0) {
                n = gItemSlotSpinItemCount;
                q = gItemSlotSpinItems;
            } else {
                n = gItemSlotPossibleItemCount;
                q = gItemSlotPossibleItems;
            }
            b = &gRaceProgress->mLocalRandom;
            i = func_020f830c_inline(b, n);
            if (param_1->mSlotShownItem == q[i]) {
                i = (u16) (i + 1);
                if (i >= n) {
                    i = 0;
                }
            }
            param_1->mSlotShownItem = q[i];
            break;
        case 2:
            param_1->mSlotShownItem = param_1->mSlotResult;
            break;
    }
}

void func_020f82e8(s32 a) {
    data_0217bc60 = 1800;
    if (a != 0) {
        data_0217bc60 += 300;
    }
}

void func_020f82c4(s32 a) {
    data_0217bc5c = 1800;
    if (a != 0) {
        data_0217bc5c += 300;
    }
}

void func_020f82a4(s32 a) {
    data_0217bc58 = 0x384;
    if (a != 0) {
        data_0217bc58 += 0x12c;
    }
}

void func_020f8258(void) {
    if (data_0217bc60 > 0) {
        data_0217bc60 = data_0217bc60 - 1;
    }
    if (data_0217bc5c > 0) {
        data_0217bc5c = data_0217bc5c - 1;
    }
    if (data_0217bc58 > 0) {
        data_0217bc58 = data_0217bc58 - 1;
    }
}

void func_020f81c0(KartItems *a) {
    ItemInfo *e;
    ItemPool *v;
    enum { K0 } k, j;

    if (a->mSelf->mKartIndex == data_021759c0->mEntryIndex) {
        func_020bb5cc();
    }
    k = a->mSlotResult;
    e = &gItemInfos[k];
    j = e->mObjectKind;
    v = &gItemPools[j];
    v->mReservedCount -= e->mObjectCount;
    a->mSlotState = 0;
    a->mSlotFrames = 0;
    a->mSlotShownItem = 0x13;
    a->mSlotResult = 0x13;
    a->mActiveItem = 0x13;
    a->mUnk_020 = FALSE;
}

void SetActiveItem(KartItems *p0, u32 p1) {
    p0->mActiveItem = p1;
}

#pragma thumb on

u8 *LoadItemSlotTableData(ItemSlotTable *param_1, u8 *param_2) {
    s32 a;
    s32 b;
    s32 i;
    s32 j;
    u16(*tab)[0x12];

    a = *param_2++;
    b = *param_2++;
    param_1->mRowCount = a;
    param_1->mRows = HeapAlloc(GetHeap(func_020364e8()), (a + 1) * 0x24);
    tab = param_1->mRows;
    for (i = 0; i < b; i++) {
        for (j = 0; j < a; j++) {
            tab[j][i] = *param_2++;
        }
        tab[j][i] = 0xffff;
    }
    return param_2;
}

#pragma thumb off

#pragma thumb on
u32 ComputeItemSlotTableDataEnd(u32 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    value2 = (value0) + (2u);
    value1 = *(const u8 *) ((value0) + 1u);
    value0 = *(const u8 *) ((value0) + 0u);
    value1 = (value1) * (value0);
    value0 = (value2) + (value1);
    return value0;
}
#pragma thumb off
