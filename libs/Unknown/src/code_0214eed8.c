#include "code_0214eed8.h"
#include "code_0214eef0.h"

// clang-format off
// Hand-written asm: waits while the first word of data_02180414 is 1. It keeps the address in ip, which the
// compiler never picks for it.
asm void func_0214eed8(void) {
    ldr ip, =data_02180414
wait_loop:
    ldr r0, [ip]
    cmp r0, #0x1
    beq wait_loop
    bx lr
}
// clang-format on
