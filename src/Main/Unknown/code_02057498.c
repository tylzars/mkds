#include "Main/Unknown/code_02057498.h"

#pragma thumb on

// The byte of an array of bits that holds the given bit; only the low 11 bits of the number count.
u8 *GetBitArrayByte(u32 bitIndex, u8 *bytes) {
    return bytes + ((bitIndex << 21) >> 24);
}

#pragma thumb off
