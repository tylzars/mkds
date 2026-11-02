#include "00/code_0218dc44.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "00/code_021a3678.h"
#include "00/code_021a3690.h"
#include "code_02134d30.h"

#include "00/code_0218db48.h"

void func_ov000_0218dd74(void *b, s32 c) {
    Unk0218dc94 *a = b;
    if (a->mUnk_10 != 0) {
        a->mUnk_10(func_ov000_0218dbf8(a, c));
    }
}

void func_ov000_0218dd38(Unk0218dc94 *a) {
    a->mUnk_04 = a->mUnk_04 + a->mUnk_0c;
    a->mUnk_14 = func_ov000_021a3678(a->mUnk_14, a->mUnk_04 * a->mUnk_08);
    if (a->mUnk_14 == 0) {
        func_0213442c(data_ov000_021b2348, data_ov000_021b22dc, 0, 0x41);
    }
}

void func_ov000_0218dd18(Unk0218dc94 *a, const void *b, s32 c) {
    memcpy(func_ov000_0218dbf8(a, c), b, a->mUnk_08);
}

void *func_ov000_0218dc94(s32 b, s32 c, void (*d)(void *)) {
    Unk0218dc94 *a = func_ov000_021a3690(0x18);
    if (a == 0) {
        func_0213442c(data_ov000_021b2334, data_ov000_021b22dc, 0, 0x52);
    }
    if (b == 0) {
        func_0213442c(data_ov000_021b233c, data_ov000_021b22dc, 0, 0x53);
    }
    if (c == 0) {
        c = 8;
    }
    a->mUnk_00 = 0;
    a->mUnk_04 = c;
    a->mUnk_08 = b;
    a->mUnk_0c = c;
    a->mUnk_10 = d;
    if (a->mUnk_04 != 0) {
        a->mUnk_14 = func_ov000_021a3690(a->mUnk_04 * a->mUnk_08);
        if (a->mUnk_14 == 0) {
            func_0213442c(data_ov000_021b2348, data_ov000_021b22dc, 0, 0x5e);
        }
    } else {
        a->mUnk_14 = 0;
    }
    return a;
}

void func_ov000_0218dc48(void *c) {
    Unk0218dc94 *a = c;
    s32 b;
    if (a == 0) {
        func_0213442c(data_ov000_021b2334, data_ov000_021b22dc, 0, 0x69);
    }
    b = 0;
    if (0 < a->mUnk_00) {
        do {
            func_ov000_0218dd74(a, b);
            b = b + 1;
        } while (b < a->mUnk_00);
    }
    func_ov000_021a3668(a->mUnk_14);
    func_ov000_021a3668(a);
    return;
}

s32 func_ov000_0218dc44(void *b) {
    Unk0218dc94 *a = b;
    return a->mUnk_00;
}
