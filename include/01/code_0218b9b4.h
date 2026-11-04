#pragma once

#include "types.h"
#include "01/code_02188950.h"
#include "Main/Unknown/code_0208b000.h"

// 0x34 bytes: two words, then four function pointers among zero words. Referenced only from main-module data.
typedef struct Unk021a7b64 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ void (*mUnk_08)(Unk02188950 *);
    /* 0c */ void (*mUnk_0c)(void);
    /* 10 */ void *(*mUnk_10)(void);
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ void *(*mUnk_1c)(void);
    /* 20 */ s32 mUnk_20[5];
} Unk021a7b64;

#include "01/code_02187000.h"
#include "01/code_02188000.h"
#include "01/code_02188218.h"
#include "01/code_02188da4.h"
#include "01/code_02188e24.h"
#include "01/code_02185ef4.h"
#include "01/code_0218bfc8.h"
#include "01/code_0218c000.h"
#include "01/code_0218c55c.h"
#include "01/code_0218c5fc.h"
#include "01/code_0218c63c.h"
#include "01/callees_0219b000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_0210b708.h"
#include "01/code_0218b000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "01/code_0218155c.h"
#include "01/code_02187d14.h"
#include "01/code_02187e78.h"
#include "01/code_02187eb0.h"
#include "01/code_02188158.h"
#include "01/code_0218c0a4.h"
#include "01/code_0218d520.h"
#include "01/code_0219b1c4.h"
#include "01/code_0219b250.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020a2300.h"
#include "Main/Unknown/unk_021759c0.h"

void func_ov001_0218b9b4(Unk02188950 *a);
void func_ov001_0218ba34(Unk02188950 *a);
void func_ov001_0218ba48(Unk02188950 *a);
int func_ov001_0218bb74(Unk02188950 *a);
void func_ov001_0218bbac(Unk02188950 *a);
void func_ov001_0218bc60(Unk02188950 *a);
void func_ov001_0218bcc4(Unk02188950 *a);
void func_ov001_0218bd80(Unk02188950 *a);
void func_ov001_0218bde8(Unk02188950 *a);
void func_ov001_0218bee4(Unk02188950 *a);

#include "01/code_0219b540.h"
