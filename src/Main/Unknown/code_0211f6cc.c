#include "Main/Unknown/code_02060cb4.h"
#include "Main/Unknown/code_0211f6cc.h"
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

void func_0211fef4(u32 a, void *b, u32 c) {
    if (gWiFiSession->mUnk_0008.mState != 5) {
        return;
    }
    if (gWiFiSession->mUnk_1f38 == FALSE) {
        return;
    }
    if (func_02121990(b, c, a, func_ov000_0219bb50()) != FALSE) {
        return;
    }
    func_0205b504(a, b, c, 0);
}

void func_0211fe44(void) {
    if (gWiFiSession->mUnk_1cfc == FALSE) {
        return;
    }
    func_02060c0c(&gWiFiSession->mBuddies[0]);
    func_02060b68();
    func_0205edf8();
    while (data_0217aa08->mUnk_28 == 0 ? (data_021759d4->mUnk_0c != 0 ? data_021759d4->mUnk_10 : 0) : 1) {
    }
    gWiFiSession->mUnk_1cfc = FALSE;
}

void func_0211fe24(void) {
    Unk0217d384_08 *q;

    q = &gWiFiSession->mUnk_0008;
    q->mNextState = 1;
    q->mNextStateRequested = 1;
}

void func_0211fe18(void) {
    func_ov000_0219c0f4();
}

u32 func_0211fda8(void) {
    Unk0217d384_08 *q;

    if (gWiFiSession->mUnk_0008.mState == 0) {
        return 1;
    }
    if (func_ov000_021a377c() == FALSE) {
        return 0;
    }
    ResetWiFiSession();
    q = &gWiFiSession->mUnk_0008;
    q->mNextState = 0;
    q->mNextStateRequested = 1;
    return 1;
}

s32 func_0211fd68(void) {
    switch (gWiFiSession->mUnk_1f20.mStep) {
        case 5:
            return 1;
        case 7:
            return -1;
        default:
            return 0;
    }
}

void func_0211fd28(void) {
    Unk0217d384_08 *q;

    func_ov000_0219c0f4();
    func_ov000_021a37dc();
    ResetWiFiSession();
    q = &gWiFiSession->mUnk_0008;
    q->mNextState = 0;
    q->mNextStateRequested = 1;
}

void func_0211fb44(void) {
    u8 i;
    WiFiSession *p;

    MemFill(&gWiFiSession->mUnk_1f20, 0, 0x10);
    MemFill(&gWiFiSession->mUnk_19b0, 0, 0x350);
    MemFill(&gWiFiSession->mUnk_0b2c, 0, 0xe24);
    if (func_02061290() != 0) {
        MemCopy(&data_0217aa08->mUnk_00->mUnk_4c, &gWiFiSession->mUnk_19b0, 0x40);
    } else {
        func_02152690(&gWiFiSession->mUnk_19b0, 0x414d434a);
    }
    func_02060c38(&gWiFiSession->mBuddies[0]);
    func_ov000_021a39c4(&gWiFiSession->mUnk_1f20);
    func_ov000_021a397c(2);
    func_ov000_021a3910();
    i = 0;
    if (func_ov000_0219d9b0(&gWiFiSession->mBuddies[0], 0x3c) > 0) {
        do {
            i++;
        } while (i < func_ov000_0219d9b0(&gWiFiSession->mBuddies[0], 0x3c));
    }
    p = gWiFiSession;
    func_ov000_0219c1e4(&p->mUnk_0b2c, &p->mUnk_19b0, 0x4d6, "mariokartds", "yeJ3x8", 0, 0, &p->mBuddies[0], 0x3c);
    gWiFiSession->mUnk_1f44 = 0;
    gWiFiSession->mUnk_1f48 = 0;
    gWiFiSession->mUnk_1f20.mStep = 1;
}

void func_0211fa70(void) {
    if (func_ov000_021a38d8() == 0) {
        func_ov000_021a3884();
        return;
    }
    switch (func_ov000_021a3810()) {
        case 4:
            func_ov000_0219bea8(0, 0, func_0211f864, 0);
            gWiFiSession->mUnk_1f20.mStep = 2;
            break;
        case 7:
            gWiFiSession->mUnk_1f44 = func_ov000_0219c3cc(&gWiFiSession->mUnk_1f48);
            func_ov000_0219c0f4();
            func_ov000_021a37dc();
            gWiFiSession->mUnk_1f20.mStep = 7;
            break;
        case 8:
            break;
    }
}

u32 func_0211f91c(void) {
    switch (gWiFiSession->mUnk_1f20.mStep) {
        case 1:
            func_0211fa70();
            break;
        case 3:
            if (data_0217aa08->mUnk_28 == 0 ? (data_021759d4->mUnk_0c != 0 ? data_021759d4->mUnk_10 : 0) : 1) {
                break;
            }
            func_02152324(&gWiFiSession->mUnk_19b0);
            if (func_ov000_0219bdec(NULL, func_0211f77c, NULL, func_0211f6cc, NULL, func_0211f6e8, NULL) == 0) {
                gWiFiSession->mUnk_1f20.mStep = 7;
            }
            func_ov000_0219d934((void *) func_0211f6b0, NULL);
            gWiFiSession->mUnk_1f20.mStep = 4;
            break;
        case 6:
            func_ov000_0219c0f4();
            func_ov000_021a37dc();
            gWiFiSession->mUnk_1f20.mStep = 7;
            break;
        case 5:
            return 1;
        case 7:
            break;
    }
    return 0;
}

void func_0211f864(s32 a) {
    if (a == 0) {
        if (func_021525e0(&gWiFiSession->mUnk_19b0) != 0) {
            func_021525a8(&gWiFiSession->mUnk_19b0);
            MemCopy(&gWiFiSession->mUnk_19b0, &data_0217aa08->mUnk_00->mUnk_4c, 0x40);
            func_02056d40();
        }
        gWiFiSession->mUnk_1f20.mStep = 3;
    } else {
        gWiFiSession->mUnk_1f20.mStep = 6;
    }
}

void func_0211f77c(s32 a, s32 b) {
    u8 i;

    if (a == 0) {
        if (b != 0) {
            gWiFiSession->mUnk_1cfc = TRUE;
        }
        i = 0;
        if (func_ov000_0219d9b0(&gWiFiSession->mBuddies[0], 0x3c) > 0) {
            do {
                func_02152340(&gWiFiSession->mUnk_19b0, &gWiFiSession->mBuddies[i]);
                i++;
            } while (i < func_ov000_0219d9b0(&gWiFiSession->mBuddies[0], 0x3c));
        }
        gWiFiSession->mUnk_1f20.mStep = 5;
    } else {
        func_ov000_0219c0f4();
        func_ov000_021a37dc();
        gWiFiSession->mUnk_1f20.mStep = 7;
    }
}

void func_0211f6e8(u32 a, u32 b) {
    func_02060510(b, a);
    func_02060c0c(&gWiFiSession->mBuddies[0]);
    func_02060b68();
    func_0205edf8();
    while (data_0217aa08->mUnk_28 == 0 ? (data_021759d4->mUnk_0c != 0 ? data_021759d4->mUnk_10 : 0) : 1) {
    }
}

void func_0211f6cc(u32 a, u8 b) {
    gWiFiSession->mBuddyStatuses[a] = b;
}
