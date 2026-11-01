#include "Main/Unknown/code_02028e00.h"
#include "Main/Unknown/code_0214d000.h"

void func_02028e14(void *a, u32 b, u32 c) {
    volatile u32 v = b;
    func_0214d05c(v, a, c);
}

void func_02028e00(void *a, u32 b) {
    func_02028e14(a, 0, b);
}
