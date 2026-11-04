#include "code_0200f3e0.h"
#include "code_0200f3f4.h"
#include "Main/Unknown/code_0200f000.h"

// clang-format off
// Hand-written asm: pushes only lr, which the compiler never does (it always pads the frame to 8 bytes).
asm void func_0200f3e0(u32 a) {
    stmfd sp!, {lr}
    bl func_0200f3f4
    bl func_0200f484
    ldmfd sp!, {lr}
    bx lr
}
// clang-format on
