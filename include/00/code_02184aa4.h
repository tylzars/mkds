#pragma once

#include "types.h"

typedef struct Unk021b0cd4 Unk021b0cd4;

extern Unk021b0cd4 gWiFiVSCourseSelectCallbacks;

void RegisterWiFiVSCourseSelectCallbacks(void);
void func_ov000_02184ac8(void);
void AdvanceWiFiVSCourseSelectState(void);
void func_ov000_02184b4c(void);
void func_ov000_02184b50(void);
void InitWiFiVSCourseSelectState(u32 a);
