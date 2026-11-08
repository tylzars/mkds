#include "Main/Unknown/code_02151f88.h"
#include "code_02151868.h"
#include "code_02151fc4.h"

#pragma thumb on

u32 WriteNewWiFiInfoToNvram(u32 work) {
    int result;
    u8 wifiInfo[24];
    result = DWCi_AUTH_GetNewWiFiInfo((DWCWiFiInfo *) wifiInfo);
    if (result == 0) {
        return 0;
    }
    result = DWCi_BM_SetWiFiInfo((DWCWiFiInfo *) wifiInfo, (u8 *) work);
    if (result != 0) {
        return 1;
    }
    return 0;
}

#pragma thumb off
