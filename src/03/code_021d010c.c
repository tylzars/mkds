#include "03/code_021d010c.h"

#include "03/code_021d079c.h"
#include "code_02142eac.h"
#include "03/code_021d0000.h"
#include "03/code_021cfa68.h"
#include "03/unk_021da000.h"
#include "code_021445e0.h"
#include "03/unk_021d7000.h"

s32 func_ov003_021d0358(void) {
    s32 result = func_021453b4((Unk021450ec *) ((u8 *) data_ov003_021da2a8 + 0x1e00));
    if (result != 2) {
        func_ov003_021d079c(result);
        return 0;
    }
    return 1;
}

s32 func_ov003_021d032c(void) {
    s32 result;
    func_ov003_021d07b0(3);
    result = func_02143fbc(func_ov003_021d02e8);
    if (result != 2) {
        func_ov003_021d079c(result);
        return 0;
    }
    return 1;
}

void func_ov003_021d02e8(Unk021425e8 *v1) {
    if (v1->mUnk_02 != 0) {
        func_ov003_021d079c(v1->mUnk_02);
        func_ov003_021cfb80();
    } else if (func_ov003_021d02c0() == 0) {
        if (data_ov003_021da2a4 != 0) {
            data_ov003_021da2a4(0x08000000, data_ov003_021d7b18);
        }
        func_ov003_021cfb80();
    }
}

s32 func_ov003_021d02c0(void) {
    s32 result = func_02143b7c(func_ov003_021d02a0);
    if (result != 2) {
        func_ov003_021d079c(result);
        return 0;
    }
    return 1;
}

void func_ov003_021d02a0(Unk021425e8 *event) {
    if (event->mUnk_02 != 0) {
        func_ov003_021d079c(event->mUnk_02);
    } else {
        func_ov003_021d07b0(1);
    }
}

s32 func_ov003_021d0258(void) {
    s32 r;

    if (data_ov003_021da2a8->mUnk_40 != 6) {
        return 0;
    }
    func_ov003_021d07b0(3);
    r = func_021453b4(&data_ov003_021da2a8->mUnk_1e00);
    if (r != 2) {
        func_ov003_021d079c(r);
        return 0;
    }
    return 1;
}

s32 func_ov003_021d022c(void) {
    s32 result;
    func_ov003_021d07b0(3);
    result = func_02143fbc(func_ov003_021d0200);
    if (result != 2) {
        func_ov003_021d079c(result);
        return 0;
    }
    return 1;
}

void func_ov003_021d0200(Unk021425e8 *event) {
    if (event->mUnk_02 != 0) {
        func_ov003_021d079c(event->mUnk_02);
        func_ov003_021cfaa8();
    } else {
        if (func_ov003_021d01cc() == 0) {
            func_ov003_021d07b0(9);
        }
    }
}

s32 func_ov003_021d01cc(void) {
    s32 r;

    func_ov003_021d07b0(3);
    r = func_021436d0(func_ov003_021d01ac, 0);
    if (r != 2) {
        func_ov003_021d079c(r);
        func_ov003_021cfb80();
        return 0;
    }
    return 1;
}

void func_ov003_021d01ac(Unk021425e8 *event) {
    if (event->mUnk_02 != 0) {
        func_ov003_021d079c(event->mUnk_02);
    } else {
        func_ov003_021d07b0(1);
    }
}

s32 func_ov003_021d0180(void) {
    s32 result;
    func_ov003_021d07b0(3);
    result = func_02143dd0(func_ov003_021d0158);
    if (result != 2) {
        func_ov003_021d079c(result);
        return 0;
    }
    return 1;
}

void func_ov003_021d0158(Unk021425e8 *event) {
    if (event->mUnk_02 != 0) {
        func_ov003_021d07b0(9);
        func_ov003_021d079c(event->mUnk_02);
    } else {
        func_ov003_021d07b0(1);
    }
}

void func_ov003_021d0134(int a) {
    if (*(u16 *) (a + 2) != 0) {
        func_ov003_021d07b0((u32) 10);
        return;
    }
    func_ov003_021d07b0((u32) 0);
}

void func_ov003_021d0128(u32 a) {
    data_ov003_021da2a8->mUnk_08 = a;
}

u16 func_ov003_021d0118(void) {
    return data_ov003_021da2a8->mUnk_52;
}

u32 func_ov003_021d010c(void) {
    return (u32) data_ov003_021da2a8->mUnk_40;
}
