#include "Main/Unknown/code_02037a04.h"

#include "Main/Unknown/code_02039774.h"
#include "code_0200f5ac.h"
#include "code_0214a748.h"
#include "Main/Unknown/code_02038000.h"
#include "Main/Unknown/code_02039000.h"
#include "code_0214a5e0.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02175000.h"
#include "code_021488e8.h"
#include "code_02148950.h"
#include "code_02148d34.h"
#include "code_0214a5f0.h"
#include "registers.h"

// Enum-typed parameters of the inlines below: the original reads their values before the register.
typedef enum { UNK_02037ABC_ARG_0 } Unk02037abc_Arg;

// Calls func_0214d05c with v, passed through a stack offset of its own.
static inline void func_02037abc_inline(u32 v, void *p, u32 n) {
    volatile u32 w = v;
    func_0214d05c(w, p, n);
}

// Sets the low two bits of the halfword register r and its bit 6 from the first two halfwords of q.
static inline void func_02037abc_inline2(vu16 *r, Unk021755a0_28 *q) {
    *r = (*r & ~3) | q->mUnk_00;
    if (q->mUnk_02 != 0) {
        *r |= 0x40;
    } else {
        *r &= ~0x40;
    }
}

// Sets bits 4, 20 and 21 of the word register r.
static inline void func_02037abc_inline3(vu32 *r, Unk02037abc_Arg v) {
    *r = (*r & 0xffcfffef) | v;
}

// Sets bits 5, 6 and 22 of the word at 0x04000000.
static inline void func_02037abc_inline4(Unk02037abc_Arg v) {
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffbfff9f) | v;
}

// Sets bits 5 and 6 of the word at 0x04001000.
static inline void func_02037abc_inline5(Unk02037abc_Arg v) {
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x60) | v;
}

// Keeps bits 0, 1 and 6 of the halfword register r and sets the rest from five values.
static inline void func_02037abc_inline6(vu16 *r, Unk02037abc_Arg b, Unk02037abc_Arg c, Unk02037abc_Arg d,
                                         Unk02037abc_Arg e, Unk02037abc_Arg f) {
    *r = (*r & 0x43) | (b << 14) | (c << 7) | (d << 8) | (e << 2) | (f << 13);
}

void func_02037abc(void *a) {
    Unk021755a0 *p;
    Unk021755a0_28 *q;
    u16 v;

    p = a;
    data_021755a0 = p;
    func_02039bd4();
    func_02037abc_inline(0xc0, (void *) 0x07000000, 0x400);
    func_02037abc_inline(0xc0, (void *) 0x07000400, 0x400);
    func_02037abc_inline(0, (void *) 0x05000000, 0x400);
    func_02037abc_inline(0, (void *) 0x05000400, 0x400);
    if (data_021755a0->mUnk_0e != 0) {
        func_02149b20(data_021755a0->mUnk_0e);
    }
    if (data_021755a0->mUnk_10 != 0) {
        func_021499b4(data_021755a0->mUnk_10);
    }
    if (data_021755a0->mUnk_12 != 0) {
        func_021498a0(data_021755a0->mUnk_12);
    }
    if (data_021755a0->mUnk_14 != 0) {
        func_021497e8(data_021755a0->mUnk_14);
    }
    if (data_021755a0->mUnk_16 != 0) {
        func_021495e4(data_021755a0->mUnk_16);
    }
    if (data_021755a0->mUnk_18 != 0) {
        func_021494f0(data_021755a0->mUnk_18);
    }
    if (data_021755a0->mUnk_1a != 0) {
        func_021493b0(data_021755a0->mUnk_1a);
    }
    if (data_021755a0->mUnk_1c != 0) {
        func_0214922c(data_021755a0->mUnk_1c);
    }
    if (data_021755a0->mUnk_1e != 0) {
        func_021491b0(data_021755a0->mUnk_1e);
    }
    if (data_021755a0->mUnk_20 != 0) {
        func_02149124(data_021755a0->mUnk_20);
    }
    if (data_021755a0->mUnk_22 != 0) {
        func_02149098(data_021755a0->mUnk_22);
    }
    if (data_021755a0->mUnk_24 != 0) {
        func_02039b94(data_021755a0->mUnk_24);
    }
    if (data_021755a0->mUnk_26 != 0) {
        func_021492d8(data_021755a0->mUnk_26);
    }
    data_02175614.mUnk_00;
    func_02148950(p->mUnk_06, p->mUnk_08, p->mUnk_0a);
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1f00) | (p->mUnk_02 << 8);
    func_02148934(p->mUnk_0c);
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | (p->mUnk_04 << 8);
    if (p->mUnk_0a == 1) {
        func_0214aa58();
        func_0214a648();
        func_0214a8ec();
        reg_G3X_DISP3DCNT &= 0xffffcffd;
        reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~0x3000) | 0x10;
        reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~0x3000) | 4;
        reg_G3X_ALPHA_TEST_REF = 0;
        reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~0x3000) | 8;
        reg_G2_BLDCNT = 0;
        reg_G3_SWAP_BUFFERS = (p->mUnk_6c->mUnk_03 << 1) | p->mUnk_6c->mUnk_02;
        v = p->mUnk_6c->mUnk_00;
        func_0214a700((u16) (v & 0x7fff), (u8) ((v & 0x8000) >> 15), 0x7fff, 0x3f, 0);
    }
    if (p->mUnk_02 & 1) {
        q = &p->mUnk_28;
        func_02037abc_inline2(&reg_G2_BG0CNT, q);
        if (p->mUnk_0a == 1) {
            func_0214a5e0(0);
        } else {
            reg_G2_BG0OFS = 0;
            func_02037abc_inline6(&reg_G2_BG0CNT, (Unk02037abc_Arg) q->mUnk_04, (Unk02037abc_Arg) q->mUnk_06,
                                  (Unk02037abc_Arg) q->mUnk_08, (Unk02037abc_Arg) q->mUnk_0a,
                                  (Unk02037abc_Arg) q->mUnk_0c);
        }
    }
    if (p->mUnk_04 & 1) {
        reg_G2S_DB_BG0OFS = 0;
        q = &p->mUnk_70;
        func_02037abc_inline2(&reg_G2S_DB_BG0CNT, q);
        func_02037abc_inline6(&reg_G2S_DB_BG0CNT, (Unk02037abc_Arg) q->mUnk_04, (Unk02037abc_Arg) q->mUnk_06,
                              (Unk02037abc_Arg) q->mUnk_08, (Unk02037abc_Arg) q->mUnk_0a, (Unk02037abc_Arg) q->mUnk_0c);
    }
    if (p->mUnk_02 & 2) {
        reg_G2_BG1OFS = 0;
        q = &p->mUnk_38;
        func_02037abc_inline2(&reg_G2_BG1CNT, q);
        func_02037abc_inline6(&reg_G2_BG1CNT, (Unk02037abc_Arg) q->mUnk_04, (Unk02037abc_Arg) q->mUnk_06,
                              (Unk02037abc_Arg) q->mUnk_08, (Unk02037abc_Arg) q->mUnk_0a, (Unk02037abc_Arg) q->mUnk_0c);
    }
    if (p->mUnk_04 & 2) {
        reg_G2S_DB_BG1OFS = 0;
        q = &p->mUnk_80;
        func_02037abc_inline2(&reg_G2S_DB_BG1CNT, q);
        func_02037abc_inline6(&reg_G2S_DB_BG1CNT, (Unk02037abc_Arg) q->mUnk_04, (Unk02037abc_Arg) q->mUnk_06,
                              (Unk02037abc_Arg) q->mUnk_08, (Unk02037abc_Arg) q->mUnk_0a, (Unk02037abc_Arg) q->mUnk_0c);
    }
    if (p->mUnk_02 & 4) {
        func_020386d0(&p->mUnk_48, 1);
    }
    if (p->mUnk_04 & 4) {
        func_020386d0(&p->mUnk_90, 0);
    }
    if (p->mUnk_02 & 8) {
        func_0203810c(&p->mUnk_58, 1);
    }
    if (p->mUnk_04 & 8) {
        func_0203810c(&p->mUnk_a0, 0);
    }
    if (p->mUnk_02 & 0x10) {
        func_02037abc_inline3(&reg_GX_DISPCNT, (Unk02037abc_Arg) p->mUnk_68);
        func_02037abc_inline4((Unk02037abc_Arg) p->mUnk_6a);
    }
    if (p->mUnk_04 & 0x10) {
        func_02037abc_inline3(&reg_GXS_DB_DISPCNT, (Unk02037abc_Arg) p->mUnk_b0);
        func_02037abc_inline5((Unk02037abc_Arg) p->mUnk_b2);
    }
    reg_GX_POWCNT |= 0x8000;
}

void func_02037a94(void) {
    func_02039b24();
    data_021755a0 = NULL;
}

void func_02037a40(void) {
    Unk021755a0 *p;
    u64 t;
    p = data_021755a0;
    t = func_0200f5ac();
    p->mUnk_bc = t;
    if (p->mUnk_0a == 1) {
        func_0214a9d0();
    }
    if (data_usa_02175584 != NULL) {
        data_usa_02175584(0);
    }
}

u32 func_02037a20(void) {
    return (data_021755a0->mUnk_d8 & 2) ? 1 : 0;
}

u32 func_02037a04(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_021755a0;
    value1 = (u32) * (const u32 *) ((value0) + (0));
    value0 = (u32) * (const u8 *) ((value1) + (216));
    value0 = (value0) & ~(1u);
    *(u8 *) ((value1) + (216)) = (u8) value0;
    return value0;
}
