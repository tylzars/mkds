#pragma once

#include "types.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/unk_0217a000.h"
#include "00/code_02182fdc.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_02125da0.h"
#include "01/code_02198854.h"
#include "Main/Unknown/code_021258f0.h"
#include "Main/Unknown/code_02125f88.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02126000.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/unk_02175000.h"
#include "03/code_021b94b8.h"

// Object behind data_ov001_021a9be4.
typedef struct Unk021a9be4 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ s16 mUnk_0c;
    /* 0e */ s16 mUnk_0e;
    /* 10 */ void *mUnk_10;
    /* 14 */ void *mUnk_14;
} Unk021a9be4;

extern Unk021a9be4 *data_ov001_021a9be4;

int func_ov001_0219853c(void);
void func_ov001_0219854c(void);
void func_ov001_02198554(void);
void func_ov001_021985b0(void);
void func_ov001_02198624(void);
void func_ov001_021986e8(void);
void func_ov001_02198768(void);
void func_ov001_021987bc(void);
void func_ov001_021987d4(void *heap, s16 param_2);
