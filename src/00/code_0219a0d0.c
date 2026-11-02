#include "00/code_0219a0d0.h"
#include "code_02134d30.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "00/code_021a3678.h"
#include "00/code_021a3690.h"
#include "00/code_0218dc44.h"
#include "00/code_0218dd8c.h"
#include "00/code_0218e3c4.h"
#include "00/unk_021b4000.h"
#include "00/code_0218e368.h"
#include "00/code_0218e49c.h"
#include "00/code_02197000.h"
#include "00/code_02199000.h"
#include "00/code_0219a000.h"
#include "00/code_0219903c.h"
#include "00/code_02197ddc.h"
#include "00/code_02198584.h"
#include "00/code_0219a044.h"
#include "00/code_0219a3e8.h"
#include "00/code_0219a430.h"
#include "00/code_021a3668.h"
#include "code_021382a8.h"
#include "00/code_0218d818.h"
#include "00/code_0218e8c4.h"

typedef struct Unk0219a110Addr {
    /* 0 */ u8 mUnk_00;
    /* 1 */ u8 mUnk_01;
    /* 2 */ u16 mUnk_02;
    /* 4 */ u32 mUnk_04;
} Unk0219a110Addr;

u32 func_ov000_0219a28c(Unk02197e8c *a, Unk02197fe8 **b, u32 c, u32 d) {
    Unk02197fe8 *e = 0;
    if (func_ov000_0219a5b0(a, c, d) != 0) {
        return 5;
    }
    e = func_ov000_0219a3e8();
    if (e != 0) {
        memset(e, 0, 0xa0);
        e->mUnk_00 = c;
        e->mUnk_04 = d;
        e->mUnk_08 = a;
        e->mUnk_1c = func_ov000_0218e8c4();
        e->mUnk_88 = e->mUnk_1c;
        e->mUnk_64 = 0;
        e->mUnk_66 = 0;
        if (func_ov000_02197e60((int *) &e->mUnk_44, (int) a->mUnk_3c) != 0 &&
            func_ov000_02197e60((int *) &e->mUnk_50, (int) a->mUnk_38) != 0) {
            e->mUnk_5c = (void *) func_ov000_0218dc94(0x10, 0x40, 0);
            if (e->mUnk_5c != 0) {
                e->mUnk_60 = (void *) func_ov000_0218dc94(0x10, 0x40, 0);
                if (e->mUnk_60 != 0) {
                    e->mUnk_98 = (void *) func_ov000_0218dc94(4, 2, 0);
                    if (e->mUnk_98 != 0) {
                        e->mUnk_9c = (void *) func_ov000_0218dc94(4, 2, 0);
                        if (e->mUnk_9c != 0) {
                            func_ov000_0218def0(a->mUnk_0c, &e);
                            *b = func_ov000_0219a5b0(a, c, d);
                            if (*b != 0) {
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    if (e != 0) {
        func_ov000_021a3668(e->mUnk_44.mUnk_00);
        func_ov000_021a3668(e->mUnk_50.mUnk_00);
        if (e->mUnk_5c != 0) {
            func_ov000_0218dc48(e->mUnk_5c);
        }
        if (e->mUnk_60 != 0) {
            func_ov000_0218dc48(e->mUnk_60);
        }
        if (e->mUnk_98 != 0) {
            func_ov000_0218dc48(e->mUnk_98);
        }
        if (e->mUnk_9c != 0) {
            func_ov000_0218dc48(e->mUnk_9c);
        }
        func_ov000_021a3668(e);
    }
    return 1;
}

void func_ov000_0219a220(Unk02197fe8 *a) {
    s32 b;
    s32 c;
    if (a->mUnk_14 == 0 && a->mUnk_24 == 0) {
        if (a->mUnk_0c == 7) {
            b = func_ov000_0218dc44(a->mUnk_08->mUnk_10);
            for (c = 0; c < b; c++) {
                if (a == *(Unk02197fe8 **) func_ov000_0218dbf8(a->mUnk_08->mUnk_10, c)) {
                    func_ov000_0218da5c(a->mUnk_08->mUnk_10, c);
                    return;
                }
            }
        } else {
            func_ov000_0218de8c(a->mUnk_08->mUnk_0c, &a);
        }
    }
}

u32 func_ov000_0219a110(u32 *param_1, u32 param_2, int param_3, u32 param_4, u32 param_5) {
    Unk02197e8c *a = (Unk02197e8c *) param_1;
    s32 e;
    func_ov000_0219a61c((const u8 **) &param_4, (s32 *) &param_5);
    if (func_ov000_0218e644(a->mUnk_00) == 0) {
        return 1;
    }
    {
        Unk0219a110Addr b = {0, 0, 0, 0};
        Unk0219a110Addr *p = &b;
        p->mUnk_01 = 2;
        p->mUnk_04 = param_2;
        p->mUnk_02 = ((param_3 >> 8) & 0xff) | ((param_3 << 8) & 0xff00);
        if (func_ov000_0218e3e4(a->mUnk_00, (void *) param_4, param_5, 0, &b, 8) == -1) {
            e = func_ov000_0218e368(a->mUnk_00);
            if (e == -15) {
                if (func_ov000_0219922c((int) a, param_2, param_3) == 0) {
                    return 0;
                }
            } else if (e == -42 || e == -6) {
                return 1;
            } else if (e != -35) {
                func_ov000_0219a044(a);
                return 0;
            }
        } else if (a->mUnk_28 != 0) {
            if (func_ov000_02197f28((int) a, (int) func_ov000_0219a5b0(a, param_2, param_3), param_2, param_3, 0,
                                    param_4, param_5, 1) == 0) {
                return 0;
            }
        }
    }
    return 1;
}

u32 func_ov000_0219a0d0(Unk02197fe8 **a, u32 *b) {
    Unk02197fe8 *c = *a;
    u32 d = *b;
    if (c->mUnk_0c != 7 && func_ov000_02198584((u32) c, d) == 0) {
        return 0;
    }
    if (c->mUnk_0c == 7 && c->mUnk_14 == 0 && c->mUnk_24 == 0) {
        func_ov000_0219a220(c);
    }
    return 1;
}
