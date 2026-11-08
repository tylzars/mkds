#include "code_021526bc.h"
#include "Main/Unknown/code_021526c8.h"

#pragma thumb on

BOOL DWCi_Acc_IsAuthentic(const DWCAccUserData *userdata) {
    return IsFriendDataLoginId(&userdata->mAuthentic);
}

#pragma thumb off
