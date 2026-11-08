#include "Main/Unknown/code_020ec884.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/unk_0216c000.h"

void InitPushedObjectStates(Unk020e43a8 *object) {
    u32 value0 = (u32) object;
    u32 stateTable;
    u32 stateCount;
    u32 owner;
    u32 objectAddress;
    objectAddress = value0;
    stateTable = (u32) &gPushedObjectStateTable;
    owner = objectAddress;
    value0 = (objectAddress) + (0x80u);
    stateCount = 3u;
    InitStateMachine((void *) value0, (UnkFunc *const *) stateTable, stateCount, (void *) owner);
    value0 = 0u;
    *(u16 *) ((objectAddress) + (144)) = value0;
    value0 = 1u;
    *(u16 *) ((objectAddress) + (146)) = value0;
}
