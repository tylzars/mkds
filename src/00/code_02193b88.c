#include "00/code_02193b88.h"
#include "00/code_021906e4.h"
#include "00/code_021947e4.h"
#include "00/code_02196914.h"
#include "00/code_021a3690.h"
#include "00/code_02196590.h"
#include "00/unk_021b2000.h"
#include "string.h"
#include "code_02134398.h"
#include "code_02139f70.h"
#include "code_0213a460.h"
#include "00/code_021948f8.h"
#include "00/code_0218e0fc.h"
#include "00/code_02191200.h"
#include "00/code_02196480.h"
#include "00/code_02190ff8.h"
#include "00/code_02192d64.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/code_0218d818.h"
#include "00/code_02196000.h"
#include "00/code_02190000.h"
#include "00/code_0218f960.h"
#include "00/code_02194bb8.h"
#include "00/code_02193000.h"

#include "00/code_0218e2dc.h"
#include "00/code_02194000.h"
#include "00/code_021965a0.h"
#include "00/unk_021b4000.h"
#include "00/code_021a3668.h"
#include "00/unk_021b3000.h"
#include "00/code_02190548.h"
#include "00/code_0219218c.h"
#include "00/code_02192000.h"
#include "00/code_0218eb9c.h"
#include "00/code_0218f15c.h"
#include "00/code_021a3678.h"
#include "code_021382a8.h"
#include "00/code_021965c8.h"
#include "00/code_02190cd4.h"

s32 func_ov000_02194590(GpConnection *a, GpiPeer *b) {
    GpiConnection *r;
    GpiPeer *p;
    BOOL f;
    s32 t;
    s32 x;
    s32 y;
    s32 z;
    GpiProfile *e;
    char *q;
    char *w;

    r = a->mGpiConnection;
    switch (b->mState) {
        case 0x65:
            break;
        case 0x66:
            t = GpiPeerConnect(a, b);
            if (t != 0) {
                return t;
            }
            break;
        case 0x67:
            t = GpiCheckConnectComplete(a, b->mSocket, (u32 *) &x);
            if (t != 0) {
                return t;
            }
            if (x == 4) {
                GpiSetErrorMessage(a, data_ov000_021b33a0);
                return 3;
            } else if (x == 3) {
                f = TRUE;
                if (GpiFindProfile(a, b->mProfileId, &e) == 0) {
                    GpiSetErrorMessage(a, data_ov000_021b33a0);
                    return 3;
                }
                GpiAppendBufferString(a, b->mOutputBuffer, data_ov000_021b34d0);
                GpiAppendBufferString(a, b->mOutputBuffer, data_ov000_021b34d8);
                GpiAppendBufferNumber(a, b->mOutputBuffer, r->mProfileId);
                GpiAppendBufferString(a, b->mOutputBuffer, data_ov000_021b34e0);
                GpiAppendBufferString(a, b->mOutputBuffer, r->mNick);
                GpiAppendBufferString(a, b->mOutputBuffer, data_ov000_021b34e8);
                GpiAppendBufferString(a, b->mOutputBuffer, e->mUnk_18);
                GpiAppendBufferString(a, b->mOutputBuffer, data_ov000_021b34c8);
                for (p = r->mPeerList; p != NULL; p = p->mNext) {
                    if (p->mProfileId == b->mProfileId && p != b && p->mState <= 0x67) {
                        f = FALSE;
                    }
                }
                if (f != FALSE) {
                    func_ov000_021a3668(e->mUnk_18);
                    e->mUnk_18 = NULL;
                    if (GpiIsProfileEmpty(e) != 0) {
                        GpiRemoveProfile(a, e);
                    }
                }
                b->mState = 0x68;
            }
            break;
        case 0x68:
            t = GpiReceiveBuffer(a, b->mSocket, (GpiBuffer *) &b->mUnk_18, (s32 *) &y, (u32 *) &z, data_ov000_021b3490);
            if (t != 0) {
                return t;
            }
            w = strstr(b->mUnk_18, data_ov000_021b34c8);
            if (w == NULL) {
                break;
            }
            *w = 0;
            q = b->mUnk_18;
            if (strncmp(q, data_ov000_021b34f8, 7) == 0) {
                b->mUnk_14 = b->mUnk_14 + 1;
                if (b->mUnk_14 > 1) {
                    GpiSetErrorMessage(a, data_ov000_021b3508);
                    return 3;
                }
                t = func_ov000_02193e70(a, b);
                if (t != 0) {
                    return t;
                }
            } else if (strncmp(q, data_ov000_021b3500, 6) != 0) {
                GpiSetErrorMessage(a, data_ov000_021b352c);
                return 3;
            }
            b->mState = 0x69;
            b->mUnk_20 = 0;
            break;
        default:
            AssertionFailed(data_ov000_021b3440, data_ov000_021b333c, NULL, 0x9f);
            break;
    }
    if (b->mOutputBufferLength > 0) {
        t = GpiSendBuffer(a, b->mSocket, (GpiBuffer *) b->mOutputBuffer, (u32 *) &z, 1, data_ov000_021b3490);
        if (z != 0 || t != 0) {
            b->mState = 0x6a;
        }
    }
    return 0;
}

s32 GpiPeerUpdateWaiting(GpConnection *a, GpiPeer *b) {
    GpiConnection *r;
    s32 x;
    s32 y;
    s32 t;
    s32 v;
    char *p;
    char *q;
    char c0[0x10];
    char c1[0x1f];
    char c2[0x21];
    char c3[0x21];
    char c4[0x103];

    r = a->mGpiConnection;
    if (b->mState != 0x68) {
        AssertionFailed(data_ov000_021b34a8, data_ov000_021b333c, NULL, 0xc1);
    }
    t = GpiReceiveBuffer(a, b->mSocket, (GpiBuffer *) &b->mUnk_18, (s32 *) &x, (u32 *) &y, data_ov000_021b3490);
    if (t != 0) {
        return t;
    }
    if (y != 0) {
        b->mState = 0x6a;
        return 0;
    }
    p = strstr(b->mUnk_18, data_ov000_021b34c8);
    if (p != NULL) {
        *p = 0;
        q = b->mUnk_18;
        if (strncmp(q, data_ov000_021b34d0, 6) == 0) {
            if (GpiGetValue(q, data_ov000_021b34d8, c0, 0x10) == 0) {
                b->mState = 0x6a;
                return 0;
            }
            v = StrtolBase10(c0);
            if (GpiGetValue(b->mUnk_18, data_ov000_021b34e0, c1, 0x1f) == 0) {
                b->mState = 0x6a;
                return 0;
            }
            if (GpiGetValue(b->mUnk_18, data_ov000_021b34e8, c2, 0x21) == 0) {
                b->mState = 0x6a;
                return 0;
            }
            sprintf(c4, data_ov000_021b34f0, r->mPassword, r->mProfileId, v);
            func_ov000_0218e0fc(c4, strlen(c4), c3);
            if (strcmp(c2, c3) != 0) {
                GpiAppendBufferString(a, b->mOutputBuffer, data_ov000_021b34f8);
                GpiAppendBufferString(a, b->mOutputBuffer, data_ov000_021b34c8);
                b->mState = 0x6a;
                return 0;
            }
            GpiAppendBufferString(a, b->mOutputBuffer, data_ov000_021b3500);
            GpiAppendBufferString(a, b->mOutputBuffer, data_ov000_021b34c8);
            b->mState = 0x69;
            b->mProfileId = v;
        } else {
            b->mState = 0x6a;
            return 0;
        }
        b->mUnk_20 = 0;
    }
    return 0;
}

s32 func_ov000_02194370(GpConnection *a, GpiPeer *b) {
    Unk02194370Entry *c;
    s32 y;
    s32 t;

    if (b->mOutputBufferLength != 0) {
        return 0;
    }
    if (DarrayGetCount(b->mQueuedMessages) != 0) {
        do {
            c = DarrayGetElement(b->mQueuedMessages, 0);
            t = GpiSendBuffer(a, b->mSocket, (GpiBuffer *) c, (u32 *) &y, 0, data_ov000_021b3490);
            if (y != 0 || t != 0) {
                b->mState = 0x6a;
                return 0;
            }
            if (c->mPos != c->mLength) {
                break;
            }
            DarrayRemove(b->mQueuedMessages, 0);
        } while (DarrayGetCount(b->mQueuedMessages) != 0);
    }
    return 0;
}

s32 func_ov000_021941c4(GpConnection *a, GpiPeer *b) {
    GpiConnection *r;
    Unk021941c4Msg *s;
    s32 x;
    s32 y;
    GpiCallback p;
    s32 m;
    s32 n;
    s32 o;
    s32 t;

    r = a->mGpiConnection;
    if (b->mOutputBufferLength != 0) {
        t = GpiSendBuffer(a, b->mSocket, (GpiBuffer *) b->mOutputBuffer, (u32 *) &y, 1, data_ov000_021b3490);
        if (y != 0 || t != 0) {
            b->mState = 0x6a;
            return 0;
        }
    }
    if (b->mOutputBufferLength == 0) {
        t = func_ov000_02194370(a, b);
        if (t != 0) {
            return t;
        }
        if (b->mState == 0x6a) {
            return 0;
        }
    }
    t = GpiReceiveBuffer(a, b->mSocket, (GpiBuffer *) &b->mUnk_18, (s32 *) &x, (u32 *) &y, data_ov000_021b3490);
    if (t != 0) {
        b->mState = 0x6a;
        return 0;
    }
    if (x > 0) {
        b->mUnk_10 = func_ov000_0218e320(NULL) + 0x12c;
    }
    do {
        t = func_ov000_02190618(a, (GpiBuffer *) &b->mUnk_18, &m, &n, &o);
        if (t != 0) {
            return t;
        }
        if (m != 0) {
            switch (n) {
                case 1:
                    p = r->mCallbacks[3];
                    if (p.mCallback != NULL) {
                        s = func_ov000_021a3690(0xc);
                        if (s == NULL) {
                            GpiSetErrorMessage(a, data_ov000_021b3494);
                            return 1;
                        }
                        s->mUnk_00 = b->mProfileId;
                        s->mUnk_08 = (u32) func_ov000_0218e880((const char *) m);
                        s->mUnk_04 = func_ov000_0218e320(NULL);
                        t = GpiQueueCallback(a, p, s, NULL, 2);
                        if (t != 0) {
                            return t;
                        }
                    }
                    break;
                case 0x66:
                    func_ov000_0218fb3c(a, b->mProfileId, 0x67, data_ov000_021b34a4);
                    break;
                case 200:
                case 201:
                case 202:
                case 203:
                case 204:
                case 205:
                case 206:
                case 207:
                case 208:
                    func_ov000_02196434(a, b, n, b->mUnk_18, m, o);
                    break;
            }
            func_ov000_021905d4(a, (GpiBuffer *) &b->mUnk_18);
        }
    } while (m != 0);
    if (y != 0) {
        b->mState = 0x6a;
    }
    return 0;
}

s32 GpiPeerUpdate(GpConnection *b, GpiPeer *c) {
    s32 a = 0;

    if (c->mState == 0x64) {
        AssertionFailed(data_ov000_021b3468, data_ov000_021b333c, NULL, 0x1d9);
    }
    if (c->mState != 0x69) {
        if (c->mUnk_04 != 0) {
            a = func_ov000_02194590(b, c);
        } else {
            a = GpiPeerUpdateWaiting(b, c);
        }
    }
    if (a == 0 && c->mState == 0x69) {
        a = func_ov000_021941c4(b, c);
    }
    return a;
}

void GpiPeerDelete(GpConnection *a, GpiPeer *b) {
    func_ov000_0218e524(b->mSocket, 2);
    func_ov000_0218e53c(b->mSocket);
    func_ov000_021a3668(b->mUnk_18);
    b->mUnk_18 = NULL;
    func_ov000_021a3668(*(void **) b->mOutputBuffer);
    *(void **) b->mOutputBuffer = NULL;
    if (b->mQueuedMessages != NULL) {
        DarrayDelete(b->mQueuedMessages);
        b->mQueuedMessages = NULL;
    }
    func_ov000_021a3668(b);
}

void GpiPeerRemoveAndWriteQueuedMessages(GpConnection *f, GpiPeer *g) {
    GpiConnection *a = f->mGpiConnection;
    GpiPeer *b;
    GpiPeer *c;
    Unk0219405c *d;
    s32 e;

    if (g == NULL) {
        AssertionFailed(data_ov000_021b332c, data_ov000_021b333c, NULL, 0x213);
    }
    b = a->mPeerList;
    if (b == g) {
        a->mPeerList = g->mNext;
    } else {
        c = b->mNext;
        while (c != g) {
            if (c == NULL) {
                AssertionFailed(data_ov000_021b3440, data_ov000_021b333c, NULL, 0x225);
                func_ov000_0219690c(f, data_ov000_021b3444);
                return;
            }
            b = c;
            c = c->mNext;
        }
        b->mNext = g->mNext;
    }
    if (DarrayGetCount(g->mQueuedMessages) != 0) {
        do {
            d = DarrayGetElement(g->mQueuedMessages, 0);
            if (d->mUnk_10 < 0x64) {
                func_ov000_0218fbe0(f, g->mProfileId, d->mUnk_10, (const char *) (d->mBuffer + d->mUnk_14));
            }
            DarrayRemove(g->mQueuedMessages, 0);
        } while (DarrayGetCount(g->mQueuedMessages) != 0);
    }
    GpiPeerDelete(f, g);
}

void func_ov000_02193ff4(s32 a) {
    func_ov000_0218e7dc(a, 0x4000);
    func_ov000_0218e7dc(a, 0x8000);
    func_ov000_0218e7dc(a, 0x10000);
    func_ov000_0218e7dc(a, 0x20000);
    func_ov000_0218e7dc(a, 0x40000);
    func_ov000_0218e7ac(a, 0x4000);
    func_ov000_0218e7ac(a, 0x8000);
    func_ov000_0218e7ac(a, 0x10000);
    func_ov000_0218e77c(a);
    func_ov000_0218e74c(a);
}

s32 GpiUpdatePeers(GpConnection *e) {
    GpiConnection *a = e->mGpiConnection;
    GpiPeer *b;
    GpiPeer *c;
    s32 d;

    if (a->mListenSocket != -1 && func_ov000_0218e668(a->mListenSocket) != 0) {
        d = func_ov000_0218e478(a->mListenSocket, NULL, NULL);
        if (d != -1) {
            b = GpiPeerCreate(e, -1, 0);
            if (b != NULL) {
                b->mState = 0x68;
                b->mSocket = d;
                func_ov000_0218e80c(d, 0);
                func_ov000_02193ff4(b->mSocket);
            } else {
                func_ov000_0218e53c(d);
            }
        }
    }
    b = a->mPeerList;
    while (b != NULL) {
        c = b->mNext;
        d = GpiPeerUpdate(e, b);
        if (b->mState == 0x6a || d != 0 || (s32) func_ov000_0218e320(NULL) > b->mUnk_10) {
            GpiPeerRemoveAndWriteQueuedMessages(e, b);
        }
        b = c;
    }
    return 0;
}

GpiPeer *func_ov000_02193f2c(GpConnection *object, u32 key) {
    GpiPeer *node = object->mGpiConnection->mPeerList;
    while (node != NULL) {
        if (node->mProfileId == key && node->mState == 0x69) {
            return node;
        }
        node = node->mNext;
    }
    return NULL;
}

void func_ov000_02193f18(u32 *a) {
    func_ov000_021a3668((void *) (*a));
    *a = 0;
    return;
}

GpiPeer *GpiPeerCreate(GpConnection *c, u32 d, u32 e) {
    GpiConnection *a = c->mGpiConnection;
    GpiPeer *b = func_ov000_021a3690(0x40);

    if (b == NULL) {
        return NULL;
    }
    memset(b, 0, 0x40);
    b->mState = 0x64;
    b->mUnk_04 = e;
    b->mSocket = -1;
    b->mProfileId = d;
    b->mUnk_10 = func_ov000_0218e320(NULL) + 0x12c;
    b->mNext = a->mPeerList;
    b->mQueuedMessages = (void *) DarrayCreate(0x18, 0, (void (*)(void *)) func_ov000_02193f18);
    a->mPeerList = b;
    return b;
}

int func_ov000_02193e70(GpConnection *a, GpiPeer *b) {
    int v1;
    int v2[2];
    v1 = GpiCreateOperation(a, 2, 0, v2, 0, 0, 0);
    if ((v1 == 0) && (v1 = func_ov000_02192330(a, (u32) (b->mProfileId), (u32) (*(u32 *) (v2[0] + 0x18))), v1 == 0)) {
        b->mState = 0x65;
        v1 = 0;
    }
    return v1;
}

s32 GpiPeerConnect(GpConnection *param_1, GpiPeer *param_2) {
    Unk02193d64 b;
    GpiProfile *a;
    s32 c;
    u32 *p;

    if (GpiFindProfile(param_1, param_2->mProfileId, &a) == 0) {
        GpiSetErrorMessage(param_1, data_ov000_021b33a0);
        return 3;
    }
    param_2->mSocket = func_ov000_0218e554(2, 1, 0);
    if (param_2->mSocket == -1) {
        GpiSetError(param_1, 5, data_ov000_021b33bc);
        GpiQueueErrorCallback(param_1, 3, 0);
        return 3;
    }
    if (func_ov000_0218e80c(param_2->mSocket, 0) == 0) {
        GpiSetError(param_1, 5, data_ov000_021b33e4);
        GpiQueueErrorCallback(param_1, 3, 0);
        return 3;
    }
    func_ov000_02193ff4(param_2->mSocket);
    p = (u32 *) &b;
    p[0] = 0;
    p[1] = 0;
    b.mUnk_01 = 2;
    b.mUnk_04 = a->mBuddyStatus->mUnk_10;
    b.mUnk_02 = a->mBuddyStatus->mUnk_14;
    c = func_ov000_0218e4b4(param_2->mSocket, &b, 8);
    if (c == -1) {
        c = func_ov000_0218e368(param_2->mSocket);
        if (c != -6 && c != -0x1a && c != -0x4c) {
            GpiSetError(param_1, 5, data_ov000_021b3418);
            GpiQueueErrorCallback(param_1, 3, 1);
            return 3;
        }
    }
    param_2->mState = 0x67;
    return 0;
}

s32 GpiPeerQueueMessage(GpConnection *param_1, GpiPeer *peer, u32 param_3, const char *message) {
    u32 b;
    s32 c;

    if (peer == NULL) {
        AssertionFailed(data_ov000_021b332c, data_ov000_021b333c, NULL, 0x340);
    }
    if (message == NULL) {
        AssertionFailed(data_ov000_021b337c, data_ov000_021b333c, NULL, 0x341);
    }
    b = strlen(message);
    {
        Unk02193c74 a = {0};
        a.mUnk_10 = param_3;
        c = GpiAppendBufferString(param_1, &a, data_ov000_021b338c);
        if (c != 0) {
            return c;
        }
        c = GpiAppendBufferNumber(param_1, &a, param_3);
        if (c != 0) {
            return c;
        }
        c = GpiAppendBufferString(param_1, &a, data_ov000_021b3390);
        if (c != 0) {
            return c;
        }
        c = GpiAppendBufferNumber(param_1, &a, b);
        if (c != 0) {
            return c;
        }
        c = GpiAppendBufferString(param_1, &a, data_ov000_021b3398);
        if (c != 0) {
            return c;
        }
        a.mUnk_14 = a.mLength;
        c = GpiAppendBufferBytes(param_1, (GpiBuffer *) &a, message, b);
        if (c != 0) {
            return c;
        }
        c = GpiAppendBufferByte(param_1, (GpiBuffer *) &a, 0);
        if (c != 0) {
            return c;
        }
        DarrayAppend(peer->mQueuedMessages, &a);
        peer->mUnk_10 = func_ov000_0218e320(NULL) + 0x12c;
        return 0;
    }
}

u32 GpiPeerSendXfer(GpConnection *param_1, GpiPeer *param_2, u32 param_3, GpiTransferId *transferID) {
    char a[0x44];
    u32 b = transferID->mUnk_04;
    u32 c = transferID->mUnk_00;
    u32 d = transferID->mUnk_08;

    if (transferID == NULL) {
        AssertionFailed(data_ov000_021b335c, data_ov000_021b333c, NULL, 0x376);
    }
    sprintf(a, data_ov000_021b3368, param_3, c, b, d);
    return GpiPeerSendString(param_1, (Unk02190988 *) param_2, a);
}

s32 GpiPeerSendLenMsg(GpConnection *param_1, GpiPeer *peer, const char *param_3, s32 param_4) {
    char a[0x24];
    s32 b;

    if (peer == NULL) {
        AssertionFailed(data_ov000_021b332c, data_ov000_021b333c, NULL, 0x389);
    }
    if (param_3 == NULL) {
        param_3 = data_ov000_021b3348;
    }
    if (param_4 == -1) {
        param_4 = strlen(param_3);
    }
    sprintf(a, data_ov000_021b334c, param_4);
    b = GpiPeerSendString(param_1, (Unk02190988 *) peer, a);
    if (b != 0) {
        return b;
    }
    b = GpiPeerSendBytes(param_1, (Unk02190988 *) peer, param_3, param_4);
    if (b != 0) {
        return b;
    }
    b = GpiPeerSendByte(param_1, (Unk02190988 *) peer, 0);
    if (b != 0) {
        return b;
    }
    peer->mUnk_10 = func_ov000_0218e320(NULL) + 0x12c;
    return 0;
}
