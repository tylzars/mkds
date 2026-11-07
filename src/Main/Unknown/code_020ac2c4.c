#include "Main/Unknown/code_020ac2c4.h"

#pragma thumb on

#include "Main/Unknown/code_020ac2c4.h"

#pragma thumb on

// The reverse of SplitBytesIntoNibbles: joins pairs of 4-bit entries into bytes.
void JoinNibblesIntoBytes(const u8 *nibbles, u8 *bytes, int side) {
    int i;
    int byteCount = side * side / 2;
    for (i = 0; i < byteCount; i++) {
        bytes[i] = nibbles[i * 2] | (nibbles[i * 2 + 1] << 4);
    }
}

#pragma thumb off

#pragma thumb off
