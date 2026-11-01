#include "Main/Unknown/code_020b3728.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/code_02089000.h"
#include "Main/Unknown/code_020b3b08.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020c7000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b35c.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"

void func_020b3728(void) {
    Unk021759c0 *d;
    s32 a;
    s32 b;
    s32 f;
    u16 i;

    if (data_0217561c->mUnk_4cc != 0 && data_0217b35c->mUnk_0c == 0) {
        func_020b3cd8();
        func_020b3b58();
        func_0205eeb0();
        data_0217b35c->mUnk_0c = 1;
    }
    i = func_020b4d9c();
    if (data_0217561c->mUnk_000[i].mUnk_14 != 1 && data_0217561c->mUnk_4cc == 0) {
        return;
    }
    a = data_0217b35c->mUnk_00;
    if (a < 11) {
        data_0217b35c->mUnk_00 = a + 1;
        if (a == 0) {
            d = data_021759c0;
            switch (d->mUnk_08) {
                case 0:
                case 1:
                    func_02089ef4(3);
                    break;
                case 3:
                case 5:
                    if (d->mUnk_1c != 1) {
                        if (data_0217561c->mUnk_000[func_020b4d9c()].mUnk_14 == 1) {
                            func_02089ef4(3);
                        }
                    }
                    break;
            }
            if ((u32) (data_0217d084.mUnk_04 - 2) <= 1 && data_021759c0->mUnk_08 != 2) {
                d = data_021759c0;
                f = 1;
                if (d->mUnk_00c == 1) {
                    f = 0;
                } else if (d->mUnk_08 == 4) {
                    switch (d->mUnk_2f) {
                        case 2:
                        case 4:
                        case 6:
                        case 10:
                            if ((func_0203c880((u16) d->mUnk_62) ? data_0217561c->mUnk_4e0 : 6) != 0) {
                                f = 0;
                            }
                            break;
                        default:
                            f = 0;
                            break;
                    }
                }
                if (f != 0) {
                    if (func_020c7148() != 0 || func_020c70ec() != 0) {
                        func_0212ecc0(&data_0217d068, 0, 0x44);
                    } else {
                        b = data_0217561c->mUnk_000[func_020b4d9c()].mUnk_14;
                        if (b == 3) {
                            func_0212ecc0(&data_0217d068, 0, 0x43);
                        } else {
                            func_0212ecc0(&data_0217d068, 0, 0x42);
                        }
                    }
                }
            }
        } else if (a == 10) {
            d = data_021759c0;
            switch (d->mUnk_08) {
                case 3:
                    if (d->mUnk_1c == 1) {
                        func_02089ef4((func_0207a974(d->mUnk_62)->mUnk_7c & 0x2000000) ? 4 : 5);
                    }
                    break;
                case 2:
                    func_02089ef4((func_0207a974(d->mUnk_62)->mUnk_7c & 0x2000000) ? 4 : 5);
                    break;
                case 4:
                    if ((func_0203c880((u16) d->mUnk_62) ? data_0217561c->mUnk_4e0 : 6) != 0) {
                        func_02089ef4(7);
                    }
                    break;
                case 0:
                case 1:
                case 5:
                    break;
            }
        }
    }
    if (data_0217b35c->mUnk_04 == 0) {
        return;
    }
    a = data_0217b35c->mUnk_08;
    data_0217b35c->mUnk_08 = a + 1;
    if (a != 10) {
        return;
    }
    d = data_021759c0;
    switch (d->mUnk_08) {
        case 4:
            if ((func_0203c880((u16) d->mUnk_62) ? data_0217561c->mUnk_4e0 : 6) == 0) {
                func_02089ef4(6);
            }
            break;
        case 0:
        case 1:
        case 2:
        case 3:
        case 5:
            break;
    }
    data_0217b35c->mUnk_04 = 0;
}
