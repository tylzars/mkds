#pragma once

#include "types.h"

typedef struct WiFiStateCallbacks WiFiStateCallbacks;

extern WiFiStateCallbacks gWiFiVSCourseSelectCallbacks;

void RegisterWiFiVSCourseSelectCallbacks(void);
void func_ov000_02184ac8(void);
void AdvanceWiFiVSCourseSelectState(void);
void func_ov000_02184b4c(void);
void ReleaseWiFiVSCourseSelectState(void);
void InitWiFiVSCourseSelectState(u32 a);
