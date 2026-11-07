#include "code_0200cd04.h"
#include "code_0200c914.h"

// Empties the queue of threads waiting for an interrupt.
void OS_InitIrqTable(void) {
    OSThreadQueue *queue;

    queue = &data_027e0000.mUnk_0000;
    queue->mTail = 0;
    queue->mHead = 0;
}
