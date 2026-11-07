#include "code_020218f4.h"
#include "code_02020e3c.h"
#include "Main/Unknown/unk_02152000.h"

// Returns the entry of waveArc table at index as an address: values below 0x2000000 are offsets from waveArc, others
// are addresses already; an empty entry gives 0.
void *SND_GetWaveDataAddress(Unk02021968 *waveArc, u32 index) {
    u32 entry;
    u8 *address;

    SNDi_LockMutex();
    entry = waveArc->mUnk_3c[index];
    if (entry != 0) {
        address = (u8 *) entry;
        if (entry < 0x2000000) {
            address = (u8 *) waveArc + entry;
        }
    } else {
        address = 0;
    }
    SNDi_UnlockMutex();
    return address;
}

// Converts an attenuation dB (-723 to 0) into a volume byte, with a shift selector in bits 8 and 9.
u16 SND_CalcChannelVolume(s32 dB) {
    u8 volume;
    s32 shift;

    if (dB < -0x2d3) {
        dB = -0x2d3;
    } else if (dB > 0) {
        dB = 0;
    }
    volume = data_02152de4[dB + 0x2d3];
    if (dB < -0xf0) {
        shift = 3;
    } else if (dB < -0x78) {
        shift = 2;
    } else if (dB < -0x3c) {
        shift = 1;
    } else {
        shift = 0;
    }
    return volume | (shift << 8);
}
