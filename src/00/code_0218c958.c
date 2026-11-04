#include "00/code_0218c958.h"
#include "00/code_0218b3ac.h"
#include "00/code_0218cd74.h"
#include "00/code_0218d000.h"
#include "00/code_0218d818.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "00/code_0218e2dc.h"
#include "00/code_02196000.h"
#include "00/code_02196590.h"
#include "00/code_021a3678.h"
#include "code_02134d30.h"
#include "00/code_021965a0.h"
#include "00/code_02190ff8.h"
#include "code_02135014.h"
#include "00/code_02190000.h"
#include "code_02139f70.h"
#include "00/code_021906e4.h"
#include "00/code_021a3690.h"
#include "code_021384cc.h"
#include "00/code_021a3668.h"

// non-matching: loop temporaries get other registers (values in r4/r0 swapped) and the stack word at 0x20 is never
// stored (0xac bytes against 0xb6)
void func_ov000_0218ccbc(SbServerList *p) {
    s32 v1;
    s32 v2;
    s32 v3;
    s32 v4;
    BOOL v5;
    s32 v6;
    s32 v7;
    s32 v8;
    s32 t;
    s32 s;
    s32 i;
    p->mUnk_074[0] = (s32) rand() % 0x5d + 0x21;
    s = 0;
    i = 1;
    v2 = 0;
    v1 = 1;
    v4 = 0;
    v3 = 1;
    v6 = 1;
    v5 = TRUE;
    v7 = 1;
    v8 = 1;
    for (; i < 8; i++) {
        s = ((p->mUnk_074[0] & v6) ^ (s ^ (t = i, t ^= p->mUnk_074[i - 1], t &= v5, t))) ^
            ((p->mUnk_074[0] < 0x4f) ? v3 : v4) ^ ((p->mUnk_074[i - 1] < p->mUnk_074[0]) ? v1 : v2);
        p->mUnk_074[i] = (s32) rand() % 0x5d + 0x21;
        if ((s != 0 && (p->mUnk_074[i] & v7) != 0) || (s == 0 && (p->mUnk_074[i] & v8) == 1)) {
            p->mUnk_074[i] = p->mUnk_074[i] + 1;
        }
    }
}

s32 func_ov000_0218cc48(SbServerList *p, void *a, s32 b) {
    s32 i = 1;
    s32 n;
    s32 r;
    do {
        i--;
        n = func_ov000_0218e420(p->mUnk_4b0, a, b, 0);
        if (n > 0) {
            break;
        }
        if (i < 0) {
            break;
        }
        func_ov000_0218c980(p);
        r = func_ov000_0218ca58(p, NULL, NULL, 2, 0);
        if (r != 0) {
            func_ov000_0218cf30(p);
            return r;
        }
    } while (i >= 0);
    if (n <= 0) {
        return 3;
    }
    return 0;
}

// non-matching: the final two-byte copy puts the stack addresses in other registers and a different order (5
// instructions, same size)
s32 func_ov000_0218ca58(SbServerList *p, const char *a, const char *b, u32 c, u32 d) {
    u8 v1[0x300];
    Unk0218ca58 t;
    s32 v2;
    u8 *v3;
    u8 *q;
    s32 r;
    if (p->mState != 1) {
        func_0213442c(data_ov000_021b2240, data_ov000_021b2218, NULL, 0x20a);
    }
    if (a == NULL) {
        a = data_ov000_021b2260;
    }
    if (b == NULL) {
        b = data_ov000_021b2260;
    }
    if (strlen(a) > 0x100) {
        return 6;
    }
    if (strlen(b) > 0x100) {
        return 6;
    }
    r = func_ov000_0218ce14(p);
    if (r != 0) {
        return r;
    }
    p->mUnk_5c4 = c;
    func_ov000_0218ccbc(p);
    v2 = 2;
    q = v1;
    v3 = q + 2;
    func_ov000_0218cdc4(&v3, 0, &v2);
    func_ov000_0218cdc4(&v3, 1, &v2);
    func_ov000_0218cdc4(&v3, 3, &v2);
    func_ov000_0218cd94(&v3, p->mUnk_4b8, &v2);
    func_ov000_0218cdd8(&v3, p->mUnk_00c, &v2);
    func_ov000_0218cdd8(&v3, p->mUnk_030, &v2);
    func_ov000_0218cd74(&v3, p->mUnk_074, 8, &v2);
    func_ov000_0218cdd8(&v3, b, &v2);
    func_ov000_0218cdd8(&v3, a, &v2);
    func_ov000_0218cd94(
        &v3, ((c << 24) & 0xff000000) | (((c << 8) & 0xff0000) | (((c >> 24) & 0xff) | ((c >> 8) & 0xff00))), &v2);
    if ((p->mUnk_5c4 & 8) != 0) {
        func_ov000_0218cd94(&v3, p->mUnk_4a4, &v2);
    }
    if ((p->mUnk_5c4 & 0x80) != 0) {
        func_ov000_0218cd94(&v3, d, &v2);
    }
    *(u16 *) &t = (u16) ((((u16) v2 >> 8) & 0xff) | (((u16) v2 << 8) & 0xff00));
    *(Unk0218ca58 *) q = t;
    if (func_ov000_0218e420(p->mUnk_4b0, v1, v2, 0) <= 0) {
        func_ov000_0218c980(p);
        return 3;
    }
    p->mState = 3;
    p->mUnk_5c8 = 0;
    if (p->mInBuffer == NULL) {
        p->mInBuffer = func_ov000_021a3690(0x1000);
        if (p->mInBuffer == NULL) {
            return 5;
        }
        p->mInBufferLength = 0;
    }
    return 0;
}

void func_ov000_0218ca1c(SbServerList *p) {
    int i;
    for (i = 0; i < p->mUnk_480; i++) {
        func_ov000_0218d0e4(p, (u32) p->mUnk_084[i]);
    }
    p->mUnk_480 = 0;
}

void func_ov000_0218c9d4(SbServerList *p) {
    int i;
    if (p->mUnk_008 != NULL) {
        for (i = 0; i < DarrayGetCount(p->mUnk_008); i++) {
            func_ov000_0218d0e4(p, *(u32 *) DarrayGetElement(p->mUnk_008, i));
        }
        DarrayDelete(p->mUnk_008);
        p->mUnk_008 = NULL;
    }
}

void func_ov000_0218c980(SbServerList *p) {
    if (p->mInBuffer != NULL) {
        func_ov000_021a3668(p->mInBuffer);
    }
    p->mInBuffer = NULL;
    p->mInBufferLength = 0;
    if (p->mUnk_4b0 != -1) {
        func_ov000_0218e53c(p->mUnk_4b0);
    }
    p->mUnk_4b0 = -1;
    p->mState = 1;
    func_ov000_0218c9d4(p);
    p->mUnk_484 = -1;
    func_ov000_0218ca1c(p);
}

void func_ov000_0218c958(SbServerList *p) {
    func_ov000_0218c980(p);
    func_ov000_0218d1a0(p);
    func_ov000_0218b3c8(p);
    if (p->mUnk_004 != NULL) {
        DarrayDelete(p->mUnk_004);
    }
    p->mUnk_004 = NULL;
}
