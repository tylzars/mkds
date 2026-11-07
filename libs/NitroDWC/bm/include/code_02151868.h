#pragma once

#include "types.h"

typedef struct DWCWiFiInfo DWCWiFiInfo;

void DWCi_BM_GetWiFiInfo(DWCWiFiInfo *info);
BOOL DWCi_BM_SetWiFiInfo(const DWCWiFiInfo *info, u8 *work);
