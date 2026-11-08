#include "03/code_021d2e50.h"
#include "03/code_021d2e68.h"

void AddNodeToListBack(void *list, void *node) {
    u32 value0 = (u32) list;
    u32 nodeAddress = (u32) node;
    u32 unused;
    value0 = (value0) + 8u;
    AddNodeBefore(value0, nodeAddress);
}

void AddNodeToListFront(void *list, void *node) {
    u32 value0 = (u32) list;
    u32 nodeAddress = (u32) node;
    u32 unused;
    value0 = *(const u32 *) ((value0) + 4u);
    AddNodeBefore(value0, nodeAddress);
}
