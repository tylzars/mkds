#include "00/code_0219f544.h"
#include "00/code_0218b64c.h"
#include "00/code_0218b000.h"
#include "00/code_0219d000.h"
#include "00/code_0219e000.h"
#include "00/code_0219f000.h"
#include "00/code_021a0000.h"
#include "00/code_021a1000.h"
#include "00/code_021a1488.h"
#include "00/code_021a4818.h"
#include "00/unk_021b5000.h"
#include "code_0200f5ac.h"

void func_ov000_0219f544(s32 a) {
    Unk021b566c *p;
    u32 v[4]; // the original also writes v[4], one word past the end
    s32 w;
    s32 f;
    s32 n;
    s32 c;
    w = 3;
    f = 0;
    switch (a) {
        case 0:
            p = data_ov000_021b566c;
            if (p->mUnk_19c < p->mUnk_0d - 1) {
                p->mUnk_198 = 13;
                p = data_ov000_021b566c;
                v[0] = p->mUnk_f4[p->mUnk_19c + 1];
                v[1] = p->mUnk_19c + 1;
                v[2] = p->mUnk_2b8[p->mUnk_19c + 1];
                v[3] = p->mUnk_24[p->mUnk_19c + 1];
                v[4] = p->mUnk_a4[p->mUnk_19c + 1];
                w = 5;
            } else {
                p->mUnk_17 = 0;
                data_ov000_021b566c->mUnk_20 = 0;
                func_ov000_021a4818(data_ov000_021b566c->mUnk_10);
                p = data_ov000_021b566c;
                if (p->mUnk_15 == 0) {
                    p->mUnk_198 = 3;
                } else if (p->mUnk_15 == 1) {
                    p->mUnk_198 = 4;
                } else {
                    p->mUnk_198 = 10;
                }
                data_ov000_021b566c->mUnk_19c = 0;
                p = data_ov000_021b566c;
                if (p->mUnk_15 == 2 || p->mUnk_0d == p->mUnk_16) {
                    if (p->mUnk_15 == 2) {
                        p = data_ov000_021b566c;
                        p->mUnk_1f4 = p->mUnk_f4[p->mUnk_0d];
                    } else {
                        p->mUnk_1f4 = 0;
                        p = data_ov000_021b566c;
                        p->mUnk_f4[0] = p->mUnk_1e8;
                    }
                    data_ov000_021b566c->mUnk_198 = 16;
                    data_ov000_021b566c->mUnk_1c8 = 0;
                    for (n = 1; n <= data_ov000_021b566c->mUnk_0d; n++) {
                        func_ov000_0219ef68(data_ov000_021b566c->mUnk_2b8[n], 2);
                    }
                } else {
                    v[0] = 0;
                    v[1] = p->mUnk_0d;
                    v[2] = p->mUnk_2b8[p->mUnk_0d];
                    if (p->mUnk_15 == 0) {
                        p->mUnk_e8 = 2;
                        data_ov000_021b566c->mUnk_ec = func_0200f5ac();
                    } else if (p->mUnk_15 == 1) {
                        func_ov000_0219fbec(1, 0);
                    }
                }
                if (data_ov000_021b566c->mUnk_15 != 2) {
                    f = 1;
                }
            }
            if (data_ov000_021b566c->mUnk_198 == 16) {
                break;
            }
            p = data_ov000_021b566c;
            n = p->mUnk_0d;
            if (func_ov000_0219fee4(func_ov000_021a0ae8(8, p->mUnk_f4[n], p->mUnk_24[n], p->mUnk_a4[n], v, w)) != 0) {
                return;
            }
            data_ov000_021b566c->mUnk_3b5 = 0;
            break;
        case 1:
            data_ov000_021b566c->mUnk_198 = 1;
            p = data_ov000_021b566c;
            if (p->mUnk_15 == 3) {
                p->mUnk_1f4 = p->mUnk_f4[p->mUnk_0d];
            }
            f = 1;
            break;
        case 2:
            data_ov000_021b566c->mUnk_198 = 1;
            p = data_ov000_021b566c;
            if (p->mUnk_15 == 0 || p->mUnk_15 == 1) {
                p->mUnk_17 = 1;
                data_ov000_021b566c->mUnk_20 = data_ov000_021b566c->mUnk_1e8;
            }
            p = data_ov000_021b566c;
            if (p->mUnk_0d > 1) {
                if (func_ov000_0219fee4(func_ov000_021a0ae8(9, p->mUnk_f4[0], p->mUnk_24[0], p->mUnk_a4[0],
                                                            &p->mUnk_f4[p->mUnk_0d - 1], 1)) != 0) {
                    return;
                }
            }
            break;
        case 3:
            data_ov000_021b566c->mUnk_198 = 1;
            data_ov000_021b566c->mUnk_1f4 = f;
            f = 1;
            break;
        case 4:
            if (data_ov000_021b566c->mUnk_15 != 2) {
                func_ov000_0219d558(2, data_ov000_021b4114, (void *) f);
            }
            p = data_ov000_021b566c;
            if (p->mUnk_1f4 == 0) {
                c = 1;
            } else {
                c = 0;
            }
            data_ov000_021b566c->mUnk_44c(0, 0, c, 0, func_ov000_0219d5e4(data_ov000_021b566c->mUnk_1f4), p->mUnk_450);
            p = data_ov000_021b566c;
            if (p->mUnk_15 == 0 || p->mUnk_15 == 1) {
                func_ov000_021a104c();
            } else {
                if (p->mUnk_e4 != 0) {
                    func_ov000_0218b64c(p->mUnk_e4);
                    data_ov000_021b566c->mUnk_e4 = 0;
                }
                func_ov000_0219b110();
                p = data_ov000_021b566c;
                if (p->mUnk_15 == 2) {
                    if (func_ov000_0219e608(func_ov000_021a1488()) != 0) {
                        return;
                    }
                    if (data_ov000_021b5668.mUnk_00 == 1) {
                        data_ov000_021b5668.mUnk_01 = 1;
                    }
                    data_ov000_021b566c->mUnk_198 = 10;
                } else {
                    p->mUnk_198 = 1;
                }
                data_ov000_021b566c->mUnk_1f4 = 0;
            }
            data_ov000_021b566c->mUnk_1a1 = 0;
            break;
    }
    if (f != 0) {
        p = data_ov000_021b566c;
        if (p->mUnk_15 != 3) {
            func_ov000_0218b48c(p->mUnk_e4);
        }
    }
}
