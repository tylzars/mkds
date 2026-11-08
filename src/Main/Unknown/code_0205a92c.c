#include "Main/Unknown/code_0205a92c.h"
#include "Main/Unknown/code_0205a548.h"
#include "Main/Unknown/code_0205b0f4.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_020fe4b4.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "00/code_0219b580.h"
#include "code_0214d018.h"

void func_0205ae8c(u32 kartIndex) {
    u8 otherKartIndex;
    u8 rank;
    u8 f;
    u8 otherRank;
    s32 participantIndex;
    s32 otherParticipantIndex;
    ParticipantKartMap *g;
    Unk0217aa14 *p;

    g = gParticipantKartMap;
    p = data_0217aa14;
    participantIndex = g->mParticipantOfKart[(u8) kartIndex];
    rank = p->mUnk_104[participantIndex].mRank;
    if (participantIndex < 0) {
        return;
    }
    otherKartIndex = 0;
    for (otherKartIndex = 0; otherKartIndex < (s32) gRaceSetup->mKartCount; otherKartIndex++) {
        if (otherKartIndex != kartIndex) {
            otherParticipantIndex = g->mParticipantOfKart[otherKartIndex];
            otherRank = p->mUnk_104[otherParticipantIndex].mRank;
            if (otherParticipantIndex >= 0 && otherRank < rank) {
                f = 0;
                if ((p->mUnk_0fc & (1 << (u8) otherParticipantIndex)) != 0 &&
                    (p->mUnk_749 & (1 << (u8) otherParticipantIndex)) == 0) {
                    f = 1;
                }
                if (f != 0) {
                    rank = rank - 1;
                }
            }
        }
    }
    p->mUnk_104[participantIndex].mRank = rank;
}

void ResetItemDataSlots(void) {
    s32 slotIndex;
    s32 participantIndex;
    ItemDataSlot *slot;

    for (slotIndex = 0; slotIndex < 16; slotIndex++) {
        for (participantIndex = 0; participantIndex < 4; participantIndex++) {
            slot = &data_0217aa14->mUnk_3e4[slotIndex][participantIndex];
            slot->mUnk_08 = 0;
            slot->mUnk_00 = 0;
            slot->mItemKind = 15;
            slot->mMessageKind = 0;
            slot->mDataSize = 0;
            MI_CpuFill8(slot->mData, 0, 20);
            data_0217aa14->mUnk_6e4[slotIndex][participantIndex] = 0;
        }
        slot = &data_0217aa14->mUnk_324[slotIndex];
        slot->mUnk_08 = 0;
        slot->mUnk_00 = 0;
        slot->mItemKind = 15;
        slot->mMessageKind = 0;
        slot->mDataSize = 0;
        MI_CpuFill8(slot->mData, 0, 20);
    }
    data_0217aa14->mUnk_724 = 0x30;
}

BOOL IsAnyItemDataSlotFree(void) {
    u16 slotIndex;

    for (slotIndex = 0; slotIndex < 16; slotIndex++) {
        if (data_0217aa14->mUnk_324[slotIndex].mUnk_08 == 0) {
            return TRUE;
        }
    }
    return FALSE;
}

void func_0205ac38(void) {
    u16 slotIndex;
    u8 *headerCursor;
    u8 *dataCursor;
    u16 usedSize;
    ItemDataSlot *slot;
    Unk0217aa14_754_04 *q;
    u8 headerByte;

    usedSize = 0;
    q = (void *) &data_0217aa14->mUnk_754->mUnk_04;
    headerCursor = q->mUnk_28;
    dataCursor = headerCursor + 16;
    for (slotIndex = 0; slotIndex < 16; slotIndex++) {
        slot = &data_0217aa14->mUnk_324[slotIndex];
        if (slot->mUnk_08 == 0 || slot->mUnk_08 == 2 || slot->mItemKind == 15) {
            headerByte = 15;
        } else {
            headerByte = (slot->mItemKind & 0x1f) | ((slot->mMessageKind << 5) & 0xe0);
        }
        *headerCursor++ = headerByte;
        switch (slot->mUnk_08) {
            case 0:
                break;
            case 1:
                if (slot->mDataSize != 0 && 0x30 - (usedSize + slot->mDataSize) >= 0) {
                    MI_CpuCopy8(slot->mData, dataCursor, slot->mDataSize);
                    usedSize = usedSize + slot->mDataSize;
                    dataCursor += slot->mDataSize;
                }
                break;
            case 2:
                break;
        }
    }
    data_0217aa14->mUnk_724 = 0x30 - usedSize;
}

void ExpireItemDataSlots(void) {
    u16 slotIndex;
    ItemDataSlot *slot;

    for (slotIndex = 0; slotIndex < 16; slotIndex++) {
        slot = &data_0217aa14->mUnk_324[slotIndex];
        if (slot->mItemKind == 15) {
            continue;
        }
        switch (slot->mUnk_08) {
            case 0:
                break;
            case 2:
                if (slot->mUnk_00 + 30 < (u32) data_0217aa14->mUnk_728) {
                    slot->mUnk_08 = 0;
                    slot->mUnk_00 = 0;
                    slot->mItemKind = 15;
                    slot->mMessageKind = 0;
                    slot->mDataSize = 0;
                    MI_CpuFill8(slot->mData, 0, 20);
                }
                break;
            case 1:
                if (slot->mUnk_00 < (u32) data_0217aa14->mUnk_728) {
                    slot->mUnk_08 = 2;
                }
                break;
        }
    }
}

void func_0205aa60(void) {
    u8 participantIndex;
    u16 slotIndex;
    u8 *headerCursor;
    u8 *dataCursor;
    ItemDataSlot *slot;
    u8 headerByte;

    for (participantIndex = 0; participantIndex < 4; participantIndex++) {
        if (participantIndex != func_ov000_0219bb50() && (data_0217aa14->mUnk_749 & (1 << participantIndex)) != 0 &&
            data_0217aa14->mUnk_104[participantIndex].mUnk_86_0 != 0) {
            headerCursor = (u8 *) &data_0217aa14->mUnk_104[participantIndex] + 0x28;
            dataCursor = headerCursor + 16;
            for (slotIndex = 0; slotIndex < 16; slotIndex++) {
                headerByte = *headerCursor++;
                slot = &data_0217aa14->mUnk_3e4[slotIndex][participantIndex];
                slot->mItemKind = headerByte & 0x1f;
                slot->mMessageKind = (headerByte & 0xe0) >> 5;
                if (slot->mItemKind == 15) {
                    slot->mDataSize = 0;
                } else {
                    slot->mDataSize = func_020fa0e8(slot->mItemKind, slot->mMessageKind);
                }
                if (slot->mDataSize != 0) {
                    MI_CpuCopy8(dataCursor, slot->mData, slot->mDataSize);
                    dataCursor += slot->mDataSize;
                }
            }
        }
    }
}

void ProcessOtherParticipantItemData(void) {
    u8 participantIndex;
    u16 slotIndex;
    Unk0217aa14 *p;
    ItemDataSlot *slot;
    u8 *handledFlag;
    u8 *data;

    for (participantIndex = 0; participantIndex < 4; participantIndex++) {
        if (participantIndex != func_ov000_0219bb50() && (data_0217aa14->mUnk_749 & (1 << participantIndex)) != 0 &&
            data_0217aa14->mUnk_104[participantIndex].mUnk_86_0 != 0) {
            for (slotIndex = 0; slotIndex < 16; slotIndex++) {
                p = data_0217aa14;
                slot = &p->mUnk_3e4[slotIndex][participantIndex];
                handledFlag = &p->mUnk_6e4[slotIndex][participantIndex];
                if (slot->mItemKind == 15) {
                    *handledFlag = 0;
                } else if (*handledFlag == 0) {
                    data = NULL;
                    func_0205b954(participantIndex);
                    if (slot->mDataSize != 0) {
                        data = slot->mData;
                    }
                    if (slot->mMessageKind <= 1) {
                        func_0205a630(participantIndex);
                    }
                    func_020fe5b8(slot->mItemKind, slot->mMessageKind, data,
                                  gParticipantKartMap->mKartOfParticipant[participantIndex]);
                    *handledFlag = 1;
                }
            }
        }
    }
}
