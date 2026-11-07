#pragma once

#include "types.h"
#include "os_thread.h"

#include "00/code_02185954.h"

extern char data_ov000_021b1204[];
extern char data_ov000_021b1348[];
extern char data_ov000_021b135c[];
extern char data_ov000_021b1368[];
extern const char data_ov000_021b1370[];
extern char data_ov000_021b1374[];
extern u32 data_ov000_021b4ca8;

void ReleaseHttp(Http *a);
void DWCi_Http_Thread(void *l);
u32 func_ov000_02187230(Http *a);
void DWC_Http_Abort(Http *p);
void DWC_Http_StartThread(Http *p);
u32 DWC_Http_FinishHeader(Http *p);
s32 DWC_Http_Create(Http *p, const Unk021b4cb4 *q);
