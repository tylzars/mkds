#include "Main/Unknown/code_02120044.h"
#include "Main/Unknown/code_0205b0b4.h"
#include "Main/Unknown/code_0205b0f4.h"

#include "Main/Unknown/code_02120048.h"
#include "Main/Unknown/code_02120054.h"
#include "Main/Unknown/code_0211f6cc.h"
#include "Main/Unknown/code_0211ff74.h"
#include "Main/Unknown/code_02122b14.h"
#include "Main/Unknown/code_02123000.h"
#include "Main/Unknown/code_021200a4.h"
#include "Main/Unknown/code_021200a8.h"
#include "Main/Unknown/code_02120610.h"
#include "00/code_021832d8.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_0205c000.h"
#include "Main/Unknown/code_021201e4.h"
#include "Main/Unknown/code_02120240.h"
#include "Main/Unknown/code_02120294.h"
#include "Main/Unknown/code_021202f0.h"
#include "00/unk_021b5000.h"
#include "00/code_021a2ccc.h"

u32 func_021202f0(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &gWiFiSession;
    value1 = 0x244u;
    value2 = *(const u32 *) ((value2) + (0));
    value2 = (value2) + (0x440u);
    value0 = (value1) * (value0) + (value2);
    return value0;
}

u32 GetPlayerRecordRegion(u32 a) {
    return gWiFiSession->mPlayerRecords[a].mRegion;
}

void *func_021202b0(u32 a) {
    return &gWiFiSession->mPlayerRecords[a].mUnk_00c;
}

void *func_02120294(u32 a) {
    return &gWiFiSession->mPlayerRecords[a].mUnk_020;
}

u8 func_02120278(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &gWiFiSession;
    value1 = 0x244u;
    value2 = *(const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = *(const u8 *) ((value1) + (1084));
    return value0;
}

u32 func_0212025c(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &gWiFiSession;
    value1 = 0x244u;
    value2 = *(const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = *(const u32 *) ((value1) + (1108));
    return value0;
}

u32 func_02120240(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &gWiFiSession;
    value1 = 0x244u;
    value2 = *(const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = *(const u32 *) ((value1) + (1112));
    return value0;
}

int GetPlayerRecordElo(int arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &gWiFiSession;
    value1 = 0x244u;
    value2 = *(const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = (value1) + (0x400u);
    value0 = *(const s16 *) ((value0) + (62));
    return value0;
}

void SetPlayerRecordElo(int arg0, s16 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2;
    u32 value3;
    value3 = (u32) &gWiFiSession;
    value2 = 0x244u;
    value3 = *(const u32 *) ((value3) + (0));
    value2 = (value0) * (value2) + (value3);
    value0 = (value2) + (0x400u);
    *(u16 *) ((value0) + (62)) = value1;
}

u8 func_021201e4(int arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &gWiFiSession;
    value1 = 0x244u;
    value2 = *(const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = *(const u8 *) ((value1) + (1105));
    return value0;
}

void func_02120150(void) {
    WiFiSession *d;
    BOOL a = FALSE;

    d = gWiFiSession;
    if (d != NULL) {
        if (d->mHeapCreated != FALSE) {
            a = TRUE;
        }
    }
    if (a == FALSE) {
        return;
    }
    d->mUnk_1f3c++;
    if (gWiFiSession->mUnk_0008.mState != 5) {
        return;
    }
    if (gWiFiSession->mUnk_1f38 == FALSE) {
        return;
    }
    func_0205ccec();
}

void EnterWiFiSessionState1(void) {
    func_0211fb44();
}

void UpdateWiFiSessionState1(void) {
    Unk0217d384_08 *p;

    if (func_0211f91c() == 0) {
        return;
    }
    p = &gWiFiSession->mUnk_0008;
    p->mNextState = 2;
    p->mNextStateRequested = 1;
}

void EnterWiFiSessionState3(void) {
    RegisterKartKeysAndStart();
}

void UpdateWiFiSessionState3(void) {
    Unk0217d384_08 *p;

    if (IsKartKeysStartStatus3() == FALSE) {
        return;
    }
    p = &gWiFiSession->mUnk_0008;
    p->mNextState = 4;
    p->mNextStateRequested = 1;
}

void func_021200a4(void) {}

void UpdateWiFiSessionState4(void) {
    func_021236f8();
}

void EnterWiFiSessionState5(void) {
    Unk0217aa14 *p;

    func_ov000_021a3250(func_0211ff74);
    func_ov000_021a323c(func_0211fef4);
    p = data_0217aa14;
    p->mUnk_010 = 1;
    p->mUnk_012 = 1;
}

void UpdateWiFiSessionState5(void) {
    u32 value12;
    func_0205b0b4();
}

void func_02120044(void) {}
