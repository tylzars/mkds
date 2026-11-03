#include "Main/Unknown/code_02036c90.h"
#include "Main/Unknown/code_02039000.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_02039044.h"
#include "Main/Unknown/unk_02175000.h"
#include "code_0200eddc.h"
#include "code_0200f5ac.h"
#include "code_0200c894.h"
#include "code_021488e8.h"

void func_02036c90(void) {
    data_021755b4.mUnk_00 = 2;
    data_021755b4.mUnk_02 = 0;
    data_021755b4.mUnk_04 = 0;
    data_021755b4.mUnk_06 = 0;
    data_021755b4.mUnk_08 = 0;
    data_021755a8.mUnk_00 = 2;
    data_021755a8.mUnk_02 = 0;
    data_021755a8.mUnk_04 = 0;
    data_021755a8.mUnk_06 = 0;
    data_021755a8.mUnk_08 = 0;
    func_02148908((u16 *) 0x400006c, data_021755b4.mUnk_08);
    func_02148908((u16 *) 0x400106c, data_021755a8.mUnk_08);
}

u32 func_02036d08(void) {
    if (data_021755b4.mUnk_00 == 0 && data_021755a8.mUnk_00 == 0) {
        return 1;
    }
    return 0;
}

static inline void func_02036d3c_inline(Unk021755a8 *p, s16 a) {
    if (p->mUnk_00 == 0 || (p->mUnk_00 == 3 && p->mUnk_02 == 1)) {
        return;
    }
    p->mUnk_02 = 1;
    if (p->mUnk_00 != 1) {
        p->mUnk_04 = 0;
    } else {
        p->mUnk_04 = (a * p->mUnk_08) / 16;
    }
    p->mUnk_00 = 3;
    p->mUnk_06 = a;
}

void func_02036d3c(s16 a) {
    func_02036d3c_inline(&data_021755b4, a);
    func_02036d3c_inline(&data_021755a8, a);
}

void func_02036e20(s16 a, s32 b) {
    if (b != 0) {
        func_02036d3c_inline(&data_021755b4, a);
    } else {
        func_02036d3c_inline(&data_021755a8, a);
    }
}

static inline void func_02036f10_inline(Unk021755a8 *p, s16 a) {
    if (p->mUnk_00 == 0 || (p->mUnk_00 == 3 && p->mUnk_02 == 0)) {
        return;
    }
    p->mUnk_02 = 0;
    if (p->mUnk_00 != 1) {
        p->mUnk_04 = 0;
    } else {
        p->mUnk_04 = (a * p->mUnk_08) / 16;
    }
    p->mUnk_00 = 3;
    p->mUnk_06 = a;
}

void func_02036f10(s16 a) {
    func_02036f10_inline(&data_021755b4, a);
    func_02036f10_inline(&data_021755a8, a);
}

void func_02036fec(s32 a, s32 b) {
    if (b != 0) {
        func_02036f10_inline(&data_021755b4, a);
    } else {
        func_02036f10_inline(&data_021755a8, a);
    }
}

static inline void func_020370d4_inline(Unk021755a8 *p, s16 a) {
    if (p->mUnk_00 == 2 || p->mUnk_00 == 1) {
        return;
    }
    p->mUnk_02 = 0;
    if (p->mUnk_00 == 2 || p->mUnk_00 == 1) {
        return;
    }
    if (p->mUnk_00 != 3) {
        p->mUnk_04 = 0;
    } else {
        p->mUnk_04 = (a * p->mUnk_08) / 16;
    }
    p->mUnk_00 = 1;
    p->mUnk_06 = a;
}

void func_020370d4(s16 a) {
    func_020370d4_inline(&data_021755b4, a);
    func_020370d4_inline(&data_021755a8, a);
}

void func_020371a8(s32 a, s32 b) {
    if (b != 0) {
        func_020370d4_inline(&data_021755b4, a);
    } else {
        func_020370d4_inline(&data_021755a8, a);
    }
}

static inline void func_02037288_inline(Unk021755a8 *p, s16 a) {
    if (p->mUnk_00 == 2 || p->mUnk_00 == 1) {
        return;
    }
    if (p->mUnk_00 != 3) {
        p->mUnk_04 = 0;
    } else {
        p->mUnk_04 = (a * p->mUnk_08) / 16;
    }
    p->mUnk_00 = 1;
    p->mUnk_06 = a;
}

void func_02037288(s16 a) {
    func_02037288_inline(&data_021755b4, a);
    func_02037288_inline(&data_021755a8, a);
}

void func_02037334(s16 a, s32 b) {
    if (b != 0) {
        func_02037288_inline(&data_021755b4, a);
    } else {
        func_02037288_inline(&data_021755a8, a);
    }
}

void func_020373ec(void) {
    u64 t;
    Unk021755a0 *p;
    t = func_0200f5ac();
    if (data_usa_02175584 != NULL) {
        data_usa_02175584(3);
    }
    p = data_021755a0;
    p->mUnk_d0 = (t - p->mUnk_c4) * 0xfa00 / 0x82ea;
    p = data_021755a0;
    p->mUnk_d4 = (t - p->mUnk_bc) * 0xfa00 / 0x82ea;
}

void func_02037498(s32 a) {
    Unk021755a0 *p;
    u64 t;
    s16 c;
    s16 d;
    u16 i;
    c = data_021755b4.mUnk_08;
    d = data_021755a8.mUnk_08;
    if (data_usa_02175584 != NULL) {
        data_usa_02175584(1);
    }
    func_020390f0(&data_021755b4);
    func_020390f0(&data_021755a8);
    func_0200eddc();
    if ((data_021755a0->mUnk_d8 & 1) == 0) {
        data_021755a0->mUnk_d8 |= 2;
    } else {
        data_021755a0->mUnk_d8 &= ~2;
        data_021755a0->mUnk_d8 &= ~1;
    }
    p = data_021755a0;
    if (p->mUnk_0a == 1 && a != 0) {
        *(vu32 *) 0x4000540 = (p->mUnk_6c->mUnk_03 << 1) | p->mUnk_6c->mUnk_02;
    }
    p = data_021755a0;
    t = func_0200f5ac();
    p->mUnk_cc = (t - p->mUnk_bc) * 0xfa00 / 0x82ea;
    for (i = 0; i < data_021755a0->mUnk_00; i++) {
        func_0200c894(1, 1);
    }
    data_021755a0->mUnk_d8 |= 1;
    data_021755a0->mUnk_c4 = func_0200f5ac();
    if (c != data_021755b4.mUnk_08) {
        func_02148908((u16 *) 0x400006c, data_021755b4.mUnk_08);
    }
    if (d != data_021755a8.mUnk_08) {
        func_02148908((u16 *) 0x400106c, data_021755a8.mUnk_08);
    }
    if (data_usa_02175584 != NULL) {
        data_usa_02175584(2);
    }
}

void func_02037658(s32 a) {
    u64 t;
    s16 c;
    s16 d;
    u16 i;
    BOOL e;
    Unk021755a0 *p;
    c = data_021755b4.mUnk_08;
    d = data_021755a8.mUnk_08;
    if (data_usa_02175584 != NULL) {
        data_usa_02175584(1);
    }
    func_020390f0(&data_021755b4);
    func_020390f0(&data_021755a8);
    func_0200eddc();
    if ((data_021755a0->mUnk_d8 & 1) == 0) {
        data_021755a0->mUnk_d8 |= 2;
    } else {
        data_021755a0->mUnk_d8 &= ~2;
        data_021755a0->mUnk_d8 &= ~1;
    }
    if (a == 0 || (data_021755a0->mUnk_d8 & 2) == 0) {
        e = TRUE;
    } else {
        e = FALSE;
    }
    p = data_021755a0;
    if (p->mUnk_0a == 1 && e != FALSE) {
        *(vu32 *) 0x4000540 = (p->mUnk_6c->mUnk_03 << 1) | p->mUnk_6c->mUnk_02;
    }
    p = data_021755a0;
    t = func_0200f5ac();
    p->mUnk_cc = (t - p->mUnk_bc) * 0xfa00 / 0x82ea;
    if (e != FALSE) {
        for (i = 0; i < data_021755a0->mUnk_00; i++) {
            func_0200c894(1, 1);
        }
    }
    data_021755a0->mUnk_d8 |= 1;
    data_021755a0->mUnk_c4 = func_0200f5ac();
    if (c != data_021755b4.mUnk_08) {
        func_02148908((u16 *) 0x400006c, data_021755b4.mUnk_08);
    }
    if (d != data_021755a8.mUnk_08) {
        func_02148908((u16 *) 0x400106c, data_021755a8.mUnk_08);
    }
    if (data_usa_02175584 != NULL) {
        data_usa_02175584(2);
    }
}

void func_02037850(void) {
    Unk021755a0 *p;
    u64 t;
    s16 c;
    s16 d;
    u16 i;
    c = data_021755b4.mUnk_08;
    d = data_021755a8.mUnk_08;
    if (data_usa_02175584 != NULL) {
        data_usa_02175584(1);
    }
    func_020390f0(&data_021755b4);
    func_020390f0(&data_021755a8);
    func_0200eddc();
    p = data_021755a0;
    if (p->mUnk_0a == 1) {
        *(vu32 *) 0x4000540 = (p->mUnk_6c->mUnk_03 << 1) | p->mUnk_6c->mUnk_02;
    }
    if ((data_021755a0->mUnk_d8 & 1) == 0) {
        data_021755a0->mUnk_d8 |= 2;
    } else {
        data_021755a0->mUnk_d8 &= ~2;
        data_021755a0->mUnk_d8 &= ~1;
    }
    p = data_021755a0;
    t = func_0200f5ac();
    p->mUnk_cc = (t - p->mUnk_bc) * 0xfa00 / 0x82ea;
    for (i = 0; i < data_021755a0->mUnk_00; i++) {
        func_0200c894(1, 1);
    }
    data_021755a0->mUnk_d8 |= 1;
    data_021755a0->mUnk_c4 = func_0200f5ac();
    if (c != data_021755b4.mUnk_08) {
        func_02148908((u16 *) 0x400006c, data_021755b4.mUnk_08);
    }
    if (d != data_021755a8.mUnk_08) {
        func_02148908((u16 *) 0x400106c, data_021755a8.mUnk_08);
    }
    if (data_usa_02175584 != NULL) {
        data_usa_02175584(2);
    }
}
