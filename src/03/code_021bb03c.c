#include "03/code_021bb03c.h"

#include "03/code_021bcedc.h"
#include "03/code_021be3b8.h"
#include "03/code_021be418.h"
#include "os_thread.h"
#include "code_0214d018.h"
#include "03/unk_021d8000.h"
#include "code_0200f5ac.h"
#include "code_021329f8.h"
#include "string.h"
#include "code_02134398.h"
#include "03/unk_021d3000.h"
#include "03/code_021b7000.h"
#include "Main/Unknown/code_02133000.h"
#include "03/code_021b7bb4.h"
#include "03/code_021bb000.h"
#include "03/code_021bd000.h"
#include "03/code_021be000.h"
#include "00/code_021a8aa8.h"
#include "code_02139f70.h"
#include "03/unk_021d6000.h"
#include "code_0200fc8c.h"
#include "03/code_021be610.h"
#include "00/code_021a6fa8.h"
#include "00/code_021a86bc.h"
#include "code_0200f790.h"
#include "00/unk_021b6000.h"
#include "00/code_021a6d5c.h"

u32 func_ov003_021be604(void) {
    return data_ov003_021d8bfc;
}

u32 CallAllocFunctionWithMutex(u32 unused, s32 size) {
    u32 result;
    if (size > 0) {
        OS_LockMutex(&gAllocMutex);
        result = gAllocFunction(size);
        OS_UnlockMutex(&gAllocMutex);
        return result;
    }
    return 0;
}

void CallFreeFunctionWithMutex(u32 unused, s32 block, s32 size) {
    if (block != 0 && size > 0) {
        OS_LockMutex(&gAllocMutex);
        gFreeFunction(block);
        OS_UnlockMutex(&gAllocMutex);
    }
}

void ClearEventQueue(void) {
    u32 savedInterrupts = OS_DisableInterrupts();
    s32 i;

    gEventWriteIndex = 0;
    gEventReadIndex = 0;
    for (i = 0; i < 4; i++) {
        gEvents[i] = 0;
    }
    OS_RestoreInterrupts(savedInterrupts);
}

u32 DequeueEvent(void) {
    u32 savedInterrupts = OS_DisableInterrupts();
    s32 readIndex = gEventReadIndex;
    u32 event;

    if (gEventWriteIndex == readIndex) {
        event = 0;
    } else {
        event = gEvents[readIndex];
        readIndex++;
        gEventReadIndex = readIndex;
        if (readIndex >= 4) {
            gEventReadIndex = 0;
        }
    }
    OS_RestoreInterrupts(savedInterrupts);
    return event;
}

void EnqueueEventEx(u32 event, u32 unused) {
    s32 readIndex = gEventReadIndex;
    s32 writeIndex = gEventWriteIndex;
    s32 nextIndex = writeIndex + 1;

    if (nextIndex == readIndex) {
        return;
    }
    if (writeIndex == readIndex + 3) {
        return;
    }
    gEvents[writeIndex] = event;
    gEventWriteIndex = nextIndex;
    if (nextIndex >= 4) {
        gEventWriteIndex = 0;
    }
}

void EnqueueEvent(u32 value) {
    EnqueueEventEx(value, 0);
}

s32 func_ov003_021be418(u32 entryCount) {
    u32 waiting = 1;
    s32 result;
    u32 event;
    u32 alignedBuffer;
    u32 entriesSize;
    u32 bufferSize;
    enum { K0 } alignMask;
    u32 bufferEnd;

    gEntryCountMax = entryCount;
    ClearEventQueue();
    entriesSize = entryCount * 0xd0;
    gAllocatedBuffer = (void *) gAllocFunction(entriesSize + 0x24d0 + entryCount * 0xc0);
    if (gAllocatedBuffer == NULL) {
        return -1;
    }
    alignMask = 0x1f;
    alignedBuffer = ((u32) gAllocatedBuffer + alignMask) & ~0x1f;
    gAlignedBuffer = (void *) alignedBuffer;
    bufferSize = entriesSize + 0x2490;
    bufferEnd = alignedBuffer + bufferSize;
    gRawEntries = (RawEntry *) ((bufferEnd + alignMask) & ~0x1f);
    if (func_ov003_021be610(EnqueueEventEx, (void *) alignedBuffer, bufferSize) == 0) {
        return -2;
    }
    do {
        OS_Sleep(10);
        while ((event = DequeueEvent()) != 0) {
            if (event == 4 || event == 5) {
            } else if (event == 6) {
                waiting = 0;
                result = 1;
            } else {
                waiting = 0;
                result = -2;
            }
        }
    } while (waiting != 0);
    return result;
}

u32 func_ov003_021be3b8(void) {
    u32 waiting = 1;
    u32 event;

    if (func_ov003_021be7b8() != 0) {
        do {
            OS_Sleep(10);
            while ((event = DequeueEvent()) != 0) {
                switch (event) {
                    case 4:
                    case 5:
                        break;
                    case 20:
                        waiting = 0;
                        break;
                    default:
                        waiting = 0;
                        break;
                }
            }
        } while (waiting != 0);
    }
    if (gAllocatedBuffer != NULL) {
        gFreeFunction(gAllocatedBuffer);
        gAllocatedBuffer = NULL;
    }
    return 1;
}

s32 func_ov003_021be264(void) {
    OSAlarm alarm;
    RawEntry *entry;
    s32 waiting = 1;
    s32 result = -2;
    BOOL c;
    s32 event;

    entry = gRawEntries + gSelectedEntryIndex;
    if (entry == NULL) {
        return 0;
    }
    if (func_ov003_021be708(entry, NULL, 0x30000) == 0) {
        return -2;
    }
    OS_CreateAlarm(&alarm);
    OS_SetAlarm(&alarm, 0x3fec42, (void (*)(void *)) EnqueueEvent, (void *) 0x12);
    c = FALSE;
    do {
        if (GetTickMilliseconds() >= gTimeoutAtMs) {
            result = -3;
            break;
        }
        if (gStopRequested != 0) {
            result = -8;
            break;
        }
        OS_Sleep(10);
        while ((event = DequeueEvent()) != 0) {
            switch (event) {
                case 12:
                    waiting = c;
                    result = 1;
                    break;
                case 13:
                    if (gStopRequested != 0) {
                        waiting = c;
                        result = -8;
                    } else if (func_ov003_021be708(entry, NULL, 0x30000) == 0) {
                        return result;
                    }
                    break;
                case 4:
                case 5:
                case 18:
                case 19:
                    break;
                default:
                    waiting = c;
                    break;
            }
        }
    } while (waiting != 0);
    OS_CancelAlarm(&alarm);
    while (DequeueEvent() != 0) {
    }
    if (result > 0) {
        data_ov003_021d8bf0 = 1;
        if (func_ov000_021a8c94(data_ov003_021d691c) < 0) {
            result = -2;
        } else {
            data_ov003_021d8bf4 = 1;
        }
    }
    return result;
}

void func_ov003_021be1fc(void) {
    BOOL waiting;
    u32 event;
    waiting = TRUE;
    if (data_ov003_021d8bf0 != 0) {
        if (func_ov003_021be820() != 0) {
            do {
                OS_Sleep(10);
                while ((event = DequeueEvent()) != 0) {
                    switch (event) {
                        case 4:
                        case 5:
                            break;
                        case 0xe:
                            waiting = FALSE;
                            break;
                        default:
                            waiting = FALSE;
                            break;
                    }
                }
            } while (waiting != FALSE);
        }
        data_ov003_021d8bf0 = 0;
    }
    if (data_ov003_021d8bf4 != 0) {
        data_ov003_021d8bf4 = 0;
        func_ov000_021a8c8c();
    }
}

// Finds an entry of current whose bit-4 flag is clear and was set in previous, else a six-asterisk entry that is clear
// in current but not in previous; stores its index.
s32 FindEntryWithNewlyClearedBit4(EntrySummaryList *current, EntrySummaryList *previous, u32 *foundIndex) {
    BOOL found;
    BOOL result;
    BOOL currentHasAsterisks;
    BOOL previousHasAsterisks;
    EntrySummary *currentEntry;
    EntrySummary *previousEntry;
    u32 previousCount;
    u32 index;
    u32 previousIndex;
    u32 nameLength;
    found = FALSE;
    result = FALSE;
    currentEntry = current->mEntries;
    previousEntry = previous->mEntries;
    index = 0;
    for (; index < current->mCount; index++) {
        char currentName[0x22] = {0};
        memcpy(currentName, currentEntry->mSsid, 0x20);
        currentName[currentEntry->mSsidLength] = 0;
        previousIndex = 0;
        previousCount = previous->mCount;
        if (previousIndex < previousCount) {
            nameLength = currentEntry->mSsidLength;
            do {
                if (nameLength == 0 || nameLength > 0x20) {
                    break;
                }
                if (nameLength == 1 && (currentEntry->mSsid[0] == 0 || currentEntry->mSsid[0] == 0x20)) {
                    break;
                }
                if (memcmp(currentName, previousEntry->mSsid, strlen(currentName)) == 0 &&
                    memcmp(currentEntry->mAddress.mBytes, previousEntry->mAddress.mBytes, 4) == 0 &&
                    currentEntry->mBit4Set != previousEntry->mBit4Set && currentEntry->mBit4Set == 0) {
                    found = TRUE;
                    break;
                }
                previousEntry++;
                previousIndex++;
            } while (previousIndex < previousCount);
        }
        if (found != FALSE) {
            break;
        }
        currentEntry++;
        previousEntry = previous->mEntries;
    }
    if (found == FALSE) {
        char entryName[0x22] = {0};
        currentHasAsterisks = FALSE;
        previousHasAsterisks = FALSE;
        currentEntry = current->mEntries;
        previousEntry = previous->mEntries;
        previousIndex = 0;
        for (; previousIndex < previous->mCount; previousIndex++) {
            memcpy(entryName, previousEntry->mSsid, 0x20);
            entryName[previousEntry->mSsidLength] = 0;
            if (memcmp(entryName, gSixAsterisksString, strlen(gSixAsterisksString)) == 0 &&
                previousEntry->mBit4Set == 0) {
                previousHasAsterisks = TRUE;
                break;
            }
            previousEntry++;
        }
        index = 0;
        for (; index < current->mCount; index++) {
            memcpy(entryName, currentEntry->mSsid, 0x20);
            entryName[currentEntry->mSsidLength] = 0;
            if (strlen(entryName) == strlen(gSixAsterisksString) &&
                memcmp(entryName, gSixAsterisksString, strlen(gSixAsterisksString)) == 0 &&
                currentEntry->mBit4Set == 0) {
                currentHasAsterisks = TRUE;
                break;
            }
            currentEntry++;
        }
        if (currentHasAsterisks != FALSE && previousHasAsterisks == FALSE) {
            found = TRUE;
        }
    }
    if (found != FALSE) {
        *foundIndex = index;
        result = TRUE;
    }
    return result;
}

// Repeats the entry search up to 30 times until FindEntryWithNewlyClearedBit4 reports one; stores its index, name and
// address.
s32 SearchEntriesAndStoreEntryWithNewlyClearedBit4(void) {
    s32 a;
    s32 round;
    s32 copied;
    s32 index;
    BOOL waiting;
    s32 collected;
    u32 summarySize;
    u32 event;
    EntrySummaryList *currentList;
    EntrySummaryList *previousList;
    RawEntry *rawEntry;
    EntrySummary *entry;
    u8 *source;
    u8 *target;
    u32 changedIndex;
    u8 addressText[0x20];
    OSAlarm alarm;
    a = 0;
    currentList = NULL;
    a = -1;
    previousList = NULL;
    changedIndex = 0;
    summarySize = gEntryCountMax * 0x30 + 0x34;
    currentList = CallAllocFunctionAndClear(1, summarySize);
    if (currentList == NULL) {
        goto end;
    }
    previousList = CallAllocFunctionAndClear(1, summarySize);
    if (previousList == NULL) {
        goto end;
    }
    round = 0;
    while (round < 30 && gStopRequested == 0) {
        if (GetTickMilliseconds() >= gTimeoutAtMs) {
            break;
        }
        if (func_ov003_021be860(NULL, NULL, 0, 0x30bffe) == 0) {
            a = -2;
            goto end;
        }
        OS_CreateAlarm(&alarm);
        OS_SetAlarm(&alarm, 0xffb10, (void (*)(void *)) EnqueueEvent, (void *) 0x13);
        waiting = TRUE;
        a = 0;
        do {
            OS_Sleep(10);
            if (GetTickMilliseconds() >= gTimeoutAtMs || gStopRequested != 0) {
                break;
            }
            while ((event = DequeueEvent()) != 0) {
                switch (event) {
                    case 19:
                        waiting = FALSE;
                        break;
                    case 5:
                        collected = func_ov003_021be96c((u8 *) gRawEntries, gEntryCountMax);
                        if (collected > a) {
                            a = collected;
                            OS_CancelAlarm(&alarm);
                            OS_SetAlarm(&alarm, 0xffb10, (void (*)(void *)) EnqueueEvent, (void *) 0x13);
                        }
                        break;
                    case 10:
                        waiting = FALSE;
                        break;
                    case 4:
                    case 8:
                    case 18:
                        break;
                    case 0:
                    case 1:
                    case 2:
                    case 3:
                    case 6:
                    case 7:
                    case 9:
                    case 11:
                    case 12:
                    case 13:
                    case 14:
                    case 15:
                    case 16:
                    case 17:
                    default:
                        waiting = FALSE;
                        break;
                }
            }
        } while (waiting != FALSE);
        OS_CancelAlarm(&alarm);
        while (DequeueEvent() != 0) {
        }
        if (gStopRequested != 0) {
            break;
        }
        index = 0;
        if (a >= gEntryCountMax) {
            a = -6;
            goto end;
        }
        copied = 0;
        rawEntry = gRawEntries;
        if (a > 0) {
            do {
                memcpy(currentList->mEntries[index].mSsid, rawEntry->mSsid, 0x20);
                currentList->mEntries[index].mSsidLength = rawEntry->mSsidLength;
                currentList->mEntries[index].mSsid[rawEntry->mSsidLength] = 0;
                currentList->mEntries[index].mBit4Set = (rawEntry->mFlags & 0x10) ? 1 : 0;
                source = (u8 *) &rawEntry->mAddress;
                target = (u8 *) &currentList->mEntries[index].mAddress;
                target[0] = source[0];
                target[1] = source[1];
                target[2] = source[2];
                target[3] = source[3];
                target[4] = source[4];
                target[5] = source[5];
                index++;
                copied++;
                rawEntry++;
            } while (copied < a);
        }
        currentList->mCount = a;
        if (gExchangeStatus != 1) {
            index = FindEntryWithNewlyClearedBit4(currentList, previousList, &changedIndex);
            if (index != 0) {
                entry = &currentList->mEntries[changedIndex];
                gSelectedEntryIndex = changedIndex;
                strcpy(gSelectedEntryName, entry->mSsid);
                target = (u8 *) &gSelectedEntryAddress;
                source = (u8 *) &entry->mAddress;
                target[0] = source[0];
                target[1] = source[1];
                target[2] = source[2];
                target[3] = source[3];
                target[4] = source[4];
                target[5] = source[5];
                FormatMacAddress(addressText, (const s8 *) &gSelectedEntryAddress);
                break;
            }
        }
        memcpy(previousList, currentList, summarySize);
        gExchangeStatus = 2;
        CallStatusCallback();
        round++;
    }
    if (round >= 30 || GetTickMilliseconds() > gTimeoutAtMs) {
        a = -3;
    } else if (gStopRequested != 0) {
        a = -8;
    } else {
        a = 1;
    }
end:
    if (currentList != NULL) {
        CallFreeFunction(currentList);
    }
    if (previousList != NULL) {
        CallFreeFunction(previousList);
    }
    return a;
}

s32 SendBytesToAddress(s32 descriptor, const SocketAddress *address, const u8 *unused, const void *data, u32 size) {
    s32 result;
    result = func_ov000_021a9018(descriptor, data, size, 0, address);
    if (result < 0) {
        result = -4;
    }
    return result;
}

s32 SendBytesToAllOnesAddress(s32 descriptor, const void *data, u32 size) {
    SocketAddress address;
    u8 unused[4];
    address.mLength = 8;
    address.mUnk_01 = 2;
    address.mAddress = -1;
    address.mPort = 0x1e6;
    func_ov000_021a8bb0(func_ov000_021a8830(), unused);
    return SendBytesToAddress(descriptor, &address, unused, data, size);
}

s32 func_ov003_021bdccc(s32 descriptor, const void *unused, const void *data, u32 size) {
    return SendBytesToAllOnesAddress(descriptor, data, size);
}

// Returns the payload when the byte sum at its end matches, else NULL; stores the kind and length.
u8 *ReadExchangePacketAndCheckSum(const u8 *packet, u32 *kind, s32 *length) {
    u32 sum;
    const u8 *end;
    const u8 *cursor;
    sum = 0;
    *kind = SwapBytes16_inline(*(u16 *) packet);
    *length = SwapBytes16_inline(*OFFSET_PTR(u16, packet, 2));
    end = packet + 6 + *length;
    for (cursor = packet; cursor < end; cursor++) {
        sum += *cursor;
    }
    if ((u16) sum != SwapBytes16_inline(*(u16 *) end)) {
        return NULL;
    }
    return OFFSET_PTR(u8, packet, 6);
}

// Items are a big-endian type and length, then the value padded so the item is a multiple of 8 bytes.
u8 *ReadNextItem(u8 **cursor, u8 *end, u32 *type, s32 *length) {
    u8 *item;
    item = *cursor;
    if (item >= end) {
        return NULL;
    }
    *type = SwapBytes16_inline(*(u16 *) item);
    *length = SwapBytes16_inline(*OFFSET_PTR(u16, item, 2));
    item += 4;
    *cursor = item + (((*length + 0xb) & ~7) - 4);
    return item;
}

u8 *ReadFirstItem(const u8 *body, u32 *type, s32 *length) {
    u8 *cursor;
    cursor = OFFSET_PTR(u8, body, 8);
    return ReadNextItem(&cursor, cursor + SwapBytes16_inline(*(u16 *) body), type, length);
}

// Frames a body: six header bytes, the body (copied or transformed with the key), then the byte sum.
s32 BuildExchangePacket(u8 *packet, u32 kind, u8 *body, u32 length, const void *key) {
    u8 *end;
    u8 *cursor;
    u32 sum;
    end = packet;
    sum = 0;
    body[0] = 0;
    body[1] = 0;
    body[2] = 0;
    body[3] = 0;
    body[4] = 0;
    body[5] = 0;
    body[6] = 0;
    body[7] = 0;
    *(u16 *) body = SwapBytes16_inline(length - 8);
    if (key != NULL) {
        func_ov003_021bccd0(packet + 6, body, length, key, 0x10);
        length += 8;
    } else {
        memcpy(packet + 6, body, length);
    }
    packet[0] = 0;
    packet[1] = 0;
    packet[2] = 0;
    packet[3] = 0;
    packet[4] = 0;
    packet[5] = 0;
    *(u16 *) packet = SwapBytes16_inline(kind);
    *OFFSET_PTR(u16, packet, 2) = SwapBytes16_inline(length);
    end += 6;
    end += length;
    for (cursor = packet; cursor < end; cursor++) {
        sum += *cursor;
    }
    *(u16 *) end = SwapBytes16_inline(sum);
    return end + 2 - packet;
}

u8 *AppendItem(u8 *out, u32 type, const void *value, u32 length) {
    u32 paddedSize;
    out[0] = 0;
    out[1] = 0;
    out[2] = 0;
    out[3] = 0;
    *(u16 *) out = SwapBytes16_inline(type);
    paddedSize = ((length + 0xb) & ~7) - 4;
    *OFFSET_PTR(u16, out, 2) = SwapBytes16_inline(length);
    out = OFFSET_PTR(u8, out, 4);
    memset(out, 0, paddedSize);
    memcpy(out, value, length);
    return out + paddedSize;
}

s32 BuildSingleItemBody(u8 *out, u32 type, const void *value, u32 length) {
    s32 size;
    out[0] = 0;
    out[1] = 0;
    out[2] = 0;
    out[3] = 0;
    out[4] = 0;
    out[5] = 0;
    out[6] = 0;
    out[7] = 0;
    size = AppendItem(out + 8, type, value, length) - out;
    *(u16 *) out = size - 8;
    return size;
}

typedef struct Kind2Values {
    /* 0 */ u16 mHalfword;
    /* 2 */ Bytes7 mSevenBytes;
} Kind2Values;

BOOL ParseAndCheckExchangePacketKind1(const u8 *packet, s32 *item5Flag) {
    u32 value1;
    u32 value2;
    s32 value5;
    u32 kind;
    s32 length;
    u32 type;
    s32 itemLength;
    u8 *payload;
    u8 *end;
    u8 *item;
    payload = ReadExchangePacketAndCheckSum(packet, &kind, &length);
    value1 = 0;
    value2 = 0;
    value5 = 0;
    if (payload == NULL) {
        return FALSE;
    }
    if (kind != 1) {
        return FALSE;
    }
    end = payload + length;
    payload += 8;
    item = ReadNextItem(&payload, end, &type, &itemLength);
    if (item != NULL) {
        do {
            switch (type) {
                case 1:
                    value1 = SwapBytes16_inline(*(u16 *) item);
                    break;
                case 2:
                    value2 = SwapBytes16_inline(*(u16 *) item);
                    break;
                case 5:
                    value5 = SwapBytes16_inline(*(u16 *) item);
                    break;
            }
            item = ReadNextItem(&payload, end, &type, &itemLength);
        } while (item != NULL);
    }
    if (value1 != 1 || value2 != 1) {
        return FALSE;
    }
    if (value5 >= 1) {
        *item5Flag = 1;
    } else {
        *item5Flag = 0;
    }
    return TRUE;
}

s32 ReadExchangePacketPayloadOfKind(const u8 *packet, u32 kind, u8 *output, const void *key) {
    u32 packetKind;
    s32 length;
    u8 *payload;
    payload = ReadExchangePacketAndCheckSum(packet, &packetKind, &length);
    if (payload == NULL) {
        return 0;
    }
    if (packetKind != kind) {
        return 0;
    }
    if (key != NULL) {
        func_ov003_021bcadc(output, payload, length, key, 0x10);
        length -= 8;
    } else {
        memcpy(output, payload, length);
    }
    return length;
}

s32 BuildExchangePacketKind2(u8 *packet) {
    Kind2Values values;
    u8 *cursor;
    values.mHalfword = 0x100;
    values.mSevenBytes = gKind2Item3Bytes;
    cursor = AppendItem(data_ov003_021d68ac, 1, &values, 2);
    cursor = AppendItem(cursor, 2, &values, 2);
    if (gKind1Item5Flag != 0) {
        cursor = AppendItem(cursor, 5, &values, 2);
    }
    cursor = AppendItem(cursor, 3, &values.mSevenBytes, 7);
    if (gKind1Item5Flag != 0) {
        cursor = AppendItem(cursor, 4, &gMacAddress, 6);
    }
    return BuildExchangePacket(packet, 2, gBodyBuffer, cursor - data_ov003_021d68ac + 8, NULL);
}

u32 GetMacAddress(void *address) {
    OS_GetMacAddress(address);
    return 0x1u;
}

// Stores this machine's address, then writes the higher then the lower of it and the entry's address, then four fixed
// bytes, as the 16-byte key.
s32 StoreMacAddressAndBuildKey(u8 *key, void *unused) {
    u8 peerAddress[6];
    u8 ownAddress[6];
    u8 ownText[0x20];
    u8 peerText[0x20];
    __memcpy(key + 0xc, &data_ov003_021d6974, sizeof(Unk021d6974));
    __memcpy(peerAddress, &gSelectedEntryAddress, sizeof(MacAddress));
    peerAddress[0] &= 0xfd;
    GetMacAddress(ownAddress);
    __memcpy(&gMacAddress, ownAddress, sizeof(MacAddress));
    if (memcmp(peerAddress, ownAddress, 6) <= 0) {
        __memcpy(key, ownAddress, sizeof(MacAddress));
        __memcpy(key + 6, peerAddress, sizeof(MacAddress));
    } else {
        __memcpy(key, peerAddress, sizeof(MacAddress));
        __memcpy(key + 6, ownAddress, sizeof(MacAddress));
    }
    if (data_ov003_021d68b0 != 0) {
        FormatMacAddress(ownText, (const s8 *) ownAddress);
        FormatMacAddress(peerText, (const s8 *) peerAddress);
    }
    return 1;
}

// Stores the items of types 0x201 to 0x20a in gKind5Record, gKind5Words, gKind5Values and gKind5Item20a.
s32 ParseExchangePacketKind5Items(u8 *body) {
    u8 *end;
    BOOL found;
    u8 *cursor;
    u32 type;
    s32 length;
    u8 *value;
    u8 *slot0x204;
    cursor = body + 8;
    found = FALSE;
    end = cursor + SwapBytes16_inline(*(u16 *) body);
    value = ReadNextItem(&cursor, end, &type, &length);
    while (value != NULL) {
        switch (type) {
            case 0x201:
                __clear(&gKind5Record, 0x20);
                memcpy(&gKind5Record, value, length);
                found = TRUE;
                break;
            case 0x202:
                gKind5Record.mItem202Value = SwapBytes16_inline(*(u16 *) value);
                break;
            case 0x203: {
                s32 value0x203;
                s32 index0x203;
                u8 *slot0x203;
                value0x203 = SwapBytes16_inline(*(u16 *) value);
                index0x203 = 0;
                slot0x203 = (u8 *) gKind5Words;
                for (; index0x203 < 4; index0x203++) {
                    *OFFSET_PTR(u32, slot0x203, 0x15c) = value0x203;
                    slot0x203 += 0x28;
                }
                break;
            }
            case 0x204: {
                u32 value0x204;
                s32 index0x203;
                value0x204 = SwapBytes16_inline(*(u16 *) value);
                index0x203 = 0;
                slot0x204 = (u8 *) gKind5Words;
                for (; index0x203 < 4; index0x203++) {
                    *OFFSET_PTR(u32, slot0x204, 0x160) = value0x204;
                    slot0x204 += 0x28;
                }
                break;
            }
                {
                    u32 value0x203;
                    s32 index0x204;
                    value0x203 = SwapBytes16_inline(*(u16 *) value);
                    index0x204 = 0;
                    slot0x204 = (u8 *) gKind5Words;
                    for (; index0x204 < 4; index0x204++) {
                        *OFFSET_PTR(u32, slot0x204, 0x160) = value0x203;
                        slot0x204 += 0x28;
                    }
                    break;
                }
            case 0x205:
                gKind5Record.mItem205Value = SwapBytes16_inline(*(u16 *) value);
                break;
            case 0x206:
            case 0x207:
            case 0x208:
            case 0x209:
                memset(gKind5Values + (type - 0x206) * 0x28, 0, 0x20);
                if (gKind5Record.mStoreValuesAsHex == 1) {
                    u8 *hexCursor;
                    s32 byteIndex;
                    hexCursor = gKind5Values + (type - 0x206) * 0x28;
                    for (byteIndex = 0; byteIndex < length; byteIndex++) {
                        hexCursor += FormatByteAsHex(hexCursor, *value++);
                    }
                } else {
                    memcpy(gKind5Values + (type - 0x206) * 0x28, value, length);
                }
                break;
            case 0x20a:
                __clear(&gKind5Item20a, 0x48);
                memcpy(&gKind5Item20a, value, length);
                break;
        }
        value = ReadNextItem(&cursor, end, &type, &length);
    }
    return found;
}

BOOL ParseHexText(u8 *output, const s8 *text, s32 length) {
    u32 value;
    s32 index;
    value = 0;
    index = 0;
    for (; index < length; index++) {
        switch (text[index]) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                value += text[index] - '0';
                break;
            case 'a':
            case 'b':
            case 'c':
            case 'd':
            case 'e':
            case 'f':
                value += text[index] - 'W';
                break;
            case 'A':
            case 'B':
            case 'C':
            case 'D':
            case 'E':
            case 'F':
                value += text[index] - '7';
                break;
            default:
                return FALSE;
        }
        if (index % 2 == 0) {
            value <<= 4;
        } else {
            output[index / 2] = value;
            value = 0;
        }
    }
    return TRUE;
}

// Builds gExchangeResult from the Kind5 data; returns 1, or -7 for a value text of the wrong length, a zero item 0x205
// value or an unknown item 0x202 value.
s32 FillExchangeResultFromKind5Data(void) {
    s32 result;
    s32 valueIndex;
    char valueBuffer[0x21];
    char *valueText;
    u8 *valueSource;
    u8 *resultBytes;
    result = 1;
    strcpy(gExchangeResult.mText, gKind5Record.mText);
    switch (gKind5Record.mItem202Value) {
        case 0:
            gExchangeResult.mKind = 0;
            break;
        case 1:
            if (gKind5Record.mItem205Value == 0) {
                result = -7;
                break;
            }
            gExchangeResult.mUnk_24 = gKind5Record.mItem205Value;
            valueIndex = 0;
            valueText = valueBuffer;
            valueSource = gKind5Values;
            resultBytes = gExchangeResult.mValueBytes[0];
            for (; valueIndex < 4; valueIndex++) {
                memcpy(valueText, valueSource, 0x20);
                valueBuffer[0x20] = 0;
                switch (strlen(valueText)) {
                    case 0:
                        break;
                    case 5:
                        gExchangeResult.mKind = 1;
                        *(Bytes5 *) resultBytes = *(Bytes5 *) valueText;
                        break;
                    case 10:
                        gExchangeResult.mKind = 1;
                        ParseHexText(resultBytes, (s8 *) valueText, 10);
                        break;
                    case 13:
                        gExchangeResult.mKind = 2;
                        *(Bytes13 *) resultBytes = *(Bytes13 *) valueText;
                        break;
                    case 26:
                        gExchangeResult.mKind = 2;
                        ParseHexText(resultBytes, (s8 *) valueText, 26);
                        break;
                    case 16:
                        gExchangeResult.mKind = 3;
                        *(Bytes16 *) resultBytes = *(Bytes16 *) valueText;
                        break;
                    case 32:
                        gExchangeResult.mKind = 3;
                        ParseHexText(resultBytes, (s8 *) valueText, 32);
                        break;
                    default:
                        result = -7;
                        break;
                }
                valueSource += 0x28;
                resultBytes += 0x20;
            }
            break;
        case 2:
            gExchangeResult.mKind = 4;
            __memcpy(&gExchangeResult.mItem20aWords, &gKind5Item20a.mBytes, sizeof(gExchangeResult.mItem20aWords));
            break;
        case 3:
            gExchangeResult.mKind = 5;
            __memcpy(&gExchangeResult.mItem20aWords, &gKind5Item20a.mBytes, sizeof(gExchangeResult.mItem20aWords));
            break;
        default:
            result = -7;
            break;
    }
    return result;
}

// Steps 1 to 10: find an entry, connect, open a socket, then trade packets of kind 1 to 6; returns 1 or a negative
// error.
s32 RunExchange(void) {
    u32 stamp;
    s32 descriptor;
    s32 result;
    s32 retryCount;
    BOOL done;
    u8 *value;
    SocketAddress bindAddress;
    SocketAddress peerAddress;
    u32 itemType;
    s32 itemLength;
    u32 now;
    descriptor = 0;
    result = -5;
    stamp = 0;
    retryCount = 0;
    done = FALSE;
    gExchangeState = 1;
    while (done == FALSE && gStopRequested == 0) {
        OS_Sleep(500);
        switch (gExchangeState) {
            case 1:
                result = SearchEntriesAndStoreEntryWithNewlyClearedBit4();
                if (result != 1) {
                    done = TRUE;
                } else {
                    gExchangeStatus = 3;
                    CallStatusCallback();
                    gExchangeState = 2;
                }
                break;
            case 2:
                result = func_ov003_021be264();
                if (result != 1) {
                    done = TRUE;
                } else {
                    gExchangeState = 3;
                }
                break;
            case 3:
                descriptor = func_ov000_021a918c(2, 2, 0);
                if (descriptor < 0) {
                    result = -2;
                    done = TRUE;
                    break;
                }
                __clear(&bindAddress, 8);
                bindAddress.mLength = 8;
                bindAddress.mUnk_01 = 2;
                bindAddress.mPort = 0x1e6;
                bindAddress.mAddress = 0;
                result = func_ov000_021a916c(descriptor, &bindAddress);
                if (result < 0) {
                    result = -2;
                    done = TRUE;
                } else {
                    gExchangeState = 4;
                }
                break;
            case 4:
                if (GetTickMilliseconds() >= gTimeoutAtMs) {
                    func_ov000_021a9008(descriptor);
                    result = -3;
                    done = TRUE;
                    break;
                }
                peerAddress.mLength = 8;
                StoreMacAddressAndBuildKey(gFirstKey, &peerAddress);
                if (func_ov000_021a90a0(descriptor, gPacketBuffer, 0x800, 4, &peerAddress) > 0) {
                    if (ParseAndCheckExchangePacketKind1(gPacketBuffer, (s32 *) &gKind1Item5Flag) != FALSE) {
                        gTimeoutAtMs = GetTickMilliseconds() + 30000;
                        gExchangeState = 5;
                        gExchangeStatus = 4;
                        CallStatusCallback();
                    }
                }
                break;
            case 5:
                gPacketLength = BuildExchangePacketKind2(gPacketBuffer);
                func_ov003_021bdccc(descriptor, &peerAddress, gPacketBuffer, gPacketLength);
                stamp = GetTickMilliseconds();
                gExchangeState = 6;
                break;
            case 6:
                if (GetTickMilliseconds() >= gTimeoutAtMs) {
                    func_ov000_021a9008(descriptor);
                    result = -4;
                    done = TRUE;
                    break;
                }
                if (func_ov000_021a90a0(descriptor, gPacketBuffer, 0x800, 4, &peerAddress) > 0 &&
                    ReadExchangePacketPayloadOfKind(gPacketBuffer, 3, gBodyBuffer, gFirstKey) != 0) {
                    value = ReadFirstItem(gBodyBuffer, &itemType, &itemLength);
                    if (itemType == 0x101) {
                        now = GetTickMilliseconds();
                        gSecondKeyReceivedPart = *(Bytes8 *) value;
                        ComputeHash(gSecondKeyHashedPart, (const u8 *) &now, 4);
                        retryCount = 0;
                        gExchangeState = 7;
                        gExchangeStatus = 5;
                        gTimeoutAtMs = -1;
                        CallStatusCallback();
                    }
                } else if (GetTickMilliseconds() >= stamp + 1000) {
                    gExchangeState = 5;
                }
                break;
            case 7:
                gBodyLength = BuildSingleItemBody(gBodyBuffer, 0x102, gSecondKeyHashedPart, 8);
                gPacketLength = BuildExchangePacket(gPacketBuffer, 4, gBodyBuffer, gBodyLength, gFirstKey);
                func_ov003_021bdccc(descriptor, &peerAddress, gPacketBuffer, gPacketLength);
                stamp = GetTickMilliseconds();
                __clear(gKind5Words, 0x254);
                gExchangeState = 8;
                break;
            case 8:
                if (func_ov000_021a90a0(descriptor, gPacketBuffer, 0x800, 4, &peerAddress) > 0) {
                    gBodyLength =
                        ReadExchangePacketPayloadOfKind(gPacketBuffer, 5, gBodyBuffer, &gSecondKeyReceivedPart);
                    if (gBodyLength != 0 && ParseExchangePacketKind5Items(gBodyBuffer) != 0) {
                        if (*(s8 *) gKind5Record.mText != 0) {
                            gReceivedTextNonEmpty = 1;
                        } else {
                            gReceivedTextNonEmpty = 0;
                        }
                        retryCount = 0;
                        gExchangeState = 9;
                        break;
                    }
                }
                if (GetTickMilliseconds() >= stamp + 1000) {
                    retryCount++;
                    if (retryCount >= 10) {
                        func_ov000_021a9008(descriptor);
                        result = -2;
                        done = TRUE;
                    } else {
                        gExchangeState = 7;
                    }
                }
                break;
            case 9:
                gBodyLength = BuildSingleItemBody(gBodyBuffer, 0x301, &gReceivedTextNonEmpty, 1);
                gPacketLength =
                    BuildExchangePacket(gPacketBuffer, 6, gBodyBuffer, gBodyLength, &gSecondKeyReceivedPart);
                if (func_ov003_021be604() != 7) {
                    stamp = GetTickMilliseconds() + 1000;
                    retryCount = 10;
                    gExchangeState = 10;
                } else {
                    func_ov003_021bdccc(descriptor, &peerAddress, gPacketBuffer, gPacketLength);
                    stamp = GetTickMilliseconds();
                    gExchangeState = 10;
                }
                break;
            case 10:
                if (GetTickMilliseconds() >= stamp + 1000) {
                    retryCount++;
                    if (retryCount >= 10) {
                        done = TRUE;
                        result = FillExchangeResultFromKind5Data();
                    } else {
                        gExchangeState = 9;
                    }
                }
                break;
        }
    }
    if (descriptor != 0) {
        func_ov000_021a9008(descriptor);
    }
    if (gStopRequested != 0) {
        result = -8;
    }
    return result;
}

void RunExchangeThread(void) {
    int result;

    result = RunExchange();
    gExchangeResultCode = result;
    func_ov003_021be1fc();
    if (result == 1) {
        gExchangeStatus = 6;
    } else {
        gExchangeStatus = 7;
    }
    gTimeoutAtMs = -1;
    CallStatusCallback();
}

typedef struct Unk021bccd0_block {
    /* 0 */ u8 mUnk_00[8];
} Unk021bccd0_block;

BOOL func_ov003_021bccd0(u8 *output, u8 *input, u32 inputLength, u8 *key, int keyLength) {
    u8 workBuffer[16];
    u64 counterBytes;
    u32 keyWords[80];
    u32 fixedBytes[2];
    int blockIndex;
    int pass;
    int blockCount;
    int lastGroup;
    u64 counter;
    u8 *cursor;
    u8 *source;
    enum { K0 } bytesLeft;

    fixedBytes[0] = 0xa6a6a6a6;
    fixedBytes[1] = 0xa6a6a6a6;
    if ((inputLength & 7) != 0 || (keyLength & 7) != 0) {
        return FALSE;
    }
    blockCount = inputLength >> 3;
    if (blockCount < 2) {
        return FALSE;
    }
    lastGroup = ExpandKey(keyWords, key, keyLength << 3);
    memcpy(output + 8, input, inputLength);
    cursor = workBuffer;
    source = (u8 *) fixedBytes;
    bytesLeft = 8;
    do {
        *cursor++ = *source++;
    } while (--bytesLeft != 0);
    for (pass = 0; pass < 6; pass++) {
        for (blockIndex = 1; blockIndex <= blockCount; blockIndex++) {
            cursor = output + (u32) blockIndex * 8;
            *(Unk021bccd0_block *) (workBuffer + 8) = *(Unk021bccd0_block *) cursor;
            func_ov003_021bc1c4(keyWords, lastGroup, workBuffer, workBuffer);
            counter = (s64) blockCount * (s32) pass + (s32) blockIndex;
            counterBytes = (((counter & 0x00000000000000ffULL) << 56) | ((counter & 0x000000000000ff00ULL) << 40) |
                            ((counter & 0x0000000000ff0000ULL) << 24) | ((counter & 0x00000000ff000000ULL) << 8) |
                            ((counter & 0x000000ff00000000ULL) >> 8) | ((counter & 0x0000ff0000000000ULL) >> 24) |
                            ((counter & 0x00ff000000000000ULL) >> 40) | ((counter & 0xff00000000000000ULL) >> 56));
            XorEightBytes(workBuffer, (u8 *) &counterBytes, workBuffer);
            *(Unk021bccd0_block *) cursor = *(Unk021bccd0_block *) (workBuffer + 8);
        }
    }
    *(Unk021bccd0_block *) output = *(Unk021bccd0_block *) workBuffer;
    return TRUE;
}

BOOL func_ov003_021bcadc(u8 *output, u8 *input, u32 inputLength, u8 *key, int keyLength) {
    u8 workBuffer[16];
    u64 counterBytes;
    u32 keyWords[80];
    u32 fixedBytes[2];
    int blockIndex;
    int pass;
    int blockCount;
    int lastGroup;
    BOOL valid;
    u64 counter;
    u8 *cursor;
    u8 *copyCursor;
    enum { K0 } bytesLeft;

    valid = TRUE;
    fixedBytes[0] = 0xa6a6a6a6;
    fixedBytes[1] = 0xa6a6a6a6;
    if ((inputLength & 7) != 0 || (keyLength & 7) != 0) {
        return FALSE;
    }
    blockCount = (inputLength - 1) >> 3;
    if (blockCount < 2) {
        return FALSE;
    }
    lastGroup = ExpandKeyReversedWithTables(keyWords, key, keyLength << 3);
    cursor = workBuffer;
    copyCursor = input;
    bytesLeft = 8;
    do {
        *cursor++ = *copyCursor++;
    } while (--bytesLeft != 0);
    memcpy(output, input + 8, inputLength - 1);
    for (pass = 5; pass >= 0; pass--) {
        for (blockIndex = blockCount; blockIndex > 0; blockIndex--) {
            counter = (s64) blockCount * (s32) pass + (s32) blockIndex;
            counterBytes = (((counter & 0x00000000000000ffULL) << 56) | ((counter & 0x000000000000ff00ULL) << 40) |
                            ((counter & 0x0000000000ff0000ULL) << 24) | ((counter & 0x00000000ff000000ULL) << 8) |
                            ((counter & 0x000000ff00000000ULL) >> 8) | ((counter & 0x0000ff0000000000ULL) >> 24) |
                            ((counter & 0x00ff000000000000ULL) >> 40) | ((counter & 0xff00000000000000ULL) >> 56));
            XorEightBytes(workBuffer, (u8 *) &counterBytes, workBuffer);
            cursor = output + (blockIndex - 1) * 8;
            {
                u8 *r = cursor;
                copyCursor = workBuffer + 8;
                bytesLeft = 8;
                do {
                    *copyCursor++ = *r++;
                } while (--bytesLeft != 0);
            }
            func_ov003_021bbd9c(keyWords, lastGroup, workBuffer, workBuffer);
            {
                u8 *r = workBuffer + 8;
                bytesLeft = 8;
                do {
                    *cursor++ = *r++;
                } while (--bytesLeft != 0);
            }
        }
    }
    if (memcmp((u8 *) fixedBytes, workBuffer, 8) != 0) {
        valid = FALSE;
    }
    return valid;
}

void XorEightBytes(u8 *first, u8 *second, u8 *output) {
    *output = *first ^ *second;
    output[1] = first[1] ^ second[1];
    output[2] = first[2] ^ second[2];
    output[3] = first[3] ^ second[3];
    output[4] = first[4] ^ second[4];
    output[5] = first[5] ^ second[5];
    output[6] = first[6] ^ second[6];
    output[7] = first[7] ^ second[7];
}

// Expands the key into 4 * (n + 1) words and returns n: 10, 12 or 14 for 128, 192 or 256 bits.
int ExpandKey(u32 *words, u8 *key, int keyBits) {
    int i = 0;
    u32 lastWord;

    words[0] = (key[0] << 24) ^ (key[1] << 16) ^ (key[2] << 8) ^ key[3];
    words[1] = (key[4] << 24) ^ (key[5] << 16) ^ (key[6] << 8) ^ key[7];
    words[2] = (key[8] << 24) ^ (key[9] << 16) ^ (key[10] << 8) ^ key[11];
    words[3] = (key[12] << 24) ^ (key[13] << 16) ^ (key[14] << 8) ^ key[15];
    if (keyBits == 128) {
        for (;;) {
            lastWord = words[3];
            words[4] = words[0] ^ (data_ov003_021d52bc[(lastWord >> 16) & 0xff] & 0xff000000) ^
                       (data_ov003_021d52bc[(lastWord >> 8) & 0xff] & 0x00ff0000) ^
                       (data_ov003_021d52bc[lastWord & 0xff] & 0x0000ff00) ^
                       (data_ov003_021d52bc[lastWord >> 24] & 0x000000ff) ^ data_ov003_021d3694[i];
            words[5] = words[1] ^ words[4];
            words[6] = words[2] ^ words[5];
            words[7] = words[3] ^ words[6];
            if (++i == 10) {
                return 10;
            }
            words += 4;
        }
    }
    words[4] = (key[16] << 24) ^ (key[17] << 16) ^ (key[18] << 8) ^ key[19];
    words[5] = (key[20] << 24) ^ (key[21] << 16) ^ (key[22] << 8) ^ key[23];
    if (keyBits == 192) {
        for (;;) {
            lastWord = words[5];
            words[6] = words[0] ^ (data_ov003_021d52bc[(lastWord >> 16) & 0xff] & 0xff000000) ^
                       (data_ov003_021d52bc[(lastWord >> 8) & 0xff] & 0x00ff0000) ^
                       (data_ov003_021d52bc[lastWord & 0xff] & 0x0000ff00) ^
                       (data_ov003_021d52bc[lastWord >> 24] & 0x000000ff) ^ data_ov003_021d3694[i];
            words[7] = words[1] ^ words[6];
            words[8] = words[2] ^ words[7];
            words[9] = words[3] ^ words[8];
            if (++i == 8) {
                return 12;
            }
            words[10] = words[4] ^ words[9];
            words[11] = words[5] ^ words[10];
            words += 6;
        }
    }
    words[6] = (key[24] << 24) ^ (key[25] << 16) ^ (key[26] << 8) ^ key[27];
    words[7] = (key[28] << 24) ^ (key[29] << 16) ^ (key[30] << 8) ^ key[31];
    if (keyBits == 256) {
        for (;;) {
            lastWord = words[7];
            words[8] = words[0] ^ (data_ov003_021d52bc[(lastWord >> 16) & 0xff] & 0xff000000) ^
                       (data_ov003_021d52bc[(lastWord >> 8) & 0xff] & 0x00ff0000) ^
                       (data_ov003_021d52bc[lastWord & 0xff] & 0x0000ff00) ^
                       (data_ov003_021d52bc[lastWord >> 24] & 0x000000ff) ^ data_ov003_021d3694[i];
            words[9] = words[1] ^ words[8];
            words[10] = words[2] ^ words[9];
            words[11] = words[3] ^ words[10];
            if (++i == 7) {
                return 14;
            }
            lastWord = words[11];
            words[12] = words[4] ^ (data_ov003_021d52bc[lastWord >> 24] & 0xff000000) ^
                        (data_ov003_021d52bc[(lastWord >> 16) & 0xff] & 0x00ff0000) ^
                        (data_ov003_021d52bc[(lastWord >> 8) & 0xff] & 0x0000ff00) ^
                        (data_ov003_021d52bc[lastWord & 0xff] & 0x000000ff);
            words[13] = words[5] ^ words[12];
            words[14] = words[6] ^ words[13];
            words[15] = words[7] ^ words[14];
            words += 8;
        }
    }
    return i;
}

// Expands the key, reverses the order of its four-word groups and passes the inner ones through tables.
int ExpandKeyReversedWithTables(u32 *words, u8 *key, int keyBits) {
    int i, highIndex, lastGroup;
    u32 swapWord;

    lastGroup = ExpandKey(words, key, keyBits);
    for (i = 0, highIndex = 4 * lastGroup; i < highIndex; i += 4, highIndex -= 4) {
        swapWord = words[i];
        words[i] = words[highIndex];
        words[highIndex] = swapWord;
        swapWord = words[i + 1];
        words[i + 1] = words[highIndex + 1];
        words[highIndex + 1] = swapWord;
        swapWord = words[i + 2];
        words[i + 2] = words[highIndex + 2];
        words[highIndex + 2] = swapWord;
        swapWord = words[i + 3];
        words[i + 3] = words[highIndex + 3];
        words[highIndex + 3] = swapWord;
    }
    for (i = 1; i < lastGroup; i++) {
        words += 4;
        words[0] = data_ov003_021d56bc[data_ov003_021d52bc[words[0] >> 24] & 0xff] ^
                   data_ov003_021d5abc[data_ov003_021d52bc[(words[0] >> 16) & 0xff] & 0xff] ^
                   data_ov003_021d36bc[data_ov003_021d52bc[(words[0] >> 8) & 0xff] & 0xff] ^
                   data_ov003_021d3abc[data_ov003_021d52bc[words[0] & 0xff] & 0xff];
        words[1] = data_ov003_021d56bc[data_ov003_021d52bc[words[1] >> 24] & 0xff] ^
                   data_ov003_021d5abc[data_ov003_021d52bc[(words[1] >> 16) & 0xff] & 0xff] ^
                   data_ov003_021d36bc[data_ov003_021d52bc[(words[1] >> 8) & 0xff] & 0xff] ^
                   data_ov003_021d3abc[data_ov003_021d52bc[words[1] & 0xff] & 0xff];
        words[2] = data_ov003_021d56bc[data_ov003_021d52bc[words[2] >> 24] & 0xff] ^
                   data_ov003_021d5abc[data_ov003_021d52bc[(words[2] >> 16) & 0xff] & 0xff] ^
                   data_ov003_021d36bc[data_ov003_021d52bc[(words[2] >> 8) & 0xff] & 0xff] ^
                   data_ov003_021d3abc[data_ov003_021d52bc[words[2] & 0xff] & 0xff];
        words[3] = data_ov003_021d56bc[data_ov003_021d52bc[words[3] >> 24] & 0xff] ^
                   data_ov003_021d5abc[data_ov003_021d52bc[(words[3] >> 16) & 0xff] & 0xff] ^
                   data_ov003_021d36bc[data_ov003_021d52bc[(words[3] >> 8) & 0xff] & 0xff] ^
                   data_ov003_021d3abc[data_ov003_021d52bc[words[3] & 0xff] & 0xff];
    }
    return lastGroup;
}

void func_ov003_021bc1c4(u32 *keyWords, int lastGroup, u8 *input, u8 *output) {
    u32 s0, s1, s2, s3, t0, t1, t2, t3;
    int passesLeft;

    s0 = ((input[0] << 24) ^ (input[1] << 16) ^ (input[2] << 8) ^ input[3]) ^ keyWords[0];
    s1 = ((input[4] << 24) ^ (input[5] << 16) ^ (input[6] << 8) ^ input[7]) ^ keyWords[1];
    s2 = ((input[8] << 24) ^ (input[9] << 16) ^ (input[10] << 8) ^ input[11]) ^ keyWords[2];
    s3 = ((input[12] << 24) ^ (input[13] << 16) ^ (input[14] << 8) ^ input[15]) ^ keyWords[3];
    passesLeft = lastGroup >> 1;
    for (;;) {
        t0 = data_ov003_021d42bc[s0 >> 24] ^ data_ov003_021d46bc[(s1 >> 16) & 0xff] ^
             data_ov003_021d4abc[(s2 >> 8) & 0xff] ^ data_ov003_021d4ebc[s3 & 0xff] ^ keyWords[4];
        t1 = data_ov003_021d42bc[s1 >> 24] ^ data_ov003_021d46bc[(s2 >> 16) & 0xff] ^
             data_ov003_021d4abc[(s3 >> 8) & 0xff] ^ data_ov003_021d4ebc[s0 & 0xff] ^ keyWords[5];
        t2 = data_ov003_021d42bc[s2 >> 24] ^ data_ov003_021d46bc[(s3 >> 16) & 0xff] ^
             data_ov003_021d4abc[(s0 >> 8) & 0xff] ^ data_ov003_021d4ebc[s1 & 0xff] ^ keyWords[6];
        t3 = data_ov003_021d42bc[s3 >> 24] ^ data_ov003_021d46bc[(s0 >> 16) & 0xff] ^
             data_ov003_021d4abc[(s1 >> 8) & 0xff] ^ data_ov003_021d4ebc[s2 & 0xff] ^ keyWords[7];
        keyWords += 8;
        if (--passesLeft == 0) {
            break;
        }
        s0 = data_ov003_021d42bc[t0 >> 24] ^ data_ov003_021d46bc[(t1 >> 16) & 0xff] ^
             data_ov003_021d4abc[(t2 >> 8) & 0xff] ^ data_ov003_021d4ebc[t3 & 0xff] ^ keyWords[0];
        s1 = data_ov003_021d42bc[t1 >> 24] ^ data_ov003_021d46bc[(t2 >> 16) & 0xff] ^
             data_ov003_021d4abc[(t3 >> 8) & 0xff] ^ data_ov003_021d4ebc[t0 & 0xff] ^ keyWords[1];
        s2 = data_ov003_021d42bc[t2 >> 24] ^ data_ov003_021d46bc[(t3 >> 16) & 0xff] ^
             data_ov003_021d4abc[(t0 >> 8) & 0xff] ^ data_ov003_021d4ebc[t1 & 0xff] ^ keyWords[2];
        s3 = data_ov003_021d42bc[t3 >> 24] ^ data_ov003_021d46bc[(t0 >> 16) & 0xff] ^
             data_ov003_021d4abc[(t1 >> 8) & 0xff] ^ data_ov003_021d4ebc[t2 & 0xff] ^ keyWords[3];
    }
    s0 = (data_ov003_021d52bc[t0 >> 24] & 0xff000000) ^ (data_ov003_021d52bc[(t1 >> 16) & 0xff] & 0x00ff0000) ^
         (data_ov003_021d52bc[(t2 >> 8) & 0xff] & 0x0000ff00) ^ (data_ov003_021d52bc[t3 & 0xff] & 0x000000ff) ^
         keyWords[0];
    output[0] = s0 >> 24;
    output[1] = s0 >> 16;
    output[2] = s0 >> 8;
    output[3] = s0;
    s1 = (data_ov003_021d52bc[t1 >> 24] & 0xff000000) ^ (data_ov003_021d52bc[(t2 >> 16) & 0xff] & 0x00ff0000) ^
         (data_ov003_021d52bc[(t3 >> 8) & 0xff] & 0x0000ff00) ^ (data_ov003_021d52bc[t0 & 0xff] & 0x000000ff) ^
         keyWords[1];
    output[4] = s1 >> 24;
    output[5] = s1 >> 16;
    output[6] = s1 >> 8;
    output[7] = s1;
    s2 = (data_ov003_021d52bc[t2 >> 24] & 0xff000000) ^ (data_ov003_021d52bc[(t3 >> 16) & 0xff] & 0x00ff0000) ^
         (data_ov003_021d52bc[(t0 >> 8) & 0xff] & 0x0000ff00) ^ (data_ov003_021d52bc[t1 & 0xff] & 0x000000ff) ^
         keyWords[2];
    output[8] = s2 >> 24;
    output[9] = s2 >> 16;
    output[10] = s2 >> 8;
    output[11] = s2;
    s3 = (data_ov003_021d52bc[t3 >> 24] & 0xff000000) ^ (data_ov003_021d52bc[(t0 >> 16) & 0xff] & 0x00ff0000) ^
         (data_ov003_021d52bc[(t1 >> 8) & 0xff] & 0x0000ff00) ^ (data_ov003_021d52bc[t2 & 0xff] & 0x000000ff) ^
         keyWords[3];
    output[12] = s3 >> 24;
    output[13] = s3 >> 16;
    output[14] = s3 >> 8;
    output[15] = s3;
}

void func_ov003_021bbd9c(u32 *keyWords, int lastGroup, u8 *input, u8 *output) {
    u32 s0, s1, s2, s3, t0, t1, t2, t3;
    int passesLeft;

    s0 = ((input[0] << 24) ^ (input[1] << 16) ^ (input[2] << 8) ^ input[3]) ^ keyWords[0];
    s1 = ((input[4] << 24) ^ (input[5] << 16) ^ (input[6] << 8) ^ input[7]) ^ keyWords[1];
    s2 = ((input[8] << 24) ^ (input[9] << 16) ^ (input[10] << 8) ^ input[11]) ^ keyWords[2];
    s3 = ((input[12] << 24) ^ (input[13] << 16) ^ (input[14] << 8) ^ input[15]) ^ keyWords[3];
    passesLeft = lastGroup >> 1;
    for (;;) {
        t0 = data_ov003_021d56bc[s0 >> 24] ^ data_ov003_021d5abc[(s3 >> 16) & 0xff] ^
             data_ov003_021d36bc[(s2 >> 8) & 0xff] ^ data_ov003_021d3abc[s1 & 0xff] ^ keyWords[4];
        t1 = data_ov003_021d56bc[s1 >> 24] ^ data_ov003_021d5abc[(s0 >> 16) & 0xff] ^
             data_ov003_021d36bc[(s3 >> 8) & 0xff] ^ data_ov003_021d3abc[s2 & 0xff] ^ keyWords[5];
        t2 = data_ov003_021d56bc[s2 >> 24] ^ data_ov003_021d5abc[(s1 >> 16) & 0xff] ^
             data_ov003_021d36bc[(s0 >> 8) & 0xff] ^ data_ov003_021d3abc[s3 & 0xff] ^ keyWords[6];
        t3 = data_ov003_021d56bc[s3 >> 24] ^ data_ov003_021d5abc[(s2 >> 16) & 0xff] ^
             data_ov003_021d36bc[(s1 >> 8) & 0xff] ^ data_ov003_021d3abc[s0 & 0xff] ^ keyWords[7];
        keyWords += 8;
        if (--passesLeft == 0) {
            break;
        }
        s0 = data_ov003_021d56bc[t0 >> 24] ^ data_ov003_021d5abc[(t3 >> 16) & 0xff] ^
             data_ov003_021d36bc[(t2 >> 8) & 0xff] ^ data_ov003_021d3abc[t1 & 0xff] ^ keyWords[0];
        s1 = data_ov003_021d56bc[t1 >> 24] ^ data_ov003_021d5abc[(t0 >> 16) & 0xff] ^
             data_ov003_021d36bc[(t3 >> 8) & 0xff] ^ data_ov003_021d3abc[t2 & 0xff] ^ keyWords[1];
        s2 = data_ov003_021d56bc[t2 >> 24] ^ data_ov003_021d5abc[(t1 >> 16) & 0xff] ^
             data_ov003_021d36bc[(t0 >> 8) & 0xff] ^ data_ov003_021d3abc[t3 & 0xff] ^ keyWords[2];
        s3 = data_ov003_021d56bc[t3 >> 24] ^ data_ov003_021d5abc[(t2 >> 16) & 0xff] ^
             data_ov003_021d36bc[(t1 >> 8) & 0xff] ^ data_ov003_021d3abc[t0 & 0xff] ^ keyWords[3];
    }
    s0 = (data_ov003_021d3ebc[t0 >> 24] & 0xff000000) ^ (data_ov003_021d3ebc[(t3 >> 16) & 0xff] & 0x00ff0000) ^
         (data_ov003_021d3ebc[(t2 >> 8) & 0xff] & 0x0000ff00) ^ (data_ov003_021d3ebc[t1 & 0xff] & 0x000000ff) ^
         keyWords[0];
    output[0] = s0 >> 24;
    output[1] = s0 >> 16;
    output[2] = s0 >> 8;
    output[3] = s0;
    s1 = (data_ov003_021d3ebc[t1 >> 24] & 0xff000000) ^ (data_ov003_021d3ebc[(t0 >> 16) & 0xff] & 0x00ff0000) ^
         (data_ov003_021d3ebc[(t3 >> 8) & 0xff] & 0x0000ff00) ^ (data_ov003_021d3ebc[t2 & 0xff] & 0x000000ff) ^
         keyWords[1];
    output[4] = s1 >> 24;
    output[5] = s1 >> 16;
    output[6] = s1 >> 8;
    output[7] = s1;
    s2 = (data_ov003_021d3ebc[t2 >> 24] & 0xff000000) ^ (data_ov003_021d3ebc[(t1 >> 16) & 0xff] & 0x00ff0000) ^
         (data_ov003_021d3ebc[(t0 >> 8) & 0xff] & 0x0000ff00) ^ (data_ov003_021d3ebc[t3 & 0xff] & 0x000000ff) ^
         keyWords[2];
    output[8] = s2 >> 24;
    output[9] = s2 >> 16;
    output[10] = s2 >> 8;
    output[11] = s2;
    s3 = (data_ov003_021d3ebc[t3 >> 24] & 0xff000000) ^ (data_ov003_021d3ebc[(t2 >> 16) & 0xff] & 0x00ff0000) ^
         (data_ov003_021d3ebc[(t1 >> 8) & 0xff] & 0x0000ff00) ^ (data_ov003_021d3ebc[t0 & 0xff] & 0x000000ff) ^
         keyWords[3];
    output[12] = s3 >> 24;
    output[13] = s3 >> 16;
    output[14] = s3 >> 8;
    output[15] = s3;
}

void ResetHashContext(HashContext *context) {
    context->mBitCountHigh = 0;
    context->mBitCountLow = context->mBitCountHigh;
    context->mHashWords[0] = 0x67452301;
    context->mHashWords[1] = 0xefcdab89;
    context->mHashWords[2] = 0x98badcfe;
    context->mHashWords[3] = 0x10325476;
}

void AddBytesToHash(HashContext *context, const u8 *bytes, u32 count) {
    u32 offset;
    u32 used;
    u32 room;
    used = (context->mBitCountLow >> 3) & 0x3f;
    context->mBitCountLow += count << 3;
    if (context->mBitCountLow < (count << 3)) {
        context->mBitCountHigh++;
    }
    context->mBitCountHigh += count >> 29;
    room = 0x40 - used;
    if (count >= room) {
        CopyBytesWithLoop(context->mBuffer + used, bytes, room);
        ProcessHashBlock(context, context->mBuffer);
        for (offset = room; offset + 63 < count; offset += 64) {
            ProcessHashBlock(context, bytes + offset);
        }
        used = 0;
    } else {
        offset = 0;
    }
    CopyBytesWithLoop(context->mBuffer + used, bytes + offset, count - offset);
}

// Pads the data, writes the 16 digest bytes and zeroes the context.
void FinishHash(u8 *digest, HashContext *context) {
    u8 countBytes[8];
    u32 used;
    u32 padLength;
    CopyWordsToBytesLittleEndian(countBytes, &context->mBitCountLow, 8);
    used = (context->mBitCountLow >> 3) & 0x3f;
    if (used < 0x38) {
        padLength = 0x38 - used;
    } else {
        padLength = 0x78 - used;
    }
    AddBytesToHash(context, gHashPadding, padLength);
    AddBytesToHash(context, countBytes, 8);
    CopyWordsToBytesLittleEndian(digest, context->mHashWords, 0x10);
    FillBytesWithLoop(context, 0, 0x58);
}

void ProcessHashBlock(HashContext *context, const u8 *block) {
    u32 a = context->mHashWords[0];
    u32 b = context->mHashWords[1];
    u32 c = context->mHashWords[2];
    u32 d = context->mHashWords[3];
    u32 words[16];

    CopyBytesToWordsLittleEndian(words, block, 64);
    a += ((b & c) | (~b & d)) + words[0] + 0xd76aa478;
    a = (a << 7) | (a >> 25);
    a += b;
    d += ((a & b) | (~a & c)) + words[1] + 0xe8c7b756;
    d = (d << 12) | (d >> 20);
    d += a;
    c += ((d & a) | (~d & b)) + words[2] + 0x242070db;
    c = (c << 17) | (c >> 15);
    c += d;
    b += ((c & d) | (~c & a)) + words[3] + 0xc1bdceee;
    b = (b << 22) | (b >> 10);
    b += c;
    a += ((b & c) | (~b & d)) + words[4] + 0xf57c0faf;
    a = (a << 7) | (a >> 25);
    a += b;
    d += ((a & b) | (~a & c)) + words[5] + 0x4787c62a;
    d = (d << 12) | (d >> 20);
    d += a;
    c += ((d & a) | (~d & b)) + words[6] + 0xa8304613;
    c = (c << 17) | (c >> 15);
    c += d;
    b += ((c & d) | (~c & a)) + words[7] + 0xfd469501;
    b = (b << 22) | (b >> 10);
    b += c;
    a += ((b & c) | (~b & d)) + words[8] + 0x698098d8;
    a = (a << 7) | (a >> 25);
    a += b;
    d += ((a & b) | (~a & c)) + words[9] + 0x8b44f7af;
    d = (d << 12) | (d >> 20);
    d += a;
    c += ((d & a) | (~d & b)) + words[10] + 0xffff5bb1;
    c = (c << 17) | (c >> 15);
    c += d;
    b += ((c & d) | (~c & a)) + words[11] + 0x895cd7be;
    b = (b << 22) | (b >> 10);
    b += c;
    a += ((b & c) | (~b & d)) + words[12] + 0x6b901122;
    a = (a << 7) | (a >> 25);
    a += b;
    d += ((a & b) | (~a & c)) + words[13] + 0xfd987193;
    d = (d << 12) | (d >> 20);
    d += a;
    c += ((d & a) | (~d & b)) + words[14] + 0xa679438e;
    c = (c << 17) | (c >> 15);
    c += d;
    b += ((c & d) | (~c & a)) + words[15] + 0x49b40821;
    b = (b << 22) | (b >> 10);
    b += c;
    a += ((b & d) | (c & ~d)) + words[1] + 0xf61e2562;
    a = (a << 5) | (a >> 27);
    a += b;
    d += ((a & c) | (b & ~c)) + words[6] + 0xc040b340;
    d = (d << 9) | (d >> 23);
    d += a;
    c += ((d & b) | (a & ~b)) + words[11] + 0x265e5a51;
    c = (c << 14) | (c >> 18);
    c += d;
    b += ((c & a) | (d & ~a)) + words[0] + 0xe9b6c7aa;
    b = (b << 20) | (b >> 12);
    b += c;
    a += ((b & d) | (c & ~d)) + words[5] + 0xd62f105d;
    a = (a << 5) | (a >> 27);
    a += b;
    d += ((a & c) | (b & ~c)) + words[10] + 0x02441453;
    d = (d << 9) | (d >> 23);
    d += a;
    c += ((d & b) | (a & ~b)) + words[15] + 0xd8a1e681;
    c = (c << 14) | (c >> 18);
    c += d;
    b += ((c & a) | (d & ~a)) + words[4] + 0xe7d3fbc8;
    b = (b << 20) | (b >> 12);
    b += c;
    a += ((b & d) | (c & ~d)) + words[9] + 0x21e1cde6;
    a = (a << 5) | (a >> 27);
    a += b;
    d += ((a & c) | (b & ~c)) + words[14] + 0xc33707d6;
    d = (d << 9) | (d >> 23);
    d += a;
    c += ((d & b) | (a & ~b)) + words[3] + 0xf4d50d87;
    c = (c << 14) | (c >> 18);
    c += d;
    b += ((c & a) | (d & ~a)) + words[8] + 0x455a14ed;
    b = (b << 20) | (b >> 12);
    b += c;
    a += ((b & d) | (c & ~d)) + words[13] + 0xa9e3e905;
    a = (a << 5) | (a >> 27);
    a += b;
    d += ((a & c) | (b & ~c)) + words[2] + 0xfcefa3f8;
    d = (d << 9) | (d >> 23);
    d += a;
    c += ((d & b) | (a & ~b)) + words[7] + 0x676f02d9;
    c = (c << 14) | (c >> 18);
    c += d;
    b += ((c & a) | (d & ~a)) + words[12] + 0x8d2a4c8a;
    b = (b << 20) | (b >> 12);
    b += c;
    a += (b ^ c ^ d) + words[5] + 0xfffa3942;
    a = (a << 4) | (a >> 28);
    a += b;
    d += (a ^ b ^ c) + words[8] + 0x8771f681;
    d = (d << 11) | (d >> 21);
    d += a;
    c += (d ^ a ^ b) + words[11] + 0x6d9d6122;
    c = (c << 16) | (c >> 16);
    c += d;
    b += (c ^ d ^ a) + words[14] + 0xfde5380c;
    b = (b << 23) | (b >> 9);
    b += c;
    a += (b ^ c ^ d) + words[1] + 0xa4beea44;
    a = (a << 4) | (a >> 28);
    a += b;
    d += (a ^ b ^ c) + words[4] + 0x4bdecfa9;
    d = (d << 11) | (d >> 21);
    d += a;
    c += (d ^ a ^ b) + words[7] + 0xf6bb4b60;
    c = (c << 16) | (c >> 16);
    c += d;
    b += (c ^ d ^ a) + words[10] + 0xbebfbc70;
    b = (b << 23) | (b >> 9);
    b += c;
    a += (b ^ c ^ d) + words[13] + 0x289b7ec6;
    a = (a << 4) | (a >> 28);
    a += b;
    d += (a ^ b ^ c) + words[0] + 0xeaa127fa;
    d = (d << 11) | (d >> 21);
    d += a;
    c += (d ^ a ^ b) + words[3] + 0xd4ef3085;
    c = (c << 16) | (c >> 16);
    c += d;
    b += (c ^ d ^ a) + words[6] + 0x04881d05;
    b = (b << 23) | (b >> 9);
    b += c;
    a += (b ^ c ^ d) + words[9] + 0xd9d4d039;
    a = (a << 4) | (a >> 28);
    a += b;
    d += (a ^ b ^ c) + words[12] + 0xe6db99e5;
    d = (d << 11) | (d >> 21);
    d += a;
    c += (d ^ a ^ b) + words[15] + 0x1fa27cf8;
    c = (c << 16) | (c >> 16);
    c += d;
    b += (c ^ d ^ a) + words[2] + 0xc4ac5665;
    b = (b << 23) | (b >> 9);
    b += c;
    a += (c ^ (b | ~d)) + words[0] + 0xf4292244;
    a = (a << 6) | (a >> 26);
    a += b;
    d += (b ^ (a | ~c)) + words[7] + 0x432aff97;
    d = (d << 10) | (d >> 22);
    d += a;
    c += (a ^ (d | ~b)) + words[14] + 0xab9423a7;
    c = (c << 15) | (c >> 17);
    c += d;
    b += (d ^ (c | ~a)) + words[5] + 0xfc93a039;
    b = (b << 21) | (b >> 11);
    b += c;
    a += (c ^ (b | ~d)) + words[12] + 0x655b59c3;
    a = (a << 6) | (a >> 26);
    a += b;
    d += (b ^ (a | ~c)) + words[3] + 0x8f0ccc92;
    d = (d << 10) | (d >> 22);
    d += a;
    c += (a ^ (d | ~b)) + words[10] + 0xffeff47d;
    c = (c << 15) | (c >> 17);
    c += d;
    b += (d ^ (c | ~a)) + words[1] + 0x85845dd1;
    b = (b << 21) | (b >> 11);
    b += c;
    a += (c ^ (b | ~d)) + words[8] + 0x6fa87e4f;
    a = (a << 6) | (a >> 26);
    a += b;
    d += (b ^ (a | ~c)) + words[15] + 0xfe2ce6e0;
    d = (d << 10) | (d >> 22);
    d += a;
    c += (a ^ (d | ~b)) + words[6] + 0xa3014314;
    c = (c << 15) | (c >> 17);
    c += d;
    b += (d ^ (c | ~a)) + words[13] + 0x4e0811a1;
    b = (b << 21) | (b >> 11);
    b += c;
    a += (c ^ (b | ~d)) + words[4] + 0xf7537e82;
    a = (a << 6) | (a >> 26);
    a += b;
    d += (b ^ (a | ~c)) + words[11] + 0xbd3af235;
    d = (d << 10) | (d >> 22);
    d += a;
    c += (a ^ (d | ~b)) + words[2] + 0x2ad7d2bb;
    c = (c << 15) | (c >> 17);
    c += d;
    b += (d ^ (c | ~a)) + words[9] + 0xeb86d391;
    b = (b << 21) | (b >> 11);
    b += c;
    context->mHashWords[0] += a;
    context->mHashWords[1] += b;
    context->mHashWords[2] += c;
    context->mHashWords[3] += d;
    FillBytesWithLoop(words, 0, sizeof(words));
}

void CopyWordsToBytesLittleEndian(u8 *output, const u32 *input, u32 size) {
    u32 i;
    for (i = 0; i < size; i += 4) {
        output[i] = *input;
        output[i + 1] = *input >> 8;
        output[i + 2] = *input >> 16;
        output[i + 3] = *input >> 24;
        input++;
    }
}

void CopyBytesToWordsLittleEndian(u32 *output, const u8 *input, u32 size) {
    u32 i;
    for (i = 0; i < size; i += 4) {
        *output++ = (input[i + 3] << 24) | ((input[i + 2] << 16) | (input[i] | (input[i + 1] << 8)));
    }
}

void CopyBytesWithLoop(void *destination, const void *source, u32 count) {
    u8 *destinationBytes = destination;
    const u8 *sourceBytes = source;
    u32 i;
    for (i = 0; i < count; i++) {
        destinationBytes[i] = sourceBytes[i];
    }
}

void FillBytesWithLoop(void *buffer, s32 value, u32 count) {
    s8 *cursor = buffer;
    u32 i = 0;
    for (i = 0; i < count; i++) {
        *cursor++ = value;
    }
}

void ComputeHash(u8 *digest, const u8 *input, u32 size) {
    HashContext context;
    ResetHashContext(&context);
    AddBytesToHash(&context, input, size);
    FinishHash(digest, &context);
}

u32 GetTickMilliseconds(void) {
    return _ll_udiv(OS_GetTick() << 6, 0x82ea);
}

void *CallAllocFunctionAndClear(s32 count, s32 size) {
    s32 total = count * size;
    void *block = (void *) gAllocFunction(total);
    if (block != NULL) {
        memset(block, 0, total);
    }
    return block;
}

void CallFreeFunction(void *block) {
    u32 functionSlot = ((u32) (&gFreeFunction));
    u32 freeFunction = (*(u32 *) ((functionSlot) + (0)));
    u32 result = ((u32(*)(void *))(freeFunction))(block);
}

s32 FormatByteAsHex(u8 *output, s8 value) {
    u8 *cursor = output;
    u8 byte = value;
    s32 i;
    s32 digit;
    s32 lowDigit;
    digit = (byte & 0xf0) >> 4;
    i = 0;
    lowDigit = byte & 0xf;
    for (; i < 2; i++) {
        if (digit <= 9) {
            *cursor++ = digit + 0x30;
        } else {
            *cursor++ = digit + 0x37;
        }
        digit = lowDigit;
    }
    *cursor = 0;
    return cursor - output;
}

s32 FormatMacAddress(u8 *output, const s8 *address) {
    u8 *cursor = output;
    s32 i;
    for (i = 0; i < 6; i++) {
        cursor += FormatByteAsHex(cursor, *address++);
        if (i < 5) {
            *cursor++ = ':';
        }
    }
    *cursor = 0;
    return cursor - output;
}

// Starts the thread that runs RunExchange; returns 1, or -10 while a run is under way.
s32 StartExchange(u32 priority, s32 count, UnkFunc *callback, UnkWordFunc *allocFunction, UnkFunc *freeFunction,
                  u32 stackSize) {
    s32 result;
    if (gExchangeStatus >= 1 && gExchangeStatus <= 5) {
        return -10;
    }
    data_ov003_021d68bc = count;
    gExchangeStatus = 7;
    gStatusCallback = callback;
    gAllocFunction = allocFunction;
    gFreeFunction = freeFunction;
    gThreadStackSize = stackSize;
    result = func_ov003_021be418(count);
    data_ov003_021d8c44 = 1;
    if (result < 0) {
        gExchangeResultCode = result;
        return result;
    }
    gThreadStack = (void *) gAllocFunction(gThreadStackSize);
    if (gThreadStack == NULL) {
        gExchangeResultCode = -1;
        return -1;
    }
    if (OS_IsThreadAvailable() != 1) {
        gExchangeResultCode = -9;
        return -9;
    }
    OS_CreateThread(&gExchangeThread, (void (*)(void *)) RunExchangeThread, NULL,
                    (u8 *) gThreadStack + (gThreadStackSize & ~7), gThreadStackSize, priority);
    gExchangeStatus = 1;
    gTimeoutAtMs = GetTickMilliseconds() + 60000;
    gStopRequested = 0;
    __clear(&gExchangeResult, 0xe8);
    CallStatusCallback();
    OS_WakeupThreadDirect(&gExchangeThread);
    gThreadStarted = 1;
    return 1;
}

// Asks the thread to stop, waits for it to end, frees its stack and shuts the lower layer down.
s32 StopExchange(void) {
    s32 oldStatus;
    if (gThreadStarted != 0) {
        oldStatus = gExchangeStatus;
        gStopRequested = 1;
        while (gExchangeStatus >= 1 && gExchangeStatus <= 5) {
            OS_Sleep(100);
        }
        OS_Sleep(500);
        if (OS_IsThreadTerminated(&gExchangeThread) == 0) {
            do {
                OS_WakeupThreadDirect(&gExchangeThread);
                OS_JoinThread(&gExchangeThread);
            } while (OS_IsThreadTerminated(&gExchangeThread) == 0);
        }
        if (gThreadStack != NULL) {
            gFreeFunction(gThreadStack);
            gThreadStack = NULL;
        }
        gThreadStarted = 0;
        if (oldStatus != gExchangeStatus) {
            CallStatusCallback();
        }
    }
    if (data_ov003_021d8c44 > 0) {
        s32 result = func_ov003_021be3b8();
        data_ov003_021d8c44 = 0;
        return result;
    }
    return -10;
}

u32 GetExchangeStatus(u32 *output) {
    int now;
    *output = *(u32 *) &gExchangeStatus;
    if ((gTimeoutAtMs) == -1) {
        output[1] = 0xffffffff;
    } else {
        now = GetTickMilliseconds();
        output[1] = (gTimeoutAtMs) -now;
    }
    output[2] = *(u32 *) &gExchangeResultCode;
    return 1;
}

u32 CopyExchangeResult(ExchangeResult *output) {
    memcpy(((u32 *) (u32) output), &gExchangeResult, 0xe8);
    return 1;
}

// Reports the status, the time left and the result code to the stored callback.
void CallStatusCallback(void) {
    u8 status[8];
    GetExchangeStatus(((void *) status));
    (*(UnkFunc *) (u32) gStatusCallback)(status);
}
