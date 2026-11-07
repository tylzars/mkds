#pragma once

#include "types.h"

void SetWiFiSessionOwnPickedCourseId(s32 a);
void SetWiFiSessionOwnKartIndex(s32 a);
void SetWiFiSessionOwnCharacterIndexNone(void);
void SetWiFiSessionOwnCharacterIndex(s32 a);
void ReceiveWiFiSessionMessage(u32 a, void *b, u32 c);
BOOL UpdateWiFiSessionStepTimeout(u32 a);
void PackWiFiSessionIndices(void);
void func_02122728(void);
