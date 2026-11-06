#include "code_020219e8.h"
#include "code_0200eddc.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_02020e3c.h"

// Links entry index of bank into the list of waveArc, first taking it out of the list of the wave archive it was in.
void SND_AssignWaveArc(Unk02021968 *bank, s32 index, Unk02021968 *waveArc) {
    Unk02021968 *oldArc;
    Unk02021be8 *cur;
    Unk02021be8 *link;
    Unk02021be8 *top;
    Unk02021be8 *next;

    SNDi_LockMutex();
    oldArc = bank->mUnk_18[index].mUnk_00;
    if (oldArc != 0) {
        if (waveArc == oldArc) {
            SNDi_UnlockMutex();
            return;
        }
        cur = oldArc->mUnk_18[0].mUnk_00;
        link = &bank->mUnk_18[index];
        if (link == cur) {
            oldArc->mUnk_18[0].mUnk_00 = bank->mUnk_18[index].mUnk_04;
            DC_StoreRange(bank->mUnk_18[index].mUnk_00, 0x3c);
        } else {
            while (cur != 0) {
                next = cur->mUnk_04;
                if (link == next) {
                    break;
                }
                cur = next;
            }
            cur->mUnk_04 = bank->mUnk_18[index].mUnk_04;
            DC_StoreRange(cur, 8);
        }
    }
    top = waveArc->mUnk_18[0].mUnk_00;
    waveArc->mUnk_18[0].mUnk_00 = &bank->mUnk_18[index];
    bank->mUnk_18[index].mUnk_04 = top;
    bank->mUnk_18[index].mUnk_00 = waveArc;
    SNDi_UnlockMutex();
    DC_StoreRange(bank, 0x3c);
    DC_StoreRange(waveArc, 0x3c);
}

// Takes each of the four entries of bank out of the list of the wave archive it is in.
void SND_DestroyBank(Unk02021968 *bank) {
    s32 i;
    Unk02021968 *waveArchive;
    Unk02021be8 *cur;
    Unk02021be8 *link;
    Unk02021be8 *next;

    SNDi_LockMutex();
    link = &bank->mUnk_18[0];
    for (i = 0; i < 4; i++) {
        waveArchive = bank->mUnk_18[i].mUnk_00;
        if (waveArchive != 0) {
            cur = waveArchive->mUnk_18[0].mUnk_00;
            if (link == cur) {
                waveArchive->mUnk_18[0].mUnk_00 = bank->mUnk_18[i].mUnk_04;
                DC_StoreRange(waveArchive, 0x3c);
            } else {
                while (cur != 0) {
                    next = cur->mUnk_04;
                    if (link == next) {
                        break;
                    }
                    cur = next;
                }
                cur->mUnk_04 = bank->mUnk_18[i].mUnk_04;
                DC_StoreRange(cur, 8);
            }
        }
        link++;
    }
    SNDi_UnlockMutex();
}

// Clears every entry in the list of waveArc.
void SND_DestroyWaveArc(Unk02021968 *waveArc) {
    Unk02021be8 *cur;
    Unk02021be8 *next;

    SNDi_LockMutex();
    cur = waveArc->mUnk_18[0].mUnk_00;
    if (cur != 0) {
        do {
            next = cur->mUnk_04;
            cur->mUnk_00 = 0;
            cur->mUnk_04 = 0;
            DC_StoreRange(cur, 8);
            cur = next;
        } while (next != 0);
    }
    SNDi_UnlockMutex();
}

// Sets pos to the start of the instrument entries.
void SND_GetFirstInstDataPos(Unk02021bc8 *pos) {
    Unk02021bc8 first;

    first.mUnk_00 = 0;
    first.mUnk_04 = 0;
    *pos = first;
}

// Copies the instrument entry at pos into inst and moves pos on; returns 0 when there are no more.
u32 SND_GetNextInstData(Unk02021968 *bank, Unk020219f0 *inst, Unk02021bc8 *pos) {
    u32 entry;
    Unk02021a60 *simple;
    Unk02021aa8 *drumSet;
    Unk02021b24 *keySplit;

    while (pos->mUnk_00 < bank->mUnk_38) {
        entry = bank->mUnk_3c[pos->mUnk_00];
        inst->mUnk_00 = entry;
        switch (inst->mUnk_00) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                simple = (Unk02021a60 *) ((u8 *) bank + (entry >> 8));
                *(Unk02021a5c *) &inst->mUnk_02 = simple->mUnk_00;
                *(Unk02021a5c *) &inst->mUnk_06 = simple->mUnk_04;
                inst->mUnk_0a = simple->mUnk_08;
                pos->mUnk_00++;
                return 1;
            case 0x10:
                drumSet = (Unk02021aa8 *) ((u8 *) bank + (entry >> 8));
                while (pos->mUnk_04 < drumSet->mUnk_01 - drumSet->mUnk_00 + 1) {
                    *(Unk02021ab0 *) inst = drumSet->mUnk_02[pos->mUnk_04];
                    pos->mUnk_04++;
                    return 1;
                }
                break;
            case 0x11:
                keySplit = (Unk02021b24 *) ((u8 *) bank + (entry >> 8));
                while (pos->mUnk_04 < 8) {
                    if (keySplit->mUnk_00[pos->mUnk_04] == 0) {
                        break;
                    }
                    *(Unk02021ab0 *) inst = keySplit->mUnk_08[pos->mUnk_04];
                    pos->mUnk_04++;
                    return 1;
                }
                break;
        }
        pos->mUnk_00++;
        pos->mUnk_04 = 0;
    }
    return 0;
}

// Returns the number of wave data entries of waveArc.
u32 SND_GetWaveDataCount(Unk02021968 *waveArc) {
    return waveArc->mUnk_38;
}
