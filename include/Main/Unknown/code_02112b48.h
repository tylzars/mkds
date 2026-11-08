#pragma once

#include "types.h"

void AdvanceRecordVSIndexChange(void);
void RequestRecordVSState0(void);
void RequestRecordVSState1(void);
void RequestRecordVSState2AndRefreshPage(void);
void RequestRecordVSState3(void);
void RequestRecordVSState4(void);
void RequestRecordVSState5(void);
void RequestRecordVSState6AndChangePage(void);
void RequestRecordVSState7(void);
void RequestRecordVSState8(void);
void RequestRecordVSState9(void);
void RequestRecordVSState10(void);
void RequestRecordVSState11AndRefreshPage(void);
void InitRecordVS(void *heap);
void ReleaseRecordVS(void);
