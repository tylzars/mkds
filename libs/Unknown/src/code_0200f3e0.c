#include "code_0200f3e0.h"
#include "code_0200f3f4.h"
#include "Main/Unknown/code_0200f000.h"

// clang-format off
// Saves the exception context with OSi_SetExContext, then shows it with OSi_DisplayExContext.
// Hand-written asm: pushes only lr, which the compiler never does (it always pads the frame to 8 bytes).
asm void OSi_GetAndDisplayContext(u32 exinfo) {
    stmfd sp!, {lr}
    bl OSi_SetExContext
    bl OSi_DisplayExContext
    ldmfd sp!, {lr}
    bx lr
}
// clang-format on
