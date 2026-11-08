#include "Main/Unknown/code_0200b1b0.h"
#include "Main/Unknown/code_02008934.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"

#pragma thumb on

u32 func_0200b1b0(u32 index, struct Unk0217aa00_24 *destination) {
    u32 savedInterrupts;
    Unk02008934 *entry;
    if (16 <= index) {
        return 0;
    }
    savedInterrupts = ((s64) OS_DisableInterrupts());
    entry = func_02008934(index);
    if (entry == NULL) {
        OS_RestoreInterrupts(savedInterrupts);
        return 0;
    }
    MI_CpuCopy8(entry->mUnk_4c0, ((u32 *) (u32) destination), 0xc0);
    OS_RestoreInterrupts(savedInterrupts);
    return 1;
}

#pragma thumb off
