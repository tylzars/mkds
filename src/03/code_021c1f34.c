#include "03/code_021c1f34.h"
#include "03/code_021cd000.h"

#include "03/code_021b94b8.h"
#include "03/code_021cd2e0.h"
#include "03/unk_021da000.h"
#include "03/code_021d27d8.h"
#include "03/code_021c1f20.h"
#include "03/code_021c1f28.h"
#include "03/unk_021d6000.h"
#include "code_0200fc8c.h"
#include "code_0214cfe4.h"
#include "code_0214d018.h"

void func_ov003_021c1fc8(void) {
    Unk021c1fc8 requestItem;
    ValueRecordsRequest *request;
    gValueRecordsRequest = AllocZeroedExpHeapBlock(0x26c, 4);
    gValueRecordsRequestSucceeded[0] = 0;
    requestItem.mUnk_00 = 0;
    MIi_CpuClear16(requestItem.mUnk_00, &requestItem.mItemType, 0x104);
    requestItem.mItemType = 0x50;
    requestItem.mItemLength = 0xc;
    MI_CpuCopy8(gNintendoDsItemBytes, requestItem.mItemBytes, 0xc);
    gValueRecordsRequest->mWantedRecordMask = 3;
    request = gValueRecordsRequest;
    *(Unk021c1fc8_02 *) &request->mItemType = *(Unk021c1fc8_02 *) &requestItem.mItemType;
    request->mScanRetryLimit = 1;
    gValueRecordsRequest->mScanRetryDelayMs = -1;
    gValueRecordsRequest->mSendAttemptLimit = 1;
    gValueRecordsRequest->mSendAttemptDelayMs = -1;
    gValueRecordsRequest->mReceiveTimeoutMs = -1;
    OS_GetMacAddress(gValueRecordsRequest->mMacAddress);
    if (func_ov003_021ba61c((void *(*) (u32)) func_ov003_021c1f28, func_ov003_021c1f20) != 0) {
        OS_Terminate();
    }
}

void func_ov003_021c1f84(int succeeded) {
    func_ov003_021ba560();
    if (((succeeded != 0) && (gValueRecordsRequest->mResultCode == 0)) &&
        ((*(u8 *) &gValueRecordsRequestSucceeded) == 1)) {
        func_ov003_021cd4e8((s32) &gValueRecordsRequest->mUnk_117);
    }
    FreeExpHeapBlockAndClearPointer(&gValueRecordsRequest);
}

u32 func_ov003_021c1f34(void) {
    u8 resultCode;
    if (func_ov003_021ba05c(gValueRecordsRequest) == 0) {
        gValueRecordsRequestSucceeded[0] = 1;
        return 1;
    }
    resultCode = gValueRecordsRequest->mResultCode;
    if (resultCode == 1 || (u8) (resultCode + 253) <= 2) {
        return 0;
    }
    return 2;
}
