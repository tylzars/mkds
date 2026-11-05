#pragma once

#include "types.h"
#include "Main/Unknown/code_0202578c.h"
#include "Main/Unknown/code_0203b0a0.h"
#include "Main/Unknown/code_0202a340.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020cbad0.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02174000.h"

typedef struct Unk02029aa0 {
    /* 00 */ u8 pad_00[4];
    /* 04 */ u16 mUnk_04;
} Unk02029aa0;

// Object behind data_usa_02174e00, allocated by func_02029dcc.
typedef struct Unk02029dcc {
    /* 00 */ Unk02174e14_00 mUnk_00[2];
    /* 38 */ void *mUnk_38[2];
    /* 40 */ s32 mUnk_40;
    /* 44 */ s32 mUnk_44;
    /* 48 */ s32 mUnk_48;
    /* 4c */ Bmg *mUnk_4c;
    /* 50 */ Bmg *mUnk_50;
    /* 54 */ s32 mUnk_54;
    /* 58 */ u32 mUnk_58;
    /* 5c */ s32 mUnk_5c;
} Unk02029dcc;

extern Unk02029dcc *data_usa_02174e00;

extern const char data_usa_02162138[];
extern const char data_usa_02162144[];
extern const char data_usa_02162150[];
extern const char data_usa_02162164[];
extern const char data_usa_02162178[];
extern const char data_usa_0216218c[];
extern const char data_usa_021621a0[];
extern const char data_usa_021621b8[];
extern const char data_usa_021621d0[];
extern const char data_usa_021621e4[];
extern const char data_usa_021621f8[];
extern const char data_usa_0216220c[];
extern const char data_usa_02162220[];
extern const char data_usa_02162234[];
extern const char data_usa_02162248[];
extern const char data_usa_02162260[];
extern const char data_usa_02162278[];
extern const char data_usa_0216228c[];
extern const char data_usa_021622a0[];
extern const char data_usa_021622b4[];
extern const char data_usa_021622cc[];
extern const char data_usa_021622e4[];
extern u16 data_usa_02153860[];
extern u16 data_usa_02153868[];
extern u16 data_usa_02153878[];
extern u16 data_usa_02153888[];
extern u32 data_usa_02153898[][4];
extern Unk02153918 data_usa_02153918[];

void func_02029aa0(Unk02029aa0 *a);
void func_02029dcc(void *a, void *b, void *c);
