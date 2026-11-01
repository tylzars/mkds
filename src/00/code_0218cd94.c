#include "00/code_0218cd94.h"

// non-matching: the four-byte copy addresses the stack word through r1 plus offsets 4 to 7 instead of a pointer in r3
// (4 instructions, same size)
void func_ov000_0218cd94(u8 **a, u32 b, s32 *c) {
    *(Unk0218cd94 *) *a = *(Unk0218cd94 *) &b;
    *c = *c + 4;
    *a = *a + 4;
}
