#include "Main/Unknown/code_020f1a24.h"
#include "Main/Unknown/code_020f1a38.h"

#pragma thumb on

void InitItemKinds(void) {
    CreateItemKinds();
    ComputeItemKindObjectCounts();
}

#pragma thumb off
