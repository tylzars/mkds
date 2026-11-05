#include "00/code_0219b1f8.h"
#include "00/code_0218d818.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "string.h"
#include "code_02134398.h"
#include "00/unk_021b4000.h"
#include "00/code_0218e2dc.h"
#include "00/code_0219887c.h"
#include "00/code_0219a654.h"
#include "00/code_0219b580.h"
#include "00/code_0219c384.h"
#include "00/code_0219d000.h"
#include "00/code_0219c000.h"
#include "00/unk_021b5000.h"
#include "code_02139f70.h"
#include "00/code_0219d128.h"
#include "code_0200d118.h"
#include "00/code_021a10b0.h"
#include "00/code_021a17bc.h"
#include "00/code_021a1ae0.h"
#include "00/code_021a2ccc.h"
#include "00/code_021a3a18.h"
#include "code_0213a460.h"

// GP callback slot 3 (message). The first branch hands the text to func_ov000_0219d6c4 (the "I have authorized ..."
// sentence); the second takes GPCM-prefixed text with a MAT tag and forwards it to the matching code only in state 5
// or matching mode 2 and 3.
void WiFiGpMessageCallback(GpConnection *a, Unk0219b4b4 *b, u32 g) {
    char *d;
    char c[12] = {0};
    u32 e;
    WiFiConnection *f;

    d = b->mUnk_08;
    if (func_ov000_0219d6c4(a, (u32 *) b, g) == 0) {
        if (memcmp(d, data_ov000_021b4058, strlen(data_ov000_021b4058)) == 0) {
            d += strlen(data_ov000_021b4058);
            e = strchr(d, 0x76) - d;
            strncpy(c, d, e);
            if (e <= 10) {
                if (strtoul(c, NULL, 10) == 3) {
                    d += e + 1;
                    if (memcmp(d, data_ov000_021b4060, strlen(data_ov000_021b4060)) == 0) {
                        f = gWiFiConnection;
                        if (f->mState == 5 || f->mMatching.mMode == 2 || f->mMatching.mMode == 3) {
                            d += strlen(data_ov000_021b4060);
                            func_ov000_021a1ae0(a, b->mUnk_00, d);
                        }
                    }
                }
            }
        }
    }
}

// Slot 1 of the Gt2ConnectionCallbacks record (the library's Gt2CallDataCallback, code_02197e58.c:152): the body
// only forwards (connection, data, size, flag) to func_ov000_021a317c, the receive side of the message layer.
void WiFiGt2DataCallback(Unk0219887c *a, void *b, s32 c, u32 d) {
    func_ov000_021a317c(a, b, c, d);
}

void func_ov000_0219b27c(Unk0219887c *a, u32 b) {
    u32 e;
    s32 d;
    BOOL f;
    u8 *g;
    u32 h;
    s32 c;
    u32 i;
    WiFiConnection *j;
    u32 k;
    void **m;

    e = 0;
    f = FALSE;
    if (func_ov000_021a141c() != 0) {
        return;
    }
    switch (b) {
        case 0:
        case 1:
            c = 0;
            break;
        case 2:
        case 3:
            c = 6;
            d = -0x1db0;
            break;
        case 4:
            c = 0xb;
            d = -0x1db1;
            break;
    }
    if (c == 0) {
        g = func_ov000_0219887c(a);
        if (g == NULL) {
            return;
        }
        h = g[1];
        i = (gWiFiConnection->mMatching.mParticipantMask & (1 << h)) != 0;
        func_ov000_021a2ff8(h);
        j = gWiFiConnection;
        if ((j->mMatching.mMode == 2 && b == 0) || (j->mMatching.mMode == 3 && h == 0)) {
            f = TRUE;
        }
        e = func_ov000_0219b868(h);
        data_ov000_021b54d0[g[0]] = NULL;
        gWiFiConnection->mMatching.mLastParticipantPos--;
        gWiFiConnection->mMatching.mUnk_14--;
    }
    if (gWiFiConnection->mUnk_2d == 0 && gWiFiConnection->mState == 6 && i == 0) {
        if (gWiFiConnection->mMatching.mMode == 2 && c == 0) {
            func_ov000_021a1488();
            func_ov000_021a1798(e);
        }
        return;
    }
    if (func_ov000_021a17bc(c, d, e) != 0) {
        return;
    }
    if (c != 0) {
        func_ov000_0219c384(c, d);
        return;
    }
    if (gWiFiConnection->mMatching.mMode == 2) {
        if (gWiFiConnection->mUnk_2d == 0) {
            func_ov000_021a1488();
        } else if (gWiFiConnection->mMatching.mLastParticipantPos == 0) {
            func_ov000_0219d558(1, data_ov000_021b4054, NULL);
        }
    } else if (gWiFiConnection->mMatching.mLastParticipantPos == 0) {
        func_ov000_0219d558(1, data_ov000_021b4054, NULL);
    }
    if (gWiFiConnection->mMatching.mMode == 0 || gWiFiConnection->mMatching.mMode == 1) {
        gWiFiConnection->mMatching.mUnk_16 = gWiFiConnection->mMatching.mUnk_14;
        func_ov000_021a4818(gWiFiConnection->mMatching.mUnk_10);
    }
    j = gWiFiConnection;
    if (j->mUnk_7c != NULL && i != 0) {
        if (b == 0) {
            b = 1;
        } else {
            b = 0;
        }
        k = FindBuddyEntryIndex(e);
        m = &j->mUnk_80;
        gWiFiConnection->mUnk_7c(c, b, f, h, k, *m);
    }
    if (gWiFiConnection->mUnk_2d != 0 || gWiFiConnection->mMatching.mMode != 2) {
        if (gWiFiConnection->mMatching.mLastParticipantPos == 0) {
            func_ov000_0219b110();
            func_ov000_021a1a10();
            SetWiFiConnectionState(3);
        }
    }
}

// Slot 3 of the record (Gt2CallElapsedTimeCallback, code_02197e58.c:196): the body only forwards (connection,
// elapsed time) to func_ov000_021a314c, which calls the layer's mUnk_60c with the time and the peer index.
void WiFiGt2ElapsedTimeCallback(Unk0219887c *a, u32 b) {
    func_ov000_021a314c(a, b);
}

void func_ov000_0219b240(u32 *a) {
    data_ov000_021b54cc = func_ov000_0218e368(GetSocketDescriptor(a));
    func_ov000_0219c384(0xb, -0x17aeb);
    gWiFiConnection->mSocket = NULL;
}

Unk0219b1d4 *func_ov000_0219b1f8(u32 a) {
    s32 b;
    Unk0219b1d4 *c;

    if (data_ov000_021b52c4 == NULL) {
        return NULL;
    }
    for (b = 0; b < DarrayGetCount((u32 *) data_ov000_021b52c4); b++) {
        c = DarrayGetElement(data_ov000_021b52c4, b);
        if (c->mUnk_08 == a) {
            return c;
        }
    }
    return NULL;
}
