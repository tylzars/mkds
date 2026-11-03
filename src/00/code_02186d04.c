#include "00/code_02186d04.h"
#include "00/unk_021b1000.h"
#include "03/code_021b94b8.h"
#include "00/code_021adbac.h"
#include "00/code_021acef8.h"
#include "00/code_02186a9c.h"

#include "00/code_02186000.h"
#include "00/code_02186628.h"
#include "00/code_021a9200.h"
#include "00/code_021ab548.h"
#include "00/code_021ae258.h"
#include "00/code_021ae304.h"
#include "00/code_021b0014.h"
#include "code_0200d118.h"
#include "code_0200db4c.h"
#include "code_0200f5ac.h"
#include "code_0200fe7c.h"
#include "code_0213a460.h"
#include "code_02139f70.h"
#include "code_0214d018.h"
#include "00/code_021ae2f4.h"
#include "00/code_021adb80.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_0200edc0.h"
#include "code_0200e77c.h"

s32 func_ov000_021873d4(Unk02186d7c *p, const Unk021873d4 *q) {
    func_0214d168(p, 0, 0x1a60);
    p->mContentLength = -1;
    p->mUnk_04 = *q;
    p->mLowReceiveBuffer = p->mUnk_04.mUnk_10(data_ov000_021b1320, 0xb68);
    if (p->mLowReceiveBuffer == NULL) {
        p->mResult = 1;
        return 1;
    }
    p->mLowSendBuffer = p->mUnk_04.mUnk_10(data_ov000_021b1334, 0x5ea);
    if (p->mLowSendBuffer == NULL) {
        p->mResult = 1;
        return 1;
    }
    func_ov000_021868d0((Http *) p, (const u8 *) q->mUnk_00);
    p->mResult = func_ov000_02186c74((Http *) p);
    if (p->mResult == 0) {
        p->mUnk_00 = 0xff;
    }
    return p->mResult;
}

u32 func_ov000_0218735c(Unk02186d7c *p) {
    char v1[8];
    u32 n;
    if (func_ov000_02186bd4((Http *) p, data_ov000_021b135c, data_ov000_021b1368) != 0) {
        return 1;
    }
    n = strlen(strstr(p->mSendBuffer.mStart, data_ov000_021b1230) + 4);
    if (n != 0) {
        func_0200d9e0(v1, 7, data_ov000_021b1370, n);
        if (func_ov000_02186bd4((Http *) p, data_ov000_021b1374, (const u8 *) v1) != 0) {
            return 1;
        }
    }
    return 0;
}

void func_ov000_021872bc(Unk02186d7c *p) {
    u32 n;
    n = func_0200dcd8(data_0216ff5c.mUnk_04);
    p->mUnk_a40 = 0;
    func_0200edc0(&p->mUnk_a28);
    func_0200edc0(&p->mUnk_948);
    if (p->mUnk_04.mUnk_18 == 1) {
        data_ov000_021b4ca8 = 1;
    } else {
        data_ov000_021b4ca8 = 0;
    }
    if (p->mThread.mUnk_6c == 0 || func_0200e070(&p->mThread) != 0) {
        func_0200e28c(&p->mThread, func_ov000_02186d7c, p, p->mUnk_1a60, 0x1000, n - 1);
        func_0200df68(&p->mThread);
    }
}

void func_ov000_02187274(Unk02186d7c *p) {
    if (p->mUnk_00 == 0xff) {
        func_0200ed34(&p->mUnk_a28);
        p->mUnk_a40 = 1;
        func_0200ecc4(&p->mUnk_a28);
        if (p->mThread.mUnk_6c != 0) {
            func_0200e084(&p->mThread);
        }
    }
}

u32 func_ov000_02187230(Unk02186d7c *a) {
    func_0200ed34(&a->mUnk_a28);
    if (a->mUnk_a40 == 1) {
        func_0200ecc4(&a->mUnk_a28);
        return 0;
    }
    func_0200ecc4(&a->mUnk_a28);
    func_0200dc3c((u32) 10);
    return 1;
}

void func_ov000_02186d7c(void *l) {
    Unk02186d7c *p = l;
    Unk02186d7cB4 *a;
    Unk02186d7c118 *b;
    Unk02186d7cBuf *c;
    const u8 *x;
    s32 d;
    int g;
    u64 t0;
    u64 t1;
    u8 f;
    int h;
    u32 m;
    s32 r;
    u64 t;
    s8 *q;
    s8 e;
    s32 n;
    Unk0201000c v1;
    u8 *s;
    const u8 *y;

    f = 0;
    a = &p->mUnk_b4;
    b = &p->mUnk_118;
    c = &p->mReceiveBuffer;
    d = p->mUnk_04.mUnk_1c;
    if (d <= 0) {
        d = 60000;
    }
    func_0214d168(a, 0, 0x64);
    a->mUnk_3c = 0xb68;
    a->mUnk_40 = p->mLowReceiveBuffer;
    a->mUnk_48 = 0x5ea;
    a->mUnk_4c = p->mLowSendBuffer;
    func_ov000_021ae304((void *) a);
    g = func_ov000_021acef8((const char *) p->mHost);
    if (g == 0) {
        p->mResult = 2;
        return;
    }
    func_ov000_021ae270();
    if (p->mUseHttps == 1) {
        func_0214d168(b, 0, 0x804);
        b->mUnk_7e4 = func_ov000_02186a84;
        b->mUnk_7d4 = p->mHost;
        a->mUnk_0c = b;
        func_ov000_021ab594((u32) data_ov000_021b1204, 0xb);
        func_ov000_021a9200(1);
        h = 0x1bb;
    } else {
        h = 0x50;
    }
    func_ov000_021ae290(0, h, g);
    t0 = func_0200f5ac();
    if (p->mUseHttps == 1) {
        func_0201000c(&v1);
        func_ov000_021a9c5c(&v1, 0x20);
        t1 = t0;
    }
    if (func_ov000_021ae134() != 0) {
        p->mResult = 3;
        func_ov000_021ae258();
        func_ov000_021ae2f4();
        return;
    }
    p->mSendBuffer.mCursor = p->mSendBuffer.mStart;
    s = p->mSendBuffer.mStart;
    p->mSendBuffer.mEnd = s + strlen(s);
    while (p->mSendBuffer.mCursor < p->mSendBuffer.mEnd) {
        if (data_ov000_021b63b4 == 0) {
            p->mResult = 5;
            goto fail;
        }
        n = p->mSendBuffer.mEnd - p->mSendBuffer.mCursor;
        if (n > 0x238) {
            n = 0x238;
        }
        n = func_ov000_021adbf4(p->mSendBuffer.mCursor, n);
        if (n <= 0) {
            p->mResult = 5;
            goto fail;
        }
        func_ov000_021adb80();
        t = func_0200f5ac();
        if ((u64) d < (t - t0) * 64 / 0x82ea) {
            p->mResult = 4;
            goto fail;
        }
        if (p->mUseHttps == 1) {
            if (1000 < (t - t1) * 64 / 0x82ea) {
                func_0201000c(&v1);
                func_ov000_021a9c5c(&v1, 0x20);
                t1 = t;
            }
        }
        p->mSendBuffer.mCursor += n;
        if (func_ov000_02187230(p) == 0) {
            p->mResult = 7;
            goto fail;
        }
    }
    FreeHttpBuffer((Http *) p, (HttpBuffer *) &p->mSendBuffer);
    func_0200ed34(&p->mUnk_948);
    if (p->mUnk_04.mUnk_08 == NULL) {
        if (InitHttpBuffer((Http *) p, (HttpBuffer *) &p->mReceiveBuffer, p->mUnk_04.mUnk_0c) == 0) {
            p->mResult = 1;
            func_0200ecc4(&p->mUnk_948);
            goto fail;
        }
    } else {
        p->mReceiveBuffer.mStart = p->mUnk_04.mUnk_08;
        p->mReceiveBuffer.mCursor = p->mReceiveBuffer.mStart;
        p->mReceiveBuffer.mEnd = p->mReceiveBuffer.mStart + p->mUnk_04.mUnk_0c;
        p->mReceiveBuffer.mSize = p->mUnk_04.mUnk_0c;
    }
    c->mCursor = c->mStart;
    c->mEnd = c->mStart + c->mSize;
    func_0200ecc4(&p->mUnk_948);
    while (1) {
        if (data_ov000_021b63b4 == 0) {
            p->mResult = 5;
            goto fail;
        }
        func_0200ed34(&p->mUnk_948);
        if (c->mCursor >= c->mEnd - 1) {
            func_0200ecc4(&p->mUnk_948);
            break;
        }
        n = func_ov000_021adbac();
        if (n > 0) {
            x = func_ov000_021adf78((u32 *) &n);
            if (x == NULL) {
                func_0200ecc4(&p->mUnk_948);
                break;
            }
            r = c->mEnd - 1 - c->mCursor;
            m = n;
            if ((s32) m >= r) {
                m = r;
            }
            func_0214d1fc(x, c->mCursor, m);
            c->mCursor += m;
            *c->mCursor = 0;
            if (f != 1) {
                s = c->mStart;
                if (strstr(s, data_ov000_021b1230) != NULL) {
                    f = 1;
                    p->mBodyStart = strstr(s, data_ov000_021b1230) + 4;
                    y = strstr(c->mStart, data_ov000_021b1348);
                    if (y != NULL) {
                        y = y + strlen(data_ov000_021b1348);
                        q = (s8 *) strstr(y, data_ov000_021b1258);
                        e = *q;
                        *q = 0;
                        p->mContentLength = func_0213bf90(y);
                        *q = e;
                    }
                }
            }
            if (n > m) {
                func_ov000_021adf00(n);
                func_0200ecc4(&p->mUnk_948);
                break;
            }
            func_ov000_021adf00(m);
        }
        if (n < 0) {
            func_0200ecc4(&p->mUnk_948);
            break;
        }
        if (p->mContentLength > 0 && n > 0 && p->mBodyStart + p->mContentLength <= c->mCursor) {
            func_0200ecc4(&p->mUnk_948);
            break;
        }
        t = func_0200f5ac();
        if ((u64) d < (t - t0) * 64 / 0x82ea) {
            p->mResult = 6;
            func_0200ecc4(&p->mUnk_948);
            goto fail;
        }
        if (p->mUseHttps == 1) {
            if (1000 < (t - t1) * 64 / 0x82ea) {
                func_0201000c(&v1);
                func_ov000_021a9c5c(&v1, 0x20);
                t1 = t;
            }
        }
        func_0200ecc4(&p->mUnk_948);
        if (func_ov000_02187230(p) == 0) {
            p->mResult = 7;
            goto fail;
        }
    }
    func_ov000_021ae094();
    func_ov000_021ae048();
    func_ov000_021ae258();
    func_ov000_021ae2f4();
    p->mResult = 8;
    return;
fail:
    func_ov000_021ae094();
    func_ov000_021ae048();
    func_ov000_021ae258();
    func_ov000_021ae2f4();
}

void ReleaseHttp(Http *a) {
    if (a != NULL) {
        if (a->mGivenReceiveBuffer == 0) {
            FreeHttpBuffer(a, &a->mReceiveBuffer);
        }
        FreeHttpBuffer(a, &a->mSendBuffer);
        if (a->mLowReceiveBuffer != NULL) {
            a->mFree(data_ov000_021b1320, a->mLowReceiveBuffer, 0);
            a->mLowReceiveBuffer = NULL;
        }
        if (a->mLowSendBuffer != NULL) {
            a->mFree(data_ov000_021b1334, a->mLowSendBuffer, 0);
            a->mLowSendBuffer = NULL;
        }
        func_0214d168(a, 0, 0x1a60);
    }
    return;
}
