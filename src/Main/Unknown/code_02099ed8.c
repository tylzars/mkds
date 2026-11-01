#include "Main/Unknown/code_02099ed8.h"

#include "Main/Unknown/code_02099f48.h"
#include "Main/Unknown/code_02099fbc.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/unk_0217b000.h"

void func_02099ed8(void *a) {
    func_0209bbd0(a, data_0217b124);
}

void func_02099ef0(void *a) {
    data_0217b124 = func_0209bd08(a, "TownTree1.nsbmd");
    func_0209b940(data_0217b124, 0x3f);
}

void *func_02099f24(void) {
    return (void *) func_0209bef0(func_02099fd4, func_02099f48, func_02099fbc);
}
