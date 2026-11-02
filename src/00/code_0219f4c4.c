#include "00/code_0219f4c4.h"
#include "00/code_0218eb9c.h"
#include "00/unk_021b5000.h"
#include "00/code_0218cdc4.h"
#include "00/code_0219de4c.h"

#include "00/code_0218a000.h"
#include "00/code_0218b000.h"
#include "00/code_0218c000.h"
#include "00/code_021a3000.h"
#include "00/code_0218b434.h"
#include "00/code_0219d000.h"
#include "00/code_0219e000.h"
#include "00/code_0219f000.h"
#include "00/code_021a0000.h"
#include "00/code_021a1000.h"
#include "00/unk_021b4000.h"
#include "code_0200d118.h"
#include "00/code_021a10b0.h"
#include "00/code_021a4784.h"
#include "code_0200f5ac.h"
#include "00/code_021988e8.h"
#include "00/code_0219a000.h"
#include "00/code_0219fb48.h"
#include "00/code_021a01dc.h"
#include "00/code_021a0958.h"
#include "00/code_021a17bc.h"

u32 func_ov000_0219fb14(u32 param_1) {
    u32 result;
    result = func_ov000_021a0ae8(5, param_1, data_ov000_021b566c->mUnk_24[0], data_ov000_021b566c->mUnk_a4[0], 0, 0);
    data_ov000_021b566c->mUnk_1ec = 0;
    return result;
}

u32 func_ov000_0219f9bc(u32 a) {
    s32 i;
    u32 b;

    if (data_ov000_021b566c->mUnk_17 != 0 && data_ov000_021b566c->mUnk_20 == data_ov000_021b566c->mUnk_1e8) {
        b = 0;
    } else {
        b = 1;
    }
    if (b != 0) {
        data_ov000_021b566c->mUnk_17 = 0;
        data_ov000_021b566c->mUnk_20 = 0;
        func_ov000_021a4818(data_ov000_021b566c->mUnk_10);
    }
    if (data_ov000_021b566c->mUnk_0d < 0x1f) {
        data_ov000_021b566c->mUnk_f4[data_ov000_021b566c->mUnk_0d + 1] = 0;
    }
    data_ov000_021b566c->mUnk_3b4 = 0xff;
    if (data_ov000_021b566c->mUnk_194 != 0) {
        func_ov000_0219ac50(data_ov000_021b566c->mUnk_194);
        data_ov000_021b566c->mUnk_194 = 0;
    }
    data_ov000_021b566c->mUnk_14 = data_ov000_021b566c->mUnk_0d;
    data_ov000_021b566c->mUnk_1ec = 0;
    if (b == 0) {
        if (data_ov000_021b566c->mUnk_15 != 3) {
            func_ov000_0219f214();
        }
    } else if (data_ov000_021b566c->mUnk_15 == 0) {
        data_ov000_021b566c->mUnk_198 = 3;
        data_ov000_021b566c->mUnk_e8 = 2;
        data_ov000_021b566c->mUnk_ec = func_0200f5ac();
    } else if (data_ov000_021b566c->mUnk_15 == 1) {
        data_ov000_021b566c->mUnk_198 = 4;
        func_ov000_0219fbec(1, 0);
    } else if (data_ov000_021b566c->mUnk_15 == 2) {
        data_ov000_021b566c->mUnk_198 = 14;
        data_ov000_021b566c->mUnk_1cc = 0;
        data_ov000_021b566c->mUnk_1a8 = 0;
        func_ov000_0219f124(a);
        for (i = 1; i <= data_ov000_021b566c->mUnk_0d; i++) {
            if (func_ov000_0219edb0(data_ov000_021b566c->mUnk_f4[i], 0xd) == 0) {
                return 0;
            }
        }
        if (data_ov000_021b566c->mUnk_0d == 0) {
            func_ov000_0219f23c(2);
        }
    }
    return 1;
}

u32 func_ov000_0219f938(u32 a) {
    u32 b;

    b = 1;
    if (data_ov000_021b566c->mUnk_15 == 3) {
        if (data_ov000_021b566c->mUnk_0d != 0) {
            func_ov000_0219f0f4();
        }
        func_ov000_021a1a38(6, -80430);
        return 0;
    }
    data_ov000_021b566c->mUnk_14 = data_ov000_021b566c->mUnk_0d;
    data_ov000_021b566c->mUnk_1f0 = 0;
    if (data_ov000_021b566c->mUnk_194 != 0) {
        func_ov000_0219ac50(data_ov000_021b566c->mUnk_194);
        data_ov000_021b566c->mUnk_194 = 0;
    }
    if (data_ov000_021b566c->mUnk_0d != 0) {
        func_ov000_0219f214();
    } else {
        data_ov000_021b566c->mUnk_198 = 4;
        b = func_ov000_0219fb48();
    }
    return b;
}

u32 func_ov000_0219f8b0(void) {
    s32 i;
    u32 r;

    for (i = 1; i <= data_ov000_021b566c->mUnk_0d; i++) {
        r = func_ov000_021a0ae8(10, data_ov000_021b566c->mUnk_f4[i], data_ov000_021b566c->mUnk_24[i],
                                data_ov000_021b566c->mUnk_a4[i], data_ov000_021b566c->mUnk_330,
                                data_ov000_021b566c->mUnk_330[0] + 1);
        if (r != 0) {
            return r;
        }
    }
    data_ov000_021b566c->mUnk_17 = 0;
    data_ov000_021b566c->mUnk_20 = 0;
    data_ov000_021b566c->mUnk_1a0 = 1;
    func_ov000_021988e8(*data_ov000_021b566c->mUnk_04);
    data_ov000_021b566c->mUnk_1a0 = 0;
    return 0;
}

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

u32 func_ov000_0219f4c4(u32 *param_1, u32 param_2) {
    Unk021b566c *p;
    u32 i;
    p = data_ov000_021b566c;
    if (p->mUnk_19e != 0 && p->mUnk_198 == 4) {
        return 1;
    }
    for (i = 0; i < param_2; i++) {
        if (func_ov000_0218eb9c(p->mUnk_00, *param_1) == 0) {
            return 0;
        }
        p = data_ov000_021b566c;
        if (p->mUnk_19e != 0 && p->mUnk_198 == 1) {
            return 1;
        }
        param_1++;
    }
    return 1;
}
