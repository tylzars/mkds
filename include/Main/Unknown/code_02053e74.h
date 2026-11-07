#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217a000.h" // Unk0217aa00_15bc

void func_02053e74(void);
void ResetConnectionData(void);
void ResetDataSharing(Unk0217aa00_15bc *a);
void func_02054330(void);
void InitConnectionBuffers(void *a);
void InitConnection(void *a);
s32 func_0205465c(void);
s32 StartDataSharingSync(void);
BOOL FinishDataSharingSync(void);
s32 AdvanceBlockReceive(void);
void func_02054aa0(void);
s32 AdvanceBlockCountRequest(void);
s32 AdvanceConnectionSetup(s32 a, void *b);
