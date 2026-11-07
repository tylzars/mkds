#include "Main/Unknown/code_020307b8.h"
#include "Main/Unknown/code_020302a0.h"
#include "Main/Unknown/code_0202f688.h"
#include "Main/Unknown/code_02030a10.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_0204f7f4.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/code_0212775c.h"
#include "code_02148950.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/unk_02163000.h"
#include "Main/Unknown/unk_02174000.h"
#include "code_02016468.h"
#include "code_0214d018.h"

#pragma optimize_for_size on

#pragma thumb on

void func_020309d8(void) {
    MultiSelectNS *o;
    s32 i;
    s32 n;

    o = gMultiSelectNS;
    n = func_02030a18(o->mBncl) + func_02030a10(o->mBnll);
    for (i = 0; i < n; i++) {
        o->mUnk_18[i].mUnk_06 = gMultiSelectNS->mOffset;
    }
}

void RefreshMultiSelectNS(s32 a) {
    u32 t[2];
    s32 i;
    MultiSelectNS *o;
    s32 v;
    s32 w;
    BOOL z1;
    BOOL z2;
    u16 *q;
    u32 c;
    u32 d;

    o = gMultiSelectNS;
    c = *(volatile u32 *) &data_02163614[0];
    d = *(volatile u32 *) &data_02163614[1];
    t[0] = c;
    t[1] = d;
    z1 = FALSE;
    z2 = FALSE;
    for (i = 0; i < 2; i++) {
        if (gMultiSelectNS->mIndex == i && a != 0) {
            v = 1;
        } else {
            v = z1;
        }
        q = data_02153d20[i];
        o->mUnk_18[q[0]].mUnk_00 = v;
        if (v == 0) {
            w = 1;
        } else {
            w = z2;
        }
        o->mUnk_18[q[1]].mUnk_00 = w;
        func_02124100(q[2], t[v], o->mBnll, o->mUnk_18, o->mBncl);
    }
}

#pragma thumb off

void func_02030930(void *a, u32 b, u32 c) {
    volatile u32 v = b;
    MIi_CpuClearFast(v, a, c);
}

void func_0203091c(void *a, u32 b) {
    func_02030930(a, 0, b);
}

#pragma thumb on

void InitMultiSelectNS(void *a, void *b, void *c) {
    void *h;
    MultiSelectNS *o;
    Unk02153d2c *q;
    s32 i;
    u32 n;
    s32 x;

    h = CreateFrmHeapFromMaxFree(a);
    gMultiSelectNS = HeapAlloc(h, 0x40);
    func_0203091c(gMultiSelectNS, 0x40);
    gMultiSelectNS->mHeap = h;
    gMultiSelectNS->mUnk_1c = b;
    gMultiSelectNS->mUnk_20 = c;
    gMultiSelectNS->mBannerMessages = FindSceneFile(data_0216362c);
    gMultiSelectNS->mOffset = -0xc0;
    n = GX_GetSizeOfSubOBJ();
    o = gMultiSelectNS;
    LocateNcgr2(&o->mNcgr, FindSceneFile(data_02163638));
    LocateNcer(&o->mNcer, FindSceneFile(data_02163654));
    LocateNclr(&o->mNclr, FindSceneFile(data_02163670));
    o->mBncl = FindSceneFile(gMultiSelectNSSBnclName);
    o->mBnbl = FindSceneFile(gMultiSelectNSSBnblName);
    o->mBnll = FindSceneFile(gMultiSelectNSSBnllName);
    func_02124ed0(gMultiSelectNS->mHeap, o->mBncl, o->mBnll, &o->mUnk_18);
    for (i = 0; i < 2; i++) {
        q = &data_02153d2c[i];
        x = q->mUnk_00;
        n -= func_021243ac(gMultiSelectNS->mHeap, x, o->mBnll, q->mUnk_02, q->mUnk_04, q->mUnk_06, o->mNcer, o->mBncl,
                           o->mUnk_18, n);
        func_0212426c(1, x, o->mBnll, GetBmgEntry(gMultiSelectNS->mBannerMessages, q->mUnk_08), o->mBncl, o->mUnk_18);
    }
    CallQueueAppend(0x23, 0, o->mNcgr->mData, o->mNcgr->mDataSize);
    CallQueueAppend(0x1e, 0, o->mNclr->mData, o->mNclr->mDataSize);
    RefreshMultiSelectNS(1);
    SetSelectReturnSoundId(0xe);
    func_0204f804();
    FrmHeapShrinkInParent(gMultiSelectNS->mHeap);
}

#pragma thumb off
