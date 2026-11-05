#include "00/code_0218d488.h"
#include "00/code_0218aea4.h"
#include "00/code_0218b000.h"
#include "00/code_0218e2dc.h"
#include "00/unk_021b4000.h"
#include "00/code_021919ac.h"
#include "00/code_021a3a18.h"
#include "00/unk_021b2000.h"
#include "string.h"
#include "code_02134398.h"
#include "code_02139f70.h"
#include "00/code_021a6d5c.h"

#pragma opt_propagation off

BOOL func_ov000_0218d7bc(const char *a, u32 b, Unk0218ce14 *c) {
    Unk021a8f84 *e;
    c->mUnk_01 = 2;
    c->mUnk_02 = (((u16) b >> 8) & 0xff) | (((u16) b << 8) & 0xff00);
    c->mUnk_04 = func_ov000_0218e374((u32) a);
    if (c->mUnk_04 == -1) {
        e = func_ov000_021a8f84(a);
        if (e == NULL) {
            return FALSE;
        }
        c->mUnk_04 = **e->mUnk_0c;
    }
    return TRUE;
}

void func_ov000_0218d788(void) {
    func_ov000_0218e3e4(data_ov000_021b4dac.mUnk_00, data_ov000_021b4db8, data_ov000_021b4dac.mUnk_4c, 0,
                        data_ov000_021b4db0, 8);
    data_ov000_021b4dac.mUnk_50 = func_ov000_0218e8c4();
}

void func_ov000_0218d6e4(const char *a) {
    char v1[0x40];
    s8 c;
    strcpy(data_ov000_021b4d6c, a);
    data_ov000_021b4dac.mUnk_00 = -1;
    func_ov000_0218e8b8();
    c = data_ov000_021b4d2c[0];
    if (c == 0) {
        sprintf(v1, data_ov000_021b22b4, a);
    }
    if (func_ov000_0218d7bc(c != 0 ? data_ov000_021b4d2c : v1, 0x6cfc, (Unk0218ce14 *) data_ov000_021b4db0) != FALSE) {
        data_ov000_021b4dac.mUnk_00 = func_ov000_0218e554(2, 2, 0);
        if (data_ov000_021b4dac.mUnk_00 != -1) {
            u32 n;
            data_ov000_021b4dac.mUnk_0c = 9;
            n = strlen(a);
            memcpy(data_ov000_021b4dbd, a, n + 1);
            data_ov000_021b4dac.mUnk_4c = n + 6;
            func_ov000_0218d788();
            data_ov000_021b4dac.mUnk_54 = 0;
        }
    }
}

BOOL func_ov000_0218d644(const s8 *a, s32 b, u8 *c, u32 *d) {
    u32 v;
    if (b < 7) {
        return TRUE;
    }
    if (memcmp(c + 4, data_ov000_021b4db4, 4) != 0) {
        return TRUE;
    }
    if (*(u16 *) (c + 2) != data_ov000_021b4dac.mUnk_06) {
        return TRUE;
    }
    if (memcmp((const u8 *) a, data_ov000_021b22b0, 3) != 0) {
        return TRUE;
    }
    v = (a[3] << 24) & 0xff000000;
    v |= (a[4] << 16) & 0xff0000;
    v |= (a[5] << 8) & 0xff00;
    v |= a[6] & 0xff;
    *d = v;
    return FALSE;
}

s32 func_ov000_0218d574(void) {
    Unk0218ce14 v1;
    s32 v2;
    u32 v3;
    s8 v4[0x40];
    v2 = 8;
    if (data_ov000_021b4dac.mUnk_00 == -1) {
        data_ov000_021b4d28 = 1;
        return 1;
    }
    if (func_ov000_0218e668(data_ov000_021b4dac.mUnk_00) != 0 &&
        func_ov000_0218d644(v4, func_ov000_0218e438(data_ov000_021b4dac.mUnk_00, v4, 0x40, 0, (u8 *) &v1, &v2),
                            (u8 *) &v1, &v3) == FALSE) {
        func_ov000_0218e53c(data_ov000_021b4dac.mUnk_00);
        if ((v3 & 1) != 0) {
            data_ov000_021b4d28 = 2;
        } else if ((v3 & 2) != 0) {
            data_ov000_021b4d28 = 3;
        } else {
            data_ov000_021b4d28 = 1;
        }
        return data_ov000_021b4d28;
    }
    if (func_ov000_0218e8c4() > data_ov000_021b4dac.mUnk_50 + 0x7d0) {
        if (data_ov000_021b4dac.mUnk_54 == 1) {
            func_ov000_0218e53c(data_ov000_021b4dac.mUnk_00);
            data_ov000_021b4d28 = 1;
            return 1;
        }
        func_ov000_0218d788();
        data_ov000_021b4dac.mUnk_54 = data_ov000_021b4dac.mUnk_54 + 1;
    }
    return 0;
}

s32 func_ov000_0218d528(u32 *a, u32 *b) {
    u32 e;
    u32 f;
    s32 x;
    s32 r;
    e = *a;
    f = *b;
    x = SbServerGetInt((SbServer *) e, (void *) data_ov000_021b4d24->mUnk_498, 0);
    r = x - SbServerGetInt((SbServer *) f, (void *) data_ov000_021b4d24->mUnk_498, 0);
    if (data_ov000_021b4d24->mUnk_49c == 0) {
        r = -r;
    }
    return r;
}

s32 func_ov000_0218d488(u32 *a, u32 *b) {
    u32 e;
    u32 f;
    double x;
    double y;
    double d;
    e = *a;
    f = *b;
    x = SbServerGetDouble((SbServer *) e, (const char *) data_ov000_021b4d24->mUnk_498, 0);
    y = SbServerGetDouble((SbServer *) f, (const char *) data_ov000_021b4d24->mUnk_498, 0);
    d = x - y;
    if (data_ov000_021b4d24->mUnk_49c == 0) {
        d = 0 - d;
    }
    if ((float) d > 0) {
        return 1;
    }
    return -((float) d < 0);
}
