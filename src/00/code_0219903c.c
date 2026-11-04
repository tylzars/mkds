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
#include "00/unk_021b3000.h"
#include "string.h"
#include "code_02134398.h"
#include "00/code_0218d818.h"
#include "00/code_0218e2dc.h"
#include "00/unk_021b4000.h"
#include "00/code_021906e4.h"
#include "00/code_021947e4.h"
#include "00/code_02196914.h"
#include "00/code_021a3690.h"
#include "00/code_02196590.h"
#include "code_02139f70.h"
#include "code_0213a460.h"
#include "00/code_021948f8.h"
#include "00/code_0218e0fc.h"
#include "00/code_02191200.h"
#include "00/code_02196480.h"
#include "00/code_02190ff8.h"
#include "00/code_02192d64.h"
#include "00/code_02196000.h"
#include "00/code_02190000.h"
#include "00/code_0218f960.h"
#include "00/code_02194bb8.h"
#include "00/code_02193b88.h"
#include "00/code_021a3a18.h"
#include "00/code_02199000.h"
#include "00/code_0219a000.h"
#include "00/code_021992d4.h"
#include "00/code_0219a044.h"

u32 func_ov000_0219922c(Gt2Socket *a, u32 b, u32 c) {
    int v1;
    int v2;
    v1 = (s32) FindConnection(a, b, c);
    if (a->mUnk_2c != NULL) {
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

u32 func_ov000_0219914c(Gt2Socket *a) {
    Unk0219914cHeader h;
    u8 v1[0x5dc];
    s32 n;
    s32 r;
    u32 e;
    while (func_ov000_0218e668(a->mDescriptor) != 0) {
        n = 8;
        r = func_ov000_0218e438(a->mDescriptor, v1, 0x5dc, 0, (u8 *) &h, &n);
        if (r == -1) {
            e = func_ov000_0218e368(a->mDescriptor);
            if (e == -15) {
                if (func_ov000_0219922c(a, h.mUnk_04,
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

u32 func_ov000_021990f8(Gt2Connection *a, u16 b, s32 c) {
    Unk021990f8Entry d = {0, 0, 0, {0, 0}, 0};
    s32 e;
    d.mUnk_00 = a->mSendBuffer.mLength;
    d.mUnk_04 = c;
    d.mUnk_08 = b;
    d.mUnk_0c = func_ov000_0218e8c4();
    e = DarrayGetCount(a->mUnk_60);
    DarrayAppend(a->mUnk_60, &d);
    if (e + 1 == DarrayGetCount(a->mUnk_60)) {
        return 1;
    }
    return 0;
}

BOOL func_ov000_0219903c(Gt2Connection *a, u32 b, int c, int *d) {
    if (GetBufferUnusedSize(&a->mSendBuffer) < c) {
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
    AppendBufferBytes(&a->mSendBuffer, data_ov000_021b3fa4, 2);
    AppendBufferByte(&a->mSendBuffer, b);
    AppendBufferU16(&a->mSendBuffer, a->mUnk_64++);
    AppendBufferU16(&a->mSendBuffer, a->mUnk_66);
    *d = 0;
    return TRUE;
}
