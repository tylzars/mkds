#include "Main/Unknown/code_02099fbc.h"

#include "Main/Unknown/code_0209a02c.h"
#include "Main/Unknown/code_0209a0a0.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/unk_0217b000.h"

void *func_0209a008(void) {
    return (void *) func_0209bef0(func_0209a0b8, func_0209a02c, func_0209a0a0);
}

void func_02099fd4(void *a) {
    data_0217b118 = func_0209bd08(a, "GardenTree1.nsbmd");
    func_0209b940(data_0217b118, 0x3f);
}

void func_02099fbc(void *a) {
    func_0209bbd0(a, data_0217b118);
}
