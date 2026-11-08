#include "Main/Unknown/code_020ea514.h"
#include "Main/Unknown/code_02087d0c.h"

#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_02088000.h"

#pragma thumb on

void InitModelAnimationWithEntries(u32 animationKind, void *model, void *animation, void *nsbmdFile,
                                   void *animationFile) {
    void *heap;

    heap = GetHeap(GetCurrentHeapCall());
    InitModelAnimation(animationKind, animation, model, 1, heap, nsbmdFile);
    InitModelAnimationEntries(animation, animationFile, GetHeap(GetCurrentHeapCall()));
    SetModelAnimation(animation, 0);
}

#pragma thumb off
