#include "00/code_02185344.h"
#include "00/unk_021b0000.h"
#include "code_0214b824.h"

#include "00/code_02180608.h"
#include "00/code_02184ba8.h"
#include "00/unk_021b4000.h"
#include "00/code_ov000_021804e0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02060cb4.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_0212658c.h"
#include "Main/Unknown/code_02047104.h"

void SetWiFiAikotobaCheckDigits(void) {
    u8 a[20];
    s32 i;

    func_02061220((u32) a);
    for (i = 0; i < 12; i++) {
        gWiFiAikotobaCheck->mDigits[i] = a[i];
    }
}

void func_ov000_021856a8(void) {
    s32 n = 0x4000;
    u8 a[12] = {0, 0, 1, 2, 3, 4, 1, 6, 7, 8, 9, 10};
    u8 b[12] = {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
    u16 c;
    s32 i;
    s16 z[2];

    c = gWiFiAikotobaCheck->mWiFiAikotobaCheckBncl->mUnk_06;
    SetWiFiAikotobaCheckDigits();
    for (i = 0; i < 12; i++) {
        if (b[i] == 0) {
            a[i] = a[i] + c;
        }
    }
    for (i = 0; i < 12; i++) {
        n -=
            func_021243ac(gWiFiAikotobaCheck->mHeap, data_ov000_021b06dc[i], gWiFiAikotobaCheck->mWiFiAikotobaCheckBnll,
                          8, 0x10, a[i], gWiFiAikotobaCheck->mWiFiAikotobaCheckMNcer,
                          gWiFiAikotobaCheck->mWiFiAikotobaCheckBncl, gWiFiAikotobaCheck->mWiFiAikotobaCheckTable, n);
        z[0] = 0;
        z[1] = 0;
        z[0] = gWiFiAikotobaCheck->mDigits[i];
        func_0212426c(0, data_ov000_021b06dc[i], gWiFiAikotobaCheck->mWiFiAikotobaCheckBnll, z,
                      gWiFiAikotobaCheck->mWiFiAikotobaCheckBncl, gWiFiAikotobaCheck->mWiFiAikotobaCheckTable);
    }
}

void InitWiFiAikotobaCheck(void *a) {
    void *b;

    gWiFiAikotobaCheck = HeapAlloc(a, 0x54);
    gWiFiAikotobaCheck->mHeap = a;
    gWiFiAikotobaCheck->mState = 0;
    gWiFiAikotobaCheck->mNextState = 0;
    gWiFiAikotobaCheck->mPendingWiFiState = -1;
    gWiFiAikotobaCheck->mStateFrames = 0;
    gWiFiAikotobaCheck->mWiFiMessages = FindSceneFile(data_ov000_021b0fc0);
    gWiFiAikotobaCheck->mCommonMessages = func_02047a28(data_ov000_021b0fcc);
    LocateAndUploadWiFiAikotobaCheck();
    b = func_ov000_021804f4();
    func_020ae6d4(b, func_ov000_021804e0());
    func_02124ed0(a, gWiFiAikotobaCheck->mWiFiAikotobaCheckBncl, gWiFiAikotobaCheck->mWiFiAikotobaCheckBnll,
                  &gWiFiAikotobaCheck->mWiFiAikotobaCheckTable);
    gWiFiAikotobaCheck->mOffset = 0x50;
    func_ov000_021854f8();
    func_ov000_021856a8();
    func_02126638(GetBmgEntry(gWiFiAikotobaCheck->mWiFiMessages, 0x11), 0, 1, 0, 0, 0, 0);
}

void func_ov000_021855f8(void) {
    gWiFiAikotobaCheck = NULL;
}

void LocateAndUploadWiFiAikotobaCheck(void) {
    void *v1;
    v1 = FindSceneFile(gWiFiAikotobaCheckBnclName);
    gWiFiAikotobaCheck->mWiFiAikotobaCheckBncl = v1;
    v1 = FindSceneFile(gWiFiAikotobaCheckBnllName);
    gWiFiAikotobaCheck->mWiFiAikotobaCheckBnll = v1;
    v1 = FindSceneFile(gWiFiAikotobaCheckMNcgrName);
    LocateNcgr2(&gWiFiAikotobaCheck->mWiFiAikotobaCheckMNcgr, v1);
    v1 = FindSceneFile(gWiFiAikotobaCheckMNcerName);
    LocateNcer(&gWiFiAikotobaCheck->mWiFiAikotobaCheckMNcer, v1);
    v1 = FindSceneFile(gWiFiAikotobaCheckMONclrName);
    LocateNclr(&gWiFiAikotobaCheck->mWiFiAikotobaCheckMONclr, v1);
    GX_LoadOBJ(gWiFiAikotobaCheck->mWiFiAikotobaCheckMNcgr->mData, 0,
               gWiFiAikotobaCheck->mWiFiAikotobaCheckMNcgr->mDataSize);
    GX_LoadOBJPltt(gWiFiAikotobaCheck->mWiFiAikotobaCheckMONclr->mData, 0, 0x1a0);
    GX_LoadOBJPltt(gWiFiAikotobaCheck->mWiFiAikotobaCheckMONclr->mData + 0xe0, 0x1c0, 0x40);
}

void func_ov000_021854f8(void) {
    s32 i;

    for (i = 0; i < 2; i++) {
        gWiFiAikotobaCheck->mWiFiAikotobaCheckTable[data_ov000_021b06d8[i]].mUnk_06 = gWiFiAikotobaCheck->mOffset;
    }
    for (i = 0; i < 12; i++) {
        gWiFiAikotobaCheck
            ->mWiFiAikotobaCheckTable[data_ov000_021b06dc[i] + gWiFiAikotobaCheck->mWiFiAikotobaCheckBncl->mUnk_06]
            .mUnk_06 = gWiFiAikotobaCheck->mOffset;
    }
}

void AdvanceWiFiAikotobaCheckState0(void) {
    gWiFiAikotobaCheck->mStateFrames = gWiFiAikotobaCheck->mStateFrames + 1;
    gWiFiAikotobaCheck->mOffset = func_020ae4c0(1, 0x50, 0, gWiFiAikotobaCheck->mStateFrames, 15);
    if (gWiFiAikotobaCheck->mStateFrames >= 15 && func_02125fa4() != 0) {
        gWiFiAikotobaCheck->mNextState = 1;
        gWiFiAikotobaCheck->mStateFrames = 0;
    }
}

void AdvanceWiFiAikotobaCheckState1(void) {
    Unk02175628Index i = UNK_02175628_INDEX_8;
    BOOL a;
    BOOL b;
    u16 c;

    if ((u16) (data_02175628[i].mUnk_00 & 2) == 0) {
        a = FALSE;
        b = FALSE;
        c = data_02175628[i].mHasPair;
        if (c == 0 && data_02175628[i].mNoPairCount < 5) {
            b = TRUE;
        }
        if (b == FALSE && data_02175628[i].mPrevHasPair == 0 && c != 0) {
            a = TRUE;
        }
        if (a == FALSE || IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175628[i].mUnk_48,
                                                                          data_02175628[i].mUnk_4a) == FALSE) {
            return;
        }
    }
    gWiFiAikotobaCheck->mNextState = 2;
    gWiFiAikotobaCheck->mPendingWiFiState = 8;
    func_02128310(0);
    RequestTxtSystemClose();
}

void AdvanceWiFiAikotobaCheckState2(void) {
    gWiFiAikotobaCheck->mStateFrames = gWiFiAikotobaCheck->mStateFrames + 1;
    gWiFiAikotobaCheck->mOffset = func_020ae4c0(1, 0, 0x50, gWiFiAikotobaCheck->mStateFrames, 15);
    if (gWiFiAikotobaCheck->mStateFrames >= 15 && func_02125f88() != 0 &&
        IsSelectReturnState2NoState3Or4Request() != 0) {
        RequestWiFiState(gWiFiAikotobaCheck->mPendingWiFiState);
    }
}

void AdvanceWiFiAikotobaCheck(void) {
    WiFiAikotobaCheck *p;

    gWiFiAikotobaCheck->mState = gWiFiAikotobaCheck->mNextState;
    switch (gWiFiAikotobaCheck->mState) {
        case 0:
            AdvanceWiFiAikotobaCheckState0();
            break;
        case 1:
            AdvanceWiFiAikotobaCheckState1();
            break;
        case 2:
            AdvanceWiFiAikotobaCheckState2();
            break;
    }
    func_ov000_021854f8();
    p = gWiFiAikotobaCheck;
    func_02124c30(p->mWiFiAikotobaCheckBncl, p->mWiFiAikotobaCheckMNcer, p->mWiFiAikotobaCheckBnll,
                  func_ov000_021804f4(), p->mWiFiAikotobaCheckTable);
}

void func_ov000_02185368(void) {}

void RegisterWiFiAikotobaCheckCallbacks(void) {
    WiFiStateCallbacks callbacks = gWiFiAikotobaCheckCallbacks;
    SetWiFiStateCallbacks(&callbacks);
}
