#include "00/code_0219caac.h"
#include "code_0214d018.h"

u32 func_ov000_0219caf4(void) {
    return gWiFiBuddySync->mPendingStatsRequestCount;
}

// Per login (called by InitWiFiConnection after the caller zeroed the connection; not once at boot): stores gWiFiLogin,
// zeroes the 0x264 bytes and stores the GP connection, product id, saved record and the callback pair. Pair of
// ReleaseWiFiLogin.
void InitWiFiLogin(WiFiLogin *a, Unk02152500 *b, GpConnection *c, u32 d, u32 e, void (*f)(), void *g) {
    gWiFiLogin = a;
    MemFill(a, 0, 0x264);
    gWiFiLogin->mGpConnection = c;
    gWiFiLogin->mState = 0;
    gWiFiLogin->mProductId = d;
    gWiFiLogin->mUnk_0c = e;
    gWiFiLogin->mResultCallback = f;
    gWiFiLogin->mResultCallbackArg = g;
    gWiFiLogin->mUnk_20 = b;
}
