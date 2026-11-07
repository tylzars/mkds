#pragma once

#include "types.h"

typedef struct Unk0217aa14_104_68 Unk0217aa14_104_68;

struct Unk021000d0;

void UpdateResultScene(u32 arg0);
void func_02059bcc(void);
void ReleaseResultScene(void);
void InitResultScene(void);
u32 IsInOverlayRange(struct Unk021000d0 *address);
void ReleaseCurrentOverlay(void);
s32 TryFinishOverlayLoad(void);
void FreeOverlayExpHeap(void);
void CreateOverlayExpHeap(void);
void FinishOverlayLoad(void);
void StartLoadOverlay(s32 overlay);
void ResetCurrentOverlay(void);
void CreateOverlayFrmHeap(void);
void InitOverlayTable(void *heap);
s32 func_0205a2ac(s32 a);
s32 func_0205a310(s32 a);
void func_0205a350(void);
void func_0205a4b0(Unk0217aa14_104_68 *a, s32 b);
