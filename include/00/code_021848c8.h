#pragma once

#include "types.h"

typedef struct WiFiStateCallbacks WiFiStateCallbacks;

extern WiFiStateCallbacks gSelectCharacterCallbacks;

void RegisterSelectCharacterCallbacks(void);
void func_ov000_021848ec(void);
void AdvanceWiFiSelectCharacterState(void);
void func_ov000_02184934(void);
void ReleaseWiFiSelectCharacterState(void);
void InitWiFiSelectCharacterState(void *a);
