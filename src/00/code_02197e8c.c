#include "00/code_0218d818.h"
#include "00/code_02197e8c.h"
#include "00/code_0219a3f4.h"
#include "code_0213442c.h"

BOOL Gt2CallElapsedTimeCallback(Gt2Connection *connection, s32 b) {
    if (connection == NULL) {
        AssertionFailed(data_ov000_021b3f68, data_ov000_021b3f58, NULL, 0xd9);
    }
    if (connection == NULL) {
        return TRUE;
    }
    if (connection->mCallbacks.mElapsedTimeCallback == NULL) {
        return TRUE;
    }
    connection->mUnk_24++;
    connection->mSocket->mRunningCallbackCount++;
    connection->mCallbacks.mElapsedTimeCallback(connection, b);
    connection->mUnk_24--;
    connection->mSocket->mRunningCallbackCount--;
    if (connection->mSocket->mDeletePending != 0 && connection->mSocket->mRunningCallbackCount == 0) {
        DeleteSocket(connection->mSocket);
        return FALSE;
    }
    return TRUE;
}

BOOL func_ov000_02198098(Gt2Connection *connection, s32 b, s32 c, void *d, s32 e) {
    Unk02197fe8Entry *f;
    if (connection == NULL) {
        AssertionFailed(data_ov000_021b3f68, data_ov000_021b3f58, NULL, 0x101);
    }
    if (connection == NULL) {
        return TRUE;
    }
    f = DarrayGetElement(connection->mUnk_98, b);
    if (f == NULL) {
        return TRUE;
    }
    if (d == NULL || c == 0) {
        c = 0;
        d = NULL;
    }
    connection->mUnk_24++;
    connection->mSocket->mRunningCallbackCount++;
    f->mUnk_00(connection, b, c, d, e);
    connection->mUnk_24--;
    connection->mSocket->mRunningCallbackCount--;
    if (connection->mSocket->mDeletePending != 0 && connection->mSocket->mRunningCallbackCount == 0) {
        DeleteSocket(connection->mSocket);
        return FALSE;
    }
    return TRUE;
}

BOOL func_ov000_02197fe8(Gt2Connection *connection, s32 b, void *c, s32 d, s32 e) {
    Unk02197fe8Entry *f;
    if (connection == NULL) {
        AssertionFailed(data_ov000_021b3f68, data_ov000_021b3f58, NULL, 0x12d);
    }
    if (connection == NULL) {
        return TRUE;
    }
    f = DarrayGetElement(connection->mUnk_9c, b);
    if (f == NULL) {
        return TRUE;
    }
    if (d == 0 || c == NULL) {
        c = NULL;
        d = 0;
    }
    connection->mUnk_24++;
    connection->mSocket->mRunningCallbackCount++;
    f->mUnk_00(connection, b, c, d, e);
    connection->mUnk_24--;
    connection->mSocket->mRunningCallbackCount--;
    if (connection->mSocket->mDeletePending != 0 && connection->mSocket->mRunningCallbackCount == 0) {
        DeleteSocket(connection->mSocket);
        return FALSE;
    }
    return TRUE;
}

u32 func_ov000_02197f28(Gt2Socket *socket, int e, u32 f, u32 g, u32 h, int l, int m, int n) {
    Gt2Connection *b = (Gt2Connection *) e;
    UnkWordFunc *c;
    if (socket == NULL) {
        AssertionFailed(data_ov000_021b3f50, data_ov000_021b3f58, NULL, 0x160);
    }
    if (socket == NULL) {
        return 1;
    }
    if (n != 0) {
        c = socket->mSentCallback;
    } else {
        c = socket->mUnk_2c;
    }
    if (c == NULL) {
        return 1;
    }
    if (m == 0 || l == 0) {
        l = 0;
        m = 0;
    }
    socket->mRunningCallbackCount++;
    if (b != NULL) {
        b->mUnk_24++;
    }
    c(socket, b, f, g, h, l, m);
    socket->mRunningCallbackCount--;
    if (b != NULL) {
        b->mUnk_24--;
    }
    if (socket->mDeletePending != 0 && socket->mRunningCallbackCount == 0) {
        DeleteSocket(socket);
        return 0;
    }
    return 1;
}

BOOL CallUnmatchedDataCallback(Gt2Socket *a, s32 b, s32 c, void *d, s32 e, s32 *f) {
    *f = 0;
    if (a == NULL) {
        AssertionFailed(data_ov000_021b3f50, data_ov000_021b3f58, NULL, 0x197);
    }
    if (a == NULL) {
        return TRUE;
    }
    if (a->mUnmatchedDataCallback == NULL) {
        return TRUE;
    }
    if (e == 0 || d == NULL) {
        d = NULL;
        e = 0;
    }
    a->mRunningCallbackCount++;
    *f = a->mUnmatchedDataCallback(a, b, c, d, e);
    a->mRunningCallbackCount--;
    if (a->mDeletePending != 0 && a->mRunningCallbackCount == 0) {
        DeleteSocket(a);
        return FALSE;
    }
    return TRUE;
}
