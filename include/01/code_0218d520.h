#pragma once

#include "types.h"
#include "01/code_02188950.h"
#include "01/code_0219b250.h"

// Object behind Unk02188950.mUnk_0a4.
typedef struct Unk0218dabc {
    /* 000 */ u8 mUnk_000[0x4];
    /* 004 */ s32 mUnk_004;
    /* 008 */ s32 mUnk_008;
    /* 00c */ s32 mUnk_00c;
    /* 010 */ u8 mUnk_010[0x174];
    /* 184 */ s32 mUnk_184;
} Unk0218dabc;

// Table of objects returned by FindMapObjectKindUpdateList(0x1fe).
typedef struct Unk0218d87c {
    /* 00 */ Unk02188950 **mUnk_00;
    /* 04 */ u16 mUnk_04;
} Unk0218d87c;

int func_ov001_0218d520(Unk02188950 *a);
void func_ov001_0218d800(Unk02188950 *a);
void func_ov001_0218d824(Unk02188950 *b, int c);
void func_ov001_0218d87c(Unk02188950 *a, int b);
void func_ov001_0218d8f4(Unk02188950 *a, int b);
void func_ov001_0218d950(Unk02188950 *a);
void func_ov001_0218d9cc(Unk02188950 *a);
void func_ov001_0218da1c(Unk02188950 *a);
void func_ov001_0218dabc(Unk02188950 *a);
void func_ov001_0218dadc(Unk02188950 *a);
void func_ov001_0218dba8(Unk02188950 *a);
void func_ov001_0218dc20(Unk02188950 *a);

#include "01/code_0219b540.h"
