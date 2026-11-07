#include "snd_work.h"

#include "snd_command.h"
#include "code_0200eddc.h"
#include "Main/Unknown/code_0200e000.h"

Unk020217b4 *data_02174e00;

// Reads the player status word of the shared work area after invalidating its cache line.
u32 SND_GetPlayerStatus(void) {
    DC_InvalidateRange(&data_02174e00->mPlayerStatus, 4);
    return data_02174e00->mPlayerStatus;
}

// Reads variable varNo of player playerNo from the shared work area after invalidating its cache line.
s16 SND_GetPlayerLocalVariable(s32 playerNo, s32 varNo) {
    DC_InvalidateRange(&data_02174e00->mPlayer[playerNo].mVariable[varNo], 2);
    return data_02174e00->mPlayer[playerNo].mVariable[varNo];
}

// Reads the finished command tag of the shared work area after invalidating its cache line.
u32 SNDi_GetFinishedCommandTag(void) {
    DC_InvalidateRange(data_02174e00, 4);
    return data_02174e00->mFinishCommandTag;
}

// Clears the status words, the tick counters and sets every variable to -1, then writes the area back to memory.
void SNDi_InitSharedWork(Unk020217b4 *work) {
    s32 playerNo;
    s32 variableNo;

    work->mPlayerStatus = 0;
    work->mChannelStatus = 0;
    work->mCaptureStatus = 0;
    work->mFinishCommandTag = 0;
    for (playerNo = 0; playerNo < 16; playerNo++) {
        work->mPlayer[playerNo].mTickCounter = 0;
        for (variableNo = 0; variableNo < 16; variableNo++) {
            work->mPlayer[playerNo].mVariable[variableNo] = -1;
        }
    }
    for (variableNo = 0; variableNo < 16; variableNo++) {
        work->mGlobalVariable[variableNo] = -1;
    }
    DC_FlushRange(work, 0x280);
}

// Clears the handler, argument and id of each of the 8 alarm table entries.
void SND_AlarmInit(void) {
    s32 alarmNo;

    for (alarmNo = 0; alarmNo < 8; alarmNo++) {
        data_02174da0[alarmNo].mFunc = 0;
        data_02174da0[alarmNo].mArg = 0;
        data_02174da0[alarmNo].mId = 0;
    }
}

// Raises the id byte of alarm table entry alarmNo and returns it.
u32 SNDi_IncAlarmId(u32 alarmNo) {
    Unk02021734 *info;
    u32 id;

    info = &data_02174da0[alarmNo];
    id = info->mId + 1;
    info->mId = id;
    return id;
}
