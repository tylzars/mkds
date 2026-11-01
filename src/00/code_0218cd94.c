#include "00/code_0218cd94.h"

void func_ov000_0218cd94(u8 **a, u32 b, s32 *c) {
    u8 *p = *a;
    u8 *q = (u8 *) &b;
    p[0] = q[0];
    p[1] = q[1];
    p[2] = q[2];
    p[3] = q[3];
    *c = *c + 4;
    *a = *a + 4;
}
