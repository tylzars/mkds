#include "Main/Unknown/code_0200692c.h"
#include "Main/Unknown/code_02006954.h"

#pragma thumb on

void ReceivePacketFromIndexChecked(const u8 *data, int size, u32 fromIndex) {
    if (((data != NULL) && (size != 0)) && (size != 0xffff)) {
        ReceivePacketFromIndex(fromIndex, data, size);
    }
}

#pragma thumb off
