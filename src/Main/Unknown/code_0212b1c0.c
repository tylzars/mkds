#include "Main/Unknown/code_0212b1c0.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_02024000.h"
#include "Main/Unknown/code_0214a034.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_02016468.h"

void func_0212b260(void) {
    s32 e;
    s32 c;
    s32 i;
    u8 *r;
    Unk0217d40c *p;
    u16 buf[100];
    s32 v;
    s32 n;
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
    func_0214d05c_inline((void *) (func_0214a034() + ((a >> 3) << 10)), 0x400);
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
    n = 0;
    func_0214d168(buf, 0, 0xc8);
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
                        n = 1;
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
                        n = 1;
                        p->mUnk_014 = 0xd0000;
                        break;
                }
            }
            data_0217d40c->mUnk_018 += e;
        } else if (w == 0xa) {
            n = 1;
            p->mUnk_010 += 0x10000;
            data_0217d40c->mUnk_018 += 2;
        } else if (w == 0) {
            p->mUnk_018 = r + 2;
        } else {
            buf[i] = w;
            i++;
            p->mUnk_018 += 2;
        }
    } while (n == 0);
    func_0214d168(data_0217d40c->mUnk_050, 0, 0x800);
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
        func_02016468(0x14, a << 7, p->mUnk_050, (0x100 - a) << 7);
        func_02016468(0x14, 0, &data_0217d40c->mUnk_050[a << 7], (a - 0xf0) << 7);
    } else {
        func_02016468(0x14, a << 7, p->mUnk_050, 0x800);
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
    func_020164e8();
}
