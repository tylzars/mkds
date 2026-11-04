#include "Main/Unknown/code_02006380.h"
#include "Main/Unknown/code_02006954.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_02133000.h"
#include "code_0214d018.h"

#pragma thumb on

static inline u8 *func_0214d1fc_inline(const void *v1, u8 *v2, u32 n) {
    MemCopy(v1, v2, n);
    return v2 + n;
}

u32 func_02006914(s32 a, s32 b) {
    if (b > 0 && a != 0) {
        func_02006b50(a, b);
    }
}

void func_020068f4(const u8 *a, u32 b) {
    if (a != NULL && b != 0 && b != 0xffff) {
        func_02006bec(a, b);
    }
}

s32 func_020068b4(s32 a, u16 b, u8 c) {
    struct {
        u8 m0;
        u16 m2;
    } v;
    u8 *v1;
    v1 = (u8 *) a;
    v.m2 = b;
    v.m0 = 1;
    v1 = func_0214d1fc_inline(&v, v1, 1);
    v1 = func_0214d1fc_inline(&v.m2, v1, 2);
    MemCopy(&c, v1, 1);
    return (s32) v1 + 1 - a;
}

s32 func_02006858(s32 a, u16 b, u8 c, u32 d, u32 e) {
    struct {
        u8 m0;
        u16 m2;
    } v;
    u8 *v1;
    v1 = (u8 *) a;
    v.m2 = b;
    v.m0 = 2;
    v1 = func_0214d1fc_inline(&v, v1, 1);
    v1 = func_0214d1fc_inline(&v.m2, v1, 2);
    v1 = func_0214d1fc_inline(&c, v1, 1);
    v1 = func_0214d1fc_inline(&d, v1, 2);
    MemCopy(&e, v1, 2);
    return (s32) v1 + 2 - a;
}

s32 func_020067f0(s32 a, u16 b, u8 c, s16 d, u32 e, u32 f) {
    struct {
        u8 m0;
        u16 m2;
    } v;
    u8 *v1;
    v1 = (u8 *) a;
    v.m2 = b;
    v.m0 = 3;
    v1 = func_0214d1fc_inline(&v, v1, 1);
    v1 = func_0214d1fc_inline(&v.m2, v1, 2);
    v1 = func_0214d1fc_inline(&c, v1, 1);
    v1 = func_0214d1fc_inline(&d, v1, 2);
    v1 = func_0214d1fc_inline(&e, v1, 2);
    MemCopy(&f, v1, 2);
    return (s32) v1 + 2 - a;
}

s32 func_02006794(s32 a, u16 b, u8 c, u32 d, u32 e) {
    struct {
        u8 m0;
        u16 m2;
    } v;
    u8 *v1;
    v1 = (u8 *) a;
    v.m2 = b;
    v.m0 = 4;
    v1 = func_0214d1fc_inline(&v, v1, 1);
    v1 = func_0214d1fc_inline(&v.m2, v1, 2);
    v1 = func_0214d1fc_inline(&c, v1, 1);
    v1 = func_0214d1fc_inline(&d, v1, 4);
    MemCopy(&e, v1, 4);
    return (s32) v1 + 4 - a;
}

s32 func_0200671c(s32 a, u32 b, u8 c, u32 d, u32 e, u32 f, s32 g) {
    struct {
        u8 m0;
        u16 m2;
    } v;
    u8 *v1;
    v1 = (u8 *) a;
    v.m2 = b;
    v.m0 = 5;
    v1 = func_0214d1fc_inline(&v, v1, 1);
    v1 = func_0214d1fc_inline(&v.m2, v1, 2);
    v1 = func_0214d1fc_inline(&c, v1, 1);
    v1 = func_0214d1fc_inline(&d, v1, 4);
    v1 = func_0214d1fc_inline(&e, v1, 4);
    if (f == 0) {
        MemFill(v1, 0, g);
    } else {
        MemCopy((void *) f, v1, g);
    }
    return (s32) v1 + g - a;
}

s32 func_020066c0(s32 a, u16 b, u8 c, u32 d, u32 e) {
    struct {
        u8 m0;
        u16 m2;
    } v;
    u8 *v1;
    v1 = (u8 *) a;
    v.m2 = b;
    v.m0 = 6;
    v1 = func_0214d1fc_inline(&v, v1, 1);
    v1 = func_0214d1fc_inline(&v.m2, v1, 2);
    v1 = func_0214d1fc_inline(&c, v1, 1);
    v1 = func_0214d1fc_inline(&d, v1, 4);
    MemCopy(&e, v1, 4);
    return (s32) v1 + 4 - a;
}

s32 func_02006648(s32 a, u32 b, u8 c, u32 d, u32 e, u32 f, u32 g) {
    struct {
        u8 m0;
        u16 m2;
    } v;
    u8 *v1;
    v1 = (u8 *) a;
    v.m2 = b;
    v.m0 = 7;
    v1 = func_0214d1fc_inline(&v, v1, 1);
    v1 = func_0214d1fc_inline(&v.m2, v1, 2);
    v1 = func_0214d1fc_inline(&c, v1, 1);
    v1 = func_0214d1fc_inline(&d, v1, 4);
    v1 = func_0214d1fc_inline(&e, v1, 4);
    if (f == 0) {
        MemFill(v1, 0, g);
    } else {
        MemCopy((void *) f, v1, g);
    }
    return (s32) v1 + g - a;
}

s32 func_020065f8(s32 a, u16 b, u8 c, u32 d) {
    struct {
        u8 m0;
        u16 m2;
    } v;
    u8 *v1;
    v1 = (u8 *) a;
    v.m2 = b;
    v.m0 = 8;
    v1 = func_0214d1fc_inline(&v, v1, 1);
    v1 = func_0214d1fc_inline(&v.m2, v1, 2);
    v1 = func_0214d1fc_inline(&c, v1, 1);
    MemCopy(&d, v1, 4);
    return (s32) v1 + 4 - a;
}

s32 func_020065a8(s32 a, u16 b, u8 c, u32 d) {
    struct {
        u8 m0;
        u16 m2;
    } v;
    u8 *v1;
    v1 = (u8 *) a;
    v.m2 = b;
    v.m0 = 9;
    v1 = func_0214d1fc_inline(&v, v1, 1);
    v1 = func_0214d1fc_inline(&v.m2, v1, 2);
    v1 = func_0214d1fc_inline(&c, v1, 1);
    MemCopy(&d, v1, 4);
    return (s32) v1 + 4 - a;
}

s32 func_0200654c(s32 a, u16 b, u8 c, u32 *d, u32 e) {
    struct {
        u8 m0;
        u16 m2;
    } v;
    u8 *v1;
    v1 = (u8 *) a;
    v.m2 = b;
    v.m0 = 0xa;
    v1 = func_0214d1fc_inline(&v, v1, 1);
    v1 = func_0214d1fc_inline(&v.m2, v1, 2);
    v1 = func_0214d1fc_inline(&c, v1, 1);
    v1 = func_0214d1fc_inline(&e, v1, 1);
    MemCopy(d, v1, 9);
    return (s32) v1 + 9 - a;
}

s32 func_02006508(s32 a, u16 b, u8 c) {
    struct {
        u8 m0;
        u16 m2;
    } v;
    u8 *v1;
    v1 = (u8 *) a;
    v.m2 = b;
    v.m0 = 0xb;
    v1 = func_0214d1fc_inline(&v, v1, 1);
    v1 = func_0214d1fc_inline(&v.m2, v1, 2);
    MemCopy(&c, v1, 1);
    return (s32) v1 + 1 - a;
}

s32 func_02006458(u32 a, s32 b) {
    Unk02007014 *v1;
    s32 i;
    v1 = func_02007040();
    if (a < 1000) {
        return b;
    }
    for (; v1 != NULL; v1 = v1->mUnk_28) {
        if (v1->mUnk_00 == a) {
            if (a == data_02161774) {
                i = 0;
                while (b == data_02161770 || b == data_02161778) {
                    b++;
                    if (b > (v1->mUnk_04 + (s32) func_020070d8() - 1) / (s32) func_020070d8() - 1) {
                        b = 0;
                    }
                    i++;
                    if (i > 2) {
                        break;
                    }
                }
            }
            data_02161774 = a;
            data_02161778 = data_02161770;
            data_02161770 = b;
            return b;
        }
    }
    return -1;
}

u32 func_020063f4(u32 a, u32 b) {
    Unk02007014 *v1;
    u32 i;
    v1 = func_02007040();
    if (a < 1000) {
        for (i = 0;; i++, v1 = v1->mUnk_28) {
            if (v1 == NULL) {
                break;
            }
            if (i == a) {
                return (u32) v1 + b * func_020070d8();
            }
        }
        return 0;
    }
    for (; v1 != NULL; v1 = v1->mUnk_28) {
        if (v1->mUnk_00 == a) {
            v1 = (Unk02007014 *) v1->mUnk_2c;
            return (u32) v1 + b * func_020070d8();
        }
    }
    return 0;
}

void func_0200639c(Unk0200628c *a, s32 b, void *c, u32 d) {
    s32 v1;
    v1 = func_020070e4();
    a->mUnk_00 = b;
    a->mUnk_08 = 0;
    a->mUnk_0c = 0;
    a->mUnk_10 = 0;
    a->mUnk_04 = b / v1 + ((b % v1) != 0 ? 1 : 0);
    a->mUnk_14 = c;
    a->mUnk_18 = (u8 *) d;
    MemFill(c, 0, func_02006f98(b));
}

BOOL func_02006380(Unk0200628c *a, s32 b) {
    u32 v1;
    v1 = a->mUnk_14[b >> 5];
    if ((v1 & (1 << (b & 0x1f))) != 0) {
        return TRUE;
    }
    return FALSE;
}

#pragma thumb off
