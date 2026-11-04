#include "00/code_0219c3e4.h"

#include "00/code_0219c954.h"
#include "00/code_0219d128.h"
#include "00/unk_021b5000.h"
#include "00/code_0219c93c.h"
#include "Main/Unknown/code_0200f000.h"
#include "00/code_0219c000.h"
#include "00/code_0218f15c.h"
#include "00/code_02190000.h"
#include "00/code_0218f960.h"
#include "00/code_02194000.h"
#include "00/code_0218e8d4.h"
#include "00/code_02187484.h"
#include "03/code_021b94b8.h"
#include "00/code_021a369c.h"
#include "00/code_021a1ae0.h"
#include "code_0200f5ac.h"
#include "code_02133048.h"
#include "code_021329f8.h"
#include "code_02139f70.h"
#include "code_0214d018.h"
#include "code_02152500.h"
#include "code_021526bc.h"
#include "code_021526e4.h"
#include "code_02152a7c.h"
#include "Main/Unknown/code_021526c8.h"
#include "00/code_0218f000.h"
#include "00/code_0219b000.h"
#include "00/code_0219d000.h"
#include "00/unk_021b4000.h"
#include "code_0200fc8c.h"
#include "00/unk_021b1000.h"
#include "code_02151868.h"
#include "code_021519d4.h"
#include "00/code_02186a9c.h"
#include "00/code_021acef8.h"
#include "00/code_021a6c08.h"
#include "00/code_0218a67c.h"
#include "00/code_021a6934.h"
#include "00/code_02185954.h"
#include "00/code_0219c384.h"
#include "00/code_02198a8c.h"
#include "00/code_0219b580.h"

void func_ov000_0219ca84(void) {
    func_ov000_0219c67c(func_ov000_0219c80c, NULL);
    data_ov000_021b565c->mUnk_04 = 1;
    data_ov000_021b565c->mUnk_34 = 0;
}

void func_ov000_0219c9d8(void) {
    Unk021b565c *p;
    if (data_ov000_021b565c == NULL || func_ov000_0219c39c() != 0) {
        return;
    }
    p = data_ov000_021b565c;
    switch (p->mUnk_04) {
        case 1:
            func_ov000_0219c524();
            break;
        case 2:
        case 3:
        case 4:
            if (p->mUnk_00 != NULL && p->mUnk_00->mGpiConnection != NULL) {
                GpUpdate(p->mUnk_00);
            }
            if (data_ov000_021b565c->mUnk_34 != 0) {
                if ((((u64) func_0200f5ac() - data_ov000_021b565c->mUnk_38) << 6) / 0x82ea > 0xea60) {
                    func_ov000_0219c990(6, -61070);
                    data_ov000_021b565c->mUnk_34 = 0;
                }
            }
            break;
        case 5:
            break;
    }
}

Unk02152500 *func_ov000_0219c9c4(void) {
    if (data_ov000_021b565c != NULL) {
        return data_ov000_021b565c->mUnk_20;
    }
    return NULL;
}

void func_ov000_0219c990(s32 a, s32 b) {
    if (data_ov000_021b565c != NULL && a != 0) {
        func_ov000_0219c384(a, b);
        if (data_ov000_021b565c->mUnk_18 != NULL) {
            data_ov000_021b565c->mUnk_18(a, 0, data_ov000_021b565c->mUnk_1c);
        }
        func_ov000_0219c93c();
    }
}

void func_ov000_0219c954(void) {
    if (data_ov000_021b565c->mUnk_28 != NULL) {
        func_ov000_02186474();
        func_ov000_02186430();
        func_ov000_021a3704((u32) 0, (u32) ((u32) data_ov000_021b565c->mUnk_28), (u32) 0);
        data_ov000_021b565c->mUnk_28 = NULL;
    }
    *(s32 *) &data_ov000_021b565c = 0;
}

void func_ov000_0219c93c(void) {
    if (data_ov000_021b565c != NULL) {
        data_ov000_021b565c->mUnk_04 = 0;
        data_ov000_021b565c->mUnk_34 = 0;
    }
}

s32 func_ov000_0219c8dc(s32 a) {
    s32 x;
    s32 y;
    if (a == 0) {
        return 0;
    }
    switch (a) {
        case 1:
            x = 0xb;
            y = -1;
            break;
        case 2:
            x = 0xb;
            y = -2;
            break;
        case 3:
            x = 6;
            y = -10;
            break;
        case 4:
            x = 6;
            y = -20;
            break;
    }
    func_ov000_0219c990(x, y - 0xee48);
    return a;
}

void func_ov000_0219c824(GpConnection *a, Unk0219c400 *b, u32 c) {
    data_ov000_021b565c->mUnk_34 = 0;
    if (b->mUnk_00 == 0) {
        if (data_ov000_021b565c->mUnk_04 == 2) {
            if (func_ov000_0219c8dc(func_ov000_0219d558(1, data_ov000_021b4064, NULL)) == 0) {
                if (data_ov000_021b565c->mUnk_20->mUnk_1c == b->mUnk_04) {
                    if (func_ov000_0219ba20() == 0 && func_ov000_021a2768(b->mUnk_04) == 0) {
                        data_ov000_021b565c->mUnk_04 = 5;
                        data_ov000_021b565c->mUnk_18(0, b->mUnk_04, data_ov000_021b565c->mUnk_1c);
                    }
                } else {
                    func_ov000_0219c990(6, -60000);
                }
            }
        } else if (data_ov000_021b565c->mUnk_04 == 3) {
            if (func_ov000_0219c8dc(func_ov000_0218eff8(a, b->mUnk_04, 0, 0, func_ov000_0219c400, 0)) != 0) {
                return;
            }
        }
    } else {
        func_ov000_0219c8dc(b->mUnk_00);
    }
}

void func_ov000_0219c80c(char *a, char *b) {
    func_ov000_0219c79c(a, b, func_ov000_0219c824, 2);
}

void func_ov000_0219c79c(char *a, char *b, void (*c)(), s32 d) {
    Unk021b565c *v1;
    u32 v2;
    u64 v3;
    strcpy(data_ov000_021b565c->mUnk_4c, a);
    strcpy(data_ov000_021b565c->mUnk_14c, b);
    v2 = *(s32 *) &data_ov000_021b565c;
    v3 = func_0200f5ac();
    *(u64 *) (v2 + 0x38) = v3;
    *(u32 *) (v2 + 0x34) = 1;
    v1 = data_ov000_021b565c;
    v2 = func_ov000_0219c8dc(func_ov000_0218f15c(v1->mUnk_00, v1->mUnk_4c, v1->mUnk_14c, 1, 0, c, 0));
    if (v2 == 0) {
        data_ov000_021b565c->mUnk_04 = d;
    }
}

void func_ov000_0219c67c(void (*a)(), void *b) {
    Unk02186560 s;
    void *h;
    u64 t;
    MemFill(&s, 0, 0x2c);
    data_ov000_021b5660 = a;
    data_ov000_021b5658 = b;
    if (func_021526bc(data_ov000_021b565c->mUnk_20) != 0) {
        func_02152808(&data_ov000_021b565c->mUnk_20->mUnk_10, data_ov000_021b565c->mUnk_20->mUnk_24,
                      data_ov000_021b565c->mUnk_24c);
    } else {
        if (func_021526c8(&data_ov000_021b565c->mUnk_40) == 0) {
            if (func_021526e4(&data_ov000_021b565c->mUnk_20->mUnk_04) != 0) {
                data_ov000_021b565c->mUnk_40 = data_ov000_021b565c->mUnk_20->mUnk_04;
            } else {
                func_02152744(&data_ov000_021b565c->mUnk_40);
            }
        } else {
            func_02152a88(&data_ov000_021b565c->mUnk_40,
                          (u32) (((s64) func_0200f5ac() * 0x5d588b656c078965 + 0x269ec3) >> 32));
        }
        func_02152808(&data_ov000_021b565c->mUnk_40, data_ov000_021b565c->mUnk_0c, data_ov000_021b565c->mUnk_24c);
    }
    strcpy(s.mUnk_15, data_ov000_021b565c->mUnk_255);
    s.mUnk_24 = (void *(*) (const void *, u32)) func_ov000_021a372c;
    s.mUnk_28 = (void (*)(const void *, void *, u32)) func_ov000_021a3704;
    h = func_ov000_021a3718(0, 0x1a60, 4);
    data_ov000_021b565c->mUnk_28 = h;
    t = func_0200f5ac();
    *(u64 *) &data_ov000_021b565c->mUnk_2c = t;
    func_ov000_02186560(&s, h);
}

void func_ov000_0219c524(void) {
    Unk02186560 s;
    Unk0218635c x;
    Unk0218635c y;
    if (func_ov000_021863cc() == 0x14) {
        func_ov000_0218635c(&x.mUnk_000);
        strcpy(data_ov000_021b565c->mUnk_4c, x.mUnk_04a);
        strcpy(data_ov000_021b565c->mUnk_14c, x.mUnk_177);
        func_ov000_02186430();
        func_ov000_021a3704(0, (u32) data_ov000_021b565c->mUnk_28, 0);
        data_ov000_021b565c->mUnk_28 = NULL;
        if (func_021526bc(data_ov000_021b565c->mUnk_20) != 0) {
            data_ov000_021b5660(data_ov000_021b565c->mUnk_4c, data_ov000_021b565c->mUnk_14c, data_ov000_021b5658);
        } else {
            func_ov000_0219c79c(data_ov000_021b565c->mUnk_4c, data_ov000_021b565c->mUnk_14c, func_ov000_0219c824, 3);
        }
    } else if (func_ov000_021863cc() != 0) {
        if ((((u64) func_0200f5ac() - *(u64 *) &data_ov000_021b565c->mUnk_2c) << 6) / 0x82ea > 0x2710) {
            func_ov000_0218635c(&y.mUnk_000);
            func_ov000_02186430();
            func_ov000_021a3704(0, (u32) data_ov000_021b565c->mUnk_28, 0);
            data_ov000_021b565c->mUnk_28 = NULL;
            func_ov000_0219c990(2, y.mUnk_000);
        } else {
            func_ov000_02186430();
            MemFill(&s, 0, 0x2c);
            strcpy(s.mUnk_15, data_ov000_021b565c->mUnk_255);
            s.mUnk_24 = (void *(*) (const void *, u32)) func_ov000_021a372c;
            s.mUnk_28 = (void (*)(const void *, void *, u32)) func_ov000_021a3704;
            func_ov000_02186560(&s, data_ov000_021b565c->mUnk_28);
        }
    }
}

void func_ov000_0219c400(GpConnection *a, Unk0219c400 *b, u32 f) {
    char c[0x15];
    char d[0x15];
    char e[0x15];
    Unk021b565c *p;
    if (b->mUnk_00 != 0) {
        return;
    }
    p = data_ov000_021b565c;
    if (p->mUnk_04 == 3) {
        if (b->mUnk_8e[0] == 0) {
            func_02152808(&p->mUnk_20->mUnk_04, p->mUnk_0c, c);
            if (func_ov000_0219c8dc(func_ov000_0218efa8(a, 0x705, (const s8 *) c)) == 0) {
                data_ov000_021b565c->mUnk_04 = 4;
                if (func_ov000_0219c8dc(func_ov000_0218eff8(a, b->mUnk_04, 0, 0, func_ov000_0219c400, 0)) != 0) {
                    return;
                }
            }
        } else {
            GpDisconnect(a);
            func_ov000_0219c67c(func_ov000_0219c80c, NULL);
            data_ov000_021b565c->mUnk_04 = 1;
        }
    } else if (p->mUnk_04 == 4) {
        func_02152808(&p->mUnk_20->mUnk_04, p->mUnk_0c, d);
        if (strcmp((const char *) b->mUnk_8e, d) == 0) {
            func_02152808(&data_ov000_021b565c->mUnk_40, data_ov000_021b565c->mUnk_0c, e);
            func_021525f0(data_ov000_021b565c->mUnk_20, &data_ov000_021b565c->mUnk_40, b->mUnk_04);
            GpDisconnect(a);
            data_ov000_021b5660(data_ov000_021b565c->mUnk_4c, data_ov000_021b565c->mUnk_14c, data_ov000_021b5658);
        } else {
            if (func_ov000_0219c8dc(func_ov000_0218eff8(a, b->mUnk_04, 0, 0, func_ov000_0219c400, 0)) != 0) {
                return;
            }
        }
    }
}

u32 func_ov000_0219c3e4(void) {
    if ((data_ov000_021b565c != NULL) && (data_ov000_021b565c->mUnk_04 == 5)) {
        return 1;
    }
    return 0;
}
