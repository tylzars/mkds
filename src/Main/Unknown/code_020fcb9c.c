#include "Main/Unknown/code_020fcb9c.h"
#include "Main/Unknown/unk_027e0000.h"

void func_020fcb9c(int arg0, int arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2;
    u32 value3;
    value3 = ((u32) &data_027e00c8);
    value2 = 0x210u;
    value3 = (u32) * (const u32 *) ((value3) + (0));
    value2 = (value1) * (value2) + (value3);
    *(u32 *) ((value0) + (552)) = value2;
}
