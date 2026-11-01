#include "01/code_021a30e0.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/code_020ae408.h"
#include "01/code_02181070.h"
#include "01/code_021a5140.h"
#include "01/code_02184000.h"
#include "01/code_02185000.h"
#include "01/code_02192000.h"
#include "01/code_021927c0.h"
#include "01/code_021a4000.h"
#include "01/code_021a5000.h"
#include "01/code_021a6000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "Main/Unknown/code_02105000.h"
#include "code_0212df7c.h"

void func_ov001_021a30e0(void) {
    s32 i;
    s32 x;
    s32 y;
    s32 dx;
    s32 dy;
    s32 dz;
    s32 prev;
    s32 flag;
    void *entry8;
    void *entry9;
    void *entry;

    flag = 0;
    if (func_ov001_02192a54()) {
        y = func_ov001_02192a60();
        x = func_ov001_02192a6c();
        i = func_ov001_021850b4(data_ov001_021ca41c->mUnk_0858, 0, x, y);
        while (i >= 0) {
            func_ov001_021a41c8(i, 1);
            y = func_ov001_02192a60();
            x = func_ov001_02192a6c();
            i = func_ov001_021850b4(data_ov001_021ca41c->mUnk_0858, i + 1, x, y);
        }
    }

    if (func_ov001_02192a14(8)) {
        func_ov001_021a41c8(0x1a, 0);
    } else if (func_ov001_02192a14(4)) {
        func_ov001_021a41c8(0x19, 0);
    } else if (func_ov001_02192a14(2)) {
        func_ov001_021a41c8(0x17, 0);
    } else if (func_ov001_02192a14(0x800)) {
        func_ov001_021a41c8(0x2a, 0);
    } else {
        entry8 = func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 8);
        func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, data_ov001_021a6fe8[data_ov001_021ca41c->mUnk_107c]);
        entry9 = func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 9);
        func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, data_ov001_021a7058[data_ov001_021ca41c->mUnk_1080]);
        dx = 0;
        dy = 0;
        dz = 0;
        dx += func_020ae408(8, 0x20) ? -1 : 0;
        dx += func_020ae408(8, 0x10) ? 1 : 0;
        dy += func_020ae408(8, 0x40) ? -1 : 0;
        dy += func_020ae408(8, 0x80) ? 1 : 0;
        dz += func_020ae408(8, 0x200) ? -1 : 0;
        dz += func_020ae408(8, 0x100) ? 1 : 0;

        switch (data_ov001_021ca41c->mUnk_1094) {
            case 0:
                func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 0xb), -5);
                func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 0xc), 0);
                func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 0xd), -5);
                if (dz > 0) {
                    data_ov001_021ca41c->mUnk_1094 = 2;
                    data_ov001_021ca41c->mUnk_1080 = func_ov001_021a63b4() - 1;
                    func_ov001_02184fb4(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 9), 0x1000);
                    func_ov001_02184fb4(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 10), 0);
                    func_ov001_021850a4(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 9), 0);
                    func_ov001_021850a4(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 10), 0);
                    func_0212ecc0(&data_0217d068, 0, 0x1ee);
                } else if (dz < 0) {
                    data_ov001_021ca41c->mUnk_1094 = 1;
                    switch (func_ov001_021a639c()) {
                        case 0:
                            data_ov001_021ca41c->mUnk_107c =
                                func_ov001_021a637c() + data_ov001_021a6fc8[func_ov001_021a639c()];
                            break;
                        case 1:
                            data_ov001_021ca41c->mUnk_107c =
                                func_ov001_021a637c() + data_ov001_021a6fc8[func_ov001_021a639c()];
                            break;
                        case 2:
                            data_ov001_021ca41c->mUnk_107c = data_ov001_021a6fc8[func_ov001_021a639c()];
                            break;
                        case 3:
                            data_ov001_021ca41c->mUnk_107c = data_ov001_021a6fc8[func_ov001_021a639c()];
                            break;
                    }
                    func_ov001_02184fb4(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 8), 0x1000);
                    func_ov001_021850a4(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 8), 0);
                    func_0212ecc0(&data_0217d068, 0, 0x1ee);
                }
                break;
            case 1:
                func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 0xb), 0);
                func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 0xc), -5);
                func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 0xd), -5);
                if (dz < 0) {
                    data_ov001_021ca41c->mUnk_1094 = 2;
                    data_ov001_021ca41c->mUnk_1080 = func_ov001_021a63b4() - 1;
                    func_ov001_02184fb4(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 9), 0x1000);
                    func_ov001_02184fb4(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 10), 0);
                    func_ov001_021850a4(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 9), 0);
                    func_ov001_021850a4(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 10), 0);
                    func_ov001_02185018(entry8, -5);
                    func_0212ecc0(&data_0217d068, 0, 0x1ee);
                } else if (dz > 0) {
                    data_ov001_021ca41c->mUnk_1094 = 3;
                    func_ov001_02185018(entry8, -5);
                    func_0212ecc0(&data_0217d068, 0, 0x1ee);
                } else if (func_ov001_02192a14(1)) {
                    if (data_ov001_021a6fe8[data_ov001_021ca41c->mUnk_107c] != 0x17 || func_ov001_02181070()) {
                        func_ov001_021a41c8(data_ov001_021a6fe8[data_ov001_021ca41c->mUnk_107c], 0);
                    }
                } else {
                    prev = data_ov001_021ca41c->mUnk_107c;
                    data_ov001_021ca41c->mUnk_107c = data_ov001_021a710c[dy + 1][prev];
                    data_ov001_021ca41c->mUnk_107c = data_ov001_021a719c[dx + 1][data_ov001_021ca41c->mUnk_107c];
                    entry = func_ov001_02185160(data_ov001_021ca41c->mUnk_0858,
                                                data_ov001_021a6fe8[data_ov001_021ca41c->mUnk_107c]);
                    func_ov001_02185018(entry8, 0);
                    func_ov001_02184fd8(entry8, func_ov001_02184fc8(entry), func_ov001_02184fb8(entry));
                    if (data_ov001_021ca41c->mUnk_107c != prev) {
                        func_02105ac0(0x1ef);
                    }
                }
                func_ov001_021a5f70(0, (s32) (func_ov001_02192a6c()), (s32) (func_ov001_02192a60()), 0, 0, 0);
                break;
            case 2:
                func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 0xb), -5);
                func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 0xc), -5);
                func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 0xd), 0);
                if (dz > 0) {
                    data_ov001_021ca41c->mUnk_1094 = 1;
                    switch (func_ov001_021a639c()) {
                        case 0:
                            data_ov001_021ca41c->mUnk_107c =
                                func_ov001_021a637c() + data_ov001_021a6fb8[func_ov001_021a639c()];
                            break;
                        case 1:
                            data_ov001_021ca41c->mUnk_107c =
                                func_ov001_021a637c() + data_ov001_021a6fb8[func_ov001_021a639c()];
                            break;
                        case 2:
                            data_ov001_021ca41c->mUnk_107c = data_ov001_021a6fb8[func_ov001_021a639c()];
                            break;
                        case 3:
                            data_ov001_021ca41c->mUnk_107c = data_ov001_021a6fb8[func_ov001_021a639c()];
                            break;
                    }
                    func_ov001_02184fb4(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 8), 0x1000);
                    func_ov001_021850a4(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 8), 0);
                    func_ov001_02184fb4(entry9, 0);
                    func_ov001_02184fb4(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 10), 0x1000);
                    data_ov001_021ca41c->mUnk_1080 = func_ov001_021a63b4() - 1;
                    func_ov001_02185018(entry9, -5);
                    func_0212ecc0(&data_0217d068, 0, 0x1ee);
                } else if (dz < 0) {
                    data_ov001_021ca41c->mUnk_1094 = 3;
                    func_ov001_02184fb4(entry9, 0);
                    func_ov001_02184fb4(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 10), 0x1000);
                    data_ov001_021ca41c->mUnk_1080 = func_ov001_021a63b4() - 1;
                    func_ov001_02185018(entry9, -5);
                    func_0212ecc0(&data_0217d068, 0, 0x1ee);
                } else if (func_ov001_02192a14(1)) {
                    func_ov001_021a41c8(data_ov001_021a7058[data_ov001_021ca41c->mUnk_1080], 0);
                } else {
                    prev = data_ov001_021ca41c->mUnk_1080;
                    data_ov001_021ca41c->mUnk_1080 = data_ov001_021a722c[dy + 1][prev];
                    data_ov001_021ca41c->mUnk_1080 = data_ov001_021a72ec[dx + 1][data_ov001_021ca41c->mUnk_1080];
                    func_ov001_02185160(data_ov001_021ca41c->mUnk_0858,
                                        data_ov001_021a7058[data_ov001_021ca41c->mUnk_1080]);
                    if (data_ov001_021ca41c->mUnk_1080 < 0xf) {
                        func_ov001_02185018(entry9, 0);
                    } else {
                        func_ov001_02185018(entry9, -5);
                    }
                    if (data_ov001_021ca41c->mUnk_1080 != prev) {
                        func_02105ac0(0x1ef);
                    }
                }
                func_ov001_021a5f70(0, (s32) (func_ov001_02192a6c()), (s32) (func_ov001_02192a60()), 0, 0, 0);
                break;
        }
    }

    if (func_ov001_02192a54() && func_ov001_021a62c4((s32) (func_ov001_02192a6c()), (s32) (func_ov001_02192a60()))) {
        func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 0xb), -5);
        func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 0xc), 0);
        func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 0xd), -5);
        data_ov001_021ca41c->mUnk_1080 = func_ov001_021a63b4() - 1;
        if (func_ov001_02184fb0(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 9)) == 0x1000) {
            func_ov001_02184fb4(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 9), 0);
            func_ov001_02184fb4(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 10), 0x1000);
        }
        if (func_ov001_02184fb0(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 8)) == 0x1000) {
            func_ov001_02184fb4(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 8), 0);
        }
        data_ov001_021ca41c->mUnk_1094 = 0;
    } else if (data_ov001_021ca41c->mUnk_1094 == 3) {
        func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 0xb), -5);
        func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 0xc), 0);
        func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 0xd), -5);
        data_ov001_021ca41c->mUnk_1080 = func_ov001_021a63b4() - 1;
        if (func_ov001_02184fb0(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 9)) == 0x1000) {
            func_ov001_02184fb4(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 9), 0);
            func_ov001_02184fb4(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 10), 0x1000);
        }
        if (func_ov001_02184fb0(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 8)) == 0x1000) {
            func_ov001_02184fb4(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 8), 0);
        }
        if (!func_ov001_02192a48() && !func_ov001_02192a04(1) && !func_ov001_02192a04(2)) {
            data_ov001_021ca41c->mUnk_1094 = 0;
        }
    }

    if (data_ov001_021ca41c->mUnk_1094 == 0) {
        dx = 0;
        dy = 0;
        dx += func_ov001_021928c8(0x20) ? -1 : 0;
        dx += func_ov001_021928c8(0x10) ? 1 : 0;
        dy += func_ov001_021928c8(0x40) ? -1 : 0;
        dy += func_ov001_021928c8(0x80) ? 1 : 0;
        if (func_ov001_021a5f70((s32) (func_ov001_02192a48()), (s32) (func_ov001_02192a6c()),
                                (s32) (func_ov001_02192a60()), (s32) (func_ov001_02192a04(1)), (s32) (dx),
                                (s32) (dy))) {
            if (func_ov001_021a639c() == 3) {
                data_ov001_021ca41c->mUnk_1080 = func_ov001_021a63b4() - 1;
                func_0212ecc0(&data_0217d068, 0, 0x1f4);
            } else if (func_ov001_021a639c() == 2) {
                func_0212ecc0(&data_0217d068, 0, 0x1f5);
            }
        } else if (func_ov001_02192a04(0x400)) {
            flag = 1;
            if (func_ov001_021a6278()) {
                data_ov001_021ca41c->mUnk_1080 = func_ov001_021a63b4() - 1;
                func_0212ecc0(&data_0217d068, 0, 0x1f4);
            }
        }
        if (func_ov001_02192a48() && !func_ov001_02192a24() &&
            func_ov001_021a62c4((s32) (func_ov001_02192a6c()), (s32) (func_ov001_02192a60()))) {
            data_ov001_021ca41c->mUnk_10b8 = 1;
        } else if (func_ov001_02192a48() &&
                   (func_ov001_021a62c4((s32) (func_ov001_02192a6c()), (s32) (func_ov001_02192a60())) ||
                    func_ov001_021a62c4((s32) (func_ov001_02192a3c()), (s32) (func_ov001_02192a30()))) &&
                   (func_ov001_021a633c() != func_ov001_021a6314() || func_ov001_021a6328() != func_ov001_021a6300())) {
            data_ov001_021ca41c->mUnk_10b8 = 1;
        } else if (func_ov001_02192a14(1)) {
            data_ov001_021ca41c->mUnk_10b8 = 1;
        } else if (func_ov001_02192a04(1) &&
                   (func_ov001_021a633c() != func_ov001_021a6314() || func_ov001_021a6328() != func_ov001_021a6300())) {
            data_ov001_021ca41c->mUnk_10b8 = 1;
        }
    } else {
        func_ov001_021a5f70(0, (s32) (func_ov001_02192a6c()), (s32) (func_ov001_02192a60()), 0, 0, 0);
    }

    func_ov001_02184fd8(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 0), func_ov001_021a633c(),
                        func_ov001_021a6328());
    func_ov001_02184fd8(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 1), func_ov001_021a633c(),
                        func_ov001_021a6328());
    func_ov001_02184fd8(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 2), func_ov001_021a633c(),
                        func_ov001_021a6328());
    func_ov001_02184fd8(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 3), func_ov001_021a633c(),
                        func_ov001_021a6328());

    if (data_ov001_021ca41c->mUnk_1094 == 0 && func_ov001_02192a48() &&
        func_ov001_021a62c4((s32) (func_ov001_02192a6c()), (s32) (func_ov001_02192a60()))) {
        func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 0), -5);
        data_ov001_021ca41c->mUnk_1088 = -1;
    } else if (data_ov001_021ca41c->mUnk_1094 == 0 && func_ov001_02192a48() &&
               func_ov001_02184ff8(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 0)) == -5) {
        func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 0), -5);
        data_ov001_021ca41c->mUnk_1088 = -1;
    } else {
        data_ov001_021ca41c->mUnk_1088 = func_ov001_021a637c();
        if (flag) {
            func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 0), 3);
        } else {
            switch (func_ov001_021a639c()) {
                case 0:
                    func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 0), 0);
                    break;
                case 2:
                    func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 0), 1);
                    break;
                case 1:
                    func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 0), 2);
                    break;
                case 3:
                    func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 0), 3);
                    break;
            }
        }
    }

    switch (data_ov001_021ca41c->mUnk_1088) {
        case 0:
            func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 1), -4);
            func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 2), -5);
            func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 3), -5);
            break;
        case 1:
            func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 1), -5);
            func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 2), -4);
            func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 3), -5);
            break;
        case 2:
            func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 1), -5);
            func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 2), -5);
            func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 3), -4);
            break;
    }

    entry = func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, data_ov001_021a7058[data_ov001_021ca41c->mUnk_1080]);
    func_ov001_02184fd8(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 9), func_ov001_02184fc8(entry),
                        func_ov001_02184fb8(entry));
    func_ov001_02184fd8(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 10), func_ov001_02184fc8(entry),
                        func_ov001_02184fb8(entry));

    if (data_ov001_021ca41c->mUnk_1080 < 0xf) {
        func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 4), -5);
        func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 5), -5);
        func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 6), -5);
        func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 7), -5);
    } else {
        func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 4), 0);
        func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 5), 0);
        func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 6), 0);
        func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 7), 0);
    }

    if (func_ov001_02181070() && func_ov001_02184ff8(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 0x17)) == 2) {
        func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 0x17), 0);
    }
}
