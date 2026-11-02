#include "00/code_021ac37c.h"

void func_ov000_021ac37c(u8 *a, u32 *b, u32 c) {
    u32 v1;
    u32 v2;
    u8 *v3;
    v2 = 0;
    if (v2 < c >> 2) {
        do {
            v1 = *b;
            b = b + 1;
            *a = (s8) (v1 >> 0x18);
            a[1] = (s8) (v1 >> 0x10);
            a[2] = (s8) (v1 >> 8);
            v3 = a + 3;
            a = a + 4;
            *v3 = (s8) v1;
            v2 = v2 + 1;
        } while (v2 < c >> 2);
    }
    return;
}
