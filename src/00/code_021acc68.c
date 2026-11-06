#include "00/code_021acc68.h"

void func_ov000_021acc68(u16 *a, u32 b, int c, int d) {
    u16 v1;
    u16 *v2;
    v2 = a + c;
    for (; (b != 0 && (c < d)); c = c + 1) {
        v1 = *v2;
        *v2 = b + v1;
        b = b + v1 >> 0x10;
        v2 = v2 + 1;
    }
    return;
}
