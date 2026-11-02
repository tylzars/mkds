#include "00/code_0218b280.h"
#include "00/code_0218aea4.h"
#include "00/code_0218d000.h"
#include "code_02135014.h"
#include "code_0213442c.h"
#include "code_02139f70.h"
#include "code_0213a460.h"

double func_ov000_0218b280(Unk0218af28 *e, const u8 *v1, double d) {
    u8 *a;
    a = func_ov000_0218b30c(e, v1, NULL);
    if (a != NULL) {
        d = atof(a);
    }
    return d;
}

s32 func_ov000_0218b2a8(Unk0218af28 *e, const u8 *v1, s32 d) {
    u8 *a;
    s32 c;
    if (strcmp(v1, data_ov000_021b21c8) == 0) {
        return func_ov000_0218af9c((s32) e);
    }
    a = func_ov000_0218b30c(e, v1, NULL);
    if (a == NULL || (c = *a, !((c < 0 || c >= 0x80) ? 0 : (data_0215d284[c] & 8)))) {
        return d;
    }
    return func_0213bf90(a);
}

u8 *func_ov000_0218b30c(Unk0218af28 *e, const u8 *v1, u8 *d) {
    Unk0218b30c a;
    u32 *b;
    if (e == NULL) {
        func_0213442c(data_ov000_021b21d0, data_ov000_021b21d8, NULL, 0x97);
    }
    if (e == NULL) {
        return NULL;
    }
    a.mUnk_00 = v1;
    b = func_ov000_0218de28(e->mUnk_18, &a);
    if (b != NULL) {
        d = (u8 *) b[1];
    }
    return d;
}

void func_ov000_0218b358(Unk0218af28 *e, const u8 *v1, u32 c) {
    u8 a[20];
    sprintf(a, data_ov000_021b21e4, c);
    func_ov000_0218b380(e, v1, a);
}

void func_ov000_0218b380(Unk0218af28 *e, const u8 *v1, const u8 *v2) {
    u8 *a[2];
    a[0] = func_ov000_0218d134(NULL, v1);
    a[1] = func_ov000_0218d134(NULL, v2);
    func_ov000_0218def0(e->mUnk_18, a);
}
