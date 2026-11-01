#include "Main/Unknown/code_02029a38.h"
#include "Main/Unknown/code_0214d000.h"

void func_02029a4c(void *a, u32 b, u32 c) {
    volatile u32 v = b;
    func_0214d05c(v, a, c);
}

void func_02029a38(void *a, u32 b) {
    func_02029a4c(a, 0, b);
}
