#include "00/code_021a88a8.h"

#include "00/code_021acef8.h"
#include "00/code_021adbac.h"
#include "00/code_02186d04.h"
#include "00/code_021ae2f4.h"
#include "00/code_021ae304.h"
#include "00/code_021b0014.h"
#include "00/unk_021b5000.h"
#include "00/code_021a8878.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"
#include "00/code_021a8000.h"
#include "00/code_021a7bfc.h"
#include "00/code_021a740c.h"
#include "00/unk_021b6000.h"
#include "00/code_021a8aa8.h"
#include "00/code_021a78a4.h"
#include "00/types_021a8ab8.h"

BOOL func_ov000_021a8a5c(Unk021a8ab8 *node) {
    if (func_ov000_021a8ab8((Unk021a8ab8 **) &data_ov000_021b6008, node) != NULL) {
        return TRUE;
    }
    return FALSE;
}

u32 func_ov000_021a8a54(int a) {
    return a + 3U & 0xfffffffc;
}

// the original reloads the halfword at 0x70 for every test; a volatile view of the object is the only spelling found
u32 func_ov000_021a8994(Unk021a6fa8 *a) {
    u32 b = 0;
    u32 c;
    BOOL d;
    volatile Unk021a6fa8 *v = a;
    if (func_ov000_021a8a80(a) != 0) {
        b |= 0x80;
    } else {
        if ((v->mUnk_70 & 0x40) != 0) {
            b |= 0x20;
        }
        if (a->mUnk_73 == 1 || (v->mUnk_70 & 4) != 0) {
            c = func_0200fca0();
            if (func_ov000_021a8960(a) > 0) {
                b |= 1;
            }
            if (func_ov000_021a8118(a) > 0) {
                b |= 8;
            }
            func_0200fcb4(c);
        }
        d = TRUE;
        if (a->mUnk_73 != 0 && a->mUnk_73 != 4) {
            d = FALSE;
        }
        if (d != FALSE) {
            if ((v->mUnk_70 & 4) != 0 && a->mState != 4 && (b & 1) == 0) {
                v->mUnk_70 &= ~6;
            }
            if ((v->mUnk_70 & 2) == 0 && (v->mUnk_70 & 4) == 0) {
                b |= 0x40;
            }
        }
    }
    return b;
}

s32 func_ov000_021a8960(Unk021a6fa8 *a) {
    u32 v1;
    Unk021a71c0 *v2;
    s8 v3;
    v2 = a->mReceiveBlock;
    v1 = 0;
    if (v2 != NULL) {
        v3 = a->mUnk_73;
        if (v3 == 1) {
            if (v2->mUnk_104 != NULL) {
                v1 = v2->mUnk_104->mUnk_04;
            }
        } else if ((v3 == 0) || (v3 == 4)) {
            v1 = a->mReceiveBufferLength - v2->mUnk_f8;
        }
    }
    return v1;
}

s32 func_ov000_021a88e4(const char *a) {
    Unk021a88e4 b;
    u8 *c;
    s32 d;
    if (a == NULL) {
        return 0;
    }
    c = data_ov000_021b5f94->mUnk_18(0x1154);
    if (c == NULL) {
        return 0;
    }
    func_0214d168(&b, 0, 0x64);
    b.mReceiveBuffer.mStart = c;
    b.mReceiveBuffer.mSize = 0xb68;
    b.mSendBuffer.mStart = c + 0xb68;
    b.mSendBuffer.mSize = 0x5ea;
    func_ov000_021ae304(&b);
    d = func_ov000_021acef8(a);
    func_ov000_021ae2f4();
    data_ov000_021b5f94->mUnk_1c(c);
    return d;
}

s32 func_ov000_021a88a8(u32 a) {
    u32 b = func_0200fca0();
    u32 c = data_ov000_021b63d8[0];
    u32 d = data_ov000_021b63d8[1];
    s32 e;
    data_ov000_021b63d8[0] = 0;
    data_ov000_021b63d8[1] = 0;
    e = func_ov000_021acef8((const char *) a);
    data_ov000_021b63d8[0] = c;
    data_ov000_021b63d8[1] = d;
    func_0200fcb4(b);
    return e;
}
