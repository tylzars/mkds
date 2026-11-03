#include "00/code_02197b34.h"
#include "00/code_02197e8c.h"
#include "00/code_02198ba8.h"
#include "00/code_02197000.h"
#include "00/code_02197ddc.h"
#include "00/code_02198714.h"
#include "00/code_0219a01c.h"
#include "00/unk_021b3000.h"
#include "code_02134d30.h"

static inline void func_ov000_02198ba8_inline(void *a, const void *b) {
    u8 *p = (u8 *) a;
    const u8 *q = b;
    p[0] = q[0];
    p[1] = q[1];
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
    if (func_ov000_02198714((u32 *) a, (u32) d, e) == 0) {
        return FALSE;
    }
    return TRUE;
}

BOOL func_ov000_02198c08(Gt2Connection *a) {
    u8 b[3];
    func_ov000_02198ba8_inline(b, data_ov000_021b3fa4);
    b[2] = 0x64;
    func_ov000_0219a01c(b, 3, a->mUnk_66);
    if (func_ov000_02198714((u32 *) a, (u32) b, 5) == 0) {
        return FALSE;
    }
    a->mUnk_90 = 0;
    return TRUE;
}

BOOL func_ov000_02198c58(Gt2Connection *a, u8 *b, int c) {
    int d;
    u8 *e;
    if (c < 2 || memcmp(b, data_ov000_021b3fa4, 2) != 0) {
        if (func_ov000_02198714((u32 *) a, (u32) b, c) == 0) {
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
    if (func_ov000_02198714((u32 *) a, (u32) e, d) == 0) {
        return FALSE;
    }
    RemoveBufferBytes(&a->mSendBuffer, -1, d);
    return TRUE;
}
