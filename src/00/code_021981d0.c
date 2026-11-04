#include "00/code_0218db48.h"
#include "00/code_0218dd8c.h"
#include "00/code_02197e8c.h"
#include "00/code_021981d0.h"
#include "00/code_0218d000.h"
#include "00/code_0219a0d0.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "00/code_0218dc44.h"
#include "00/code_02198a8c.h"
#include "00/code_02198d04.h"
#include "00/code_0219a3f4.h"
#include "00/code_021a3668.h"
#include "00/unk_021b3000.h"

void func_ov000_02198548(Gt2Connection *a, int b) {
    if (b != 0) {
        if (a->mUnk_0c < 7) {
            func_ov000_02198514(a);
            func_ov000_02198b8c(a);
            func_ov000_021981d0(a, NULL);
            func_ov000_0219a220(a);
        }
    } else {
        a->mUnk_0c = 6;
        func_ov000_02198d50(a);
    }
}

void func_ov000_02198514(Gt2Connection *a, ...) {
    if (a->mUnk_0c != 7) {
        a->mUnk_0c = 7;
        func_ov000_0218de8c(a->mSocket->mConnections, &a);
        func_ov000_0218dbc0(a->mSocket->mConnectionsToFree, &a);
    }
}

void func_ov000_021984b4(Gt2Connection *a) {
    if (a->mUnk_38.mData != NULL) {
        func_ov000_021a3668(a->mUnk_38.mData);
    }
    if (a->mUnk_44.mData != NULL) {
        func_ov000_021a3668(a->mUnk_44.mData);
    }
    if (a->mSendBuffer.mData != NULL) {
        func_ov000_021a3668(a->mSendBuffer.mData);
    }
    if (a->mUnk_5c != NULL) {
        func_ov000_0218dc48(a->mUnk_5c);
    }
    if (a->mUnk_60 != NULL) {
        func_ov000_0218dc48(a->mUnk_60);
    }
    if (a->mUnk_98 != NULL) {
        func_ov000_0218dc48(a->mUnk_98);
    }
    if (a->mUnk_9c != NULL) {
        func_ov000_0218dc48(a->mUnk_9c);
    }
    func_ov000_021a3668(a);
}

BOOL func_ov000_02198448(Gt2Socket *a) {
    if (a == NULL) {
        func_0213442c(data_ov000_021b3f50, data_ov000_021b3f58, NULL, 0x1b);
    }
    if (a == NULL) {
        return TRUE;
    }
    if (a->mUnk_24 == NULL) {
        return TRUE;
    }
    a->mRunningCallbackCount++;
    a->mUnk_24(a);
    a->mRunningCallbackCount--;
    if (a->mDeletePending != 0 && a->mRunningCallbackCount == 0) {
        DeleteSocket(a);
        return FALSE;
    }
    return TRUE;
}

BOOL CallIncomingConnectionCallback(Gt2Socket *a, Gt2Connection *b, int c, int d, int e, int f, int g) {
    if (a == NULL || b == NULL) {
        func_0213442c(data_ov000_021b3f74, data_ov000_021b3f58, NULL, 0x3d);
    }
    if (a == NULL || b == NULL) {
        return TRUE;
    }
    if (a->mIncomingConnectionCallback == NULL) {
        return TRUE;
    }
    if (g == 0 || f == 0) {
        f = 0;
        g = 0;
    }
    a->mRunningCallbackCount++;
    b->mUnk_24++;
    a->mIncomingConnectionCallback(a, b, c, d, e, f, g);
    a->mRunningCallbackCount--;
    b->mUnk_24--;
    if (a->mDeletePending != 0 && a->mRunningCallbackCount == 0) {
        DeleteSocket(a);
        return FALSE;
    }
    return TRUE;
}

BOOL func_ov000_021982f4(Gt2Connection *a, int b, void *c, int d) {
    if (a == NULL) {
        func_0213442c(data_ov000_021b3f68, data_ov000_021b3f58, NULL, 0x69);
    }
    if (a == NULL) {
        return TRUE;
    }
    a->mResult = b;
    if (a->mCallbacks.mResultCallback == NULL) {
        return TRUE;
    }
    if (d == 0 || c == NULL) {
        c = NULL;
        d = 0;
    }
    a->mUnk_24++;
    a->mSocket->mRunningCallbackCount++;
    a->mCallbacks.mResultCallback(a, b, c, d);
    a->mUnk_24--;
    a->mSocket->mRunningCallbackCount--;
    if (a->mSocket->mDeletePending != 0 && a->mSocket->mRunningCallbackCount == 0) {
        DeleteSocket(a->mSocket);
        return FALSE;
    }
    return TRUE;
}

BOOL func_ov000_02198258(Gt2Connection *a, void *b, int c, int d) {
    if (a == NULL) {
        func_0213442c(data_ov000_021b3f68, data_ov000_021b3f58, NULL, 0x94);
    }
    if (a == NULL) {
        return TRUE;
    }
    if (a->mCallbacks.mDataCallback == NULL) {
        return TRUE;
    }
    if (c == 0 || b == NULL) {
        b = NULL;
        c = 0;
    }
    a->mUnk_24++;
    a->mSocket->mRunningCallbackCount++;
    a->mCallbacks.mDataCallback(a, b, c, d);
    a->mUnk_24--;
    a->mSocket->mRunningCallbackCount--;
    if (a->mSocket->mDeletePending != 0 && a->mSocket->mRunningCallbackCount == 0) {
        DeleteSocket(a->mSocket);
        return FALSE;
    }
    return TRUE;
}

BOOL func_ov000_021981d0(Gt2Connection *a, void *b) {
    if (a == NULL) {
        func_0213442c(data_ov000_021b3f68, data_ov000_021b3f58, NULL, 0xba);
    }
    if (a == NULL) {
        return TRUE;
    }
    if (a->mCallbacks.mUnk_08 == NULL) {
        return TRUE;
    }
    a->mUnk_24++;
    a->mSocket->mRunningCallbackCount++;
    a->mCallbacks.mUnk_08(a, b);
    a->mUnk_24--;
    a->mSocket->mRunningCallbackCount--;
    if (a->mSocket->mDeletePending != 0 && a->mSocket->mRunningCallbackCount == 0) {
        DeleteSocket(a->mSocket);
        return FALSE;
    }
    return TRUE;
}
