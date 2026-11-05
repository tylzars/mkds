#pragma once

#include "types.h"
#include "code_02152490.h"
#include "code_02152500.h"
#include "00/code_0218f960.h"

// Login machine, embedded in WiFiConnection at 0x84 (0x264 bytes = the MemFill of InitWiFiLogin), reached through
// gWiFiLogin and stepped by UpdateWiFiLogin in connection state 2. mState 1 waits for the HTTP reply that holds the
// auth token and a second string; 2 to 4 run the GP connect with them (state 2: check the saved record's profile id,
// make the socket, done; state 3 then 4: profile name check in func_ov000_0219c400, which can send the machine back to
// state 1); 5 is done. It is not strictly two logins in turn.
typedef struct WiFiLogin {
    /* 00 */ GpConnection *mGpConnection;
    // 0 idle, 1 waiting for the HTTP reply, 2 GP connect for a known profile (success: id check, socket, done), 3 GP
    // connect then 4 profile name check (func_ov000_0219c400), 5 done. Written only by the machine; 0 is
    // func_ov000_0219c93c.
    /* 04 */ s32 mState;
    // Game id 0x4d6 (InitWiFiConnection's fourth parameter): given to GpInitialize, which stores it as
    // GpiConnection.mProductId (code_0218f848.c:31) and writes it after '\productid\' (code_02190ff8.c:260).
    /* 08 */ u32 mProductId;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    // Set by InitWiFiLogin (WiFiLoginCallback). Called with (error kind, 0, arg) by ReportWiFiLoginError and with (0,
    // profile id, arg) when state 2 succeeds.
    /* 18 */ void (*mResultCallback)();
    /* 1c */ void *mResultCallbackArg;
    /* 20 */ Unk02152500 *mUnk_20;
    /* 24 */ u8 pad_24[4];
    // Http (0x1a60 bytes; declared void *) of the running request: made by func_ov000_0219c67c, freed when the reply or
    // an error ends the request and by ReleaseWiFiLogin.
    /* 28 */ void *mHttp;
    /* 2c */ u32 mUnk_2c;
    /* 30 */ u32 mUnk_30;
    // TRUE from func_ov000_0219c79c until the GP connect callback or an error; UpdateWiFiLogin times the connect out
    // while it is TRUE.
    /* 34 */ BOOL mConnectPending;
    // func_0200f5ac reading when the GP connect started; (ticks << 6) / 0x82ea is ms, limit 60000 ms (UpdateWiFiLogin).
    /* 38 */ u64 mConnectStartTime;
    /* 40 */ Unk02152490 mUnk_40;
    // First string of the HTTP reply (0x100 buffer): given to the GP connect as its first credential, which
    // GpiWriteLogin writes after '\authtoken\' (code_02190ff8.c:232-233); also passed to StartBuddySync (stats login).
    // The reply's second string (mUnk_14c) is the password substitute the library hashes (code_02190ff8.c:205-210), not
    // the library's '\challenge\' (a random string the library makes, :204, :229-230).
    /* 4c */ char mAuthToken[0x100];
    // Second string of the HTTP reply (0x100 buffer), the second GP connect credential: GpiStartConnect copies it to
    // q->mUnk_1c2 and GpiWriteLogin hashes it where it would hash the password (code_02190ff8.c:205-210). Not the
    // library's \challenge\ value.
    /* 14c */ char mUnk_14c[0x100];
    /* 24c */ char mUnk_24c[9];
    /* 255 */ char mUnk_255[0xf];
} WiFiLogin;

// Points at WiFiConnection.mLogin: set by InitWiFiLogin (once per login), set to 0 by ReleaseWiFiLogin.
extern WiFiLogin *gWiFiLogin;

void func_ov000_0219c93c(void);
