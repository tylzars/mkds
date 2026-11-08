#include "Main/Unknown/code_020b6800.h"
#include "Main/Unknown/code_020364e0.h"

void *RaceHudSubScreenGetCurrentHeap(void) {
    void *value0;
    value0 = GetCurrentHeapCall();
    value0 = GetHeap(value0);
    return value0;
}
