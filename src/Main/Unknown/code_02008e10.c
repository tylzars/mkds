#include "Main/Unknown/code_02008e10.h"
#include "code_0214cfe4.h"

#pragma thumb on

s32 func_02009098(const u8 *a, Unk02008f00Func b) {
    s32 i;
    Unk0216fc20 *d;
    Unk02008934 *e;
    u16 v1;
    i = 0;
    d = data_0216fc40;
    e = d->mUnk_10;
    for (; i < 0x10; i++) {
        u32 m = 1 << i;
        v1 = d->mUnk_00;
        if ((v1 & m) != 0 && e->mUnk_4b8 == data_usa_0216fc1c->mUnk_00 && e->mUnk_4c4[0] == a[4] &&
            e->mUnk_4c4[1] == a[5] && e->mUnk_4c4[2] == a[6] && e->mUnk_4c4[3] == a[7] && e->mUnk_4c4[4] == a[8] &&
            e->mUnk_4c4[5] == a[9] && data_usa_0216fc1c->mUnk_04_2 == d->mUnk_10[i].mUnk_4b5) {
            if ((d->mUnk_04 & m) == 0) {
                func_02008a4c(i);
            }
            return i;
        }
        e++;
    }
    i = 0;
    v1 = *(u16 *) d;
    for (; i < 0x10; i++) {
        u32 m = 1 << i;
        if ((v1 & m) == 0) {
            func_0214cffc(a, d->mUnk_10[i].mUnk_4c0, 0xc0);
            data_0216fc40->mUnk_10[i].mUnk_4b3 = data_usa_0216fc1c->mUnk_05;
            data_0216fc40->mUnk_00 |= (u16) m;
            func_02008a4c(i);
            return i;
        }
    }
    if (b != NULL) {
        b(4, NULL, 0);
    }
    return -1;
}

void func_02008ff0(u32 a, Unk02008f00Func b) {
    Unk02008934 *e;
    u32 m;
    e = &data_0216fc40->mUnk_10[a];
    if (e->mUnk_580 == e->mUnk_584 && e->mUnk_580 != 0 && e->mUnk_35a != 0 && e->mUnk_588 == e->mUnk_35a) {
        m = 1 << a;
        if ((data_0216fc40->mUnk_04 & m) == 0) {
            data_0216fc40->mUnk_04 |= m;
            data_0216fc40->mUnk_02 |= m;
            func_02008a14();
            if (b != NULL) {
                b(1, e, a);
            }
        }
    } else {
        m = 1 << a;
        if ((data_0216fc40->mUnk_04 & m) != 0) {
            data_0216fc40->mUnk_04 ^= m;
            if (b != NULL) {
                b(2, e, a);
            }
        }
    }
}

void func_02008f00(Unk02008f00Func a, u32 b) {
    u32 v1;
    s32 i;
    u32 v2;
    v1 = 0;
    i = 0;
    v2 = 0;
    for (; i < 0x10; i++) {
        Unk02008934 *e = (Unk02008934 *) ((u8 *) data_0216fc40->mUnk_10 + v2);
        u16 m = 1 << i;
        if (data_0216fc40->mUnk_00 & m) {
            e->mUnk_58a -= data_0216fc40->mUnk_0c;
            if (e->mUnk_58a < 0) {
                e->mUnk_58a = 0;
                if ((data_0216fc40->mUnk_04 & m) != 0 && a != NULL) {
                    a(3, NULL, i);
                }
                if ((data_0216fc40->mUnk_06 & m) != 0) {
                    v1 = 1;
                }
                data_0216fc40->mUnk_00 &= ~m;
                func_020089d0(i);
            }
        }
        v2 += sizeof(Unk02008934);
    }
    if (data_0216fc40->mUnk_06 != 0 && data_0216fc40->mUnk_08 > 0) {
        data_0216fc40->mUnk_08 -= data_0216fc40->mUnk_0c;
        if (data_0216fc40->mUnk_08 < 0) {
            v1 = 1;
        } else if (b == 0) {
            data_0216fc40->mUnk_0a++;
            if (data_0216fc40->mUnk_0a > 4) {
                v1 = 1;
            }
        } else {
            data_0216fc40->mUnk_0a = 0;
        }
    }
    if (v1 != 0) {
        data_0216fc40->mUnk_08 = 0;
        func_02008a14();
    }
}

void func_02008e10(u8 *a, u32 b, u32 c) {
    Unk02008934 *e;
    func_02008dbc(a, b);
    func_02008d68(b);
    func_02008d30(b);
    e = &data_0216fc40->mUnk_10[b];
    if (e->mUnk_58e == data_usa_0216fc1c->mUnk_07) {
        e->mUnk_58f++;
        if (e->mUnk_58f > 3) {
            e->mUnk_58a = 0;
            func_02008cbc(e->mUnk_4c4);
            return;
        }
    } else {
        e->mUnk_58f = 0;
    }
    e->mUnk_58e = data_usa_0216fc1c->mUnk_07;
    e->mUnk_58a = 0x1771;
    e->mUnk_4b8 = data_usa_0216fc1c->mUnk_00;
    e->mUnk_4b5 = data_usa_0216fc1c->mUnk_04_2;
    e->mUnk_58c = c;
    func_020091e0(e->mUnk_4c0, e->mUnk_4b8);
    if (data_usa_0216fc1c->mUnk_04 == 2) {
        func_02008aa0(b);
    } else {
        func_02008c08(b);
    }
}

#pragma thumb off
