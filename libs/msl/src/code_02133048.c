#include "code_02133048.h"

// clang-format off
// Multiplies the 64-bit integers r1:r0 and r3:r2 and returns the low 64 bits of the product in r1:r0.
// Not compiled code: it saves three registers (r4, r5, lr) with no padding word, where the 1.2 compiler always pads a
// frame to 8 bytes, and it keeps its values in r4 and r5 while ip is free; 1.2's own 64-bit product uses ip and lr
// (frame layout in the compiler; docs/compiler.md, Registers).
// The same routine is also `_ull_mul`, which 1.2 calls for an unsigned product: a second name at this address in
// symbols.txt (after `_ll_mul`, so dsd keeps naming the original's calls `_ll_mul`). An asm function cannot export a
// second name (a label in its body stays local), so the delinked object carries it.
asm u64 _ll_mul(u64 a, u64 b) {
    // Low words multiplied in full, plus the two cross products into the high word.
    stmfd sp!, {r4, r5, lr}
    umull r5, r4, r0, r2
    mla r4, r0, r3, r4
    mla r4, r2, r1, r4
    mov r1, r4
    mov r0, r5
    ldmfd sp!, {r4, r5, lr}
    bx lr
}

// Signed 32-bit division: r0 divided by r1 gives the quotient in r0 and the remainder in r1, both rounded toward zero
// (the remainder takes the dividend's sign). Division by zero returns at once. It works on the magnitudes: the dividend
// is shifted up by the number of leading quotient bits that must be zero (found four at a time), then a computed jump
// enters a run of 32 identical steps at the right place; each step shifts the next dividend bit into the remainder and
// subtracts the divisor when it fits, the carry giving the quotient bit.
// Not compiled code: the computed jump `add pc, pc, r2, lsl #2` has no bound check and lands inside straight-line code,
// where 1.2 dispatches only switches, through `addls pc` and a table of branches; and every step tests the carry of an
// `adcs` with `sublo`, a condition 1.2 takes only from a compare (docs/compiler.md, Conditions).
asm u64 _s32_div_f(u32 param_1, u32 param_2) {
    // ip bit 31 = the quotient's sign, bit 0 = the dividend's sign. Work on the magnitudes. A zero divisor returns at
    // once; a dividend below the divisor gives quotient 0 and the dividend as remainder.
    eor ip, r0, r1
    and ip, ip, #0x80000000
    cmp r0, #0
    rsblt r0, r0, #0
    addlt ip, ip, #1
    cmp r1, #0
    rsblt r1, r1, #0
    beq sdiv_sign
    cmp r0, r1
    movlo r1, r0
    movlo r0, #0
    blo sdiv_sign
    // r2 = 28 minus the number of leading quotient bits known to be zero, in steps of 4 (16, 8, 4). Shift the dividend
    // up by that many bits, negate the divisor, and jump over the first r2 of the 32 steps below (three instructions
    // each).
    mov r2, #28
    mov r3, r0, lsr #4
    cmp r1, r3, lsr #12
    suble r2, r2, #16
    movle r3, r3, lsr #16
    cmp r1, r3, lsr #4
    suble r2, r2, #8
    movle r3, r3, lsr #8
    cmp r1, r3
    suble r2, r2, #4
    movle r3, r3, lsr #4
    mov r0, r0, lsl r2
    rsb r1, r1, #0
    adds r0, r0, r0
    add r2, r2, r2, lsl #1
    add pc, pc, r2, lsl #2              // pc reads two instructions ahead: step 0 is after the nop
    // The run of division steps; r3 = the remainder, r0 = dividend bits shifted out and quotient bits in.
    mov r0, r0                          // never executed
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    // Remainder to r1.
    mov r1, r3
    // Apply the signs: the quotient's to r0, the dividend's to the remainder in r1.
sdiv_sign:
    ands r3, ip, #0x80000000
    rsbne r0, r0, #0
    ands r3, ip, #1
    rsbne r1, r1, #0
    bx lr
}
// clang-format on
