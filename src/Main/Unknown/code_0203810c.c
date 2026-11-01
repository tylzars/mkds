#include "Main/Unknown/code_0203810c.h"
#include "code_0214a390.h"
#include "registers.h"
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
static inline void func_0203810c_inline4(vu16 *r, Unk0203810c_Arg b, Unk0203810c_Arg c, Unk0203810c_04 *d) {
    *r = (*r & 0x43) | (b << 14) | (c << 8) | (d->mUnk_06 << 13);
}

// Keeps bits 0, 1 and 6 of the halfword register r, sets bit 7 and the rest from three values.
static inline void func_0203810c_inline5(vu16 *r, Unk0203810c_Arg b, Unk0203810c_Arg c, Unk0203810c_04 *d) {
    *r = (*r & 0x43) | (b << 14) | 0x80 | (c << 8) | (d->mUnk_06 << 13);
}

// Keeps bits 0, 1 and 6 of the halfword register r, sets bits 2 and 7 and the rest from three values.
static inline void func_0203810c_inline6(vu16 *r, Unk0203810c_Arg b, Unk0203810c_Arg c, Unk0203810c_04 *d) {
    *r = (*r & 0x43) | (b << 14) | 0x84 | (c << 8) | (d->mUnk_06 << 13);
}

// non-matching: in cases 3, 4 and 5 (both register paths) r2 and r3 are swapped for the members 0x04 and 0x06: 24 words
// differ, same size (1476 bytes).
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
                func_0203810c_inline4((vu16 *) 0x0400000e, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_08,
                                      q);
            } else {
                func_0214a428((u32 *) 0x04001030, m, 0, 0, 0, 0);
                func_0203810c_inline((vu16 *) 0x0400100e, q);
                func_0203810c_inline4((vu16 *) 0x0400100e, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_08,
                                      q);
            }
            break;
        case 4:
            if (b != 0) {
                func_0214a428((u32 *) 0x04000030, m, 0, 0, 0, 0);
                func_0203810c_inline((vu16 *) 0x0400000e, q);
                func_0203810c_inline5((vu16 *) 0x0400000e, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_08,
                                      q);
            } else {
                func_0214a428((u32 *) 0x04001030, m, 0, 0, 0, 0);
                func_0203810c_inline((vu16 *) 0x0400100e, q);
                func_0203810c_inline5((vu16 *) 0x0400100e, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_08,
                                      q);
            }
            break;
        case 5:
            if (b != 0) {
                func_0214a428((u32 *) 0x04000030, m, 0, 0, 0, 0);
                func_0203810c_inline((vu16 *) 0x0400000e, q);
                func_0203810c_inline6((vu16 *) 0x0400000e, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_08,
                                      q);
            } else {
                func_0214a428((u32 *) 0x04001030, m, 0, 0, 0, 0);
                func_0203810c_inline((vu16 *) 0x0400100e, q);
                func_0203810c_inline6((vu16 *) 0x0400100e, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_08,
                                      q);
            }
            break;
        default:
            break;
    }
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
static inline void func_020386d0_inline4(vu16 *r, Unk0203810c_Arg b, Unk0203810c_Arg c, Unk0203810c_04 *d) {
    *r = (*r & 0x43) | (b << 14) | (c << 8) | (d->mUnk_06 << 13);
}

// Keeps bits 0, 1 and 6 of the halfword register r, sets bit 7 and the rest from three values.
static inline void func_020386d0_inline5(vu16 *r, Unk0203810c_Arg b, Unk0203810c_Arg c, Unk0203810c_04 *d) {
    *r = (*r & 0x43) | (b << 14) | 0x80 | (c << 8) | (d->mUnk_06 << 13);
}

// Keeps bits 0, 1 and 6 of the halfword register r, sets bits 2 and 7 and the rest from three values.
static inline void func_020386d0_inline6(vu16 *r, Unk0203810c_Arg b, Unk0203810c_Arg c, Unk0203810c_04 *d) {
    *r = (*r & 0x43) | (b << 14) | 0x84 | (c << 8) | (d->mUnk_06 << 13);
}

// non-matching: in cases 3, 4 and 5 (both register paths) r2 and r3 are swapped for the members 0x04 and 0x06: 24 words
// differ, same size (1476 bytes).
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
                func_020386d0_inline4((vu16 *) 0x0400000c, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_08,
                                      q);
            } else {
                func_0214a428((u32 *) 0x04001020, m, 0, 0, 0, 0);
                func_020386d0_inline((vu16 *) 0x0400100c, q);
                func_020386d0_inline4((vu16 *) 0x0400100c, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_08,
                                      q);
            }
            break;
        case 4:
            if (b != 0) {
                func_0214a428((u32 *) 0x04000020, m, 0, 0, 0, 0);
                func_020386d0_inline((vu16 *) 0x0400000c, q);
                func_020386d0_inline5((vu16 *) 0x0400000c, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_08,
                                      q);
            } else {
                func_0214a428((u32 *) 0x04001020, m, 0, 0, 0, 0);
                func_020386d0_inline((vu16 *) 0x0400100c, q);
                func_020386d0_inline5((vu16 *) 0x0400100c, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_08,
                                      q);
            }
            break;
        case 5:
            if (b != 0) {
                func_0214a428((u32 *) 0x04000020, m, 0, 0, 0, 0);
                func_020386d0_inline((vu16 *) 0x0400000c, q);
                func_020386d0_inline6((vu16 *) 0x0400000c, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_08,
                                      q);
            } else {
                func_0214a428((u32 *) 0x04001020, m, 0, 0, 0, 0);
                func_020386d0_inline((vu16 *) 0x0400100c, q);
                func_020386d0_inline6((vu16 *) 0x0400100c, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_08,
                                      q);
            }
            break;
        default:
            break;
    }
}
