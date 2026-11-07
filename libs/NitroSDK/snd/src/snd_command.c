#include "snd_command.h"
#include "code_0200eddc.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200e77c.h"
#include "code_0214d5b8.h"
#include "snd_work.h"

u32 data_021732cc;
u32 data_021732e8;
SNDCommand *data_021732d8;
SNDCommand *data_021732d0;
SNDCommand *data_021732c8;
SNDCommand *data_021732d4;
s32 data_021732dc;
s32 data_021732e0;
s32 data_021732e4;
SNDCommand *data_021732ec[13];
Unk020217b4 data_02173320;
SNDCommand data_021735a0[256];

// Stores handler and arg in the alarm table entry for alarmNo and returns the id byte of that entry after raising it.
u8 SNDi_SetAlarmHandler(int alarmNo, SNDAlarmHandler handler, void *arg) {
    Unk02021734 *info;

    info = &data_02174da0[alarmNo];
    info->mFunc = handler;
    info->mArg = arg;
    info->mId++;
    return info->mId;
}

// Calls the handler of the alarm in the low byte of alarmNo when the id byte in the next byte is still the entry's id.
void SNDi_CallAlarmHandler(int alarmNo) {
    Unk02021734 *info;

    info = &data_02174da0[alarmNo & 0xff];
    if (((alarmNo >> 8) & 0xff) != info->mId) {
        return;
    }
    if (info->mFunc == 0) {
        return;
    }
    info->mFunc(info->mArg);
}

// Waits for the other processor's side of the command channel, links all records into the free list, clears the
// counters and queues the command that hands over the shared work area.
void SND_CommandInit(void) {
    s32 i;
    SNDCommand *command;

    InitPXI();
    data_021732c8 = data_021735a0;
    for (i = 0; i < 255; i++) {
        data_021735a0[i].mNext = &data_021735a0[i + 1];
    }
    data_021735a0[255].mNext = 0;
    data_021732d8 = &data_021735a0[255];
    data_021732d0 = 0;
    data_021732d4 = 0;
    data_021732e4 = 0;
    data_021732dc = 0;
    data_021732e0 = 0;
    data_021732e8 = 1;
    data_021732cc = 0;
    data_02174e00 = &data_02173320;
    SNDi_InitSharedWork(&data_02173320);
    command = SND_AllocCommand(1);
    if (command == 0) {
        return;
    }
    command->mId = 0x1d;
    command->mArg[0] = (u32) data_02174e00;
    SND_PushCommand(command);
    SND_FlushCommand(1);
}

// Takes the oldest sent command list back into the free list and returns it. With flags bit 0 it waits for the reply,
// otherwise it returns 0 when none has come.
const SNDCommand *SND_RecvCommandReply(u32 flags) {
    u32 enabled;
    SNDCommand *commandList;
    SNDCommand *commandListEnd;
    s32 i;

    enabled = OS_DisableInterrupts();
    if ((flags & 1) != 0) {
        while (data_021732cc == SNDi_GetFinishedCommandTag()) {
            OS_RestoreInterrupts(enabled);
            OS_SpinWait(0x64);
            enabled = OS_DisableInterrupts();
        }
    } else if (data_021732cc == SNDi_GetFinishedCommandTag()) {
        OS_RestoreInterrupts(enabled);
        return 0;
    }
    i = data_021732dc;
    commandList = data_021732ec[i];
    data_021732dc = i + 1;
    if (data_021732dc > 8) {
        data_021732dc = 0;
    }
    commandListEnd = commandList;
    while (commandListEnd->mNext != 0) {
        commandListEnd = commandListEnd->mNext;
    }
    if (data_021732d8 != 0) {
        data_021732d8->mNext = commandList;
    } else {
        data_021732c8 = commandList;
    }
    data_021732d8 = commandListEnd;
    data_021732e4--;
    data_021732cc++;
    OS_RestoreInterrupts(enabled);
    return commandList;
}

// Returns a record from the free list. When there is none and flags bit 0 is set, it flushes or collects replies until
// one is free; without the bit it returns 0.
SNDCommand *SND_AllocCommand(u32 flags) {
    SNDCommand *command;

    if (IsCommandAvailable() == 0) {
        return 0;
    }
    command = AllocCommand();
    if (command != 0) {
        return command;
    }
    if ((flags & 1) == 0) {
        return 0;
    }
    if (SND_CountWaitingCommand() > 0) {
        while (SND_RecvCommandReply(0) != 0) {
        }
        command = AllocCommand();
        if (command != 0) {
            return command;
        }
    } else {
        SND_FlushCommand(1);
    }
    RequestCommandProc();
    do {
        SND_RecvCommandReply(1);
        command = AllocCommand();
    } while (command == 0);
    return command;
}

// Appends the record to the list of commands that wait to be sent.
void SND_PushCommand(SNDCommand *command) {
    u32 enabled;
    SNDCommand *end;

    enabled = OS_DisableInterrupts();
    end = data_021732d4;
    if (end == 0) {
        data_021732d4 = command;
        data_021732d0 = command;
    } else {
        end->mNext = command;
        data_021732d4 = command;
    }
    command->mNext = 0;
    OS_RestoreInterrupts(enabled);
}

// Sends the list of waiting commands to the other processor; returns 1 when sent or when none wait. With flags bit 0 it
// waits until it can send, otherwise it returns 0. Flags bit 1 also requests command processing.
u32 SND_FlushCommand(u32 flags) {
    u32 enabled;

    enabled = OS_DisableInterrupts();
    if (data_021732d0 == 0) {
        OS_RestoreInterrupts(enabled);
        return 1;
    }
    if (data_021732e4 >= 8) {
        if ((flags & 1) == 0) {
            OS_RestoreInterrupts(enabled);
            return 0;
        }
        do {
            SND_RecvCommandReply(1);
        } while (data_021732e4 >= 8);
    }
    DC_FlushRange(data_021735a0, 0x1800);
    if (PXI_SendWordByFifo(7, (u32) data_021732d0, 0) < 0) {
        if ((flags & 1) == 0) {
            OS_RestoreInterrupts(enabled);
            return 0;
        }
        if (PXI_SendWordByFifo(7, (u32) data_021732d0, 0) < 0) {
            do {
                OS_RestoreInterrupts(enabled);
                OS_SpinWait(0x64);
                enabled = OS_DisableInterrupts();
            } while (PXI_SendWordByFifo(7, (u32) data_021732d0, 0) < 0);
        }
    }
    if ((flags & 2) != 0) {
        RequestCommandProc();
    }
    data_021732ec[data_021732e0] = data_021732d0;
    data_021732e0++;
    if (data_021732e0 > 8) {
        data_021732e0 = 0;
    }
    data_021732d0 = 0;
    data_021732d4 = 0;
    data_021732e4++;
    data_021732e8++;
    OS_RestoreInterrupts(enabled);
    return 1;
}

// Returns once the other processor has finished the commands up to tag.
void SND_WaitForCommandProc(u32 tag) {
    if (SND_IsFinishedCommandTag(tag) != 0) {
        return;
    }
    while (SND_RecvCommandReply(0) != 0) {
    }
    if (SND_IsFinishedCommandTag(tag) != 0) {
        return;
    }
    RequestCommandProc();
    if (SND_IsFinishedCommandTag(tag) != 0) {
        return;
    }
    do {
        SND_RecvCommandReply(1);
    } while (SND_IsFinishedCommandTag(tag) == 0);
}

// Returns the tag that the next sent command list will get: the finished tag when no command waits, else the current
// one.
u32 SND_GetCurrentCommandTag(void) {
    u32 enabled;
    u32 tag;

    enabled = OS_DisableInterrupts();
    if (data_021732d0 == 0) {
        tag = data_021732cc;
    } else {
        tag = data_021732e8;
    }
    OS_RestoreInterrupts(enabled);
    return tag;
}

// Returns 1 when tag is not after the finished tag (compared as a wrapping counter).
u32 SND_IsFinishedCommandTag(u32 tag) {
    u32 enabled;
    u32 finished;
    u32 result;

    enabled = OS_DisableInterrupts();
    finished = data_021732cc;
    if (tag > finished) {
        if ((tag - finished) < 0x80000000u) {
            result = 0;
        } else {
            result = 1;
        }
    } else {
        if ((finished - tag) < 0x80000000u) {
            result = 1;
        } else {
            result = 0;
        }
    }
    OS_RestoreInterrupts(enabled);
    return result;
}

// Counts the records in the free list.
s32 SND_CountFreeCommand(void) {
    u32 enabled;
    SNDCommand *command;
    s32 count;

    enabled = OS_DisableInterrupts();
    count = 0;
    for (command = data_021732c8; command != 0; command = command->mNext) {
        count++;
    }
    OS_RestoreInterrupts(enabled);
    return count;
}

// Counts the records in the list of commands that wait to be sent.
s32 SND_CountReservedCommand(void) {
    u32 enabled;
    SNDCommand *command;
    s32 count;

    enabled = OS_DisableInterrupts();
    count = 0;
    for (command = data_021732d0; command != 0; command = command->mNext) {
        count++;
    }
    OS_RestoreInterrupts(enabled);
    return count;
}

// Counts the records that were sent and not yet taken back.
s32 SND_CountWaitingCommand(void) {
    s32 free;

    free = SND_CountFreeCommand();
    return 0x100 - free - SND_CountReservedCommand();
}

// Runs the alarm handler for data with interrupts off.
void PxiFifoCallback(u32 tag, u32 data) {
    u32 enabled;

    enabled = OS_DisableInterrupts();
    SNDi_CallAlarmHandler(data);
    OS_RestoreInterrupts(enabled);
}

// Sets the sound FIFO callback and, when the command channel is available, waits until the other side is ready.
void InitPXI(void) {
    PXI_SetFifoRecvCallback(7, PxiFifoCallback);
    if (IsCommandAvailable() == 0) {
        return;
    }
    if (PXI_IsCallbackReady(7, 1) != 0) {
        return;
    }
    do {
        OS_SpinWait(0x64);
    } while (PXI_IsCallbackReady(7, 1) == 0);
}

// Sends the request-command-processing message until the FIFO takes it.
void RequestCommandProc(void) {
    while (PXI_SendWordByFifo(7, 0, 0) < 0) {
    }
}

// Takes the first record off the free list, or returns 0 when it is empty.
SNDCommand *AllocCommand(void) {
    u32 enabled;
    SNDCommand *command;
    SNDCommand *next;

    enabled = OS_DisableInterrupts();
    command = data_021732c8;
    if (command == 0) {
        OS_RestoreInterrupts(enabled);
        return 0;
    }
    next = command->mNext;
    data_021732c8 = next;
    if (next == 0) {
        data_021732d8 = 0;
    }
    OS_RestoreInterrupts(enabled);
    return command;
}

// Returns 1 unless the port at 0x04fff200 does not answer.
u32 IsCommandAvailable(void) {
    u32 enabled;
    u32 value;

    if (OS_IsRunOnEmulator() == 0) {
        return 1;
    }
    enabled = OS_DisableInterrupts();
    *(vu32 *) 0x04fff200 = 0x10;
    value = *(vu32 *) 0x04fff200;
    OS_RestoreInterrupts(enabled);
    return value != 0;
}
