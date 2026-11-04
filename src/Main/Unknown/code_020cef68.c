#include "Main/Unknown/code_020cef68.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0214d018.h"

void func_020cef7c(void *a, u32 b, u32 c) {
    volatile u32 v = b;
    MemFillWordsByBlock(v, a, c);
}

void func_020cef68(void *a, u32 b) {
    func_020cef7c(a, 0, b);
}
