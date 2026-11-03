#include "01/code_02187cd4.h"
#include "01/code_02187d14.h"
#include "code_020109c4.h"

void func_ov001_02187cd4(int a, u32 b) {
    int *v1;
    *(u32 *) (a + 0x2e4) = b;
    *(u32 *) (a + 0x27c) = 3;
    v1 = (s32 *) (a + 0x304);
    *(s32 *) (*(s32 *) (*v1 + 0x10) + 0x2c) = a;
    func_020109c4((void *) (*(u32 *) (*v1 + 0x10)), (void (*)(void *))((u32) &func_ov001_02187d14), (u32) 0, (u8) 6,
                  (u8) 3);
}
