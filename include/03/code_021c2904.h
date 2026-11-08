#pragma once

#include "types.h"

typedef struct ExchangeStatus {
    /* 00 */ u32 mStatus;
    /* 04 */ u32 mTimeoutMillisecondsRemaining;
    /* 08 */ u32 mResultCode;
} ExchangeStatus;

extern ExchangeStatus *gExchangeStatusRecord;

void StoreExchangeStatus(const ExchangeStatus *status);
void func_ov003_021c2918(void);
u32 func_ov003_021c2938(void);
void StopExchangeWithStatusRecord(void);
void StartExchangeWithStatusRecord(void);
void func_ov003_021c2a28(void);
