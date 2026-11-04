#pragma once

#include "types.h"

typedef struct SelectBattleStageNscrRect {
    /* 00 */ u8 mFirstColumn;
    /* 01 */ u8 mLastColumn;
    /* 02 */ u8 mFirstRow;
    /* 03 */ u8 mLastRow;
} SelectBattleStageNscrRect;

extern const u8 gSelectBattleStageSTableIndices[6][3];

#include "00/code_02181f98.h"
#include "01/code_021956dc.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02105000.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_02127000.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_0212775c.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_02175628.h"

extern const u8 data_ov001_021a6bc4[];
extern const u8 data_ov001_021a6bc8[];
extern const u8 gSelectBattleStageMNscrCopyDestination[];
extern const u8 data_ov001_021a6bd0[];
extern const u8 data_ov001_021a6bd4[];
extern const s8 data_ov001_021a6bd8[];
extern const u8 gSelectBattleStageMNscrIndices[];
extern const u8 data_ov001_021a6be8[6];
extern const SelectBattleStageNscrRect gSelectBattleStageNscrRects[];

void func_ov001_0219c784(void);
s32 AdvanceSelectBattleStage(void);
void func_ov001_0219c8c8(void);
void func_ov001_0219c8ec(void);
void func_ov001_0219c950(void);
void func_ov001_0219ca2c(void);
void func_ov001_0219ca94(void);
void func_ov001_0219caf4(void);
void func_ov001_0219cba0(void);
void func_ov001_0219cdb4(void);
void func_ov001_0219cdd4(void);
void func_ov001_0219cec4(void);
void func_ov001_0219cf60(void);
void LocateAndQueueSelectBattleStage(void);
void ReleaseSelectBattleStage(void);
void InitSelectBattleStage(void *c, s32 d, void *e, void *f);

#include "00/code_021832d8.h"
