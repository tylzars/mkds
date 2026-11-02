#pragma once

#include "types.h"
#include "01/code_02188950.h"

// List of objects: an array of pointers and its length.
typedef struct Unk0218fa78 {
    /* 00 */ Unk02188950 **mUnk_00;
    /* 04 */ u16 mUnk_04;
} Unk0218fa78;

// Offsets 0x50..0x5b of the object are a position.
typedef struct Unk0218fd20 {
    /* 00 */ u8 mUnk_00[0x50];
    /* 50 */ Vec3 mUnk_50;
} Unk0218fd20;

// Four words handed to func_0210b734; the second points at the Vec3 of Unk02188950.
typedef struct Unk02190ee0 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ Vec3 *mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
} Unk02190ee0;

#include "01/code_02185ef4.h"

#include "01/callees_0219b000.h"
#include "01/code_02185000.h"
#include "01/code_02186000.h"
#include "01/code_02187000.h"
#include "01/code_02188000.h"
#include "01/code_02188260.h"
#include "01/code_02188da4.h"
#include "01/code_02188e24.h"
#include "01/code_02190000.h"
#include "Main/Unknown/code_020d2000.h"
#include "01/code_02188158.h"
#include "01/code_02191000.h"
#include "01/code_02192000.h"
#include "01/code_02187bfc.h"
#include "01/code_02188e88.h"
#include "01/code_02188484.h"
#include "01/code_0218f000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061f7c.h"

void *func_ov001_0218f9d4(void);
void *func_ov001_0218f9ec(void);
void *func_ov001_0218fa04(void);
void func_ov001_0218fa20(void);
void func_ov001_0218fa58(u32 a, u32 b);
void func_ov001_0218fa78(Unk0218fa78 *a);
void func_ov001_0218fb24(u32 a, Unk02188950 *b);
void func_ov001_0218fbe0(Unk0218fa78 *a);
void func_ov001_0218fc4c(u32 a, Unk02188950 *b);
void func_ov001_0218fcc4(Unk0218fa78 *a);
void func_ov001_0218fd20(Unk02188950 *a, Unk0218fd20 *b);
void func_ov001_0218fee0(Unk02188950 *a);
void func_ov001_0218fef8(Unk02188950 *a);
void func_ov001_0218ff34(int a);
void func_ov001_0218ff64(Unk02188950 *a);
void func_ov001_0218ff98(Unk02188950 *a);
void func_ov001_0218ffd4(int a);
void func_ov001_02190030(Unk02188950 *a);
void func_ov001_0219006c(Unk02188950 *a);
void func_ov001_02190080(Unk02188950 *a);
u32 func_ov001_02190090(Unk02188950 *a);
void func_ov001_021900ac(Unk02188950 *c);
int func_ov001_02190168(Unk02188950 *c);
void func_ov001_02190248(Unk02188950 *a);
void func_ov001_02190270(Unk02188950 *c);
void func_ov001_02190328(Unk02188950 *c);
int func_ov001_021903e0(Unk02188950 *c);
void func_ov001_02190468(Unk02188950 *c);
int func_ov001_0219052c(Unk02188950 *c);
void func_ov001_021905f8(Unk02188950 *c);
int func_ov001_02190688(Unk02188950 *c);
int func_ov001_0219079c(Unk02188950 *c);
void func_ov001_0219081c(Unk02188950 *c);
int func_ov001_021908a8(Unk02188950 *c);
void func_ov001_02190948(Unk02188950 *c);
s32 func_ov001_02190a20(Unk02188950 *c);
void func_ov001_02190acc(Unk02188950 *c);
s32 func_ov001_02190b58(Unk02188950 *c);
void func_ov001_02190c08(Unk02188950 *c);
s32 func_ov001_02190d00(Unk02188950 *c);
s32 func_ov001_02190d78(Unk02188950 *a);
void func_ov001_02190df0(void);
void func_ov001_02190df8(Unk02188950 *a);
void func_ov001_02190eb0(Unk02188950 *a);
void func_ov001_02190ee0(Unk02188950 *a);
void func_ov001_02190fc4(Unk02188950 *a);
void func_ov001_02191034(int a);
void func_ov001_02191064(Unk02188950 *a);
s32 func_ov001_021910d4(Unk02188950 *a);
s32 func_ov001_021910fc(Unk02188950 *a);
void func_ov001_02191130(Unk02188950 *a);
void func_ov001_0219116c(Unk02188950 *a);
void func_ov001_021911a8(Unk02188950 *a);
void func_ov001_02191258(Unk02188950 *a);
void func_ov001_02191318(Unk02188950 *a);
void func_ov001_021913b8(Unk02188950 *a);
s32 func_ov001_02191470(Unk02188950 *a);
void func_ov001_02191488(Unk02188950 *a);
void func_ov001_02191550(Unk02188950 *a);
void func_ov001_02191618(Unk02188950 *a);
void func_ov001_021916e0(Unk02188950 *a);
void func_ov001_021917d0(Unk02188950 *a);
s32 func_ov001_02191870(Unk02188950 *a);
int func_ov001_02191888(Unk02188950 *a);
void func_ov001_021918c8(Unk02188950 *a);
void func_ov001_02191980(Unk02188950 *a);
void func_ov001_02191a3c(Unk02188950 *a);
void func_ov001_02191adc(Unk02188950 *a);
void func_ov001_02191b40(Unk02188950 *a);
void func_ov001_02191bc0(Unk02188950 *a);
void func_ov001_02191c14(Unk02188950 *a);
void func_ov001_02191cf4(Unk02188950 *a);
u32 func_ov001_02191dc8(Unk02188950 *a);
void func_ov001_02191de0(Unk02188950 *a);
void func_ov001_02191e1c(Unk02188950 *a);
void func_ov001_02191e90(Unk02188950 *a);
void func_ov001_02191ecc(Unk02188950 *a);
void func_ov001_02191f70(Unk02188950 *a);
void func_ov001_02191fe8(Unk02188950 *a);
void func_ov001_02192080(Unk02188950 *a);
void func_ov001_021920dc(Unk02188950 *a);
void func_ov001_02192174(Unk02188950 *a);
void func_ov001_021921e4(Unk02188950 *a);
void func_ov001_0219226c(Unk02188950 *a);
void func_ov001_021922e0(Unk02188950 *a);
void func_ov001_02192358(Unk02188950 *a);
void func_ov001_021923e0(Unk02188950 *a);
void func_ov001_0219246c(Unk02188950 *a);
void func_ov001_021924cc(void);
void func_ov001_02192694(void);
void func_ov001_02192794(int a);
void func_ov001_021927c0(Unk02188950 *a);
void func_ov001_02192878(Unk02188950 *a);
void func_ov001_02192890(Unk02188950 *a);
