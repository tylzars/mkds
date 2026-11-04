#include "00/code_0218d818.h"
#include "00/code_0218dd8c.h"
#include "00/code_02197e8c.h"
#include "00/code_021981d0.h"
#include "00/code_0218d000.h"
#include "00/code_0219a0d0.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
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
        HashtableRemove(a->mSocket->mConnections, &a);
        DarrayAppend(a->mSocket->mConnectionsToFree, &a);
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
        DarrayDelete(a->mUnk_5c);
    }
    if (a->mUnk_60 != NULL) {
        DarrayDelete(a->mUnk_60);
    }
    if (a->mUnk_98 != NULL) {
        DarrayDelete(a->mUnk_98);
    }
    if (a->mUnk_9c != NULL) {
        DarrayDelete(a->mUnk_9c);
    }
    func_ov000_021a3668(a);
}

BOOL func_ov000_02198448(Gt2Socket *socket) {
    if (socket == NULL) {
        func_0213442c(data_ov000_021b3f50, data_ov000_021b3f58, NULL, 0x1b);
    }
    if (socket == NULL) {
        return TRUE;
    }
    if (socket->mUnk_24 == NULL) {
        return TRUE;
    }
    socket->mRunningCallbackCount++;
    socket->mUnk_24(socket);
    socket->mRunningCallbackCount--;
    if (socket->mDeletePending != 0 && socket->mRunningCallbackCount == 0) {
        DeleteSocket(socket);
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

BOOL Gt2SetResultAndCallResultCallback(Gt2Connection *connection, int b, void *c, int d) {
    if (connection == NULL) {
        func_0213442c(data_ov000_021b3f68, data_ov000_021b3f58, NULL, 0x69);
    }
    if (connection == NULL) {
        return TRUE;
    }
    connection->mResult = b;
    if (connection->mCallbacks.mResultCallback == NULL) {
        return TRUE;
    }
    if (d == 0 || c == NULL) {
        c = NULL;
        d = 0;
    }
    connection->mUnk_24++;
    connection->mSocket->mRunningCallbackCount++;
    connection->mCallbacks.mResultCallback(connection, b, c, d);
    connection->mUnk_24--;
    connection->mSocket->mRunningCallbackCount--;
    if (connection->mSocket->mDeletePending != 0 && connection->mSocket->mRunningCallbackCount == 0) {
        DeleteSocket(connection->mSocket);
        return FALSE;
    }
    return TRUE;
}

BOOL Gt2CallDataCallback(Gt2Connection *connection, void *b, int c, int d) {
    if (connection == NULL) {
        func_0213442c(data_ov000_021b3f68, data_ov000_021b3f58, NULL, 0x94);
    }
    if (connection == NULL) {
        return TRUE;
    }
    if (connection->mCallbacks.mDataCallback == NULL) {
        return TRUE;
    }
    if (c == 0 || b == NULL) {
        b = NULL;
        c = 0;
    }
    connection->mUnk_24++;
    connection->mSocket->mRunningCallbackCount++;
    connection->mCallbacks.mDataCallback(connection, b, c, d);
    connection->mUnk_24--;
    connection->mSocket->mRunningCallbackCount--;
    if (connection->mSocket->mDeletePending != 0 && connection->mSocket->mRunningCallbackCount == 0) {
        DeleteSocket(connection->mSocket);
        return FALSE;
    }
    return TRUE;
}

BOOL func_ov000_021981d0(Gt2Connection *connection, void *b) {
    if (connection == NULL) {
        func_0213442c(data_ov000_021b3f68, data_ov000_021b3f58, NULL, 0xba);
    }
    if (connection == NULL) {
        return TRUE;
    }
    if (connection->mCallbacks.mUnk_08 == NULL) {
        return TRUE;
    }
    connection->mUnk_24++;
    connection->mSocket->mRunningCallbackCount++;
    connection->mCallbacks.mUnk_08(connection, b);
    connection->mUnk_24--;
    connection->mSocket->mRunningCallbackCount--;
    if (connection->mSocket->mDeletePending != 0 && connection->mSocket->mRunningCallbackCount == 0) {
        DeleteSocket(connection->mSocket);
        return FALSE;
    }
    return TRUE;
}
