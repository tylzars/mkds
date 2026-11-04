#include "00/code_0218f960.h"

#include "00/code_0218f15c.h"
#include "00/code_02190000.h"
#include "code_02139f70.h"
#include "00/code_0218d000.h"
#include "00/code_02194840.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "00/code_0218d818.h"
#include "00/code_0218e2dc.h"
#include "00/code_021965a0.h"
#include "00/code_02190cd4.h"
#include "00/code_02196000.h"
#include "code_02135014.h"
#include "00/code_021906e4.h"
#include "00/code_02194000.h"
#include "00/code_021947e4.h"
#include "00/code_02190548.h"
#include "00/code_021948f8.h"
#include "00/code_02196914.h"
#include "00/code_021a3690.h"
#include "00/code_02196590.h"
#include "code_02134d30.h"
#include "code_0213a460.h"
#include "00/code_0218e0fc.h"
#include "00/code_02191200.h"
#include "00/code_02196480.h"
#include "00/code_02190ff8.h"
#include "00/code_02192d64.h"
#include "00/code_02194bb8.h"
#include "00/code_02193000.h"
#include "00/code_02193b88.h"
#include "00/code_02192000.h"
#include "00/code_021a3668.h"
#include "00/unk_021b23b0.h"
#include "00/code_021967b4.h"

s32 func_ov000_0218fca8(GpConnection *a, char *b) {
    char c[0x1000];
    char d[0x100];
    char e[0x10];
    GpiCallback s1;
    GpiCallback s2;
    GpiCallback s3;
    GpiCallback s4;
    s32 z;
    s32 y;
    s32 k;
    s32 n;
    s32 r;
    u16 h;
    char *q;
    u8 *w;
    enum { K0 } i;
    GpiConnection *o;
    Unk0218fca8 *p1;
    Unk0218fca8_40c *p2;
    Unk0218fca8_108 *p3;
    GpiProfile *p;
    GpiBuddyStatus *t;

    o = a->mGpiConnection;
    if (GpiGetValue(b, data_ov000_021b27c4, c, 0x1000) == 0) {
        GpiSetError(a, 1, data_ov000_021b27d8);
        GpiQueueErrorCallback(a, 3, 1);
        return 3;
    }
    k = StrtolBase10(c);
    if (GpiGetValue(b, data_ov000_021b2808, c, 0x1000) == 0) {
        GpiSetError(a, 1, data_ov000_021b27d8);
        GpiQueueErrorCallback(a, 3, 1);
        return 3;
    }
    y = StrtolBase10(c);
    if (GpiGetValue(b, data_ov000_021b280c, c, 0x1000) != 0) {
        z = StrtolBase10(c);
    } else {
        z = func_ov000_0218e320(NULL);
    }
    switch (k) {
        case 1:
            s1 = o->mCallbacks[3];
            if (s1.mCallback == NULL) {
                break;
            }
            p1 = func_ov000_021a3690(0xc);
            if (p1 == NULL) {
                GpiSetErrorMessage(a, data_ov000_021b2814);
                return 1;
            }
            if (GpiGetValue(b, data_ov000_021b27d0, c, 0x1000) == 0) {
                GpiSetError(a, 1, data_ov000_021b27d8);
                GpiQueueErrorCallback(a, 3, 1);
                return 3;
            }
            p1->mUnk_08 = func_ov000_021a3690(strlen(c) + 1);
            if (p1->mUnk_08 == NULL) {
                GpiSetErrorMessage(a, data_ov000_021b2814);
                return 1;
            }
            strcpy(p1->mUnk_08, c);
            p1->mUnk_00 = y;
            p1->mUnk_04 = z;
            r = GpiQueueCallback(a, s1, p1, NULL, 2);
            if (r != 0) {
                return r;
            }
            break;
        case 2:
            p = GpiFindOrAddProfile(a, y);
            if (p == NULL) {
                GpiSetErrorMessage(a, data_ov000_021b2814);
                return 1;
            }
            if (GpiGetValue(b, data_ov000_021b27d0, c, 0x1000) == 0) {
                GpiSetError(a, 1, data_ov000_021b27d8);
                GpiQueueErrorCallback(a, 3, 1);
                return 3;
            }
            q = strstr(c, data_ov000_021b2824);
            if (q == NULL) {
                GpiSetError(a, 1, data_ov000_021b27d8);
                GpiQueueErrorCallback(a, 3, 1);
                return 3;
            }
            *q = 0;
            if (strlen(q + 8) != 0x20) {
                GpiSetError(a, 1, data_ov000_021b27d8);
                GpiQueueErrorCallback(a, 3, 1);
                return 3;
            }
            func_ov000_021a3668(p->mUnk_10);
            p->mUnk_10 = NULL;
            q += 8;
            p->mUnk_10 = func_ov000_0218e880(q);
            p->mUnk_14++;
            s4 = o->mCallbacks[1];
            if (s4.mCallback == NULL) {
                break;
            }
            p2 = func_ov000_021a3690(0x40c);
            if (p2 == NULL) {
                GpiSetErrorMessage(a, data_ov000_021b2814);
                return 1;
            }
            GpiCopyString(p2->mUnk_008, c, 0x401);
            p2->mUnk_000 = y;
            p2->mUnk_004 = z;
            r = GpiQueueCallback(a, s4, p2, NULL, 6);
            if (r != 0) {
                return r;
            }
            break;
        case 100:
            p = GpiFindOrAddProfile(a, y);
            if (p == NULL) {
                GpiSetErrorMessage(a, data_ov000_021b2814);
                return 1;
            }
            if (p->mBuddyStatus == NULL) {
                p->mBuddyStatus = func_ov000_021a3690(0x18);
                if (p->mBuddyStatus == NULL) {
                    GpiSetErrorMessage(a, data_ov000_021b2814);
                    return 1;
                }
                w = (u8 *) p->mBuddyStatus;
                i = 0x18;
                do {
                    *w++ = 0;
                } while (--i != 0);
                p->mBuddyStatus->mIndex = o->mBuddyCount++;
            }
            t = p->mBuddyStatus;
            if (GpiGetValue(b, data_ov000_021b27d0, c, 0x1000) == 0) {
                GpiSetError(a, 1, data_ov000_021b27d8);
                GpiQueueErrorCallback(a, 3, 1);
                return 3;
            }
            if (GpiGetValue(c, data_ov000_021b2830, e, 0x10) == 0) {
                GpiSetError(a, 1, data_ov000_021b27d8);
                GpiQueueErrorCallback(a, 3, 1);
                return 3;
            }
            t->mUnk_04 = StrtolBase10(e);
            func_ov000_021a3668(t->mUnk_08);
            t->mUnk_08 = NULL;
            if (GpiGetValue(c, data_ov000_021b2834, d, 0x100) == 0) {
                d[0] = 0;
            }
            t->mUnk_08 = func_ov000_0218e880(d);
            if (t->mUnk_08 == NULL) {
                GpiSetErrorMessage(a, data_ov000_021b2814);
                return 1;
            }
            func_ov000_021a3668(t->mUnk_0c);
            t->mUnk_0c = NULL;
            if (GpiGetValue(c, data_ov000_021b283c, d, 0x100) == 0) {
                d[0] = 0;
            }
            t->mUnk_0c = func_ov000_0218e880(d);
            if (t->mUnk_0c == NULL) {
                GpiSetErrorMessage(a, data_ov000_021b2814);
                return 1;
            }
            if (GpiGetValue(c, data_ov000_021b2844, e, 0x10) == 0) {
                t->mUnk_10 = 0;
            } else {
                t->mUnk_10 = (((u32) StrtolBase10(e) >> 24) & 0xff) | (((u32) StrtolBase10(e) >> 8) & 0xff00) |
                             (((u32) StrtolBase10(e) << 8) & 0xff0000) | (((u32) StrtolBase10(e) << 24) & 0xff000000);
            }
            if (GpiGetValue(c, data_ov000_021b284c, e, 0x10) == 0) {
                t->mUnk_14 = 0;
            } else {
                h = StrtolBase10(e);
                t->mUnk_14 = (u16) (((h >> 8) & 0xff) | ((h << 8) & 0xff00));
            }
            s3 = o->mCallbacks[2];
            if (s3.mCallback == NULL) {
                break;
            }
            p1 = func_ov000_021a3690(0xc);
            if (p1 == NULL) {
                GpiSetErrorMessage(a, data_ov000_021b2814);
                return 1;
            }
            p1->mUnk_00 = y;
            p1->mUnk_08 = (void *) t->mIndex;
            p1->mUnk_04 = z;
            r = GpiQueueCallback(a, s3, p1, NULL, 5);
            if (r != 0) {
                return r;
            }
            break;
        case 101:
            if (GpiGetValue(b, data_ov000_021b27d0, c, 0x1000) == 0) {
                GpiSetError(a, 1, data_ov000_021b27d8);
                GpiQueueErrorCallback(a, 3, 1);
                return 3;
            }
            q = strstr(c, data_ov000_021b284c);
            if (q == NULL) {
                GpiSetError(a, 1, data_ov000_021b27d8);
                GpiQueueErrorCallback(a, 3, 1);
                return 3;
            }
            if ((s8) q[3] == 0) {
                GpiSetError(a, 1, data_ov000_021b27d8);
                GpiQueueErrorCallback(a, 3, 1);
                return 3;
            }
            n = StrtolBase10(q + 3);
            q = strstr(c, data_ov000_021b2850);
            if (q != NULL) {
                GpiCopyString(d, (q + 3), 0x100);
            } else {
                d[0] = 0;
            }
            s2 = o->mCallbacks[4];
            if (s2.mCallback == NULL) {
                break;
            }
            p3 = func_ov000_021a3690(0x108);
            if (p3 == NULL) {
                GpiSetErrorMessage(a, data_ov000_021b2814);
                return 1;
            }
            p3->mUnk_000 = y;
            p3->mUnk_004 = n;
            strcpy(p3->mUnk_008, d);
            r = GpiQueueCallback(a, s2, p3, NULL, 0);
            if (r != 0) {
                return r;
            }
            break;
        case 102:
            if (GpiGetValue(b, data_ov000_021b27d0, c, 0x1000) == 0) {
                GpiSetError(a, 1, data_ov000_021b27d8);
                GpiQueueErrorCallback(a, 3, 1);
                return 3;
            }
            func_ov000_0218fb3c(a, y, 0x67, data_ov000_021b2854);
            break;
    }
    return 0;
}

u32 func_ov000_0218fbe0(GpConnection *a, s32 b, s32 c, const char *d) {
    GpiConnection *o;
    char e[0xdad];
    o = a->mGpiConnection;
    GpiCopyString(e, d, 0xdad);
    GpiAppendBufferString(a, &o->mOutputBuffer, data_ov000_021b27c4);
    GpiAppendBufferNumber(a, &o->mOutputBuffer, c);
    GpiAppendBufferString(a, &o->mOutputBuffer, data_ov000_021b275c);
    GpiAppendBufferNumber(a, &o->mOutputBuffer, o->mSesskey);
    GpiAppendBufferString(a, &o->mOutputBuffer, data_ov000_021b27cc);
    GpiAppendBufferNumber(a, &o->mOutputBuffer, b);
    GpiAppendBufferString(a, &o->mOutputBuffer, data_ov000_021b27d0);
    GpiAppendBufferString(a, &o->mOutputBuffer, e);
    GpiAppendBufferString(a, &o->mOutputBuffer, data_ov000_021b2778);
    return 0;
}

u32 func_ov000_0218fb3c(GpConnection *a, s32 b, s32 c, const char *d) {
    GpiProfile *e;
    GpiPeer *n;
    u32 r;
    n = func_ov000_02193f2c(a, b);
    if (n == NULL) {
        if (GpiFindProfile(a, b, &e) == 0 || e->mBuddyStatus == NULL || e->mBuddyStatus->mUnk_14 == 0) {
            return func_ov000_0218fbe0(a, b, c, d);
        }
        n = GpiPeerCreate(a, b, 1);
        if (n == NULL) {
            return 1;
        }
        if (e->mUnk_18 == NULL) {
            r = func_ov000_02193e70(a, n);
            if (r != 0) {
                return r;
            }
        } else {
            r = GpiPeerConnect(a, n);
            if (r != 0) {
                return r;
            }
        }
    }
    r = GpiPeerQueueMessage(a, n, c, d);
    if (r == 0) {
        return 0;
    }
    return r;
}

u32 func_ov000_0218faac(GpConnection *a, u32 b) {
    GpiConnection *o;
    GpiProfile *e;
    u32 r;
    o = a->mGpiConnection;
    if (GpiFindProfile(a, b, &e) == 0) {
        GpiSetErrorMessage(a, data_ov000_021b273c);
        return 2;
    }
    if (e->mUnk_10 == NULL) {
        GpiSetErrorMessage(a, data_ov000_021b273c);
        return 2;
    }
    r = func_ov000_02190548(a, e);
    if (r == 0) {
        e->mUnk_14--;
        if (o->mUnk_100 == 0 && e->mUnk_14 <= 0) {
            func_ov000_021a3668(e->mUnk_10);
            e->mUnk_10 = NULL;
            if (GpiIsProfileEmpty(e) != 0) {
                GpiRemoveProfile(a, e);
            }
        }
        return 0;
    }
    return r;
}

s32 GpiDecrementBuddyIndexAbove(void *unused, Unk0218fa98 *object, s32 minimum) {
    if (object->mUnk_08 != NULL && *object->mUnk_08 > minimum) {
        --*object->mUnk_08;
    }
    return 1;
}

u32 GpiWriteDelbuddyAndRemoveBuddy(GpConnection *p, u32 b) {
    GpiConnection *o;
    GpiProfile *e;
    s32 n;

    o = p->mGpiConnection;
    if (GpiFindProfile(p, b, &e) == 0) {
        GpiSetErrorMessage(p, data_ov000_021b273c);
        return 2;
    }
    GpiAppendBufferString(p, &o->mOutputBuffer, data_ov000_021b2750);
    GpiAppendBufferString(p, &o->mOutputBuffer, data_ov000_021b275c);
    GpiAppendBufferNumber(p, &o->mOutputBuffer, o->mSesskey);
    GpiAppendBufferString(p, &o->mOutputBuffer, data_ov000_021b2768);
    GpiAppendBufferNumber(p, &o->mOutputBuffer, e->mProfileId);
    GpiAppendBufferString(p, &o->mOutputBuffer, data_ov000_021b2778);
    if (e->mBuddyStatus != NULL) {
        n = e->mBuddyStatus->mIndex;
        if (n < 0) {
            AssertionFailed(data_ov000_021b2780, data_ov000_021b278c, NULL, 0x1fd);
        }
        func_ov000_021a3668(e->mBuddyStatus->mUnk_08);
        e->mBuddyStatus->mUnk_08 = NULL;
        func_ov000_021a3668(e->mBuddyStatus->mUnk_0c);
        e->mBuddyStatus->mUnk_0c = NULL;
        func_ov000_021a3668(e->mBuddyStatus);
        e->mBuddyStatus = NULL;
        if (GpiIsProfileEmpty(e) != 0) {
            GpiRemoveProfile(p, e);
        }
        o->mBuddyCount--;
        if (o->mBuddyCount < 0) {
            AssertionFailed(data_ov000_021b2798, data_ov000_021b278c, NULL, 0x204);
        }
        GpiForEachProfileWhileNonZero(p, GpiDecrementBuddyIndexAbove, (void *) n);
    }
    return 0;
}
