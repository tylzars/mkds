#include "03/code_021b7bb4.h"
#include "03/code_021b7000.h"
#include "03/unk_021d8000.h"
#include "Main/Unknown/code_02133000.h"

#include "code_02133048.h"
#include "code_0214d018.h"
#include "code_0214d93c.h"
#include "00/code_021ad734.h"
#include "03/code_021b94b8.h"
#include "00/code_021a8aa8.h"
#include "00/unk_021b6000.h"
#include "03/unk_021d7000.h"
#include "00/code_021a6d5c.h"

s32 GetErrorCode(void) {
    u32 errorCode;
    errorCode = (u32) &gErrorCode;
    errorCode = *(const u32 *) ((errorCode) + 0u);
    return errorCode;
}

s32 CheckAndCopyValueRecordsToRequest(ValueRecordsRequest *request) {
    u8 *recordBytes = (u8 *) request + 0x117;
    ParsedRecordView *fourValueRecord0 = &gParsedFourValueRecord0;
    ParsedRecordView *fourValueRecord1 = &gParsedFourValueRecord1;
    ParsedRecordView *singleValueRecord0 = &gParsedSingleValueRecord0;
    ParsedRecordView *singleValueRecord1 = &gParsedSingleValueRecord1;
    if (recordBytes == NULL) {
        return -1;
    }
    request->mWantedRecordMask = gRequestState.mWantedRecordMask & gRequestState.mFoundRecordMask;
    FillBytes(recordBytes, 0, 0x154);
    if (request->mWantedRecordMask & 1) {
        CopyBytes(recordBytes, fourValueRecord0->mValue0, fourValueRecord0->mValueLength);
        CopyBytes(recordBytes + 6, fourValueRecord0->mValue1, fourValueRecord0->mValueLength);
        CopyBytes(recordBytes + 0xc, fourValueRecord0->mValue2, fourValueRecord0->mValueLength);
        CopyBytes(recordBytes + 0x12, fourValueRecord0->mValue3, fourValueRecord0->mValueLength);
        if (CheckBytesInRange0x20To0x7f(fourValueRecord0->mString, GetStringLength(fourValueRecord0->mString)) != 0) {
            goto fail;
        }
        CopyBytes(recordBytes + 0x18, fourValueRecord0->mString, GetStringLength(fourValueRecord0->mString));
    }
    if (request->mWantedRecordMask & 2) {
        CopyBytes(recordBytes + 0x39, fourValueRecord1->mValue0, fourValueRecord1->mValueLength);
        CopyBytes(recordBytes + 0x47, fourValueRecord1->mValue1, fourValueRecord1->mValueLength);
        CopyBytes(recordBytes + 0x55, fourValueRecord1->mValue2, fourValueRecord1->mValueLength);
        CopyBytes(recordBytes + 0x63, fourValueRecord1->mValue3, fourValueRecord1->mValueLength);
        if (CheckBytesInRange0x20To0x7f(fourValueRecord1->mString, GetStringLength(fourValueRecord1->mString)) != 0) {
            goto fail;
        }
        CopyBytes(recordBytes + 0x71, fourValueRecord1->mString, GetStringLength(fourValueRecord1->mString));
    }
    if (request->mWantedRecordMask & 4) {
        if (CheckBytesInRange0x20To0x7f(singleValueRecord0->mValue0, singleValueRecord0->mValueLength - 1) != 0) {
            goto fail;
        }
        CopyBytes(recordBytes + 0x92, singleValueRecord0->mValue0, singleValueRecord0->mValueLength);
        if (CheckBytesInRange0x20To0x7f(singleValueRecord0->mString, GetStringLength(singleValueRecord0->mString)) !=
            0) {
            goto fail;
        }
        CopyBytes(recordBytes + 0xd2, singleValueRecord0->mString, GetStringLength(singleValueRecord0->mString));
    }
    if (request->mWantedRecordMask & 8) {
        if (CheckBytesInRange0x20To0x7f(singleValueRecord1->mValue0, singleValueRecord1->mValueLength - 1) != 0) {
            goto fail;
        }
        CopyBytes(recordBytes + 0xf3, singleValueRecord1->mValue0, singleValueRecord1->mValueLength);
        if (CheckBytesInRange0x20To0x7f(singleValueRecord1->mString, GetStringLength(singleValueRecord1->mString)) !=
            0) {
            goto fail;
        }
        CopyBytes(recordBytes + 0x133, singleValueRecord1->mString, GetStringLength(singleValueRecord1->mString));
    }
    request->mResultCode = 0;
    return 0;
fail:
    FillBytes(recordBytes, 0, 0x154);
    return -1;
}

s32 CheckBytesInRange0x20To0x7f(const u8 *bytes, s32 count) {
    s32 i;
    for (i = 0; i < count; i++) {
        u32 value = *bytes++;
        if (value < 0x20 || value > 0x7f) {
            return -1;
        }
    }
    return 0;
}

typedef struct PacketHeaderPrefix {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 pad_02[4];
    /* 06 */ u16 mKind;
    /* 08 */ u8 pad_08[7];
    /* 0f */ u8 mUnk_0f;
} PacketHeaderPrefix;

// Returns 0 when exactly one entry with bit 0 of mUnk_50 holds the gEssidAossString bytes, 4 for several, 5 for none.
s32 CheckSingleEssidAossEntry(EssidEntryList *entryList) {
    s32 count;
    s32 result;
    s32 i;
    s32 matchCount;
    result = 0;
    matchCount = 0;
    count = entryList->mCount;
    if (count == 0) {
        return 5;
    }
    if ((u32) count > 0x40) {
        count = 0x40;
    }
    for (i = 0; i < count; i++) {
        if (entryList->mEntries[i].mUnk_50 & 1) {
            if (entryList->mEntries[i].mEssidLength == GetStringLength(gEssidAossString)) {
                if (CompareBytes(entryList->mEntries[i].mEssid, gEssidAossString, GetStringLength(gEssidAossString)) ==
                    0) {
                    matchCount++;
                }
            }
        }
    }
    if (matchCount > 1) {
        result = 4;
    }
    if (matchCount == 0) {
        result = 5;
    }
    return result;
}

s32 FillEssidAossAndMelcoRequest(EssidMelcoRequest *request) {
    request->mEssidLength = GetStringLength(gEssidAossString);
    CopyBytes(request->mEssid, gEssidAossString, request->mEssidLength);
    request->mUnk_24 = TRUE;
    request->mMelcoLength = GetStringLength(gMelcoString);
    if ((u32) request->mMelcoLength > 0xd) {
        return -1;
    }
    CopyBytes(request->mMelcoBytes, gMelcoString, request->mMelcoLength);
    return 0;
}

void FillPacketTags(s32 count, PacketTag *tags, const u8 *tagBytes) {
    s32 i;
    for (i = 0; i < count; i++) {
        CopyBytes(tags, tagBytes, 6);
        tags->mSequence = NextRandomValue();
        tags->mSequence = func_ov003_021b7c94(tags->mSequence);
        tags++;
    }
}

s32 ReportStateChange(s32 state) {
    BOOL result = FALSE;
    if (state == -1) {
        gReportedState = state;
        return result;
    }
    if (gReportedState != state) {
        gReportedState = state;
        return func_ov003_021ba18c(state);
    }
    return result;
}

s32 AdvanceStepByKind(s32 mode, PacketBuffer *buffer, s32 *attempts, PacketTag *list, s32 descriptor) {
    PacketHeaderPrefix *header = (PacketHeaderPrefix *) buffer->mBytes;
    u32 kind;
    if (SwapBytes16(header->mUnk_00) < 1) {
        *attempts = *attempts + 1;
        return mode;
    }
    if (header->mUnk_0f != 0x11) {
        *attempts = *attempts + 1;
        return mode;
    }
    if (CheckPacketAndXorPayload((Packet *) buffer->mBytes) > 0) {
        *attempts = *attempts + 1;
        return mode;
    }
    kind = SwapBytes16(header->mKind);
    switch (kind) {
        case 0x1010:
            mode = AdvanceStepForKind1010(mode, buffer, attempts, list);
            break;
        case 0x2010:
            mode = AdvanceStepForKind2010(mode, buffer, attempts, list);
            break;
        case 0x3010:
            mode = AdvanceStepForKind3010(mode, buffer, attempts, list);
            break;
    }
    return mode;
}

s32 AdvanceStepForKind1010(s32 mode, PacketBuffer *buffer, s32 *attempts, PacketTag *list) {
    Packet *packet;
    Unk021b7cec *payload;
    u32 *valuePointer;
    s32 result;
    if (mode != 0) {
        (*attempts)++;
        return mode;
    }
    packet = (Packet *) buffer->mBytes;
    payload = (Unk021b7cec *) &buffer->mBytes[0x18];
    result = XorSwapAndCheckTag(&list[0], &packet->mTag);
    if (result < 0) {
        (*attempts)++;
        return mode;
    }
    if (SwapBytes16(payload->mUnk_02) == 0) {
        (*attempts)++;
        return mode;
    }
    if (payload->mUnk_00 == 7) {
        valuePointer = &payload->mUnk_04;
        if (func_ov003_021b7c5c(payload->mUnk_04) == -2) {
            SetErrorCode(0x14);
        } else if (func_ov003_021b7c5c(*valuePointer) == -3) {
            SetErrorCode(0x15);
        } else {
            SetErrorCode(0x18);
        }
        return -1;
    }
    if (payload->mUnk_00 != 1) {
        (*attempts)++;
        return mode;
    }
    result = ParseItemChain((PacketItem *) &payload->mUnk_04, gItemSlots);
    if (result < 0) {
        if (result == -2) {
            SetErrorCode(0x16);
            return -1;
        }
        (*attempts)++;
        return mode;
    }
    gFlagBit4OfKind1010Packet = IsBit4Set(SwapBytes16(packet->mFlags));
    *attempts = 0;
    return 1;
}

s32 AdvanceStepForKind2010(s32 mode, PacketBuffer *buffer, s32 *attempts, PacketTag *list) {
    Packet *packet;
    Unk021b7cec *payload;
    s32 result;
    if (mode != 1) {
        (*attempts)++;
        return mode;
    }
    packet = (Packet *) buffer->mBytes;
    payload = (Unk021b7cec *) &buffer->mBytes[0x18];
    result = XorSwapAndCheckTag(&list[1], &packet->mTag);
    if (result < 0) {
        (*attempts)++;
        return mode;
    }
    if (SwapBytes16(payload->mUnk_02) == 0) {
        (*attempts)++;
        return mode;
    }
    if (payload->mUnk_00 == 7) {
        if (func_ov003_021b7c5c(payload->mUnk_04) == -2) {
            SetErrorCode(0x14);
        } else if (func_ov003_021b7c5c(payload->mUnk_04) == -3) {
            SetErrorCode(0x15);
        } else {
            SetErrorCode(0x18);
        }
        return -1;
    }
    FillBytes(gParsedItems, 0, 0x6a0);
    result = FindItemAndParseSubItems(0, (PacketItem *) payload, SwapBytes16(packet->mPayloadLength), gParsedItems,
                                      gItemSlots);
    if (result < 0) {
        (*attempts)++;
        return mode;
    }
    if ((gRequestState.mFoundRecordMask & gRequestState.mWantedRecordMask) == 0) {
        return mode;
    }
    *attempts = 0;
    return 2;
}

s32 AdvanceStepForKind3010(s32 mode, PacketBuffer *buffer, s32 *attempts, PacketTag *list) {
    Packet *packet;
    Unk021b7cec *payload;
    s32 result;
    if (mode != 2) {
        (*attempts)++;
        return mode;
    }
    packet = (Packet *) buffer->mBytes;
    payload = (Unk021b7cec *) &buffer->mBytes[0x18];
    result = XorSwapAndCheckTag(&list[2], &packet->mTag);
    if (result < 0) {
        (*attempts)++;
        return mode;
    }
    if (payload->mUnk_00 != 7) {
        (*attempts)++;
        return mode;
    }
    if (SwapBytes16(payload->mUnk_02) == 0) {
        (*attempts)++;
        return mode;
    }
    if (func_ov003_021b7c5c(payload->mUnk_04) == 0) {
        return 0x64;
    }
    if (func_ov003_021b7c5c(payload->mUnk_04) == -2) {
        SetErrorCode(0x14);
        return -1;
    }
    if (func_ov003_021b7c5c(payload->mUnk_04) == -3) {
        SetErrorCode(0x15);
        return -1;
    }
    SetErrorCode(0x18);
    return -1;
}

// Checks the tag against the saved bytes; when mFlags & 0xf is set, xors the payload back in place.
s32 CheckPacketAndXorPayload(Packet *packet) {
    PayloadRecord *payload;
    u8 tag[8];
    s32 result;
    u32 length;
    u8 *copy;
    payload = (PayloadRecord *) packet->mPayload;
    CopyBytes(tag, &packet->mTag, 8);
    result = XorAndSwapBytesWithKey(tag, 8, gMelcoString, GetStringLength(gMelcoString));
    if (result == -1) {
        SetErrorCode(2);
        return -100;
    }
    result = CheckTagAgainstSavedBytesOrKind1000(SwapBytes16(packet->mKind), tag);
    if (result != 0) {
        return result;
    }
    if (SwapBytes16(packet->mKind) == 0x1000) {
        CopyBytes(gSavedTagBytes, tag, 8);
    }
    if ((SwapBytes16(packet->mFlags) & 0xf) == 0) {
        return 0;
    }
    length = SwapBytes16(payload->mLength);
    copy = func_ov003_021ba178(length);
    if (copy == NULL) {
        SetErrorCode(2);
        return 100;
    }
    if (XorBytesWithKeyStreamAndCheckCrc(payload->mBytes, copy, length, packet->mPayloadCrc, payload->mKeyPrefix,
                                         gSavedTagBytes, 8) < 0) {
        func_ov003_021ba164(copy);
        if (GetErrorCode() == 2) {
            return 100;
        }
        return 200;
    }
    CopyBytes(payload, copy, length);
    packet->mPayloadLength = func_ov003_021b7c94(length);
    func_ov003_021ba164(copy);
    return 0;
}

s32 CheckTagAgainstSavedBytesOrKind1000(s32 kind, const u8 *tag) {
    s32 result;
    s32 i;
    BOOL found;
    u8 *cursor;
    result = 0;
    found = FALSE;
    i = 0;
    cursor = gSavedTagBytes;
    do {
        if (*cursor != 0) {
            found = TRUE;
            break;
        }
        cursor++;
        i++;
    } while (i < 6);
    if (found != FALSE) {
        if (CompareBytes(gSavedTagBytes, tag, 6) != 0) {
            result = 1;
        }
    } else if (kind != 0x1000) {
        result = 2;
    }
    return result;
}

s32 XorSwapAndCheckTag(PacketTag *expectedTag, PacketTag *incomingTag) {
    s32 result;
    result = 0;
    XorAndSwapBytesWithKey(incomingTag->mBytes, 8, gMelcoString, GetStringLength(gMelcoString));
    if (CompareBytes(expectedTag->mBytes, incomingTag->mBytes, 6) != 0) {
        result = -1;
    } else if (SwapBytes16(expectedTag->mSequence) + 1 != SwapBytes16(incomingTag->mSequence)) {
        result = -2;
    }
    return result;
}

s32 ParseItemChain(PacketItem *firstItem, u8 *slots) {
    PacketItem *item;
    s32 length;
    s32 value;
    FillBytes(slots, 0, 0x104);
    item = firstItem;
    while (1) {
        length = SwapBytes16(item->mLength);
        if (length <= 0) {
            return -1;
        }
        switch (item->mType) {
            case 0:
                CopyBytes(slots, item->mValue, length);
                break;
            case 1:
                CopyBytes(slots + 0x80, item->mValue, length);
                break;
            case 2:
                CopyBytes(slots + 0x100, item->mValue, length);
                break;
            case 3:
            case 4:
                value = SwapBytes16(item->mValue[0]);
                if (value <= 0) {
                    return -2;
                }
                break;
            case 5:
                gRequestState.mDestinationAddress = func_ov003_021b7c5c(ReadLittleEndianValue(item->mValue, length));
                break;
            case 6:
                gRequestState.mAddressMask = func_ov003_021b7c5c(ReadLittleEndianValue(item->mValue, length));
                break;
            default:
                return -1;
        }
        if (item->mNextOffset != 0) {
            item = OFFSET_PTR(PacketItem, firstItem, SwapBytes16(item->mNextOffset));
            continue;
        }
        return 0;
    }
}

u32 ReadLittleEndianValue(const u8 *bytes, s32 count) {
    u32 value = 0;
    s32 i;
    const u8 *cursor = bytes + (count - 1);
    for (i = 0; i < count; i++) {
        value = (value << 8) + *cursor--;
    }
    return value;
}

s32 ParseFourValueItems(PacketItem *container, FourValueRecord *record) {
    PacketItem *item = OFFSET_PTR(PacketItem, container, 6);
    u32 length;
    while (1) {
        length = SwapBytes16(item->mLength);
        switch (item->mType) {
            case 0x10:
            case 0x11:
            case 0x12:
            case 0x13:
                if (length > 5) {
                    return -1;
                }
                break;
            case 0x20:
            case 0x21:
            case 0x22:
            case 0x23:
                if (length > 0xd) {
                    return -1;
                }
                break;
            case 0x15:
            case 0x25:
                if (length > 0x21) {
                    return -1;
                }
                break;
        }
        switch (item->mType) {
            case 0x10:
            case 0x20:
                CopyBytes(record->mValue0, item->mValue, length);
                record->mValueLength = length;
                break;
            case 0x11:
            case 0x21:
                CopyBytes(record->mValue1, item->mValue, length);
                record->mValueLength = length;
                break;
            case 0x12:
            case 0x22:
                CopyBytes(record->mValue2, item->mValue, length);
                record->mValueLength = length;
                break;
            case 0x13:
            case 0x23:
                CopyBytes(record->mValue3, item->mValue, length);
                record->mValueLength = length;
                break;
            case 0x15:
            case 0x25:
                if (length != 0 && item->mValue[length - 1] != 0) {
                    return -1;
                }
                CopyBytes(record->mString, item->mValue, length);
                break;
            default:
                return -1;
        }
        if (item->mNextOffset != 0) {
            item = (PacketItem *) ((u8 *) container + 6 + SwapBytes16(item->mNextOffset));
            continue;
        }
        return 0;
    }
}

s32 ParseSingleValueItems(PacketItem *container, SingleValueRecord *record) {
    PacketItem *item = OFFSET_PTR(PacketItem, container, 6);
    u32 length;
    while (1) {
        length = SwapBytes16(item->mLength);
        switch (item->mType) {
            case 0x30:
            case 0x40:
                if (length > 0x40) {
                    return -1;
                }
                break;
            case 0x35:
            case 0x45:
                if (length > 0x21) {
                    return -1;
                }
                break;
        }
        switch (item->mType) {
            case 0x30:
            case 0x40:
                CopyBytes(record->mValue, item->mValue, length);
                record->mValueLength = length;
                break;
            case 0x35:
            case 0x45:
                if (length != 0 && item->mValue[length - 1] != 0) {
                    return -1;
                }
                CopyBytes(record->mString, item->mValue, length);
                break;
            default:
                return -1;
        }
        if (item->mNextOffset != 0) {
            item = (PacketItem *) ((u8 *) container + 6 + SwapBytes16(item->mNextOffset));
            continue;
        }
        return 0;
    }
}

s32 CopyFirstItemValueIfType0x70(PacketItem *container, u8 *output) {
    PacketItem *item = OFFSET_PTR(PacketItem, container, 6);
    s32 length;
    length = SwapBytes16(item->mLength);
    if (length <= 0) {
        return -1;
    }
    if (item->mType != 0x70) {
        return -1;
    }
    CopyBytes(output, item->mValue, length);
    return 0;
}

// Skips to the top-level item of type gItemTypesToFind[a], then stores its sub-items by type.
s32 FindItemAndParseSubItems(s32 index, PacketItem *item, s32 remaining, ParsedItems *parsedItems, u8 *slots) {
    u32 foundMask;
    s32 itemSize;
    u32 subRemaining;
    u8 *typePointer;
    ParsedItems *parsed;
    u8 *slotBytes;
    s32 result;
    PacketItem *matchedItem;
    foundMask = 0;
    if (remaining <= 0) {
        return -2;
    }
    typePointer = gItemTypesToFind + index;
    for (;;) {
        matchedItem = item;
        if (item->mType == *typePointer) {
            break;
        }
        itemSize = SwapBytes16(item->mLength) + 4;
        item = OFFSET_PTR(PacketItem, item, itemSize);
        remaining -= itemSize;
        if (remaining <= 0) {
            return -4;
        }
    }
    item = OFFSET_PTR(PacketItem, item, 4);
    subRemaining = SwapBytes16(matchedItem->mLength);
    parsed = parsedItems + index;
    slotBytes = slots + (index + 3) * 0x80;
    result = -3;
    do {
        switch (item->mType) {
            case 3:
                result = ParseFourValueItems(item, &parsed->mFourValueRecord0);
                foundMask |= 1;
                break;
            case 4:
                result = ParseFourValueItems(item, &parsed->mFourValueRecord1);
                foundMask |= 2;
                break;
            case 5:
                result = ParseSingleValueItems(item, &parsed->mSingleValueRecord0);
                foundMask |= 4;
                break;
            case 6:
                result = ParseSingleValueItems(item, &parsed->mSingleValueRecord1);
                foundMask |= 8;
                break;
            case 10:
                result = CopyFirstItemValueIfType0x70(item, slotBytes);
                break;
            default:
                result = -3;
                break;
        }
        if (result != 0) {
            return result;
        }
        itemSize = SwapBytes16(item->mLength) + 4;
        item = OFFSET_PTR(PacketItem, item, itemSize);
        subRemaining -= itemSize;
    } while ((s32) subRemaining > 0);
    gRequestState.mFoundRecordMask |= foundMask;
    return 0;
}

s32 IsBit4Set(u32 value) {
    BOOL result = FALSE;
    if (value & 0x10) {
        result = TRUE;
    }
    return result;
}

// Reports state 2, 3 or 5 and sends the packet of kind 0x1000, 0x2000 or 0x3000 for mode 0, 1 or 2.
s32 ReportStateAndSendPacketForMode(s32 mode, Unk021b86e4 *buf, PacketTag *list, s32 descriptor) {
    switch (mode) {
        case 0:
            ReportStateChange(2);
            return SendPacketKind1000(buf, list, descriptor);
        case 1:
            ReportStateChange(3);
            return SendPacketKind2000(buf, list, descriptor);
        case 2:
            ReportStateChange(5);
            return SendPacketKind3000(buf, list, descriptor);
    }
    return -1;
}

s32 SendPacketKind1000(Unk021b86e4 *buf, PacketTag *list, s32 descriptor) {
    PacketFieldValues fields;
    PacketBuffer *packetBuffer;
    ItemContainer *container;
    u8 *payloadRecord;
    fields.mPayloadCrc = 0;
    fields.mPayloadLength = 0;
    fields.mFlags = 0;
    packetBuffer = gRequestPacketBuffer;
    FillBytes(packetBuffer, 0, 0x5dc);
    container = func_ov003_021ba178(0x210);
    if (container == NULL) {
        SetErrorCode(2);
        return -1;
    }
    FillBytes(container, 0, 0x210);
    payloadRecord = &packetBuffer->mBytes[12];
    CopyBytes(gSavedTagBytes, list, 8);
    CopyBytes(fields.mTag, gSavedTagBytes, 8);
    fields.mPayloadLength = BuildTwoItemChain(container->mItems);
    if (fields.mPayloadLength < 0) {
        SetErrorCode(3);
        if (container != NULL) {
            func_ov003_021ba164(container);
        }
        return -1;
    }
    container->mUnk_00 = 0;
    container->mLength = func_ov003_021b7c94(fields.mPayloadLength);
    fields.mPayloadLength += 4;
    FillPayloadRecord(0, payloadRecord, container, &fields.mPayloadLength, &fields.mFlags, &fields.mPayloadCrc);
    fields.mFlags |= 0x10;
    if (XorAndSwapBytesWithKey(fields.mTag, 8, gMelcoString, 6) != 0) {
        SetErrorCode(2);
        if (container != NULL) {
            func_ov003_021ba164(container);
        }
        return -1;
    }
    FillPacketHeader(packetBuffer, 0x1000, fields.mPayloadLength, fields.mFlags, fields.mPayloadCrc, 0x11, fields.mTag);
    fields.mPayloadLength += 0x18;
    SendPacket(packetBuffer, fields.mPayloadLength, 0xff, descriptor);
    if (container != NULL) {
        func_ov003_021ba164(container);
    }
    return 0;
}

s32 SendPacketKind2000(Unk021b86e4 *buf, PacketTag *list, s32 descriptor) {
    s8 payloadCrc;
    s16 payloadLength;
    s16 flags;
    u8 tagBytes[8];
    Unk021b7cec item;
    PacketBuffer *packetBuffer;
    payloadCrc = 0;
    payloadLength = 0;
    flags = 0;
    packetBuffer = gRequestPacketBuffer;
    FillBytes(&item, 0, 8);
    FillBytes(packetBuffer, 0, 0x5dc);
    item.mUnk_00 = 2;
    item.mUnk_01 = 0;
    item.mUnk_02 = func_ov003_021b7c94(4);
    item.mUnk_04 = gRequestState.mWantedRecordMask;
    item.mUnk_04 = SwapBytes32(item.mUnk_04);
    payloadLength = 8;
    FillPayloadRecord(gFlagBit4OfKind1010Packet, &packetBuffer->mBytes[12], &item, &payloadLength, &flags, &payloadCrc);
    CopyBytes(tagBytes, &list[1], 8);
    if (XorAndSwapBytesWithKey(tagBytes, 8, gMelcoString, 6) != 0) {
        SetErrorCode(2);
        return -1;
    }
    FillPacketHeader(packetBuffer, 0x2000, payloadLength, flags, payloadCrc, 0x11, tagBytes);
    payloadLength += 0x18;
    SendPacket(packetBuffer, payloadLength, 0, descriptor);
    return 0;
}

s32 SendPacketKind3000(Unk021b86e4 *buf, PacketTag *list, s32 descriptor) {
    PacketBuffer *packetBuffer;
    u8 tagBytes[8];
    packetBuffer = gRequestPacketBuffer;
    FillBytes(packetBuffer, 0, 0x5dc);
    CopyBytes(tagBytes, &list[2], 8);
    XorAndSwapBytesWithKey(tagBytes, 8, gMelcoString, GetStringLength(gMelcoString));
    FillPacketHeader(packetBuffer, 0x3000, 0, 0, 0, 0x11, tagBytes);
    SendPacket(packetBuffer, 0x18, 0, descriptor);
    return 0;
}

s16 BuildTwoItemChain(void *buffer) {
    OutgoingPacketItem *firstItem = buffer;
    OutgoingPacketItem *secondItem;
    s16 firstLength;
    s16 firstSize;
    s16 totalSize;
    u32 value;
    totalSize = 0;
    firstItem->mType = gRequestState.mItemType;
    firstItem->mUnk_01 = 1;
    firstLength = gRequestState.mItemLength;
    CopyBytes(firstItem->mValue, gRequestState.mItemBytes, firstLength);
    firstItem->mLength = func_ov003_021b7c94(firstLength);
    firstLength += 6;
    firstSize = (firstLength + 1) / 2 * 2;
    firstItem->mNextOffset = func_ov003_021b7c94(firstSize);
    totalSize += firstSize;
    secondItem = OFFSET_PTR(OutgoingPacketItem, firstItem, firstSize);
    ((u8 *) firstItem)[firstSize] = 0x60;
    secondItem->mUnk_01 = 0;
    secondItem->mNextOffset = func_ov003_021b7c94(0);
    value = SwapBytes32(0xe);
    CopyBytes(secondItem->mValue, &value, 4);
    secondItem->mLength = func_ov003_021b7c94(4);
    totalSize += 0xa;
    return totalSize;
}

void FillPayloadRecord(s32 useKeyStream, void *destination, const void *source, s16 *length, s16 *flags, s8 *crc) {
    PayloadRecord *record = destination;
    if (useKeyStream == 1) {
        *flags = 1;
        XorBytesWithRandomKeyStreamAndComputeCrc(source, record->mBytes, *length, crc, record->mKeyPrefix,
                                                 gSavedTagBytes, 8);
        record->mLength = func_ov003_021b7c94(*length);
        *length += 4;
    } else {
        CopyBytes(record, source, *length);
    }
}

void FillPacketHeader(void *buffer, s32 kind, s32 payloadLength, s32 flags, s8 payloadCrc, s8 f, const u8 *tagBytes) {
    PacketHeader *header = buffer;
    header->mUnk_00 = func_ov003_021b7c94(1);
    header->mUnk_02 = 0;
    header->mUnk_04 = 0;
    header->mKind = func_ov003_021b7c94(kind);
    header->mUnk_08 = 0;
    header->mPayloadLength = func_ov003_021b7c94(payloadLength);
    header->mFlags = func_ov003_021b7c94(flags);
    header->mPayloadCrc = payloadCrc;
    header->mUnk_0f = f;
    CopyBytes(header->mTag, tagBytes, 8);
}

s32 SendPacket(void *packet, s32 length, u32 target, s32 descriptor) {
    Unk021b7cec address;
    FillBytes(&address, 0, 8);
    address.mUnk_01 = 2;
    address.mUnk_02 = func_ov003_021b7c94(0x5790);
    address.mUnk_04 = SwapBytes32(gRequestState.mDestinationAddress);
    if (target == 0xff || gRequestState.mAddressApplied == 0) {
        address.mUnk_04 = -1;
    }
    return func_ov003_021b7d04(descriptor, packet, length, 0, &address, 8);
}

s32 XorBytesWithRandomKeyStreamAndComputeCrc(const u8 *src, u8 *dst, s32 length, s8 *crc, u8 *keyPrefix,
                                             const u8 *keyTail, s32 keyTailLength) {
    u16 random;
    KeyStreamState state;
    *crc = ComputeCrcLowByte(src, length);
    state.mTable = func_ov003_021ba178(length);
    if (state.mTable == NULL) {
        return -1;
    }
    random = NextRandomValue();
    CopyBytes(keyPrefix, &random, 2);
    CopyBytes(gKeyStreamKeyPrefix, keyPrefix, 2);
    CopyBytes(gKeyStreamKeyTail, keyTail, keyTailLength);
    InitKeyStream(&state, gKeyStreamKeyPrefix, keyTailLength + 2, length);
    XorWithKeyStream(&state, dst, src, length);
    func_ov003_021ba164(state.mTable);
    return 0;
}

s32 XorBytesWithKeyStreamAndCheckCrc(const u8 *src, u8 *dst, s32 length, u32 expectedCrc, const u8 *keyPrefix,
                                     const u8 *keyTail, s32 keyTailLength) {
    KeyStreamState state;
    u8 crc;
    state.mTable = func_ov003_021ba178(length);
    if (state.mTable == NULL) {
        SetErrorCode(2);
        return -1;
    }
    CopyBytes(gKeyStreamKeyPrefix, keyPrefix, 2);
    CopyBytes(gKeyStreamKeyTail, keyTail, keyTailLength);
    InitKeyStream(&state, gKeyStreamKeyPrefix, keyTailLength + 2, length);
    XorWithKeyStream(&state, dst, src, length);
    crc = ComputeCrcLowByte(dst, length);
    if (crc != expectedCrc) {
        SetErrorCode(0x12);
        func_ov003_021ba164(state.mTable);
        return -1;
    }
    func_ov003_021ba164(state.mTable);
    return 0;
}

// Fills the table with 0..n-1, then permutes it using the key bytes.
void InitKeyStream(KeyStreamState *state, const u8 *key, u32 keyLength, u32 count) {
    u8 *table;
    u32 i;
    u32 swapIndex;
    u32 keyIndex;
    u8 current;
    u8 swapped;
    table = state->mTable;
    state->mSwapIndex = 0;
    state->mIndex = state->mSwapIndex;
    state->mTableCount = count;
    for (i = 0; i < count; i++) {
        table[i] = i;
    }
    swapIndex = 0;
    keyIndex = 0;
    for (i = 0; i < count; i++) {
        current = table[i];
        swapIndex = (swapIndex + key[keyIndex] + current) % state->mTableCount;
        swapped = table[swapIndex];
        table[swapIndex] = current;
        table[i] = swapped;
        keyIndex++;
        if (keyIndex >= keyLength) {
            keyIndex = 0;
        }
    }
}

void XorWithKeyStream(KeyStreamState *state, u8 *dst, const u8 *src, u32 count) {
    u32 i;
    u8 keyByte;
    for (i = 0; i < count; i++) {
        keyByte = NextKeyStreamByte(state);
        dst[i] = keyByte ^ src[i];
    }
}

u32 NextKeyStreamByte(KeyStreamState *state) {
    u8 *table;
    u32 count;
    u8 index;
    u8 swapIndex;
    u8 first;
    u8 second;
    table = state->mTable;
    count = state->mTableCount;
    index = (state->mIndex + 1) % count;
    first = table[index];
    swapIndex = (first + state->mSwapIndex) % count;
    second = table[swapIndex];
    state->mIndex = index;
    state->mSwapIndex = swapIndex;
    table[swapIndex] = first;
    table[index] = second;
    return table[(first + second) % state->mTableCount];
}

u8 ComputeCrcLowByte(const u8 *bytes, s32 count) {
    return ComputeCrc(~0, bytes, count, 0, (u32 *) data_ov003_021d7f6c) ^ ~0;
}

u32 ComputeCrc(u32 crc, const u8 *bytes, s32 count, s32 tableBuilt, u32 *table) {
    s32 i;
    if (tableBuilt == 0) {
        InitCrcTable(tableBuilt, table);
    }
    for (i = 0; i < count; i++) {
        crc = (crc >> 8) ^ table[(crc ^ bytes[i]) & 0xff];
    }
    return crc;
}

void InitCrcTable(s32 a, u32 *table) {
    u32 value;
    s32 i;
    s32 j;
    for (i = 0; i < 0x100; i++) {
        value = i;
        for (j = 0; j < 8; j++) {
            if (value & 1) {
                value = (value >> 1) ^ 0xedb88320;
            } else {
                value = value >> 1;
            }
        }
        *table++ = value;
    }
}

// Two passes of xor-ing the second half with key bytes and swapping the halves.
s32 XorAndSwapBytesWithKey(u8 *buffer, s32 size, const s8 *key, s32 keyLength) {
    s8 *keyHalf;
    u8 *scratch;
    s32 i;
    keyHalf = func_ov003_021ba178(size / 2);
    if (keyHalf == NULL) {
        return -1;
    }
    scratch = func_ov003_021ba178(size);
    if (scratch == NULL) {
        func_ov003_021ba164(keyHalf);
        return -1;
    }
    for (i = 0; i < 2; i++) {
        FillIndexXorKeyBytes(i, keyHalf, size, key, keyLength);
        XorSecondHalf(keyHalf, buffer, size);
        SwapBufferHalves(buffer, size, scratch);
    }
    func_ov003_021ba164(keyHalf);
    func_ov003_021ba164(scratch);
    return 0;
}

void FillIndexXorKeyBytes(s32 round, s8 *output, s32 size, const s8 *key, s32 keyLength) {
    s32 half = size / 2;
    s32 keyIndex = round % keyLength;
    s32 i;
    for (i = 0; i < half; i++) {
        output[i] = i;
        output[i] ^= key[keyIndex++];
        if (keyIndex >= keyLength) {
            keyIndex = 0;
        }
    }
}

void XorSecondHalf(const s8 *key, u8 *buffer, s32 size) {
    s32 half = size / 2;
    s32 i;
    for (i = 0; i < half; i++) {
        buffer[half + i] ^= key[i];
    }
}

void SwapBufferHalves(u8 *buffer, u32 size, u8 *scratch) {
    int half;
    half = _s32_div_f(size, 2);
    CopyBytes(scratch, (buffer + half), half);
    CopyBytes((scratch + half), buffer, half);
    CopyBytes(buffer, scratch, size);
}

u32 func_ov003_021b7e70(u32 a, int size) {
    u32 memory;
    if (0 < size) {
        memory = (*(UnkWordFunc *) (*(u32 *) &data_ov003_021d8a0c))(size);
        return memory;
    }
    return 0;
}

void func_ov003_021b7e58(u32 a, u32 pointer) {
    (*(UnkFunc *) (*(u32 *) &data_ov003_021d8a18))(pointer);
}

s32 func_ov003_021b7df4(u32 address, u32 mask, u32 c) {
    data_ov003_021d6810.mUnk_10 = SwapBytes32(address);
    data_ov003_021d6810.mUnk_14 = SwapBytes32(mask);
    data_ov003_021d6810.mUnk_18 = SwapBytes32(c);
    if (func_ov000_021a8c94(&data_ov003_021d6810) < 0) {
        return -1;
    }
    while (data_ov000_021b63b4 == 0) {
        OS_Sleep(100);
    }
    return 0;
}

s32 func_ov003_021b7dc8(void) {
    if (func_ov000_021a8c8c() < 0) {
        return -1;
    }
    return -(func_ov003_021ba524() != 0);
}

s32 CompareBytes(const u8 *left, const u8 *right, s32 count) {
    s32 difference = 0;
    while (count-- > 0 && (difference = *left - *right) == 0) {
        left++;
        right++;
    }
    return difference;
}

void CopyBytes(void *destination, const void *source, u32 size) {
    MI_CpuCopy8(source, destination, size);
}

void FillBytes(void *destination, s32 fillValue, u32 size) {
    void *destinationCopy = destination;
    u32 byteValue = fillValue;
    u32 sizeCopy = size;
    u32 value3;
    byteValue = (byteValue << 24);
    byteValue = (byteValue >> 24);
    MI_CpuFill8(destinationCopy, byteValue, sizeCopy);
}

s32 func_ov003_021b7d68(s32 descriptor, void *buffer, s32 length, s32 v4, Unk021b7cec *address, s32 *addressLength) {
    address->mUnk_00 = *addressLength;
    return func_ov000_021a90a0(descriptor, buffer, length, v4, address);
}

s32 func_ov003_021b7d1c(s32 v1, Unk021b7ba0 *set, void *v3, void *v4, WaitTimeout *timeout) {
    Unk021b7ba0 setCopy;
    s64 ticks;
    ticks = 0;
    setCopy = *set;
    ticks += timeout->mSeconds * 0x1ff6210 / 0x40;
    ticks += timeout->mUnk_04 * 0x1ff6210 / 0x40;
    return func_ov000_021a8b20(&setCopy, 1, ticks);
}

s32 func_ov003_021b7d04(s32 descriptor, void *buffer, s32 length, s32 d, Unk021b7cec *address, u32 addressLength) {
    address->mUnk_00 = addressLength;
    return func_ov000_021a9018(descriptor, buffer, length, d, address);
}

s32 func_ov003_021b7d00(s32 id, s32 arg1, s32 arg2, void *value, s32 length) {
    return id;
}

s32 func_ov003_021b7cf8(s32 domain, s32 type, s32 protocol) {
    return func_ov000_021a918c(domain, type, protocol);
}

s32 func_ov003_021b7cec(s32 descriptor, Unk021b7cec *address, u32 addressLength) {
    address->mUnk_00 = addressLength;
    return func_ov000_021a916c(descriptor, address);
}

s32 func_ov003_021b7ce4(s32 descriptor) {
    return func_ov000_021a9008(descriptor);
}

u32 SwapBytes32(u32 input) {
    u32 value0 = input;
    u32 value1;
    u32 value2;
    u32 value3;
    u32 value4;
    value1 = (value0 << 24);
    value2 = 0xff000000u;
    value1 = (value1) & (value2);
    value4 = (value0 << 8);
    value2 = 0xff0000u;
    value4 = (value4) & (value2);
    value3 = (value0 >> 24);
    value2 = 255u;
    value3 = (value3) & (value2);
    value2 = (value0 >> 8);
    value0 = 0xff00u;
    value2 = (value2) & (value0);
    value3 = (value3) | (value2);
    value4 = (value4) | (value3);
    value1 = (value1) | (value4);
    value0 = (value1) + (0u);
    return value0;
}

u16 func_ov003_021b7c94(u16 value) {
    return ((value >> 8) & 0xff) | ((value << 8) & 0xff00);
}

u32 func_ov003_021b7c5c(u32 input) {
    u32 value0 = input;
    u32 value1;
    u32 value2;
    u32 value3;
    u32 value4;
    value1 = (value0 << 24);
    value2 = 0xff000000u;
    value1 = (value1) & (value2);
    value4 = (value0 << 8);
    value2 = 0xff0000u;
    value4 = (value4) & (value2);
    value3 = (value0 >> 24);
    value2 = 255u;
    value3 = (value3) & (value2);
    value2 = (value0 >> 8);
    value0 = 0xff00u;
    value2 = (value2) & (value0);
    value3 = (value3) | (value2);
    value4 = (value4) | (value3);
    value1 = (value1) | (value4);
    value0 = (value1) + (0u);
    return value0;
}

u16 SwapBytes16(u16 value) {
    return ((value >> 8) & 0xff) | ((value << 8) & 0xff00);
}

int GetStringLength(const void *string) {
    const s8 *chars = string;
    int length = 0;
    while (chars[length] != 0) {
        length++;
    }
    return length;
}

// Multiply-add generator, seeded from the clock on the first call; returns a value below 0x7fff.
u16 NextRandomValue(void) {
    s32 seed;
    RTCTime time;
    u32 *c;
    if (gRandomSeeded == 0) {
        seed = 0;
        FillBytes(&time, 0, 12);
        if (RTC_GetTime(&time) == 0) {
            seed += time.mHour << 10;
            seed += time.mMinute << 3;
            seed += time.mSecond;
        }
        gRandomState[0] = seed;
        gRandomState[1] = 0x5d588b65;
        gRandomState[2] = 0x269ec3;
        gRandomSeeded = 1;
    }
    gRandomState[0] = gRandomState[2] + gRandomState[1] * gRandomState[0];
    return ((gRandomState[0] >> 16) * 0x7fff) >> 16;
}
