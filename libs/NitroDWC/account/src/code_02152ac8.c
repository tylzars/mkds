#include "code_02152ac8.h"
#include "code_021519d4.h"
#include "code_02152490.h"
#include "Main/Unknown/code_02000b44.h"
#include "Main/Unknown/code_02151f88.h"
#include "Main/Unknown/code_02152000.h"

#pragma thumb on

u32 DWC_Init(u8 *work) {
    u32 created;
    s32 result;

    created = 0;
    func_02000b44(0x2000b88);
    result = DWC_BM_Init(work);
    if (DWC_Auth_CheckWiFiIDNeedCreate() != 0) {
        WriteNewWiFiInfoToNvram((u32) work);
        created = 1;
    }
    if (result < 0) {
        if (created != 0) {
            return 2;
        }
        return 3;
    }
    if (created != 0) {
        return 1;
    }
    return 0;
}

BOOL DWCi_Acc_SetMaskBits(u32 *ptr, u32 data, u32 shift, u32 mask) {
    if ((data & ~mask) != 0) {
        return 0;
    }
    *ptr = *ptr & ~(mask << shift) | data << shift;
    return 1;
}

u64 DWCi_Acc_GetUserId(const DWCAccFriendData *userdata) {
    return (u64) (userdata->mUnk_00 & 0x7ff) << 32 | userdata->mUnk_04;
}

#pragma thumb off
