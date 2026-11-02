#include "Main/Unknown/code_020cb3e4.h"

#include "Main/Unknown/code_020cae8c.h"
#include "Main/Unknown/code_020cb48c.h"

void func_020cb4a8(int arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    value2 = 0x4000000u;
    value1 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value1) & ~(0x1f00u);
    value0 = (value1) | ((value0 << 8));
    *(u32 *) ((value2) + (0)) = value0;
}

void func_020cb48c(int arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    value2 = 0x4001000u;
    value1 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value1) & ~(0x1f00u);
    value0 = (value1) | ((value0 << 8));
    *(u32 *) ((value2) + (0)) = value0;
}

#pragma thumb on

void func_020cb3e4(void) {
    int v1;
    v1 = func_020cccc0();
    if (v1 != 0) {
        func_020cb4a8(0x18);
        func_02148950((u16) 1, (u32) 0, 0);
        func_0214c090((const void *) (*(u32 *) (*(int *) ((int) data_0217b43c + 0x910) + 0xc)), 0,
                      (u32) (((u32) 0x000001a0u)));
        func_0214c090((const void *) (*(int *) (*(int *) ((int) data_0217b43c + 0x910) + 0xc) + 0x1c0), 0x1c0,
                      (u32) 0x40);
        func_0214bf04((const void *) (*(u32 *) (*(int *) ((int) data_0217b43c + 0x914) + 0x14)), 0,
                      (u32) (*(u32 *) (*(int *) ((int) data_0217b43c + 0x914) + 0x10)));
        func_020cb48c(0x16);
        func_02148934((u32) 0);
        func_0214c028((const void *) (*(u32 *) (*(int *) ((int) data_0217b43c + 0x920) + 0xc)), 0,
                      (u32) (*(u32 *) (*(int *) ((int) data_0217b43c + 0x920) + 8)));
        func_0214bea4((const void *) (*(u32 *) (*(int *) ((int) data_0217b43c + 0x924) + 0x14)), 0,
                      (u32) (*(u32 *) (*(int *) ((int) data_0217b43c + 0x924) + 0x10)));
    }
}

#pragma thumb off
