#include "Main/Unknown/code_02057ed8.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/unk_0217a000.h"
#include "os_thread.h"

void (*func_02057f8c(Unk0217aa0c *queue))(void) {
    void (**lastFilledSlot)(void) = NULL;
    void (*callback)(void) = NULL;
    s32 filledCount = 0;
    s32 slot;
    u8 startSlot = queue->mUnk_28;
    do {
        slot = startSlot - filledCount;
        if (slot < 0) {
            slot += 10;
        }
        if (queue->mUnk_00[slot] == NULL) {
            break;
        }
        filledCount++;
        lastFilledSlot = &queue->mUnk_00[slot];
    } while (filledCount < 10);
    if (lastFilledSlot != NULL) {
        callback = *lastFilledSlot;
        *lastFilledSlot = NULL;
    }
    return callback;
}

void func_02057ed8(void *heap) {
    Unk0217aa0c *queue;
    s32 i;
    data_0217aa0c = HeapAlloc(heap, 0xfc);
    data_0217aa0c->mUnk_f4 = HeapAllocAligned(heap, 0x800, 0x20);
    OS_CreateThread(&data_0217aa0c->mUnk_2c, func_02057e8c, NULL, (u8 *) data_0217aa0c->mUnk_f4 + 0x800, 0x800, 0x11);
    OS_WakeupThreadDirect(&data_0217aa0c->mUnk_2c);
    data_0217aa0c->mUnk_f8 = 0;
    queue = data_0217aa0c;
    for (i = 0; i < 10; i++) {
        queue->mUnk_00[i] = NULL;
    }
    queue->mUnk_28 = 0;
}
