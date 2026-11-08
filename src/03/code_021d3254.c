#include "03/code_021d3254.h"

s32 GetStringLengthWithLimit(const u8 *bytes, s32 limit) {
    s32 i;
    for (i = 0; i < limit; i++) {
        if (bytes[i] == 0) {
            break;
        }
    }
    return i;
}
