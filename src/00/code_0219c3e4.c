#include "00/code_0219c3e4.h"

#include "00/code_0219c954.h"
#include "00/code_0219d128.h"
#include "00/unk_021b5000.h"
#include "00/code_0219c93c.h"
#include "Main/Unknown/code_0200f000.h"
#include "00/code_0219c000.h"
#include "00/code_0218f15c.h"
#include "00/code_02190000.h"
#include "00/code_0218f960.h"
#include "00/code_02194000.h"
#include "00/code_0218e8d4.h"
#include "00/code_02187484.h"
#include "03/code_021b94b8.h"
#include "00/code_021a369c.h"
#include "00/code_021a1ae0.h"
#include "code_0200f5ac.h"
#include "code_02133048.h"
#include "code_021329f8.h"
#include "code_02139f70.h"
#include "code_0214d018.h"
#include "code_02152500.h"
#include "code_021526bc.h"
#include "code_021526e4.h"
#include "code_02152a7c.h"
#include "Main/Unknown/code_021526c8.h"
#include "00/code_0218f000.h"
#include "00/code_0219b000.h"
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
#include "00/code_0219c384.h"
#include "00/code_02198a8c.h"
#include "00/code_0219b580.h"

void func_ov000_0219ca84(void) {
    StartWiFiLoginRequest(WiFiLoginRequestCallback, NULL);
    gWiFiLogin->mState = 1;
    gWiFiLogin->mConnectPending = FALSE;
}

// One step per connection frame in state 2 (UpdateWiFiConnection returns first when an error is pending); mState 1 runs
// UpdateWiFiLoginRequest, 2 to 4 pump GpUpdate and time the GP connect out (60 s), 5 does nothing.
void UpdateWiFiLogin(void) {
    WiFiLogin *p;
    if (gWiFiLogin == NULL || func_ov000_0219c39c() != 0) {
        return;
    }
    p = gWiFiLogin;
    switch (p->mState) {
        case 1:
            UpdateWiFiLoginRequest();
            break;
        case 2:
        case 3:
        case 4:
            if (p->mGpConnection != NULL && p->mGpConnection->mGpiConnection != NULL) {
                GpUpdate(p->mGpConnection);
            }
            if (gWiFiLogin->mConnectPending != FALSE) {
                if ((((u64) OS_GetTick() - gWiFiLogin->mConnectStartTime) << 6) / 0x82ea > 0xea60) {
                    ReportWiFiLoginError(6, -61070);
                    gWiFiLogin->mConnectPending = FALSE;
                }
            }
            break;
        case 5:
            break;
    }
}

DWCAccUserData *func_ov000_0219c9c4(void) {
    if (gWiFiLogin != NULL) {
        return gWiFiLogin->mUnk_20;
    }
    return NULL;
}

// Records the (kind, code) pair, calls mResultCallback with the kind and resets the machine (ResetWiFiLogin); does
// nothing when the object is NULL or the kind is 0. Same extent as ReportBuddySyncError (which closes the stats link).
void ReportWiFiLoginError(s32 a, s32 b) {
    if (gWiFiLogin != NULL && a != 0) {
        func_ov000_0219c384(a, b);
        if (gWiFiLogin->mResultCallback != NULL) {
            gWiFiLogin->mResultCallback(a, 0, gWiFiLogin->mResultCallbackArg);
        }
        ResetWiFiLogin();
    }
}

// Frees the Http (cancel and close the request first) and sets gWiFiLogin to 0; the object itself is part of
// WiFiConnection and is not freed. Called by ReleaseWiFiConnection; no NULL test of gWiFiLogin.
void ReleaseWiFiLogin(void) {
    if (gWiFiLogin->mHttp != NULL) {
        DWC_Auth_Abort();
        DWC_Auth_Destroy();
        func_ov000_021a3704(0, (u32) gWiFiLogin->mHttp, 0);
        gWiFiLogin->mHttp = NULL;
    }
    *(s32 *) &gWiFiLogin = 0;
}

// Writes the start values back (mState 0, mConnectPending FALSE) when the object exists; called by
// ReportWiFiLoginError. Keeps the Http and the strings (ReleaseWiFiLogin frees the Http).
void ResetWiFiLogin(void) {
    if (gWiFiLogin != NULL) {
        gWiFiLogin->mState = 0;
        gWiFiLogin->mConnectPending = FALSE;
    }
}

// Maps a GP result code 1 to 4 to (kind 0xb or 6, code -61001, -61002, -61010, -61020) and passes it to
// ReportWiFiLoginError (login offset 0xee48 = 61000), returning the result; 0 returns 0 at once. Results above 4 have
// no case.
s32 ReportWiFiLoginGpResult(s32 a) {
    s32 x;
    s32 y;
    if (a == 0) {
        return 0;
    }
    switch (a) {
        case 1:
            x = 0xb;
            y = -1;
            break;
        case 2:
            x = 0xb;
            y = -2;
            break;
        case 3:
            x = 6;
            y = -10;
            break;
        case 4:
            x = 6;
            y = -20;
            break;
    }
    ReportWiFiLoginError(x, y - 0xee48);
    return a;
}

// Callback of the GP connect, given by StartWiFiLoginGpConnect: clears mConnectPending; on success in mState 2 checks
// the saved record's profile id, then (func_ov000_0219ba20, func_ov000_021a2768 with the profile id) sets mState 5 and
// reports success through mResultCallback (id mismatch: error 6); in mState 3 calls func_ov000_0218eff8 with the
// profile id and func_ov000_0219c400 as its callback; a GP error goes to ReportWiFiLoginGpResult.
void WiFiLoginGpConnectCallback(GpConnection *a, Unk0219c400 *b, u32 c) {
    gWiFiLogin->mConnectPending = FALSE;
    if (b->mUnk_00 == 0) {
        if (gWiFiLogin->mState == 2) {
            if (ReportWiFiLoginGpResult(func_ov000_0219d558(1, data_ov000_021b4064, NULL)) == 0) {
                if (gWiFiLogin->mUnk_20->mGsProfileId == b->mUnk_04) {
                    if (func_ov000_0219ba20() == 0 && func_ov000_021a2768(b->mUnk_04) == 0) {
                        gWiFiLogin->mState = 5;
                        gWiFiLogin->mResultCallback(0, b->mUnk_04, gWiFiLogin->mResultCallbackArg);
                    }
                } else {
                    ReportWiFiLoginError(6, -60000);
                }
            }
        } else if (gWiFiLogin->mState == 3) {
            if (ReportWiFiLoginGpResult(func_ov000_0218eff8(a, b->mUnk_04, 0, 0, func_ov000_0219c400, 0)) != 0) {
                return;
            }
        }
    } else {
        ReportWiFiLoginGpResult(b->mUnk_00);
    }
}

// The stored done callback of StartWiFiLoginRequest: called through data_ov000_021b5660 with (auth token, second
// string, arg) when the reply is in hand (code_0219c3e4.c:263) and after the profile check (:314); ignores arg and
// starts the GP connect with state 2 (StartWiFiLoginGpConnect with WiFiLoginGpConnectCallback).
void WiFiLoginRequestCallback(char *a, char *b) {
    StartWiFiLoginGpConnect(a, b, WiFiLoginGpConnectCallback, 2);
}

// Copies the token and the second string, sets mConnectStartTime and mConnectPending, starts the GP connect
// (func_ov000_0218f15c) with callback c, reporting a failed start through ReportWiFiLoginGpResult, and only when it
// started sets mState to d (2 from WiFiLoginRequestCallback, 3 from UpdateWiFiLoginRequest); UpdateWiFiLogin then pumps
// GpUpdate and times the connect out.
void StartWiFiLoginGpConnect(char *a, char *b, void (*c)(), s32 d) {
    WiFiLogin *v1;
    u32 v2;
    u64 v3;
    WiFiLogin *v4;
    strcpy(gWiFiLogin->mAuthToken, a);
    strcpy(gWiFiLogin->mUnk_14c, b);
    v4 = gWiFiLogin;
    v3 = OS_GetTick();
    v4->mConnectStartTime = v3;
    v4->mConnectPending = TRUE;
    v1 = gWiFiLogin;
    v2 = ReportWiFiLoginGpResult(func_ov000_0218f15c(v1->mGpConnection, v1->mAuthToken, v1->mUnk_14c, 1, 0, c, 0));
    if (v2 == 0) {
        gWiFiLogin->mState = d;
    }
}

// Stores the done callback and its argument in two globals (data_ov000_021b5660 / data_ov000_021b5658), formats the
// login id text (from the saved record's id, or from a 12-byte id it takes or makes), allocates the Http (0x1a60),
// records the start time and issues the request; UpdateWiFiLoginRequest polls the reply. Called by func_ov000_0219ca84
// and by the profile check func_ov000_0219c400, which restarts the request.
void StartWiFiLoginRequest(void (*a)(), void *b) {
    AuthCreateParams s;
    void *h;
    u64 t;
    MI_CpuFill8(&s, 0, 0x2c);
    data_ov000_021b5660 = a;
    data_ov000_021b5658 = b;
    if (DWCi_Acc_IsAuthentic(gWiFiLogin->mUnk_20) != 0) {
        DWCi_Acc_LoginIdToUserName(&gWiFiLogin->mUnk_20->mAuthentic, gWiFiLogin->mUnk_20->mGamecode,
                                   gWiFiLogin->mUnk_24c);
    } else {
        if (func_021526c8(&gWiFiLogin->mUnk_40) == 0) {
            if (DWCi_Acc_CheckConsoleUserId(&gWiFiLogin->mUnk_20->mPseudo) != 0) {
                gWiFiLogin->mUnk_40 = gWiFiLogin->mUnk_20->mPseudo;
            } else {
                DWCi_Acc_CreateTempLoginId(&gWiFiLogin->mUnk_40);
            }
        } else {
            DWCi_Acc_SetPlayerId(&gWiFiLogin->mUnk_40, ((s64) OS_GetTick() * 0x5d588b656c078965 + 0x269ec3) >> 32);
        }
        DWCi_Acc_LoginIdToUserName(&gWiFiLogin->mUnk_40, gWiFiLogin->mUnk_0c, gWiFiLogin->mUnk_24c);
    }
    strcpy(s.mGsbrcd, gWiFiLogin->mUnk_255);
    s.mAlloc = (void *(*) (const void *, u32)) func_ov000_021a372c;
    s.mFree = (void (*)(const void *, void *, u32)) func_ov000_021a3704;
    h = func_ov000_021a3718(0, 0x1a60, 4);
    gWiFiLogin->mHttp = h;
    t = OS_GetTick();
    gWiFiLogin->mRequestStartTime = t;
    DWC_Auth_Create(&s, h);
}

// State 1 step of UpdateWiFiLogin (every frame while mState is 1): when the reply is done (status 0x14) copies the
// token and the second string, frees the Http and goes on through the stored callback (when DWCi_Acc_IsAuthentic
// accepts the saved record) or StartWiFiLoginGpConnect with state 3; while the request runs, reports error 2 after 10
// s, otherwise closes it and issues it again.
void UpdateWiFiLoginRequest(void) {
    AuthCreateParams s;
    Unk0218635c x;
    Unk0218635c y;
    if (DWC_Auth_GetError() == 0x14) {
        func_ov000_0218635c(&x.mUnk_000);
        strcpy(gWiFiLogin->mAuthToken, x.mUnk_04a);
        strcpy(gWiFiLogin->mUnk_14c, x.mUnk_177);
        DWC_Auth_Destroy();
        func_ov000_021a3704(0, (u32) gWiFiLogin->mHttp, 0);
        gWiFiLogin->mHttp = NULL;
        if (DWCi_Acc_IsAuthentic(gWiFiLogin->mUnk_20) != 0) {
            data_ov000_021b5660(gWiFiLogin->mAuthToken, gWiFiLogin->mUnk_14c, data_ov000_021b5658);
        } else {
            StartWiFiLoginGpConnect(gWiFiLogin->mAuthToken, gWiFiLogin->mUnk_14c, WiFiLoginGpConnectCallback, 3);
        }
    } else if (DWC_Auth_GetError() != 0) {
        if ((((u64) OS_GetTick() - gWiFiLogin->mRequestStartTime) << 6) / 0x82ea > 0x2710) {
            func_ov000_0218635c(&y.mUnk_000);
            DWC_Auth_Destroy();
            func_ov000_021a3704(0, (u32) gWiFiLogin->mHttp, 0);
            gWiFiLogin->mHttp = NULL;
            ReportWiFiLoginError(2, y.mUnk_000);
        } else {
            DWC_Auth_Destroy();
            MI_CpuFill8(&s, 0, 0x2c);
            strcpy(s.mGsbrcd, gWiFiLogin->mUnk_255);
            s.mAlloc = (void *(*) (const void *, u32)) func_ov000_021a372c;
            s.mFree = (void (*)(const void *, void *, u32)) func_ov000_021a3704;
            DWC_Auth_Create(&s, gWiFiLogin->mHttp);
        }
    }
}

void func_ov000_0219c400(GpConnection *a, Unk0219c400 *b, u32 f) {
    char c[0x15];
    char d[0x15];
    char e[0x15];
    WiFiLogin *p;
    if (b->mUnk_00 != 0) {
        return;
    }
    p = gWiFiLogin;
    if (p->mState == 3) {
        if (b->mUnk_8e[0] == 0) {
            DWCi_Acc_LoginIdToUserName(&p->mUnk_20->mPseudo, p->mUnk_0c, c);
            if (ReportWiFiLoginGpResult(func_ov000_0218efa8(a, 0x705, (const s8 *) c)) == 0) {
                gWiFiLogin->mState = 4;
                if (ReportWiFiLoginGpResult(func_ov000_0218eff8(a, b->mUnk_04, 0, 0, func_ov000_0219c400, 0)) != 0) {
                    return;
                }
            }
        } else {
            GpDisconnect(a);
            StartWiFiLoginRequest(WiFiLoginRequestCallback, NULL);
            gWiFiLogin->mState = 1;
        }
    } else if (p->mState == 4) {
        DWCi_Acc_LoginIdToUserName(&p->mUnk_20->mPseudo, p->mUnk_0c, d);
        if (strcmp((const char *) b->mUnk_8e, d) == 0) {
            DWCi_Acc_LoginIdToUserName(&gWiFiLogin->mUnk_40, gWiFiLogin->mUnk_0c, e);
            DWCi_Acc_SetLoginIdToUserData(gWiFiLogin->mUnk_20, &gWiFiLogin->mUnk_40, b->mUnk_04);
            GpDisconnect(a);
            data_ov000_021b5660(gWiFiLogin->mAuthToken, gWiFiLogin->mUnk_14c, data_ov000_021b5658);
        } else {
            if (ReportWiFiLoginGpResult(func_ov000_0218eff8(a, b->mUnk_04, 0, 0, func_ov000_0219c400, 0)) != 0) {
                return;
            }
        }
    }
}

// 1 only in mState 5 (set on success by WiFiLoginGpConnectCallback), 0 when the object is NULL; the buddy sync gates on
// it (code_0219cfc0.c:18) and RemoveBuddyEntry tests it (code_0219d948.c:80).
u32 IsWiFiLoginDone(void) {
    if ((gWiFiLogin != NULL) && (gWiFiLogin->mState == 5)) {
        return 1;
    }
    return 0;
}
