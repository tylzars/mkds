#include "00/code_02190548.h"
#include "00/code_02190000.h"
#include "code_02139f70.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "00/code_0218dc44.h"
#include "00/code_0218e368.h"
#include "00/code_021965a0.h"
#include "00/code_02190ba0.h"
#include "00/code_02196000.h"
#include "code_02135014.h"
#include "00/code_021906e4.h"
#include "00/code_021967b4.h"
#include "00/unk_021b23b0.h"
#include "code_02134d30.h"
#include "code_0213a460.h"

u32 func_ov000_02190548(Unk0218f960 *a, Unk02194934 *b) {
    Unk0218f960_00 *o;
    o = a->mUnk_00;
    func_ov000_02190b80(a, &o->mUnk_1f4, data_ov000_021b2858);
    func_ov000_02190b80(a, &o->mUnk_1f4, data_ov000_021b275c);
    func_ov000_02190b58(a, &o->mUnk_1f4, o->mUnk_198);
    func_ov000_02190b80(a, &o->mUnk_1f4, data_ov000_021b2864);
    func_ov000_02190b58(a, &o->mUnk_1f4, b->mUnk_00);
    func_ov000_02190b80(a, &o->mUnk_1f4, data_ov000_021b2874);
    func_ov000_02190b80(a, &o->mUnk_1f4, b->mUnk_10);
    func_ov000_02190b80(a, &o->mUnk_1f4, data_ov000_021b2778);
    return 0;
}

u32 func_ov000_021905d4(Unk0218f960 *a, Unk021906e4 *b) {
    s32 n;
    if (b == NULL || b->mUnk_00 == NULL || (n = b->mUnk_0c) == 0) {
        return 0;
    }
    b->mUnk_08 = b->mUnk_08 - n;
    if (b->mUnk_08 != 0) {
        memmove(b->mUnk_00, b->mUnk_00 + b->mUnk_0c, b->mUnk_08);
    }
    b->mUnk_00[b->mUnk_08] = 0;
    b->mUnk_0c = 0;
    return 0;
}

u32 func_ov000_02190618(Unk0218f960 *a, Unk021906e4 *b, s32 *c, s32 *d, s32 *e) {
    u8 f[0x10];
    u8 *p;
    s32 n;
    s32 m;
    *c = 0;
    if (b->mUnk_08 < 5) {
        return 0;
    }
    p = (u8 *) strchr(b->mUnk_00, 10);
    if (p != NULL) {
        if (strncmp(p - 5, data_ov000_021b287c, 5) != 0) {
            return 3;
        }
        *p = 0;
        if (func_ov000_021967b4(b->mUnk_00, data_ov000_021b2884, f, 0x10) == 0) {
            return 3;
        }
        *d = func_0213bf90(f);
        if (func_ov000_021967b4(b->mUnk_00, data_ov000_021b2888, f, 0x10) == 0) {
            return 3;
        }
        n = func_0213bf90(f);
        m = n + 1;
        if (b->mUnk_08 > m + (p - b->mUnk_00)) {
            if (*(s8 *) (p + m) != 0) {
                return 3;
            }
            *c = (s32) (p + 1);
            *e = n;
            b->mUnk_0c = m + (p - b->mUnk_00) + 1;
        } else {
            *p = 10;
        }
    }
    return 0;
}
