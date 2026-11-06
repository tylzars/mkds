#include "Main/Unknown/code_0211f394.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_02116dc8.h"

#include "Main/Unknown/code_0211f4b0.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_02116d24.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/unk_0216e000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_0211f498.h"
#include "Main/Unknown/code_0211f61c.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_02116dd4.h"
#include "code_02148950.h"
#include "Main/Unknown/code_02047104.h"

#pragma thumb on

void func_0211f61c(void) {
    void *v1;
    Ncgr *v2;
    Nclr *v3[1];
    v2 = NULL;
    v3[0] = NULL;
    v1 = FindSceneFile(data_0216e128);
    LocateNcer(&data_0217d380->mNcer, v1);
    v1 = FindSceneFile(data_0216e134);
    LocateNcgr2(&v2, v1);
    v1 = FindSceneFile(data_0216e130);
    LocateNclr(v3, v1);
    v1 = FindSceneFile(data_0216e124);
    data_0217d380->mBncl = v1;
    v1 = FindSceneFile(data_0216e12c);
    data_0217d380->mBnll = v1;
    CallQueueAppend(0x23, 0, v2->mData, v2->mDataSize);
    CallQueueAppend(0x1e, 0, v3[0]->mData, v3[0]->mDataSize);
}

#pragma thumb off

#pragma thumb on

void func_0211f5e4(void) {
    u16 a;

    data_0217d380->mNextState = 0;
    data_0217d380->mStateFrames = 0;
    a = data_0217d380->mBncl->mUnk_06;
    data_0217d380->mTable[0x2a].mUnk_06 = 0xc0;
    data_0217d380->mTable[a + 0xe].mUnk_06 = 0xc0;
}

void func_0211f5d0(void) {
    data_0217d380->mNextState = 1;
    data_0217d380->mStateFrames = 0;
}

void func_0211f598(void) {
    u16 a;

    data_0217d380->mNextState = 2;
    data_0217d380->mStateFrames = 0;
    a = data_0217d380->mBncl->mUnk_06;
    data_0217d380->mTable[0x2a].mUnk_06 = 0;
    data_0217d380->mTable[a + 0xe].mUnk_06 = 0;
}

void func_0211f4b0(void *a, void *b) {
    Unk0217d380 *p;
    s32 i;
    u16 n;
    u32 v;

    data_0217d380 = HeapAlloc(a, 0x28);
    data_0217d380->mState = 1;
    data_0217d380->mUnk_18 = b;
    func_0211f61c();
    func_02124ed0(a, data_0217d380->mBncl, data_0217d380->mBnll, &data_0217d380->mTable);
    data_0217d380->mCommonMessages = func_02047a28("common.bmg");
    v = GX_GetSizeOfSubOBJ();
    func_021243ac(a, 0xe, data_0217d380->mBnll, 0xc8, 0xd, 0, data_0217d380->mNcer, data_0217d380->mBncl,
                  data_0217d380->mTable, v);
    p = data_0217d380;
    func_0212426c(1, 0xe, data_0217d380->mBnll, GetBmgEntry(p->mCommonMessages, 0x79), p->mBncl, p->mTable);
    i = 0;
    n = data_0217d380->mBncl->mUnk_06;
    for (; i < n; i++) {
        data_0217d380->mTable[i].mUnk_00 = 0;
    }
    data_0217d380->mTable[0x2a].mUnk_00 = 1;
    CreateWait(a, data_0217d380->mNcer, data_0217d380->mBncl, 0x2a, 0xe, 1);
    func_0211f5e4();
    func_0211f5d0();
    func_0211f39c();
}

#pragma thumb off

#pragma thumb on

void func_0211f498(void) {
    func_02116dc8();
    *(u32 *) &data_0217d380 = 0;
}

#pragma thumb off

#pragma thumb on

void func_0211f440(void) {
    u16 a;
    s16 v;

    a = data_0217d380->mBncl->mUnk_06;
    data_0217d380->mStateFrames++;
    v = func_020ae4c0(1, 0xc0, 0, data_0217d380->mStateFrames, 10);
    data_0217d380->mTable[0x2a].mUnk_06 = v;
    data_0217d380->mTable[a + 0xe].mUnk_06 = v;
    if (data_0217d380->mStateFrames >= 10) {
        func_0211f5d0();
    }
}

void func_0211f3e8(void) {
    u16 a;
    s16 v;

    a = data_0217d380->mBncl->mUnk_06;
    data_0217d380->mStateFrames++;
    v = func_020ae4c0(1, 0, 0xc0, data_0217d380->mStateFrames, 10);
    data_0217d380->mTable[0x2a].mUnk_06 = v;
    data_0217d380->mTable[a + 0xe].mUnk_06 = v;
    if (data_0217d380->mStateFrames >= 10) {
        func_0211f5d0();
    }
}

void func_0211f39c(void) {
    data_0217d380->mState = data_0217d380->mNextState;
    switch (data_0217d380->mState) {
        case 0:
            func_0211f440();
            break;
        case 1:
            break;
        case 2:
            func_0211f3e8();
            break;
    }
    AdvanceWait();
    func_02124c30(data_0217d380->mBncl, data_0217d380->mNcer, data_0217d380->mBnll, data_0217d380->mUnk_18,
                  data_0217d380->mTable);
}

void func_0211f394(void) {
    func_0211f5e4();
}

#pragma thumb off
