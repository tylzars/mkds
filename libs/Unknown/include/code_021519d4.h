#pragma once

#include "types.h"

typedef struct DWCWiFiInfo DWCWiFiInfo;

typedef struct DWCAuthWiFiId {
    /* 00 */ u64 mUId;
    /* 08 */ u64 mNotAttestedId;
    /* 10 */ u32 mFlag;
    /* 14 */ u32 mUnk_14;
} DWCAuthWiFiId;

extern const u8 data_usa_0216172c[];

void initPage(u8 *work, u32 page);
s32 init(u8 *work);
BOOL checkAp(const u8 *ap);
s32 DWC_BM_Init(u8 *work);
BOOL DWC_Auth_CheckWiFiIDNeedCreate(void);
void DWC_Auth_GetId(DWCAuthWiFiId *id);
BOOL DWCi_AUTH_RemakeWiFiID(DWCWiFiInfo *info);
BOOL DWCi_AUTH_UpDateWiFiID(DWCWiFiInfo *info, u8 *work);
