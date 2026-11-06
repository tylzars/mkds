#pragma once

#include "types.h"
#include "03/types_021d299c.h"

typedef struct Unk021d299c Unk021d299c;

// Table of bytes func_ov003_021c81b8 reads.
typedef struct Unk021d73d0 {
    /* 00 */ u8 mUnk_00[0xe];
} Unk021d73d0;

extern u8 data_ov003_021d6430[];
extern u8 data_ov003_021d6460[];
extern Unk021d299c gJb3ListFixedRects[];
extern Unk021d299c data_ov003_021d64b4[];
extern u8 gJb3ListTimerIds[];
extern Unk021d73d0 data_ov003_021d73d0;

void SetJb3ListMode(u8 a);
void func_ov003_021c7d3c(void);
void func_ov003_021c7d58(void);
u32 func_ov003_021c7d8c(void);
void StartJb3ListIdTimer(void);
void AdvanceJb3ListIdTimers(void);
void func_ov003_021c7ec4(void);
void MoveJb3ListSelection(s32 d);
void SetJb3ListSelectedId(u32 a);
// Declared here until the code that defines them is decompiled.
void SetJb3ListSelectedIdFromRow(void);
void func_ov003_021c81b8(void);
void WriteJb3ListBgOffset(void);
void AdvanceJb3ListScrollYIncrease(u32 b);
void AdvanceJb3ListScrollYDecrease(u32 b);
int GetJb3ListEntryIndexOfRow(int a);
int GetJb3ListRowOfEntryIndex(int a);
u32 GetJb3ListHitId(void);
void RefreshJb3ListRowPositions(void);
void PrintJb3ListEntryBytes(const u8 *b, int c);
void PrintJb3ListEntryString(const u8 *g, int h);
void SetupJb3ListCell(int d, int e, int f);
u32 IsJb3ListIdEnabled(u32 a);
void SetupJb3ListEntryCells(u32 a, int b);
void PrintJb3ListEntryText(u32 a, int b);
void RefreshJb3List(void);
void func_ov003_021c8c14(void);
void func_ov003_021c8e48(void);
void func_ov003_021c8e80(void);
void UpdateJb3ListScrollInput(void);
void func_ov003_021c9058(u32 a);
void func_ov003_021c9084(u32 param_1);
void func_ov003_021c90dc(u32 param_1);
u32 UpdateJb3ListHit(void);
void UpdateJb3ListInput(void);
void UpdateJb3List(void);
void func_ov003_021c9464(void);
void func_ov003_021c948c(void);
void func_ov003_021c94c8(void);
void LoadJb3ListFilesAndSetBgCnt(void);
void CreateJb3List(void);
