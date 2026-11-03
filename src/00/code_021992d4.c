#include "00/code_021992d4.h"
#include "code_02134d30.h"
#include "00/code_021985ec.h"
#include "00/code_021988e8.h"
#include "00/code_02198a8c.h"
#include "00/code_02199000.h"
#include "00/code_0219960c.h"
#include "00/code_02199614.h"
#include "00/code_02199ad8.h"
#include "00/code_02199fb0.h"
#include "00/code_0219a000.h"
#include "00/code_0218e8c4.h"
#include "00/code_02197e8c.h"
#include "00/code_02198748.h"
#include "00/code_02199fa4.h"
#include "00/code_0219a430.h"
#include "00/unk_021b3000.h"

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

enum { K0, K1 };

u32 func_ov000_02199554(Gt2Connection *a) {
    if (a->mUnk_0c == 7) {
        return 1;
    }
    if (func_ov000_02199fb0((s32) a, 2, a->mUnk_0c == 6 ? K0 : K1) == 0) {
        return 0;
    }
    return 1;
}

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
    if (func_ov000_02198148(a, func_ov000_0218e8c4() - d) != 0) {
        return 1;
    }
    return 0;
}
