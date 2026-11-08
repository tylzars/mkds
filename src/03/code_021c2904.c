#include "03/code_021c2904.h"
#include "03/unk_021d8000.h"

#include "03/unk_021da000.h"
#include "03/code_021d1c18.h"
#include "03/code_021cd2e0.h"
#include "03/code_021bb03c.h"
#include "03/code_021bf698.h"
#include "03/code_021bf810.h"
#include "03/code_021c209c.h"
#include "03/code_021c2530.h"
#include "03/code_021c28f0.h"
#include "03/code_021c28f8.h"
#include "03/code_021bf4dc.h"
#include "03/code_021d1fd0.h"
#include "03/unk_021d5000.h"
#include "03/code_021bf410.h"
#include "03/code_021d1f70.h"
#include "03/code_021d27d8.h"
#include "os_thread.h"
#include "code_0200fc8c.h"

void func_ov003_021c2a28(void) {
    if (IsBlendBrightnessFadeSlotBusy(1) == 0 && IsBlendBrightnessFadeSlotBusy(0) == 0) {
        FreeNceFile(1);
        FreeNceFile(0);
        ReleaseHlScr();
        ReleaseSelectionObjects();
        ReleaseMessages(gMessages);
        FreeMessagesPool();
        func_ov003_021cdb80();
        func_ov003_021c209c();
    }
}

void StartExchangeWithStatusRecord(void) {
    gExchangeStatusRecord = AllocZeroedExpHeapBlock(0xc, -4);
    if (StartExchange(0xf, 0x40, StoreExchangeStatus, func_ov003_021c28f8, func_ov003_021c28f0, 0x800) != 1) {
        OS_Terminate();
    }
    OS_Sleep(0xa);
}

void StopExchangeWithStatusRecord(void) {
    if (StopExchange() != 1) {
        OS_Terminate();
    }
    FreeExpHeapBlockAndClearPointer(&gExchangeStatusRecord);
}

u32 func_ov003_021c2938(void) {
    ExchangeResult exchangeResult;
    switch (gExchangeStatusRecord->mStatus) {
        case 0:
        case 1:
        case 3:
        case 5:
            return 0;
        case 2:
            return 1;
        case 4:
            return 2;
        case 6:
            if (CopyExchangeResult(&exchangeResult) != 1) {
                OS_Terminate();
            }
            if (exchangeResult.mKind >= 0 && exchangeResult.mKind <= 3 && exchangeResult.mUnk_24 == 1) {
                return 3;
            }
            return 5;
        case 7:
            return 4;
    }
}

void func_ov003_021c2918(void) {
    ExchangeResult exchangeResult;
    if (CopyExchangeResult(&exchangeResult) != 1) {
        OS_Terminate();
    }
    func_ov003_021cd5e0((const Unk021cd5e0_arg *) &exchangeResult);
}

void StoreExchangeStatus(const ExchangeStatus *status) {
    *gExchangeStatusRecord = *status;
}
