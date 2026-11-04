#include "code_0214d93c.h"
#include "code_0214d954.h"

// clang-format off
// Hand-written asm: waits while the first word of data_021803b0 is 1. It keeps the address in ip, which the
// compiler never picks for it.
asm void func_0214d93c(void) {
    ldr ip, =data_021803b0
wait_loop:
    ldr r0, [ip]
    cmp r0, #0x1
    beq wait_loop
    bx lr
}
// clang-format on
