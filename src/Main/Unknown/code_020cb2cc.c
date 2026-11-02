#include "Main/Unknown/code_020cb2cc.h"

#include "Main/Unknown/code_020cb2d4.h"

#pragma thumb on

void func_020cb2d4(void) {
    int v1;
    func_020cb340();
    v1 = *(int *) &data_0217b43c;
    func_02124c30((void *) (*(u32 *) (v1 + 0x940)), (void *) (*(u32 *) (v1 + 0x918)), (void *) 0, (void *) (v1 + 0x108),
                  (void *) (*(u32 *) (v1 + 0x93c)));
    v1 = *(int *) &data_0217b43c;
    func_02124c30((void *) (*(u32 *) (v1 + 0x94c)), (void *) (*(u32 *) (v1 + 0x928)), (void *) 0, (void *) (v1 + 0x50c),
                  (void *) (*(u32 *) (v1 + 0x948)));
}

#pragma thumb off

#pragma thumb on
void func_020cb2cc(void) {
    u32 value3;
    value3 = (u32) &func_020cb3e4;
    func_020cb3e4();
}
#pragma thumb off
