#include "00/code_0218f15c.h"
#include "03/code_021b94b8.h"
#include "00/code_0218e2dc.h"
#include "00/code_0218f960.h"
#include "00/code_02194000.h"
#include "00/code_0218e8d4.h"
#include "00/code_0218f7f8.h"
#include "00/code_0218f808.h"
#include "00/code_0218f848.h"
#include "00/code_02196000.h"
#include "00/code_02196590.h"
#include "00/code_021a3678.h"
#include "00/unk_021b2000.h"
#include "string.h"
#include "code_02134398.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/code_0218d818.h"
#include "00/code_021965a0.h"
#include "00/code_02190cd4.h"
#include "00/code_02190ff8.h"
#include "00/code_02190000.h"
#include "code_02139f70.h"
#include "00/code_021906e4.h"
#include "00/unk_021b3000.h"
#include "00/code_02196594.h"
#include "00/code_02191200.h"
#include "00/code_02192d64.h"
#include "00/code_021919ac.h"
#include "00/code_021947e4.h"
#include "00/code_021a3690.h"
#include "code_0213a460.h"
#include "00/code_02193634.h"
#include "00/code_021948f8.h"
#include "00/code_0218e0fc.h"
#include "00/code_02196480.h"
#include "00/code_02193000.h"
#include "00/code_02193b88.h"
#include "00/code_02194840.h"
#include "00/code_02194bb8.h"
#include "00/code_021a3668.h"
#include "00/unk_021b23b0.h"
#include "00/unk_021b4000.h"
#include "code_021384cc.h"

u32 GpiResetConnection(GpConnection *a) {
    GpiConnection *o;
    GpiOperation **n;
    o = a->mGpiConnection;
    o->mNick[0] = 0;
    o->mUniquenick[0] = 0;
    o->mEmail[0] = 0;
    o->mConnectSocket = -1;
    o->mConnectState = 0;
    o->mInputBufferLength = 0;
    o->mUnk_1e8 = 0;
    o->mInputBufferCapacity = 0;
    func_ov000_021a3668(o->mInputBuffer);
    o->mInputBuffer = NULL;
    o->mInputBuffer = NULL;
    o->mCommandBufferCapacity = 0;
    func_ov000_021a3668(o->mCommandBuffer);
    o->mCommandBuffer = NULL;
    o->mCommandBuffer = NULL;
    o->mOutputBuffer.mLength = 0;
    o->mOutputBuffer.mPos = 0;
    o->mOutputBuffer.mCapacity = 0;
    func_ov000_021a3668(o->mOutputBuffer.mBuffer);
    o->mOutputBuffer.mBuffer = NULL;
    o->mOutputBuffer.mBuffer = NULL;
    o->mUpdateproBufferLength = 0;
    o->mUnk_44c = 0;
    o->mUpdateproBufferCapacity = 0;
    func_ov000_021a3668(o->mUpdateproBuffer);
    o->mUpdateproBuffer = NULL;
    o->mUpdateproBuffer = NULL;
    o->mUpdateuiBufferLength = 0;
    o->mUnk_45c = 0;
    o->mUpdateuiBufferCapacity = 0;
    func_ov000_021a3668(o->mUpdateuiBuffer);
    o->mUpdateuiBuffer = NULL;
    o->mUpdateuiBuffer = NULL;
    o->mListenSocket = -1;
    o->mNextOperationId = 2;
    n = &o->mOperationList;
    while (*n != NULL) {
        GpiRemoveOperation(a, *n);
    }
    o->mOperationList = NULL;
    o->mBuddyCount = 0;
    GpiForEachProfileWhileNonZero(a, func_ov000_0218f7f8, NULL);
    o->mUserId = 0;
    o->mProfileId = 0;
    o->mSesskey = 0;
    o->mSearchCount = 0;
    o->mFatal = FALSE;
    o->mPeerList = NULL;
    o->mStatus = -1;
    o->mStatusString[0] = 0;
    o->mLocationString[0] = 0;
    return 0;
}

u32 func_ov000_0218f408(GpConnection *a) {
    GpiConnection *o;
    GpiOperation *n;
    u32 r;
    s32 m;
    char *p;
    char *q;
    s32 v1;
    u32 v2;
    s32 t;
    v2 = 0;
    o = a->mGpiConnection;
    do {
        GpiWriteUpdateBuffers(a, &o->mOutputBuffer);
        r = GpiSendBuffer(a, o->mConnectSocket, &o->mOutputBuffer, &v2, 1, data_ov000_021b262c);
        if (r != 0) {
            return r;
        }
        r = GpiReceiveBuffer(a, o->mConnectSocket, (GpiBuffer *) &o->mInputBuffer, &v1, &v2, data_ov000_021b262c);
        if (r != 0) {
            if (r == 3) {
                GpiSetError(a, 5, data_ov000_021b2630);
                GpiQueueErrorCallback(a, 3, 1);
                return 3;
            }
            return r;
        }
        p = strstr(o->mInputBuffer, data_ov000_021b265c);
        while (p != NULL) {
            *p = 0;
            func_ov000_0219690c(a, data_ov000_021b2664, o->mInputBuffer);
            v1 = p - o->mInputBuffer;
            if (v1 > o->mCommandBufferCapacity) {
                t = v1;
                if (t < 0x800) {
                    t = 0x800;
                }
                o->mCommandBufferCapacity = o->mCommandBufferCapacity + t;
                q = func_ov000_021a3678(o->mCommandBuffer, o->mCommandBufferCapacity + 1);
                if (q == NULL) {
                    GpiSetErrorMessage(a, data_ov000_021b2670);
                    return 1;
                }
                o->mCommandBuffer = q;
            }
            memcpy(o->mCommandBuffer, o->mInputBuffer, v1 + 1);
            o->mInputBufferLength = o->mInputBufferLength - (p + 7 - o->mInputBuffer);
            memmove(o->mInputBuffer, p + 7, o->mInputBufferLength + 1);
            q = o->mCommandBuffer;
            p = strstr(q, data_ov000_021b2680);
            if (p != NULL) {
                m = StrtolBase10(p + 4);
                if (GpiFindOperation(a, &n, m) == FALSE) {
                    func_ov000_0219690c(a, data_ov000_021b2688, m);
                } else {
                    r = GpiProcessOperation(a, n, o->mCommandBuffer);
                    if (r != 0) {
                        return r;
                    }
                }
            } else {
                if (GpiReadError(a, q, 1) != FALSE) {
                    return 4;
                }
                q = o->mCommandBuffer;
                if (strncmp(q, data_ov000_021b26b0, 4) == 0) {
                    r = func_ov000_0218fca8(a, q);
                    if (r != 0) {
                        return r;
                    }
                } else if (strncmp(q, data_ov000_021b26b8, 10) != 0) {
                    func_ov000_0219690c(a, data_ov000_021b26c0);
                }
            }
            p = strstr(o->mInputBuffer, data_ov000_021b265c);
        }
        if (v2 != 0) {
            o->mConnectState = 4;
            GpiSetError(a, 7, data_ov000_021b26f0);
            GpiQueueErrorCallback(a, 3, 1);
            return 0;
        }
        r = func_ov000_021937c0(a);
        if (r != 0) {
            func_ov000_0218e8bc(10);
        }
    } while (r != 0);
    return 0;
}

int GpiUpdateConnection(void *a, int b) {
    GpConnection *p;
    GpiConnection *o;
    GpiOperation *n;
    GpiOperation *m;
    u32 r;
    u32 x;
    BOOL t;
    p = a;
    o = p->mGpiConnection;
    r = 0;
    if ((u32) o->mConnectState > 4) {
        AssertionFailed(data_ov000_021b2528, data_ov000_021b2620, NULL, 0x1b5);
    }
    if (o->mConnectState == 1) {
        do {
            r = func_ov000_02191200(p);
            if (r == 0 && b != 0 && o->mConnectState == 1) {
                t = TRUE;
            } else {
                t = FALSE;
            }
            if (t != FALSE) {
                func_ov000_0218e8bc(10);
            }
        } while (t != FALSE);
        if (r != 0) {
            if (GpiFindOperation(p, &n, 1) != FALSE) {
                n->mUnk_1c = 4;
            } else {
                AssertionFailed(data_ov000_021b2628, data_ov000_021b2620, NULL, 0x1db);
            }
        }
    }
    if ((u32) (o->mConnectState - 2) <= 1) {
        if (r == 0) {
            r = func_ov000_0218f408(p);
        }
        if (r == 0) {
            r = GpiUpdatePeers(p);
        }
    }
    if (r == 0) {
        r = GpiUpdateSearches(p);
    }
    n = o->mOperationList;
    if (n != NULL) {
        do {
            if (n->mUnk_1c != 0) {
                GpiQueueOperationCallback(p, n);
                m = n;
                n = n->mNext;
                GpiRemoveOperation(p, m);
            } else {
                n = n->mNext;
            }
        } while (n != NULL);
    }
    x = GpiCallQueuedCallbacks(p, b);
    if (x == 0) {
        if (o->mFatal != FALSE) {
            GpiCloseConnection(p, 0);
        }
        x = r;
    }
    return x;
}

u32 GpInitialize(GpConnection *a, s32 b, s32 c) {
    if (data_ov000_021b4d28 != 1) {
        return 2;
    }
    if (a == NULL) {
        return 2;
    }
    return GpiInitialize(a, b, c);
}

void func_ov000_0218f2a0(GpConnection *a) {
    if (a != NULL && a->mGpiConnection != NULL) {
        func_ov000_0218f808(a);
    }
}

u32 GpUpdate(GpConnection *a) {
    GpiConnection *o;
    if (a == NULL || (o = a->mGpiConnection) == NULL) {
        return 2;
    }
    if (o->mUnk_108 != 0) {
        return 0;
    }
    return GpiUpdateConnection(a, 0);
}

u32 func_ov000_0218f21c(GpConnection *a, s32 b, void (*c)(void *a, void *b, u32 c), u32 d) {
    GpiConnection *o;
    if (a == NULL || (o = a->mGpiConnection) == NULL) {
        return 2;
    }
    if (b < 0 || b >= 6) {
        GpiSetErrorMessage(a, data_ov000_021b2518);
        return 2;
    }
    o->mCallbacks[b].mCallback = c;
    o->mCallbacks[b].mUnk_04 = d;
    return 0;
}

u32 func_ov000_0218f15c(GpConnection *a, s8 *b, s8 *c, s32 d, s32 e, Unk0218f15cCb f, u32 g) {
    GpiConnection *o;
    if (a == NULL || (o = a->mGpiConnection) == NULL) {
        return 2;
    }
    if (b == NULL || *b == 0) {
        return 2;
    }
    if (c == NULL || *c == 0) {
        return 2;
    }
    if (f == NULL) {
        GpiSetErrorMessage(a, data_ov000_021b242c);
        return 2;
    }
    if (o->mUnk_108 != 0) {
        Unk0218f15cArg h = {0};
        f(a, &h, g);
        return 0;
    }
    return GpiStartConnect(a, data_ov000_021b2514, data_ov000_021b2514, data_ov000_021b2514, data_ov000_021b2514, b, c,
                           NULL, d, 0, e, (s32) f, g);
}
