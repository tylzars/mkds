#include "03/code_021cfa68.h"
#include "03/code_021d0000.h"
#include "03/code_021d010c.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_021453ec.h"

#include "03/code_021d079c.h"
#include "03/unk_021d7000.h"
#include "03/unk_021da000.h"
#include "code_021445e0.h"
#include "03/code_021d06b0.h"
#include "code_0200fd1c.h"
#include "code_02142eac.h"

int func_ov003_021cff38(Unk021425e8Func a, u16 b) {
    return func_0214544c(a, (u16) (3), (u16) (0x11), (u16) (b), (u16) (0x1e));
}

u16 func_ov003_021cfed8(void) {
    int *v1;
    u16 v2;
    if (data_ov003_021da2a8->mUnk_40 != 7) {
        func_0200fd1c();
    }
    func_ov003_021d07b0(1);
    v2 = func_ov003_021cfe40((u32) (data_ov003_021da2a8->mUnk_60));
    v1 = (int *) &data_ov003_021da2a8;
    data_ov003_021da2a8->mUnk_5c = v2;
    if ((UnkFunc *) (*(u32 *) &data_ov003_021da2a4) != (UnkFunc *) 0x0) {
        (*(UnkFunc *) (*(u32 *) &data_ov003_021da2a4))(((u32) 0x08000000u), (u32) &data_ov003_021d7ac8,
                                                       *(u16 *) (*v1 + 0x5c));
    }
    return data_ov003_021da2a8->mUnk_5c;
}

int func_ov003_021cfe40(u16 c) {
    s16 a;
    s16 i;
    u16 b;
    u16 n;
    s16 j;

    a = 0;
    b = 0;
    for (i = 0; i < 16; i++) {
        if ((c & (1 << i)) != 0) {
            a = i + 1;
            b++;
        }
    }
    if (b > 1) {
        data_ov003_021da2a8->mUnk_58 = data_ov003_021da2a8->mUnk_58 * 0x10dcd + 0x3039;
        n = (b * (data_ov003_021da2a8->mUnk_58 & 0xff)) >> 8;
        for (j = 0; j < 16; j++) {
            if ((c & 1) != 0) {
                if (n == 0) {
                    return (s16) (j + 1);
                }
                n--;
            }
            c = c >> 1;
        }
        return 0;
    }
    return a;
}

s32 func_ov003_021cfde4(void) {
    data_ov003_021da2a8->mUnk_12a4 = 0;
    data_ov003_021da2a8->mUnk_12a0 = 0;
    data_ov003_021da2a8->mUnk_48 = 0;
    data_ov003_021da2a8->mUnk_50 = 0;
    data_ov003_021da2a8->mUnk_52 = 1;
    data_ov003_021da2a8->mUnk_54 = 0;
    data_ov003_021da2a8->mUnk_00 = 0;
    data_ov003_021da2a8->mUnk_04 = 0;
    data_ov003_021da2a8->mUnk_4c = 0;
    if (func_ov003_021cfd88() != 0) {
        return 1;
    }
    return 0;
}

void func_ov003_021cfdc8(Unk021425e8 *event) {
    if (event->mUnk_02 == 8) {
        func_ov003_021d07b0(9);
        func_0200fd1c();
    }
}

s32 func_ov003_021cfd88(void) {
    s32 r;
    func_ov003_021d07b0(3);
    r = func_02143e10(data_ov003_021da2a8->mUnk_80, func_ov003_021cfd44, 2);
    if (r != 2) {
        func_ov003_021d079c(r);
        func_ov003_021d07b0(10);
        return 0;
    }
    return 1;
}

void func_ov003_021cfd44(Unk021425e8 *a) {
    if (a->mUnk_02 != 0) {
        func_ov003_021d079c(a->mUnk_02);
        func_ov003_021d07b0(10);
    } else {
        s32 r = func_021435e8(func_ov003_021cfdc8);
        if (r != 0) {
            func_ov003_021d079c(r);
            func_ov003_021d07b0(10);
        } else {
            func_ov003_021d07b0(1);
        }
    }
}

s32 func_ov003_021cfc4c(u32 a, u16 b, u16 c) {
    if (data_ov003_021da2a8->mUnk_40 != 1) {
        func_0200fd1c();
    }
    data_ov003_021da2a8->mUnk_12a4 = 0x180;
    data_ov003_021da2a8->mUnk_12a0 = 0xe0;
    if (data_ov003_021da2a4 != 0) {
        data_ov003_021da2a4(0x08000000, data_ov003_021d7a7c, data_ov003_021da2a8->mUnk_12a4);
    }
    if (data_ov003_021da2a4 != 0) {
        data_ov003_021da2a4(0x08000000, data_ov003_021d7a94, data_ov003_021da2a8->mUnk_12a0);
    }
    data_ov003_021da2a8->mUnk_44 = a;
    func_ov003_021d07b0(3);
    data_ov003_021da2a8->mUnk_0c = b;
    data_ov003_021da2a8->mUnk_32 = c;
    data_ov003_021da2a8->mUnk_18 = func_02143134();
    data_ov003_021da2a8->mUnk_34 = 0xd0;
    data_ov003_021da2a8->mUnk_36 = 0x44;
    data_ov003_021da2a8->mUnk_10 = 2;
    data_ov003_021da2a8->mUnk_16 = 0;
    data_ov003_021da2a8->mUnk_12 = 0;
    data_ov003_021da2a8->mUnk_0e = 1;
    data_ov003_021da2a8->mUnk_14 = a == 2 ? 1 : 0;
    if (a == 0 || a == 2 || a == 4) {
        return func_ov003_021d0760();
    }
    if (data_ov003_021da2a4 != 0) {
        data_ov003_021da2a4(0x08000000, data_ov003_021d7aac, a);
    }
    return 0;
}

void func_ov003_021cfc40(u32 a) {
    *(u32 *) ((int) data_ov003_021da2a8 + 0x4c) = a;
    return;
}

u8 *func_ov003_021cfc1c(u32 a) {
    return func_0214461c(&data_ov003_021da2a8->mUnk_13e0, &data_ov003_021da2a8->mUnk_1c00, a);
}

s32 func_ov003_021cfb98(void *a) {
    s32 r = func_02144c6c(&data_ov003_021da2a8->mUnk_13e0, a, &data_ov003_021da2a8->mUnk_1c00);
    if (r == 7) {
        if (data_ov003_021da2a4 != 0) {
            data_ov003_021da2a4(0x08000000, data_ov003_021d7a18);
        }
        return 0;
    }
    if (r == 5) {
        if (data_ov003_021da2a4 != 0) {
            data_ov003_021da2a4(0x08000000, data_ov003_021d7a48);
        }
        func_ov003_021d079c(r);
        return 0;
    }
    if (r != 0) {
        func_ov003_021d079c(r);
        return 0;
    }
    return 1;
}

void func_ov003_021cfb80(void) {
    int v1;
    v1 = func_ov003_021d0180();
    if (v1 == 0) {
        func_ov003_021d07b0(10);
    }
    return;
}

void func_ov003_021cfaa8(void) {
    s32 a = data_ov003_021da2a8->mUnk_40;
    if (a == 1) {
        if (data_ov003_021da2a4 != 0) {
            data_ov003_021da2a4(0x08000000, data_ov003_021d79d0);
        }
        return;
    }
    if (data_ov003_021da2a4 != 0) {
        data_ov003_021da2a4(0x08000000, data_ov003_021d79f4, a);
    }
    if (data_ov003_021da2a8->mUnk_40 != 6 && data_ov003_021da2a8->mUnk_40 != 5 && data_ov003_021da2a8->mUnk_40 != 4) {
        func_ov003_021d07b0(3);
        func_ov003_021cfb80();
        return;
    }
    func_ov003_021d07b0(3);
    switch (data_ov003_021da2a8->mUnk_44) {
        case 3:
            if (func_ov003_021d0258() == 0) {
                func_ov003_021cfb80();
            }
            break;
        case 1:
        case 5:
            if (func_ov003_021d022c() == 0) {
                func_ov003_021cfb80();
            }
            break;
        case 2:
            if (func_ov003_021d0358() == 0) {
                func_ov003_021cfb80();
            }
            break;
        case 0:
        case 4:
            if (func_ov003_021d032c() == 0) {
                func_ov003_021cfb80();
            }
            break;
    }
}

u32 func_ov003_021cfa68(void) {
    int v1;
    if (data_ov003_021da2a8->mUnk_40 != 1) {
        func_0200fd1c();
    }
    func_ov003_021d07b0(3);
    v1 = func_02143d88((Unk021425e8Func) func_ov003_021d0134);
    if (v1 != 2) {
        func_ov003_021d07b0(9);
        return 0;
    }
    return 1;
}
