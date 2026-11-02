#include "03/code_021d0388.h"
#include "03/code_021d079c.h"
#include "03/unk_021d7000.h"
#include "03/unk_021da000.h"
#include "code_021445e0.h"
#include "code_02142eac.h"

s32 func_ov003_021d0388(void) {
    s32 r;

    func_ov003_021d07b0(6);
    r = func_021453c0(&data_ov003_021da2a8->mUnk_1e00, 0xd);
    if (r != 2) {
        func_ov003_021d079c(r);
        return 0;
    }
    return 1;
}

void func_ov003_021d03c0(Unk021425e8 *v1) {
    s32 r;

    if (v1->mUnk_02 != 0) {
        func_ov003_021d079c(v1->mUnk_02);
        func_ov003_021d07b0(9);
        return;
    }
    switch (v1->mUnk_04) {
        case 0xa:
            if (data_ov003_021da2a8->mUnk_44 == 2) {
                if (data_ov003_021da2a8->mUnk_40 == 4) {
                    if (func_ov003_021d0388() != 0) {
                        return;
                    }
                    if (data_ov003_021da2a4 != 0) {
                        data_ov003_021da2a4(0x08000000, data_ov003_021d7b40);
                    }
                    func_ov003_021d07b0(9);
                    return;
                }
                if (data_ov003_021da2a8->mUnk_40 == 6) {
                    return;
                }
            } else if (data_ov003_021da2a8->mUnk_44 == 4) {
                r = func_021450ec(&data_ov003_021da2a8->mUnk_13e0, 0xd, 7, 0x44, 1);
                if (r != 0) {
                    func_ov003_021d079c(r);
                    func_ov003_021d07b0(9);
                    return;
                }
                func_ov003_021d07b0(5);
                return;
            }
            func_ov003_021d07b0(4);
            return;
        case 0xb:
            break;
        case 0xc:
        case 0xd:
        default:
            if (data_ov003_021da2a4 != 0) {
                data_ov003_021da2a4(0x08000000, data_ov003_021d7af8, v1->mUnk_04);
            }
            break;
    }
}

s32 func_ov003_021d04a8(void) {
    s32 r;

    if ((u32) (data_ov003_021da2a8->mUnk_40 - 4) <= 2) {
        return 1;
    }
    func_ov003_021d07b0(4);
    r = func_02144230(func_ov003_021d03c0, (u32) data_ov003_021da2a8->mUnk_1060, (u16) data_ov003_021da2a8->mUnk_12a4,
                      (u32) data_ov003_021da2a8->mUnk_f80, (u16) data_ov003_021da2a8->mUnk_12a0, 1, 0, 0, 0, 0, 0);
    if (r != 2) {
        func_ov003_021d079c(r);
        return 0;
    }
    return 1;
}

void func_ov003_021d0530(Unk021425e8 *v1) {
    u16 v2;
    s32 r;

    v2 = 1 << v1->mUnk_10;
    if (v1->mUnk_02 != 0) {
        func_ov003_021d079c(v1->mUnk_02);
        func_ov003_021d07b0(9);
        return;
    }
    switch (v1->mUnk_08_0) {
        case 7:
            if (data_ov003_021da2a4 != 0) {
                data_ov003_021da2a4(0x08000000, data_ov003_021d7b70, v1->mUnk_10);
            }
            if (data_ov003_021da2a8->mUnk_4c != 0 && data_ov003_021da2a8->mUnk_4c(v1) == 0) {
                r = func_021436d0(0, v1->mUnk_10);
                if (r == 2) {
                    return;
                }
                func_ov003_021d079c(r);
                func_ov003_021d07b0(9);
                return;
            }
            data_ov003_021da2a8->mUnk_52 = data_ov003_021da2a8->mUnk_52 | v2;
            return;
        case 9:
            if (data_ov003_021da2a4 != 0) {
                data_ov003_021da2a4(0x08000000, data_ov003_021d7b9c, v1->mUnk_10);
            }
            data_ov003_021da2a8->mUnk_52 = data_ov003_021da2a8->mUnk_52 & ~v2;
            return;
        case 0:
            if (func_ov003_021d04a8() == 0) {
                func_ov003_021d07b0(9);
            }
            return;
        case 2:
            return;
        default:
            if (data_ov003_021da2a4 != 0) {
                data_ov003_021da2a4(0x08000000, data_ov003_021d7af8, v1->mUnk_08_0);
            }
            return;
    }
}

s32 func_ov003_021d0630(void) {
    s32 r;

    if ((u32) (data_ov003_021da2a8->mUnk_40 - 4) <= 2) {
        return 1;
    }
    r = func_02143bc4(func_ov003_021d0530);
    if (r != 2) {
        func_ov003_021d079c(r);
        return 0;
    }
    data_ov003_021da2a8->mUnk_50 = 0;
    data_ov003_021da2a8->mUnk_52 = 1;
    return 1;
}
