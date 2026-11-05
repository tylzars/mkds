#pragma once

#include "types.h"
#include "code_02142eac.h"
#include "code_021445e0.h"

typedef struct Unk021da2a8 {
    /* 0000 */ void *mUnk_00;
    /* 0004 */ u16 mUnk_04;
    /* 0006 */ u8 pad_06[2];
    /* 0008 */ u32 mUnk_08;
    /* 000c */ u16 mUnk_0c;
    /* 000e */ u16 mUnk_0e;
    /* 0010 */ u16 mUnk_10;
    /* 0012 */ u16 mUnk_12;
    /* 0014 */ u16 mUnk_14;
    /* 0016 */ u16 mUnk_16;
    /* 0018 */ u16 mUnk_18;
    /* 001a */ u8 pad_1a[0x18];
    /* 0032 */ u16 mUnk_32;
    /* 0034 */ u16 mUnk_34;
    /* 0036 */ u16 mUnk_36;
    /* 0038 */ u8 pad_38[8];
    /* 0040 */ s32 mUnk_40;
    /* 0044 */ u32 mUnk_44;
    /* 0048 */ u32 mUnk_48;
    /* 004c */ s32 (*mUnk_4c)(Unk021425e8 *);
    /* 0050 */ u16 mUnk_50;
    /* 0052 */ u16 mUnk_52;
    /* 0054 */ s32 mUnk_54;
    /* 0058 */ u32 mUnk_58;
    /* 005c */ u16 mUnk_5c;
    /* 005e */ u16 mUnk_5e;
    /* 0060 */ u16 mUnk_60;
    /* 0062 */ u8 pad_62[0x1e];
    /* 0080 */ u8 mUnk_80[0xf00];
    /* 0f80 */ u8 mUnk_f80[0xe0];
    /* 1060 */ u8 mUnk_1060[0x240];
    /* 12a0 */ u32 mUnk_12a0;
    /* 12a4 */ u32 mUnk_12a4;
    /* 12a8 */ u8 pad_12a8[0x100];
    /* 13a8 */ u32 mUnk_13a8;
    /* 13ac */ u32 (*mUnk_13ac)(void *, struct Unk021da2a8 *);
    /* 13b0 */ u32 mUnk_13b0;
    /* 13b4 */ u8 pad_13b4[0xc];
    /* 13c0 */ u8 mUnk_13c0[0x20];
    /* 13e0 */ Unk021450ec mUnk_13e0;
    /* 1c00 */ Unk0214461c mUnk_1c00;
    /* 1e00 */ Unk021450ec mUnk_1e00;
} Unk021da2a8;

extern Unk021da2a8 *data_ov003_021da2a8;

u32 func_ov003_021cfa68(void);
void func_ov003_021cfaa8(void);
void func_ov003_021cfb80(void);
BOOL func_ov003_021cfb98(void *a);
u8 *func_ov003_021cfc1c(u32 a);
void func_ov003_021cfc40(u32 a);
s32 func_ov003_021cfc4c(u32 a, u16 b, u16 c);
void func_ov003_021cfd44(Unk021425e8 *a);
BOOL func_ov003_021cfd88(void);
void func_ov003_021cfdc8(Unk021425e8 *event);
BOOL func_ov003_021cfde4(void);
int func_ov003_021cfe40(u16 c);
u16 func_ov003_021cfed8(void);
int func_ov003_021cff38(Unk021425e8Func a, u16 b);
void func_ov003_021cff50(Unk021425e8 *param_1);
u32 func_ov003_021cfff8(u16 param_1);
BOOL func_ov003_021d0078(void);
u32 func_ov003_021d010c(void);
u16 func_ov003_021d0118(void);
void func_ov003_021d0128(u32 a);
void func_ov003_021d0134(Unk021425e8 *a);
void func_ov003_021d0158(Unk021425e8 *event);
BOOL func_ov003_021d0180(void);
void func_ov003_021d01ac(Unk021425e8 *event);
BOOL func_ov003_021d01cc(void);
void func_ov003_021d0200(Unk021425e8 *event);
BOOL func_ov003_021d022c(void);
BOOL func_ov003_021d0258(void);
void func_ov003_021d02a0(Unk021425e8 *event);
BOOL func_ov003_021d02c0(void);
void func_ov003_021d02e8(Unk021425e8 *event);
BOOL func_ov003_021d032c(void);
BOOL func_ov003_021d0358(void);
BOOL func_ov003_021d0388(void);
void func_ov003_021d03c0(Unk021425e8 *event);
BOOL func_ov003_021d04a8(void);
void func_ov003_021d0530(Unk021425e8 *event);
BOOL func_ov003_021d0630(void);
void func_ov003_021d0680(Unk021425e8 *event);
BOOL func_ov003_021d06b0(void);
void func_ov003_021d0708(Unk021425e8 *event);
BOOL func_ov003_021d0760(void);
void func_ov003_021d079c(s32 value);
void func_ov003_021d07b0(u32 value);
void func_ov003_021d0810(Unk021da2a8 *a);
