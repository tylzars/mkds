#include "Main/Unknown/code_0211f6cc.h"
#include "Main/Unknown/code_02060cb4.h"
#include "Main/Unknown/code_0205b0f4.h"
#include "Main/Unknown/code_02060000.h"
#include "Main/Unknown/code_02061000.h"
#include "Main/Unknown/code_02120000.h"
#include "Main/Unknown/code_02121000.h"
#include "Main/Unknown/code_02152000.h"
#include "00/code_0219b000.h"
#include "00/code_0219c000.h"
#include "00/code_0219d000.h"
#include "Main/Unknown/code_0211f6b0.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_02056d40.h"
#include "Main/Unknown/code_0205edcc.h"
#include "Main/Unknown/code_02060c38.h"
#include "00/code_021832d8.h"
#include "00/code_02181f98.h"
#include "00/code_0218d000.h"
#include "00/code_0219d948.h"
#include "00/unk_021b5000.h"
#include "00/code_0219c384.h"
#include "00/code_021a3000.h"
#include "01/code_021956dc.h"
#include "00/code_0219b580.h"
#include "03/code_021b94b8.h"
#include "00/code_021a3760.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"
#include "code_021522a0.h"

void func_0211fef4(u32 fromIndex, void *message, u32 size) {
    if (gWiFiSession->mUnk_0008.mState != 5) {
        return;
    }
    if (gWiFiSession->mUnk_1f38 == FALSE) {
        return;
    }
    if (DoesMessageHeaderMatch(message, size, fromIndex, func_ov000_0219bb50()) != FALSE) {
        return;
    }
    func_0205b504(fromIndex, message, size, 0);
}

void func_0211fe44(void) {
    if (gWiFiSession->mBuddiesChanged == FALSE) {
        return;
    }
    CopyWiFiBuddiesToRecordBlock(&gWiFiSession->mBuddies[0]);
    RefreshNotYetBuddyFlags();
    func_0205edf8();
    while (data_0217aa08->mBusy == 0 ? (gBackupAccess->mBackupEnabled != 0 ? gBackupAccess->mCommandRunning : 0) : 1) {
    }
    gWiFiSession->mBuddiesChanged = FALSE;
}

void RequestWiFiSessionLogin(void) {
    Unk0217d384_08 *stateMachine;

    stateMachine = &gWiFiSession->mUnk_0008;
    stateMachine->mNextState = 1;
    stateMachine->mNextStateRequested = 1;
}

void func_0211fe18(void) {
    ReleaseWiFiConnection();
}

u32 func_0211fda8(void) {
    Unk0217d384_08 *stateMachine;

    if (gWiFiSession->mUnk_0008.mState == 0) {
        return 1;
    }
    if (func_ov000_021a377c() == FALSE) {
        return 0;
    }
    ResetWiFiSession();
    stateMachine = &gWiFiSession->mUnk_0008;
    stateMachine->mNextState = 0;
    stateMachine->mNextStateRequested = 1;
    return 1;
}

s32 GetWiFiSessionLoginResult(void) {
    switch (gWiFiSession->mLogin.mStep) {
        case 5:
            return 1;
        case 7:
            return -1;
        default:
            return 0;
    }
}

void func_0211fd28(void) {
    Unk0217d384_08 *stateMachine;

    ReleaseWiFiConnection();
    func_ov000_021a37dc();
    ResetWiFiSession();
    stateMachine = &gWiFiSession->mUnk_0008;
    stateMachine->mNextState = 0;
    stateMachine->mNextStateRequested = 1;
}

void SetupWiFiSessionLogin(void) {
    u8 i;
    WiFiSession *session;

    MI_CpuFill8(&gWiFiSession->mLogin, 0, 0x10);
    MI_CpuFill8(&gWiFiSession->mUserData, 0, 0x350);
    MI_CpuFill8(&gWiFiSession->mConnection, 0, 0xe24);
    if (func_02061290() != 0) {
        MI_CpuCopy8(&data_0217aa08->mFirstBlock->mUserData, &gWiFiSession->mUserData, 0x40);
    } else {
        DWC_CreateUserData((DWCAccUserData *) &gWiFiSession->mUserData, 0x414d434a);
    }
    func_02060c38(&gWiFiSession->mBuddies[0]);
    func_ov000_021a39c4(&gWiFiSession->mLogin);
    func_ov000_021a397c(2);
    func_ov000_021a3910();
    i = 0;
    if (func_ov000_0219d9b0(&gWiFiSession->mBuddies[0], 0x3c) > 0) {
        do {
            i++;
        } while (i < func_ov000_0219d9b0(&gWiFiSession->mBuddies[0], 0x3c));
    }
    session = gWiFiSession;
    InitWiFiConnection(&session->mConnection, &session->mUserData, 0x4d6, "mariokartds", "yeJ3x8", 0, 0,
                       &session->mBuddies[0], 0x3c);
    gWiFiSession->mUnk_1f44 = 0;
    gWiFiSession->mUnk_1f48 = 0;
    gWiFiSession->mLogin.mStep = 1;
}

void func_0211fa70(void) {
    if (func_ov000_021a38d8() == 0) {
        func_ov000_021a3884();
        return;
    }
    switch (func_ov000_021a3810()) {
        case 4:
            StartWiFiLogin(0, 0, WiFiSessionLoginCallback, 0);
            gWiFiSession->mLogin.mStep = 2;
            break;
        case 7:
            gWiFiSession->mUnk_1f44 = func_ov000_0219c3cc(&gWiFiSession->mUnk_1f48);
            ReleaseWiFiConnection();
            func_ov000_021a37dc();
            gWiFiSession->mLogin.mStep = 7;
            break;
        case 8:
            break;
    }
}

u32 UpdateWiFiSessionLogin(void) {
    switch (gWiFiSession->mLogin.mStep) {
        case 1:
            func_0211fa70();
            break;
        case 3:
            if (data_0217aa08->mBusy == 0 ? (gBackupAccess->mBackupEnabled != 0 ? gBackupAccess->mCommandRunning : 0)
                                          : 1) {
                break;
            }
            DWC_ReportUserData((DWCAccUserData *) &gWiFiSession->mUserData);
            if (StartWiFiBuddySync(NULL, WiFiSessionBuddySyncCallback, NULL, SetBuddyStatus, NULL, func_0211f6e8,
                                   NULL) == 0) {
                gWiFiSession->mLogin.mStep = 7;
            }
            SetBuddyChangedCallback((void *) BuddyChangedCallback, NULL);
            gWiFiSession->mLogin.mStep = 4;
            break;
        case 6:
            ReleaseWiFiConnection();
            func_ov000_021a37dc();
            gWiFiSession->mLogin.mStep = 7;
            break;
        case 5:
            return 1;
        case 7:
            break;
    }
    return 0;
}

void WiFiSessionLoginCallback(s32 result) {
    if (result == 0) {
        if (DWCi_Acc_IsDirty((DWCAccUserData *) &gWiFiSession->mUserData) != 0) {
            DWCi_Acc_ClearDirty((DWCAccUserData *) &gWiFiSession->mUserData);
            MI_CpuCopy8(&gWiFiSession->mUserData, &data_0217aa08->mFirstBlock->mUserData, 0x40);
            func_02056d40();
        }
        gWiFiSession->mLogin.mStep = 3;
    } else {
        gWiFiSession->mLogin.mStep = 6;
    }
}

void WiFiSessionBuddySyncCallback(s32 result, s32 changed) {
    u8 i;

    if (result == 0) {
        if (changed != 0) {
            gWiFiSession->mBuddiesChanged = TRUE;
        }
        i = 0;
        if (func_ov000_0219d9b0(&gWiFiSession->mBuddies[0], 0x3c) > 0) {
            do {
                DWC_ReportFriendData((DWCAccUserData *) &gWiFiSession->mUserData,
                                     (DWCAccFriendData *) &gWiFiSession->mBuddies[i]);
                i++;
            } while (i < func_ov000_0219d9b0(&gWiFiSession->mBuddies[0], 0x3c));
        }
        gWiFiSession->mLogin.mStep = 5;
    } else {
        ReleaseWiFiConnection();
        func_ov000_021a37dc();
        gWiFiSession->mLogin.mStep = 7;
    }
}

void func_0211f6e8(u32 a, u32 b) {
    MergeBuddyRecords(b, a);
    CopyWiFiBuddiesToRecordBlock(&gWiFiSession->mBuddies[0]);
    RefreshNotYetBuddyFlags();
    func_0205edf8();
    while (data_0217aa08->mBusy == 0 ? (gBackupAccess->mBackupEnabled != 0 ? gBackupAccess->mCommandRunning : 0) : 1) {
    }
}

void SetBuddyStatus(u32 index, u8 status) {
    gWiFiSession->mBuddyStatuses[index] = status;
}
