#include "Main/Unknown/code_0202f744.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/unk_02174000.h"

#pragma thumb on

void func_0202f744(void) {
    HeapDestroy((void *) data_02174e50->mHeap);
    *&data_02174e50 = NULL;
}

#pragma thumb off
