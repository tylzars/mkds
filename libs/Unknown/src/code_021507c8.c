#include "code_021507c8.h"

void Hash16Init(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = 0x67452301u;
    value1 = 0xefcdab89u;
    *(u32 *) ((value0) + (0)) = value2;
    value2 = 0x98badcfeu;
    *(u32 *) ((value0) + (4)) = value1;
    value1 = 0x10325476u;
    *(u32 *) ((value0) + (8)) = value2;
    *(u32 *) ((value0) + (12)) = value1;
    value1 = 0u;
    *(u32 *) ((value0) + (16)) = value1;
    *(u32 *) ((value0) + (20)) = value1;
}
