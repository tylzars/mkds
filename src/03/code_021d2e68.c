#include "03/code_021d2e68.h"
#include "code_0200c914.h"

void RemoveNodeFromList(u32 node) {
    u32 nodeAddress = ((node) + (0x0u));
    u32 savedIrqMask = OS_DisableIrqMask(0x1u);
    u32 next = (*(u32 *) ((nodeAddress) + (4)));
    u32 previous = (*(u32 *) ((nodeAddress) + (0)));
    u32 reloadedPrevious;
    u32 reloadedNext;
    u32 nullLink;
    u32 v14;
    *(u32 *) ((previous) + (4)) = next;
    reloadedPrevious = (*(u32 *) ((nodeAddress) + (0)));
    reloadedNext = (*(u32 *) ((nodeAddress) + (4)));
    *(u32 *) ((reloadedNext) + (0)) = reloadedPrevious;
    *(u32 *) ((nodeAddress) + (4)) = 0x0u;
    nullLink = (*(u32 *) ((nodeAddress) + (4)));
    *(u32 *) ((nodeAddress) + (0)) = nullLink;
    v14 = OS_EnableIrqMask(savedIrqMask);
}

void AddNodeBefore(u32 node, u32 newNode) {
    u32 nodeAddress = ((node) + (0x0u));
    u32 newNodeAddress = ((newNode) + (0x0u));
    u32 savedIrqMask = OS_DisableIrqMask(0x1u);
    u32 previous = (*(u32 *) ((nodeAddress) + (0)));
    u32 reloadedPrevious;
    u32 v12;
    *(u32 *) ((previous) + (4)) = newNodeAddress;
    reloadedPrevious = (*(u32 *) ((nodeAddress) + (0)));
    *(u32 *) ((newNodeAddress) + (0)) = reloadedPrevious;
    *(u32 *) ((newNodeAddress) + (4)) = nodeAddress;
    *(u32 *) ((nodeAddress) + (0)) = newNodeAddress;
    v12 = OS_EnableIrqMask(savedIrqMask);
}
