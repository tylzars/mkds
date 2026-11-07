#include "Main/Unknown/code_020562b4.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_02056d54.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

void CombineParticipantBits(void) {
    u8 i;
    u8 j;
    u8 value;
    u8 *bitsByte;
    Unk0217aa00_45c *entry;

    ClearParticipantBits();
    for (i = 0; i < 8; i++) {
        if ((data_0217aa00->mParticipantMask & (1 << i)) != 0) {
            for (j = 0; j < 4; j++) {
                entry = &data_0217aa00->mUnk_045c[i];
                bitsByte = &entry->mBits[j];
                if (i == 0) {
                    data_0217aa08->mParticipantAndBits[j] = *bitsByte;
                    data_0217aa08->mParticipantOrBits[j] = *bitsByte;
                } else {
                    data_0217aa08->mParticipantAndBits[j] &= *bitsByte;
                    data_0217aa08->mParticipantOrBits[j] |= *bitsByte;
                }
            }
            entry = &data_0217aa00->mUnk_045c[i];
            value = func_02056dac(entry->mBits);
            if (i == 0) {
                data_0217aa08->mParticipantMaxValue = value;
                data_0217aa08->mParticipantMinValue = value;
            } else {
                if (value > data_0217aa08->mParticipantMaxValue) {
                    data_0217aa08->mParticipantMaxValue = value;
                }
                if (value < data_0217aa08->mParticipantMinValue) {
                    data_0217aa08->mParticipantMinValue = value;
                }
            }
        }
    }
}

void ClearParticipantBits(void) {
    u8 i;

    for (i = 0; i < 4; i++) {
        data_0217aa08->mParticipantAndBits[i] = 0;
        data_0217aa08->mParticipantOrBits[i] = 0;
    }
    data_0217aa08->mParticipantMaxValue = 0;
    data_0217aa08->mParticipantMinValue = 0;
}
#pragma thumb off
