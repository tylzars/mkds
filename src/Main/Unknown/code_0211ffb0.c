#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0211ffb0.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/code_02036000.h"
#include "00/code_02182fdc.h"
#include "code_0200fc8c.h"

void *func_0211fffc(u32 a, u32 b, s32 c) {
    u32 v;
    void *p;

    v = IrqDisable();
    p = HeapAllocAligned(data_0217d384->mHeap, b, c);
    IrqRestore(v);
    return p;
}

void func_0211ffb0(u32 a, void *b) {
    u32 v;

    if (b == NULL) {
        return;
    }
    v = IrqDisable();
    HeapFree(data_0217d384->mHeap, b);
    IrqRestore(v);
}
