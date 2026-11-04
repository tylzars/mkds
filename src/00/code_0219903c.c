#include "00/code_0219903c.h"

#include "00/code_02197b34.h"
#include "00/code_02197e58.h"
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
#include "00/code_02196594.h"
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
#include "00/code_0219a044.h"
#include "00/code_021985ec.h"
#include "00/code_021988e8.h"
#include "00/code_02198a8c.h"
#include "00/code_0219960c.h"
#include "00/code_02199614.h"
#include "00/code_02199ad8.h"
#include "00/code_02198748.h"
#include "00/code_02199fa4.h"

enum { K0, K1 };

u32 func_ov000_0219958c(Gt2Connection *a, u8 *b, s32 c) {
    s32 d;
    u8 *t;
    u8 *p;
    if (a->mCallbacks.mElapsedTimeCallback == NULL) {
        return 1;
    }
    if (c != 8) {
        return 1;
    }
    if (memcmp(b, data_ov000_021b3fa8, 4) != 0) {
        return 1;
    }
    t = (u8 *) &d;
    p = b + 4;
    t[0] = p[0];
    t[1] = p[1];
    t[2] = p[2];
    t[3] = p[3];
    if (Gt2CallElapsedTimeCallback(a, func_ov000_0218e8c4() - d) != 0) {
        return 1;
    }
    return 0;
}

u32 func_ov000_02199554(Gt2Connection *a) {
    if (a->mUnk_0c == 7) {
        return 1;
    }
    if (func_ov000_02199fb0((s32) a, 2, a->mUnk_0c == 6 ? K0 : K1) == 0) {
        return 0;
    }
    return 1;
}

u32 func_ov000_021994c4(Gt2Connection *a, u32 b, u8 *c, s32 d) {
    u8 *e = c + 3;
    s32 f = d - 3;
    if (b == 0x64) {
        if (func_ov000_021996b8(a, e, f) == 0) {
            return 0;
        }
    } else if (b == 0x65) {
        if (func_ov000_02199614(a, e, f) == 0) {
            return 0;
        }
    } else if (b == 0x66) {
        if (func_ov000_0219960c((u32) a, (u32) c, (u32) d) == 0) {
            return 0;
        }
    } else if (b == 0x67) {
        if (func_ov000_0219958c(a, e, f) == 0) {
            return 0;
        }
    } else if (b == 0x68) {
        if (func_ov000_02199554(a) == 0) {
            return 0;
        }
    }
    return 1;
}

u32 func_ov000_021992d4(Gt2Socket *a, u8 *b, s32 c, u32 d, u32 e) {
    Gt2Connection *f;
    Gt2Connection *k;
    s32 g;
    BOOL h;
    s32 i;
    f = FindConnection(a, d, e);
    if (a->mUnk_2c != NULL) {
        if (func_ov000_02197f28(a, (s32) f, d, e, 0, (s32) b, c, 0) == 0) {
            return 0;
        }
    }
    if (c > 2 && memcmp(b, data_ov000_021b3fa4, 2) == 0) {
        h = TRUE;
    } else {
        h = FALSE;
    }
    if (f == NULL) {
        if (CallUnmatchedDataCallback(a, d, e, b, c, &g) == 0) {
            return 0;
        }
        if (g != 0) {
            return 1;
        }
        if (h == FALSE || b[2] != 1) {
            if (h == FALSE || b[2] != 0x68) {
                if (func_ov000_02198b50(a, d, e) == 0) {
                    return 0;
                }
            }
            return 1;
        } else {
            if (a->mIncomingConnectionCallback == NULL) {
                return 1;
            }
            i = func_ov000_0219883c(a, &f, d, e);
            if (i != 0) {
                if (i != 5 && func_ov000_02198b50(a, d, e) == 0) {
                    return 0;
                }
                return 1;
            }
        }
    }
    k = f;
    if (k->mUnk_0c == 7) {
        if (h == FALSE || b[2] != 0x68) {
            if (func_ov000_02198b8c(k) == 0) {
                return 0;
            }
        }
        return 1;
    }
    if (h != FALSE && c >= 4 && memcmp(b + 2, data_ov000_021b3fa4, 2) == 0) {
        b += 2;
        c -= 2;
        h = FALSE;
    }
    if (h == FALSE) {
        if (func_ov000_02199e50(k, b, c) != 0) {
            return 1;
        }
        return 0;
    }
    i = b[2];
    if (i < 0) {
        if (func_ov000_02199fa4((u32) k) != 0) {
            return 1;
        }
        return 0;
    }
    if (i < 8) {
        if (func_ov000_021996fc(k, i, b, c) != 0) {
            return 1;
        }
        return 0;
    }
    if (func_ov000_021994c4(k, i, b, c) != 0) {
        return 1;
    }
    return 0;
}

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
