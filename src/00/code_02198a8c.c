#include "00/code_02198a8c.h"

#include "00/code_02198714.h"
#include "00/code_02198d04.h"
#include "00/code_0219903c.h"
#include "00/code_0219a000.h"
#include "00/code_0219a01c.h"
#include "00/code_0219a044.h"
#include "00/code_0219a09c.h"
#include "00/code_0219a0d0.h"
#include "00/code_0219a3f4.h"
#include "00/code_021988e8.h"
#include "00/code_0219a430.h"
#include "00/unk_021b3000.h"
#include "00/code_02197b34.h"
#include "00/code_02197e58.h"
#include "00/code_02197000.h"
#include "00/code_02197ddc.h"
#include "string.h"
#include "code_02134398.h"

static inline void func_ov000_02198ba8_inline(void *a, const void *b) {
    u8 *p = a;
    const u8 *q = b;
    p[0] = q[0];
    p[1] = q[1];
}

BOOL func_ov000_02198c58(Gt2Connection *a, u8 *b, int c) {
    int d;
    u8 *e;
    if (c < 2 || memcmp(b, data_ov000_021b3fa4, 2) != 0) {
        if (SendConnectionBytes(a, b, c) == 0) {
            return FALSE;
        }
        return TRUE;
    }
    d = c + 2;
    if (GetBufferUnusedSize(&a->mSendBuffer) < d) {
        return TRUE;
    }
    e = a->mSendBuffer.mData + a->mSendBuffer.mLength;
    AppendBufferBytes(&a->mSendBuffer, data_ov000_021b3fa4, 2);
    AppendBufferBytes(&a->mSendBuffer, b, c);
    if (SendConnectionBytes(a, e, d) == 0) {
        return FALSE;
    }
    RemoveBufferBytes(&a->mSendBuffer, -1, d);
    return TRUE;
}

BOOL func_ov000_02198c08(Gt2Connection *a) {
    u8 b[3];
    func_ov000_02198ba8_inline(b, data_ov000_021b3fa4);
    b[2] = 0x64;
    func_ov000_0219a01c(b, 3, a->mUnk_66);
    if (SendConnectionBytes(a, b, 5) == 0) {
        return FALSE;
    }
    a->mUnk_90 = 0;
    return TRUE;
}

BOOL func_ov000_02198ba8(Gt2Connection *a, u16 b, u16 c) {
    u8 d[7];
    int e;
    e = 0;
    func_ov000_02198ba8_inline(d, data_ov000_021b3fa4);
    d[2] = 0x65;
    func_ov000_0219a01c(d, 3, b);
    e += 5;
    if (b != c) {
        func_ov000_0219a01c(d, e, c);
        e += 2;
    }
    if (SendConnectionBytes(a, d, e) == 0) {
        return FALSE;
    }
    return TRUE;
}

u32 func_ov000_02198b9c(u32 arg0, u32 arg1, u32 arg2) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2 = arg2;
    u32 value3;
    value3 = 103u;
    *(u8 *) ((value1) + 2u) = value3;
    value3 = (u32) &SendConnectionBytes;
    value0 = SendConnectionBytes((Gt2Connection *) value0, (u8 *) value1, value2);
    return value0;
}

int func_ov000_02198b8c(Gt2Connection *a) {
    return func_ov000_02198b50(a->mSocket, a->mAddress, a->mPort);
}

BOOL func_ov000_02198b50(Gt2Socket *a, u32 b, int c) {
    u8 d[3];

    __memcpy(d, data_ov000_021b3fa4, 2);
    d[2] = 0x68;
    if (func_ov000_0219a110((u32 *) a, b, c, (u32) d, 3) != 0) {
        return TRUE;
    }
    return FALSE;
}

BOOL func_ov000_02198af4(Gt2Connection *a, Unk02198af4 *b) {
    func_ov000_0219a01c(a->mSendBuffer.mData, b->mUnk_00 + 5, a->mUnk_66);
    if (SendConnectionBytes(a, a->mSendBuffer.mData + b->mUnk_00, b->mUnk_04) == 0) {
        return FALSE;
    }
    b->mUnk_0c = a->mLastSendTime;
    if (a->mSendBuffer.mData[b->mUnk_00 + 2] == 2) {
        a->mUnk_8c = a->mLastSendTime;
    }
    return TRUE;
}

int func_ov000_02198ad8(Gt2Connection *a, u8 *b, int c, int d) {
    if (d != 0) {
        return func_ov000_02198f80(a, b, c);
    }
    return func_ov000_02198c58(a, b, c);
}

u32 func_ov000_02198ac4(Gt2Socket **a, const char *b, u32 c, u32 d, u32 e) {
    return CreateSocket(a, b, c, d, e);
}

void func_ov000_02198ab0(Gt2Socket *a) {
    func_ov000_021988e8(a);
    DeleteSocket(a);
}

void func_ov000_02198a8c(Gt2Socket *a) {
    if (func_ov000_0219914c(a) != 0) {
        if (func_ov000_0219a09c(a) != 0) {
            func_ov000_0219a06c(a);
        }
    }
}
