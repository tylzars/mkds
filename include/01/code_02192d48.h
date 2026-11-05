#pragma once

#include "types.h"
#include "ITCM/code_01ff9000.h"

typedef struct StopSignObject {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ u8 mUnk_10[0xc];
    /* 1c */ u8 mUnk_1c[0xc];
    /* 28 */ u8 mUnk_28[0x24];
    /* 4c */ s32 mUnk_4c;
    /* 50 */ s32 mUnk_50;
    /* 54 */ s32 mUnk_54;
} StopSignObject;

#include "01/code_021928c8.h"
#include "01/code_0218f9d4.h"
#include "Main/Unknown/code_0209b000.h"
#include "01/code_02188950.h"
#include "01/code_0219b250.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020d2450.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"

void *func_ov001_02192d48(void);
void func_ov001_02192d60(void);
void DrawStopSign(void *a, StopSignObject *b);
void LoadStopSign(Unk0219b478 *a);
void InitStopSign(Unk02188950 *a); /* object is MapObject-sized; Unk02188950 is only the prefix view */

#include "01/code_0219b540.h"
