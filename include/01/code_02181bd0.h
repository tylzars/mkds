#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject
#include "Main/Unknown/code_020e005c.h"

// Object updated by func_ov001_02181c3c, one state per value of mUnk_0f8.
typedef struct Unk02181c3c {
    /* 000 */ MapObject mUnk_000;
    /* 0a0 */ u16 mUnk_0a0;
    /* 0a2 */ u8 mUnk_0a2[0x2];
    /* 0a4 */ s32 mUnk_0a4;
    /* 0a8 */ s32 mUnk_0a8;
    /* 0ac */ s32 mUnk_0ac;
    /* 0b0 */ s32 mUnk_0b0;
    /* 0b4 */ Unk020e0144 mUnk_0b4;
    /* 0d8 */ Vec3 mUnk_0d8;
    /* 0e4 */ s32 mUnk_0e4;
    /* 0e8 */ Vec3 *mUnk_0e8;
    /* 0ec */ Vec3 mUnk_0ec;
    /* 0f8 */ s32 mUnk_0f8;
    /* 0fc */ void *mUnk_0fc;
    /* 100 */ s32 mUnk_100;
} Unk02181c3c;

// List of objects, as returned by func_02100138(0x68).
typedef struct Unk02181c3c_list {
    /* 00 */ Unk02181c3c **mUnk_00;
    /* 04 */ u16 mUnk_04;
} Unk02181c3c_list;

// Object with a flags word at 0x48.
typedef struct Unk0218274c {
    /* 00 */ u8 mUnk_00[0x48];
    /* 48 */ u32 mUnk_48;
} Unk0218274c;

#include "Main/Unknown/code_0209b000.h"
#include "01/code_02182000.h"
#include "01/code_0218155c.h"
#include "01/unk_021a6000.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02148000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "01/code_0219b250.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020e6000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_02100000.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_020d22c0.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020d4000.h"

void *func_ov001_02181bd0(void);
void *func_ov001_02181bec(void);
void *func_ov001_02181c08(void);
void func_ov001_02181c20(void);
void func_ov001_02181c3c(void *a, Unk02181c3c *b);
void func_ov001_0218254c(void);
void func_ov001_02182550(Unk02181c3c_list *a);
void func_ov001_0218263c(void *b, Unk02181c3c *c);
void func_ov001_021826fc(Unk0219b478 *a);
u8 func_ov001_0218274c(Unk02181c3c *c, Unk0218274c *d, u8 *e, u8 *f);
void func_ov001_021827a4(void);
void func_ov001_021827f0(void);
void func_ov001_021828f0(void);
void func_ov001_021829ac(s32 a);
void func_ov001_02182a3c(s32 a);
void func_ov001_02182bbc(u32 a);
void func_ov001_02182bdc(void);
void func_ov001_02182d30(void);
void func_ov001_02182e84(void);
void func_ov001_02182eb8(Unk02181c3c *a, s32 b);
void func_ov001_02182f1c(Unk02181c3c *p0, Kart *p1);

#include "01/code_0219b540.h"
#include "Main/Unknown/code_02081000.h"
#include "Main/Unknown/code_02081618.h"
