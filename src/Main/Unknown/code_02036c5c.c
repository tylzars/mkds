#include "Main/Unknown/code_02036c5c.h"

#include "Main/Unknown/code_02039000.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/unk_02175000.h"
#include "code_0200eddc.h"
#include "code_0200f5ac.h"
#include "code_0200c894.h"
#include "code_021488e8.h"
#include "Main/Unknown/code_02039774.h"
#include "code_0214a748.h"
#include "Main/Unknown/code_02038000.h"
#include "code_0214a5e0.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_02148950.h"
#include "code_0214a5f0.h"
#include "code_0214d018.h"
#include "registers.h"
#include "code_0214a390.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02036820.h"

void func_020390f0(Unk021755a8 *a) {
    switch (a->mUnk_00) {
        case 0:
            break;
        case 1:
            a->mUnk_04++;
            if (a->mUnk_04 >= a->mUnk_06) {
                a->mUnk_00 = 2;
                a->mUnk_08 = 0;
            } else {
                a->mUnk_08 = 0x10 - (a->mUnk_04 << 4) / a->mUnk_06;
            }
            if (a->mUnk_02 == 0) {
                a->mUnk_08 = -a->mUnk_08;
            }
            break;
        case 2:
            a->mUnk_08 = 0;
            break;
        case 3:
            a->mUnk_04++;
            if (a->mUnk_04 >= a->mUnk_06) {
                a->mUnk_00 = 0;
                a->mUnk_08 = 0x10;
            } else {
                a->mUnk_08 = (a->mUnk_04 << 4) / a->mUnk_06;
            }
            if (a->mUnk_02 == 0) {
                a->mUnk_08 = -a->mUnk_08;
            }
            break;
    }
}

void func_0203907c(void) {
    data_021755b4.mUnk_00 = 0;
    data_021755b4.mUnk_02 = 1;
    data_021755b4.mUnk_04 = 0;
    data_021755b4.mUnk_06 = 0;
    data_021755b4.mUnk_08 = 0x10;
    data_021755a8.mUnk_00 = 0;
    data_021755a8.mUnk_02 = 1;
    data_021755a8.mUnk_04 = 0;
    data_021755a8.mUnk_06 = 0;
    data_021755a8.mUnk_08 = 0x10;
    GXx_SetMasterBrightness_((u16 *) 0x400006c, data_021755b4.mUnk_08);
    GXx_SetMasterBrightness_((u16 *) 0x400106c, data_021755a8.mUnk_08);
}

void func_02039044(void) {
    InterruptClearAndWait(1, 1);
    GX_DispOn();
    *(vu32 *) 0x4001000 = *(vu32 *) 0x4001000 | 0x10000;
}

void func_02038e6c(void *a, u32 b) {
    Unk02038e6c *p = a;
    u32 c;
    p->mUnk_00 = 0;
    p->mUnk_02 = 0;
    p->mUnk_04 = 0;
    p->mUnk_06 = 0;
    p->mUnk_08 = 0;
    p->mUnk_0a = 0;
    p->mUnk_0c = 0;
    p->mUnk_10 = 1;
    p->mUnk_14 = 0;
    p->mUnk_16 = 0;
    p->mUnk_12 = 0;
    p->mUnk_18 = 0;
    p->mUnk_1a = 0;
    p->mUnk_1c = 0;
    c = 6;
    switch (b) {
        case 0:
        case 1:
        case 3:
            c = 1;
            break;
        case 2:
        case 4:
            c = 2;
            break;
        case 5:
            c = 3;
            break;
        case 6:
            break;
    }
    p->mUnk_20 = c;
    switch (c) {
        case 1:
            p->mUnk_24 = 2;
            p->mUnk_28 = 0;
            p->mUnk_2a = 0;
            p->mUnk_26 = 0;
            p->mUnk_2c = 0;
            p->mUnk_2e = 0;
            break;
        case 2:
            p->mUnk_24 = 2;
            p->mUnk_28 = 0;
            p->mUnk_26 = 0;
            p->mUnk_2a = 0;
            p->mUnk_2c = 0;
            p->mUnk_2e = 0;
            break;
        case 3:
            p->mUnk_24 = 2;
            p->mUnk_26 = 0;
            p->mUnk_28 = 0;
            p->mUnk_2a = 0;
            p->mUnk_2c = 0;
            break;
    }
    c = 6;
    switch (b) {
        case 0:
            c = 1;
            break;
        case 1:
        case 2:
            c = 2;
            break;
        case 3:
        case 4:
        case 5:
            c = 3;
            break;
        case 6:
            break;
    }
    p->mUnk_30 = c;
    switch (c) {
        case 1:
            p->mUnk_34 = 2;
            p->mUnk_38 = 0;
            p->mUnk_3a = 0;
            p->mUnk_36 = 0;
            p->mUnk_3c = 0;
            p->mUnk_3e = 0;
            break;
        case 2:
            p->mUnk_34 = 2;
            p->mUnk_38 = 0;
            p->mUnk_36 = 0;
            p->mUnk_3a = 0;
            p->mUnk_3c = 0;
            p->mUnk_3e = 0;
            break;
        case 3:
            p->mUnk_34 = 2;
            p->mUnk_36 = 0;
            p->mUnk_38 = 0;
            p->mUnk_3a = 0;
            p->mUnk_3c = 0;
            break;
    }
    p->mUnk_40 = 0;
    p->mUnk_42 = 0;
}

void func_02038de4(Unk021755a0 *a, void *b) {
    Unk02038de4 *c = b;
    *(Unk02038de4 *) a = *c;
    func_02038e6c(&a->mUnk_28, c->mUnk_08);
    func_02038e6c(&a->mUnk_70, c->mUnk_0c);
    a->mUnk_6c = NULL;
    a->mUnk_bc = 0;
    a->mUnk_c4 = 0;
    a->mUnk_cc = 0;
    a->mUnk_d0 = 0;
    a->mUnk_d4 = 0;
    a->mUnk_b4 = 0;
    a->mUnk_b8 = NULL;
    a->mUnk_d8 = 0;
}

void *func_02038d88(void *a, void *b) {
    Unk021755a0 *p = HeapAlloc(a, 0xdc);
    Unk021755a0_6c *q;
    func_02038de4(p, b);
    if (p->mUnk_0a == 1) {
        q = HeapAlloc(a, 8);
        q->mUnk_00 = 0x5000;
        q->mUnk_02 = 1;
        q->mUnk_03 = 1;
        p->mUnk_6c = q;
    }
    return p;
}

void func_02038d58(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h) {
    Unk02038e6c *p = a;
    p->mUnk_00 = b;
    p->mUnk_04 = d;
    p->mUnk_06 = e;
    p->mUnk_02 = c;
    p->mUnk_08 = f;
    p->mUnk_0a = g;
    p->mUnk_0c = h;
}

void func_02038d28(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h) {
    Unk02038e6c *p = a;
    p->mUnk_10 = b;
    p->mUnk_14 = d;
    p->mUnk_16 = e;
    p->mUnk_12 = c;
    p->mUnk_18 = f;
    p->mUnk_1a = g;
    p->mUnk_1c = h;
}

void func_02038d00(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    Unk02038e6c *p = a;
    p->mUnk_24 = b;
    p->mUnk_26 = c;
    p->mUnk_28 = d;
    p->mUnk_2a = e;
    p->mUnk_2c = f;
    p->mUnk_2e = g;
}

void func_02038cd8(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    Unk02038e6c *p = a;
    p->mUnk_34 = b;
    p->mUnk_36 = c;
    p->mUnk_38 = d;
    p->mUnk_3a = e;
    p->mUnk_3c = f;
    p->mUnk_3e = g;
}

void func_02038cb0(void *a, u32 b, u32 c, u32 d, u32 e, u32 f) {
    Unk02038e6c *p = a;
    p->mUnk_20 = 5;
    p->mUnk_24 = b;
    p->mUnk_26 = c;
    p->mUnk_28 = d;
    p->mUnk_2a = e;
    p->mUnk_2c = f;
}

u32 func_02038c9c(Unk021755a0 *arg0, u32 arg1, u32 arg2) {
    u32 value0 = (u32) arg0;
    u32 value1 = arg1;
    u32 value2 = arg2;
    u32 value3;
    value3 = (u32) * (const u32 *) ((value0) + (108));
    arg0->mUnk_6c->mUnk_02 = (u8) value1;
    value0 = (u32) * (const u32 *) ((value0) + (108));
    *(u8 *) ((value0) + (3)) = (u8) value2;
    return value0;
}

void func_02038c94(Unk021755a0 *p0, u32 p1) {
    p0->mUnk_b2 = (u16) p1;
}

// Enum-typed parameters of the inlines below: the original reads their values before the register.
typedef enum { UNK_0203810C_ARG_0 } Unk0203810c_Arg;

// Sets the low two bits of the halfword register r and its bit 6 from the first two halfwords of q.
static inline void func_0203810c_inline(vu16 *r, Unk0203810c_04 *q) {
    *r = (*r & ~3) | q->mUnk_00;
    if (q->mUnk_02 != 0) {
        *r |= 0x40;
    } else {
        *r &= ~0x40;
    }
}

// Keeps bits 0, 1 and 6 of the halfword register r and sets the rest from four values.
static inline void func_0203810c_inline2(vu16 *r, Unk0203810c_Arg b, Unk0203810c_Arg c, Unk0203810c_Arg d,
                                         Unk0203810c_Arg e) {
    *r = (*r & 0x43) | (b << 14) | (c << 7) | (d << 8) | (e << 2);
}

// Keeps bits 0, 1 and 6 of the halfword register r and sets the rest from four values.
static inline void func_0203810c_inline3(vu16 *r, Unk0203810c_Arg b, Unk0203810c_Arg c, Unk0203810c_Arg d,
                                         Unk0203810c_Arg e) {
    *r = (*r & 0x43) | (b << 14) | (c << 8) | (d << 2) | (e << 13);
}

// Keeps bits 0, 1 and 6 of the halfword register r and sets the rest from three values.
static inline void func_0203810c_inline4(vu16 *r, Unk0203810c_Arg b, Unk0203810c_Arg c, Unk0203810c_Arg d) {
    *r = (*r & 0x43) | (b << 14) | (d << 8) | (c << 13);
}

// Keeps bits 0, 1 and 6 of the halfword register r, sets bit 7 and the rest from three values.
static inline void func_0203810c_inline5(vu16 *r, Unk0203810c_Arg b, Unk0203810c_Arg c, Unk0203810c_Arg d) {
    *r = (*r & 0x43) | (b << 14) | 0x80 | (d << 8) | (c << 13);
}

// Keeps bits 0, 1 and 6 of the halfword register r, sets bits 2 and 7 and the rest from three values.
static inline void func_0203810c_inline6(vu16 *r, Unk0203810c_Arg b, Unk0203810c_Arg c, Unk0203810c_Arg d) {
    *r = (*r & 0x43) | (b << 14) | 0x84 | (d << 8) | (c << 13);
}

// Sets the low two bits of the halfword register r and its bit 6 from the first two halfwords of q.
static inline void func_020386d0_inline(vu16 *r, Unk0203810c_04 *q) {
    *r = (*r & ~3) | q->mUnk_00;
    if (q->mUnk_02 != 0) {
        *r |= 0x40;
    } else {
        *r &= ~0x40;
    }
}

// Keeps bits 0, 1 and 6 of the halfword register r and sets the rest from four values.
static inline void func_020386d0_inline2(vu16 *r, Unk0203810c_Arg b, Unk0203810c_Arg c, Unk0203810c_Arg d,
                                         Unk0203810c_Arg e) {
    *r = (*r & 0x43) | (b << 14) | (c << 7) | (d << 8) | (e << 2);
}

// Keeps bits 0, 1 and 6 of the halfword register r and sets the rest from four values.
static inline void func_020386d0_inline3(vu16 *r, Unk0203810c_Arg b, Unk0203810c_Arg c, Unk0203810c_Arg d,
                                         Unk0203810c_Arg e) {
    *r = (*r & 0x43) | (b << 14) | (c << 8) | (d << 2) | (e << 13);
}

// Keeps bits 0, 1 and 6 of the halfword register r and sets the rest from three values.
static inline void func_020386d0_inline4(vu16 *r, Unk0203810c_Arg b, Unk0203810c_Arg c, Unk0203810c_Arg d) {
    *r = (*r & 0x43) | (b << 14) | (d << 8) | (c << 13);
}

// Keeps bits 0, 1 and 6 of the halfword register r, sets bit 7 and the rest from three values.
static inline void func_020386d0_inline5(vu16 *r, Unk0203810c_Arg b, Unk0203810c_Arg c, Unk0203810c_Arg d) {
    *r = (*r & 0x43) | (b << 14) | 0x80 | (d << 8) | (c << 13);
}

// Keeps bits 0, 1 and 6 of the halfword register r, sets bits 2 and 7 and the rest from three values.
static inline void func_020386d0_inline6(vu16 *r, Unk0203810c_Arg b, Unk0203810c_Arg c, Unk0203810c_Arg d) {
    *r = (*r & 0x43) | (b << 14) | 0x84 | (d << 8) | (c << 13);
}

void func_020386d0(Unk0203810c *a, s32 b) {
    s32 m[4];
    Unk0203810c_04 *q;

    m[1] = 0;
    m[2] = 0;
    m[0] = 0x1000;
    m[3] = 0x1000;
    q = &a->mUnk_04;
    switch (a->mUnk_00) {
        case 1:
            if (b != 0) {
                reg_G2_BG2OFS = 0;
                func_020386d0_inline((vu16 *) 0x0400000c, q);
                func_020386d0_inline2((vu16 *) 0x0400000c, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_06,
                                      (Unk0203810c_Arg) q->mUnk_08, (Unk0203810c_Arg) q->mUnk_0a);
            } else {
                reg_G2S_DB_BG2OFS = 0;
                func_020386d0_inline((vu16 *) 0x0400100c, q);
                func_020386d0_inline2((vu16 *) 0x0400100c, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_06,
                                      (Unk0203810c_Arg) q->mUnk_08, (Unk0203810c_Arg) q->mUnk_0a);
            }
            break;
        case 2:
            if (b != 0) {
                func_0214a428((u32 *) 0x04000020, m, 0, 0, 0, 0);
                func_020386d0_inline((vu16 *) 0x0400000c, q);
                func_020386d0_inline3((vu16 *) 0x0400000c, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_08,
                                      (Unk0203810c_Arg) q->mUnk_0a, (Unk0203810c_Arg) q->mUnk_06);
            } else {
                func_0214a428((u32 *) 0x04001020, m, 0, 0, 0, 0);
                func_020386d0_inline((vu16 *) 0x0400100c, q);
                func_020386d0_inline3((vu16 *) 0x0400100c, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_08,
                                      (Unk0203810c_Arg) q->mUnk_0a, (Unk0203810c_Arg) q->mUnk_06);
            }
            break;
        case 3:
            if (b != 0) {
                func_0214a428((u32 *) 0x04000020, m, 0, 0, 0, 0);
                func_020386d0_inline((vu16 *) 0x0400000c, q);
                func_020386d0_inline4((vu16 *) 0x0400000c, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_06,
                                      (Unk0203810c_Arg) q->mUnk_08);
            } else {
                func_0214a428((u32 *) 0x04001020, m, 0, 0, 0, 0);
                func_020386d0_inline((vu16 *) 0x0400100c, q);
                func_020386d0_inline4((vu16 *) 0x0400100c, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_06,
                                      (Unk0203810c_Arg) q->mUnk_08);
            }
            break;
        case 4:
            if (b != 0) {
                func_0214a428((u32 *) 0x04000020, m, 0, 0, 0, 0);
                func_020386d0_inline((vu16 *) 0x0400000c, q);
                func_020386d0_inline5((vu16 *) 0x0400000c, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_06,
                                      (Unk0203810c_Arg) q->mUnk_08);
            } else {
                func_0214a428((u32 *) 0x04001020, m, 0, 0, 0, 0);
                func_020386d0_inline((vu16 *) 0x0400100c, q);
                func_020386d0_inline5((vu16 *) 0x0400100c, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_06,
                                      (Unk0203810c_Arg) q->mUnk_08);
            }
            break;
        case 5:
            if (b != 0) {
                func_0214a428((u32 *) 0x04000020, m, 0, 0, 0, 0);
                func_020386d0_inline((vu16 *) 0x0400000c, q);
                func_020386d0_inline6((vu16 *) 0x0400000c, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_06,
                                      (Unk0203810c_Arg) q->mUnk_08);
            } else {
                func_0214a428((u32 *) 0x04001020, m, 0, 0, 0, 0);
                func_020386d0_inline((vu16 *) 0x0400100c, q);
                func_020386d0_inline6((vu16 *) 0x0400100c, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_06,
                                      (Unk0203810c_Arg) q->mUnk_08);
            }
            break;
        default:
            break;
    }
}

void func_0203810c(Unk0203810c *a, s32 b) {
    s32 m[4];
    Unk0203810c_04 *q;

    m[1] = 0;
    m[2] = 0;
    m[0] = 0x1000;
    m[3] = 0x1000;
    q = &a->mUnk_04;
    switch (a->mUnk_00) {
        case 1:
            if (b != 0) {
                reg_G2_BG3OFS = 0;
                func_0203810c_inline((vu16 *) 0x0400000e, q);
                func_0203810c_inline2((vu16 *) 0x0400000e, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_06,
                                      (Unk0203810c_Arg) q->mUnk_08, (Unk0203810c_Arg) q->mUnk_0a);
            } else {
                reg_G2S_DB_BG3OFS = 0;
                func_0203810c_inline((vu16 *) 0x0400100e, q);
                func_0203810c_inline2((vu16 *) 0x0400100e, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_06,
                                      (Unk0203810c_Arg) q->mUnk_08, (Unk0203810c_Arg) q->mUnk_0a);
            }
            break;
        case 2:
            if (b != 0) {
                func_0214a428((u32 *) 0x04000030, m, 0, 0, 0, 0);
                func_0203810c_inline((vu16 *) 0x0400000e, q);
                func_0203810c_inline3((vu16 *) 0x0400000e, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_08,
                                      (Unk0203810c_Arg) q->mUnk_0a, (Unk0203810c_Arg) q->mUnk_06);
            } else {
                func_0214a428((u32 *) 0x04001030, m, 0, 0, 0, 0);
                func_0203810c_inline((vu16 *) 0x0400100e, q);
                func_0203810c_inline3((vu16 *) 0x0400100e, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_08,
                                      (Unk0203810c_Arg) q->mUnk_0a, (Unk0203810c_Arg) q->mUnk_06);
            }
            break;
        case 3:
            if (b != 0) {
                func_0214a428((u32 *) 0x04000030, m, 0, 0, 0, 0);
                func_0203810c_inline((vu16 *) 0x0400000e, q);
                func_0203810c_inline4((vu16 *) 0x0400000e, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_06,
                                      (Unk0203810c_Arg) q->mUnk_08);
            } else {
                func_0214a428((u32 *) 0x04001030, m, 0, 0, 0, 0);
                func_0203810c_inline((vu16 *) 0x0400100e, q);
                func_0203810c_inline4((vu16 *) 0x0400100e, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_06,
                                      (Unk0203810c_Arg) q->mUnk_08);
            }
            break;
        case 4:
            if (b != 0) {
                func_0214a428((u32 *) 0x04000030, m, 0, 0, 0, 0);
                func_0203810c_inline((vu16 *) 0x0400000e, q);
                func_0203810c_inline5((vu16 *) 0x0400000e, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_06,
                                      (Unk0203810c_Arg) q->mUnk_08);
            } else {
                func_0214a428((u32 *) 0x04001030, m, 0, 0, 0, 0);
                func_0203810c_inline((vu16 *) 0x0400100e, q);
                func_0203810c_inline5((vu16 *) 0x0400100e, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_06,
                                      (Unk0203810c_Arg) q->mUnk_08);
            }
            break;
        case 5:
            if (b != 0) {
                func_0214a428((u32 *) 0x04000030, m, 0, 0, 0, 0);
                func_0203810c_inline((vu16 *) 0x0400000e, q);
                func_0203810c_inline6((vu16 *) 0x0400000e, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_06,
                                      (Unk0203810c_Arg) q->mUnk_08);
            } else {
                func_0214a428((u32 *) 0x04001030, m, 0, 0, 0, 0);
                func_0203810c_inline((vu16 *) 0x0400100e, q);
                func_0203810c_inline6((vu16 *) 0x0400100e, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_06,
                                      (Unk0203810c_Arg) q->mUnk_08);
            }
            break;
        default:
            break;
    }
}

// Enum-typed parameters of the inlines below: the original reads their values before the register.
typedef enum { UNK_02037ABC_ARG_0 } Unk02037abc_Arg;

// Calls MIi_CpuClearFast with v, passed through a stack offset of its own.
static inline void func_02037abc_inline(u32 v, void *p, u32 n) {
    volatile u32 w = v;
    MIi_CpuClearFast(w, p, n);
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
        GX_SetBankForBG(data_021755a0->mUnk_0e);
    }
    if (data_021755a0->mUnk_10 != 0) {
        GX_SetBankForOBJ(data_021755a0->mUnk_10);
    }
    if (data_021755a0->mUnk_12 != 0) {
        GX_SetBankForBGExtPltt(data_021755a0->mUnk_12);
    }
    if (data_021755a0->mUnk_14 != 0) {
        GX_SetBankForOBJExtPltt(data_021755a0->mUnk_14);
    }
    if (data_021755a0->mUnk_16 != 0) {
        GX_SetBankForTex(data_021755a0->mUnk_16);
    }
    if (data_021755a0->mUnk_18 != 0) {
        GX_SetBankForTexPltt(data_021755a0->mUnk_18);
    }
    if (data_021755a0->mUnk_1a != 0) {
        GX_SetBankForClearImage(data_021755a0->mUnk_1a);
    }
    if (data_021755a0->mUnk_1c != 0) {
        GX_SetBankForSubBG(data_021755a0->mUnk_1c);
    }
    if (data_021755a0->mUnk_1e != 0) {
        GX_SetBankForSubOBJ(data_021755a0->mUnk_1e);
    }
    if (data_021755a0->mUnk_20 != 0) {
        GX_SetBankForSubBGExtPltt(data_021755a0->mUnk_20);
    }
    if (data_021755a0->mUnk_22 != 0) {
        GX_SetBankForSubOBJExtPltt(data_021755a0->mUnk_22);
    }
    if (data_021755a0->mUnk_24 != 0) {
        func_02039b94(data_021755a0->mUnk_24);
    }
    if (data_021755a0->mUnk_26 != 0) {
        GX_SetBankForLCDC(data_021755a0->mUnk_26);
    }
    data_02175614.mUnk_00;
    GX_SetGraphicsMode(p->mUnk_06, p->mUnk_08, p->mUnk_0a);
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1f00) | (p->mUnk_02 << 8);
    GXS_SetGraphicsMode(p->mUnk_0c);
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | (p->mUnk_04 << 8);
    if (p->mUnk_0a == 1) {
        G3X_Init();
        G3X_InitTable();
        G3X_InitMtxStack();
        reg_G3X_DISP3DCNT &= 0xffffcffd;
        reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~0x3000) | 0x10;
        reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~0x3000) | 4;
        reg_G3X_ALPHA_TEST_REF = 0;
        reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~0x3000) | 8;
        reg_G2_BLDCNT = 0;
        reg_G3_SWAP_BUFFERS = (p->mUnk_6c->mUnk_03 << 1) | p->mUnk_6c->mUnk_02;
        v = p->mUnk_6c->mUnk_00;
        ClearColorDepthWrite((u16) (v & 0x7fff), (u8) ((v & 0x8000) >> 15), 0x7fff, 0x3f, 0);
    }
    if (p->mUnk_02 & 1) {
        q = &p->mUnk_28;
        func_02037abc_inline2(&reg_G2_BG0CNT, q);
        if (p->mUnk_0a == 1) {
            G2Bg0OfsWrite(0);
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
    t = OS_GetTick();
    p->mUnk_bc = t;
    if (p->mUnk_0a == 1) {
        G3X_Reset();
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
    value0 = (u32) data_021755a0->mUnk_d8;
    value0 = (value0) & ~(1u);
    data_021755a0->mUnk_d8 = (u8) value0;
    return value0;
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
    DC_StoreAll();
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
    t = OS_GetTick();
    p->mUnk_cc = (t - p->mUnk_bc) * 0xfa00 / 0x82ea;
    for (i = 0; i < data_021755a0->mUnk_00; i++) {
        InterruptClearAndWait(1, 1);
    }
    data_021755a0->mUnk_d8 |= 1;
    data_021755a0->mUnk_c4 = OS_GetTick();
    if (c != data_021755b4.mUnk_08) {
        GXx_SetMasterBrightness_((u16 *) 0x400006c, data_021755b4.mUnk_08);
    }
    if (d != data_021755a8.mUnk_08) {
        GXx_SetMasterBrightness_((u16 *) 0x400106c, data_021755a8.mUnk_08);
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
    DC_StoreAll();
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
    t = OS_GetTick();
    p->mUnk_cc = (t - p->mUnk_bc) * 0xfa00 / 0x82ea;
    if (e != FALSE) {
        for (i = 0; i < data_021755a0->mUnk_00; i++) {
            InterruptClearAndWait(1, 1);
        }
    }
    data_021755a0->mUnk_d8 |= 1;
    data_021755a0->mUnk_c4 = OS_GetTick();
    if (c != data_021755b4.mUnk_08) {
        GXx_SetMasterBrightness_((u16 *) 0x400006c, data_021755b4.mUnk_08);
    }
    if (d != data_021755a8.mUnk_08) {
        GXx_SetMasterBrightness_((u16 *) 0x400106c, data_021755a8.mUnk_08);
    }
    if (data_usa_02175584 != NULL) {
        data_usa_02175584(2);
    }
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
    DC_StoreAll();
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
    t = OS_GetTick();
    p->mUnk_cc = (t - p->mUnk_bc) * 0xfa00 / 0x82ea;
    for (i = 0; i < data_021755a0->mUnk_00; i++) {
        InterruptClearAndWait(1, 1);
    }
    data_021755a0->mUnk_d8 |= 1;
    data_021755a0->mUnk_c4 = OS_GetTick();
    if (c != data_021755b4.mUnk_08) {
        GXx_SetMasterBrightness_((u16 *) 0x400006c, data_021755b4.mUnk_08);
    }
    if (d != data_021755a8.mUnk_08) {
        GXx_SetMasterBrightness_((u16 *) 0x400106c, data_021755a8.mUnk_08);
    }
    if (data_usa_02175584 != NULL) {
        data_usa_02175584(2);
    }
}

void func_020373ec(void) {
    u64 t;
    Unk021755a0 *p;
    t = OS_GetTick();
    if (data_usa_02175584 != NULL) {
        data_usa_02175584(3);
    }
    p = data_021755a0;
    p->mUnk_d0 = (t - p->mUnk_c4) * 0xfa00 / 0x82ea;
    p = data_021755a0;
    p->mUnk_d4 = (t - p->mUnk_bc) * 0xfa00 / 0x82ea;
}

void func_02037334(s16 a, s32 b) {
    if (b != 0) {
        func_02037288_inline(&data_021755b4, a);
    } else {
        func_02037288_inline(&data_021755a8, a);
    }
}

void func_02037288(s16 a) {
    func_02037288_inline(&data_021755b4, a);
    func_02037288_inline(&data_021755a8, a);
}

void func_020371a8(s32 a, s32 b) {
    if (b != 0) {
        func_020370d4_inline(&data_021755b4, a);
    } else {
        func_020370d4_inline(&data_021755a8, a);
    }
}

void func_020370d4(s16 a) {
    func_020370d4_inline(&data_021755b4, a);
    func_020370d4_inline(&data_021755a8, a);
}

void func_02036fec(s32 a, s32 b) {
    if (b != 0) {
        func_02036f10_inline(&data_021755b4, a);
    } else {
        func_02036f10_inline(&data_021755a8, a);
    }
}

void func_02036f10(s16 a) {
    func_02036f10_inline(&data_021755b4, a);
    func_02036f10_inline(&data_021755a8, a);
}

void func_02036e20(s16 a, s32 b) {
    if (b != 0) {
        func_02036d3c_inline(&data_021755b4, a);
    } else {
        func_02036d3c_inline(&data_021755a8, a);
    }
}

void func_02036d3c(s16 a) {
    func_02036d3c_inline(&data_021755b4, a);
    func_02036d3c_inline(&data_021755a8, a);
}

u32 func_02036d08(void) {
    if (data_021755b4.mUnk_00 == 0 && data_021755a8.mUnk_00 == 0) {
        return 1;
    }
    return 0;
}

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
    GXx_SetMasterBrightness_((u16 *) 0x400006c, data_021755b4.mUnk_08);
    GXx_SetMasterBrightness_((u16 *) 0x400106c, data_021755a8.mUnk_08);
}

u32 func_02036c5c(void) {
    if (((*(u16 *) &data_021755b4) == 2) && ((*(u16 *) &data_021755a8) == 2)) {
        return 1;
    }
    return 0;
}
