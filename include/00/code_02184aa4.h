#pragma once

#include "types.h"
#include "00/code_02180608.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_0202a820.h"

extern Unk021b0cd4 gWiFiVSCourseSelectCallbacks;

void RegisterWiFiVSCourseSelectCallbacks(void);
void func_ov000_02184ac8(void);
void AdvanceWiFiVSCourseSelectState(void);
void func_ov000_02184b4c(void);
void func_ov000_02184b50(void);
void InitWiFiVSCourseSelectState(u32 a);
