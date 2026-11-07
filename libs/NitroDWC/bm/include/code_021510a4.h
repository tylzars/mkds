#pragma once

#include "types.h"

// The Wi-Fi ID record.
typedef struct DWCWiFiInfo {
    /* 00 */ u64 mAttestedUserId;
    /* 08 */ u64 mNotAttestedId;
    /* 10 */ u16 mPass;
    /* 12 */ u16 mRandomHistory;
} DWCWiFiInfo;

extern u16 data_usa_02180474;
extern u32 data_usa_02180478;
extern u8 data_usa_021804a0;

u8 *DWCi_BACKUPlConvWifiInfo(const DWCWiFiInfo *info);
u16 Callback_NVRAM(u32 tag, u32 data, u32 err);
BOOL writeDisable(void);
BOOL verify(const u8 *src, u32 address, u32 size, const u8 *work);
void writeNvram(u32 address, u16 size, void *data);
BOOL readNvram(u32 address, u32 size, void *buf);
BOOL NVRAMm_ExecuteCommand(u32 state, u32 addr, u16 size, u8 *srcp);
BOOL DWC_BACKUPlCheckAddress(const u8 *address);
BOOL DWC_BACKUPlCheckIp(const u8 *ip, const u8 *mask);
BOOL DWC_BACKUPlCheckSsid(const u8 *ssid);
void DWCi_BACKUPlConvMaskAddr(u32 mask, u8 *buf);
u8 DWCi_BACKUPlConvMaskCidr(const u8 *mask);
