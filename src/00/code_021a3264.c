#include "00/code_021a3264.h"
#include "00/code_0219b580.h"
#include "00/code_0219b000.h"
#include "00/unk_021b5000.h"
#include "00/code_0219c384.h"
#include "00/code_021a2ccc.h"
#include "00/unk_021b4000.h"
#include "code_02139f70.h"
#include "code_0200d118.h"
#include "code_0200f5ac.h"
#include "code_0200fc8c.h"
#include "code_021329f8.h"
#include "string.h"
#include "code_02134398.h"

u32 func_ov000_021a363c(void *param_1, void *param_2, void *param_3, u32 param_4) {
    StringFormatBounded(param_3, 0x1000, data_ov000_021b41f4, param_4, param_1, param_4, param_2);
    return strlen(param_3);
}

u32 func_ov000_021a360c(void *param_1, void *param_2, void *param_3, u32 param_4) {
    func_ov000_021a363c(param_1, param_2, strchr(param_3, 0), param_4);
    return strlen(param_3);
}

s32 func_ov000_021a3530(const char *a, char *b, const char *c, int d) {
    const char *p;
    const char *q;
    s32 n;
    enum { K1 = 1 } k;
    if (b == NULL) {
        return -1;
    }
    p = strchr(c, d);
    if (p == NULL) {
        return -1;
    }
    k = K1;
    while (1) {
        if (strncmp(p + 1, a, strlen(a)) == 0 && (n = strlen(a), n += (u32) p, d == *(s8 *) (n + k))) {
            break;
        }
        q = strchr(p + 1, d);
        if (q == NULL) {
            return -1;
        }
        p = strchr(q + 1, d);
        if (p == NULL) {
            return -1;
        }
    }
    p = strchr(p + 1, d);
    if (p == NULL) {
        return -1;
    }
    q = strchr(p + 1, d);
    if (q != NULL) {
        n = q - (p + 1);
    } else {
        n = strlen(p + 1);
    }
    strncpy(b, p + 1, n);
    b[n] = 0;
    return n;
}

u64 func_ov000_021a350c(void) {
    return _ll_udiv(OS_GetTick() << 6, 0x82ea);
}

u32 func_ov000_021a3448(u32 a) {
    u64 s;
    u64 t;
    if (data_ov000_021b5dd4.mUnk_00 == 0 && data_ov000_021b5dd4.mUnk_08 == 0 && data_ov000_021b5dd4.mUnk_10 == 0) {
        OS_GetMacAddress(&s);
        t = OS_GetTick();
        s = ((s >> 24) & 0xffffff) | (t << 24);
        data_ov000_021b5dd4.mUnk_00 = s;
        data_ov000_021b5dd4.mUnk_08 = 0x5d588b656c078965;
        data_ov000_021b5dd4.mUnk_10 = 0x269ec3;
    }
    data_ov000_021b5dd4.mUnk_00 =
        data_ov000_021b5dd4.mUnk_08 * data_ov000_021b5dd4.mUnk_00 + data_ov000_021b5dd4.mUnk_10;
    if (a == 0) {
        return (u32) (data_ov000_021b5dd4.mUnk_00 >> 32);
    }
    return (u32) (((data_ov000_021b5dd4.mUnk_00 >> 32) * a) >> 32);
}

BOOL func_ov000_021a33e4(u32 a, s32 b) {
    if ((b == 1 && func_ov000_0219bac8(a) == 0) || func_ov000_0219b8bc(a) == FALSE) {
        return FALSE;
    }
    if (func_ov000_021a2fc8(a) == 1) {
        return FALSE;
    }
    if (func_ov000_021a2d18(a) >= func_ov000_021a31d4(b)) {
        return TRUE;
    }
    return FALSE;
}

// Starts a send of kind a (1 = data) to peer b: refuses (FALSE) while an error is pending or func_ov000_021a33e4 says
// no (peer not usable, kind 1 to a non-participant, already sending, or less send room than the header needs); marks
// the peer sending, stores the buffer and size, writes the 8-byte header and the first chunk (when the socket has no
// room for the chunk it returns TRUE after the header); UpdateWiFiMessageLayer sends the later chunks; calls
// mSendCallback when the whole message went out at once (kind 1 only).
BOOL StartPeerMessageSend(u16 a, u32 b, u8 *c, s32 d) {
    WiFiPeerMessage *e = func_ov000_021a2fdc(b);
    Unk021a31e8 t;
    s32 n;
    if (func_ov000_0219c39c() != 0) {
        return FALSE;
    }
    if (func_ov000_021a33e4(b, a) == FALSE) {
        return FALSE;
    }
    e->mUnk_1c = 1;
    e->mSendBuffer = c;
    e->mSentSize = 0;
    e->mSendSize = d;
    func_ov000_021a321c(&t, a, d);
    func_ov000_021a2f98(b, &t, 8, 1);
    n = gWiFiMessageLayer->mSendChunkSize;
    if (d <= n) {
        n = d;
    }
    if (n > func_ov000_021a2d18(b)) {
        return TRUE;
    }
    func_ov000_021a2f98(b, c, n, 1);
    e->mSentSize += n;
    if (e->mSentSize == e->mSendSize) {
        if (gWiFiMessageLayer->mSendCallback != NULL && a == 1) {
            gWiFiMessageLayer->mSendCallback(e->mSendSize, b);
        }
        e->mUnk_1c = 0;
        e->mSendBuffer = NULL;
        e->mSentSize = 0;
        e->mSendSize = 0;
    }
    return TRUE;
}

BOOL func_ov000_021a32a0(u32 a, void *b, s32 c) {
    if (func_ov000_0219c39c() != 0) {
        return FALSE;
    }
    if (func_ov000_0219bac8(a) == 0) {
        return FALSE;
    }
    if (c > gWiFiMessageLayer->mSendChunkSize) {
        return FALSE;
    }
    func_ov000_021a2f98(a, b, c, 0);
    if (gWiFiMessageLayer->mSendCallback != NULL) {
        gWiFiMessageLayer->mSendCallback(c, a);
    }
    return TRUE;
}

// Gives peer a the buffer b of capacity c to receive into and sets mReceiveState to 1 with both received counters 0;
// refuses (FALSE) while a body is being received into the old buffer (state 2).
BOOL SetPeerReceiveBuffer(u32 a, void *b, s32 c) {
    WiFiPeerMessage *e = func_ov000_021a2fdc(a);
    if (func_ov000_021a2fb4(a) == 2) {
        return FALSE;
    }
    e->mReceiveBuffer = b;
    e->mReceiveBufferSize = c;
    e->mReceiveState = 1;
    e->mReceivedSize = 0;
    e->mReceiveSize = 0;
    return TRUE;
}
