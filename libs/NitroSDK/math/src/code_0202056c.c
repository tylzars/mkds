#include "code_0202056c.h"

u32 CountSetBits(u32 a) {
    a = a - ((a >> 1) & 0x55555555);
    a = (a & 0x33333333) + ((a >> 2) & 0x33333333);
    a = (a + (a >> 4)) & 0x0f0f0f0f;
    a = a + (a >> 8);
    a = a + (a >> 16);
    return a & 0xff;
}
