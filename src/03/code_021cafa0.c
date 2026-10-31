#include "03/code_021cafa0.h"
#include "03/code_021d2a34.h"

void func_ov003_021cb06c(void) {
    func_ov003_021cafa4();
    func_ov003_021cafa0();
    func_ov003_021caeb8();
    return;
}

void func_ov003_021cafa4(void) {
    int v1;
    u32 v2;
    int v3;
    v2 = 0;
    v3 = ((int) ((u32) (&data_ov003_021d6508)));
    do {
        v1 = func_ov003_021d2a34((const Unk021d299c *) (u16 *) ((u16 *) (u32) (v3)));
        if (v1 != 0) {
            func_ov003_021bf31c((u8) (1));
            *(u8 *) &data_ov003_021da230 = (s8) v2;
            func_ov003_021caca8();
            return;
        }
        v3 = v3 + 8;
        v2 = v2 + 1;
    } while (v2 < 7);
    v3 = func_ov003_021d2b04(1);
    if (v3 != 0) {
        func_ov003_021bf31c((u8) (1));
        return;
    }
    v3 = func_ov003_021d2b04(2);
    if (v3 != 0) {
        func_ov003_021bf31c((u8) (0));
        return;
    }
    v3 = func_ov003_021d2ae8(0x40);
    if (v3 != 0) {
        func_ov003_021cab4c(1);
        return;
    }
    v3 = func_ov003_021d2ae8(0x80);
    if (v3 != 0) {
        func_ov003_021cab4c(3);
        return;
    }
    v3 = func_ov003_021d2ae8(0x20);
    if (v3 != 0) {
        func_ov003_021cab4c(0);
        return;
    }
    v3 = func_ov003_021d2ae8(0x10);
    if (v3 != 0) {
        func_ov003_021cab4c(2);
    }
    return;
}

void func_ov003_021cafa0(void) {
    return;
}
