#include "00/code_0219a3f4.h"
#include "00/code_0218e49c.h"

void func_ov000_0219a3f8(u32 *a) {
    if (a[7] != 0) {
        a[5] = 1;
        return;
    }
    func_ov000_0218e53c(*a);
    func_ov000_0218dfb4((int *) ((int *) (u32) (a[3])));
    func_ov000_0218dc48((int *) ((int *) (u32) (a[4])));
    func_ov000_021a3668((void *) ((u32) (a)));
    func_ov000_0218e8b4();
    return;
}

void func_ov000_0219a3f4(int a, u32 b) {
    *(u32 *) (a + 0x20) = b;
    return;
}
