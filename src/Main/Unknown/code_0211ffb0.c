#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0211ffb0.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/code_02036000.h"
#include "00/code_021832d8.h"
#include "code_0200fc8c.h"

// Allocator registered with the net layer; the first argument is unused; interrupts off.
void *WiFiSessionHeapAlloc(u32 a, u32 b, s32 c) {
    u32 v;
    void *p;

    v = IrqDisable();
    p = HeapAllocAligned(gWiFiSession->mHeap, b, c);
    IrqRestore(v);
    return p;
}

void WiFiSessionHeapFree(u32 a, void *b) {
    u32 v;

    if (b == NULL) {
        return;
    }
    v = IrqDisable();
    HeapFree(gWiFiSession->mHeap, b);
    IrqRestore(v);
}
