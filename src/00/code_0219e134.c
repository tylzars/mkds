#include "00/code_0218b280.h"
#include "00/code_0219e134.h"
#include "00/code_0219e4e8.h"

#include "00/code_0219fb48.h"
#include "00/code_021a0958.h"
#include "00/unk_021b4000.h"
#include "00/unk_021b5000.h"
#include "00/code_0218b000.h"
#include "00/code_0218b220.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "00/code_0218d818.h"
#include "00/code_0218cd74.h"
#include "00/code_0218b434.h"
#include "00/code_0219dee0.h"
#include "00/code_0219f000.h"
#include "00/code_021a0000.h"
#include "00/code_0219f4c4.h"
#include "00/code_021a01dc.h"
#include "00/code_021a3264.h"
#include "code_0200f5ac.h"

s32 func_ov000_0219e4a0(s32 a) {
    s32 b;
    s32 c;
    if (a == 0) {
        return 0;
    }
    switch (a) {
        case 1:
            b = 11;
            c = -1;
            break;
        case 2:
            b = 6;
            c = -50;
            break;
        case 3:
            b = 6;
            c = -30;
            break;
    }
    func_ov000_021a1a38(b, c - 0x14ff0);
    return a;
}

s32 func_ov000_0219e45c(s32 a) {
    enum { K6 = 6 } b;
    s32 c;
    if (a == 0) {
        return 0;
    }
    switch (a) {
        case 1:
            return 1;
        case 2:
            return 2;
        default:
            b = K6;
            c = -9;
            break;
    }
    if (b != 0) {
        func_ov000_021a1a38(b, c - 0x14ff0);
    }
    return a;
}

u32 func_ov000_0219e3e4(u32 a) {
    s32 b;
    s32 c;
    if (a == 0) {
        return 0;
    }
    switch (a) {
        case 1:
            b = 11;
            c = -1;
            break;
        case 2:
        case 5:
            b = 0;
            c = 0;
            a = 0;
            break;
        case 3:
            b = 6;
            c = -10;
            break;
        case 4:
            b = 6;
            c = -30;
            break;
        case 6:
            b = 6;
            c = -70;
            break;
        case 7:
            b = 6;
            c = -80;
            break;
    }
    if (b != 0) {
        func_ov000_021a1a38(b, c - 0x153d8);
    }
    return a;
}

void func_ov000_0219e138(u32 a, s32 b, s32 c) {
    s32 d;
    u32 e;
    Unk021b566c *f;
    switch (b) {
        case 0:
            func_ov000_0219e134(c);
            return;
        case 4:
            d = 0;
            if ((s32) func_ov000_0218b474(a) > 0) {
                do {
                    e = func_ov000_0218b480(a, d);
                    if (func_ov000_0219e994(e) == 0) {
                        func_ov000_0218b4d4((struct Unk0218b668 *) a, e);
                        d--;
                    }
                    d++;
                } while (d < (s32) func_ov000_0218b474(a));
            }
            switch (data_ov000_021b566c->mUnk_198) {
                case 2:
                    d = 0;
                    if ((s32) func_ov000_0218b474(a) > 0) {
                        do {
                            e = func_ov000_0218b480(a, d);
                            f = data_ov000_021b566c;
                            if (f->mUnk_1c != NULL && f->mUnk_1c == (void *) func_ov000_0218b27c((u32 *) e) &&
                                f->mUnk_1a != 0 && data_ov000_021b566c->mUnk_1a == func_ov000_0218b260(e)) {
                                break;
                            }
                            d++;
                        } while (d < (s32) func_ov000_0218b474(a));
                    }
                    if (d < (s32) func_ov000_0218b474(a)) {
                        data_ov000_021b566c->mUnk_198 = 3;
                        data_ov000_021b566c->mUnk_1ec = 0;
                        if (func_ov000_0219e594(func_ov000_021a0f20(data_ov000_021b566c->mUnk_1ec)) != 0) {
                            return;
                        }
                        return;
                    }
                    data_ov000_021b566c->mUnk_e8 = 2;
                    data_ov000_021b566c->mUnk_ec = func_0200f5ac();
                    return;
                case 3:
                    func_ov000_0219dfe4(1);
                    if (func_ov000_0218b474(a) != 0) {
                        if (func_ov000_0219fee4(func_ov000_0219fdc8(0, 0)) != 0) {
                            return;
                        }
                        data_ov000_021b566c->mUnk_198 = 4;
                        data_ov000_021b566c->mUnk_e8 = 0;
                        return;
                    }
                    data_ov000_021b566c->mUnk_e8 = 2;
                    data_ov000_021b566c->mUnk_ec = func_0200f5ac();
                    return;
                case 5:
                    if (func_ov000_0218b474(a) != 0) {
                        do {
                            e = func_ov000_0218b480(a, 0);
                            if (data_ov000_021b566c->mUnk_1ac == func_ov000_0218b27c((u32 *) e) &&
                                data_ov000_021b566c->mUnk_1aa == func_ov000_0218b260(e)) {
                                break;
                            }
                            func_ov000_0218b4d4((struct Unk0218b668 *) a, e);
                        } while (func_ov000_0218b474(a) != 0);
                    }
                    if (func_ov000_0218b474(a) != 0) {
                        e = SbServerGetInt((SbServer *) func_ov000_0218b480(a, 0), data_ov000_021b40c4, 0);
                        f = data_ov000_021b566c;
                        if (f->mUnk_15 == 1 && e == f->mUnk_f4[0]) {
                            if (func_ov000_0219dfe4(0) != 0) {
                                if (data_ov000_021b566c->mUnk_0d != 0) {
                                    if (func_ov000_0219fee4(func_ov000_0219f8b0()) != 0) {
                                        return;
                                    }
                                }
                            } else {
                                if (func_ov000_0219fee4(func_ov000_0219fb14(data_ov000_021b566c->mUnk_f4[0])) != 0) {
                                    return;
                                }
                                data_ov000_021b566c->mUnk_198 = 4;
                                if (func_ov000_0219fee4(func_ov000_0219fbec(0, 0)) != 0) {
                                    return;
                                }
                                return;
                            }
                        }
                        data_ov000_021b566c->mUnk_198 = 6;
                        if (func_ov000_0219e4a0(func_ov000_021a0cac(0, 0, func_ov000_0218b480(a, 0))) != 0) {
                            return;
                        }
                        return;
                    }
                    data_ov000_021b566c->mUnk_e8 = 2;
                    data_ov000_021b566c->mUnk_ec = func_0200f5ac();
                    return;
            }
            return;
        case 5:
            break;
    }
}

void func_ov000_0219e134(s32 a) {
    return;
}
