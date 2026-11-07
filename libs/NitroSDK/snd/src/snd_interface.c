#include "snd_interface.h"
#include "snd_command.h"
#include "snd_work.h"

// Stops the sequence on the player.
void SND_StopSeq(int playerNo) {
    PushCommand_impl(1, playerNo, 0, 0, 0);
}

// Loads a sequence into the player without starting it.
void SND_PrepareSeq(int playerNo, const void *base, u32 offset, const void *bank) {
    PushCommand_impl(2, playerNo, (u32) base, offset, (u32) bank);
}

// Starts the sequence that SND_PrepareSeq loaded into the player.
void SND_StartPreparedSeq(int playerNo) {
    PushCommand_impl(3, playerNo, 0, 0, 0);
}

// Sets the tempo ratio of the player (a 2-byte value at offset 0x1a of its record).
void SND_SetPlayerTempoRatio(int playerNo, int ratio) {
    SNDi_SetPlayerParam(playerNo, 0x1a, ratio, 2);
}

// Sets the volume of the player (a 2-byte value at offset 6 of its record).
void SND_SetPlayerVolume(int playerNo, int volume) {
    SNDi_SetPlayerParam(playerNo, 6, volume, 2);
}

// Sets the channel priority of the player (a 1-byte value at offset 4 of its record).
void SND_SetPlayerChannelPriority(int playerNo, int prio) {
    SNDi_SetPlayerParam(playerNo, 4, prio, 1);
}

// Sets local variable varNo of the player.
void SND_SetPlayerLocalVariable(int playerNo, int varNo, int var) {
    PushCommand_impl(0xa, playerNo, varNo, var, 0);
}

// Sets the volume of the tracks in trackBitMask (a 2-byte value at offset 0xa).
void SND_SetTrackVolume(int playerNo, u32 trackBitMask, int volume) {
    SNDi_SetTrackParam(playerNo, trackBitMask, 0xa, volume, 2);
}

// Sets the pitch of the tracks in trackBitMask (a 2-byte value at offset 0xc).
void SND_SetTrackPitch(int playerNo, u32 trackBitMask, int pitch) {
    SNDi_SetTrackParam(playerNo, trackBitMask, 0xc, pitch, 2);
}

// Sets the pan of the tracks in trackBitMask (a 1-byte value at offset 9).
void SND_SetTrackPan(int playerNo, u32 trackBitMask, int pan) {
    SNDi_SetTrackParam(playerNo, trackBitMask, 9, pan, 1);
}

// Sets the modulation speed of the tracks in trackBitMask (a 1-byte value at offset 0x19).
void SND_SetTrackModSpeed(int playerNo, u32 trackBitMask, int speed) {
    SNDi_SetTrackParam(playerNo, trackBitMask, 0x19, speed, 1);
}

// Sets which channels the tracks in trackBitMask may use.
void SND_SetTrackAllocatableChannel(int playerNo, u32 trackBitMask, u32 chBitMask) {
    PushCommand_impl(9, playerNo, trackBitMask, chBitMask, 0);
}

// Starts the channels, captures and alarms in the three bit masks together.
void SND_StartTimer(u32 chBitMask, u32 capBitMask, u32 alarmBitMask, u32 flags) {
    PushCommand_impl(0xc, chBitMask, capBitMask, alarmBitMask, flags);
}

// Counts up the id of each alarm in alarmBitMask, then stops the channels, captures and alarms in the three bit masks.
void SND_StopTimer(u32 chBitMask, u32 capBitMask, u32 alarmBitMask, u32 flags) {
    int alarmNo;
    u32 mask;

    mask = alarmBitMask;
    for (alarmNo = 0; alarmNo < 8 && mask != 0; alarmNo++, mask >>= 1) {
        if (mask & 1) {
            SNDi_IncAlarmId(alarmNo);
        }
    }
    PushCommand_impl(0xd, chBitMask, capBitMask, alarmBitMask, flags);
}

// Sets up capture unit capture to record into buffer; the flags go into the top five bits of one word.
void SND_SetupCapture(int capture, int format, void *buffer, u32 length, u32 loopFlag, u32 in, u32 out) {
    PushCommand_impl(0x11, (u32) buffer, length,
                     (capture << 31) | (format << 30) | (loopFlag << 29) | (in << 28) | (out << 27), 0);
}

// Stores handler and arg for the alarm and sends its timing; the alarm id byte that SNDi_SetAlarmHandler returns goes
// with it.
void SND_SetupAlarm(int alarmNo, u32 tick, u32 period, SNDAlarmHandler handler, void *arg) {
    u32 id;

    id = SNDi_SetAlarmHandler(alarmNo, handler, arg);
    PushCommand_impl(0x12, alarmNo, tick, period, id);
}

// Sets the mute mode of the tracks in trackBitMask.
void SND_SetTrackMuteEx(int playerNo, u32 trackBitMask, int mute) {
    PushCommand_impl(8, playerNo, trackBitMask, mute, 0);
}

// Locks the channels in chBitMask.
void SND_LockChannel(u32 chBitMask, u32 flags) {
    PushCommand_impl(0x1a, chBitMask, flags, 0, 0);
}

// Unlocks the channels in chBitMask.
void SND_UnlockChannel(u32 chBitMask, u32 flags) {
    PushCommand_impl(0x1b, chBitMask, flags, 0, 0);
}

// Sets the volume and data shift of the channels in chBitMask.
void SND_SetChannelVolume(u32 chBitMask, int volume, int shift) {
    PushCommand_impl(0x14, chBitMask, volume, shift, 0);
}

// Sets up channel chNo to play PCM wave data; the settings are packed into the last three words.
void SND_SetupChannelPcm(int chNo, int format, const void *dataaddr, int loop, int loopStart, int loopLen, u32 volume,
                         int shift, int timer, int pan) {
    PushCommand_impl(0xe, chNo | (timer << 16), (u32) dataaddr, (volume << 24) | (shift << 22) | loopLen,
                     (loop << 26) | (format << 24) | (pan << 16) | loopStart);
}

// Tells the sound processor that the sequence data from start to end is gone.
void SND_InvalidateSeqData(const void *start, const void *end) {
    PushCommand_impl(0x1e, (u32) start, (u32) end, 0, 0);
}

// Tells the sound processor that the bank data from start to end is gone.
void SND_InvalidateBankData(const void *start, const void *end) {
    PushCommand_impl(0x1f, (u32) start, (u32) end, 0, 0);
}

// Tells the sound processor that the wave data from start to end is gone.
void SND_InvalidateWaveData(const void *start, const void *end) {
    PushCommand_impl(0x20, (u32) start, (u32) end, 0, 0);
}

// Sets the master volume.
void SND_SetMasterVolume(int volume) {
    PushCommand_impl(0x17, volume, 0, 0, 0);
}

// Sets the output of the left and right mixer and of channels 1 and 3.
void SND_SetOutputSelector(int left, int right, int channel1, int channel3) {
    PushCommand_impl(0x19, left, right, channel1, channel3);
}

// Sets the master pan.
void SND_SetMasterPan(int pan) {
    PushCommand_impl(0x18, pan, 0, 0, 0);
}

// Sets the master pan back to the value of each channel.
void SND_ResetMasterPan(void) {
    PushCommand_impl(0x18, -1, 0, 0, 0);
}

// Sets a size-byte value at offset of the player record.
void SNDi_SetPlayerParam(int playerNo, u32 offset, u32 data, int size) {
    PushCommand_impl(6, playerNo, offset, data, size);
}

// Sets a size-byte value at offset of the record of each track in trackBitMask; the size goes into bits 24 and up of
// the player word.
void SNDi_SetTrackParam(int playerNo, u32 trackBitMask, u32 offset, u32 data, int size) {
    PushCommand_impl(7, playerNo | (size << 24), trackBitMask, offset, data);
}

// Sets the surround decay.
void SNDi_SetSurroundDecay(int decay) {
    PushCommand_impl(0x16, decay, 0, 0, 0);
}

// Takes a command record, fills in the id and four arguments and queues it.
void PushCommand_impl(u32 id, u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    SNDCommand *command;

    command = SND_AllocCommand(1);
    if (command == 0) {
        return;
    }
    command->mId = id;
    command->mArg[0] = arg0;
    command->mArg[1] = arg1;
    command->mArg[2] = arg2;
    command->mArg[3] = arg3;
    SND_PushCommand(command);
}
