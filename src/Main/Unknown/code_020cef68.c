#include "Main/Unknown/code_020cef68.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0214d018.h"

void func_020cef7c(void *dest, u32 value, u32 size) {
    volatile u32 valueCopy = value;
    MIi_CpuClearFast(valueCopy, dest, size);
}

void func_020cef68(void *dest, u32 size) {
    func_020cef7c(dest, 0, size);
}
