#include "code_0201750c.h"
#include "code_0212da1c.h"

#include "Main/Unknown/code_0212da2c.h"

u32 func_0212da2c(HeapStack *arg0) {
    u32 value0 = (u32) arg0;
    value0 = (u32) * (const u16 *) ((value0) + (12));
    value0 = (value0) - (1u);
    return value0;
}

void func_0212da1c(LinkedList *arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value12;
    value12 = (u32) &ListInit;
    value1 = 0u;
    ListInit((LinkedList *) value0, (u16) value1);
}
