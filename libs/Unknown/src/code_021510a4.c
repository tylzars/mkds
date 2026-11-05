#include "code_021510a4.h"
#include "code_0200eddc.h"
#include "code_0214d018.h"
#include "code_0214d5b8.h"
#include "code_0200f5ac.h"
#include "string.h"
#include "code_02134398.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_02000000.h"
#include "Main/Unknown/unk_02180000.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/code_0200007e.h"

#pragma thumb on

u8 CountSetBitsInBytes4(const u8 *a) {
    s32 c;
    s32 b;
    s32 d;
    u8 e;
    b = 0;
    c = 0;
    for (; b < 4; b++) {
        d = 0;
        e = a[b];
        for (; d < 8; d++) {
            if ((e >> d) & 1) {
                c++;
            }
        }
    }
    return c;
}

void Bytes4StoreTopBitsMask(u32 a, u8 *b) {
    s32 c;
    u32 d;
    u32 e;
    c = 0;
    d = ((u32) ~c >> a) ^ ~c;
    e = c;
    for (; c < 4; c++) {
        b[c] = d >> (0x18 - e);
        e += 8;
    }
}

u32 Bytes32AnyNonzero(const u8 *a) {
    s32 b;
    for (b = 0; b < 0x20; b++) {
        if (a[b] != 0) {
            return 1;
        }
    }
    return 0;
}

u32 func_02151640(const u8 *a, const u8 *b) {
    u32 c[2];
    if (func_02151620(a) == 0) {
        return 0;
    }
    MemCopy(a, &c[0], 4);
    MemCopy(b, &c[1], 4);
    if ((c[0] | c[1]) == 0xfffffffe) {
        return 0;
    }
    if ((c[0] & ~c[1]) == 0) {
        return 0;
    }
    return 1;
}

u32 func_02151620(const u8 *a) {
    u8 b = *a;
    if (b == 0x7f) {
        return 0;
    }
    if (b < 1) {
        return 0;
    }
    if (b <= 0xdf) {
        return 1;
    }
    return 0;
}

static inline u32 func_02151288_inline(u32 f, u32 a, u32 b, u32 c, u32 d, u32 e, u32 g) {
    if (PxiSendFifoWord(f, a, 0) < 0) {
        return 0;
    }
    if (PxiSendFifoWord(f, b, 0) < 0) {
        return 0;
    }
    if (PxiSendFifoWord(f, c, 0) < 0) {
        return 0;
    }
    if (PxiSendFifoWord(f, d, 0) < 0) {
        return 0;
    }
    if (PxiSendFifoWord(f, e, 0) < 0) {
        return 0;
    }
    if (PxiSendFifoWord(f, g, 0) < 0) {
        return 0;
    }
    return 1;
}

static inline u32 func_02151288_inline2(u32 f, u32 a, u32 b, u32 c) {
    if (PxiSendFifoWord(f, a, 0) < 0) {
        return 0;
    }
    if (PxiSendFifoWord(f, b, 0) < 0) {
        return 0;
    }
    if (PxiSendFifoWord(f, c, 0) < 0) {
        return 0;
    }
    return 1;
}

static inline u32 func_02151288_inline3(u32 f, u32 a) {
    if (PxiSendFifoWord(f, a, 0) >= 0) {
        return 1;
    }
    return 0;
}

u32 func_02151288(u32 a, u32 b, u16 c, u32 d) {
    u32 e;
    u32 f;
    u32 l1;
    u32 l2;
    u32 l3;
    u32 l4;
    u32 l5;
    u32 l6;
    u32 l7;
    u32 l8;
    u32 l9;
    u64 g;
    e = 0;
    l5 = (b >> 16) & 0xff;
    l1 = l5;
    l1 |= 0x2002300;
    b &= 0xffff;
    b |= 0x10000;
    l2 = c;
    l2 &= 0xffff;
    l2 |= 0x30000;
    l6 = d;
    l6 >>= 16;
    l3 = l6;
    l3 |= 0x40000;
    d &= 0xffff;
    l4 = d;
    l4 |= 0x1050000;
    l5 |= 0x2002500;
    l6 |= 0x30000;
    d |= 0x1040000;
    l7 = (u32) &data_usa_021804a0 >> 24;
    l7 |= 0x2002200;
    l8 = (u32) &data_usa_021804a0 >> 8;
    l8 &= 0xffff;
    l8 |= 0x10000;
    l9 = (u32) &data_usa_021804a0 << 8;
    l9 &= 0xff00;
    l9 |= 0x1020000;
    f = 4;
    while (1) {
        if (e == 0) {
            data_usa_02180478 = 0;
            switch (a) {
                case 1:
                    e = func_02151288_inline(f, l1, b, 0x20000, l2, l3, l4);
                    break;
                case 2:
                    e = func_02151288_inline3(f, 0x3002000);
                    break;
                case 3:
                    if (PxiSendFifoWord(f, l5, 0) < 0) {
                        e = 0;
                    } else if (PxiSendFifoWord(f, b, 0) < 0) {
                        e = 0;
                    } else if (PxiSendFifoWord(f, c | 0x20000, 0) < 0) {
                        e = 0;
                    } else if (PxiSendFifoWord(f, l6, 0) < 0) {
                        e = 0;
                    } else if (PxiSendFifoWord(f, d, 0) < 0) {
                        e = 0;
                    } else {
                        e = 1;
                    }
                    g = func_0200f5ac();
                    break;
                case 4:
                case 5:
                    e = func_02151288_inline2(f, l7, l8, l9);
                    break;
                case 6:
                    e = func_02151288_inline3(f, 0x3002d00);
                    break;
                case 7:
                    e = func_02151288_inline3(f, 0x3002100);
                    break;
            }
        } else if (data_usa_02180478 == 1) {
            e = 0;
            if (data_usa_02180474 != 0) {
                break;
            }
            switch (a) {
                case 1:
                    return 1;
                case 2:
                    a = f;
                    break;
                case 3:
                    a = 5;
                    break;
                case 4:
                case 5:
                    func_0200ee3c(&data_usa_021804a0, 1);
                    if (a == 4) {
                        if (data_usa_021804a0 & 2) {
                            a = 3;
                            break;
                        }
                        return 0;
                    }
                    if ((data_usa_021804a0 & 1) == 0) {
                        return 1;
                    }
                    if ((data_usa_021804a0 & 0x20) != 0 || ((func_0200f5ac() - g) * 64) / 33514 > 4000) {
                        a = 6;
                    } else {
                        WaitByLoop(0x4000);
                    }
                    break;
                case 6:
                    return e;
                case 7:
                    return 1;
            }
        }
    }
    return e;
}

u32 func_0215122c(u32 a, u32 b, void *c) {
    u32 d;
    func_0200ee3c(c, b);
    d = 4;
    while (PxiCallbackBitIsSet(d, 1) == 0) {
    }
    PxiCallbackSet(4, (UnkFunc *) func_02151128);
    d = 1;
    while (1) {
        if (func_02151288(d, a, b, (u32) c) == 1) {
            break;
        }
        WaitByLoop(0x40000);
    }
    func_0200ee3c(c, b);
    return 1;
}

void func_021511d8(u32 a, u16 b, void *c) {
    u32 d;
    d = 4;
    while (PxiCallbackBitIsSet(d, 1) == 0) {
    }
    PxiCallbackSet(4, (UnkFunc *) func_02151128);
    func_0200ee58(c, b);
    d = 2;
    while (1) {
        if (func_02151288(d, a, b, (u32) c) == 1) {
            break;
        }
        WaitByLoop(0x40000);
    }
}

u32 func_0215119c(const u8 *a, u32 b, u32 c, const u8 *d) {
    if (func_0215122c(b, c, (void *) d) == 0) {
        return 0;
    }
    if (memcmp(a, d, c) == 0) {
        return 1;
    }
    return 0;
}

u32 func_02151154(void) {
    u32 a;
    u32 b;
    u32 c;
    a = 4;
    b = 1;
    while (PxiCallbackBitIsSet(a, b) == 0) {
    }
    PxiCallbackSet(4, (UnkFunc *) func_02151128);
    b = 0x40000;
    a = 7;
    c = 0;
    while (1) {
        if (func_02151288(a, c, c, c) == 1) {
            break;
        }
        WaitByLoop(b);
    }
    return 1;
}

u16 func_02151128(u32 a, u32 b, u32 c) {
    data_usa_02180474 = b & 0xff;
    data_usa_02180478 = 1;
    if (c != 0) {
        data_usa_02180474 = 0xff;
    }
    return data_usa_02180474;
}

u8 *func_021510a4(const Unk021510a4 *a) {
    u64 b;
    u32 c;
    u32 d;
    b = a->mUnk_08;
    MemCopy(a, data_021804a0, 5);
    c = ((u32) (a->mUnk_00 >> 32) >> 8) & 7;
    c |= ((u32) b & 0x1f) << 3;
    data_021804a0[5] = c;
    b >>= 5;
    MemCopy(&b, data_021804a0 + 6, 4);
    d = (u32) (b >> 32) & 0x3f;
    d |= (a->mUnk_10 & 3) << 6;
    data_021804a0[10] = d;
    data_021804a0[11] = a->mUnk_10 >> 2;
    MemCopy(&a->mUnk_12, data_021804a0 + 12, 2);
    return data_021804a0;
}

#pragma thumb off
