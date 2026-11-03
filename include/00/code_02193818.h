#pragma once

#include "types.h"

#include "00/code_0218f960.h"
#include "00/code_021947e4.h"
#include "00/code_02196914.h"
#include "00/code_021965a0.h"
#include "00/code_021a3690.h"
#include "00/code_02196590.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "code_02135014.h"
#include "code_02139f70.h"
#include "code_02134d30.h"
#include "code_0213a460.h"
#include "00/code_021919ac.h"
#include "00/code_02193818.h"
#include "00/code_021948f8.h"
#include "00/code_0218e0fc.h"
#include "00/code_021967b4.h"
#include "00/code_02191200.h"
#include "00/code_02196240.h"
#include "00/code_02193634.h"
#include "00/code_02190ba0.h"
#include "00/code_02192d64.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/code_0218dc44.h"
#include "00/code_0218e368.h"
#include "00/code_02196000.h"
#include "00/code_02190000.h"
#include "00/code_021906e4.h"
#include "00/code_0218db48.h"
#include "00/code_0218e2dc.h"
#include "00/code_0218e49c.h"

// Payload at 0x04 of a Unk021937c0Node whose 0x00 is 3.
typedef struct Unk02193858 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ u8 mUnk_0c[0xc];
    /* 18 */ void *mUnk_18;
} Unk02193858;

// Buffers made by func_ov000_02193954, one for each request type; the first word is taken from the request.
typedef struct Unk02193954_0 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u8 mUnk_08[0x18];
} Unk02193954_0;

typedef struct Unk02193954_1 {
    /* 0 */ s32 mUnk_00;
    /* 4 */ u8 mUnk_04[4];
} Unk02193954_1;

typedef struct Unk02193954_3 {
    /* 0 */ s32 mUnk_00;
    /* 4 */ u8 mUnk_04[8];
    /* c */ u32 mUnk_0c;
} Unk02193954_3;

typedef struct Unk02193954_4 {
    /* 0 */ s32 mUnk_00;
} Unk02193954_4;

// Three words printed by func_ov000_02193c20.
typedef struct Unk02193c20 {
    /* 0 */ u32 mUnk_00;
    /* 4 */ u32 mUnk_04;
    /* 8 */ u32 mUnk_08;
} Unk02193c20;

// Output buffer description built by func_ov000_02193c74.
typedef struct Unk02193c74 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
} Unk02193c74;

// Address passed to func_ov000_0218e4b4 by func_ov000_02193d64.
typedef struct Unk02193d64 {
    /* 0 */ u8 mUnk_00;
    /* 1 */ u8 mUnk_01;
    /* 2 */ u16 mUnk_02;
    /* 4 */ u32 mUnk_04;
} Unk02193d64;

void func_ov000_02193818(GpConnection *param_1, Unk021937c0Node *param_2);
void func_ov000_02193858(GpConnection *param_1, Unk021937c0Node *param_2);
u32 func_ov000_021938cc(GpConnection *param_1, int param_2, int param_3, int *param_4, int param_5, int param_6,
                        int param_7);
s32 func_ov000_02193954(GpConnection *param_1, Unk021937c0Node *param_2);
s32 func_ov000_02193b88(GpConnection *param_1, Unk02193f2cNode *param_2, const char *param_3, s32 param_4);
u32 func_ov000_02193c20(GpConnection *param_1, Unk02193f2cNode *param_2, u32 param_3, Unk02193c20 *param_4);
s32 func_ov000_02193c74(GpConnection *param_1, Unk02193f2cNode *param_2, u32 param_3, const char *param_4);
s32 func_ov000_02193d64(GpConnection *param_1, Unk02193f2cNode *param_2);
