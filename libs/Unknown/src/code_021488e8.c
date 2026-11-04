#include "code_021488e8.h"

// Replaces the low three bits of the word at 0x4001000 with the bits of a.
void GxsDispCntBits0To2Write(u32 a) {
    *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & ~0x7) | a;
}

// Stores 0 at p when v is 0, v | 0x4000 for positive v and -v | 0x8000 for negative v.
void MasterBrightWrite(u16 *p, s32 v) {
    if (v == 0) {
        *p = 0;
        return;
    }
    if (v > 0) {
        *p = v | 0x4000;
    } else {
        *p = -v | 0x8000;
    }
}

// Does nothing.
void func_02148904(void) {}

// Returns the low 32 bits of (a * b + 0x800) >> 12, computed in 64 bits.
u32 MulFixed12(s32 a, s32 b) {
    return ((s64) a * b + 0x800) >> 12;
}
