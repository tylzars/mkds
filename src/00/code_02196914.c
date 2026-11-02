#include "00/code_02196914.h"

void func_ov000_02196914(u8 *a, const void *b, s32 c) {
    if (a == NULL) {
        func_0213442c(data_ov000_021b3b10, data_ov000_021b3a1c, NULL, 0x2f);
    }
    if (b == NULL) {
        func_0213442c(data_ov000_021b3b20, data_ov000_021b3a1c, NULL, 0x30);
    }
    strncpy(a, b, c);
    *(a + c + -1) = 0;
    return;
}
