#include "Main/Unknown/code_0200b200.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/code_0200b6e8.h"
#include "code_0214d018.h"

#pragma thumb on

void ScanConnectEndScanCallback(Unk021425e8 *a) {
    if (a->mResultCode != 0) {
        ReportScanError(0xb, a->mResultCode);
        return;
    }
    gScanConnectWork->mEndScanRequested = 0;
    if (gScanConnectWork->mEndRequested != 0) {
        FinishScanConnect();
        return;
    }
    CallScanCallbackWithEntry(3, NULL, 0);
}

u32 StartConnectToEntry(u32 entryIndex) {
    Unk02008934 *v1;
    v1 = func_02008934(entryIndex);
    if (v1 == NULL) {
        return 0;
    }
    gScanConnectWork->mUnk_5f08 = v1->mUnk_4b8;
    gScanConnectWork->mUnk_5f0c = v1->mUnk_4b5;
    SetupMPLink((u32) gScanConnectWork->mMPLink);
    SetMPLinkCallback((u32) MPLinkCallback);
    SetScanConnectStateAndNotify(1, 0);
    MI_CpuCopy8(v1->mUnk_4c0, gScanConnectWork->mScanBuffer, 0xc0);
    ScanConnectStartConnect(gScanConnectWork->mScanBuffer);
    return 1;
}

void MPLinkCallback(s32 a, Unk021425e8 *b) {
    u16 v1;
    u16 v2;
    u16 t;
    switch (a) {
        case 7:
        case 8:
            break;
        case 11:
            SetScanConnectStateAndNotify(3, 0);
            break;
        case 6:
            SetScanConnectStateAndNotify(2, b);
            SetPortCallbackAndStartMP(gScanConnectWork, gScanConnectWork->mReceiveBuffer);
            break;
        case 10:
            SetScanConnectStateAndNotify(4, b);
            break;
        case 25:
            QueueStateMessage();
            break;
        case 9:
            ReceivePortMessage(b);
            break;
        case 15:
            if (gScanConnectWork->mState == 10) {
                SetScanConnectStateAndNotify(11, 0);
            } else {
                SetScanConnectStateAndNotify(12, 0);
            }
            if (gScanConnectWork->mEndRequested != 0) {
                FinishScanConnect();
            }
            break;
        case 0xff:
            t = b->mResultCode;
            if (gScanConnectWork->mStateCallback != NULL) {
                switch (t) {
                    case 1:
                    case 4:
                    case 5:
                    case 6:
                    case 8:
                    case 9:
                        t = 9;
                        break;
                    case 15:
                    default:
                        t = 8;
                        break;
                }
                v1 = t;
                gScanConnectWork->mStateCallback(0x13, &v1);
            }
            break;
        case 0x100:
            t = b->mCommand;
            if (gScanConnectWork->mStateCallback != NULL) {
                switch (t) {
                    case 0:
                    case 7:
                    case 8:
                    case 13:
                    case 14:
                    case 15:
                    case 17:
                    case 18:
                    case 21:
                    case 25:
                    case 29:
                        t = 9;
                        break;
                    case 1:
                    default:
                        t = 8;
                        break;
                }
                v2 = t;
                gScanConnectWork->mStateCallback(0x13, &v2);
            }
            break;
        case 0x29:
            break;
    }
}

void ReceivePortMessage(Unk021425e8 *a) {
    Unk0200c0d8 v1;
    func_0200c0d8(&v1, a->mUnk_0c);
    switch (v1.mUnk_00) {
        case 1:
            if (gScanConnectWork->mState == 2) {
                SetScanConnectStateAndNotify(5, 0);
            }
            break;
        case 2:
            if (gScanConnectWork->mState == 5) {
                SetScanConnectStateAndNotify(6, 0);
            }
            break;
        case 6:
            if (gScanConnectWork->mState == 5) {
                SetScanConnectStateAndNotify(0xe, 0);
            }
            break;
        case 3:
            if (gScanConnectWork->mState == 5) {
                SetScanConnectStateAndNotify(7, 0);
            }
            break;
        case 4:
            if (gScanConnectWork->mState == 7) {
                SetScanConnectStateAndNotify(8, 0);
            }
            if (gScanConnectWork->mState == 8) {
                SetScanConnectStateAndNotify(9, 0);
            }
            break;
        case 5:
            if (gScanConnectWork->mState == 9) {
                SetScanConnectStateAndNotify(10, 0);
            } else if (gScanConnectWork->mState == 10) {
                StartResetWithFlag();
            }
            break;
    }
}

void QueueStateMessage(void) {
    Unk0200c16c v1;
    Unk0200c12c v2;
    u8 *p;
    switch (gScanConnectWork->mState) {
        case 5:
            v2.mUnk_00 = gScanConnectWork->mUnk_5f08;
            v2.mUnk_1a = 1;
            v2.mUnk_1c = gScanConnectWork->mUnk_5f0c;
            MI_CpuCopy8(gScanConnectWork->mUnk_05c4, v2.mUnk_04, 0x16);
            v1.mUnk_00 = 7;
            p = &v1.mUnk_00;
            p += 3;
            *(u8 *) &v1.mUnk_02 = func_0200c12c(p, &v2);
            if (func_0200c16c(&v1, gScanConnectWork->mMessageBuffer) != NULL) {
                QueueMPDataIfReady(8, 0xffff, gScanConnectWork->mMessageBuffer);
            }
            break;
        case 7:
            v1.mUnk_00 = 8;
            func_0200c16c(&v1, gScanConnectWork->mMessageBuffer);
            QueueMPDataIfReady(8, 0xffff, gScanConnectWork->mMessageBuffer);
            break;
        case 8:
            break;
        case 9:
            v1.mUnk_00 = 10;
            func_0200c16c(&v1, gScanConnectWork->mMessageBuffer);
            QueueMPDataIfReady(8, 0xffff, gScanConnectWork->mMessageBuffer);
            break;
        case 10:
            v1.mUnk_00 = 11;
            func_0200c16c(&v1, gScanConnectWork->mMessageBuffer);
            QueueMPDataIfReady(8, 0xffff, gScanConnectWork->mMessageBuffer);
            break;
        default:
            v1.mUnk_00 = 0;
            func_0200c16c(&v1, gScanConnectWork->mMessageBuffer);
            QueueMPDataIfReady(8, 0xffff, gScanConnectWork->mMessageBuffer);
            break;
    }
}

#pragma thumb off
