#include "00/code_02197b34.h"
#include "00/code_02197e8c.h"
#include "00/code_0219903c.h"
#include "00/code_021981d0.h"

#include "00/code_02197000.h"
#include "00/code_02197ddc.h"
#include "00/code_02199f80.h"
#include "00/code_0218d000.h"
#include "00/code_02199fb0.h"
#include "00/code_0219a430.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "00/code_0218dc44.h"
#include "00/code_0218e3c4.h"
#include "00/unk_021b4000.h"
#include "00/code_0218e368.h"
#include "00/code_0218e49c.h"
#include "00/code_02193818.h"
#include "00/code_021a39d8.h"
#include "00/code_021a4784.h"
#include "00/code_02199000.h"
#include "00/code_0219a000.h"
#include "00/code_021992d4.h"
#include "00/code_0219a044.h"
#include "00/code_0218e8c4.h"

u32 func_ov000_0219922c(int a, u32 b, u32 c) {
    int v1;
    int v2;
    v1 = (s32) func_ov000_0219a5b0((Unk02197e8c *) a, b, c);
    if (*(s32 *) (a + 0x2c) != 0) {
        v2 = func_ov000_02197f28(a, v1, b, c, 1, 0, 0, 0);
        if (v2 == 0) {
            return 0;
        }
    }
    if (v1 == 0) {
        return 1;
    }
    if (*(s32 *) (v1 + 0xc) == 0) {
        if ((*(s32 *) (v1 + 0x20) == 0) ||
            (v2 = func_ov000_0218e8c4(), (v2 - *(s32 *) (v1 + 0x1c)) < *(u32 *) (v1 + 0x20))) {
            return 1;
        }
        v1 = func_ov000_02199fb0(v1, 6, 1);
        if (v1 == 0) {
            return 0;
        }
    } else {
        v1 = func_ov000_02199fb0(v1, 2, 1);
        if (v1 == 0) {
            return 0;
        }
    }
    return 1;
}

typedef struct Unk0219914cHeader {
    /* 0 */ u8 mUnk_00;
    /* 1 */ u8 mUnk_01;
    /* 2 */ u16 mUnk_02;
    /* 4 */ u32 mUnk_04;
} Unk0219914cHeader;

u32 func_ov000_0219914c(Unk02197e8c *a) {
    Unk0219914cHeader h;
    u8 v1[0x5dc];
    s32 n;
    s32 r;
    u32 e;
    while (func_ov000_0218e668(a->mUnk_00) != 0) {
        n = 8;
        r = func_ov000_0218e438(a->mUnk_00, v1, 0x5dc, 0, (u8 *) &h, &n);
        if (r == -1) {
            e = func_ov000_0218e368(a->mUnk_00);
            if (e == -15) {
                if (func_ov000_0219922c((s32) a, h.mUnk_04,
                                        (u16) (((h.mUnk_02 >> 8) & 0xff) | ((h.mUnk_02 << 8) & 0xff00))) == 0) {
                    return 0;
                }
            } else if (e != -35) {
                func_ov000_0219a044(a);
                return 0;
            }
        } else {
            if (func_ov000_021992d4(a, v1, r, h.mUnk_04,
                                    (u16) (((h.mUnk_02 >> 8) & 0xff) | ((h.mUnk_02 << 8) & 0xff00))) == 0) {
                return 0;
            }
        }
    }
    return 1;
}

u32 func_ov000_021990f8(Unk02197fe8 *a, u16 b, s32 c) {
    Unk021990f8Entry d = {0, 0, 0, {0, 0}, 0};
    s32 e;
    d.mUnk_00 = a->mUnk_50.mUnk_08;
    d.mUnk_04 = c;
    d.mUnk_08 = b;
    d.mUnk_0c = func_ov000_0218e8c4();
    e = func_ov000_0218dc44(a->mUnk_60);
    func_ov000_0218dbc0(a->mUnk_60, &d);
    if (e + 1 == func_ov000_0218dc44(a->mUnk_60)) {
        return 1;
    }
    return 0;
}

BOOL func_ov000_0219903c(Unk02197fe8 *a, u32 b, int c, int *d) {
    if (func_ov000_02197e58((s32) &a->mUnk_50) < c) {
        if (func_ov000_02199f80((u32) a) == 0) {
            return FALSE;
        }
        *d = 1;
        return TRUE;
    }
    if (func_ov000_021990f8(a, a->mUnk_64, c) == 0) {
        if (func_ov000_02199f80((u32) a) == 0) {
            return FALSE;
        }
        *d = 1;
        return TRUE;
    }
    func_ov000_02197d84((s32 *) &a->mUnk_50, data_ov000_021b3fa4, 2);
    func_ov000_02197e20((s32 *) &a->mUnk_50, b);
    func_ov000_02197ddc((s32 *) &a->mUnk_50, a->mUnk_64++);
    func_ov000_02197ddc((s32 *) &a->mUnk_50, a->mUnk_66);
    *d = 0;
    return TRUE;
}
