#include "code_020176b0.h"
#include "code_020176c0.h"

// Sets the group ID that new blocks of the Exp heap are tagged with and returns the previous one.
u16 NNS_FndSetGroupIDForExpHeap(NNSFndHeapHandle heap, u16 groupID) {
    NNSiFndExpHeapHead *expHeap;
    u16 oldId;

    expHeap = (NNSiFndExpHeapHead *) (heap + 1);
    oldId = expHeap->mGroupID;
    expHeap->mGroupID = groupID;
    return oldId;
}
