#include "00/code_0218e49c.h"
#include "03/code_021b94b8.h"

#include "00/code_021a740c.h"
#include "00/unk_021b6000.h"
#include "00/code_021a88a8.h"
#include "00/code_021a4654.h"
#include "00/code_021a8aa8.h"
#include "00/code_0218e3c4.h"
#include "00/unk_021b5000.h"
#include "00/code_021a6fa8.h"
#include "00/code_021a86bc.h"
#include "00/unk_021b2000.h"
#include "00/code_0218e368.h"
#include "00/code_021a3690.h"
#include "00/code_021a8dd8.h"
#include "code_02139f70.h"
#include "code_0214177c.h"

void func_ov000_0218e8bc(u32 arg0) {
    u32 value0 = arg0;
    u32 value3;
    value3 = (u32) &func_0200dc3c;
    func_0200dc3c(value0);
    return;
}

void func_ov000_0218e8b8(void) {
    return;
}

void func_ov000_0218e8b4(void) {
    return;
}

void *func_ov000_0218e880(const char *a) {
    void *b;
    if (a == NULL) {
        return NULL;
    }
    b = func_ov000_021a3690(strlen(a) + 1);
    if (b != NULL) {
        strcpy(b, a);
    }
    return b;
}

s8 *func_ov000_0218e850(s8 *a) {
    s32 c;
    s8 *b;
    b = a;
    c = *a;
    if (c != 0) {
        do {
            if (c >= 0 && c < 0x80) {
                c = data_0215d184[c];
            }
            *a = c;
            a++;
            c = *a;
        } while (c != 0);
    }
    return b;
}

BOOL func_ov000_0218e80c(s32 a, s32 b) {
    s32 c;
    c = func_ov000_021a8dd8((Unk021a6fa8 *) a, 3, 0);
    if (b != 0) {
        c = c & ~4;
    } else {
        c = c | 4;
    }
    return func_ov000_021a8dd8((Unk021a6fa8 *) a, 4, c) == 0;
}

s32 func_ov000_0218e7dc(s32 a, u32 b) {
    return func_ov000_0218e3b8(a, 0xffff, 0x1002, &b, 4) != -1 ? 1 : 0;
}

s32 func_ov000_0218e7ac(s32 a, u32 b) {
    return func_ov000_0218e3b8(a, 0xffff, 0x1001, &b, 4) != -1 ? 1 : 0;
}

s32 func_ov000_0218e77c(s32 d) {
    s32 a;
    s32 b = 4;
    s32 c = func_ov000_0218e3c4(d, 0xffff, 0x1002, &a, &b);
    return c != -1 ? a : -1;
}

s32 func_ov000_0218e74c(s32 d) {
    s32 a;
    s32 b = 4;
    s32 c = func_ov000_0218e3c4(d, 0xffff, 0x1001, &a, &b);
    return c != -1 ? a : -1;
}

s32 func_ov000_0218e68c(s32 c, u32 *d, u32 *e, u32 *f) {
    Unk0218e68c a;
    s32 b;
    a.mUnk_00 = c;
    a.mUnk_04 = 0;
    if (d != NULL) {
        a.mUnk_04 |= 1;
    }
    if (e != NULL) {
        a.mUnk_04 |= 8;
    }
    a.mUnk_06 = 0;
    b = func_ov000_021a8b20(&a, 1, 0);
    if (b < 0) {
        return -1;
    }
    if (d != NULL) {
        if (b > 0 && (a.mUnk_06 & 0x41) != 0) {
            *d = 1;
        } else {
            *d = 0;
        }
    }
    if (e != NULL) {
        if (b > 0 && (a.mUnk_06 & 8) != 0) {
            *e = 1;
        } else {
            *e = 0;
        }
    }
    if (f != NULL) {
        if (b > 0 && (a.mUnk_06 & 0x20) != 0) {
            *f = 1;
        } else {
            *f = 0;
        }
    }
    return b;
}

u32 func_ov000_0218e668(u32 a) {
    int v1;
    u32 v2[1];
    v2[0] = 0;
    v1 = func_ov000_0218e68c((u32) (a), (u32 *) (v2), (u32 *) (0), (u32 *) (0));
    if (v1 == 1) {
        return v2[0];
    }
    return 0;
}

u32 func_ov000_0218e644(u32 a) {
    int v1;
    u32 v2[1];
    v2[0] = 0;
    v1 = func_ov000_0218e68c((u32) (a), (u32 *) (0), (u32 *) (v2), (u32 *) (0));
    if (v1 == 1) {
        return v2[0];
    }
    return 0;
}

Unk021a8f84 *func_ov000_0218e5e4(void) {
    data_ov000_021b4e0c.mUnk_00 = data_ov000_021b23dc;
    data_ov000_021b4e0c.mUnk_04 = data_ov000_021b4e04;
    data_ov000_021b4e0c.mUnk_08 = 2;
    data_ov000_021b4e0c.mUnk_0a = 0;
    data_ov000_021b4e0c.mUnk_0c = data_ov000_021b4e30;
    data_ov000_021b4e1c = 0;
    func_ov000_021a8bb0(func_ov000_021a8830(), (u8 *) &data_ov000_021b4e1c);
    if (data_ov000_021b4e1c == 0) {
        return NULL;
    }
    data_ov000_021b4e30[0] = &data_ov000_021b4e1c;
    data_ov000_021b4e0c.mUnk_0a = 4;
    data_ov000_021b4e30[1] = NULL;
    return &data_ov000_021b4e0c;
}

BOOL func_ov000_0218e57c(u32 *e) {
    u32 a = *e;
    u32 b = ((a << 24) & 0xff000000) | (((a << 8) & 0xff0000) | (((a >> 24) & 0xff) | ((a >> 8) & 0xff00)));
    s32 c = (b >> 24) & 0xff;
    s32 d = (b >> 16) & 0xff;
    if (c == 10) {
        return TRUE;
    }
    if (c == 172 && d >= 16 && d <= 31) {
        return TRUE;
    }
    if (c == 192 && d == 168) {
        return TRUE;
    }
    return FALSE;
}

s32 func_ov000_0218e56c(s32 result, s32 fallback) {
    if (result < 0) {
        data_ov000_021b4e08 = result;
        result = fallback;
    }
    return result;
}

s32 func_ov000_0218e554(s32 domain, s32 type, s32 protocol) {
    return func_ov000_0218e56c(func_ov000_021a918c(domain, type, protocol), -1);
}

s32 func_ov000_0218e53c(s32 descriptor) {
    return func_ov000_0218e56c(func_ov000_021a9008(descriptor), -1);
}

s32 func_ov000_0218e524(s32 descriptor, s32 a) {
    return func_ov000_0218e56c(func_ov000_021a9010(descriptor), -1);
}

s32 func_ov000_0218e4e4(s32 c, void *d, s32 e) {
    Unk0218e3c4 *a = d;
    Unk0218e3c4 b;
    if (*(u16 *) a->mUnk_02 == 0) {
        return 0;
    }
    b = *a;
    b.mUnk_00 = e;
    return func_ov000_0218e56c(func_ov000_021a916c(c, &b), -1);
}

s32 func_ov000_0218e4b4(s32 b, void *c, s32 d) {
    Unk0218e3c4 a = *(Unk0218e3c4 *) c;
    a.mUnk_00 = d;
    return func_ov000_0218e56c(func_ov000_021a911c((Unk021a6fa8 *) b, (Unk021a8e18 *) &a), -1);
}

s32 func_ov000_0218e49c(s32 descriptor) {
    return func_ov000_0218e56c(func_ov000_021a8e70(descriptor), -1);
}
