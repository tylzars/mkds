#include "Main/Unknown/code_02104a0c.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_020d2dec.h"
#include "Main/Unknown/code_020f73fc.h"

#include "Main/Unknown/code_02069000.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020deb2c.h"
#include "Main/Unknown/code_020f2dac.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f49bc.h"
#include "Main/Unknown/code_020f6000.h"
#include "Main/Unknown/code_020f7000.h"
#include "Main/Unknown/code_020f9000.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_0210e000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f9c40.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_021053d8.h"
#include "Main/Unknown/code_021053e4.h"
#include "Main/Unknown/code_02105550.h"
#include "Main/Unknown/code_021052fc.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020f813c.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_02147cd8.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"
#include "ITCM/code_01ffcf7c.h"

const u16 data_0215a584 = 0x2000;

const ItemInfo gItemInfoKiller = {1, 1, 0xd, 1, 0, 0, StartItemKiller};

const ItemKind gItemKindKiller = {
    0x12c, 1, 1,    -1,  -1,   {0}, NULL, NULL,     NULL, NULL,   NULL, NULL, ComputeViewTest, NULL,   NULL,  NULL,
    0,     0, NULL, 0,   NULL, 1,   0,    0x4b0000, 2,    0x319a, 0,    0,    0x1000,          0x1b33, 0x19a, 0x11f,
    0,     1, 0,    {0}, 0,    1,   1,    1,        1,    0};

#pragma thumb on
// Allocates the map objects that the item objects with a map-object look take from the pool.
void CreatePooledMapObjects(void) {
    Vec3 buf;
    s32 i;
    switch (gRaceSetup->mMode) {
        case MODE_BATTLE:
            gPooledMapObjectCount = 0xb;
            break;
        case MODE_MISSION_RUN:
            gPooledMapObjectCount = 0x20;
            break;
        case 5:
            gPooledMapObjectCount = 6;
            break;
        default:
            gPooledMapObjectCount = 3;
            break;
    }
    gPooledMapObjects = HeapAlloc(GetHeap(GetCurrentHeapCall()), gPooledMapObjectCount * 4);
    buf = data_0215a6cc;
    gPooledMapObjectRow.mUnk_00 = buf;
    data_0217c73c = buf;
    data_0217c748 = data_0215a6c0;
    gPooledMapObjectRow.mKind = 0x6f;
    gPooledMapObjectRow.mUnk_2e = 1;
    for (i = 0; i < gPooledMapObjectCount; i++) {
        gPooledMapObjects[i] = CreateMapObjectFromCourseMapRow(&gPooledMapObjectRow, 0x6f);
    }
    gPooledMapObjectNextIndex = 0;
}
#pragma thumb off

void StartItemKiller(ItemInUse *p0, HeldItem *p1) {
    StartKartKiller(p1->mKartItems->mKart);
    RemoveHeldItemObjects(p1, 1);
    SetActiveItem(p0->mKartItems, 0xe);
}

void func_0210515c(s32 a) {
    gKartItems[a].mActiveItem = 0x13;
    if (gRaceSetup->mMode != 5) {
        return;
    }
    if (a == gRaceSetup->mEntryIndex) {
        return;
    }
    func_020efd84(&gKartItems[a], 0xe);
}

// Battle only: hands item 17 to a kart with an empty hand when its timer is 0 and counts the running timers down.
void UpdateBouncingItemBoxTimers(void) {
    s32 i;
    s32 c;
    KartItems *p;
    HeldItem *q;
    NNSSndSeqPlayer **v;
    u32 a = 0;
    u32 b = 0;
    if (gRaceSetup->mMode != MODE_BATTLE) {
        return;
    }
    for (i = 0; i < 8; i++) {
        c = gBouncingItemBoxTimers[i];
        if (c < 0) {
            continue;
        }
        p = &gKartItems[(u16) i];
        q = &p->mHeldItem;
        if (q->mItemInfoIndex != 0x13) {
            continue;
        }
        if (c == 0) {
            SetHeldItem(q, 0x11);
            gBouncingItemBoxTimerRunning[i] = 0;
            if (i == gRaceSetup->mEntryIndex && (data_0217c780 & 1)) {
                v = func_0210e128(func_02108ea0(0));
                if (data_0217d084.mUnk_0c != 0) {
                    if (v[0] != NULL) {
                        NNS_SndPlayerStopSeq(v, 0);
                    }
                    if (v[0] != NULL) {
                        NNS_SndPlayerStopSeq(v, a);
                    }
                    NNS_SndArcPlayerStartSeqArc(v, b, 0x3f);
                }
            }
        } else if (gBouncingItemBoxTimerRunning[i] != 0 && c > 0) {
            gBouncingItemBoxTimers[i]--;
        }
    }
}

void func_02104f84(s32 a) {
    if (gRaceSetup->mMode != MODE_BATTLE) {
        return;
    }
    if ((s32) gBouncingItemBoxTimers[a] >= 0) {
        return;
    }
    gBouncingItemBoxTimers[a] = 0;
    func_020f0044(&gKartItems[a]);
}

void StartBouncingItemBox(BouncingItemBox *p) {
    if (p->mKartIsEntry != 0) {
        (p->mPooledMapObject)->mUnk_b0 = 1;
    }
    if ((p->mUnk_000.mItemObject.mFlags & 0x180000) == 0) {
        p->mUnk_000.mItemObject.mAdvance = (void (*)(ItemObject *)) AdvanceBouncingItemBox;
    }
}

void ReleaseBouncingItemBox(BouncingItemBox *p) {
    u16 i = p->mUnk_000.mItemObject.mUnk_78 & ~0xff00;
    if ((s32) gBouncingItemBoxTimers[i] > 0) {
        gBouncingItemBoxTimerRunning[i] = 1;
    }
    func_021053d8((u32) p->mPooledMapObject);
}

void CollideKartWithBouncingItemBox(BouncingItemBox *p, void *a) {
    func_020deb2c(&p->mUnk_000.mItemObject.mPos, a, 0, (p->mUnk_000.mItemObject.mFlags & 0x10000) ? 1 : 0, 0);
}

void ResetBouncingItemBox(BouncingItemBox *p) {
    p->mScaleRatio = 0x666;
    func_021053e4(p->mPooledMapObject);
    p->mKartIsEntry = (u16) (p->mUnk_000.mItemObject.mUnk_78 & ~0xff00) == gRaceSetup->mEntryIndex;
    if (p->mKartIsEntry != 0) {
        (p->mPooledMapObject)->mUnk_b0 = 2;
    }
    gBouncingItemBoxTimers[(u16) (p->mUnk_000.mItemObject.mUnk_78 & ~0xff00)] = 0x258;
}

void AdvanceBouncingItemBoxInUse(ItemInUse *p0, BouncingItemBox *p1) {
    Vec3 t;
    Unk021052fc *b = p1->mPooledMapObject;
    s32 n;
    if (p1->mKartIsEntry != 0) {
        VEC_MultAdd(((s64) p0->mUnk_084.z * -28877) >> 12, &p0->mUnk_02c.mUnk_0c, &p1->mUnk_000.mItemObject.mPos,
                    &p1->mMapObjectPos);
        n = p1->mScaleRatio;
        t.x = ((s64) p1->mUnk_000.mItemObject.mScale.x * n) >> 12;
        t.y = ((s64) p1->mUnk_000.mItemObject.mScale.y * n) >> 12;
        t.z = ((s64) p1->mUnk_000.mItemObject.mScale.z * n) >> 12;
        SetPooledMapObjectFromItem(b, p1->mUnk_000.mItemObject.mUnk_d8, &t);
    } else {
        p1->mMapObjectPos = p1->mUnk_000.mItemObject.mPos;
        SetPooledMapObjectFromItem(b, p1->mUnk_000.mItemObject.mUnk_d8, &p1->mUnk_000.mItemObject.mScale);
    }
    AdvancePooledMapObject(b);
}

s32 InitBouncingItemBox(ItemInUse *p0, BouncingItemBox *p1) {
    func_020f9114(p1);
    p1->mUnk_000.mItemObject.mUnk_78 |= data_0215a584;
    if (p1->mKartIsEntry != 0) {
        (p1->mPooledMapObject)->mUnk_b0 = 1;
    }
    if ((p0->mKartItems->mFlags & KART_ITEMS_THROW_FORWARD) != 0) {
        ThrowBouncingItem(&p1->mUnk_000, p0, 0, 1, 0x4000, 0x3000, 0x59a);
        StartSound(&p1->mUnk_000.mItemObject.mSoundSource, 0xda, 0x7f, 0);
        p1->mThrownForward = 1;
        return p1->mThrownForward;
    } else {
        ThrowBouncingItem(&p1->mUnk_000, p0, 0, 0, 0x4000, 0x3000, 0x59a);
        if (p0->mKartVelocityLength < 0x1000) {
            p1->mUnk_000.mItemObject.mVelocity.x = 0;
            p1->mUnk_000.mItemObject.mVelocity.y = 0;
            p1->mUnk_000.mItemObject.mVelocity.z = 0;
        }
        p1->mThrownForward = 0;
        return p1->mThrownForward;
    }
}

void AdvanceBouncingItemBox(BouncingItemBox *p) {
    u32 buf;
    Vec3 d;
    Vec3 t;
    u16 i;
    s32 v;
    s32 n;
    s32 a;
    Unk021052fc *b;
    if ((p->mUnk_000.mItemObject.mFlags & 0x180000) != 0) {
        if ((p->mUnk_000.mItemObject.mFlags & 0x80000) != 0) {
            func_020f6e58(&p->mUnk_000.mItemObject);
        } else if ((p->mUnk_000.mItemObject.mFlags & 0x100000) != 0) {
            AdvanceItemObjectReleaseTimer(&p->mUnk_000.mItemObject);
        }
    } else if ((p->mUnk_000.mItemObject.mFlags & 0x8000) != 0) {
        if (gRaceSetup->mMode == MODE_BATTLE) {
            i = p->mUnk_000.mItemObject.mUnk_78 & ~0xff00;
            v = gBouncingItemBoxTimers[i] - 0x3c;
            if (v < p->mUnk_000.mItemObject.mUnk_d8) {
                p->mUnk_000.mItemObject.mUnk_d8 = v;
            }
            if (v < 0xa) {
                FreeItemObjectCollisionSlot((s32) p);
                if (v == 0) {
                    ReleaseItemPoolObject(&gItemPools[p->mUnk_000.mItemObject.mKind], &p->mUnk_000.mItemObject);
                    return;
                }
            }
            gBouncingItemBoxTimers[i]--;
        }
        AdvanceRestingItemObject(&p->mUnk_000.mItemObject);
    } else if ((p->mUnk_000.mItemObject.mFlags & 0x4000) != 0) {
        AdvanceFallingItemObject(&p->mUnk_000.mItemObject);
    } else {
        if (p->mThrownForward != 0) {
            AdvanceBouncingItem(&p->mUnk_000, 0x1ec, 0xfec, 0, &buf);
        } else {
            AdvanceBouncingItem(&p->mUnk_000, 0x2e1, 0xf85, 0, &buf);
        }
        if ((p->mUnk_000.mItemObject.mFlags & 8) != 0 && (p->mUnk_000.mItemObject.mFlags & 3) == 0) {
            if (p->mThrownForward != 0) {
                p->mUnk_000.mItemObject.mVelocity.y <<= 1;
            }
            StopSound(&p->mUnk_000.mItemObject.mSoundSource, 0xda);
            StartRestingItemObject(&p->mUnk_000.mItemObject, &buf);
        }
    }
    a = p->mKartIsEntry;
    b = p->mPooledMapObject;
    if (a != 0 && p->mScaleRatio < 0x1000) {
        p->mScaleRatio += 0xcd;
        n = p->mScaleRatio;
        t.x = ((s64) p->mUnk_000.mItemObject.mScale.x * n) >> 12;
        t.y = ((s64) p->mUnk_000.mItemObject.mScale.y * n) >> 12;
        t.z = ((s64) p->mUnk_000.mItemObject.mScale.z * n) >> 12;
        VEC_Subtract(&p->mUnk_000.mItemObject.mPos, &p->mMapObjectPos, &d);
        VEC_MultAdd(((s64) p->mScaleRatio * p->mScaleRatio) >> 12, &d, &p->mMapObjectPos, &p->mMapObjectPos);
        SetPooledMapObjectFromItem(b, p->mUnk_000.mItemObject.mUnk_d8, &t);
    } else {
        p->mMapObjectPos = p->mUnk_000.mItemObject.mPos;
        SetPooledMapObjectFromItem(b, p->mUnk_000.mItemObject.mUnk_d8, &p->mUnk_000.mItemObject.mScale);
    }
    AdvancePooledMapObject(b);
}
