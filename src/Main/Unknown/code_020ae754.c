#include "Main/Unknown/code_020ae754.h"
#include "Main/Unknown/code_020364e0.h"

u32 func_020ae754(void) {
    u32 value0;
    value0 = (u32) GetCurrentHeapCall();
    value0 = (u32) GetHeap((void *) value0);
    return value0;
}
