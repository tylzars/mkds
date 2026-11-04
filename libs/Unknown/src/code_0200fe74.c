#include "code_0200fe74.h"

// clang-format off
// Counts the leading zero bits of r0.
asm u32 CountLeadingZeros(u32 a) {
    clz r0, r0
    bx lr
}
// clang-format on
