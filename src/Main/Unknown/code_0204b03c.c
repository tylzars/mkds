#include "Main/Unknown/code_0204b03c.h"
#include "Main/Unknown/code_0202f14c.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02059bc0.h"
#include "Main/Unknown/unk_02154000.h"
#include "code_0200cd1c.h"
#include "code_0200f5ac.h"
#include "code_0214578c.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_0204984c.h"

#pragma thumb on

void UnlockBackup(void) {
    s32 lockId;
    lockId = gBackupAccess->mLockId;
    if (lockId != -3) {
        CARD_UnlockBackup(lockId);
        OS_ReleaseLockID(gBackupAccess->mLockId);
        gBackupAccess->mLockId = -3;
    }
}

BOOL TryLockBackup(void) {
    s32 lockId;
    gBackupAccess->mLockId = OS_GetLockID();
    lockId = gBackupAccess->mLockId;
    if (lockId == -3) {
        return 0;
    }
    CARD_LockBackup(lockId);
    return 1;
}

void func_0204b344(s32 errorCode) {
    BOOL f;
    f = TRUE;
    switch (gBackupAccess->mUnk_00) {
        case 1:
        case 2:
            f = FALSE;
    }
    gBackupAccess->mUnk_00 = 4;
    gBackupAccess->mErrorCode = (void *) errorCode;
    switch ((s32) gBackupAccess->mErrorCode) {
        case 0:
            break;
        case 1:
        case 2:
            if (f != FALSE) {
                func_02049980(1);
            } else {
                func_02049980(2);
            }
            break;
        case 3:
        case 4:
            break;
    }
}

u16 ComputeBytesCrc(u8 *cursor, u32 byteCount) {
    u16 crc;
    u16 byteIndex;
    u16 unused;
    u8 byte;
    s32 bitIndex;
    byteIndex = 0;
    crc = 0;
    if (byteIndex < byteCount) {
        do {
            byte = *cursor;
            for (bitIndex = 0; bitIndex < 8; bitIndex++) {
                if (crc & 0x8000) {
                    crc <<= 1;
                    crc ^= gCrcXorValue;
                } else {
                    crc <<= 1;
                }
                if (byte & 0x80) {
                    crc ^= 1;
                }
                byte = byte << 1;
            }
            cursor++;
            byteIndex++;
        } while (byteIndex < byteCount);
    }
    return crc;
}

void WriteBlockTail(u8 *bytes, u32 byteCount, u32 skipTickBytes) {
    u8 *tail;
    u16 crc;
    tail = bytes + byteCount - 4;
    if (skipTickBytes == 0) {
        tail[0] = 0;
        tail[1] = 0;
    }
    tail[2] = 0;
    tail[3] = 0;
    crc = ComputeBytesCrc(bytes, byteCount);
    if (skipTickBytes == 0) {
        tail[0] = (OS_GetTick() >> 16) & 0xff;
        tail[1] = (OS_GetTick() >> 32) & 0xff;
    }
    tail[2] = crc >> 8;
    tail[3] = crc;
}

BOOL ClearTickBytesAndCheckBlockCrc(u8 *bytes, u32 byteCount, u32 skipTickBytes) {
    u8 *tail;
    tail = bytes + byteCount - 4;
    if (skipTickBytes == 0) {
        tail[0] = 0;
        tail[1] = 0;
    }
    if (ComputeBytesCrc(bytes, byteCount) == 0) {
        return 1;
    }
    return 0;
}

s32 FindBackupXorIndex(u32 value, u32 expected) {
    u16 index;
    s32 foundIndex;
    index = 0;
    foundIndex = -1;
    for (; index < 0x1d; index++) {
        if (expected == (value ^ (data_usa_02154694[index] +
                                  (data_usa_02154648[0] + (data_usa_021545d8[0] + data_usa_02154604[0]))))) {
            foundIndex = index;
            break;
        }
    }
    return foundIndex;
}

void XorBackupWordsAtTickIndex(u32 *cursor, u32 byteCount) {
    u16 i;
    u16 j;
    u16 k;
    u16 l;
    u32 *end;
    u32 tableSum;
    j = 0;
    l = 0;
    k = 0;
    i = (OS_GetTick() >> 16) % 0x1d;
    tableSum = data_usa_02154694[i] + (data_usa_02154648[0] + (data_usa_021545d8[0] + data_usa_02154604[0]));
    i = FindBackupXorIndex(tableSum ^ *cursor, *cursor);
    end = OFFSET_PTR(u32, cursor, byteCount);
    do {
        *cursor ^= data_usa_02154694[i] + (data_usa_02154648[j] + (data_usa_021545d8[k] + data_usa_02154604[l]));
        cursor++;
        k++;
        if (k >= 0xb) {
            k = 0;
            l++;
            if (l >= 0x11) {
                l = 0;
                j++;
                if (j >= 0x13) {
                    j = 0;
                    i++;
                    if (i >= 0x1d) {
                        i = 0;
                    }
                }
            }
        }
    } while (cursor < end);
}

BOOL TryXorBackupWordsAtFoundIndex(u32 *cursor, u32 byteCount, u32 expectedFirstWord) {
    u16 i;
    u16 j;
    u16 k;
    u16 l;
    s32 foundIndex;
    u32 *end;
    j = 0;
    l = 0;
    k = 0;
    foundIndex = FindBackupXorIndex(*cursor, expectedFirstWord);
    if (foundIndex == -1) {
        return 0;
    }
    i = foundIndex;
    end = OFFSET_PTR(u32, cursor, byteCount);
    do {
        *cursor ^= data_usa_02154694[i] + (data_usa_02154648[j] + (data_usa_021545d8[k] + data_usa_02154604[l]));
        cursor++;
        k++;
        if (k >= 0xb) {
            k = 0;
            l++;
            if (l >= 0x11) {
                l = 0;
                j++;
                if (j >= 0x13) {
                    j = 0;
                    i++;
                    if (i >= 0x1d) {
                        i = 0;
                    }
                }
            }
        }
    } while (cursor < end);
    return 1;
}

#pragma thumb off

void InitWLMenuSceneCallback(void) {
    if (data_021759d0->mUnk_20 == 3) {
        ReleaseCurrentOverlay();
        StartLoadOverlay(0);
        FinishOverlayLoad();
    }
    InitWLMenuScene(GetHeap(GetCurrentHeapCall()));
}
