#include "code_02152490.h"
#include "code_0214d018.h"
#include "code_021526bc.h"
#include "code_02152a7c.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_021529e0.h"

#pragma thumb on

void DWC_CreateExchangeToken(const DWCAccUserData *userdata, DWCAccFriendData *token) {
    MI_CpuFill8(token, 0, 12);
    if (DWCi_Acc_IsAuthentic(userdata) != 0) {
        DWCi_Acc_SetGsProfileId(token, userdata->mGsProfileId);
        func_021529e0(token, 3);
    } else {
        *token = userdata->mPseudo;
    }
}

#pragma thumb off
