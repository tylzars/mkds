#include "Main/Unknown/code_0212b1a8.h"

#include "Main/Unknown/code_0212b1c0.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_02024000.h"
#include "code_02023374.h"
#include "code_0214a034.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_02016468.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0212b5d8.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/unk_0216e000.h"
#include "Main/Unknown/code_02036bec.h"
#include "code_0214a2f4.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02023000.h"
#include "Main/Unknown/code_0212b928.h"

#pragma thumb on
void func_0212b928(void *a, Nclr *b, u32 c) {
    s32 i;
    s32 v;
    data_0217d410 = HeapAlloc(a, 0x90);
    data_0217d410->mUnk_00 = 0;
    data_0217d410->mUnk_04 = 0;
    data_0217d410->mUnk_08 = c;
    data_0217d410->mUnk_8c = 1;
    MemCopy(b->mData + c * 0x10, data_0217d410->mUnk_0a, 0x20);
    for (i = 0; i < 4; i++) {
        v = data_0217d410->mUnk_14[i];
        data_0217d410->mUnk_2c[i].mUnk_00 = v & 0x1f;
        data_0217d410->mUnk_2c[i].mUnk_04 = (v & 0x3e0) >> 5;
        data_0217d410->mUnk_2c[i].mUnk_08 = (v & 0x7c00) >> 10;
    }
    for (i = 0; i < 4; i++) {
        v = data_0217d410->mUnk_1c[i];
        data_0217d410->mUnk_5c[i].mUnk_00 = v & 0x1f;
        data_0217d410->mUnk_5c[i].mUnk_04 = (v & 0x3e0) >> 5;
        data_0217d410->mUnk_5c[i].mUnk_08 = (v & 0x7c00) >> 10;
    }
}
#pragma thumb off

#pragma thumb on
void func_0212b91c(void) {
    u32 value0;
    u32 value1;
    value1 = 0u;
    value0 = (u32) &data_0217d410;
    *(u32 *) ((value0) + 0u) = value1;
}
#pragma thumb off

#pragma thumb on
void func_0212b874(s32 a) {
    s32 i;
    Unk0217d410 *p;
    for (i = 0; i < 4; i++) {
        p = data_0217d410;
        (&p->mUnk_0a[1])[i] = ((((0x1000 - a) * p->mUnk_2c[i].mUnk_08 + a * p->mUnk_5c[i].mUnk_08) >> 12) << 10) |
                              ((((0x1000 - a) * p->mUnk_2c[i].mUnk_00 + a * p->mUnk_5c[i].mUnk_00) >> 12) |
                               ((((0x1000 - a) * p->mUnk_2c[i].mUnk_04 + a * p->mUnk_5c[i].mUnk_04) >> 12) << 5));
    }
    if (data_0217d410->mUnk_8c == 0) {
        CallQueueAppend(0x1e, data_0217d410->mUnk_08 << 5, data_0217d410->mUnk_0a, 0x20);
    } else {
        data_0217d410->mUnk_8c = 0;
    }
}

void func_0212b80c(void) {
    s32 a;
    if (data_0217d410->mUnk_04 == 0) {
        data_0217d410->mUnk_00++;
        if (data_0217d410->mUnk_00 >= 0x5a) {
            data_0217d410->mUnk_00 = 0;
        }
    }
    a = data_0217d410->mUnk_00;
    if (a < 0x1e) {
        func_0212b874(((0x1e - a) << 12) / 0x1e);
    } else if (a < 0x3c) {
        func_0212b874(0);
    } else {
        func_0212b874(((a - 0x3c) << 12) / 0x1e);
    }
}

void func_0212b7fc(void) {
    data_0217d410->mUnk_00 = 0;
}

void func_0212b7e8(void) {
    data_0217d410->mUnk_00 = 0;
    data_0217d410->mUnk_04 = 1;
}

void func_0212b7d8(void) {
    data_0217d410->mUnk_04 = 0;
}
#pragma thumb off

void func_0212b5ec(void *a) {
    s32 i;
    s32 v;
    Nclr *p;
    Unk0217d40c *d;
    Unk02180728 *q;
    void *t;
    data_0217d40c = HeapAlloc(a, 0x85c);
    data_0217d40c->mUnk_858 = a;
    data_0217d40c->mUnk_000 = 0;
    data_0217d40c->mUnk_004 = 0;
    CallQueueInit(HeapAlloc(a, 0xa0), 0xa);
    data_0217d40c->mUnk_008 = 0;
    data_0217d40c->mUnk_010 = 0;
    data_0217d40c->mUnk_014 = -1;
    data_0217d40c->mUnk_00c = 0x70a;
    data_0217d40c->mUnk_01c = 1;
    data_0217d40c->mUnk_850 = 1;
    data_0217d40c->mUnk_854 = 0x240;
    *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & ~0x1f00) | 0x100;
    *(vu16 *) 0x4001008 = (*(vu16 *) 0x4001008 & ~3) | 1;
    *(vu16 *) 0x4001008 = (*(vu16 *) 0x4001008 & 0x43) | 0x1000;
    MemFillWordsByBlock_inline((void *) G2sBg0CntBits2To5Address(), 0x8000);
    for (i = 0; i < 0x400; i++) {
        ((u16 *) G2sBg0CntBits8To12Address())[i] = i | 0xf000;
    }
    LoadNclrData(&p, FindSceneFile(data_0216ea78));
    CallQueueAppend(0x1f, 0x1e0, p->mData + 0xf0, 0x20);
    func_02023408(data_0217d40c->mUnk_020, data_0217d40c->mUnk_050, 0x20, 2, 4);
    v = data_0217d40c->mUnk_01c;
    t = func_020b403c(2);
    d = data_0217d40c;
    q = &d->mUnk_040;
    d->mUnk_040.mUnk_00 = d->mUnk_020;
    q->mUnk_04 = t;
    q->mUnk_08 = v;
    q->mUnk_0c = 0;
    MemFill(data_0217d40c->mUnk_050, 0, 0x800);
    data_0217d40c->mUnk_018 = GetBmgEntry(FindSceneFile(data_0216ea94), 0);
}

u32 func_0212b5d8(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217d40c;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

void func_0212b260(void) {
    s32 e;
    s32 c;
    s32 i;
    u8 *r;
    Unk0217d40c *p;
    u16 buf[100];
    s32 v;
    BOOL n;
    s32 f;
    s32 x;
    u32 w;
    s32 a;
    Unk0217d40c_18 *q;
    data_0217d40c->mUnk_008 += data_0217d40c->mUnk_00c;
    a = (data_0217d40c->mUnk_008 >> 12) - 8;
    if (a < 0) {
        a += 0x100;
    }
    a = a % 256;
    MemFillWordsByBlock_inline((void *) (G2sBg0CntBits2To5Address() + ((a >> 3) << 10)), 0x400);
    p = data_0217d40c;
    if (p->mUnk_014 > 0) {
        p->mUnk_014 -= p->mUnk_00c;
        if (data_0217d40c->mUnk_014 <= 0) {
            data_0217d40c->mUnk_004 = 2;
        }
        return;
    }
    if (p->mUnk_008 <= p->mUnk_010) {
        return;
    }
    i = 0;
    n = FALSE;
    MemFill(buf, 0, 0xc8);
    do {
        p = data_0217d40c;
        r = p->mUnk_018;
        q = (Unk0217d40c_18 *) r;
        w = q->mUnk_00;
        if (w == 0x1a) {
            c = q->mUnk_03;
            e = q->mUnk_02;
            f = q->mUnk_04;
            if (c == 1) {
                x = 0;
                if (f != 0x63) {
                    x = q->mUnk_06;
                }
                switch (f) {
                    case 0:
                        p->mUnk_854 = 0x40;
                        switch (x) {
                            case 0:
                                data_0217d40c->mUnk_854 |= 0x200;
                                break;
                            case 1:
                                data_0217d40c->mUnk_854 |= 0x400;
                                break;
                            case 2:
                                data_0217d40c->mUnk_854 |= 0x800;
                                break;
                        }
                        break;
                    case 1:
                        n = TRUE;
                        p->mUnk_010 += x << 16;
                        break;
                    case 2:
                        p->mUnk_850 = x * 2 + 1;
                        break;
                    case 3:
                        p->mUnk_01c = x;
                        break;
                    case 4:
                        p->mUnk_00c = (x << 12) / 100;
                        break;
                    case 5:
                        break;
                    case 0x63:
                        n = TRUE;
                        p->mUnk_014 = 0xd0000;
                        break;
                }
            }
            data_0217d40c->mUnk_018 += e;
        } else if (w == 0xa) {
            n = TRUE;
            p->mUnk_010 += 0x10000;
            data_0217d40c->mUnk_018 += 2;
        } else if (w == 0) {
            p->mUnk_018 = r + 2;
        } else {
            buf[i] = w;
            i++;
            p->mUnk_018 += 2;
        }
    } while (n == FALSE);
    MemFill(data_0217d40c->mUnk_050, 0, 0x800);
    v = data_0217d40c->mUnk_850;
    c = 0;
    if (v == 3) {
        c = 2;
    }
    func_0202428c(&data_0217d40c->mUnk_040, 8, c, 0xf0, 0x10, v, data_0217d40c->mUnk_854, buf);
    p = data_0217d40c;
    a = (((p->mUnk_008 >> 12) % 256) + 0xc0) >> 3;
    a = a << 3;
    if (a >= 0x100) {
        a -= 0x100;
    }
    if (a + 0x10 > 0x100) {
        CallQueueAppend(0x14, a << 7, p->mUnk_050, (0x100 - a) << 7);
        CallQueueAppend(0x14, 0, &data_0217d40c->mUnk_050[a << 7], (a - 0xf0) << 7);
    } else {
        CallQueueAppend(0x14, a << 7, p->mUnk_050, 0x800);
    }
}

void func_0212b204(void) {
    data_0217d40c->mUnk_000 = data_0217d40c->mUnk_004;
    switch (data_0217d40c->mUnk_000) {
        case 0:
            break;
        case 1:
            func_0212b260();
            break;
        case 2:
            break;
    }
}

void func_0212b1c0(void) {
    *(vu32 *) 0x4001010 = (((data_0217d40c->mUnk_008 >> 12) % 256) << 16) & 0x1ff0000;
    CallQueueDrain();
}

u32 func_0212b1a8(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217d40c;
    value1 = 1u;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    *(u32 *) ((value0) + (4)) = value1;
    return value0;
}
