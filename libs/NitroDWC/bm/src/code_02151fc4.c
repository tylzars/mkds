#include "code_02151fc4.h"
#include "code_021510a4.h"
#include "code_021519d4.h"
#include "code_02151868.h"
#include "code_0200f5ac.h"
#include "code_0214d018.h"
#include "code_0214d93c.h"
#include "code_0200fc8c.h"
#include "code_021522a0.h"
#include "Main/Unknown/code_0215228c.h"

#pragma thumb on

// Seconds since 2000-01-01, or -1 for a bad date.
s64 func_02152244(const u32 *date, const u32 *time) {
    s32 day;
    s32 sec;
    day = func_021522a0(date);
    if (day == -1) {
        return -1;
    }
    sec = ComputeSecondsOfDay(time);
    return (s64) sec + (s64) day * 0x15180;
}

u64 DWCi_Util_WiFiId_scrambleUid(u16 rand, u32 mac, u8 vend, u8 mainunit) {
    union {
        u64 v;
        u8 b[8];
    } value;
    u8 copy[8];
    s32 i;
    u8 *src;
    u8 *dst;
    const u8 *order;
    value.v = (((u64) rand & 0xffff) << 27) |
              ((((u64) mac & 0xffffff) << 3) | (((u64) mainunit & 3) | (((u64) vend & 1) << 2)));
    src = value.b;
    for (i = 0; i < 6; i++) {
        *src ^= 0xd6;
        src++;
    }
    i = 0;
    src = value.b;
    for (; i < 5; i++) {
        *src = (data_usa_02161738[(*src >> 4) & 0xf] << 4) | data_usa_02161738[*src & 0xf];
        src++;
    }
    MI_CpuCopy8(value.b, copy, 8);
    i = 0;
    dst = copy;
    order = data_usa_02161730;
    for (; i < 5; i++) {
        value.b[*order] = *dst;
        dst++;
        order++;
    }
    value.b[7] = 0;
    value.b[6] = 0;
    value.b[5] &= 7;
    value.v <<= 1;
    value.b[0] |= (value.b[5] >> 3) & 1;
    src = value.b;
    for (i = 0; i < 6; i++) {
        *src ^= 0x67;
        src++;
    }
    value.b[7] = 0;
    value.b[6] = 0;
    value.b[5] &= 7;
    return value.v;
}

BOOL DWCi_AUTH_GetNewWiFiInfo(DWCWiFiInfo *info) {
    u8 vendor;
    u32 macLow;
    u8 mac[6];
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
    info->mAttestedUserId = 0;
    if (info->mRandomHistory == 0) {
        info->mNotAttestedId = 0;
        while (info->mNotAttestedId == 0) {
            seed = seed * 0x5d588b65 + 0x269ec3;
            while (seed == 0) {
                seed = seed * 0x5d588b65 + 0x269ec3;
            }
            info->mRandomHistory = seed;
            info->mNotAttestedId = DWCi_Util_WiFiId_scrambleUid(info->mRandomHistory, macLow, vendor, 0);
        }
    } else {
        info->mNotAttestedId = 0;
        while (info->mNotAttestedId == 0) {
            info->mRandomHistory++;
            info->mNotAttestedId = DWCi_Util_WiFiId_scrambleUid(info->mRandomHistory, macLow, vendor, 0);
        }
    }
    return 1;
}

#pragma thumb off
