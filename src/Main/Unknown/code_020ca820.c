#include "Main/Unknown/code_020ca820.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_020cab8c.h"

#pragma thumb on
void func_020ca83c(void) {
    u32 unusedValue;
    func_020cab8c();
}
#pragma thumb off

void *func_020ca820(void) {
    void *value0;
    value0 = GetCurrentHeapCall();
    value0 = GetHeap(value0);
    return value0;
}
