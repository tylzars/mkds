#pragma once

#include "types.h"

void SetWiFiSessionOwnPickedCourseId(s32 pickedCourseId);
void SetWiFiSessionOwnKartIndex(s32 kartIndex);
void SetWiFiSessionOwnCharacterIndexNone(void);
void SetWiFiSessionOwnCharacterIndex(s32 characterIndex);
void ReceiveWiFiSessionMessage(u32 fromIndex, void *buffer, u32 size);
BOOL UpdateWiFiSessionStepTimeout(u32 limit);
void PackWiFiSessionIndices(void);
void func_02122728(void);
