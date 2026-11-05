#include "code_0200cd04.h"
#include "code_0200c914.h"

void OS_InitIrqTable(void) {
    Unk027e0000 *p;

    p = &data_027e0000;
    p->mUnk_0000.mTail = 0;
    p->mUnk_0000.mHead = 0;
}
