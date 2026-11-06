#pragma once

#include "types.h"
#include "Main/Unknown/code_02008000.h"
#include "Main/Unknown/code_0200b000.h"
#include "Main/Unknown/code_020091fc.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/code_0200b6e8.h"
#include "Main/Unknown/code_0200c000.h"
#include "Main/Unknown/code_0200c0d8.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_02142eac.h"

void QueueStateMessage(void);
void ReceivePortMessage(Unk021425e8 *a);
void MPLinkCallback(s32 a, Unk021425e8 *b);
u32 StartConnectToEntry(u32 entryIndex);
void ScanConnectEndScanCallback(Unk021425e8 *a);
