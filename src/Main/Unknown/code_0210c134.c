#include "Main/Unknown/code_0210c134.h"

void func_0210c134(int a, u32 b) {
    u32 v1;
    u32 v2;
    func_02017538((Unk02017328 *) ((u32 *) (u32) (a + 0xc)), (u16) 8);
    v1 = ((u32) (&func_0210d0b4));
    *(u32 *) (a + 0x38) = 1;
    v2 = ((u32) (&func_0210d078));
    *(u32 *) (a + 0x2c) = v1;
    *(u32 *) (a + 0x30) = v2;
    *(u16 *) (a + 0x34) = 0;
    *(u32 *) (a + 0x28) = b;
    *(u32 *) (a + 0x18) = 3;
    func_0210bce0((u32 *) (u32) (a + 0x1c));
    func_0210bce0((u32 *) (u32) a);
    func_0210bc8c((int) (((u32) (&data_0217d028))), a);
}
