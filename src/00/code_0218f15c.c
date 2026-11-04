#include "00/code_0218f15c.h"
#include "03/code_021b94b8.h"
#include "00/code_0218e2dc.h"
#include "00/code_0218e908.h"
#include "00/code_0218f7f8.h"
#include "00/code_0218f808.h"
#include "00/code_0218f848.h"
#include "00/code_0218f960.h"
#include "00/code_02196000.h"
#include "00/code_02196590.h"
#include "00/code_021a3678.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "code_02134d30.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/code_0218d818.h"
#include "00/code_021965a0.h"
#include "00/code_02190cd4.h"
#include "00/code_02190ff8.h"
#include "code_02135014.h"
#include "00/code_02190000.h"
#include "code_02139f70.h"
#include "00/code_021906e4.h"
#include "00/code_0218eb9c.h"
#include "00/unk_021b3000.h"
#include "00/code_021965c8.h"
#include "00/code_02191200.h"
#include "00/code_02192d64.h"
#include "00/code_021919ac.h"
#include "00/code_021947e4.h"
#include "00/code_02196914.h"
#include "00/code_021a3690.h"
#include "code_0213a460.h"
#include "00/code_02193634.h"
#include "00/code_021948f8.h"
#include "00/code_0218e0fc.h"
#include "00/code_021967b4.h"
#include "00/code_02196480.h"
#include "00/code_02193000.h"
#include "00/code_02193b88.h"
#include "00/code_02194840.h"
#include "00/code_02194bb8.h"
#include "00/code_021a3668.h"
#include "00/unk_021b23b0.h"
#include "00/unk_021b4000.h"
#include "code_021384cc.h"

u32 func_ov000_0218f654(GpConnection *a) {
    GpiConnection *o;
    Unk021937c0Node **n;
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
    o->mOutputBuffer.mUnk_08 = 0;
    o->mOutputBuffer.mUnk_0c = 0;
    o->mOutputBuffer.mUnk_04 = 0;
    func_ov000_021a3668(o->mOutputBuffer.mUnk_00);
    o->mOutputBuffer.mUnk_00 = NULL;
    o->mOutputBuffer.mUnk_00 = NULL;
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
        func_ov000_02193818(a, *n);
    }
    o->mOperationList = NULL;
    o->mBuddyCount = 0;
    func_ov000_02194840(a, func_ov000_0218f7f8, NULL);
    o->mUserId = 0;
    o->mProfileId = 0;
    o->mSesskey = 0;
    o->mSearchCount = 0;
    o->mFatal = 0;
    o->mPeerList = NULL;
    o->mStatus = -1;
    o->mStatusString[0] = 0;
    o->mLocationString[0] = 0;
    return 0;
}

u32 func_ov000_0218f408(GpConnection *a) {
    GpiConnection *o;
    Unk021937c0Node *n;
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
        func_ov000_02192d64(a, &o->mOutputBuffer);
        r = func_ov000_021906e4(a, o->mConnectSocket, &o->mOutputBuffer, &v2, 1, data_ov000_021b262c);
        if (r != 0) {
            return r;
        }
        r = func_ov000_021907e8(a, o->mConnectSocket, (Unk021906e4 *) &o->mInputBuffer, &v1, &v2, data_ov000_021b262c);
        if (r != 0) {
            if (r == 3) {
                func_ov000_021965a0(a, 5, data_ov000_021b2630);
                func_ov000_02190f4c(a, 3, 1);
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
                    func_ov000_02196590(a, data_ov000_021b2670);
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
                m = func_0213bf90(p + 4);
                if (func_ov000_021937e8(a, &n, m) == 0) {
                    func_ov000_0219690c(a, data_ov000_021b2688, m);
                } else {
                    r = func_ov000_02193748(a, n, o->mCommandBuffer);
                    if (r != 0) {
                        return r;
                    }
                }
            } else {
                if (func_ov000_02196870(a, q, 1) != 0) {
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
            func_ov000_021965a0(a, 7, data_ov000_021b26f0);
            func_ov000_02190f4c(a, 3, 1);
            return 0;
        }
        r = func_ov000_021937c0(a);
        if (r != 0) {
            func_ov000_0218e8bc(10);
        }
    } while (r != 0);
    return 0;
}

int func_ov000_0218f2e8(void *a, int b) {
    GpConnection *p;
    GpiConnection *o;
    Unk021937c0Node *n;
    Unk021937c0Node *m;
    u32 r;
    u32 x;
    BOOL t;
    p = a;
    o = p->mGpiConnection;
    r = 0;
    if ((u32) o->mConnectState > 4) {
        func_0213442c(data_ov000_021b2528, data_ov000_021b2620, NULL, 0x1b5);
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
            if (func_ov000_021937e8(p, &n, 1) != 0) {
                n->mUnk_1c = 4;
            } else {
                func_0213442c(data_ov000_021b2628, data_ov000_021b2620, NULL, 0x1db);
            }
        }
    }
    if ((u32) (o->mConnectState - 2) <= 1) {
        if (r == 0) {
            r = func_ov000_0218f408(p);
        }
        if (r == 0) {
            r = func_ov000_02193f50(p);
        }
    }
    if (r == 0) {
        r = func_ov000_02194bb8(p);
    }
    n = o->mOperationList;
    if (n != NULL) {
        do {
            if (n->mUnk_1c != 0) {
                func_ov000_02193954(p, n);
                m = n;
                n = n->mNext;
                func_ov000_02193818(p, m);
            } else {
                n = n->mNext;
            }
        } while (n != NULL);
    }
    x = func_ov000_02190cd4(p, b);
    if (x == 0) {
        if (o->mFatal != 0) {
            func_ov000_02190ff8(p, 0);
        }
        x = r;
    }
    return x;
}

u32 func_ov000_0218f2b8(GpConnection *a, s32 b, s32 c) {
    if (data_ov000_021b4d28 != 1) {
        return 2;
    }
    if (a == NULL) {
        return 2;
    }
    return func_ov000_0218f848(a, b, c);
}

void func_ov000_0218f2a0(GpConnection *a) {
    if (a != NULL && a->mGpiConnection != NULL) {
        func_ov000_0218f808(a);
    }
}

u32 func_ov000_0218f268(GpConnection *a) {
    GpiConnection *o;
    if (a == NULL || (o = a->mGpiConnection) == NULL) {
        return 2;
    }
    if (o->mUnk_108 != 0) {
        return 0;
    }
    return func_ov000_0218f2e8(a, 0);
}

u32 func_ov000_0218f21c(GpConnection *a, s32 b, void (*c)(void *a, void *b, u32 c), u32 d) {
    GpiConnection *o;
    if (a == NULL || (o = a->mGpiConnection) == NULL) {
        return 2;
    }
    if (b < 0 || b >= 6) {
        func_ov000_02196590(a, data_ov000_021b2518);
        return 2;
    }
    o->mCallbacks[b].mUnk_00 = c;
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
        func_ov000_02196590(a, data_ov000_021b242c);
        return 2;
    }
    if (o->mUnk_108 != 0) {
        Unk0218f15cArg h = {0};
        f(a, &h, g);
        return 0;
    }
    return func_ov000_02191cb0(a, data_ov000_021b2514, data_ov000_021b2514, data_ov000_021b2514, data_ov000_021b2514, b,
                               c, NULL, d, 0, e, (s32) f, g);
}
