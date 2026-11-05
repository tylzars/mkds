#include "code_0200eddc.h"

#include "code_0200c4a4.h"
#include "code_0200c914.h"
#include "code_0200cd04.h"
#include "code_0200ce60.h"
#include "code_0200db4c.h"
#include "code_0214d594.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200f3f4.h"
#include "code_0200f790.h"
#include "code_0200fc8c.h"
#include "code_0200fe74.h"
#include "Main/Unknown/code_02146000.h"
#include "code_021458c4.h"
#include "code_0214d5b8.h"
#include "code_0214f4a4.h"
#include "Main/Unknown/code_02150000.h"
#include "Main/Unknown/unk_02170000.h"
#include "code_0200e77c.h"
#include "Main/Unknown/unk_00000000.h"
#include "Main/Unknown/unk_00002000.h"
#include "Main/Unknown/unk_02400000.h"
#include "code_0200f328.h"
#include "Main/Unknown/code_0200e000.h"

u32 data_021701b8;

// On the first call fills the tables of func_0200ef24 and func_0200ef38 for indices 0 and 3 to 6 from
// func_0200ef4c and func_0200f038, and clears index 2.
void func_0200f210(void) {
    if (data_021701b4 != 0) {
        return;
    }
    data_021701b4 = 1;
    func_0200ef38(0, func_0200f038(0));
    func_0200ef24(0, func_0200ef4c(0));
    func_0200ef24(2, 0);
    func_0200ef38(2, 0);
    func_0200ef38(3, func_0200f038(3));
    func_0200ef24(3, func_0200ef4c(3));
    func_0200ef38(4, func_0200f038(4));
    func_0200ef24(4, func_0200ef4c(4));
    func_0200ef38(5, func_0200f038(5));
    func_0200ef24(5, func_0200ef4c(5));
    func_0200ef38(6, func_0200f038(6));
    func_0200ef24(6, func_0200ef4c(6));
}

// Fills index 2 of both tables, then unless data_021701b8 is nonzero and the low two bits of func_0200e884() are
// not 1, passes one constant each to func_0200f35c and func_0200f364.
void func_0200f190(void) {
    func_0200ef38(2, func_0200f038(2));
    func_0200ef24(2, func_0200ef4c(2));
    if (data_021701b8 != 0 && (func_0200e884() & 3) != 1) {
        return;
    }
    func_0200f35c(0x200002b);
    func_0200f364(0x23e0021);
}

u32 func_0200f17c(int arg0) {
    u32 value0 = (u32) arg0;
    value0 = (value0 << 2);
    value0 = (value0) + (0x2700000u);
    value0 = (value0) + (0xff000u);
    value0 = (u32) * (const u32 *) ((value0) + (3524));
    return value0;
}

u32 func_0200f168(int arg0) {
    u32 value0 = (u32) arg0;
    value0 = (value0 << 2);
    value0 = (value0) + (0x2700000u);
    value0 = (value0) + (0xff000u);
    value0 = (u32) * (const u32 *) ((value0) + (3488));
    return value0;
}

u32 func_0200f038(u32 i) {
    u32 a;
    s32 n;
    u32 c;

    switch (i) {
        case 0:
            return 0x23e0000;
        case 2:
            if (data_021701b8 == 0 || (func_0200e884() & 3) == 1) {
                return 0;
            }
            return 0x2700000;
        case 3:
            return 0x2000000;
        case 4:
            a = (u32) &data_027e0000;
            c = a + 0x3f80 - (u32) data_00000c00;
            n = (s32) data_00002800;
            if (n == 0) {
                return a < 0x27e00e0 ? 0x27e00e0 : a;
            }
            if (n < 0) {
                return 0x27e00e0 - n;
            }
            return c - n;
        case 5:
            return 0x27ff680;
        case 6:
            return 0x37f8000;
    }
    return 0;
}

u32 func_0200ef4c(u32 i) {
    switch (i) {
        case 0:
            return 0x21da300;
        case 2:
            if (data_021701b8 == 0 || (func_0200e884() & 3) == 1) {
                return 0;
            }
            return (u32) data_02400000;
        case 3:
            return 0x1ffffa0;
        case 4:
            return 0x27e00e0;
        case 5:
            return 0x27ff000;
        case 6:
            return 0x37f8000;
    }
    return 0;
}

void func_0200ef38(u32 i, u32 v) {
    ((vu32 *) 0x027ffdc4)[i] = v;
}

void func_0200ef24(u32 i, u32 v) {
    ((vu32 *) 0x027ffda0)[i] = v;
}

u32 func_0200ef10(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_021701b8;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

// Calls fifteen functions in a fixed order.
void func_0200eec0(void) {
    func_0200f210();
    PxiInit();
    func_0200d028();
    func_0200f190();
    func_0200cd04();
    func_0200ca34();
    func_0200f4f0();
    MI_Init();
    func_0200fc1c();
    func_0200ffd8();
    ThreadSystemInit();
    func_0200fd74();
    func_0200c7f4();
    func_02146154();
    PM_Init();
}

// clang-format off
// Not compiled code: C has no way to write a coprocessor 15 register (mcr).
asm void func_0200eddc(void) {
    mov r1, #0x0
loop_outer:
    mov r0, #0x0
loop_inner:
    orr r2, r1, r0
    mcr p15, 0, r2, c7, c10, 2
    add r0, r0, #0x20
    cmp r0, #0x400
    blt loop_inner
    add r1, r1, #0x40000000
    cmp r1, #0x0
    bne loop_outer
    bx lr
}

// Not compiled code: C has no way to write a coprocessor 15 register (mcr).
asm void func_0200ee08(void) {
    mov ip, #0x0
    mov r1, #0x0
loop_outer:
    mov r0, #0x0
loop_inner:
    orr r2, r1, r0
    mcr p15, 0, ip, c7, c10, 4
    mcr p15, 0, r2, c7, c14, 2
    add r0, r0, #0x20
    cmp r0, #0x400
    blt loop_inner
    add r1, r1, #0x40000000
    cmp r1, #0x0
    bne loop_outer
    bx lr
}

// Not compiled code: C has no way to write a coprocessor 15 register (mcr).
asm void func_0200ee3c(void *p, u32 n) {
    add r1, r1, r0
    bic r0, r0, #0x1f
loop:
    mcr p15, 0, r0, c7, c6, 1
    add r0, r0, #0x20
    cmp r0, r1
    blt loop
    bx lr
}

// Not compiled code: C has no way to write a coprocessor 15 register (mcr).
asm void func_0200ee58(void *p, u32 n) {
    add r1, r1, r0
    bic r0, r0, #0x1f
loop:
    mcr p15, 0, r0, c7, c10, 1
    add r0, r0, #0x20
    cmp r0, r1
    blt loop
    bx lr
}

// Not compiled code: C has no way to write a coprocessor 15 register (mcr).
asm void func_0200ee74(const void *a, int b) {
    mov ip, #0x0
    add r1, r1, r0
    bic r0, r0, #0x1f
loop:
    mcr p15, 0, ip, c7, c10, 4
    mcr p15, 0, r0, c7, c14, 1
    add r0, r0, #0x20
    cmp r0, r1
    blt loop
    bx lr
}

// Not compiled code: C has no way to write a coprocessor 15 register (mcr).
asm void func_0200ee98(void) {
    mov r0, #0x0
    mcr p15, 0, r0, c7, c10, 4
    bx lr
}

// Not compiled code: C has no way to write a coprocessor 15 register (mcr).
asm void func_0200eea4(void *p, u32 n) {
    add r1, r1, r0
    bic r0, r0, #0x1f
loop:
    mcr p15, 0, r0, c7, c5, 1
    add r0, r0, #0x20
    cmp r0, r1
    blt loop
    bx lr
}
// clang-format on
