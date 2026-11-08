#include "03/code_021b94b8.h"
#include "03/code_021b7000.h"
#include "03/unk_021d8000.h"
#include "Main/Unknown/code_02133000.h"
#include "03/code_021b7bb4.h"
#include "03/code_021bb03c.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"
#include "00/code_021a669c.h"

MaskCodeEntry gMaskCodeTable[12] = {
    {0x0001, 0x02, 0}, {0x0002, 0x04, 0}, {0x0004, 0x0b, 0}, {0x0008, 0x0c, 0}, {0x0010, 0x12, 0}, {0x0020, 0x16, 0},
    {0x0040, 0x18, 0}, {0x0080, 0x24, 0}, {0x0100, 0x30, 0}, {0x0200, 0x48, 0}, {0x0400, 0x60, 0}, {0x0800, 0x6c, 0},
};

void ConvertRecordToEssidEntry(RawEntry *src, EssidEntry *dst) {
    int i;
    int count;
    int mode;
    dst->mEssidLength = src->mSsidLength;
    MIi_CpuCopy16(src->mSsid, dst->mEssid, 0x20);
    dst->mUnk_24 = src->mUnk_36;
    MIi_CpuCopy16(&src->mAddress, dst->mUnk_30, 6);
    count = 0;
    for (i = 0; i < 12; i++) {
        if (src->mUnk_30 & gMaskCodeTable[i].mMask) {
            dst->mCodes[count] = gMaskCodeTable[i].mCode;
            if (src->mUnk_2e & gMaskCodeTable[i].mMask) {
                dst->mCodes[count] |= 0x80;
            }
            count++;
        }
    }
    dst->mCodeCount = count;
    dst->mUnk_4c = src->mUnk_32;
    mode = src->mFlags & 3;
    if (mode == 1) {
        dst->mUnk_50 = 1;
    } else if (mode == 2) {
        dst->mUnk_50 = 2;
    } else {
        dst->mUnk_50 = 0;
    }
}

void SetRecordEssidFromRequest(EssidMelcoRequest *request, RawEntry *rec) {
    vu16 zero = 0;
    MIi_CpuClear16(zero, rec->mSsid, 0x20);
    rec->mSsidLength = request->mEssidLength;
    MI_CpuCopy8(request->mEssid, rec->mSsid, rec->mSsidLength);
}

void FillEssidEntryListFromRecord(EssidEntryList *list, RawEntry *src, s32 count) {
    list->mCount = count;
    ConvertRecordToEssidEntry(src, list->mEntries);
}

s32 func_ov003_021ba720(void *msg) {
    return OS_SendMessage(&gMessageQueue, msg, 0);
}

s32 func_ov003_021ba70c(void *msg) {
    return OS_SendMessage(&gMessageQueue, msg, 0);
}

s32 func_ov003_021ba61c(void *(*alloc)(u32), void (*release)(void *)) {
    BOOL running = TRUE;
    void *msg;
    void *buffer;
    u32 enabled;
    OS_InitMessageQueue(&gMessageQueue, gMessageQueueSlots, 4);
    if (alloc == NULL || release == NULL) {
        return -1;
    }
    enabled = OS_DisableInterrupts();
    data_ov003_021d8a0c = alloc;
    data_ov003_021d8a18 = release;
    OS_RestoreInterrupts(enabled);
    buffer = data_ov003_021d8a0c(0x5890);
    data_ov003_021d8a14 = buffer;
    if (buffer == NULL) {
        return -1;
    }
    if (func_ov003_021ba818(func_ov003_021ba720, buffer, 0x5890) == FALSE) {
        running = FALSE;
    }
    if (running != FALSE) {
        do {
            OS_ReceiveMessage(&gMessageQueue, &msg, 1);
            switch ((u32) msg) {
                case 4:
                case 5:
                    break;
                case 6:
                    return 0;
                    // placeholder: labels that fall into default only give the original's jump table its size
                case 8:
                case 0xa:
                case 0xc:
                case 0xd:
                case 0xf:
                default:
                    running = FALSE;
                    break;
            }
        } while (running != FALSE);
    }
    data_ov003_021d8a18(data_ov003_021d8a14);
    return -1;
}

s32 func_ov003_021ba560(void) {
    s32 result;
    BOOL running;
    void *msg;
    u32 enabled;
    running = TRUE;
    result = -1;
    if (data_ov003_021d8a18 == NULL) {
        return -1;
    }
    if (func_ov003_021ba9c0() == FALSE) {
        return -1;
    }
    do {
        OS_ReceiveMessage(&gMessageQueue, &msg, 1);
        switch ((u32) msg) {
            case 4:
            case 5:
                break;
            case 0x14:
                running = FALSE;
                result = 0;
                data_ov003_021d8a18(data_ov003_021d8a14);
                break;
                // placeholder: labels that fall into default only give the original's jump table its size
            case 8:
            case 0xa:
            case 0xc:
            case 0xd:
            case 0x12:
            case 0x13:
            default:
                running = FALSE;
                break;
        }
    } while (running != FALSE);
    enabled = OS_DisableInterrupts();
    data_ov003_021d8a0c = NULL;
    data_ov003_021d8a18 = NULL;
    OS_RestoreInterrupts(enabled);
    return result;
}

s32 func_ov003_021ba524(void) {
    BOOL done;
    s32 result = -1;
    void *msg;
    if (func_ov003_021baa28() != FALSE) {
        done = FALSE;
        do {
            OS_ReceiveMessage(&gMessageQueue, &msg, 1);
            /* waits for one entry; the loop flag is a placeholder */
            if ((u32) msg == 0xe) {
                result = 0;
                done = FALSE;
            }
        } while (done != FALSE);
    }
    return result;
}

s32 ScanEssidEntries(EssidEntryList **out) {
    BOOL found = FALSE;
    s32 result = -1;
    BOOL running = TRUE;
    s32 count = 0;
    s32 waits = 0;
    RawEntry *scan;
    RawEntry *buffer;
    EssidEntryList *list;
    void *msg;
    OSAlarm timer;
    s32 i;
    if (data_ov003_021d8a0c == NULL || data_ov003_021d8a18 == NULL) {
        return -1;
    }
    scan = data_ov003_021d8a0c(0x3000);
    if (scan == NULL) {
        return -1;
    }
    buffer = scan;
    if (func_ov003_021baaac(NULL, NULL, 0, 0x30bffe) != 0) {
        OS_CreateAlarm(&timer);
        OS_SetAlarm(&timer, 0x3fec42, (void (*)(void *)) func_ov003_021ba70c, (void *) 0x13);
        do {
            OS_ReceiveMessage(&gMessageQueue, &msg, 1);
            switch ((u32) msg) {
                case 0x13:
                    if (found == FALSE) {
                        if (waits != 0) {
                            count = func_ov003_021babc0(scan, 0x40);
                        }
                        if (func_ov003_021baa68() == FALSE) {
                            goto cleanup;
                        }
                        found = TRUE;
                    }
                    break;
                case 5:
                    if (found == FALSE) {
                        if (waits < 8) {
                            waits++;
                        } else {
                            count = func_ov003_021babc0(scan, 0x40);
                            if (func_ov003_021baa68() == FALSE) {
                                goto cleanup;
                            }
                            found = TRUE;
                        }
                    }
                    break;
                case 0xa:
                    running = FALSE;
                    result = 0;
                    break;
                case 4:
                case 8:
                case 0x12:
                    break;
                    // placeholder: labels that fall into default only give the original's jump table its size
                case 0xc:
                case 0xd:
                default:
                    goto cleanup;
            }
        } while (running != FALSE);
        if (count != 0) {
            list = data_ov003_021d8a0c((count - 1) * 0x54 + 0x58);
            if (list == NULL) {
                goto cleanup;
            }
        } else {
            list = data_ov003_021d8a0c(0x58);
            if (list == NULL) {
                goto cleanup;
            }
        }
        *out = list;
        list->mCount = count;
        for (i = 0; i < count; i++) {
            ConvertRecordToEssidEntry(scan, &list->mEntries[i]);
            scan++;
        }
    cleanup:
        OS_CancelAlarm(&timer);
        while (OS_ReceiveMessage(&gMessageQueue, &msg, 0) == 1) {
        }
    }
    data_ov003_021d8a18(buffer);
    return result;
}

s32 RunEssidMelcoRequest(EssidMelcoRequest *request, EssidEntryList *out) {
    BOOL running = TRUE;
    s32 result;
    s32 retries;
    BOOL done;
    u32 flags;
    void *msg;
    OSAlarm timer;
    done = FALSE;
    result = -1;
    if (request->mUnk_24 == FALSE) {
        flags = 0x80000;
    } else if (request->mUnk_24 == TRUE) {
        flags = 0xc0000;
    }
    MI_CpuFill8(&data_ov003_021d8a4c, 0, 0x60);
    if (request->mMelcoLength == 5) {
        data_ov003_021d8a4c.mLengthKind = 1;
    } else if (request->mMelcoLength == 0xd) {
        data_ov003_021d8a4c.mLengthKind = 2;
    } else if (request->mMelcoLength == 0x10) {
        data_ov003_021d8a4c.mLengthKind = 3;
    } else {
        return -1;
    }
    data_ov003_021d8a4c.mUnk_01 = 0;
    MI_CpuCopy8(request->mMelcoBytes, data_ov003_021d8a4c.mMelcoBytes, request->mMelcoLength);
    func_ov000_021a6894();
    if (func_ov003_021baaac(NULL, request->mEssid, request->mEssidLength, 0x30bffe) != 0) {
        retries = 0;
        OS_CreateAlarm(&timer);
        OS_SetAlarm(&timer, 0x3fec42, (void (*)(void *)) func_ov003_021ba70c, (void *) 0x12);
        flags |= 0x30000;
        do {
            OS_ReceiveMessage(&gMessageQueue, &msg, 1);
            switch ((u32) msg) {
                case 0x12:
                    if (done == FALSE) {
                        running = FALSE;
                    }
                    break;
                case 5:
                    if (done == FALSE) {
                        OS_CancelAlarm(&timer);
                        if (func_ov003_021babc0(&data_ov003_021d8ac0, 1) != 1) {
                            running = FALSE;
                        } else {
                            SetRecordEssidFromRequest(request, &data_ov003_021d8ac0);
                            if (func_ov003_021ba910(&data_ov003_021d8ac0, &data_ov003_021d8a4c, flags) == FALSE) {
                                running = FALSE;
                            } else {
                                done = TRUE;
                            }
                        }
                    }
                    break;
                case 0xa:
                    SetRecordEssidFromRequest(request, &data_ov003_021d8ac0);
                    if (func_ov003_021ba910(&data_ov003_021d8ac0, &data_ov003_021d8a4c, flags) == FALSE) {
                        running = FALSE;
                    }
                    break;
                case 0xc:
                    result = 0;
                    running = FALSE;
                    break;
                case 0xd:
                    retries++;
                    if (retries < 3) {
                        if (func_ov003_021ba910(&data_ov003_021d8ac0, &data_ov003_021d8a4c, flags) == FALSE) {
                            running = FALSE;
                        }
                    } else {
                        running = FALSE;
                    }
                    break;
                case 4:
                case 8:
                case 0x13:
                    break;
                default:
                    running = FALSE;
                    break;
            }
        } while (running != FALSE);
        OS_CancelAlarm(&timer);
        while (OS_ReceiveMessage(&gMessageQueue, &msg, 0) == 1) {
        }
    }
    FillEssidEntryListFromRecord(out, &data_ov003_021d8ac0, result == 0 ? 1 : 0);
    return result;
}

void func_ov003_021ba1a8(u32 msec) {
    OS_Sleep(msec);
}

int func_ov003_021ba18c(int state) {
    // nothing in the game sets this pointer
    if (data_ov003_021d8a10 != NULL) {
        data_ov003_021d8a10(state);
    }
    return 0;
}

void *func_ov003_021ba178(u32 size) {
    return data_ov003_021d8a0c(size);
}

void func_ov003_021ba164(void *ptr) {
    data_ov003_021d8a18(ptr);
}

s32 func_ov003_021ba05c(ValueRecordsRequest *req) {
    s32 status;
    s32 ret;
    if (req->mScanRetryLimit == 0 || req->mScanRetryLimit < -1 || req->mScanRetryDelayMs < -1 ||
        req->mSendAttemptLimit == 0 || req->mSendAttemptLimit < -1 || req->mSendAttemptDelayMs < -1 ||
        req->mReceiveTimeoutMs < -1 || req->mItemLength == 0 || req->mItemLength > 0x100 ||
        req->mItemBytes[req->mItemLength - 1] != 0) {
        status = -1;
    } else {
        status = 0;
    }
    if (data_ov003_021d8a0c == NULL || data_ov003_021d8a18 == NULL) {
        status = -1;
    }
    if (status == -1) {
        req->mResultCode = 0xf;
        ReleaseEssidEntryLists();
        return -1;
    }
    gRequestPacketBuffer = func_ov003_021ba178(0x5f8);
    if (gRequestPacketBuffer == NULL) {
        req->mResultCode = 0xf;
        ReleaseEssidEntryLists();
        return -1;
    }
    ReportStateChange(-1);
    ret = func_ov003_021b9570(req);
    func_ov003_021ba164(gRequestPacketBuffer);
    ReleaseEssidEntryLists();
    if (gSocketDescriptor != -1) {
        func_ov003_021b7ce4(gSocketDescriptor);
    }
    return ret;
}

s32 func_ov003_021b9570(ValueRecordsRequest *req) {
    s16 timeout;
    s32 mode;
    s32 state;
    s32 addr;
    PacketBuffer *buffer;
    s32 scanResult;
    s32 result;
    RetryLimit scan = data_ov003_021d6808;
    RetryLimit limits = {0, 0};
    s32 value = 1;
    s32 attempts;
    s32 ret;
    u8 code;
    s16 cnt;
    s16 delay;
    SocketAddress src2;
    s32 srcLen;
    s32 received;
    Unk021b7ba0 set;
    WaitTimeout wait;
    SocketAddress info;
    PacketTag list[3];
    EssidMelcoRequest request;
    Unk021b86e4 buf;

    mode = 0;
    attempts = mode;
    addr = mode;
    FillBytes(list, 0, sizeof(list));
    scan.mCount = req->mScanRetryLimit;
    if (scan.mCount == -1) {
        scan.mCount = 10;
    }
    limits.mCount = req->mSendAttemptLimit;
    if (limits.mCount == -1) {
        limits.mCount = 10;
    }
    scan.mDelayMs = req->mScanRetryDelayMs;
    if (scan.mDelayMs == -1) {
        scan.mDelayMs = 100;
    }
    limits.mDelayMs = req->mSendAttemptDelayMs;
    if (limits.mDelayMs == -1) {
        limits.mDelayMs = 100;
    }
    timeout = req->mReceiveTimeoutMs;
    if (timeout == -1) {
        timeout = 2000;
    }
    InitRequestState(req);
    if ((gRequestState.mWantedRecordMask & 1) != 1) {
        SetErrorCode(0x13);
        req->mResultCode = 0xf;
        ReleaseEssidEntryLists();
        return -1;
    }

    cnt = 0;
    ReportStateChange(0);
    delay = scan.mDelayMs;
    while (1) {
        if (gScannedEssidList != NULL) {
            func_ov003_021ba164(gScannedEssidList);
            gScannedEssidList = NULL;
        }
        if (ScanEssidEntries(&gScannedEssidList) == -1) {
            req->mResultCode = 0xf;
            ReleaseEssidEntryLists();
            return -1;
        }
        result = CheckSingleEssidAossEntry(gScannedEssidList);
        if (result == 4) {
            req->mResultCode = 2;
            ReleaseEssidEntryLists();
            return -1;
        }
        if (result == 0) {
            break;
        }
        if (cnt >= scan.mCount) {
            req->mResultCode = 1;
            ReleaseEssidEntryLists();
            return -1;
        }
        func_ov003_021ba1a8(delay);
        cnt++;
    }

    ReportStateChange(1);
    FillBytes(&request, 0, 0x3c);
    if (FillEssidAossAndMelcoRequest(&request) != 0) {
        req->mResultCode = 0xf;
        ReleaseEssidEntryLists();
        return -1;
    }
    gRequestedEssidList = func_ov003_021ba178(0x58);
    if (gRequestedEssidList == NULL) {
        req->mResultCode = 0xf;
        ReleaseEssidEntryLists();
        return -1;
    }
    FillBytes(gRequestedEssidList, 0, 0x58);
    cnt = 0;
    if (scan.mCount > 0) {
        do {
            result = RunEssidMelcoRequest(&request, gRequestedEssidList);
            if (result == -1) {
                req->mResultCode = 0xf;
                ReleaseEssidEntryLists();
                return -1;
            }
            if (result == 0) {
                /* repeated test of result, kept as a placeholder */
                if (result != 0 || gRequestedEssidList->mCount == 1) {
                    break;
                }
            }
            func_ov003_021ba1a8(delay);
            cnt++;
        } while (cnt < scan.mCount);
    }
    if (cnt == scan.mCount) {
        req->mResultCode = 0xf;
        ReleaseEssidEntryLists();
        return -1;
    }
    if (func_ov003_021b7df4(0xc0a80b65, 0xffffff00, 0xc0a80b65) != 0) {
        SetErrorCode(0xc);
        req->mResultCode = 0xf;
        ReleaseEssidEntryLists();
        return -1;
    }
    ReleaseEssidEntryLists();
    FillPacketTags(3, list, req->mMacAddress);
    gSocketDescriptor = func_ov003_021b7cf8(2, 2, 0);
    if (gSocketDescriptor < 0) {
        req->mResultCode = 0xf;
        ReleaseEssidEntryLists();
        return -1;
    }
    if (func_ov003_021b7d00(gSocketDescriptor, 0xffff, 1, &value, 4) < 0) {
        SetErrorCode(0xb);
        req->mResultCode = 0xf;
        ReleaseEssidEntryLists();
        return -1;
    }
    FillBytes(&info, 0, 8);
    info.mUnk_01 = 2;
    info.mAddress = SwapBytes32(0xc0a80b65);
    info.mPort = func_ov003_021b7c94(0x5790);
    if (func_ov003_021b7cec(gSocketDescriptor, &info, 8) < 0) {
        req->mResultCode = 0xf;
        ReleaseEssidEntryLists();
        return -1;
    }

    while (1) {
        buffer = gRequestPacketBuffer;
        FillBytes(&buf, 0, 0x14);
        buf.mUnk_10 = 0xc0a80b65;
        buf.mUnk_00 = 0xc0a80b01;
        while (1) {
            if (mode == 1 && gRequestState.mAddressApplied != 1) {
                if (gSocketDescriptor != -1) {
                    func_ov003_021b7ce4(gSocketDescriptor);
                }
                gSocketDescriptor = -1;
                if (func_ov003_021b7dc8() != 0) {
                    req->mResultCode = 0xf;
                    ReleaseEssidEntryLists();
                    return -1;
                }
                if (gScannedEssidList != NULL) {
                    func_ov003_021ba164(gScannedEssidList);
                    gScannedEssidList = NULL;
                }
                gScannedEssidList = func_ov003_021ba178(0x58);
                if (gScannedEssidList == NULL) {
                    req->mResultCode = 0xf;
                    ReleaseEssidEntryLists();
                    return -1;
                }
                while (1) {
                    scanResult = ScanEssidEntries(&gScannedEssidList);
                    if (scanResult == -1) {
                        req->mResultCode = 0xf;
                        ReleaseEssidEntryLists();
                        return -1;
                    }
                    result = CheckSingleEssidAossEntry(gScannedEssidList);
                    if (result == 4) {
                        req->mResultCode = 2;
                        ReleaseEssidEntryLists();
                        return -1;
                    }
                    if (result == 0) {
                        break;
                    }
                    if (cnt >= scan.mCount) {
                        req->mResultCode = 1;
                        ReleaseEssidEntryLists();
                        return -1;
                    }
                    func_ov003_021ba1a8(delay);
                    cnt++;
                }
                if (scanResult == -1) {
                    req->mResultCode = 0xf;
                    ReleaseEssidEntryLists();
                    return -1;
                }
                gRequestedEssidList = func_ov003_021ba178(0x58);
                if (gRequestedEssidList == NULL) {
                    req->mResultCode = 0xf;
                    ReleaseEssidEntryLists();
                    return -1;
                }
                FillBytes(gRequestedEssidList, 0, 0x58);
                cnt = 0;
                if (scan.mCount > 0) {
                    do {
                        result = RunEssidMelcoRequest(&request, gRequestedEssidList);
                        if (result == -1) {
                            req->mResultCode = 0xf;
                            ReleaseEssidEntryLists();
                            return -1;
                        }
                        if (result == 0) {
                            /* repeated test of result, kept as a placeholder */
                            if (result != 0 || gRequestedEssidList->mCount == 1) {
                                break;
                            }
                        }
                        func_ov003_021ba1a8(delay);
                        cnt++;
                    } while (cnt < scan.mCount);
                }
                if (cnt == scan.mCount) {
                    req->mResultCode = 0xf;
                    ReleaseEssidEntryLists();
                    return -1;
                }
                addr = GetNextAddressInMask(gRequestState.mDestinationAddress, gRequestState.mAddressMask);
                if (func_ov003_021b7df4(addr, gRequestState.mAddressMask, addr) != 0) {
                    SetErrorCode(0xc);
                    req->mResultCode = 0xf;
                    ReleaseEssidEntryLists();
                    return -1;
                }
                gRequestState.mAddressApplied = 1;
                ReleaseEssidEntryLists();
                gSocketDescriptor = func_ov003_021b7cf8(2, 2, 0);
                if (gSocketDescriptor < 0) {
                    req->mResultCode = 0xf;
                    ReleaseEssidEntryLists();
                    return -1;
                }
                if (func_ov003_021b7d00(gSocketDescriptor, 0xffff, 1, &value, 4) < 0) {
                    SetErrorCode(0xb);
                    req->mResultCode = 0xf;
                    ReleaseEssidEntryLists();
                    return -1;
                }
                FillBytes(&info, 0, 8);
                info.mUnk_01 = 2;
                info.mAddress = SwapBytes32(addr);
                info.mPort = func_ov003_021b7c94(0x5790);
                if (func_ov003_021b7cec(gSocketDescriptor, &info, 8) < 0) {
                    req->mResultCode = 0xf;
                    ReleaseEssidEntryLists();
                    return -1;
                }
            }
            if (ReportStateAndSendPacketForMode(mode, &buf, list, gSocketDescriptor) == -1) {
                SetErrorCode(mode + 0x1000);
                req->mResultCode = 0xf;
                ReleaseEssidEntryLists();
                return -1;
            }
            FillBytes(buffer, 0, 0x5f8);
            func_ov003_021b7ba8(&set);
            func_ov003_021b7ba0(gSocketDescriptor, &set);
            wait.mSeconds = timeout / 1000;
            wait.mUnk_04 = timeout % 1000 * 1000;
            if (func_ov003_021b7d1c(gSocketDescriptor + 1, &set, NULL, NULL, &wait) > 0) {
                break;
            }
            attempts++;
            if (attempts > limits.mCount) {
                if (mode == 0) {
                    SetErrorCode(0xf);
                } else if (mode == 1) {
                    SetErrorCode(0x10);
                } else {
                    SetErrorCode(0x11);
                }
                ret = -1;
                goto cleanup;
            }
            func_ov003_021ba1a8(limits.mDelayMs);
        }
        srcLen = 8;
        received = func_ov003_021b7d68(gSocketDescriptor, buffer->mBytes, 0x5dc, 0, &src2, &srcLen);
        buffer->mDescriptor = gSocketDescriptor;
        buffer->mReceivedLength = SwapBytes16(received);
        state = AdvanceStepByKind(mode, buffer, &attempts, list, gSocketDescriptor);
        if (state == 0x64) {
            ret = 0;
            goto cleanup;
        }
        if (state == -1) {
            ret = -1;
            goto cleanup;
        }
        if (mode != state) {
            if (state == 2) {
                if (gSocketDescriptor != -1) {
                    func_ov003_021b7ce4(gSocketDescriptor);
                }
                gSocketDescriptor = -1;
                if (func_ov003_021b7dc8() != 0) {
                    req->mResultCode = 0xf;
                    ReleaseEssidEntryLists();
                    return -1;
                }
                cnt = 0;
                ReportStateChange(4);
                while (1) {
                    if (gScannedEssidList != NULL) {
                        func_ov003_021ba164(gScannedEssidList);
                        gScannedEssidList = NULL;
                    }
                    if (ScanEssidEntries(&gScannedEssidList) == -1) {
                        req->mResultCode = 0xf;
                        ReleaseEssidEntryLists();
                        return -1;
                    }
                    result = CheckSingleEssidAossEntry(gScannedEssidList);
                    if (result == 4) {
                        req->mResultCode = 2;
                        ReleaseEssidEntryLists();
                        return -1;
                    }
                    if (result == 0) {
                        break;
                    }
                    if (cnt >= scan.mCount) {
                        req->mResultCode = 1;
                        ReleaseEssidEntryLists();
                        return -1;
                    }
                    func_ov003_021ba1a8(delay);
                    cnt++;
                }
                gRequestedEssidList = func_ov003_021ba178(0x58);
                if (gRequestedEssidList == NULL) {
                    req->mResultCode = 0xf;
                    ReleaseEssidEntryLists();
                    return -1;
                }
                FillBytes(gRequestedEssidList, 0, 0x58);
                cnt = 0;
                if (scan.mCount > 0) {
                    do {
                        result = RunEssidMelcoRequest(&request, gRequestedEssidList);
                        if (result == -1) {
                            req->mResultCode = 0xf;
                            ReleaseEssidEntryLists();
                            return -1;
                        }
                        if (result == 0) {
                            /* repeated test of result, kept as a placeholder */
                            if (result != 0 || gRequestedEssidList->mCount == 1) {
                                break;
                            }
                        }
                        func_ov003_021ba1a8(delay);
                        cnt++;
                    } while (cnt < scan.mCount);
                }
                if (cnt == scan.mCount) {
                    req->mResultCode = 0xf;
                    ReleaseEssidEntryLists();
                    return -1;
                }
                if (func_ov003_021b7df4(addr, gRequestState.mAddressMask, addr) != 0) {
                    SetErrorCode(0xc);
                    req->mResultCode = 0xf;
                    ReleaseEssidEntryLists();
                    return -1;
                }
                ReleaseEssidEntryLists();
                gSocketDescriptor = func_ov003_021b7cf8(2, 2, 0);
                if (gSocketDescriptor < 0) {
                    req->mResultCode = 0xf;
                    ReleaseEssidEntryLists();
                    return -1;
                }
                if (func_ov003_021b7d00(gSocketDescriptor, 0xffff, 1, &value, 4) < 0) {
                    SetErrorCode(0xb);
                    req->mResultCode = 0xf;
                    ReleaseEssidEntryLists();
                    return -1;
                }
                FillBytes(&info, 0, 8);
                info.mUnk_01 = 2;
                info.mAddress = SwapBytes32(addr);
                info.mPort = func_ov003_021b7c94(0x5790);
                if (func_ov003_021b7cec(gSocketDescriptor, &info, 8) < 0) {
                    req->mResultCode = 0xf;
                    ReleaseEssidEntryLists();
                    return -1;
                }
            }
            mode = state;
            continue;
        }
        mode = state;
        if (attempts > limits.mCount) {
            if (state == 0) {
                SetErrorCode(0xf);
            } else if (state == 1) {
                SetErrorCode(0x10);
            } else {
                SetErrorCode(0x11);
            }
            ret = -1;
            goto cleanup;
        }
        func_ov003_021ba1a8(limits.mDelayMs);
        continue;
    }

cleanup:
    if (gSocketDescriptor != -1) {
        func_ov003_021b7ce4(gSocketDescriptor);
    }
    gSocketDescriptor = -1;
    if (func_ov003_021b7dc8() != 0) {
        req->mResultCode = 0xf;
        ReleaseEssidEntryLists();
        return -1;
    }
    if (ret != 0) {
        switch (GetErrorCode()) {
            case 0xf:
                code = 3;
                break;
            case 0x10:
                code = 4;
                break;
            case 0x11:
                code = 5;
                break;
            case 0x14:
                code = 7;
                break;
            case 0x15:
                code = 8;
                break;
            default:
                code = 0xf;
                break;
        }
        req->mResultCode = code;
        ReleaseEssidEntryLists();
        return -1;
    }
    if (CheckAndCopyValueRecordsToRequest(req) != 0) {
        req->mResultCode = 6;
        ReleaseEssidEntryLists();
        return -1;
    }
    return 0;
}

u32 GetNextAddressInMask(u32 addr, u32 mask) {
    u32 base = addr & mask;
    u32 next = (addr & ~mask) + 1;
    if ((base | next) < (base | ~mask)) {
        return base | next;
    }
    return base | 1;
}

void ReleaseEssidEntryLists(void) {
    if (gRequestedEssidList != NULL) {
        func_ov003_021ba164(gRequestedEssidList);
        gRequestedEssidList = NULL;
    }
    if (gScannedEssidList != NULL) {
        func_ov003_021ba164(gScannedEssidList);
        gScannedEssidList = NULL;
    }
}

void InitRequestState(ValueRecordsRequest *req) {
    FillBytes(gSavedTagBytes, 0, 8);
    gErrorCode = 1;
    FillBytes(&gRequestState, 0, 0x1c);
    gRequestState.mItemBytes = req->mItemBytes;
    gRequestState.mItemLength = req->mItemLength;
    gRequestState.mWantedRecordMask = req->mWantedRecordMask & 0xf;
    gRequestState.mItemType = req->mItemType;
    gRequestState.mFoundRecordMask = 0;
    gRequestState.mDestinationAddress = 0xc0a80b01;
    gRequestState.mAddressApplied = 0;
}

void SetErrorCode(s32 code) {
    gErrorCode = code;
}
