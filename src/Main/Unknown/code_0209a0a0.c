#include "Main/Unknown/code_0209a0a0.h"

#include "Main/Unknown/code_0209a110.h"
#include "Main/Unknown/code_0209a184.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/unk_0217b000.h"

void func_0209a0a0(void *a) {
    func_0209bbd0(a, data_0217b144);
}

void func_0209a0b8(void *a) {
    data_0217b144 = func_0209bd08(a, "Bank_Tree1.nsbmd");
    func_0209b940(data_0217b144, 0x3f);
}

void *func_0209a0ec(void) {
    return (void *) func_0209bef0(func_0209a19c, func_0209a110, func_0209a184);
}
