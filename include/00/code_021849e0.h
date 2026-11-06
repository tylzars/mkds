#pragma once

#include "types.h"

typedef struct WiFiStateCallbacks WiFiStateCallbacks;

extern WiFiStateCallbacks gSelectKartCallbacks;

void RegisterSelectKartCallbacks(void);
void func_ov000_02184a04(void);
void AdvanceWiFiSelectKartState(void);
void func_ov000_02184a50(void);
void ReleaseWiFiSelectKartState(void);
void InitWiFiSelectKartState(void *a);
