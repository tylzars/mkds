#include "00/code_02197b34.h"
#include "00/code_02198748.h"
#include "00/code_02198d04.h"
#include "00/code_0219a0d0.h"
#include "00/code_0219a61c.h"
#include "00/code_021a3690.h"
#include "code_02134d30.h"

int func_ov000_0219885c(void *a, Gt2Connection **b, int c, u32 d) {
    int r = func_ov000_0219a28c(a, b, c, d);
    if (r != 0) {
        return r;
    }
    (*b)->mUnk_0c = 0;
    (*b)->mUnk_10 = 1;
    return 0;
}

int func_ov000_0219883c(void *a, Gt2Connection **b, int c, u32 d) {
    int r = func_ov000_0219a28c(a, b, c, d);
    if (r != 0) {
        return r;
    }
    (*b)->mUnk_0c = 2;
    (*b)->mUnk_10 = 0;
    return 0;
}

BOOL func_ov000_021987c8(Gt2Connection *a, void *b, int c, Gt2ConnectionCallbacks *d) {
    s8 e[0x24];
    func_ov000_0219a61c((const u8 **) &b, (s32 *) &c);
    if (c > 0) {
        a->mUnk_38.mData = func_ov000_021a3690(c);
        if (a->mUnk_38.mData == NULL) {
            return TRUE;
        }
        memcpy(a->mUnk_38.mData, b, c);
        a->mUnk_38.mSize = c;
    }
    if (d != NULL) {
        a->mCallbacks = *d;
    }
    func_ov000_02197be0(e);
    func_ov000_02197b34((s8 *) a->mUnk_68, e);
    func_ov000_02198f24(a, e);
    a->mUnk_0c = 0;
    return FALSE;
}

BOOL func_ov000_02198778(Gt2Connection *a, Gt2ConnectionCallbacks *b) {
    if (a->mUnk_14 != 0) {
        a->mUnk_14 = 0;
        return FALSE;
    }
    a->mUnk_14 = 0;
    if (a->mUnk_0c != 4) {
        return FALSE;
    }
    func_ov000_02198df8(a);
    a->mUnk_0c = 5;
    if (b != NULL) {
        a->mCallbacks = *b;
    }
    return TRUE;
}

void func_ov000_02198748(Gt2Connection *a, void *b, u32 c, ...) {
    a->mUnk_14 = 0;
    if (a->mUnk_0c == 4) {
        func_ov000_0219a61c((const u8 **) &b, (s32 *) &c);
        func_ov000_02198d9c(a, b, c);
        a->mUnk_0c = 6;
    }
}
