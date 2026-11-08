#include "Main/Unknown/code_0205a548.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f813c.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_0214d000.h"
#include "00/code_0219b580.h"
#include "code_0214d018.h"

void AddItemData(u32 itemKind, u32 messageKind, void *data, u8 size) {
    ItemDataSlot *slot;
    u16 slotIndex;

    for (slotIndex = 0; slotIndex < 16; slotIndex++) {
        slot = &data_0217aa14->mUnk_324[slotIndex];
        if (slot->mUnk_08 == 0) {
            goto found;
        }
    }
    slot = NULL;
found:
    slot->mItemKind = itemKind;
    slot->mMessageKind = messageKind;
    slot->mUnk_08 = 1;
    slot->mUnk_00 = data_0217aa14->mUnk_728 + 0x28;
    MI_CpuFill8(slot->mData, 0, 20);
    if (size == 0) {
        slot->mDataSize = 0;
        return;
    }
    MI_CpuCopy8(data, slot->mData, size);
    slot->mDataSize = size;
}

void func_0205a7dc(s32 participantIndex, u16 remaining, s32 itemIndex, s32 state) {
    Unk0217aa14_754_04_20 *entry;

    entry = &((Unk0217aa14_754_04 *) (void *) &data_0217aa14->mUnk_754->mUnk_04)->mUnk_20[participantIndex];
    entry->mUnk_00_0 = remaining;
    entry->mUnk_00_7 = itemIndex;
    entry->mUnk_00_12 = state;
}

void func_0205a7ac(s32 participantIndex) {
    Unk0217aa14_754_04 *p = (void *) &data_0217aa14->mUnk_754->mUnk_04;
    MI_CpuFill8(&p->mUnk_20[participantIndex], 0, 2);
}

void func_0205a750(s32 itemIndex) {
    Unk0217aa14_104_68 *view;
    s32 t;

    view = &data_0217aa14->mUnk_104[func_ov000_0219bb50()].mUnk_68_view;
    view->mUnk_0e = 0;
    t = data_0217aa14->mUnk_728;
    view->mUnk_0c = 2;
    view->mUnk_00 = itemIndex;
    view->mUnk_08 = t + 0x78;
    view->mUnk_04 = 0x13;
}

void func_0205a71c(s32 participantIndex) {
    func_020f86c4(&gKartItems[(u8) data_0217aa18->mKartOfParticipant[participantIndex]]);
}

void func_0205a6b4(void) {
    u16 participantIndex;
    Unk0217aa14_104_68 *view;

    for (participantIndex = 0; participantIndex < 4;) {
        view = &data_0217aa14->mUnk_104[participantIndex].mUnk_68_view;
        participantIndex++;
        view->mUnk_00 = 0x13;
        view->mUnk_04 = 0x13;
        view->mUnk_08 = 0;
        view->mUnk_0c = 0;
        view->mUnk_10 = 0x13;
        view->mUnk_14 = 0;
    }
}

s32 func_0205a630(s32 participantIndex) {
    BOOL result;
    s32 itemInfoIndex;

    itemInfoIndex = data_0217aa14->mUnk_104[participantIndex].mUnk_6c;
    result = FALSE;
    if (func_020efd84(&gKartItems[(u8) data_0217aa18->mKartOfParticipant[participantIndex]], itemInfoIndex) != FALSE) {
        data_0217aa14->mUnk_104[participantIndex].mUnk_6c = 0x13;
        result = TRUE;
    }
    return result;
}

void func_0205a5b0(u32 participantIndex) {
    Unk0217aa14_104_68 *view;

    view = &data_0217aa14->mUnk_104[participantIndex].mUnk_68_view;
    if (view->mUnk_0c != 0) {
        return;
    }
    view->mUnk_04 = 0x13;
    ResetHeldItem(&gKartItems[(u16) data_0217aa18->mKartOfParticipant[participantIndex]].mHeldItem);
}

void func_0205a548(s32 participantIndex, s32 itemInfoIndex, s32 count) {
    Unk0217aa14_104_68 *view;

    view = &data_0217aa14->mUnk_104[participantIndex].mUnk_68_view;
    view->mUnk_00 = itemInfoIndex;
    view->mUnk_04 = itemInfoIndex;
    SetHeldItemWithCount(&gKartItems[(u16) data_0217aa18->mKartOfParticipant[participantIndex]].mHeldItem,
                         itemInfoIndex, count);
}
