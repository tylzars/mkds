#include "Main/Unknown/code_020ea514.h"
#include "Main/Unknown/code_02087d0c.h"

#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_02088000.h"

#pragma thumb on

void func_020ea514(u32 a, void *b, void *c, void *d, void *e) {
    void *p;

    p = GetHeap(GetCurrentHeapCall());
    InitModelAnimation(a, c, b, 1, p, d);
    InitModelAnimationEntries(c, e, GetHeap(GetCurrentHeapCall()));
    SetModelAnimation(c, 0);
}

#pragma thumb off
