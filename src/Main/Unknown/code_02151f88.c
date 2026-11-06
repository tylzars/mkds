#include "Main/Unknown/code_02151f88.h"
#include "code_02151868.h"
#include "code_02151fc4.h"

#pragma thumb on

u32 func_02151f88(u32 a) {
    int v1;
    u8 v2[24];
    v1 = DWCi_AUTH_GetNewWiFiInfo((DWCWiFiInfo *) v2);
    if (v1 == 0) {
        return 0;
    }
    v1 = DWCi_BM_SetWiFiInfo((DWCWiFiInfo *) v2, (u8 *) a);
    if (v1 != 0) {
        return 1;
    }
    return 0;
}

#pragma thumb off
