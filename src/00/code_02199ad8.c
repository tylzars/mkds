#include "00/code_02199ad8.h"
#include "00/code_0218d818.h"
#include "00/code_0219903c.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "string.h"
#include "code_02134398.h"
#include "00/code_021a3678.h"
#include "00/code_021a3690.h"
#include "00/code_02197b08.h"
#include "00/code_02197b34.h"
#include "00/code_02197ddc.h"
#include "00/code_02197e58.h"
#include "00/code_021985ec.h"
#include "00/code_021988e8.h"
#include "00/code_02198a8c.h"
#include "00/code_02198d04.h"
#include "00/code_02199fa4.h"
#include "00/code_02199fb0.h"
#include "00/code_0219a014.h"
#include "00/code_021a3668.h"
#include "code_021382a8.h"
#include "00/code_0218e2dc.h"

enum { K0, K1 };

u32 func_ov000_02199ec8(Gt2Connection *a, u32 b) {
    s32 c;
    s32 d;
    s32 e;
    Unk021990f8Entry *f;
    c = DarrayGetCount(a->mUnk_60);
    if (c == 0) {
        return 1;
    }
    for (d = 0; d < c; d++) {
        f = DarrayGetElement(a->mUnk_60, d);
        if (func_ov000_0219a014(f->mUnk_08, b) >= 0) {
            break;
        }
    }
    if (d == 0) {
        return 1;
    }
    while (d-- != 0) {
        DarrayRemove(a->mUnk_60, d);
    }
    c = DarrayGetCount(a->mUnk_60);
    if (c == 0) {
        a->mSendBuffer.mLength = 0;
        return 1;
    }
    f = DarrayGetElement(a->mUnk_60, 0);
    e = f->mUnk_00;
    for (d = 0; d < c; d++) {
        f = DarrayGetElement(a->mUnk_60, d);
        f->mUnk_00 -= e;
    }
    RemoveBufferBytes(&a->mSendBuffer, 0, e);
    return 1;
}

u32 func_ov000_02199e50(Gt2Connection *a, const u8 *b, s32 c) {
    if (a->mUnk_0c != 5 && a->mUnk_0c != 6) {
        return 1;
    }
    if (DarrayGetCount(a->mUnk_9c) != 0) {
        if (func_ov000_02197fe8(a, 0, b, c, 0) != FALSE) {
            return 1;
        }
        return 0;
    }
    if (Gt2CallDataCallback(a, b, c, 0) != FALSE) {
        return 1;
    }
    return 0;
}

u32 func_ov000_02199dd0(Gt2Connection *a, const u8 *c, u32 d) {
    if (a->mUnk_0c != 5 && a->mUnk_0c != 6) {
        if (func_ov000_02199fa4(a) == 0) {
            return 0;
        }
    } else {
        if (DarrayGetCount(a->mUnk_9c) != 0) {
            if (func_ov000_02197fe8(a, 0, c, d, 1) != FALSE) {
                return 1;
            }
            return 0;
        }
        if (Gt2CallDataCallback(a, c, d, 1) == FALSE) {
            return 0;
        }
    }
    return 1;
}

u32 func_ov000_02199d4c(Gt2Connection *a, const u8 *e, int f) {
    s8 b[0x20];
    s8 c[0x20];
    if (a->mUnk_0c != 2) {
        if (func_ov000_02199fa4(a) != 0) {
            return 1;
        }
        return 0;
    }
    if (f < 0x20) {
        if (func_ov000_02199fa4(a) != 0) {
            return 1;
        }
        return 0;
    }
    func_ov000_02197b34(b, (const s8 *) e);
    func_ov000_02197be0(c);
    func_ov000_02197b34((s8 *) a->mUnk_68, c);
    if (func_ov000_02198eb0(a, (const u8 *) b, (const u8 *) c) == 0) {
        return 0;
    }
    a->mUnk_0c = 3;
    return 1;
}

u32 func_ov000_02199c98(Gt2Connection *a, const u8 *d, int e) {
    s8 b[0x20];
    if (a->mUnk_0c != 0) {
        if (func_ov000_02199fa4(a) != 0) {
            return 1;
        }
        return 0;
    }
    if (e < 0x40) {
        if (func_ov000_02199fa4(a) != 0) {
            return 1;
        }
        return 0;
    }
    if (func_ov000_02197b08(d, a->mUnk_68) == FALSE) {
        if (func_ov000_02199fa4(a) != 0) {
            return 1;
        }
        return 0;
    }
    func_ov000_02197b34(b, (const s8 *) (d + 0x20));
    if (func_ov000_02198e44(a, (const u8 *) b, a->mUnk_38.mData, a->mUnk_38.mSize) == 0) {
        return 0;
    }
    if (a->mUnk_38.mData != NULL) {
        func_ov000_021a3668(a->mUnk_38.mData);
        a->mUnk_38.mData = NULL;
    }
    a->mUnk_0c = 1;
    return 1;
}

u32 func_ov000_02199bb4(Gt2Connection *a, const u8 *c, int d) {
    if (a->mUnk_0c != 3) {
        if (func_ov000_02199fa4(a) != 0) {
            return 1;
        }
        return 0;
    }
    if (d < 0x20) {
        if (func_ov000_02199fa4(a) != 0) {
            return 1;
        }
        return 0;
    }
    if (func_ov000_02197b08(c, a->mUnk_68) == FALSE) {
        if (func_ov000_02199fa4(a) != 0) {
            return 1;
        }
        return 0;
    }
    if (a->mSocket->mIncomingConnectionCallback == NULL) {
        if (func_ov000_02198b8c(a) == 0) {
            return 0;
        }
        func_ov000_02198514(a);
        return 1;
    }
    a->mUnk_0c = 4;
    if (CallIncomingConnectionCallback(a->mSocket, a, a->mAddress, a->mPort, func_ov000_0218e8c4() - a->mUnk_8c,
                                       c + 0x20, d - 0x20) != FALSE) {
        return 1;
    }
    return 0;
}

u32 func_ov000_02199b70(Gt2Connection *a) {
    if (a->mUnk_0c != 1) {
        if (func_ov000_02199fa4(a) != 0) {
            return 1;
        }
        return 0;
    }
    a->mUnk_0c = 5;
    if (Gt2SetResultAndCallResultCallback(a, 0, NULL, 0) != 0) {
        return 1;
    }
    return 0;
}

u32 func_ov000_02199b14(Gt2Connection *a, void *c, u32 d) {
    if (a->mUnk_0c != 1) {
        if (func_ov000_02199fa4(a) != 0) {
            return 1;
        }
        return 0;
    }
    func_ov000_02198514(a);
    if (func_ov000_02198b8c(a) == 0) {
        return 0;
    }
    if (Gt2SetResultAndCallResultCallback(a, 2, c, d) != FALSE) {
        return 1;
    }
    return 0;
}

u32 func_ov000_02199ad8(Gt2Connection *a) {
    if (func_ov000_02198b8c(a) == 0) {
        return 0;
    }
    if (func_ov000_02199fb0(a, 2, a->mUnk_0c == 6 ? K0 : K1) == 0) {
        return 0;
    }
    return 1;
}
