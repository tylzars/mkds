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
    func_02120144,
    func_021200fc,
    0,
    0,
    func_021200f0,
    func_021200a8,
    func_021200a4,
    func_02120098,
    func_02120054,
    func_02120048,
    0,
    func_02120044,
};

u32 func_021205e8(void) {
    return func_ov000_021a3758();
}

#pragma thumb on
void InitWiFiSession(void *a) {
    Unk0217d384_08 *p;

    gWiFiSession = HeapAllocAligned(a, 0x1f58, 0x20);
    func_02046be8(&gWiFiSession->mUnk_0008, data_0216e21c, 8, NULL);
    p = &gWiFiSession->mUnk_0008;
    p->mNextState = 0;
    p->mNextStateRequested = 1;
}

// Creates the 0x3e800-byte exp heap and registers WiFiSessionHeapAlloc / Free with the net layer (the heap is used only
// through them).
void CreateWiFiSessionHeap(void *a) {
    gWiFiSession->mHeapBuffer = HeapAllocAligned(a, 0x3e800, 0x20);
    gWiFiSession->mHeap = NNS_FndCreateExpHeapEx(gWiFiSession->mHeapBuffer, 0x3e800, 1);
    gWiFiSession->mHeapCreated = TRUE;
    func_ov000_021a3744(WiFiSessionHeapAlloc, WiFiSessionHeapFree);
}

// Destroys the heap and frees its buffer (mHeap is left set), clears mHeapCreated and requests state 0.
void DeleteWiFiSessionHeap(void) {
    Unk0217d384_08 *p;

    if (gWiFiSession->mHeap != NULL) {
        NNS_FndDestroyExpHeap(gWiFiSession->mHeap);
        HeapFree(GetHeap(func_020364e8()), gWiFiSession->mHeapBuffer);
    }
    gWiFiSession->mHeapCreated = FALSE;
    p = &gWiFiSession->mUnk_0008;
    p->mNextState = 0;
    p->mNextStateRequested = 1;
}
#pragma thumb off

void func_021204d0(void) {
    Unk0217d384_08 *p;

    ResetWiFiSession();
    gWiFiSession->mUnk_1f34 = TRUE;
    p = &gWiFiSession->mUnk_0008;
    p->mNextState = 0;
    p->mNextStateRequested = 1;
}

// Polls one buddy entry's status per call and counts the entries with status 4 into mUnk_194d.
void UpdateBuddyStatuses(void) {
    u8 n = 0;
    WiFiSession *d;
    WiFiSession *p;
    u8 i;

    if (gWiFiSession->mBuddyPollIndex >= 0x3c) {
        gWiFiSession->mBuddyPollIndex = 0;
    }
    d = gWiFiSession;
    d->mBuddyStatuses[d->mBuddyPollIndex] = func_ov000_0219daa8(&d->mBuddies[d->mBuddyPollIndex], NULL);
    gWiFiSession->mBuddyPollIndex++;
    p = gWiFiSession;
    i = 0;
    do {
        switch (p->mBuddyStatuses[i]) {
            case 2:
                break;
            case 4:
                n++;
                break;
        }
        i++;
    } while (i < 0x3c);
    p->mUnk_194d = n;
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
    func_02046b40(&gWiFiSession->mUnk_0008);
}

s32 func_02120340(u32 a, void *b, s32 c, u32 (*d)(void)) {
    return func_ov000_021a32a0(a, b, c);
}

// Returns the name+emblem part of the index's record, or NULL if the index is not in mKartMask.
void *GetWiFiSessionPlayerRecordData(u32 a) {
    WiFiSession *d = gWiFiSession;

    if (d->mKartMask & (1 << a)) {
        return &d->mPlayerRecords[a].mUnk_00c;
    }
    return NULL;
}
