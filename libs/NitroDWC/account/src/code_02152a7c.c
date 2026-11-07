#include "code_02152a7c.h"
#include "code_02152490.h"
#include "code_02152ac8.h"

#pragma thumb on

void DWCi_Acc_SetUserId(DWCAccFriendData *loginid, u32 useridLo, u32 useridHi) {
    enum { K0 } shift = K0;
    DWCi_Acc_SetMaskBits(&loginid->mUnk_00, useridHi, shift, 0x7ff);
    loginid->mUnk_04 = useridLo;
}

void DWCi_Acc_SetPlayerId(DWCAccFriendData *loginid, u32 playerid) {
    loginid->mUnk_08 = playerid;
}

void DWCi_Acc_SetFriendKey(DWCAccFriendData *data, u32 friendkeyLo, u32 friendkeyHi) {
    data->mUnk_04 = friendkeyLo;
    data->mUnk_08 = friendkeyHi;
}

void DWCi_Acc_SetGsProfileId(DWCAccFriendData *data, u32 gsProfileId) {
    data->mUnk_04 = gsProfileId;
}

#pragma thumb off
