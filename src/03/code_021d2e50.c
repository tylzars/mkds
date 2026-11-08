#include "03/code_021d2e50.h"
#include "03/code_021d2e68.h"

void func_ov003_021d2e5c(void *list, void *node) {
    u32 value0 = (u32) list;
    u32 nodeAddress = (u32) node;
    u32 value3;
    value0 = (value0) + 8u;
    AddNodeBefore(value0, nodeAddress);
}

void func_ov003_021d2e50(void *list, void *node) {
    u32 value0 = (u32) list;
    u32 nodeAddress = (u32) node;
    u32 value3;
    value0 = *(const u32 *) ((value0) + 4u);
    AddNodeBefore(value0, nodeAddress);
}
