#include "00/code_02197b34.h"
#include "00/code_0218e2dc.h"
#include "00/code_02197e8c.h"
#include "00/unk_021b3000.h"
#include "code_02134420.h"
#include "code_0213442c.h"
#include "code_02134d30.h"
#include "code_021384cc.h"
#include "code_02139f70.h"

void AppendBufferBytes(Gt2Buffer *a, const u8 *b, int c) {
    if (b != NULL && c != 0) {
        if (c == -1) {
            c = strlen((const char *) b);
        }
        if (a->mLength + c > a->mSize) {
            func_0213442c(data_ov000_021b3eec, data_ov000_021b3ebc, NULL, 0x40);
        }
        memcpy(a->mData + a->mLength, b, c);
        a->mLength = a->mLength + c;
    }
}

void RemoveBufferBytes(Gt2Buffer *a, int b, int c) {
    if (b == -1) {
        b = a->mLength - c;
    }
    if (b > a->mLength) {
        func_0213442c(data_ov000_021b3ea4, data_ov000_021b3ebc, NULL, 0x4f);
    }
    if (c > a->mLength - b) {
        func_0213442c(data_ov000_021b3ec8, data_ov000_021b3ebc, NULL, 0x50);
    }
    memmove(a->mData + b, a->mData + b + c, a->mLength - b - c);
    a->mLength = a->mLength - c;
}

BOOL func_ov000_02197ca0(const s8 *a) {
    s32 b[8];
    u32 h;
    u32 g;
    s32 e;
    s32 f;
    u32 c;
    u32 d;
    e = 0;
    f = 1;
    c = (u8) a[0];
    b[0] = c;
    b[0] &= f;
    b[2] = e;
    b[1] = f;
    b[4] = e;
    b[3] = f;
    b[6] = f;
    b[5] = f;
    b[7] = f;
    do {
        d = (u8) a[f - 1];
        if (d < c) {
            g = b[1];
        } else {
            g = b[2];
        }
        if (c < 0x4f) {
            h = b[3];
        } else {
            h = b[4];
        }
        e ^= (f ^ d) & b[5];
        d = b[0];
        d ^= e;
        d ^= h;
        e = d;
        e ^= g;
        if ((e != 0 && ((u8) a[f] & b[6]) == 0) || (e == 0 && ((u8) a[f] & b[7]) == 1)) {
            return FALSE;
        }
        f++;
    } while (f < 0x20);
    return TRUE;
}

s8 *func_ov000_02197be0(s8 *a) {
    s32 b[9];
    u32 c;
    u32 h;
    u32 d;
    s32 f;
    s32 e;
    u32 g;
    u8 *i;
    if (a == NULL) {
        func_0213442c(data_ov000_021b3e90, data_ov000_021b3e98, NULL, 0x2b);
    }
    srand(func_ov000_0218e8c4());
    a[0] = (s32) rand() % 0x5d + 0x21;
    e = 0;
    f = 1;
    b[1] = e;
    b[0] = f;
    b[3] = e;
    b[2] = f;
    b[5] = f;
    b[4] = f;
    b[6] = f;
    b[7] = f;
    do {
        c = (u8) a[f - 1];
        d = (u8) a[0];
        if (c < d) {
            g = b[0];
        } else {
            g = b[1];
        }
        if (d < 0x4f) {
            h = b[2];
        } else {
            h = b[3];
        }
        d &= b[5];
        b[8] = f;
        b[8] ^= c;
        b[8] &= b[4];
        e ^= b[8];
        d ^= e;
        d ^= h;
        e = d;
        e ^= g;
        i = (u8 *) &a[f];
        a[f] = (s32) rand() % 0x5d + 0x21;
        if ((e != 0 && (*i & b[6]) == 0) || (e == 0 && (*i & b[7]) == 1)) {
            (*i)++;
        }
        f++;
    } while (f < 0x20);
    return a;
}

s8 *func_ov000_02197b34(s8 *a, const s8 *b) {
    s32 d;
    s32 c;
    s32 e;
    s32 f;
    s32 g;
    s32 i;
    c = strlen((const char *) data_ov000_021b3e6c);
    d = func_ov000_02197ca0(b);
    e = 0;
    f = 0;
    do {
        if (d == 0 || e == 0 || e == 0xd) {
            a[e] = (s32) rand() % 0x5d + 0x21;
        } else {
            if (e == 1 || e == 0xe) {
                g = b[e];
            } else {
                g = b[e - 1];
            }
            i = (data_ov000_021b3e6c[(e + (u8) b[e]) % c] + e * (u8) b[e]) % 0x20;
            a[e] = (s32) func_02134420((u8) b[i] ^ data_ov000_021b3e6c[(g * f) % c]) % 0x5d + 0x21;
        }
        f += 0x4647;
        e++;
    } while (e < 0x20);
    return a;
}
