#pragma once

#include "types.h"

// Four callbacks handed over as one block.
typedef struct Unk021a8cd0 {
    /* 00 */ UnkFunc *mUnk_00[4];
} Unk021a8cd0;

#include "01/code_02192000.h"
#include "Main/Unknown/code_0214a000.h"
#include "01/unk_021a9000.h"
#include "01/code_02192e78.h"
#include "01/code_0219e824.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02125ebc.h"
#include "Main/Unknown/code_02125f88.h"
#include "Main/Unknown/code_02126230.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/unk_0217a000.h"
#include "01/code_021956dc.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_02105000.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/unk_02175628.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02036c5c.h"
#include "01/unk_021a8000.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047104.h"

extern const Unk021a8cd0 gOptionEmbremSelectCallbacks;

void RegisterOptionEmbremSelectCallbacks(void);
void func_ov001_0219d600(void);
void AdvanceOptionEmbremSelect(void);
void func_ov001_0219d6ac(void);
void func_ov001_0219d730(void);
void func_ov001_0219d810(void);
void func_ov001_0219d858(void);
void AdvanceOptionEmbremSelectState6(void);
void AdvanceOptionEmbremSelectState5(void);
void AdvanceOptionEmbremSelectState4(void);
void AdvanceOptionEmbremSelectState3(void);
void AdvanceOptionEmbremSelectState2(void);
void AdvanceOptionEmbremSelectState1(void);
void AdvanceOptionEmbremSelectState0(void);
BOOL func_ov001_0219de38(void);
void LocateAndQueueOptionEmbremSelect(void);
void func_ov001_0219df64(void);
void InitOptionEmbremSelect(void *a);

#include "00/code_021832d8.h"
