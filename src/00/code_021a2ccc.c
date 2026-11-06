#include "00/code_021a2ccc.h"

#include "00/code_021988e8.h"
#include "00/code_021a1ae0.h"
#include "03/code_021b94b8.h"
#include "Main/Unknown/code_0200f000.h"
#include "00/code_0219b580.h"
#include "00/unk_021b5000.h"
#include "00/code_0219c384.h"
#include "00/code_021a1000.h"
#include "00/code_021a2000.h"
#include "code_0200f5ac.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"
#include "00/code_0219b000.h"
#include "code_021329f8.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_02139f70.h"
#include "00/unk_021b4000.h"
#include "string.h"
#include "code_02134398.h"

void func_ov000_021a3250(u32 (*arg0)(void)) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    value1 = (u32) &gWiFiMessageLayer;
    value2 = (u32) * (const u32 *) ((value1) + 0u);
    value1 = 0x600u;
    *(u32 *) ((value2) + (value1)) = value0;
    return;
}

void func_ov000_021a323c(void (*arg0)(u32, void *, u32)) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    value1 = (u32) &gWiFiMessageLayer;
    value2 = (u32) * (const u32 *) ((value1) + 0u);
    value1 = 0x604u;
    *(u32 *) ((value2) + (value1)) = value0;
    return;
}

void func_ov000_021a321c(Unk021a31e8 *a, u16 b, u32 c) {
    strncpy((char *) a->mUnk_06, data_ov000_021b41f0, 2);
    a->mUnk_04 = b;
    a->mUnk_00 = c;
    return;
}

u16 func_ov000_021a31e8(const void *a) {
    Unk021a31e8 t;
    MI_CpuCopy8(a, &t, 8);
    if (memcmp(t.mUnk_06, data_ov000_021b41f0, 2) == 0) {
        return t.mUnk_04;
    }
    return 0;
}

s32 func_ov000_021a31d4(s32 value) {
    switch (value) {
        case 2:
        case 3:
        case 4:
            return 12;
        default:
            return 8;
    }
}

// Per login (called by InitWiFiConnection): stores gWiFiMessageLayer, zeroes the struct and sets mSendChunkSize.
void InitWiFiMessageLayer(WiFiMessageLayer *state) {
    gWiFiMessageLayer = state;
    MI_CpuFill8(state, 0, sizeof(WiFiMessageLayer));
    gWiFiMessageLayer->mSendChunkSize = 0x5b9;
}

void func_ov000_021a317c(Unk0219887c *a, void *b, s32 c, u32 d) {
    if (gWiFiMessageLayer != NULL) {
        if (d != 0) {
            func_ov000_021a2eec(a, b, c);
        } else {
            func_ov000_021a2e7c(a, b, c);
        }
    }
}

void func_ov000_021a314c(Unk0219887c *a, u32 b) {
    if (gWiFiMessageLayer->mUnk_60c != NULL) {
        gWiFiMessageLayer->mUnk_60c(b, func_ov000_0219b9c4(a));
    }
}

// One step per frame in connection state 6 (returns at once when the layer is NULL): for each participant (except the
// own index) continues the chunked send and, when the elapsed time since the last receive exceeds the peer's limit,
// calls the timeout callback func (mUnk_608; no writer in src).
void UpdateWiFiMessageLayer(void) {
    u8 *l;
    s32 n;
    s32 i;
    u8 d;
    WiFiPeerMessage *e;
    s32 m;
    s32 k;
    u64 t;
    if (gWiFiMessageLayer != NULL) {
        n = func_ov000_0219bb04(&l);
        for (i = 0; i < n; i++) {
            d = l[i];
            if (d != func_ov000_0219bb50() && func_ov000_021a2fc8(d) == 1) {
                e = func_ov000_021a2fdc(d);
                m = e->mSendSize - e->mSentSize;
                k = gWiFiMessageLayer->mSendChunkSize;
                if (m <= k) {
                    k = m;
                }
                if (func_ov000_021a2d18(d) < k) {
                    continue;
                }
                func_ov000_021a2f98(d, (e->mSendBuffer + e->mSentSize), k, 1);
                e->mSentSize += k;
                if (e->mSentSize == e->mSendSize) {
                    if (gWiFiMessageLayer->mSendCallback != NULL) {
                        gWiFiMessageLayer->mSendCallback(e->mSendSize, d);
                    }
                    e->mUnk_1c = 0;
                    e->mSendBuffer = NULL;
                    e->mSentSize = 0;
                    e->mSendSize = 0;
                }
            }
            if (func_ov000_0219bac8(d) != 0) {
                e = func_ov000_021a2fdc(d);
                if (gWiFiMessageLayer->mUnk_608 != NULL && e->mUnk_2c != 0) {
                    t = OS_GetTick();
                    if ((u32) _ll_udiv((t - e->mUnk_24) << 6, 0x82ea) > e->mUnk_2c) {
                        gWiFiMessageLayer->mUnk_608(d);
                        e->mUnk_24 = t;
                    }
                }
            }
        }
    }
}

void func_ov000_021a2ff8(int a) {
    if (gWiFiMessageLayer != NULL) {
        gWiFiMessageLayer->mPeers[a].mSentSize = 0;
        gWiFiMessageLayer->mPeers[a].mReceivedSize = 0;
        gWiFiMessageLayer->mPeers[a].mSendSize = 0;
        gWiFiMessageLayer->mPeers[a].mReceiveSize = 0;
        gWiFiMessageLayer->mPeers[a].mUnk_1c = 0;
        gWiFiMessageLayer->mPeers[a].mMessageKind = 0;
    }
    return;
}

void func_ov000_021a2fec(void) {
    gWiFiMessageLayer = NULL;
    return;
}

WiFiPeerMessage *func_ov000_021a2fdc(int a) {
    return &gWiFiMessageLayer->mPeers[a];
}

u8 func_ov000_021a2fc8(int a) {
    return gWiFiMessageLayer->mPeers[a].mUnk_1c;
}

u8 func_ov000_021a2fb4(int a) {
    return gWiFiMessageLayer->mPeers[a].mReceiveState;
}

void func_ov000_021a2f98(u32 a, void *b, u32 c, u32 d) {
    void *v1;
    v1 = func_ov000_0219b9d4(a);
    func_ov000_02198914(v1, b, c, d);
    return;
}

void func_ov000_021a2eec(Unk0219887c *a, void *b, s32 c) {
    u8 v1 = func_ov000_0219b9c4(a);
    switch (func_ov000_021a2fb4(v1)) {
        case 0: {
            u16 n = func_ov000_021a31e8(b);
            if (n >= 2 && n <= 4) {
                func_ov000_021a2dfc(v1, b, c);
            }
            break;
        }
        case 1:
            func_ov000_021a2dfc(v1, b, c);
            break;
        case 2:
            func_ov000_021a2d68(v1, b, c);
            break;
        case 3:
            func_ov000_021a2d38(v1, b, c);
            break;
        case 4:
            gWiFiMessageLayer->mPeers[v1].mReceiveState = 1;
            gWiFiMessageLayer->mPeers[v1].mReceivedSize = 0;
            gWiFiMessageLayer->mPeers[v1].mReceiveSize = 0;
            break;
        default:
            OS_Terminate();
            break;
    }
}

void func_ov000_021a2e7c(Unk0219887c *a, const void *b, int c) {
    int v1;
    WiFiPeerMessage *v2;
    u64 v3;
    v1 = func_ov000_0219b9c4(a);
    v2 = &gWiFiMessageLayer->mPeers[v1];
    if ((v2->mReceiveBuffer != NULL) && (v2->mReceiveBufferSize >= c)) {
        MI_CpuCopy8(b, v2->mReceiveBuffer, c);
        if (gWiFiMessageLayer->mReceiveCallback != NULL) {
            gWiFiMessageLayer->mReceiveCallback(v1, v2->mReceiveBuffer, c);
        }
        if ((gWiFiMessageLayer->mUnk_608 != NULL) && (v2->mUnk_2c != 0)) {
            v3 = OS_GetTick();
            v2->mUnk_24 = v3;
        }
    }
}

void func_ov000_021a2dfc(int a, void *b, s32 c) {
    WiFiPeerMessage *e = &gWiFiMessageLayer->mPeers[a];
    u32 t[2];
    u16 n;
    e->mUnk_1e = func_ov000_021a2fb4(a);
    n = func_ov000_021a31e8(b);
    switch (n) {
        case 1:
            if (c != 8) {
                return;
            }
            MI_CpuCopy8(b, t, 8);
            e->mReceiveSize = t[0];
            e->mReceivedSize = 0;
            if (e->mReceiveBuffer != NULL && e->mReceiveBufferSize >= e->mReceiveSize) {
                e->mReceiveState = 2;
            } else {
                e->mReceiveState = 4;
            }
            break;
        case 2:
        case 3:
        case 4:
            e->mReceiveState = 3;
            break;
    }
    e->mMessageKind = n;
}

void func_ov000_021a2d68(int a, void *b, s32 c) {
    WiFiPeerMessage *e = &gWiFiMessageLayer->mPeers[a];
    s32 n;
    if (func_ov000_021a2fb4(a) == 2) {
        if (e->mReceivedSize + c > e->mReceiveBufferSize) {
            OS_Terminate();
        }
        MI_CpuCopy8(b, e->mReceiveBuffer + e->mReceivedSize, c);
    }
    e->mReceivedSize += c;
    n = e->mReceiveSize;
    if (e->mReceivedSize == n) {
        e->mReceiveState = 1;
        e->mReceivedSize = 0;
        e->mReceiveSize = 0;
        if (gWiFiMessageLayer->mReceiveCallback != NULL) {
            gWiFiMessageLayer->mReceiveCallback(a, e->mReceiveBuffer, n);
        }
    }
    if (gWiFiMessageLayer->mUnk_608 != NULL && e->mUnk_2c != 0) {
        e->mUnk_24 = OS_GetTick();
    }
}

void func_ov000_021a2d38(u32 a, void *b, s32 c) {
    WiFiPeerMessage *e = func_ov000_021a2fdc(a);
    e->mReceiveState = e->mUnk_1e;
    switch (e->mMessageKind) {
        case 2:
        case 3:
        case 4:
            func_ov000_021a18e0(a, e->mMessageKind, b);
            break;
    }
}

s32 func_ov000_021a2d18(u32 a) {
    s32 n = func_ov000_021988dc(func_ov000_0219b9d4(a)) - 0x207;
    if (n <= 0) {
        n = 0;
    }
    return n;
}

BOOL func_ov000_021a2ccc(void) {
    if (gWiFiMatching == NULL || gWiFiMatching->mUnk_1e8 == 0 || func_ov000_0219c39c() != 0) {
        return FALSE;
    }
    if (func_ov000_021a2768(gWiFiMatching->mUnk_1e8) == 0) {
        return TRUE;
    }
    return FALSE;
}
