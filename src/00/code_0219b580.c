#include "00/code_0219b580.h"

#include "00/code_0219b000.h"
#include "00/code_0219c954.h"
#include "00/unk_021b5000.h"
#include "00/code_021a10b0.h"
#include "00/code_021a17bc.h"
#include "00/code_0219c000.h"
#include "00/code_021a01dc.h"
#include "00/code_0219a654.h"
#include "00/code_02188720.h"
#include "00/code_0219b1f8.h"
#include "00/code_02198a8c.h"
#include "00/code_0219887c.h"
#include "00/code_0219a000.h"
#include "00/code_021a3264.h"
#include "00/code_02198a84.h"
#include "00/code_021a1ae0.h"
#include "code_0214d018.h"
#include "00/code_0218d488.h"
#include "00/code_0218f960.h"
#include "00/code_02194000.h"
#include "00/code_0218e8d4.h"
#include "00/code_0219c93c.h"
#include "00/code_021a3760.h"
#include "00/code_0219cc00.h"
#include "Main/Unknown/code_02152000.h"
#include "code_02139f70.h"
#include "00/code_0219d128.h"
#include "00/code_021988e8.h"
#include "00/code_0218d000.h"
#include "00/code_0218f15c.h"
#include "00/code_0219c384.h"
#include "00/code_0219d000.h"
#include "00/unk_021b4000.h"
#include "code_0200fc8c.h"
#include "00/unk_021b1000.h"
#include "code_02151868.h"
#include "code_021519d4.h"
#include "00/code_02186a9c.h"
#include "00/code_021acef8.h"
#include "00/code_021a6c08.h"
#include "00/code_0218a67c.h"
#include "00/code_021a6934.h"
#include "00/code_02185954.h"
#include "03/code_021b94b8.h"
#include "00/code_021a369c.h"
#include "00/code_021a2ccc.h"
#include "00/code_021a3a18.h"
#include "00/code_0218a000.h"
#include "00/code_0218b000.h"
#include "00/code_0218c000.h"
#include "00/code_021a3000.h"
#include "00/code_0218aea4.h"
#include "00/code_0219caac.h"
#include "00/code_0219742c.h"
#include "00/code_02196960.h"

// Sets up the object at each login (the caller zeroes the 0xdb4 bytes first, code_0211f6cc.c): stores
// gWiFiConnection, builds the login, buddy, matching and net-layer objects and copies the game name and key. Undone
// by ReleaseWiFiConnection.
void InitWiFiConnection(void *a, void *b, s32 c, const char *d, const char *e, s32 f, s32 g, void *h, s32 i) {
    u32 n;
    u32 m;
    gWiFiConnection = a;
    func_ov000_0219c3b0();
    gWiFiConnection->mSocket = NULL;
    gWiFiConnection->mResultCallback = func_ov000_021a1b2c;
    gWiFiConnection->mDataCallback = func_ov000_0219b4a4;
    gWiFiConnection->mUnk_0c = (s32(*)()) func_ov000_0219b27c;
    gWiFiConnection->mElapsedTimeCallback = func_ov000_0219b274;
    gWiFiConnection->mSendBufferSize = f == 0 ? 0x2000 : f;
    gWiFiConnection->mUnk_18 = g == 0 ? 0x2000 : g;
    gWiFiConnection->mGpConnection.mGpiConnection = NULL;
    gWiFiConnection->mUnk_20 = b;
    gWiFiConnection->mState = 0;
    gWiFiConnection->mPrevState = 0;
    gWiFiConnection->mOwnIndex = 0;
    gWiFiConnection->mUnk_2d = 0;
    gWiFiConnection->mUnk_2e = 0;
    gWiFiConnection->mProfileId = 0;
    gWiFiConnection->mGameName = data_ov000_021b4e84;
    gWiFiConnection->mUnk_58 = data_ov000_021b4f84;
    gWiFiConnection->mLoginCallback = NULL;
    gWiFiConnection->mLoginCallbackArg = 0;
    gWiFiConnection->mBuddySyncCallback = NULL;
    gWiFiConnection->mBuddySyncCallbackArg = NULL;
    gWiFiConnection->mMatchingCallback = NULL;
    gWiFiConnection->mMatchingCallbackArg = NULL;
    gWiFiConnection->mUnk_74 = NULL;
    gWiFiConnection->mUnk_78 = NULL;
    gWiFiConnection->mUnk_7c = NULL;
    gWiFiConnection->mUnk_80 = NULL;
    func_ov000_0219b964();
    InitWiFiLogin(&gWiFiConnection->mLogin, b, &gWiFiConnection->mGpConnection, c, ((Unk02152500 *) b)->mUnk_24,
                  WiFiLoginCallback, NULL);
    InitBuddySync(&gWiFiConnection->mBuddySync, &gWiFiConnection->mGpConnection, gWiFiConnection->mUnk_34, h, i);
    InitMatching(&gWiFiConnection->mMatching, &gWiFiConnection->mGpConnection, &gWiFiConnection->mSocket,
                 &gWiFiConnection->mResultCallback, data_ov000_021b4e84, data_ov000_021b4f84, h, i);
    InitWiFiMessageLayer(&gWiFiConnection->mMessageLayer);
    if (strlen(d) < 0x100) {
        n = strlen(d);
    } else {
        n = 0xff;
    }
    MemCopy(d, data_ov000_021b4e84, n);
    data_ov000_021b4e84[n] = 0;
    if (strlen(e) < 0x100) {
        m = strlen(e);
    } else {
        m = 0xff;
    }
    MemCopy(e, data_ov000_021b4f84, m);
    data_ov000_021b4f84[m] = 0;
}

// Undo of InitWiFiConnection: frees the matching list, closes stats and GP, closes the socket and clears
// gWiFiConnection. Called on failure, leave and logout paths.
void ReleaseWiFiConnection(void) {
    if (gWiFiConnection != NULL) {
        if (gWiFiConnection->mMatching.mUnk_10 != NULL) {
            func_ov000_021a47ac(gWiFiConnection->mMatching.mUnk_10);
            gWiFiConnection->mMatching.mUnk_10 = NULL;
        }
        gWiFiConnection->mMatching.mUnk_18 = 0;
        if (gWiFiConnection->mMatching.mUnk_e4 != NULL) {
            func_ov000_0218b64c(gWiFiConnection->mMatching.mUnk_e4);
            gWiFiConnection->mMatching.mUnk_e4 = NULL;
        }
        func_ov000_0219b110();
        GstatsClose();
        if (gWiFiConnection->mGpConnection.mGpiConnection != NULL) {
            func_ov000_0218f21c(&gWiFiConnection->mGpConnection, 0, NULL, 0);
            func_ov000_0218f21c(&gWiFiConnection->mGpConnection, 3, NULL, 0);
            func_ov000_0218f21c(&gWiFiConnection->mGpConnection, 1, NULL, 0);
            func_ov000_0218f21c(&gWiFiConnection->mGpConnection, 2, NULL, 0);
            GpUpdate(&gWiFiConnection->mGpConnection);
            func_ov000_0218f2a0(&gWiFiConnection->mGpConnection);
            gWiFiConnection->mGpConnection.mGpiConnection = NULL;
        }
        ReleaseWiFiLogin();
        func_ov000_0219d4f8();
        func_ov000_021a1430();
        func_ov000_021a2fec();
        if (gWiFiConnection->mSocket != NULL) {
            func_ov000_02198ab0(gWiFiConnection->mSocket);
            gWiFiConnection->mSocket = NULL;
        }
        gWiFiConnection = NULL;
    }
}

u32 func_ov000_0219c0c8(void) {
    int v1;
    func_ov000_021a3884();
    v1 = func_ov000_021a3760();
    if (v1 != 0) {
        func_ov000_0219c384(9, 0);
        func_ov000_021a37dc();
        return 1;
    }
    return 0;
}

void func_ov000_0219c0c4(void) {
    return;
}

void UpdateWiFiConnection(void) {
    if (func_ov000_0219c0c8() != 0) {
        func_ov000_0219c0c4();
    }
    if (gWiFiConnection == NULL) {
        return;
    }
    if (gWiFiConnection->mState == 0) {
        return;
    }
    if (func_ov000_0219c39c() != 0) {
        return;
    }
    switch (gWiFiConnection->mState) {
        case 1:
            switch (func_ov000_0218d574()) {
                case 1:
                    if (ReportWiFiGpResult(GpInitialize(&gWiFiConnection->mGpConnection,
                                                        gWiFiConnection->mLogin.mProductId, 0)) != 0) {
                        return;
                    }
                    if (ReportWiFiGpResult(func_ov000_0218f21c(&gWiFiConnection->mGpConnection, 0,
                                                               (void (*)(void *, void *, u32)) WiFiGpErrorCallback,
                                                               0)) != 0) {
                        return;
                    }
                    if (ReportWiFiGpResult(func_ov000_0218f21c(&gWiFiConnection->mGpConnection, 3,
                                                               (void (*)(void *, void *, u32)) WiFiGpMessageCallback,
                                                               0)) != 0) {
                        return;
                    }
                    if (ReportWiFiGpResult(
                            func_ov000_0218f21c(&gWiFiConnection->mGpConnection, 1,
                                                (void (*)(void *, void *, u32)) WiFiGpBuddyRequestCallback, 0)) != 0) {
                        return;
                    }
                    if (ReportWiFiGpResult(
                            func_ov000_0218f21c(&gWiFiConnection->mGpConnection, 2,
                                                (void (*)(void *, void *, u32)) WiFiGpBuddyStatusCallback, 0)) != 0) {
                        return;
                    }
                    SetWiFiConnectionState(2);
                    func_ov000_0219ca84();
                    break;
                case 2:
                    ReportWiFiLoginError(3, -20110);
                    return;
                case 3:
                    ReportWiFiLoginError(4, -20101);
                    return;
            }
            break;
        case 2:
            UpdateWiFiLogin();
            break;
        case 3:
        case 4:
            UpdateBuddySync();
            UpdateMatching(0);
            break;
        case 5:
            UpdateMatching(1);
            UpdateBuddySync();
            break;
        case 6:
            UpdateWiFiMessageLayer();
            UpdateBuddySync();
            if (gWiFiConnection->mMatching.mMode == 2 || gWiFiConnection->mMatching.mMode == 3) {
                UpdateMatching(1);
            } else if (gWiFiConnection->mSocket != NULL) {
                UpdateMatching(0);
            }
            break;
    }
    if (gWiFiConnection->mMatching.mUnk_18 == 1) {
        if (gWiFiConnection->mMatching.mUnk_10 != NULL) {
            func_ov000_021a47ac(gWiFiConnection->mMatching.mUnk_10);
            gWiFiConnection->mMatching.mUnk_10 = NULL;
        }
        gWiFiConnection->mMatching.mUnk_18 = 0;
    }
}

// Also stores a and b into the login object (mLogin.mUnk_10 / mUnk_14).
void StartWiFiLogin(u32 a, u32 b, void (*c)(s32 a), u32 d) {
    if (func_ov000_0219c39c() == 0) {
        if (gWiFiConnection->mState == 0) {
            gWiFiConnection->mLoginCallback = c;
            gWiFiConnection->mLoginCallbackArg = d;
            gWiFiConnection->mLogin.mUnk_10 = a;
            gWiFiConnection->mLogin.mUnk_14 = b;
            if (func_ov000_021a3810() != 4) {
                ReportWiFiLoginError(2, -60010);
                return;
            }
            SetWiFiConnectionState(1);
            func_ov000_0218d6e4(gWiFiConnection->mGameName);
        }
    }
}

// The connection-level start (state check, state 4, callbacks); calls StartBuddySync (the two names differ only by
// WiFi). Refused (FALSE) in states 0 to 2 and 4.
BOOL StartWiFiBuddySync(const s8 *a, void (*b)(s32, s32), void *c, void (*d)(u32, u8), void *e, void (*f)(u32, u32),
                        void *g) {
    WiFiConnection *p;
    u32 n;
    if (gWiFiConnection == NULL || func_ov000_0219c39c() != 0 || (p = gWiFiConnection)->mState < 3 || p->mState == 4) {
        return FALSE;
    }
    if (a == NULL || *a == 0) {
        n = 0;
    } else {
        if (strlen((const char *) a) < 0x20) {
            n = strlen((const char *) a);
        } else {
            n = 0x1f;
        }
        MemCopy(a, p->mUnk_34, n);
    }
    gWiFiConnection->mUnk_34[n] = 0;
    gWiFiConnection->mBuddySyncCallback = b;
    gWiFiConnection->mBuddySyncCallbackArg = c;
    SetWiFiConnectionState(4);
    StartBuddySync((s32) gWiFiConnection->mLogin.mAuthToken, gWiFiConnection->mLogin.mUnk_14c,
                   (void (*)(s32, u8, void *)) WiFiBuddySyncCallback, NULL, (void (*)(s32, u8, void *, void *)) d, e,
                   (void (*)(s32, s32, void *)) f, g);
    return TRUE;
}

// Connection-level start: only in state 3 and with no error pending; clears the peer tables, stores the callback pair,
// sets state 5 and calls func_ov000_021a260c.
void StartWiFiMatchingWithFilter(u32 a, void *b, void *c, void *d, void *e, u32 f) {
    if (func_ov000_0219c39c() == 0 && gWiFiConnection->mState == 3) {
        func_ov000_0219b964();
        gWiFiConnection->mMatchingCallback = (void (*)(u32, u32, void *)) c;
        gWiFiConnection->mMatchingCallbackArg = d;
        SetWiFiConnectionState(5);
        func_ov000_021a260c((u8) (a - 1), b, (u32) WiFiMatchingCallback, 0, (u32) e, f);
    }
}

// Connection-level start: only in state 3; stores the callback pair, sets state 5 and calls func_ov000_021a2468 with
// the given list, or with a list of all buddy entries in random order when it is NULL (the one caller passes NULL).
void StartWiFiMatchingWithBuddies(void *a, u32 b, u32 c, u32 d, void *e, void *f, u32 g, u32 h) {
    u8 s[0x40];
    u8 t[0x40];
    u8 i;
    u8 j;
    u8 n;
    if (func_ov000_0219c39c() == 0 && gWiFiConnection->mState == 3) {
        func_ov000_0219b964();
        gWiFiConnection->mMatchingCallback = (void (*)(u32, u32, void *)) e;
        gWiFiConnection->mMatchingCallbackArg = f;
        SetWiFiConnectionState(5);
        if (a != NULL) {
            func_ov000_021a2468(a, b, (u8) (c - 1), d, WiFiMatchingCallback, 0, g, h);
            return;
        }
        i = 0;
        b = 0;
        for (; i < func_ov000_0219d660(); i++) {
            t[i] = func_ov000_021a3448(0x80) + 1;
            b++;
        }
        i = 0;
        for (; i < func_ov000_0219d660(); i++) {
            if (t[i] != 0) {
                j = 0;
                n = 0;
                for (; j < func_ov000_0219d660(); j++) {
                    if (i != j && t[i] < t[j]) {
                        n++;
                    }
                }
                s[n] = i;
            }
        }
        func_ov000_021a2468(s, b, (u8) (c - 1), d, WiFiMatchingCallback, 0, g, h);
    }
}

s32 func_ov000_0219bbfc(void) {
    WiFiConnection *p;
    if (gWiFiConnection == NULL || func_ov000_0219c39c() != 0 ||
        ((p = gWiFiConnection)->mState != 5 && p->mState != 6)) {
        return -1;
    }
    if (p->mMatching.mUnk_0d == 0) {
        func_ov000_0219d558(1, data_ov000_021b4054, NULL);
        func_ov000_0219b110();
        SetWiFiConnectionState(3);
        return 1;
    }
    p->mUnk_2d = 1;
    func_ov000_021988e8(gWiFiConnection->mSocket);
    gWiFiConnection->mUnk_2d = 0;
    return 0;
}

s32 func_ov000_0219bbac(s32 a) {
    void *p;
    if (gWiFiConnection == NULL || func_ov000_0219c39c() != 0 ||
        (gWiFiConnection->mState != 5 && gWiFiConnection->mState != 6)) {
        return -1;
    }
    p = func_ov000_0219b9d4(a);
    if (p == NULL) {
        return -2;
    }
    func_ov000_02198908(p);
    return 0;
}

s32 func_ov000_0219bb68(void) {
    if (gWiFiConnection == NULL) {
        return 0;
    }
    if (gWiFiConnection->mMatching.mMode == 2 || gWiFiConnection->mMatching.mMode == 3) {
        return func_ov000_021a15f8() + 1;
    }
    return func_ov000_021a160c() + 1;
}

u8 func_ov000_0219bb50(void) {
    if (gWiFiConnection != NULL) {
        return gWiFiConnection->mOwnIndex;
    }
    return 0;
}

s32 func_ov000_0219bb04(u8 **a) {
    if (gWiFiConnection == NULL) {
        return 0;
    }
    *a = gWiFiConnection->mMatching.mParticipantIndices;
    if (gWiFiConnection->mMatching.mMode == 2 || gWiFiConnection->mMatching.mMode == 3) {
        return func_ov000_021a1514((void **) a);
    }
    return func_ov000_021a158c((void **) a);
}

BOOL func_ov000_0219bac8(u32 a) {
    if (gWiFiConnection == NULL) {
        return FALSE;
    }
    if ((gWiFiConnection->mMatching.mParticipantMask & (1 << a)) != 0) {
        return func_ov000_0219b8bc(a);
    }
    return FALSE;
}

// 0 when the object is NULL.
u32 GetWiFiConnectionState(void) {
    if (gWiFiConnection != NULL) {
        return gWiFiConnection->mState;
    }
    return 0;
}

s32 func_ov000_0219ba20(void) {
    WiFiConnection *p;
    u32 v;
    s32 r;
    if (gWiFiConnection->mSocket != NULL) {
        return 0;
    }
    v = (u16) (func_ov000_021a3448(0x4000) + 0xc000);
    p = gWiFiConnection;
    r = func_ov000_02198ac4((Gt2Socket **) gWiFiConnection, (const char *) Gt2FormatAddress(0, v, 0),
                            p->mSendBufferSize, p->mUnk_18, (u32) func_ov000_0219b240);
    if (ReportWiFiSocketResult(r) != 0) {
        return r;
    }
    func_ov000_02198a84(gWiFiConnection->mSocket, func_ov000_021a1ca8);
    SetUnmatchedDataCallback(gWiFiConnection->mSocket, (UnkWordFunc *) func_ov000_021a1e40);
    return r;
}

void *func_ov000_0219b9d4(u32 a) {
    s32 i;
    void **p;
    if (gWiFiConnection == NULL) {
        return NULL;
    }
    i = 0;
    p = data_ov000_021b54d0;
    for (; i < 32; p++, i++) {
        if (*p != NULL && a == func_ov000_0219887c(*p)[1]) {
            return data_ov000_021b54d0[i];
        }
    }
    return NULL;
}

u8 func_ov000_0219b9c4(Unk0219887c *object) {
    return func_ov000_0219887c(object)[1];
}

u32 func_ov000_0219b9b4(Unk0219887c *object) {
    return func_ov000_0219887c(object)[0];
}

s32 func_ov000_0219b998(void) {
    s32 i = 0;
    void **slot = data_ov000_021b54d0;
    for (; i < 32; slot++, i++) {
        if (*slot == NULL) {
            return i;
        }
    }
    return -1;
}

void func_ov000_0219b964(void) {
    func_0214d018_inline(data_ov000_021b54d0, 0x80);
    func_0214d018_inline(data_ov000_021b5550, 0x100);
}

void **func_ov000_0219b958(s32 index) {
    return &data_ov000_021b54d0[index];
}

void **func_ov000_0219b8fc(u32 a, s32 b) {
    u8 c;

    for (c = 0; c < b; c++) {
        if (a == gWiFiConnection->mMatching.mParticipantProfileIds[c]) {
            break;
        }
    }
    if (c >= b) {
        return NULL;
    }
    return func_ov000_0219b958(
        func_ov000_0219b9b4(func_ov000_0219b9d4(gWiFiConnection->mMatching.mParticipantIndices[c])));
}

Unk021b5550 *func_ov000_0219b8f0(s32 index) {
    return &data_ov000_021b5550[index];
}

BOOL func_ov000_0219b8bc(u32 a) {
    s32 b;

    for (b = 0; b < 0x20; b++) {
        if (data_ov000_021b54d0[b] != NULL && a == func_ov000_0219887c(data_ov000_021b54d0[b])[1]) {
            return TRUE;
        }
    }
    return FALSE;
}

// Plain setter; also copies the old state into mPrevState (so a Set to the same value overwrites it).
void SetWiFiConnectionState(s32 value) {
    gWiFiConnection->mPrevState = gWiFiConnection->mState;
    gWiFiConnection->mState = value;
}

u32 func_ov000_0219b868(u32 a) {
    void *b;
    s32 d;
    s32 e;

    d = func_ov000_021a158c(&b);
    for (e = 0; e < d; e++) {
        if (a == ((u8 *) b)[e]) {
            break;
        }
    }
    if (e == d) {
        return 0;
    }
    return func_ov000_021a1620(e, d);
}

u32 func_ov000_0219b844(const u8 *values, s32 count) {
    u32 mask = 0;
    s32 i;
    for (i = 0; i < count; i++) {
        mask |= 1 << values[i];
    }
    return mask;
}

// Maps a GP result 1 to 4 to (kind 0xb or 6, code), subtracts an offset chosen by the connection state, reports it to
// the login (states 1 and 2: ReportWiFiLoginError) or the matching object (state 5: func_ov000_021a1a38) and always to
// the buddy object (ReportBuddySyncError); returns the code, 0 passes through.
int ReportWiFiGpResult(int c) {
    s32 a;
    s32 b;

    if (c == 0) {
        return 0;
    }
    switch (c) {
        case 1:
            a = 0xb;
            b = -1;
            break;
        case 2:
            a = 0xb;
            b = -2;
            break;
        case 3:
            a = 6;
            b = -10;
            break;
        case 4:
            a = 6;
            b = -20;
            break;
    }
    switch (gWiFiConnection->mState) {
        case 1:
            b -= 0xee48;
            ReportWiFiLoginError(a, b);
            break;
        case 2:
            b -= 0xee48;
            ReportWiFiLoginError(a, b);
            break;
        case 5:
            b -= 0x13c68;
            func_ov000_021a1a38(a, b);
            break;
        case 4:
            b -= 0x11558;
            break;
        default:
            b -= 0x16378;
            break;
    }
    ReportBuddySyncError(a, b);
    return c;
}

// Maps a CreateSocket result (1 to 7; 2 and 5 mean no error and return 0) to (kind, code) and reports it through
// ReportWiFiLoginError; returns the result.
u32 ReportWiFiSocketResult(u32 a) {
    s32 b;
    s32 c;

    if (a == 0) {
        return 0;
    }
    switch (a) {
        case 1:
            b = 0xb;
            c = -1;
            break;
        case 2:
        case 5:
            b = 0;
            c = 0;
            a = 0;
            break;
        case 3:
            b = 6;
            c = -10;
            break;
        case 4:
            b = 6;
            c = -30;
            break;
        case 6:
            b = 6;
            c = -70;
            break;
        case 7:
            b = 6;
            c = -80;
            break;
    }
    if (b != 0) {
        ReportWiFiLoginError(b, c - 0x105b8);
    }
    return a;
}

// Called by the login object with (0, profile id) on success and (code, 0) on failure; passes the result on to
// mLoginCallback.
void WiFiLoginCallback(int a, u32 b) {
    UnkFunc *v1;
    if (a == 0) {
        gWiFiConnection->mProfileId = b;
        SetWiFiConnectionState(3);
        func_ov000_0219d5bc();
    } else {
        SetWiFiConnectionState(0);
    }
    v1 = gWiFiConnection->mLoginCallback;
    if (v1 != NULL) {
        (*v1)(a, b, gWiFiConnection->mLoginCallbackArg);
    }
    return;
}

void WiFiBuddySyncCallback(u32 a, u32 b) {
    SetWiFiConnectionState((u32) (gWiFiConnection->mPrevState));
    gWiFiConnection->mBuddySyncCallback(a, b, gWiFiConnection->mBuddySyncCallbackArg);
    return;
}

// Result callback of both starts (the matching object's mResultCallback): result 0 with flag 0 sets state 6 and finds
// the own position / mOwnIndex among the participants; result 0 with a flag sets state 3 when no search is running;
// every result rebuilds mParticipantMask and then calls mMatchingCallback (modes 0 and 1) or the unset mode 2/3
// callback.
void WiFiMatchingCallback(u32 a, u32 b, u32 c, u32 d, u32 e) {
    s32 f;
    WiFiConnection *h;

    if (a == 0 && b != 0) {
        if (gWiFiConnection->mMatching.mState == 0) {
            func_ov000_021a1a10();
            SetWiFiConnectionState(3);
        }
    } else if (a == 0) {
        SetWiFiConnectionState(6);
        for (f = 0; f <= gWiFiConnection->mMatching.mUnk_0d; f++) {
            if (gWiFiConnection->mProfileId == gWiFiConnection->mMatching.mParticipantProfileIds[f]) {
                gWiFiConnection->mOwnIndex = gWiFiConnection->mMatching.mParticipantIndices[f];
                break;
            }
        }
    }
    gWiFiConnection->mMatching.mParticipantMask =
        func_ov000_0219b844(gWiFiConnection->mMatching.mParticipantIndices, gWiFiConnection->mMatching.mUnk_0d + 1);
    func_ov000_021a15b0();
    h = gWiFiConnection;
    if (h->mMatching.mMode == 2 || h->mMatching.mMode == 3) {
        h = gWiFiConnection;
        h->mUnk_74(a, b, c, d, e, h->mUnk_78);
    } else {
        h->mMatchingCallback(a, b, h->mMatchingCallbackArg);
    }
}

// GP callback slot 0 (error). Reports error kind 3 through ReportWiFiGpResult only when the GP error number is not
// 0x603 or 0x901.
void WiFiGpErrorCallback(u32 a, int b) {
    if ((*(s32 *) (b + 4) != 0x603) && (*(s32 *) (b + 4) != 0x901)) {
        ReportWiFiGpResult(3);
    }
}
