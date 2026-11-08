#include "Main/Unknown/code_0212030c.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020467d0.h"
#include "00/code_021832d8.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_0211f6cc.h"
#include "Main/Unknown/code_0211ffb0.h"
#include "Main/Unknown/code_02120610.h"
#include "00/code_0219b580.h"
#include "00/code_021a3264.h"
#include "00/code_021a3758.h"
#include "00/unk_021b5000.h"
#include "00/code_021a369c.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_02120044.h"
#include "Main/Unknown/code_02120048.h"
#include "Main/Unknown/code_02120054.h"
#include "Main/Unknown/code_021200a4.h"
#include "Main/Unknown/code_021200a8.h"
#include "00/code_0219daa8.h"
#include "00/code_0219c384.h"
#include "00/code_0219b000.h"
#include "00/code_021a3000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_020364e0.h"
#include "code_020176c0.h"

UnkFunc *data_0216e21c[14] = {
    0,
    0,
    EnterWiFiSessionState1,
    UpdateWiFiSessionState1,
    0,
    0,
    EnterWiFiSessionState3,
    UpdateWiFiSessionState3,
    func_021200a4,
    UpdateWiFiSessionState4,
    EnterWiFiSessionState5,
    UpdateWiFiSessionState5,
    0,
    func_02120044,
};

u32 func_021205e8(void) {
    return func_ov000_021a3758();
}

#pragma thumb on
void InitWiFiSession(void *heap) {
    Unk0217d384_08 *stateMachine;

    gWiFiSession = HeapAllocAligned(heap, 0x1f58, 0x20);
    InitStateMachine(&gWiFiSession->mUnk_0008, data_0216e21c, 8, NULL);
    stateMachine = &gWiFiSession->mUnk_0008;
    stateMachine->mNextState = 0;
    stateMachine->mNextStateRequested = 1;
}

// Creates the 0x3e800-byte exp heap and registers WiFiSessionHeapAlloc / Free with the net layer (the heap is used only
// through them).
void CreateWiFiSessionHeap(void *heap) {
    gWiFiSession->mHeapBuffer = HeapAllocAligned(heap, 0x3e800, 0x20);
    gWiFiSession->mHeap = NNS_FndCreateExpHeapEx(gWiFiSession->mHeapBuffer, 0x3e800, 1);
    gWiFiSession->mHeapCreated = TRUE;
    func_ov000_021a3744(WiFiSessionHeapAlloc, WiFiSessionHeapFree);
}

// Destroys the heap and frees its buffer (mHeap is left set), clears mHeapCreated and requests state 0.
void DeleteWiFiSessionHeap(void) {
    Unk0217d384_08 *stateMachine;

    if (gWiFiSession->mHeap != NULL) {
        NNS_FndDestroyExpHeap(gWiFiSession->mHeap);
        HeapFree(GetHeap(GetCurrentHeapCall()), gWiFiSession->mHeapBuffer);
    }
    gWiFiSession->mHeapCreated = FALSE;
    stateMachine = &gWiFiSession->mUnk_0008;
    stateMachine->mNextState = 0;
    stateMachine->mNextStateRequested = 1;
}
#pragma thumb off

void func_021204d0(void) {
    Unk0217d384_08 *stateMachine;

    ResetWiFiSession();
    gWiFiSession->mUnk_1f34 = TRUE;
    stateMachine = &gWiFiSession->mUnk_0008;
    stateMachine->mNextState = 0;
    stateMachine->mNextStateRequested = 1;
}

// Polls one buddy entry's status per call and counts the entries with status 4 into mStatus4BuddyCount.
void UpdateBuddyStatuses(void) {
    u8 status4Count = 0;
    WiFiSession *session;
    WiFiSession *countSession;
    u8 i;

    if (gWiFiSession->mBuddyPollIndex >= 0x3c) {
        gWiFiSession->mBuddyPollIndex = 0;
    }
    session = gWiFiSession;
    session->mBuddyStatuses[session->mBuddyPollIndex] =
        func_ov000_0219daa8(&session->mBuddies[session->mBuddyPollIndex], NULL);
    gWiFiSession->mBuddyPollIndex++;
    countSession = gWiFiSession;
    i = 0;
    do {
        switch (countSession->mBuddyStatuses[i]) {
            case 2:
                break;
            case 4:
                status4Count++;
                break;
        }
        i++;
    } while (i < 0x3c);
    countSession->mStatus4BuddyCount = status4Count;
}

void UpdateWiFiSession(void) {
    if (gWiFiSession == NULL) {
        return;
    }
    if (data_0217aa10->mUnk_00 != 0) {
        return;
    }
    UpdateWiFiConnection();
    if (func_ov000_0219c3cc(NULL) != 0) {
        gWiFiSession->mUnk_1f44 = func_ov000_0219c3cc(&gWiFiSession->mUnk_1f48);
        func_ov000_0219c3b0();
    }
    if (gWiFiSession->mUnk_0008.mState != 0) {
        UpdateBuddyStatuses();
    }
    AdvanceStateMachine(&gWiFiSession->mUnk_0008);
}

s32 func_02120340(u32 a, void *b, s32 c, u32 (*d)(void)) {
    return func_ov000_021a32a0(a, b, c);
}

// Returns the name+emblem part of the index's record, or NULL if the index is not in mKartMask.
void *GetWiFiSessionPlayerRecordData(u32 index) {
    WiFiSession *session = gWiFiSession;

    if (session->mKartMask & (1 << index)) {
        return &session->mPlayerRecords[index].mName;
    }
    return NULL;
}
