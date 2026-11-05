#include "00/code_0218d818.h"
#include "00/code_02199614.h"
#include "00/code_0219903c.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "code_02134398.h"
#include "00/code_02197e58.h"
#include "00/code_021985ec.h"
#include "00/code_021988e8.h"
#include "00/code_02198a8c.h"
#include "00/code_02199000.h"
#include "00/code_021997f8.h"
#include "00/code_02199a0c.h"
#include "00/code_02199f80.h"
#include "00/code_02199fa4.h"
#include "00/code_0219981c.h"
#include "00/code_0219a014.h"
#include "00/code_0219a028.h"
#include "00/code_02199ad8.h"

u32 func_ov000_021996fc(Gt2Connection *a, u32 b, const u8 *c, s32 d) {
    u32 e;
    s32 g;
    u32 f;
    if (d < 7) {
        if (func_ov000_02199fa4(a) != 0) {
            return 1;
        }
        return 0;
    }
    e = func_ov000_0219a028(c, 3);
    f = func_ov000_0219a028(c, 5);
    if (func_ov000_02199ec8(a, f) == 0) {
        return 0;
    }
    if (e == a->mUnk_66) {
        func_ov000_021997f8(a);
        if (func_ov000_02199a0c(a, b, (u32) (c + 7), d - 7) == 0) {
            return 0;
        }
        if (func_ov000_0219981c(a) != 0) {
            return 1;
        }
        return 0;
    }
    if (func_ov000_0219a014(e, a->mUnk_66) < 0) {
        func_ov000_021997f8(a);
        return 1;
    }
    if (func_ov000_021998d8(a, b, e, c + 7, d - 7, &g) == 0) {
        return 0;
    }
    if (g != 0 && func_ov000_02199f80(a) == 0) {
        return 0;
    }
    return 1;
}

u32 func_ov000_021996b8(Gt2Connection *a, const u8 *b, s32 c) {
    if (c != 2) {
        if (func_ov000_02199fa4(a) != 0) {
            return 1;
        }
        return 0;
    }
    if (func_ov000_02199ec8(a, func_ov000_0219a028(b, 0)) != 0) {
        return 1;
    }
    return 0;
}

u32 func_ov000_02199614(Gt2Connection *a, const u8 *b, s32 c) {
    u32 d;
    u32 e;
    s32 f;
    s32 i;
    Unk021990f8Entry *g;
    d = func_ov000_0219a028(b, 0);
    if (c == 2) {
        e = d;
    } else if (c == 4) {
        e = func_ov000_0219a028(b, 2);
    } else {
        if (func_ov000_02199fa4(a) != 0) {
            return 1;
        }
        return 0;
    }
    f = DarrayGetCount(a->mUnk_60);
    for (i = 0; i < f; i++) {
        g = DarrayGetElement(a->mUnk_60, i);
        if (func_ov000_0219a014(g->mUnk_08, d) >= 0 && func_ov000_0219a014(g->mUnk_08, e) <= 0) {
            if (func_ov000_02198af4(a, (Unk02198af4 *) g) == 0) {
                return 0;
            }
        }
    }
    return 1;
}
