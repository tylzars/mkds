#include "00/code_0218a9bc.h"
#include "00/code_0218aea4.h"
#include "00/code_0218cd74.h"
#include "00/types_0218b928.h"
#include "00/code_0218d000.h"

#include "00/code_021a3668.h"
#include "00/code_021a3690.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "00/code_021a3678.h"
#include "00/code_0218dd8c.h"
#include "code_0214177c.h"
#include "00/code_0218afd4.h"
#include "00/unk_021b4000.h"

void func_ov000_0218afb8(u32 *a) {
    func_ov000_0218d0e4((u32) (0), (u32) (*a));
    func_ov000_0218d0e4((u32) (0), (u32) (a[1]));
    return;
}

u32 func_ov000_0218afac(Unk0218afac *entry, u32 modulus) {
    return func_ov000_0218afd4(entry->mName, modulus);
}

s32 func_ov000_0218afa0(const char *const *first, const char *const *second) {
    return func_02142368(*first, *second);
}

u32 func_ov000_0218af9c(SbServer *a) {
    return a->mPing;
}

SbServer *func_ov000_0218af28(SbServerList *a, u32 b, u16 c) {
    SbServer *p;
    p = func_ov000_021a3690(0x24);
    if (p == NULL) {
        return NULL;
    }
    p->mKeyValues =
        HashtableCreate(8, 8, 4, (s32(*)(void *, s32)) func_ov000_0218afac,
                        (s32(*)(void *, void *)) func_ov000_0218afa0, (void (*)(void *)) func_ov000_0218afb8);
    if (p->mKeyValues == NULL) {
        func_ov000_021a3668(p);
        return NULL;
    }
    p->mUnk_14 = 0;
    p->mUnk_15 = 0;
    p->mUnk_20 = NULL;
    p->mPing = 0;
    p->mUnk_10 = 0;
    p->mUnk_00 = b;
    p->mUnk_04 = c;
    p->mUnk_08 = 0;
    p->mUnk_0c = 0;
    return p;
}

void func_ov000_0218af24(SbServer *a, s32 b) {
    a->mUnk_15 = b;
    return;
}

void func_ov000_0218af1c(SbServer *a, u32 b, u16 c) {
    a->mUnk_08 = b;
    a->mUnk_0c = c;
    return;
}

void func_ov000_0218af18(SbServer *a, u32 b) {
    a->mUnk_10 = b;
    return;
}

void func_ov000_0218af14(SbServer *a, u8 b) {
    a->mUnk_14 = b;
    return;
}

u8 func_ov000_0218af10(SbServer *a) {
    return a->mUnk_14;
}

u32 func_ov000_0218aefc(SbServer *a) {
    if (a == *(SbServer **) &data_ov000_021b4d1c) {
        return 1;
    }
    return 0;
}

void func_ov000_0218aedc(Unk0218ae68 *a, SbServer *b) {
    if (a->mUnk_04 != NULL) {
        a->mUnk_04->mUnk_20 = b;
    }
    a->mUnk_04 = b;
    b->mUnk_20 = NULL;
    if (a->mUnk_00 == NULL) {
        a->mUnk_00 = b;
    }
    a->mUnk_08 = a->mUnk_08 + 1;
    return;
}

void func_ov000_0218aec4(Unk0218ae68 *a, SbServer *b) {
    b->mUnk_20 = a->mUnk_00;
    a->mUnk_00 = b;
    if (a->mUnk_04 == NULL) {
        a->mUnk_04 = b;
    }
    a->mUnk_08 = a->mUnk_08 + 1;
    return;
}

SbServer *func_ov000_0218aea4(Unk0218ae68 *a) {
    SbServer *v1;
    v1 = a->mUnk_00;
    if (v1 != NULL) {
        a->mUnk_00 = v1->mUnk_20;
        if (a->mUnk_00 == NULL) {
            a->mUnk_04 = NULL;
        }
        a->mUnk_08 = a->mUnk_08 + -1;
    }
    return v1;
}
