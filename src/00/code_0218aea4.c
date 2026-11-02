#include "00/code_0218aea4.h"
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

void func_ov000_0218afb8(u32 *a) {
    func_ov000_0218d0e4((u32) (0), (u32) (*a));
    func_ov000_0218d0e4((u32) (0), (u32) (a[1]));
    return;
}

u32 func_ov000_0218afac(Unk0218afac *entry, u32 modulus) {
    return func_ov000_0218afd4(entry->mName, modulus);
}

s32 func_ov000_0218afa0(const u8 *const *first, const u8 *const *second) {
    return func_02142368(*first, *second);
}

u32 func_ov000_0218af9c(int a) {
    return *(u32 *) (a + 0x1c);
}

Unk0218af28 *func_ov000_0218af28(Unk021b4d24 *a, u32 b, u16 c) {
    Unk0218af28 *p;
    p = func_ov000_021a3690(0x24);
    if (p == 0) {
        return 0;
    }
    p->mUnk_18 =
        func_ov000_0218e004(8, 8, 4, (s32(*)(void *, s32)) func_ov000_0218afac,
                            (s32(*)(void *, void *)) func_ov000_0218afa0, (void (*)(void *)) func_ov000_0218afb8);
    if (p->mUnk_18 == 0) {
        func_ov000_021a3668(p);
        return 0;
    }
    p->mUnk_14 = 0;
    p->mUnk_15 = 0;
    p->mUnk_20 = 0;
    p->mUnk_1c = 0;
    p->mUnk_10 = 0;
    p->mUnk_00 = b;
    p->mUnk_04 = c;
    p->mUnk_08 = 0;
    p->mUnk_0c = 0;
    return p;
}

void func_ov000_0218af24(int a, s32 b) {
    *(u8 *) (a + 0x15) = b;
    return;
}

void func_ov000_0218af1c(int a, u32 b, u16 c) {
    *(u32 *) (a + 8) = b;
    *(u16 *) (a + 0xc) = c;
    return;
}

void func_ov000_0218af18(int a, u32 b) {
    *(u32 *) (a + 0x10) = b;
    return;
}

void func_ov000_0218af14(int a, u8 b) {
    *(u8 *) (a + 0x14) = b;
    return;
}

u8 func_ov000_0218af10(int a) {
    return *(u8 *) (a + 0x14);
}

u32 func_ov000_0218aefc(int a) {
    if (a == (*(int *) &data_ov000_021b4d1c)) {
        return 1;
    }
    return 0;
}

void func_ov000_0218aedc(int *a, int b) {
    if (a[1] != 0) {
        *(int *) (a[1] + 0x20) = b;
    }
    a[1] = b;
    *(u32 *) (b + 0x20) = 0;
    if (*a == 0) {
        *a = b;
    }
    a[2] = a[2] + 1;
    return;
}

void func_ov000_0218aec4(int *a, int b) {
    *(int *) (b + 0x20) = *a;
    *a = b;
    if (a[1] == 0) {
        a[1] = b;
    }
    a[2] = a[2] + 1;
    return;
}

int func_ov000_0218aea4(int *a) {
    int v1;
    v1 = *a;
    if (v1 != 0) {
        *a = *(int *) (v1 + 0x20);
        if (*a == 0) {
            a[1] = 0;
        }
        a[2] = a[2] + -1;
    }
    return v1;
}
