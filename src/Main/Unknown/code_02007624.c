#include "Main/Unknown/code_02007624.h"
#include "Main/Unknown/code_020091fc.h"
#include "code_0214d018.h"

#pragma thumb on

void *func_02007e38(u32 child) {
    u32 savedInterrupts;
    savedInterrupts = OS_DisableInterrupts();
    if (data_0216fdac != NULL && IsChildIndexInRange(child) != 0) {
        MI_CpuCopy8(data_0216fdac->mUnk_1340 + (child - 1) * 0x16, data_0216fdac->mUnk_1772, 0x16);
        OS_RestoreInterrupts(savedInterrupts);
        return data_0216fdac->mUnk_1772;
    }
    OS_RestoreInterrupts(savedInterrupts);
    return NULL;
}

u32 func_02007df8(u32 child) {
    if (data_0216fdac != NULL && IsChildIndexInRange(child) != 0 && data_0216fdac->mUnk_14e8[child - 1] == 7) {
        return 1;
    }
    return 0;
}

u32 func_02007d50(u32 child, u32 pairIndex) {
    u32 savedInterrupts;
    u32 newValue;
    u32 expectedValue;
    savedInterrupts = OS_DisableInterrupts();
    switch (pairIndex) {
        case 0:
            expectedValue = 0xa;
            newValue = 4;
            break;
        case 1:
            expectedValue = 0xa;
            newValue = 3;
            break;
        case 2:
            expectedValue = 0xe;
            newValue = 2;
            break;
        case 3:
            expectedValue = 7;
            newValue = 5;
            break;
        default:
            OS_RestoreInterrupts(savedInterrupts);
            return 0;
    }
    if (data_0216fdac != NULL && IsChildIndexInRange(child) != 0 &&
        expectedValue == data_0216fdac->mUnk_14e8[child - 1]) {
        data_0216fdac->mUnk_1754[child - 1] = newValue;
        OS_RestoreInterrupts(savedInterrupts);
        return 1;
    }
    OS_RestoreInterrupts(savedInterrupts);
    return 0;
}

void func_02007d18(u32 child, u32 value, void *data) {
    if (IsChildIndexInRange(child) != 0) {
        data_0216fdac->mUnk_14e8[child - 1] = value;
    }
    func_02007cf8(child, value, data);
}

void func_02007cf8(u32 child, u32 value, void *data) {
    Unk0216fdac *work;
    work = data_0216fdac;
    if (work->mCallback != NULL) {
        work->mCallback(child, value, data);
    }
}

void func_020079c4(s32 eventCode, Unk021425e8 *eventData) {
    u32 v1;
    u8 i;
    Unk0216fdac *work;
    u32 v2;
    u16 child;
    u8 entryIndex;
    s32 childEntryIndex;
    void (*callback)(u32, u32, void *);
    v1 = 0;
    switch (eventCode) {
        case 0x15:
            func_02007d18(0, 1, eventData);
            break;
        case 0:
            child = eventData->mUnk_10;
            if (child != 0 && child < 16) {
                func_02007d18(child, 2, eventData);
            }
            break;
        case 1:
            child = eventData->mUnk_10;
            if (child != 0 && child < 16) {
                data_0216fdac->mUnk_148a[eventData->mUnk_10 - 1] = 0;
                MI_CpuFill8(data_0216fdac->mUnk_14a8 + (eventData->mUnk_10 - 1), 0, 4);
                MI_CpuFill8(data_0216fdac->mUnk_1340 + (eventData->mUnk_10 - 1) * 0x16, 0, 0x16);
                ClearChildPieces(eventData->mUnk_10);
                v2 = 0;
                data_0216fdac->mUnk_1754[eventData->mUnk_10 - 1] = v2;
                child = eventData->mUnk_10;
                childEntryIndex = data_0216fdac->mChildEntryIndex[(s32) child - 1];
                v2 = ~v2;
                if (childEntryIndex != v2) {
                    v1 = 1 << child;
                    entryIndex = childEntryIndex;
                    (OFFSET_PTR(Unk0216fdac, data_0216fdac, entryIndex * 0x5d4))->mUnk_1d4e &= ~v1;
                    (OFFSET_PTR(Unk0216fdac, data_0216fdac, entryIndex * 0x5d4))->mUnk_1d50 |= v1;
                    data_0216fdac->mChildEntryIndex[child - 1] = v2;
                    (OFFSET_PTR(Unk0216fdac, data_0216fdac, entryIndex * 0x5d4))->mUnk_1d4c &= ~v1;
                }
                if ((data_0216fdac->mUnk_1536 & (1 << eventData->mUnk_10)) != 0) {
                    data_0216fdac->mUnk_1535--;
                    data_0216fdac->mUnk_1536 &= ~(1 << eventData->mUnk_10);
                }
                child = eventData->mUnk_10;
                if (data_0216fdac->mUnk_14e8[child - 1] == 8) {
                    func_02007d18(child, 9, NULL);
                }
                func_02007d18(eventData->mUnk_10, 3, eventData);
                data_0216fdac->mUnk_14e8[eventData->mUnk_10 - 1] = 0;
            }
            break;
        case 0x11:
            break;
        case 3:
            func_02007624((Unk021432ac *) eventData);
            break;
        case 0x19:
            func_020071b4();
            break;
        case 0x1c:
            i = 0;
            v1 = 0;
            do {
                work = data_0216fdac;
                v2 = i * 0x5d4;
                if ((OFFSET_PTR(Unk0216fdac, work, v2))->mEntryUsed != 0 &&
                    (OFFSET_PTR(Unk0216fdac, work, v2))->mUnk_1d50 != 0) {
                    func_0200973c((Unk0200b610 *) (work->mUnk_1788 + 0xe4 + v2), work->mUnk_1340,
                                  (OFFSET_PTR(Unk0216fdac, work, v2))->mUnk_1d4e,
                                  (OFFSET_PTR(Unk0216fdac, work, v2))->mUnk_1d50);
                    (OFFSET_PTR(Unk0216fdac, data_0216fdac, v2))->mUnk_1d50 = v1;
                }
                i++;
            } while (i < 16);
            {
                u32 ggid;
                u16 tgid;
                ggid = GetGgid();
                tgid = GetTgid();
                func_0200964c(ggid, tgid, GetGameInfoAttr());
            }
            break;
        case 0xff:
            switch (eventData->mResultCode) {
                case 1:
                case 4:
                case 5:
                case 6:
                case 8:
                case 9:
                    func_02007120(0, 9);
                    break;
                case 15:
                default:
                    func_02007120(0, 8);
                    break;
            }
            break;
        case 0x100:
            switch (eventData->mCommand) {
                case 0:
                case 7:
                case 8:
                case 13:
                case 14:
                case 15:
                case 17:
                case 18:
                case 21:
                case 25:
                case 29:
                    func_02007120(0, 9);
                    break;
                case 22:
                default:
                    func_02007120(0, 8);
                    break;
            }
            break;
    }
    if (eventCode == 0x11) {
        callback = data_0216fdac->mCallback;
        MemFillWordsByBlock_inline(data_0216fdac, 0x7d00);
        data_0216fdac = NULL;
        if (callback != NULL) {
            callback(0, 0xc, NULL);
        }
    }
}

void func_02007698(Unk021432ac *childData, u32 child) {
    ChildMessage message;
    Unk0200c12c payloadCopy;
    u8 *payload;
    u32 arrayIndex;
    u32 childValue;
    u8 bitIndex;
    u8 bitCount;
    u8 entryIndex;
    u32 v12;
    if (child == 0 || child > 15) {
        return;
    }
    payload = ReadChildMessage(childData->mUnk_0a, &message, child);
    arrayIndex = child - 1;
    childValue = data_0216fdac->mUnk_14e8[arrayIndex];
    switch (message.mKind) {
        case 7:
            if (childValue == 2) {
                if (payload == NULL) {
                    return;
                }
                MI_CpuCopy8(payload, &payloadCopy, 0x1d);
                v12 = child - 1;
                data_0216fdac->mUnk_14a8[arrayIndex] = payloadCopy.mUnk_00;
                data_0216fdac->mUnk_148a[v12] = payloadCopy.mUnk_1a;
                v12 *= 0x16;
                MI_CpuCopy8(payloadCopy.mUnk_04, data_0216fdac->mUnk_1340 + v12, 0x16);
                ((Unk0216fdac_1340 *) &data_0216fdac->mUnk_1340[v12])->mUnk_00_4 = child;
                func_02007d18(child, 0xa, payloadCopy.mUnk_04);
            }
            if (childValue == 10) {
                bitCount = 0;
                entryIndex = ((Unk0200c12c *) payload)->mUnk_1c;
                if (entryIndex >= 16 || (OFFSET_PTR(Unk0216fdac, data_0216fdac, entryIndex * 0x5d4))->mEntryUsed == 0 ||
                    data_0216fdac->mUnk_14a8[arrayIndex] !=
                        (OFFSET_PTR(Unk0216fdac, data_0216fdac, entryIndex * 0x5d4))->mUnk_1d40->mUnk_14) {
                    data_0216fdac->mUnk_1754[arrayIndex] = 4;
                } else {
                    bitIndex = 0;
                    do {
                        if (((1 << bitIndex) &
                             (OFFSET_PTR(Unk0216fdac, data_0216fdac, entryIndex * 0x5d4))->mUnk_1d4e) != 0) {
                            bitCount++;
                        }
                        bitIndex++;
                    } while (bitIndex < 16);
                    if (bitCount >=
                        (OFFSET_PTR(Unk0216fdac, data_0216fdac, entryIndex * 0x5d4))->mUnk_1d40->mUnk_18[0]) {
                        data_0216fdac->mUnk_1754[arrayIndex] = 0;
                        func_02007d18(child, 0xb, NULL);
                        return;
                    }
                }
                switch (data_0216fdac->mUnk_1754[arrayIndex]) {
                    case 3:
                        if ((data_0216fdac->mUnk_1536 & (1U << child)) != 0) {
                            return;
                        }
                        data_0216fdac->mUnk_1535++;
                        data_0216fdac->mUnk_1536 |= 1 << child;
                        data_0216fdac->mChildEntryIndex[child - 1] = entryIndex;
                        (OFFSET_PTR(Unk0216fdac, data_0216fdac, entryIndex * 0x5d4))->mUnk_1d4e |= 1 << child;
                        (OFFSET_PTR(Unk0216fdac, data_0216fdac, entryIndex * 0x5d4))->mUnk_1d50 |= 1 << child;
                        data_0216fdac->mUnk_1754[arrayIndex] = 0;
                        func_02007d18(child, 5, NULL);
                        break;
                    case 4:
                        (OFFSET_PTR(Unk0216fdac, data_0216fdac, arrayIndex * 2))->mUnk_1754[0] = 0;
                        func_02007d18(child, 4, NULL);
                        break;
                }
            }
            break;
        case 8:
            if (childValue == 5) {
                func_02007d18(child, 0xe, NULL);
            } else if (childValue == 0xe) {
                if (data_0216fdac->mUnk_1754[arrayIndex] == 2) {
                    entryIndex = data_0216fdac->mChildEntryIndex[arrayIndex];
                    (OFFSET_PTR(Unk0216fdac, data_0216fdac, entryIndex * 0x5d4))->mUnk_1d4c |= 1 << child;
                    (OFFSET_PTR(Unk0216fdac, data_0216fdac, entryIndex * 0x5d4))->mUnk_1d48 = 0;
                    data_0216fdac->mUnk_1754[arrayIndex] = 0;
                    func_02007d18(child, 6, NULL);
                }
            }
            break;
        case 9:
            if (childValue == 6) {
                entryIndex = data_0216fdac->mChildEntryIndex[arrayIndex];
                if (entryIndex != 0xff) {
                    (OFFSET_PTR(Unk0216fdac, data_0216fdac, entryIndex * 0x5d4))->mUnk_1d4a = GetLargerValue(
                        (OFFSET_PTR(Unk0216fdac, data_0216fdac, entryIndex * 0x5d4))->mUnk_1d4a, message.mUnk_02);
                }
            }
            break;
        case 10:
            if (childValue == 6) {
                entryIndex = data_0216fdac->mChildEntryIndex[arrayIndex];
                if (entryIndex != 0xff) {
                    (OFFSET_PTR(Unk0216fdac, data_0216fdac, entryIndex * 0x5d4))->mUnk_1d4c &= ~(1 << child);
                    func_02007d18(child, 7, NULL);
                }
            } else if (childValue == 7) {
                if (data_0216fdac->mUnk_1754[arrayIndex] == 5) {
                    (OFFSET_PTR(Unk0216fdac, data_0216fdac, arrayIndex * 2))->mUnk_1754[0] = 0;
                    func_02007d18(child, 8, NULL);
                }
            }
            break;
        case 11:
            break;
    }
}

void func_02007624(Unk021432ac *header) {
    u16 i;
    u16 firstHalfword;
    void *childData;
    for (i = 0; i < 16; i++) {
        if ((OFFSET_PTR(Unk0216fdac, data_0216fdac, i * 0x5d4))->mEntryUsed != 0) {
            (OFFSET_PTR(Unk0216fdac, data_0216fdac, i * 0x5d4))->mUnk_1d4a = 0;
        }
    }
    for (i = 1; i <= 15; i++) {
        childData = WM_ReadMPData(header, i);
        if (childData != NULL) {
            firstHalfword = *(u16 *) childData;
            if (firstHalfword != 0xffff && firstHalfword != 0) {
                func_02007698(childData, i);
            }
        }
    }
}

#pragma thumb off
