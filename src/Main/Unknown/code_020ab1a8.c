#include "Main/Unknown/code_020ab1a8.h"
#include "Main/Unknown/code_020ab5b4.h"
#include "Main/Unknown/code_020ab5bc.h"
#include "Main/Unknown/code_020ab5e4.h"
#include "Main/Unknown/code_020ab604.h"
#include "Main/Unknown/unk_02167000.h"

#pragma thumb on

s32 func_020ab59c(Unk0217b278_34 *p) {
    if (p->mUnk_00 == p->mUnk_02 || p->mUnk_00 == p->mUnk_04) {
        return 1;
    }
    return 0;
}

void func_020ab580(u16 a) {
    func_020ab5f4(&data_0217b2cc.mUnk_00);
    data_0217b2cc.mUnk_08 = a;
    data_0217b2cc.mUnk_0a = 0;
}

void func_020ab528(void) {
    if (data_0217b2cc.mUnk_0a == 0 && func_020ab650(data_0217b2cc.mUnk_08) != 0) {
        data_0217b2cc.mUnk_0a = func_020ab650(data_0217b2cc.mUnk_08);
        return;
    }
    if (func_020ab640(data_0217b2cc.mUnk_0a) != 0) {
        func_020ab5bc(&data_0217b2cc.mUnk_00);
    } else {
        func_020ab5b4(&data_0217b2cc.mUnk_00);
        data_0217b2cc.mUnk_0a = 0;
    }
}

u16 func_020ab500(void) {
    u32 v;

    if (func_020ab59c(&data_0217b2cc.mUnk_00) != 0) {
        v = func_020ab640(data_0217b2cc.mUnk_0a);
    } else {
        v = 0;
    }
    return v;
}

u16 func_020ab4d4(void) {
    if (func_020ab650(0x2fff) != 0) {
        return func_020ab650(0x2fff);
    }
    return func_020ab500();
}

void func_020ab45c(Unk0217b278 *p) {
    switch (p->mUnk_3c) {
        case 4:
            p->mUnk_42 = p->mUnk_42 != 4 ? 4 : 0;
            break;
        case 5:
            p->mUnk_42 = p->mUnk_42 != 5 ? 5 : 0;
            break;
    }
    switch (p->mUnk_42) {
        case 0:
            p->mUnk_30 = data_0217b318 + 1;
            break;
        case 4:
            p->mUnk_30 = data_0217b304 + 1;
            break;
        case 5:
            p->mUnk_30 = data_0217b31c + 1;
            break;
    }
}

void func_020ab3ec(Unk0217b278 *p) {
    switch (p->mUnk_3c) {
        case 4:
            p->mUnk_40 = 4;
            p->mUnk_42 = 0;
            break;
        case 5:
            p->mUnk_40 = 5;
            p->mUnk_42 = 0;
            break;
    }
    switch (p->mUnk_40) {
        case 4:
            if (p->mUnk_42 == 0) {
                p->mUnk_30 = data_0217b338 + 1;
            }
            break;
        case 5:
            if (p->mUnk_42 == 0) {
                p->mUnk_30 = data_0217b300 + 1;
            }
            break;
    }
}

Unk0217b278_10 *func_020ab338(u16 a) {
    Unk0217b278_10 *e;
    s32 i;
    u16 n;
    u16 c;
    u16 *w;

    if (data_0217b278.mUnk_2c != 0) {
        e = data_0217b278.mUnk_2c->mUnk_00;
        n = data_0217b278.mUnk_2c->mUnk_0e;
        c = data_0217b278.mUnk_2c->mUnk_0c;
        w = data_0217b278.mUnk_30;
        switch (a) {
            case 0:
                return 0;
            case 1:
                return &data_0217b278.mUnk_00;
            case 2:
                return &data_0217b278.mUnk_08;
            case 8:
                return e;
            case 10:
                return e + 1;
            case 0x20:
            case 0x3000:
                return e + 2;
        }
        for (i = 0; i < n; i++) {
            if (e[i].mUnk_02 > 1 && e[i].mUnk_03 > 1 && a == w[e[i].mUnk_06 - c - 1]) {
                return &e[i];
            }
        }
    }
    return 0;
}

s32 func_020ab2a4(Unk0217b278_10 *p) {
    Unk0217b278_10 *e;
    s32 i;
    s32 n;
    u16 c;
    u16 *w;

    if (data_0217b278.mUnk_2c != 0) {
        e = data_0217b278.mUnk_2c->mUnk_00;
        n = data_0217b278.mUnk_2c->mUnk_0e;
        c = data_0217b278.mUnk_2c->mUnk_0c;
        w = data_0217b278.mUnk_30;
        if (p == 0) {
            return 0;
        }
        if (p == &data_0217b278.mUnk_00) {
            return 1;
        }
        if (p == &data_0217b278.mUnk_08) {
            return 2;
        }
        for (i = 0; i < n; i++) {
            if (e[i].mUnk_02 > 1 && e[i].mUnk_03 > 1 && p == &e[i]) {
                switch (i) {
                    case 0:
                        return 8;
                    case 1:
                        return 0xa;
                    case 2:
                        return 0x20;
                }
                return w[e[i].mUnk_06 - c - 1];
            }
        }
    }
    return 0;
}

s32 func_020ab1d0(u32 a) {
    Unk0217b278_1c *t;
    u16 c;

    t = data_0217b278.mUnk_2c;
    if (t != 0) {
        if (a == 0) {
            return 0;
        }
        c = t->mUnk_0c;
        if (a <= c || a == 0xffff) {
            if (t->mUnk_08 == func_020ab3ec) {
                switch ((s32) a) {
                    case 1:
                        return 8;
                    case 2:
                        return 0xa;
                    case 3:
                        return 0x3000;
                    case 4:
                        return 6;
                    case 5:
                        return 7;
                    case 6:
                        return 0x10;
                    case 7:
                        return 0x11;
                    case 8:
                        return 0x12;
                    case 0xffff:
                        return 0x13;
                }
            } else {
                switch ((s32) a) {
                    case 1:
                        return 8;
                    case 2:
                        return 0xa;
                    case 3:
                        return 0x20;
                    case 4:
                        return 4;
                    case 5:
                        return 5;
                }
            }
        }
        if (a <= 0xff && data_0217b278.mUnk_30[a - c - 1] > 0x20) {
            return data_0217b278.mUnk_30[a - c - 1];
        }
    }
    return 0;
}

void func_020ab1a8(u16 a, u16 b, u16 c) {
    data_021679fc[0] = a;
    data_021679fc[1] = b;
    data_021679fc[2] = c;
    func_020ab580(data_021679fc[2] | (data_021679fc[0] | 0xf0 | data_021679fc[1]));
}

#pragma thumb off
