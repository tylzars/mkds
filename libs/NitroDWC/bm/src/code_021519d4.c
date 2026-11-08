#include "code_021519d4.h"
#include "code_021510a4.h"
#include "code_02151868.h"
#include "code_02151fc4.h"
#include "code_020205b0.h"
#include "code_0200f5ac.h"
#include "code_0214cfe4.h"
#include "code_0214d018.h"
#include "code_0214d93c.h"
#include "string.h"
#include "code_02134398.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/code_02151708.h"
#include "Main/Unknown/code_02151718.h"

#pragma thumb on

BOOL DWCi_AUTH_UpDateWiFiID(DWCWiFiInfo *info, u8 *work) {
    DWCWiFiInfo stored;
    DWCi_BM_GetWiFiInfo(&stored);
    info->mAttestedUserId = info->mNotAttestedId;
    info->mNotAttestedId = stored.mNotAttestedId;
    if (DWCi_BM_SetWiFiInfo(info, work) != 0) {
        return 1;
    }
    return 0;
}

// Like DWCi_AUTH_GetNewWiFiInfo, but always picks a new random history.
BOOL DWCi_AUTH_RemakeWiFiID(DWCWiFiInfo *info) {
    u8 vendor;
    u32 macLow;
    u8 mac[6] = {0, 0, 0, 0, 0, 0};
    u32 date[4];
    u32 time[3];
    s64 seconds;
    u32 seed;
    DWCi_BM_GetWiFiInfo(info);
    RTC_Init();
    if (RTC_GetDate((RTCDate *) date) != 0) {
        return 0;
    }
    if (RTC_GetTime((RTCTime *) time) != 0) {
        return 0;
    }
    seconds = func_02152244(date, time);
    seed = seconds;
    if (seconds < 0) {
        return 0;
    }
    if (OS_IsTickAvailable() != 0) {
        seed += (u32) OS_GetTick;
    }
    OS_GetMacAddress(mac);
    vendor = (mac[0] << 16 | mac[1] << 8 | mac[2]) != 0x9bf;
    macLow = mac[5];
    macLow |= (mac[3] << 16 | mac[4] << 8);
    seed = seed * 0x5d588b65 + 0x269ec3;
    info->mPass = ((seed >> 16) * 1000) >> 16;
    info->mNotAttestedId = 0;
    while (info->mNotAttestedId == 0) {
        seed = seed * 0x5d588b65 + 0x269ec3;
        while (seed == 0 || info->mRandomHistory == (u16) seed) {
            seed = seed * 0x5d588b65 + 0x269ec3;
        }
        info->mRandomHistory = seed;
        info->mNotAttestedId = DWCi_Util_WiFiId_scrambleUid(info->mRandomHistory, macLow, vendor, 0);
    }
    return 1;
}

void DWC_Auth_GetId(DWCAuthWiFiId *id) {
    DWCWiFiInfo info;
    DWCi_BM_GetWiFiInfo(&info);
    id->mUId = info.mAttestedUserId;
    id->mNotAttestedId = info.mNotAttestedId;
    if (info.mAttestedUserId == 0) {
        id->mFlag = 0;
    } else {
        id->mFlag = 1;
    }
}

BOOL DWC_Auth_CheckWiFiIDNeedCreate(void) {
    DWCWiFiInfo info;
    DWCi_BM_GetWiFiInfo(&info);
    if (info.mNotAttestedId == 0 && info.mAttestedUserId == 0) {
        return 1;
    }
    return 0;
}

// Checks and repairs the NVRAM backup pages; returns 0 or a negative error code.
s32 DWC_BM_Init(u8 *work) {
    u32 valid[4];
    s32 i;
    u8 *page;
    u8 *apPage;
    u32 *validEntry;
    u32 dropped;
    u32 *validCheck;
    s32 j;
    u32 crc;
    if (ReadNvramEntriesOffset((u16 *) work) == 0) {
        return -10001;
    }
    Crc16InitTable(OFFSET_PTR(u16, work, 0x500), 0xa001);
    if (ReadNvramEntries(work) == 0) {
        return -10001;
    }
    MI_CpuFill8(valid, 0, 0x10);
    i = 0;
    page = work;
    apPage = work;
    validEntry = valid;
    do {
        crc = Crc16(OFFSET_PTR(u16, work, 0x500), page, 0xfe);
        if (crc == *OFFSET_PTR(u16, page, 0xfe)) {
            if (checkAp(apPage) != 0) {
                *validEntry = 1;
            }
        }
        page += 0x100;
        apPage += 0x100;
        validEntry++;
        i++;
    } while (i < 3);
    crc = Crc16(OFFSET_PTR(u16, work, 0x500), work + 0x300, 0xfe);
    if (crc == *OFFSET_PTR(u16, work, 0x3fe)) {
        valid[3] = 1;
    }
    if (valid[0] != 0 && valid[1] != 0 && valid[2] != 0 && valid[3] != 0) {
        WritePackedWiFiInfo((u32) (work + 0xf0));
        return 0;
    }
    if (valid[0] == 0 && valid[1] == 0 && valid[2] == 0 && valid[3] == 0) {
        init(work);
        if (WriteNvramEntriesWithCrc16((int) work) != 0) {
            return 0;
        }
        return -10000;
    }
    if ((valid[0] == 0 || valid[1] == 0) && (valid[2] == 0 || valid[3] == 0)) {
        init(work);
        if (WriteNvramEntriesWithCrc16((int) work) != 0) {
            return 0;
        }
        return -10000;
    }
    if (valid[0] == 0 && valid[1] == 0) {
        init(work);
        if (WriteNvramEntriesWithCrc16((int) work) != 0) {
            return -10003;
        }
        return -10000;
    }
    if (valid[0] == 0) {
        initPage(work, 0);
        MI_CpuCopy8(work + 0x1f0, work + 0xf0, 0xd);
        work[0xef] = work[0x1ef];
    } else if (valid[1] == 0) {
        initPage(work, 1);
        MI_CpuCopy8(work + 0xf0, work + 0x1f0, 0xd);
        work[0x1ef] = work[0xef];
    }
    WritePackedWiFiInfo((u32) (work + 0xf0));
    if (valid[2] == 0) {
        initPage(work, 2);
    }
    if (valid[3] == 0) {
        vu16 zero = 0;
        MIi_CpuClear16(zero, work + 0x300, 0x100);
    }
    dropped = 0;
    j = 0;
    validCheck = valid;
    for (; j < 3; validCheck++, j++) {
        if (*validCheck == 0) {
            crc = 1 << j;
            if ((work[0xef] & crc) != 0) {
                work[0xef] &= ~crc;
                dropped = 1;
            }
        }
    }
    if (WriteNvramEntriesWithCrc16((int) work) == 0) {
        return -10000;
    }
    if (dropped != 0) {
        return -10002;
    }
    return 0;
}

BOOL checkAp(const u8 *ap) {
    u8 netmask[8];
    u8 setType;
    setType = ap[0xe7];
    if (setType == 0xff) {
        return 1;
    }
    if (setType > 2) {
        return 0;
    }
    if (DWC_BACKUPlCheckSsid(ap + 0x40) == 0) {
        return 0;
    }
    if (memcmp(ap + 0xc0, data_usa_0216172c, 4) != 0) {
        if (DWC_BACKUPlCheckAddress(ap + 0xc4) == 0) {
            return 0;
        }
        if (ap[0xd0] > 0x20) {
            return 0;
        }
        DWCi_BACKUPlConvMaskAddr(ap[0xd0], netmask);
        if (DWC_BACKUPlCheckIp(ap + 0xc0, netmask) == 0) {
            return 0;
        }
    }
    if (memcmp(ap + 0xc8, data_usa_0216172c, 4) != 0) {
        if (DWC_BACKUPlCheckAddress(ap + 0xc8) == 0 && DWC_BACKUPlCheckAddress(ap + 0xcc) == 0) {
            return 0;
        }
    }
    return 1;
}

s32 init(u8 *work) {
    vu16 zero;
    s32 i;
    u8 *page;
    u8 *wifiPage;
    DWCWiFiInfo info;
    u8 *packed;
    zero = 0;
    MIi_CpuClear16(zero, work, 0x400);
    i = 0;
    page = work;
    for (; i < 3; i++) {
        page[0xe7] = 0xff;
        page += 0x100;
    }
    DWCi_AUTH_GetNewWiFiInfo(&info);
    packed = DWCi_BACKUPlConvWifiInfo(&info);
    wifiPage = work;
    for (i = 0; i < 2; i++) {
        MI_CpuCopy8(packed, wifiPage + 0xf0, 0xe);
        wifiPage += 0x100;
    }
    return 0;
}

void initPage(u8 *work, u32 page) {
    vu16 zero;
    u32 offset;
    zero = 0;
    offset = page << 8;
    MIi_CpuClear16(zero, work + offset, 0x100);
    (work + offset)[0xe7] = 0xff;
}

#pragma thumb off
