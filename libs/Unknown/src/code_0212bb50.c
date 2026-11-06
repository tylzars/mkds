#include "code_0212bb50.h"

#include "Main/Unknown/unk_0217d000.h"
#include "code_020207ec.h"

u32 data_0217d440;
u32 data_0217d438;
u32 data_0217d43c;

// Locks the channels in channels unless one of them is already locked.
BOOL NNS_SndLockChannel(u32 channels) {
    if (channels == 0) {
        return 1;
    }
    if (channels & data_0217d440) {
        return 0;
    }
    SND_LockChannel(channels, 0);
    data_0217d440 |= channels;
    return 1;
}

// Unlocks the channels in channels.
void NNS_SndUnlockChannel(u32 channels) {
    if (channels == 0) {
        return;
    }
    SND_UnlockChannel(channels, 0);
    data_0217d440 &= ~channels;
}

// Locks the capture units in captures unless one of them is already locked.
BOOL NNS_SndLockCapture(u32 captures) {
    if (captures & data_0217d438) {
        return 0;
    }
    data_0217d438 |= captures;
    return 1;
}

// Unlocks the capture units in captures.
void NNS_SndUnlockCapture(u32 captures) {
    data_0217d438 &= ~captures;
}

// Returns the number of the first free alarm and marks it used, or -1 when all eight are used.
s32 NNS_SndAllocAlarm(void) {
    s32 alarm;
    u32 bit;

    bit = 1;
    for (alarm = 0; alarm < 8; alarm++) {
        if ((data_0217d43c & bit) == 0) {
            data_0217d43c |= bit;
            return alarm;
        }
        bit <<= 1;
    }
    return -1;
}

// Marks alarm number alarm free.
void NNS_SndFreeAlarm(s32 alarm) {
    data_0217d43c &= ~(1 << alarm);
}

// Clears the channel, capture and alarm locks.
void NNSi_SndInitResourceMgr(void) {
    data_0217d440 = 0;
    data_0217d438 = 0;
    data_0217d43c = 0;
}
