#include "00/code_021906e4.h"
#include "00/code_021947e4.h"
#include "00/code_02194000.h"
#include "00/code_02196914.h"
#include "00/code_021a3668.h"
#include "00/code_021a3690.h"
#include "00/code_02193000.h"
#include "00/code_021a3000.h"
#include "00/code_02196590.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "code_02135014.h"
#include "code_02139f70.h"
#include "code_02134d30.h"
#include "code_0213a460.h"
#include "00/code_021948f8.h"
#include "00/code_0218e0fc.h"
#include "00/code_02191200.h"
#include "00/code_02196480.h"
#include "00/code_02190ff8.h"
#include "00/code_02192d64.h"
#include "00/code_0218d000.h"
#include "00/code_0218d818.h"
#include "00/code_02196000.h"
#include "00/code_02190000.h"
#include "00/code_0218f960.h"
#include "00/code_02194bb8.h"
#include "00/code_02193b88.h"

#include "00/code_0218e2dc.h"
#include "00/code_021967b4.h"
#include "00/code_021a3678.h"
#include "00/code_021965a0.h"
#include "00/code_02194840.h"
#include "00/code_02190cd4.h"

u32 GpiAppendBufferByte(void *a, GpiBuffer *outputBuffer, s32 c) {
    u8 *d;
    s32 e;
    s32 f;

    if (outputBuffer == NULL) {
        AssertionFailed(data_ov000_021b2890, data_ov000_021b28a8, NULL, 0x25);
    }
    e = outputBuffer->mLength;
    f = outputBuffer->mCapacity;
    d = outputBuffer->mBuffer;
    if (f == e) {
        f += 0x800;
        d = func_ov000_021a3678(d, f + 1);
        if (d == NULL) {
            GpiSetErrorMessage(a, data_ov000_021b292c);
            return 1;
        }
    }
    d[e] = c;
    d[e + 1] = 0;
    outputBuffer->mLength += 1;
    outputBuffer->mCapacity = f;
    outputBuffer->mBuffer = d;
    return 0;
}

u32 GpiAppendBufferBytes(void *a, GpiBuffer *outputBuffer, const void *string, s32 stringLen) {
    s32 f;
    u8 *e;
    s32 g;

    if (string == NULL) {
        AssertionFailed(data_ov000_021b2a18, data_ov000_021b28a8, NULL, 0x51);
    }
    if (stringLen < 0) {
        AssertionFailed(data_ov000_021b2a28, data_ov000_021b28a8, NULL, 0x52);
    }
    if (outputBuffer == NULL) {
        AssertionFailed(data_ov000_021b2890, data_ov000_021b28a8, NULL, 0x53);
    }
    if (string == NULL) {
        return 0;
    }
    g = outputBuffer->mLength;
    f = outputBuffer->mCapacity;
    e = outputBuffer->mBuffer;
    if (f - g < stringLen) {
        f += stringLen < 0x800 ? 0x800 : stringLen;
        e = func_ov000_021a3678(e, f + 1);
        if (e == NULL) {
            GpiSetErrorMessage(a, data_ov000_021b292c);
            return 1;
        }
    }
    memcpy(e + g, string, stringLen);
    e[g + stringLen] = 0;
    outputBuffer->mLength += stringLen;
    outputBuffer->mCapacity = f;
    outputBuffer->mBuffer = e;
    return 0;
}

u32 GpiAppendBufferString(void *p0, void *p1, const void *p2) {
    return GpiAppendBufferBytes(p0, p1, p2, strlen(p2));
}

u32 GpiAppendBufferNumber(void *a, void *b, u32 c) {
    char d[0x14];

    sprintf(d, data_ov000_021b29a0, c);
    return GpiAppendBufferString(a, b, d);
}

u32 GpiSendBytes(GpConnection *a, s32 b, const void *c, s32 d, s32 *e, s32 *f, const s8 *g) {
    s32 h;
    u32 i;

    h = func_ov000_0218e420(b, c, d, 0);
    if (h == -1) {
        i = func_ov000_0218e368(b);
        if (i != -6 && i != -0x1a && i != -0x4c) {
            if (g[0] == 0x50 && g[1] == 0x52) {
                return 3;
            }
            GpiSetError(a, 5, data_ov000_021b29cc);
            GpiQueueErrorCallback(a, 3, 0);
            return 3;
        }
        *f = 0;
        *e = 0;
    } else if (h == 0) {
        func_ov000_0219690c(a, data_ov000_021b29f4, g);
        *f = 0;
        *e = 1;
    } else {
        *f = h;
        *e = 0;
    }
    return 0;
}

u32 GpiPeerSendByte(GpConnection *a, Unk02190988 *b, s8 c) {
    s32 d;
    s32 e;
    u32 f;

    if (b->mOutputBuffer.mBuffer == NULL) {
        AssertionFailed(data_ov000_021b29a4, data_ov000_021b28a8, NULL, 0xde);
    }
    if (b->mOutputBuffer.mLength - b->mOutputBuffer.mPos == 0 && DarrayGetCount(b->mQueuedMessages) == 0) {
        f = GpiSendBytes(a, b->mSocket, &c, 1, &d, &e, data_ov000_021b29c8);
        if (f != 0) {
            return f;
        }
        if (e != 0) {
            return 0;
        }
    }
    return GpiAppendBufferByte(a, &b->mOutputBuffer, c);
}

u32 GpiPeerSendBytes(GpConnection *a, Unk02190988 *b, const char *c, s32 d) {
    s32 e;
    s32 f;
    s32 g;
    u32 h;

    if (b->mOutputBuffer.mBuffer == NULL) {
        AssertionFailed(data_ov000_021b29a4, data_ov000_021b28a8, NULL, 0xfb);
    }
    e = 0;
    if (d == 0) {
        return e;
    }
    if (b->mOutputBuffer.mLength - b->mOutputBuffer.mPos == 0 && DarrayGetCount(b->mQueuedMessages) == 0) {
        do {
            h = GpiSendBytes(a, b->mSocket, c + e, d, &f, &g, data_ov000_021b29c8);
            if (h != 0) {
                return h;
            }
            if (g != 0) {
                e += g;
                d -= g;
            }
        } while (g != 0 && d != 0);
    }
    if (d != 0) {
        h = GpiAppendBufferBytes(a, &b->mOutputBuffer, c + e, d);
        if (h != 0) {
            return h;
        }
    }
    return 0;
}

u32 GpiPeerSendString(GpConnection *p0, Unk02190988 *p1, const char *p2) {
    u32 v6 = strlen(p2);
    return GpiPeerSendBytes(p0, p1, p2, v6);
}

u32 GpiReceiveBuffer(GpConnection *a, s32 sock, GpiBuffer *inputBuffer, s32 *bytesRead, u32 *connClosed, const s8 *f) {
    u8 *g;
    s32 h;
    s32 i;
    s32 j;
    BOOL k;
    s32 l;
    BOOL m;
    s32 n;

    if (sock == -1) {
        AssertionFailed(data_ov000_021b28d8, data_ov000_021b28a8, NULL, 0x150);
    }
    if (inputBuffer == NULL) {
        AssertionFailed(data_ov000_021b28f0, data_ov000_021b28a8, NULL, 0x151);
    }
    if (bytesRead == NULL) {
        AssertionFailed(data_ov000_021b2904, data_ov000_021b28a8, NULL, 0x152);
    }
    if (connClosed == NULL) {
        AssertionFailed(data_ov000_021b2918, data_ov000_021b28a8, NULL, 0x153);
    }
    g = inputBuffer->mBuffer;
    h = inputBuffer->mLength;
    i = inputBuffer->mCapacity;
    j = 0;
    k = FALSE;
    l = 0;
    m = FALSE;
    do {
        n = h + 0x800;
        if (n > i) {
            i = n;
            g = func_ov000_021a3678(g, n + 1);
            if (g == NULL) {
                GpiSetErrorMessage(a, data_ov000_021b292c);
                return 1;
            }
        }
        l = func_ov000_0218e460(sock, g + h, i - h, 0);
        if (l == -1) {
            n = func_ov000_0218e368(sock);
            if (n != -6 && n != -0x1a && n != -0x4c) {
                GpiSetErrorMessage(a, data_ov000_021b293c);
                return 3;
            }
        } else if (l == 0) {
            k = TRUE;
            func_ov000_0219690c(a, data_ov000_021b2968, f);
        } else {
            h += l;
            j += l;
        }
        g[h] = 0;
    } while (l != -1 && k == FALSE && j < 0x20000);
    if (j != 0) {
        func_ov000_0219690c(a, data_ov000_021b298c, f, j);
    }
    inputBuffer->mBuffer = g;
    inputBuffer->mLength = h;
    inputBuffer->mCapacity = i;
    *bytesRead = j;
    *connClosed = k;
    return 0;
}

u32 GpiSendBuffer(GpConnection *a, s32 sock, GpiBuffer *outputBuffer, u32 *d, s32 e, const s8 *f) {
    s32 g;
    s32 h;
    u8 *i;
    s32 len;
    s32 pos;
    s32 m;
    s32 l;
    s32 n;
    u32 r;

    if (outputBuffer == NULL) {
        AssertionFailed(data_ov000_021b2890, data_ov000_021b28a8, NULL, 0x1b9);
    }
    i = outputBuffer->mBuffer;
    len = outputBuffer->mLength;
    pos = outputBuffer->mPos;
    l = len - pos;
    m = 0;
    if (l == 0) {
        return m;
    }
    do {
        r = GpiSendBytes(a, sock, i + (pos + m), l, &g, &h, f);
        if (r != 0) {
            return r;
        }
        n = h;
        if (n != 0) {
            m += n;
            l -= n;
        }
    } while (n != 0 && l != 0);
    if (e != 0) {
        if (m > 0) {
            memmove(i, i + m, l + 1);
            len -= m;
        }
    } else {
        pos += m;
    }
    if (len < 0) {
        AssertionFailed(data_ov000_021b28b4, data_ov000_021b28a8, NULL, 0x1de);
    }
    if (pos < 0) {
        AssertionFailed(data_ov000_021b28c0, data_ov000_021b28a8, NULL, 0x1df);
    }
    if (pos > len) {
        AssertionFailed(data_ov000_021b28cc, data_ov000_021b28a8, NULL, 0x1e0);
    }
    outputBuffer->mLength = len;
    outputBuffer->mPos = pos;
    if (d != NULL) {
        *d = g;
    }
    return 0;
}
