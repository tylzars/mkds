#include "Main/Unknown/code_020566a8.h"
#include "Main/Unknown/code_02057304.h"
#include "Main/Unknown/code_020574a0.h"
#include "Main/Unknown/code_020578fc.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"

#pragma thumb on

void WriteSlotGhostRecord(u32 index, int source) {
    int slotBit;
    GhostRecord *destination;
    destination = data_0217aa08->mGhostRecords[1];
    *(u32 *) (source + 8) = *(u32 *) (source + 8) & 0xfffffffe | 1;
    MI_CpuCopy8(((u16 *) (u32) source), ((u32 *) destination), (0x00001000u));
    func_02057944(index, destination);
    slotBit = func_020573c8(index);
    if (slotBit == 0) {
        func_0205746c(index, data_0217aa08->mUnk_00->mSlotGhostBits, 2);
        func_020574a0();
    }
}

#pragma thumb off
